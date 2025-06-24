#include <iostream>
#include "Particle.h"
#include "globals.h"
#include <fstream>

//Define duration for simulation, preferably time equal to time of flight.
#define time 8.12

float timeElapsed = 0;

int main() {
  //Create a file to store the projectile's coordinates over time.
	std::ofstream outputFile("projectile_motion.csv");
	outputFile << "X,Y" << std::endl;

  //Initial force to start projectile motion.
	vec2 ExternalForce = vec2(200, 400);

  //Define time interval.
	float dt = 0.1;
  //Create an instance of a particle and define its mass and position.
	Particle Ball;
	Ball.Mass = 1.0f;
	Ball.Position = vec2(0.0f, 0.0f);
	
	while (timeElapsed < time) {
		Ball.ApplyForce(ExternalForce, dt);
		//Reset force to zero.
		ExternalForce = vec2(0, 0);
	  outputFile << Ball.Position.x << ',' << Ball.Position.y << std::endl;
		timeElapsed += dt;
	}
	std::cout << "Final Postion" << Ball.Position.x << ',' << Ball.Position.y << std::endl;
	outputFile.close();
	return 0;
}
