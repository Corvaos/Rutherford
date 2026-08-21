//
// Created by corvus on 8/19/26.
//

#ifndef RUTHERFORD_FORCECALCULATOR_H
#define RUTHERFORD_FORCECALCULATOR_H

#include <vector>
#include "Rutherford/Particle.h"
#include <iostream>

class ForceCalculator
{
  static constexpr double COULOMB_CONSTANT = 8.99e9;

public:
  // Assumes the gold particle is static !!
  static std::vector<vaos::numerics::Vector3> calculateCoulombForce(const std::vector<Particle>& particles)
  {
    std::vector<vaos::numerics::Vector3> output = {vaos::numerics::Vector3(0)};

    for (unsigned int i = 1; i < particles.size(); i++)
    {
      vaos::numerics::Vector3 posDiff = particles[i].position - particles[0].position;
      output.emplace_back(posDiff * (COULOMB_CONSTANT * particles[0].charge * particles[i].charge / (posDiff.squareLength() * posDiff.length())));
    }

    return output;
  }
};


#endif //RUTHERFORD_FORCECALCULATOR_H
