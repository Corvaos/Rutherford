//
// Created by corvaos on 8/18/26.
//

#include "Rutherford/Application.h"

#include "vaos/renderer/Mesh/MeshFactory.h"

Application::Application()
{
  vaos::renderer::GLFWContext::init();
  renderManager = std::make_unique<RenderManager>("Rutherford", 1920, 1080);
  simulationManager = std::make_unique<Simulation>();

  vaos::renderer::MeshFactory::generateCircle(100, true);
}

void Application::setup(const int resolution, const int rows) const
{
  initCoreParticles(resolution, rows);
  launchWave(Config::HELIUM_RESOLUTION);

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
    renderManager->assignTransforms(vaos::numerics::Transform(simulationManager->particles[i]->position, 0, 0.01), i);
  }

  renderManager->drawAll();
}

void Application::addParticle(const vaos::numerics::Vector3& position, const vaos::numerics::Vector3& velocity,
                              const double mass, const double charge, const int atomType) const
{
  simulationManager->addSimParticle(position, velocity, mass, charge, atomType);
  renderManager->addRenderParticle(position, mass, atomType);
}

void Application::initCoreParticles(const int resolution, const int rows) const
{
  const int r = resolution / rows;

  const double xOffset = 2.0 / (r + 1);
  const double yOffset = 1.0 / (r + 1);
  double y = 0;

  for (int i = 0; i < rows; i++)
  {
    double x = -1;
    if (i % 2 == 1)
    {
      x += xOffset / 2;
    }
    for (int j = 0; j < r; j++)
    {
      x += xOffset;
      addParticle(
        vaos::numerics::Vector3(x, y, 0),
        vaos::numerics::Vector3(0, 0, 0),
        3.27e-25,
        1.266e-16,
        PARTICLE_TYPE::ATOM_GOLD_197
      );
    }
    y += yOffset;
  }
}

void Application::launchWave(const int resolution) const
{
  const double r = 2.0/(resolution+1);
  double offset = -1;
  for (int i = 0; i < resolution; i++)
  {
    offset += r;
    addParticle(
      vaos::numerics::Vector3(offset, -0.75, 0),
      vaos::numerics::Vector3(0, 1.66e-24, 0),
      6.64e-27,
      3.204e-19,
      PARTICLE_TYPE::ATOM_HELIUM_4
    );
  }
}
