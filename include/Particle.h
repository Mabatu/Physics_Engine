#pragma once
#include "vec2.h"
#include "globals.h"

class Particle
{
public:
	vec2 Position;
	vec2 Velocity;
	vec2 Force;
	vec2 Acceleration;
	float Mass;

	void Update(float dt);
	void ApplyForce(vec2 ExternalForce, float dt);
	void ApplyImpulse(vec2 ImpulsiveForce, float dt);
};
