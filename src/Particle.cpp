#include <iostream>
#include <cmath>
#include "Particle.h"
#include "globals.h"

void Particle::Update(float dt) {
	Force = earth_gravity * Mass;
	if (Position.y <= 0.0f) {
		Force.y = 0.0f;
	}
	else {
		Force.y = Force.y;
	}	
	Acceleration = Force / Mass;
	Position = Position + Velocity * dt + Acceleration * (dt * dt) / 2;
	Velocity = Velocity + Acceleration * dt;
	
}
void Particle::ApplyForce(vec2 ExternalForce, float dt) {
	if (ExternalForce.x == 0.0 && ExternalForce.y == 0.0) {
		Acceleration = earth_gravity;
		Position = Position + Velocity * dt + Acceleration * (dt * dt) / 2;
		Velocity = Velocity + Acceleration * dt;
	}
	
	/*if (Position.y <= 0.0f) {
		 Force.y = 0.0f;
	 }
	 else {
		 Force.y = Force.y;
	 }*/
	else {
		Force = (earth_gravity * Mass) + ExternalForce;

		Acceleration = Force / Mass;
		Position = Position + Velocity * dt + Acceleration * (dt * dt) / 2;
		Velocity = Velocity + Acceleration * dt;
	}
}
void Particle::ApplyImpulse(vec2 ImpulsiveForce, float dt) {
	//Impulse can be defined as change in momentum: F * dt = mv - mu 
	Velocity = ((ImpulsiveForce * dt) + Velocity) / Mass;
	Position = Position + Velocity * dt + Acceleration * (dt * dt) / 2;
}
