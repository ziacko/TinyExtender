#ifndef TINYEXTENDER_H_
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
	enum openGL1_2
	{
		TE_UNSIGNED_BYTE_3_3_2 =				0x8032,
		TE_UNSIGNED_SHORT_4_4_4_4 =				0x8033,
		TE_UNSIGNED_SHORT_5_5_5_1 =				0x8034,
		TE_UNSIGNED_INT_8_8_8_8 =				0x8035,
		TE_UNSIGNED_INT_10_10_10_2 =			0x8036,
		TE_TEXTURE_BINDING_3D =					0x806A,
		TE_PACK_SKIP_IMAGES =					0x806B,
		TE_PACK_IMAGE_HEIGHT =					0x806C,
		TE_UNPACK_SKIP_IMAGES =					0x806D,
		TE_UNPACK_IMAGE_HEIGHT =				0x806E,
		TE_TEXTURE_3D =							0x806F,
		TE_PROXY_TEXTURE_3D =					0x8070,
		TE_TEXTURE_DEPTH =						0x8071,
		TE_TEXTURE_WRAP_R =						0x8072,
		TE_MAX_3D_TEXTURE_SIZE =				0x8073,
		TE_UNSIGNED_BYTE_2_3_3_REV =			0x8362,
		TE_UNSIGNED_SHORT_5_6_5 =				0x8363,
		TE_UNSIGNED_SHORT_5_6_5_REV =			0x8364,
		TE_UNSIGNED_SHORT_4_4_4_4_REV =			0x8365,
		TE_UNSIGNED_SHORT_1_5_5_5_REV =			0x8366,
		TE_UNSIGNED_INT_8_8_8_8_REV =			0x8367,
		TE_UNSIGNED_INT_2_10_10_10_REV =		0x8368,
		TE_BGR =								0x80E0,
		TE_BGRA =								0x80E1,
		TE_MAX_ELEMENTS_VERTICES =				0x80E8,
		TE_MAX_ELEMENTS_INDICES =				0x80E9,
		TE_CLAMP_TO_EDGE =						0x812F,
		TE_TEXTURE_MIN_LOD =					0x813A,
		TE_TEXTURE_MAX_LOD =					0x813B,
		TE_TEXTURE_BASE_LEVEL =					0x813C,
		TE_TEXTURE_MAX_LEVEL =					0x813D,
		TE_SMOOTH_POINT_SIZE_RANGE =			0x0B12,
		TE_SMOOTH_POINT_SIZE_GRANULARITY =		0x0B13,
		TE_SMOOTH_LINE_WIDTH_RANGE =			0x0B22,
		TE_SMOOTH_LINE_WIDTH_GRANULARITY =		0x0B23,
		TE_ALIASED_LINE_WIDTH_RANGE =			0x846E,
		TE_RESCALE_NORMAL =						0x803A,
		TE_LIGHT_MODEL_COLOR_CONTROL =			0x81F8,
		TE_SINGLE_COLOR =						0x81F9,
		TE_SEPARATE_SPECULAR_COLOR =			0x81FA,
		TE_ALIASED_POINT_SIZE_RANGE =			0x846D
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
	enum openGL1_3
	{
		TE_TEXTURE0 =								0x84C0,
		TE_TEXTURE1 =								0x84C1,
		TE_TEXTURE2 =								0x84C2,
		TE_TEXTURE3 =								0x84C3,
		TE_TEXTURE4 =								0x84C4,
		TE_TEXTURE5 =								0x84C5,
		TE_TEXTURE6 =								0x84C6,
		TE_TEXTURE7 =								0x84C7,
		TE_TEXTURE8 =								0x84C8,
		TE_TEXTURE9 =								0x84C9,
		TE_TEXTURE10 =								0x84CA,
		TE_TEXTURE11 =								0x84CB,
		TE_TEXTURE12 =								0x84CC,
		TE_TEXTURE13 =								0x84CD,
		TE_TEXTURE14 =								0x84CE,
		TE_TEXTURE15 =								0x84CF,
		TE_TEXTURE16 =								0x84D0,
		TE_TEXTURE17 =								0x84D1,
		TE_TEXTURE18 =								0x84D2,
		TE_TEXTURE19 =								0x84D3,
		TE_TEXTURE20 =								0x84D4,
		TE_TEXTURE21 =								0x84D5,
		TE_TEXTURE22 =								0x84D6,
		TE_TEXTURE23 =								0x84D7,
		TE_TEXTURE24 =								0x84D8,
		TE_TEXTURE25 =								0x84D9,
		TE_TEXTURE26 =								0x84DA,
		TE_TEXTURE27 =								0x84DB,
		TE_TEXTURE28 =								0x84DC,
		TE_TEXTURE29 =								0x84DD,
		TE_TEXTURE30 =								0x84DE,
		TE_TEXTURE31 =								0x84DF,
		TE_ACTIVE_TEXTURE =							0x84E0,
		TE_MULTISAMPLE =							0x809D,
		TE_SAMPLE_ALPHA_TO_COVERAGE =				0x809E,
		TE_SAMPLE_ALPHA_TO_ONE =					0x809F,
		TE_SAMPLE_COVERAGE =						0x80A0,
		TE_SAMPLE_BUFFERS =							0x80A8,
		TE_SAMPLES =								0x80A9,
		TE_SAMPLE_COVERAGE_VALUE =					0x80AA,
		TE_SAMPLE_COVERAGE_INVERT =					0x80AB,
		TE_TEXTURE_CUBE_MAP =						0x8513,
		TE_TEXTURE_BINDING_CUBE_MAP =				0x8514,
		TE_TEXTURE_CUBE_MAP_POSITIVE_X =			0x8515,
		TE_TEXTURE_CUBE_MAP_NEGATIVE_X =			0x8516,
		TE_TEXTURE_CUBE_MAP_POSITIVE_Y =			0x8517,
		TE_TEXTURE_CUBE_MAP_NEGATIVE_Y =			0x8518,
		TE_TEXTURE_CUBE_MAP_POSITIVE_Z =			0x8519,
		TE_TEXTURE_CUBE_MAP_NEGATIVE_Z =			0x851A,
		TE_PROXY_TEXTURE_CUBE_MAP =					0x851B,
		TE_MAX_CUBE_MAP_TEXTURE_SIZE =				0x851C,
		TE_COMPRESSED_RGB =							0x84ED,
		TE_COMPRESSED_RGBA =						0x84EE,
		TE_TEXTURE_COMPRESSION_HINT =				0x84EF,
		TE_TEXTURE_COMPRESSED_IMAGE_SIZE =			0x86A0,
		TE_TEXTURE_COMPRESSED =						0x86A1,
		TE_NUM_COMPRESSED_TEXTURE_FORMATS =			0x86A2,
		TE_COMPRESSED_TEXTURE_FORMATS =				0x86A3,
		TE_CLAMP_TO_BORDER =						0x812D,
		TE_CLIENT_ACTIVE_TEXTURE =					0x84E1,
		TE_MAX_TEXTURE_UNITS =						0x84E2,
		TE_TRANSPOSE_MODELVIEW_MATRIX =				0x84E3,
		TE_TRANSPOSE_PROJECTION_MATRIX =			0x84E4,
		TE_TRANSPOSE_TEXTURE_MATRIX =				0x84E5,
		TE_TRANSPOSE_COLOR_MATRIX =					0x84E6,
		TE_MULTISAMPLE_BIT =						0x20000000,
		TE_NORMAL_MAP =								0x8511,
		TE_REFLECTION_MAP =							0x8512,
		TE_COMPRESSED_ALPHA =						0x84E9,
		TE_COMPRESSED_LUMINANCE =					0x84EA,
		TE_COMPRESSED_LUMINANCE_ALPHA =				0x84EB,
		TE_COMPRESSED_INTENSITY =					0x84EC,
		TE_COMBINE =								0x8570,
		TE_COMBINE_RGB =							0x8571,
		TE_COMBINE_ALPHA =							0x8572,
		TE_SOURCE0_RGB =							0x8580,
		TE_SOURCE1_RGB =							0x8581,
		TE_SOURCE2_RGB =							0x8582,
		TE_SOURCE0_ALPHA =							0x8588,
		TE_SOURCE1_ALPHA =							0x8589,
		TE_SOURCE2_ALPHA =							0x858A,
		TE_OPERAND0_RGB =							0x8590,
		TE_OPERAND1_RGB =							0x8591,
		TE_OPERAND2_RGB =							0x8592,
		TE_OPERAND0_ALPHA =							0x8598,
		TE_OPERAND1_ALPHA =							0x8599,
		TE_OPERAND2_ALPHA =							0x859A,
		TE_RGB_SCALE =								0x8573,
		TE_ADD_SIGNED =								0x8574,
		TE_INTERPOLATE =							0x8575,
		TE_SUBTRACT =								0x84E7,
		TE_CONSTANT =								0x8576,
		TE_PRIMARY_COLOR =							0x8577,
		TE_PREVIOUS =								0x8578,
		TE_DOT3_RGB =								0x86AE,
		TE_DOT3_RGBA =								0x86AF,
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
	enum openGL1_4
	{
		TE_BLEND_DST_RGB =						0x80C8,
		TE_BLEND_SRC_RGB =						0x80C9,
		TE_BLEND_DST_ALPHA =					0x80CA,
		TE_BLEND_SRC_ALPHA =					0x80CB,
		TE_POINT_FADE_THRESHOLD_SIZE =			0x8128,
		TE_DEPTH_COMPONENT16 =					0x81A5,
		TE_DEPTH_COMPONENT24 =					0x81A6,
		TE_DEPTH_COMPONENT32 =					0x81A7,
		TE_MIRRORED_REPEAT =					0x8370,
		TE_MAX_TEXTURE_LOD_BIAS =				0x84FD,
		TE_TEXTURE_LOD_BIAS =					0x8501,
		TE_INCR_WRAP =							0x8507,
		TE_DECR_WRAP =							0x8508,
		TE_TEXTURE_DEPTH_SIZE =					0x884A,
		TE_TEXTURE_COMPARE_MODE =				0x884C,
		TE_TEXTURE_COMPARE_FUNC =				0x884D,
		TE_POINT_SIZE_MIN =						0x8126,
		TE_POINT_SIZE_MAX =						0x8127,
		TE_POINT_DISTANCE_ATTENUATION =			0x8129,
		TE_GENERATE_MIPMAP =					0x8191,
		TE_GENERATE_MIPMAP_HINT =				0x8192,
		TE_FOG_COORDINATE_SOURCE =				0x8450,
		TE_FOG_COORDINATE =						0x8451,
		TE_FRAGMENT_DEPTH =						0x8452,
		TE_CURRENT_FOG_COORDINATE =				0x8453,
		TE_FOG_COORDINATE_ARRAY_TYPE =			0x8454,
		TE_FOG_COORDINATE_ARRAY_STRIDE =		0x8455,
		TE_FOG_COORDINATE_ARRAY_POINTER =		0x8456,
		TE_FOG_COORDINATE_ARRAY =				0x8457,
		TE_COLOR_SUM =							0x8458,
		TE_CURRENT_SECONDARY_COLOR =			0x8459,
		TE_SECONDARY_COLOR_ARRAY_SIZE =			0x845A,
		TE_SECONDARY_COLOR_ARRAY_TYPE =			0x845B,
		TE_SECONDARY_COLOR_ARRAY_STRIDE =		0x845C,
		TE_SECONDARY_COLOR_ARRAY_POINTER =		0x845D,
		TE_SECONDARY_COLOR_ARRAY =				0x845E,
		TE_TEXTURE_FILTER_CONTROL =				0x8500,
		TE_DEPTH_TEXTURE_MODE =					0x884B,
		TE_COMPARE_R_TO_TEXTURE =				0x884E,
		TE_FUNC_ADD =							0x8006,
		TE_FUNC_SUBTRACT =						0x800A,
		TE_FUNC_REVERSE_SUBTRACT =				0x800B,
		TE_MIN =								0x8007,
		TE_MAX =								0x8008,
		TE_CONSTANT_COLOR =						0x8001,
		TE_ONE_MINUS_CONSTANT_COLOR =			0x8002,
		TE_CONSTANT_ALPHA =						0x8003,
		TE_ONE_MINUS_CONSTANT_ALPHA =			0x8004
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
	enum openGL1_5
	{
		TE_BUFFER_SIZE =								0x8764,
		TE_BUFFER_USAGE =								0x8765,
		TE_QUERY_COUNTER_BITS =							0x8864,
		TE_CURRENT_QUERY =								0x8865,
		TE_QUERY_RESULT =								0x8866,
		TE_QUERY_RESULT_AVAILABLE =						0x8867,
		TE_ARRAY_BUFFER =								0x8892,
		TE_ELEMENT_ARRAY_BUFFER =						0x8893,
		TE_ARRAY_BUFFER_BINDING =						0x8894,
		TE_ELEMENT_ARRAY_BUFFER_BINDING =				0x8895,
		TE_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING =			0x889F,
		TE_READ_ONLY =									0x88B8,
		TE_WRITE_ONLY =									0x88B9,
		TE_READ_WRITE =									0x88BA,
		TE_BUFFER_ACCESS =								0x88BB,
		TE_BUFFER_MAPPED =								0x88BC,
		TE_BUFFER_MAP_POINTER =							0x88BD,
		TE_STREAM_DRAW =								0x88E0,
		TE_STREAM_READ =								0x88E1,
		TE_STREAM_COPY =								0x88E2,
		TE_STATIC_DRAW =								0x88E4,
		TE_STATIC_READ =								0x88E5,
		TE_STATIC_COPY =								0x88E6,
		TE_DYNAMIC_DRAW =								0x88E8,
		TE_DYNAMIC_READ =								0x88E9,
		TE_DYNAMIC_COPY =								0x88EA,
		TE_SAMPLES_PASSED =								0x8914,
		TE_SRC1_ALPHA =									0x8589,
		TE_VERTEX_ARRAY_BUFFER_BINDING =				0x8896,
		TE_NORMAL_ARRAY_BUFFER_BINDING =				0x8897,
		TE_COLOR_ARRAY_BUFFER_BINDING =					0x8898,
		TE_INDEX_ARRAY_BUFFER_BINDING =					0x8899,
		TE_TEXTURE_COORD_ARRAY_BUFFER_BINDING =			0x889A,
		TE_EDGE_FLAG_ARRAY_BUFFER_BINDING =				0x889B,
		TE_SECONDARY_COLOR_ARRAY_BUFFER_BINDING =		0x889C,
		TE_FOG_COORDINATE_ARRAY_BUFFER_BINDING =		0x889D,
		TE_WEIGHT_ARRAY_BUFFER_BINDING =				0x889E,
		TE_FOG_COORD_SRC =								0x8450,
		TE_FOG_COORD =									0x8451,
		TE_CURRENT_FOG_COORD =							0x8453,
		TE_FOG_COORD_ARRAY_TYPE =						0x8454,
		TE_FOG_COORD_ARRAY_STRIDE =						0x8455,
		TE_FOG_COORD_ARRAY_POINTER =					0x8456,
		TE_FOG_COORD_ARRAY =							0x8457,
		TE_FOG_COORD_ARRAY_BUFFER_BINDING =				0x889D,
		TE_SRC0_RGB =									0x8580,
		TE_SRC1_RGB =									0x8581,
		TE_SRC2_RGB =									0x8582,
		TE_SRC0_ALPHA =									0x8588,
		TE_SRC2_ALPHA =									0x858A,
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
	enum openGL2_0
	{
		TE_BLEND_EQUATION_RGB =						0x8009,
		TE_VERTEX_ATTRIB_ARRAY_ENABLED =			0x8622,
		TE_VERTEX_ATTRIB_ARRAY_SIZE =				0x8623,
		TE_VERTEX_ATTRIB_ARRAY_STRIDE =				0x8624,
		TE_VERTEX_ATTRIB_ARRAY_TYPE =				0x8625,
		TE_CURRENT_VERTEX_ATTRIB =					0x8626,
		TE_VERTEX_PROGRAM_POINT_SIZE =				0x8642,
		TE_VERTEX_ATTRIB_ARRAY_POINTER =			0x8645,
		TE_STENCIL_BACK_FUNC =						0x8800,
		TE_STENCIL_BACK_FAIL =						0x8801,
		TE_STENCIL_BACK_PASS_DEPTH_FAIL =			0x8802,
		TE_STENCIL_BACK_PASS_DEPTH_PASS =			0x8803,
		TE_MAX_DRAW_BUFFERS =						0x8824,
		TE_DRAW_BUFFER0 =							0x8825,
		TE_DRAW_BUFFER1 =							0x8826,
		TE_DRAW_BUFFER2 =							0x8827,
		TE_DRAW_BUFFER3 =							0x8828,
		TE_DRAW_BUFFER4 =							0x8829,
		TE_DRAW_BUFFER5 =							0x882A,
		TE_DRAW_BUFFER6 =							0x882B,
		TE_DRAW_BUFFER7 =							0x882C,
		TE_DRAW_BUFFER8 =							0x882D,
		TE_DRAW_BUFFER9 =							0x882E,
		TE_DRAW_BUFFER10 =							0x882F,
		TE_DRAW_BUFFER11 =							0x8830,
		TE_DRAW_BUFFER12 =							0x8831,
		TE_DRAW_BUFFER13 =							0x8832,
		TE_DRAW_BUFFER14 =							0x8833,
		TE_DRAW_BUFFER15 =							0x8834,
		TE_BLEND_EQUATION_ALPHA =					0x883D,
		TE_MAX_VERTEX_ATTRIBS =						0x8869,
		TE_VERTEX_ATTRIB_ARRAY_NORMALIZED =			0x886A,
		TE_MAX_TEXTURE_IMAGE_UNITS =				0x8872,
		TE_FRAGMENT_SHADER =						0x8B30,
		TE_VERTEX_SHADER =							0x8B31,
		TE_MAX_FRAGMENT_UNIFORM_COMPONENTS =		0x8B49,
		TE_MAX_VERTEX_UNIFORM_COMPONENTS =			0x8B4A,
		TE_MAX_VARYING_FLOATS =						0x8B4B,
		TE_MAX_VERTEX_TEXTURE_IMAGE_UNITS =			0x8B4C,
		TE_MAX_COMBINED_TEXTURE_IMAGE_UNITS =		0x8B4D,
		TE_SHADER_TYPE =							0x8B4F,
		TE_FLOAT_VEC2 =								0x8B50,
		TE_FLOAT_VEC3 =								0x8B51,
		TE_FLOAT_VEC4 =								0x8B52,
		TE_INT_VEC2 =								0x8B53,
		TE_INT_VEC3 =								0x8B54,
		TE_INT_VEC4 =								0x8B55,
		TE_BOOL =									0x8B56,
		TE_BOOL_VEC2 =								0x8B57,
		TE_BOOL_VEC3 =								0x8B58,
		TE_BOOL_VEC4 =								0x8B59,
		TE_FLOAT_MAT2 =								0x8B5A,
		TE_FLOAT_MAT3 =								0x8B5B,
		TE_FLOAT_MAT4 =								0x8B5C,
		TE_SAMPLER_1D =								0x8B5D,
		TE_SAMPLER_2D =								0x8B5E,
		TE_SAMPLER_3D =								0x8B5F,
		TE_SAMPLER_CUBE =							0x8B60,
		TE_SAMPLER_1D_SHADOW =						0x8B61,
		TE_SAMPLER_2D_SHADOW =						0x8B62,
		TE_DELETE_STATUS =							0x8B80,
		TE_COMPILE_STATUS =							0x8B81,
		TE_LINK_STATUS =							0x8B82,
		TE_VALIDATE_STATUS =						0x8B83,
		TE_INFO_LOG_LENGTH =						0x8B84,
		TE_ATTACHED_SHADERS =						0x8B85,
		TE_ACTIVE_UNIFORMS =						0x8B86,
		TE_ACTIVE_UNIFORM_MAX_LENGTH =				0x8B87,
		TE_SHADER_SOURCE_LENGTH =					0x8B88,
		TE_ACTIVE_ATTRIBUTES =						0x8B89,
		TE_ACTIVE_ATTRIBUTE_MAX_LENGTH =			0x8B8A,
		TE_FRAGMENT_SHADER_DERIVATIVE_HINT =		0x8B8B,
		TE_SHADING_LANGUAGE_VERSION =				0x8B8C,
		TE_CURRENT_PROGRAM =						0x8B8D,
		TE_POINT_SPRITE_COORD_ORIGIN =				0x8CA0,
		TE_LOWER_LEFT =								0x8CA1,
		TE_UPPER_LEFT =								0x8CA2,
		TE_STENCIL_BACK_REF =						0x8CA3,
		TE_STENCIL_BACK_VALUE_MASK =				0x8CA4,
		TE_STENCIL_BACK_WRITEMASK =					0x8CA5,
		TE_VERTEX_PROGRAM_TWO_SIDE =				0x8643,
		TE_POINT_SPRITE =							0x8861,
		TE_COORD_REPLACE =							0x8862,
		TE_MAX_TEXTURE_COORDS =						0x8871
	};

	//OpenGL 2.1 Extensions
	extern void(*glUniformMatrix2x3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void(*glUniformMatrix3x2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void(*glUniformMatrix2x4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void(*glUniformMatrix4x2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void(*glUniformMatrix3x4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void(*glUniformMatrix4x3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	enum openGL2_1
	{
		TE_PIXEL_PACK_BUFFER =					0x88EB,
		TE_PIXEL_UNPACK_BUFFER =				0x88EC,
		TE_PIXEL_PACK_BUFFER_BINDING =			0x88ED,
		TE_PIXEL_UNPACK_BUFFER_BINDING =		0x88EF,
		TE_FLOAT_MAT2x3 =						0x8B65,
		TE_FLOAT_MAT2x4 =						0x8B66,
		TE_FLOAT_MAT3x2 =						0x8B67,
		TE_FLOAT_MAT3x4 =						0x8B68,
		TE_FLOAT_MAT4x2 =						0x8B69,
		TE_FLOAT_MAT4x3 =						0x8B6A,
		TE_SRGB =								0x8C40,
		TE_SRGB8 =								0x8C41,
		TE_SRGB_ALPHA =							0x8C42,
		TE_SRGB8_ALPHA8 =						0x8C43,
		TE_COMPRESSED_SRGB =					0x8C48,
		TE_COMPRESSED_SRGB_ALPHA =				0x8C49,
		TE_CURRENT_RASTER_SECONDARY_COLOR =		0x845F,
		TE_SLUMINANCE_ALPHA =					0x8C44,
		TE_SLUMINANCE8_ALPHA8 =					0x8C45,
		TE_SLUMINANCE =							0x8C46,
		TE_SLUMINANCE8 =						0x8C47,
		TE_COMPRESSED_SLUMINANCE =				0x8C4A,
		TE_COMPRESSED_SLUMINANCE_ALPHA =		0x8C4B,
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
	enum openGL3_0
	{
		TE_COMPARE_REF_TO_TEXTURE =								0x884E,
		TE_CLIP_DISTANCE0 =										0x3000,
		TE_CLIP_DISTANCE1 =										0x3001,
		TE_CLIP_DISTANCE2 =										0x3002,
		TE_CLIP_DISTANCE3 =										0x3003,
		TE_CLIP_DISTANCE4 =										0x3004,
		TE_CLIP_DISTANCE5 =										0x3005,
		TE_CLIP_DISTANCE6 =										0x3006,
		TE_CLIP_DISTANCE7 =										0x3007,
		TE_MAX_CLIP_DISTANCES =									0x0D32,
		TE_MAJOR_VERSION =										0x821B,
		TE_MINOR_VERSION =										0x821C,
		TE_NUM_EXTENSIONS =										0x821D,
		TE_CONTEXT_FLAGS =										0x821E,
		TE_COMPRESSED_RED =										0x8225,
		TE_COMPRESSED_RG =										0x8226,
		TE_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT =				0x00000001,
		TE_RGBA32F =											0x8814,
		TE_RGB32F =												0x8815,
		TE_RGBA16F =											0x881A,
		TE_RGB16F =												0x881B,
		TE_VERTEX_ATTRIB_ARRAY_INTEGER =						0x88FD,
		TE_MAX_ARRAY_TEXTURE_LAYERS =							0x88FF,
		TE_MIN_PROGRAM_TEXEL_OFFSET =							0x8904,
		TE_MAX_PROGRAM_TEXEL_OFFSET =							0x8905,
		TE_CLAMP_READ_COLOR =									0x891C,
		TE_FIXED_ONLY =											0x891D,
		TE_MAX_VARYING_COMPONENTS =								0x8B4B,
		TE_TEXTURE_1D_ARRAY =									0x8C18,
		TE_PROXY_TEXTURE_1D_ARRAY =								0x8C19,
		TE_TEXTURE_2D_ARRAY =									0x8C1A,
		TE_PROXY_TEXTURE_2D_ARRAY =								0x8C1B,
		TE_TEXTURE_BINDING_1D_ARRAY =							0x8C1C,
		TE_TEXTURE_BINDING_2D_ARRAY =							0x8C1D,
		TE_R11F_G11F_B10F =										0x8C3A,
		TE_UNSIGNED_INT_10F_11F_11F_REV =						0x8C3B,
		TE_RGB9_E5 =											0x8C3D,
		TE_UNSIGNED_INT_5_9_9_9_REV =							0x8C3E,
		TE_TEXTURE_SHARED_SIZE =								0x8C3F,
		TE_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH =				0x8C76,
		TE_TRANSFORM_FEEDBACK_BUFFER_MODE =						0x8C7F,
		TE_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS =			0x8C80,
		TE_TRANSFORM_FEEDBACK_VARYINGS =						0x8C83,
		TE_TRANSFORM_FEEDBACK_BUFFER_START =					0x8C84,
		TE_TRANSFORM_FEEDBACK_BUFFER_SIZE =						0x8C85,
		TE_PRIMITIVES_GENERATED =								0x8C87,
		TE_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN =				0x8C88,
		TE_RASTERIZER_DISCARD =									0x8C89,
		TE_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS =		0x8C8A,
		TE_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS =			0x8C8B,
		TE_INTERLEAVED_ATTRIBS =								0x8C8C,
		TE_SEPARATE_ATTRIBS =									0x8C8D,
		TE_TRANSFORM_FEEDBACK_BUFFER =							0x8C8E,
		TE_TRANSFORM_FEEDBACK_BUFFER_BINDING =					0x8C8F,
		TE_RGBA32UI =											0x8D70,
		TE_RGB32UI =											0x8D71,
		TE_RGBA16UI =											0x8D76,
		TE_RGB16UI =											0x8D77,
		TE_RGBA8UI =											0x8D7C,
		TE_RGB8UI =												0x8D7D,
		TE_RGBA32I =											0x8D82,
		TE_RGB32I =												0x8D83,
		TE_RGBA16I =											0x8D88,
		TE_RGB16I =												0x8D89,
		TE_RGBA8I =												0x8D8E,
		TE_RGB8I =												0x8D8F,
		TE_RED_INTEGER =										0x8D94,
		TE_GREEN_INTEGER =										0x8D95,
		TE_BLUE_INTEGER =										0x8D96,
		TE_RGB_INTEGER =										0x8D98,
		TE_RGBA_INTEGER =										0x8D99,
		TE_BGR_INTEGER =										0x8D9A,
		TE_BGRA_INTEGER =										0x8D9B,
		TE_SAMPLER_1D_ARRAY =									0x8DC0,
		TE_SAMPLER_2D_ARRAY =									0x8DC1,
		TE_SAMPLER_1D_ARRAY_SHADOW =							0x8DC3,
		TE_SAMPLER_2D_ARRAY_SHADOW =							0x8DC4,
		TE_SAMPLER_CUBE_SHADOW =								0x8DC5,
		TE_UNSIGNED_INT_VEC2 =									0x8DC6,
		TE_UNSIGNED_INT_VEC3 =									0x8DC7,
		TE_UNSIGNED_INT_VEC4 =									0x8DC8,
		TE_INT_SAMPLER_1D =										0x8DC9,
		TE_INT_SAMPLER_2D =										0x8DCA,
		TE_INT_SAMPLER_3D =										0x8DCB,
		TE_INT_SAMPLER_CUBE =									0x8DCC,
		TE_INT_SAMPLER_1D_ARRAY =								0x8DCE,
		TE_INT_SAMPLER_2D_ARRAY =								0x8DCF,
		TE_UNSIGNED_INT_SAMPLER_1D =							0x8DD1,
		TE_UNSIGNED_INT_SAMPLER_2D =							0x8DD2,
		TE_UNSIGNED_INT_SAMPLER_3D =							0x8DD3,
		TE_UNSIGNED_INT_SAMPLER_CUBE =							0x8DD4,
		TE_UNSIGNED_INT_SAMPLER_1D_ARRAY =						0x8DD6,
		TE_UNSIGNED_INT_SAMPLER_2D_ARRAY =						0x8DD7,
		TE_QUERY_WAIT =											0x8E13,
		TE_QUERY_NO_WAIT =										0x8E14,
		TE_QUERY_BY_REGION_WAIT =								0x8E15,
		TE_QUERY_BY_REGION_NO_WAIT =							0x8E16,
		TE_BUFFER_ACCESS_FLAGS =								0x911F,
		TE_BUFFER_MAP_LENGTH =									0x9120,
		TE_BUFFER_MAP_OFFSET =									0x9121,
		TE_DEPTH_COMPONENT32F =									0x8CAC,
		TE_DEPTH32F_STENCIL8 =									0x8CAD,
		TE_FLOAT_32_UNSIGNED_INT_24_8_REV =						0x8DAD,
		TE_INVALID_FRAMEBUFFER_OPERATION =						0x0506,
		TE_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING =				0x8210,
		TE_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE =				0x8211,
		TE_FRAMEBUFFER_ATTACHMENT_RED_SIZE =					0x8212,
		TE_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE =					0x8213,
		TE_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE =					0x8214,
		TE_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE =					0x8215,
		TE_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE =					0x8216,
		TE_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE =				0x8217,
		TE_FRAMEBUFFER_DEFAULT =								0x8218,
		TE_FRAMEBUFFER_UNDEFINED =								0x8219,
		TE_DEPTH_STENCIL_ATTACHMENT =							0x821A,
		TE_MAX_RENDERBUFFER_SIZE =								0x84E8,
		TE_DEPTH_STENCIL =										0x84F9,
		TE_UNSIGNED_INT_24_8 =									0x84FA,
		TE_DEPTH24_STENCIL8 =									0x88F0,
		TE_TEXTURE_STENCIL_SIZE =								0x88F1,
		TE_TEXTURE_RED_TYPE =									0x8C10,
		TE_TEXTURE_GREEN_TYPE =									0x8C11,
		TE_TEXTURE_BLUE_TYPE =									0x8C12,
		TE_TEXTURE_ALPHA_TYPE =									0x8C13,
		TE_TEXTURE_DEPTH_TYPE =									0x8C16,
		TE_UNSIGNED_NORMALIZED =								0x8C17,
		TE_FRAMEBUFFER_BINDING =								0x8CA6,
		TE_DRAW_FRAMEBUFFER_BINDING =							0x8CA6,
		TE_RENDERBUFFER_BINDING =								0x8CA7,
		TE_READ_FRAMEBUFFER =									0x8CA8,
		TE_DRAW_FRAMEBUFFER =									0x8CA9,
		TE_READ_FRAMEBUFFER_BINDING =							0x8CAA,
		TE_RENDERBUFFER_SAMPLES =								0x8CAB,
		TE_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE =					0x8CD0,
		TE_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME =					0x8CD1,
		TE_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL =				0x8CD2,
		TE_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE =		0x8CD3,
		TE_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER =				0x8CD4,
		TE_FRAMEBUFFER_COMPLETE =								0x8CD5,
		TE_FRAMEBUFFER_INCOMPLETE_ATTACHMENT =					0x8CD6,
		TE_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT =			0x8CD7,
		TE_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER =					0x8CDB,
		TE_FRAMEBUFFER_INCOMPLETE_READ_BUFFER =					0x8CDC,
		TE_FRAMEBUFFER_UNSUPPORTED =							0x8CDD,
		TE_MAX_COLOR_ATTACHMENTS =								0x8CDF,
		TE_COLOR_ATTACHMENT0 =									0x8CE0,
		TE_COLOR_ATTACHMENT1 =									0x8CE1,
		TE_COLOR_ATTACHMENT2 =									0x8CE2,
		TE_COLOR_ATTACHMENT3 =									0x8CE3,
		TE_COLOR_ATTACHMENT4 =									0x8CE4,
		TE_COLOR_ATTACHMENT5 =									0x8CE5,
		TE_COLOR_ATTACHMENT6 =									0x8CE6,
		TE_COLOR_ATTACHMENT7 =									0x8CE7,
		TE_COLOR_ATTACHMENT8 =									0x8CE8,
		TE_COLOR_ATTACHMENT9 =									0x8CE9,
		TE_COLOR_ATTACHMENT10 =									0x8CEA,
		TE_COLOR_ATTACHMENT11 =									0x8CEB,
		TE_COLOR_ATTACHMENT12 =									0x8CEC,
		TE_COLOR_ATTACHMENT13 =									0x8CED,
		TE_COLOR_ATTACHMENT14 =									0x8CEE,
		TE_COLOR_ATTACHMENT15 =									0x8CEF,
		TE_DEPTH_ATTACHMENT =									0x8D00,
		TE_STENCIL_ATTACHMENT =									0x8D20,
		TE_FRAMEBUFFER =										0x8D40,
		TE_RENDERBUFFER =										0x8D41,
		TE_RENDERBUFFER_WIDTH =									0x8D42,
		TE_RENDERBUFFER_HEIGHT =								0x8D43,
		TE_RENDERBUFFER_INTERNAL_FORMAT =						0x8D44,
		TE_STENCIL_INDEX1 =										0x8D46,
		TE_STENCIL_INDEX4 =										0x8D47,
		TE_STENCIL_INDEX8 =										0x8D48,
		TE_STENCIL_INDEX16 =									0x8D49,
		TE_RENDERBUFFER_RED_SIZE =								0x8D50,
		TE_RENDERBUFFER_GREEN_SIZE =							0x8D51,
		TE_RENDERBUFFER_BLUE_SIZE =								0x8D52,
		TE_RENDERBUFFER_ALPHA_SIZE =							0x8D53,
		TE_RENDERBUFFER_DEPTH_SIZE =							0x8D54,
		TE_RENDERBUFFER_STENCIL_SIZE =							0x8D55,
		TE_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE =					0x8D56,
		TE_MAX_SAMPLES =										0x8D57,
		TE_INDEX =												0x8222,
		TE_TEXTURE_LUMINANCE_TYPE =								0x8C14,
		TE_TEXTURE_INTENSITY_TYPE =								0x8C15,
		TE_FRAMEBUFFER_SRGB =									0x8DB9,
		TE_HALF_FLOAT =											0x140B,
		TE_MAP_READ_BIT =										0x0001,
		TE_MAP_WRITE_BIT =										0x0002,
		TE_MAP_INVALIDATE_RANGE_BIT =							0x0004,
		TE_MAP_INVALIDATE_BUFFER_BIT =							0x0008,
		TE_MAP_FLUSH_EXPLICIT_BIT =								0x0010,
		TE_MAP_UNSYNCHRONIZED_BIT =								0x0020,
		TE_COMPRESSED_RED_RGTC1 =								0x8DBB,
		TE_COMPRESSED_SIGNED_RED_RGTC1 =						0x8DBC,
		TE_COMPRESSED_RG_RGTC2 =								0x8DBD,
		TE_COMPRESSED_SIGNED_RG_RGTC2 =							0x8DBE,
		TE_RG =													0x8227,
		TE_RG_INTEGER =											0x8228,
		TE_R8 =													0x8229,
		TE_R16 =												0x822A,
		TE_RG8 =												0x822B,
		TE_RG16 =												0x822C,
		TE_R16F =												0x822D,
		TE_R32F =												0x822E,
		TE_RG16F =												0x822F,
		TE_RG32F =												0x8230,
		TE_R8I =												0x8231,
		TE_R8UI =												0x8232,
		TE_R16I =												0x8233,
		TE_R16UI =												0x8234,
		TE_R32I =												0x8235,
		TE_R32UI =												0x8236,
		TE_RG8I =												0x8237,
		TE_RG8UI =												0x8238,
		TE_RG16I =												0x8239,
		TE_RG16UI =												0x823A,
		TE_RG32I =												0x823B,
		TE_RG32UI =												0x823C,
		TE_VERTEX_ARRAY_BINDING =								0x85B5,
		TE_CLAMP_VERTEX_COLOR =									0x891A,
		TE_CLAMP_FRAGMENT_COLOR =								0x891B,
		TE_ALPHA_INTEGER =										0x8D97,
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
	enum openGL3_1
	{
		TE_SAMPLER_2D_RECT =									0x8B63,
		TE_SAMPLER_2D_RECT_SHADOW =								0x8B64,
		TE_SAMPLER_BUFFER =										0x8DC2,
		TE_INT_SAMPLER_2D_RECT =								0x8DCD,
		TE_INT_SAMPLER_BUFFER =									0x8DD0,
		TE_UNSIGNED_INT_SAMPLER_2D_RECT =						0x8DD5,
		TE_UNSIGNED_INT_SAMPLER_BUFFER =						0x8DD8,
		TE_TEXTURE_BUFFER =										0x8C2A,
		TE_MAX_TEXTURE_BUFFER_SIZE =							0x8C2B,
		TE_TEXTURE_BINDING_BUFFER =								0x8C2C,
		TE_TEXTURE_BUFFER_DATA_STORE_BINDING =					0x8C2D,
		TE_TEXTURE_RECTANGLE =									0x84F5,
		TE_TEXTURE_BINDING_RECTANGLE =							0x84F6,
		TE_PROXY_TEXTURE_RECTANGLE =							0x84F7,
		TE_MAX_RECTANGLE_TEXTURE_SIZE =							0x84F8,
		TE_R8_SNORM =											0x8F94,
		TE_RG8_SNORM =											0x8F95,
		TE_RGB8_SNORM =											0x8F96,
		TE_RGBA8_SNORM =										0x8F97,
		TE_R16_SNORM =											0x8F98,
		TE_RG16_SNORM =											0x8F99,
		TE_RGB16_SNORM =										0x8F9A,
		TE_RGBA16_SNORM =										0x8F9B,
		TE_SIGNED_NORMALIZED =									0x8F9C,
		TE_PRIMITIVE_RESTART =									0x8F9D,
		TE_PRIMITIVE_RESTART_INDEX =							0x8F9E,
		TE_COPY_READ_BUFFER =									0x8F36,
		TE_COPY_WRITE_BUFFER =									0x8F37,
		TE_UNIFORM_BUFFER =										0x8A11,
		TE_UNIFORM_BUFFER_BINDING =								0x8A28,
		TE_UNIFORM_BUFFER_START =								0x8A29,
		TE_UNIFORM_BUFFER_SIZE =								0x8A2A,
		TE_MAX_VERTEX_UNIFORM_BLOCKS =							0x8A2B,
		TE_MAX_FRAGMENT_UNIFORM_BLOCKS =						0x8A2D,
		TE_MAX_COMBINED_UNIFORM_BLOCKS =						0x8A2E,
		TE_MAX_UNIFORM_BUFFER_BINDINGS =						0x8A2F,
		TE_MAX_UNIFORM_BLOCK_SIZE =								0x8A30,
		TE_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS =				0x8A31,
		TE_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS =			0x8A33,
		TE_UNIFORM_BUFFER_OFFSET_ALIGNMENT =					0x8A34,
		TE_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH =				0x8A35,
		TE_ACTIVE_UNIFORM_BLOCKS =								0x8A36,
		TE_UNIFORM_TYPE =										0x8A37,
		TE_UNIFORM_SIZE =										0x8A38,
		TE_UNIFORM_NAME_LENGTH =								0x8A39,
		TE_UNIFORM_BLOCK_INDEX =								0x8A3A,
		TE_UNIFORM_OFFSET =										0x8A3B,
		TE_UNIFORM_ARRAY_STRIDE =								0x8A3C,
		TE_UNIFORM_MATRIX_STRIDE =								0x8A3D,
		TE_UNIFORM_IS_ROW_MAJOR =								0x8A3E,
		TE_UNIFORM_BLOCK_BINDING =								0x8A3F,
		TE_UNIFORM_BLOCK_DATA_SIZE =							0x8A40,
		TE_UNIFORM_BLOCK_NAME_LENGTH =							0x8A41,
		TE_UNIFORM_BLOCK_ACTIVE_UNIFORMS =						0x8A42,
		TE_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES =				0x8A43,
		TE_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER =			0x8A44,
		TE_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER =		0x8A46,
		TE_INVALID_INDEX =										0xFFFFFFFFu
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
	enum openGL3_2
	{
		TE_CONTEXT_CORE_PROFILE_BIT =						0x00000001,
		TE_CONTEXT_COMPATIBILITY_PROFILE_BIT =				0x00000002,
		TE_LINES_ADJACENCY =								0x000A,
		TE_LINE_STRIP_ADJACENCY =							0x000B,
		TE_TRIANGLES_ADJACENCY =							0x000C,
		TE_TRIANGLE_STRIP_ADJACENCY =						0x000D,
		TE_PROGRAM_POINT_SIZE =								0x8642,
		TE_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS =				0x8C29,
		TE_FRAMEBUFFER_ATTACHMENT_LAYERED =					0x8DA7,
		TE_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS =			0x8DA8,
		TE_GEOMETRY_SHADER =								0x8DD9,
		TE_GEOMETRY_VERTICES_OUT =							0x8916,
		TE_GEOMETRY_INPUT_TYPE =							0x8917,
		TE_GEOMETRY_OUTPUT_TYPE =							0x8918,
		TE_MAX_GEOMETRY_UNIFORM_COMPONENTS =				0x8DDF,
		TE_MAX_GEOMETRY_OUTPUT_VERTICES =					0x8DE0,
		TE_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS =			0x8DE1,
		TE_MAX_VERTEX_OUTPUT_COMPONENTS =					0x9122,
		TE_MAX_GEOMETRY_INPUT_COMPONENTS =					0x9123,
		TE_MAX_GEOMETRY_OUTPUT_COMPONENTS =					0x9124,
		TE_MAX_FRAGMENT_INPUT_COMPONENTS =					0x9125,
		TE_CONTEXT_PROFILE_MASK =							0x9126,
		TE_DEPTH_CLAMP =									0x864F,
		TE_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION =		0x8E4C,
		TE_FIRST_VERTEX_CONVENTION =						0x8E4D,
		TE_LAST_VERTEX_CONVENTION =							0x8E4E,
		TE_PROVOKING_VERTEX =								0x8E4F,
		TE_TEXTURE_CUBE_MAP_SEAMLESS =						0x884F,
		TE_MAX_SERVER_WAIT_TIMEOUT =						0x9111,
		TE_OBJECT_TYPE =									0x9112,
		TE_SYNC_CONDITION =									0x9113,
		TE_SYNC_STATUS =									0x9114,
		TE_SYNC_FLAGS =										0x9115,
		TE_SYNC_FENCE =										0x9116,
		TE_SYNC_GPU_COMMANDS_COMPLETE =						0x9117,
		TE_UNSIGNALED =										0x9118,
		TE_SIGNALED =										0x9119,
		TE_ALREADY_SIGNALED =								0x911A,
		TE_TIMEOUT_EXPIRED =								0x911B,
		TE_CONDITION_SATISFIED =							0x911C,
		TE_WAIT_FAILED =									0x911D,
		TE_TIMEOUT_IGNORED =								0xFFFFFFFFFFFFFFFFull,
		TE_SYNC_FLUSH_COMMANDS_BIT =						0x00000001,
		TE_SAMPLE_POSITION =								0x8E50,
		TE_SAMPLE_MASK =									0x8E51,
		TE_SAMPLE_MASK_VALUE =								0x8E52,
		TE_MAX_SAMPLE_MASK_WORDS =							0x8E59,
		TE_TEXTURE_2D_MULTISAMPLE =							0x9100,
		TE_PROXY_TEXTURE_2D_MULTISAMPLE =					0x9101,
		TE_TEXTURE_2D_MULTISAMPLE_ARRAY =					0x9102,
		TE_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY =				0x9103,
		TE_TEXTURE_BINDING_2D_MULTISAMPLE =					0x9104,
		TE_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY =			0x9105,
		TE_TEXTURE_SAMPLES =								0x9106,
		TE_TEXTURE_FIXED_SAMPLE_LOCATIONS =					0x9107,
		TE_SAMPLER_2D_MULTISAMPLE =							0x9108,
		TE_INT_SAMPLER_2D_MULTISAMPLE =						0x9109,
		TE_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE =			0x910A,
		TE_SAMPLER_2D_MULTISAMPLE_ARRAY =					0x910B,
		TE_INT_SAMPLER_2D_MULTISAMPLE_ARRAY =				0x910C,
		TE_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY =		0x910D,
		TE_MAX_COLOR_TEXTURE_SAMPLES =						0x910E,
		TE_MAX_DEPTH_TEXTURE_SAMPLES =						0x910F,
		TE_MAX_INTEGER_SAMPLES =							0x9110,
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
	enum openGL3_3
	{
		TE_VERTEX_ATTRIB_ARRAY_DIVISOR =		0x88FE,
		TE_SRC1_COLOR =							0x88F9,
		TE_ONE_MINUS_SRC1_COLOR =				0x88FA,
		TE_ONE_MINUS_SRC1_ALPHA =				0x88FB,
		TE_MAX_DUAL_SOURCE_DRAW_BUFFERS =		0x88FC,
		TE_ANY_SAMPLES_PASSED =					0x8C2F,
		TE_SAMPLER_BINDING =					0x8919,
		TE_RGB10_A2UI =							0x906F,
		TE_TEXTURE_SWIZZLE_R =					0x8E42,
		TE_TEXTURE_SWIZZLE_G =					0x8E43,
		TE_TEXTURE_SWIZZLE_B =					0x8E44,
		TE_TEXTURE_SWIZZLE_A =					0x8E45,
		TE_TEXTURE_SWIZZLE_RGBA =				0x8E46,
		TE_TIME_ELAPSED =						0x88BF,
		TE_TIMESTAMP =							0x8E28,
		TE_INT_2_10_10_10_REV =					0x8D9F,
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
	enum openGL4_0
	{
		TE_SAMPLE_SHADING =												0x8C36,
		TE_MIN_SAMPLE_SHADING_VALUE =									0x8C37,
		TE_MIN_PROGRAM_TEXTURE_GATHER_OFFSET =							0x8E5E,
		TE_MAX_PROGRAM_TEXTURE_GATHER_OFFSET =							0x8E5F,
		TE_TEXTURE_CUBE_MAP_ARRAY =										0x9009,
		TE_TEXTURE_BINDING_CUBE_MAP_ARRAY =								0x900A,
		TE_PROXY_TEXTURE_CUBE_MAP_ARRAY =								0x900B,
		TE_SAMPLER_CUBE_MAP_ARRAY =										0x900C,
		TE_SAMPLER_CUBE_MAP_ARRAY_SHADOW =								0x900D,
		TE_INT_SAMPLER_CUBE_MAP_ARRAY =									0x900E,
		TE_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY =						0x900F,
		TE_DRAW_INDIRECT_BUFFER =										0x8F3F,
		TE_DRAW_INDIRECT_BUFFER_BINDING =								0x8F43,
		TE_GEOMETRY_SHADER_INVOCATIONS =								0x887F,
		TE_MAX_GEOMETRY_SHADER_INVOCATIONS =							0x8E5A,
		TE_MIN_FRAGMENT_INTERPOLATION_OFFSET =							0x8E5B,
		TE_MAX_FRAGMENT_INTERPOLATION_OFFSET =							0x8E5C,
		TE_FRAGMENT_INTERPOLATION_OFFSET_BITS =							0x8E5D,
		TE_MAX_VERTEX_STREAMS =											0x8E71,
		TE_DOUBLE_VEC2 =												0x8FFC,
		TE_DOUBLE_VEC3 =												0x8FFD,
		TE_DOUBLE_VEC4 =												0x8FFE,
		TE_DOUBLE_MAT2 =												0x8F46,
		TE_DOUBLE_MAT3 =												0x8F47,
		TE_DOUBLE_MAT4 =												0x8F48,
		TE_DOUBLE_MAT2x3 =												0x8F49,
		TE_DOUBLE_MAT2x4 =												0x8F4A,
		TE_DOUBLE_MAT3x2 =												0x8F4B,
		TE_DOUBLE_MAT3x4 =												0x8F4C,
		TE_DOUBLE_MAT4x2 =												0x8F4D,
		TE_DOUBLE_MAT4x3 =												0x8F4E,
		TE_ACTIVE_SUBROUTINES =											0x8DE5,
		TE_ACTIVE_SUBROUTINE_UNIFORMS =									0x8DE6,
		TE_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS =						0x8E47,
		TE_ACTIVE_SUBROUTINE_MAX_LENGTH =								0x8E48,
		TE_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH =						0x8E49,
		TE_MAX_SUBROUTINES =											0x8DE7,
		TE_MAX_SUBROUTINE_UNIFORM_LOCATIONS =							0x8DE8,
		TE_NUM_COMPATIBLE_SUBROUTINES =									0x8E4A,
		TE_COMPATIBLE_SUBROUTINES =										0x8E4B,
		TE_PATCHES =													0x000E,
		TE_PATCH_VERTICES =												0x8E72,
		TE_PATCH_DEFAULT_INNER_LEVEL =									0x8E73,
		TE_PATCH_DEFAULT_OUTER_LEVEL =									0x8E74,
		TE_TESS_CONTROL_OUTPUT_VERTICES =								0x8E75,
		TE_TESS_GEN_MODE =												0x8E76,
		TE_TESS_GEN_SPACING =											0x8E77,
		TE_TESS_GEN_VERTEX_ORDER =										0x8E78,
		TE_TESS_GEN_POINT_MODE =										0x8E79,
		TE_ISOLINES =													0x8E7A,
		TE_FRACTIONAL_ODD =												0x8E7B,
		TE_FRACTIONAL_EVEN =											0x8E7C,
		TE_MAX_PATCH_VERTICES =											0x8E7D,
		TE_MAX_TESS_GEN_LEVEL =											0x8E7E,
		TE_MAX_TESS_CONTROL_UNIFORM_COMPONENTS =						0x8E7F,
		TE_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS =						0x8E80,
		TE_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS =						0x8E81,
		TE_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS =					0x8E82,
		TE_MAX_TESS_CONTROL_OUTPUT_COMPONENTS =							0x8E83,
		TE_MAX_TESS_PATCH_COMPONENTS =									0x8E84,
		TE_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS =					0x8E85,
		TE_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS =						0x8E86,
		TE_MAX_TESS_CONTROL_UNIFORM_BLOCKS =							0x8E89,
		TE_MAX_TESS_EVALUATION_UNIFORM_BLOCKS =							0x8E8A,
		TE_MAX_TESS_CONTROL_INPUT_COMPONENTS =							0x886C,
		TE_MAX_TESS_EVALUATION_INPUT_COMPONENTS =						0x886D,
		TE_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS =				0x8E1E,
		TE_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS =			0x8E1F,
		TE_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER =			0x84F0,
		TE_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER =			0x84F1,
		TE_TESS_EVALUATION_SHADER =										0x8E87,
		TE_TESS_CONTROL_SHADER =										0x8E88,
		TE_TRANSFORM_FEEDBACK =											0x8E22,
		TE_TRANSFORM_FEEDBACK_BUFFER_PAUSED =							0x8E23,
		TE_TRANSFORM_FEEDBACK_BUFFER_ACTIVE =							0x8E24,
		TE_TRANSFORM_FEEDBACK_BINDING =									0x8E25,
		TE_MAX_TRANSFORM_FEEDBACK_BUFFERS =								0x8E70,
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
	enum openGL4_1
	{
		TE_FIXED =									0x140C,
		TE_IMPLEMENTATION_COLOR_READ_TYPE =			0x8B9A,
		TE_IMPLEMENTATION_COLOR_READ_FORMAT =		0x8B9B,
		TE_LOW_FLOAT =								0x8DF0,
		TE_MEDIUM_FLOAT =							0x8DF1,
		TE_HIGH_FLOAT =								0x8DF2,
		TE_LOW_INT =								0x8DF3,
		TE_MEDIUM_INT =								0x8DF4,
		TE_HIGH_INT =								0x8DF5,
		TE_SHADER_COMPILER =						0x8DFA,
		TE_SHADER_BINARY_FORMATS =					0x8DF8,
		TE_NUM_SHADER_BINARY_FORMATS =				0x8DF9,
		TE_MAX_VERTEX_UNIFORM_VECTORS =				0x8DFB,
		TE_MAX_VARYING_VECTORS =					0x8DFC,
		TE_MAX_FRAGMENT_UNIFORM_VECTORS =			0x8DFD,
		TE_RGB565 =									0x8D62,
		TE_PROGRAM_BINARY_RETRIEVABLE_HINT =		0x8257,
		TE_PROGRAM_BINARY_LENGTH =					0x8741,
		TE_NUM_PROGRAM_BINARY_FORMATS =				0x87FE,
		TE_PROGRAM_BINARY_FORMATS =					0x87FF,
		TE_VERTEX_SHADER_BIT =						0x00000001,
		TE_FRAGMENT_SHADER_BIT =					0x00000002,
		TE_GEOMETRY_SHADER_BIT =					0x00000004,
		TE_TESS_CONTROL_SHADER_BIT =				0x00000008,
		TE_TESS_EVALUATION_SHADER_BIT =				0x00000010,
		TE_ALL_SHADER_BITS =						0xFFFFFFFF,
		TE_PROGRAM_SEPARABLE =						0x8258,
		TE_ACTIVE_PROGRAM =							0x8259,
		TE_PROGRAM_PIPELINE_BINDING =				0x825A,
		TE_MAX_VIEWPORTS =							0x825B,
		TE_VIEWPORT_SUBPIXEL_BITS =					0x825C,
		TE_VIEWPORT_BOUNDS_RANGE =					0x825D,
		TE_LAYER_PROVOKING_VERTEX =					0x825E,
		TE_VIEWPORT_INDEX_PROVOKING_VERTEX =		0x825F,
		TE_UNDEFINED_VERTEX =						0x8260
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
	enum openGL4_2
	{
		TE_UNPACK_COMPRESSED_BLOCK_WIDTH =										0x9127,
		TE_UNPACK_COMPRESSED_BLOCK_HEIGHT =										0x9128,
		TE_UNPACK_COMPRESSED_BLOCK_DEPTH =										0x9129,
		TE_UNPACK_COMPRESSED_BLOCK_SIZE =										0x912A,
		TE_PACK_COMPRESSED_BLOCK_WIDTH =										0x912B,
		TE_PACK_COMPRESSED_BLOCK_HEIGHT =										0x912C,
		TE_PACK_COMPRESSED_BLOCK_DEPTH =										0x912D,
		TE_PACK_COMPRESSED_BLOCK_SIZE =											0x912E,
		TE_NUM_SAMPLE_COUNTS =													0x9380,
		TE_MIN_MAP_BUFFER_ALIGNMENT =											0x90BC,
		TE_ATOMIC_COUNTER_BUFFER =												0x92C0,
		TE_ATOMIC_COUNTER_BUFFER_BINDING =										0x92C1,
		TE_ATOMIC_COUNTER_BUFFER_START =										0x92C2,
		TE_ATOMIC_COUNTER_BUFFER_SIZE =											0x92C3,
		TE_ATOMIC_COUNTER_BUFFER_DATA_SIZE =									0x92C4,
		TE_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS =						0x92C5,
		TE_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES =				0x92C6,
		TE_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER =					0x92C7,
		TE_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER =			0x92C8,
		TE_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER =			0x92C9,
		TE_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER =				0x92CA,
		TE_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER =				0x92CB,
		TE_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS =									0x92CC,
		TE_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS =							0x92CD,
		TE_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS =							0x92CE,
		TE_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS =								0x92CF,
		TE_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS =								0x92D0,
		TE_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS =								0x92D1,
		TE_MAX_VERTEX_ATOMIC_COUNTERS =											0x92D2,
		TE_MAX_TESS_CONTROL_ATOMIC_COUNTERS =									0x92D3,
		TE_MAX_TESS_EVALUATION_ATOMIC_COUNTERS =								0x92D4,
		TE_MAX_GEOMETRY_ATOMIC_COUNTERS =										0x92D5,
		TE_MAX_FRAGMENT_ATOMIC_COUNTERS =										0x92D6,
		TE_MAX_COMBINED_ATOMIC_COUNTERS =										0x92D7,
		TE_MAX_ATOMIC_COUNTER_BUFFER_SIZE =										0x92D8,
		TE_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS =									0x92DC,
		TE_ACTIVE_ATOMIC_COUNTER_BUFFERS =										0x92D9,
		TE_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX =								0x92DA,
		TE_UNSIGNED_INT_ATOMIC_COUNTER =										0x92DB,
		TE_VERTEX_ATTRIB_ARRAY_BARRIER_BIT =									0x00000001,
		TE_ELEMENT_ARRAY_BARRIER_BIT =											0x00000002,
		TE_UNIFORM_BARRIER_BIT =												0x00000004,
		TE_TEXTURE_FETCH_BARRIER_BIT =											0x00000008,
		TE_SHADER_IMAGE_ACCESS_BARRIER_BIT =									0x00000020,
		TE_COMMAND_BARRIER_BIT =												0x00000040,
		TE_PIXEL_BUFFER_BARRIER_BIT =											0x00000080,
		TE_TEXTURE_UPDATE_BARRIER_BIT =											0x00000100,
		TE_BUFFER_UPDATE_BARRIER_BIT =											0x00000200,
		TE_FRAMEBUFFER_BARRIER_BIT =											0x00000400,
		TE_TRANSFORM_FEEDBACK_BARRIER_BIT =										0x00000800,
		TE_ATOMIC_COUNTER_BARRIER_BIT =											0x00001000,
		TE_ALL_BARRIER_BITS =													0xFFFFFFFF,
		TE_MAX_IMAGE_UNITS =													0x8F38,
		TE_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS =						0x8F39,
		TE_IMAGE_BINDING_NAME =													0x8F3A,
		TE_IMAGE_BINDING_LEVEL =												0x8F3B,
		TE_IMAGE_BINDING_LAYERED =												0x8F3C,
		TE_IMAGE_BINDING_LAYER =												0x8F3D,
		TE_IMAGE_BINDING_ACCESS =												0x8F3E,
		TE_IMAGE_1D =															0x904C,
		TE_IMAGE_2D =															0x904D,
		TE_IMAGE_3D =															0x904E,
		TE_IMAGE_2D_RECT =														0x904F,
		TE_IMAGE_CUBE =															0x9050,
		TE_IMAGE_BUFFER =														0x9051,
		TE_IMAGE_1D_ARRAY =														0x9052,
		TE_IMAGE_2D_ARRAY =														0x9053,
		TE_IMAGE_CUBE_MAP_ARRAY =												0x9054,
		TE_IMAGE_2D_MULTISAMPLE =												0x9055,
		TE_IMAGE_2D_MULTISAMPLE_ARRAY =											0x9056,
		TE_INT_IMAGE_1D =														0x9057,
		TE_INT_IMAGE_2D =														0x9058,
		TE_INT_IMAGE_3D =														0x9059,
		TE_INT_IMAGE_2D_RECT =													0x905A,
		TE_INT_IMAGE_CUBE =														0x905B,
		TE_INT_IMAGE_BUFFER =													0x905C,
		TE_INT_IMAGE_1D_ARRAY =													0x905D,
		TE_INT_IMAGE_2D_ARRAY =													0x905E,
		TE_INT_IMAGE_CUBE_MAP_ARRAY =											0x905F,
		TE_INT_IMAGE_2D_MULTISAMPLE =											0x9060,
		TE_INT_IMAGE_2D_MULTISAMPLE_ARRAY =										0x9061,
		TE_UNSIGNED_INT_IMAGE_1D =												0x9062,
		TE_UNSIGNED_INT_IMAGE_2D =												0x9063,
		TE_UNSIGNED_INT_IMAGE_3D =												0x9064,
		TE_UNSIGNED_INT_IMAGE_2D_RECT =											0x9065,
		TE_UNSIGNED_INT_IMAGE_CUBE =											0x9066,
		TE_UNSIGNED_INT_IMAGE_BUFFER =											0x9067,
		TE_UNSIGNED_INT_IMAGE_1D_ARRAY =										0x9068,
		TE_UNSIGNED_INT_IMAGE_2D_ARRAY =										0x9069,
		TE_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY =									0x906A,
		TE_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE =									0x906B,
		TE_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY =							0x906C,
		TE_MAX_IMAGE_SAMPLES =													0x906D,
		TE_IMAGE_BINDING_FORMAT =												0x906E,
		TE_IMAGE_FORMAT_COMPATIBILITY_TYPE =									0x90C7,
		TE_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE =									0x90C8,
		TE_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS =								0x90C9,
		TE_MAX_VERTEX_IMAGE_UNIFORMS =											0x90CA,
		TE_MAX_TESS_CONTROL_IMAGE_UNIFORMS =									0x90CB,
		TE_MAX_TESS_EVALUATION_IMAGE_UNIFORMS =									0x90CC,
		TE_MAX_GEOMETRY_IMAGE_UNIFORMS =										0x90CD,
		TE_MAX_FRAGMENT_IMAGE_UNIFORMS =										0x90CE,
		TE_MAX_COMBINED_IMAGE_UNIFORMS =										0x90CF,
		TE_TEXTURE_IMMUTABLE_FORMAT =											0x912F,
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
	enum openGL4_3
	{
		TE_NUM_SHADING_LANGUAGE_VERSIONS =								0x82E9,
		TE_VERTEX_ATTRIB_ARRAY_LONG =									0x874E,
		TE_COMPRESSED_RGB8_ETC2 =										0x9274,
		TE_COMPRESSED_SRGB8_ETC2 =										0x9275,
		TE_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 =					0x9276,
		TE_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 =					0x9277,
		TE_COMPRESSED_RGBA8_ETC2_EAC =									0x9278,
		TE_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC =							0x9279,
		TE_COMPRESSED_R11_EAC =											0x9270,
		TE_COMPRESSED_SIGNED_R11_EAC =									0x9271,
		TE_COMPRESSED_RG11_EAC =										0x9272,
		TE_COMPRESSED_SIGNED_RG11_EAC =									0x9273,
		TE_PRIMITIVE_RESTART_FIXED_INDEX =								0x8D69,
		TE_ANY_SAMPLES_PASSED_CONSERVATIVE =							0x8D6A,
		TE_MAX_ELEMENT_INDEX =											0x8D6B,
		TE_COMPUTE_SHADER =												0x91B9,
		TE_MAX_COMPUTE_UNIFORM_BLOCKS =									0x91BB,
		TE_MAX_COMPUTE_TEXTURE_IMAGE_UNITS =							0x91BC,
		TE_MAX_COMPUTE_IMAGE_UNIFORMS =									0x91BD,
		TE_MAX_COMPUTE_SHARED_MEMORY_SIZE =								0x8262,
		TE_MAX_COMPUTE_UNIFORM_COMPONENTS =								0x8263,
		TE_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS =							0x8264,
		TE_MAX_COMPUTE_ATOMIC_COUNTERS =								0x8265,
		TE_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS =					0x8266,
		TE_MAX_COMPUTE_WORK_GROUP_INVOCATIONS =							0x90EB,
		TE_MAX_COMPUTE_WORK_GROUP_COUNT =								0x91BE,
		TE_MAX_COMPUTE_WORK_GROUP_SIZE =								0x91BF,
		TE_COMPUTE_WORK_GROUP_SIZE =									0x8267,
		TE_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER =					0x90EC,
		TE_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER =			0x90ED,
		TE_DISPATCH_INDIRECT_BUFFER =									0x90EE,
		TE_DISPATCH_INDIRECT_BUFFER_BINDING =							0x90EF,
		TE_DEBUG_OUTPUT_SYNCHRONOUS =									0x8242,
		TE_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH =							0x8243,
		TE_DEBUG_CALLBACK_FUNCTION =									0x8244,
		TE_DEBUG_CALLBACK_USER_PARAM =									0x8245,
		TE_DEBUG_SOURCE_API =											0x8246,
		TE_DEBUG_SOURCE_WINDOW_SYSTEM =									0x8247,
		TE_DEBUG_SOURCE_SHADER_COMPILER =								0x8248,
		TE_DEBUG_SOURCE_THIRD_PARTY =									0x8249,
		TE_DEBUG_SOURCE_APPLICATION =									0x824A,
		TE_DEBUG_SOURCE_OTHER =											0x824B,
		TE_DEBUG_TYPE_ERROR =											0x824C,
		TE_DEBUG_TYPE_DEPRECATED_BEHAVIOR =								0x824D,
		TE_DEBUG_TYPE_UNDEFINED_BEHAVIOR =								0x824E,
		TE_DEBUG_TYPE_PORTABILITY =										0x824F,
		TE_DEBUG_TYPE_PERFORMANCE =										0x8250,
		TE_DEBUG_TYPE_OTHER =											0x8251,
		TE_MAX_DEBUG_MESSAGE_LENGTH =									0x9143,
		TE_MAX_DEBUG_LOGGED_MESSAGES =									0x9144,
		TE_DEBUG_LOGGED_MESSAGES =										0x9145,
		TE_DEBUG_SEVERITY_HIGH =										0x9146,
		TE_DEBUG_SEVERITY_MEDIUM =										0x9147,
		TE_DEBUG_SEVERITY_LOW =											0x9148,
		TE_DEBUG_TYPE_MARKER =											0x8268,
		TE_DEBUG_TYPE_PUSH_GROUP =										0x8269,
		TE_DEBUG_TYPE_POP_GROUP =										0x826A,
		TE_DEBUG_SEVERITY_NOTIFICATION =								0x826B,
		TE_MAX_DEBUG_GROUP_STACK_DEPTH =								0x826C,
		TE_DEBUG_GROUP_STACK_DEPTH =									0x826D,
		TE_BUFFER =														0x82E0,
		TE_SHADER =														0x82E1,
		TE_PROGRAM =													0x82E2,
		TE_QUERY =														0x82E3,
		TE_PROGRAM_PIPELINE =											0x82E4,
		TE_SAMPLER =													0x82E6,
		TE_MAX_LABEL_LENGTH =											0x82E8,
		TE_DEBUG_OUTPUT =												0x92E0,
		TE_CONTEXT_FLAG_DEBUG_BIT =										0x00000002,
		TE_MAX_UNIFORM_LOCATIONS =										0x826E,
		TE_FRAMEBUFFER_DEFAULT_WIDTH =									0x9310,
		TE_FRAMEBUFFER_DEFAULT_HEIGHT =									0x9311,
		TE_FRAMEBUFFER_DEFAULT_LAYERS =									0x9312,
		TE_FRAMEBUFFER_DEFAULT_SAMPLES =								0x9313,
		TE_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS =					0x9314,
		TE_MAX_FRAMEBUFFER_WIDTH =										0x9315,
		TE_MAX_FRAMEBUFFER_HEIGHT =										0x9316,
		TE_MAX_FRAMEBUFFER_LAYERS =										0x9317,
		TE_MAX_FRAMEBUFFER_SAMPLES =									0x9318,
		TE_INTERNALFORMAT_SUPPORTED =									0x826F,
		TE_INTERNALFORMAT_PREFERRED =									0x8270,
		TE_INTERNALFORMAT_RED_SIZE =									0x8271,
		TE_INTERNALFORMAT_GREEN_SIZE =									0x8272,
		TE_INTERNALFORMAT_BLUE_SIZE =									0x8273,
		TE_INTERNALFORMAT_ALPHA_SIZE =									0x8274,
		TE_INTERNALFORMAT_DEPTH_SIZE =									0x8275,
		TE_INTERNALFORMAT_STENCIL_SIZE =								0x8276,
		TE_INTERNALFORMAT_SHARED_SIZE =									0x8277,
		TE_INTERNALFORMAT_RED_TYPE =									0x8278,
		TE_INTERNALFORMAT_GREEN_TYPE =									0x8279,
		TE_INTERNALFORMAT_BLUE_TYPE =									0x827A,
		TE_INTERNALFORMAT_ALPHA_TYPE =									0x827B,
		TE_INTERNALFORMAT_DEPTH_TYPE =									0x827C,
		TE_INTERNALFORMAT_STENCIL_TYPE =								0x827D,
		TE_MAX_WIDTH =													0x827E,
		TE_MAX_HEIGHT =													0x827F,
		TE_MAX_DEPTH =													0x8280,
		TE_MAX_LAYERS =													0x8281,
		TE_MAX_COMBINED_DIMENSIONS =									0x8282,
		TE_COLOR_COMPONENTS =											0x8283,
		TE_DEPTH_COMPONENTS =											0x8284,
		TE_STENCIL_COMPONENTS =											0x8285,
		TE_COLOR_RENDERABLE =											0x8286,
		TE_DEPTH_RENDERABLE =											0x8287,
		TE_STENCIL_RENDERABLE =											0x8288,
		TE_FRAMEBUFFER_RENDERABLE =										0x8289,
		TE_FRAMEBUFFER_RENDERABLE_LAYERED =								0x828A,
		TE_FRAMEBUFFER_BLEND =											0x828B,
		TE_READ_PIXELS =												0x828C,
		TE_READ_PIXELS_FORMAT =											0x828D,
		TE_READ_PIXELS_TYPE =											0x828E,
		TE_TEXTURE_IMAGE_FORMAT =										0x828F,
		TE_TEXTURE_IMAGE_TYPE =											0x8290,
		TE_GET_TEXTURE_IMAGE_FORMAT =									0x8291,
		TE_GET_TEXTURE_IMAGE_TYPE =										0x8292,
		TE_MIPMAP =														0x8293,
		TE_MANUAL_GENERATE_MIPMAP =										0x8294,
		TE_AUTO_GENERATE_MIPMAP =										0x8295,
		TE_COLOR_ENCODING =												0x8296,
		TE_SRGB_READ =													0x8297,
		TE_SRGB_WRITE =													0x8298,
		TE_FILTER =														0x829A,
		TE_VERTEX_TEXTURE =												0x829B,
		TE_TESS_CONTROL_TEXTURE =										0x829C,
		TE_TESS_EVALUATION_TEXTURE =									0x829D,
		TE_GEOMETRY_TEXTURE =											0x829E,
		TE_FRAGMENT_TEXTURE =											0x829F,
		TE_COMPUTE_TEXTURE =											0x82A0,
		TE_TEXTURE_SHADOW =												0x82A1,
		TE_TEXTURE_GATHER =												0x82A2,
		TE_TEXTURE_GATHER_SHADOW =										0x82A3,
		TE_SHADER_IMAGE_LOAD =											0x82A4,
		TE_SHADER_IMAGE_STORE =											0x82A5,
		TE_SHADER_IMAGE_ATOMIC =										0x82A6,
		TE_IMAGE_TEXEL_SIZE =											0x82A7,
		TE_IMAGE_COMPATIBILITY_CLASS =									0x82A8,
		TE_IMAGE_PIXEL_FORMAT =											0x82A9,
		TE_IMAGE_PIXEL_TYPE =											0x82AA,
		TE_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST =						0x82AC,
		TE_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST =						0x82AD,
		TE_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE =						0x82AE,
		TE_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE =						0x82AF,
		TE_TEXTURE_COMPRESSED_BLOCK_WIDTH =								0x82B1,
		TE_TEXTURE_COMPRESSED_BLOCK_HEIGHT =							0x82B2,
		TE_TEXTURE_COMPRESSED_BLOCK_SIZE =								0x82B3,
		TE_CLEAR_BUFFER =												0x82B4,
		TE_TEXTURE_VIEW =												0x82B5,
		TE_VIEW_COMPATIBILITY_CLASS =									0x82B6,
		TE_FULL_SUPPORT =												0x82B7,
		TE_CAVEAT_SUPPORT =												0x82B8,
		TE_IMAGE_CLASS_4_X_32 =											0x82B9,
		TE_IMAGE_CLASS_2_X_32 =											0x82BA,
		TE_IMAGE_CLASS_1_X_32 =											0x82BB,
		TE_IMAGE_CLASS_4_X_16 =											0x82BC,
		TE_IMAGE_CLASS_2_X_16 =											0x82BD,
		TE_IMAGE_CLASS_1_X_16 =											0x82BE,
		TE_IMAGE_CLASS_4_X_8 =											0x82BF,
		TE_IMAGE_CLASS_2_X_8 =											0x82C0,
		TE_IMAGE_CLASS_1_X_8 =											0x82C1,
		TE_IMAGE_CLASS_11_11_10 =										0x82C2,
		TE_IMAGE_CLASS_10_10_10_2 =										0x82C3,
		TE_VIEW_CLASS_128_BITS =										0x82C4,
		TE_VIEW_CLASS_96_BITS =											0x82C5,
		TE_VIEW_CLASS_64_BITS =											0x82C6,
		TE_VIEW_CLASS_48_BITS =											0x82C7,
		TE_VIEW_CLASS_32_BITS =											0x82C8,
		TE_VIEW_CLASS_24_BITS =											0x82C9,
		TE_VIEW_CLASS_16_BITS =											0x82CA,
		TE_VIEW_CLASS_8_BITS =											0x82CB,
		TE_VIEW_CLASS_S3TC_DXT1_RGB =									0x82CC,
		TE_VIEW_CLASS_S3TC_DXT1_RGBA =									0x82CD,
		TE_VIEW_CLASS_S3TC_DXT3_RGBA =									0x82CE,
		TE_VIEW_CLASS_S3TC_DXT5_RGBA =									0x82CF,
		TE_VIEW_CLASS_RGTC1_RED =										0x82D0,
		TE_VIEW_CLASS_RGTC2_RG =										0x82D1,
		TE_VIEW_CLASS_BPTC_UNORM =										0x82D2,
		TE_VIEW_CLASS_BPTC_FLOAT =										0x82D3,
		TE_UNIFORM =													0x92E1,
		TE_UNIFORM_BLOCK =												0x92E2,
		TE_PROGRAM_INPUT =												0x92E3,
		TE_PROGRAM_OUTPUT =												0x92E4,
		TE_BUFFER_VARIABLE =											0x92E5,
		TE_SHADER_STORAGE_BLOCK =										0x92E6,
		TE_VERTEX_SUBROUTINE =											0x92E8,
		TE_TESS_CONTROL_SUBROUTINE =									0x92E9,
		TE_TESS_EVALUATION_SUBROUTINE =									0x92EA,
		TE_GEOMETRY_SUBROUTINE =										0x92EB,
		TE_FRAGMENT_SUBROUTINE =										0x92EC,
		TE_COMPUTE_SUBROUTINE =											0x92ED,
		TE_VERTEX_SUBROUTINE_UNIFORM =									0x92EE,
		TE_TESS_CONTROL_SUBROUTINE_UNIFORM =							0x92EF,
		TE_TESS_EVALUATION_SUBROUTINE_UNIFORM =							0x92F0,
		TE_GEOMETRY_SUBROUTINE_UNIFORM =								0x92F1,
		TE_FRAGMENT_SUBROUTINE_UNIFORM =								0x92F2,
		TE_COMPUTE_SUBROUTINE_UNIFORM =									0x92F3,
		TE_TRANSFORM_FEEDBACK_VARYING =									0x92F4,
		TE_ACTIVE_RESOURCES =											0x92F5,
		TE_MAX_NAME_LENGTH =											0x92F6,
		TE_MAX_NUM_ACTIVE_VARIABLES =									0x92F7,
		TE_MAX_NUM_COMPATIBLE_SUBROUTINES =								0x92F8,
		TE_NAME_LENGTH =												0x92F9,
		TE_TYPE =														0x92FA,
		TE_ARRAY_SIZE =													0x92FB,
		TE_OFFSET =														0x92FC,
		TE_BLOCK_INDEX =												0x92FD,
		TE_ARRAY_STRIDE =												0x92FE,
		TE_MATRIX_STRIDE =												0x92FF,
		TE_IS_ROW_MAJOR =												0x9300,
		TE_ATOMIC_COUNTER_BUFFER_INDEX =								0x9301,
		TE_BUFFER_BINDING =												0x9302,
		TE_BUFFER_DATA_SIZE =											0x9303,
		TE_NUM_ACTIVE_VARIABLES =										0x9304,
		TE_ACTIVE_VARIABLES =											0x9305,
		TE_REFERENCED_BY_VERTEX_SHADER =								0x9306,
		TE_REFERENCED_BY_TESS_CONTROL_SHADER =							0x9307,
		TE_REFERENCED_BY_TESS_EVALUATION_SHADER =						0x9308,
		TE_REFERENCED_BY_GEOMETRY_SHADER =								0x9309,
		TE_REFERENCED_BY_FRAGMENT_SHADER =								0x930A,
		TE_REFERENCED_BY_COMPUTE_SHADER =								0x930B,
		TE_TOP_LEVEL_ARRAY_SIZE =										0x930C,
		TE_TOP_LEVEL_ARRAY_STRIDE =										0x930D,
		TE_LOCATION =													0x930E,
		TE_LOCATION_INDEX =												0x930F,
		TE_IS_PER_PATCH =												0x92E7,
		TE_SHADER_STORAGE_BUFFER =										0x90D2,
		TE_SHADER_STORAGE_BUFFER_BINDING =								0x90D3,
		TE_SHADER_STORAGE_BUFFER_START =								0x90D4,
		TE_SHADER_STORAGE_BUFFER_SIZE =									0x90D5,
		TE_MAX_VERTEX_SHADER_STORAGE_BLOCKS =							0x90D6,
		TE_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS =							0x90D7,
		TE_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS =						0x90D8,
		TE_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS =					0x90D9,
		TE_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS =							0x90DA,
		TE_MAX_COMPUTE_SHADER_STORAGE_BLOCKS =							0x90DB,
		TE_MAX_COMBINED_SHADER_STORAGE_BLOCKS =							0x90DC,
		TE_MAX_SHADER_STORAGE_BUFFER_BINDINGS =							0x90DD,
		TE_MAX_SHADER_STORAGE_BLOCK_SIZE =								0x90DE,
		TE_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT =						0x90DF,
		TE_SHADER_STORAGE_BARRIER_BIT =									0x00002000,
		TE_MAX_COMBINED_SHADER_OUTPUT_RESOURCES =						0x8F39,
		TE_DEPTH_STENCIL_TEXTURE_MODE =									0x90EA,
		TE_TEXTURE_BUFFER_OFFSET =										0x919D,
		TE_TEXTURE_BUFFER_SIZE =										0x919E,
		TE_TEXTURE_BUFFER_OFFSET_ALIGNMENT =							0x919F,
		TE_TEXTURE_VIEW_MIN_LEVEL =										0x82DB,
		TE_TEXTURE_VIEW_NUM_LEVELS =									0x82DC,
		TE_TEXTURE_VIEW_MIN_LAYER =										0x82DD,
		TE_TEXTURE_VIEW_NUM_LAYERS =									0x82DE,
		TE_TEXTURE_IMMUTABLE_LEVELS =									0x82DF,
		TE_VERTEX_ATTRIB_BINDING =										0x82D4,
		TE_VERTEX_ATTRIB_RELATIVE_OFFSET =								0x82D5,
		TE_VERTEX_BINDING_DIVISOR =										0x82D6,
		TE_VERTEX_BINDING_OFFSET =										0x82D7,
		TE_VERTEX_BINDING_STRIDE =										0x82D8,
		TE_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET =							0x82D9,
		TE_MAX_VERTEX_ATTRIB_BINDINGS =									0x82DA,
		TE_DISPLAY_LIST =												0x82E7,
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
	enum openGL4_4
	{
		TE_MAX_VERTEX_ATTRIB_STRIDE =						0x82E5,
		TE_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED =		0x8221,
		TE_TEXTURE_BUFFER_BINDING =							0x8C2A,
		TE_MAP_PERSISTENT_BIT =								0x0040,
		TE_MAP_COHERENT_BIT =								0x0080,
		TE_DYNAMIC_STORAGE_BIT =							0x0100,
		TE_CLIENT_STORAGE_BIT =								0x0200,
		TE_CLIENT_MAPPED_BUFFER_BARRIER_BIT = 				0x00004000,
		TE_BUFFER_IMMUTABLE_STORAGE =						0x821F,
		TE_BUFFER_STORAGE_FLAGS =							0x8220,
		TE_CLEAR_TEXTURE =									0x9365,
		TE_LOCATION_COMPONENT =								0x934A,
		TE_TRANSFORM_FEEDBACK_BUFFER_INDEX =				0x934B,
		TE_TRANSFORM_FEEDBACK_BUFFER_STRIDE =				0x934C,
		TE_QUERY_BUFFER =									0x9192,
		TE_QUERY_BUFFER_BARRIER_BIT =						0x00008000,
		TE_QUERY_BUFFER_BINDING =							0x9193,
		TE_QUERY_RESULT_NO_WAIT =							0x9194,
		TE_MIRROR_CLAMP_TO_EDGE =							0x8743
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

	/**< returns a proc address to an OpenGL extension */
	template<typename T> void FetchProcAddress(T& funcPointer, const char* procName)
	{
#if defined(TE_WINDOWS)
		funcPointer = (T)wglGetProcAddress(procName);
#elif defined(TE_LINUX)
		funcPointer = (T)glXGetProcAddress(procName);
#endif
	}

	/**< get OpenGL version */
	std::error_code InitializeGLVersion(void);

	/**< load OpenGL 1.2 extensions */
	void Load1_2Extensions(void);
	/**< load OpenGL 1.3 extensions */
	void Load1_3Extensions(void);
	/**< load OpenGL 1.4 extensions */
	void Load1_4Extensions(void);
	/**< load OpenGL 1.5 extensions */
	void Load1_5Extensions(void);
	/**< load OpenGL 2.0 extensions */
	void Load2_0Extensions(void);
	/**< load OpenGL 2.1 extensions */
	void Load2_1Extensions(void);
	/**< load OpenGL 3.0 extensions */
	void Load3_0Extensions(void);
	/**< load OpenGL 3.1 extensions */
	void Load3_1Extensions(void);
	/**< load OpenGL 3.2 extensions */
	void Load3_2Extensions(void);
	/**< load OpenGL 3.3 extensions */
	void Load3_3Extensions(void);
	/**< load OpenGL 4.0 extensions */
	void Load4_0Extensions(void);
	/**< load OpenGL 4.1 extensions */
	void Load4_1Extensions(void);
	/**< load OpenGL 4.2 extensions */
	void Load4_2Extensions(void);
	/**< load OpenGL 4.3 extensions */
	void Load4_3Extensions(void);
	/**< load OpenGL 4.4 extensions */
	void Load4_4Extensions(void);

	/**< load all applicable OpenGL extensions */
	std::error_code InitializeExtentions(void);

	/**< load specific OpenGL extensions via OpenGL versions */
	std::error_code InitializeExtensionsSpecific(unsigned int OpenGLVersions);

	/**< whether an extension is supported */
	bool IsExtensionSupported(const char* extensionName);

}
#endif
