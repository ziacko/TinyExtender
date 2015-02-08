#include <TinyExtender.h>
#include <WindowManager.h>
int main()
{
	WindowManager::Initialize();
	WindowManager::AddWindow(new FWindow("TinyExtenderTest"));

	TinyExtender::InitializeExtensions();

	GLuint Program = glCreateProgram();

	while(!WindowManager::GetWindowShouldClose("TinyExtenderTest"))
	{
		WindowManager::PollForEvents();
		glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		WindowManager::WindowSwapBuffers("TinyExtenderTest");
	}

	return 0;
}
