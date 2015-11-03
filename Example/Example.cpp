#include <TinyExtender.h>
#include "TinyWindow.h"
int main()
{
	windowManager* manager = new windowManager();
	manager->AddWindow("TinyExtender Example");

	tinyExtender* extender = new tinyExtender();

	extender->InitializeExtensions();

	GLuint Program = extender->glCreateProgram();

	while(!manager->GetWindowShouldCloseByIndex(0))
	{
		manager->PollForEvents();
		glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		manager->WindowSwapBuffersByIndex(0);
	}

	return 0;
}
