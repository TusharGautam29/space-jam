# Space Jam 🚀🔫 (OpenGL Game)

[![View on GitHub](https://img.shields.io/badge/View%20on-GitHub-000?logo=github&style=flat-square)](https://github.com/TusharGautam29/YourRepoHere)

https://github.com/user-attachments/assets/31a022a4-d41a-4b65-8fd1-13a8d14c3161

A modern 2D space shooter inspired by Space Invaders, built entirely from scratch in C++ using OpenGL. Features fast-paced gameplay, randomized enemy attacks, audio via `raudio`, and a clean debug UI with ImGui.

## 🎮 Features

- **Hardware-accelerated 2D gameplay** with OpenGL
- **Randomized enemy spawns and shooting behavior**
- **Real-time audio using raylib's `raudio` module**
- **Player movement and shooting mechanics**
- **ImGui-based UI overlays**
- **Smooth rendering via GL2D**
- **Built using CMake**

## 🧰 Tech Stack

- **C++ / CMake**
- **OpenGL (Core Profile)**
- **GLFW** – windowing/input
- **GLAD** – OpenGL loader
- **GLM** – math library
- **GL2D** – 2D rendering wrapper
- **ImGui** – GUI overlays
- **GLUI** – lightweight UI framework
- **raudio** – audio playback (from [raylib](https://github.com/raysan5/raylib))

## 🛠️ Build Instructions
The easiest way to build is just open the .sln with Visual Studio -> ctrl + S on cmakelists.txt, and select spaceGame.exe then run.
```bash
git clone [https://github.com/TusharGautam29/space-jam]
cd space-jam
mkdir build && cd build
cmake ..
make
./spaceGame.exe
