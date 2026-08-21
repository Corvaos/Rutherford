# N-Body Simulator

# Purpose
This C++ program simulates the Rutherford experiment and renders it using OpenGL using my own personal [Vaos-Renderer]([Vaos-Renderer](https://github.com/Corvaos/Vaos-Renderer)) library.

Configuration can be found in the `Config.h` in `/include/Rutherford`. Configurable values include:
* Resolution
* Simulation Speed
* Δt (Delta Time / Time Step)
* [Method / Solver](#Methods)

# Methods
Various methods can be applied through `Config.h`, primarily the `INTEGRATOR` variable, of which can be any option in the list directly above its declaration.

* **Euler's Method** (First Order Accuracy)
* **Velocity Verlet** (Second Order Accuracy)
    * **Velocity Verlet** is a sympletic integrator, so it is more effective in keeping accuracy over longer periods of time. While not necessary for this on most time scales, it does provide a higher accuracy in high energy scenarios.

# Rendering
All visual output is rendered through OpenGL through the [Vaos-Renderer](https://github.com/Corvaos/Vaos-Renderer) library of my own creation.

# Development
This program currently demonstrates approximately `O(n)` time complexity, as each particle interacts only once with the core particle, but not any neighboring particles. This is to simulate the effect of each particle being fired one at a time to reflect the original experiment's practices.
