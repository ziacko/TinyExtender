#include "TinyExtender.h"

//OpenGL 1.2 Extensions
PFNGLDRAWRANGEELEMENTSPROC __teDrawRangeElements = 0;
PFNGLTEXIMAGE3DPROC __teTexImage3D = 0;
PFNGLTEXSUBIMAGE3DPROC __teTexSubImage3D = 0;
PFNGLCOPYTEXSUBIMAGE3DPROC __teCopyTexSubImage3D = 0;
//OpenGL 1.3 Extensions
PFNGLACTIVETEXTUREPROC __teActiveTexture = 0;
PFNGLSAMPLECOVERAGEPROC __teSampleCoverage = 0;
PFNGLCOMPRESSEDTEXIMAGE3DPROC __teCompressedTexImage3D = 0;
PFNGLCOMPRESSEDTEXIMAGE2DPROC __teCompressedTexImage2D = 0;
PFNGLCOMPRESSEDTEXIMAGE1DPROC __teCompressedTexImage1D = 0;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC __teCompressedTexSubImage3D = 0;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC __teCompressedTexSubImage2D = 0;
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC __teCompressedTexSubImage1D = 0;
PFNGLGETCOMPRESSEDTEXIMAGEPROC __teGetCompressedTexImage = 0;
/*PFNGLCLIENTACTIVETEXTUREPROC __teClientActiveTexture = 0;
PFNGLMULTITEXCOORD1DPROC __teMultiTexCoord1d = 0;
PFNGLMULTITEXCOORD1DVPROC __teMultiTexCoord1dv = 0;
PFNGLMULTITEXCOORD1FPROC __teMultiTexCoord1f = 0;
PFNGLMULTITEXCOORD1FVPROC __teMultiTexCoord1fv = 0;
PFNGLMULTITEXCOORD1IPROC __teMultiTexCoord1i = 0;
PFNGLMULTITEXCOORD1IVPROC __teMultiTexCoord1iv = 0;
PFNGLMULTITEXCOORD1SPROC __teMultiTexCoord1s = 0;
PFNGLMULTITEXCOORD1SVPROC __teMultiTexCoord1sv = 0;
PFNGLMULTITEXCOORD2DPROC __teMultiTexCoord2d = 0;
PFNGLMULTITEXCOORD2DVPROC __teMultiTexCoord2dv = 0;
PFNGLMULTITEXCOORD2FPROC __teMultiTexCoord2f = 0;
PFNGLMULTITEXCOORD2FVPROC __teMultiTexCoord2fv = 0;
PFNGLMULTITEXCOORD2IPROC __teMultiTexCoord2i = 0;
PFNGLMULTITEXCOORD2IVPROC __teMultiTexCoord2iv = 0;
PFNGLMULTITEXCOORD2SPROC __teMultiTexCoord2s = 0;
PFNGLMULTITEXCOORD2SVPROC __teMultiTexCoord2sv = 0;
PFNGLMULTITEXCOORD3DPROC __teMultiTexCoord3d = 0;
PFNGLMULTITEXCOORD3DVPROC __teMultiTexCoord3dv = 0;
PFNGLMULTITEXCOORD3FPROC __teMultiTexCoord3f = 0;
PFNGLMULTITEXCOORD3FVPROC __teMultiTexCoord3fv = 0;
PFNGLMULTITEXCOORD3IPROC __teMultiTexCoord3i = 0;
PFNGLMULTITEXCOORD3IVPROC __teMultiTexCoord3iv = 0;
PFNGLMULTITEXCOORD3SPROC __teMultiTexCoord3s = 0;
PFNGLMULTITEXCOORD3SVPROC __teMultiTexCoord3sv = 0;
PFNGLMULTITEXCOORD4DPROC __teMultiTexCoord4d = 0;
PFNGLMULTITEXCOORD4DVPROC __teMultiTexCoord4dv = 0;
PFNGLMULTITEXCOORD4FPROC __teMultiTexCoord4f = 0;
PFNGLMULTITEXCOORD4FVPROC __teMultiTexCoord4fv = 0;
PFNGLMULTITEXCOORD4IPROC __teMultiTexCoord4i = 0;
PFNGLMULTITEXCOORD4IVPROC __teMultiTexCoord4iv = 0;
PFNGLMULTITEXCOORD4SPROC __teMultiTexCoord4s = 0;
PFNGLMULTITEXCOORD4SVPROC __teMultiTexCoord4sv = 0;
PFNGLLOADTRANSPOSEMATRIXFPROC __teLoadTransposeMatrixf = 0;
PFNGLLOADTRANSPOSEMATRIXDPROC __teLoadTransposeMatrixd = 0;
PFNGLMULTTRANSPOSEMATRIXFPROC __teMultTransposeMatrixf = 0;
PFNGLMULTTRANSPOSEMATRIXDPROC __teMultTransposeMatrixd = 0;*/

//OpenGL 1.4 Extensions
PFNGLBLENDFUNCSEPARATEPROC __teBlendFuncSeparate = 0;
PFNGLMULTIDRAWARRAYSPROC __teMultiDrawArrays = 0;
PFNGLMULTIDRAWELEMENTSPROC __teMultiDrawElements = 0;
PFNGLPOINTPARAMETERFPROC __tePointParameterf = 0;
PFNGLPOINTPARAMETERFVPROC __tePointParameterfv = 0;
PFNGLPOINTPARAMETERIPROC __tePointParameteri = 0;
PFNGLPOINTPARAMETERIVPROC __tePointParameteriv = 0;
PFNGLFOGCOORDFPROC __teFogCoordf = 0;
PFNGLFOGCOORDFVPROC __teFogCoordfv = 0;
PFNGLFOGCOORDDPROC __teFogCoordd = 0;
PFNGLFOGCOORDDVPROC __teFogCoorddv = 0;
PFNGLFOGCOORDPOINTERPROC __teFogCoordPointer = 0;
PFNGLSECONDARYCOLOR3BPROC __teSecondaryColor3b = 0;
PFNGLSECONDARYCOLOR3BVPROC __teSecondaryColor3bv = 0;
PFNGLSECONDARYCOLOR3DPROC __teSecondaryColor3d = 0;
PFNGLSECONDARYCOLOR3DVPROC __teSecondaryColor3dv = 0;
PFNGLSECONDARYCOLOR3FPROC __teSecondaryColor3f = 0;
PFNGLSECONDARYCOLOR3FVPROC __teSecondaryColor3fv = 0;
PFNGLSECONDARYCOLOR3IPROC __teSecondaryColor3i = 0;
PFNGLSECONDARYCOLOR3IVPROC __teSecondaryColor3iv = 0;
PFNGLSECONDARYCOLOR3SPROC __teSecondaryColor3s = 0;
PFNGLSECONDARYCOLOR3SVPROC __teSecondaryColor3sv = 0;
PFNGLSECONDARYCOLOR3UBPROC __teSecondaryColor3ub = 0;
PFNGLSECONDARYCOLOR3UBVPROC __teSecondaryColor3ubv = 0;
PFNGLSECONDARYCOLOR3UIPROC __teSecondaryColor3ui = 0;
PFNGLSECONDARYCOLOR3UIVPROC __teSecondaryColor3uiv = 0;
PFNGLSECONDARYCOLOR3USPROC __teSecondaryColor3us = 0;
PFNGLSECONDARYCOLOR3USVPROC __teSecondaryColor3usv = 0;
PFNGLSECONDARYCOLORPOINTERPROC __teSecondaryColorPointer = 0;
PFNGLWINDOWPOS2DPROC __teWindowPos2d = 0;
PFNGLWINDOWPOS2DVPROC __teWindowPos2dv = 0;
PFNGLWINDOWPOS2FPROC __teWindowPos2f = 0;
PFNGLWINDOWPOS2FVPROC __teWindowPos2fv = 0;
PFNGLWINDOWPOS2IPROC __teWindowPos2i = 0;
PFNGLWINDOWPOS2IVPROC __teWindowPos2iv = 0;
PFNGLWINDOWPOS2SPROC __teWindowPos2s = 0;
PFNGLWINDOWPOS2SVPROC __teWindowPos2sv = 0;
PFNGLWINDOWPOS3DPROC __teWindowPos3d = 0;
PFNGLWINDOWPOS3DVPROC __teWindowPos3dv = 0;
PFNGLWINDOWPOS3FPROC __teWindowPos3f = 0;
PFNGLWINDOWPOS3FVPROC __teWindowPos3fv = 0;
PFNGLWINDOWPOS3IPROC __teWindowPos3i = 0;
PFNGLWINDOWPOS3IVPROC __teWindowPos3iv = 0;
PFNGLWINDOWPOS3SPROC __teWindowPos3s = 0;
PFNGLWINDOWPOS3SVPROC __teWindowPos3sv = 0;
PFNGLBLENDCOLORPROC __teBlendColor = 0;
PFNGLBLENDEQUATIONPROC __teBlendEquation = 0;
//OpenGL 1.5 Extensions
PFNGLGENQUERIESPROC __teGenQueries = 0;
PFNGLDELETEQUERIESPROC __teDeleteQueries = 0;
PFNGLISQUERYPROC __teIsQuery = 0;
PFNGLBEGINQUERYPROC __teBeginQuery = 0;
PFNGLENDQUERYPROC __teEndQuery = 0;
PFNGLGETQUERYIVPROC __teGetQueryiv = 0;
PFNGLGETQUERYOBJECTIVPROC __teGetQueryObjectiv = 0;
PFNGLGETQUERYOBJECTUIVPROC __teGetQueryObjectuiv = 0;
PFNGLBINDBUFFERPROC __teBindBuffer = 0;
PFNGLDELETEBUFFERSPROC __teDeleteBuffers = 0;
PFNGLGENBUFFERSPROC __teGenBuffers = 0;
PFNGLISBUFFERPROC __teIsBuffer = 0;
PFNGLBUFFERDATAPROC __teBufferData = 0;
PFNGLBUFFERSUBDATAPROC __teBufferSubData = 0;
PFNGLGETBUFFERSUBDATAPROC __teGetBufferSubData = 0;
PFNGLMAPBUFFERPROC __teMapBuffer = 0;
PFNGLUNMAPBUFFERPROC __teUnmapBuffer = 0;
PFNGLGETBUFFERPARAMETERIVPROC __teGetBufferParameteriv = 0;
PFNGLGETBUFFERPOINTERVPROC __teGetBufferPointerv = 0;
//OpenGL 2.0 Extensions
PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate = 0;
PFNGLDRAWBUFFERSPROC __teDrawBuffers = 0;
PFNGLSTENCILOPSEPARATEPROC __teStencilOpSeparate = 0;
PFNGLSTENCILFUNCSEPARATEPROC __teStencilFuncSeparate = 0;
PFNGLSTENCILMASKSEPARATEPROC __teStencilMaskSeparate = 0;
PFNGLATTACHSHADERPROC __teAttachShader = 0;
PFNGLBINDATTRIBLOCATIONPROC __teBindAttribLocation = 0;
PFNGLCOMPILESHADERPROC __teCompileShader = 0;
PFNGLCREATEPROGRAMPROC __teCreateProgram = 0;
PFNGLCREATESHADERPROC __teCreateShader = 0;
PFNGLDELETEPROGRAMPROC __teDeleteProgram = 0;
PFNGLDELETESHADERPROC __teDeleteShader = 0;
PFNGLDETACHSHADERPROC __teDetachShader = 0;
PFNGLDISABLEVERTEXATTRIBARRAYPROC __teDisableVertexAttribArray = 0;
PFNGLENABLEVERTEXATTRIBARRAYPROC __teEnableVertexAttribArray = 0;
PFNGLGETACTIVEATTRIBPROC __teGetActiveAttrib = 0;
PFNGLGETACTIVEUNIFORMPROC __teGetActiveUniform = 0;
PFNGLGETATTACHEDSHADERSPROC __teGetAttachedShaders = 0;
PFNGLGETATTRIBLOCATIONPROC __teGetAttribLocation = 0;
PFNGLGETPROGRAMIVPROC __teGetProgramiv = 0;
PFNGLGETPROGRAMINFOLOGPROC __teGetProgramInfoLog = 0;
PFNGLGETSHADERIVPROC __teGetShaderiv = 0;
PFNGLGETSHADERINFOLOGPROC __teGetShaderInfoLog = 0;
PFNGLGETSHADERSOURCEPROC __teGetShaderSource = 0;
PFNGLGETUNIFORMLOCATIONPROC __teGetUniformLocation = 0;
PFNGLGETUNIFORMFVPROC __teGetUniformfv = 0;
PFNGLGETUNIFORMIVPROC __teGetUniformiv = 0;
PFNGLGETVERTEXATTRIBDVPROC __teGetVertexAttribdv = 0;
PFNGLGETVERTEXATTRIBFVPROC __teGetVertexAttribfv = 0;
PFNGLGETVERTEXATTRIBIVPROC __teGetVertexAttribiv = 0;
PFNGLGETVERTEXATTRIBPOINTERVPROC __teGetVertexAttribPointerv = 0;
PFNGLISPROGRAMPROC __teIsProgram = 0;
PFNGLISSHADERPROC __teIsShader = 0;
PFNGLLINKPROGRAMPROC __teLinkProgram = 0;
PFNGLSHADERSOURCEPROC __teShaderSource = 0;
PFNGLUSEPROGRAMPROC __teUseProgram = 0;
PFNGLUNIFORM1FPROC __teUniform1f = 0;
PFNGLUNIFORM2FPROC __teUniform2f = 0;
PFNGLUNIFORM3FPROC __teUniform3f = 0;
PFNGLUNIFORM4FPROC __teUniform4f = 0;
PFNGLUNIFORM1IPROC __teUniform1i = 0;
PFNGLUNIFORM2IPROC __teUniform2i = 0;
PFNGLUNIFORM3IPROC __teUniform3i = 0;
PFNGLUNIFORM4IPROC __teUniform4i = 0;
PFNGLUNIFORM1FVPROC __teUniform1fv = 0;
PFNGLUNIFORM2FVPROC __teUniform2fv = 0;
PFNGLUNIFORM3FVPROC __teUniform3fv = 0;
PFNGLUNIFORM4FVPROC __teUniform4fv = 0;
PFNGLUNIFORM1IVPROC __teUniform1iv = 0;
PFNGLUNIFORM2IVPROC __teUniform2iv = 0;
PFNGLUNIFORM3IVPROC __teUniform3iv = 0;
PFNGLUNIFORM4IVPROC __teUniform4iv = 0;
PFNGLUNIFORMMATRIX2FVPROC __teUniformMatrix2fv = 0;
PFNGLUNIFORMMATRIX3FVPROC __teUniformMatrix3fv = 0;
PFNGLUNIFORMMATRIX4FVPROC __teUniformMatrix4fv = 0;
PFNGLVALIDATEPROGRAMPROC __teValidateProgram = 0;
PFNGLVERTEXATTRIB1DPROC __teVertexAttrib1d = 0;
PFNGLVERTEXATTRIB1DVPROC __teVertexAttrib1dv = 0;
PFNGLVERTEXATTRIB1FPROC __teVertexAttrib1f = 0;
PFNGLVERTEXATTRIB1FVPROC __teVertexAttrib1fv = 0;
PFNGLVERTEXATTRIB1SPROC __teVertexAttrib1s = 0;
PFNGLVERTEXATTRIB1SVPROC __teVertexAttrib1sv = 0;
PFNGLVERTEXATTRIB2DPROC __teVertexAttrib2d = 0;
PFNGLVERTEXATTRIB2DVPROC __teVertexAttrib2dv = 0;
PFNGLVERTEXATTRIB2FPROC __teVertexAttrib2f = 0;
PFNGLVERTEXATTRIB2FVPROC __teVertexAttrib2fv = 0;
PFNGLVERTEXATTRIB2SPROC __teVertexAttrib2s = 0;
PFNGLVERTEXATTRIB2SVPROC __teVertexAttrib2sv = 0;
PFNGLVERTEXATTRIB3DPROC __teVertexAttrib3d = 0;
PFNGLVERTEXATTRIB3DVPROC __teVertexAttrib3dv = 0;
PFNGLVERTEXATTRIB3FPROC __teVertexAttrib3f = 0;
PFNGLVERTEXATTRIB3FVPROC __teVertexAttrib3fv = 0;
PFNGLVERTEXATTRIB3SPROC __teVertexAttrib3s = 0;
PFNGLVERTEXATTRIB3SVPROC __teVertexAttrib3sv = 0;
PFNGLVERTEXATTRIB4NBVPROC __teVertexAttrib4Nbv = 0;
PFNGLVERTEXATTRIB4NIVPROC __teVertexAttrib4Niv = 0;
PFNGLVERTEXATTRIB4NSVPROC __teVertexAttrib4Nsv = 0;
PFNGLVERTEXATTRIB4NUBPROC __teVertexAttrib4Nub = 0;
PFNGLVERTEXATTRIB4NUBVPROC __teVertexAttrib4Nubv = 0;
PFNGLVERTEXATTRIB4NUIVPROC __teVertexAttrib4Nuiv = 0;
PFNGLVERTEXATTRIB4NUSVPROC __teVertexAttrib4Nusv = 0;
PFNGLVERTEXATTRIB4BVPROC __teVertexAttrib4bv = 0;
PFNGLVERTEXATTRIB4DPROC __teVertexAttrib4d = 0;
PFNGLVERTEXATTRIB4DVPROC __teVertexAttrib4dv = 0;
PFNGLVERTEXATTRIB4FPROC __teVertexAttrib4f = 0;
PFNGLVERTEXATTRIB4FVPROC __teVertexAttrib4fv = 0;
PFNGLVERTEXATTRIB4IVPROC __teVertexAttrib4iv = 0;
PFNGLVERTEXATTRIB4SPROC __teVertexAttrib4s = 0;
PFNGLVERTEXATTRIB4SVPROC __teVertexAttrib4sv = 0;
PFNGLVERTEXATTRIB4UBVPROC __teVertexAttrib4ubv = 0;
PFNGLVERTEXATTRIB4UIVPROC __teVertexAttrib4uiv = 0;
PFNGLVERTEXATTRIB4USVPROC __teVertexAttrib4usv = 0;
PFNGLVERTEXATTRIBPOINTERPROC __teVertexAttribPointer = 0;

//OpenGL 2.1 Extensions
PFNGLUNIFORMMATRIX2X3FVPROC __teUniformMatrix2x3fv = 0;
PFNGLUNIFORMMATRIX3X2FVPROC __teUniformMatrix3x2fv = 0;
PFNGLUNIFORMMATRIX2X4FVPROC __teUniformMatrix2x4fv = 0;
PFNGLUNIFORMMATRIX4X2FVPROC __teUniformMatrix4x2fv = 0;
PFNGLUNIFORMMATRIX3X4FVPROC __teUniformMatrix3x4fv = 0;
PFNGLUNIFORMMATRIX4X3FVPROC __teUniformMatrix4x3fv = 0;

GLvoid TinyExtender::InitializeExtensions()
{
	//Load1_2Extensions();
	//Load1_3Extensions();
	//Load1_4Extensions();
	//Load1_5Extensions();
	Load2_0Extensions();
	//Load2_1Extensions();
}

void* TinyExtender::GetProcAddress(const GLubyte* ProcName)
{
#if defined(_WIN32)
	return wglGetProcAddress(ProcName);
#endif

#if defined(__linux__)
	return glXGetProcAddress(ProcName);
#endif

}

GLvoid TinyExtender::Load1_2Extensions()
{
	glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDrawRangeElements");
	glTexImage3D = (PFNGLTEXIMAGE3DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glTexImage3D");
	glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glTexSubImage3D");
	glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glCopyTexSubImage3D");
}

GLvoid TinyExtender::Load1_3Extensions()
{
	glActiveTexture = (PFNGLACTIVETEXTUREPROC)TinyExtender::GetProcAddress((const GLubyte*)"glActiveTexture");
	glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSampleCoverage");
	glCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glCompressedTexImage3D");
	glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glCompressedTexImage2D");
	glCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glCompressedTexImage1D");
	glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glCompressedTexSubImage3D");
	glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glCompressedTexSubImage2D");
	glCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glCompressedTexSubImage1D");
	glGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetCompressedTexImage");
}

GLvoid TinyExtender::Load1_4Extensions()
{
	glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBlendFuncSeparate");
	glMultiDrawArrays = (PFNGLMULTIDRAWARRAYSPROC)TinyExtender::GetProcAddress((const GLubyte*)"glMultiDrawArrays");
	glMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC)TinyExtender::GetProcAddress((const GLubyte*)"glMultiDrawElements");
	glPointParameterf = (PFNGLPOINTPARAMETERFPROC)TinyExtender::GetProcAddress((const GLubyte*)"glPointParameterf");
	glPointParameterfv = (PFNGLPOINTPARAMETERFVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glPointParameterfv");
	glPointParameteri = (PFNGLPOINTPARAMETERIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glPointParameteri");
	glPointParameteriv = (PFNGLPOINTPARAMETERIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glPointParameteriv");
	glFogCoordf = (PFNGLFOGCOORDFPROC)TinyExtender::GetProcAddress((const GLubyte*)"glFogCoordf");
	glFogCoordfv = (PFNGLFOGCOORDFVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glFogCoordfv");
	glFogCoordd = (PFNGLFOGCOORDDPROC)TinyExtender::GetProcAddress((const GLubyte*)"glFogCoordd");
	glFogCoorddv = (PFNGLFOGCOORDDVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glFogCoorddv");
	glFogCoordPointer = (PFNGLFOGCOORDPOINTERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glFogCoordPointer");
	glSecondaryColor3b = (PFNGLSECONDARYCOLOR3BPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSecondaryColor3b");
	glSecondaryColor3bv = (PFNGLSECONDARYCOLOR3BVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSecondaryColor3bv");
	glSecondaryColor3d = (PFNGLSECONDARYCOLOR3DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSecondaryColor3d");
	glSecondaryColor3dv = (PFNGLSECONDARYCOLOR3DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSecondaryColor3dv");
	glSecondaryColor3f = (PFNGLSECONDARYCOLOR3FPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSecondaryColor3f");
	glSecondaryColor3fv = (PFNGLSECONDARYCOLOR3FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSecondaryColor3fv");
	glSecondaryColor3i = (PFNGLSECONDARYCOLOR3IPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSecondaryColor3i");
	glSecondaryColor3iv = (PFNGLSECONDARYCOLOR3IVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSecondaryColor3iv");
	glSecondaryColor3s = (PFNGLSECONDARYCOLOR3SPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSecondaryColor3s");
	glSecondaryColor3sv = (PFNGLSECONDARYCOLOR3SVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSecondaryColor3sv");
	glSecondaryColor3ub = (PFNGLSECONDARYCOLOR3UBPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSecondaryColor3ub");
	glSecondaryColor3ubv = (PFNGLSECONDARYCOLOR3UBVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSecondaryColor3ubv");
	glSecondaryColor3ui = (PFNGLSECONDARYCOLOR3UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSecondaryColor3ui");
	glSecondaryColor3uiv = (PFNGLSECONDARYCOLOR3UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSecondaryColor3uiv");
	glSecondaryColor3us = (PFNGLSECONDARYCOLOR3USPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSecondaryColor3us");
	glSecondaryColor3usv = (PFNGLSECONDARYCOLOR3USVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSecondaryColor3usv");
	glSecondaryColorPointer = (PFNGLSECONDARYCOLORPOINTERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSecondaryColorPointer");
	glWindowPos2d = (PFNGLWINDOWPOS2DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glWindowPos2d");
	glWindowPos2dv = (PFNGLWINDOWPOS2DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glWindowPos2dv");
	glWindowPos2f = (PFNGLWINDOWPOS2FPROC)TinyExtender::GetProcAddress((const GLubyte*)"glWindowPos2f");
	glWindowPos2fv = (PFNGLWINDOWPOS2FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glWindowPos2fv");
	glWindowPos2i = (PFNGLWINDOWPOS2IPROC)TinyExtender::GetProcAddress((const GLubyte*)"glWindowPos2i");
	glWindowPos2iv = (PFNGLWINDOWPOS2IVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glWindowPos2iv");
	glWindowPos2s = (PFNGLWINDOWPOS2SPROC)TinyExtender::GetProcAddress((const GLubyte*)"glWindowPos2s");
	glWindowPos2sv = (PFNGLWINDOWPOS2SVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glWindowPos2sv");
	glWindowPos3d = (PFNGLWINDOWPOS3DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glWindowPos3d");
	glWindowPos3dv = (PFNGLWINDOWPOS3DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glWindowPos3dv");
	glWindowPos3f = (PFNGLWINDOWPOS3FPROC)TinyExtender::GetProcAddress((const GLubyte*)"glWindowPos3f");
	glWindowPos3fv = (PFNGLWINDOWPOS3FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glWindowPos3fv");
	glWindowPos3i = (PFNGLWINDOWPOS3IPROC)TinyExtender::GetProcAddress((const GLubyte*)"glWindowPos3i");
	glWindowPos3iv = (PFNGLWINDOWPOS3IVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glWindowPos3iv");
	glWindowPos3s = (PFNGLWINDOWPOS3SPROC)TinyExtender::GetProcAddress((const GLubyte*)"glWindowPos3s");
	glWindowPos3sv = (PFNGLWINDOWPOS3SVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glWindowPos3sv");
	glBlendColor = (PFNGLBLENDCOLORPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBlendColor");
	glBlendEquation = (PFNGLBLENDEQUATIONPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBlendEquation");
}

GLvoid TinyExtender::Load1_5Extensions()
{
	glGenQueries = (PFNGLGENQUERIESPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGenQueries");
	glDeleteQueries = (PFNGLDELETEQUERIESPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDeleteQueries");
	glIsQuery = (PFNGLISQUERYPROC)TinyExtender::GetProcAddress((const GLubyte*)"glIsQuery");
	glBeginQuery = (PFNGLBEGINQUERYPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBeginQuery");
	glEndQuery = (PFNGLENDQUERYPROC)TinyExtender::GetProcAddress((const GLubyte*)"glEndQuery");
	glGetQueryiv = (PFNGLGETQUERYIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetQueryiv");
	glGetQueryObjectiv = (PFNGLGETQUERYOBJECTIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetQueryObjectiv");
	glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetQueryObjectuiv");
	glBindBuffer = (PFNGLBINDBUFFERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBindBuffer");
	glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDeleteBuffers");
	glGenBuffers = (PFNGLGENBUFFERSPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGenBuffers");
	glIsBuffer = (PFNGLISBUFFERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glIsBuffer");
	glBufferData = (PFNGLBUFFERDATAPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBufferData");
	glBufferSubData = (PFNGLBUFFERSUBDATAPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBufferSubData");
	glGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetBufferSubData");
	glMapBuffer = (PFNGLMAPBUFFERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glMapBuffer");
	glUnmapBuffer = (PFNGLUNMAPBUFFERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUnmapBuffer");
	glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetBufferParameteriv");
	glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetBufferPointerv");
}

GLvoid TinyExtender::Load2_0Extensions()
{
	glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBlendEquationSeperate");
	glDrawBuffers = (PFNGLDRAWBUFFERSPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDrawBuffers");
	glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glStencilOpsSeparate");
	glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glStencilFuncSeparate");
	glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glStencilMaskSeparate");
	glAttachShader = (PFNGLATTACHSHADERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glAttachShader");
	glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBindAttribLocation");
	glCompileShader = (PFNGLCOMPILESHADERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glCompileShader");
	glCreateProgram = (PFNGLCREATEPROGRAMPROC)TinyExtender::GetProcAddress((const GLubyte*)"glCreateProgram");
	glDeleteProgram = (PFNGLDELETEPROGRAMPROC)TinyExtender::GetProcAddress((const GLubyte*)" glDeleteProgram");
	glDetachShader = (PFNGLDETACHSHADERPROC)TinyExtender::GetProcAddress((const GLubyte*)" glDetachShader");
	glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)TinyExtender::GetProcAddress((const GLubyte*)" glDisableVertexAttribArray");
	glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)TinyExtender::GetProcAddress((const GLubyte*)" glEnableVertexAttribArray");
	glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC)TinyExtender::GetProcAddress((const GLubyte*)" glGetActiveAttrib");
	glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC)TinyExtender::GetProcAddress((const GLubyte*)" glGetActiveUniform");
	glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC)TinyExtender::GetProcAddress((const GLubyte*)" glGetAttachedShaders");
	glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)TinyExtender::GetProcAddress((const GLubyte*)" glGetAttribLocation");
	glGetProgramiv = (PFNGLGETPROGRAMIVPROC)TinyExtender::GetProcAddress((const GLubyte*)" glGetProgramiv");
	glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)TinyExtender::GetProcAddress((const GLubyte*)" glGetProgramInfoLog");
	glGetShaderSource = (PFNGLGETSHADERSOURCEPROC)TinyExtender::GetProcAddress((const GLubyte*)" glGetShaderSource");
	glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)TinyExtender::GetProcAddress((const GLubyte*)" glGetUniformLocation");
	glGetUniformfv = (PFNGLGETUNIFORMFVPROC)TinyExtender::GetProcAddress((const GLubyte*)" glGetUniformfv");
	glGetUniformiv = (PFNGLGETUNIFORMIVPROC)TinyExtender::GetProcAddress((const GLubyte*)" glGetUniformiv");
	glGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDVPROC)TinyExtender::GetProcAddress((const GLubyte*)" glGetVertexAttribdv");
	glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC)TinyExtender::GetProcAddress((const GLubyte*)" glGetVertexAttribfv");
	glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC)TinyExtender::GetProcAddress((const GLubyte*)" glGetVertexAttribiv");
	glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC)TinyExtender::GetProcAddress((const GLubyte*)" glGetVertexAttribPointerv");
	glIsProgram = (PFNGLISPROGRAMPROC)TinyExtender::GetProcAddress((const GLubyte*)" glIsProgram");
	glIsShader = (PFNGLISSHADERPROC)TinyExtender::GetProcAddress((const GLubyte*)" glIsShader");
	glLinkProgram = (PFNGLLINKPROGRAMPROC)TinyExtender::GetProcAddress((const GLubyte*)" glLinkProgram");
	glShaderSource = (PFNGLSHADERSOURCEPROC)TinyExtender::GetProcAddress((const GLubyte*)" glShaderSource");
	glUseProgram = (PFNGLUSEPROGRAMPROC)TinyExtender::GetProcAddress((const GLubyte*)" glUseProgram");
	glUniform1f = (PFNGLUNIFORM1FPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform1f");
	glUniform2f = (PFNGLUNIFORM2FPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform2f");
	glUniform3f = (PFNGLUNIFORM3FPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform3f");
	glUniform4f = (PFNGLUNIFORM4FPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform4f");
	glUniform1i = (PFNGLUNIFORM1IPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform1i");
	glUniform2i = (PFNGLUNIFORM2IPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform2i");
	glUniform3i = (PFNGLUNIFORM3IPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform3i");
	glUniform4i = (PFNGLUNIFORM4IPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform4i");
	glUniform1fv = (PFNGLUNIFORM1FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform1fv");
	glUniform2fv = (PFNGLUNIFORM2FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform2fv");
	glUniform3fv = (PFNGLUNIFORM3FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform3fv");
	glUniform4fv = (PFNGLUNIFORM4FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform4fv");
	glUniform1iv = (PFNGLUNIFORM1IVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform1iv");
	glUniform2iv = (PFNGLUNIFORM2IVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform2iv");
	glUniform3iv = (PFNGLUNIFORM3IVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform3iv");
	glUniform4iv = (PFNGLUNIFORM4IVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform4iv");
	glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniformMatrix2fv");
	glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniformMatrix3fv");
	glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniformMatrix4fv");
	glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)TinyExtender::GetProcAddress((const GLubyte*)"glValidateProgram");
	glVertexAttrib1d = (PFNGLVERTEXATTRIB1DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib1d");
	glVertexAttrib1dv = (PFNGLVERTEXATTRIB1DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib1dv");
	glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib1f");
	glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib1fv");
	glVertexAttrib1s = (PFNGLVERTEXATTRIB1SPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib1s");
	glVertexAttrib1sv = (PFNGLVERTEXATTRIB1SVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib1sv");
	glVertexAttrib2d = (PFNGLVERTEXATTRIB2DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib2d");
	glVertexAttrib2dv = (PFNGLVERTEXATTRIB2DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib2dv");
	glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib2f");
	glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib2fv");
	glVertexAttrib2s = (PFNGLVERTEXATTRIB2SPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib2s");
	glVertexAttrib2sv = (PFNGLVERTEXATTRIB2SVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib2sv");
	glVertexAttrib3d = (PFNGLVERTEXATTRIB3DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib3d");
	glVertexAttrib3dv = (PFNGLVERTEXATTRIB3DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib3dv");
	glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib3f");
	glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib3fv");
	glVertexAttrib3s = (PFNGLVERTEXATTRIB3SPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib3s");
	glVertexAttrib3sv = (PFNGLVERTEXATTRIB3SVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib3sv");
	glVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib4Nbv");
	glVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib4Niv");
	glVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib4Nsv");
	glVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUBPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib4Nub");
	glVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttib4Nubv");
	glVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib4Nuiv");
	glVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib4Nusv");
	glVertexAttrib4bv = (PFNGLVERTEXATTRIB4BVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib4bv");
	glVertexAttrib4d = (PFNGLVERTEXATTRIB4DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribb4d");
	glVertexAttrib4dv = (PFNGLVERTEXATTRIB4DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib4dv");
	glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib4f");
	glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib4fv");
	glVertexAttrib4iv = (PFNGLVERTEXATTRIB4IVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib4iv");
	glVertexAttrib4s = (PFNGLVERTEXATTRIB4SPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib4s");
	glVertexAttrib4sv = (PFNGLVERTEXATTRIB4SVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib4sv");
	glVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib4ubv");
	glVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib4uiv");
	glVertexAttrib4usv = (PFNGLVERTEXATTRIB4USVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib4usv");
	glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribPointer");
}

GLvoid TinyExtender::Load2_1Extensions()
{
	glUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC)TinyExtender::GetProcAddress((const GLubyte*)" glUniformMatrix2x3fv");
	glUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC)TinyExtender::GetProcAddress((const GLubyte*)" glUniformMatrix3x2fv");
	glUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC)TinyExtender::GetProcAddress((const GLubyte*)" glUniformMatrix2x4fv");
	glUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC)TinyExtender::GetProcAddress((const GLubyte*)" glUniformMatrix4x2fv");
	glUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC)TinyExtender::GetProcAddress((const GLubyte*)" glUniformMatrix3x4fv");
	glUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC)TinyExtender::GetProcAddress((const GLubyte*)" glUniformMatrix4x3fv");
}

GLvoid TinyExtender::Load3_0Extensions()
{
	glColorMaski = (PFNGLCOLORMASKIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glColorMaski");	
	glGetBooleani_v = (PFNGLGETBOOLEANI_VPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetBooleani_v");
	glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetIntegeri_v");
	glEnablei = (PFNGLENABLEIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glEnablei");
	glDisablei = (PFNGLDISABLEIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDisablei");
	glIsEnabledi = (PFNGLISENABLEDIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glIsEnabledi");
	glBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBeginTransformFeedback");
	glEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC)TinyExtender::GetProcAddress((const GLubyte*)"glEndTransformFeedback");
	glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBindBufferRange");
}
