#include <TinyExtender.h>
#include "TinyWindow.h"
int main()
{
	windowManager* Manager = new windowManager();

	Manager->Initialize();
	Manager->AddWindow("TinyExtender Test");
	TinyExtender::extensionManager extensions = TinyExtender::extensionManager(); //After an OpenGL instance has been created

	extensions.InitializeExtentions();

	if (extensions.glCreateProgram != nullptr)
	{
		GLuint Program = extensions.glCreateProgram();
	}

	while(!Manager->GetWindowShouldCloseByIndex(0))
	{
		Manager->PollForEvents();
		glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Manager->WindowSwapBuffersByIndex(0);
	}

	return 0;
}
