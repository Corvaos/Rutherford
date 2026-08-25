//
// Created by corvaos on 8/18/26.
//

#include "Rutherford/Integrator.h"

void Integrator::step(std::vector<Particle>& heliumParticles, const std::vector<Particle>& goldParticles, const double dt)
{
  /* Euler's Method

      * Update Acceleration (2nd Derivative)
      * Update Velocity (1st Derivative)
      * Update Position (0th Derivative(?))

  */

  const std::vector<vaos::numerics::Vector3> forces = ForceCalculator::calculateCoulombForce(heliumParticles, goldParticles);

  for (int i = 0; i < forces.size(); i++)
  {
    heliumParticles[i].momentum += (forces[i]) * dt;
    heliumParticles[i].position += heliumParticles[i].getVelocity() * dt;
  }
}

void Integrator::stepVerlet(std::vector<Particle>& heliumParticles, const std::vector<Particle>& goldParticles, const double dt)
{
  /* Velocity Verlet
      *
      * Update POSITION
      * Calculate FORCES->MOMENTUM
      * Update MOMENTUMS
      * Store FORCES
      *
      */

  if (verletForces.empty())
  {
    verletForces = ForceCalculator::calculateCoulombForce(heliumParticles, goldParticles);
  }

  for (int i = 0; i < heliumParticles.size(); i++)
  {
    heliumParticles[i].position += (heliumParticles[i].momentum + verletForces[i] * dt * 0.5) * dt / heliumParticles[i].mass;
  }

  const std::vector<vaos::numerics::Vector3> forces = ForceCalculator::calculateCoulombForce(heliumParticles, goldParticles);

  for (int i = 0; i < forces.size(); i++)
  {
    heliumParticles[i].momentum += (forces[i] + verletForces[i]) * 0.5 * dt;

    verletForces[i] = forces[i];
  }
}