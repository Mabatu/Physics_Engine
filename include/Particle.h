#pragma once
#include "vec2.h"

class Particle
{
public:
	vec2 Position;
	vec2 Velocity;
	vec2 Force;
	float Mass;

	void Update(float dt);
	void ApplyForce(vec2 ExternalForce, float dt);
};
