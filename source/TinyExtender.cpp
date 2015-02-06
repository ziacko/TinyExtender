﻿#include "TinyExtender.h"
#include <string.h>
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
#if defined(__WIN32)
PFNGLGETCOMPRESSEDTEXIMAGEPROC __teGetCompressedTexImage = 0;
PFNGLCLIENTACTIVETEXTUREPROC __teClientActiveTexture = 0;
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
PFNGLMULTTRANSPOSEMATRIXDPROC __teMultTransposeMatrixd = 0;
#endif
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
PFNGLBLENDEQUATIONSEPARATEPROC __teBlendEquationSeparate = 0;
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

PFNGLCOLORMASKIPROC __teColorMaski = 0;
PFNGLGETBOOLEANI_VPROC __teGetBooleani_v = 0;
PFNGLGETINTEGERI_VPROC __teGetIntegeri_v = 0;
PFNGLENABLEIPROC __teEnablei = 0;
PFNGLDISABLEIPROC __teDisablei = 0;
PFNGLISENABLEDIPROC __teIsEnabledi = 0;
PFNGLBEGINTRANSFORMFEEDBACKPROC __teBeginTransformFeedback = 0;
PFNGLENDTRANSFORMFEEDBACKPROC __teEndTransformFeedback = 0;
PFNGLBINDBUFFERRANGEPROC __teBindBufferRange = 0;
PFNGLBINDBUFFERBASEPROC __teBindBufferBase = 0;
PFNGLTRANSFORMFEEDBACKVARYINGSPROC __teTransformFeedbackVaryings = 0;
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC __teGetTransformFeedbackVarying = 0;
PFNGLCLAMPCOLORPROC __teClampColor = 0;
PFNGLBEGINCONDITIONALRENDERPROC __teBeginConditionalRender = 0;
PFNGLENDCONDITIONALRENDERPROC __teEndConditionalRender = 0;
PFNGLVERTEXATTRIBIPOINTERPROC __teVertexAttribIPointer = 0;
PFNGLGETVERTEXATTRIBIIVPROC __teGetVertexAttribIiv = 0;
PFNGLGETVERTEXATTRIBIUIVPROC __teGetVertexAttribIuiv = 0;
PFNGLVERTEXATTRIBI1IPROC __teVertexAttribI1i = 0;
PFNGLVERTEXATTRIBI2IPROC __teVertexAttribI2i = 0;
PFNGLVERTEXATTRIBI3IPROC __teVertexAttribI3i = 0;
PFNGLVERTEXATTRIBI4IPROC __teVertexAttribI4i = 0;
PFNGLVERTEXATTRIBI1UIPROC __teVertexAttribI1ui = 0;
PFNGLVERTEXATTRIBI2UIPROC __teVertexAttribI2ui = 0;
PFNGLVERTEXATTRIBI3UIPROC __teVertexAttribI3ui = 0;
PFNGLVERTEXATTRIBI4UIPROC __teVertexAttribI4ui = 0;
PFNGLVERTEXATTRIBI1IVPROC __teVertexAttribI1iv = 0;
PFNGLVERTEXATTRIBI2IVPROC __teVertexAttribI2iv = 0;
PFNGLVERTEXATTRIBI3IVPROC __teVertexAttribI3iv = 0;
PFNGLVERTEXATTRIBI4IVPROC __teVertexAttribI4iv = 0;
PFNGLVERTEXATTRIBI1UIVPROC __teVertexAttribI1uiv = 0;
PFNGLVERTEXATTRIBI2UIVPROC __teVertexAttribI2uiv = 0;
PFNGLVERTEXATTRIBI3UIVPROC __teVertexAttribI3uiv = 0;
PFNGLVERTEXATTRIBI4UIVPROC __teVertexAttribI4uiv = 0;
PFNGLVERTEXATTRIBI4BVPROC __teVertexAttribI4bv = 0;
PFNGLVERTEXATTRIBI4SVPROC __teVertexAttribI4sv = 0;
PFNGLVERTEXATTRIBI4UBVPROC __teVertexAttribI4ubv = 0;
PFNGLVERTEXATTRIBI4USVPROC __teVertexAttribI4usv = 0;
PFNGLGETUNIFORMUIVPROC __teGetUniformuiv = 0;
PFNGLBINDFRAGDATALOCATIONPROC __teBindFragDataLocation = 0;
PFNGLGETFRAGDATALOCATIONPROC __teGetFragDataLocation = 0;
PFNGLUNIFORM1UIPROC __teUniform1ui = 0;
PFNGLUNIFORM2UIPROC __teUniform2ui = 0;
PFNGLUNIFORM3UIPROC __teUniform3ui = 0;
PFNGLUNIFORM4UIPROC __teUniform4ui = 0;
PFNGLUNIFORM1UIVPROC __teUniform1uiv = 0;
PFNGLUNIFORM2UIVPROC __teUniform2uiv = 0;
PFNGLUNIFORM3UIVPROC __teUniform3uiv = 0;
PFNGLUNIFORM4UIVPROC __teUniform4uiv = 0;
PFNGLTEXPARAMETERIIVPROC __teTexParameterIiv = 0;
PFNGLTEXPARAMETERIUIVPROC __teTexParameterIuiv = 0;
PFNGLGETTEXPARAMETERIIVPROC __teGetTexParameterIiv = 0;
PFNGLGETTEXPARAMETERIUIVPROC __teGetTexParameterIuiv = 0;
PFNGLCLEARBUFFERIVPROC __teClearBufferiv = 0;
PFNGLCLEARBUFFERUIVPROC __teClearBufferuiv = 0;
PFNGLCLEARBUFFERFVPROC __teClearBufferfv = 0;
PFNGLCLEARBUFFERFIPROC __teClearBufferfi = 0;
PFNGLGETSTRINGIPROC __teGetStringi = 0;
PFNGLISRENDERBUFFERPROC __teIsRenderbuffer = 0;
PFNGLBINDRENDERBUFFERPROC __teBindRenderbuffer = 0;
PFNGLDELETERENDERBUFFERSPROC __teDeleteRenderbuffers = 0;
PFNGLGENRENDERBUFFERSPROC __teGenRenderbuffers = 0;
PFNGLRENDERBUFFERSTORAGEPROC __teRenderbufferStorage = 0;
PFNGLGETRENDERBUFFERPARAMETERIVPROC __teGetRenderbufferParameteriv = 0;
PFNGLISFRAMEBUFFERPROC __teIsFramebuffer = 0;
PFNGLBINDFRAMEBUFFERPROC __teBindFramebuffer = 0;
PFNGLDELETEFRAMEBUFFERSPROC __teDeleteFramebuffers = 0;
PFNGLGENFRAMEBUFFERSPROC __teGenFramebuffers = 0;
PFNGLCHECKFRAMEBUFFERSTATUSPROC __teCheckFramebufferStatus = 0;
PFNGLFRAMEBUFFERTEXTURE1DPROC __teFramebufferTexture1D = 0;
PFNGLFRAMEBUFFERTEXTURE2DPROC __teFramebufferTexture2D = 0;
PFNGLFRAMEBUFFERTEXTURE3DPROC __teFramebufferTexture3D = 0;
PFNGLFRAMEBUFFERRENDERBUFFERPROC __teFramebufferRenderbuffer = 0;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC __teGetFramebufferAttachmentParameteriv = 0;
PFNGLGENERATEMIPMAPPROC __teGenerateMipmap = 0;
PFNGLBLITFRAMEBUFFERPROC __teBlitFramebuffer = 0;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC __teRenderbufferStorageMultisample = 0;
PFNGLFRAMEBUFFERTEXTURELAYERPROC __teFramebufferTextureLayer = 0;
PFNGLMAPBUFFERRANGEPROC __teMapBufferRange = 0;
PFNGLFLUSHMAPPEDBUFFERRANGEPROC __teFlushMappedBufferRange = 0;
PFNGLBINDVERTEXARRAYPROC __teBindVertexArray = 0;
PFNGLDELETEVERTEXARRAYSPROC __teDeleteVertexArrays = 0;
PFNGLGENVERTEXARRAYSPROC __teGenVertexArrays = 0;
PFNGLISVERTEXARRAYPROC __teIsVertexArray = 0;

//OpenGL 3.1 Extensions
PFNGLDRAWARRAYSINSTANCEDPROC __teDrawArraysInstanced = 0;
PFNGLDRAWELEMENTSINSTANCEDPROC __teDrawElementsInstanced = 0;
PFNGLTEXBUFFERPROC __teTexBuffer = 0;
PFNGLPRIMITIVERESTARTINDEXPROC __tePrimitiveRestartIndex = 0;
PFNGLCOPYBUFFERSUBDATAPROC __teCopyBufferSubdata = 0;
PFNGLGETUNIFORMINDICESPROC __teGetUniformIndices = 0;
PFNGLGETACTIVEUNIFORMSIVPROC __teGetActiveUniformsiv = 0;
PFNGLGETACTIVEUNIFORMNAMEPROC __teGetActiveUniformName = 0;
PFNGLGETUNIFORMBLOCKINDEXPROC __teGetUniformBlockIndex = 0;
PFNGLGETACTIVEUNIFORMBLOCKIVPROC __teGetActiveUniformBlockiv = 0;
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC __teGetActiveUniformBlockName = 0;
PFNGLUNIFORMBLOCKBINDINGPROC __teUniformBlockBinding = 0;

//OpenGL 3.2 Extensions
PFNGLDRAWELEMENTSBASEVERTEXPROC __teDrawElementsBaseVertex = 0;
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC __teDrawRangeElementsBaseVertex = 0;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC __teDrawElementsInstancedBaseVertex = 0;
PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC __teMultiDrawElementsBaseVertex = 0;
PFNGLPROVOKINGVERTEXPROC __teProvokingVertex = 0;
PFNGLFENCESYNCPROC __teFenceSync = 0;
PFNGLISSYNCPROC __teIsSync = 0;
PFNGLDELETESYNCPROC __teDeleteSync = 0;
PFNGLCLIENTWAITSYNCPROC __teClientWaitSync = 0;
PFNGLWAITSYNCPROC __teWaitSync = 0;
PFNGLGETINTEGER64VPROC __teGetInteger64v = 0;
PFNGLGETSYNCIVPROC __teGetSynciv = 0;
PFNGLGETINTEGER64I_VPROC __teGetInteger64i_v = 0;
PFNGLGETBUFFERPARAMETERI64VPROC __teGetBufferParameteri64v = 0;
PFNGLFRAMEBUFFERTEXTUREPROC __teFramebufferTexture = 0;
PFNGLTEXIMAGE2DMULTISAMPLEPROC __teTexImage2DMultisample = 0;
PFNGLTEXIMAGE3DMULTISAMPLEPROC __teTexImage3DMultisample = 0;
PFNGLGETMULTISAMPLEFVPROC __teGetMultisamplefv = 0;
PFNGLSAMPLEMASKIPROC __teSampleMaski = 0;

//OpenGL 3.3 Extensions
PFNGLBINDFRAGDATALOCATIONINDEXEDPROC __teBindFragDataLocationIndexed = 0;
PFNGLGETFRAGDATAINDEXPROC __teGetFragDataIndex = 0;
PFNGLGENSAMPLERSPROC __teGenSamplers = 0;
PFNGLDELETESAMPLERSPROC __teDeleteSamplers = 0;
PFNGLISSAMPLERPROC __teIsSampler = 0;
PFNGLBINDSAMPLERPROC __teBindSampler = 0;
PFNGLSAMPLERPARAMETERIPROC __teSamplerParameteri = 0;
PFNGLSAMPLERPARAMETERIVPROC __teSamplerParameteriv = 0;
PFNGLSAMPLERPARAMETERFPROC __teSamplerParameterf = 0;
PFNGLSAMPLERPARAMETERFVPROC __teSamplerParameterfv = 0;
PFNGLSAMPLERPARAMETERIIVPROC __teSamplerParameterIiv = 0;
PFNGLSAMPLERPARAMETERIUIVPROC __teSamplerParameterIuiv = 0;
PFNGLGETSAMPLERPARAMETERIVPROC __teGetSamplerParameteriv = 0;
PFNGLGETSAMPLERPARAMETERIIVPROC __teGetSamplerParameterIiv = 0;
PFNGLGETSAMPLERPARAMETERFVPROC __teGetSamplerParameterfv = 0;
PFNGLGETSAMPLERPARAMETERIUIVPROC __teGetSamplerParameterIuiv = 0;
PFNGLQUERYCOUNTERPROC __teQueryCounter = 0;
PFNGLGETQUERYOBJECTI64VPROC __teGetQueryObjecti64v = 0;
PFNGLGETQUERYOBJECTUI64VPROC __teGetQueryObjectui64v = 0;
PFNGLVERTEXATTRIBDIVISORPROC __teVertexAttribDivisor = 0;
PFNGLVERTEXATTRIBP1UIPROC __teVertexAttribP1ui = 0;
PFNGLVERTEXATTRIBP1UIVPROC __teVertexAttribP1uiv = 0;
PFNGLVERTEXATTRIBP2UIPROC __teVertexAttribP2ui = 0;
PFNGLVERTEXATTRIBP2UIVPROC __teVertexAttribP2uiv = 0;
PFNGLVERTEXATTRIBP3UIPROC __teVertexAttribP3ui = 0;
PFNGLVERTEXATTRIBP3UIVPROC __teVertexAttribP3uiv = 0;
PFNGLVERTEXATTRIBP4UIPROC __teVertexAttribP4ui = 0;
PFNGLVERTEXATTRIBP4UIVPROC __teVertexAttribP4uiv = 0;
PFNGLVERTEXP2UIPROC __teVertexP2ui = 0;
PFNGLVERTEXP2UIVPROC __teVertexP2uiv = 0;
PFNGLVERTEXP3UIPROC __teVertexP3ui = 0;
PFNGLVERTEXP3UIVPROC __teVertexP3uiv = 0;
PFNGLVERTEXP4UIPROC __teVertexP4ui = 0;
PFNGLVERTEXP4UIVPROC __teVertexP4uiv = 0;
PFNGLTEXCOORDP1UIPROC __teTexCoordP1ui = 0;
PFNGLTEXCOORDP1UIVPROC __teTexCoordP1uiv = 0;
PFNGLTEXCOORDP2UIPROC __teTexCoordP2ui = 0;
PFNGLTEXCOORDP2UIVPROC __teTexCoordP2uiv = 0;
PFNGLTEXCOORDP3UIPROC __teTexCoordP3ui = 0;
PFNGLTEXCOORDP3UIVPROC __teTexCoordP3uiv = 0;
PFNGLTEXCOORDP4UIPROC __teTexCoordP4ui = 0;
PFNGLTEXCOORDP4UIVPROC __teTexCoordP4uiv = 0;
PFNGLMULTITEXCOORDP1UIPROC __teMultiTexCoordP1ui = 0;
PFNGLMULTITEXCOORDP1UIVPROC __teMultiTexCoordP1uiv = 0;
PFNGLMULTITEXCOORDP2UIPROC __teMultiTexCoordP2ui = 0;
PFNGLMULTITEXCOORDP2UIVPROC __teMultiTexCoordP2uiv = 0;
PFNGLMULTITEXCOORDP3UIPROC __teMultiTexCoordP3ui = 0;
PFNGLMULTITEXCOORDP3UIVPROC __teMultiTexCoordP3uiv = 0;
PFNGLMULTITEXCOORDP4UIPROC __teMultiTexCoordP4ui = 0;
PFNGLMULTITEXCOORDP4UIVPROC __teMultiTexCoordP4uiv = 0;
PFNGLNORMALP3UIPROC __teNormalP3ui = 0;
PFNGLNORMALP3UIVPROC __teNormalP3uiv = 0;
PFNGLCOLORP3UIPROC __teColorP3ui = 0;
PFNGLCOLORP3UIVPROC __teColorP3uiv = 0;
PFNGLCOLORP4UIPROC __teColorP4ui = 0;
PFNGLCOLORP4UIVPROC __teColorP4uiv = 0;
PFNGLSECONDARYCOLORP3UIPROC __teSecondaryColorP3ui = 0;
PFNGLSECONDARYCOLORP3UIVPROC __teSecondaryColorP3uiv = 0;

//OpenGL 4.0 Extensions
PFNGLMINSAMPLESHADINGPROC __teMinSampleShading = 0;
PFNGLBLENDEQUATIONIPROC __teBlendEquationi = 0;
PFNGLBLENDEQUATIONSEPARATEIPROC __teBlendEquationSeparatei = 0;
PFNGLBLENDFUNCIPROC __teBlendFunci = 0;
PFNGLBLENDFUNCSEPARATEIPROC __teBlendFuncSeparatei = 0;
PFNGLDRAWARRAYSINDIRECTPROC __teDrawArraysIndirect = 0;
PFNGLDRAWELEMENTSINDIRECTPROC __teDrawElementsIndirect = 0;
PFNGLUNIFORM1DPROC __teUniform1d = 0;
PFNGLUNIFORM2DPROC __teUniform2d = 0;
PFNGLUNIFORM3DPROC __teUniform3d = 0;
PFNGLUNIFORM4DPROC __teUniform4d = 0;
PFNGLUNIFORM1DVPROC __teUniform1dv = 0;
PFNGLUNIFORM2DVPROC __teUniform2dv = 0;
PFNGLUNIFORM3DVPROC __teUniform3dv = 0;
PFNGLUNIFORM4DVPROC __teUniform4dv = 0;
PFNGLUNIFORMMATRIX2DVPROC __teUniformMatrix2dv = 0;
PFNGLUNIFORMMATRIX3DVPROC __teUniformMatrix3dv = 0;
PFNGLUNIFORMMATRIX4DVPROC __teUniformMatrix4dv = 0;
PFNGLUNIFORMMATRIX2X3DVPROC __teUniformMatrix2x3dv = 0;
PFNGLUNIFORMMATRIX2X4DVPROC __teUniformMatrix2x4dv = 0;
PFNGLUNIFORMMATRIX3X2DVPROC __teUniformMatrix3x2dv = 0;
PFNGLUNIFORMMATRIX3X4DVPROC __teUniformMatrix3x4dv = 0;
PFNGLUNIFORMMATRIX4X2DVPROC __teUniformMatrix4x2dv = 0;
PFNGLUNIFORMMATRIX4X3DVPROC __teUniformMatrix4x3dv = 0;
PFNGLGETUNIFORMDVPROC __teGetUniformdv = 0;
PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC __teGetSubroutineUniformLocation = 0;
PFNGLGETSUBROUTINEINDEXPROC __teGetSubroutineIndex = 0;
PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC __teGetActiveSubroutineUniformiv = 0;
PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC __teGetActiveSubroutineUniformName = 0;
PFNGLGETACTIVESUBROUTINENAMEPROC __teGetActiveSubroutineName = 0;
PFNGLUNIFORMSUBROUTINESUIVPROC __teUniformSubroutinesuiv = 0;
PFNGLGETUNIFORMSUBROUTINEUIVPROC __teGetUniformSubroutineuiv = 0;
PFNGLGETPROGRAMSTAGEIVPROC __teGetProgramStageiv = 0;
PFNGLPATCHPARAMETERIPROC __tePatchParameteri = 0;
PFNGLPATCHPARAMETERFVPROC __tePatchParameterfv = 0;
PFNGLBINDTRANSFORMFEEDBACKPROC __teBindTransformFeedback = 0;
PFNGLDELETETRANSFORMFEEDBACKSPROC __teDeleteTransformFeedbacks = 0;
PFNGLGENTRANSFORMFEEDBACKSPROC __teGenTransformFeedbacks = 0;
PFNGLISTRANSFORMFEEDBACKPROC __teIsTransformFeedback = 0;
PFNGLPAUSETRANSFORMFEEDBACKPROC __tePauseTransformFeedback = 0;
PFNGLRESUMETRANSFORMFEEDBACKPROC __teResumeTransformFeedback = 0;
PFNGLDRAWTRANSFORMFEEDBACKPROC __teDrawTransformFeedback = 0;
PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC __teDrawTransformFeedbackStream = 0;
PFNGLBEGINQUERYINDEXEDPROC __teBeginQueryIndexed = 0;
PFNGLENDQUERYINDEXEDPROC __teEndQueryIndexed = 0;
PFNGLGETQUERYINDEXEDIVPROC __teGetQueryIndexediv = 0;

//OpenGL 4.1 Extensions
PFNGLRELEASESHADERCOMPILERPROC __teReleaseShaderCompiler = 0;
PFNGLSHADERBINARYPROC __teShaderBinary = 0;
PFNGLGETSHADERPRECISIONFORMATPROC __teGetShaderPrecisionFormat = 0;
PFNGLDEPTHRANGEFPROC __teDepthRangef = 0;
PFNGLCLEARDEPTHFPROC __teClearDepthf = 0;
PFNGLGETPROGRAMBINARYPROC __teGetProgramBinary = 0;
PFNGLPROGRAMBINARYPROC __teProgramBinary = 0;
PFNGLPROGRAMPARAMETERIPROC __teProgramParameteri = 0;
PFNGLUSEPROGRAMSTAGESPROC __teUseProgramStages = 0;
PFNGLACTIVESHADERPROGRAMPROC __teActiveShaderProgram = 0;
PFNGLCREATESHADERPROGRAMVPROC __teCreateShaderProgramv = 0;
PFNGLBINDPROGRAMPIPELINEPROC __teBindProgramPipeline = 0;
PFNGLDELETEPROGRAMPIPELINESPROC __teDeleteProgramPipelines = 0;
PFNGLGENPROGRAMPIPELINESPROC __teGenProgramPipelines = 0;
PFNGLISPROGRAMPIPELINEPROC __teIsProgramPipeline = 0;
PFNGLGETPROGRAMPIPELINEIVPROC __teGetProgramPipelineiv = 0;
PFNGLPROGRAMUNIFORM1IPROC __teProgramUniform1i = 0;
PFNGLPROGRAMUNIFORM1IVPROC __teProgramUniform1iv = 0;
PFNGLPROGRAMUNIFORM1FPROC __teProgramUniform1f = 0;
PFNGLPROGRAMUNIFORM1FVPROC __teProgramUniform1fv = 0;
PFNGLPROGRAMUNIFORM1DPROC __teProgramUniform1d = 0;
PFNGLPROGRAMUNIFORM1DVPROC __teProgramUniform1dv = 0;
PFNGLPROGRAMUNIFORM1UIPROC __teProgramUniform1ui = 0;
PFNGLPROGRAMUNIFORM1UIVPROC __teProgramUniform1uiv = 0;
PFNGLPROGRAMUNIFORM2IPROC __teProgramUniform2i = 0;
PFNGLPROGRAMUNIFORM2IVPROC __teProgramUniform2iv = 0;
PFNGLPROGRAMUNIFORM2FPROC __teProgramUniform2f = 0;
PFNGLPROGRAMUNIFORM2FVPROC __teProgramUniform2fv = 0;
PFNGLPROGRAMUNIFORM2DPROC __teProgramUniform2d = 0;
PFNGLPROGRAMUNIFORM2DVPROC __teProgramUniform2dv = 0;
PFNGLPROGRAMUNIFORM2UIPROC __teProgramUniform2ui = 0;
PFNGLPROGRAMUNIFORM2UIVPROC __teProgramUniform2uiv = 0;
PFNGLPROGRAMUNIFORM3IPROC __teProgramUniform3i = 0;
PFNGLPROGRAMUNIFORM3IVPROC __teProgramUniform3iv = 0;
PFNGLPROGRAMUNIFORM3FPROC __teProgramUniform3f = 0;
PFNGLPROGRAMUNIFORM3FVPROC __teProgramUniform3fv = 0;
PFNGLPROGRAMUNIFORM3DPROC __teProgramUniform3d = 0;
PFNGLPROGRAMUNIFORM3DVPROC __teProgramUniform3dv = 0;
PFNGLPROGRAMUNIFORM3UIPROC __teProgramUniform3ui = 0;
PFNGLPROGRAMUNIFORM3UIVPROC __teProgramUniform3uiv = 0;
PFNGLPROGRAMUNIFORM4IPROC __teProgramUniform4i = 0;
PFNGLPROGRAMUNIFORM4IVPROC __teProgramUniform4iv = 0;
PFNGLPROGRAMUNIFORM4FPROC __teProgramUniform4f = 0;
PFNGLPROGRAMUNIFORM4FVPROC __teProgramUniform4fv = 0;
PFNGLPROGRAMUNIFORM4DPROC __teProgramUniform4d = 0;
PFNGLPROGRAMUNIFORM4DVPROC __teProgramUniform4dv = 0;
PFNGLPROGRAMUNIFORM4UIPROC __teProgramUniform4ui = 0;
PFNGLPROGRAMUNIFORM4UIVPROC __teProgramUniform4uiv = 0;
PFNGLPROGRAMUNIFORMMATRIX2FVPROC __teProgramUniformMatrix2fv = 0;
PFNGLPROGRAMUNIFORMMATRIX3FVPROC __teProgramUniformMatrix3fv = 0;
PFNGLPROGRAMUNIFORMMATRIX4FVPROC __teProgramUniformMatrix4fv = 0;
PFNGLPROGRAMUNIFORMMATRIX2DVPROC __teProgramUniformMatrix2dv = 0;
PFNGLPROGRAMUNIFORMMATRIX3DVPROC __teProgramUniformMatrix3dv = 0;
PFNGLPROGRAMUNIFORMMATRIX4DVPROC __teProgramUniformMatrix4dv = 0;
PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC __teProgramUniformMatrix2x3fv = 0;
PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC __teProgramUniformMatrix3x2fv = 0;
PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC __teProgramUniformMatrix2x4fv = 0;
PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC __teProgramUniformMatrix4x2fv = 0;
PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC __teProgramUniformMatrix3x4fv = 0;
PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC __teProgramUniformMatrix4x3fv = 0;
PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC __teProgramUniformMatrix2x3dv = 0;
PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC __teProgramUniformMatrix3x2dv = 0;
PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC __teProgramUniformMatrix2x4dv = 0;
PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC __teProgramUniformMatrix4x2dv = 0;
PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC __teProgramUniformMatrix3x4dv = 0;
PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC __teProgramUniformMatrix4x3dv = 0;
PFNGLVALIDATEPROGRAMPIPELINEPROC __teValidateProgramPipeline = 0;
PFNGLGETPROGRAMPIPELINEINFOLOGPROC __teGetProgramPipelineInfoLog = 0;
PFNGLVERTEXATTRIBL1DPROC __teVertexAttribL1d = 0;
PFNGLVERTEXATTRIBL2DPROC __teVertexAttribL2d = 0;
PFNGLVERTEXATTRIBL3DPROC __teVertexAttribL3d = 0;
PFNGLVERTEXATTRIBL4DPROC __teVertexAttribL4d = 0;
PFNGLVERTEXATTRIBL1DVPROC __teVertexAttribL1dv = 0;
PFNGLVERTEXATTRIBL2DVPROC __teVertexAttribL2dv = 0;
PFNGLVERTEXATTRIBL3DVPROC __teVertexAttribL3dv = 0;
PFNGLVERTEXATTRIBL4DVPROC __teVertexAttribL4dv = 0;
PFNGLVERTEXATTRIBLPOINTERPROC __teVertexAttribLPointer = 0;
PFNGLGETVERTEXATTRIBLDVPROC __teGetVertexAttribLdv = 0;
PFNGLVIEWPORTARRAYVPROC __teViewportArrayv = 0;
PFNGLVIEWPORTINDEXEDFPROC __teViewportIndexedf = 0;
PFNGLVIEWPORTINDEXEDFVPROC __teViewportIndexedfv = 0;
PFNGLSCISSORARRAYVPROC __teScissorArrayv = 0;
PFNGLSCISSORINDEXEDPROC __teScissorIndexed = 0;
PFNGLSCISSORINDEXEDVPROC __teScissorIndexedv = 0;
PFNGLDEPTHRANGEARRAYVPROC __teDepthRangeArrayv = 0;
PFNGLDEPTHRANGEINDEXEDPROC __teDepthRangeIndexed = 0;
PFNGLGETFLOATI_VPROC __teGetFloati_v = 0;
PFNGLGETDOUBLEI_VPROC __teGetDoublei_v = 0;

//OpenGL 4.2 Extensions
PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC __teDrawArraysInstancedBaseInstance = 0;
PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC __teDrawElementsInstancedBaseInstance = 0;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC __teDrawElementsInstancedBaseVertexBaseInstance = 0;
PFNGLGETINTERNALFORMATIVPROC __teGetInternalformativ = 0;
PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC __teGetActiveAtomicCounterBufferiv = 0;
PFNGLBINDIMAGETEXTUREPROC __teBindImageTexture = 0;
PFNGLMEMORYBARRIERPROC __teMemoryBarrier = 0;
PFNGLTEXSTORAGE1DPROC __teTexStorage1D = 0;
PFNGLTEXSTORAGE2DPROC __teTexStorage2D = 0;
PFNGLTEXSTORAGE3DPROC __teTexStorage3D = 0;
PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC __teDrawTransformFeedbackInstanced = 0;
PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC __teDrawTransformFeedbackStreamInstanced = 0;

//OpenGL 4.3 Extensions
PFNGLCLEARBUFFERDATAPROC __teClearBufferData = 0;
PFNGLCLEARBUFFERSUBDATAPROC __teClearBufferSubdata = 0;
PFNGLDISPATCHCOMPUTEPROC __teDispatchCompute = 0;
PFNGLDISPATCHCOMPUTEINDIRECTPROC __teDispatchComputeIndirect = 0;
PFNGLCOPYIMAGESUBDATAPROC  __teCopyImageSubdata = 0;
PFNGLFRAMEBUFFERPARAMETERIPROC __teFramebufferParameteri = 0;
PFNGLGETFRAMEBUFFERPARAMETERIVPROC __teGetFramebufferParameteriv = 0;
PFNGLGETINTERNALFORMATI64VPROC __teGetInternalformati64v = 0;
PFNGLINVALIDATETEXSUBIMAGEPROC __teInvalidateTexSubImage = 0;
PFNGLINVALIDATETEXIMAGEPROC __teInvalidateTexImage = 0;
PFNGLINVALIDATEBUFFERSUBDATAPROC __teInvalidateBufferSubdata = 0;
PFNGLINVALIDATEBUFFERDATAPROC __teInvalidateBufferData = 0;
PFNGLINVALIDATEFRAMEBUFFERPROC __teInvalidateFramebuffer = 0;
PFNGLINVALIDATESUBFRAMEBUFFERPROC __teInvalidateSubFramebuffer = 0;
PFNGLMULTIDRAWARRAYSINDIRECTPROC __teMultiDrawArraysIndirect = 0;
PFNGLMULTIDRAWELEMENTSINDIRECTPROC __teMultiDrawElementsIndirect = 0;
PFNGLGETPROGRAMINTERFACEIVPROC __teGetProgramInterfaceiv = 0;
PFNGLGETPROGRAMRESOURCEINDEXPROC __teGetProgramResourceIndex = 0;
PFNGLGETPROGRAMRESOURCENAMEPROC __teGetProgramResourceName = 0;
PFNGLGETPROGRAMRESOURCEIVPROC __teGetProgramResourceiv = 0;
PFNGLGETPROGRAMRESOURCELOCATIONPROC __teGetProgramResourceLocation = 0;
PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC __teGetProgramResourceLocationIndex = 0;
PFNGLSHADERSTORAGEBLOCKBINDINGPROC __teShaderStorageBlockBinding = 0;
PFNGLTEXBUFFERRANGEPROC __teTexBufferRange = 0;
PFNGLTEXSTORAGE2DMULTISAMPLEPROC __teTexStorage2DMultisample = 0;
PFNGLTEXSTORAGE3DMULTISAMPLEPROC __teTexStorage3DMultisample = 0;
PFNGLTEXTUREVIEWPROC __teTextureView = 0;
PFNGLBINDVERTEXBUFFERPROC __teBindVertexBuffer = 0;
PFNGLVERTEXATTRIBFORMATPROC __teVertexAttribFormat = 0;
PFNGLVERTEXATTRIBIFORMATPROC __teVertexAttribIFormat = 0;
PFNGLVERTEXATTRIBLFORMATPROC __teVertexAttribLFormat = 0;
PFNGLVERTEXATTRIBBINDINGPROC __teVertexAttribBinding = 0;
PFNGLVERTEXBINDINGDIVISORPROC __teVertexBindingDivisor = 0;
PFNGLDEBUGMESSAGECONTROLPROC __teDebugMessageControl = 0;
PFNGLDEBUGMESSAGEINSERTPROC __teDebugMessageInsert = 0;
PFNGLDEBUGMESSAGECALLBACKPROC __teDebugMessageCallback = 0;
PFNGLGETDEBUGMESSAGELOGPROC __teGetDebugMessageLog = 0;
PFNGLPUSHDEBUGGROUPPROC __tePushDebugGroup = 0;
PFNGLPOPDEBUGGROUPPROC __tePopDebugGroup = 0;
PFNGLOBJECTLABELPROC __teObjectLabel = 0;
PFNGLGETOBJECTLABELPROC __teGetObjectLabel = 0;
PFNGLOBJECTPTRLABELPROC __teObjectPtrLabel = 0;
PFNGLGETOBJECTPTRLABELPROC __teGetObjectPtrLabel = 0;

//OpenGL 4.4 Extensions
PFNGLBUFFERSTORAGEPROC __teBufferStorage = 0;
PFNGLCLEARTEXIMAGEPROC __teClearTexImage = 0;
PFNGLCLEARTEXSUBIMAGEPROC __teClearTexSubImage = 0;
PFNGLBINDBUFFERSBASEPROC __teBindBuffersBase = 0;
PFNGLBINDBUFFERSRANGEPROC __teBindBuffersRange = 0;
PFNGLBINDTEXTURESPROC __teBindTextures = 0;
PFNGLBINDSAMPLERSPROC __teBindSamplers = 0;
PFNGLBINDIMAGETEXTURESPROC __teBindImageTextures = 0;
PFNGLBINDVERTEXBUFFERSPROC __teBindVertexBuffers = 0;


GLvoid TinyExtender::InitializeExtensions()
{
	TinyExtender::InitializeGLVersion();
	GLuint Version_Major, Version_Minor;
	Version_Major = TinyExtender::GLVersion_Major;
	Version_Minor = TinyExtender::GLVersion_Minor;

	//this was a bad idea...
	//(Version_Major >= 1 && Version_Minor >= 2) ? Load1_2Extensions() : TinyExtender::PrintErrorMessage(Version_Major, Version_Minor);
	
	if(Version_Major > 1 || (Version_Minor >=  2 && Version_Major >= 1))
	{
		Load1_2Extensions();
	}

	else
	{
		TinyExtender::PrintErrorMessage(1, 2);
		return; 
	}

	if(Version_Major > 1 || (Version_Minor >= 3 && Version_Major >= 1))
	{
		Load1_3Extensions();
	}

	else
	{
		TinyExtender::PrintErrorMessage(1, 3);
		return;
	}

	if(Version_Major > 1 || (Version_Minor >= 4 && Version_Major >= 1))
	{
		Load1_4Extensions();
	}

	else
	{
		TinyExtender::PrintErrorMessage(1, 4);
		return;
	}

	if(Version_Major > 1 || (Version_Minor >= 5 && Version_Major >= 1))
	{
		Load1_5Extensions();
	}

	else
	{
		TinyExtender::PrintErrorMessage(1, 5);
		return;
	}

	if(Version_Major > 2 || (Version_Minor >= 0 && Version_Major >= 2))
	{
		Load2_0Extensions();
	}

	else
	{
		TinyExtender::PrintErrorMessage(2, 0);
		return;
	}

	if(Version_Major > 2 || (Version_Minor >= 1 && Version_Major >= 2))
	{
		Load2_1Extensions();
	}

	else
	{
		TinyExtender::PrintErrorMessage(2, 1);
		return;
	}

	if(Version_Major > 3 || (Version_Minor >= 0 && Version_Major >= 3))
	{
		Load3_0Extensions();
	}

	else
	{
		TinyExtender::PrintErrorMessage(3, 0);
		return;
	}

	if(Version_Major > 3 || (Version_Minor >= 1 && Version_Major >= 3))
	{
		Load3_1Extensions();
	}

	else
	{
		TinyExtender::PrintErrorMessage(3, 1);
		return;
	}

	if(Version_Major > 3 || (Version_Minor >= 2 && Version_Major >= 3))
	{
		Load3_2Extensions();
	}

	else
	{
		TinyExtender::PrintErrorMessage(3, 2);
		return;
	}

	if(Version_Major > 3 || (Version_Minor >= 3 && Version_Major >= 3))
	{
		Load3_3Extensions();
	}

	else
	{
		TinyExtender::PrintErrorMessage(3, 3);
		return;
	}

	if(Version_Major > 4 || (Version_Minor >= 0 && Version_Major >= 4))
	{
		Load4_0Extensions();
	}

	else
	{
		TinyExtender::PrintErrorMessage(4, 0);
		return;
	}

	if(Version_Major > 4 || (Version_Minor >= 1 && Version_Major >= 4))
	{
		Load4_1Extensions();
	}

	else
	{
		TinyExtender::PrintErrorMessage(4, 1);
		return;
	}

	if(Version_Major > 4 || (Version_Minor >= 2 && Version_Major >= 4))
	{
		Load4_2Extensions();
	}

	else
	{
		TinyExtender::PrintErrorMessage(4, 2);
		return;
	}

	if(Version_Major > 4 || (Version_Minor >= 3 && Version_Minor >= 4))
	{
		Load4_3Extensions();
	}

	else
	{
		TinyExtender::PrintErrorMessage(4, 3);
	}

	if(Version_Major > 4 || (Version_Minor >= 4 && Version_Major >= 4))
	{
		Load4_4Extensions();
	}

	else
	{
		TinyExtender::PrintErrorMessage(4, 4);
		return;
	}
	
}

void* TinyExtender::GetProcAddress(const GLubyte* ProcName)
{
#if defined(_WIN32)
	return wglGetProcAddress((LPCTSTR)ProcName);
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
	glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBlendEquationSeparate");
	glDrawBuffers = (PFNGLDRAWBUFFERSPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDrawBuffers");
	glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glStencilOpSeparate");
	glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glStencilFuncSeparate");
	glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glStencilMaskSeparate");
	glAttachShader = (PFNGLATTACHSHADERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glAttachShader");
	glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBindAttribLocation");
	glCompileShader = (PFNGLCOMPILESHADERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glCompileShader");
	glCreateProgram = (PFNGLCREATEPROGRAMPROC)TinyExtender::GetProcAddress((const GLubyte*)"glCreateProgram");
	glDeleteProgram = (PFNGLDELETEPROGRAMPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDeleteProgram");
	glDetachShader = (PFNGLDETACHSHADERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDetachShader");
	glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDisableVertexAttribArray");
	glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)TinyExtender::GetProcAddress((const GLubyte*)"glEnableVertexAttribArray");
	glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetActiveAttrib");
	glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetActiveUniform");
	glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetAttachedShaders");
	glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetAttribLocation");
	glGetProgramiv = (PFNGLGETPROGRAMIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetProgramiv");
	glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetProgramInfoLog");
	glGetShaderSource = (PFNGLGETSHADERSOURCEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetShaderSource");
	glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetUniformLocation");
	glGetUniformfv = (PFNGLGETUNIFORMFVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetUniformfv");
	glGetUniformiv = (PFNGLGETUNIFORMIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetUniformiv");
	glGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetVertexAttribdv");
	glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetVertexAttribfv");
	glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetVertexAttribiv");
	glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetVertexAttribPointerv");
	glIsProgram = (PFNGLISPROGRAMPROC)TinyExtender::GetProcAddress((const GLubyte*)"glIsProgram");
	glIsShader = (PFNGLISSHADERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glIsShader");
	glLinkProgram = (PFNGLLINKPROGRAMPROC)TinyExtender::GetProcAddress((const GLubyte*)"glLinkProgram");
	glShaderSource = (PFNGLSHADERSOURCEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glShaderSource");
	glUseProgram = (PFNGLUSEPROGRAMPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUseProgram");
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
	glVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib4Nubv");
	glVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib4Nuiv");
	glVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib4Nusv");
	glVertexAttrib4bv = (PFNGLVERTEXATTRIB4BVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib4bv");
	glVertexAttrib4d = (PFNGLVERTEXATTRIB4DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib4d");
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
	glUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniformMatrix2x3fv");
	glUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniformMatrix3x2fv");
	glUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniformMatrix2x4fv");
	glUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniformMatrix4x2fv");
	glUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniformMatrix3x4fv");
	glUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniformMatrix4x3fv");
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
	glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBindBufferBase");
	glTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC)TinyExtender::GetProcAddress((const GLubyte*)"glTransformFeedbackVaryings");
	glGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetTransformFeedbackVarying");
	glClampColor = (PFNGLCLAMPCOLORPROC)TinyExtender::GetProcAddress((const GLubyte*)"glClampColor");
	glBeginConditionalRender = (PFNGLBEGINCONDITIONALRENDERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBeginConditionalRender");
	glEndConditionalRender = (PFNGLENDCONDITIONALRENDERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glEndConditionalRender");
	glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribIPointer");
	glGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetVertexAttribIiv");
	glGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetVertexAttribIuiv");
	glVertexAttribI1i = (PFNGLVERTEXATTRIBI1IPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribI1i");
	glVertexAttribI2i = (PFNGLVERTEXATTRIBI2IPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribI2i");
	glVertexAttribI3i = (PFNGLVERTEXATTRIBI3IPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribI3i");
	glVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribI4i");
	glVertexAttribI1ui = (PFNGLVERTEXATTRIBI1UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribI1ui");
	glVertexAttribI2ui = (PFNGLVERTEXATTRIBI2UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribI2ui");
	glVertexAttribI3ui = (PFNGLVERTEXATTRIBI3UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribI3ui");
	glVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribI4ui");
	glVertexAttribI1iv = (PFNGLVERTEXATTRIBI1IVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribI1iv");
	glVertexAttribI2iv = (PFNGLVERTEXATTRIBI2IVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribI2iv");
	glVertexAttribI3iv = (PFNGLVERTEXATTRIBI3IVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribI3iv");
	glVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribI4iv");
	glVertexAttribI1uiv = (PFNGLVERTEXATTRIBI1UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribI1uiv");
	glVertexAttribI2uiv = (PFNGLVERTEXATTRIBI2UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribI2uiv");
	glVertexAttribI3uiv = (PFNGLVERTEXATTRIBI3UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribI3uiv");
	glVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribI4uiv");
	glVertexAttribI4bv = (PFNGLVERTEXATTRIBI4BVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribI4bv");
	glVertexAttribI4sv = (PFNGLVERTEXATTRIBI4SVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribI4sv");
	glVertexAttribI4ubv = (PFNGLVERTEXATTRIBI4UBVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribI4ubv");
	glVertexAttribI4usv = (PFNGLVERTEXATTRIBI4USVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribI4usv");
	glGetUniformuiv = (PFNGLGETUNIFORMUIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetUniformuiv");
	glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBindFragDataLocation");
	glGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetFragDataLocation");
	glUniform1ui = (PFNGLUNIFORM1UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform1ui");
	glUniform2ui = (PFNGLUNIFORM2UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform2ui");
	glUniform3ui = (PFNGLUNIFORM3UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform3ui");
	glUniform4ui = (PFNGLUNIFORM4UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform4ui");
	glUniform1uiv = (PFNGLUNIFORM1UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform1uiv");
	glUniform2uiv = (PFNGLUNIFORM2UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform2uiv");
	glUniform3uiv = (PFNGLUNIFORM3UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform3uiv");
	glUniform4uiv = (PFNGLUNIFORM4UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform4uiv");
	glTexParameterIiv = (PFNGLTEXPARAMETERIIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glTexParameterIiv");
	glTexParameterIuiv = (PFNGLTEXPARAMETERIUIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glTexParameterIuiv");
	glGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetTexParameterIiv");
	glGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetTexParameterIuiv");
	glClearBufferiv = (PFNGLCLEARBUFFERIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glClearBufferiv");
	glClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glClearBufferuiv");
	glClearBufferfv = (PFNGLCLEARBUFFERFVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glClearBufferfv");
	glClearBufferfi = (PFNGLCLEARBUFFERFIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glClearBufferi");
	glGetStringi = (PFNGLGETSTRINGIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetStringi");
	glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glIsRenderbuffer");
	glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBindRenderbuffer");
	glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDeleteRenderbuffers");
	glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGenRenderbuffers");
	glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glRenderbufferStorage");
	glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetRenderbufferParameteriv");
	glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glIsFramebuffer");
	glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBindFramebuffer");
	glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDeleteFramebuffers");
	glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGenFramebuffers");
	glCheckFrameBufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)TinyExtender::GetProcAddress((const GLubyte*)"glCheckFrameBufferStatus");
	glFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glFramebufferTexture1D");
	glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glFramebufferTexture2D");
	glFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glFramebufferTexture3D");
	glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glFramebufferRenderbuffer");
	glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetFramebufferAttachmentParameteriv");
	glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGenerateMapmap");
	glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBlitFramebuffer");
	glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glRenderbufferStorageMultisample");
	glFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glFramebufferTextureLayer");
	glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glMapBufferRange");
	glFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glFlushMappedBufferRange");
	glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBindVertexArray");
	glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDeleteVertexArrays");
	glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGenVertexArrays");
	glIsVertexArray = (PFNGLISVERTEXARRAYPROC)TinyExtender::GetProcAddress((const GLubyte*)"glIsVertexArray");
}

GLvoid TinyExtender::Load3_1Extensions()
{
	glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDrawArraysInstanced");
	glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDrawElementsInstanced");
	glTexBuffer = (PFNGLTEXBUFFERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glTexBuffer");
	glPrimtiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEXPROC)TinyExtender::GetProcAddress((const GLubyte*)"glPrimtiveRestartIndex");
	glCopyBufferSubdata = (PFNGLCOPYBUFFERSUBDATAPROC)TinyExtender::GetProcAddress((const GLubyte*)"glCopyBufferSubdata");
	glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetUniformIndices");
	glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetActiveUniformsiv");
	glGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetActiveUniformName");
	glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetUniformBlockIndex");
	glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetActiveUniformBlockiv");
	glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetActiveUniformBlockName");
	glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniformBlockBinding");
}

GLvoid TinyExtender::Load3_2Extensions()
{
	glDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDrawElementsBaseVertex");
	glDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDrawRangeElementsBaseVertex");
	glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDrawElementsInstancedBaseVertex");
	glMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)TinyExtender::GetProcAddress((const GLubyte*)"glMultiDrawElementsBaseVertex");
	glProvokingVertex = (PFNGLPROVOKINGVERTEXPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProvokingVertex");
	glFenceSync = (PFNGLFENCESYNCPROC)TinyExtender::GetProcAddress((const GLubyte*)"glFenceSync");
	glIsSync = (PFNGLISSYNCPROC)TinyExtender::GetProcAddress((const GLubyte*)"glIsSync");
	glDeleteSync = (PFNGLDELETESYNCPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDeleteSync");
	glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC)TinyExtender::GetProcAddress((const GLubyte*)"glClientWaitSync");
	glWaitSync = (PFNGLWAITSYNCPROC)TinyExtender::GetProcAddress((const GLubyte*)"glWaitSync");
	glGetInteger64v = (PFNGLGETINTEGER64VPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetInteger64v");
	glGetSynciv = (PFNGLGETSYNCIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetSynciv");
	glGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetInteger64i_v");
	glGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetBufferParameteri64v");
	glFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC)TinyExtender::GetProcAddress((const GLubyte*)"glFramebufferTexture");
	glTexImage2DMultiSample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glTexImage2DMultiSample");
	glTexImage3DMultisample = (PFNGLTEXIMAGE3DMULTISAMPLEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glTexImage3DMultisample");
	glGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetMultisamplefv");
	glSampleMaski = (PFNGLSAMPLEMASKIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSampleMaski");
}

GLvoid TinyExtender::Load3_3Extensions()
{
	glBindFragDataLocationIndexed = (PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBindFragDataLocationIndexed");
	glGetFragDataIndex = (PFNGLGETFRAGDATAINDEXPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetFragDataIndex");
	glGenSamplers = (PFNGLGENSAMPLERSPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGenSamplers");
	glDeleteSamplers = (PFNGLDELETESAMPLERSPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDeleteSamplers");
	glIsSampler = (PFNGLISSAMPLERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glIsSampler");
	glBindSampler = (PFNGLBINDSAMPLERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBindSampler");
	glSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSamplerParameteri");
	glSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSamplerParameteriv");
	glSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSamplerParameterf");
	glSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSamplerParameterfv");
	glSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSamplerParameterIiv");
	glSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSamplerParameterIuiv");
	glGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetSamplerParameteriv");
	glGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetSamplerParameterIiv");
	glGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetSamplerParameterfv");
	glGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetSamplerParameterIuiv");
	glQueryCounter = (PFNGLQUERYCOUNTERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glQueryCounter");
	glGetQueryObjecti64v = (PFNGLGETQUERYOBJECTI64VPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetQueryObjecti64v");
	glGetQueryObjectui64v = (PFNGLGETQUERYOBJECTUI64VPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetQueryObjectui64v");
	glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribDivisor");
	glVertexAttribP1ui = (PFNGLVERTEXATTRIBP1UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribP1ui");
	glVertexAttribP1uiv = (PFNGLVERTEXATTRIBP1UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribP1uiv");
	glVertexAttribP2ui = (PFNGLVERTEXATTRIBP2UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribP2ui");
	glVertexAttribP2uiv = (PFNGLVERTEXATTRIBP2UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribP2uiv");
	glVertexAttribP3ui = (PFNGLVERTEXATTRIBP3UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribP3ui");
	glVertexAttribP3uiv = (PFNGLVERTEXATTRIBP3UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribP3uiv");
	glVertexAttribP4ui = (PFNGLVERTEXATTRIBP4UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribP4ui");
	glVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttrib4uiv");
	glVertexP2ui = (PFNGLVERTEXP2UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexP2ui");
	glVertexP2uiv = (PFNGLVERTEXP2UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexP2uiv");
	glVertexP3ui = (PFNGLVERTEXP3UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexP3ui");
	glVertexP3uiv = (PFNGLVERTEXP3UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexP3uiv");
	glVertexP4ui = (PFNGLVERTEXP4UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexP4ui");
	glVertexP4uiv = (PFNGLVERTEXP4UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexP4uiv");
	glTexCoordP1ui = (PFNGLTEXCOORDP1UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glTexCoordP1ui");
	glTexCoordP1uiv = (PFNGLTEXCOORDP1UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glTexCoordP1uiv");
	glTexCoordP2ui = (PFNGLTEXCOORDP2UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glTexCoordP2ui");
	glTexCoordP2uiv = (PFNGLTEXCOORDP2UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glTexCoordP2uiv");
	glTexCoordP3ui = (PFNGLTEXCOORDP3UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glTexCoordP3ui");
	glTexCoordP3uiv = (PFNGLTEXCOORDP3UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glTexCoordP3uiv");
	glTexCoordP4ui = (PFNGLTEXCOORDP4UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glTexCoordP4ui");
	glTexCoordP4uiv = (PFNGLTEXCOORDP4UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glTexCoordP4uiv");
	glMultiTexCoordP1ui = (PFNGLMULTITEXCOORDP1UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glMultiTexCoordP1ui");
	glMultiTexCoordP1uiv = (PFNGLMULTITEXCOORDP1UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glMultiTexCoordP1uiv");
	glMultiTexCoordP2ui = (PFNGLMULTITEXCOORDP2UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glMultiTexCoordP2ui");
	glMultiTexCoordP2uiv = (PFNGLMULTITEXCOORDP2UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glMultiTexCoordP2uiv");
	glMultiTexCoordP3ui = (PFNGLMULTITEXCOORDP3UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glMultiTexCoordP3ui");
	glMultiTexCoordP3uiv = (PFNGLMULTITEXCOORDP3UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glMultiTexCoordP3uiv");
	glMultiTexCoordP4ui = (PFNGLMULTITEXCOORDP4UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glMultiTexCoordP4ui");
	glMultiTexCoordP4uiv = (PFNGLMULTITEXCOORDP4UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glMultiTexCoordP4uiv");
	glNormalP3ui = (PFNGLNORMALP3UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glNormalP3ui");
	glNormalP3uiv = (PFNGLNORMALP3UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glNormalP3uiv");
	glColorP3ui = (PFNGLCOLORP3UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glColorP3ui");
	glColorP3uiv = (PFNGLCOLORP3UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glColorP3uiv");
	glColorP4ui = (PFNGLCOLORP4UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glColorP4ui");
	glColorP4uiv = (PFNGLCOLORP4UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glColorP4uiv");
	glSecondaryColorP3ui = (PFNGLSECONDARYCOLORP3UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSecondaryColorP3ui");
	glSecondaryColorP3uiv = (PFNGLSECONDARYCOLORP3UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glSecondaryColorP3uiv");
}

GLvoid TinyExtender::Load4_0Extensions()
{
	glMinSampleShading = (PFNGLMINSAMPLESHADINGPROC)TinyExtender::GetProcAddress((const GLubyte*)"glMinSampleShading");
	glBlendEquationi = (PFNGLBLENDEQUATIONIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBlendEquationi");
	glBlendEquationSeparatei = (PFNGLBLENDEQUATIONSEPARATEIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBlendEquationSeparatei");
	glBlendFunci = (PFNGLBLENDFUNCIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBlendFunci");
	glBlendFuncSeparatei = (PFNGLBLENDFUNCSEPARATEIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBlendFuncSeparatei");
	glDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECTPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDrawArraysIndirect");
	glDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECTPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDrawElementsIndirect");
	glUniform1d = (PFNGLUNIFORM1DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform1d");
	glUniform2d = (PFNGLUNIFORM2DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform2d");
	glUniform3d = (PFNGLUNIFORM3DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform3d");
	glUniform4d = (PFNGLUNIFORM4DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform4d");
	glUniform1dv = (PFNGLUNIFORM1DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform1dv");
	glUniform2dv = (PFNGLUNIFORM2DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform2dv");
	glUniform3dv = (PFNGLUNIFORM3DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform3dv");
	glUniform4dv = (PFNGLUNIFORM4DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniform4dv");
	glUniformMatrix2dv = (PFNGLUNIFORMMATRIX2DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniformMatrix2dv");
	glUniformMatrix3dv = (PFNGLUNIFORMMATRIX3DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniformMatrix3dv");
	glUniformMatrix4dv = (PFNGLUNIFORMMATRIX4DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniformMatrix4dv");
	glUniformMatrix2x3dv = (PFNGLUNIFORMMATRIX2X3DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniformMatrix2x3dv");
	glUniformMatrix2x4dv = (PFNGLUNIFORMMATRIX2X4DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniformMatrix2x4dv");
	glUniformMatrix3x2dv = (PFNGLUNIFORMMATRIX3X2DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniformMatrix3x2dv");
	glUniformMatrix3x4dv = (PFNGLUNIFORMMATRIX3X4DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniformMatrix3x4dv");
	glUniformMatrix4x2dv = (PFNGLUNIFORMMATRIX4X2DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniformMatrix4x2dv");
	glUniformMatrix4x3dv = (PFNGLUNIFORMMATRIX4X3DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniformMatrix4x3dv");
	glGetUniformdv = (PFNGLGETUNIFORMDVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetUniformdv");
	glGetSubroutineUniformLocation = (PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetSubroutineUniformLocation");
	glGetSubroutineIndex = (PFNGLGETSUBROUTINEINDEXPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetSubroutineIndex");
	glGetActiveSubroutineUniformiv = (PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetActiveSubroutineUniformiv");
	glGetActiveSubroutineUniformName = (PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetActiveSubroutineUniformName");
	glGetActiveSubroutineName = (PFNGLGETACTIVESUBROUTINENAMEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetActiveSubroutineName");
	glUniformSubroutinesuiv = (PFNGLUNIFORMSUBROUTINESUIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUniformSubroutinesuiv");
	glGetUniformSubroutineuiv = (PFNGLGETUNIFORMSUBROUTINEUIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetUniformSubroutineuiv");
	glGetProgramStageiv = (PFNGLGETPROGRAMSTAGEIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetProgramStageiv");
	glPatchParameteri = (PFNGLPATCHPARAMETERIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glPatchParameteri");
	glPatchParameterfv = (PFNGLPATCHPARAMETERFVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glPatchParameterfv");
	glBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACKPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBindTransformFeedback");
	glDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKSPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDeleteTransformFeedbacks");
	glGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKSPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGenTransformFeedbacks");
	glIsTransformFeedback = (PFNGLISTRANSFORMFEEDBACKPROC)TinyExtender::GetProcAddress((const GLubyte*)"glIsTransformFeedback");
	glPauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACKPROC)TinyExtender::GetProcAddress((const GLubyte*)"glPauseTransformFeedback");
	glResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACKPROC)TinyExtender::GetProcAddress((const GLubyte*)"glResumeTransformFeedback");
	glDrawTransformFeedback = (PFNGLDRAWTRANSFORMFEEDBACKPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDrawTransformFeedback");
	glDrawTransformFeedbackStream = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDrawTransformFeedbackStream");
	glBeginQueryIndexed = (PFNGLBEGINQUERYINDEXEDPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBeginQueryIndexed");
	glEndQueryIndexed = (PFNGLENDQUERYINDEXEDPROC)TinyExtender::GetProcAddress((const GLubyte*)"glEndQueryIndexed");
	glGetQueryIndexediv = (PFNGLGETQUERYINDEXEDIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetQueryIndexediv");
}

GLvoid TinyExtender::Load4_1Extensions()
{
	glReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glReleaseShaderCompiler");
	glShaderBinary = (PFNGLSHADERBINARYPROC)TinyExtender::GetProcAddress((const GLubyte*)"glShaderBinary");
	glGetShaderPrecisionFormat = (PFNGLGETSHADERPRECISIONFORMATPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetShaderPrecisionFormat");
	glDepthRangef = (PFNGLDEPTHRANGEFPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDepthRangef");
	glClearDepthf = (PFNGLCLEARDEPTHFPROC)TinyExtender::GetProcAddress((const GLubyte*)"glClearDepthf");
	glGetProgramBinary = (PFNGLGETPROGRAMBINARYPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetProgramBinary");
	glProgramBinary = (PFNGLPROGRAMBINARYPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramBinary");
	glProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramParameteri");
	glUseProgramStages = (PFNGLUSEPROGRAMSTAGESPROC)TinyExtender::GetProcAddress((const GLubyte*)"glUseProgramStages");
	glActiveShaderProgram = (PFNGLACTIVESHADERPROGRAMPROC)TinyExtender::GetProcAddress((const GLubyte*)"glActiveShaderProgram");
	glCreateShaderProgramv = (PFNGLCREATESHADERPROGRAMVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glCreateShaderProgramv");
	glBindProgramPipeline = (PFNGLBINDPROGRAMPIPELINEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBindProgramPipeline");
	glDeleteProgramPipelines = (PFNGLDELETEPROGRAMPIPELINESPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDeleteProgramPipelines");
	glGenProgramPipelines = (PFNGLGENPROGRAMPIPELINESPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGenProgramPipelines");
	glIsProgramPipeline = (PFNGLISPROGRAMPIPELINEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glIsProgramPipeline");
	glGetProgramPipelineiv = (PFNGLGETPROGRAMPIPELINEIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetProgramPipelineiv");
	glProgramUniform1i = (PFNGLPROGRAMUNIFORM1IPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform1i");
	glProgramUniform1iv = (PFNGLPROGRAMUNIFORM1IVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform1iv");
	glProgramUniform1f = (PFNGLPROGRAMUNIFORM1FPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform1f");
	glProgramUniform1fv = (PFNGLPROGRAMUNIFORM1FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform1fv");
	glProgramUniform1d = (PFNGLPROGRAMUNIFORM1DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform1d");
	glProgramUniform1dv = (PFNGLPROGRAMUNIFORM1DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform1dv");
	glProgramUniform1ui = (PFNGLPROGRAMUNIFORM1UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform1ui");
	glProgramUniform1uiv = (PFNGLPROGRAMUNIFORM1UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform1uiv");
	glProgramUniform2i = (PFNGLPROGRAMUNIFORM2IPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform2i");
	glProgramUniform2iv = (PFNGLPROGRAMUNIFORM2IVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform2iv");
	glProgramUniform2f = (PFNGLPROGRAMUNIFORM2FPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform2f");
	glProgramUniform2fv = (PFNGLPROGRAMUNIFORM2FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform2fv");
	glProgramUniform2d = (PFNGLPROGRAMUNIFORM2DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform2d");
	glProgramUniform2dv = (PFNGLPROGRAMUNIFORM2DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform2dv");
	glProgramUniform2ui = (PFNGLPROGRAMUNIFORM2UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform2ui");
	glProgramUniform2uiv = (PFNGLPROGRAMUNIFORM2UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform2uiv");
	glProgramUniform3i = (PFNGLPROGRAMUNIFORM3IPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform3i");
	glProgramUniform3iv = (PFNGLPROGRAMUNIFORM3IVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform3iv");
	glProgramUniform3f = (PFNGLPROGRAMUNIFORM3FPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform3f");
	glProgramUniform3fv = (PFNGLPROGRAMUNIFORM3FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform3fv");
	glProgramUniform3d = (PFNGLPROGRAMUNIFORM3DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform3d");
	glProgramUniform3dv = (PFNGLPROGRAMUNIFORM3DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform3dv");
	glProgramUniform3ui = (PFNGLPROGRAMUNIFORM3UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform3ui");
	glProgramUniform3uiv = (PFNGLPROGRAMUNIFORM3UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform3uiv");
	glProgramUniform4i = (PFNGLPROGRAMUNIFORM4IPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform4i");
	glProgramUniform4iv = (PFNGLPROGRAMUNIFORM4IVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform4iv");
	glProgramUniform4f = (PFNGLPROGRAMUNIFORM4FPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform4f");
	glProgramUniform4fv = (PFNGLPROGRAMUNIFORM4FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform4fv");
	glProgramUniform4d = (PFNGLPROGRAMUNIFORM4DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform4d");
	glProgramUniform4dv = (PFNGLPROGRAMUNIFORM4DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform4dv");
	glProgramUniform4ui = (PFNGLPROGRAMUNIFORM4UIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform4ui");
	glProgramUniform4uiv = (PFNGLPROGRAMUNIFORM4UIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniform4uiv");
	glProgramUniformMatrix2fv = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniformMatrix2fv");
	glProgramUniformMatrix3fv = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniformMatrix3fv");
	glProgramUniformMatrix4fv = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniformMatrix4fv");
	glProgramUniformMatrix2dv = (PFNGLPROGRAMUNIFORMMATRIX2DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniformMatrix2dv");
	glProgramUniformMatrix3dv = (PFNGLPROGRAMUNIFORMMATRIX3DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniformMatrix3dv");
	glProgramUniformMatrix4dv = (PFNGLPROGRAMUNIFORMMATRIX4DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniformMatrix4dv");
	glProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniformMatrix2x3fv");
	glProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniformMatrix3x2fv");
	glProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniformMatrix2x4fv");
	glProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniformMatrix4x2fv");
	glProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniformMatrix3x4fv");
	glProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniformMatrix4x3fv");
	glProgramUniformMatrix2x3dv = (PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniformMatrix2x3dv");
	glProgramUniformMatrix3x2dv = (PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniformMatrix3x2dv");
	glProgramUniformMatrix2x4dv = (PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniformMatrix2x4dv");
	glProgramUniformMatrix4x2dv = (PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniformMatrix4x2dv");
	glProgramUniformMatrix3x4dv = (PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniformMatrix3x4dv");
	glProgramUniformMatrix4x3dv = (PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glProgramUniformMatrix4x3dv");
	glValidateProgramPipeline = (PFNGLVALIDATEPROGRAMPIPELINEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glValidateProgramPipeline");
	glGetProgramPipelineInfoLog = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetProgramPipelineInfoLog");
	glVertexAttribL1d = (PFNGLVERTEXATTRIBL1DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribL1d");
	glVertexAttribL2d = (PFNGLVERTEXATTRIBL2DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribL2d");
	glVertexAttribL3d = (PFNGLVERTEXATTRIBL3DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribL3d");
	glVertexAttribL4d = (PFNGLVERTEXATTRIBL4DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribL4d");
	glVertexAttribL1dv = (PFNGLVERTEXATTRIBL1DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribL1dv");
	glVertexAttribL2dv = (PFNGLVERTEXATTRIBL2DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribL2dv");
	glVertexAttribL3dv = (PFNGLVERTEXATTRIBL3DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribL3dv");
	glVertexAttribL4dv = (PFNGLVERTEXATTRIBL4DVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribL4dv");
	glVertexAttribLPointer = (PFNGLVERTEXATTRIBLPOINTERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribLPointer");
	glGetVertexAttribLdv = (PFNGLGETVERTEXATTRIBLDVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetVertexAttribLdv");
	glViewportarrayv = (PFNGLVIEWPORTARRAYVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glViewportarrayv");
	glViewportIndexedf = (PFNGLVIEWPORTINDEXEDFPROC)TinyExtender::GetProcAddress((const GLubyte*)"glViewportIndexedf");
	glViewportIndexedfv = (PFNGLVIEWPORTINDEXEDFVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glViewportIndexedfv");
	glScissorArrayv = (PFNGLSCISSORARRAYVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glScissorArrayv");
	glScissorIndexed = (PFNGLSCISSORINDEXEDPROC)TinyExtender::GetProcAddress((const GLubyte*)"glScissorIndexed");
	glScissorIndexedv = (PFNGLSCISSORINDEXEDVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glScissorIndexedv");
	glDepthRangeIndexed = (PFNGLDEPTHRANGEINDEXEDPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDepthRangeIndexed");
	glGetFloati_v = (PFNGLGETFLOATI_VPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetFloati_v");
	glGetDoublei_v = (PFNGLGETDOUBLEI_VPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetDoublei_v");
}

GLvoid TinyExtender::Load4_2Extensions()
{
	glDrawArraysInstancedBaseInstance = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDrawArraysInstancedBaseInstance");
	glDrawElementsInstancedBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDrawElementsInstancedBaseInstance");
	glDrawElementsInstancedBaseVertexBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDrawElementsInstancedBaseVertexBaseInstance");
	glGetInternalFormativ = (PFNGLGETINTERNALFORMATIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetInternalFormativ");
	glGetActiveAtomicCounterBufferiv = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetActiveAtomicCounterBufferiv");
	glBindImageTexture = (PFNGLBINDIMAGETEXTUREPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBindImageTexture");
	glMemoryBarrier = (PFNGLMEMORYBARRIERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glMemoryBarrier");
	glTexStorage1D = (PFNGLTEXSTORAGE1DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glTexStorage1D");
	glTexStorage2D = (PFNGLTEXSTORAGE2DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glTexStorage2D");
	glTexStorage3D = (PFNGLTEXSTORAGE3DPROC)TinyExtender::GetProcAddress((const GLubyte*)"glTexStorage3D");
	glDrawTransformFeedbackInstanced = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDrawTransformFeedbackInstanced");
	glDrawTransformFeedbackStreamInstanced = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDrawTransformFeedbackStreamInstanced");
}

GLvoid TinyExtender::Load4_3Extensions()
{
	glClearBufferData = (PFNGLCLEARBUFFERDATAPROC)TinyExtender::GetProcAddress((const GLubyte*)"glClearBufferData");
	glClearBufferSubdata = (PFNGLCLEARBUFFERSUBDATAPROC)TinyExtender::GetProcAddress((const GLubyte*)"glClearBufferSubdata");
	glDispatchCompute = (PFNGLDISPATCHCOMPUTEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDispatchCompute");
	glDispatchComputeIndirect = (PFNGLDISPATCHCOMPUTEINDIRECTPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDispatchComputeIndirect");
	glCopyImageSubdata = (PFNGLCOPYIMAGESUBDATAPROC)TinyExtender::GetProcAddress((const GLubyte*)"glCopyImageSubdata");
	glFramebufferParameteri = (PFNGLFRAMEBUFFERPARAMETERIPROC)TinyExtender::GetProcAddress((const GLubyte*)"glFramebufferParameteri");
	glGetFramebufferParameteriv = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetFramebufferParameteriv");
	glGetInternalFormati64v = (PFNGLGETINTERNALFORMATI64VPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetInternalFormati64v");
	glInvalidateTexSubImage = (PFNGLINVALIDATETEXSUBIMAGEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glInvalidateTexSubImage");
	glInvalidateTexImage = (PFNGLINVALIDATETEXIMAGEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glInvalidateTexImage");
	glInvalidateBufferSubdata = (PFNGLINVALIDATEBUFFERSUBDATAPROC)TinyExtender::GetProcAddress((const GLubyte*)"glInvalidateBufferSubdata");
	glInvalidateBufferData = (PFNGLINVALIDATEBUFFERDATAPROC)TinyExtender::GetProcAddress((const GLubyte*)"glInvalidateBufferData");
	glInvalidateFramebuffer = (PFNGLINVALIDATEFRAMEBUFFERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glInvalidateFramebuffer");
	glInvalidateSubFramebuffer = (PFNGLINVALIDATESUBFRAMEBUFFERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glInvalidateSubFramebuffer");
	glMultiDrawArraysIndirect = (PFNGLMULTIDRAWARRAYSINDIRECTPROC)TinyExtender::GetProcAddress((const GLubyte*)"glMultiDrawArraysIndirect");
	glMultiDrawElementsIndirect = (PFNGLMULTIDRAWELEMENTSINDIRECTPROC)TinyExtender::GetProcAddress((const GLubyte*)"glMultiDrawElementsIndirect");
	glGetProgramInterfaceiv = (PFNGLGETPROGRAMINTERFACEIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetProgramInterfaceiv");
	glGetProgramResourceIndex = (PFNGLGETPROGRAMRESOURCEINDEXPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetProgramResourceIndex");
	glGetProgramResourceName = (PFNGLGETPROGRAMRESOURCENAMEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetProgramResourceName");
	glGetProgramResourceiv = (PFNGLGETPROGRAMRESOURCEIVPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetProgramResourceiv");
	glGetProgramResourceLocation = (PFNGLGETPROGRAMRESOURCELOCATIONPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetProgramResourceLocation");
	glGetProgramResourceLocationIndex = (PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetProgramResourceLocationIndex");
	glShaderStorageBlockBinding = (PFNGLSHADERSTORAGEBLOCKBINDINGPROC)TinyExtender::GetProcAddress((const GLubyte*)"glShaderStorageBlockBinding");
	glTexBufferRange = (PFNGLTEXBUFFERRANGEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glTexBufferRange");
	glTexStorage2DMultisample = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glTexStorage2DMultisample");
	glTexStorage3DMultisample = (PFNGLTEXSTORAGE3DMULTISAMPLEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glTexStorage3DMultisample");
	glTextureView = (PFNGLTEXTUREVIEWPROC)TinyExtender::GetProcAddress((const GLubyte*)"glTextureView");
	glBindVertexBuffer = (PFNGLBINDVERTEXBUFFERPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBindVertexBuffer");
	glVertexAttribFormat = (PFNGLVERTEXATTRIBFORMATPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribFormat");
	glVertexAttribIFormat = (PFNGLVERTEXATTRIBIFORMATPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribIFormat");
	glVertexAttribLFormat = (PFNGLVERTEXATTRIBLFORMATPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribLFormat");
	glVertexAttribBinding = (PFNGLVERTEXATTRIBBINDINGPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexAttribBinding");
	glVertexBindingDivisor = (PFNGLVERTEXBINDINGDIVISORPROC)TinyExtender::GetProcAddress((const GLubyte*)"glVertexBindingDivisor");
	glDebugMessageControl = (PFNGLDEBUGMESSAGECONTROLPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDebugMessageControl");
	glDebugMessageInsert = (PFNGLDEBUGMESSAGEINSERTPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDebugMessageInsert");
	glDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC)TinyExtender::GetProcAddress((const GLubyte*)"glDebugMessageCallback");
	glGetDebugMessageLog = (PFNGLGETDEBUGMESSAGELOGPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetDebugMessageLog");
	glPushDebugGroup = (PFNGLPUSHDEBUGGROUPPROC)TinyExtender::GetProcAddress((const GLubyte*)"glPushDebugGroup");
	glPopDebugGroup = (PFNGLPOPDEBUGGROUPPROC)TinyExtender::GetProcAddress((const GLubyte*)"glPopDebugGroup");
	glObjectLabel = (PFNGLOBJECTLABELPROC)TinyExtender::GetProcAddress((const GLubyte*)"glObjectLabel");
	glObjectPtrLabel = (PFNGLOBJECTPTRLABELPROC)TinyExtender::GetProcAddress((const GLubyte*)"glObjectPtrLabel");
	glGetObjectPtrLabel = (PFNGLGETOBJECTPTRLABELPROC)TinyExtender::GetProcAddress((const GLubyte*)"glGetObjectPtrLabel");
}

GLvoid TinyExtender::Load4_4Extensions()
{
	glBufferStorage = (PFNGLBUFFERSTORAGEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBufferStorage");
	glClearTexImage = (PFNGLCLEARTEXIMAGEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glClearTexImage");
	glClearTexSubImage = (PFNGLCLEARTEXSUBIMAGEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glClearTexSubImage");
	glBindBuffersBase = (PFNGLBINDBUFFERSBASEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBindBuffersBase");
	glBindBuffersRange = (PFNGLBINDBUFFERSRANGEPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBindBuffersRange");
	glBindTextures = (PFNGLBINDTEXTURESPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBindTextures");
	glBindSamplers = (PFNGLBINDSAMPLERSPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBindSamplers");
	glBindImageTextures = (PFNGLBINDIMAGETEXTURESPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBindImageTextures");
	glBindVertexBuffers = (PFNGLBINDVERTEXBUFFERSPROC)TinyExtender::GetProcAddress((const GLubyte*)"glBindVertexBuffers");
}

GLvoid TinyExtender::GetOpenGLVersion(GLuint& Version_Major, GLuint& Version_Minor)
{
	Version_Major = TinyExtender::GLVersion_Major;
	Version_Minor = TinyExtender::GLVersion_Minor;
}

GLvoid TinyExtender::InitializeExtensionsSpecific(GLbitfield OpenGLVersions)
{
	TinyExtender::InitializeGLVersion();	
	if(OpenGLVersions & GLVERSION1_2)
	{
		if(TinyExtender::GLVersion_Major >= 1 && TinyExtender::GLVersion_Minor >= 2)
		{
			TinyExtender::Load1_2Extensions();
		}

		printf("Error: OpenGL version 1.2 extensions not supported. (dude update your freaking drivers!)\n");
	}

	if(OpenGLVersions & GLVERSION1_3)
	{
		if(TinyExtender::GLVersion_Major >= 1 && TinyExtender::GLVersion_Minor >= 3)
		{
			TinyExtender::Load1_3Extensions();
		}

		printf("Error: OpenGL version 1.3 extensions not supported\n");
	}

	if(OpenGLVersions & GLVERSION1_4)
	{
		if(TinyExtender::GLVersion_Major >= 1 && TinyExtender::GLVersion_Minor >= 4)
		{
			TinyExtender::Load1_4Extensions();
		}

		printf("Error: OpenGL versions 1.4 extensions not supported\n");
	}

	if(OpenGLVersions & GLVERSION1_5)
	{
		if(TinyExtender::GLVersion_Major >= 1 && TinyExtender::GLVersion_Minor >= 5)
		{
			TinyExtender::Load1_5Extensions();
		}

		printf("Error: OpenGL versions 1.4 extensions not supported\n");
	}

	if(OpenGLVersions & GLVERSION2_0)
	{
		if(TinyExtender::GLVersion_Major >= 2 && TinyExtender::GLVersion_Minor >= 0)
		{
			TinyExtender::Load2_0Extensions();
		}

		printf("Error: OpenGL versions 2.0 extensions not supported\n");
	}

	if(OpenGLVersions & GLVERSION2_1)
	{
		if(TinyExtender::GLVersion_Major >= 2 && TinyExtender::GLVersion_Minor >= 1)
		{
			TinyExtender::Load2_1Extensions();
		}

		printf("Error: OpenGL versions 2.1 extensions not supported\n");
	}

	if(OpenGLVersions & GLVERSION3_0)
	{
		if(TinyExtender::GLVersion_Major >= 3 && TinyExtender::GLVersion_Minor >= 0)
		{
			TinyExtender::Load3_0Extensions();
		}

		printf("Error: OpenGL versions 3.0 extensions not supported\n");
	}

	if(OpenGLVersions & GLVERSION3_1)
	{
		if(TinyExtender::GLVersion_Major >= 3 && TinyExtender::GLVersion_Minor >= 1)
		{
			TinyExtender::Load3_1Extensions();
		}

		printf("Error: OpenGL versions 3.1 extensions not supported\n");
	}

	if(OpenGLVersions & GLVERSION3_2)
	{
		if(TinyExtender::GLVersion_Major >= 3 && TinyExtender::GLVersion_Minor >= 2)
		{
			TinyExtender::Load3_2Extensions();
		}

		printf("Error: OpenGL versions 3.2 extensions not supported\n");
	}

	if(OpenGLVersions & GLVERSION3_3)
	{
		if(TinyExtender::GLVersion_Major >= 3 && TinyExtender::GLVersion_Minor >= 3)
		{
			TinyExtender::Load3_3Extensions();
		}

		printf("Error: OpenGL versions 3.3 extensions not supported\n");
	}

	if(OpenGLVersions & GLVERSION4_0)
	{
		if(TinyExtender::GLVersion_Major >= 4 && TinyExtender::GLVersion_Minor >= 0)
		{
			TinyExtender::Load4_0Extensions();
		}

		printf("Error: OpenGL versions 4.0 extensions not supported\n");
	}

	if(OpenGLVersions & GLVERSION4_1)
	{
		if(TinyExtender::GLVersion_Major >= 4 && TinyExtender::GLVersion_Minor >= 1)
		{
			TinyExtender::Load4_1Extensions();
		}

		printf("Error: OpenGL versions 4.1 extensions not supported\n");
	}

	if(OpenGLVersions & GLVERSION4_2)
	{
		if(TinyExtender::GLVersion_Major >= 4 && TinyExtender::GLVersion_Minor >= 2)
		{
			TinyExtender::Load4_2Extensions();
		}

		printf("Error: OpenGL versions 4.2 extensions not supported\n");
	}

	if(OpenGLVersions & GLVERSION4_3)
	{
		if(TinyExtender::GLVersion_Major >= 4 && TinyExtender::GLVersion_Minor >= 3)
		{
			TinyExtender::Load4_3Extensions();
		}

		printf("Error: OpenGL versions 4.3 extensions not supported\n");
	}

	if(OpenGLVersions & GLVERSION4_4)
	{
		if(TinyExtender::GLVersion_Major >= 4 && TinyExtender::GLVersion_Minor >= 4)
		{
			TinyExtender::Load4_4Extensions();
		}

		printf("Error: OpenGL versions 4.4 extensions not supported\n");
	}
}

GLvoid TinyExtender::InitializeGLVersion()
{
	const GLubyte* VersionString = glGetString(GL_VERSION);

	TinyExtender::GLVersion_Major = VersionString[0] - '0';
	TinyExtender::GLVersion_Minor = VersionString[2] - '0';

	printf("%s \n", VersionString);
}

GLboolean TinyExtender::IsExtensionSupported(const GLubyte* ExtensionName)
{
	GLubyte* Extensions; //all the extensions
	GLubyte* End; //the last extension name in Extensions 
	GLint NameLength; //the string length of the given extension

	NameLength = strlen(ExtensionName); // the length of the given extension name string 

	Extensions = glGetString(GL_EXTENSIONS); // get all supported extensions

	//if extensions is not empty
	if(Extensions) 
	{
		End = Extensions + strlen((const char*)Extensions);
		
		while (Extensions < End)
		{
			GLint Blarg = strcspn((const char*)Extensions, " ");
			if((NameLength == Blarg) && (strncmp(ExtensionName, Extensions, Blarg) == 0))
			{
				return GL_TRUE;
			}	

			Extensions += (Blarg + 1);
		}
		return GL_FALSE;
	}
	return GL_FALSE;
}

GLvoid TinyExtender::PrintErrorMessage(GLuint Version_Major, GLuint Version_Minor)
{
	printf("Error: OpenGL version %i.%i not supported\n", Version_Major, Version_Minor);
}

GLuint TinyExtender::GLVersion_Major = 0;
GLuint TinyExtender::GLVersion_Minor = 0;
