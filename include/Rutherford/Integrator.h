//
// Created by corvus on 8/18/26.
//

#ifndef RUTHERFORD_INTEGRATOR_H
#define RUTHERFORD_INTEGRATOR_H

#include <memory>
#include <vector>

#include "Rutherford/Particle.h"
#include "Rutherford/ForceCalculator.h"

class Integrator
{
  inline static std::vector<vaos::numerics::Vector3> verletAccels = {};

public:
  static void step(std::vector<Particle>& particles, double dt);

  static void stepVerlet(std::vector<Particle>& particles, double dt);
};


#endif //RUTHERFORD_INTEGRATOR_H
