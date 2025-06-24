#include <iostream>
#include <cmath>
#include "Particle.h"
#include "globals.h"

void Particle::Update(float dt) {
	Force = earth_gravity * Mass;
	if (Force.y <= 0.0f) {
		Force.y = 0.0f;
	}
	else {
		Force.y = Force.y;
	}	
	Velocity = Velocity + Force / Mass * dt;
	Position = Position + Velocity * dt;
	
}
void Particle::ApplyForce(vec2 ExternalForce, float dt) {
	Force = (earth_gravity * Mass) + ExternalForce;
	if (Force.y <= 0.0f) {
		Force.y = 0.0f;
	}
	else {
		Force.y = Force.y;
	}
	Velocity = Velocity + Force / Mass * dt;
	Position = Position + Velocity * dt;
}

