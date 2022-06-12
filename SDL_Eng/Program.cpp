#include "Program.hpp"

Program::Program(int w, int h) {
	width = w;
	height = h;

	// Initialization flag
	bool success = true;
	// The window we'll be rendering to
	window = NULL;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		success = false;
	}
	else {
		//Use OpenGL 3.3 core
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		// We want to request a double buffer for smooth updating.
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

		//Create window
		window = SDL_CreateWindow("Engine",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			width,
			height,
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

		// Check if Window did not create.
		if (window == NULL) {
			success = false;
		}

		// Create an OpenGL Graphics Context and check if it failed
		openGLContext = SDL_GL_CreateContext(window);
		if (openGLContext == NULL) {
			success = false;
		}

		// Initialize GLAD Library and check if it failed
		if (!gladLoadGLLoader(SDL_GL_GetProcAddress)) {
			success = false;
		}

		//Initialize OpenGL
		if (!InitGL()) {
			success = false;
		}
	}

	// This is where objects are initialized


}

Program::~Program() {
}

void Program::Update() {

}

void Program::Render() {

}

void Program::Loop() {
	// Read input event
	SDL_Event e;
	SDL_StartTextInput();

	bool quit = false;
	while (!quit) {
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0) {
			// User posts an event to quit
			// An example is hitting the "x" in the corner of the window.
			if (e.type == SDL_QUIT) {
				quit = true;
			}

			if (e.type = SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {
				case SDLK_q:
					quit = true;
					break;
				default:
					break;
				}
			}
		} // End SDL_PollEvent loop.
		SDL_GL_SwapWindow(window);
	}
}

SDL_Window* Program::GetSDLWindow() {
	return window;
}

// Initialize OpenGL
// Setup shaders here.
bool Program::InitGL() {
	//Success flag
	bool success = true;

	// Setup our OpenGL State machine
	//glEnable(GL_DEPTH_TEST);
	//glEnable(GL_TEXTURE_2D);
	return success;
}