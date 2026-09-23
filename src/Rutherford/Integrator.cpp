//
// Created by corvaos on 8/18/26.
//

#include "Rutherford/Integrator.h"

#include <complex>

void Integrator::step(std::vector<Particle>& heliumParticles, const std::vector<Particle>& goldParticles, const double dt)
{
  /* Euler's Method

      * Update Acceleration (2nd Derivative)
      * Update Velocity (1st Derivative)
      * Update Position (0th Derivative(?))

  */

  if (verletForces.empty()) [[unlikely]]
  {
    verletForces.resize(heliumParticles.size());
  }
  verletForces = ForceCalculator::calculateCoulombForce(heliumParticles, goldParticles);

  for (int i = 0; i < verletForces.size(); i++)
  {
    heliumParticles[i].momentum += (verletForces[i]) * dt;
    heliumParticles[i].position += heliumParticles[i].velocity * dt;
  }
}

void Integrator::stepVerlet(std::vector<Particle>& heliumParticles, const std::vector<Particle>& goldParticles, const double dt)
{
  /* Velocity Verlet
      *
      * Update POSITION
      * Calculate FORCES->MOMENTUM
      * Calculate VELOCITY
      * Update MOMENTUMS
      * Store FORCES
      *
      */

  if (verletForces.empty()) [[unlikely]]
  {
    verletForces = ForceCalculator::calculateCoulombForce(heliumParticles, goldParticles);
  }

  for (int i = 0; i < heliumParticles.size(); i++)
  {
    heliumParticles[i].velocity = heliumParticles[i].momentum *
      sqrt(1.0 - (heliumParticles[i].velocity.squareLength() / (SPEED_OF_LIGHT * SPEED_OF_LIGHT))) /    // LORENTZ FACTOR
        heliumParticles[i].mass;
    heliumParticles[i].momentum += verletForces[i] * dt * 0.5;
  }

  for (auto & heliumParticle : heliumParticles)
  {
    heliumParticle.position += heliumParticle.velocity * dt;
  }

  verletForces = ForceCalculator::calculateCoulombForce(heliumParticles, goldParticles);

  for (int i = 0; i < heliumParticles.size(); i++)
  {
    heliumParticles[i].velocity = heliumParticles[i].momentum *
      sqrt(1.0 - (heliumParticles[i].velocity.squareLength() / (SPEED_OF_LIGHT * SPEED_OF_LIGHT))) /    // LORENTZ FACTOR
        heliumParticles[i].mass;
    heliumParticles[i].momentum += verletForces[i] * dt * 0.5;
  }
}