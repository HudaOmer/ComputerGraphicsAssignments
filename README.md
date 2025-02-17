# freeglut 3.0.0-1 for MinGW (C++)

This repository contains the freeglut 3.0.0-1 package for MinGW, including import libraries, headers, and Windows DLLs to compile 32-bit and 64-bit GLUT applications on Windows using MinGW. It also includes both static and shared versions of the freeglut library, and can be used in C++ projects.

For more information on freeglut, visit the official site:  
[freeglut SourceForge](http://freeglut.sourceforge.net/).

---

## Directory Structure
The project follows a typical structure for C++ OpenGL applications:

```go
ComputerGraphicsAssignments/
│
├── freeglut/
|   ├── bin/                     # Executable files
│   │   ├── x64/                 # Binary files
│   │   |   └── freeglut.dll     # 32-bit freeglut.dll
│   │   └── freeglut.dll         # 64-bit freeglut.dll
|   └── (placeholder for any custom DLLs)
│
├── include/                     # Header files
│   ├── GL/
│   │   ├── freeglut_ext.h       # freeglut extension header
│   │   ├── freeglut_std.h       # freeglut standard header
│   │   ├── freeglut.h           # freeglut header
│   │   └── glut.h               # GLUT header
│   └── (placeholder for any custom headers)
│
├── lib/                         # External libraries
│   ├── x64/                     # 64-bit libraries
│   │   ├── libfreeglut_static.a # 64-bit static library
│   │   └── libfreeglut.a        # 64-bit shared library
│   ├── libfreeglut_static.a
│   └── libfreeglut.a
│
├── src/                         # Source code directory
│   └── main.cpp                 # Main OpenGL application
|
├── AUTHORS                      # Author information
├── COPYING                      # License information
├── freeglut.dll                 # 32-bit freeglut.dll
├── Makefile                     # Build configuration
└── README.md                    # This file

```

## Installation

### Prerequisites
   - C++ compiler (e.g., g++ for MinGW)
   - make (for compiling the project)

1. **Clone this repository**:

   ```bash
   git clone https://github.com/HudaOmer/ComputerGraphicsAssignments.git
   cd ComputerGraphicsAssignments
   ```

2. **Adjust files to the correct architecture (32-bit or 64-bit)** based on your system.

   - If you're using a **64-bit** system, you can directly run the make file or use `g++`.
   - If you're using a **32-bit** system:
     1. Replace `.\freeglut.dll` with `.\freeglut\bin\freeglut.dll`.
     2. In the `Makefile`, replace line 2:
        ```bash
        g++ main.cpp -o main -I".\include" -L".\lib\x64" -lfreeglut -lopengl32
        ```
        with:
        ```bash
        g++ main.cpp -o main -I".\include" -L".\lib" -lfreeglut -lopengl32
        ```

---

## Compiling C++ Applications

### 32-bit Applications

To compile a C++ application with GLUT, use the following commands. For freeglut-specific extensions, include `#include <GL/freeglut.h>`, otherwise use `#include <GL/glut.h>`.

#### Example Compilation (32-bit):

Given a source file `main.cpp`, compile and link it with the following commands:

```bash
g++ -c -o main.o main.cpp -I".\include"
g++ -o main.exe main.o -L".\lib" -lfreeglut -lopengl32 -Wl,--subsystem,windows
```

Remember to include the appropriate freeglut DLL with your application or ensure that your users have access to it.

---

### 64-bit Applications

To compile 64-bit applications, the process is similar. The main difference is updating the library path to point to the `x64` directory.

#### Example Compilation (64-bit):

```bash
g++ -c -o main.o main.cpp -I".\include"
g++ -o main.exe main.o -L".\lib\x64" -lfreeglut -lopengl32 -Wl,--subsystem,windows
```

---


## Testing & Adding New Files

To test if everything is working correctly after setting it up, follow these steps:

1. Build the `main.exe` as described above using the commands for 32-bit or 64-bit.
2. Once it successfully builds and runs, you can start adding your own files to the project.
3. If you're using the `Makefile`, remember to edit it according to the new files you've added.

---

# More About the Lib
## Static Linking

To statically link the freeglut library into your C++ application, define `FREEGLUT_STATIC` during compilation and link with the static version of the library. Additionally, you need to link with the GDI and Windows multimedia libraries.

#### Example Static Compilation (32-bit):

```bash
g++ -c -o main.o main.cpp -D FREEGLUT_STATIC -I".\include"
g++ -o main.exe main.o -L".\lib" -lfreeglut_static -lopengl32 -lwinmm -lgdi32 -Wl,--subsystem,windows
```

#### Example Static Compilation (64-bit):

For a 64-bit static build, update the library path to the `x64` directory.

```bash
g++ -c -o main.o main.cpp -D FREEGLUT_STATIC -I".\include"
g++ -o main.exe main.o -L".\lib\x64" -lfreeglut_static -lopengl32 -lwinmm -lgdi32 -Wl,--subsystem,windows
```

---

## Full Tutorial

For a detailed tutorial on using GLUT and freeglut with MinGW and C++, check out this guide:  
[Using GLUT with MinGW](http://www.transmissionzero.co.uk/computing/using-glut-with-mingw/).

---

## Cross-Compilation

This repository doesn't specifically cover cross-compilation (building Windows freeglut applications from Linux). However, you can follow the same steps on Linux with appropriate path modifications.

---

## Troubleshooting

If you encounter issues during compilation (such as linker or compiler errors), ensure you've followed the steps carefully. Here are some common problems:

- Mismatched 32-bit and 64-bit libraries.
- Missing or incorrectly configured paths.

If you're still facing issues after compiling a simple example program, refer to the [Using GLUT with MinGW](http://www.transmissionzero.co.uk/computing/using-glut-with-mingw/) tutorial for a working setup.

For further support, contact:  
[Contact Transmission Zero](http://www.transmissionzero.co.uk/contact/).
[Contact Huda Omer](https://www.github.com/HudaOmer)

---

## Changelog

### 2015-03-15: Release 3.0.0-1.mp
- First release of freeglut 3.0.0 for MinGW.
- The only change is the update of the DLL version resource to distinguish between MinGW and MSVC builds.

---

Transmission Zero  
2015-03-15  
[Visit Transmission Zero](http://www.transmissionzero.co.uk/)  

---