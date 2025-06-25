#include <iostream>
#include "Particle.h"
#include "globals.h"
#include <fstream>

// Tracks the total time the particle is in the air.
float timeElapsed = 0;

int main() {
	// Create a CSV file to store the projectile's trajectory
	std::ofstream outputFile("projectile_motion.csv");
	outputFile << "X,Y" << '\n';

	// Define the time step (smaller values improve simulation accuracy)
	const float dt = 0.0001;

	// Create a particle to represent the projectile (e.g., a ball)
	Particle Ball;

	// Set initial conditions: mass, position, and velocity
	Ball.Mass = 1.0;
	Ball.Position = vec2(0.0f, 0.0f); // Starting at origin
	Ball.Velocity = vec2(20.0, 20.0); // 45-degree launch

	//Log initial position.
	outputFile << Ball.Position.x << ',' << Ball.Position.y << '\n';

	// Simulate motion until the projectile returns to ground level (y = 0)
	while (Ball.Position.y >= 0) {
		Ball.Update(dt);

		//Debugging.
		std::cout << "Acceleration: ";
		Ball.Acceleration.Print();
		std::cout << '\t' << "Velocity: ";
		Ball.Velocity.Print();
		std::cout << '\n';
		
		//Log updated position.
	    outputFile << Ball.Position.x << ',' << Ball.Position.y << '\n';
		timeElapsed += dt;
	}
	std::cout << "Final Postion" << Ball.Position.x << ',' << Ball.Position.y 
		      << "Time of Flight = " << timeElapsed << '\n';
	outputFile.close();
	return 0;
}
