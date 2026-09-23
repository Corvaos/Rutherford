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

constexpr double ELECTRON_CHARGE = 1.60217663e-19;
constexpr double AMU = 1.66054e-24;
constexpr double SPEED_OF_LIGHT = 299792458.0;

class Particle
{
public:
  vaos::numerics::Vector3 position{};
  vaos::numerics::Vector3 velocity{};
  vaos::numerics::Vector3 momentum{};

  double mass{AMU};
  double charge{0};

  Particle(const vaos::numerics::Vector3& position, const vaos::numerics::Vector3& momentum, const double mass,
           const double charge)
    : position(position), velocity(momentum / mass), momentum(momentum), mass(mass), charge(charge * ELECTRON_CHARGE)
  {
  }
};

#endif //RUTHERFORD_PARTICLE_H
