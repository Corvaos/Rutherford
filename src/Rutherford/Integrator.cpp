//
// Created by corvaos on 8/18/26.
//

#include "Rutherford/Integrator.h"

#include "Rutherford/Simulation.h"

void Integrator::step(std::vector<Particle>& particles, const double dt)
{
  /* Euler's Method

      * Update Acceleration (2nd Derivative)
      * Update Velocity (1st Derivative)
      * Update Position (0th Derivative(?))

  */

  const std::vector<vaos::numerics::Vector3> forces = ForceCalculator::calculateCoulombForce(particles);

  for (int i = 0; i < forces.size(); i++)
  {
    particles[i].velocity += (forces[i]/particles[i].mass) * dt;
    particles[i].position += particles[i].velocity * dt;
  }
}

void Integrator::stepVerlet(std::vector<Particle>& particles, const double dt)
{
  /* Velocity Verlet
      *
      * Update POSITION
      * Calculate FORCES->ACCELERATIONS
      * Update VELOCITIES
      * Store ACCELERATIONS
      *
      */

  verletAccels.resize(particles.size());

  for (Particle& particle : particles)
  {
    particle.position += particle.velocity * dt;
  }

  const std::vector<vaos::numerics::Vector3> forces = ForceCalculator::calculateCoulombForce(particles);

  for (int i = 0; i < forces.size(); i++)
  {
    vaos::numerics::Vector3 accel = forces[i]/particles[i].mass;
    particles[i].velocity += (accel + verletAccels[i]) * 0.5 * dt;

    verletAccels[i] = accel;
  }
}