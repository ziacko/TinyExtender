﻿#ifndef TINYEXTENDER_H_
#define TINYEXTENDER_H_

#if defined(_WIN32) || defined(_WIN64)
#define TE_WINDOWS
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif //WIN32_LEAN_AND_MEAN
#ifndef NOMINMAX
#define NOMINMAX 1
#endif //NOMINMAX

#include <Windows.h>
#include <gl/GL.h>
#endif //_WIN32 || _WIN64

#if defined(__linux__)
#define TE_LINUX
#include <GL/glx.h>
#endif //__linux__

#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <functional>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <functional>
#include <memory>
#include <system_error>


#ifndef GLEXT_64_TYPES_DEFINED
	/* This code block is duplicated in glxext.h, so must be protected */
#define GLEXT_64_TYPES_DEFINED
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <inttypes.h>
#if defined(__STDC__)
	typedef long long int int64_t;
	typedef unsigned long long int uint64_t;
#endif /* __STDC__ */
#elif defined(_WIN32) && defined(__GNUC__)
#include <stdint.h>
#elif defined(_WIN32)
	typedef __int32 int32_t;
	typedef __int64 int64_t;
	typedef unsigned __int64 uint64_t;
#else
	/* fall back if nothing above works */
#include <inttypes.h>
#endif
#endif

namespace TinyExtender
{
	//OpenGL 1.2 Extensions
	extern void(*glDrawRangeElements) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
	extern void(*glTexImage3D) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
	extern void(*glTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
	extern void(*glCopyTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	enum class openGL1_2 : unsigned int
	{
		UNSIGNED_BYTE_3_3_2 =				0x8032,
		UNSIGNED_SHORT_4_4_4_4 =			0x8033,
		UNSIGNED_SHORT_5_5_5_1 =			0x8034,
		UNSIGNED_INT_8_8_8_8 =				0x8035,
		UNSIGNED_INT_10_10_10_2 =			0x8036,
		TEXTURE_BINDING_3D =				0x806A,
		PACK_SKIP_IMAGES =					0x806B,
		PACK_IMAGE_HEIGHT =					0x806C,
		UNPACK_SKIP_IMAGES =				0x806D,
		UNPACK_IMAGE_HEIGHT =				0x806E,
		TEXTURE_3D =						0x806F,
		PROXY_TEXTURE_3D =					0x8070,
		TEXTURE_DEPTH =						0x8071,
		TEXTURE_WRAP_R =					0x8072,
		MAX_3D_TEXTURE_SIZE =				0x8073,
		UNSIGNED_BYTE_2_3_3_REV =			0x8362,
		UNSIGNED_SHORT_5_6_5 =				0x8363,
		UNSIGNED_SHORT_5_6_5_REV =			0x8364,
		UNSIGNED_SHORT_4_4_4_4_REV =		0x8365,
		UNSIGNED_SHORT_1_5_5_5_REV =		0x8366,
		UNSIGNED_INT_8_8_8_8_REV =			0x8367,
		UNSIGNED_INT_2_10_10_10_REV =		0x8368,
		BGR =								0x80E0,
		BGRA =								0x80E1,
		MAX_ELEMENTS_VERTICES =				0x80E8,
		MAX_ELEMENTS_INDICES =				0x80E9,
		CLAMP_TO_EDGE =						0x812F,
		TEXTURE_MIN_LOD =					0x813A,
		TEXTURE_MAX_LOD =					0x813B,
		TEXTURE_BASE_LEVEL =				0x813C,
		TEXTURE_MAX_LEVEL =					0x813D,
		SMOOTH_POINT_SIZE_RANGE =			0x0B12,
		SMOOTH_POINT_SIZE_GRANULARITY =		0x0B13,
		SMOOTH_LINE_WIDTH_RANGE =			0x0B22,
		SMOOTH_LINE_WIDTH_GRANULARITY =		0x0B23,
		ALIASED_LINE_WIDTH_RANGE =			0x846E,
		RESCALE_NORMAL =					0x803A,
		LIGHT_MODEL_COLOR_CONTROL =			0x81F8,
		SINGLE_COLOR =						0x81F9,
		SEPARATE_SPECULAR_COLOR =			0x81FA,
		ALIASED_POINT_SIZE_RANGE =			0x846D
	};

	//OpenGL 1.3 Extensions
	extern void(*glActiveTexture) (GLenum texture);
	extern void(*glSampleCoverage) (GLfloat value, GLboolean invert);
	extern void(*glCompressedTexImage3D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
	extern void(*glCompressedTexImage2D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
	extern void(*glCompressedTexImage1D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
	extern void(*glCompressedTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
	extern void(*glCompressedTexSubImage2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
	extern void(*glCompressedTexSubImage1D) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
	extern void(*glGetCompressedTexImage) (GLenum target, GLint level, void *img);
	extern void(*glClientActiveTexture) (GLenum texture);
	extern void(*glMultiTexCoord1d) (GLenum target, GLdouble s);
	extern void(*glMultiTexCoord1dv) (GLenum target, const GLdouble *v);
	extern void(*glMultiTexCoord1f) (GLenum target, GLfloat s);
	extern void(*glMultiTexCoord1fv) (GLenum target, const GLfloat *v);
	extern void(*glMultiTexCoord1i) (GLenum target, GLint s);
	extern void(*glMultiTexCoord1iv) (GLenum target, const GLint *v);
	extern void(*glMultiTexCoord1s) (GLenum target, GLshort s);
	extern void(*glMultiTexCoord1sv) (GLenum target, const GLshort *v);
	extern void(*glMultiTexCoord2d) (GLenum target, GLdouble s, GLdouble t);
	extern void(*glMultiTexCoord2dv) (GLenum target, const GLdouble *v);
	extern void(*glMultiTexCoord2f) (GLenum target, GLfloat s, GLfloat t);
	extern void(*glMultiTexCoord2fv) (GLenum target, const GLfloat *v);
	extern void(*glMultiTexCoord2i) (GLenum target, GLint s, GLint t);
	extern void(*glMultiTexCoord2iv) (GLenum target, const GLint *v);
	extern void(*glMultiTexCoord2s) (GLenum target, GLshort s, GLshort t);
	extern void(*glMultiTexCoord2sv) (GLenum target, const GLshort *v);
	extern void(*glMultiTexCoord3d) (GLenum target, GLdouble s, GLdouble t, GLdouble r);
	extern void(*glMultiTexCoord3dv) (GLenum target, const GLdouble *v);
	extern void(*glMultiTexCoord3f) (GLenum target, GLfloat s, GLfloat t, GLfloat r);
	extern void(*glMultiTexCoord3fv) (GLenum target, const GLfloat *v);
	extern void(*glMultiTexCoord3i) (GLenum target, GLint s, GLint t, GLint r);
	extern void(*glMultiTexCoord3iv) (GLenum target, const GLint *v);
	extern void(*glMultiTexCoord3s) (GLenum target, GLshort s, GLshort t, GLshort r);
	extern void(*glMultiTexCoord3sv) (GLenum target, const GLshort *v);
	extern void(*glMultiTexCoord4d) (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
	extern void(*glMultiTexCoord4dv) (GLenum target, const GLdouble *v);
	extern void(*glMultiTexCoord4f) (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
	extern void(*glMultiTexCoord4fv) (GLenum target, const GLfloat *v);
	extern void(*glMultiTexCoord4i) (GLenum target, GLint s, GLint t, GLint r, GLint q);
	extern void(*glMultiTexCoord4iv) (GLenum target, const GLint *v);
	extern void(*glMultiTexCoord4s) (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
	extern void(*glMultiTexCoord4sv) (GLenum target, const GLshort *v);
	extern void(*glLoadTransposeMatrixf) (const GLfloat *m);
	extern void(*glLoadTransposeMatrixd) (const GLdouble *m);
	extern void(*glMultTransposeMatrixf) (const GLfloat *m);
	extern void(*glMultTransposeMatrixd) (const GLdouble *m);
	enum class openGL1_3 : unsigned int
	{
		TEXTURE0 =								0x84C0,
		TEXTURE1 =								0x84C1,
		TEXTURE2 =								0x84C2,
		TEXTURE3 =								0x84C3,
		TEXTURE4 =								0x84C4,
		TEXTURE5 =								0x84C5,
		TEXTURE6 =								0x84C6,
		TEXTURE7 =								0x84C7,
		TEXTURE8 =								0x84C8,
		TEXTURE9 =								0x84C9,
		TEXTURE10 =								0x84CA,
		TEXTURE11 =								0x84CB,
		TEXTURE12 =								0x84CC,
		TEXTURE13 =								0x84CD,
		TEXTURE14 =								0x84CE,
		TEXTURE15 =								0x84CF,
		TEXTURE16 =								0x84D0,
		TEXTURE17 =								0x84D1,
		TEXTURE18 =								0x84D2,
		TEXTURE19 =								0x84D3,
		TEXTURE20 =								0x84D4,
		TEXTURE21 =								0x84D5,
		TEXTURE22 =								0x84D6,
		TEXTURE23 =								0x84D7,
		TEXTURE24 =								0x84D8,
		TEXTURE25 =								0x84D9,
		TEXTURE26 =								0x84DA,
		TEXTURE27 =								0x84DB,
		TEXTURE28 =								0x84DC,
		TEXTURE29 =								0x84DD,
		TEXTURE30 =								0x84DE,
		TEXTURE31 =								0x84DF,
		ACTIVE_TEXTURE =						0x84E0,
		MULTISAMPLE =							0x809D,
		SAMPLE_ALPHA_TO_COVERAGE =				0x809E,
		SAMPLE_ALPHA_TO_ONE =					0x809F,
		SAMPLE_COVERAGE =						0x80A0,
		SAMPLE_BUFFERS =						0x80A8,
		SAMPLES =								0x80A9,
		SAMPLE_COVERAGE_VALUE =					0x80AA,
		SAMPLE_COVERAGE_INVERT =				0x80AB,
		TEXTURE_CUBE_MAP =						0x8513,
		TEXTURE_BINDING_CUBE_MAP =				0x8514,
		TEXTURE_CUBE_MAP_POSITIVE_X =			0x8515,
		TEXTURE_CUBE_MAP_NEGATIVE_X =			0x8516,
		TEXTURE_CUBE_MAP_POSITIVE_Y =			0x8517,
		TEXTURE_CUBE_MAP_NEGATIVE_Y =			0x8518,
		TEXTURE_CUBE_MAP_POSITIVE_Z =			0x8519,
		TEXTURE_CUBE_MAP_NEGATIVE_Z =			0x851A,
		PROXY_TEXTURE_CUBE_MAP =				0x851B,
		MAX_CUBE_MAP_TEXTURE_SIZE =				0x851C,
		COMPRESSED_RGB =						0x84ED,
		COMPRESSED_RGBA =						0x84EE,
		TEXTURE_COMPRESSION_HINT =				0x84EF,
		TEXTURE_COMPRESSED_IMAGE_SIZE =			0x86A0,
		TEXTURE_COMPRESSED =					0x86A1,
		NUM_COMPRESSED_TEXTURE_FORMATS =		0x86A2,
		COMPRESSED_TEXTURE_FORMATS =			0x86A3,
		CLAMP_TO_BORDER =						0x812D,
		CLIENT_ACTIVE_TEXTURE =					0x84E1,
		MAX_TEXTURE_UNITS =						0x84E2,
		TRANSPOSE_MODELVIEW_MATRIX =			0x84E3,
		TRANSPOSE_PROJECTION_MATRIX =			0x84E4,
		TRANSPOSE_TEXTURE_MATRIX =				0x84E5,
		TRANSPOSE_COLOR_MATRIX =				0x84E6,
		MULTISAMPLE_BIT =						0x20000000,
		NORMAL_MAP =							0x8511,
		REFLECTION_MAP =						0x8512,
		COMPRESSED_ALPHA =						0x84E9,
		COMPRESSED_LUMINANCE =					0x84EA,
		COMPRESSED_LUMINANCE_ALPHA =			0x84EB,
		COMPRESSED_INTENSITY =					0x84EC,
		COMBINE =								0x8570,
		COMBINE_RGB =							0x8571,
		COMBINE_ALPHA =							0x8572,
		SOURCE0_RGB =							0x8580,
		SOURCE1_RGB =							0x8581,
		SOURCE2_RGB =							0x8582,
		SOURCE0_ALPHA =							0x8588,
		SOURCE1_ALPHA =							0x8589,
		SOURCE2_ALPHA =							0x858A,
		OPERAND0_RGB =							0x8590,
		OPERAND1_RGB =							0x8591,
		OPERAND2_RGB =							0x8592,
		OPERAND0_ALPHA =						0x8598,
		OPERAND1_ALPHA =						0x8599,
		OPERAND2_ALPHA =						0x859A,
		RGB_SCALE =								0x8573,
		ADD_SIGNED =							0x8574,
		INTERPOLATE =							0x8575,
		SUBTRACT =								0x84E7,
		CONSTANT =								0x8576,
		PRIMARY_COLOR =							0x8577,
		PREVIOUS =								0x8578,
		DOT3_RGB =								0x86AE,
		DOT3_RGBA =								0x86AF,
	};

	//OpenGL 1.4 Extensions
	extern void(*glBlendFuncSeparate) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
	extern void(*glMultiDrawArrays) (GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
	extern void(*glMultiDrawElements) (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
	extern void(*glPointParameterf) (GLenum pname, GLfloat param);
	extern void(*glPointParameterfv) (GLenum pname, const GLfloat *params);
	extern void(*glPointParameteri) (GLenum pname, GLint param);
	extern void(*glPointParameteriv) (GLenum pname, const GLint *params);
	extern void(*glFogCoordf) (GLfloat coord);
	extern void(*glFogCoordfv) (const GLfloat *coord);
	extern void(*glFogCoordd) (GLdouble coord);
	extern void(*glFogCoorddv) (const GLdouble *coord);
	extern void(*glFogCoordPointer) (GLenum type, GLsizei stride, const void *pointer);
	extern void(*glSecondaryColor3b) (GLbyte red, GLbyte green, GLbyte blue);
	extern void(*glSecondaryColor3bv) (const GLbyte *v);
	extern void(*glSecondaryColor3d) (GLdouble red, GLdouble green, GLdouble blue);
	extern void(*glSecondaryColor3dv) (const GLdouble *v);
	extern void(*glSecondaryColor3f) (GLfloat red, GLfloat green, GLfloat blue);
	extern void(*glSecondaryColor3fv) (const GLfloat *v);
	extern void(*glSecondaryColor3i) (GLint red, GLint green, GLint blue);
	extern void(*glSecondaryColor3iv) (const GLint *v);
	extern void(*glSecondaryColor3s) (GLshort red, GLshort green, GLshort blue);
	extern void(*glSecondaryColor3sv) (const GLshort *v);
	extern void(*glSecondaryColor3ub) (GLubyte red, GLubyte green, GLubyte blue);
	extern void(*glSecondaryColor3ubv) (const GLubyte *v);
	extern void(*glSecondaryColor3ui) (GLuint red, GLuint green, GLuint blue);
	extern void(*glSecondaryColor3uiv) (const GLuint *v);
	extern void(*glSecondaryColor3us) (GLushort red, GLushort green, GLushort blue);
	extern void(*glSecondaryColor3usv) (const GLushort *v);
	extern void(*glSecondaryColorPointer) (GLint size, GLenum type, GLsizei stride, const void *pointer);
	extern void(*glWindowPos2d) (GLdouble x, GLdouble y);
	extern void(*glWindowPos2dv) (const GLdouble *v);
	extern void(*glWindowPos2f) (GLfloat x, GLfloat y);
	extern void(*glWindowPos2fv) (const GLfloat *v);
	extern void(*glWindowPos2i) (GLint x, GLint y);
	extern void(*glWindowPos2iv) (const GLint *v);
	extern void(*glWindowPos2s) (GLshort x, GLshort y);
	extern void(*glWindowPos2sv) (const GLshort *v);
	extern void(*glWindowPos3d) (GLdouble x, GLdouble y, GLdouble z);
	extern void(*glWindowPos3dv) (const GLdouble *v);
	extern void(*glWindowPos3f) (GLfloat x, GLfloat y, GLfloat z);
	extern void(*glWindowPos3fv) (const GLfloat *v);
	extern void(*glWindowPos3i) (GLint x, GLint y, GLint z);
	extern void(*glWindowPos3iv) (const GLint *v);
	extern void(*glWindowPos3s) (GLshort x, GLshort y, GLshort z);
	extern void(*glWindowPos3sv) (const GLshort *v);
	extern void(*glBlendColor) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	extern void(*glBlendEquation) (GLenum mode);
	enum class openGL1_4 : unsigned int
	{
		BLEND_DST_RGB =						0x80C8,
		BLEND_SRC_RGB =						0x80C9,
		BLEND_DST_ALPHA =					0x80CA,
		BLEND_SRC_ALPHA =					0x80CB,
		POINT_FADE_THRESHOLD_SIZE =			0x8128,
		DEPTH_COMPONENT16 =					0x81A5,
		DEPTH_COMPONENT24 =					0x81A6,
		DEPTH_COMPONENT32 =					0x81A7,
		MIRRORED_REPEAT =					0x8370,
		MAX_TEXTURE_LOD_BIAS =				0x84FD,
		TEXTURE_LOD_BIAS =					0x8501,
		INCR_WRAP =							0x8507,
		DECR_WRAP =							0x8508,
		TEXTURE_DEPTH_SIZE =				0x884A,
		TEXTURE_COMPARE_MODE =				0x884C,
		TEXTURE_COMPARE_FUNC =				0x884D,
		POINT_SIZE_MIN =					0x8126,
		POINT_SIZE_MAX =					0x8127,
		POINT_DISTANCE_ATTENUATION =		0x8129,
		GENERATE_MIPMAP =					0x8191,
		GENERATE_MIPMAP_HINT =				0x8192,
		FOG_COORDINATE_SOURCE =				0x8450,
		FOG_COORDINATE =					0x8451,
		FRAGMENT_DEPTH =					0x8452,
		CURRENT_FOG_COORDINATE =			0x8453,
		FOG_COORDINATE_ARRAY_TYPE =			0x8454,
		FOG_COORDINATE_ARRAY_STRIDE =		0x8455,
		FOG_COORDINATE_ARRAY_POINTER =		0x8456,
		FOG_COORDINATE_ARRAY =				0x8457,
		COLOR_SUM =							0x8458,
		CURRENT_SECONDARY_COLOR =			0x8459,
		SECONDARY_COLOR_ARRAY_SIZE =		0x845A,
		SECONDARY_COLOR_ARRAY_TYPE =		0x845B,
		SECONDARY_COLOR_ARRAY_STRIDE =		0x845C,
		SECONDARY_COLOR_ARRAY_POINTER =		0x845D,
		SECONDARY_COLOR_ARRAY =				0x845E,
		TEXTURE_FILTER_CONTROL =			0x8500,
		DEPTH_TEXTURE_MODE =				0x884B,
		COMPARE_R_TO_TEXTURE =				0x884E,
		FUNC_ADD =							0x8006,
		FUNC_SUBTRACT =						0x800A,
		FUNC_REVERSE_SUBTRACT =				0x800B,
		MIN =								0x8007,
		MAX =								0x8008,
		CONSTANT_COLOR =					0x8001,
		ONE_MINUS_CONSTANT_COLOR =			0x8002,
		CONSTANT_ALPHA =					0x8003,
		ONE_MINUS_CONSTANT_ALPHA =			0x8004
	};

	//OpenGL 1.5 Extensions
	typedef ptrdiff_t GLsizeiptr;
	typedef ptrdiff_t GLintptr;
	extern void(*glGenQueries) (GLsizei n, GLuint *ids);
	extern void(*glDeleteQueries) (GLsizei n, const GLuint *ids);
	extern GLboolean(*glIsQuery) (GLuint id);
	extern void(*glBeginQuery) (GLenum target, GLuint id);
	extern void(*glEndQuery) (GLenum target);
	extern void(*glGetQueryiv) (GLenum target, GLenum pname, GLint *params);
	extern void(*glGetQueryObjectiv) (GLuint id, GLenum pname, GLint *params);
	extern void(*glGetQueryObjectuiv) (GLuint id, GLenum pname, GLuint *params);
	extern void(*glBindBuffer) (GLenum target, GLuint buffer);
	extern void(*glDeleteBuffers) (GLsizei n, const GLuint *buffers);
	extern void(*glGenBuffers) (GLsizei n, GLuint *buffers);
	extern GLboolean(*glIsBuffer) (GLuint buffer);
	extern void(*glBufferData) (GLenum target, GLsizeiptr size, const void *data, GLenum usage);
	extern void(*glBufferSubData) (GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
	extern void(*glGetBufferSubData) (GLenum target, GLintptr offset, GLsizeiptr size, void *data);
	extern void * (*glMapBuffer) (GLenum target, GLenum access);
	extern GLboolean(*glUnmapBuffer) (GLenum target);
	extern void(*glGetBufferParameteriv) (GLenum target, GLenum pname, GLint *params);
	extern void(*glGetBufferPointerv) (GLenum target, GLenum pname, void **params);
	enum class openGL1_5 : unsigned int
	{
		BUFFER_SIZE =								0x8764,
		BUFFER_USAGE =								0x8765,
		QUERY_COUNTER_BITS =						0x8864,
		CURRENT_QUERY =								0x8865,
		QUERY_RESULT =								0x8866,
		QUERY_RESULT_AVAILABLE =					0x8867,
		ARRAY_BUFFER =								0x8892,
		ELEMENT_ARRAY_BUFFER =						0x8893,
		ARRAY_BUFFER_BINDING =						0x8894,
		ELEMENT_ARRAY_BUFFER_BINDING =				0x8895,
		VERTEX_ATTRIB_ARRAY_BUFFER_BINDING =		0x889F,
		READ_ONLY =									0x88B8,
		WRITE_ONLY =								0x88B9,
		READ_WRITE =								0x88BA,
		BUFFER_ACCESS =								0x88BB,
		BUFFER_MAPPED =								0x88BC,
		BUFFER_MAP_POINTER =						0x88BD,
		STREAM_DRAW =								0x88E0,
		STREAM_READ =								0x88E1,
		STREAM_COPY =								0x88E2,
		STATIC_DRAW =								0x88E4,
		STATIC_READ =								0x88E5,
		STATIC_COPY =								0x88E6,
		DYNAMIC_DRAW =								0x88E8,
		DYNAMIC_READ =								0x88E9,
		DYNAMIC_COPY =								0x88EA,
		SAMPLES_PASSED =							0x8914,
		SRC1_ALPHA =								0x8589,
		VERTEX_ARRAY_BUFFER_BINDING =				0x8896,
		NORMAL_ARRAY_BUFFER_BINDING =				0x8897,
		COLOR_ARRAY_BUFFER_BINDING =				0x8898,
		INDEX_ARRAY_BUFFER_BINDING =				0x8899,
		TEXTURE_COORD_ARRAY_BUFFER_BINDING =		0x889A,
		EDGE_FLAG_ARRAY_BUFFER_BINDING =			0x889B,
		SECONDARY_COLOR_ARRAY_BUFFER_BINDING =		0x889C,
		FOG_COORDINATE_ARRAY_BUFFER_BINDING =		0x889D,
		WEIGHT_ARRAY_BUFFER_BINDING =				0x889E,
		FOG_COORD_SRC =								0x8450,
		FOG_COORD =									0x8451,
		CURRENT_FOG_COORD =							0x8453,
		FOG_COORD_ARRAY_TYPE =						0x8454,
		FOG_COORD_ARRAY_STRIDE =					0x8455,
		FOG_COORD_ARRAY_POINTER =					0x8456,
		FOG_COORD_ARRAY =							0x8457,
		FOG_COORD_ARRAY_BUFFER_BINDING =			0x889D,
		SRC0_RGB =									0x8580,
		SRC1_RGB =									0x8581,
		SRC2_RGB =									0x8582,
		SRC0_ALPHA =								0x8588,
		SRC2_ALPHA =								0x858A,
	};

	//2.0 extensions
	typedef char GLchar;
	extern void(*glBlendEquationSeparate) (GLenum modeRGB, GLenum modeAlpha);
	extern void(*glDrawBuffers) (GLsizei n, const GLenum *bufs);
	extern void(*glStencilOpSeparate) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
	extern void(*glStencilFuncSeparate) (GLenum face, GLenum func, GLint ref, GLuint mask);
	extern void(*glStencilMaskSeparate) (GLenum face, GLuint mask);
	extern void(*glAttachShader) (GLuint program, GLuint shader);
	extern void(*glBindAttribLocation) (GLuint program, GLuint index, const GLchar *name);
	extern void(*glCompileShader) (GLuint shader);
	extern GLuint(*glCreateProgram) (void);
	extern GLuint(*glCreateShader) (GLenum type);
	extern void(*glDeleteProgram) (GLuint program);
	extern void(*glDeleteShader) (GLuint shader);
	extern void(*glDetachShader) (GLuint program, GLuint shader);
	extern void(*glDisableVertexAttribArray) (GLuint index);
	extern void(*glEnableVertexAttribArray) (GLuint index);
	extern void(*glGetActiveAttrib) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
	extern void(*glGetActiveUniform) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
	extern void(*glGetAttachedShaders) (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
	extern GLint(*glGetAttribLocation) (GLuint program, const GLchar *name);
	extern void(*glGetProgramiv) (GLuint program, GLenum pname, GLint *params);
	extern void(*glGetProgramInfoLog) (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
	extern void(*glGetShaderiv) (GLuint shader, GLenum pname, GLint *params);
	extern void(*glGetShaderInfoLog) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
	extern void(*glGetShaderSource) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
	extern GLint(*glGetUniformLocation) (GLuint program, const GLchar *name);
	extern void(*glGetUniformfv) (GLuint program, GLint location, GLfloat *params);
	extern void(*glGetUniformiv) (GLuint program, GLint location, GLint *params);
	extern void(*glGetVertexAttribdv) (GLuint index, GLenum pname, GLdouble *params);
	extern void(*glGetVertexAttribfv) (GLuint index, GLenum pname, GLfloat *params);
	extern void(*glGetVertexAttribiv) (GLuint index, GLenum pname, GLint *params);
	extern void(*glGetVertexAttribPointerv) (GLuint index, GLenum pname, void **pointer);
	extern GLboolean(*glIsProgram) (GLuint program);
	extern GLboolean(*glIsShader) (GLuint shader);
	extern void(*glLinkProgram) (GLuint program);
	extern void(*glShaderSource) (GLuint shader, GLsizei count, const GLchar** string, const GLint *length);
	extern void(*glUseProgram) (GLuint program);
	extern void(*glUniform1f) (GLint location, GLfloat v0);
	extern void(*glUniform2f) (GLint location, GLfloat v0, GLfloat v1);
	extern void(*glUniform3f) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
	extern void(*glUniform4f) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
	extern void(*glUniform1i) (GLint location, GLint v0);
	extern void(*glUniform2i) (GLint location, GLint v0, GLint v1);
	extern void(*glUniform3i) (GLint location, GLint v0, GLint v1, GLint v2);
	extern void(*glUniform4i) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
	extern void(*glUniform1fv) (GLint location, GLsizei count, const GLfloat *value);
	extern void(*glUniform2fv) (GLint location, GLsizei count, const GLfloat *value);
	extern void(*glUniform3fv) (GLint location, GLsizei count, const GLfloat *value);
	extern void(*glUniform4fv) (GLint location, GLsizei count, const GLfloat *value);
	extern void(*glUniform1iv) (GLint location, GLsizei count, const GLint *value);
	extern void(*glUniform2iv) (GLint location, GLsizei count, const GLint *value);
	extern void(*glUniform3iv) (GLint location, GLsizei count, const GLint *value);
	extern void(*glUniform4iv) (GLint location, GLsizei count, const GLint *value);
	extern void(*glUniformMatrix2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void(*glUniformMatrix3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void(*glUniformMatrix4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void(*glValidateProgram) (GLuint program);
	extern void(*glVertexAttrib1d) (GLuint index, GLdouble x);
	extern void(*glVertexAttrib1dv) (GLuint index, const GLdouble *v);
	extern void(*glVertexAttrib1f) (GLuint index, GLfloat x);
	extern void(*glVertexAttrib1fv) (GLuint index, const GLfloat *v);
	extern void(*glVertexAttrib1s) (GLuint index, GLshort x);
	extern void(*glVertexAttrib1sv) (GLuint index, const GLshort *v);
	extern void(*glVertexAttrib2d) (GLuint index, GLdouble x, GLdouble y);
	extern void(*glVertexAttrib2dv) (GLuint index, const GLdouble *v);
	extern void(*glVertexAttrib2f) (GLuint index, GLfloat x, GLfloat y);
	extern void(*glVertexAttrib2fv) (GLuint index, const GLfloat *v);
	extern void(*glVertexAttrib2s) (GLuint index, GLshort x, GLshort y);
	extern void(*glVertexAttrib2sv) (GLuint index, const GLshort *v);
	extern void(*glVertexAttrib3d) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
	extern void(*glVertexAttrib3dv) (GLuint index, const GLdouble *v);
	extern void(*glVertexAttrib3f) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
	extern void(*glVertexAttrib3fv) (GLuint index, const GLfloat *v);
	extern void(*glVertexAttrib3s) (GLuint index, GLshort x, GLshort y, GLshort z);
	extern void(*glVertexAttrib3sv) (GLuint index, const GLshort *v);
	extern void(*glVertexAttrib4Nbv) (GLuint index, const GLbyte *v);
	extern void(*glVertexAttrib4Niv) (GLuint index, const GLint *v);
	extern void(*glVertexAttrib4Nsv) (GLuint index, const GLshort *v);
	extern void(*glVertexAttrib4Nub) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
	extern void(*glVertexAttrib4Nubv) (GLuint index, const GLubyte *v);
	extern void(*glVertexAttrib4Nuiv) (GLuint index, const GLuint *v);
	extern void(*glVertexAttrib4Nusv) (GLuint index, const GLushort *v);
	extern void(*glVertexAttrib4bv) (GLuint index, const GLbyte *v);
	extern void(*glVertexAttrib4d) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	extern void(*glVertexAttrib4dv) (GLuint index, const GLdouble *v);
	extern void(*glVertexAttrib4f) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	extern void(*glVertexAttrib4fv) (GLuint index, const GLfloat *v);
	extern void(*glVertexAttrib4iv) (GLuint index, const GLint *v);
	extern void(*glVertexAttrib4s) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
	extern void(*glVertexAttrib4sv) (GLuint index, const GLshort *v);
	extern void(*glVertexAttrib4ubv) (GLuint index, const GLubyte *v);
	extern void(*glVertexAttrib4uiv) (GLuint index, const GLuint *v);
	extern void(*glVertexAttrib4usv) (GLuint index, const GLushort *v);
	extern void(*glVertexAttribPointer) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
	enum class openGL2_0 : unsigned int
	{
		BLEND_EQUATION_RGB =					0x8009,
		VERTEX_ATTRIB_ARRAY_ENABLED =			0x8622,
		VERTEX_ATTRIB_ARRAY_SIZE =				0x8623,
		VERTEX_ATTRIB_ARRAY_STRIDE =			0x8624,
		VERTEX_ATTRIB_ARRAY_TYPE =				0x8625,
		CURRENT_VERTEX_ATTRIB =					0x8626,
		VERTEX_PROGRAM_POINT_SIZE =				0x8642,
		VERTEX_ATTRIB_ARRAY_POINTER =			0x8645,
		STENCIL_BACK_FUNC =						0x8800,
		STENCIL_BACK_FAIL =						0x8801,
		STENCIL_BACK_PASS_DEPTH_FAIL =			0x8802,
		STENCIL_BACK_PASS_DEPTH_PASS =			0x8803,
		MAX_DRAW_BUFFERS =						0x8824,
		DRAW_BUFFER0 =							0x8825,
		DRAW_BUFFER1 =							0x8826,
		DRAW_BUFFER2 =							0x8827,
		DRAW_BUFFER3 =							0x8828,
		DRAW_BUFFER4 =							0x8829,
		DRAW_BUFFER5 =							0x882A,
		DRAW_BUFFER6 =							0x882B,
		DRAW_BUFFER7 =							0x882C,
		DRAW_BUFFER8 =							0x882D,
		DRAW_BUFFER9 =							0x882E,
		DRAW_BUFFER10 =							0x882F,
		DRAW_BUFFER11 =							0x8830,
		DRAW_BUFFER12 =							0x8831,
		DRAW_BUFFER13 =							0x8832,
		DRAW_BUFFER14 =							0x8833,
		DRAW_BUFFER15 =							0x8834,
		BLEND_EQUATION_ALPHA =					0x883D,
		MAX_VERTEX_ATTRIBS =					0x8869,
		VERTEX_ATTRIB_ARRAY_NORMALIZED =		0x886A,
		MAX_TEXTURE_IMAGE_UNITS =				0x8872,
		FRAGMENT_SHADER =						0x8B30,
		VERTEX_SHADER =							0x8B31,
		MAX_FRAGMENT_UNIFORM_COMPONENTS =		0x8B49,
		MAX_VERTEX_UNIFORM_COMPONENTS =			0x8B4A,
		MAX_VARYING_FLOATS =					0x8B4B,
		MAX_VERTEX_TEXTURE_IMAGE_UNITS =		0x8B4C,
		MAX_COMBINED_TEXTURE_IMAGE_UNITS =		0x8B4D,
		SHADER_TYPE =							0x8B4F,
		FLOAT_VEC2 =							0x8B50,
		FLOAT_VEC3 =							0x8B51,
		FLOAT_VEC4 =							0x8B52,
		INT_VEC2 =								0x8B53,
		INT_VEC3 =								0x8B54,
		INT_VEC4 =								0x8B55,
		BOOL =									0x8B56,
		BOOL_VEC2 =								0x8B57,
		BOOL_VEC3 =								0x8B58,
		BOOL_VEC4 =								0x8B59,
		FLOAT_MAT2 =							0x8B5A,
		FLOAT_MAT3 =							0x8B5B,
		FLOAT_MAT4 =							0x8B5C,
		SAMPLER_1D =							0x8B5D,
		SAMPLER_2D =							0x8B5E,
		SAMPLER_3D =							0x8B5F,
		SAMPLER_CUBE =							0x8B60,
		SAMPLER_1D_SHADOW =						0x8B61,
		SAMPLER_2D_SHADOW =						0x8B62,
		DELETE_STATUS =							0x8B80,
		COMPILE_STATUS =						0x8B81,
		LINK_STATUS =							0x8B82,
		VALIDATE_STATUS =						0x8B83,
		INFO_LOG_LENGTH =						0x8B84,
		ATTACHED_SHADERS =						0x8B85,
		ACTIVE_UNIFORMS =						0x8B86,
		ACTIVE_UNIFORM_MAX_LENGTH =				0x8B87,
		SHADER_SOURCE_LENGTH =					0x8B88,
		ACTIVE_ATTRIBUTES =						0x8B89,
		ACTIVE_ATTRIBUTE_MAX_LENGTH =			0x8B8A,
		FRAGMENT_SHADER_DERIVATIVE_HINT =		0x8B8B,
		SHADING_LANGUAGE_VERSION =				0x8B8C,
		CURRENT_PROGRAM =						0x8B8D,
		POINT_SPRITE_COORD_ORIGIN =				0x8CA0,
		LOWER_LEFT =							0x8CA1,
		UPPER_LEFT =							0x8CA2,
		STENCIL_BACK_REF =						0x8CA3,
		STENCIL_BACK_VALUE_MASK =				0x8CA4,
		STENCIL_BACK_WRITEMASK =				0x8CA5,
		VERTEX_PROGRAM_TWO_SIDE =				0x8643,
		POINT_SPRITE =							0x8861,
		COORD_REPLACE =							0x8862,
		MAX_TEXTURE_COORDS =					0x8871
	};

	//OpenGL 2.1 Extensions
	extern void(*glUniformMatrix2x3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void(*glUniformMatrix3x2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void(*glUniformMatrix2x4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void(*glUniformMatrix4x2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void(*glUniformMatrix3x4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void(*glUniformMatrix4x3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	enum class openGL2_1 : unsigned int
	{
		PIXEL_PACK_BUFFER =					0x88EB,
		PIXEL_UNPACK_BUFFER =				0x88EC,
		PIXEL_PACK_BUFFER_BINDING =			0x88ED,
		PIXEL_UNPACK_BUFFER_BINDING =		0x88EF,
		FLOAT_MAT2x3 =						0x8B65,
		FLOAT_MAT2x4 =						0x8B66,
		FLOAT_MAT3x2 =						0x8B67,
		FLOAT_MAT3x4 =						0x8B68,
		FLOAT_MAT4x2 =						0x8B69,
		FLOAT_MAT4x3 =						0x8B6A,
		SRGB =								0x8C40,
		SRGB8 =								0x8C41,
		SRGB_ALPHA =						0x8C42,
		SRGB8_ALPHA8 =						0x8C43,
		COMPRESSED_SRGB =					0x8C48,
		COMPRESSED_SRGB_ALPHA =				0x8C49,
		CURRENT_RASTER_SECONDARY_COLOR =	0x845F,
		SLUMINANCE_ALPHA =					0x8C44,
		SLUMINANCE8_ALPHA8 =				0x8C45,
		SLUMINANCE =						0x8C46,
		SLUMINANCE8 =						0x8C47,
		COMPRESSED_SLUMINANCE =				0x8C4A,
		COMPRESSED_SLUMINANCE_ALPHA =		0x8C4B,
	};
	
	//3.0 extensions
	typedef unsigned short GLhalf;
	extern void(*glColorMaski) (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
	extern void(*glGetBooleani_v) (GLenum target, GLuint index, GLboolean *data);
	extern void(*glGetIntegeri_v) (GLenum target, GLuint index, GLint *data);
	extern void(*glEnablei) (GLenum target, GLuint index);
	extern void(*glDisablei) (GLenum target, GLuint index);
	extern GLboolean(*glIsEnabledi) (GLenum target, GLuint index);
	extern void(*glBeginTransformFeedback) (GLenum primitiveMode);
	extern void(*glEndTransformFeedback) (void);
	extern void(*glBindBufferRange) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
	extern void(*glBindBufferBase) (GLenum target, GLuint index, GLuint buffer);
	extern void(*glTransformFeedbackVaryings) (GLuint program, GLsizei count, const GLchar** varyings, GLenum bufferMode);
	extern void(*glGetTransformFeedbackVarying) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
	extern void(*glClampColor) (GLenum target, GLenum clamp);
	extern void(*glBeginConditionalRender) (GLuint id, GLenum mode);
	extern void(*glEndConditionalRender) (void);
	extern void(*glVertexAttribIPointer) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
	extern void(*glGetVertexAttribIiv) (GLuint index, GLenum pname, GLint *params);
	extern void(*glGetVertexAttribIuiv) (GLuint index, GLenum pname, GLuint *params);
	extern void(*glVertexAttribI1i) (GLuint index, GLint x);
	extern void(*glVertexAttribI2i) (GLuint index, GLint x, GLint y);
	extern void(*glVertexAttribI3i) (GLuint index, GLint x, GLint y, GLint z);
	extern void(*glVertexAttribI4i) (GLuint index, GLint x, GLint y, GLint z, GLint w);
	extern void(*glVertexAttribI1ui) (GLuint index, GLuint x);
	extern void(*glVertexAttribI2ui) (GLuint index, GLuint x, GLuint y);
	extern void(*glVertexAttribI3ui) (GLuint index, GLuint x, GLuint y, GLuint z);
	extern void(*glVertexAttribI4ui) (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
	extern void(*glVertexAttribI1iv) (GLuint index, const GLint *v);
	extern void(*glVertexAttribI2iv) (GLuint index, const GLint *v);
	extern void(*glVertexAttribI3iv) (GLuint index, const GLint *v);
	extern void(*glVertexAttribI4iv) (GLuint index, const GLint *v);
	extern void(*glVertexAttribI1uiv) (GLuint index, const GLuint *v);
	extern void(*glVertexAttribI2uiv) (GLuint index, const GLuint *v);
	extern void(*glVertexAttribI3uiv) (GLuint index, const GLuint *v);
	extern void(*glVertexAttribI4uiv) (GLuint index, const GLuint *v);
	extern void(*glVertexAttribI4bv) (GLuint index, const GLbyte *v);
	extern void(*glVertexAttribI4sv) (GLuint index, const GLshort *v);
	extern void(*glVertexAttribI4ubv) (GLuint index, const GLubyte *v);
	extern void(*glVertexAttribI4usv) (GLuint index, const GLushort *v);
	extern void(*glGetUniformuiv) (GLuint program, GLint location, GLuint *params);
	extern void(*glBindFragDataLocation) (GLuint program, GLuint color, const GLchar *name);
	extern GLint(*glGetFragDataLocation) (GLuint program, const GLchar *name);
	extern void(*glUniform1ui) (GLint location, GLuint v0);
	extern void(*glUniform2ui) (GLint location, GLuint v0, GLuint v1);
	extern void(*glUniform3ui) (GLint location, GLuint v0, GLuint v1, GLuint v2);
	extern void(*glUniform4ui) (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
	extern void(*glUniform1uiv) (GLint location, GLsizei count, const GLuint *value);
	extern void(*glUniform2uiv) (GLint location, GLsizei count, const GLuint *value);
	extern void(*glUniform3uiv) (GLint location, GLsizei count, const GLuint *value);
	extern void(*glUniform4uiv) (GLint location, GLsizei count, const GLuint *value);
	extern void(*glTexParameterIiv) (GLenum target, GLenum pname, const GLint *params);
	extern void(*glTexParameterIuiv) (GLenum target, GLenum pname, const GLuint *params);
	extern void(*glGetTexParameterIiv) (GLenum target, GLenum pname, GLint *params);
	extern void(*glGetTexParameterIuiv) (GLenum target, GLenum pname, GLuint *params);
	extern void(*glClearBufferiv) (GLenum buffer, GLint drawbuffer, const GLint *value);
	extern void(*glClearBufferuiv) (GLenum buffer, GLint drawbuffer, const GLuint *value);
	extern void(*glClearBufferfv) (GLenum buffer, GLint drawbuffer, const GLfloat *value);
	extern void(*glClearBufferfi) (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
	extern const GLubyte* (*glGetStringi) (GLenum name, GLuint index);
	extern GLboolean(*glIsRenderbuffer) (GLuint renderbuffer);
	extern void(*glBindRenderbuffer) (GLenum target, GLuint renderbuffer);
	extern void(*glDeleteRenderbuffers) (GLsizei n, const GLuint *renderbuffers);
	extern void(*glGenRenderbuffers) (GLsizei n, GLuint *renderbuffers);
	extern void(*glRenderbufferStorage) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
	extern void(*glGetRenderbufferParameteriv) (GLenum target, GLenum pname, GLint *params);
	extern GLboolean(*glIsFramebuffer) (GLuint framebuffer);
	extern void(*glBindFramebuffer) (GLenum target, GLuint framebuffer);
	extern void(*glDeleteFramebuffers) (GLsizei n, const GLuint *framebuffers);
	extern void(*glGenFramebuffers) (GLsizei n, GLuint *framebuffers);
	extern GLenum(*glCheckFramebufferStatus) (GLenum target);
	extern void(*glFramebufferTexture1D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	extern void(*glFramebufferTexture2D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	extern void(*glFramebufferTexture3D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
	extern void(*glFramebufferRenderbuffer) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
	extern void(*glGetFramebufferAttachmentParameteriv) (GLenum target, GLenum attachment, GLenum pname, GLint *params);
	extern void(*glGenerateMipmap) (GLenum target);
	extern void(*glBlitFramebuffer) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
	extern void(*glRenderbufferStorageMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
	extern void(*glFramebufferTextureLayer) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
	extern void *(*glMapBufferRange) (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
	extern void(*glFlushMappedBufferRange) (GLenum target, GLintptr offset, GLsizeiptr length);
	extern void(*glBindVertexArray) (GLuint array);
	extern void(*glDeleteVertexArrays) (GLsizei n, const GLuint *arrays);
	extern void(*glGenVertexArrays) (GLsizei n, GLuint *arrays);
	extern GLboolean(*glIsVertexArray) (GLuint array);
	enum class openGL3_0 : unsigned int
	{
		COMPARE_REF_TO_TEXTURE =							0x884E,
		CLIP_DISTANCE0 =									0x3000,
		CLIP_DISTANCE1 =									0x3001,
		CLIP_DISTANCE2 =									0x3002,
		CLIP_DISTANCE3 =									0x3003,
		CLIP_DISTANCE4 =									0x3004,
		CLIP_DISTANCE5 =									0x3005,
		CLIP_DISTANCE6 =									0x3006,
		CLIP_DISTANCE7 =									0x3007,
		MAX_CLIP_DISTANCES =								0x0D32,
		MAJOR_VERSION =										0x821B,
		MINOR_VERSION =										0x821C,
		NUM_EXTENSIONS =									0x821D,
		CONTEXT_FLAGS =										0x821E,
		COMPRESSED_RED =									0x8225,
		COMPRESSED_RG =										0x8226,
		CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT =				0x00000001,
		RGBA32F =											0x8814,
		RGB32F =											0x8815,
		RGBA16F =											0x881A,
		RGB16F =											0x881B,
		VERTEX_ATTRIB_ARRAY_INTEGER =						0x88FD,
		MAX_ARRAY_TEXTURE_LAYERS =							0x88FF,
		MIN_PROGRAM_TEXEL_OFFSET =							0x8904,
		MAX_PROGRAM_TEXEL_OFFSET =							0x8905,
		CLAMP_READ_COLOR =									0x891C,
		FIXED_ONLY =										0x891D,
		MAX_VARYING_COMPONENTS =							0x8B4B,
		TEXTURE_1D_ARRAY =									0x8C18,
		PROXY_TEXTURE_1D_ARRAY =							0x8C19,
		TEXTURE_2D_ARRAY =									0x8C1A,
		PROXY_TEXTURE_2D_ARRAY =							0x8C1B,
		TEXTURE_BINDING_1D_ARRAY =							0x8C1C,
		TEXTURE_BINDING_2D_ARRAY =							0x8C1D,
		R11F_G11F_B10F =									0x8C3A,
		UNSIGNED_INT_10F_11F_11F_REV =						0x8C3B,
		RGB9_E5 =											0x8C3D,
		UNSIGNED_INT_5_9_9_9_REV =							0x8C3E,
		TEXTURE_SHARED_SIZE =								0x8C3F,
		TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH =				0x8C76,
		TRANSFORM_FEEDBACK_BUFFER_MODE =					0x8C7F,
		MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS =		0x8C80,
		TRANSFORM_FEEDBACK_VARYINGS =						0x8C83,
		TRANSFORM_FEEDBACK_BUFFER_START =					0x8C84,
		TRANSFORM_FEEDBACK_BUFFER_SIZE =					0x8C85,
		PRIMITIVES_GENERATED =								0x8C87,
		TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN =				0x8C88,
		RASTERIZER_DISCARD =								0x8C89,
		MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS =		0x8C8A,
		MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS =			0x8C8B,
		INTERLEAVED_ATTRIBS =								0x8C8C,
		SEPARATE_ATTRIBS =									0x8C8D,
		TRANSFORM_FEEDBACK_BUFFER =							0x8C8E,
		TRANSFORM_FEEDBACK_BUFFER_BINDING =					0x8C8F,
		RGBA32UI =											0x8D70,
		RGB32UI =											0x8D71,
		RGBA16UI =											0x8D76,
		RGB16UI =											0x8D77,
		RGBA8UI =											0x8D7C,
		RGB8UI =											0x8D7D,
		RGBA32I =											0x8D82,
		RGB32I =											0x8D83,
		RGBA16I =											0x8D88,
		RGB16I =											0x8D89,
		RGBA8I =											0x8D8E,
		RGB8I =												0x8D8F,
		RED_INTEGER =										0x8D94,
		GREEN_INTEGER =										0x8D95,
		BLUE_INTEGER =										0x8D96,
		RGB_INTEGER =										0x8D98,
		RGBA_INTEGER =										0x8D99,
		BGR_INTEGER =										0x8D9A,
		BGRA_INTEGER =										0x8D9B,
		SAMPLER_1D_ARRAY =									0x8DC0,
		SAMPLER_2D_ARRAY =									0x8DC1,
		SAMPLER_1D_ARRAY_SHADOW =							0x8DC3,
		SAMPLER_2D_ARRAY_SHADOW =							0x8DC4,
		SAMPLER_CUBE_SHADOW =								0x8DC5,
		UNSIGNED_INT_VEC2 =									0x8DC6,
		UNSIGNED_INT_VEC3 =									0x8DC7,
		UNSIGNED_INT_VEC4 =									0x8DC8,
		INT_SAMPLER_1D =									0x8DC9,
		INT_SAMPLER_2D =									0x8DCA,
		INT_SAMPLER_3D =									0x8DCB,
		INT_SAMPLER_CUBE =									0x8DCC,
		INT_SAMPLER_1D_ARRAY =								0x8DCE,
		INT_SAMPLER_2D_ARRAY =								0x8DCF,
		UNSIGNED_INT_SAMPLER_1D =							0x8DD1,
		UNSIGNED_INT_SAMPLER_2D =							0x8DD2,
		UNSIGNED_INT_SAMPLER_3D =							0x8DD3,
		UNSIGNED_INT_SAMPLER_CUBE =							0x8DD4,
		UNSIGNED_INT_SAMPLER_1D_ARRAY =						0x8DD6,
		UNSIGNED_INT_SAMPLER_2D_ARRAY =						0x8DD7,
		QUERY_WAIT =										0x8E13,
		QUERY_NO_WAIT =										0x8E14,
		QUERY_BY_REGION_WAIT =								0x8E15,
		QUERY_BY_REGION_NO_WAIT =							0x8E16,
		BUFFER_ACCESS_FLAGS =								0x911F,
		BUFFER_MAP_LENGTH =									0x9120,
		BUFFER_MAP_OFFSET =									0x9121,
		DEPTH_COMPONENT32F =								0x8CAC,
		DEPTH32F_STENCIL8 =									0x8CAD,
		FLOAT_32_UNSIGNED_INT_24_8_REV =					0x8DAD,
		INVALID_FRAMEBUFFER_OPERATION =						0x0506,
		FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING =				0x8210,
		FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE =				0x8211,
		FRAMEBUFFER_ATTACHMENT_RED_SIZE =					0x8212,
		FRAMEBUFFER_ATTACHMENT_GREEN_SIZE =					0x8213,
		FRAMEBUFFER_ATTACHMENT_BLUE_SIZE =					0x8214,
		FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE =					0x8215,
		FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE =					0x8216,
		FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE =				0x8217,
		FRAMEBUFFER_DEFAULT =								0x8218,
		FRAMEBUFFER_UNDEFINED =								0x8219,
		DEPTH_STENCIL_ATTACHMENT =							0x821A,
		MAX_RENDERBUFFER_SIZE =								0x84E8,
		DEPTH_STENCIL =										0x84F9,
		UNSIGNED_INT_24_8 =									0x84FA,
		DEPTH24_STENCIL8 =									0x88F0,
		TEXTURE_STENCIL_SIZE =								0x88F1,
		TEXTURE_RED_TYPE =									0x8C10,
		TEXTURE_GREEN_TYPE =								0x8C11,
		TEXTURE_BLUE_TYPE =									0x8C12,
		TEXTURE_ALPHA_TYPE =								0x8C13,
		TEXTURE_DEPTH_TYPE =								0x8C16,
		UNSIGNED_NORMALIZED =								0x8C17,
		FRAMEBUFFER_BINDING =								0x8CA6,
		DRAW_FRAMEBUFFER_BINDING =							0x8CA6,
		RENDERBUFFER_BINDING =								0x8CA7,
		READ_FRAMEBUFFER =									0x8CA8,
		DRAW_FRAMEBUFFER =									0x8CA9,
		READ_FRAMEBUFFER_BINDING =							0x8CAA,
		RENDERBUFFER_SAMPLES =								0x8CAB,
		FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE =				0x8CD0,
		FRAMEBUFFER_ATTACHMENT_OBJECT_NAME =				0x8CD1,
		FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL =				0x8CD2,
		FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE =		0x8CD3,
		FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER =				0x8CD4,
		FRAMEBUFFER_COMPLETE =								0x8CD5,
		FRAMEBUFFER_INCOMPLETE_ATTACHMENT =					0x8CD6,
		FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT =			0x8CD7,
		FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER =				0x8CDB,
		FRAMEBUFFER_INCOMPLETE_READ_BUFFER =				0x8CDC,
		FRAMEBUFFER_UNSUPPORTED =							0x8CDD,
		MAX_COLOR_ATTACHMENTS =								0x8CDF,
		COLOR_ATTACHMENT0 =									0x8CE0,
		COLOR_ATTACHMENT1 =									0x8CE1,
		COLOR_ATTACHMENT2 =									0x8CE2,
		COLOR_ATTACHMENT3 =									0x8CE3,
		COLOR_ATTACHMENT4 =									0x8CE4,
		COLOR_ATTACHMENT5 =									0x8CE5,
		COLOR_ATTACHMENT6 =									0x8CE6,
		COLOR_ATTACHMENT7 =									0x8CE7,
		COLOR_ATTACHMENT8 =									0x8CE8,
		COLOR_ATTACHMENT9 =									0x8CE9,
		COLOR_ATTACHMENT10 =								0x8CEA,
		COLOR_ATTACHMENT11 =								0x8CEB,
		COLOR_ATTACHMENT12 =								0x8CEC,
		COLOR_ATTACHMENT13 =								0x8CED,
		COLOR_ATTACHMENT14 =								0x8CEE,
		COLOR_ATTACHMENT15 =								0x8CEF,
		DEPTH_ATTACHMENT =									0x8D00,
		STENCIL_ATTACHMENT =								0x8D20,
		FRAMEBUFFER =										0x8D40,
		RENDERBUFFER =										0x8D41,
		RENDERBUFFER_WIDTH =								0x8D42,
		RENDERBUFFER_HEIGHT =								0x8D43,
		RENDERBUFFER_INTERNAL_FORMAT =						0x8D44,
		STENCIL_INDEX1 =									0x8D46,
		STENCIL_INDEX4 =									0x8D47,
		STENCIL_INDEX8 =									0x8D48,
		STENCIL_INDEX16 =									0x8D49,
		RENDERBUFFER_RED_SIZE =								0x8D50,
		RENDERBUFFER_GREEN_SIZE =							0x8D51,
		RENDERBUFFER_BLUE_SIZE =							0x8D52,
		RENDERBUFFER_ALPHA_SIZE =							0x8D53,
		RENDERBUFFER_DEPTH_SIZE =							0x8D54,
		RENDERBUFFER_STENCIL_SIZE =							0x8D55,
		FRAMEBUFFER_INCOMPLETE_MULTISAMPLE =				0x8D56,
		MAX_SAMPLES =										0x8D57,
		INDEX =												0x8222,
		TEXTURE_LUMINANCE_TYPE =							0x8C14,
		TEXTURE_INTENSITY_TYPE =							0x8C15,
		FRAMEBUFFER_SRGB =									0x8DB9,
		HALF_FLOAT =										0x140B,
		MAP_READ_BIT =										0x0001,
		MAP_WRITE_BIT =										0x0002,
		MAP_INVALIDATE_RANGE_BIT =							0x0004,
		MAP_INVALIDATE_BUFFER_BIT =							0x0008,
		MAP_FLUSH_EXPLICIT_BIT =							0x0010,
		MAP_UNSYNCHRONIZED_BIT =							0x0020,
		COMPRESSED_RED_RGTC1 =								0x8DBB,
		COMPRESSED_SIGNED_RED_RGTC1 =						0x8DBC,
		COMPRESSED_RG_RGTC2 =								0x8DBD,
		COMPRESSED_SIGNED_RG_RGTC2 =						0x8DBE,
		RG =												0x8227,
		RG_INTEGER =										0x8228,
		R8 =												0x8229,
		R16 =												0x822A,
		RG8 =												0x822B,
		RG16 =												0x822C,
		R16F =												0x822D,
		R32F =												0x822E,
		RG16F =												0x822F,
		RG32F =												0x8230,
		R8I =												0x8231,
		R8UI =												0x8232,
		R16I =												0x8233,
		R16UI =												0x8234,
		R32I =												0x8235,
		R32UI =												0x8236,
		RG8I =												0x8237,
		RG8UI =												0x8238,
		RG16I =												0x8239,
		RG16UI =											0x823A,
		RG32I =												0x823B,
		RG32UI =											0x823C,
		VERTEX_ARRAY_BINDING =								0x85B5,
		CLAMP_VERTEX_COLOR =								0x891A,
		CLAMP_FRAGMENT_COLOR =								0x891B,
		ALPHA_INTEGER =										0x8D97,
	};

	//OpenGL 3.1 Extensions
	extern void(*glDrawArraysInstanced) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
	extern void(*glDrawElementsInstanced) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
	extern void(*glTexBuffer) (GLenum target, GLenum internalformat, GLuint buffer);
	extern void(*glPrimitiveRestartIndex) (GLuint index);
	extern void(*glCopyBufferSubData) (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
	extern void(*glGetUniformIndices) (GLuint program, GLsizei uniformCount, const GLchar** uniformNames, GLuint *uniformIndices);
	extern void(*glGetActiveUniformsiv) (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
	extern void(*glGetActiveUniformName) (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
	extern GLuint(*glGetUniformBlockIndex) (GLuint program, const GLchar *uniformBlockName);
	extern void(*glGetActiveUniformBlockiv) (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
	extern void(*glGetActiveUniformBlockName) (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
	extern void(*glUniformBlockBinding) (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
	enum class openGL3_1 : unsigned int
	{
		SAMPLER_2D_RECT =									0x8B63,
		SAMPLER_2D_RECT_SHADOW =							0x8B64,
		SAMPLER_BUFFER =									0x8DC2,
		INT_SAMPLER_2D_RECT =								0x8DCD,
		INT_SAMPLER_BUFFER =								0x8DD0,
		UNSIGNED_INT_SAMPLER_2D_RECT =						0x8DD5,
		UNSIGNED_INT_SAMPLER_BUFFER =						0x8DD8,
		TEXTURE_BUFFER =									0x8C2A,
		MAX_TEXTURE_BUFFER_SIZE =							0x8C2B,
		TEXTURE_BINDING_BUFFER =							0x8C2C,
		TEXTURE_BUFFER_DATA_STORE_BINDING =					0x8C2D,
		TEXTURE_RECTANGLE =									0x84F5,
		TEXTURE_BINDING_RECTANGLE =							0x84F6,
		PROXY_TEXTURE_RECTANGLE =							0x84F7,
		MAX_RECTANGLE_TEXTURE_SIZE =						0x84F8,
		R8_SNORM =											0x8F94,
		RG8_SNORM =											0x8F95,
		RGB8_SNORM =										0x8F96,
		RGBA8_SNORM =										0x8F97,
		R16_SNORM =											0x8F98,
		RG16_SNORM =										0x8F99,
		RGB16_SNORM =										0x8F9A,
		RGBA16_SNORM =										0x8F9B,
		SIGNED_NORMALIZED =									0x8F9C,
		PRIMITIVE_RESTART =									0x8F9D,
		PRIMITIVE_RESTART_INDEX =							0x8F9E,
		COPY_READ_BUFFER =									0x8F36,
		COPY_WRITE_BUFFER =									0x8F37,
		UNIFORM_BUFFER =									0x8A11,
		UNIFORM_BUFFER_BINDING =							0x8A28,
		UNIFORM_BUFFER_START =								0x8A29,
		UNIFORM_BUFFER_SIZE =								0x8A2A,
		MAX_VERTEX_UNIFORM_BLOCKS =							0x8A2B,
		MAX_FRAGMENT_UNIFORM_BLOCKS =						0x8A2D,
		MAX_COMBINED_UNIFORM_BLOCKS =						0x8A2E,
		MAX_UNIFORM_BUFFER_BINDINGS =						0x8A2F,
		MAX_UNIFORM_BLOCK_SIZE =							0x8A30,
		MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS =			0x8A31,
		MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS =			0x8A33,
		UNIFORM_BUFFER_OFFSET_ALIGNMENT =					0x8A34,
		ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH =				0x8A35,
		ACTIVE_UNIFORM_BLOCKS =								0x8A36,
		UNIFORM_TYPE =										0x8A37,
		UNIFORM_SIZE =										0x8A38,
		UNIFORM_NAME_LENGTH =								0x8A39,
		UNIFORM_BLOCK_INDEX =								0x8A3A,
		UNIFORM_OFFSET =									0x8A3B,
		UNIFORM_ARRAY_STRIDE =								0x8A3C,
		UNIFORM_MATRIX_STRIDE =								0x8A3D,
		UNIFORM_IS_ROW_MAJOR =								0x8A3E,
		UNIFORM_BLOCK_BINDING =								0x8A3F,
		UNIFORM_BLOCK_DATA_SIZE =							0x8A40,
		UNIFORM_BLOCK_NAME_LENGTH =							0x8A41,
		UNIFORM_BLOCK_ACTIVE_UNIFORMS =						0x8A42,
		UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES =				0x8A43,
		UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER =			0x8A44,
		UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER =		0x8A46,
		INVALID_INDEX =										0xFFFFFFFFu
	};

	//OpenGL 3.2 Extensions
	typedef struct __GLsync* GLsync;
	typedef uint64_t GLuint64;
	typedef int64_t GLint64;
	extern void(*glDrawElementsBaseVertex) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
	extern void(*glDrawRangeElementsBaseVertex) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
	extern void(*glDrawElementsInstancedBaseVertex) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
	extern void(*glMultiDrawElementsBaseVertex) (GLenum mode, const GLsizei *count, GLenum type, const void** indices, GLsizei drawcount, const GLint *basevertex);
	extern void(*glProvokingVertex) (GLenum mode);
	extern GLsync(*glFenceSync) (GLenum condition, GLbitfield flags);
	extern GLboolean(*glIsSync) (GLsync sync);
	extern void(*glDeleteSync) (GLsync sync);
	extern GLenum(*glClientWaitSync) (GLsync sync, GLbitfield flags, GLuint64 timeout);
	extern void(*glWaitSync) (GLsync sync, GLbitfield flags, GLuint64 timeout);
	extern void(*glGetInteger64v) (GLenum pname, GLint64 *params);
	extern void(*glGetSynciv) (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
	extern void(*glGetInteger64i_v) (GLenum target, GLuint index, GLint64 *data);
	extern void(*glGetBufferParameteri64v) (GLenum target, GLenum pname, GLint64 *params);
	extern void(*glFramebufferTexture) (GLenum target, GLenum attachment, GLuint texture, GLint level);
	extern void(*glTexImage2DMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
	extern void(*glTexImage3DMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
	extern void(*glGetMultisamplefv) (GLenum pname, GLuint index, GLfloat *val);
	extern void(*glSampleMaski) (GLuint index, GLbitfield mask);
	enum class openGL3_2 : long int
	{
		CONTEXT_CORE_PROFILE_BIT =						0x00000001,
		CONTEXT_COMPATIBILITY_PROFILE_BIT =				0x00000002,
		LINES_ADJACENCY =								0x000A,
		LINE_STRIP_ADJACENCY =							0x000B,
		TRIANGLES_ADJACENCY =							0x000C,
		TRIANGLE_STRIP_ADJACENCY =						0x000D,
		PROGRAM_POINT_SIZE =							0x8642,
		MAX_GEOMETRY_TEXTURE_IMAGE_UNITS =				0x8C29,
		FRAMEBUFFER_ATTACHMENT_LAYERED =				0x8DA7,
		FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS =			0x8DA8,
		GEOMETRY_SHADER =								0x8DD9,
		GEOMETRY_VERTICES_OUT =							0x8916,
		GEOMETRY_INPUT_TYPE =							0x8917,
		GEOMETRY_OUTPUT_TYPE =							0x8918,
		MAX_GEOMETRY_UNIFORM_COMPONENTS =				0x8DDF,
		MAX_GEOMETRY_OUTPUT_VERTICES =					0x8DE0,
		MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS =			0x8DE1,
		MAX_VERTEX_OUTPUT_COMPONENTS =					0x9122,
		MAX_GEOMETRY_INPUT_COMPONENTS =					0x9123,
		MAX_GEOMETRY_OUTPUT_COMPONENTS =				0x9124,
		MAX_FRAGMENT_INPUT_COMPONENTS =					0x9125,
		CONTEXT_PROFILE_MASK =							0x9126,
		DEPTH_CLAMP =									0x864F,
		QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION =		0x8E4C,
		FIRST_VERTEX_CONVENTION =						0x8E4D,
		LAST_VERTEX_CONVENTION =						0x8E4E,
		PROVOKING_VERTEX =								0x8E4F,
		TEXTURE_CUBE_MAP_SEAMLESS =						0x884F,
		MAX_SERVER_WAIT_TIMEOUT =						0x9111,
		OBJECT_TYPE =									0x9112,
		SYNC_CONDITION =								0x9113,
		SYNC_STATUS =									0x9114,
		SYNC_FLAGS =									0x9115,
		SYNC_FENCE =									0x9116,
		SYNC_GPU_COMMANDS_COMPLETE =					0x9117,
		UNSIGNALED =									0x9118,
		SIGNALED =										0x9119,
		ALREADY_SIGNALED =								0x911A,
		TIMEOUT_EXPIRED =								0x911B,
		CONDITION_SATISFIED =							0x911C,
		TE_WAIT_FAILED =								0x911D,
		TIMEOUT_IGNORED =								0xFFFFFFFFFFFFFFFFull,
		SYNC_FLUSH_COMMANDS_BIT =						0x00000001,
		SAMPLE_POSITION =								0x8E50,
		SAMPLE_MASK =									0x8E51,
		SAMPLE_MASK_VALUE =								0x8E52,
		MAX_SAMPLE_MASK_WORDS =							0x8E59,
		TEXTURE_2D_MULTISAMPLE =						0x9100,
		PROXY_TEXTURE_2D_MULTISAMPLE =					0x9101,
		TEXTURE_2D_MULTISAMPLE_ARRAY =					0x9102,
		PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY =			0x9103,
		TEXTURE_BINDING_2D_MULTISAMPLE =				0x9104,
		TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY =			0x9105,
		TEXTURE_SAMPLES =								0x9106,
		TEXTURE_FIXED_SAMPLE_LOCATIONS =				0x9107,
		SAMPLER_2D_MULTISAMPLE =						0x9108,
		INT_SAMPLER_2D_MULTISAMPLE =					0x9109,
		UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE =			0x910A,
		SAMPLER_2D_MULTISAMPLE_ARRAY =					0x910B,
		INT_SAMPLER_2D_MULTISAMPLE_ARRAY =				0x910C,
		UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY =		0x910D,
		MAX_COLOR_TEXTURE_SAMPLES =						0x910E,
		MAX_DEPTH_TEXTURE_SAMPLES =						0x910F,
		MAX_INTEGER_SAMPLES =							0x9110,
	};

	//OpenGL 3.3 Extensions
	extern void(*glBindFragDataLocationIndexed) (GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
	extern GLint(*glGetFragDataIndex) (GLuint program, const GLchar *name);
	extern void(*glGenSamplers) (GLsizei count, GLuint *samplers);
	extern void(*glDeleteSamplers) (GLsizei count, const GLuint *samplers);
	extern GLboolean(*glIsSampler) (GLuint sampler);
	extern void(*glBindSampler) (GLuint unit, GLuint sampler);
	extern void(*glSamplerParameteri) (GLuint sampler, GLenum pname, GLint param);
	extern void(*glSamplerParameteriv) (GLuint sampler, GLenum pname, const GLint *param);
	extern void(*glSamplerParameterf) (GLuint sampler, GLenum pname, GLfloat param);
	extern void(*glSamplerParameterfv) (GLuint sampler, GLenum pname, const GLfloat *param);
	extern void(*glSamplerParameterIiv) (GLuint sampler, GLenum pname, const GLint *param);
	extern void(*glSamplerParameterIuiv) (GLuint sampler, GLenum pname, const GLuint *param);
	extern void(*glGetSamplerParameteriv) (GLuint sampler, GLenum pname, GLint *params);
	extern void(*glGetSamplerParameterIiv) (GLuint sampler, GLenum pname, GLint *params);
	extern void(*glGetSamplerParameterfv) (GLuint sampler, GLenum pname, GLfloat *params);
	extern void(*glGetSamplerParameterIuiv) (GLuint sampler, GLenum pname, GLuint *params);
	extern void(*glQueryCounter) (GLuint id, GLenum target);
	extern void(*glGetQueryObjecti64v) (GLuint id, GLenum pname, GLint64 *params);
	extern void(*glGetQueryObjectui64v) (GLuint id, GLenum pname, GLuint64 *params);
	extern void(*glVertexAttribDivisor) (GLuint index, GLuint divisor);
	extern void(*glVertexAttribP1ui) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
	extern void(*glVertexAttribP1uiv) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
	extern void(*glVertexAttribP2ui) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
	extern void(*glVertexAttribP2uiv) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
	extern void(*glVertexAttribP3ui) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
	extern void(*glVertexAttribP3uiv) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
	extern void(*glVertexAttribP4ui) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
	extern void(*glVertexAttribP4uiv) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
	extern void(*glVertexP2ui) (GLenum type, GLuint value);
	extern void(*glVertexP2uiv) (GLenum type, const GLuint *value);
	extern void(*glVertexP3ui) (GLenum type, GLuint value);
	extern void(*glVertexP3uiv) (GLenum type, const GLuint *value);
	extern void(*glVertexP4ui) (GLenum type, GLuint value);
	extern void(*glVertexP4uiv) (GLenum type, const GLuint *value);
	extern void(*glTexCoordP1ui) (GLenum type, GLuint coords);
	extern void(*glTexCoordP1uiv) (GLenum type, const GLuint *coords);
	extern void(*glTexCoordP2ui) (GLenum type, GLuint coords);
	extern void(*glTexCoordP2uiv) (GLenum type, const GLuint *coords);
	extern void(*glTexCoordP3ui) (GLenum type, GLuint coords);
	extern void(*glTexCoordP3uiv) (GLenum type, const GLuint *coords);
	extern void(*glTexCoordP4ui) (GLenum type, GLuint coords);
	extern void(*glTexCoordP4uiv) (GLenum type, const GLuint *coords);
	extern void(*glMultiTexCoordP1ui) (GLenum texture, GLenum type, GLuint coords);
	extern void(*glMultiTexCoordP1uiv) (GLenum texture, GLenum type, const GLuint *coords);
	extern void(*glMultiTexCoordP2ui) (GLenum texture, GLenum type, GLuint coords);
	extern void(*glMultiTexCoordP2uiv) (GLenum texture, GLenum type, const GLuint *coords);
	extern void(*glMultiTexCoordP3ui) (GLenum texture, GLenum type, GLuint coords);
	extern void(*glMultiTexCoordP3uiv) (GLenum texture, GLenum type, const GLuint *coords);
	extern void(*glMultiTexCoordP4ui) (GLenum texture, GLenum type, GLuint coords);
	extern void(*glMultiTexCoordP4uiv) (GLenum texture, GLenum type, const GLuint *coords);
	extern void(*glNormalP3ui) (GLenum type, GLuint coords);
	extern void(*glNormalP3uiv) (GLenum type, const GLuint *coords);
	extern void(*glColorP3ui) (GLenum type, GLuint color);
	extern void(*glColorP3uiv) (GLenum type, const GLuint *color);
	extern void(*glColorP4ui) (GLenum type, GLuint color);
	extern void(*glColorP4uiv) (GLenum type, const GLuint *color);
	extern void(*glSecondaryColorP3ui) (GLenum type, GLuint color);
	extern void(*glSecondaryColorP3uiv) (GLenum type, const GLuint *color);
	enum class openGL3_3 : unsigned int
	{
		VERTEX_ATTRIB_ARRAY_DIVISOR =		0x88FE,
		SRC1_COLOR =						0x88F9,
		ONE_MINUS_SRC1_COLOR =				0x88FA,
		ONE_MINUS_SRC1_ALPHA =				0x88FB,
		MAX_DUAL_SOURCE_DRAW_BUFFERS =		0x88FC,
		ANY_SAMPLES_PASSED =				0x8C2F,
		SAMPLER_BINDING =					0x8919,
		RGB10_A2UI =						0x906F,
		TEXTURE_SWIZZLE_R =					0x8E42,
		TEXTURE_SWIZZLE_G =					0x8E43,
		TEXTURE_SWIZZLE_B =					0x8E44,
		TEXTURE_SWIZZLE_A =					0x8E45,
		TEXTURE_SWIZZLE_RGBA =				0x8E46,
		TIME_ELAPSED =						0x88BF,
		TIMESTAMP =							0x8E28,
		INT_2_10_10_10_REV =				0x8D9F,
	};

	//OpenGL 4.0 Extensions
	extern void(*glMinSampleShading) (GLfloat value);
	extern void(*glBlendEquationi) (GLuint buf, GLenum mode);
	extern void(*glBlendEquationSeparatei) (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
	extern void(*glBlendFunci) (GLuint buf, GLenum src, GLenum dst);
	extern void(*glBlendFuncSeparatei) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
	extern void(*glDrawArraysIndirect) (GLenum mode, const void* indirect);
	extern void(*glDrawElementsIndirect) (GLenum mode, GLenum type, const void* indirect);
	extern void(*glUniform1d) (GLint location, GLdouble x);
	extern void(*glUniform2d) (GLint location, GLdouble x, GLdouble y);
	extern void(*glUniform3d) (GLint location, GLdouble x, GLdouble y, GLdouble z);
	extern void(*glUniform4d) (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	extern void(*glUniform1dv) (GLint location, GLsizei count, const GLdouble *value);
	extern void(*glUniform2dv) (GLint location, GLsizei count, const GLdouble *value);
	extern void(*glUniform3dv) (GLint location, GLsizei count, const GLdouble *value);
	extern void(*glUniform4dv) (GLint location, GLsizei count, const GLdouble *value);
	extern void(*glUniformMatrix2dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	extern void(*glUniformMatrix3dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	extern void(*glUniformMatrix4dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	extern void(*glUniformMatrix2x3dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	extern void(*glUniformMatrix2x4dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	extern void(*glUniformMatrix3x2dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	extern void(*glUniformMatrix3x4dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	extern void(*glUniformMatrix4x2dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	extern void(*glUniformMatrix4x3dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	extern void(*glGetUniformdv) (GLuint program, GLint location, GLdouble *params);
	extern GLint(*glGetSubroutineUniformLocation) (GLuint program, GLenum shadertype, const GLchar *name);
	extern GLuint(*glGetSubroutineIndex) (GLuint program, GLenum shadertype, const GLchar *name);
	extern void(*glGetActiveSubroutineUniformiv) (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
	extern void(*glGetActiveSubroutineUniformName) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
	extern void(*glGetActiveSubroutineName) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
	extern void(*glUniformSubroutinesuiv) (GLenum shadertype, GLsizei count, const GLuint *indices);
	extern void(*glGetUniformSubroutineuiv) (GLenum shadertype, GLint location, GLuint *params);
	extern void(*glGetProgramStageiv) (GLuint program, GLenum shadertype, GLenum pname, GLint *values);
	extern void(*glPatchParameteri) (GLenum pname, GLint value);
	extern void(*glPatchParameterfv) (GLenum pname, const GLfloat *values);
	extern void(*glBindTransformFeedback) (GLenum target, GLuint id);
	extern void(*glDeleteTransformFeedbacks) (GLsizei n, const GLuint *ids);
	extern void(*glGenTransformFeedbacks) (GLsizei n, GLuint *ids);
	extern GLboolean(*glIsTransformFeedback) (GLuint id);
	extern void(*glPauseTransformFeedback) (void);
	extern void(*glResumeTransformFeedback) (void);
	extern void(*glDrawTransformFeedback) (GLenum mode, GLuint id);
	extern void(*glDrawTransformFeedbackStream) (GLenum mode, GLuint id, GLuint stream);
	extern void(*glBeginQueryIndexed) (GLenum target, GLuint index, GLuint id);
	extern void(*glEndQueryIndexed) (GLenum target, GLuint index);
	extern void(*glGetQueryIndexediv) (GLenum target, GLuint index, GLenum pname, GLint *params);
	enum class openGL4_0 : unsigned int
	{
		SAMPLE_SHADING =											0x8C36,
		MIN_SAMPLE_SHADING_VALUE =									0x8C37,
		MIN_PROGRAM_TEXTURE_GATHER_OFFSET =							0x8E5E,
		MAX_PROGRAM_TEXTURE_GATHER_OFFSET =							0x8E5F,
		TEXTURE_CUBE_MAP_ARRAY =									0x9009,
		TEXTURE_BINDING_CUBE_MAP_ARRAY =							0x900A,
		PROXY_TEXTURE_CUBE_MAP_ARRAY =								0x900B,
		SAMPLER_CUBE_MAP_ARRAY =									0x900C,
		SAMPLER_CUBE_MAP_ARRAY_SHADOW =								0x900D,
		INT_SAMPLER_CUBE_MAP_ARRAY =								0x900E,
		UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY =						0x900F,
		DRAW_INDIRECT_BUFFER =										0x8F3F,
		DRAW_INDIRECT_BUFFER_BINDING =								0x8F43,
		GEOMETRY_SHADER_INVOCATIONS =								0x887F,
		MAX_GEOMETRY_SHADER_INVOCATIONS =							0x8E5A,
		MIN_FRAGMENT_INTERPOLATION_OFFSET =							0x8E5B,
		MAX_FRAGMENT_INTERPOLATION_OFFSET =							0x8E5C,
		FRAGMENT_INTERPOLATION_OFFSET_BITS =						0x8E5D,
		MAX_VERTEX_STREAMS =										0x8E71,
		DOUBLE_VEC2 =												0x8FFC,
		DOUBLE_VEC3 =												0x8FFD,
		DOUBLE_VEC4 =												0x8FFE,
		DOUBLE_MAT2 =												0x8F46,
		DOUBLE_MAT3 =												0x8F47,
		DOUBLE_MAT4 =												0x8F48,
		DOUBLE_MAT2x3 =												0x8F49,
		DOUBLE_MAT2x4 =												0x8F4A,
		DOUBLE_MAT3x2 =												0x8F4B,
		DOUBLE_MAT3x4 =												0x8F4C,
		DOUBLE_MAT4x2 =												0x8F4D,
		DOUBLE_MAT4x3 =												0x8F4E,
		ACTIVE_SUBROUTINES =										0x8DE5,
		ACTIVE_SUBROUTINE_UNIFORMS =								0x8DE6,
		ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS =						0x8E47,
		ACTIVE_SUBROUTINE_MAX_LENGTH =								0x8E48,
		ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH =						0x8E49,
		MAX_SUBROUTINES =											0x8DE7,
		MAX_SUBROUTINE_UNIFORM_LOCATIONS =							0x8DE8,
		NUM_COMPATIBLE_SUBROUTINES =								0x8E4A,
		COMPATIBLE_SUBROUTINES =									0x8E4B,
		PATCHES =													0x000E,
		PATCH_VERTICES =											0x8E72,
		PATCH_DEFAULT_INNER_LEVEL =									0x8E73,
		PATCH_DEFAULT_OUTER_LEVEL =									0x8E74,
		TESS_CONTROL_OUTPUT_VERTICES =								0x8E75,
		TESS_GEN_MODE =												0x8E76,
		TESS_GEN_SPACING =											0x8E77,
		TESS_GEN_VERTEX_ORDER =										0x8E78,
		TESS_GEN_POINT_MODE =										0x8E79,
		ISOLINES =													0x8E7A,
		FRACTIONAL_ODD =											0x8E7B,
		FRACTIONAL_EVEN =											0x8E7C,
		MAX_PATCH_VERTICES =										0x8E7D,
		MAX_TESS_GEN_LEVEL =										0x8E7E,
		MAX_TESS_CONTROL_UNIFORM_COMPONENTS =						0x8E7F,
		MAX_TESS_EVALUATION_UNIFORM_COMPONENTS =					0x8E80,
		MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS =						0x8E81,
		MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS =					0x8E82,
		MAX_TESS_CONTROL_OUTPUT_COMPONENTS =						0x8E83,
		MAX_TESS_PATCH_COMPONENTS =									0x8E84,
		MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS =					0x8E85,
		MAX_TESS_EVALUATION_OUTPUT_COMPONENTS =						0x8E86,
		MAX_TESS_CONTROL_UNIFORM_BLOCKS =							0x8E89,
		MAX_TESS_EVALUATION_UNIFORM_BLOCKS =						0x8E8A,
		MAX_TESS_CONTROL_INPUT_COMPONENTS =							0x886C,
		MAX_TESS_EVALUATION_INPUT_COMPONENTS =						0x886D,
		MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS =				0x8E1E,
		MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS =			0x8E1F,
		UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER =			0x84F0,
		UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER =		0x84F1,
		TESS_EVALUATION_SHADER =									0x8E87,
		TESS_CONTROL_SHADER =										0x8E88,
		TRANSFORM_FEEDBACK =										0x8E22,
		TRANSFORM_FEEDBACK_BUFFER_PAUSED =							0x8E23,
		TRANSFORM_FEEDBACK_BUFFER_ACTIVE =							0x8E24,
		TRANSFORM_FEEDBACK_BINDING =								0x8E25,
		MAX_TRANSFORM_FEEDBACK_BUFFERS =							0x8E70,
	};

	//OpenGL 4.1 Extensions
	extern void(*glReleaseShaderCompiler) (void);
	extern void(*glShaderBinary) (GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length);
	extern void(*glGetShaderPrecisionFormat) (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
	extern void(*glDepthRangef) (GLfloat n, GLfloat f);
	extern void(*glClearDepthf) (GLfloat d);
	extern void(*glGetProgramBinary) (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
	extern void(*glProgramBinary) (GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
	extern void(*glProgramParameteri) (GLuint program, GLenum pname, GLint value);
	extern void(*glUseProgramStages) (GLuint pipeline, GLbitfield stages, GLuint program);
	extern void(*glActiveShaderProgram) (GLuint pipeline, GLuint program);
	extern GLuint(*glCreateShaderProgramv) (GLenum type, GLsizei count, const GLchar *const*strings);
	extern void(*glBindProgramPipeline) (GLuint pipeline);
	extern void(*glDeleteProgramPipelines) (GLsizei n, const GLuint *pipelines);
	extern void(*glGenProgramPipelines) (GLsizei n, GLuint *pipelines);
	extern GLboolean(*glIsProgramPipeline) (GLuint pipeline);
	extern void(*glGetProgramPipelineiv) (GLuint pipeline, GLenum pname, GLint *params);
	extern void(*glProgramUniform1i) (GLuint program, GLint location, GLint v0);
	extern void(*glProgramUniform1iv) (GLuint program, GLint location, GLsizei count, const GLint *value);
	extern void(*glProgramUniform1f) (GLuint program, GLint location, GLfloat v0);
	extern void(*glProgramUniform1fv) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
	extern void(*glProgramUniform1d) (GLuint program, GLint location, GLdouble v0);
	extern void(*glProgramUniform1dv) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
	extern void(*glProgramUniform1ui) (GLuint program, GLint location, GLuint v0);
	extern void(*glProgramUniform1uiv) (GLuint program, GLint location, GLsizei count, const GLuint *value);
	extern void(*glProgramUniform2i) (GLuint program, GLint location, GLint v0, GLint v1);
	extern void(*glProgramUniform2iv) (GLuint program, GLint location, GLsizei count, const GLint *value);
	extern void(*glProgramUniform2f) (GLuint program, GLint location, GLfloat v0, GLfloat v1);
	extern void(*glProgramUniform2fv) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
	extern void(*glProgramUniform2d) (GLuint program, GLint location, GLdouble v0, GLdouble v1);
	extern void(*glProgramUniform2dv) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
	extern void(*glProgramUniform2ui) (GLuint program, GLint location, GLuint v0, GLuint v1);
	extern void(*glProgramUniform2uiv) (GLuint program, GLint location, GLsizei count, const GLuint *value);
	extern void(*glProgramUniform3i) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
	extern void(*glProgramUniform3iv) (GLuint program, GLint location, GLsizei count, const GLint *value);
	extern void(*glProgramUniform3f) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
	extern void(*glProgramUniform3fv) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
	extern void(*glProgramUniform3d) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
	extern void(*glProgramUniform3dv) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
	extern void(*glProgramUniform3ui) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
	extern void(*glProgramUniform3uiv) (GLuint program, GLint location, GLsizei count, const GLuint *value);
	extern void(*glProgramUniform4i) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
	extern void(*glProgramUniform4iv) (GLuint program, GLint location, GLsizei count, const GLint *value);
	extern void(*glProgramUniform4f) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
	extern void(*glProgramUniform4fv) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
	extern void(*glProgramUniform4d) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
	extern void(*glProgramUniform4dv) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
	extern void(*glProgramUniform4ui) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
	extern void(*glProgramUniform4uiv) (GLuint program, GLint location, GLsizei count, const GLuint *value);
	extern void(*glProgramUniformMatrix2fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void(*glProgramUniformMatrix3fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void(*glProgramUniformMatrix4fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void(*glProgramUniformMatrix2dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	extern void(*glProgramUniformMatrix3dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	extern void(*glProgramUniformMatrix4dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	extern void(*glProgramUniformMatrix2x3fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void(*glProgramUniformMatrix3x2fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void(*glProgramUniformMatrix2x4fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void(*glProgramUniformMatrix4x2fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void(*glProgramUniformMatrix3x4fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void(*glProgramUniformMatrix4x3fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void(*glProgramUniformMatrix2x3dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	extern void(*glProgramUniformMatrix3x2dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	extern void(*glProgramUniformMatrix2x4dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	extern void(*glProgramUniformMatrix4x2dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	extern void(*glProgramUniformMatrix3x4dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	extern void(*glProgramUniformMatrix4x3dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	extern void(*glValidateProgramPipeline) (GLuint pipeline);
	extern void(*glGetProgramPipelineInfoLog) (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
	extern void(*glVertexAttribL1d) (GLuint index, GLdouble x);
	extern void(*glVertexAttribL2d) (GLuint index, GLdouble x, GLdouble y);
	extern void(*glVertexAttribL3d) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
	extern void(*glVertexAttribL4d) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	extern void(*glVertexAttribL1dv) (GLuint index, const GLdouble *v);
	extern void(*glVertexAttribL2dv) (GLuint index, const GLdouble *v);
	extern void(*glVertexAttribL3dv) (GLuint index, const GLdouble *v);
	extern void(*glVertexAttribL4dv) (GLuint index, const GLdouble *v);
	extern void(*glVertexAttribLPointer) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
	extern void(*glGetVertexAttribLdv) (GLuint index, GLenum pname, GLdouble *params);
	extern void(*glViewportArrayv) (GLuint first, GLsizei count, const GLfloat *v);
	extern void(*glViewportIndexedf) (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
	extern void(*glViewportIndexedfv) (GLuint index, const GLfloat *v);
	extern void(*glScissorArrayv) (GLuint first, GLsizei count, const GLint *v);
	extern void(*glScissorIndexed) (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
	extern void(*glScissorIndexedv) (GLuint index, const GLint *v);
	extern void(*glDepthRangeIndexed) (GLuint first, GLsizei count, const GLdouble *v);
	extern void(*glDepthRangeArrayv) (GLuint index, GLdouble n, GLdouble f);
	extern void(*glGetFloati_v) (GLenum target, GLuint index, GLfloat *data);
	extern void(*glGetDoublei_v) (GLenum target, GLuint index, GLdouble *data);
	enum class openGL4_1 : unsigned int
	{
		FIXED =									0x140C,
		IMPLEMENTATION_COLOR_READ_TYPE =		0x8B9A,
		IMPLEMENTATION_COLOR_READ_FORMAT =		0x8B9B,
		LOW_FLOAT =								0x8DF0,
		MEDIUM_FLOAT =							0x8DF1,
		HIGH_FLOAT =							0x8DF2,
		LOW_INT =								0x8DF3,
		MEDIUM_INT =							0x8DF4,
		HIGH_INT =								0x8DF5,
		SHADER_COMPILER =						0x8DFA,
		SHADER_BINARY_FORMATS =					0x8DF8,
		NUM_SHADER_BINARY_FORMATS =				0x8DF9,
		MAX_VERTEX_UNIFORM_VECTORS =			0x8DFB,
		MAX_VARYING_VECTORS =					0x8DFC,
		MAX_FRAGMENT_UNIFORM_VECTORS =			0x8DFD,
		RGB565 =								0x8D62,
		PROGRAM_BINARY_RETRIEVABLE_HINT =		0x8257,
		PROGRAM_BINARY_LENGTH =					0x8741,
		NUM_PROGRAM_BINARY_FORMATS =			0x87FE,
		PROGRAM_BINARY_FORMATS =				0x87FF,
		VERTEX_SHADER_BIT =						0x00000001,
		FRAGMENT_SHADER_BIT =					0x00000002,
		GEOMETRY_SHADER_BIT =					0x00000004,
		TESS_CONTROL_SHADER_BIT =				0x00000008,
		TESS_EVALUATION_SHADER_BIT =			0x00000010,
		ALL_SHADER_BITS =						0xFFFFFFFF,
		PROGRAM_SEPARABLE =						0x8258,
		ACTIVE_PROGRAM =						0x8259,
		PROGRAM_PIPELINE_BINDING =				0x825A,
		MAX_VIEWPORTS =							0x825B,
		VIEWPORT_SUBPIXEL_BITS =				0x825C,
		VIEWPORT_BOUNDS_RANGE =					0x825D,
		LAYER_PROVOKING_VERTEX =				0x825E,
		VIEWPORT_INDEX_PROVOKING_VERTEX =		0x825F,
		UNDEFINED_VERTEX =						0x8260
	};

	//OpenGL 4.2 Extensions
	extern void(*glDrawArraysInstancedBaseInstance) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
	extern void(*glDrawElementsInstancedBaseInstance) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
	extern void(*glDrawElementsInstancedBaseVertexBaseInstance) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
	extern void(*glGetInternalformativ) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);
	extern void(*glGetActiveAtomicCounterBufferiv) (GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
	extern void(*glBindImageTexture) (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
	extern void(*glMemoryBarrier) (GLbitfield barriers);
	extern void(*glTexStorage1D) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
	extern void(*glTexStorage2D) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
	extern void(*glTexStorage3D) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
	extern void(*glDrawTransformFeedbackInstanced) (GLenum mode, GLuint id, GLsizei instancecount);
	extern void(*glDrawTransformFeedbackStreamInstanced) (GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
	enum class openGL4_2 : unsigned int
	{
		UNPACK_COMPRESSED_BLOCK_WIDTH =										0x9127,
		UNPACK_COMPRESSED_BLOCK_HEIGHT =									0x9128,
		UNPACK_COMPRESSED_BLOCK_DEPTH =										0x9129,
		UNPACK_COMPRESSED_BLOCK_SIZE =										0x912A,
		PACK_COMPRESSED_BLOCK_WIDTH =										0x912B,
		PACK_COMPRESSED_BLOCK_HEIGHT =										0x912C,
		PACK_COMPRESSED_BLOCK_DEPTH =										0x912D,
		PACK_COMPRESSED_BLOCK_SIZE =										0x912E,
		NUM_SAMPLE_COUNTS =													0x9380,
		MIN_MAP_BUFFER_ALIGNMENT =											0x90BC,
		ATOMIC_COUNTER_BUFFER =												0x92C0,
		ATOMIC_COUNTER_BUFFER_BINDING =										0x92C1,
		ATOMIC_COUNTER_BUFFER_START =										0x92C2,
		ATOMIC_COUNTER_BUFFER_SIZE =										0x92C3,
		ATOMIC_COUNTER_BUFFER_DATA_SIZE =									0x92C4,
		ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS =						0x92C5,
		ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES =				0x92C6,
		ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER =					0x92C7,
		ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER =			0x92C8,
		ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER =		0x92C9,
		ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER =				0x92CA,
		ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER =				0x92CB,
		MAX_VERTEX_ATOMIC_COUNTER_BUFFERS =									0x92CC,
		MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS =							0x92CD,
		MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS =						0x92CE,
		MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS =								0x92CF,
		MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS =								0x92D0,
		MAX_COMBINED_ATOMIC_COUNTER_BUFFERS =								0x92D1,
		MAX_VERTEX_ATOMIC_COUNTERS =										0x92D2,
		MAX_TESS_CONTROL_ATOMIC_COUNTERS =									0x92D3,
		MAX_TESS_EVALUATION_ATOMIC_COUNTERS =								0x92D4,
		MAX_GEOMETRY_ATOMIC_COUNTERS =										0x92D5,
		MAX_FRAGMENT_ATOMIC_COUNTERS =										0x92D6,
		MAX_COMBINED_ATOMIC_COUNTERS =										0x92D7,
		MAX_ATOMIC_COUNTER_BUFFER_SIZE =									0x92D8,
		MAX_ATOMIC_COUNTER_BUFFER_BINDINGS =								0x92DC,
		ACTIVE_ATOMIC_COUNTER_BUFFERS =										0x92D9,
		UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX =								0x92DA,
		UNSIGNED_INT_ATOMIC_COUNTER =										0x92DB,
		VERTEX_ATTRIB_ARRAY_BARRIER_BIT =									0x00000001,
		ELEMENT_ARRAY_BARRIER_BIT =											0x00000002,
		UNIFORM_BARRIER_BIT =												0x00000004,
		TEXTURE_FETCH_BARRIER_BIT =											0x00000008,
		SHADER_IMAGE_ACCESS_BARRIER_BIT =									0x00000020,
		COMMAND_BARRIER_BIT =												0x00000040,
		PIXEL_BUFFER_BARRIER_BIT =											0x00000080,
		TEXTURE_UPDATE_BARRIER_BIT =										0x00000100,
		BUFFER_UPDATE_BARRIER_BIT =											0x00000200,
		FRAMEBUFFER_BARRIER_BIT =											0x00000400,
		TRANSFORM_FEEDBACK_BARRIER_BIT =									0x00000800,
		ATOMIC_COUNTER_BARRIER_BIT =										0x00001000,
		ALL_BARRIER_BITS =													0xFFFFFFFF,
		MAX_IMAGE_UNITS =													0x8F38,
		MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS =						0x8F39,
		IMAGE_BINDING_NAME =												0x8F3A,
		IMAGE_BINDING_LEVEL =												0x8F3B,
		IMAGE_BINDING_LAYERED =												0x8F3C,
		IMAGE_BINDING_LAYER =												0x8F3D,
		IMAGE_BINDING_ACCESS =												0x8F3E,
		IMAGE_1D =															0x904C,
		IMAGE_2D =															0x904D,
		IMAGE_3D =															0x904E,
		IMAGE_2D_RECT =														0x904F,
		IMAGE_CUBE =														0x9050,
		IMAGE_BUFFER =														0x9051,
		IMAGE_1D_ARRAY =													0x9052,
		IMAGE_2D_ARRAY =													0x9053,
		IMAGE_CUBE_MAP_ARRAY =												0x9054,
		IMAGE_2D_MULTISAMPLE =												0x9055,
		IMAGE_2D_MULTISAMPLE_ARRAY =										0x9056,
		INT_IMAGE_1D =														0x9057,
		INT_IMAGE_2D =														0x9058,
		INT_IMAGE_3D =														0x9059,
		INT_IMAGE_2D_RECT =													0x905A,
		INT_IMAGE_CUBE =													0x905B,
		INT_IMAGE_BUFFER =													0x905C,
		INT_IMAGE_1D_ARRAY =												0x905D,
		INT_IMAGE_2D_ARRAY =												0x905E,
		INT_IMAGE_CUBE_MAP_ARRAY =											0x905F,
		INT_IMAGE_2D_MULTISAMPLE =											0x9060,
		INT_IMAGE_2D_MULTISAMPLE_ARRAY =									0x9061,
		UNSIGNED_INT_IMAGE_1D =												0x9062,
		UNSIGNED_INT_IMAGE_2D =												0x9063,
		UNSIGNED_INT_IMAGE_3D =												0x9064,
		UNSIGNED_INT_IMAGE_2D_RECT =										0x9065,
		UNSIGNED_INT_IMAGE_CUBE =											0x9066,
		UNSIGNED_INT_IMAGE_BUFFER =											0x9067,
		UNSIGNED_INT_IMAGE_1D_ARRAY =										0x9068,
		UNSIGNED_INT_IMAGE_2D_ARRAY =										0x9069,
		UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY =									0x906A,
		UNSIGNED_INT_IMAGE_2D_MULTISAMPLE =									0x906B,
		UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY =							0x906C,
		MAX_IMAGE_SAMPLES =													0x906D,
		IMAGE_BINDING_FORMAT =												0x906E,
		IMAGE_FORMAT_COMPATIBILITY_TYPE =									0x90C7,
		IMAGE_FORMAT_COMPATIBILITY_BY_SIZE =								0x90C8,
		IMAGE_FORMAT_COMPATIBILITY_BY_CLASS =								0x90C9,
		MAX_VERTEX_IMAGE_UNIFORMS =											0x90CA,
		MAX_TESS_CONTROL_IMAGE_UNIFORMS =									0x90CB,
		MAX_TESS_EVALUATION_IMAGE_UNIFORMS =								0x90CC,
		MAX_GEOMETRY_IMAGE_UNIFORMS =										0x90CD,
		MAX_FRAGMENT_IMAGE_UNIFORMS =										0x90CE,
		MAX_COMBINED_IMAGE_UNIFORMS =										0x90CF,
		TEXTURE_IMMUTABLE_FORMAT =											0x912F,
	};

	//OpenGL 4.3 Extensions
	typedef void (*glDebug)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);
	extern void(*glClearBufferData) (GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
	extern void(*glClearBufferSubData) (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
	extern void(*glDispatchCompute) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
	extern void(*glDispatchComputeIndirect) (GLintptr indirect);
	extern void(*glCopyImageSubData) (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
	extern void(*glFramebufferParameteri) (GLenum target, GLenum pname, GLint param);
	extern void(*glGetFramebufferParameteriv) (GLenum target, GLenum pname, GLint *params);
	extern void(*glGetInternalformati64v) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params);
	extern void(*glInvalidateTexSubImage) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
	extern void(*glInvalidateTexImage) (GLuint texture, GLint level);
	extern void(*glInvalidateBufferSubData) (GLuint buffer, GLintptr offset, GLsizeiptr length);
	extern void(*glInvalidateBufferData) (GLuint buffer);
	extern void(*glInvalidateFramebuffer) (GLenum target, GLsizei numAttachments, const GLenum *attachments);
	extern void(*glInvalidateSubFramebuffer) (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
	extern void(*glMultiDrawArraysIndirect) (GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
	extern void(*glMultiDrawElementsIndirect) (GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
	extern void(*glGetProgramInterfaceiv) (GLuint program, GLenum programInterface, GLenum pname, GLint *params);
	extern GLuint(*glGetProgramResourceIndex) (GLuint program, GLenum programInterface, const GLchar *name);
	extern void(*glGetProgramResourceName) (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
	extern void(*glGetProgramResourceiv) (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params);
	extern GLint(*glGetProgramResourceLocation) (GLuint program, GLenum programInterface, const GLchar *name);
	extern GLint(*glGetProgramResourceLocationIndex) (GLuint program, GLenum programInterface, const GLchar *name);
	extern void(*glShaderStorageBlockBinding) (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
	extern void(*glTexBufferRange) (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
	extern void(*glTexStorage2DMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
	extern void(*glTexStorage3DMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
	extern void(*glTextureView) (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
	extern void(*glBindVertexBuffer) (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
	extern void(*glVertexAttribFormat) (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
	extern void(*glVertexAttribIFormat) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
	extern void(*glVertexAttribLFormat) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
	extern void(*glVertexAttribBinding) (GLuint attribindex, GLuint bindingindex);
	extern void(*glVertexBindingDivisor) (GLuint bindingindex, GLuint divisor);
	extern void(*glDebugMessageControl) (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
	extern void(*glDebugMessageInsert) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
	extern void(*glDebugMessageCallback) (glDebug callback, const void *userParam);
	extern GLuint(*glGetDebugMessageLog) (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
	extern void(*glPushDebugGroup) (GLenum source, GLuint id, GLsizei length, const GLchar *message);
	extern void(*glPopDebugGroup) (void);
	extern void(*glObjectLabel) (GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
	extern void(*glObjectPtrLabel) (const void *ptr, GLsizei length, const GLchar *label);
	extern void(*glGetObjectLabel) (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
	extern void(*glGetObjectPtrLabel) (const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
	enum class openGL4_3 : unsigned int
	{
		NUM_SHADING_LANGUAGE_VERSIONS =								0x82E9,
		VERTEX_ATTRIB_ARRAY_LONG =									0x874E,
		COMPRESSED_RGB8_ETC2 =										0x9274,
		COMPRESSED_SRGB8_ETC2 =										0x9275,
		COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 =					0x9276,
		COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 =					0x9277,
		COMPRESSED_RGBA8_ETC2_EAC =									0x9278,
		COMPRESSED_SRGB8_ALPHA8_ETC2_EAC =							0x9279,
		COMPRESSED_R11_EAC =										0x9270,
		COMPRESSED_SIGNED_R11_EAC =									0x9271,
		COMPRESSED_RG11_EAC =										0x9272,
		COMPRESSED_SIGNED_RG11_EAC =								0x9273,
		PRIMITIVE_RESTART_FIXED_INDEX =								0x8D69,
		ANY_SAMPLES_PASSED_CONSERVATIVE =							0x8D6A,
		MAX_ELEMENT_INDEX =											0x8D6B,
		COMPUTE_SHADER =											0x91B9,
		MAX_COMPUTE_UNIFORM_BLOCKS =								0x91BB,
		MAX_COMPUTE_TEXTURE_IMAGE_UNITS =							0x91BC,
		MAX_COMPUTE_IMAGE_UNIFORMS =								0x91BD,
		MAX_COMPUTE_SHARED_MEMORY_SIZE =							0x8262,
		MAX_COMPUTE_UNIFORM_COMPONENTS =							0x8263,
		MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS =						0x8264,
		MAX_COMPUTE_ATOMIC_COUNTERS =								0x8265,
		MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS =					0x8266,
		MAX_COMPUTE_WORK_GROUP_INVOCATIONS =						0x90EB,
		MAX_COMPUTE_WORK_GROUP_COUNT =								0x91BE,
		MAX_COMPUTE_WORK_GROUP_SIZE =								0x91BF,
		COMPUTE_WORK_GROUP_SIZE =									0x8267,
		UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER =				0x90EC,
		ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER =		0x90ED,
		DISPATCH_INDIRECT_BUFFER =									0x90EE,
		DISPATCH_INDIRECT_BUFFER_BINDING =							0x90EF,
		DEBUG_OUTPUT_SYNCHRONOUS =									0x8242,
		DEBUG_NEXT_LOGGED_MESSAGE_LENGTH =							0x8243,
		DEBUG_CALLBACK_FUNCTION =									0x8244,
		DEBUG_CALLBACK_USER_PARAM =									0x8245,
		DEBUG_SOURCE_API =											0x8246,
		DEBUG_SOURCE_WINDOW_SYSTEM =								0x8247,
		DEBUG_SOURCE_SHADER_COMPILER =								0x8248,
		DEBUG_SOURCE_THIRD_PARTY =									0x8249,
		DEBUG_SOURCE_APPLICATION =									0x824A,
		DEBUG_SOURCE_OTHER =										0x824B,
		DEBUG_TYPE_ERROR =											0x824C,
		DEBUG_TYPE_DEPRECATED_BEHAVIOR =							0x824D,
		DEBUG_TYPE_UNDEFINED_BEHAVIOR =								0x824E,
		DEBUG_TYPE_PORTABILITY =									0x824F,
		DEBUG_TYPE_PERFORMANCE =									0x8250,
		DEBUG_TYPE_OTHER =											0x8251,
		MAX_DEBUG_MESSAGE_LENGTH =									0x9143,
		MAX_DEBUG_LOGGED_MESSAGES =									0x9144,
		DEBUG_LOGGED_MESSAGES =										0x9145,
		DEBUG_SEVERITY_HIGH =										0x9146,
		DEBUG_SEVERITY_MEDIUM =										0x9147,
		DEBUG_SEVERITY_LOW =										0x9148,
		DEBUG_TYPE_MARKER =											0x8268,
		DEBUG_TYPE_PUSH_GROUP =										0x8269,
		DEBUG_TYPE_POP_GROUP =										0x826A,
		DEBUG_SEVERITY_NOTIFICATION =								0x826B,
		MAX_DEBUG_GROUP_STACK_DEPTH =								0x826C,
		DEBUG_GROUP_STACK_DEPTH =									0x826D,
		BUFFER =													0x82E0,
		SHADER =													0x82E1,
		PROGRAM =													0x82E2,
		QUERY =														0x82E3,
		PROGRAM_PIPELINE =											0x82E4,
		SAMPLER =													0x82E6,
		MAX_LABEL_LENGTH =											0x82E8,
		DEBUG_OUTPUT =												0x92E0,
		CONTEXT_FLAG_DEBUG_BIT =									0x00000002,
		MAX_UNIFORM_LOCATIONS =										0x826E,
		FRAMEBUFFER_DEFAULT_WIDTH =									0x9310,
		FRAMEBUFFER_DEFAULT_HEIGHT =								0x9311,
		FRAMEBUFFER_DEFAULT_LAYERS =								0x9312,
		FRAMEBUFFER_DEFAULT_SAMPLES =								0x9313,
		FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS =				0x9314,
		MAX_FRAMEBUFFER_WIDTH =										0x9315,
		MAX_FRAMEBUFFER_HEIGHT =									0x9316,
		MAX_FRAMEBUFFER_LAYERS =									0x9317,
		MAX_FRAMEBUFFER_SAMPLES =									0x9318,
		INTERNALFORMAT_SUPPORTED =									0x826F,
		INTERNALFORMAT_PREFERRED =									0x8270,
		INTERNALFORMAT_RED_SIZE =									0x8271,
		INTERNALFORMAT_GREEN_SIZE =									0x8272,
		INTERNALFORMAT_BLUE_SIZE =									0x8273,
		INTERNALFORMAT_ALPHA_SIZE =									0x8274,
		INTERNALFORMAT_DEPTH_SIZE =									0x8275,
		INTERNALFORMAT_STENCIL_SIZE =								0x8276,
		INTERNALFORMAT_SHARED_SIZE =								0x8277,
		INTERNALFORMAT_RED_TYPE =									0x8278,
		INTERNALFORMAT_GREEN_TYPE =									0x8279,
		INTERNALFORMAT_BLUE_TYPE =									0x827A,
		INTERNALFORMAT_ALPHA_TYPE =									0x827B,
		INTERNALFORMAT_DEPTH_TYPE =									0x827C,
		INTERNALFORMAT_STENCIL_TYPE =								0x827D,
		MAX_WIDTH =													0x827E,
		MAX_HEIGHT =												0x827F,
		MAX_DEPTH =													0x8280,
		MAX_LAYERS =												0x8281,
		MAX_COMBINED_DIMENSIONS =									0x8282,
		COLOR_COMPONENTS =											0x8283,
		DEPTH_COMPONENTS =											0x8284,
		STENCIL_COMPONENTS =										0x8285,
		COLOR_RENDERABLE =											0x8286,
		DEPTH_RENDERABLE =											0x8287,
		STENCIL_RENDERABLE =										0x8288,
		FRAMEBUFFER_RENDERABLE =									0x8289,
		FRAMEBUFFER_RENDERABLE_LAYERED =							0x828A,
		FRAMEBUFFER_BLEND =											0x828B,
		READ_PIXELS =												0x828C,
		READ_PIXELS_FORMAT =										0x828D,
		READ_PIXELS_TYPE =											0x828E,
		TEXTURE_IMAGE_FORMAT =										0x828F,
		TEXTURE_IMAGE_TYPE =										0x8290,
		GET_TEXTURE_IMAGE_FORMAT =									0x8291,
		GET_TEXTURE_IMAGE_TYPE =									0x8292,
		MIPMAP =													0x8293,
		MANUAL_GENERATE_MIPMAP =									0x8294,
		AUTO_GENERATE_MIPMAP =										0x8295,
		COLOR_ENCODING =											0x8296,
		SRGB_READ =													0x8297,
		SRGB_WRITE =												0x8298,
		FILTER =													0x829A,
		VERTEX_TEXTURE =											0x829B,
		TESS_CONTROL_TEXTURE =										0x829C,
		TESS_EVALUATION_TEXTURE =									0x829D,
		GEOMETRY_TEXTURE =											0x829E,
		FRAGMENT_TEXTURE =											0x829F,
		COMPUTE_TEXTURE =											0x82A0,
		TEXTURE_SHADOW =											0x82A1,
		TEXTURE_GATHER =											0x82A2,
		TEXTURE_GATHER_SHADOW =										0x82A3,
		SHADER_IMAGE_LOAD =											0x82A4,
		SHADER_IMAGE_STORE =										0x82A5,
		SHADER_IMAGE_ATOMIC =										0x82A6,
		IMAGE_TEXEL_SIZE =											0x82A7,
		IMAGE_COMPATIBILITY_CLASS =									0x82A8,
		IMAGE_PIXEL_FORMAT =										0x82A9,
		IMAGE_PIXEL_TYPE =											0x82AA,
		SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST =						0x82AC,
		SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST =						0x82AD,
		SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE =						0x82AE,
		SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE =					0x82AF,
		TEXTURE_COMPRESSED_BLOCK_WIDTH =							0x82B1,
		TEXTURE_COMPRESSED_BLOCK_HEIGHT =							0x82B2,
		TEXTURE_COMPRESSED_BLOCK_SIZE =								0x82B3,
		CLEAR_BUFFER =												0x82B4,
		TEXTURE_VIEW =												0x82B5,
		VIEW_COMPATIBILITY_CLASS =									0x82B6,
		FULL_SUPPORT =												0x82B7,
		CAVEAT_SUPPORT =											0x82B8,
		IMAGE_CLASS_4_X_32 =										0x82B9,
		IMAGE_CLASS_2_X_32 =										0x82BA,
		IMAGE_CLASS_1_X_32 =										0x82BB,
		IMAGE_CLASS_4_X_16 =										0x82BC,
		IMAGE_CLASS_2_X_16 =										0x82BD,
		IMAGE_CLASS_1_X_16 =										0x82BE,
		IMAGE_CLASS_4_X_8 =											0x82BF,
		IMAGE_CLASS_2_X_8 =											0x82C0,
		IMAGE_CLASS_1_X_8 =											0x82C1,
		IMAGE_CLASS_11_11_10 =										0x82C2,
		IMAGE_CLASS_10_10_10_2 =									0x82C3,
		VIEW_CLASS_128_BITS =										0x82C4,
		VIEW_CLASS_96_BITS =										0x82C5,
		VIEW_CLASS_64_BITS =										0x82C6,
		VIEW_CLASS_48_BITS =										0x82C7,
		VIEW_CLASS_32_BITS =										0x82C8,
		VIEW_CLASS_24_BITS =										0x82C9,
		VIEW_CLASS_16_BITS =										0x82CA,
		VIEW_CLASS_8_BITS =											0x82CB,
		VIEW_CLASS_S3TC_DXT1_RGB =									0x82CC,
		VIEW_CLASS_S3TC_DXT1_RGBA =									0x82CD,
		VIEW_CLASS_S3TC_DXT3_RGBA =									0x82CE,
		VIEW_CLASS_S3TC_DXT5_RGBA =									0x82CF,
		VIEW_CLASS_RGTC1_RED =										0x82D0,
		VIEW_CLASS_RGTC2_RG =										0x82D1,
		VIEW_CLASS_BPTC_UNORM =										0x82D2,
		VIEW_CLASS_BPTC_FLOAT =										0x82D3,
		UNIFORM =													0x92E1,
		UNIFORM_BLOCK =												0x92E2,
		PROGRAM_INPUT =												0x92E3,
		PROGRAM_OUTPUT =											0x92E4,
		BUFFER_VARIABLE =											0x92E5,
		SHADER_STORAGE_BLOCK =										0x92E6,
		VERTEX_SUBROUTINE =											0x92E8,
		TESS_CONTROL_SUBROUTINE =									0x92E9,
		TESS_EVALUATION_SUBROUTINE =								0x92EA,
		GEOMETRY_SUBROUTINE =										0x92EB,
		FRAGMENT_SUBROUTINE =										0x92EC,
		COMPUTE_SUBROUTINE =										0x92ED,
		VERTEX_SUBROUTINE_UNIFORM =									0x92EE,
		TESS_CONTROL_SUBROUTINE_UNIFORM =							0x92EF,
		TESS_EVALUATION_SUBROUTINE_UNIFORM =						0x92F0,
		GEOMETRY_SUBROUTINE_UNIFORM =								0x92F1,
		FRAGMENT_SUBROUTINE_UNIFORM =								0x92F2,
		COMPUTE_SUBROUTINE_UNIFORM =								0x92F3,
		TRANSFORM_FEEDBACK_VARYING =								0x92F4,
		ACTIVE_RESOURCES =											0x92F5,
		MAX_NAME_LENGTH =											0x92F6,
		MAX_NUM_ACTIVE_VARIABLES =									0x92F7,
		MAX_NUM_COMPATIBLE_SUBROUTINES =							0x92F8,
		NAME_LENGTH =												0x92F9,
		TYPE =														0x92FA,
		ARRAY_SIZE =												0x92FB,
		OFFSET =													0x92FC,
		BLOCK_INDEX =												0x92FD,
		ARRAY_STRIDE =												0x92FE,
		MATRIX_STRIDE =												0x92FF,
		IS_ROW_MAJOR =												0x9300,
		ATOMIC_COUNTER_BUFFER_INDEX =								0x9301,
		BUFFER_BINDING =											0x9302,
		BUFFER_DATA_SIZE =											0x9303,
		NUM_ACTIVE_VARIABLES =										0x9304,
		ACTIVE_VARIABLES =											0x9305,
		REFERENCED_BY_VERTEX_SHADER =								0x9306,
		REFERENCED_BY_TESS_CONTROL_SHADER =							0x9307,
		REFERENCED_BY_TESS_EVALUATION_SHADER =						0x9308,
		REFERENCED_BY_GEOMETRY_SHADER =								0x9309,
		REFERENCED_BY_FRAGMENT_SHADER =								0x930A,
		REFERENCED_BY_COMPUTE_SHADER =								0x930B,
		TOP_LEVEL_ARRAY_SIZE =										0x930C,
		TOP_LEVEL_ARRAY_STRIDE =									0x930D,
		LOCATION =													0x930E,
		LOCATION_INDEX =											0x930F,
		IS_PER_PATCH =												0x92E7,
		SHADER_STORAGE_BUFFER =										0x90D2,
		SHADER_STORAGE_BUFFER_BINDING =								0x90D3,
		SHADER_STORAGE_BUFFER_START =								0x90D4,
		SHADER_STORAGE_BUFFER_SIZE =								0x90D5,
		MAX_VERTEX_SHADER_STORAGE_BLOCKS =							0x90D6,
		MAX_GEOMETRY_SHADER_STORAGE_BLOCKS =						0x90D7,
		MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS =					0x90D8,
		MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS =					0x90D9,
		MAX_FRAGMENT_SHADER_STORAGE_BLOCKS =						0x90DA,
		MAX_COMPUTE_SHADER_STORAGE_BLOCKS =							0x90DB,
		MAX_COMBINED_SHADER_STORAGE_BLOCKS =						0x90DC,
		MAX_SHADER_STORAGE_BUFFER_BINDINGS =						0x90DD,
		MAX_SHADER_STORAGE_BLOCK_SIZE =								0x90DE,
		SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT =					0x90DF,
		SHADER_STORAGE_BARRIER_BIT =								0x00002000,
		MAX_COMBINED_SHADER_OUTPUT_RESOURCES =						0x8F39,
		DEPTH_STENCIL_TEXTURE_MODE =								0x90EA,
		TEXTURE_BUFFER_OFFSET =										0x919D,
		TEXTURE_BUFFER_SIZE =										0x919E,
		TEXTURE_BUFFER_OFFSET_ALIGNMENT =							0x919F,
		TEXTURE_VIEW_MIN_LEVEL =									0x82DB,
		TEXTURE_VIEW_NUM_LEVELS =									0x82DC,
		TEXTURE_VIEW_MIN_LAYER =									0x82DD,
		TEXTURE_VIEW_NUM_LAYERS =									0x82DE,
		TEXTURE_IMMUTABLE_LEVELS =									0x82DF,
		VERTEX_ATTRIB_BINDING =										0x82D4,
		VERTEX_ATTRIB_RELATIVE_OFFSET =								0x82D5,
		VERTEX_BINDING_DIVISOR =									0x82D6,
		VERTEX_BINDING_OFFSET =										0x82D7,
		VERTEX_BINDING_STRIDE =										0x82D8,
		MAX_VERTEX_ATTRIB_RELATIVE_OFFSET =							0x82D9,
		MAX_VERTEX_ATTRIB_BINDINGS =								0x82DA,
		DISPLAY_LIST =												0x82E7,
	};

	//OpenGL 4.4 Extensions
	extern void(*glBufferStorage) (GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
	extern void(*glClearTexImage) (GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
	extern void(*glClearTexSubImage) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
	extern void(*glBindBuffersBase) (GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
	extern void(*glBindBuffersRange) (GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
	extern void(*glBindTextures) (GLuint first, GLsizei count, const GLuint *textures);
	extern void(*glBindSamplers) (GLuint first, GLsizei count, const GLuint *samplers);
	extern void(*glBindImageTextures) (GLuint first, GLsizei count, const GLuint *textures);
	extern void(*glBindVertexBuffers) (GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
	enum class openGL4_4 : unsigned int
	{
		MAX_VERTEX_ATTRIB_STRIDE =						0x82E5,
		PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED =		0x8221,
		TEXTURE_BUFFER_BINDING =						0x8C2A,
		MAP_PERSISTENT_BIT =							0x0040,
		MAP_COHERENT_BIT =								0x0080,
		DYNAMIC_STORAGE_BIT =							0x0100,
		CLIENT_STORAGE_BIT =							0x0200,
		CLIENT_MAPPED_BUFFER_BARRIER_BIT = 				0x00004000,
		BUFFER_IMMUTABLE_STORAGE =						0x821F,
		BUFFER_STORAGE_FLAGS =							0x8220,
		CLEAR_TEXTURE =									0x9365,
		LOCATION_COMPONENT =							0x934A,
		TRANSFORM_FEEDBACK_BUFFER_INDEX =				0x934B,
		TRANSFORM_FEEDBACK_BUFFER_STRIDE =				0x934C,
		QUERY_BUFFER =									0x9192,
		QUERY_BUFFER_BARRIER_BIT =						0x00008000,
		QUERY_BUFFER_BINDING =							0x9193,
		QUERY_RESULT_NO_WAIT =							0x9194,
		MIRROR_CLAMP_TO_EDGE =							0x8743
	};
	
	enum glVersion_t
	{
		version1_2 =		1L << 1,
		version1_3 =		1L << 2,
		version1_4 =		1L << 3,
		version1_5 =		1L << 4,
		version2_0 =		1L << 5,
		version2_1 =		1L << 6,
		version3_0 =		1L << 7,
		version3_1 =		1L << 8,
		version3_2 =		1L << 9,
		version3_3 =		1L << 10,
		version4_0 =		1L << 11,
		version4_1 =		1L << 12,
		version4_2 =		1L << 13,
		version4_3 =		1L << 14,
		version4_4 =		1L << 15,
	};

	enum class error_t
	{
		success,
		loadFailed,
		versionLoadFailed,
		Unsupported1_2,
		Unsupported1_3,
		Unsupported1_4,
		Unsupported1_5,
		Unsupported2_0,
		Unsupported2_1,
		Unsupported3_0,
		Unsupported3_1,
		Unsupported3_2,
		Unsupported3_3,
		Unsupported4_0,
		Unsupported4_1,
		Unsupported4_2,
		Unsupported4_3,
		Unsupported4_4,
	};

	class errorCategory_t : public std::error_category
	{
	public:

		const char* name() const throw() override
		{
			return "TinyExtender";
		}

		/** 
		*	return the error message associated with the given error number
		*/
		virtual std::string message(int errorValue) const override
		{
			error_t err = (error_t)errorValue;
			switch (err)
			{
				case error_t::loadFailed:
				{
					return "Error: extension has failed to load";
				}

				case error_t::versionLoadFailed:
				{
					return "Error: Could not get OpenGL version";
				}

				case error_t::Unsupported1_2:
				{
					return "Error: OpenGL 1.2 extensions unsupported. stopping loading here";
				}

				case error_t::Unsupported1_3:
				{
					return "Error: OpenGL 1.3 extensions unsupported. stopping loading here";
				}

				case error_t::Unsupported1_4:
				{
					return "Error: OpenGL 1.4 extensions unsupported. stopping loading here";
				}

				case error_t::Unsupported1_5:
				{
					return "Error: OpenGL 1.5 extensions unsupported. stopping loading here";
				}

				case error_t::Unsupported2_0:
				{
					return "Error: OpenGL 2.0 extensions unsupported. stopping loading here";
				}

				case error_t::Unsupported2_1:
				{
					return "Error: OpenGL 2.1 extensions unsupported. stopping loading here";
				}

				case error_t::Unsupported3_0:
				{
					return "Error: OpenGL 3.0 extensions unsupported. stopping loading here";
				}

				case error_t::Unsupported3_1:
				{
					return "Error: OpenGL 3.1 extensions unsupported. stopping loading here";
				}

				case error_t::Unsupported3_2:
				{
					return "Error: OpenGL 3.2 extensions unsupported. stopping loading here";
				}

				case error_t::Unsupported3_3:
				{
					return "Error: OpenGL 3.3 extensions unsupported. stopping loading here";
				}

				case error_t::Unsupported4_0:
				{
					return "Error: OpenGL 4.0 extensions unsupported. stopping loading here";
				}

				case error_t::Unsupported4_1:
				{
					return "Error: OpenGL 4.1 extensions unsupported. stopping loading here";
				}

				case error_t::Unsupported4_2:
				{
					return "Error: OpenGL 4.2 extensions unsupported. stopping loading here";
				}

				case error_t::Unsupported4_3:
				{
					return "Error: OpenGL 4.3 extensions unsupported. stopping loading here";
				}

				case error_t::Unsupported4_4:
				{
					return "Error: OpenGL 4.4 extensions unsupported. stopping loading here";
				}

				default:
				{
					return "Error: unspecified error \n";
				}
			}
		}

		errorCategory_t() {};

		const static errorCategory_t& get()
		{
			const static errorCategory_t category;
			return category;
		}
	};

	std::error_code make_error_code(error_t errorCode);
};

namespace std
{
	template<> struct is_error_code_enum<TinyExtender::error_t> : std::true_type {};
};

namespace TinyExtender
{

	extern GLuint glVersionMajor;
	extern GLuint glVersionMinor;

	template<typename T>
	void FetchProcAddress(T& funcPointer, const char* procName)
	{
#if defined(TE_WINDOWS)
		funcPointer = (T)wglGetProcAddress(procName);
#elif defined(TE_LINUX)
		funcPointer = (T)glXGetProcAddress(procName);
#endif
	}

	std::error_code InitializeGLVersion(void);

	void Load1_2Extensions(void);

	void Load1_3Extensions(void);

	void Load1_4Extensions(void);

	void Load1_5Extensions(void);

	void Load2_0Extensions(void);

	void Load2_1Extensions(void);

	void Load3_0Extensions(void);

	void Load3_1Extensions(void);

	void Load3_2Extensions(void);

	void Load3_3Extensions(void);

	void Load4_0Extensions(void);

	void Load4_1Extensions(void);

	void Load4_2Extensions(void);

	void Load4_3Extensions(void);

	void Load4_4Extensions(void);

	std::error_code InitializeExtentions(void);

	std::error_code InitializeExtensionsSpecific(unsigned int OpenGLVersions);

	bool IsExtensionSupported(const char* extensionName);

}
#endif
