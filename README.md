### Cub3D: My First RayCaster with MiniLibX

This project is a **ray-casting engine** inspired by the legendary *Wolfenstein 3D*, often considered the first true **First Person Shooter (FPS)**. The goal of the project is to implement a dynamic 3D view of a maze using ray-casting techniques. Players will navigate through the maze from a first-person perspective, simulating a real-time game environment using mathematical algorithms for ray-tracing and visual rendering. The project introduces key concepts in graphics, physics, and game development.

---

#### **Objective**

The primary objective of **Cub3D** is to recreate a 3D maze using ray-casting, allowing players to explore and navigate through a labyrinth. The program will simulate a first-person view where the player can move within the maze, look around, and interact with the environment. The project challenges you to use basic programming concepts in C, graphics rendering with **MiniLibX**, and understand the fundamentals of ray-casting and 3D rendering.

The core requirements include:

- **Rendering a 3D scene** based on a 2D map with walls, floors, and ceilings.
- **Camera controls:** Player movement (W, A, S, D) and rotation (arrow keys).
- **Texture mapping:** Different textures for walls depending on the direction (North, South, East, West).
- **Dynamic scene update:** Real-time changes in view when moving or rotating.

---

#### **Core Features**

1. **Basic 3D Ray-Casting Engine:**
   - Use ray-casting to render a 3D view from a 2D map, simulating perspective and depth.
   - Calculate the distance from the player to the walls in the maze and project them onto the screen for a realistic view.

2. **Camera Controls:**
   - **W, A, S, D** for player movement (forward, left, back, right).
   - **Left and Right Arrow Keys** for rotating the camera and changing the viewing angle.
   - **Escape Key** to close the program gracefully.
   - **Clicking the red window close button** will also close the program properly.

3. **Texture Mapping:**
   - Map textures to walls based on their direction (North, South, East, West).
   - Display different textures for the floor and ceiling.
   - Handle texture loading from specified file paths in the configuration file.

4. **Map Parsing:**
   - Read and parse a *.cub map file to extract map data and textures.
   - Each map is composed of `0`s for open spaces, `1`s for walls, and one of the four directions (N, S, E, W) to mark the starting position and orientation of the player.
   - The map should be surrounded by walls, and the file should be well-formed. Any invalid map configuration results in an error.

5. **Window Management:**
   - Proper management of the window using **MiniLibX**.
   - Handle window resizing, minimize/restore, and proper closing when the user interacts with the window.
   - Display the 3D scene in real-time and allow smooth user interaction.

---

#### **Project Requirements**

- **Programming Language:** C
- **Libraries Allowed:**
  - **MiniLibX** for graphics rendering.
  - **Libc** for basic system calls (malloc, free, etc.).
  - **Math Library** (libm) for mathematical functions.
- **Makefile:**
  - Create a **Makefile** to compile the project with appropriate flags (`-Wall`, `-Wextra`, `-Werror`).
  - The Makefile must include rules for compiling, cleaning, and rebuilding the project. A **bonus** rule must also be included if implementing bonus features.

---

#### **Map File Format**

The program takes a `.cub` file as input. The map file contains several elements:

- **Textures:** File paths for the textures used in the North, South, East, and West walls.
  - Example:  
    ```
    NO ./path_to_north_texture
    SO ./path_to_south_texture
    WE ./path_to_west_texture
    EA ./path_to_east_texture
    ```

- **Colors:** RGB values for the floor and ceiling colors.
  - Example:  
    ```
    F 220,100,0
    C 225,30,0
    ```

- **Map Structure:** The maze is represented by a grid of characters:
  - `1` represents walls.
  - `0` represents open spaces.
  - `N`, `S`, `E`, `W` represent the player’s starting position and facing direction.
  - Example:
    ```
    111111
    100001
    101001
    1000N1
    111111
    ```

The map must be closed and enclosed by walls, and any invalid map configurations should prompt an error message.

---

#### **Bonus Features**

If the mandatory part is complete and correct, bonus features can be added:

1. **Collision Detection:**
   - Implement collision detection to prevent the player from walking through walls.

2. **Mini-map:**
   - Add a minimap that gives the player an overview of the maze.

3. **Moving Doors:**
   - Implement doors that can open and close, adding dynamic interactivity to the maze.

4. **Animated Sprites:**
   - Add animated objects or enemies in the maze.

5. **Mouse Control:**
   - Add mouse control for camera movement and rotation.

---

#### **Example Map**

Here is an example of a basic `.cub` map file:

```
NO ./textures/north_texture.xpm
SO ./textures/south_texture.xpm
WE ./textures/west_texture.xpm
EA ./textures/east_texture.xpm
F 220,100,0
C 225,30,0
1111111111111111
1000000000110001
1011000001110001
1001000000000001
1111111110110001
1000000000110001
1111011111111101
1111011111111101
1100000011010101
1000000000000001
1000000000000001
1100000111010101
1111011111111111
```

This file defines textures, floor/ceiling colors, and the layout of the maze, where `N` marks the player's start position.

---

#### **How to Run**

1. Clone the repository:

   ```
   git clone https://github.com/yourusername/Cub3D.git
   ```

2. Navigate to the project folder and compile:

   ```
   make
   ```

3. Run the program with a `.cub` map file:

   ```
   ./cub3D path/to/map.cub
   ```

4. Interact with the program:
   - Use **W, A, S, D** to move.
   - Use **Arrow Keys** to rotate the camera.
   - Press **Escape** or close the window to exit.

---

#### **Conclusion**

**Cub3D** is a challenging yet rewarding project that introduces fundamental concepts of 3D graphics, ray-casting, and game development. It will enhance your problem-solving skills and understanding of how basic 3D rendering engines work in real-time applications. The project also provides valuable experience in using external libraries like **MiniLibX** for graphical user interface creation and map file parsing.

