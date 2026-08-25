//
// Created by corvaos on 8/21/26.
//

#ifndef RUTHERFORD_CONFIG_H
#define RUTHERFORD_CONFIG_H

struct Config
{
  static constexpr double DT = 5e-7;
  static constexpr int RATE = 10;
  static constexpr int HELIUM_RESOLUTION = 100;
  static constexpr int GOLD_RESOLUTION = 10;
  static constexpr int GOLD_ROWS = 2;

  static constexpr double ZOOM = 1;

  enum INTEGRATOR_TYPES
  {
    EULERS_METHOD,
    VELOCITY_VERLET,
  };

  static constexpr enum INTEGRATOR_TYPES INTEGRATOR = VELOCITY_VERLET;
};

#endif //RUTHERFORD_CONFIG_H
