//
// Created by corvaos on 8/18/26.
//

#ifndef RUTHERFORD_SIMULATION_H
#define RUTHERFORD_SIMULATION_H

#include <vector>

#include "Rutherford/Integrator.h"
#include "Rutherford/Particle.h"
#include "Rutherford/Config.h"

class Simulation
{
public:
  std::vector<Particle> heliumParticles;
  std::vector<Particle> goldParticles;

  std::vector<Particle*> particles;

  void addSimParticle(const vaos::numerics::Vector3& position, const vaos::numerics::Vector3& velocity, double mass,
                      double charge, int typeID);

  void runStep(double dt);
};


#endif //RUTHERFORD_SIMULATION_H
