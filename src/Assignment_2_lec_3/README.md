# Assignment 2
## Lecture 3

**- Task 1**
**Write using GLUT to produce the following:**
![Image1](../../images/Lec3_Assignment_2_1.jpg)

**- Task 2**
**Write using GLUT to produce the following then fill in the shapes with different colors of your choice:**
![Image2](../../images/Lec3_Assignment_2_2.jpg)

## Steps to run the code:
In the terminal run the commands
```bash

cd src/Assignment_2_lec_3
g++ <file_name> .\src\imports.h -o <file_name> -I".\include" -L".\lib\x64" -lfreeglut -lopengl32 -lglu32
./<file_name>

```

or from the root directory


```bash
make -f Makefile

```
The program runs and results are displayed in order, eight windows will be opened each representing a part of the tasks.