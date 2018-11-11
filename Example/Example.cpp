#define TW_NO_CONSOLE

#include <TinyExtender.h>
#include "TinyWindow.h"

#define NO_STDIO_REDIRECT

using namespace TinyWindow;
using namespace TinyExtender;

/**< loads a text file into a string buffer */
GLchar* FileToBuffer(const GLchar* path)
{
	FILE* file = fopen(path, "rt"); // open a read only filestream

	if (file == nullptr)
	{
		printf( "Error: cannot open file %s for reading \n", path );
		return nullptr;
	}

	//get total byte in given file
	fseek(file, 0, SEEK_END); //set the position indicator to the end of the file
	size_t FileLength = ftell(file);//get the current value of the position indicator in bytes
	fseek(file, 0, SEEK_SET); //set the position indicator back to the beginning of the file

	//allocate a file buffer and read the contents of the file
	GLchar* buffer = new GLchar[FileLength + 1];
	memset(buffer, 0, FileLength + 1);
	fread(buffer, sizeof(GLchar), FileLength, file); //read from beginning to end of the file and load the data into the buffer

	fclose(file);
	return buffer;
}

/**< returns a handle to a shader program. returns 0 if failed */
GLuint LoadShader(const char* vertexSource, const char* fragmentSource)
{
	GLuint vertexShaderHandle = 0;
	GLuint fragmentShaderHandle = 0;
	GLuint programHandle = 0;

	GLint successful = 0;
	GLchar errorLog[512];

	const char* vertexShaderSource = FileToBuffer(vertexSource);
	const char* fragmentShaderSource = FileToBuffer(fragmentSource);

	vertexShaderHandle = glCreateShader(gl_vertex_shader);//create a handle to the vertex shader
	glShaderSource(vertexShaderHandle, 1, (const GLchar**)&vertexShaderSource, nullptr);//give openGL the vertex shader source code
	glCompileShader(vertexShaderHandle);//compile the vertex shader
	glGetShaderiv(vertexShaderHandle, gl_compile_status, &successful);//check if the vertex shader compiled correctly
	if (!successful)
	{
		//if not successful, get and print the error message
		glGetShaderInfoLog(vertexShaderHandle, sizeof(errorLog), nullptr, errorLog);
		printf("%s \n", errorLog);
	}

	fragmentShaderHandle = glCreateShader(gl_fragment_shader);// create a handle to the pixel shader
	glShaderSource(fragmentShaderHandle, 1, (const GLchar**)&fragmentShaderSource, nullptr);// give OpenGL the fragment shader source code
	glCompileShader(fragmentShaderHandle);//compile the fragment shader
	

	if (glGetShaderiv)
	{
		glGetShaderiv(fragmentShaderHandle, gl_compile_status, &successful);//check if the fragment shader compiled correctly
	}

	if (!successful)
	{
		//if not successful, get and print the error message
		glGetShaderInfoLog(vertexShaderHandle, sizeof(errorLog), nullptr, errorLog);
		printf("%s \n", errorLog);
	}

	programHandle = glCreateProgram();//create a handle to the shader program
	glAttachShader(programHandle, vertexShaderHandle);//attach the vertex shader to the shader program
	glAttachShader(programHandle, fragmentShaderHandle);//attach the fragment shader to the shader program
	glLinkProgram(programHandle);//link the attached shaders together
	glGetProgramiv(programHandle, gl_link_status, &successful);//check if the shaders linked successfully
	if (!successful)
	{
		//if not successful, get and print the error message
		glGetProgramInfoLog(programHandle, sizeof(errorLog), nullptr, errorLog);
		printf("%s \n", errorLog);
	}

	return programHandle;
}

int main()
{
	windowManager* manager = new windowManager();
	tWindow* window = manager->AddWindow("TinyExtender example");

	InitializeExtentions();

	GLuint programHandle = LoadShader("Example.vert", "Example.frag");

	glPointSize(20.0f);
	glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
	glUseProgram(programHandle);

	while(!window->shouldClose)
	{
		manager->PollForEvents();
		glDrawArrays(GL_POINTS, 0, 1);//I just need one point for this
		window->SwapDrawBuffers();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	glDeleteProgram(programHandle);
	return 0;
}
