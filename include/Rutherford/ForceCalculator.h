//
// Created by corvus on 8/19/26.
//

#ifndef RUTHERFORD_FORCECALCULATOR_H
#define RUTHERFORD_FORCECALCULATOR_H

#include <vector>
#include <iostream>
#include "Rutherford/Particle.h"

class ForceCalculator
{
  static constexpr double COULOMB_CONSTANT = 8.99e9;

public:
  // !! Assumes the gold particle is static !!
  static std::vector<vaos::numerics::Vector3> calculateCoulombForce(const std::vector<Particle>& heliumParticles,
                                                                    const std::vector<Particle>& goldParticles)
  {
    std::vector<vaos::numerics::Vector3> output = {};

    for (unsigned int i = 0; i < heliumParticles.size(); i++)
    {
      output.emplace_back(0);
      for (const Particle& goldParticle : goldParticles)
      {
        vaos::numerics::Vector3 posDiff = heliumParticles[i].position - goldParticle.position;
        output[i] += (posDiff * (COULOMB_CONSTANT * heliumParticles[i].charge * goldParticle.charge / (posDiff.
          squareLength() * posDiff.length())));
      }
    }

    return output;
  }
};


#endif //RUTHERFORD_FORCECALCULATOR_H
