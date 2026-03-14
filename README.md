*This project has been created as part of the 42 curriculum by cycolonn.*

# 🌀 fract'ol - Technical Documentation

<p align="center">
  <img src="./assets/demo.gif" alt="Fractol Demo" width="600">
</p>

## 1. Description
**fract'ol** is a computer graphics project designed to create a graphically beautiful fractal exploration program. The objective is to become familiar with the **MiniLibX** library, discover the mathematical concept of **complex numbers**, and practice event handling through real-time navigation in infinite mathematical sets.

---

<br />

## 2. Instructions & Interactive Controls
This implementation offers an interactive experience where most rendering options are managed directly through keyboard and mouse hooks.

---

<br />

* **Fractal Sets**: Support for the **Mandelbrot** set, various **Julia** sets, and the additional **Burning Ship** fractal (Bonus).
* **Live Julia Morphing**: Use the keyboard to modify the real and imaginary constants of the Julia set in real-time.
* **Navigation**:
    * **Zoom**: Mouse wheel for infinite zooming (follows actual mouse position).
    * **Movement**: Arrow keys to pan across the complex plane.
* **Resets**: Dedicated keys to reset the zoom level or return the Julia constant $C$ to its default value.
* **Clean Exit**: Pressing `ESC` or clicking the window's cross properly frees all memory and quits the program.

---

<br />

## 3. Resources & Technical Choices
The architecture of this project focuses on performance and user interaction.

---

<br />

### 🧠 Mathematical Core
* **Complex Mapping**: Pixels are mapped to a mathematical plane (initially between -2 and 2) to determine their membership in the fractal set.
* **Iteration Depth**: Depth is revealed using a range of colors to visualize the speed at which points escape to infinity.
* **Interactive Parameters**: By using `mlx_hook`, the program listens for specific keypresses to increment or decrement the Julia constant, allowing users to watch the fractal "morph" dynamically.

---

<br />

### 🛠️ Graphic Library: MiniLibX
* **External Dependency**: This project uses the **MiniLibX (Linux version)**. Note: The library source code is not provided in this repository; users must install X11 and MLX dependencies independently.
* **Image Buffering**: To ensure smooth rendering and window management, we draw to a `t_data` image structure before pushing it to the window with `mlx_put_image_to_window`.

---

<br />

### 🤖 AI Usage & Methodology
As per 42 curriculum requirements, AI was used as a learning assistant:
* **Tasks**: AI assisted in designing the `rules()` display interface and clarified the bit-shifting logic required for the color range shift bonus.
* **Validation**: All AI-suggested code was critically assessed and tested with peers to ensure full understanding and compliance with the Norm.

---

<br />

### 🔗 Useful Links
* **[Mandelbrot Set](https://en.wikipedia.org/wiki/Mandelbrot_set)**: Understanding the foundation of the escape time algorithm.
* **[The Julia Set](https://en.wikipedia.org/wiki/Julia_set)**: Relationship between $c$ parameters and fractal shapes.
* **[Burning Ship Fractal](https://en.wikipedia.org/wiki/Burning_Ship_fractal)**: Specific absolute value logic for the additional fractal type.

---

<br />

## 💻 How to Compile and Run
Ensure your system has the MiniLibX (X11) dependencies installed:

---

<br />

```bash
# Clone the repository
git clone [https://github.com/Cyril-glitch/fractol.git](https://github.com/Cyril-glitch/fractol.git)

# Navigate and compile
cd fractol
make

# Run the program
./fractol mandelbrot
./fractol julia
./fractol burning

# Interactive Keys:
# - [Mouse Wheel]       : Zoom In/Out
# - [Mouse Wheel Click] : Reset Zoom
# - [Arrow Keys]        : Move view
# - [A] / [D]           : Modify Real Part (Julia)
# - [J] / [L]           : Modify Imaginary Part (Julia)
# - [K]                 : Reset Constant C
# - [ESC]               : Quit
