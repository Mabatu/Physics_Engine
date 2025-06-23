#pragma once
#include "vec2.h"

vec2 earth_gravity = vec2(0, -9.81f);

class RigidBody
{
public:
	vec2 Position;
	vec2 Velocity;
	vec2 Force;
	float Mass;

	void Update(float dt);
	void ApplyForce(vec2 ExternalForce, float dt);
};
