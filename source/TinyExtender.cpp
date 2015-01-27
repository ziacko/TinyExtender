#include "TinyExtender.h"

GLvoid TinyExtender::InititalizeExtensions()
{
	if (GLVersion >= 1.2)
	{
		Load1_2Extensions();
	}

	if (GLVersion >= 1.3)
	{
		Load1_3Extensions();
	}

	if (GLVersion >= 1.4)
	{
		Load1_4Extensions();
	}
	if (GLVersion >= 1.5)
	{
		Load1_5Extensions();
	}

	if (GLVersion >= 2.0)
	{
		Load2_0Extensions();
	}

	if (GLVersion >= 2.1)
	{
		Load2_1Extensions();
	}

	if (GLVersion >= 3.0)
	{
		Load3_0Extensions();
	}

	if (GLVersion >= 3.1)
	{
		Load3_1Extensions();
	}

	if (GLVersion >= 3.2)
	{
		Load3_2Extensions();
	}

	if (GLVersion >= 3.3)
	{
		Load3_3Extensions();
	}

	if (GLVersion >= 4.0)
	{
		Load4_0Extensions();
	}

	if (GLVersion >= 4.1)
	{
		Load4_1Extensions();
	}

	if (GLVersion >= 4.2)
	{
		Load4_2Extensions();
	}

	if (GLVersion >= 4.3)
	{
		Load4_3Extensions();
	}

	if (GLVersion >= 4.4)
	{
		Load4_4Extensions();
	}
}

GLvoid* TinyExtender::GetProcAddress(GLchar* ProcName)
{
#if defined(_WIN32)
	return wglGetProcAddress(ProcName);
#endif

#if defined(__linux__)
	return glxGetProcAddress(ProcName);
#endif

}

GLvoid TinyExtender::Load1_2Extensions()
{
	glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)TinyExtender::GetProcAddress("glDrawRangeElements");
}