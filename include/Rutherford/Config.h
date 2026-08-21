//
// Created by corvaos on 8/21/26.
//

#ifndef RUTHERFORD_CONFIG_H
#define RUTHERFORD_CONFIG_H

struct Config
{
  static constexpr double DT = 1e-5;
  static constexpr int RATE = 10;
  static constexpr int RESOLUTION = 1000;

  enum INTEGRATOR_TYPES
  {
    EULERS_METHOD,
    VELOCITY_VERLET,
  };

  static constexpr enum INTEGRATOR_TYPES INTEGRATOR = VELOCITY_VERLET;
};

#endif //RUTHERFORD_CONFIG_H
