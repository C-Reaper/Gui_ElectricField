# Project README

## Overview
This project is a simple Electric Field simulation application written in C. It allows the user to create and manipulate electric objects, observe their interactions, and simulate their movement over time.

## Features
- Basic electric field rendering.
- Interaction with electric objects (addition and deletion).
- Real-time update of object positions based on electric forces.
- Text display for current charge value.

## Project Structure
### Prerequisites
- C/C++ Compiler and Debugger (GCC, Clang)
- Make utility
- Standard development tools
- Libraries needed in specific projects: 
  - For Linux: X11, png, jpeg libraries.
  - For Windows: User32, GDI32, Winmm libraries.

## Build & Run
### Build Process
To build the project on Linux:
```bash
cd <Project>
make -f Makefile.linux all
```

For Windows:
```bash
cd <Project>
make -f Makefile.windows all
```

For Wine (Linux to Windows cross compilation):
```bash
cd <Project>
make -f Makefile.wine all
```

For WebAssembly:
```bash
cd <Project>
make -f Makefile.web all
```

### Execution
To run the compiled executable on Linux:
```bash
make -f Makefile.linux exe
```

For Windows:
```bash
make -f Makefile.windows exe
```

For Wine:
```bash
make -f Makefile.wine exe
```

For WebAssembly, you can serve the project using a web server or use Emscripten's `emrun` tool:
```bash
make -f Makefile.web exe
```
This will start a local web server and open the application in your default browser.