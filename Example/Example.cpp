#include <TinyExtender.h>
#include "TinyWindow.h"
int main()
{
	windowManager* Manager = new windowManager();

	Manager->Initialize();
	Manager->AddWindow("TinyExtender Test");

	TinyExtender::InitializeExtensions();

	GLuint Program = glCreateProgram();

	while(!Manager->GetWindowShouldCloseByIndex(0))
	{
		Manager->PollForEvents();
		glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Manager->WindowSwapBuffersByIndex(0);
	}

	return 0;
}
