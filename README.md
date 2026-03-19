# Handmade

A minimal, from-scratch codebase providing core functionality without external libraries.

## Modules

- **graphics** – 2D rendering API, 3D rendering API, draw calls, buffers, and basic rendering abstractions
  - handmade_graphics.cpp
  - handmade_graphics_2d.cpp
  - handmade_graphics_3d.cpp
- **input** – Keyboard, mouse, and input state handling
  - handmade_keymap.cpp
  - handmade_keymap_windows.cpp
- **maths** – Vector/matrix structs, transformations (TRS, perspective, orthographic etc.), and scalar functions (min, max, floor, ceil etc.)
  - handmade_maths.cpp
- **sound** – Audio playback and basic sound handling (.wav)
  - handmade_sound.cpp
  - handmade_sound_windows.cpp
- **windows** – Win32 window creation, message loop, and platform layer
  - handmade_windows.cpp
- **opengl** – OpenGL context setup, function loading, and rendering backend
  - handmade_opengl.cpp
  - handmade_opengl_windows.cpp

## Misc

- **handmade_string.cpp** – Custom string utilities and manipulation functions  
- **handmade_os.cpp** – Platform-level helpers (file I/O, timing, etc.)  
- **handmade_assets.cpp** – Loading and managing assets (textures, audio, etc.)  
- **handmade_animation.cpp** – Basic animation systems and interpolation  
- **handmade_memory.cpp** – Custom memory management (allocators, arenas)  
- **handmade.cpp** – Helper macros, types, and shared utilities  
