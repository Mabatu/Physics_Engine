# Projectile Motion Simulation

A demonstration of how to use the Physics Engine to simulate the projectile motion of a particle, specifically to determine the time of flight.
##  How It Works
A particle is initialized with a specified mass, initial velocity, and starting position. Using the explicit(forward) Euler method, the particle's position and velocity are updated at small time intervals.
Each position is logged to a CSV file, which allows for plotting the trajectory later. The simulation continues until the particle returns to ground level, defined as when its vertical position (`y <= 0`). The total time elapsed is then calculated and returned as the time of flight.
##  Files
`Projectile_Motion.cpp`: Core implementation of the simulation.
`projectile_motion.R`: Simple R script used to plot the trajectory from the CSV data.
`projectile_motion.png`: Example output plot showing the projectile path.
## Note
Uses Euler's forward integration (explicit method). It assumes only gravity acts after launch, neglecting air resistance. A smaller time step (`dt`) enhances accuracy.
