//
// Created by corvaos on 8/18/26.
//

#include "Rutherford/Simulation.h"

void Simulation::addSimParticle(const vaos::numerics::Vector3& position, const vaos::numerics::Vector3& velocity,
                                const double mass, const double charge, const int typeID)
{
  if (typeID == PARTICLE_TYPE::ATOM_GOLD_197)
  {
    goldParticles.emplace_back(position, velocity, mass, charge);
  } else
  {
    heliumParticles.emplace_back(position, velocity, mass, charge);
  }
}

void Simulation::runStep(const double dt)
{
  if constexpr (Config::INTEGRATOR == Config::EULERS_METHOD)
  {
    for (int i = 0; i < Config::RATE; i++)
    {
      Integrator::step(heliumParticles, goldParticles, dt);
    }
  } else if constexpr (Config::INTEGRATOR == Config::VELOCITY_VERLET)
  {
    for (int i = 0; i < Config::RATE; i++)
    {
      Integrator::stepVerlet(heliumParticles, goldParticles, dt);
    }
  }
}