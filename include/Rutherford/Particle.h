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
  vaos::numerics::Vector3 velocity{};

  double mass{1};
  double charge{0};

  Particle(const vaos::numerics::Vector3& position, const vaos::numerics::Vector3& velocity, const double mass,
           const double charge)
    : position(position), velocity(velocity), mass(mass), charge(charge)
  {
  }
};

#endif //RUTHERFORD_PARTICLE_H
