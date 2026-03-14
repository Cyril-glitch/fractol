*This project has been created as part of the 42 curriculum by cycolonn.*

# 🌀 fract'ol - Technical Documentation

## 1. Description
**fract'ol** is a computer graphics project focused on creating a graphically beautiful fractal exploration program. The goal is to discover the mathematical concept of complex numbers and explore optimization techniques in a graphical environment using the MiniLibX library.

---

<br />

## 2. Instructions & Interactive Controls
Unlike static fractal viewers, this implementation allows for real-time manipulation of the rendering parameters through keyboard and mouse hooks:

---

<br />

* **Fractal Sets**: Support for **Mandelbrot**, **Julia**, and the additional **Burning Ship** set.
* **Dynamic Julia Evolution**: While in the Julia set, users can modify the real (`a`) and imaginary (`b`) parts of the constant $C$ in real-time using keys.
* **Navigation**: 
    * **Zoom**: Mouse wheel for infinite zooming (follows mouse position for precision).
    * **Movement**: Arrow keys to pan across the complex plane.
* **Resets**: Dedicated keys to reset the zoom level or the constant $C$ to its default values.
* **Exit Management**: Clean termination using the `ESC` key or by clicking the window's red cross.

---

<br />

## 3. Resources & Technical Choices
The development of this project required a balance between mathematical precision and graphical performance:

---

<br />

### 🧠 Mathematical Core & Real-time Interaction
* **Complex Mapping**: Every pixel is mapped to the complex plane, initially ranging from $-2$ to $+2$ for both axes.
* **Interactive Parameters**: By using `mlx_hook`, the program listens for specific keypresses (`A`, `D`, `J`, `L`) to increment or decrement the Julia constant, allowing users to watch the fractal "morph" dynamically.
* **Escape Time Algorithm**: The program determines the color of each pixel based on how many iterations it takes for $z$ to escape the radius of 2.

---

<br />

### 🛠️ Graphic Library: MiniLibX
* **External Dependency**: This project requires the **MiniLibX (Linux version)**. Please note that the library's source code is **not provided** in this repository. Users must install the necessary X11 dependencies and the MLX library separately.
* **Image Buffering**: To ensure smooth rendering and window management (minimizing/maximizing), we draw to a `t_data` image structure before pushing it to the window with `mlx_put_image_to_window`.

---

<br />

### 🤖 AI Usage & Methodology
In accordance with the 42 curriculum guidelines:
* **Tasks**: AI was used to assist in designing the `rules()` display logic and to clarify the bit-shifting required for custom T-R-G-B color gradients.
* **Validation**: All logic, especially the event handling for keyboard-based parameter modification, was manually verified and tested against the project requirements.

---

<br />

### 🔗 Useful Links
* **[Mandelbrot Set](https://en.wikipedia.org/wiki/Mandelbrot_set)**: Understanding the foundation of the escape time algorithm.
* **[The Julia Set](https://en.wikipedia.org/wiki/Julia_set)**: Relationship between $c$ parameters and fractal shapes.
* **[Burning Ship Fractal](https://en.wikipedia.org/wiki/Burning_Ship_fractal)**: Specific absolute value logic for the additional fractal type.

---

<br />

## 💻 How to Compile and Run
Ensure your system has the MiniLibX (X11) dependencies installed before compiling:

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
# - [Mouse Wheel]    : Zoom In/Out
# - [Wheel Click]    : Reset Zoom
# - [Arrow Keys]     : Move view
# - [A] / [D]        : Modify Real Part (Julia)
# - [J] / [L]        : Modify Imaginary Part (Julia)
# - [K]              : Reset Constant C
# - [ESC]            : Quit
