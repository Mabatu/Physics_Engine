#include <iostream>
#include <cmath>
#include "Particle.h"
#include "globals.h"

// Updates the particle's velocity and position under the influence of gravity only.
void Particle::Update(float dt) {
	Force = earth_gravity * Mass;
	Acceleration = Force / Mass;

	Velocity = Velocity + Acceleration * dt;
	Position = Position + Velocity * dt;
	Force = vec2(0.0f, 0.0f);
}

// Applies an external force to the particle in addition to gravity.
// If no external force is present, the update defaults to gravity-only motion.
void Particle::ApplyForce(vec2 ExternalForce, float dt) {
	if (ExternalForce.x == 0.0 && ExternalForce.y == 0.0) {
		Update(dt);
	}
	else {
		Force = (earth_gravity * Mass) + ExternalForce;
		Acceleration = Force / Mass;

		Velocity = Velocity + Acceleration * dt;
		Position = Position + Velocity * dt;

		//Reset force accumulator
		Force = vec2(0.0f, 0.0f);
	}
}
//Particle::ApplyImpulse() to be improved.
void Particle::ApplyImpulse(vec2 ImpulsiveForce, float dt) {
	//Impulse can be defined as change in momentum: F * dt = mv - mu 
	Velocity = ((ImpulsiveForce * dt) + Velocity) / Mass;
	Position = Position + Velocity * dt + Acceleration * (dt * dt) / 2;
}
