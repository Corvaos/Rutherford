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

  void initCoreParticles(int resolution, int rows) const;
  void launchWave(int resolution) const;

public:
  void run(double dt) const;

  [[nodiscard]] bool active() const;

  void addParticle(const vaos::numerics::Vector3& position, const vaos::numerics::Vector3& velocity, double mass,
                   double charge, int atomType) const;



  void setup(int resolution, int rows) const;

  Application();
};

#endif //RUTHERFORD_APPLICATION_H
