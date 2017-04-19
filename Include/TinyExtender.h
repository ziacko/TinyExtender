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
#include <cstring>

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
	void(*glDrawRangeElements) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices) = nullptr;
	void(*glTexImage3D) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels) = nullptr;
	void(*glTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) = nullptr;
	void(*glCopyTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) = nullptr;
	enum openGL1_2
	{
		GL_UNSIGNED_BYTE_3_3_2 =				0x8032,
		GL_UNSIGNED_SHORT_4_4_4_4 =				0x8033,
		GL_UNSIGNED_SHORT_5_5_5_1 =				0x8034,
		GL_UNSIGNED_INT_8_8_8_8 =				0x8035,
		GL_UNSIGNED_INT_10_10_10_2 =			0x8036,
		GL_TEXTURE_BINDING_3D =					0x806a,
		GL_PACK_SKIP_IMAGES =					0x806b,
		GL_PACK_IMAGE_HEIGHT =					0x806c,
		GL_UNPACK_SKIP_IMAGES =					0x806d,
		GL_UNPACK_IMAGE_HEIGHT =				0x806e,
		GL_TEXTURE_3D =							0x806f,
		GL_PROXY_TEXTURE_3D =					0x8070,
		GL_TEXTURE_DEPTH =						0x8071,
		GL_TEXTURE_WRAP_R =						0x8072,
		GL_MAX_3D_TEXTURE_SIZE =				0x8073,
		GL_UNSIGNED_BYTE_2_3_3_REV =			0x8362,
		GL_UNSIGNED_SHORT_5_6_5 =				0x8363,
		GL_UNSIGNED_SHORT_5_6_5_REV =			0x8364,
		GL_UNSIGNED_SHORT_4_4_4_4_REV =			0x8365,
		GL_UNSIGNED_SHORT_1_5_5_5_REV =			0x8366,
		GL_UNSIGNED_INT_8_8_8_8_REV =			0x8367,
		GL_UNSIGNED_INT_2_10_10_10_REV =		0x8368,
		GL_BGR =								0x80e0,
		GL_BGRA =								0x80e1,
		GL_MAX_ELEMENTS_VERTICES =				0x80e8,
		GL_MAX_ELEMENTS_INDICES =				0x80e9,
		GL_CLAMP_TO_EDGE =						0x812f,
		GL_TEXTURE_MIN_LOD =					0x813a,
		GL_TEXTURE_MAX_LOD =					0x813b,
		GL_TEXTURE_BASE_LEVEL =					0x813c,
		GL_TEXTURE_MAX_LEVEL =					0x813d,
		GL_SMOOTH_POINT_SIZE_RANGE =			0x0b12,
		GL_SMOOTH_POINT_SIZE_GRANULARITY =		0x0b13,
		GL_SMOOTH_LINE_WIDTH_RANGE =			0x0b22,
		GL_SMOOTH_LINE_WIDTH_GRANULARITY =		0x0b23,
		GL_ALIASED_LINE_WIDTH_RANGE =			0x846e,
		GL_RESCALE_NORMAL =						0x803a,
		GL_LIGHT_MODEL_COLOR_CONTROL =			0x81f8,
		GL_SINGLE_COLOR =						0x81f9,
		GL_SEPARATE_SPECULAR_COLOR =			0x81fa,
		GL_ALIASED_POINT_SIZE_RANGE =			0x846d
	};

	//OpenGL 1.3 Extensions
	void(*glActiveTexture) (GLenum texture) = nullptr;
	void(*glSampleCoverage) (GLfloat value, GLboolean invert) = nullptr;
	void(*glCompressedTexImage3D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data) = nullptr;
	void(*glCompressedTexImage2D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data) = nullptr;
	void(*glCompressedTexImage1D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data) = nullptr;
	void(*glCompressedTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) = nullptr;
	void(*glCompressedTexSubImage2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) = nullptr;
	void(*glCompressedTexSubImage1D) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data) = nullptr;
	void(*glGetCompressedTexImage) (GLenum target, GLint level, void *img) = nullptr;
	void(*glClientActiveTexture) (GLenum texture) = nullptr;
	void(*glMultiTexCoord1d) (GLenum target, GLdouble s) = nullptr;
	void(*glMultiTexCoord1dv) (GLenum target, const GLdouble *v) = nullptr;
	void(*glMultiTexCoord1f) (GLenum target, GLfloat s) = nullptr;
	void(*glMultiTexCoord1fv) (GLenum target, const GLfloat *v) = nullptr;
	void(*glMultiTexCoord1i) (GLenum target, GLint s) = nullptr;
	void(*glMultiTexCoord1iv) (GLenum target, const GLint *v) = nullptr;
	void(*glMultiTexCoord1s) (GLenum target, GLshort s) = nullptr;
	void(*glMultiTexCoord1sv) (GLenum target, const GLshort *v) = nullptr;
	void(*glMultiTexCoord2d) (GLenum target, GLdouble s, GLdouble t) = nullptr;
	void(*glMultiTexCoord2dv) (GLenum target, const GLdouble *v) = nullptr;
	void(*glMultiTexCoord2f) (GLenum target, GLfloat s, GLfloat t) = nullptr;
	void(*glMultiTexCoord2fv) (GLenum target, const GLfloat *v) = nullptr;
	void(*glMultiTexCoord2i) (GLenum target, GLint s, GLint t) = nullptr;
	void(*glMultiTexCoord2iv) (GLenum target, const GLint *v) = nullptr;
	void(*glMultiTexCoord2s) (GLenum target, GLshort s, GLshort t) = nullptr;
	void(*glMultiTexCoord2sv) (GLenum target, const GLshort *v) = nullptr;
	void(*glMultiTexCoord3d) (GLenum target, GLdouble s, GLdouble t, GLdouble r) = nullptr;
	void(*glMultiTexCoord3dv) (GLenum target, const GLdouble *v) = nullptr;
	void(*glMultiTexCoord3f) (GLenum target, GLfloat s, GLfloat t, GLfloat r) = nullptr;
	void(*glMultiTexCoord3fv) (GLenum target, const GLfloat *v) = nullptr;
	void(*glMultiTexCoord3i) (GLenum target, GLint s, GLint t, GLint r) = nullptr;
	void(*glMultiTexCoord3iv) (GLenum target, const GLint *v) = nullptr;
	void(*glMultiTexCoord3s) (GLenum target, GLshort s, GLshort t, GLshort r) = nullptr;
	void(*glMultiTexCoord3sv) (GLenum target, const GLshort *v) = nullptr;
	void(*glMultiTexCoord4d) (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) = nullptr;
	void(*glMultiTexCoord4dv) (GLenum target, const GLdouble *v) = nullptr;
	void(*glMultiTexCoord4f) (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) = nullptr;
	void(*glMultiTexCoord4fv) (GLenum target, const GLfloat *v) = nullptr;
	void(*glMultiTexCoord4i) (GLenum target, GLint s, GLint t, GLint r, GLint q) = nullptr;
	void(*glMultiTexCoord4iv) (GLenum target, const GLint *v) = nullptr;
	void(*glMultiTexCoord4s) (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) = nullptr;
	void(*glMultiTexCoord4sv) (GLenum target, const GLshort *v) = nullptr;
	void(*glLoadTransposeMatrixf) (const GLfloat *m) = nullptr;
	void(*glLoadTransposeMatrixd) (const GLdouble *m) = nullptr;
	void(*glMultTransposeMatrixf) (const GLfloat *m) = nullptr;
	void(*glMultTransposeMatrixd) (const GLdouble *m) = nullptr;
	enum openGL1_3
	{
		GL_TEXTURE0 =								0x84c0,
		GL_TEXTURE1 =								0x84c1,
		GL_TEXTURE2 =								0x84c2,
		GL_TEXTURE3 =								0x84c3,
		GL_TEXTURE4 =								0x84c4,
		GL_TEXTURE5 =								0x84c5,
		GL_TEXTURE6 =								0x84c6,
		GL_TEXTURE7 =								0x84c7,
		GL_TEXTURE8 =								0x84c8,
		GL_TEXTURE9 =								0x84c9,
		GL_TEXTURE10 =								0x84ca,
		GL_TEXTURE11 =								0x84cb,
		GL_TEXTURE12 =								0x84cc,
		GL_TEXTURE13 =								0x84cd,
		GL_TEXTURE14 =								0x84ce,
		GL_TEXTURE15 =								0x84cf,
		GL_TEXTURE16 =								0x84d0,
		GL_TEXTURE17 =								0x84d1,
		GL_TEXTURE18 =								0x84d2,
		GL_TEXTURE19 =								0x84d3,
		GL_TEXTURE20 =								0x84d4,
		GL_TEXTURE21 =								0x84d5,
		GL_TEXTURE22 =								0x84d6,
		GL_TEXTURE23 =								0x84d7,
		GL_TEXTURE24 =								0x84d8,
		GL_TEXTURE25 =								0x84d9,
		GL_TEXTURE26 =								0x84da,
		GL_TEXTURE27 =								0x84db,
		GL_TEXTURE28 =								0x84dc,
		GL_TEXTURE29 =								0x84dd,
		GL_TEXTURE30 =								0x84de,
		GL_TEXTURE31 =								0x84df,
		GL_ACTIVE_TEXTURE =							0x84e0,
		GL_MULTISAMPLE =							0x809d,
		GL_SAMPLE_ALPHA_TO_COVERAGE =				0x809e,
		GL_SAMPLE_ALPHA_TO_ONE =					0x809f,
		GL_SAMPLE_COVERAGE =						0x80a0,
		GL_SAMPLE_BUFFERS =							0x80a8,
		GL_SAMPLES =								0x80a9,
		GL_SAMPLE_COVERAGE_VALUE =					0x80aa,
		GL_SAMPLE_COVERAGE_INVERT =					0x80ab,
		GL_TEXTURE_CUBE_MAP =						0x8513,
		GL_TEXTURE_BINDING_CUBE_MAP =				0x8514,
		GL_TEXTURE_CUBE_MAP_POSITIVE_X =			0x8515,
		GL_TEXTURE_CUBE_MAP_NEGATIVE_X =			0x8516,
		GL_TEXTURE_CUBE_MAP_POSITIVE_Y =			0x8517,
		GL_TEXTURE_CUBE_MAP_NEGATIVE_Y =			0x8518,
		GL_TEXTURE_CUBE_MAP_POSITIVE_Z =			0x8519,
		GL_TEXTURE_CUBE_MAP_NEGATIVE_Z =			0x851a,
		GL_PROXY_TEXTURE_CUBE_MAP =					0x851b,
		GL_MAX_CUBE_MAP_TEXTURE_SIZE =				0x851c,
		GL_COMPRESSED_RGB =							0x84ed,
		GL_COMPRESSED_RGBA =						0x84ee,
		GL_TEXTURE_COMPRESSION_HINT =				0x84ef,
		GL_TEXTURE_COMPRESSED_IMAGE_SIZE =			0x86a0,
		GL_TEXTURE_COMPRESSED =						0x86a1,
		GL_NUM_COMPRESSED_TEXTURE_FORMATS =			0x86a2,
		GL_COMPRESSED_TEXTURE_FORMATS =				0x86a3,
		GL_CLAMP_TO_BORDER =						0x812d,
		GL_CLIENT_ACTIVE_TEXTURE =					0x84e1,
		GL_MAX_TEXTURE_UNITS =						0x84e2,
		GL_TRANSPOSE_MODELVIEW_MATRIX =				0x84e3,
		GL_TRANSPOSE_PROJECTION_MATRIX =			0x84e4,
		GL_TRANSPOSE_TEXTURE_MATRIX =				0x84e5,
		GL_TRANSPOSE_COLOR_MATRIX =					0x84e6,
		GL_MULTISAMPLE_BIT =						0x20000000,
		GL_NORMAL_MAP =								0x8511,
		GL_REFLECTION_MAP =							0x8512,
		GL_COMPRESSED_ALPHA =						0x84e9,
		GL_COMPRESSED_LUMINANCE =					0x84ea,
		GL_COMPRESSED_LUMINANCE_ALPHA =				0x84eb,
		GL_COMPRESSED_INTENSITY =					0x84ec,
		GL_COMBINE =								0x8570,
		GL_COMBINE_RGB =							0x8571,
		GL_COMBINE_ALPHA =							0x8572,
		GL_SOURCE0_RGB =							0x8580,
		GL_SOURCE1_RGB =							0x8581,
		GL_SOURCE2_RGB =							0x8582,
		GL_SOURCE0_ALPHA =							0x8588,
		GL_SOURCE1_ALPHA =							0x8589,
		GL_SOURCE2_ALPHA =							0x858a,
		GL_OPERAND0_RGB =							0x8590,
		GL_OPERAND1_RGB =							0x8591,
		GL_OPERAND2_RGB =							0x8592,
		GL_OPERAND0_ALPHA =							0x8598,
		GL_OPERAND1_ALPHA =							0x8599,
		GL_OPERAND2_ALPHA =							0x859a,
		GL_RGB_SCALE =								0x8573,
		GL_ADD_SIGNED =								0x8574,
		GL_INTERPOLATE =							0x8575,
		GL_SUBTRACT =								0x84e7,
		GL_CONSTANT =								0x8576,
		GL_PRIMARY_COLOR =							0x8577,
		GL_PREVIOUS =								0x8578,
		GL_DOT3_RGB =								0x86ae,
		GL_DOT3_RGBA =								0x86af,
	};

	//OpenGL 1.4 Extensions
	void(*glBlendFuncSeparate) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) = nullptr;
	void(*glMultiDrawArrays) (GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount) = nullptr;
	void(*glMultiDrawElements) (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount) = nullptr;
	void(*glPointParameterf) (GLenum pname, GLfloat param) = nullptr;
	void(*glPointParameterfv) (GLenum pname, const GLfloat *params) = nullptr;
	void(*glPointParameteri) (GLenum pname, GLint param) = nullptr;
	void(*glPointParameteriv) (GLenum pname, const GLint *params) = nullptr;
	void(*glFogCoordf) (GLfloat coord) = nullptr;
	void(*glFogCoordfv) (const GLfloat *coord) = nullptr;
	void(*glFogCoordd) (GLdouble coord) = nullptr;
	void(*glFogCoorddv) (const GLdouble *coord) = nullptr;
	void(*glFogCoordPointer) (GLenum type, GLsizei stride, const void *pointer) = nullptr;
	void(*glSecondaryColor3b) (GLbyte red, GLbyte green, GLbyte blue) = nullptr;
	void(*glSecondaryColor3bv) (const GLbyte *v) = nullptr;
	void(*glSecondaryColor3d) (GLdouble red, GLdouble green, GLdouble blue) = nullptr;
	void(*glSecondaryColor3dv) (const GLdouble *v) = nullptr;
	void(*glSecondaryColor3f) (GLfloat red, GLfloat green, GLfloat blue) = nullptr;
	void(*glSecondaryColor3fv) (const GLfloat *v) = nullptr;
	void(*glSecondaryColor3i) (GLint red, GLint green, GLint blue) = nullptr;
	void(*glSecondaryColor3iv) (const GLint *v) = nullptr;
	void(*glSecondaryColor3s) (GLshort red, GLshort green, GLshort blue) = nullptr;
	void(*glSecondaryColor3sv) (const GLshort *v) = nullptr;
	void(*glSecondaryColor3ub) (GLubyte red, GLubyte green, GLubyte blue) = nullptr;
	void(*glSecondaryColor3ubv) (const GLubyte *v) = nullptr;
	void(*glSecondaryColor3ui) (GLuint red, GLuint green, GLuint blue) = nullptr;
	void(*glSecondaryColor3uiv) (const GLuint *v) = nullptr;
	void(*glSecondaryColor3us) (GLushort red, GLushort green, GLushort blue) = nullptr;
	void(*glSecondaryColor3usv) (const GLushort *v) = nullptr;
	void(*glSecondaryColorPointer) (GLint size, GLenum type, GLsizei stride, const void *pointer) = nullptr;
	void(*glWindowPos2d) (GLdouble x, GLdouble y) = nullptr;
	void(*glWindowPos2dv) (const GLdouble *v) = nullptr;
	void(*glWindowPos2f) (GLfloat x, GLfloat y) = nullptr;
	void(*glWindowPos2fv) (const GLfloat *v) = nullptr;
	void(*glWindowPos2i) (GLint x, GLint y) = nullptr;
	void(*glWindowPos2iv) (const GLint *v) = nullptr;
	void(*glWindowPos2s) (GLshort x, GLshort y) = nullptr;
	void(*glWindowPos2sv) (const GLshort *v) = nullptr;
	void(*glWindowPos3d) (GLdouble x, GLdouble y, GLdouble z) = nullptr;
	void(*glWindowPos3dv) (const GLdouble *v) = nullptr;
	void(*glWindowPos3f) (GLfloat x, GLfloat y, GLfloat z) = nullptr;
	void(*glWindowPos3fv) (const GLfloat *v) = nullptr;
	void(*glWindowPos3i) (GLint x, GLint y, GLint z) = nullptr;
	void(*glWindowPos3iv) (const GLint *v) = nullptr;
	void(*glWindowPos3s) (GLshort x, GLshort y, GLshort z) = nullptr;
	void(*glWindowPos3sv) (const GLshort *v) = nullptr;
	void(*glBlendColor) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) = nullptr;
	void(*glBlendEquation) (GLenum mode) = nullptr;
	enum openGL1_4
	{
		GL_BLEND_DST_RGB =						0x80c8,
		GL_BLEND_SRC_RGB =						0x80c9,
		GL_BLEND_DST_ALPHA =					0x80ca,
		GL_BLEND_SRC_ALPHA =					0x80cb,
		GL_POINT_FADE_THRESHOLD_SIZE =			0x8128,
		GL_DEPTH_COMPONENT16 =					0x81a5,
		GL_DEPTH_COMPONENT24 =					0x81a6,
		GL_DEPTH_COMPONENT32 =					0x81a7,
		GL_MIRRORED_REPEAT =					0x8370,
		GL_MAX_TEXTURE_LOD_BIAS =				0x84fd,
		GL_TEXTURE_LOD_BIAS =					0x8501,
		GL_INCR_WRAP =							0x8507,
		GL_DECR_WRAP =							0x8508,
		GL_TEXTURE_DEPTH_SIZE =					0x884a,
		GL_TEXTURE_COMPARE_MODE =				0x884c,
		GL_TEXTURE_COMPARE_FUNC =				0x884d,
		GL_POINT_SIZE_MIN =						0x8126,
		GL_POINT_SIZE_MAX =						0x8127,
		GL_POINT_DISTANCE_ATTENUATION =			0x8129,
		GL_GENERATE_MIPMAP =					0x8191,
		GL_GENERATE_MIPMAP_HINT =				0x8192,
		GL_FOG_COORDINATE_SOURCE =				0x8450,
		GL_FOG_COORDINATE =						0x8451,
		GL_FRAGMENT_DEPTH =						0x8452,
		GL_CURRENT_FOG_COORDINATE =				0x8453,
		GL_FOG_COORDINATE_ARRAY_TYPE =			0x8454,
		GL_FOG_COORDINATE_ARRAY_STRIDE =		0x8455,
		GL_FOG_COORDINATE_ARRAY_POINTER =		0x8456,
		GL_FOG_COORDINATE_ARRAY =				0x8457,
		GL_COLOR_SUM =							0x8458,
		GL_CURRENT_SECONDARY_COLOR =			0x8459,
		GL_SECONDARY_COLOR_ARRAY_SIZE =			0x845a,
		GL_SECONDARY_COLOR_ARRAY_TYPE =			0x845b,
		GL_SECONDARY_COLOR_ARRAY_STRIDE =		0x845c,
		GL_SECONDARY_COLOR_ARRAY_POINTER =		0x845d,
		GL_SECONDARY_COLOR_ARRAY =				0x845e,
		GL_TEXTURE_FILTER_CONTROL =				0x8500,
		GL_DEPTH_TEXTURE_MODE =					0x884b,
		GL_COMPARE_R_TO_TEXTURE =				0x884e,
		GL_FUNC_ADD =							0x8006,
		GL_FUNC_SUBTRACT =						0x800a,
		GL_FUNC_REVERSE_SUBTRACT =				0x800b,
		GL_MIN =								0x8007,
		GL_MAX =								0x8008,
		GL_CONSTANT_COLOR =						0x8001,
		GL_ONE_MINUS_CONSTANT_COLOR =			0x8002,
		GL_CONSTANT_ALPHA =						0x8003,
		GL_ONE_MINUS_CONSTANT_ALPHA =			0x8004
	};

	//OpenGL 1.5 Extensions
	typedef ptrdiff_t GLsizeiptr;
	typedef ptrdiff_t GLintptr;
	void(*glGenQueries) (GLsizei n, GLuint *ids);
	void(*glDeleteQueries) (GLsizei n, const GLuint *ids);
	GLboolean(*glIsQuery) (GLuint id);
	void(*glBeginQuery) (GLenum target, GLuint id);
	void(*glEndQuery) (GLenum target);
	void(*glGetQueryiv) (GLenum target, GLenum pname, GLint *params);
	void(*glGetQueryObjectiv) (GLuint id, GLenum pname, GLint *params);
	void(*glGetQueryObjectuiv) (GLuint id, GLenum pname, GLuint *params);
	void(*glBindBuffer) (GLenum target, GLuint buffer);
	void(*glDeleteBuffers) (GLsizei n, const GLuint *buffers);
	void(*glGenBuffers) (GLsizei n, GLuint *buffers);
	GLboolean(*glIsBuffer) (GLuint buffer);
	void(*glBufferData) (GLenum target, GLsizeiptr size, const void *data, GLenum usage);
	void(*glBufferSubData) (GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
	void(*glGetBufferSubData) (GLenum target, GLintptr offset, GLsizeiptr size, void *data);
	void * (*glMapBuffer) (GLenum target, GLenum access);
	GLboolean(*glUnmapBuffer) (GLenum target);
	void(*glGetBufferParameteriv) (GLenum target, GLenum pname, GLint *params);
	void(*glGetBufferPointerv) (GLenum target, GLenum pname, void **params);
	enum openGL1_5
	{
		GL_BUFFER_SIZE =								0x8764,
		GL_BUFFER_USAGE =								0x8765,
		GL_QUERY_COUNTER_BITS =							0x8864,
		GL_CURRENT_QUERY =								0x8865,
		GL_QUERY_RESULT =								0x8866,
		GL_QUERY_RESULT_AVAILABLE =						0x8867,
		GL_ARRAY_BUFFER =								0x8892,
		GL_ELEMENT_ARRAY_BUFFER =						0x8893,
		GL_ARRAY_BUFFER_BINDING =						0x8894,
		GL_ELEMENT_ARRAY_BUFFER_BINDING =				0x8895,
		GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING =			0x889f,
		GL_READ_ONLY =									0x88b8,
		GL_WRITE_ONLY =									0x88b9,
		GL_READ_WRITE =									0x88ba,
		GL_BUFFER_ACCESS =								0x88bb,
		GL_BUFFER_MAPPED =								0x88bc,
		GL_BUFFER_MAP_POINTER =							0x88bd,
		GL_STREAM_DRAW =								0x88e0,
		GL_STREAM_READ =								0x88e1,
		GL_STREAM_COPY =								0x88e2,
		GL_STATIC_DRAW =								0x88e4,
		GL_STATIC_READ =								0x88e5,
		GL_STATIC_COPY =								0x88e6,
		GL_DYNAMIC_DRAW =								0x88e8,
		GL_DYNAMIC_READ =								0x88e9,
		GL_DYNAMIC_COPY =								0x88ea,
		GL_SAMPLES_PASSED =								0x8914,
		GL_SRC1_ALPHA =									0x8589,
		GL_VERTEX_ARRAY_BUFFER_BINDING =				0x8896,
		GL_NORMAL_ARRAY_BUFFER_BINDING =				0x8897,
		GL_COLOR_ARRAY_BUFFER_BINDING =					0x8898,
		GL_INDEX_ARRAY_BUFFER_BINDING =					0x8899,
		GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING =			0x889a,
		GL_EDGE_FLAG_ARRAY_BUFFER_BINDING =				0x889b,
		GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING =		0x889c,
		GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING =		0x889d,
		GL_WEIGHT_ARRAY_BUFFER_BINDING =				0x889e,
		GL_FOG_COORD_SRC =								0x8450,
		GL_FOG_COORD =									0x8451,
		GL_CURRENT_FOG_COORD =							0x8453,
		GL_FOG_COORD_ARRAY_TYPE =						0x8454,
		GL_FOG_COORD_ARRAY_STRIDE =						0x8455,
		GL_FOG_COORD_ARRAY_POINTER =					0x8456,
		GL_FOG_COORD_ARRAY =							0x8457,
		GL_FOG_COORD_ARRAY_BUFFER_BINDING =				0x889d,
		GL_SRC0_RGB =									0x8580,
		GL_SRC1_RGB =									0x8581,
		GL_SRC2_RGB =									0x8582,
		GL_SRC0_ALPHA =									0x8588,
		GL_SRC2_ALPHA =									0x858a,
	};

	//2.0 extensions
	typedef char GLchar;
	void(*glBlendEquationSeparate) (GLenum modeRGB, GLenum modeAlpha) = nullptr;
	void(*glDrawBuffers) (GLsizei n, const GLenum *bufs) = nullptr;
	void(*glStencilOpSeparate) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) = nullptr;
	void(*glStencilFuncSeparate) (GLenum face, GLenum func, GLint ref, GLuint mask) = nullptr;
	void(*glStencilMaskSeparate) (GLenum face, GLuint mask) = nullptr;
	void(*glAttachShader) (GLuint program, GLuint shader) = nullptr;
	void(*glBindAttribLocation) (GLuint program, GLuint index, const GLchar *name) = nullptr;
	void(*glCompileShader) (GLuint shader) = nullptr;
	GLuint(*glCreateProgram) (void) = nullptr;
	GLuint(*glCreateShader) (GLenum type) = nullptr;
	void(*glDeleteProgram) (GLuint program) = nullptr;
	void(*glDeleteShader) (GLuint shader) = nullptr;
	void(*glDetachShader) (GLuint program, GLuint shader) = nullptr;
	void(*glDisableVertexAttribArray) (GLuint index) = nullptr;
	void(*glEnableVertexAttribArray) (GLuint index) = nullptr;
	void(*glGetActiveAttrib) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) = nullptr;
	void(*glGetActiveUniform) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) = nullptr;
	void(*glGetAttachedShaders) (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders) = nullptr;
	GLint(*glGetAttribLocation) (GLuint program, const GLchar *name) = nullptr;
	void(*glGetProgramiv) (GLuint program, GLenum pname, GLint *params) = nullptr;
	void(*glGetProgramInfoLog) (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog) = nullptr;
	void(*glGetShaderiv) (GLuint shader, GLenum pname, GLint *params) = nullptr;
	void(*glGetShaderInfoLog) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog) = nullptr;
	void(*glGetShaderSource) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source) = nullptr;
	GLint(*glGetUniformLocation) (GLuint program, const GLchar *name) = nullptr;
	void(*glGetUniformfv) (GLuint program, GLint location, GLfloat *params) = nullptr;
	void(*glGetUniformiv) (GLuint program, GLint location, GLint *params) = nullptr;
	void(*glGetVertexAttribdv) (GLuint index, GLenum pname, GLdouble *params) = nullptr;
	void(*glGetVertexAttribfv) (GLuint index, GLenum pname, GLfloat *params) = nullptr;
	void(*glGetVertexAttribiv) (GLuint index, GLenum pname, GLint *params) = nullptr;
	void(*glGetVertexAttribPointerv) (GLuint index, GLenum pname, void **pointer) = nullptr;
	GLboolean(*glIsProgram) (GLuint program) = nullptr;
	GLboolean(*glIsShader) (GLuint shader) = nullptr;
	void(*glLinkProgram) (GLuint program) = nullptr;
	void(*glShaderSource) (GLuint shader, GLsizei count, const GLchar** string, const GLint *length) = nullptr;
	void(*glUseProgram) (GLuint program) = nullptr;
	void(*glUniform1f) (GLint location, GLfloat v0) = nullptr;
	void(*glUniform2f) (GLint location, GLfloat v0, GLfloat v1) = nullptr;
	void(*glUniform3f) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2) = nullptr;
	void(*glUniform4f) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) = nullptr;
	void(*glUniform1i) (GLint location, GLint v0) = nullptr;
	void(*glUniform2i) (GLint location, GLint v0, GLint v1) = nullptr;
	void(*glUniform3i) (GLint location, GLint v0, GLint v1, GLint v2) = nullptr;
	void(*glUniform4i) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3) = nullptr;
	void(*glUniform1fv) (GLint location, GLsizei count, const GLfloat *value) = nullptr;
	void(*glUniform2fv) (GLint location, GLsizei count, const GLfloat *value) = nullptr;
	void(*glUniform3fv) (GLint location, GLsizei count, const GLfloat *value) = nullptr;
	void(*glUniform4fv) (GLint location, GLsizei count, const GLfloat *value) = nullptr;
	void(*glUniform1iv) (GLint location, GLsizei count, const GLint *value) = nullptr;
	void(*glUniform2iv) (GLint location, GLsizei count, const GLint *value) = nullptr;
	void(*glUniform3iv) (GLint location, GLsizei count, const GLint *value) = nullptr;
	void(*glUniform4iv) (GLint location, GLsizei count, const GLint *value) = nullptr;
	void(*glUniformMatrix2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	void(*glUniformMatrix3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	void(*glUniformMatrix4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	void(*glValidateProgram) (GLuint program) = nullptr;
	void(*glVertexAttrib1d) (GLuint index, GLdouble x) = nullptr;
	void(*glVertexAttrib1dv) (GLuint index, const GLdouble *v) = nullptr;
	void(*glVertexAttrib1f) (GLuint index, GLfloat x) = nullptr;
	void(*glVertexAttrib1fv) (GLuint index, const GLfloat *v) = nullptr;
	void(*glVertexAttrib1s) (GLuint index, GLshort x) = nullptr;
	void(*glVertexAttrib1sv) (GLuint index, const GLshort *v) = nullptr;
	void(*glVertexAttrib2d) (GLuint index, GLdouble x, GLdouble y) = nullptr;
	void(*glVertexAttrib2dv) (GLuint index, const GLdouble *v) = nullptr;
	void(*glVertexAttrib2f) (GLuint index, GLfloat x, GLfloat y) = nullptr;
	void(*glVertexAttrib2fv) (GLuint index, const GLfloat *v) = nullptr;
	void(*glVertexAttrib2s) (GLuint index, GLshort x, GLshort y) = nullptr;
	void(*glVertexAttrib2sv) (GLuint index, const GLshort *v) = nullptr;
	void(*glVertexAttrib3d) (GLuint index, GLdouble x, GLdouble y, GLdouble z) = nullptr;
	void(*glVertexAttrib3dv) (GLuint index, const GLdouble *v) = nullptr;
	void(*glVertexAttrib3f) (GLuint index, GLfloat x, GLfloat y, GLfloat z) = nullptr;
	void(*glVertexAttrib3fv) (GLuint index, const GLfloat *v) = nullptr;
	void(*glVertexAttrib3s) (GLuint index, GLshort x, GLshort y, GLshort z) = nullptr;
	void(*glVertexAttrib3sv) (GLuint index, const GLshort *v) = nullptr;
	void(*glVertexAttrib4Nbv) (GLuint index, const GLbyte *v) = nullptr;
	void(*glVertexAttrib4Niv) (GLuint index, const GLint *v) = nullptr;
	void(*glVertexAttrib4Nsv) (GLuint index, const GLshort *v) = nullptr;
	void(*glVertexAttrib4Nub) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) = nullptr;
	void(*glVertexAttrib4Nubv) (GLuint index, const GLubyte *v) = nullptr;
	void(*glVertexAttrib4Nuiv) (GLuint index, const GLuint *v) = nullptr;
	void(*glVertexAttrib4Nusv) (GLuint index, const GLushort *v) = nullptr;
	void(*glVertexAttrib4bv) (GLuint index, const GLbyte *v) = nullptr;
	void(*glVertexAttrib4d) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) = nullptr;
	void(*glVertexAttrib4dv) (GLuint index, const GLdouble *v) = nullptr;
	void(*glVertexAttrib4f) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) = nullptr;
	void(*glVertexAttrib4fv) (GLuint index, const GLfloat *v) = nullptr;
	void(*glVertexAttrib4iv) (GLuint index, const GLint *v) = nullptr;
	void(*glVertexAttrib4s) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) = nullptr;
	void(*glVertexAttrib4sv) (GLuint index, const GLshort *v) = nullptr;
	void(*glVertexAttrib4ubv) (GLuint index, const GLubyte *v) = nullptr;
	void(*glVertexAttrib4uiv) (GLuint index, const GLuint *v) = nullptr;
	void(*glVertexAttrib4usv) (GLuint index, const GLushort *v) = nullptr;
	void(*glVertexAttribPointer) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) = nullptr;
	enum openGL2_0
	{
		GL_BLEND_EQUATION_RGB =						0x8009,
		GL_VERTEX_ATTRIB_ARRAY_ENABLED =			0x8622,
		GL_VERTEX_ATTRIB_ARRAY_SIZE =				0x8623,
		GL_VERTEX_ATTRIB_ARRAY_STRIDE =				0x8624,
		GL_VERTEX_ATTRIB_ARRAY_TYPE =				0x8625,
		GL_CURRENT_VERTEX_ATTRIB =					0x8626,
		GL_VERTEX_PROGRAM_POINT_SIZE =				0x8642,
		GL_VERTEX_ATTRIB_ARRAY_POINTER =			0x8645,
		GL_STENCIL_BACK_FUNC =						0x8800,
		GL_STENCIL_BACK_FAIL =						0x8801,
		GL_STENCIL_BACK_PASS_DEPTH_FAIL =			0x8802,
		GL_STENCIL_BACK_PASS_DEPTH_PASS =			0x8803,
		GL_MAX_DRAW_BUFFERS =						0x8824,
		GL_DRAW_BUFFER0 =							0x8825,
		GL_DRAW_BUFFER1 =							0x8826,
		GL_DRAW_BUFFER2 =							0x8827,
		GL_DRAW_BUFFER3 =							0x8828,
		GL_DRAW_BUFFER4 =							0x8829,
		GL_DRAW_BUFFER5 =							0x882a,
		GL_DRAW_BUFFER6 =							0x882b,
		GL_DRAW_BUFFER7 =							0x882c,
		GL_DRAW_BUFFER8 =							0x882d,
		GL_DRAW_BUFFER9 =							0x882e,
		GL_DRAW_BUFFER10 =							0x882f,
		GL_DRAW_BUFFER11 =							0x8830,
		GL_DRAW_BUFFER12 =							0x8831,
		GL_DRAW_BUFFER13 =							0x8832,
		GL_DRAW_BUFFER14 =							0x8833,
		GL_DRAW_BUFFER15 =							0x8834,
		GL_BLEND_EQUATION_ALPHA =					0x883d,
		GL_MAX_VERTEX_ATTRIBS =						0x8869,
		GL_VERTEX_ATTRIB_ARRAY_NORMALIZED =			0x886a,
		GL_MAX_TEXTURE_IMAGE_UNITS =				0x8872,
		GL_FRAGMENT_SHADER =						0x8b30,
		GL_VERTEX_SHADER =							0x8b31,
		GL_MAX_FRAGMENT_UNIFORM_COMPONENTS =		0x8b49,
		GL_MAX_VERTEX_UNIFORM_COMPONENTS =			0x8b4a,
		GL_MAX_VARYING_FLOATS =						0x8b4b,
		GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS =			0x8b4c,
		GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS =		0x8b4d,
		GL_SHADER_TYPE =							0x8b4f,
		GL_FLOAT_VEC2 =								0x8b50,
		GL_FLOAT_VEC3 =								0x8b51,
		GL_FLOAT_VEC4 =								0x8b52,
		GL_INT_VEC2 =								0x8b53,
		GL_INT_VEC3 =								0x8b54,
		GL_INT_VEC4 =								0x8b55,
		GL_BOOL =									0x8b56,
		GL_BOOL_VEC2 =								0x8b57,
		GL_BOOL_VEC3 =								0x8b58,
		GL_BOOL_VEC4 =								0x8b59,
		GL_FLOAT_MAT2 =								0x8b5a,
		GL_FLOAT_MAT3 =								0x8b5b,
		GL_FLOAT_MAT4 =								0x8b5c,
		GL_SAMPLER_1D =								0x8b5d,
		GL_SAMPLER_2D =								0x8b5e,
		GL_SAMPLER_3D =								0x8b5f,
		GL_SAMPLER_CUBE =							0x8b60,
		GL_SAMPLER_1D_SHADOW =						0x8b61,
		GL_SAMPLER_2D_SHADOW =						0x8b62,
		GL_DELETE_STATUS =							0x8b80,
		GL_COMPILE_STATUS =							0x8b81,
		GL_LINK_STATUS =							0x8b82,
		GL_VALIDATE_STATUS =						0x8b83,
		GL_INFO_LOG_LENGTH =						0x8b84,
		GL_ATTACHED_SHADERS =						0x8b85,
		GL_ACTIVE_UNIFORMS =						0x8b86,
		GL_ACTIVE_UNIFORM_MAX_LENGTH =				0x8b87,
		GL_SHADER_SOURCE_LENGTH =					0x8b88,
		GL_ACTIVE_ATTRIBUTES =						0x8b89,
		GL_ACTIVE_ATTRIBUTE_MAX_LENGTH =			0x8b8a,
		GL_FRAGMENT_SHADER_DERIVATIVE_HINT =		0x8b8b,
		GL_SHADING_LANGUAGE_VERSION =				0x8b8c,
		GL_CURRENT_PROGRAM =						0x8b8d,
		GL_POINT_SPRITE_COORD_ORIGIN =				0x8ca0,
		GL_LOWER_LEFT =								0x8ca1,
		GL_UPPER_LEFT =								0x8ca2,
		GL_STENCIL_BACK_REF =						0x8ca3,
		GL_STENCIL_BACK_VALUE_MASK =				0x8ca4,
		GL_STENCIL_BACK_WRITEMASK =					0x8ca5,
		GL_VERTEX_PROGRAM_TWO_SIDE =				0x8643,
		GL_POINT_SPRITE =							0x8861,
		GL_COORD_REPLACE =							0x8862,
		GL_MAX_TEXTURE_COORDS =						0x8871
	};

	//OpenGL 2.1 Extensions
	void(*glUniformMatrix2x3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	void(*glUniformMatrix3x2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	void(*glUniformMatrix2x4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	void(*glUniformMatrix4x2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	void(*glUniformMatrix3x4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	void(*glUniformMatrix4x3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	enum openGL2_1
	{
		GL_PIXEL_PACK_BUFFER =					0x88eb,
		GL_PIXEL_UNPACK_BUFFER =				0x88ec,
		GL_PIXEL_PACK_BUFFER_BINDING =			0x88ed,
		GL_PIXEL_UNPACK_BUFFER_BINDING =		0x88ef,
		GL_FLOAT_MAT2X3 =						0x8b65,
		GL_FLOAT_MAT2X4 =						0x8b66,
		GL_FLOAT_MAT3X2 =						0x8b67,
		GL_FLOAT_MAT3X4 =						0x8b68,
		GL_FLOAT_MAT4X2 =						0x8b69,
		GL_FLOAT_MAT4X3 =						0x8b6a,
		GL_SRGB =								0x8c40,
		GL_SRGB8 =								0x8c41,
		GL_SRGB_ALPHA =							0x8c42,
		GL_SRGB8_ALPHA8 =						0x8c43,
		GL_COMPRESSED_SRGB =					0x8c48,
		GL_COMPRESSED_SRGB_ALPHA =				0x8c49,
		GL_CURRENT_RASTER_SECONDARY_COLOR =		0x845f,
		GL_SLUMINANCE_ALPHA =					0x8c44,
		GL_SLUMINANCE8_ALPHA8 =					0x8c45,
		GL_SLUMINANCE =							0x8c46,
		GL_SLUMINANCE8 =						0x8c47,
		GL_COMPRESSED_SLUMINANCE =				0x8c4a,
		GL_COMPRESSED_SLUMINANCE_ALPHA =		0x8c4b,
	};
	
	//3.0 extensions
	typedef unsigned short GLhalf;
	void(*glColorMaski) (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) = nullptr;
	void(*glGetBooleani_v) (GLenum target, GLuint index, GLboolean *data) = nullptr;
	void(*glGetIntegeri_v) (GLenum target, GLuint index, GLint *data) = nullptr;
	void(*glEnablei) (GLenum target, GLuint index) = nullptr;
	void(*glDisablei) (GLenum target, GLuint index) = nullptr;
	GLboolean(*glIsEnabledi) (GLenum target, GLuint index) = nullptr;
	void(*glBeginTransformFeedback) (GLenum primitiveMode) = nullptr;
	void(*glEndTransformFeedback) (void) = nullptr;
	void(*glBindBufferRange) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) = nullptr;
	void(*glBindBufferBase) (GLenum target, GLuint index, GLuint buffer) = nullptr;
	void(*glTransformFeedbackVaryings) (GLuint program, GLsizei count, const GLchar** varyings, GLenum bufferMode) = nullptr;
	void(*glGetTransformFeedbackVarying) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name) = nullptr;
	void(*glClampColor) (GLenum target, GLenum clamp) = nullptr;
	void(*glBeginConditionalRender) (GLuint id, GLenum mode) = nullptr;
	void(*glEndConditionalRender) (void) = nullptr;
	void(*glVertexAttribIPointer) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) = nullptr;
	void(*glGetVertexAttribIiv) (GLuint index, GLenum pname, GLint *params) = nullptr;
	void(*glGetVertexAttribIuiv) (GLuint index, GLenum pname, GLuint *params) = nullptr;
	void(*glVertexAttribI1i) (GLuint index, GLint x) = nullptr;
	void(*glVertexAttribI2i) (GLuint index, GLint x, GLint y) = nullptr;
	void(*glVertexAttribI3i) (GLuint index, GLint x, GLint y, GLint z) = nullptr;
	void(*glVertexAttribI4i) (GLuint index, GLint x, GLint y, GLint z, GLint w) = nullptr;
	void(*glVertexAttribI1ui) (GLuint index, GLuint x) = nullptr;
	void(*glVertexAttribI2ui) (GLuint index, GLuint x, GLuint y) = nullptr;
	void(*glVertexAttribI3ui) (GLuint index, GLuint x, GLuint y, GLuint z) = nullptr;
	void(*glVertexAttribI4ui) (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) = nullptr;
	void(*glVertexAttribI1iv) (GLuint index, const GLint *v) = nullptr;
	void(*glVertexAttribI2iv) (GLuint index, const GLint *v) = nullptr;
	void(*glVertexAttribI3iv) (GLuint index, const GLint *v) = nullptr;
	void(*glVertexAttribI4iv) (GLuint index, const GLint *v) = nullptr;
	void(*glVertexAttribI1uiv) (GLuint index, const GLuint *v) = nullptr;
	void(*glVertexAttribI2uiv) (GLuint index, const GLuint *v) = nullptr;
	void(*glVertexAttribI3uiv) (GLuint index, const GLuint *v) = nullptr;
	void(*glVertexAttribI4uiv) (GLuint index, const GLuint *v) = nullptr;
	void(*glVertexAttribI4bv) (GLuint index, const GLbyte *v) = nullptr;
	void(*glVertexAttribI4sv) (GLuint index, const GLshort *v) = nullptr;
	void(*glVertexAttribI4ubv) (GLuint index, const GLubyte *v) = nullptr;
	void(*glVertexAttribI4usv) (GLuint index, const GLushort *v) = nullptr;
	void(*glGetUniformuiv) (GLuint program, GLint location, GLuint *params) = nullptr;
	void(*glBindFragDataLocation) (GLuint program, GLuint color, const GLchar *name) = nullptr;
	GLint(*glGetFragDataLocation) (GLuint program, const GLchar *name) = nullptr;
	void(*glUniform1ui) (GLint location, GLuint v0) = nullptr;
	void(*glUniform2ui) (GLint location, GLuint v0, GLuint v1) = nullptr;
	void(*glUniform3ui) (GLint location, GLuint v0, GLuint v1, GLuint v2) = nullptr;
	void(*glUniform4ui) (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) = nullptr;
	void(*glUniform1uiv) (GLint location, GLsizei count, const GLuint *value) = nullptr;
	void(*glUniform2uiv) (GLint location, GLsizei count, const GLuint *value) = nullptr;
	void(*glUniform3uiv) (GLint location, GLsizei count, const GLuint *value) = nullptr;
	void(*glUniform4uiv) (GLint location, GLsizei count, const GLuint *value) = nullptr;
	void(*glTexParameterIiv) (GLenum target, GLenum pname, const GLint *params) = nullptr;
	void(*glTexParameterIuiv) (GLenum target, GLenum pname, const GLuint *params) = nullptr;
	void(*glGetTexParameterIiv) (GLenum target, GLenum pname, GLint *params) = nullptr;
	void(*glGetTexParameterIuiv) (GLenum target, GLenum pname, GLuint *params) = nullptr;
	void(*glClearBufferiv) (GLenum buffer, GLint drawbuffer, const GLint *value) = nullptr;
	void(*glClearBufferuiv) (GLenum buffer, GLint drawbuffer, const GLuint *value) = nullptr;
	void(*glClearBufferfv) (GLenum buffer, GLint drawbuffer, const GLfloat *value) = nullptr;
	void(*glClearBufferfi) (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) = nullptr;
	const GLubyte* (*glGetStringi) (GLenum name, GLuint index) = nullptr;
	GLboolean(*glIsRenderbuffer) (GLuint renderbuffer) = nullptr;
	void(*glBindRenderbuffer) (GLenum target, GLuint renderbuffer) = nullptr;
	void(*glDeleteRenderbuffers) (GLsizei n, const GLuint *renderbuffers) = nullptr;
	void(*glGenRenderbuffers) (GLsizei n, GLuint *renderbuffers) = nullptr;
	void(*glRenderbufferStorage) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height) = nullptr;
	void(*glGetRenderbufferParameteriv) (GLenum target, GLenum pname, GLint *params) = nullptr;
	GLboolean(*glIsFramebuffer) (GLuint framebuffer) = nullptr;
	void(*glBindFramebuffer) (GLenum target, GLuint framebuffer) = nullptr;
	void(*glDeleteFramebuffers) (GLsizei n, const GLuint *framebuffers) = nullptr;
	void(*glGenFramebuffers) (GLsizei n, GLuint *framebuffers) = nullptr;
	GLenum(*glCheckFramebufferStatus) (GLenum target) = nullptr;
	void(*glFramebufferTexture1D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) = nullptr;
	void(*glFramebufferTexture2D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) = nullptr;
	void(*glFramebufferTexture3D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) = nullptr;
	void(*glFramebufferRenderbuffer) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) = nullptr;
	void(*glGetFramebufferAttachmentParameteriv) (GLenum target, GLenum attachment, GLenum pname, GLint *params) = nullptr;
	void(*glGenerateMipmap) (GLenum target) = nullptr;
	void(*glBlitFramebuffer) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) = nullptr;
	void(*glRenderbufferStorageMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) = nullptr;
	void(*glFramebufferTextureLayer) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) = nullptr;
	void *(*glMapBufferRange) (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) = nullptr;
	void(*glFlushMappedBufferRange) (GLenum target, GLintptr offset, GLsizeiptr length) = nullptr;
	void(*glBindVertexArray) (GLuint array) = nullptr;
	void(*glDeleteVertexArrays) (GLsizei n, const GLuint *arrays) = nullptr;
	void(*glGenVertexArrays) (GLsizei n, GLuint *arrays) = nullptr;
	GLboolean(*glIsVertexArray) (GLuint array) = nullptr;
	enum openGL3_0
	{
		GL_COMPARE_REF_TO_TEXTURE =								0x884e,
		GL_CLIP_DISTANCE0 =										0x3000,
		GL_CLIP_DISTANCE1 =										0x3001,
		GL_CLIP_DISTANCE2 =										0x3002,
		GL_CLIP_DISTANCE3 =										0x3003,
		GL_CLIP_DISTANCE4 =										0x3004,
		GL_CLIP_DISTANCE5 =										0x3005,
		GL_CLIP_DISTANCE6 =										0x3006,
		GL_CLIP_DISTANCE7 =										0x3007,
		GL_MAX_CLIP_DISTANCES =									0x0d32,
		GL_MAJOR_VERSION =										0x821b,
		GL_MINOR_VERSION =										0x821c,
		GL_NUM_EXTENSIONS =										0x821d,
		GL_CONTEXT_FLAGS =										0x821e,
		GL_COMPRESSED_RED =										0x8225,
		GL_COMPRESSED_RG =										0x8226,
		GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT =				0x00000001,
		GL_RGBA32F =											0x8814,
		GL_RGB32F =												0x8815,
		GL_RGBA16F =											0x881a,
		GL_RGB16F =												0x881b,
		GL_VERTEX_ATTRIB_ARRAY_INTEGER =						0x88fd,
		GL_MAX_ARRAY_TEXTURE_LAYERS =							0x88ff,
		GL_MIN_PROGRAM_TEXEL_OFFSET =							0x8904,
		GL_MAX_PROGRAM_TEXEL_OFFSET =							0x8905,
		GL_CLAMP_READ_COLOR =									0x891c,
		GL_FIXED_ONLY =											0x891d,
		GL_MAX_VARYING_COMPONENTS =								0x8b4b,
		GL_TEXTURE_1D_ARRAY =									0x8c18,
		GL_PROXY_TEXTURE_1D_ARRAY =								0x8c19,
		GL_TEXTURE_2D_ARRAY =									0x8c1a,
		GL_PROXY_TEXTURE_2D_ARRAY =								0x8c1b,
		GL_TEXTURE_BINDING_1D_ARRAY =							0x8c1c,
		GL_TEXTURE_BINDING_2D_ARRAY =							0x8c1d,
		GL_R11F_G11F_B10F =										0x8c3a,
		GL_UNSIGNED_INT_10F_11F_11F_REV =						0x8c3b,
		GL_RGB9_E5 =											0x8c3d,
		GL_UNSIGNED_INT_5_9_9_9_REV =							0x8c3e,
		GL_TEXTURE_SHARED_SIZE =								0x8c3f,
		GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH =				0x8c76,
		GL_TRANSFORM_FEEDBACK_BUFFER_MODE =						0x8c7f,
		GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS =			0x8c80,
		GL_TRANSFORM_FEEDBACK_VARYINGS =						0x8c83,
		GL_TRANSFORM_FEEDBACK_BUFFER_START =					0x8c84,
		GL_TRANSFORM_FEEDBACK_BUFFER_SIZE =						0x8c85,
		GL_PRIMITIVES_GENERATED =								0x8c87,
		GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN =				0x8c88,
		GL_RASTERIZER_DISCARD =									0x8c89,
		GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS =		0x8c8a,
		GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS =			0x8c8b,
		GL_INTERLEAVED_ATTRIBS =								0x8c8c,
		GL_SEPARATE_ATTRIBS =									0x8c8d,
		GL_TRANSFORM_FEEDBACK_BUFFER =							0x8c8e,
		GL_TRANSFORM_FEEDBACK_BUFFER_BINDING =					0x8c8f,
		GL_RGBA32UI =											0x8d70,
		GL_RGB32UI =											0x8d71,
		GL_RGBA16UI =											0x8d76,
		GL_RGB16UI =											0x8d77,
		GL_RGBA8UI =											0x8d7c,
		GL_RGB8UI =												0x8d7d,
		GL_RGBA32I =											0x8d82,
		GL_RGB32I =												0x8d83,
		GL_RGBA16I =											0x8d88,
		GL_RGB16I =												0x8d89,
		GL_RGBA8I =												0x8d8e,
		GL_RGB8I =												0x8d8f,
		GL_RED_INTEGER =										0x8d94,
		GL_GREEN_INTEGER =										0x8d95,
		GL_BLUE_INTEGER =										0x8d96,
		GL_RGB_INTEGER =										0x8d98,
		GL_RGBA_INTEGER =										0x8d99,
		GL_BGR_INTEGER =										0x8d9a,
		GL_BGRA_INTEGER =										0x8d9b,
		GL_SAMPLER_1D_ARRAY =									0x8dc0,
		GL_SAMPLER_2D_ARRAY =									0x8dc1,
		GL_SAMPLER_1D_ARRAY_SHADOW =							0x8dc3,
		GL_SAMPLER_2D_ARRAY_SHADOW =							0x8dc4,
		GL_SAMPLER_CUBE_SHADOW =								0x8dc5,
		GL_UNSIGNED_INT_VEC2 =									0x8dc6,
		GL_UNSIGNED_INT_VEC3 =									0x8dc7,
		GL_UNSIGNED_INT_VEC4 =									0x8dc8,
		GL_INT_SAMPLER_1D =										0x8dc9,
		GL_INT_SAMPLER_2D =										0x8dca,
		GL_INT_SAMPLER_3D =										0x8dcb,
		GL_INT_SAMPLER_CUBE =									0x8dcc,
		GL_INT_SAMPLER_1D_ARRAY =								0x8dce,
		GL_INT_SAMPLER_2D_ARRAY =								0x8dcf,
		GL_UNSIGNED_INT_SAMPLER_1D =							0x8dd1,
		GL_UNSIGNED_INT_SAMPLER_2D =							0x8dd2,
		GL_UNSIGNED_INT_SAMPLER_3D =							0x8dd3,
		GL_UNSIGNED_INT_SAMPLER_CUBE =							0x8dd4,
		GL_UNSIGNED_INT_SAMPLER_1D_ARRAY =						0x8dd6,
		GL_UNSIGNED_INT_SAMPLER_2D_ARRAY =						0x8dd7,
		GL_QUERY_WAIT =											0x8e13,
		GL_QUERY_NO_WAIT =										0x8e14,
		GL_QUERY_BY_REGION_WAIT =								0x8e15,
		GL_QUERY_BY_REGION_NO_WAIT =							0x8e16,
		GL_BUFFER_ACCESS_FLAGS =								0x911f,
		GL_BUFFER_MAP_LENGTH =									0x9120,
		GL_BUFFER_MAP_OFFSET =									0x9121,
		GL_DEPTH_COMPONENT32F =									0x8cac,
		GL_DEPTH32F_STENCIL8 =									0x8cad,
		GL_FLOAT_32_UNSIGNED_INT_24_8_REV =						0x8dad,
		GL_INVALID_FRAMEBUFFER_OPERATION =						0x0506,
		GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING =				0x8210,
		GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE =				0x8211,
		GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE =					0x8212,
		GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE =					0x8213,
		GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE =					0x8214,
		GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE =					0x8215,
		GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE =					0x8216,
		GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE =				0x8217,
		GL_FRAMEBUFFER_DEFAULT =								0x8218,
		GL_FRAMEBUFFER_UNDEFINED =								0x8219,
		GL_DEPTH_STENCIL_ATTACHMENT =							0x821a,
		GL_MAX_RENDERBUFFER_SIZE =								0x84e8,
		GL_DEPTH_STENCIL =										0x84f9,
		GL_UNSIGNED_INT_24_8 =									0x84fa,
		GL_DEPTH24_STENCIL8 =									0x88f0,
		GL_TEXTURE_STENCIL_SIZE =								0x88f1,
		GL_TEXTURE_RED_TYPE =									0x8c10,
		GL_TEXTURE_GREEN_TYPE =									0x8c11,
		GL_TEXTURE_BLUE_TYPE =									0x8c12,
		GL_TEXTURE_ALPHA_TYPE =									0x8c13,
		GL_TEXTURE_DEPTH_TYPE =									0x8c16,
		GL_UNSIGNED_NORMALIZED =								0x8c17,
		GL_FRAMEBUFFER_BINDING =								0x8ca6,
		GL_DRAW_FRAMEBUFFER_BINDING =							0x8ca6,
		GL_RENDERBUFFER_BINDING =								0x8ca7,
		GL_READ_FRAMEBUFFER =									0x8ca8,
		GL_DRAW_FRAMEBUFFER =									0x8ca9,
		GL_READ_FRAMEBUFFER_BINDING =							0x8caa,
		GL_RENDERBUFFER_SAMPLES =								0x8cab,
		GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE =					0x8cd0,
		GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME =					0x8cd1,
		GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL =				0x8cd2,
		GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE =		0x8cd3,
		GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER =				0x8cd4,
		GL_FRAMEBUFFER_COMPLETE =								0x8cd5,
		GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT =					0x8cd6,
		GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT =			0x8cd7,
		GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER =					0x8cdb,
		GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER =					0x8cdc,
		GL_FRAMEBUFFER_UNSUPPORTED =							0x8cdd,
		GL_MAX_COLOR_ATTACHMENTS =								0x8cdf,
		GL_COLOR_ATTACHMENT0 =									0x8ce0,
		GL_COLOR_ATTACHMENT1 =									0x8ce1,
		GL_COLOR_ATTACHMENT2 =									0x8ce2,
		GL_COLOR_ATTACHMENT3 =									0x8ce3,
		GL_COLOR_ATTACHMENT4 =									0x8ce4,
		GL_COLOR_ATTACHMENT5 =									0x8ce5,
		GL_COLOR_ATTACHMENT6 =									0x8ce6,
		GL_COLOR_ATTACHMENT7 =									0x8ce7,
		GL_COLOR_ATTACHMENT8 =									0x8ce8,
		GL_COLOR_ATTACHMENT9 =									0x8ce9,
		GL_COLOR_ATTACHMENT10 =									0x8cea,
		GL_COLOR_ATTACHMENT11 =									0x8ceb,
		GL_COLOR_ATTACHMENT12 =									0x8cec,
		GL_COLOR_ATTACHMENT13 =									0x8ced,
		GL_COLOR_ATTACHMENT14 =									0x8cee,
		GL_COLOR_ATTACHMENT15 =									0x8cef,
		GL_DEPTH_ATTACHMENT =									0x8d00,
		GL_STENCIL_ATTACHMENT =									0x8d20,
		GL_FRAMEBUFFER =										0x8d40,
		GL_RENDERBUFFER =										0x8d41,
		GL_RENDERBUFFER_WIDTH =									0x8d42,
		GL_RENDERBUFFER_HEIGHT =								0x8d43,
		GL_RENDERBUFFER_INTERNAL_FORMAT =						0x8d44,
		GL_STENCIL_INDEX1 =										0x8d46,
		GL_STENCIL_INDEX4 =										0x8d47,
		GL_STENCIL_INDEX8 =										0x8d48,
		GL_STENCIL_INDEX16 =									0x8d49,
		GL_RENDERBUFFER_RED_SIZE =								0x8d50,
		GL_RENDERBUFFER_GREEN_SIZE =							0x8d51,
		GL_RENDERBUFFER_BLUE_SIZE =								0x8d52,
		GL_RENDERBUFFER_ALPHA_SIZE =							0x8d53,
		GL_RENDERBUFFER_DEPTH_SIZE =							0x8d54,
		GL_RENDERBUFFER_STENCIL_SIZE =							0x8d55,
		GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE =					0x8d56,
		GL_MAX_SAMPLES =										0x8d57,
		GL_INDEX =												0x8222,
		GL_TEXTURE_LUMINANCE_TYPE =								0x8c14,
		GL_TEXTURE_INTENSITY_TYPE =								0x8c15,
		GL_FRAMEBUFFER_SRGB =									0x8db9,
		GL_HALF_FLOAT =											0x140b,
		GL_MAP_READ_BIT =										0x0001,
		GL_MAP_WRITE_BIT =										0x0002,
		GL_MAP_INVALIDATE_RANGE_BIT =							0x0004,
		GL_MAP_INVALIDATE_BUFFER_BIT =							0x0008,
		GL_MAP_FLUSH_EXPLICIT_BIT =								0x0010,
		GL_MAP_UNSYNCHRONIZED_BIT =								0x0020,
		GL_COMPRESSED_RED_RGTC1 =								0x8dbb,
		GL_COMPRESSED_SIGNED_RED_RGTC1 =						0x8dbc,
		GL_COMPRESSED_RG_RGTC2 =								0x8dbd,
		GL_COMPRESSED_SIGNED_RG_RGTC2 =							0x8dbe,
		GL_RG =													0x8227,
		GL_RG_INTEGER =											0x8228,
		GL_R8 =													0x8229,
		GL_R16 =												0x822a,
		GL_RG8 =												0x822b,
		GL_RG16 =												0x822c,
		GL_R16F =												0x822d,
		GL_R32F =												0x822e,
		GL_RG16F =												0x822f,
		GL_RG32F =												0x8230,
		GL_R8I =												0x8231,
		GL_R8UI =												0x8232,
		GL_R16I =												0x8233,
		GL_R16UI =												0x8234,
		GL_R32I =												0x8235,
		GL_R32UI =												0x8236,
		GL_RG8I =												0x8237,
		GL_RG8UI =												0x8238,
		GL_RG16I =												0x8239,
		GL_RG16UI =												0x823a,
		GL_RG32I =												0x823b,
		GL_RG32UI =												0x823c,
		GL_VERTEX_ARRAY_BINDING =								0x85b5,
		GL_CLAMP_VERTEX_COLOR =									0x891a,
		GL_CLAMP_FRAGMENT_COLOR =								0x891b,
		GL_ALPHA_INTEGER =										0x8d97,
	};

	//OpenGL 3.1 Extensions
	void(*glDrawArraysInstanced) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount) = nullptr;
	void(*glDrawElementsInstanced) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount) = nullptr;
	void(*glTexBuffer) (GLenum target, GLenum internalformat, GLuint buffer) = nullptr;
	void(*glPrimitiveRestartIndex) (GLuint index) = nullptr;
	void(*glCopyBufferSubData) (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) = nullptr;
	void(*glGetUniformIndices) (GLuint program, GLsizei uniformCount, const GLchar** uniformNames, GLuint *uniformIndices) = nullptr;
	void(*glGetActiveUniformsiv) (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params) = nullptr;
	void(*glGetActiveUniformName) (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName) = nullptr;
	GLuint(*glGetUniformBlockIndex) (GLuint program, const GLchar *uniformBlockName) = nullptr;
	void(*glGetActiveUniformBlockiv) (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params) = nullptr;
	void(*glGetActiveUniformBlockName) (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName) = nullptr;
	void(*glUniformBlockBinding) (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) = nullptr;
	enum openGL3_1
	{
		GL_SAMPLER_2D_RECT =									0x8b63,
		GL_SAMPLER_2D_RECT_SHADOW =								0x8b64,
		GL_SAMPLER_BUFFER =										0x8dc2,
		GL_INT_SAMPLER_2D_RECT =								0x8dcd,
		GL_INT_SAMPLER_BUFFER =									0x8dd0,
		GL_UNSIGNED_INT_SAMPLER_2D_RECT =						0x8dd5,
		GL_UNSIGNED_INT_SAMPLER_BUFFER =						0x8dd8,
		GL_TEXTURE_BUFFER =										0x8c2a,
		GL_MAX_TEXTURE_BUFFER_SIZE =							0x8c2b,
		GL_TEXTURE_BINDING_BUFFER =								0x8c2c,
		GL_TEXTURE_BUFFER_DATA_STORE_BINDING =					0x8c2d,
		GL_TEXTURE_RECTANGLE =									0x84f5,
		GL_TEXTURE_BINDING_RECTANGLE =							0x84f6,
		GL_PROXY_TEXTURE_RECTANGLE =							0x84f7,
		GL_MAX_RECTANGLE_TEXTURE_SIZE =							0x84f8,
		GL_R8_SNORM =											0x8f94,
		GL_RG8_SNORM =											0x8f95,
		GL_RGB8_SNORM =											0x8f96,
		GL_RGBA8_SNORM =										0x8f97,
		GL_R16_SNORM =											0x8f98,
		GL_RG16_SNORM =											0x8f99,
		GL_RGB16_SNORM =										0x8f9a,
		GL_RGBA16_SNORM =										0x8f9b,
		GL_SIGNED_NORMALIZED =									0x8f9c,
		GL_PRIMITIVE_RESTART =									0x8f9d,
		GL_PRIMITIVE_RESTART_INDEX =							0x8f9e,
		GL_COPY_READ_BUFFER =									0x8f36,
		GL_COPY_WRITE_BUFFER =									0x8f37,
		GL_UNIFORM_BUFFER =										0x8a11,
		GL_UNIFORM_BUFFER_BINDING =								0x8a28,
		GL_UNIFORM_BUFFER_START =								0x8a29,
		GL_UNIFORM_BUFFER_SIZE =								0x8a2a,
		GL_MAX_VERTEX_UNIFORM_BLOCKS =							0x8a2b,
		GL_MAX_FRAGMENT_UNIFORM_BLOCKS =						0x8a2d,
		GL_MAX_COMBINED_UNIFORM_BLOCKS =						0x8a2e,
		GL_MAX_UNIFORM_BUFFER_BINDINGS =						0x8a2f,
		GL_MAX_UNIFORM_BLOCK_SIZE =								0x8a30,
		GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS =				0x8a31,
		GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS =			0x8a33,
		GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT =					0x8a34,
		GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH =				0x8a35,
		GL_ACTIVE_UNIFORM_BLOCKS =								0x8a36,
		GL_UNIFORM_TYPE =										0x8a37,
		GL_UNIFORM_SIZE =										0x8a38,
		GL_UNIFORM_NAME_LENGTH =								0x8a39,
		GL_UNIFORM_BLOCK_INDEX =								0x8a3a,
		GL_UNIFORM_OFFSET =										0x8a3b,
		GL_UNIFORM_ARRAY_STRIDE =								0x8a3c,
		GL_UNIFORM_MATRIX_STRIDE =								0x8a3d,
		GL_UNIFORM_IS_ROW_MAJOR =								0x8a3e,
		GL_UNIFORM_BLOCK_BINDING =								0x8a3f,
		GL_UNIFORM_BLOCK_DATA_SIZE =							0x8a40,
		GL_UNIFORM_BLOCK_NAME_LENGTH =							0x8a41,
		GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS =						0x8a42,
		GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES =				0x8a43,
		GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER =			0x8a44,
		GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER =		0x8a46,
		GL_INVALID_INDEX =										0xffffffffu
	};

	//OpenGL 3.2 Extensions
	typedef struct __GLsync* GLsync;
	typedef uint64_t GLuint64;
	typedef int64_t GLint64;
	void(*glDrawElementsBaseVertex) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex) = nullptr;
	void(*glDrawRangeElementsBaseVertex) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex) = nullptr;
	void(*glDrawElementsInstancedBaseVertex) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex) = nullptr;
	void(*glMultiDrawElementsBaseVertex) (GLenum mode, const GLsizei *count, GLenum type, const void** indices, GLsizei drawcount, const GLint *basevertex) = nullptr;
	void(*glProvokingVertex) (GLenum mode) = nullptr;
	GLsync(*glFenceSync) (GLenum condition, GLbitfield flags) = nullptr;
	GLboolean(*glIsSync) (GLsync sync) = nullptr;
	void(*glDeleteSync) (GLsync sync) = nullptr;
	GLenum(*glClientWaitSync) (GLsync sync, GLbitfield flags, GLuint64 timeout) = nullptr;
	void(*glWaitSync) (GLsync sync, GLbitfield flags, GLuint64 timeout) = nullptr;
	void(*glGetInteger64v) (GLenum pname, GLint64 *params) = nullptr;
	void(*glGetSynciv) (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values) = nullptr;
	void(*glGetInteger64i_v) (GLenum target, GLuint index, GLint64 *data) = nullptr;
	void(*glGetBufferParameteri64v) (GLenum target, GLenum pname, GLint64 *params) = nullptr;
	void(*glFramebufferTexture) (GLenum target, GLenum attachment, GLuint texture, GLint level) = nullptr;
	void(*glTexImage2DMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) = nullptr;
	void(*glTexImage3DMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) = nullptr;
	void(*glGetMultisamplefv) (GLenum pname, GLuint index, GLfloat *val) = nullptr;
	void(*glSampleMaski) (GLuint index, GLbitfield mask) = nullptr;
	enum openGL3_2
	{
		GL_CONTEXT_CORE_PROFILE_BIT =						0x00000001,
		GL_CONTEXT_COMPATIBILITY_PROFILE_BIT =				0x00000002,
		GL_LINES_ADJACENCY =								0x000a,
		GL_LINE_STRIP_ADJACENCY =							0x000b,
		GL_TRIANGLES_ADJACENCY =							0x000c,
		GL_TRIANGLE_STRIP_ADJACENCY =						0x000d,
		GL_PROGRAM_POINT_SIZE =								0x8642,
		GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS =				0x8c29,
		GL_FRAMEBUFFER_ATTACHMENT_LAYERED =					0x8da7,
		GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS =			0x8da8,
		GL_GEOMETRY_SHADER =								0x8dd9,
		GL_GEOMETRY_VERTICES_OUT =							0x8916,
		GL_GEOMETRY_INPUT_TYPE =							0x8917,
		GL_GEOMETRY_OUTPUT_TYPE =							0x8918,
		GL_MAX_GEOMETRY_UNIFORM_COMPONENTS =				0x8ddf,
		GL_MAX_GEOMETRY_OUTPUT_VERTICES =					0x8de0,
		GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS =			0x8de1,
		GL_MAX_VERTEX_OUTPUT_COMPONENTS =					0x9122,
		GL_MAX_GEOMETRY_INPUT_COMPONENTS =					0x9123,
		GL_MAX_GEOMETRY_OUTPUT_COMPONENTS =					0x9124,
		GL_MAX_FRAGMENT_INPUT_COMPONENTS =					0x9125,
		GL_CONTEXT_PROFILE_MASK =							0x9126,
		GL_DEPTH_CLAMP =									0x864f,
		GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION =		0x8e4c,
		GL_FIRST_VERTEX_CONVENTION =						0x8e4d,
		GL_LAST_VERTEX_CONVENTION =							0x8e4e,
		GL_PROVOKING_VERTEX =								0x8e4f,
		GL_TEXTURE_CUBE_MAP_SEAMLESS =						0x884f,
		GL_MAX_SERVER_WAIT_TIMEOUT =						0x9111,
		GL_OBJECT_TYPE =									0x9112,
		GL_SYNC_CONDITION =									0x9113,
		GL_SYNC_STATUS =									0x9114,
		GL_SYNC_FLAGS =										0x9115,
		GL_SYNC_FENCE =										0x9116,
		GL_SYNC_GPU_COMMANDS_COMPLETE =						0x9117,
		GL_UNSIGNALED =										0x9118,
		GL_SIGNALED =										0x9119,
		GL_ALREADY_SIGNALED =								0x911a,
		GL_TIMEOUT_EXPIRED =								0x911b,
		GL_CONDITION_SATISFIED =							0x911c,
		GL_WAIT_FAILED =									0x911d,
		GL_TIMEOUT_IGNORED =								0xffffffffffffffffull,
		GL_SYNC_FLUSH_COMMANDS_BIT =						0x00000001,
		GL_SAMPLE_POSITION =								0x8e50,
		GL_SAMPLE_MASK =									0x8e51,
		GL_SAMPLE_MASK_VALUE =								0x8e52,
		GL_MAX_SAMPLE_MASK_WORDS =							0x8e59,
		GL_TEXTURE_2D_MULTISAMPLE =							0x9100,
		GL_PROXY_TEXTURE_2D_MULTISAMPLE =					0x9101,
		GL_TEXTURE_2D_MULTISAMPLE_ARRAY =					0x9102,
		GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY =				0x9103,
		GL_TEXTURE_BINDING_2D_MULTISAMPLE =					0x9104,
		GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY =			0x9105,
		GL_TEXTURE_SAMPLES =								0x9106,
		GL_TEXTURE_FIXED_SAMPLE_LOCATIONS =					0x9107,
		GL_SAMPLER_2D_MULTISAMPLE =							0x9108,
		GL_INT_SAMPLER_2D_MULTISAMPLE =						0x9109,
		GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE =			0x910a,
		GL_SAMPLER_2D_MULTISAMPLE_ARRAY =					0x910b,
		GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY =				0x910c,
		GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY =		0x910d,
		GL_MAX_COLOR_TEXTURE_SAMPLES =						0x910e,
		GL_MAX_DEPTH_TEXTURE_SAMPLES =						0x910f,
		GL_MAX_INTEGER_SAMPLES =							0x9110,
	};

	//OpenGL 3.3 Extensions
	void(*glBindFragDataLocationIndexed) (GLuint program, GLuint colorNumber, GLuint index, const GLchar *name) = nullptr;
	GLint(*glGetFragDataIndex) (GLuint program, const GLchar *name) = nullptr;
	void(*glGenSamplers) (GLsizei count, GLuint *samplers) = nullptr;
	void(*glDeleteSamplers) (GLsizei count, const GLuint *samplers) = nullptr;
	GLboolean(*glIsSampler) (GLuint sampler) = nullptr;
	void(*glBindSampler) (GLuint unit, GLuint sampler) = nullptr;
	void(*glSamplerParameteri) (GLuint sampler, GLenum pname, GLint param) = nullptr;
	void(*glSamplerParameteriv) (GLuint sampler, GLenum pname, const GLint *param) = nullptr;
	void(*glSamplerParameterf) (GLuint sampler, GLenum pname, GLfloat param) = nullptr;
	void(*glSamplerParameterfv) (GLuint sampler, GLenum pname, const GLfloat *param) = nullptr;
	void(*glSamplerParameterIiv) (GLuint sampler, GLenum pname, const GLint *param) = nullptr;
	void(*glSamplerParameterIuiv) (GLuint sampler, GLenum pname, const GLuint *param) = nullptr;
	void(*glGetSamplerParameteriv) (GLuint sampler, GLenum pname, GLint *params) = nullptr;
	void(*glGetSamplerParameterIiv) (GLuint sampler, GLenum pname, GLint *params) = nullptr;
	void(*glGetSamplerParameterfv) (GLuint sampler, GLenum pname, GLfloat *params) = nullptr;
	void(*glGetSamplerParameterIuiv) (GLuint sampler, GLenum pname, GLuint *params) = nullptr;
	void(*glQueryCounter) (GLuint id, GLenum target) = nullptr;
	void(*glGetQueryObjecti64v) (GLuint id, GLenum pname, GLint64 *params) = nullptr;
	void(*glGetQueryObjectui64v) (GLuint id, GLenum pname, GLuint64 *params) = nullptr;
	void(*glVertexAttribDivisor) (GLuint index, GLuint divisor) = nullptr;
	void(*glVertexAttribP1ui) (GLuint index, GLenum type, GLboolean normalized, GLuint value) = nullptr;
	void(*glVertexAttribP1uiv) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value) = nullptr;
	void(*glVertexAttribP2ui) (GLuint index, GLenum type, GLboolean normalized, GLuint value) = nullptr;
	void(*glVertexAttribP2uiv) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value) = nullptr;
	void(*glVertexAttribP3ui) (GLuint index, GLenum type, GLboolean normalized, GLuint value) = nullptr;
	void(*glVertexAttribP3uiv) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value) = nullptr;
	void(*glVertexAttribP4ui) (GLuint index, GLenum type, GLboolean normalized, GLuint value) = nullptr;
	void(*glVertexAttribP4uiv) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value) = nullptr;
	void(*glVertexP2ui) (GLenum type, GLuint value) = nullptr;
	void(*glVertexP2uiv) (GLenum type, const GLuint *value) = nullptr;
	void(*glVertexP3ui) (GLenum type, GLuint value) = nullptr;
	void(*glVertexP3uiv) (GLenum type, const GLuint *value) = nullptr;
	void(*glVertexP4ui) (GLenum type, GLuint value) = nullptr;
	void(*glVertexP4uiv) (GLenum type, const GLuint *value) = nullptr;
	void(*glTexCoordP1ui) (GLenum type, GLuint coords) = nullptr;
	void(*glTexCoordP1uiv) (GLenum type, const GLuint *coords) = nullptr;
	void(*glTexCoordP2ui) (GLenum type, GLuint coords) = nullptr;
	void(*glTexCoordP2uiv) (GLenum type, const GLuint *coords) = nullptr;
	void(*glTexCoordP3ui) (GLenum type, GLuint coords) = nullptr;
	void(*glTexCoordP3uiv) (GLenum type, const GLuint *coords) = nullptr;
	void(*glTexCoordP4ui) (GLenum type, GLuint coords) = nullptr;
	void(*glTexCoordP4uiv) (GLenum type, const GLuint *coords) = nullptr;
	void(*glMultiTexCoordP1ui) (GLenum texture, GLenum type, GLuint coords) = nullptr;
	void(*glMultiTexCoordP1uiv) (GLenum texture, GLenum type, const GLuint *coords) = nullptr;
	void(*glMultiTexCoordP2ui) (GLenum texture, GLenum type, GLuint coords) = nullptr;
	void(*glMultiTexCoordP2uiv) (GLenum texture, GLenum type, const GLuint *coords) = nullptr;
	void(*glMultiTexCoordP3ui) (GLenum texture, GLenum type, GLuint coords) = nullptr;
	void(*glMultiTexCoordP3uiv) (GLenum texture, GLenum type, const GLuint *coords) = nullptr;
	void(*glMultiTexCoordP4ui) (GLenum texture, GLenum type, GLuint coords) = nullptr;
	void(*glMultiTexCoordP4uiv) (GLenum texture, GLenum type, const GLuint *coords) = nullptr;
	void(*glNormalP3ui) (GLenum type, GLuint coords) = nullptr;
	void(*glNormalP3uiv) (GLenum type, const GLuint *coords) = nullptr;
	void(*glColorP3ui) (GLenum type, GLuint color) = nullptr;
	void(*glColorP3uiv) (GLenum type, const GLuint *color) = nullptr;
	void(*glColorP4ui) (GLenum type, GLuint color) = nullptr;
	void(*glColorP4uiv) (GLenum type, const GLuint *color) = nullptr;
	void(*glSecondaryColorP3ui) (GLenum type, GLuint color) = nullptr;
	void(*glSecondaryColorP3uiv) (GLenum type, const GLuint *color) = nullptr;
	enum openGL3_3
	{
		GL_VERTEX_ATTRIB_ARRAY_DIVISOR =		0x88fe,
		GL_SRC1_COLOR =							0x88f9,
		GL_ONE_MINUS_SRC1_COLOR =				0x88fa,
		GL_ONE_MINUS_SRC1_ALPHA =				0x88fb,
		GL_MAX_DUAL_SOURCE_DRAW_BUFFERS =		0x88fc,
		GL_ANY_SAMPLES_PASSED =					0x8c2f,
		GL_SAMPLER_BINDING =					0x8919,
		GL_RGB10_A2UI =							0x906f,
		GL_TEXTURE_SWIZZLE_R =					0x8e42,
		GL_TEXTURE_SWIZZLE_G =					0x8e43,
		GL_TEXTURE_SWIZZLE_B =					0x8e44,
		GL_TEXTURE_SWIZZLE_A =					0x8e45,
		GL_TEXTURE_SWIZZLE_RGBA =				0x8e46,
		GL_TIME_ELAPSED =						0x88bf,
		GL_TIMESTAMP =							0x8e28,
		GL_INT_2_10_10_10_REV =					0x8d9f,
	};

	//OpenGL 4.0 Extensions
	void(*glMinSampleShading) (GLfloat value) = nullptr;
	void(*glBlendEquationi) (GLuint buf, GLenum mode) = nullptr;
	void(*glBlendEquationSeparatei) (GLuint buf, GLenum modeRGB, GLenum modeAlpha) = nullptr;
	void(*glBlendFunci) (GLuint buf, GLenum src, GLenum dst) = nullptr;
	void(*glBlendFuncSeparatei) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) = nullptr;
	void(*glDrawArraysIndirect) (GLenum mode, const void* indirect) = nullptr;
	void(*glDrawElementsIndirect) (GLenum mode, GLenum type, const void* indirect) = nullptr;
	void(*glUniform1d) (GLint location, GLdouble x) = nullptr;
	void(*glUniform2d) (GLint location, GLdouble x, GLdouble y) = nullptr;
	void(*glUniform3d) (GLint location, GLdouble x, GLdouble y, GLdouble z) = nullptr;
	void(*glUniform4d) (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) = nullptr;
	void(*glUniform1dv) (GLint location, GLsizei count, const GLdouble *value) = nullptr;
	void(*glUniform2dv) (GLint location, GLsizei count, const GLdouble *value) = nullptr;
	void(*glUniform3dv) (GLint location, GLsizei count, const GLdouble *value) = nullptr;
	void(*glUniform4dv) (GLint location, GLsizei count, const GLdouble *value) = nullptr;
	void(*glUniformMatrix2dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) = nullptr;
	void(*glUniformMatrix3dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) = nullptr;
	void(*glUniformMatrix4dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) = nullptr;
	void(*glUniformMatrix2x3dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) = nullptr;
	void(*glUniformMatrix2x4dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) = nullptr;
	void(*glUniformMatrix3x2dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) = nullptr;
	void(*glUniformMatrix3x4dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) = nullptr;
	void(*glUniformMatrix4x2dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) = nullptr;
	void(*glUniformMatrix4x3dv) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) = nullptr;
	void(*glGetUniformdv) (GLuint program, GLint location, GLdouble *params) = nullptr;
	GLint(*glGetSubroutineUniformLocation) (GLuint program, GLenum shadertype, const GLchar *name) = nullptr;
	GLuint(*glGetSubroutineIndex) (GLuint program, GLenum shadertype, const GLchar *name) = nullptr;
	void(*glGetActiveSubroutineUniformiv) (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values) = nullptr;
	void(*glGetActiveSubroutineUniformName) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name) = nullptr;
	void(*glGetActiveSubroutineName) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name) = nullptr;
	void(*glUniformSubroutinesuiv) (GLenum shadertype, GLsizei count, const GLuint *indices) = nullptr;
	void(*glGetUniformSubroutineuiv) (GLenum shadertype, GLint location, GLuint *params) = nullptr;
	void(*glGetProgramStageiv) (GLuint program, GLenum shadertype, GLenum pname, GLint *values) = nullptr;
	void(*glPatchParameteri) (GLenum pname, GLint value) = nullptr;
	void(*glPatchParameterfv) (GLenum pname, const GLfloat *values) = nullptr;
	void(*glBindTransformFeedback) (GLenum target, GLuint id) = nullptr;
	void(*glDeleteTransformFeedbacks) (GLsizei n, const GLuint *ids) = nullptr;
	void(*glGenTransformFeedbacks) (GLsizei n, GLuint *ids) = nullptr;
	GLboolean(*glIsTransformFeedback) (GLuint id) = nullptr;
	void(*glPauseTransformFeedback) (void) = nullptr;
	void(*glResumeTransformFeedback) (void) = nullptr;
	void(*glDrawTransformFeedback) (GLenum mode, GLuint id) = nullptr;
	void(*glDrawTransformFeedbackStream) (GLenum mode, GLuint id, GLuint stream) = nullptr;
	void(*glBeginQueryIndexed) (GLenum target, GLuint index, GLuint id) = nullptr;
	void(*glEndQueryIndexed) (GLenum target, GLuint index) = nullptr;
	void(*glGetQueryIndexediv) (GLenum target, GLuint index, GLenum pname, GLint *params) = nullptr;
	enum openGL4_0
	{
		GL_SAMPLE_SHADING =												0x8c36,
		GL_MIN_SAMPLE_SHADING_VALUE =									0x8c37,
		GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET =							0x8e5e,
		GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET =							0x8e5f,
		GL_TEXTURE_CUBE_MAP_ARRAY =										0x9009,
		GL_TEXTURE_BINDING_CUBE_MAP_ARRAY =								0x900a,
		GL_PROXY_TEXTURE_CUBE_MAP_ARRAY =								0x900b,
		GL_SAMPLER_CUBE_MAP_ARRAY =										0x900c,
		GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW =								0x900d,
		GL_INT_SAMPLER_CUBE_MAP_ARRAY =									0x900e,
		GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY =						0x900f,
		GL_DRAW_INDIRECT_BUFFER =										0x8f3f,
		GL_DRAW_INDIRECT_BUFFER_BINDING =								0x8f43,
		GL_GEOMETRY_SHADER_INVOCATIONS =								0x887f,
		GL_MAX_GEOMETRY_SHADER_INVOCATIONS =							0x8e5a,
		GL_MIN_FRAGMENT_INTERPOLATION_OFFSET =							0x8e5b,
		GL_MAX_FRAGMENT_INTERPOLATION_OFFSET =							0x8e5c,
		GL_FRAGMENT_INTERPOLATION_OFFSET_BITS =							0x8e5d,
		GL_MAX_VERTEX_STREAMS =											0x8e71,
		GL_DOUBLE_VEC2 =												0x8ffc,
		GL_DOUBLE_VEC3 =												0x8ffd,
		GL_DOUBLE_VEC4 =												0x8ffe,
		GL_DOUBLE_MAT2 =												0x8f46,
		GL_DOUBLE_MAT3 =												0x8f47,
		GL_DOUBLE_MAT4 =												0x8f48,
		GL_DOUBLE_MAT2X3 =												0x8f49,
		GL_DOUBLE_MAT2X4 =												0x8f4a,
		GL_DOUBLE_MAT3X2 =												0x8f4b,
		GL_DOUBLE_MAT3X4 =												0x8f4c,
		GL_DOUBLE_MAT4X2 =												0x8f4d,
		GL_DOUBLE_MAT4X3 =												0x8f4e,
		GL_ACTIVE_SUBROUTINES =											0x8de5,
		GL_ACTIVE_SUBROUTINE_UNIFORMS =									0x8de6,
		GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS =						0x8e47,
		GL_ACTIVE_SUBROUTINE_MAX_LENGTH =								0x8e48,
		GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH =						0x8e49,
		GL_MAX_SUBROUTINES =											0x8de7,
		GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS =							0x8de8,
		GL_NUM_COMPATIBLE_SUBROUTINES =									0x8e4a,
		GL_COMPATIBLE_SUBROUTINES =										0x8e4b,
		GL_PATCHES =													0x000e,
		GL_PATCH_VERTICES =												0x8e72,
		GL_PATCH_DEFAULT_INNER_LEVEL =									0x8e73,
		GL_PATCH_DEFAULT_OUTER_LEVEL =									0x8e74,
		GL_TESS_CONTROL_OUTPUT_VERTICES =								0x8e75,
		GL_TESS_GEN_MODE =												0x8e76,
		GL_TESS_GEN_SPACING =											0x8e77,
		GL_TESS_GEN_VERTEX_ORDER =										0x8e78,
		GL_TESS_GEN_POINT_MODE =										0x8e79,
		GL_ISOLINES =													0x8e7a,
		GL_FRACTIONAL_ODD =												0x8e7b,
		GL_FRACTIONAL_EVEN =											0x8e7c,
		GL_MAX_PATCH_VERTICES =											0x8e7d,
		GL_MAX_TESS_GEN_LEVEL =											0x8e7e,
		GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS =						0x8e7f,
		GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS =						0x8e80,
		GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS =						0x8e81,
		GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS =					0x8e82,
		GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS =							0x8e83,
		GL_MAX_TESS_PATCH_COMPONENTS =									0x8e84,
		GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS =					0x8e85,
		GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS =						0x8e86,
		GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS =							0x8e89,
		GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS =							0x8e8a,
		GL_MAX_TESS_CONTROL_INPUT_COMPONENTS =							0x886c,
		GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS =						0x886d,
		GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS =				0x8e1e,
		GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS =			0x8e1f,
		GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER =			0x84f0,
		GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER =			0x84f1,
		GL_TESS_EVALUATION_SHADER =										0x8e87,
		GL_TESS_CONTROL_SHADER =										0x8e88,
		GL_TRANSFORM_FEEDBACK =											0x8e22,
		GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED =							0x8e23,
		GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE =							0x8e24,
		GL_TRANSFORM_FEEDBACK_BINDING =									0x8e25,
		GL_MAX_TRANSFORM_FEEDBACK_BUFFERS =								0x8e70,
	};

	//OpenGL 4.1 Extensions
	void(*glReleaseShaderCompiler) (void) = nullptr;
	void(*glShaderBinary) (GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length) = nullptr;
	void(*glGetShaderPrecisionFormat) (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision) = nullptr;
	void(*glDepthRangef) (GLfloat n, GLfloat f) = nullptr;
	void(*glClearDepthf) (GLfloat d) = nullptr;
	void(*glGetProgramBinary) (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary) = nullptr;
	void(*glProgramBinary) (GLuint program, GLenum binaryFormat, const void *binary, GLsizei length) = nullptr;
	void(*glProgramParameteri) (GLuint program, GLenum pname, GLint value) = nullptr;
	void(*glUseProgramStages) (GLuint pipeline, GLbitfield stages, GLuint program) = nullptr;
	void(*glActiveShaderProgram) (GLuint pipeline, GLuint program) = nullptr;
	GLuint(*glCreateShaderProgramv) (GLenum type, GLsizei count, const GLchar *const*strings) = nullptr;
	void(*glBindProgramPipeline) (GLuint pipeline) = nullptr;
	void(*glDeleteProgramPipelines) (GLsizei n, const GLuint *pipelines) = nullptr;
	void(*glGenProgramPipelines) (GLsizei n, GLuint *pipelines) = nullptr;
	GLboolean(*glIsProgramPipeline) (GLuint pipeline) = nullptr;
	void(*glGetProgramPipelineiv) (GLuint pipeline, GLenum pname, GLint *params) = nullptr;
	void(*glProgramUniform1i) (GLuint program, GLint location, GLint v0) = nullptr;
	void(*glProgramUniform1iv) (GLuint program, GLint location, GLsizei count, const GLint *value) = nullptr;
	void(*glProgramUniform1f) (GLuint program, GLint location, GLfloat v0) = nullptr;
	void(*glProgramUniform1fv) (GLuint program, GLint location, GLsizei count, const GLfloat *value) = nullptr;
	void(*glProgramUniform1d) (GLuint program, GLint location, GLdouble v0) = nullptr;
	void(*glProgramUniform1dv) (GLuint program, GLint location, GLsizei count, const GLdouble *value) = nullptr;
	void(*glProgramUniform1ui) (GLuint program, GLint location, GLuint v0) = nullptr;
	void(*glProgramUniform1uiv) (GLuint program, GLint location, GLsizei count, const GLuint *value) = nullptr;
	void(*glProgramUniform2i) (GLuint program, GLint location, GLint v0, GLint v1) = nullptr;
	void(*glProgramUniform2iv) (GLuint program, GLint location, GLsizei count, const GLint *value) = nullptr;
	void(*glProgramUniform2f) (GLuint program, GLint location, GLfloat v0, GLfloat v1) = nullptr;
	void(*glProgramUniform2fv) (GLuint program, GLint location, GLsizei count, const GLfloat *value) = nullptr;
	void(*glProgramUniform2d) (GLuint program, GLint location, GLdouble v0, GLdouble v1) = nullptr;
	void(*glProgramUniform2dv) (GLuint program, GLint location, GLsizei count, const GLdouble *value) = nullptr;
	void(*glProgramUniform2ui) (GLuint program, GLint location, GLuint v0, GLuint v1) = nullptr;
	void(*glProgramUniform2uiv) (GLuint program, GLint location, GLsizei count, const GLuint *value) = nullptr;
	void(*glProgramUniform3i) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2) = nullptr;
	void(*glProgramUniform3iv) (GLuint program, GLint location, GLsizei count, const GLint *value) = nullptr;
	void(*glProgramUniform3f) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) = nullptr;
	void(*glProgramUniform3fv) (GLuint program, GLint location, GLsizei count, const GLfloat *value) = nullptr;
	void(*glProgramUniform3d) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2) = nullptr;
	void(*glProgramUniform3dv) (GLuint program, GLint location, GLsizei count, const GLdouble *value) = nullptr;
	void(*glProgramUniform3ui) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) = nullptr;
	void(*glProgramUniform3uiv) (GLuint program, GLint location, GLsizei count, const GLuint *value) = nullptr;
	void(*glProgramUniform4i) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) = nullptr;
	void(*glProgramUniform4iv) (GLuint program, GLint location, GLsizei count, const GLint *value) = nullptr;
	void(*glProgramUniform4f) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) = nullptr;
	void(*glProgramUniform4fv) (GLuint program, GLint location, GLsizei count, const GLfloat *value) = nullptr;
	void(*glProgramUniform4d) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3) = nullptr;
	void(*glProgramUniform4dv) (GLuint program, GLint location, GLsizei count, const GLdouble *value) = nullptr;
	void(*glProgramUniform4ui) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) = nullptr;
	void(*glProgramUniform4uiv) (GLuint program, GLint location, GLsizei count, const GLuint *value) = nullptr;
	void(*glProgramUniformMatrix2fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	void(*glProgramUniformMatrix3fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	void(*glProgramUniformMatrix4fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	void(*glProgramUniformMatrix2dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) = nullptr;
	void(*glProgramUniformMatrix3dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) = nullptr;
	void(*glProgramUniformMatrix4dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) = nullptr;
	void(*glProgramUniformMatrix2x3fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	void(*glProgramUniformMatrix3x2fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	void(*glProgramUniformMatrix2x4fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	void(*glProgramUniformMatrix4x2fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	void(*glProgramUniformMatrix3x4fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	void(*glProgramUniformMatrix4x3fv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	void(*glProgramUniformMatrix2x3dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) = nullptr;
	void(*glProgramUniformMatrix3x2dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) = nullptr;
	void(*glProgramUniformMatrix2x4dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) = nullptr;
	void(*glProgramUniformMatrix4x2dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) = nullptr;
	void(*glProgramUniformMatrix3x4dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) = nullptr;
	void(*glProgramUniformMatrix4x3dv) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) = nullptr;
	void(*glValidateProgramPipeline) (GLuint pipeline) = nullptr;
	void(*glGetProgramPipelineInfoLog) (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog) = nullptr;
	void(*glVertexAttribL1d) (GLuint index, GLdouble x) = nullptr;
	void(*glVertexAttribL2d) (GLuint index, GLdouble x, GLdouble y) = nullptr;
	void(*glVertexAttribL3d) (GLuint index, GLdouble x, GLdouble y, GLdouble z) = nullptr;
	void(*glVertexAttribL4d) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) = nullptr;
	void(*glVertexAttribL1dv) (GLuint index, const GLdouble *v) = nullptr;
	void(*glVertexAttribL2dv) (GLuint index, const GLdouble *v) = nullptr;
	void(*glVertexAttribL3dv) (GLuint index, const GLdouble *v) = nullptr;
	void(*glVertexAttribL4dv) (GLuint index, const GLdouble *v) = nullptr;
	void(*glVertexAttribLPointer) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) = nullptr;
	void(*glGetVertexAttribLdv) (GLuint index, GLenum pname, GLdouble *params) = nullptr;
	void(*glViewportArrayv) (GLuint first, GLsizei count, const GLfloat *v) = nullptr;
	void(*glViewportIndexedf) (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h) = nullptr;
	void(*glViewportIndexedfv) (GLuint index, const GLfloat *v) = nullptr;
	void(*glScissorArrayv) (GLuint first, GLsizei count, const GLint *v) = nullptr;
	void(*glScissorIndexed) (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height) = nullptr;
	void(*glScissorIndexedv) (GLuint index, const GLint *v) = nullptr;
	void(*glDepthRangeIndexed) (GLuint first, GLsizei count, const GLdouble *v) = nullptr;
	void(*glDepthRangeArrayv) (GLuint index, GLdouble n, GLdouble f) = nullptr;
	void(*glGetFloati_v) (GLenum target, GLuint index, GLfloat *data) = nullptr;
	void(*glGetDoublei_v) (GLenum target, GLuint index, GLdouble *data) = nullptr;
	enum openGL4_1
	{
		GL_FIXED =									0x140c,
		GL_IMPLEMENTATION_COLOR_READ_TYPE =			0x8b9a,
		GL_IMPLEMENTATION_COLOR_READ_FORMAT =		0x8b9b,
		GL_LOW_FLOAT =								0x8df0,
		GL_MEDIUM_FLOAT =							0x8df1,
		GL_HIGH_FLOAT =								0x8df2,
		GL_LOW_INT =								0x8df3,
		GL_MEDIUM_INT =								0x8df4,
		GL_HIGH_INT =								0x8df5,
		GL_SHADER_COMPILER =						0x8dfa,
		GL_SHADER_BINARY_FORMATS =					0x8df8,
		GL_NUM_SHADER_BINARY_FORMATS =				0x8df9,
		GL_MAX_VERTEX_UNIFORM_VECTORS =				0x8dfb,
		GL_MAX_VARYING_VECTORS =					0x8dfc,
		GL_MAX_FRAGMENT_UNIFORM_VECTORS =			0x8dfd,
		GL_RGB565 =									0x8d62,
		GL_PROGRAM_BINARY_RETRIEVABLE_HINT =		0x8257,
		GL_PROGRAM_BINARY_LENGTH =					0x8741,
		GL_NUM_PROGRAM_BINARY_FORMATS =				0x87fe,
		GL_PROGRAM_BINARY_FORMATS =					0x87ff,
		GL_VERTEX_SHADER_BIT =						0x00000001,
		GL_FRAGMENT_SHADER_BIT =					0x00000002,
		GL_GEOMETRY_SHADER_BIT =					0x00000004,
		GL_TESS_CONTROL_SHADER_BIT =				0x00000008,
		GL_TESS_EVALUATION_SHADER_BIT =				0x00000010,
		GL_ALL_SHADER_BITS =						0xffffffff,
		GL_PROGRAM_SEPARABLE =						0x8258,
		GL_ACTIVE_PROGRAM =							0x8259,
		GL_PROGRAM_PIPELINE_BINDING =				0x825a,
		GL_MAX_VIEWPORTS =							0x825b,
		GL_VIEWPORT_SUBPIXEL_BITS =					0x825c,
		GL_VIEWPORT_BOUNDS_RANGE =					0x825d,
		GL_LAYER_PROVOKING_VERTEX =					0x825e,
		GL_VIEWPORT_INDEX_PROVOKING_VERTEX =		0x825f,
		GL_UNDEFINED_VERTEX =						0x8260
	};

	//OpenGL 4.2 Extensions
	void(*glDrawArraysInstancedBaseInstance) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance) = nullptr;
	void(*glDrawElementsInstancedBaseInstance) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance) = nullptr;
	void(*glDrawElementsInstancedBaseVertexBaseInstance) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance) = nullptr;
	void(*glGetInternalformativ) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params) = nullptr;
	void(*glGetActiveAtomicCounterBufferiv) (GLuint program, GLuint bufferIndex, GLenum pname, GLint *params) = nullptr;
	void(*glBindImageTexture) (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) = nullptr;
	void(*glMemoryBarrier) (GLbitfield barriers) = nullptr;
	void(*glTexStorage1D) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) = nullptr;
	void(*glTexStorage2D) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) = nullptr;
	void(*glTexStorage3D) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) = nullptr;
	void(*glDrawTransformFeedbackInstanced) (GLenum mode, GLuint id, GLsizei instancecount) = nullptr;
	void(*glDrawTransformFeedbackStreamInstanced) (GLenum mode, GLuint id, GLuint stream, GLsizei instancecount) = nullptr;
	enum openGL4_2
	{
		GL_UNPACK_COMPRESSED_BLOCK_WIDTH =										0x9127,
		GL_UNPACK_COMPRESSED_BLOCK_HEIGHT =										0x9128,
		GL_UNPACK_COMPRESSED_BLOCK_DEPTH =										0x9129,
		GL_UNPACK_COMPRESSED_BLOCK_SIZE =										0x912a,
		GL_PACK_COMPRESSED_BLOCK_WIDTH =										0x912b,
		GL_PACK_COMPRESSED_BLOCK_HEIGHT =										0x912c,
		GL_PACK_COMPRESSED_BLOCK_DEPTH =										0x912d,
		GL_PACK_COMPRESSED_BLOCK_SIZE =											0x912e,
		GL_NUM_SAMPLE_COUNTS =													0x9380,
		GL_MIN_MAP_BUFFER_ALIGNMENT =											0x90bc,
		GL_ATOMIC_COUNTER_BUFFER =												0x92c0,
		GL_ATOMIC_COUNTER_BUFFER_BINDING =										0x92c1,
		GL_ATOMIC_COUNTER_BUFFER_START =										0x92c2,
		GL_ATOMIC_COUNTER_BUFFER_SIZE =											0x92c3,
		GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE =									0x92c4,
		GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS =						0x92c5,
		GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES =				0x92c6,
		GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER =					0x92c7,
		GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER =			0x92c8,
		GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER =			0x92c9,
		GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER =				0x92ca,
		GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER =				0x92cb,
		GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS =									0x92cc,
		GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS =							0x92cd,
		GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS =							0x92ce,
		GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS =								0x92cf,
		GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS =								0x92d0,
		GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS =								0x92d1,
		GL_MAX_VERTEX_ATOMIC_COUNTERS =											0x92d2,
		GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS =									0x92d3,
		GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS =								0x92d4,
		GL_MAX_GEOMETRY_ATOMIC_COUNTERS =										0x92d5,
		GL_MAX_FRAGMENT_ATOMIC_COUNTERS =										0x92d6,
		GL_MAX_COMBINED_ATOMIC_COUNTERS =										0x92d7,
		GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE =										0x92d8,
		GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS =									0x92dc,
		GL_ACTIVE_ATOMIC_COUNTER_BUFFERS =										0x92d9,
		GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX =								0x92da,
		GL_UNSIGNED_INT_ATOMIC_COUNTER =										0x92db,
		GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT =									0x00000001,
		GL_ELEMENT_ARRAY_BARRIER_BIT =											0x00000002,
		GL_UNIFORM_BARRIER_BIT =												0x00000004,
		GL_TEXTURE_FETCH_BARRIER_BIT =											0x00000008,
		GL_SHADER_IMAGE_ACCESS_BARRIER_BIT =									0x00000020,
		GL_COMMAND_BARRIER_BIT =												0x00000040,
		GL_PIXEL_BUFFER_BARRIER_BIT =											0x00000080,
		GL_TEXTURE_UPDATE_BARRIER_BIT =											0x00000100,
		GL_BUFFER_UPDATE_BARRIER_BIT =											0x00000200,
		GL_FRAMEBUFFER_BARRIER_BIT =											0x00000400,
		GL_TRANSFORM_FEEDBACK_BARRIER_BIT =										0x00000800,
		GL_ATOMIC_COUNTER_BARRIER_BIT =											0x00001000,
		GL_ALL_BARRIER_BITS =													0xffffffff,
		GL_MAX_IMAGE_UNITS =													0x8f38,
		GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS =						0x8f39,
		GL_IMAGE_BINDING_NAME =													0x8f3a,
		GL_IMAGE_BINDING_LEVEL =												0x8f3b,
		GL_IMAGE_BINDING_LAYERED =												0x8f3c,
		GL_IMAGE_BINDING_LAYER =												0x8f3d,
		GL_IMAGE_BINDING_ACCESS =												0x8f3e,
		GL_IMAGE_1D =															0x904c,
		GL_IMAGE_2D =															0x904d,
		GL_IMAGE_3D =															0x904e,
		GL_IMAGE_2D_RECT =														0x904f,
		GL_IMAGE_CUBE =															0x9050,
		GL_IMAGE_BUFFER =														0x9051,
		GL_IMAGE_1D_ARRAY =														0x9052,
		GL_IMAGE_2D_ARRAY =														0x9053,
		GL_IMAGE_CUBE_MAP_ARRAY =												0x9054,
		GL_IMAGE_2D_MULTISAMPLE =												0x9055,
		GL_IMAGE_2D_MULTISAMPLE_ARRAY =											0x9056,
		GL_INT_IMAGE_1D =														0x9057,
		GL_INT_IMAGE_2D =														0x9058,
		GL_INT_IMAGE_3D =														0x9059,
		GL_INT_IMAGE_2D_RECT =													0x905a,
		GL_INT_IMAGE_CUBE =														0x905b,
		GL_INT_IMAGE_BUFFER =													0x905c,
		GL_INT_IMAGE_1D_ARRAY =													0x905d,
		GL_INT_IMAGE_2D_ARRAY =													0x905e,
		GL_INT_IMAGE_CUBE_MAP_ARRAY =											0x905f,
		GL_INT_IMAGE_2D_MULTISAMPLE =											0x9060,
		GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY =										0x9061,
		GL_UNSIGNED_INT_IMAGE_1D =												0x9062,
		GL_UNSIGNED_INT_IMAGE_2D =												0x9063,
		GL_UNSIGNED_INT_IMAGE_3D =												0x9064,
		GL_UNSIGNED_INT_IMAGE_2D_RECT =											0x9065,
		GL_UNSIGNED_INT_IMAGE_CUBE =											0x9066,
		GL_UNSIGNED_INT_IMAGE_BUFFER =											0x9067,
		GL_UNSIGNED_INT_IMAGE_1D_ARRAY =										0x9068,
		GL_UNSIGNED_INT_IMAGE_2D_ARRAY =										0x9069,
		GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY =									0x906a,
		GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE =									0x906b,
		GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY =							0x906c,
		GL_MAX_IMAGE_SAMPLES =													0x906d,
		GL_IMAGE_BINDING_FORMAT =												0x906e,
		GL_IMAGE_FORMAT_COMPATIBILITY_TYPE =									0x90c7,
		GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE =									0x90c8,
		GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS =								0x90c9,
		GL_MAX_VERTEX_IMAGE_UNIFORMS =											0x90ca,
		GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS =									0x90cb,
		GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS =									0x90cc,
		GL_MAX_GEOMETRY_IMAGE_UNIFORMS =										0x90cd,
		GL_MAX_FRAGMENT_IMAGE_UNIFORMS =										0x90ce,
		GL_MAX_COMBINED_IMAGE_UNIFORMS =										0x90cf,
		GL_TEXTURE_IMMUTABLE_FORMAT =											0x912f,
	};

	//OpenGL 4.3 Extensions
	typedef void (*glDebug)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);
	void(*glClearBufferData) (GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data) = nullptr;
	void(*glClearBufferSubData) (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data) = nullptr;
	void(*glDispatchCompute) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) = nullptr;
	void(*glDispatchComputeIndirect) (GLintptr indirect) = nullptr;
	void(*glCopyImageSubData) (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) = nullptr;
	void(*glFramebufferParameteri) (GLenum target, GLenum pname, GLint param) = nullptr;
	void(*glGetFramebufferParameteriv) (GLenum target, GLenum pname, GLint *params) = nullptr;
	void(*glGetInternalformati64v) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params) = nullptr;
	void(*glInvalidateTexSubImage) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth) = nullptr;
	void(*glInvalidateTexImage) (GLuint texture, GLint level) = nullptr;
	void(*glInvalidateBufferSubData) (GLuint buffer, GLintptr offset, GLsizeiptr length) = nullptr;
	void(*glInvalidateBufferData) (GLuint buffer) = nullptr;
	void(*glInvalidateFramebuffer) (GLenum target, GLsizei numAttachments, const GLenum *attachments) = nullptr;
	void(*glInvalidateSubFramebuffer) (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height) = nullptr;
	void(*glMultiDrawArraysIndirect) (GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride) = nullptr;
	void(*glMultiDrawElementsIndirect) (GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride) = nullptr;
	void(*glGetProgramInterfaceiv) (GLuint program, GLenum programInterface, GLenum pname, GLint *params) = nullptr;
	GLuint(*glGetProgramResourceIndex) (GLuint program, GLenum programInterface, const GLchar *name) = nullptr;
	void(*glGetProgramResourceName) (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name) = nullptr;
	void(*glGetProgramResourceiv) (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params) = nullptr;
	GLint(*glGetProgramResourceLocation) (GLuint program, GLenum programInterface, const GLchar *name) = nullptr;
	GLint(*glGetProgramResourceLocationIndex) (GLuint program, GLenum programInterface, const GLchar *name) = nullptr;
	void(*glShaderStorageBlockBinding) (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding) = nullptr;
	void(*glTexBufferRange) (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) = nullptr;
	void(*glTexStorage2DMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) = nullptr;
	void(*glTexStorage3DMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) = nullptr;
	void(*glTextureView) (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers) = nullptr;
	void(*glBindVertexBuffer) (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) = nullptr;
	void(*glVertexAttribFormat) (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) = nullptr;
	void(*glVertexAttribIFormat) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) = nullptr;
	void(*glVertexAttribLFormat) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) = nullptr;
	void(*glVertexAttribBinding) (GLuint attribindex, GLuint bindingindex) = nullptr;
	void(*glVertexBindingDivisor) (GLuint bindingindex, GLuint divisor) = nullptr;
	void(*glDebugMessageControl) (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled) = nullptr;
	void(*glDebugMessageInsert) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf) = nullptr;
	void(*glDebugMessageCallback) (glDebug callback, const void *userParam) = nullptr;
	GLuint(*glGetDebugMessageLog) (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog) = nullptr;
	void(*glPushDebugGroup) (GLenum source, GLuint id, GLsizei length, const GLchar *message) = nullptr;
	void(*glPopDebugGroup) (void) = nullptr;
	void(*glObjectLabel) (GLenum identifier, GLuint name, GLsizei length, const GLchar *label) = nullptr;
	void(*glObjectPtrLabel) (const void *ptr, GLsizei length, const GLchar *label) = nullptr;
	void(*glGetObjectLabel) (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label) = nullptr;
	void(*glGetObjectPtrLabel) (const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label) = nullptr;
	enum openGL4_3
	{
		GL_NUM_SHADING_LANGUAGE_VERSIONS =								0x82e9,
		GL_VERTEX_ATTRIB_ARRAY_LONG =									0x874e,
		GL_COMPRESSED_RGB8_ETC2 =										0x9274,
		GL_COMPRESSED_SRGB8_ETC2 =										0x9275,
		GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 =					0x9276,
		GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 =					0x9277,
		GL_COMPRESSED_RGBA8_ETC2_EAC =									0x9278,
		GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC =							0x9279,
		GL_COMPRESSED_R11_EAC =											0x9270,
		GL_COMPRESSED_SIGNED_R11_EAC =									0x9271,
		GL_COMPRESSED_RG11_EAC =										0x9272,
		GL_COMPRESSED_SIGNED_RG11_EAC =									0x9273,
		GL_PRIMITIVE_RESTART_FIXED_INDEX =								0x8d69,
		GL_ANY_SAMPLES_PASSED_CONSERVATIVE =							0x8d6a,
		GL_MAX_ELEMENT_INDEX =											0x8d6b,
		GL_COMPUTE_SHADER =												0x91b9,
		GL_MAX_COMPUTE_UNIFORM_BLOCKS =									0x91bb,
		GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS =							0x91bc,
		GL_MAX_COMPUTE_IMAGE_UNIFORMS =									0x91bd,
		GL_MAX_COMPUTE_SHARED_MEMORY_SIZE =								0x8262,
		GL_MAX_COMPUTE_UNIFORM_COMPONENTS =								0x8263,
		GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS =							0x8264,
		GL_MAX_COMPUTE_ATOMIC_COUNTERS =								0x8265,
		GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS =					0x8266,
		GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS =							0x90eb,
		GL_MAX_COMPUTE_WORK_GROUP_COUNT =								0x91be,
		GL_MAX_COMPUTE_WORK_GROUP_SIZE =								0x91bf,
		GL_COMPUTE_WORK_GROUP_SIZE =									0x8267,
		GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER =					0x90ec,
		GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER =			0x90ed,
		GL_DISPATCH_INDIRECT_BUFFER =									0x90ee,
		GL_DISPATCH_INDIRECT_BUFFER_BINDING =							0x90ef,
		GL_DEBUG_OUTPUT_SYNCHRONOUS =									0x8242,
		GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH =							0x8243,
		GL_DEBUG_CALLBACK_FUNCTION =									0x8244,
		GL_DEBUG_CALLBACK_USER_PARAM =									0x8245,
		GL_DEBUG_SOURCE_API =											0x8246,
		GL_DEBUG_SOURCE_WINDOW_SYSTEM =									0x8247,
		GL_DEBUG_SOURCE_SHADER_COMPILER =								0x8248,
		GL_DEBUG_SOURCE_THIRD_PARTY =									0x8249,
		GL_DEBUG_SOURCE_APPLICATION =									0x824a,
		GL_DEBUG_SOURCE_OTHER =											0x824b,
		GL_DEBUG_TYPE_ERROR =											0x824c,
		GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR =								0x824d,
		GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR =								0x824e,
		GL_DEBUG_TYPE_PORTABILITY =										0x824f,
		GL_DEBUG_TYPE_PERFORMANCE =										0x8250,
		GL_DEBUG_TYPE_OTHER =											0x8251,
		GL_MAX_DEBUG_MESSAGE_LENGTH =									0x9143,
		GL_MAX_DEBUG_LOGGED_MESSAGES =									0x9144,
		GL_DEBUG_LOGGED_MESSAGES =										0x9145,
		GL_DEBUG_SEVERITY_HIGH =										0x9146,
		GL_DEBUG_SEVERITY_MEDIUM =										0x9147,
		GL_DEBUG_SEVERITY_LOW =											0x9148,
		GL_DEBUG_TYPE_MARKER =											0x8268,
		GL_DEBUG_TYPE_PUSH_GROUP =										0x8269,
		GL_DEBUG_TYPE_POP_GROUP =										0x826a,
		GL_DEBUG_SEVERITY_NOTIFICATION =								0x826b,
		GL_MAX_DEBUG_GROUP_STACK_DEPTH =								0x826c,
		GL_DEBUG_GROUP_STACK_DEPTH =									0x826d,
		GL_BUFFER =														0x82e0,
		GL_SHADER =														0x82e1,
		GL_PROGRAM =													0x82e2,
		GL_QUERY =														0x82e3,
		GL_PROGRAM_PIPELINE =											0x82e4,
		GL_SAMPLER =													0x82e6,
		GL_MAX_LABEL_LENGTH =											0x82e8,
		GL_DEBUG_OUTPUT =												0x92e0,
		GL_CONTEXT_FLAG_DEBUG_BIT =										0x00000002,
		GL_MAX_UNIFORM_LOCATIONS =										0x826e,
		GL_FRAMEBUFFER_DEFAULT_WIDTH =									0x9310,
		GL_FRAMEBUFFER_DEFAULT_HEIGHT =									0x9311,
		GL_FRAMEBUFFER_DEFAULT_LAYERS =									0x9312,
		GL_FRAMEBUFFER_DEFAULT_SAMPLES =								0x9313,
		GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS =					0x9314,
		GL_MAX_FRAMEBUFFER_WIDTH =										0x9315,
		GL_MAX_FRAMEBUFFER_HEIGHT =										0x9316,
		GL_MAX_FRAMEBUFFER_LAYERS =										0x9317,
		GL_MAX_FRAMEBUFFER_SAMPLES =									0x9318,
		GL_INTERNALFORMAT_SUPPORTED =									0x826f,
		GL_INTERNALFORMAT_PREFERRED =									0x8270,
		GL_INTERNALFORMAT_RED_SIZE =									0x8271,
		GL_INTERNALFORMAT_GREEN_SIZE =									0x8272,
		GL_INTERNALFORMAT_BLUE_SIZE =									0x8273,
		GL_INTERNALFORMAT_ALPHA_SIZE =									0x8274,
		GL_INTERNALFORMAT_DEPTH_SIZE =									0x8275,
		GL_INTERNALFORMAT_STENCIL_SIZE =								0x8276,
		GL_INTERNALFORMAT_SHARED_SIZE =									0x8277,
		GL_INTERNALFORMAT_RED_TYPE =									0x8278,
		GL_INTERNALFORMAT_GREEN_TYPE =									0x8279,
		GL_INTERNALFORMAT_BLUE_TYPE =									0x827a,
		GL_INTERNALFORMAT_ALPHA_TYPE =									0x827b,
		GL_INTERNALFORMAT_DEPTH_TYPE =									0x827c,
		GL_INTERNALFORMAT_STENCIL_TYPE =								0x827d,
		GL_MAX_WIDTH =													0x827e,
		GL_MAX_HEIGHT =													0x827f,
		GL_MAX_DEPTH =													0x8280,
		GL_MAX_LAYERS =													0x8281,
		GL_MAX_COMBINED_DIMENSIONS =									0x8282,
		GL_COLOR_COMPONENTS =											0x8283,
		GL_DEPTH_COMPONENTS =											0x8284,
		GL_STENCIL_COMPONENTS =											0x8285,
		GL_COLOR_RENDERABLE =											0x8286,
		GL_DEPTH_RENDERABLE =											0x8287,
		GL_STENCIL_RENDERABLE =											0x8288,
		GL_FRAMEBUFFER_RENDERABLE =										0x8289,
		GL_FRAMEBUFFER_RENDERABLE_LAYERED =								0x828a,
		GL_FRAMEBUFFER_BLEND =											0x828b,
		GL_READ_PIXELS =												0x828c,
		GL_READ_PIXELS_FORMAT =											0x828d,
		GL_READ_PIXELS_TYPE =											0x828e,
		GL_TEXTURE_IMAGE_FORMAT =										0x828f,
		GL_TEXTURE_IMAGE_TYPE =											0x8290,
		GL_GET_TEXTURE_IMAGE_FORMAT =									0x8291,
		GL_GET_TEXTURE_IMAGE_TYPE =										0x8292,
		GL_MIPMAP =														0x8293,
		GL_MANUAL_GENERATE_MIPMAP =										0x8294,
		GL_AUTO_GENERATE_MIPMAP =										0x8295,
		GL_COLOR_ENCODING =												0x8296,
		GL_SRGB_READ =													0x8297,
		GL_SRGB_WRITE =													0x8298,
		GL_FILTER =														0x829a,
		GL_VERTEX_TEXTURE =												0x829b,
		GL_TESS_CONTROL_TEXTURE =										0x829c,
		GL_TESS_EVALUATION_TEXTURE =									0x829d,
		GL_GEOMETRY_TEXTURE =											0x829e,
		GL_FRAGMENT_TEXTURE =											0x829f,
		GL_COMPUTE_TEXTURE =											0x82a0,
		GL_TEXTURE_SHADOW =												0x82a1,
		GL_TEXTURE_GATHER =												0x82a2,
		GL_TEXTURE_GATHER_SHADOW =										0x82a3,
		GL_SHADER_IMAGE_LOAD =											0x82a4,
		GL_SHADER_IMAGE_STORE =											0x82a5,
		GL_SHADER_IMAGE_ATOMIC =										0x82a6,
		GL_IMAGE_TEXEL_SIZE =											0x82a7,
		GL_IMAGE_COMPATIBILITY_CLASS =									0x82a8,
		GL_IMAGE_PIXEL_FORMAT =											0x82a9,
		GL_IMAGE_PIXEL_TYPE =											0x82aa,
		GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST =						0x82ac,
		GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST =						0x82ad,
		GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE =						0x82ae,
		GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE =						0x82af,
		GL_TEXTURE_COMPRESSED_BLOCK_WIDTH =								0x82b1,
		GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT =							0x82b2,
		GL_TEXTURE_COMPRESSED_BLOCK_SIZE =								0x82b3,
		GL_CLEAR_BUFFER =												0x82b4,
		GL_TEXTURE_VIEW =												0x82b5,
		GL_VIEW_COMPATIBILITY_CLASS =									0x82b6,
		GL_FULL_SUPPORT =												0x82b7,
		GL_CAVEAT_SUPPORT =												0x82b8,
		GL_IMAGE_CLASS_4_X_32 =											0x82b9,
		GL_IMAGE_CLASS_2_X_32 =											0x82ba,
		GL_IMAGE_CLASS_1_X_32 =											0x82bb,
		GL_IMAGE_CLASS_4_X_16 =											0x82bc,
		GL_IMAGE_CLASS_2_X_16 =											0x82bd,
		GL_IMAGE_CLASS_1_X_16 =											0x82be,
		GL_IMAGE_CLASS_4_X_8 =											0x82bf,
		GL_IMAGE_CLASS_2_X_8 =											0x82c0,
		GL_IMAGE_CLASS_1_X_8 =											0x82c1,
		GL_IMAGE_CLASS_11_11_10 =										0x82c2,
		GL_IMAGE_CLASS_10_10_10_2 =										0x82c3,
		GL_VIEW_CLASS_128_BITS =										0x82c4,
		GL_VIEW_CLASS_96_BITS =											0x82c5,
		GL_VIEW_CLASS_64_BITS =											0x82c6,
		GL_VIEW_CLASS_48_BITS =											0x82c7,
		GL_VIEW_CLASS_32_BITS =											0x82c8,
		GL_VIEW_CLASS_24_BITS =											0x82c9,
		GL_VIEW_CLASS_16_BITS =											0x82ca,
		GL_VIEW_CLASS_8_BITS =											0x82cb,
		GL_VIEW_CLASS_S3TC_DXT1_RGB =									0x82cc,
		GL_VIEW_CLASS_S3TC_DXT1_RGBA =									0x82cd,
		GL_VIEW_CLASS_S3TC_DXT3_RGBA =									0x82ce,
		GL_VIEW_CLASS_S3TC_DXT5_RGBA =									0x82cf,
		GL_VIEW_CLASS_RGTC1_RED =										0x82d0,
		GL_VIEW_CLASS_RGTC2_RG =										0x82d1,
		GL_VIEW_CLASS_BPTC_UNORM =										0x82d2,
		GL_VIEW_CLASS_BPTC_FLOAT =										0x82d3,
		GL_UNIFORM =													0x92e1,
		GL_UNIFORM_BLOCK =												0x92e2,
		GL_PROGRAM_INPUT =												0x92e3,
		GL_PROGRAM_OUTPUT =												0x92e4,
		GL_BUFFER_VARIABLE =											0x92e5,
		GL_SHADER_STORAGE_BLOCK =										0x92e6,
		GL_VERTEX_SUBROUTINE =											0x92e8,
		GL_TESS_CONTROL_SUBROUTINE =									0x92e9,
		GL_TESS_EVALUATION_SUBROUTINE =									0x92ea,
		GL_GEOMETRY_SUBROUTINE =										0x92eb,
		GL_FRAGMENT_SUBROUTINE =										0x92ec,
		GL_COMPUTE_SUBROUTINE =											0x92ed,
		GL_VERTEX_SUBROUTINE_UNIFORM =									0x92ee,
		GL_TESS_CONTROL_SUBROUTINE_UNIFORM =							0x92ef,
		GL_TESS_EVALUATION_SUBROUTINE_UNIFORM =							0x92f0,
		GL_GEOMETRY_SUBROUTINE_UNIFORM =								0x92f1,
		GL_FRAGMENT_SUBROUTINE_UNIFORM =								0x92f2,
		GL_COMPUTE_SUBROUTINE_UNIFORM =									0x92f3,
		GL_TRANSFORM_FEEDBACK_VARYING =									0x92f4,
		GL_ACTIVE_RESOURCES =											0x92f5,
		GL_MAX_NAME_LENGTH =											0x92f6,
		GL_MAX_NUM_ACTIVE_VARIABLES =									0x92f7,
		GL_MAX_NUM_COMPATIBLE_SUBROUTINES =								0x92f8,
		GL_NAME_LENGTH =												0x92f9,
		GL_TYPE =														0x92fa,
		GL_ARRAY_SIZE =													0x92fb,
		GL_OFFSET =														0x92fc,
		GL_BLOCK_INDEX =												0x92fd,
		GL_ARRAY_STRIDE =												0x92fe,
		GL_MATRIX_STRIDE =												0x92ff,
		GL_IS_ROW_MAJOR =												0x9300,
		GL_ATOMIC_COUNTER_BUFFER_INDEX =								0x9301,
		GL_BUFFER_BINDING =												0x9302,
		GL_BUFFER_DATA_SIZE =											0x9303,
		GL_NUM_ACTIVE_VARIABLES =										0x9304,
		GL_ACTIVE_VARIABLES =											0x9305,
		GL_REFERENCED_BY_VERTEX_SHADER =								0x9306,
		GL_REFERENCED_BY_TESS_CONTROL_SHADER =							0x9307,
		GL_REFERENCED_BY_TESS_EVALUATION_SHADER =						0x9308,
		GL_REFERENCED_BY_GEOMETRY_SHADER =								0x9309,
		GL_REFERENCED_BY_FRAGMENT_SHADER =								0x930a,
		GL_REFERENCED_BY_COMPUTE_SHADER =								0x930b,
		GL_TOP_LEVEL_ARRAY_SIZE =										0x930c,
		GL_TOP_LEVEL_ARRAY_STRIDE =										0x930d,
		GL_LOCATION =													0x930e,
		GL_LOCATION_INDEX =												0x930f,
		GL_IS_PER_PATCH =												0x92e7,
		GL_SHADER_STORAGE_BUFFER =										0x90d2,
		GL_SHADER_STORAGE_BUFFER_BINDING =								0x90d3,
		GL_SHADER_STORAGE_BUFFER_START =								0x90d4,
		GL_SHADER_STORAGE_BUFFER_SIZE =									0x90d5,
		GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS =							0x90d6,
		GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS =							0x90d7,
		GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS =						0x90d8,
		GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS =					0x90d9,
		GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS =							0x90da,
		GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS =							0x90db,
		GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS =							0x90dc,
		GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS =							0x90dd,
		GL_MAX_SHADER_STORAGE_BLOCK_SIZE =								0x90de,
		GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT =						0x90df,
		GL_SHADER_STORAGE_BARRIER_BIT =									0x00002000,
		GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES =						0x8f39,
		GL_DEPTH_STENCIL_TEXTURE_MODE =									0x90ea,
		GL_TEXTURE_BUFFER_OFFSET =										0x919d,
		GL_TEXTURE_BUFFER_SIZE =										0x919e,
		GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT =							0x919f,
		GL_TEXTURE_VIEW_MIN_LEVEL =										0x82db,
		GL_TEXTURE_VIEW_NUM_LEVELS =									0x82dc,
		GL_TEXTURE_VIEW_MIN_LAYER =										0x82dd,
		GL_TEXTURE_VIEW_NUM_LAYERS =									0x82de,
		GL_TEXTURE_IMMUTABLE_LEVELS =									0x82df,
		GL_VERTEX_ATTRIB_BINDING =										0x82d4,
		GL_VERTEX_ATTRIB_RELATIVE_OFFSET =								0x82d5,
		GL_VERTEX_BINDING_DIVISOR =										0x82d6,
		GL_VERTEX_BINDING_OFFSET =										0x82d7,
		GL_VERTEX_BINDING_STRIDE =										0x82d8,
		GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET =							0x82d9,
		GL_MAX_VERTEX_ATTRIB_BINDINGS =									0x82da,
		GL_DISPLAY_LIST =												0x82e7,
	};

	//OpenGL 4.4 Extensions
	void(*glBufferStorage) (GLenum target, GLsizeiptr size, const void *data, GLbitfield flags) = nullptr;
	void(*glClearTexImage) (GLuint texture, GLint level, GLenum format, GLenum type, const void *data) = nullptr;
	void(*glClearTexSubImage) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data) = nullptr;
	void(*glBindBuffersBase) (GLenum target, GLuint first, GLsizei count, const GLuint *buffers) = nullptr;
	void(*glBindBuffersRange) (GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes) = nullptr;
	void(*glBindTextures) (GLuint first, GLsizei count, const GLuint *textures) = nullptr;
	void(*glBindSamplers) (GLuint first, GLsizei count, const GLuint *samplers) = nullptr;
	void(*glBindImageTextures) (GLuint first, GLsizei count, const GLuint *textures) = nullptr;
	void(*glBindVertexBuffers) (GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides) = nullptr;
	enum openGL4_4
	{
		GL_MAX_VERTEX_ATTRIB_STRIDE =						0x82e5,
		GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED =		0x8221,
		GL_TEXTURE_BUFFER_BINDING =							0x8c2a,
		GL_MAP_PERSISTENT_BIT =								0x0040,
		GL_MAP_COHERENT_BIT =								0x0080,
		GL_DYNAMIC_STORAGE_BIT =							0x0100,
		GL_CLIENT_STORAGE_BIT =								0x0200,
		GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT = 				0x00004000,
		GL_BUFFER_IMMUTABLE_STORAGE =						0x821f,
		GL_BUFFER_STORAGE_FLAGS =							0x8220,
		GL_CLEAR_TEXTURE =									0x9365,
		GL_LOCATION_COMPONENT =								0x934a,
		GL_TRANSFORM_FEEDBACK_BUFFER_INDEX =				0x934b,
		GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE =				0x934c,
		GL_QUERY_BUFFER =									0x9192,
		GL_QUERY_BUFFER_BARRIER_BIT =						0x00008000,
		GL_QUERY_BUFFER_BINDING =							0x9193,
		GL_QUERY_RESULT_NO_WAIT =							0x9194,
		GL_MIRROR_CLAMP_TO_EDGE =							0x8743
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

	class error_category : public std::error_category
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

		error_category() {};

		const static error_category& get()
		{
			const static error_category category;
			return category;
		}
	};

	std::error_code make_error_code(error_t errorCode)
	{
		return std::error_code(static_cast<int>(errorCode), error_category::get());
	}
};

namespace std
{
	template<> struct is_error_code_enum<TinyExtender::error_t> : std::true_type {};
};

namespace TinyExtender
{

	GLuint glVersionMajor;
	GLuint glVersionMinor;

	

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
	std::error_code InitializeGLVersion()
	{
		const GLubyte* versionString = glGetString(GL_VERSION);

		if (versionString != nullptr)
		{
			glVersionMajor = versionString[0] - '0';
			glVersionMinor = versionString[2] - '0';
			return TinyExtender::error_t::success;
		}

		else
		{
			return TinyExtender::error_t::versionLoadFailed;
		}
	}

	/**< load OpenGL 1.2 extensions */
	void Load1_2Extensions()
	{
		FetchProcAddress(glDrawRangeElements, "glDrawRangeElements");
		FetchProcAddress(glTexImage3D, "glTexImage3D");
		FetchProcAddress(glTexSubImage3D, "glTexSubImage3D");
		FetchProcAddress(glCopyTexSubImage3D, "glCopyTexSubImage3D");
	}
	
	/**< load OpenGL 1.3 extensions */
	void Load1_3Extensions()
	{
		FetchProcAddress(glActiveTexture, "glActiveTexture");
		FetchProcAddress(glSampleCoverage, "glSampleCoverage");
		FetchProcAddress(glCompressedTexImage3D, "glCompressedTexImage3D");
		FetchProcAddress(glCompressedTexImage2D, "glCompressedTexImage2D");
		FetchProcAddress(glCompressedTexImage1D, "glCompressedTexImage1D");
		FetchProcAddress(glCompressedTexSubImage3D, "glCompressedTexSubImage3D");
		FetchProcAddress(glCompressedTexSubImage2D, "glCompressedTexSubImage2D");
		FetchProcAddress(glCompressedTexSubImage1D, "glCompressedTexSubImage1D");
		FetchProcAddress(glGetCompressedTexImage, "glGetCompressedTexImage");
		FetchProcAddress(glClientActiveTexture, "glClientActiveTexture");
		FetchProcAddress(glMultiTexCoord1d, "glMultiTexCoord1d");
		FetchProcAddress(glMultiTexCoord1dv, "glMultiTexCoord1dv");
		FetchProcAddress(glMultiTexCoord1f, "glMultiTexCoord1f");
		FetchProcAddress(glMultiTexCoord1fv, "glMultiTexCoord1fv");
		FetchProcAddress(glMultiTexCoord1i, "glMultiTexCoord1i");
		FetchProcAddress(glMultiTexCoord1iv, "glMultiTexCoord1iv");
		FetchProcAddress(glMultiTexCoord1s, "glMultiTexCoord1s");
		FetchProcAddress(glMultiTexCoord1sv, "glMultiTexCoord1sv");
		FetchProcAddress(glMultiTexCoord2d, "glMultiTexCoord2d");
		FetchProcAddress(glMultiTexCoord2dv, "glMultiTexCoord2dv");
		FetchProcAddress(glMultiTexCoord2f, "glMultiTexCoord2f");
		FetchProcAddress(glMultiTexCoord2fv, "glMultiTexCoord2fv");
		FetchProcAddress(glMultiTexCoord2i, "glMultiTexCoord2i");
		FetchProcAddress(glMultiTexCoord2iv, "glMultiTexCoord2iv");
		FetchProcAddress(glMultiTexCoord2s, "glMultiTexCoord2s");
		FetchProcAddress(glMultiTexCoord2sv, "glMultiTexCoord2sv");
		FetchProcAddress(glMultiTexCoord3d, "glMultiTexCoord3d");
		FetchProcAddress(glMultiTexCoord3dv, "glMultiTexCoord3dv");
		FetchProcAddress(glMultiTexCoord3f, "glMultiTexCoord3f");
		FetchProcAddress(glMultiTexCoord3fv, "glMultiTexCoord3fv");
		FetchProcAddress(glMultiTexCoord3i, "glMultiTexCoord3i");
		FetchProcAddress(glMultiTexCoord3iv, "glMultiTexCoord3iv");
		FetchProcAddress(glMultiTexCoord3s, "glMultiTexCoord3s");
		FetchProcAddress(glMultiTexCoord3sv, "glMultiTexCoord3sv");
		FetchProcAddress(glMultiTexCoord4d, "glMultiTexCoord4d");
		FetchProcAddress(glMultiTexCoord4dv, "glMultiTexCoord4dv");
		FetchProcAddress(glMultiTexCoord4f, "glMultiTexCoord4f");
		FetchProcAddress(glMultiTexCoord4fv, "glMultiTexCoord4fv");
		FetchProcAddress(glMultiTexCoord4i, "glMultiTexCoord4i");
		FetchProcAddress(glMultiTexCoord4iv, "glMultiTexCoord4iv");
		FetchProcAddress(glMultiTexCoord4s, "glMultiTexCoord4s");
		FetchProcAddress(glMultiTexCoord4sv, "glMultiTexCoord4sv");
		FetchProcAddress(glLoadTransposeMatrixf, "glLoadTransposeMatrixf");
		FetchProcAddress(glLoadTransposeMatrixd, "glLoadTransposeMatrixd");
		FetchProcAddress(glMultTransposeMatrixf, "glMultTransposeMatrixf");
		FetchProcAddress(glMultTransposeMatrixd, "glMultTransposeMatrixd");
	}

	/**< load OpenGL 1.4 extensions */
	void Load1_4Extensions()
	{
		FetchProcAddress(glBlendFuncSeparate, "glBlendFuncSeparate");
		FetchProcAddress(glMultiDrawArrays, "glMultiDrawArrays");
		FetchProcAddress(glMultiDrawElements, "glMultiDrawElements");
		FetchProcAddress(glPointParameterf, "glPointParameterf");
		FetchProcAddress(glPointParameterfv, "glPointParameterfv");
		FetchProcAddress(glPointParameteri, "glPointParameteri");
		FetchProcAddress(glPointParameteriv, "glPointParameteriv");
		FetchProcAddress(glFogCoordf, "glFogCoordf");
		FetchProcAddress(glFogCoordfv, "glFogCoordfv");
		FetchProcAddress(glFogCoordd, "glFogCoordd");
		FetchProcAddress(glFogCoorddv, "glFogCoorddv");
		FetchProcAddress(glFogCoordPointer, "glFogCoordPointer");
		FetchProcAddress(glSecondaryColor3b, "glSecondaryColor3b");
		FetchProcAddress(glSecondaryColor3bv, "glSecondaryColor3bv");
		FetchProcAddress(glSecondaryColor3d, "glSecondaryColor3d");
		FetchProcAddress(glSecondaryColor3dv, "glSecondaryColor3dv");
		FetchProcAddress(glSecondaryColor3f, "glSecondaryColor3f");
		FetchProcAddress(glSecondaryColor3fv, "glSecondaryColor3fv");
		FetchProcAddress(glSecondaryColor3i, "glSecondaryColor3i");
		FetchProcAddress(glSecondaryColor3iv, "glSecondaryColor3iv");
		FetchProcAddress(glSecondaryColor3s, "glSecondaryColor3s");
		FetchProcAddress(glSecondaryColor3sv, "glSecondaryColor3sv");
		FetchProcAddress(glSecondaryColor3ub, "glSecondaryColor3ub");
		FetchProcAddress(glSecondaryColor3ubv, "glSecondaryColor3ubv");
		FetchProcAddress(glSecondaryColor3ui, "glSecondaryColor3ui");
		FetchProcAddress(glSecondaryColor3uiv, "glSecondaryColor3uiv");
		FetchProcAddress(glSecondaryColor3us, "glSecondaryColor3us");
		FetchProcAddress(glSecondaryColor3usv, "glSecondaryColor3usv");
		FetchProcAddress(glSecondaryColorPointer, "glSecondaryColorPointer");
		FetchProcAddress(glWindowPos2d, "glWindowPos2d");
		FetchProcAddress(glWindowPos2dv, "glWindowPos2dv");
		FetchProcAddress(glWindowPos2f, "glWindowPos2f");
		FetchProcAddress(glWindowPos2fv, "glWindowPos2fv");
		FetchProcAddress(glWindowPos2i, "glWindowPos2i");
		FetchProcAddress(glWindowPos2iv, "glWindowPos2iv");
		FetchProcAddress(glWindowPos2s, "glWindowPos2s");
		FetchProcAddress(glWindowPos2sv, "glWindowPos2sv");
		FetchProcAddress(glWindowPos3d, "glWindowPos3d");
		FetchProcAddress(glWindowPos3dv, "glWindowPos3dv");
		FetchProcAddress(glWindowPos3f, "glWindowPos3f");
		FetchProcAddress(glWindowPos3fv, "glWindowPos3fv");
		FetchProcAddress(glWindowPos3i, "glWindowPos3i");
		FetchProcAddress(glWindowPos3iv, "glWindowPos3iv");
		FetchProcAddress(glWindowPos3s, "glWindowPos3s");
		FetchProcAddress(glWindowPos3sv, "glWindowPos3sv");
		FetchProcAddress(glBlendColor, "glBlendColor");
		FetchProcAddress(glBlendEquation, "glBlendEquation");
	}

	/**< load OpenGL 1.5 extensions */
	void Load1_5Extensions()
	{
		FetchProcAddress(glGenQueries, "glGenQueries");
		FetchProcAddress(glDeleteQueries, "glDeleteQueries");
		FetchProcAddress(glIsQuery, "glIsQuery");
		FetchProcAddress(glBeginQuery, "glBeginQuery");
		FetchProcAddress(glEndQuery, "glEndQuery");
		FetchProcAddress(glGetQueryiv, "glGetQueryiv");
		FetchProcAddress(glGetQueryObjectiv, "glGetQueryObjectiv");
		FetchProcAddress(glGetQueryObjectuiv, "glGetQueryObjectuiv");
		FetchProcAddress(glBindBuffer, "glBindBuffer");
		FetchProcAddress(glDeleteBuffers, "glDeleteBuffers");
		FetchProcAddress(glGenBuffers, "glGenBuffers");
		FetchProcAddress(glIsBuffer, "glIsBuffer");
		FetchProcAddress(glBufferData, "glBufferData");
		FetchProcAddress(glBufferSubData, "glBufferSubData");
		FetchProcAddress(glGetBufferSubData, "glGetBufferSubData");
		FetchProcAddress(glMapBuffer, "glMapBuffer");
		FetchProcAddress(glUnmapBuffer, "glUnmapBuffer");
		FetchProcAddress(glGetBufferParameteriv, "glGetBufferParameteriv");
		FetchProcAddress(glGetBufferPointerv, "glGetBufferPointerv");
	}

	/**< load OpenGL 2.0 extensions */
	void Load2_0Extensions()
	{
		FetchProcAddress(glBlendEquationSeparate, "glBlendEquationSeparate");
		FetchProcAddress(glDrawBuffers, "glDrawBuffers");
		FetchProcAddress(glStencilOpSeparate, "glStencilOpSeparate");
		FetchProcAddress(glStencilFuncSeparate, "glStencilFuncSeparate");
		FetchProcAddress(glStencilMaskSeparate, "glStencilMaskSeparate");
		FetchProcAddress(glAttachShader, "glAttachShader");
		FetchProcAddress(glBindAttribLocation, "glBindAttribLocation");
		FetchProcAddress(glCompileShader, "glCompileShader");
		FetchProcAddress(glCreateProgram, "glCreateProgram");
		FetchProcAddress(glCreateShader, "glCreateShader");
		FetchProcAddress(glDeleteProgram, "glDeleteProgram");
		FetchProcAddress(glDeleteShader, "glDeleteShader");
		FetchProcAddress(glDetachShader, "glDetachShader");
		FetchProcAddress(glDisableVertexAttribArray, "glDisableVertexAttribArray");
		FetchProcAddress(glEnableVertexAttribArray, "glEnableVertexAttribArray");
		FetchProcAddress(glGetActiveAttrib, "glGetActiveAttrib");
		FetchProcAddress(glGetActiveUniform, "glGetActiveUniform");
		FetchProcAddress(glGetAttachedShaders, "glGetAttachedShaders");
		FetchProcAddress(glGetAttribLocation, "glGetAttribLocation");
		FetchProcAddress(glGetProgramiv, "glGetProgramiv");
		FetchProcAddress(glGetProgramInfoLog, "glGetProgramInfoLog");
		FetchProcAddress(glGetShaderiv, "glGetShaderiv");
		FetchProcAddress(glGetShaderInfoLog, "glGetShaderInfoLog");
		FetchProcAddress(glGetShaderSource, "glGetShaderSource");
		FetchProcAddress(glGetUniformLocation, "glGetUniformLocation");
		FetchProcAddress(glGetUniformfv, "glGetUniformfv");
		FetchProcAddress(glGetUniformiv, "glGetUniformiv");
		FetchProcAddress(glGetVertexAttribdv, "glGetVertexAttribdv");
		FetchProcAddress(glGetVertexAttribfv, "glGetVertexAttribfv");
		FetchProcAddress(glGetVertexAttribiv, "glGetVertexAttribiv");
		FetchProcAddress(glGetVertexAttribPointerv, "glGetVertexAttribPointerv");
		FetchProcAddress(glIsProgram, "glIsProgram");
		FetchProcAddress(glIsShader, "glIsShader");
		FetchProcAddress(glLinkProgram, "glLinkProgram");
		FetchProcAddress(glShaderSource, "glShaderSource");
		FetchProcAddress(glUseProgram, "glUseProgram");
		FetchProcAddress(glUniform1f, "glUniform1f");
		FetchProcAddress(glUniform2f, "glUniform2f");
		FetchProcAddress(glUniform3f, "glUniform3f");
		FetchProcAddress(glUniform4f, "glUniform4f");
		FetchProcAddress(glUniform1i, "glUniform1i");
		FetchProcAddress(glUniform2i, "glUniform2i");
		FetchProcAddress(glUniform3i, "glUniform3i");
		FetchProcAddress(glUniform4i, "glUniform4i");
		FetchProcAddress(glUniform1fv, "glUniform1fv");
		FetchProcAddress(glUniform2fv, "glUniform2fv");
		FetchProcAddress(glUniform3fv, "glUniform3fv");
		FetchProcAddress(glUniform4fv, "glUniform4fv");
		FetchProcAddress(glUniform1iv, "glUniform1iv");
		FetchProcAddress(glUniform2iv, "glUniform2iv");
		FetchProcAddress(glUniform3iv, "glUniform3iv");
		FetchProcAddress(glUniform4iv, "glUniform4iv");
		FetchProcAddress(glUniformMatrix2fv, "glUniformMatrix2fv");
		FetchProcAddress(glUniformMatrix3fv, "glUniformMatrix3fv");
		FetchProcAddress(glUniformMatrix4fv, "glUniformMatrix4fv");
		FetchProcAddress(glValidateProgram, "glValidateProgram");
		FetchProcAddress(glVertexAttrib1d, "glVertexAttrib1d");
		FetchProcAddress(glVertexAttrib1dv, "glVertexAttrib1dv");
		FetchProcAddress(glVertexAttrib1f, "glVertexAttrib1f");
		FetchProcAddress(glVertexAttrib1fv, "glVertexAttrib1fv");
		FetchProcAddress(glVertexAttrib1s, "glVertexAttrib1s");
		FetchProcAddress(glVertexAttrib1sv, "glVertexAttrib1sv");
		FetchProcAddress(glVertexAttrib2d, "glVertexAttrib2d");
		FetchProcAddress(glVertexAttrib2dv, "glVertexAttrib2dv");
		FetchProcAddress(glVertexAttrib2f, "glVertexAttrib2f");
		FetchProcAddress(glVertexAttrib2fv, "glVertexAttrib2fv");
		FetchProcAddress(glVertexAttrib2s, "glVertexAttrib2s");
		FetchProcAddress(glVertexAttrib2sv, "glVertexAttrib2sv");
		FetchProcAddress(glVertexAttrib3d, "glVertexAttrib3d");
		FetchProcAddress(glVertexAttrib3dv, "glVertexAttrib3dv");
		FetchProcAddress(glVertexAttrib3f, "glVertexAttrib3f");
		FetchProcAddress(glVertexAttrib3fv, "glVertexAttrib3fv");
		FetchProcAddress(glVertexAttrib3s, "glVertexAttrib3s");
		FetchProcAddress(glVertexAttrib3sv, "glVertexAttrib3sv");
		FetchProcAddress(glVertexAttrib4Nbv, "glVertexAttrib4Nbv");
		FetchProcAddress(glVertexAttrib4Niv, "glVertexAttrib4Niv");
		FetchProcAddress(glVertexAttrib4Nsv, "glVertexAttrib4Nsv");
		FetchProcAddress(glVertexAttrib4Nub, "glVertexAttrib4Nub");
		FetchProcAddress(glVertexAttrib4Nubv, "glVertexAttrib4Nubv");
		FetchProcAddress(glVertexAttrib4Nuiv, "glVertexAttrib4Nuiv");
		FetchProcAddress(glVertexAttrib4Nusv, "glVertexAttrib4Nusv");
		FetchProcAddress(glVertexAttrib4bv, "glVertexAttrib4bv");
		FetchProcAddress(glVertexAttrib4d, "glVertexAttrib4d");
		FetchProcAddress(glVertexAttrib4dv, "glVertexAttrib4dv");
		FetchProcAddress(glVertexAttrib4f, "glVertexAttrib4f");
		FetchProcAddress(glVertexAttrib4fv, "glVertexAttrib4fv");
		FetchProcAddress(glVertexAttrib4iv, "glVertexAttrib4iv");
		FetchProcAddress(glVertexAttrib4s, "glVertexAttrib4s");
		FetchProcAddress(glVertexAttrib4sv, "glVertexAttrib4sv");
		FetchProcAddress(glVertexAttrib4ubv, "glVertexAttrib4ubv");
		FetchProcAddress(glVertexAttrib4uiv, "glVertexAttrib4uiv");
		FetchProcAddress(glVertexAttrib4usv, "glVertexAttrib4usv");
		FetchProcAddress(glVertexAttribPointer, "glVertexAttribPointer");
	}

	/**< load OpenGL 2.1 extensions */
	void Load2_1Extensions()
	{
		FetchProcAddress(glUniformMatrix2x3fv, "glUniformMatrix2x3fv");
		FetchProcAddress(glUniformMatrix3x2fv, "glUniformMatrix3x2fv");
		FetchProcAddress(glUniformMatrix2x4fv, "glUniformMatrix2x4fv");
		FetchProcAddress(glUniformMatrix4x2fv, "glUniformMatrix4x2fv");
		FetchProcAddress(glUniformMatrix3x4fv, "glUniformMatrix3x4fv");
		FetchProcAddress(glUniformMatrix4x3fv, "glUniformMatrix4x3fv");
	}

	/**< load OpenGL 3.0 extensions */
	void Load3_0Extensions()
	{
		FetchProcAddress(glColorMaski, "glColorMaski");
		FetchProcAddress(glGetBooleani_v, "glGetBooleani_v");
		FetchProcAddress(glGetIntegeri_v, "glGetIntegeri_v");
		FetchProcAddress(glEnablei, "glEnablei");
		FetchProcAddress(glDisablei, "glDisablei");
		FetchProcAddress(glIsEnabledi, "glIsEnabledi");
		FetchProcAddress(glBeginTransformFeedback, "glBeginTransformFeedback");
		FetchProcAddress(glEndTransformFeedback, "glEndTransformFeedback");
		FetchProcAddress(glBindBufferRange, "glBindBufferRange");
		FetchProcAddress(glBindBufferBase, "glBindBufferBase");
		FetchProcAddress(glTransformFeedbackVaryings, "glTransformFeedbackVaryings");
		FetchProcAddress(glGetTransformFeedbackVarying, "glGetTransformFeedbackVarying");
		FetchProcAddress(glClampColor, "glClampColor");
		FetchProcAddress(glBeginConditionalRender, "glBeginConditionalRender");
		FetchProcAddress(glEndConditionalRender, "glEndConditionalRender");
		FetchProcAddress(glVertexAttribIPointer, "glVertexAttribIPointer");
		FetchProcAddress(glGetVertexAttribIiv, "glGetVertexAttribIiv");
		FetchProcAddress(glGetVertexAttribIuiv, "glGetVertexAttribIuiv");
		FetchProcAddress(glVertexAttribI1i, "glVertexAttribI1i");
		FetchProcAddress(glVertexAttribI2i, "glVertexAttribI2i");
		FetchProcAddress(glVertexAttribI3i, "glVertexAttribI3i");
		FetchProcAddress(glVertexAttribI4i, "glVertexAttribI4i");
		FetchProcAddress(glVertexAttribI1ui, "glVertexAttribI1ui");
		FetchProcAddress(glVertexAttribI2ui, "glVertexAttribI2ui");
		FetchProcAddress(glVertexAttribI3ui, "glVertexAttribI3ui");
		FetchProcAddress(glVertexAttribI4ui, "glVertexAttribI4ui");
		FetchProcAddress(glVertexAttribI1iv, "glVertexAttribI1iv");
		FetchProcAddress(glVertexAttribI2iv, "glVertexAttribI2iv");
		FetchProcAddress(glVertexAttribI3iv, "glVertexAttribI3iv");
		FetchProcAddress(glVertexAttribI4iv, "glVertexAttribI4iv");
		FetchProcAddress(glVertexAttribI1uiv, "glVertexAttribI1uiv");
		FetchProcAddress(glVertexAttribI2uiv, "glVertexAttribI2uiv");
		FetchProcAddress(glVertexAttribI3uiv, "glVertexAttribI3uiv");
		FetchProcAddress(glVertexAttribI4uiv, "glVertexAttribI4uiv");
		FetchProcAddress(glVertexAttribI4bv, "glVertexAttribI4bv");
		FetchProcAddress(glVertexAttribI4sv, "glVertexAttribI4sv");
		FetchProcAddress(glVertexAttribI4ubv, "glVertexAttribI4ubv");
		FetchProcAddress(glVertexAttribI4usv, "glVertexAttribI4usv");
		FetchProcAddress(glGetUniformuiv, "glGetUniformuiv");
		FetchProcAddress(glBindFragDataLocation, "glBindFragDataLocation");
		FetchProcAddress(glGetFragDataLocation, "glGetFragDataLocation");
		FetchProcAddress(glUniform1ui, "glUniform1ui");
		FetchProcAddress(glUniform2ui, "glUniform2ui");
		FetchProcAddress(glUniform3ui, "glUniform3ui");
		FetchProcAddress(glUniform4ui, "glUniform4ui");
		FetchProcAddress(glUniform1uiv, "glUniform1uiv");
		FetchProcAddress(glUniform2uiv, "glUniform2uiv");
		FetchProcAddress(glUniform3uiv, "glUniform3uiv");
		FetchProcAddress(glUniform4uiv, "glUniform4uiv");
		FetchProcAddress(glTexParameterIiv, "glTexParameterIiv");
		FetchProcAddress(glTexParameterIuiv, "glTexParameterIuiv");
		FetchProcAddress(glGetTexParameterIiv, "glGetTexParameterIiv");
		FetchProcAddress(glGetTexParameterIuiv, "glGetTexParameterIuiv");
		FetchProcAddress(glClearBufferiv, "glClearBufferiv");
		FetchProcAddress(glClearBufferuiv, "glClearBufferuiv");
		FetchProcAddress(glClearBufferfv, "glClearBufferfv");
		FetchProcAddress(glClearBufferfi, "glClearBufferfi");
		FetchProcAddress(glGetStringi, "glGetStringi");
		FetchProcAddress(glIsRenderbuffer, "glIsRenderbuffer");
		FetchProcAddress(glBindRenderbuffer, "glBindRenderbuffer");
		FetchProcAddress(glDeleteRenderbuffers, "glDeleteRenderbuffers");
		FetchProcAddress(glGenRenderbuffers, "glGenRenderbuffers");
		FetchProcAddress(glRenderbufferStorage, "glRenderbufferStorage");
		FetchProcAddress(glGetRenderbufferParameteriv, "glGetRenderbufferParameteriv");
		FetchProcAddress(glIsFramebuffer, "glIsFramebuffer");
		FetchProcAddress(glBindFramebuffer, "glBindFramebuffer");
		FetchProcAddress(glDeleteFramebuffers, "glDeleteFramebuffers");
		FetchProcAddress(glGenFramebuffers, "glGenFramebuffers");
		FetchProcAddress(glCheckFramebufferStatus, "glCheckFramebufferStatus");
		FetchProcAddress(glFramebufferTexture1D, "glFramebufferTexture1D");
		FetchProcAddress(glFramebufferTexture2D, "glFramebufferTexture2D");
		FetchProcAddress(glFramebufferTexture3D, "glFramebufferTexture3D");
		FetchProcAddress(glFramebufferRenderbuffer, "glFramebufferRenderbuffer");
		FetchProcAddress(glGetFramebufferAttachmentParameteriv, "glGetFramebufferAttachmentParameteriv");
		FetchProcAddress(glGenerateMipmap, "glGenerateMipmap");
		FetchProcAddress(glBlitFramebuffer, "glBlitFramebuffer");
		FetchProcAddress(glRenderbufferStorageMultisample, "glRenderbufferStorageMultisample");
		FetchProcAddress(glFramebufferTextureLayer, "glFramebufferTextureLayer");
		FetchProcAddress(glMapBufferRange, "glMapBufferRange");
		FetchProcAddress(glFlushMappedBufferRange, "glFlushMappedBufferRange");
		FetchProcAddress(glBindVertexArray, "glBindVertexArray");
		FetchProcAddress(glDeleteVertexArrays, "glDeleteVertexArrays");
		FetchProcAddress(glGenVertexArrays, "glGenVertexArrays");
		FetchProcAddress(glIsVertexArray, "glIsVertexArray");
	}

	/**< load OpenGL 3.1 extensions */
	void Load3_1Extensions()
	{
		FetchProcAddress(glDrawArraysInstanced, "glDrawArraysInstanced");
		FetchProcAddress(glDrawElementsInstanced, "glDrawElementsInstanced");
		FetchProcAddress(glTexBuffer, "glTexBuffer");
		FetchProcAddress(glPrimitiveRestartIndex, "glPrimitiveRestartIndex");
		FetchProcAddress(glCopyBufferSubData, "glCopyBufferSubData");
		FetchProcAddress(glGetUniformIndices, "glGetUniformIndices");
		FetchProcAddress(glGetActiveUniformsiv, "glGetActiveUniformsiv");
		FetchProcAddress(glGetActiveUniformName, "glGetActiveUniformName");
		FetchProcAddress(glGetUniformBlockIndex, "glGetUniformBlockIndex");
		FetchProcAddress(glGetActiveUniformBlockiv, "glGetActiveUniformBlockiv");
		FetchProcAddress(glGetActiveUniformBlockName, "glGetActiveUniformBlockName");
		FetchProcAddress(glUniformBlockBinding, "glUniformBlockBinding");
	}

	/**< load OpenGL 3.2 extensions */
	void Load3_2Extensions()
	{
		FetchProcAddress(glDrawElementsBaseVertex, "glDrawElementsBaseVertex");
		FetchProcAddress(glDrawRangeElementsBaseVertex, "glDrawRangeElementsBaseVertex");
		FetchProcAddress(glDrawElementsInstancedBaseVertex, "glDrawElementsInstancedBaseVertex");
		FetchProcAddress(glMultiDrawElementsBaseVertex, "glMultiDrawElementsBaseVertex");
		FetchProcAddress(glProvokingVertex, "glProvokingVertex");
		FetchProcAddress(glFenceSync, "glFenceSync");
		FetchProcAddress(glIsSync, "glIsSync");
		FetchProcAddress(glDeleteSync, "glDeleteSync");
		FetchProcAddress(glClientWaitSync, "glClientWaitSync");
		FetchProcAddress(glWaitSync, "glWaitSync");
		FetchProcAddress(glGetInteger64v, "glGetInteger64v");
		FetchProcAddress(glGetSynciv, "glGetSynciv");
		FetchProcAddress(glGetInteger64i_v, "glGetInteger64i_v");
		FetchProcAddress(glGetBufferParameteri64v, "glGetBufferParameteri64v");
		FetchProcAddress(glFramebufferTexture, "glFramebufferTexture");
		FetchProcAddress(glTexImage2DMultisample, "glTexImage2DMultisample");
		FetchProcAddress(glTexImage3DMultisample, "glTexImage3DMultisample");
		FetchProcAddress(glGetMultisamplefv, "glGetMultisamplefv");
		FetchProcAddress(glSampleMaski, "glSampleMaski");
	}
	/**< load OpenGL 3.3 extensions */
	void Load3_3Extensions()
	{
		FetchProcAddress(glBindFragDataLocationIndexed, "glBindFragDataLocationIndexed");
		FetchProcAddress(glGetFragDataIndex, "glGetFragDataIndex");
		FetchProcAddress(glGenSamplers, "glGenSamplers");
		FetchProcAddress(glDeleteSamplers, "glDeleteSamplers");
		FetchProcAddress(glIsSampler, "glIsSampler");
		FetchProcAddress(glBindSampler, "glBindSampler");
		FetchProcAddress(glSamplerParameteri, "glSamplerParameteri");
		FetchProcAddress(glSamplerParameteriv, "glSamplerParameteriv");
		FetchProcAddress(glSamplerParameterf, "glSamplerParameterf");
		FetchProcAddress(glSamplerParameterfv, "glSamplerParameterfv");
		FetchProcAddress(glSamplerParameterIiv, "glSamplerParameterIiv");
		FetchProcAddress(glSamplerParameterIuiv, "glSamplerParameterIuiv");
		FetchProcAddress(glGetSamplerParameteriv, "glGetSamplerParameteriv");
		FetchProcAddress(glGetSamplerParameterIiv, "glGetSamplerParameterIiv");
		FetchProcAddress(glGetSamplerParameterfv, "glGetSamplerParameterfv");
		FetchProcAddress(glGetSamplerParameterIuiv, "glGetSamplerParameterIuiv");
		FetchProcAddress(glQueryCounter, "glQueryCounter");
		FetchProcAddress(glGetQueryObjecti64v, "glGetQueryObjecti64v");
		FetchProcAddress(glGetQueryObjectui64v, "glGetQueryObjectui64v");
		FetchProcAddress(glVertexAttribDivisor, "glVertexAttribDivisor");
		FetchProcAddress(glVertexAttribP1ui, "glVertexAttribP1ui");
		FetchProcAddress(glVertexAttribP1uiv, "glVertexAttribP1uiv");
		FetchProcAddress(glVertexAttribP2ui, "glVertexAttribP2ui");
		FetchProcAddress(glVertexAttribP2uiv, "glVertexAttribP2uiv");
		FetchProcAddress(glVertexAttribP3ui, "glVertexAttribP3ui");
		FetchProcAddress(glVertexAttribP3uiv, "glVertexAttribP3uiv");
		FetchProcAddress(glVertexAttribP4ui, "glVertexAttribP4ui");
		FetchProcAddress(glVertexAttribP4uiv, "glVertexAttribP4uiv");
		FetchProcAddress(glVertexAttrib4uiv, "glVertexAttrib4uiv");
		FetchProcAddress(glVertexP2ui, "glVertexP2ui");
		FetchProcAddress(glVertexP2uiv, "glVertexP2uiv");
		FetchProcAddress(glVertexP3ui, "glVertexP3ui");
		FetchProcAddress(glVertexP3uiv, "glVertexP3uiv");
		FetchProcAddress(glVertexP4ui, "glVertexP4ui");
		FetchProcAddress(glVertexP4uiv, "glVertexP4uiv");
		FetchProcAddress(glTexCoordP1ui, "glTexCoordP1ui");
		FetchProcAddress(glTexCoordP1uiv, "glTexCoordP1uiv");
		FetchProcAddress(glTexCoordP2ui, "glTexCoordP2ui");
		FetchProcAddress(glTexCoordP2uiv, "glTexCoordP2uiv");
		FetchProcAddress(glTexCoordP3ui, "glTexCoordP3ui");
		FetchProcAddress(glTexCoordP3uiv, "glTexCoordP3uiv");
		FetchProcAddress(glTexCoordP4ui, "glTexCoordP4ui");
		FetchProcAddress(glTexCoordP4uiv, "glTexCoordP4uiv");
		FetchProcAddress(glMultiTexCoordP1ui, "glMultiTexCoordP1ui");
		FetchProcAddress(glMultiTexCoordP1uiv, "glMultiTexCoordP1uiv");
		FetchProcAddress(glMultiTexCoordP2ui, "glMultiTexCoordP2ui");
		FetchProcAddress(glMultiTexCoordP2uiv, "glMultiTexCoordP2uiv");
		FetchProcAddress(glMultiTexCoordP3ui, "glMultiTexCoordP3ui");
		FetchProcAddress(glMultiTexCoordP3uiv, "glMultiTexCoordP3uiv");
		FetchProcAddress(glMultiTexCoordP4ui, "glMultiTexCoordP4ui");
		FetchProcAddress(glMultiTexCoordP4uiv, "glMultiTexCoordP4uiv");
		FetchProcAddress(glNormalP3ui, "glNormalP3ui");
		FetchProcAddress(glNormalP3uiv, "glNormalP3uiv");
		FetchProcAddress(glColorP3ui, "glColorP3ui");
		FetchProcAddress(glColorP3uiv, "glColorP3uiv");
		FetchProcAddress(glColorP4ui, "glColorP4ui");
		FetchProcAddress(glColorP4uiv, "glColorP4uiv");
		FetchProcAddress(glSecondaryColorP3ui, "glSecondaryColorP3ui");
		FetchProcAddress(glSecondaryColorP3uiv, "glSecondaryColorP3uiv");
	}

	/**< load OpenGL 4.0 extensions */
	void Load4_0Extensions()
	{
		FetchProcAddress(glMinSampleShading, "glMinSampleShading");
		FetchProcAddress(glBlendEquationi, "glBlendEquationi");
		FetchProcAddress(glBlendEquationSeparatei, "glBlendEquationSeparatei");
		FetchProcAddress(glBlendFunci, "glBlendFunci");
		FetchProcAddress(glBlendFuncSeparatei, "glBlendFuncSeparatei");
		FetchProcAddress(glDrawArraysIndirect, "glDrawArraysIndirect");
		FetchProcAddress(glDrawElementsIndirect, "glDrawElementsIndirect");
		FetchProcAddress(glUniform1d, "glUniform1d");
		FetchProcAddress(glUniform2d, "glUniform2d");
		FetchProcAddress(glUniform3d, "glUniform3d");
		FetchProcAddress(glUniform4d, "glUniform4d");
		FetchProcAddress(glUniform1dv, "glUniform1dv");
		FetchProcAddress(glUniform2dv, "glUniform2dv");
		FetchProcAddress(glUniform3dv, "glUniform3dv");
		FetchProcAddress(glUniform4dv, "glUniform4dv");
		FetchProcAddress(glUniformMatrix2dv, "glUniformMatrix2dv");
		FetchProcAddress(glUniformMatrix3dv, "glUniformMatrix3dv");
		FetchProcAddress(glUniformMatrix4dv, "glUniformMatrix4dv");
		FetchProcAddress(glUniformMatrix2x3dv, "glUniformMatrix2x3dv");
		FetchProcAddress(glUniformMatrix2x4dv, "glUniformMatrix2x4dv");
		FetchProcAddress(glUniformMatrix3x2dv, "glUniformMatrix3x2dv");
		FetchProcAddress(glUniformMatrix3x4dv, "glUniformMatrix3x4dv");
		FetchProcAddress(glUniformMatrix4x2dv, "glUniformMatrix4x2dv");
		FetchProcAddress(glUniformMatrix4x3dv, "glUniformMatrix4x3dv");
		FetchProcAddress(glGetUniformdv, "glGetUniformdv");
		FetchProcAddress(glGetSubroutineUniformLocation, "glGetSubroutineUniformLocation");
		FetchProcAddress(glGetSubroutineIndex, "glGetSubroutineIndex");
		FetchProcAddress(glGetActiveSubroutineUniformiv, "glGetActiveSubroutineUniformiv");
		FetchProcAddress(glGetActiveSubroutineUniformName, "glGetActiveSubroutineUniformName");
		FetchProcAddress(glGetActiveSubroutineName, "glGetActiveSubroutineName");
		FetchProcAddress(glUniformSubroutinesuiv, "glUniformSubroutinesuiv");
		FetchProcAddress(glGetUniformSubroutineuiv, "glGetUniformSubroutineuiv");
		FetchProcAddress(glGetProgramStageiv, "glGetProgramStageiv");
		FetchProcAddress(glPatchParameteri, "glPatchParameteri");
		FetchProcAddress(glPatchParameterfv, "glPatchParameterfv");
		FetchProcAddress(glBindTransformFeedback, "glBindTransformFeedback");
		FetchProcAddress(glDeleteTransformFeedbacks, "glDeleteTransformFeedbacks");
		FetchProcAddress(glGenTransformFeedbacks, "glGenTransformFeedbacks");
		FetchProcAddress(glIsTransformFeedback, "glIsTransformFeedback");
		FetchProcAddress(glPauseTransformFeedback, "glPauseTransformFeedback");
		FetchProcAddress(glResumeTransformFeedback, "glResumeTransformFeedback");
		FetchProcAddress(glDrawTransformFeedback, "glDrawTransformFeedback");
		FetchProcAddress(glDrawTransformFeedbackStream, "glDrawTransformFeedbackStream");
		FetchProcAddress(glBeginQueryIndexed, "glBeginQueryIndexed");
		FetchProcAddress(glEndQueryIndexed, "glEndQueryIndexed");
		FetchProcAddress(glGetQueryIndexediv, "glGetQueryIndexediv");
	}

	/**< load OpenGL 4.1 extensions */
	void Load4_1Extensions()
	{
		FetchProcAddress(glReleaseShaderCompiler, "glReleaseShaderCompiler");
		FetchProcAddress(glShaderBinary, "glShaderBinary");
		FetchProcAddress(glGetShaderPrecisionFormat, "glGetShaderPrecisionFormat");
		FetchProcAddress(glDepthRangef, "glDepthRangef");
		FetchProcAddress(glClearDepthf, "glClearDepthf");
		FetchProcAddress(glGetProgramBinary, "glGetProgramBinary");
		FetchProcAddress(glProgramBinary, "glProgramBinary");
		FetchProcAddress(glProgramParameteri, "glProgramParameteri");
		FetchProcAddress(glUseProgramStages, "glUseProgramStages");
		FetchProcAddress(glActiveShaderProgram, "glActiveShaderProgram");
		FetchProcAddress(glCreateShaderProgramv, "glCreateShaderProgramv");
		FetchProcAddress(glBindProgramPipeline, "glBindProgramPipeline");
		FetchProcAddress(glDeleteProgramPipelines, "glDeleteProgramPipelines");
		FetchProcAddress(glGenProgramPipelines, "glGenProgramPipelines");
		FetchProcAddress(glIsProgramPipeline, "glIsProgramPipeline");
		FetchProcAddress(glGetProgramPipelineiv, "glGetProgramPipelineiv");
		FetchProcAddress(glProgramUniform1i, "glProgramUniform1i");
		FetchProcAddress(glProgramUniform1iv, "glProgramUniform1iv");
		FetchProcAddress(glProgramUniform1f, "glProgramUniform1f");
		FetchProcAddress(glProgramUniform1fv, "glProgramUniform1fv");
		FetchProcAddress(glProgramUniform1d, "glProgramUniform1d");
		FetchProcAddress(glProgramUniform1dv, "glProgramUniform1dv");
		FetchProcAddress(glProgramUniform1ui, "glProgramUniform1ui");
		FetchProcAddress(glProgramUniform1uiv, "glProgramUniform1uiv");
		FetchProcAddress(glProgramUniform2i, "glProgramUniform2i");
		FetchProcAddress(glProgramUniform2iv, "glProgramUniform2iv");
		FetchProcAddress(glProgramUniform2f, "glProgramUniform2f");
		FetchProcAddress(glProgramUniform2fv, "glProgramUniform2fv");
		FetchProcAddress(glProgramUniform2d, "glProgramUniform2d");
		FetchProcAddress(glProgramUniform2dv, "glProgramUniform2dv");
		FetchProcAddress(glProgramUniform2ui, "glProgramUniform2ui");
		FetchProcAddress(glProgramUniform2uiv, "glProgramUniform2uiv");
		FetchProcAddress(glProgramUniform3i, "glProgramUniform3i");
		FetchProcAddress(glProgramUniform3iv, "glProgramUniform3iv");
		FetchProcAddress(glProgramUniform3f, "glProgramUniform3f");
		FetchProcAddress(glProgramUniform3fv, "glProgramUniform3fv");
		FetchProcAddress(glProgramUniform3d, "glProgramUniform3d");
		FetchProcAddress(glProgramUniform3dv, "glProgramUniform3dv");
		FetchProcAddress(glProgramUniform3ui, "glProgramUniform3ui");
		FetchProcAddress(glProgramUniform3uiv, "glProgramUniform3uiv");
		FetchProcAddress(glProgramUniform4i, "glProgramUniform4i");
		FetchProcAddress(glProgramUniform4iv, "glProgramUniform4iv");
		FetchProcAddress(glProgramUniform4f, "glProgramUniform4f");
		FetchProcAddress(glProgramUniform4fv, "glProgramUniform4fv");
		FetchProcAddress(glProgramUniform4d, "glProgramUniform4d");
		FetchProcAddress(glProgramUniform4dv, "glProgramUniform4dv");
		FetchProcAddress(glProgramUniform4ui, "glProgramUniform4ui");
		FetchProcAddress(glProgramUniform4uiv, "glProgramUniform4uiv");
		FetchProcAddress(glProgramUniformMatrix2fv, "glProgramUniformMatrix2fv");
		FetchProcAddress(glProgramUniformMatrix3fv, "glProgramUniformMatrix3fv");
		FetchProcAddress(glProgramUniformMatrix4fv, "glProgramUniformMatrix4fv");
		FetchProcAddress(glProgramUniformMatrix2dv, "glProgramUniformMatrix2dv");
		FetchProcAddress(glProgramUniformMatrix3dv, "glProgramUniformMatrix3dv");
		FetchProcAddress(glProgramUniformMatrix4dv, "glProgramUniformMatrix4dv");
		FetchProcAddress(glProgramUniformMatrix2x3fv, "glProgramUniformMatrix2x3fv");
		FetchProcAddress(glProgramUniformMatrix3x2fv, "glProgramUniformMatrix3x2fv");
		FetchProcAddress(glProgramUniformMatrix2x4fv, "glProgramUniformMatrix2x4fv");
		FetchProcAddress(glProgramUniformMatrix4x2fv, "glProgramUniformMatrix4x2fv");
		FetchProcAddress(glProgramUniformMatrix3x4fv, "glProgramUniformMatrix3x4fv");
		FetchProcAddress(glProgramUniformMatrix4x3fv, "glProgramUniformMatrix4x3fv");
		FetchProcAddress(glProgramUniformMatrix2x3dv, "glProgramUniformMatrix2x3dv");
		FetchProcAddress(glProgramUniformMatrix3x2dv, "glProgramUniformMatrix3x2dv");
		FetchProcAddress(glProgramUniformMatrix2x4dv, "glProgramUniformMatrix2x4dv");
		FetchProcAddress(glProgramUniformMatrix4x2dv, "glProgramUniformMatrix4x2dv");
		FetchProcAddress(glProgramUniformMatrix3x4dv, "glProgramUniformMatrix3x4dv");
		FetchProcAddress(glProgramUniformMatrix4x3dv, "glProgramUniformMatrix4x3dv");
		FetchProcAddress(glValidateProgramPipeline, "glValidateProgramPipeline");
		FetchProcAddress(glGetProgramPipelineInfoLog, "glGetProgramPipelineInfoLog");
		FetchProcAddress(glVertexAttribL1d, "glVertexAttribL1d");
		FetchProcAddress(glVertexAttribL2d, "glVertexAttribL2d");
		FetchProcAddress(glVertexAttribL3d, "glVertexAttribL3d");
		FetchProcAddress(glVertexAttribL4d, "glVertexAttribL4d");
		FetchProcAddress(glVertexAttribL1dv, "glVertexAttribL1dv");
		FetchProcAddress(glVertexAttribL2dv, "glVertexAttribL2dv");
		FetchProcAddress(glVertexAttribL3dv, "glVertexAttribL3dv");
		FetchProcAddress(glVertexAttribL4dv, "glVertexAttribL4dv");
		FetchProcAddress(glVertexAttribLPointer, "glVertexAttribLPointer");
		FetchProcAddress(glGetVertexAttribLdv, "glGetVertexAttribLdv");
		FetchProcAddress(glViewportArrayv, "glViewportArrayv");
		FetchProcAddress(glViewportIndexedf, "glViewportIndexedf");
		FetchProcAddress(glViewportIndexedfv, "glViewportIndexedfv");
		FetchProcAddress(glScissorArrayv, "glScissorArrayv");
		FetchProcAddress(glScissorIndexed, "glScissorIndexed");
		FetchProcAddress(glScissorIndexedv, "glScissorIndexedv");
		FetchProcAddress(glDepthRangeIndexed, "glDepthRangeIndexed");
		FetchProcAddress(glDepthRangeArrayv, "glDepthRangeArrayv");
		FetchProcAddress(glGetFloati_v, "glGetFloati_v");
		FetchProcAddress(glGetDoublei_v, "glGetDoublei_v");
	}

	/**< load OpenGL 4.2 extensions */
	void Load4_2Extensions()
	{
		FetchProcAddress(glDrawArraysInstancedBaseInstance, "glDrawArraysInstancedBaseInstance");
		FetchProcAddress(glDrawElementsInstancedBaseInstance, "glDrawElementsInstancedBaseInstance");
		FetchProcAddress(glDrawElementsInstancedBaseVertexBaseInstance, "glDrawElementsInstancedBaseVertexBaseInstance");
		FetchProcAddress(glGetInternalformativ, "glGetInternalformativ");
		FetchProcAddress(glGetActiveAtomicCounterBufferiv, "glGetActiveAtomicCounterBufferiv");
		FetchProcAddress(glBindImageTexture, "glBindImageTexture");
		FetchProcAddress(glMemoryBarrier, "glMemoryBarrier");
		FetchProcAddress(glTexStorage1D, "glTexStorage1D");
		FetchProcAddress(glTexStorage2D, "glTexStorage2D");
		FetchProcAddress(glTexStorage3D, "glTexStorage3D");
		FetchProcAddress(glDrawTransformFeedbackInstanced, "glDrawTransformFeedbackInstanced");
		FetchProcAddress(glDrawTransformFeedbackStreamInstanced, "glDrawTransformFeedbackStreamInstanced");
	}

	/**< load OpenGL 4.3 extensions */
	void Load4_3Extensions()
	{
		FetchProcAddress(glClearBufferData, "glClearBufferData");
		FetchProcAddress(glClearBufferSubData, "glClearBufferSubData");
		FetchProcAddress(glDispatchCompute, "glDispatchCompute");
		FetchProcAddress(glDispatchComputeIndirect, "glDispatchComputeIndirect");
		FetchProcAddress(glCopyImageSubData, "glCopyImageSubData");
		FetchProcAddress(glFramebufferParameteri, "glFramebufferParameteri");
		FetchProcAddress(glGetFramebufferParameteriv, "glGetFramebufferParameteriv");
		FetchProcAddress(glGetInternalformati64v, "glGetInternalformati64v");
		FetchProcAddress(glInvalidateTexSubImage, "glInvalidateTexSubImage");
		FetchProcAddress(glInvalidateTexImage, "glInvalidateTexImage");
		FetchProcAddress(glInvalidateBufferSubData, "glInvalidateBufferSubData");
		FetchProcAddress(glInvalidateBufferData, "glInvalidateBufferData");
		FetchProcAddress(glInvalidateFramebuffer, "glInvalidateFramebuffer");
		FetchProcAddress(glInvalidateSubFramebuffer, "glInvalidateSubFramebuffer");
		FetchProcAddress(glMultiDrawArraysIndirect, "glMultiDrawArraysIndirect");
		FetchProcAddress(glMultiDrawElementsIndirect, "glMultiDrawElementsIndirect");
		FetchProcAddress(glGetProgramInterfaceiv, "glGetProgramInterfaceiv");
		FetchProcAddress(glGetProgramResourceIndex, "glGetProgramResourceIndex");
		FetchProcAddress(glGetProgramResourceName, "glGetProgramResourceName");
		FetchProcAddress(glGetProgramResourceiv, "glGetProgramResourceiv");
		FetchProcAddress(glGetProgramResourceLocation, "glGetProgramResourceLocation");
		FetchProcAddress(glGetProgramResourceLocationIndex, "glGetProgramResourceLocationIndex");
		FetchProcAddress(glShaderStorageBlockBinding, "glShaderStorageBlockBinding");
		FetchProcAddress(glTexBufferRange, "glTexBufferRange");
		FetchProcAddress(glTexStorage2DMultisample, "glTexStorage2DMultisample");
		FetchProcAddress(glTexStorage3DMultisample, "glTexStorage3DMultisample");
		FetchProcAddress(glTextureView, "glTextureView");
		FetchProcAddress(glBindVertexBuffer, "glBindVertexBuffer");
		FetchProcAddress(glVertexAttribFormat, "glVertexAttribFormat");
		FetchProcAddress(glVertexAttribIFormat, "glVertexAttribIFormat");
		FetchProcAddress(glVertexAttribLFormat, "glVertexAttribLFormat");
		FetchProcAddress(glVertexAttribBinding, "glVertexAttribBinding");
		FetchProcAddress(glVertexBindingDivisor, "glVertexBindingDivisor");
		FetchProcAddress(glDebugMessageControl, "glDebugMessageControl");
		FetchProcAddress(glDebugMessageInsert, "glDebugMessageInsert");
		FetchProcAddress(glDebugMessageCallback, "glDebugMessageCallback");
		FetchProcAddress(glGetDebugMessageLog, "glGetDebugMessageLog");
		FetchProcAddress(glPushDebugGroup, "glPushDebugGroup");
		FetchProcAddress(glPopDebugGroup, "glPopDebugGroup");
		FetchProcAddress(glObjectLabel, "glObjectLabel");
		FetchProcAddress(glObjectPtrLabel, "glObjectPtrLabel");
		FetchProcAddress(glGetObjectLabel, "glGetObjectLabel");
		FetchProcAddress(glGetObjectPtrLabel, "glGetObjectPtrLabel");
	}

	/**< load OpenGL 4.4 extensions */
	void Load4_4Extensions()
	{
		FetchProcAddress(glBufferStorage, "glBufferStorage");
		FetchProcAddress(glClearTexImage, "glClearTexImage");
		FetchProcAddress(glClearTexSubImage, "glClearTexSubImage");
		FetchProcAddress(glBindBuffersBase, "glBindBuffersBase");
		FetchProcAddress(glBindBuffersRange, "glBindBuffersRange");
		FetchProcAddress(glBindTextures, "glBindTextures");
		FetchProcAddress(glBindSamplers, "glBindSamplers");
		FetchProcAddress(glBindImageTextures, "glBindImageTextures");
		FetchProcAddress(glBindVertexBuffers, "glBindVertexBuffers");
	}

	/**< load all applicable OpenGL extensions */
	std::error_code InitializeExtentions()
	{
		std::error_code errCode = InitializeGLVersion();
		if (errCode == TinyExtender::error_t::versionLoadFailed)
		{
			return 	errCode;
		}

		if (glVersionMajor > 1 || (glVersionMinor >= 2 && glVersionMajor >= 1))
		{
			Load1_2Extensions();
		}

		else
		{
			return TinyExtender::error_t::Unsupported1_2;
		}

		if (glVersionMajor > 1 || (glVersionMinor >= 3 && glVersionMajor >= 1))
		{
			Load1_3Extensions();
		}

		else
		{
			return TinyExtender::error_t::Unsupported1_3;
		}

		if (glVersionMajor > 1 || (glVersionMinor >= 4 && glVersionMajor >= 1))
		{
			Load1_4Extensions();
		}

		else
		{
			return TinyExtender::error_t::Unsupported1_4;
		}

		if (glVersionMajor > 1 || (glVersionMinor >= 5 && glVersionMajor >= 1))
		{
			Load1_5Extensions();
		}

		else
		{
			return TinyExtender::error_t::Unsupported1_5;
		}

		if (glVersionMajor >= 2)
		{
			Load2_0Extensions();
		}

		else
		{
			return TinyExtender::error_t::Unsupported2_0;
		}

		if (glVersionMajor > 2 || (glVersionMinor >= 1 && glVersionMajor >= 2))
		{
			Load2_1Extensions();
		}

		else
		{
			return TinyExtender::error_t::Unsupported2_1;
		}

		if (glVersionMajor >= 3)
		{
			Load3_0Extensions();
		}

		else
		{
			return TinyExtender::error_t::Unsupported3_0;
		}

		if (glVersionMajor > 3 || (glVersionMinor >= 1 && glVersionMajor >= 3))
		{
			Load3_1Extensions();
		}

		else
		{
			return TinyExtender::error_t::Unsupported3_1;
		}

		if (glVersionMajor > 3 || (glVersionMinor >= 2 && glVersionMajor >= 3))
		{
			Load3_2Extensions();
		}

		else
		{
			return TinyExtender::error_t::Unsupported3_2;
		}

		if (glVersionMajor > 3 || (glVersionMinor >= 3 && glVersionMajor >= 3))
		{
			Load3_3Extensions();
		}

		else
		{
			return TinyExtender::error_t::Unsupported3_3;
		}

		if (glVersionMajor >= 4)
		{
			Load4_0Extensions();
		}

		else
		{
			return TinyExtender::error_t::Unsupported4_0;
		}

		if (glVersionMajor > 4 || (glVersionMinor >= 1 && glVersionMajor >= 4))
		{
			Load4_1Extensions();
		}

		else
		{
			return TinyExtender::error_t::Unsupported4_1;
		}

		if (glVersionMajor > 4 || (glVersionMinor >= 2 && glVersionMajor >= 4))
		{
			Load4_2Extensions();
		}

		else
		{
			return TinyExtender::error_t::Unsupported4_2;
		}

		if (glVersionMajor > 4 || (glVersionMinor >= 3 && glVersionMajor >= 4))
		{
			Load4_3Extensions();
		}

		else
		{
			return TinyExtender::error_t::Unsupported4_3;
		}

		if (glVersionMajor > 4 || (glVersionMinor >= 4 && glVersionMajor >= 4))
		{
			Load4_4Extensions();
		}

		else
		{
			return TinyExtender::error_t::Unsupported4_4;
		}

		return TinyExtender::error_t::success;
	}

	/**< load specific OpenGL extensions via OpenGL versions */
	std::error_code InitializeExtensionsSpecific(unsigned int OpenGLVersions)
	{
		if (OpenGLVersions & glVersion_t::version1_2)
		{
			if (glVersionMajor > 1 || (glVersionMinor >= 2 && glVersionMajor >= 1))
			{
				Load1_2Extensions();
			}

			else
			{
				return TinyExtender::error_t::Unsupported1_2;
			}
		}

		if (OpenGLVersions & glVersion_t::version1_3)
		{
			if (glVersionMajor > 1 || (glVersionMinor >= 3 && glVersionMajor >= 1))
			{
				Load1_3Extensions();
			}

			else
			{
				return TinyExtender::error_t::Unsupported1_3;
			}
		}

		if (OpenGLVersions & glVersion_t::version1_4)
		{
			if (glVersionMajor > 1 || (glVersionMinor >= 4 && glVersionMajor >= 1))
			{
				Load1_4Extensions();
			}

			else
			{
				return TinyExtender::error_t::Unsupported1_4;
			}
		}

		if (OpenGLVersions & glVersion_t::version1_5)
		{
			if (glVersionMajor > 1 || (glVersionMinor >= 5 && glVersionMajor >= 1))
			{
				Load1_5Extensions();
			}

			else
			{
				return TinyExtender::error_t::Unsupported1_5;
			}
		}

		if (OpenGLVersions & glVersion_t::version2_0)
		{
			if (glVersionMajor > 2)
			{
				Load2_0Extensions();
			}

			else
			{
				return TinyExtender::error_t::Unsupported2_0;
			}
		}

		if (OpenGLVersions & glVersion_t::version2_1)
		{
			if (glVersionMajor > 2 || (glVersionMinor >= 1 && glVersionMajor >= 2))
			{
				Load2_1Extensions();
			}

			else
			{
				return TinyExtender::error_t::Unsupported2_1;
			}
		}

		if (OpenGLVersions & glVersion_t::version3_0)
		{
			if (glVersionMajor > 3)
			{
				Load3_0Extensions();
			}

			else
			{
				return TinyExtender::error_t::Unsupported3_0;
			}
		}

		if (OpenGLVersions & glVersion_t::version3_1)
		{
			if (glVersionMajor > 3 || (glVersionMinor >= 1 && glVersionMajor >= 3))
			{
				Load3_1Extensions();
			}

			else
			{
				return TinyExtender::error_t::Unsupported3_1;
			}
		}

		if (OpenGLVersions & glVersion_t::version3_2)
		{
			if (glVersionMajor > 3 || (glVersionMinor >= 2 && glVersionMajor >= 3))
			{
				Load3_2Extensions();
			}

			else
			{
				return TinyExtender::error_t::Unsupported3_2;
			}
		}

		if (OpenGLVersions & glVersion_t::version3_3)
		{
			if (glVersionMajor > 3 || (glVersionMinor >= 3 && glVersionMajor >= 3))
			{
				Load3_3Extensions();
			}

			else
			{
				return TinyExtender::error_t::Unsupported3_3;
			}
		}

		if (OpenGLVersions & glVersion_t::version4_0)
		{
			if (glVersionMajor > 4)
			{
				Load4_0Extensions();
			}

			else
			{
				return TinyExtender::error_t::Unsupported4_0;
			}
		}

		if (OpenGLVersions & glVersion_t::version4_1)
		{
			if (glVersionMajor > 4 || (glVersionMinor >= 1 && glVersionMajor >= 4))
			{
				Load4_1Extensions();
			}

			else
			{
				return TinyExtender::error_t::Unsupported4_1;
			}
		}

		if (OpenGLVersions & glVersion_t::version4_2)
		{
			if (glVersionMajor > 4 || (glVersionMinor >= 2 && glVersionMajor >= 4))
			{
				Load4_2Extensions();
			}

			else
			{
				return TinyExtender::error_t::Unsupported4_2;
			}
		}

		if (OpenGLVersions & glVersion_t::version4_3)
		{
			if (glVersionMajor > 4 || (glVersionMinor >= 3 && glVersionMajor >= 4))
			{
				Load4_3Extensions();
			}

			else
			{
				return TinyExtender::error_t::Unsupported4_3;
			}
		}

		if (OpenGLVersions & glVersion_t::version4_4)
		{
			if (glVersionMajor > 4 || (glVersionMinor >= 4 && glVersionMajor >= 4))
			{
				Load4_4Extensions();
			}

			else
			{
				return TinyExtender::error_t::Unsupported4_4;
			}
		}

		return TinyExtender::error_t::success;
	}

	/**< whether an extension is supported */
	bool IsExtensionSupported(const char* extensionName)
	{
		GLubyte* end;//the last extension name in Extensions
		size_t	nameLength; //the string length of the extension name

		nameLength = strlen((const char*)extensionName);

		GLubyte* allExtensions = (GLubyte*)glGetString(GL_EXTENSIONS); //get all supported extensions

		if (allExtensions != NULL)
		{
			end = allExtensions + strlen((const char*)allExtensions);

			while (allExtensions < end)
			{
				size_t str = strcspn((const char*)allExtensions, " ");

				if ((nameLength == str) && (strncmp((const char*)extensionName, (const char*)allExtensions, str) == 0))
				{
					return true;
				}

				allExtensions += (str + 1);
			}
			return false;
		}
		return false;
	}

}
#endif
