#include <TinyExtender.h>
#include "TinyWindow.h"

using namespace TinyWindow;
using namespace TinyExtender;
int main()
{
	windowManager* manager = new windowManager();
	tWindow* window = manager->AddWindow("TinyExtender example");

	InitializeExtentions();
	GLuint Program = glCreateProgram();
	printf("%i \n", Program);

	while(!window->shouldClose)
	{
		manager->PollForEvents();
		glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		window->SwapDrawBuffers();
	}

	return 0;
}
