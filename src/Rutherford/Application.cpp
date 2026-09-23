//
// Created by corvaos on 8/18/26.
//

#include "Rutherford/Application.h"

#include "vaos/renderer/Mesh/MeshFactory.h"

double randomValue(const double min, const double max) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> num(min, max);
  return num(gen);
}

Application::Application()
{
  vaos::renderer::GLFWContext::init();
  renderManager = std::make_unique<RenderManager>("Rutherford", 1920, 1920);
  simulationManager = std::make_unique<Simulation>();

  vaos::renderer::MeshFactory::generateCircle(100, true);
}

void Application::setup() const
{
  initCoreParticles();
  launchWave();

  for (int i = 0; i < simulationManager->goldParticles.size(); i++)
  {
    simulationManager->particles.push_back(&simulationManager->goldParticles[i]);
  }

  for (int i = 0; i < simulationManager->heliumParticles.size(); i++)
  {
    simulationManager->particles.push_back(&simulationManager->heliumParticles[i]);
  }
}

bool Application::active() const { return renderManager->window.active; }

void Application::run(const double dt) const
{
  simulationManager->runStep(dt);

  for (int i = 0; i < simulationManager->particles.size(); i++)
  {
    renderManager->assignTransforms(
      vaos::numerics::Transform(simulationManager->particles[i]->position, 0, 0.0075 / Config::ZOOM), i);
  }

  renderManager->drawAll();
}

void Application::addParticle(const vaos::numerics::Vector3& position, const vaos::numerics::Vector3& velocity,
                              const double mass, const double charge, const int atomType) const
{
  simulationManager->addSimParticle(position, velocity*mass, mass, charge, atomType);
  renderManager->addRenderParticle(position, mass, atomType);
}

void Application::initCoreParticles() const
{
  constexpr double xAmount = Config::GOLD_WIDTH / Config::GOLD_SEPARATION;

  for (int i = 0; i < Config::GOLD_ROWS; i++)
  {
    double x = -Config::GOLD_WIDTH / 2;

    if (i % 2 == 1)
    {
      x += Config::GOLD_SEPARATION / 2;
    }

    for (int j = 0; j < xAmount; j++)
    {
      x += Config::GOLD_SEPARATION;
      addParticle(
        vaos::numerics::Vector3(x + randomValue(-1e-11, 3e-11), i * Config::GOLD_SEPARATION + randomValue(-1e-11, 3e-11), 0),
        vaos::numerics::Vector3(0, 0, 0),
        3.27e-25,
        79,
        PARTICLE_TYPE::ATOM_GOLD_197
      );
    }
  }
}

void Application::launchWave() const
{
  constexpr double xOffset = Config::GOLD_WIDTH / (Config::HELIUM_RESOLUTION + 1);
  double x = -Config::GOLD_WIDTH / 2;
  for (int i = 0; i < Config::HELIUM_RESOLUTION; i++)
  {
    x += xOffset;
    addParticle(
      vaos::numerics::Vector3(x, -1e-10, 0),
      vaos::numerics::Vector3(0, SPEED_OF_LIGHT * Config::HELIUM_SPEED_PERCENT, 0),
      6.64e-27,
      2,
      PARTICLE_TYPE::ATOM_HELIUM_4
    );
  }
}
