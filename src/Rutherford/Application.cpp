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

bool Application::active() const { return renderManager->window.active; }

void Application::run(const double dt) const
{
  simulationManager->runStep(dt);

  for (int i = 0; i < renderManager->window.objects.size(); i++)
  {
    renderManager->assignTransforms(vaos::numerics::Transform(simulationManager->particles[i].position, 0, 0.01), i);
  }
  renderManager->drawAll();
}

void Application::addParticle(const vaos::numerics::Vector3& position, const vaos::numerics::Vector3& velocity,
                              const double mass, const double charge, const int atomType) const
{
  simulationManager->addSimParticle(position, velocity, mass, charge);
  renderManager->addRenderParticle(position, mass, atomType);
}

void Application::initCoreParticles() const
{
  addParticle(
    vaos::numerics::Vector3(0),
    vaos::numerics::Vector3(0),
    3.27e-25,
    1.266e-16,
    PARTICLE_TYPE::ATOM_GOLD_197
  );
}

void Application::launchWave(const int resolution) const
{
  for (int offset = -resolution; offset < resolution; offset ++)
  {
    addParticle(
      vaos::numerics::Vector3(static_cast<double>(offset)/resolution, -0.5, 0),
      vaos::numerics::Vector3(0, 25, 0),
      6.64e-27,
      3.204e-19,
      PARTICLE_TYPE::ATOM_HELIUM_4
    );
  }
}
