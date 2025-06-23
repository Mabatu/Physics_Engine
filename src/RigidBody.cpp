#include "RigidBody.h"

void RigidBody::Update(float dt) {
	Force = earth_gravity * Mass;
	Velocity = Velocity + Force / Mass * dt;
	Position = Position + Velocity * dt;
}
void RigidBody::ApplyForce(vec2 ExternalForce, float dt) {
	Force = (earth_gravity * Mass) + ExternalForce;
	Velocity = Velocity + Force / Mass * dt;
	Position = Position + Velocity * dt;
}
