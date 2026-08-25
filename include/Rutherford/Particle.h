//
// Created by corvus on 8/18/26.
//

#ifndef RUTHERFORD_PARTICLE_H
#define RUTHERFORD_PARTICLE_H

#include "vaos/renderer/Numerics/Matrix.h"

enum PARTICLE_TYPE
{
  ATOM_HELIUM_4,
  ATOM_GOLD_197
};

class Particle
{
public:
  vaos::numerics::Vector3 position{};
  vaos::numerics::Vector3 momentum{};

  double mass{1};
  double charge{0};

  Particle(const vaos::numerics::Vector3& position, const vaos::numerics::Vector3& momentum, const double mass,
           const double charge)
    : position(position), momentum(momentum), mass(mass), charge(charge)
  {
  }

  [[nodiscard]] vaos::numerics::Vector3 getVelocity() const
  {
    return momentum / mass;
  }
};

#endif //RUTHERFORD_PARTICLE_H
