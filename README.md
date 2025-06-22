# Boids-Unreal

This project implements a **Boids simulation system** in Unreal Engine, showcasing emergent flocking behaviors inspired by Craig Reynolds' model. 
Each "Boid" in the simulation is governed by a series of steering behaviors that simulate realistic group movement, such as alignment, cohesion, and separation.

## 🧩 Core Components

- `Boid`: Represents an individual agent (boid) in the simulation. Handles position updates and applies steering forces.
- `BoidsHUD`: Manages the Heads-Up Display for visualizing or interacting with simulation parameters.
- `SteeringComponent`: Central component responsible for combining the various steering behaviors applied to a Boid.
- `SteeringControlWidget`: A UI widget for controlling parameters of the steering behaviors in real-time.
- `SteeringBehaviour`: Base class or interface for all steering behavior implementations.

## 🧠 Steering Behaviors

Each behavior is modular and implemented in its own class:

- `AlignmentBehaviour`: Aligns a Boid’s direction with its neighbors.
- `CohesionBehaviour`: Moves a Boid toward the average position of nearby Boids.
- `SeparationBehaviour`: Ensures Boids maintain personal space by steering away from nearby Boids.
- `ObstacleAvoidanceBehaviour`: Enables Boids to detect and avoid obstacles in their path.
- `WanderBehaviour`: Introduces randomness to simulate natural movement patterns.

## ⚙️ Design Philosophy

This modular design allows for:

- Easy extension of new behaviors
- Real-time tuning of parameters
- Clean separation of logic and UI
- Experimentation with different steering combinations
