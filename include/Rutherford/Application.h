//
// Created by corvus on 8/18/26.
//

#ifndef RUTHERFORD_APPLICATION_H
#define RUTHERFORD_APPLICATION_H

#include "Rutherford/RenderManager.h"
#include "Rutherford/Simulation.h"

#include "vaos/renderer/GLFWContext.h"

#include <memory>

class Application
{
private:
  std::unique_ptr<RenderManager> renderManager;
  std::unique_ptr<Simulation> simulationManager;

public:
  void run(double dt) const;

  [[nodiscard]] bool active() const;

  void addParticle(const vaos::numerics::Vector3& position, const vaos::numerics::Vector3& velocity, double mass,
                   double charge, int atomType) const;

  void initCoreParticles() const;
  void launchWave(int resolution) const;

  Application();
};

#endif //RUTHERFORD_APPLICATION_H
