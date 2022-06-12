Required setup:

Must first configure ./include as an additional include directory, configure ./lib as
an additional linker directory, and make sure that SDL2.lib and SDL2main.lib are included within 
additional dependencies. 

Within ./include is header code for glad, KHR and SDL2, and within ./lib is library code for x64 SDL2.

Within additional dependencies, do not forget to include opengl32.lib.