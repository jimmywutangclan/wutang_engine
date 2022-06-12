#include "SDL2/SDL.h"
#include "Program.hpp"

int main(int argc, char* argv[]) {
	
	Program prog(1280, 720);
	prog.Loop();

	return 0;
}