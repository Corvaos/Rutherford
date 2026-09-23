//
// Created by corvaos on 8/21/26.
//

#ifndef RUTHERFORD_CONFIG_H
#define RUTHERFORD_CONFIG_H

struct Config
{
  static constexpr double DT = 2e-21;
  static constexpr int RATE = 100;

  static constexpr int HELIUM_RESOLUTION = 100;
  static constexpr double HELIUM_SPEED_PERCENT = 0.03;

  static constexpr int GOLD_ROWS = 3;
  static constexpr double GOLD_WIDTH = 1e-8;
  // Atoms are approximately 100 picometers apart (10^-10, 1e-10 meters)
  static constexpr double GOLD_SEPARATION = 1e-10;

  static constexpr double ZOOM = 1e9;

  enum INTEGRATOR_TYPES
  {
    EULERS_METHOD,
    VELOCITY_VERLET,
  };

  static constexpr enum INTEGRATOR_TYPES INTEGRATOR = VELOCITY_VERLET;
};

#endif //RUTHERFORD_CONFIG_H
