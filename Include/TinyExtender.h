#ifndef TINYEXTENDER_H_
#define TINYEXTENDER_H_

#if defined(_WIN32)
#include <Windows.h>
#include <gl/GL.h>
#endif

#if defined(__linux__)
#include <GL/glx.h>
#endif

#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <functional>

namespace TinyExtender
{
	enum glVersion_t
	{
		version1_2 = 1L << 1,
		version1_3 = 1L << 2,
		version1_4 = 1L << 3,
		version1_5 = 1L << 4,
		version2_0 = 1L << 5,
		version2_1 = 1L << 6,
		version3_0 = 1L << 7,
		version3_1 = 1L << 8,
		version3_2 = 1L << 9,
		version3_3 = 1L << 10,
		version4_0 = 1L << 11,
		version4_1 = 1L << 12,
		version4_2 = 1L << 13,
		version4_3 = 1L << 14,
		version4_4 = 1L << 15,
	};

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

//OpenGL 1.2 Extensions
#define GL_UNSIGNED_BYTE_3_3_2            0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4         0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1         0x8034
#define GL_UNSIGNED_INT_8_8_8_8           0x8035
#define GL_UNSIGNED_INT_10_10_10_2        0x8036
#define GL_TEXTURE_BINDING_3D             0x806A
#define GL_PACK_SKIP_IMAGES               0x806B
#define GL_PACK_IMAGE_HEIGHT              0x806C
#define GL_UNPACK_SKIP_IMAGES             0x806D
#define GL_UNPACK_IMAGE_HEIGHT            0x806E
#define GL_TEXTURE_3D                     0x806F
#define GL_PROXY_TEXTURE_3D               0x8070
#define GL_TEXTURE_DEPTH                  0x8071
#define GL_TEXTURE_WRAP_R                 0x8072
#define GL_MAX_3D_TEXTURE_SIZE            0x8073
#define GL_UNSIGNED_BYTE_2_3_3_REV        0x8362
#define GL_UNSIGNED_SHORT_5_6_5           0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV       0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV     0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV     0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV       0x8367
#define GL_UNSIGNED_INT_2_10_10_10_REV    0x8368
#define GL_BGR                            0x80E0
#define GL_BGRA                           0x80E1
#define GL_MAX_ELEMENTS_VERTICES          0x80E8
#define GL_MAX_ELEMENTS_INDICES           0x80E9
#define GL_CLAMP_TO_EDGE                  0x812F
#define GL_TEXTURE_MIN_LOD                0x813A
#define GL_TEXTURE_MAX_LOD                0x813B
#define GL_TEXTURE_BASE_LEVEL             0x813C
#define GL_TEXTURE_MAX_LEVEL              0x813D
#define GL_SMOOTH_POINT_SIZE_RANGE        0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY  0x0B13
#define GL_SMOOTH_LINE_WIDTH_RANGE        0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY  0x0B23
#define GL_ALIASED_LINE_WIDTH_RANGE       0x846E
#define GL_RESCALE_NORMAL                 0x803A
#define GL_LIGHT_MODEL_COLOR_CONTROL      0x81F8
#define GL_SINGLE_COLOR                   0x81F9
#define GL_SEPARATE_SPECULAR_COLOR        0x81FA
#define GL_ALIASED_POINT_SIZE_RANGE       0x846D
typedef void (*DrawRangeElements_t) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
typedef void (*TexImage3D_t) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (*TexSubImage3D_t) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (*CopyTexSubImage3D_t) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);

//OpenGL 1.3 Extensions
#define GL_TEXTURE0                       0x84C0
#define GL_TEXTURE1                       0x84C1
#define GL_TEXTURE2                       0x84C2
#define GL_TEXTURE3                       0x84C3
#define GL_TEXTURE4                       0x84C4
#define GL_TEXTURE5                       0x84C5
#define GL_TEXTURE6                       0x84C6
#define GL_TEXTURE7                       0x84C7
#define GL_TEXTURE8                       0x84C8
#define GL_TEXTURE9                       0x84C9
#define GL_TEXTURE10                      0x84CA
#define GL_TEXTURE11                      0x84CB
#define GL_TEXTURE12                      0x84CC
#define GL_TEXTURE13                      0x84CD
#define GL_TEXTURE14                      0x84CE
#define GL_TEXTURE15                      0x84CF
#define GL_TEXTURE16                      0x84D0
#define GL_TEXTURE17                      0x84D1
#define GL_TEXTURE18                      0x84D2
#define GL_TEXTURE19                      0x84D3
#define GL_TEXTURE20                      0x84D4
#define GL_TEXTURE21                      0x84D5
#define GL_TEXTURE22                      0x84D6
#define GL_TEXTURE23                      0x84D7
#define GL_TEXTURE24                      0x84D8
#define GL_TEXTURE25                      0x84D9
#define GL_TEXTURE26                      0x84DA
#define GL_TEXTURE27                      0x84DB
#define GL_TEXTURE28                      0x84DC
#define GL_TEXTURE29                      0x84DD
#define GL_TEXTURE30                      0x84DE
#define GL_TEXTURE31                      0x84DF
#define GL_ACTIVE_TEXTURE                 0x84E0
#define GL_MULTISAMPLE                    0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE       0x809E
#define GL_SAMPLE_ALPHA_TO_ONE            0x809F
#define GL_SAMPLE_COVERAGE                0x80A0
#define GL_SAMPLE_BUFFERS                 0x80A8
#define GL_SAMPLES                        0x80A9
#define GL_SAMPLE_COVERAGE_VALUE          0x80AA
#define GL_SAMPLE_COVERAGE_INVERT         0x80AB
#define GL_TEXTURE_CUBE_MAP               0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP       0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X    0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X    0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y    0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y    0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z    0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z    0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP         0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE      0x851C
#define GL_COMPRESSED_RGB                 0x84ED
#define GL_COMPRESSED_RGBA                0x84EE
#define GL_TEXTURE_COMPRESSION_HINT       0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE  0x86A0
#define GL_TEXTURE_COMPRESSED             0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS     0x86A3
#define GL_CLAMP_TO_BORDER                0x812D
#define GL_CLIENT_ACTIVE_TEXTURE          0x84E1
#define GL_MAX_TEXTURE_UNITS              0x84E2
#define GL_TRANSPOSE_MODELVIEW_MATRIX     0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX    0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX       0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX         0x84E6
#define GL_MULTISAMPLE_BIT                0x20000000
#define GL_NORMAL_MAP                     0x8511
#define GL_REFLECTION_MAP                 0x8512
#define GL_COMPRESSED_ALPHA               0x84E9
#define GL_COMPRESSED_LUMINANCE           0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA     0x84EB
#define GL_COMPRESSED_INTENSITY           0x84EC
#define GL_COMBINE                        0x8570
#define GL_COMBINE_RGB                    0x8571
#define GL_COMBINE_ALPHA                  0x8572
#define GL_SOURCE0_RGB                    0x8580
#define GL_SOURCE1_RGB                    0x8581
#define GL_SOURCE2_RGB                    0x8582
#define GL_SOURCE0_ALPHA                  0x8588
#define GL_SOURCE1_ALPHA                  0x8589
#define GL_SOURCE2_ALPHA                  0x858A
#define GL_OPERAND0_RGB                   0x8590
#define GL_OPERAND1_RGB                   0x8591
#define GL_OPERAND2_RGB                   0x8592
#define GL_OPERAND0_ALPHA                 0x8598
#define GL_OPERAND1_ALPHA                 0x8599
#define GL_OPERAND2_ALPHA                 0x859A
#define GL_RGB_SCALE                      0x8573
#define GL_ADD_SIGNED                     0x8574
#define GL_INTERPOLATE                    0x8575
#define GL_SUBTRACT                       0x84E7
#define GL_CONSTANT                       0x8576
#define GL_PRIMARY_COLOR                  0x8577
#define GL_PREVIOUS                       0x8578
#define GL_DOT3_RGB                       0x86AE
#define GL_DOT3_RGBA                      0x86AF
typedef void (*ActiveTexture_t) (GLenum texture);
typedef void (*SampleCoverage_t) (GLfloat value, GLboolean invert);
typedef void (*CompressedTexImage3D_t) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
typedef void (*CompressedTexImage2D_t) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
typedef void (*CompressedTexImage1D_t) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
typedef void (*CompressedTexSubImage3D_t) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
typedef void (*CompressedTexSubImage2D_t) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
typedef void (*CompressedTexSubImage1D_t) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
typedef void (*GetCompressedTexImage_t) (GLenum target, GLint level, void *img);
typedef void (*ClientActiveTexture_t) (GLenum texture);
typedef void (*MultiTexCoord1d_t) (GLenum target, GLdouble s);
typedef void (*MultiTexCoord1dv_t) (GLenum target, const GLdouble *v);
typedef void (*MultiTexCoord1f_t) (GLenum target, GLfloat s);
typedef void (*MultiTexCoord1fv_t) (GLenum target, const GLfloat *v);
typedef void (*MultiTexCoord1i_t) (GLenum target, GLint s);
typedef void (*MultiTexCoord1iv_t) (GLenum target, const GLint *v);
typedef void (*MultiTexCoord1s_t) (GLenum target, GLshort s);
typedef void (*MultiTexCoord1sv_t) (GLenum target, const GLshort *v);
typedef void (*MultiTexCoord2d_t) (GLenum target, GLdouble s, GLdouble t);
typedef void (*MultiTexCoord2dv_t) (GLenum target, const GLdouble *v);
typedef void (*MultiTexCoord2f_t) (GLenum target, GLfloat s, GLfloat t);
typedef void (*MultiTexCoord2fv_t) (GLenum target, const GLfloat *v);
typedef void (*MultiTexCoord2i_t) (GLenum target, GLint s, GLint t);
typedef void (*MultiTexCoord2iv_t) (GLenum target, const GLint *v);
typedef void (*MultiTexCoord2s_t) (GLenum target, GLshort s, GLshort t);
typedef void (*MultiTexCoord2sv_t) (GLenum target, const GLshort *v);
typedef void (*MultiTexCoord3d_t) (GLenum target, GLdouble s, GLdouble t, GLdouble r);
typedef void (*MultiTexCoord3dv_t) (GLenum target, const GLdouble *v);
typedef void (*MultiTexCoord3f_t) (GLenum target, GLfloat s, GLfloat t, GLfloat r);
typedef void (*MultiTexCoord3fv_t) (GLenum target, const GLfloat *v);
typedef void (*MultiTexCoord3i_t) (GLenum target, GLint s, GLint t, GLint r);
typedef void (*MultiTexCoord3iv_t) (GLenum target, const GLint *v);
typedef void (*MultiTexCoord3s_t) (GLenum target, GLshort s, GLshort t, GLshort r);
typedef void (*MultiTexCoord3sv_t) (GLenum target, const GLshort *v);
typedef void (*MultiTexCoord4d_t) (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void (*MultiTexCoord4dv_t) (GLenum target, const GLdouble *v);
typedef void (*MultiTexCoord4f_t) (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void (*MultiTexCoord4fv_t) (GLenum target, const GLfloat *v);
typedef void (*MultiTexCoord4i_t) (GLenum target, GLint s, GLint t, GLint r, GLint q);
typedef void (*MultiTexCoord4iv_t) (GLenum target, const GLint *v);
typedef void (*MultiTexCoord4s_t) (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
typedef void (*MultiTexCoord4sv_t) (GLenum target, const GLshort *v);
typedef void (*LoadTransposeMatrixf_t) (const GLfloat *m);
typedef void (*LoadTransposeMatrixd_t) (const GLdouble *m);
typedef void (*MultTransposeMatrixf_t) (const GLfloat *m);
typedef void (*MultTransposeMatrixd_t) (const GLdouble *m);

//OpenGL 1.4 Extensions
#define GL_BLEND_DST_RGB                  0x80C8
#define GL_BLEND_SRC_RGB                  0x80C9
#define GL_BLEND_DST_ALPHA                0x80CA
#define GL_BLEND_SRC_ALPHA                0x80CB
#define GL_POINT_FADE_THRESHOLD_SIZE      0x8128
#define GL_DEPTH_COMPONENT16              0x81A5
#define GL_DEPTH_COMPONENT24              0x81A6
#define GL_DEPTH_COMPONENT32              0x81A7
#define GL_MIRRORED_REPEAT                0x8370
#define GL_MAX_TEXTURE_LOD_BIAS           0x84FD
#define GL_TEXTURE_LOD_BIAS               0x8501
#define GL_INCR_WRAP                      0x8507
#define GL_DECR_WRAP                      0x8508
#define GL_TEXTURE_DEPTH_SIZE             0x884A
#define GL_TEXTURE_COMPARE_MODE           0x884C
#define GL_TEXTURE_COMPARE_FUNC           0x884D
#define GL_POINT_SIZE_MIN                 0x8126
#define GL_POINT_SIZE_MAX                 0x8127
#define GL_POINT_DISTANCE_ATTENUATION     0x8129
#define GL_GENERATE_MIPMAP                0x8191
#define GL_GENERATE_MIPMAP_HINT           0x8192
#define GL_FOG_COORDINATE_SOURCE          0x8450
#define GL_FOG_COORDINATE                 0x8451
#define GL_FRAGMENT_DEPTH                 0x8452
#define GL_CURRENT_FOG_COORDINATE         0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE      0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE    0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER   0x8456
#define GL_FOG_COORDINATE_ARRAY           0x8457
#define GL_COLOR_SUM                      0x8458
#define GL_CURRENT_SECONDARY_COLOR        0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE     0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE     0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE   0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER  0x845D
#define GL_SECONDARY_COLOR_ARRAY          0x845E
#define GL_TEXTURE_FILTER_CONTROL         0x8500
#define GL_DEPTH_TEXTURE_MODE             0x884B
#define GL_COMPARE_R_TO_TEXTURE           0x884E
#define GL_FUNC_ADD                       0x8006
#define GL_FUNC_SUBTRACT                  0x800A
#define GL_FUNC_REVERSE_SUBTRACT          0x800B
#define GL_MIN                            0x8007
#define GL_MAX                            0x8008
#define GL_CONSTANT_COLOR                 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR       0x8002
#define GL_CONSTANT_ALPHA                 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA       0x8004
typedef void (*BlendFuncSeparate_t) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
typedef void (*MultiDrawArrays_t) (GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
typedef void (*MultiDrawElements_t) (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
typedef void (*PointParameterf_t) (GLenum pname, GLfloat param);
typedef void (*PointParameterfv_t) (GLenum pname, const GLfloat *params);
typedef void (*PointParameteri_t) (GLenum pname, GLint param);
typedef void (*PointParameteriv_t) (GLenum pname, const GLint *params);
typedef void (*FogCoordf_t) (GLfloat coord);
typedef void (*FogCoordfv_t) (const GLfloat *coord);
typedef void (*FogCoordd_t) (GLdouble coord);
typedef void (*FogCoorddv_t) (const GLdouble *coord);
typedef void (*FogCoordPointer_t) (GLenum type, GLsizei stride, const void *pointer);
typedef void (*SecondaryColor3b_t) (GLbyte red, GLbyte green, GLbyte blue);
typedef void (*SecondaryColor3bv_t) (const GLbyte *v);
typedef void (*SecondaryColor3d_t) (GLdouble red, GLdouble green, GLdouble blue);
typedef void (*SecondaryColor3dv_t) (const GLdouble *v);
typedef void (*SecondaryColor3f_t) (GLfloat red, GLfloat green, GLfloat blue);
typedef void (*SecondaryColor3fv_t) (const GLfloat *v);
typedef void (*SecondaryColor3i_t) (GLint red, GLint green, GLint blue);
typedef void (*SecondaryColor3iv_t) (const GLint *v);
typedef void (*SecondaryColor3s_t) (GLshort red, GLshort green, GLshort blue);
typedef void (*SecondaryColor3sv_t) (const GLshort *v);
typedef void (*SecondaryColor3ub_t) (GLubyte red, GLubyte green, GLubyte blue);
typedef void (*SecondaryColor3ubv_t) (const GLubyte *v);
typedef void (*SecondaryColor3ui_t) (GLuint red, GLuint green, GLuint blue);
typedef void (*SecondaryColor3uiv_t) (const GLuint *v);
typedef void (*SecondaryColor3us_t) (GLushort red, GLushort green, GLushort blue);
typedef void (*SecondaryColor3usv_t) (const GLushort *v);
typedef void (*SecondaryColorPointer_t) (GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (*WindowPos2d_t) (GLdouble x, GLdouble y);
typedef void (*WindowPos2dv_t) (const GLdouble *v);
typedef void (*WindowPos2f_t) (GLfloat x, GLfloat y);
typedef void (*WindowPos2fv_t) (const GLfloat *v);
typedef void (*WindowPos2i_t) (GLint x, GLint y);
typedef void (*WindowPos2iv_t) (const GLint *v);
typedef void (*WindowPos2s_t) (GLshort x, GLshort y);
typedef void (*WindowPos2sv_t) (const GLshort *v);
typedef void (*WindowPos3d_t) (GLdouble x, GLdouble y, GLdouble z);
typedef void (*WindowPos3dv_t) (const GLdouble *v);
typedef void (*WindowPos3f_t) (GLfloat x, GLfloat y, GLfloat z);
typedef void (*WindowPos3fv_t) (const GLfloat *v);
typedef void (*WindowPos3i_t) (GLint x, GLint y, GLint z);
typedef void (*WindowPos3iv_t) (const GLint *v);
typedef void (*WindowPos3s_t) (GLshort x, GLshort y, GLshort z);
typedef void (*WindowPos3sv_t) (const GLshort *v);
typedef void (*BlendColor_t) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (*BlendEquation_t) (GLenum mode);

//OpenGL 1.5 Extensions
typedef ptrdiff_t GLsizeiptr;
typedef ptrdiff_t GLintptr;
#define GL_BUFFER_SIZE                    0x8764
#define GL_BUFFER_USAGE                   0x8765
#define GL_QUERY_COUNTER_BITS             0x8864
#define GL_CURRENT_QUERY                  0x8865
#define GL_QUERY_RESULT                   0x8866
#define GL_QUERY_RESULT_AVAILABLE         0x8867
#define GL_ARRAY_BUFFER                   0x8892
#define GL_ELEMENT_ARRAY_BUFFER           0x8893
#define GL_ARRAY_BUFFER_BINDING           0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING   0x8895
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_READ_ONLY                      0x88B8
#define GL_WRITE_ONLY                     0x88B9
#define GL_READ_WRITE                     0x88BA
#define GL_BUFFER_ACCESS                  0x88BB
#define GL_BUFFER_MAPPED                  0x88BC
#define GL_BUFFER_MAP_POINTER             0x88BD
#define GL_STREAM_DRAW                    0x88E0
#define GL_STREAM_READ                    0x88E1
#define GL_STREAM_COPY                    0x88E2
#define GL_STATIC_DRAW                    0x88E4
#define GL_STATIC_READ                    0x88E5
#define GL_STATIC_COPY                    0x88E6
#define GL_DYNAMIC_DRAW                   0x88E8
#define GL_DYNAMIC_READ                   0x88E9
#define GL_DYNAMIC_COPY                   0x88EA
#define GL_SAMPLES_PASSED                 0x8914
#define GL_SRC1_ALPHA                     0x8589
#define GL_VERTEX_ARRAY_BUFFER_BINDING    0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING    0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING     0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING     0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING 0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING 0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING 0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING 0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING    0x889E
#define GL_FOG_COORD_SRC                  0x8450
#define GL_FOG_COORD                      0x8451
#define GL_CURRENT_FOG_COORD              0x8453
#define GL_FOG_COORD_ARRAY_TYPE           0x8454
#define GL_FOG_COORD_ARRAY_STRIDE         0x8455
#define GL_FOG_COORD_ARRAY_POINTER        0x8456
#define GL_FOG_COORD_ARRAY                0x8457
#define GL_FOG_COORD_ARRAY_BUFFER_BINDING 0x889D
#define GL_SRC0_RGB                       0x8580
#define GL_SRC1_RGB                       0x8581
#define GL_SRC2_RGB                       0x8582
#define GL_SRC0_ALPHA                     0x8588
#define GL_SRC2_ALPHA                     0x858A
typedef void (*GenQueries_t) (GLsizei n, GLuint *ids);
typedef void (*DeleteQueries_t) (GLsizei n, const GLuint *ids);
typedef GLboolean(*IsQuery_t) (GLuint id);
typedef void (*BeginQuery_t) (GLenum target, GLuint id);
typedef void (*EndQuery_t) (GLenum target);
typedef void (*GetQueryiv_t) (GLenum target, GLenum pname, GLint *params);
typedef void (*GetQueryObjectiv_t) (GLuint id, GLenum pname, GLint *params);
typedef void (*GetQueryObjectuiv_t) (GLuint id, GLenum pname, GLuint *params);
typedef void (*BindBuffer_t) (GLenum target, GLuint buffer);
typedef void (*DeleteBuffers_t) (GLsizei n, const GLuint *buffers);
typedef void (*GenBuffers_t) (GLsizei n, GLuint *buffers);
typedef GLboolean(*IsBuffer_t) (GLuint buffer);
typedef void (*BufferData_t) (GLenum target, GLsizeiptr size, const void *data, GLenum usage);
typedef void (*BufferSubData_t) (GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
typedef void (*GetBufferSubData_t) (GLenum target, GLintptr offset, GLsizeiptr size, void *data);
typedef void* (*MapBuffer_t) (GLenum target, GLenum access);
typedef GLboolean(*UnmapBuffer_t) (GLenum target);
typedef void (*GetBufferParameteriv_t) (GLenum target, GLenum pname, GLint *params);
typedef void (*GetBufferPointerv_t) (GLenum target, GLenum pname, void **params);

//2.0 extensions
typedef char GLchar;
#define GL_BLEND_EQUATION_RGB             0x8009
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED    0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE       0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE     0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE       0x8625
#define GL_CURRENT_VERTEX_ATTRIB          0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE      0x8642
#define GL_VERTEX_ATTRIB_ARRAY_POINTER    0x8645
#define GL_STENCIL_BACK_FUNC              0x8800
#define GL_STENCIL_BACK_FAIL              0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL   0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS   0x8803
#define GL_MAX_DRAW_BUFFERS               0x8824
#define GL_DRAW_BUFFER0                   0x8825
#define GL_DRAW_BUFFER1                   0x8826
#define GL_DRAW_BUFFER2                   0x8827
#define GL_DRAW_BUFFER3                   0x8828
#define GL_DRAW_BUFFER4                   0x8829
#define GL_DRAW_BUFFER5                   0x882A
#define GL_DRAW_BUFFER6                   0x882B
#define GL_DRAW_BUFFER7                   0x882C
#define GL_DRAW_BUFFER8                   0x882D
#define GL_DRAW_BUFFER9                   0x882E
#define GL_DRAW_BUFFER10                  0x882F
#define GL_DRAW_BUFFER11                  0x8830
#define GL_DRAW_BUFFER12                  0x8831
#define GL_DRAW_BUFFER13                  0x8832
#define GL_DRAW_BUFFER14                  0x8833
#define GL_DRAW_BUFFER15                  0x8834
#define GL_BLEND_EQUATION_ALPHA           0x883D
#define GL_MAX_VERTEX_ATTRIBS             0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_MAX_TEXTURE_IMAGE_UNITS        0x8872
#define GL_FRAGMENT_SHADER                0x8B30
#define GL_VERTEX_SHADER                  0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS  0x8B4A
#define GL_MAX_VARYING_FLOATS             0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE                    0x8B4F
#define GL_FLOAT_VEC2                     0x8B50
#define GL_FLOAT_VEC3                     0x8B51
#define GL_FLOAT_VEC4                     0x8B52
#define GL_INT_VEC2                       0x8B53
#define GL_INT_VEC3                       0x8B54
#define GL_INT_VEC4                       0x8B55
#define GL_BOOL                           0x8B56
#define GL_BOOL_VEC2                      0x8B57
#define GL_BOOL_VEC3                      0x8B58
#define GL_BOOL_VEC4                      0x8B59
#define GL_FLOAT_MAT2                     0x8B5A
#define GL_FLOAT_MAT3                     0x8B5B
#define GL_FLOAT_MAT4                     0x8B5C
#define GL_SAMPLER_1D                     0x8B5D
#define GL_SAMPLER_2D                     0x8B5E
#define GL_SAMPLER_3D                     0x8B5F
#define GL_SAMPLER_CUBE                   0x8B60
#define GL_SAMPLER_1D_SHADOW              0x8B61
#define GL_SAMPLER_2D_SHADOW              0x8B62
#define GL_DELETE_STATUS                  0x8B80
#define GL_COMPILE_STATUS                 0x8B81
#define GL_LINK_STATUS                    0x8B82
#define GL_VALIDATE_STATUS                0x8B83
#define GL_INFO_LOG_LENGTH                0x8B84
#define GL_ATTACHED_SHADERS               0x8B85
#define GL_ACTIVE_UNIFORMS                0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH      0x8B87
#define GL_SHADER_SOURCE_LENGTH           0x8B88
#define GL_ACTIVE_ATTRIBUTES              0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH    0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION       0x8B8C
#define GL_CURRENT_PROGRAM                0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN      0x8CA0
#define GL_LOWER_LEFT                     0x8CA1
#define GL_UPPER_LEFT                     0x8CA2
#define GL_STENCIL_BACK_REF               0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK        0x8CA4
#define GL_STENCIL_BACK_WRITEMASK         0x8CA5
#define GL_VERTEX_PROGRAM_TWO_SIDE        0x8643
#define GL_POINT_SPRITE                   0x8861
#define GL_COORD_REPLACE                  0x8862
#define GL_MAX_TEXTURE_COORDS             0x8871
typedef void (*BlendEquationSeparate_t) (GLenum modeRGB, GLenum modeAlpha);
typedef void (*DrawBuffers_t) (GLsizei n, const GLenum *bufs);
typedef void (*StencilOpSeparate_t) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
typedef void (*StencilFuncSeparate_t) (GLenum face, GLenum func, GLint ref, GLuint mask);
typedef void (*StencilMaskSeparate_t) (GLenum face, GLuint mask);
typedef void (*AttachShader_t) (GLuint program, GLuint shader);
typedef void (*BindAttribLocation_t) (GLuint program, GLuint index, const GLchar *name);
typedef void (*CompileShader_t) (GLuint shader);
typedef GLuint(*CreateProgram_t) (void);
typedef GLuint(*CreateShader_t) (GLenum type);
typedef void (*DeleteProgram_t) (GLuint program);
typedef void (*DeleteShader_t) (GLuint shader);
typedef void (*DetachShader_t) (GLuint program, GLuint shader);
typedef void (*DisableVertexAttribArray_t) (GLuint index);
typedef void (*EnableVertexAttribArray_t) (GLuint index);
typedef void (*GetActiveAttrib_t) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (*GetActiveUniform_t) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (*GetAttachedShaders_t) (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
typedef GLint(*GetAttribLocation_t) (GLuint program, const GLchar *name);
typedef void (*GetProgramiv_t) (GLuint program, GLenum pname, GLint *params);
typedef void (*GetProgramInfoLog_t) (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (*GetShaderiv_t) (GLuint shader, GLenum pname, GLint *params);
typedef void (*GetShaderInfoLog_t) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (*GetShaderSource_t) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
typedef GLint(*GetUniformLocation_t) (GLuint program, const GLchar *name);
typedef void (*GetUniformfv_t) (GLuint program, GLint location, GLfloat *params);
typedef void (*GetUniformiv_t) (GLuint program, GLint location, GLint *params);
typedef void (*GetVertexAttribdv_t) (GLuint index, GLenum pname, GLdouble *params);
typedef void (*GetVertexAttribfv_t) (GLuint index, GLenum pname, GLfloat *params);
typedef void (*GetVertexAttribiv_t) (GLuint index, GLenum pname, GLint *params);
typedef void (*GetVertexAttribPointerv_t) (GLuint index, GLenum pname, void **pointer);
typedef GLboolean(*IsProgram_t) (GLuint program);
typedef GLboolean(*IsShader_t) (GLuint shader);
typedef void (*LinkProgram_t) (GLuint program);
typedef void (*ShaderSource_t) (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
typedef void (*UseProgram_t) (GLuint program);
typedef void (*Uniform1f_t) (GLint location, GLfloat v0);
typedef void (*Uniform2f_t) (GLint location, GLfloat v0, GLfloat v1);
typedef void (*Uniform3f_t) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (*Uniform4f_t) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (*Uniform1i_t) (GLint location, GLint v0);
typedef void (*Uniform2i_t) (GLint location, GLint v0, GLint v1);
typedef void (*Uniform3i_t) (GLint location, GLint v0, GLint v1, GLint v2);
typedef void (*Uniform4i_t) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (*Uniform1fv_t) (GLint location, GLsizei count, const GLfloat *value);
typedef void (*Uniform2fv_t) (GLint location, GLsizei count, const GLfloat *value);
typedef void (*Uniform3fv_t) (GLint location, GLsizei count, const GLfloat *value);
typedef void (*Uniform4fv_t) (GLint location, GLsizei count, const GLfloat *value);
typedef void (*Uniform1iv_t) (GLint location, GLsizei count, const GLint *value);
typedef void (*Uniform2iv_t) (GLint location, GLsizei count, const GLint *value);
typedef void (*Uniform3iv_t) (GLint location, GLsizei count, const GLint *value);
typedef void (*Uniform4iv_t) (GLint location, GLsizei count, const GLint *value);
typedef void (*UniformMatrix2fv_t) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*UniformMatrix3fv_t) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*UniformMatrix4fv_t) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*ValidateProgram_t) (GLuint program);
typedef void (*VertexAttrib1d_t) (GLuint index, GLdouble x);
typedef void (*VertexAttrib1dv_t) (GLuint index, const GLdouble *v);
typedef void (*VertexAttrib1f_t) (GLuint index, GLfloat x);
typedef void (*VertexAttrib1fv_t) (GLuint index, const GLfloat *v);
typedef void (*VertexAttrib1s_t) (GLuint index, GLshort x);
typedef void (*VertexAttrib1sv_t) (GLuint index, const GLshort *v);
typedef void (*VertexAttrib2d_t) (GLuint index, GLdouble x, GLdouble y);
typedef void (*VertexAttrib2dv_t) (GLuint index, const GLdouble *v);
typedef void (*VertexAttrib2f_t) (GLuint index, GLfloat x, GLfloat y);
typedef void (*VertexAttrib2fv_t) (GLuint index, const GLfloat *v);
typedef void (*VertexAttrib2s_t) (GLuint index, GLshort x, GLshort y);
typedef void (*VertexAttrib2sv_t) (GLuint index, const GLshort *v);
typedef void (*VertexAttrib3d_t) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (*VertexAttrib3dv_t) (GLuint index, const GLdouble *v);
typedef void (*VertexAttrib3f_t) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (*VertexAttrib3fv_t) (GLuint index, const GLfloat *v);
typedef void (*VertexAttrib3s_t) (GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (*VertexAttrib3sv_t) (GLuint index, const GLshort *v);
typedef void (*VertexAttrib4Nbv_t) (GLuint index, const GLbyte *v);
typedef void (*VertexAttrib4Niv_t) (GLuint index, const GLint *v);
typedef void (*VertexAttrib4Nsv_t) (GLuint index, const GLshort *v);
typedef void (*VertexAttrib4Nub_t) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (*VertexAttrib4Nubv_t) (GLuint index, const GLubyte *v);
typedef void (*VertexAttrib4Nuiv_t) (GLuint index, const GLuint *v);
typedef void (*VertexAttrib4Nusv_t) (GLuint index, const GLushort *v);
typedef void (*VertexAttrib4bv_t) (GLuint index, const GLbyte *v);
typedef void (*VertexAttrib4d_t) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (*VertexAttrib4dv_t) (GLuint index, const GLdouble *v);
typedef void (*VertexAttrib4f_t) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (*VertexAttrib4fv_t) (GLuint index, const GLfloat *v);
typedef void (*VertexAttrib4iv_t) (GLuint index, const GLint *v);
typedef void (*VertexAttrib4s_t) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (*VertexAttrib4sv_t) (GLuint index, const GLshort *v);
typedef void (*VertexAttrib4ubv_t) (GLuint index, const GLubyte *v);
typedef void (*VertexAttrib4uiv_t) (GLuint index, const GLuint *v);
typedef void (*VertexAttrib4usv_t) (GLuint index, const GLushort *v);
typedef void (*VertexAttribPointer_t) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);

//OpenGL 2.1 Extensions
#define GL_PIXEL_PACK_BUFFER              0x88EB
#define GL_PIXEL_UNPACK_BUFFER            0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING      0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING    0x88EF
#define GL_FLOAT_MAT2x3                   0x8B65
#define GL_FLOAT_MAT2x4                   0x8B66
#define GL_FLOAT_MAT3x2                   0x8B67
#define GL_FLOAT_MAT3x4                   0x8B68
#define GL_FLOAT_MAT4x2                   0x8B69
#define GL_FLOAT_MAT4x3                   0x8B6A
#define GL_SRGB                           0x8C40
#define GL_SRGB8                          0x8C41
#define GL_SRGB_ALPHA                     0x8C42
#define GL_SRGB8_ALPHA8                   0x8C43
#define GL_COMPRESSED_SRGB                0x8C48
#define GL_COMPRESSED_SRGB_ALPHA          0x8C49
#define GL_CURRENT_RASTER_SECONDARY_COLOR 0x845F
#define GL_SLUMINANCE_ALPHA               0x8C44
#define GL_SLUMINANCE8_ALPHA8             0x8C45
#define GL_SLUMINANCE                     0x8C46
#define GL_SLUMINANCE8                    0x8C47
#define GL_COMPRESSED_SLUMINANCE          0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA    0x8C4B
typedef void (*UniformMatrix2x3fv_t) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*UniformMatrix3x2fv_t) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*UniformMatrix2x4fv_t) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*UniformMatrix4x2fv_t) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*UniformMatrix3x4fv_t) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*UniformMatrix4x3fv_t) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);

//3.0 extensions
typedef unsigned short GLhalf;
#define GL_COMPARE_REF_TO_TEXTURE         0x884E
#define GL_CLIP_DISTANCE0                 0x3000
#define GL_CLIP_DISTANCE1                 0x3001
#define GL_CLIP_DISTANCE2                 0x3002
#define GL_CLIP_DISTANCE3                 0x3003
#define GL_CLIP_DISTANCE4                 0x3004
#define GL_CLIP_DISTANCE5                 0x3005
#define GL_CLIP_DISTANCE6                 0x3006
#define GL_CLIP_DISTANCE7                 0x3007
#define GL_MAX_CLIP_DISTANCES             0x0D32
#define GL_MAJOR_VERSION                  0x821B
#define GL_MINOR_VERSION                  0x821C
#define GL_NUM_EXTENSIONS                 0x821D
#define GL_CONTEXT_FLAGS                  0x821E
#define GL_COMPRESSED_RED                 0x8225
#define GL_COMPRESSED_RG                  0x8226
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x00000001
#define GL_RGBA32F                        0x8814
#define GL_RGB32F                         0x8815
#define GL_RGBA16F                        0x881A
#define GL_RGB16F                         0x881B
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER    0x88FD
#define GL_MAX_ARRAY_TEXTURE_LAYERS       0x88FF
#define GL_MIN_PROGRAM_TEXEL_OFFSET       0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET       0x8905
#define GL_CLAMP_READ_COLOR               0x891C
#define GL_FIXED_ONLY                     0x891D
#define GL_MAX_VARYING_COMPONENTS         0x8B4B
#define GL_TEXTURE_1D_ARRAY               0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY         0x8C19
#define GL_TEXTURE_2D_ARRAY               0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY         0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY       0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY       0x8C1D
#define GL_R11F_G11F_B10F                 0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV   0x8C3B
#define GL_RGB9_E5                        0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV       0x8C3E
#define GL_TEXTURE_SHARED_SIZE            0x8C3F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS    0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define GL_PRIMITIVES_GENERATED           0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define GL_RASTERIZER_DISCARD             0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_INTERLEAVED_ATTRIBS            0x8C8C
#define GL_SEPARATE_ATTRIBS               0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER      0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#define GL_RGBA32UI                       0x8D70
#define GL_RGB32UI                        0x8D71
#define GL_RGBA16UI                       0x8D76
#define GL_RGB16UI                        0x8D77
#define GL_RGBA8UI                        0x8D7C
#define GL_RGB8UI                         0x8D7D
#define GL_RGBA32I                        0x8D82
#define GL_RGB32I                         0x8D83
#define GL_RGBA16I                        0x8D88
#define GL_RGB16I                         0x8D89
#define GL_RGBA8I                         0x8D8E
#define GL_RGB8I                          0x8D8F
#define GL_RED_INTEGER                    0x8D94
#define GL_GREEN_INTEGER                  0x8D95
#define GL_BLUE_INTEGER                   0x8D96
#define GL_RGB_INTEGER                    0x8D98
#define GL_RGBA_INTEGER                   0x8D99
#define GL_BGR_INTEGER                    0x8D9A
#define GL_BGRA_INTEGER                   0x8D9B
#define GL_SAMPLER_1D_ARRAY               0x8DC0
#define GL_SAMPLER_2D_ARRAY               0x8DC1
#define GL_SAMPLER_1D_ARRAY_SHADOW        0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW        0x8DC4
#define GL_SAMPLER_CUBE_SHADOW            0x8DC5
#define GL_UNSIGNED_INT_VEC2              0x8DC6
#define GL_UNSIGNED_INT_VEC3              0x8DC7
#define GL_UNSIGNED_INT_VEC4              0x8DC8
#define GL_INT_SAMPLER_1D                 0x8DC9
#define GL_INT_SAMPLER_2D                 0x8DCA
#define GL_INT_SAMPLER_3D                 0x8DCB
#define GL_INT_SAMPLER_CUBE               0x8DCC
#define GL_INT_SAMPLER_1D_ARRAY           0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY           0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_1D        0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D        0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D        0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE      0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY  0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY  0x8DD7
#define GL_QUERY_WAIT                     0x8E13
#define GL_QUERY_NO_WAIT                  0x8E14
#define GL_QUERY_BY_REGION_WAIT           0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT        0x8E16
#define GL_BUFFER_ACCESS_FLAGS            0x911F
#define GL_BUFFER_MAP_LENGTH              0x9120
#define GL_BUFFER_MAP_OFFSET              0x9121
#define GL_DEPTH_COMPONENT32F             0x8CAC
#define GL_DEPTH32F_STENCIL8              0x8CAD
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD
#define GL_INVALID_FRAMEBUFFER_OPERATION  0x0506
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
#define GL_FRAMEBUFFER_DEFAULT            0x8218
#define GL_FRAMEBUFFER_UNDEFINED          0x8219
#define GL_DEPTH_STENCIL_ATTACHMENT       0x821A
#define GL_MAX_RENDERBUFFER_SIZE          0x84E8
#define GL_DEPTH_STENCIL                  0x84F9
#define GL_UNSIGNED_INT_24_8              0x84FA
#define GL_DEPTH24_STENCIL8               0x88F0
#define GL_TEXTURE_STENCIL_SIZE           0x88F1
#define GL_TEXTURE_RED_TYPE               0x8C10
#define GL_TEXTURE_GREEN_TYPE             0x8C11
#define GL_TEXTURE_BLUE_TYPE              0x8C12
#define GL_TEXTURE_ALPHA_TYPE             0x8C13
#define GL_TEXTURE_DEPTH_TYPE             0x8C16
#define GL_UNSIGNED_NORMALIZED            0x8C17
#define GL_FRAMEBUFFER_BINDING            0x8CA6
#define GL_DRAW_FRAMEBUFFER_BINDING       0x8CA6
#define GL_RENDERBUFFER_BINDING           0x8CA7
#define GL_READ_FRAMEBUFFER               0x8CA8
#define GL_DRAW_FRAMEBUFFER               0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING       0x8CAA
#define GL_RENDERBUFFER_SAMPLES           0x8CAB
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_FRAMEBUFFER_COMPLETE           0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED        0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS          0x8CDF
#define GL_COLOR_ATTACHMENT0              0x8CE0
#define GL_COLOR_ATTACHMENT1              0x8CE1
#define GL_COLOR_ATTACHMENT2              0x8CE2
#define GL_COLOR_ATTACHMENT3              0x8CE3
#define GL_COLOR_ATTACHMENT4              0x8CE4
#define GL_COLOR_ATTACHMENT5              0x8CE5
#define GL_COLOR_ATTACHMENT6              0x8CE6
#define GL_COLOR_ATTACHMENT7              0x8CE7
#define GL_COLOR_ATTACHMENT8              0x8CE8
#define GL_COLOR_ATTACHMENT9              0x8CE9
#define GL_COLOR_ATTACHMENT10             0x8CEA
#define GL_COLOR_ATTACHMENT11             0x8CEB
#define GL_COLOR_ATTACHMENT12             0x8CEC
#define GL_COLOR_ATTACHMENT13             0x8CED
#define GL_COLOR_ATTACHMENT14             0x8CEE
#define GL_COLOR_ATTACHMENT15             0x8CEF
#define GL_DEPTH_ATTACHMENT               0x8D00
#define GL_STENCIL_ATTACHMENT             0x8D20
#define GL_FRAMEBUFFER                    0x8D40
#define GL_RENDERBUFFER                   0x8D41
#define GL_RENDERBUFFER_WIDTH             0x8D42
#define GL_RENDERBUFFER_HEIGHT            0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT   0x8D44
#define GL_STENCIL_INDEX1                 0x8D46
#define GL_STENCIL_INDEX4                 0x8D47
#define GL_STENCIL_INDEX8                 0x8D48
#define GL_STENCIL_INDEX16                0x8D49
#define GL_RENDERBUFFER_RED_SIZE          0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE        0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE         0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE        0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE        0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE      0x8D55
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#define GL_MAX_SAMPLES                    0x8D57
#define GL_INDEX                          0x8222
#define GL_TEXTURE_LUMINANCE_TYPE         0x8C14
#define GL_TEXTURE_INTENSITY_TYPE         0x8C15
#define GL_FRAMEBUFFER_SRGB               0x8DB9
#define GL_HALF_FLOAT                     0x140B
#define GL_MAP_READ_BIT                   0x0001
#define GL_MAP_WRITE_BIT                  0x0002
#define GL_MAP_INVALIDATE_RANGE_BIT       0x0004
#define GL_MAP_INVALIDATE_BUFFER_BIT      0x0008
#define GL_MAP_FLUSH_EXPLICIT_BIT         0x0010
#define GL_MAP_UNSYNCHRONIZED_BIT         0x0020
#define GL_COMPRESSED_RED_RGTC1           0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1    0x8DBC
#define GL_COMPRESSED_RG_RGTC2            0x8DBD
#define GL_COMPRESSED_SIGNED_RG_RGTC2     0x8DBE
#define GL_RG                             0x8227
#define GL_RG_INTEGER                     0x8228
#define GL_R8                             0x8229
#define GL_R16                            0x822A
#define GL_RG8                            0x822B
#define GL_RG16                           0x822C
#define GL_R16F                           0x822D
#define GL_R32F                           0x822E
#define GL_RG16F                          0x822F
#define GL_RG32F                          0x8230
#define GL_R8I                            0x8231
#define GL_R8UI                           0x8232
#define GL_R16I                           0x8233
#define GL_R16UI                          0x8234
#define GL_R32I                           0x8235
#define GL_R32UI                          0x8236
#define GL_RG8I                           0x8237
#define GL_RG8UI                          0x8238
#define GL_RG16I                          0x8239
#define GL_RG16UI                         0x823A
#define GL_RG32I                          0x823B
#define GL_RG32UI                         0x823C
#define GL_VERTEX_ARRAY_BINDING           0x85B5
#define GL_CLAMP_VERTEX_COLOR             0x891A
#define GL_CLAMP_FRAGMENT_COLOR           0x891B
#define GL_ALPHA_INTEGER                  0x8D97
typedef void(*ColorMaski_t) (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
typedef void(*GetBooleani_v_t) (GLenum target, GLuint index, GLboolean *data);
typedef void(*GetIntegeri_v_t) (GLenum target, GLuint index, GLint *data);
typedef void(*Enablei_t) (GLenum target, GLuint index);
typedef void(*Disablei_t) (GLenum target, GLuint index);
typedef GLboolean(*IsEnabledi_t) (GLenum target, GLuint index);
typedef void(*BeginTransformFeedback_t) (GLenum primitiveMode);
typedef void(*EndTransformFeedback_t) (void);
typedef void(*BindBufferRange_t) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void(*BindBufferBase_t) (GLenum target, GLuint index, GLuint buffer);
typedef void(*TransformFeedbackVaryings_t) (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
typedef void(*GetTransformFeedbackVarying_t) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
typedef void(*ClampColor_t) (GLenum target, GLenum clamp);
typedef void(*BeginConditionalRender_t) (GLuint id, GLenum mode);
typedef void(*EndConditionalRender_t) (void);
typedef void(*VertexAttribIPointer_t) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void(*GetVertexAttribIiv_t) (GLuint index, GLenum pname, GLint *params);
typedef void(*GetVertexAttribIuiv_t) (GLuint index, GLenum pname, GLuint *params);
typedef void(*VertexAttribI1i_t) (GLuint index, GLint x);
typedef void(*VertexAttribI2i_t) (GLuint index, GLint x, GLint y);
typedef void(*VertexAttribI3i_t) (GLuint index, GLint x, GLint y, GLint z);
typedef void(*VertexAttribI4i_t) (GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void(*VertexAttribI1ui_t) (GLuint index, GLuint x);
typedef void(*VertexAttribI2ui_t) (GLuint index, GLuint x, GLuint y);
typedef void(*VertexAttribI3ui_t) (GLuint index, GLuint x, GLuint y, GLuint z);
typedef void(*VertexAttribI4ui_t) (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void(*VertexAttribI1iv_t) (GLuint index, const GLint *v);
typedef void(*VertexAttribI2iv_t) (GLuint index, const GLint *v);
typedef void(*VertexAttribI3iv_t) (GLuint index, const GLint *v);
typedef void(*VertexAttribI4iv_t) (GLuint index, const GLint *v);
typedef void(*VertexAttribI1uiv_t) (GLuint index, const GLuint *v);
typedef void(*VertexAttribI2uiv_t) (GLuint index, const GLuint *v);
typedef void(*VertexAttribI3uiv_t) (GLuint index, const GLuint *v);
typedef void(*VertexAttribI4uiv_t) (GLuint index, const GLuint *v);
typedef void(*VertexAttribI4bv_t) (GLuint index, const GLbyte *v);
typedef void(*VertexAttribI4sv_t) (GLuint index, const GLshort *v);
typedef void(*VertexAttribI4ubv_t) (GLuint index, const GLubyte *v);
typedef void(*VertexAttribI4usv_t) (GLuint index, const GLushort *v);
typedef void(*GetUniformuiv_t) (GLuint program, GLint location, GLuint *params);
typedef void(*BindFragDataLocation_t) (GLuint program, GLuint color, const GLchar *name);
typedef GLint(*GetFragDataLocation_t) (GLuint program, const GLchar *name);
typedef void(*Uniform1ui_t) (GLint location, GLuint v0);
typedef void(*Uniform2ui_t) (GLint location, GLuint v0, GLuint v1);
typedef void(*Uniform3ui_t) (GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void(*Uniform4ui_t) (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void(*Uniform1uiv_t) (GLint location, GLsizei count, const GLuint *value);
typedef void(*Uniform2uiv_t) (GLint location, GLsizei count, const GLuint *value);
typedef void(*Uniform3uiv_t) (GLint location, GLsizei count, const GLuint *value);
typedef void(*Uniform4uiv_t) (GLint location, GLsizei count, const GLuint *value);
typedef void(*TexParameterIiv_t) (GLenum target, GLenum pname, const GLint *params);
typedef void(*TexParameterIuiv_t) (GLenum target, GLenum pname, const GLuint *params);
typedef void(*GetTexParameterIiv_t) (GLenum target, GLenum pname, GLint *params);
typedef void(*GetTexParameterIuiv_t) (GLenum target, GLenum pname, GLuint *params);
typedef void(*ClearBufferiv_t) (GLenum buffer, GLint drawbuffer, const GLint *value);
typedef void(*ClearBufferuiv_t) (GLenum buffer, GLint drawbuffer, const GLuint *value);
typedef void(*ClearBufferfv_t) (GLenum buffer, GLint drawbuffer, const GLfloat *value);
typedef void(*ClearBufferfi_t) (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef const GLubyte *(*GetStringi_t) (GLenum name, GLuint index);
typedef GLboolean(*IsRenderbuffer_t) (GLuint renderbuffer);
typedef void(*BindRenderbuffer_t) (GLenum target, GLuint renderbuffer);
typedef void(*DeleteRenderbuffers_t) (GLsizei n, const GLuint *renderbuffers);
typedef void(*GenRenderbuffers_t) (GLsizei n, GLuint *renderbuffers);
typedef void(*RenderbufferStorage_t) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
typedef void(*GetRenderbufferParameteriv_t) (GLenum target, GLenum pname, GLint *params);
typedef GLboolean(*IsFramebuffer_t) (GLuint framebuffer);
typedef void(*BindFramebuffer_t) (GLenum target, GLuint framebuffer);
typedef void(*DeleteFramebuffers_t) (GLsizei n, const GLuint *framebuffers);
typedef void(*GenFramebuffers_t) (GLsizei n, GLuint *framebuffers);
typedef GLenum(*CheckFramebufferStatus_t) (GLenum target);
typedef void(*FramebufferTexture1D_t) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void(*FramebufferTexture2D_t) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void(*FramebufferTexture3D_t) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef void(*FramebufferRenderbuffer_t) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void(*GetFramebufferAttachmentParameteriv_t) (GLenum target, GLenum attachment, GLenum pname, GLint *params);
typedef void(*GenerateMipmap_t) (GLenum target);
typedef void(*BlitFramebuffer_t) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef void(*RenderbufferStorageMultisample_t) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void(*FramebufferTextureLayer_t) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void *(*MapBufferRange_t) (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef void(*FlushMappedBufferRange_t) (GLenum target, GLintptr offset, GLsizeiptr length);
typedef void(*BindVertexArray_t) (GLuint array);
typedef void(*DeleteVertexArrays_t) (GLsizei n, const GLuint *arrays);
typedef void(*GenVertexArrays_t) (GLsizei n, GLuint *arrays);
typedef GLboolean(*IsVertexArray_t) (GLuint array);

//OpenGL 3.1 Extensions
#define GL_SAMPLER_2D_RECT                0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW         0x8B64
#define GL_SAMPLER_BUFFER                 0x8DC2
#define GL_INT_SAMPLER_2D_RECT            0x8DCD
#define GL_INT_SAMPLER_BUFFER             0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT   0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_BUFFER    0x8DD8
#define GL_TEXTURE_BUFFER                 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE        0x8C2B
#define GL_TEXTURE_BINDING_BUFFER         0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#define GL_TEXTURE_RECTANGLE              0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE      0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE        0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE     0x84F8
#define GL_R8_SNORM                       0x8F94
#define GL_RG8_SNORM                      0x8F95
#define GL_RGB8_SNORM                     0x8F96
#define GL_RGBA8_SNORM                    0x8F97
#define GL_R16_SNORM                      0x8F98
#define GL_RG16_SNORM                     0x8F99
#define GL_RGB16_SNORM                    0x8F9A
#define GL_RGBA16_SNORM                   0x8F9B
#define GL_SIGNED_NORMALIZED              0x8F9C
#define GL_PRIMITIVE_RESTART              0x8F9D
#define GL_PRIMITIVE_RESTART_INDEX        0x8F9E
#define GL_COPY_READ_BUFFER               0x8F36
#define GL_COPY_WRITE_BUFFER              0x8F37
#define GL_UNIFORM_BUFFER                 0x8A11
#define GL_UNIFORM_BUFFER_BINDING         0x8A28
#define GL_UNIFORM_BUFFER_START           0x8A29
#define GL_UNIFORM_BUFFER_SIZE            0x8A2A
#define GL_MAX_VERTEX_UNIFORM_BLOCKS      0x8A2B
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS    0x8A2D
#define GL_MAX_COMBINED_UNIFORM_BLOCKS    0x8A2E
#define GL_MAX_UNIFORM_BUFFER_BINDINGS    0x8A2F
#define GL_MAX_UNIFORM_BLOCK_SIZE         0x8A30
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
#define GL_ACTIVE_UNIFORM_BLOCKS          0x8A36
#define GL_UNIFORM_TYPE                   0x8A37
#define GL_UNIFORM_SIZE                   0x8A38
#define GL_UNIFORM_NAME_LENGTH            0x8A39
#define GL_UNIFORM_BLOCK_INDEX            0x8A3A
#define GL_UNIFORM_OFFSET                 0x8A3B
#define GL_UNIFORM_ARRAY_STRIDE           0x8A3C
#define GL_UNIFORM_MATRIX_STRIDE          0x8A3D
#define GL_UNIFORM_IS_ROW_MAJOR           0x8A3E
#define GL_UNIFORM_BLOCK_BINDING          0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE        0x8A40
#define GL_UNIFORM_BLOCK_NAME_LENGTH      0x8A41
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS  0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
#define GL_INVALID_INDEX                  0xFFFFFFFFu
typedef void(*DrawArraysInstanced_t) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
typedef void(*DrawElementsInstanced_t) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
typedef void(*TexBuffer_t) (GLenum target, GLenum internalformat, GLuint buffer);
typedef void(*PrimitiveRestartIndex_t) (GLuint index);
typedef void(*CopyBufferSubData_t) (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void(*GetUniformIndices_t) (GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
typedef void(*GetActiveUniformsiv_t) (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
typedef void(*GetActiveUniformName_t) (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
typedef GLuint(*GetUniformBlockIndex_t) (GLuint program, const GLchar *uniformBlockName);
typedef void(*GetActiveUniformBlockiv_t) (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
typedef void(*GetActiveUniformBlockName_t) (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
typedef void(*UniformBlockBinding_t) (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);

//OpenGL 3.2 Extensions
typedef struct __GLsync* GLsync;
typedef uint64_t GLuint64;
typedef int64_t GLint64;
#define GL_CONTEXT_CORE_PROFILE_BIT       0x00000001
#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002
#define GL_LINES_ADJACENCY                0x000A
#define GL_LINE_STRIP_ADJACENCY           0x000B
#define GL_TRIANGLES_ADJACENCY            0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY       0x000D
#define GL_PROGRAM_POINT_SIZE             0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
#define GL_GEOMETRY_SHADER                0x8DD9
#define GL_GEOMETRY_VERTICES_OUT          0x8916
#define GL_GEOMETRY_INPUT_TYPE            0x8917
#define GL_GEOMETRY_OUTPUT_TYPE           0x8918
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES   0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS   0x9122
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS  0x9123
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS  0x9125
#define GL_CONTEXT_PROFILE_MASK           0x9126
#define GL_DEPTH_CLAMP                    0x864F
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C
#define GL_FIRST_VERTEX_CONVENTION        0x8E4D
#define GL_LAST_VERTEX_CONVENTION         0x8E4E
#define GL_PROVOKING_VERTEX               0x8E4F
#define GL_TEXTURE_CUBE_MAP_SEAMLESS      0x884F
#define GL_MAX_SERVER_WAIT_TIMEOUT        0x9111
#define GL_OBJECT_TYPE                    0x9112
#define GL_SYNC_CONDITION                 0x9113
#define GL_SYNC_STATUS                    0x9114
#define GL_SYNC_FLAGS                     0x9115
#define GL_SYNC_FENCE                     0x9116
#define GL_SYNC_GPU_COMMANDS_COMPLETE     0x9117
#define GL_UNSIGNALED                     0x9118
#define GL_SIGNALED                       0x9119
#define GL_ALREADY_SIGNALED               0x911A
#define GL_TIMEOUT_EXPIRED                0x911B
#define GL_CONDITION_SATISFIED            0x911C
#define GL_WAIT_FAILED                    0x911D
#define GL_TIMEOUT_IGNORED                0xFFFFFFFFFFFFFFFFull
#define GL_SYNC_FLUSH_COMMANDS_BIT        0x00000001
#define GL_SAMPLE_POSITION                0x8E50
#define GL_SAMPLE_MASK                    0x8E51
#define GL_SAMPLE_MASK_VALUE              0x8E52
#define GL_MAX_SAMPLE_MASK_WORDS          0x8E59
#define GL_TEXTURE_2D_MULTISAMPLE         0x9100
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE   0x9101
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY   0x9102
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#define GL_TEXTURE_SAMPLES                0x9106
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
#define GL_SAMPLER_2D_MULTISAMPLE         0x9108
#define GL_INT_SAMPLER_2D_MULTISAMPLE     0x9109
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY   0x910B
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
#define GL_MAX_COLOR_TEXTURE_SAMPLES      0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES      0x910F
#define GL_MAX_INTEGER_SAMPLES            0x9110
typedef void(*DrawElementsBaseVertex_t) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
typedef void(*DrawRangeElementsBaseVertex_t) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
typedef void(*DrawElementsInstancedBaseVertex_t) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
typedef void(*MultiDrawElementsBaseVertex_t) (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
typedef void(*ProvokingVertex_t) (GLenum mode);
typedef GLsync(*FenceSync_t) (GLenum condition, GLbitfield flags);
typedef GLboolean(*IsSync_t) (GLsync sync);
typedef void(*DeleteSync_t) (GLsync sync);
typedef GLenum(*ClientWaitSync_t) (GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void(*WaitSync_t) (GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void(*GetInteger64v_t) (GLenum pname, GLint64 *params);
typedef void(*GetSynciv_t) (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
typedef void(*GetInteger64i_v_t) (GLenum target, GLuint index, GLint64 *data);
typedef void(*GetBufferParameteri64v_t) (GLenum target, GLenum pname, GLint64 *params);
typedef void(*FramebufferTexture_t) (GLenum target, GLenum attachment, GLuint texture, GLint level);
typedef void(*TexImage2DMultisample_t) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void(*TexImage3DMultisample_t) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void(*GetMultisamplefv_t) (GLenum pname, GLuint index, GLfloat *val);
typedef void(*SampleMaski_t) (GLuint index, GLbitfield mask);

//OpenGL 3.3 Extensions
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR    0x88FE
#define GL_SRC1_COLOR                     0x88F9
#define GL_ONE_MINUS_SRC1_COLOR           0x88FA
#define GL_ONE_MINUS_SRC1_ALPHA           0x88FB
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS   0x88FC
#define GL_ANY_SAMPLES_PASSED             0x8C2F
#define GL_SAMPLER_BINDING                0x8919
#define GL_RGB10_A2UI                     0x906F
#define GL_TEXTURE_SWIZZLE_R              0x8E42
#define GL_TEXTURE_SWIZZLE_G              0x8E43
#define GL_TEXTURE_SWIZZLE_B              0x8E44
#define GL_TEXTURE_SWIZZLE_A              0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA           0x8E46
#define GL_TIME_ELAPSED                   0x88BF
#define GL_TIMESTAMP                      0x8E28
#define GL_INT_2_10_10_10_REV             0x8D9F
typedef void(*BindFragDataLocationBindIndexed_t) (GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
typedef GLint(*GetFragDataIndex_t) (GLuint program, const GLchar *name);
typedef void(*GenSamplers_t) (GLsizei count, GLuint *samplers);
typedef void(*DeleteSamplers_t) (GLsizei count, const GLuint *samplers);
typedef GLboolean(*IsSampler_t) (GLuint sampler);
typedef void(*BindSampler_t) (GLuint unit, GLuint sampler);
typedef void(*SamplerParameteri_t) (GLuint sampler, GLenum pname, GLint param);
typedef void(*SamplerParameteriv_t) (GLuint sampler, GLenum pname, const GLint *param);
typedef void(*SamplerParameterf_t) (GLuint sampler, GLenum pname, GLfloat param);
typedef void(*SamplerParamterfv_t) (GLuint sampler, GLenum pname, const GLfloat *param);
typedef void(*SamplerParameterIiv_t) (GLuint sampler, GLenum pname, const GLint *param);
typedef void(*SamplerParameterIuiv_t) (GLuint sampler, GLenum pname, const GLuint *param);
typedef void(*GetSamplerParameteriv_t) (GLuint sampler, GLenum pname, GLint *params);
typedef void(*GetSamplerParameterIiv_t) (GLuint sampler, GLenum pname, GLint *params);
typedef void(*GetSamplerParameterfv_t) (GLuint sampler, GLenum pname, GLfloat *params);
typedef void(*GetSamplerParameterIuiv_t) (GLuint sampler, GLenum pname, GLuint *params);
typedef void(*QueryCounter_t) (GLuint id, GLenum target);
typedef void(*GetQueryObjecti64v_t) (GLuint id, GLenum pname, GLint64 *params);
typedef void(*GetQueryObjectui64v_t) (GLuint id, GLenum pname, GLuint64 *params);
typedef void(*VertexAttribDivisor_t) (GLuint index, GLuint divisor);
typedef void(*VertexAttribP1ui_t) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void(*VertexAttribP1uiv_t) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void(*VertexAttribP2ui_t) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void(*VertexAttribP2uiv_t) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void(*VertexAttribP3ui_t) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void(*VertexAttribP3uiv_t) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void(*VertexAttribP4ui_t) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void(*VertexAttribP4uiv_t) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void(*VertexP2ui_t) (GLenum type, GLuint value);
typedef void(*VertexP2uiv_t) (GLenum type, const GLuint *value);
typedef void(*VertexP3ui_t) (GLenum type, GLuint value);
typedef void(*VertexP3uiv_t) (GLenum type, const GLuint *value);
typedef void(*VertexP4ui_t) (GLenum type, GLuint value);
typedef void(*VertexP4uiv_t) (GLenum type, const GLuint *value);
typedef void(*TexCoordP1ui_t) (GLenum type, GLuint coords);
typedef void(*TexCoordP1uiv_t) (GLenum type, const GLuint *coords);
typedef void(*TexCoordP2ui_t) (GLenum type, GLuint coords);
typedef void(*TexCoordP2uiv_t) (GLenum type, const GLuint *coords);
typedef void(*TexCoordP3ui_t) (GLenum type, GLuint coords);
typedef void(*TexCoordP3uiv_t) (GLenum type, const GLuint *coords);
typedef void(*TexCoordP4ui_t) (GLenum type, GLuint coords);
typedef void(*TexCoordP4uiv_t) (GLenum type, const GLuint *coords);
typedef void(*MultiTexCoordP1ui_t) (GLenum texture, GLenum type, GLuint coords);
typedef void(*MultiTexCoordP1uiv_t) (GLenum texture, GLenum type, const GLuint *coords);
typedef void(*MultiTexCoordP2ui_t) (GLenum texture, GLenum type, GLuint coords);
typedef void(*MultiTexCoordP2uiv_t) (GLenum texture, GLenum type, const GLuint *coords);
typedef void(*MultiTexCoordP3ui_t) (GLenum texture, GLenum type, GLuint coords);
typedef void(*MultiTexCoordP3uiv_t) (GLenum texture, GLenum type, const GLuint *coords);
typedef void(*MultiTexCoordP4ui_t) (GLenum texture, GLenum type, GLuint coords);
typedef void(*MultiTexCoordP4uiv_t) (GLenum texture, GLenum type, const GLuint *coords);
typedef void(*NormalP3ui_t) (GLenum type, GLuint coords);
typedef void(*NormalP3uiv_t) (GLenum type, const GLuint *coords);
typedef void(*ColorP3ui_t) (GLenum type, GLuint color);
typedef void(*ColorP3uiv_t) (GLenum type, const GLuint *color);
typedef void(*ColorP4ui_t) (GLenum type, GLuint color);
typedef void(*ColorP4uiv_t) (GLenum type, const GLuint *color);
typedef void(*SecondaryColorP3ui_t) (GLenum type, GLuint color);
typedef void(*SecondaryColorP3uiv_t) (GLenum type, const GLuint *color);

//OpenGL 4.0 Extensions
#define GL_SAMPLE_SHADING                 0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE       0x8C37
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5F
#define GL_TEXTURE_CUBE_MAP_ARRAY         0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY   0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY         0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW  0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY     0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY 0x900F
#define GL_DRAW_INDIRECT_BUFFER           0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING   0x8F43
#define GL_GEOMETRY_SHADER_INVOCATIONS    0x887F
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS 0x8E5A
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET 0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET 0x8E5C
#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS 0x8E5D
#define GL_MAX_VERTEX_STREAMS             0x8E71
#define GL_DOUBLE_VEC2                    0x8FFC
#define GL_DOUBLE_VEC3                    0x8FFD
#define GL_DOUBLE_VEC4                    0x8FFE
#define GL_DOUBLE_MAT2                    0x8F46
#define GL_DOUBLE_MAT3                    0x8F47
#define GL_DOUBLE_MAT4                    0x8F48
#define GL_DOUBLE_MAT2x3                  0x8F49
#define GL_DOUBLE_MAT2x4                  0x8F4A
#define GL_DOUBLE_MAT3x2                  0x8F4B
#define GL_DOUBLE_MAT3x4                  0x8F4C
#define GL_DOUBLE_MAT4x2                  0x8F4D
#define GL_DOUBLE_MAT4x3                  0x8F4E
#define GL_ACTIVE_SUBROUTINES             0x8DE5
#define GL_ACTIVE_SUBROUTINE_UNIFORMS     0x8DE6
#define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS 0x8E47
#define GL_ACTIVE_SUBROUTINE_MAX_LENGTH   0x8E48
#define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH 0x8E49
#define GL_MAX_SUBROUTINES                0x8DE7
#define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS 0x8DE8
#define GL_NUM_COMPATIBLE_SUBROUTINES     0x8E4A
#define GL_COMPATIBLE_SUBROUTINES         0x8E4B
#define GL_PATCHES                        0x000E
#define GL_PATCH_VERTICES                 0x8E72
#define GL_PATCH_DEFAULT_INNER_LEVEL      0x8E73
#define GL_PATCH_DEFAULT_OUTER_LEVEL      0x8E74
#define GL_TESS_CONTROL_OUTPUT_VERTICES   0x8E75
#define GL_TESS_GEN_MODE                  0x8E76
#define GL_TESS_GEN_SPACING               0x8E77
#define GL_TESS_GEN_VERTEX_ORDER          0x8E78
#define GL_TESS_GEN_POINT_MODE            0x8E79
#define GL_ISOLINES                       0x8E7A
#define GL_FRACTIONAL_ODD                 0x8E7B
#define GL_FRACTIONAL_EVEN                0x8E7C
#define GL_MAX_PATCH_VERTICES             0x8E7D
#define GL_MAX_TESS_GEN_LEVEL             0x8E7E
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E7F
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E80
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS 0x8E81
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS 0x8E82
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS 0x8E83
#define GL_MAX_TESS_PATCH_COMPONENTS      0x8E84
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS 0x8E85
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS 0x8E86
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS 0x8E89
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS 0x8E8A
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS 0x886C
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS 0x886D
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER 0x84F0
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER 0x84F1
#define GL_TESS_EVALUATION_SHADER         0x8E87
#define GL_TESS_CONTROL_SHADER            0x8E88
#define GL_TRANSFORM_FEEDBACK             0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED 0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE 0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING     0x8E25
#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS 0x8E70
typedef void(*MinSampleShading_t) (GLfloat value);
typedef void(*BlendEquationi_t) (GLuint buf, GLenum mode);
typedef void(*BlendEquationSeparatei_t) (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void(*BlendFunci_t) (GLuint buf, GLenum src, GLenum dst);
typedef void(*BlendFuncSeparatei_t) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
typedef void(*DrawArraysIndirect_t) (GLenum mode, const void *indirect);
typedef void(*DrawElementsIndirect_t) (GLenum mode, GLenum type, const void *indirect);
typedef void(*Uniform1d_t) (GLint location, GLdouble x);
typedef void(*Uniform2d_t) (GLint location, GLdouble x, GLdouble y);
typedef void(*Uniform3d_t) (GLint location, GLdouble x, GLdouble y, GLdouble z);
typedef void(*Uniform4d_t) (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void(*Uniform1dv_t) (GLint location, GLsizei count, const GLdouble *value);
typedef void(*Uniform2dv_t) (GLint location, GLsizei count, const GLdouble *value);
typedef void(*Uniform3dv_t) (GLint location, GLsizei count, const GLdouble *value);
typedef void(*Uniform4dv_t) (GLint location, GLsizei count, const GLdouble *value);
typedef void(*UniformMatrix2dv_t) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void(*UniformMatrix3dv_t) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void(*UniformMatrix4dv_t) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void(*UniformMatrix2x3dv_t) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void(*UniformMatrix2x4dv_t) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void(*UniformMatrix3x2dv_t) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void(*UniformMatrix3x4dv_t) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void(*UniformMatrix4x2dv_t) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void(*UniformMatrix4x3dv_t) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void(*GetUniformdv_t) (GLuint program, GLint location, GLdouble *params);
typedef GLint(*GetSubroutineUniformLocation_t) (GLuint program, GLenum shadertype, const GLchar *name);
typedef GLuint(*GetSubroutineIndex_t) (GLuint program, GLenum shadertype, const GLchar *name);
typedef void(*GetActiveSubroutineUniformiv_t) (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
typedef void(*GetActiveSubroutineUniformName_t) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
typedef void(*GetActiveSubroutineName_t) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
typedef void(*UniformSubroutinesuiv_t) (GLenum shadertype, GLsizei count, const GLuint *indices);
typedef void(*GetUniformSubroutineuiv_t) (GLenum shadertype, GLint location, GLuint *params);
typedef void(*GetProgramStageiv_t) (GLuint program, GLenum shadertype, GLenum pname, GLint *values);
typedef void(*PatchParameteri_t) (GLenum pname, GLint value);
typedef void(*PatchParameterfv_t) (GLenum pname, const GLfloat *values);
typedef void(*BindTransformFeedback_t) (GLenum target, GLuint id);
typedef void(*DeleteTransformFeedbacks_t) (GLsizei n, const GLuint *ids);
typedef void(*GenTransformFeedbacks_t) (GLsizei n, GLuint *ids);
typedef GLboolean(*IsTransformFeedback_t) (GLuint id);
typedef void(*PauseTransformFeedback_t) (void);
typedef void(*ResumeTransportFeedback_t) (void);
typedef void(*DrawTransformFeedback_t) (GLenum mode, GLuint id);
typedef void(*DrawTransformFeedbackStream_t) (GLenum mode, GLuint id, GLuint stream);
typedef void(*BeginQueryIndexed_t) (GLenum target, GLuint index, GLuint id);
typedef void(*EndQueryIndexed_t) (GLenum target, GLuint index);
typedef void(*GetQueryIndexed_t) (GLenum target, GLuint index, GLenum pname, GLint *params);

//OpenGL 4.1 Extensions
#define GL_FIXED                          0x140C
#define GL_IMPLEMENTATION_COLOR_READ_TYPE 0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT 0x8B9B
#define GL_LOW_FLOAT                      0x8DF0
#define GL_MEDIUM_FLOAT                   0x8DF1
#define GL_HIGH_FLOAT                     0x8DF2
#define GL_LOW_INT                        0x8DF3
#define GL_MEDIUM_INT                     0x8DF4
#define GL_HIGH_INT                       0x8DF5
#define GL_SHADER_COMPILER                0x8DFA
#define GL_SHADER_BINARY_FORMATS          0x8DF8
#define GL_NUM_SHADER_BINARY_FORMATS      0x8DF9
#define GL_MAX_VERTEX_UNIFORM_VECTORS     0x8DFB
#define GL_MAX_VARYING_VECTORS            0x8DFC
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS   0x8DFD
#define GL_RGB565                         0x8D62
#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT 0x8257
#define GL_PROGRAM_BINARY_LENGTH          0x8741
#define GL_NUM_PROGRAM_BINARY_FORMATS     0x87FE
#define GL_PROGRAM_BINARY_FORMATS         0x87FF
#define GL_VERTEX_SHADER_BIT              0x00000001
#define GL_FRAGMENT_SHADER_BIT            0x00000002
#define GL_GEOMETRY_SHADER_BIT            0x00000004
#define GL_TESS_CONTROL_SHADER_BIT        0x00000008
#define GL_TESS_EVALUATION_SHADER_BIT     0x00000010
#define GL_ALL_SHADER_BITS                0xFFFFFFFF
#define GL_PROGRAM_SEPARABLE              0x8258
#define GL_ACTIVE_PROGRAM                 0x8259
#define GL_PROGRAM_PIPELINE_BINDING       0x825A
#define GL_MAX_VIEWPORTS                  0x825B
#define GL_VIEWPORT_SUBPIXEL_BITS         0x825C
#define GL_VIEWPORT_BOUNDS_RANGE          0x825D
#define GL_LAYER_PROVOKING_VERTEX         0x825E
#define GL_VIEWPORT_INDEX_PROVOKING_VERTEX 0x825F
#define GL_UNDEFINED_VERTEX               0x8260
typedef void(*ReleaseShaderCompiler_t) (void);
typedef void(*ShaderBinary_t) (GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length);
typedef void(*GetShaderPrecisionFormat_t) (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
typedef void(*DepthRangef_t) (GLfloat n, GLfloat f);
typedef void(*ClearDepthf_t) (GLfloat d);
typedef void(*GetProgramBinary_t) (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
typedef void(*ProgramBinary_t) (GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
typedef void(*ProgramParameteri_t) (GLuint program, GLenum pname, GLint value);
typedef void(*UseProgramStages_t) (GLuint pipeline, GLbitfield stages, GLuint program);
typedef void(*ActiveShaderProgram_t) (GLuint pipeline, GLuint program);
typedef GLuint(*CreateShaderProgramv_t) (GLenum type, GLsizei count, const GLchar *const*strings);
typedef void(*BindProgramPipeline_t) (GLuint pipeline);
typedef void(*DeleteProgramPipelines_t) (GLsizei n, const GLuint *pipelines);
typedef void(*GenProgramPipelines_t) (GLsizei n, GLuint *pipelines);
typedef GLboolean(*IsProgramPipeline_t) (GLuint pipeline);
typedef void(*GetProgramPipelineiv_t) (GLuint pipeline, GLenum pname, GLint *params);
typedef void(*ProgramUniform1i_t) (GLuint program, GLint location, GLint v0);
typedef void(*ProgramUniform1iv_t) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void(*ProgramUniform1f_t) (GLuint program, GLint location, GLfloat v0);
typedef void(*ProgramUniform1fv_t) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void(*ProgramUniform1d_t) (GLuint program, GLint location, GLdouble v0);
typedef void(*ProgramUniform1dv_t) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void(*ProgramUniform1ui_t) (GLuint program, GLint location, GLuint v0);
typedef void(*ProgramUniform1uiv_t) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void(*ProgramUniform2i_t) (GLuint program, GLint location, GLint v0, GLint v1);
typedef void(*ProgramUniform2iv_t) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void(*ProgramUniform2f_t) (GLuint program, GLint location, GLfloat v0, GLfloat v1);
typedef void(*ProgramUniform2fv_t) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void(*ProgramUniform2d_t) (GLuint program, GLint location, GLdouble v0, GLdouble v1);
typedef void(*ProgramUniform2dv_t) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void(*ProgramUniform2ui_t) (GLuint program, GLint location, GLuint v0, GLuint v1);
typedef void(*ProgramUniform2uiv_t) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void(*ProgramUniform3i_t) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
typedef void(*ProgramUniform3iv_t) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void(*ProgramUniform3f_t) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void(*ProgramUniform3fv_t) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void(*ProgramUniform3d_t) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
typedef void(*ProgramUniform3dv_t) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void(*ProgramUniform3ui_t) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void(*ProgramUniform3uiv_t) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void(*ProgramUniform4i_t) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void(*ProgramUniform4iv_t) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void(*ProgramUniform4f_t) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void(*ProgramUniform4fv_t) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void(*ProgramUniform4d_t) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
typedef void(*ProgramUniform4dv_t) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void(*ProgramUniform4ui_t) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void(*ProgramUniform4uiv_t) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void(*ProgramUniformMatrix2fv_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void(*ProgramUniformMatrix3fv_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void(*ProgramUniformMatrix4fv_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void(*ProgramUniformMatrix2dv_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void(*ProgramUniformMatrix3dv_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void(*ProgramUniformMatrix4dv_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void(*ProgramUniformMatrix2x3fv_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void(*ProgramUniformMatrix3x2fv_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void(*ProgramUniformMatrix2x4fv_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void(*ProgramUniformMatrix4x2fv_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void(*ProgramUniformMatrix3x4fv_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void(*ProgramUniformMatrix4x3fv_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void(*ProgramUniformMatrix2x3dv_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void(*ProgramUniformMatrix3x2dv_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void(*ProgramUniformMatrix2x4dv_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void(*ProgramUniformMatrix4x2dv_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void(*ProgramUniformMatrix3x4dv_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void(*ProgramUniformMatrix4x3dv_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void(*ValidateProgramPipeline_t) (GLuint pipeline);
typedef void(*GetProgramPipelineInfoLog_t) (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void(*VertexAttribL1d_t) (GLuint index, GLdouble x);
typedef void(*VertexAttribL2d_t) (GLuint index, GLdouble x, GLdouble y);
typedef void(*VertexAttribL3d_t) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void(*VertexAttribL4d_t) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void(*VertexAttribL1dv_t) (GLuint index, const GLdouble *v);
typedef void(*VertexAttribL2dv_t) (GLuint index, const GLdouble *v);
typedef void(*VertexAttribL3dv_t) (GLuint index, const GLdouble *v);
typedef void(*VertexAttribL4dv_t) (GLuint index, const GLdouble *v);
typedef void(*VertexAttribLPointer_t) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void(*GetVertexAttribLdv_t) (GLuint index, GLenum pname, GLdouble *params);
typedef void(*ViewportArrayv_t) (GLuint first, GLsizei count, const GLfloat *v);
typedef void(*ViewportIndexedf_t) (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
typedef void(*ViewportIndexedfv_t) (GLuint index, const GLfloat *v);
typedef void(*ScissorArrayv_t) (GLuint first, GLsizei count, const GLint *v);
typedef void(*ScissorIndexed_t) (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
typedef void(*ScissorIndexedv_t) (GLuint index, const GLint *v);
typedef void(*DepthRangeIndexed_t) (GLuint first, GLsizei count, const GLdouble *v);
typedef void(*DepthRangeArrayv_t) (GLuint index, GLdouble n, GLdouble f);
typedef void(*GetFloati_v_t) (GLenum target, GLuint index, GLfloat *data);
typedef void(*GetDoublei_v_t) (GLenum target, GLuint index, GLdouble *data);

//OpenGL 4.2 Extensions
#define GL_UNPACK_COMPRESSED_BLOCK_WIDTH  0x9127
#define GL_UNPACK_COMPRESSED_BLOCK_HEIGHT 0x9128
#define GL_UNPACK_COMPRESSED_BLOCK_DEPTH  0x9129
#define GL_UNPACK_COMPRESSED_BLOCK_SIZE   0x912A
#define GL_PACK_COMPRESSED_BLOCK_WIDTH    0x912B
#define GL_PACK_COMPRESSED_BLOCK_HEIGHT   0x912C
#define GL_PACK_COMPRESSED_BLOCK_DEPTH    0x912D
#define GL_PACK_COMPRESSED_BLOCK_SIZE     0x912E
#define GL_NUM_SAMPLE_COUNTS              0x9380
#define GL_MIN_MAP_BUFFER_ALIGNMENT       0x90BC
#define GL_ATOMIC_COUNTER_BUFFER          0x92C0
#define GL_ATOMIC_COUNTER_BUFFER_BINDING  0x92C1
#define GL_ATOMIC_COUNTER_BUFFER_START    0x92C2
#define GL_ATOMIC_COUNTER_BUFFER_SIZE     0x92C3
#define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE 0x92C4
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS 0x92C5
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES 0x92C6
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER 0x92C7
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER 0x92C8
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER 0x92CA
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER 0x92CB
#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS 0x92CC
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS 0x92CD
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS 0x92CE
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS 0x92CF
#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS 0x92D0
#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS 0x92D1
#define GL_MAX_VERTEX_ATOMIC_COUNTERS     0x92D2
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS 0x92D3
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS 0x92D4
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS   0x92D5
#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS   0x92D6
#define GL_MAX_COMBINED_ATOMIC_COUNTERS   0x92D7
#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE 0x92D8
#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS 0x92DC
#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS  0x92D9
#define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX 0x92DA
#define GL_UNSIGNED_INT_ATOMIC_COUNTER    0x92DB
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT 0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT      0x00000002
#define GL_UNIFORM_BARRIER_BIT            0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT      0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT 0x00000020
#define GL_COMMAND_BARRIER_BIT            0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT       0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT     0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT      0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT        0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT 0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT     0x00001000
#define GL_ALL_BARRIER_BITS               0xFFFFFFFF
#define GL_MAX_IMAGE_UNITS                0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS 0x8F39
#define GL_IMAGE_BINDING_NAME             0x8F3A
#define GL_IMAGE_BINDING_LEVEL            0x8F3B
#define GL_IMAGE_BINDING_LAYERED          0x8F3C
#define GL_IMAGE_BINDING_LAYER            0x8F3D
#define GL_IMAGE_BINDING_ACCESS           0x8F3E
#define GL_IMAGE_1D                       0x904C
#define GL_IMAGE_2D                       0x904D
#define GL_IMAGE_3D                       0x904E
#define GL_IMAGE_2D_RECT                  0x904F
#define GL_IMAGE_CUBE                     0x9050
#define GL_IMAGE_BUFFER                   0x9051
#define GL_IMAGE_1D_ARRAY                 0x9052
#define GL_IMAGE_2D_ARRAY                 0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY           0x9054
#define GL_IMAGE_2D_MULTISAMPLE           0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY     0x9056
#define GL_INT_IMAGE_1D                   0x9057
#define GL_INT_IMAGE_2D                   0x9058
#define GL_INT_IMAGE_3D                   0x9059
#define GL_INT_IMAGE_2D_RECT              0x905A
#define GL_INT_IMAGE_CUBE                 0x905B
#define GL_INT_IMAGE_BUFFER               0x905C
#define GL_INT_IMAGE_1D_ARRAY             0x905D
#define GL_INT_IMAGE_2D_ARRAY             0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY       0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE       0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x9061
#define GL_UNSIGNED_INT_IMAGE_1D          0x9062
#define GL_UNSIGNED_INT_IMAGE_2D          0x9063
#define GL_UNSIGNED_INT_IMAGE_3D          0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT     0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE        0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER      0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY    0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY    0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY 0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE 0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x906C
#define GL_MAX_IMAGE_SAMPLES              0x906D
#define GL_IMAGE_BINDING_FORMAT           0x906E
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE 0x90C7
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE 0x90C8
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS 0x90C9
#define GL_MAX_VERTEX_IMAGE_UNIFORMS      0x90CA
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS 0x90CB
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS 0x90CC
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS    0x90CD
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS    0x90CE
#define GL_MAX_COMBINED_IMAGE_UNIFORMS    0x90CF
#define GL_TEXTURE_IMMUTABLE_FORMAT       0x912F
typedef void(*DrawArraysInstancedBaseInstance_t) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
typedef void(*DrawElementsInstancedBaseInstance_t) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
typedef void(*DrawElementsInstancedBaseVertexBaseInstance_t) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
typedef void(*GetInternalFormativ_t) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);
typedef void(*GetActiveAtomicCounterBufferiv_t) (GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
typedef void(*BindImageTexture_t) (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
typedef void(*MemoryBarrier_t) (GLbitfield barriers);
typedef void(*TexStorage1D_t) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void(*TexStorage2D_t) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void(*TexStorage3D_t) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void(*DrawTransformFeedbackInstanced) (GLenum mode, GLuint id, GLsizei instancecount);
typedef void(*DrawTransformFeedbackStreamInstanced) (GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);

//OpenGL 4.3 Extensions
typedef void (*Debug_t)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);
#define GL_NUM_SHADING_LANGUAGE_VERSIONS  0x82E9
#define GL_VERTEX_ATTRIB_ARRAY_LONG       0x874E
#define GL_COMPRESSED_RGB8_ETC2           0x9274
#define GL_COMPRESSED_SRGB8_ETC2          0x9275
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9276
#define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9277
#define GL_COMPRESSED_RGBA8_ETC2_EAC      0x9278
#define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC 0x9279
#define GL_COMPRESSED_R11_EAC             0x9270
#define GL_COMPRESSED_SIGNED_R11_EAC      0x9271
#define GL_COMPRESSED_RG11_EAC            0x9272
#define GL_COMPRESSED_SIGNED_RG11_EAC     0x9273
#define GL_PRIMITIVE_RESTART_FIXED_INDEX  0x8D69
#define GL_ANY_SAMPLES_PASSED_CONSERVATIVE 0x8D6A
#define GL_MAX_ELEMENT_INDEX              0x8D6B
#define GL_COMPUTE_SHADER                 0x91B9
#define GL_MAX_COMPUTE_UNIFORM_BLOCKS     0x91BB
#define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS 0x91BC
#define GL_MAX_COMPUTE_IMAGE_UNIFORMS     0x91BD
#define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE 0x8262
#define GL_MAX_COMPUTE_UNIFORM_COMPONENTS 0x8263
#define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS 0x8264
#define GL_MAX_COMPUTE_ATOMIC_COUNTERS    0x8265
#define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS 0x8266
#define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS 0x90EB
#define GL_MAX_COMPUTE_WORK_GROUP_COUNT   0x91BE
#define GL_MAX_COMPUTE_WORK_GROUP_SIZE    0x91BF
#define GL_COMPUTE_WORK_GROUP_SIZE        0x8267
#define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER 0x90EC
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER 0x90ED
#define GL_DISPATCH_INDIRECT_BUFFER       0x90EE
#define GL_DISPATCH_INDIRECT_BUFFER_BINDING 0x90EF
#define GL_DEBUG_OUTPUT_SYNCHRONOUS       0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION        0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM      0x8245
#define GL_DEBUG_SOURCE_API               0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM     0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER   0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY       0x8249
#define GL_DEBUG_SOURCE_APPLICATION       0x824A
#define GL_DEBUG_SOURCE_OTHER             0x824B
#define GL_DEBUG_TYPE_ERROR               0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR  0x824E
#define GL_DEBUG_TYPE_PORTABILITY         0x824F
#define GL_DEBUG_TYPE_PERFORMANCE         0x8250
#define GL_DEBUG_TYPE_OTHER               0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH       0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES      0x9144
#define GL_DEBUG_LOGGED_MESSAGES          0x9145
#define GL_DEBUG_SEVERITY_HIGH            0x9146
#define GL_DEBUG_SEVERITY_MEDIUM          0x9147
#define GL_DEBUG_SEVERITY_LOW             0x9148
#define GL_DEBUG_TYPE_MARKER              0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP          0x8269
#define GL_DEBUG_TYPE_POP_GROUP           0x826A
#define GL_DEBUG_SEVERITY_NOTIFICATION    0x826B
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH    0x826C
#define GL_DEBUG_GROUP_STACK_DEPTH        0x826D
#define GL_BUFFER                         0x82E0
#define GL_SHADER                         0x82E1
#define GL_PROGRAM                        0x82E2
#define GL_QUERY                          0x82E3
#define GL_PROGRAM_PIPELINE               0x82E4
#define GL_SAMPLER                        0x82E6
#define GL_MAX_LABEL_LENGTH               0x82E8
#define GL_DEBUG_OUTPUT                   0x92E0
#define GL_CONTEXT_FLAG_DEBUG_BIT         0x00000002
#define GL_MAX_UNIFORM_LOCATIONS          0x826E
#define GL_FRAMEBUFFER_DEFAULT_WIDTH      0x9310
#define GL_FRAMEBUFFER_DEFAULT_HEIGHT     0x9311
#define GL_FRAMEBUFFER_DEFAULT_LAYERS     0x9312
#define GL_FRAMEBUFFER_DEFAULT_SAMPLES    0x9313
#define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS 0x9314
#define GL_MAX_FRAMEBUFFER_WIDTH          0x9315
#define GL_MAX_FRAMEBUFFER_HEIGHT         0x9316
#define GL_MAX_FRAMEBUFFER_LAYERS         0x9317
#define GL_MAX_FRAMEBUFFER_SAMPLES        0x9318
#define GL_INTERNALFORMAT_SUPPORTED       0x826F
#define GL_INTERNALFORMAT_PREFERRED       0x8270
#define GL_INTERNALFORMAT_RED_SIZE        0x8271
#define GL_INTERNALFORMAT_GREEN_SIZE      0x8272
#define GL_INTERNALFORMAT_BLUE_SIZE       0x8273
#define GL_INTERNALFORMAT_ALPHA_SIZE      0x8274
#define GL_INTERNALFORMAT_DEPTH_SIZE      0x8275
#define GL_INTERNALFORMAT_STENCIL_SIZE    0x8276
#define GL_INTERNALFORMAT_SHARED_SIZE     0x8277
#define GL_INTERNALFORMAT_RED_TYPE        0x8278
#define GL_INTERNALFORMAT_GREEN_TYPE      0x8279
#define GL_INTERNALFORMAT_BLUE_TYPE       0x827A
#define GL_INTERNALFORMAT_ALPHA_TYPE      0x827B
#define GL_INTERNALFORMAT_DEPTH_TYPE      0x827C
#define GL_INTERNALFORMAT_STENCIL_TYPE    0x827D
#define GL_MAX_WIDTH                      0x827E
#define GL_MAX_HEIGHT                     0x827F
#define GL_MAX_DEPTH                      0x8280
#define GL_MAX_LAYERS                     0x8281
#define GL_MAX_COMBINED_DIMENSIONS        0x8282
#define GL_COLOR_COMPONENTS               0x8283
#define GL_DEPTH_COMPONENTS               0x8284
#define GL_STENCIL_COMPONENTS             0x8285
#define GL_COLOR_RENDERABLE               0x8286
#define GL_DEPTH_RENDERABLE               0x8287
#define GL_STENCIL_RENDERABLE             0x8288
#define GL_FRAMEBUFFER_RENDERABLE         0x8289
#define GL_FRAMEBUFFER_RENDERABLE_LAYERED 0x828A
#define GL_FRAMEBUFFER_BLEND              0x828B
#define GL_READ_PIXELS                    0x828C
#define GL_READ_PIXELS_FORMAT             0x828D
#define GL_READ_PIXELS_TYPE               0x828E
#define GL_TEXTURE_IMAGE_FORMAT           0x828F
#define GL_TEXTURE_IMAGE_TYPE             0x8290
#define GL_GET_TEXTURE_IMAGE_FORMAT       0x8291
#define GL_GET_TEXTURE_IMAGE_TYPE         0x8292
#define GL_MIPMAP                         0x8293
#define GL_MANUAL_GENERATE_MIPMAP         0x8294
#define GL_AUTO_GENERATE_MIPMAP           0x8295
#define GL_COLOR_ENCODING                 0x8296
#define GL_SRGB_READ                      0x8297
#define GL_SRGB_WRITE                     0x8298
#define GL_FILTER                         0x829A
#define GL_VERTEX_TEXTURE                 0x829B
#define GL_TESS_CONTROL_TEXTURE           0x829C
#define GL_TESS_EVALUATION_TEXTURE        0x829D
#define GL_GEOMETRY_TEXTURE               0x829E
#define GL_FRAGMENT_TEXTURE               0x829F
#define GL_COMPUTE_TEXTURE                0x82A0
#define GL_TEXTURE_SHADOW                 0x82A1
#define GL_TEXTURE_GATHER                 0x82A2
#define GL_TEXTURE_GATHER_SHADOW          0x82A3
#define GL_SHADER_IMAGE_LOAD              0x82A4
#define GL_SHADER_IMAGE_STORE             0x82A5
#define GL_SHADER_IMAGE_ATOMIC            0x82A6
#define GL_IMAGE_TEXEL_SIZE               0x82A7
#define GL_IMAGE_COMPATIBILITY_CLASS      0x82A8
#define GL_IMAGE_PIXEL_FORMAT             0x82A9
#define GL_IMAGE_PIXEL_TYPE               0x82AA
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST 0x82AC
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST 0x82AD
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE 0x82AE
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE 0x82AF
#define GL_TEXTURE_COMPRESSED_BLOCK_WIDTH 0x82B1
#define GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT 0x82B2
#define GL_TEXTURE_COMPRESSED_BLOCK_SIZE  0x82B3
#define GL_CLEAR_BUFFER                   0x82B4
#define GL_TEXTURE_VIEW                   0x82B5
#define GL_VIEW_COMPATIBILITY_CLASS       0x82B6
#define GL_FULL_SUPPORT                   0x82B7
#define GL_CAVEAT_SUPPORT                 0x82B8
#define GL_IMAGE_CLASS_4_X_32             0x82B9
#define GL_IMAGE_CLASS_2_X_32             0x82BA
#define GL_IMAGE_CLASS_1_X_32             0x82BB
#define GL_IMAGE_CLASS_4_X_16             0x82BC
#define GL_IMAGE_CLASS_2_X_16             0x82BD
#define GL_IMAGE_CLASS_1_X_16             0x82BE
#define GL_IMAGE_CLASS_4_X_8              0x82BF
#define GL_IMAGE_CLASS_2_X_8              0x82C0
#define GL_IMAGE_CLASS_1_X_8              0x82C1
#define GL_IMAGE_CLASS_11_11_10           0x82C2
#define GL_IMAGE_CLASS_10_10_10_2         0x82C3
#define GL_VIEW_CLASS_128_BITS            0x82C4
#define GL_VIEW_CLASS_96_BITS             0x82C5
#define GL_VIEW_CLASS_64_BITS             0x82C6
#define GL_VIEW_CLASS_48_BITS             0x82C7
#define GL_VIEW_CLASS_32_BITS             0x82C8
#define GL_VIEW_CLASS_24_BITS             0x82C9
#define GL_VIEW_CLASS_16_BITS             0x82CA
#define GL_VIEW_CLASS_8_BITS              0x82CB
#define GL_VIEW_CLASS_S3TC_DXT1_RGB       0x82CC
#define GL_VIEW_CLASS_S3TC_DXT1_RGBA      0x82CD
#define GL_VIEW_CLASS_S3TC_DXT3_RGBA      0x82CE
#define GL_VIEW_CLASS_S3TC_DXT5_RGBA      0x82CF
#define GL_VIEW_CLASS_RGTC1_RED           0x82D0
#define GL_VIEW_CLASS_RGTC2_RG            0x82D1
#define GL_VIEW_CLASS_BPTC_UNORM          0x82D2
#define GL_VIEW_CLASS_BPTC_FLOAT          0x82D3
#define GL_UNIFORM                        0x92E1
#define GL_UNIFORM_BLOCK                  0x92E2
#define GL_PROGRAM_INPUT                  0x92E3
#define GL_PROGRAM_OUTPUT                 0x92E4
#define GL_BUFFER_VARIABLE                0x92E5
#define GL_SHADER_STORAGE_BLOCK           0x92E6
#define GL_VERTEX_SUBROUTINE              0x92E8
#define GL_TESS_CONTROL_SUBROUTINE        0x92E9
#define GL_TESS_EVALUATION_SUBROUTINE     0x92EA
#define GL_GEOMETRY_SUBROUTINE            0x92EB
#define GL_FRAGMENT_SUBROUTINE            0x92EC
#define GL_COMPUTE_SUBROUTINE             0x92ED
#define GL_VERTEX_SUBROUTINE_UNIFORM      0x92EE
#define GL_TESS_CONTROL_SUBROUTINE_UNIFORM 0x92EF
#define GL_TESS_EVALUATION_SUBROUTINE_UNIFORM 0x92F0
#define GL_GEOMETRY_SUBROUTINE_UNIFORM    0x92F1
#define GL_FRAGMENT_SUBROUTINE_UNIFORM    0x92F2
#define GL_COMPUTE_SUBROUTINE_UNIFORM     0x92F3
#define GL_TRANSFORM_FEEDBACK_VARYING     0x92F4
#define GL_ACTIVE_RESOURCES               0x92F5
#define GL_MAX_NAME_LENGTH                0x92F6
#define GL_MAX_NUM_ACTIVE_VARIABLES       0x92F7
#define GL_MAX_NUM_COMPATIBLE_SUBROUTINES 0x92F8
#define GL_NAME_LENGTH                    0x92F9
#define GL_TYPE                           0x92FA
#define GL_ARRAY_SIZE                     0x92FB
#define GL_OFFSET                         0x92FC
#define GL_BLOCK_INDEX                    0x92FD
#define GL_ARRAY_STRIDE                   0x92FE
#define GL_MATRIX_STRIDE                  0x92FF
#define GL_IS_ROW_MAJOR                   0x9300
#define GL_ATOMIC_COUNTER_BUFFER_INDEX    0x9301
#define GL_BUFFER_BINDING                 0x9302
#define GL_BUFFER_DATA_SIZE               0x9303
#define GL_NUM_ACTIVE_VARIABLES           0x9304
#define GL_ACTIVE_VARIABLES               0x9305
#define GL_REFERENCED_BY_VERTEX_SHADER    0x9306
#define GL_REFERENCED_BY_TESS_CONTROL_SHADER 0x9307
#define GL_REFERENCED_BY_TESS_EVALUATION_SHADER 0x9308
#define GL_REFERENCED_BY_GEOMETRY_SHADER  0x9309
#define GL_REFERENCED_BY_FRAGMENT_SHADER  0x930A
#define GL_REFERENCED_BY_COMPUTE_SHADER   0x930B
#define GL_TOP_LEVEL_ARRAY_SIZE           0x930C
#define GL_TOP_LEVEL_ARRAY_STRIDE         0x930D
#define GL_LOCATION                       0x930E
#define GL_LOCATION_INDEX                 0x930F
#define GL_IS_PER_PATCH                   0x92E7
#define GL_SHADER_STORAGE_BUFFER          0x90D2
#define GL_SHADER_STORAGE_BUFFER_BINDING  0x90D3
#define GL_SHADER_STORAGE_BUFFER_START    0x90D4
#define GL_SHADER_STORAGE_BUFFER_SIZE     0x90D5
#define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS 0x90D6
#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS 0x90D7
#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS 0x90D8
#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS 0x90D9
#define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS 0x90DA
#define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS 0x90DB
#define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS 0x90DC
#define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS 0x90DD
#define GL_MAX_SHADER_STORAGE_BLOCK_SIZE  0x90DE
#define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT 0x90DF
#define GL_SHADER_STORAGE_BARRIER_BIT     0x00002000
#define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES 0x8F39
#define GL_DEPTH_STENCIL_TEXTURE_MODE     0x90EA
#define GL_TEXTURE_BUFFER_OFFSET          0x919D
#define GL_TEXTURE_BUFFER_SIZE            0x919E
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT 0x919F
#define GL_TEXTURE_VIEW_MIN_LEVEL         0x82DB
#define GL_TEXTURE_VIEW_NUM_LEVELS        0x82DC
#define GL_TEXTURE_VIEW_MIN_LAYER         0x82DD
#define GL_TEXTURE_VIEW_NUM_LAYERS        0x82DE
#define GL_TEXTURE_IMMUTABLE_LEVELS       0x82DF
#define GL_VERTEX_ATTRIB_BINDING          0x82D4
#define GL_VERTEX_ATTRIB_RELATIVE_OFFSET  0x82D5
#define GL_VERTEX_BINDING_DIVISOR         0x82D6
#define GL_VERTEX_BINDING_OFFSET          0x82D7
#define GL_VERTEX_BINDING_STRIDE          0x82D8
#define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D9
#define GL_MAX_VERTEX_ATTRIB_BINDINGS     0x82DA
#define GL_DISPLAY_LIST                   0x82E7
typedef void(*ClearBufferData_t) (GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
typedef void(*ClearBufferSubData_t) (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
typedef void(*DispatchCompute_t) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
typedef void(*DispatchComputeIndirect_t) (GLintptr indirect);
typedef void(*CopyImageSubData_t) (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
typedef void(*FramebufferParameteri_t) (GLenum target, GLenum pname, GLint param);
typedef void(*GetFramebufferParameteriv_t) (GLenum target, GLenum pname, GLint *params);
typedef void(*GetInternalFormati64v_t) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params);
typedef void(*InvalidateTexSubImage_t) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
typedef void(*InvalidateTexImage_t) (GLuint texture, GLint level);
typedef void(*InvalidateBufferSubData_t) (GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void(*InvalidateBufferData_t) (GLuint buffer);
typedef void(*InvalidateFramebuffer_t) (GLenum target, GLsizei numAttachments, const GLenum *attachments);
typedef void(*InvalidateSubFramebuffer_t) (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void(*MultiDrawArraysIndirect_t) (GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
typedef void(*MultiDrawElementsIndirect_t) (GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
typedef void(*GetProgramInterfaceiv_t) (GLuint program, GLenum programInterface, GLenum pname, GLint *params);
typedef GLuint(*GetProgramResourceIndex_t) (GLuint program, GLenum programInterface, const GLchar *name);
typedef void(*GetProgramResourceName_t) (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
typedef void(*GetProgramResourceiv_t) (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params);
typedef GLint(*GetProgramResourceLocation_t) (GLuint program, GLenum programInterface, const GLchar *name);
typedef GLint(*GetProgramResourceLocationIndex_t) (GLuint program, GLenum programInterface, const GLchar *name);
typedef void(*ShaderStorageBlockBinding_t) (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
typedef void(*TexBufferRange_t) (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void(*TexStorage2DMultisample_t) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void(*TexStorage3DMultisample_t) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void(*TextureView_t) (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
typedef void(*BindVertexBuffer_t) (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void(*VertexAttribFormat_t) (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void(*VertexAttribIFormat_t) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void(*VertexAttribLFormat_t) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void(*VertexAttribBinding_t) (GLuint attribindex, GLuint bindingindex);
typedef void(*VertexBindingDivisor_t) (GLuint bindingindex, GLuint divisor);
typedef void(*DebugMessageControl_t) (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
typedef void(*DebugMessageInsert_t) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
typedef void(*DebugMessageCallback_t) (Debug_t callback, const void *userParam);
typedef GLuint(*GetDebugMessageLog_t) (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
typedef void(*PushDebugGroup_t) (GLenum source, GLuint id, GLsizei length, const GLchar *message);
typedef void(*PopDebugGroup_t) (void);
typedef void(*ObjectLabel_t) (GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
typedef void(*ObjectPtrLabel_t) (const void *ptr, GLsizei length, const GLchar *label);
typedef void(*GetObjectLabel_t) (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
typedef void(*GetObjectPtrLabel_t) (const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);

//OpenGL 4.4 Extensions
#define GL_MAX_VERTEX_ATTRIB_STRIDE       0x82E5
#define GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED 0x8221
#define GL_TEXTURE_BUFFER_BINDING         0x8C2A
#define GL_MAP_PERSISTENT_BIT             0x0040
#define GL_MAP_COHERENT_BIT               0x0080
#define GL_DYNAMIC_STORAGE_BIT            0x0100
#define GL_CLIENT_STORAGE_BIT             0x0200
#define GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT 0x00004000
#define GL_BUFFER_IMMUTABLE_STORAGE       0x821F
#define GL_BUFFER_STORAGE_FLAGS           0x8220
#define GL_CLEAR_TEXTURE                  0x9365
#define GL_LOCATION_COMPONENT             0x934A
#define GL_TRANSFORM_FEEDBACK_BUFFER_INDEX 0x934B
#define GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE 0x934C
#define GL_QUERY_BUFFER                   0x9192
#define GL_QUERY_BUFFER_BARRIER_BIT       0x00008000
#define GL_QUERY_BUFFER_BINDING           0x9193
#define GL_QUERY_RESULT_NO_WAIT           0x9194
#define GL_MIRROR_CLAMP_TO_EDGE           0x8743
typedef void(*BufferStorage_t) (GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
typedef void(*ClearTexImage_t) (GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
typedef void(*ClearTexSubImage_t) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
typedef void(*BindBuffersBase_t) (GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
typedef void(*BindBuffersRange_t) (GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
typedef void(*BindTextures_t) (GLuint first, GLsizei count, const GLuint *textures);
typedef void(*BindSamplers_t) (GLuint first, GLsizei count, const GLuint *samplers);
typedef void(*BindImageTextures_t) (GLuint first, GLsizei count, const GLuint *textures);
typedef void(*BindVertexBuffers_t) (GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);

	class extensionManager
	{
	public:

		GLuint glVersionMajor;
		GLuint glVersionMinor;

		extensionManager(void)
		{
			InitializeGLVersion();
		}

#pragma region

		//1.2 extensions
		std::function<void(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices)>																							glDrawRangeElements;
		std::function<void(GLenum target, GLuint level, GLuint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels)>					glTexImage3D;
		std::function<void(GLenum target, GLuint level, GLint xOffset, GLint yOffset, GLint zOffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels)>			glTexSubImage3D;
		std::function<void(GLenum target, GLuint level, GLint xOffset, GLint yOffset, GLint zOffset, GLint x, GLint y, GLsizei width, GLsizei height)>														glCopyTexSubImage3D;

		//1.3 extensions
		std::function<void(GLenum texture)>																																									glActiveTexture;
		std::function<void(GLfloat value, GLboolean invert)>																																				glSampleCoverage;
		std::function<void(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data)>								glCompressedTexImage3D;
		std::function<void(GLenum target, GLint level, GLenum internalFormat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data)>											glCompressedTexImage2D;
		std::function<void(GLenum target, GLint level, GLenum internalFormat, GLsizei width, GLint border, GLsizei imageSize, const void* data)>															glCompressedTexImage1D;
		std::function<void(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data)>		glCompressedTexSubImage3D;
		std::function<void(GLenum target, GLint level, GLint xOffset, GLint yOffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data)>									glCompressedTexSubImage2D;
		std::function<void(GLenum target, GLint level, GLint xOffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data)>																	glCompressedTexSubImage1D;
		std::function<void(GLenum target, GLint level, void* image)>																																		glGetCompressedTexImage;
		std::function<void(GLenum texture)>																																									glClientActiveTexture;
		std::function<void(GLenum target, GLdouble s)>																																						glMultiTexCoord1d;
		std::function<void(GLenum target, const GLdouble* v)>																																				glMultiTexCoord1dv;
		std::function<void(GLenum target, GLfloat s)>																																						glMultiTexCoord1f;
		std::function<void(GLenum target, const GLfloat* v)>																																				glMultiTexCoord1fv;
		std::function<void(GLenum target, GLint s)>																																							glMultiTexCoord1i;
		std::function<void(GLenum target, const GLint* v)>																																					glMultiTexCoord1iv;
		std::function<void(GLenum target, GLshort s)>																																						glMultiTexCoord1s;
		std::function<void(GLenum target, const GLshort* v)>																																				glMultiTexCoord1sv;
		std::function<void(GLenum target, GLdouble s, GLdouble t)>																																			glMultiTexCoord2d;
		std::function<void(GLenum target, const GLdouble* v)>																																				glMultiTexCoord2dv;
		std::function<void(GLenum target, GLfloat s, GLfloat t)>																																			glMultiTexCoord2f;
		std::function<void(GLenum target, const GLfloat* v)>																																				glMultiTexCoord2fv;
		std::function<void(GLenum target, GLint s, GLint t)>																																				glMultiTexCoord2i;
		std::function<void(GLenum target, const GLint* v)>																																					glMultiTexCoord2iv;
		std::function<void(GLenum target, GLshort s, GLshort t)>																																			glMultiTexCoord2s;
		std::function<void(GLenum target, const GLshort* v)>																																				glMultiTexCoord2sv;
		std::function<void(GLenum target, GLdouble s, GLdouble t, GLdouble r)>																																glMultiTexCoord3d;
		std::function<void(GLenum target, const GLdouble* v)>																																				glMultiTexCoord3dv;
		std::function<void(GLenum target, GLfloat s, GLfloat t, GLfloat r)>																																	glMultiTexCoord3f;
		std::function<void(GLenum target, const GLfloat* v)>																																				glMultiTexCoord3fv;
		std::function<void(GLenum target, GLint s, GLint t, GLint r)>																																		glMultiTexCoord3i;
		std::function<void(GLenum target, const GLint* v)>																																					glMultiTexCoord3iv;
		std::function<void(GLenum target, GLshort s, GLshort t, GLshort r)>																																	glMultiTexCoord3s;
		std::function<void(GLenum target, const GLshort* v)>																																				glMultiTexCoord3sv;
		std::function<void(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q)>																													glMultiTexCoord4d;
		std::function<void(GLenum target, const GLdouble* v)>																																				glMultiTexCoord4dv;
		std::function<void(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q)>																														glMultiTexCoord4f;
		std::function<void(GLenum target, const GLfloat* v)>																																				glMultiTexCoord4fv;
		std::function<void(GLenum target, GLint s, GLint t, GLint r, GLint q)>																																glMultiTexCoord4i;
		std::function<void(GLenum target, const GLint* v)>																																					glMultiTexCoord4iv;
		std::function<void(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q)>																														glMultiTexCoord4s;
		std::function<void(GLenum target, const GLshort* v)>																																				glMultiTexCoord4sv;
		std::function<void(const GLfloat* m)>																																								glLoadTransposeMatrixf;
		std::function<void(const GLdouble* m)>																																								glLoadTransposeMatrixd;
		std::function<void(const GLfloat* m)>																																								glMultTransposeMatrixf;
		std::function<void(const GLdouble* m)>																																								glMultTransposeMatrixd;

		//1.4 extensions
		std::function<void(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)>						glBlendFuncSeparate;
		std::function<void(GLenum mode, const GLint* first, const GLsizei *count, GLsizei drawcount)>							glMultiDrawArrays;
		std::function<void(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount)>		glMultiDrawElements;
		std::function<void(GLenum pname, GLfloat param)>																		glPointParameterf;
		std::function<void(GLenum pname, const GLfloat* params)>																glPointParameterfv;
		std::function<void(GLenum pname, GLint param)>																			glPointParameteri;
		std::function<void(GLenum pname, const GLint* params)>																	glPointParameteriv;
		std::function<void(GLfloat coord)>																						glFogCoordf;
		std::function<void(const GLfloat* coord)>																				glFogCoordfv;
		std::function<void(GLdouble coord)>																						glFogCoordd;
		std::function<void(const GLdouble* coord)>																				glFogCoorddv;
		std::function<void(GLenum type, GLsizei stride, const void* pointer)>													glFogCoordPointer;
		std::function<void(GLbyte red, GLbyte green, GLbyte blue)>																glSecondaryColor3b;
		std::function<void(const GLbyte* v)>																					glSecondaryColor3bv;
		std::function<void(GLdouble red, GLdouble green, GLdouble blue)>														glSecondaryColor3d;
		std::function<void(const GLdouble* v)>																					glSecondaryColor3dv;
		std::function<void(GLfloat red, GLfloat green, GLfloat blue)>															glSecondaryColor3f;
		std::function<void(const GLfloat* v)>																					glSecondaryColor3fv;
		std::function<void(GLint red, GLint green, GLint blue)>																	glSecondaryColor3i;
		std::function<void(const GLint* v)>																						glSecondaryColor3iv;
		std::function<void(GLshort red, GLshort green, GLshort blue)>															glSecondaryColor3s;
		std::function<void(const GLshort* v)>																					glSecondaryColor3sv;
		std::function<void(GLubyte red, GLubyte green, GLubyte blue)>															glSecondaryColor3ub;
		std::function<void(const GLubyte* v)>																					glSecondaryColor3ubv;
		std::function<void(GLuint red, GLuint green, GLuint blue)>																glSecondaryColor3ui;
		std::function<void(const GLuint* v)>																					glSecondaryColor3uiv;
		std::function<void(GLushort red, GLushort green, GLushort blue)>														glSecondaryColor3us;
		std::function<void(const GLushort* v)>																					glSecondaryColor3usv;
		std::function<void(GLint size, GLenum type, GLsizei stride, const void *pointer)>										glSecondaryColorPointer;
		std::function<void(GLdouble x, GLdouble y)>																				glWindowPos2d;
		std::function<void(const GLdouble* v)>																					glWindowPos2dv;
		std::function<void(GLfloat x, GLfloat y)>																				glWindowPos2f;
		std::function<void(const GLfloat* v)>																					glWindowPos2fv;
		std::function<void(GLint x, GLint y)>																					glWindowPos2i;
		std::function<void(const GLint* v)>																						glWindowPos2iv;
		std::function<void(GLshort x, GLshort y)>																				glWindowPos2s;
		std::function<void(const GLshort* v)>																					glWindowPos2sv;
		std::function<void(GLdouble x, GLdouble y, GLdouble z)>																	glWindowPos3d;
		std::function<void(const GLdouble* v)>																					glWindowPos3dv;
		std::function<void(GLfloat x, GLfloat y, GLfloat z)>																	glWindowPos3f;
		std::function<void(const GLfloat* v)>																					glWindowPos3fv;
		std::function<void(GLint x, GLint y, GLint z)>																			glWindowPos3i;
		std::function<void(const GLint* v)>																						glWindowPos3iv;
		std::function<void(GLshort x, GLshort y, GLshort z)>																	glWindowPos3s;
		std::function<void(const GLshort* v)>																					glWindowPos3sv;
		std::function<void(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)>											glBlendColor;
		std::function<void(GLenum mode)>																						glBlendEquation;

		//1.5 extensions
		std::function<void(GLsizei n, GLuint* ids)>													glGenQueries;
		std::function<void(GLsizei n, const GLuint* ids)>											glDeleteQueries;
		std::function<GLboolean(GLuint id)>															glIsQuery;
		std::function<void(GLenum target, GLuint id)>												glBeginQuery;
		std::function<void(GLenum target)>															glEndQuery;
		std::function<void(GLenum target, GLenum pname, GLint* params)>								glGetQueryiv;
		std::function<void(GLuint id, GLenum pname, GLint* params)>									glGetQueryObjectiv;
		std::function<void(GLuint id, GLenum pname, GLuint* params)>								glGetQueryObjectuiv;
		std::function<void(GLenum target, GLuint buffer)>											glBindBuffer;
		std::function<void(GLsizei n, const GLuint* buffers)>										glDeleteBuffers;
		std::function<void(GLsizei n, GLuint* buffers)>												glGenBuffers;
		std::function<GLboolean(GLuint buffer)>														glIsBuffer;
		std::function<void(GLenum target, GLsizeiptr size, const void* data, GLenum usage)>			glBufferData;
		std::function<void(GLenum target, GLintptr offset, GLsizeiptr size, const void* data)>		glBufferSubData;
		std::function<void(GLenum target, GLintptr offset, GLsizeiptr size, void* data)>			glGetBufferSubData;
		std::function<void*(GLenum target, GLenum access)>											glMapBuffer;
		std::function<GLboolean(GLenum target)>														glUnmapBuffer;
		std::function<void(GLenum target, GLenum pname, GLint *params)>								glGetBufferParameteriv;
		std::function<void(GLenum target, GLenum pname, void **params)>								glGetBufferPointerv;

		//2.0 extensions
		std::function<void(GLenum modeRGB, GLenum modeAlpha)>																				glBlendEquationSeparate;
		std::function<void(GLsizei n, const GLenum *bufs)>																					glDrawBuffers;
		std::function<void(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)>														glStencilOpSeparate;
		std::function<void(GLenum face, GLenum func, GLint ref, GLuint mask)>																glStencilFuncSeparate;
		std::function<void(GLenum face, GLuint mask)>																						glStencilMaskSeparate;
		std::function<void(GLuint program, GLuint shader)>																					glAttachShader;
		std::function<void(GLuint program, GLuint index, const GLchar *name)>																glBindAttribLocation;
		std::function<void(GLuint shader)>																									glCompileShader;
		std::function<GLuint(void)>																											glCreateProgram;
		std::function<GLuint(GLenum type)>																									glCreateShader;
		std::function<void(GLuint program)>																									glDeleteProgram;
		std::function<void(GLuint shader)>																									glDeleteShader;
		std::function<void(GLuint program, GLuint shader)>																					glDetachShader;
		std::function<void(GLuint index)>																									glDisableVertexAttribArray;
		std::function<void(GLuint index)>																									glEnableVertexAttribArray;
		std::function<void(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)>		glGetActiveAttrib;
		std::function<void(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)>		glGetActiveUniform;
		std::function<void(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders)>												glGetAttachedShaders;
		std::function<GLint(GLuint program, const GLchar *name)>																			glGetAttribLocation;
		std::function<void(GLuint program, GLenum pname, GLint *params)>																	glGetProgramiv;
		std::function<void(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog)>												glGetProgramInfoLog;
		std::function<void(GLuint shader, GLenum pname, GLint *params)>																		glGetShaderiv;
		std::function<void(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog)>												glGetShaderInfoLog;
		std::function<void(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source)>												glGetShaderSource;
		std::function<GLint(GLuint program, const GLchar *name)>																			glGetUniformLocation;
		std::function<void(GLuint program, GLint location, GLfloat *params)>																glGetUniformfv;
		std::function<void(GLuint program, GLint location, GLint *params)>																	glGetUniformiv;
		std::function<void(GLuint index, GLenum pname, GLdouble *params)>																	glGetVertexAttribdv;
		std::function<void(GLuint index, GLenum pname, GLfloat *params)>																	glGetVertexAttribfv;
		std::function<void(GLuint index, GLenum pname, GLint *params)>																		glGetVertexAttribiv;
		std::function<void(GLuint index, GLenum pname, void **pointer)>																		glGetVertexAttribPointerv;
		std::function<GLboolean(GLuint program)>																							glIsProgram;
		std::function<GLboolean(GLuint shader)>																								glIsShader;
		std::function<void(GLuint program)>																									glLinkProgram;
		std::function<void(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length)>									glShaderSource;
		std::function<void(GLuint program)>																									glUseProgram;
		std::function<void(GLint location, GLfloat v0)>																						glUniform1f;
		std::function<void(GLint location, GLfloat v0, GLfloat v1)>																			glUniform2f;
		std::function<void(GLint location, GLfloat v0, GLfloat v1, GLfloat v2)>																glUniform3f;
		std::function<void(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)>													glUniform4f;
		std::function<void(GLint location, GLint v0)>																						glUniform1i;
		std::function<void(GLint location, GLint v0, GLint v1)>																				glUniform2i;
		std::function<void(GLint location, GLint v0, GLint v1, GLint v2)>																	glUniform3i;
		std::function<void(GLint location, GLint v0, GLint v1, GLint v2, GLint v3)>															glUniform4i;
		std::function<void(GLint location, GLsizei count, const GLfloat *value)>															glUniform1fv;
		std::function<void(GLint location, GLsizei count, const GLfloat *value)>															glUniform2fv;
		std::function<void(GLint location, GLsizei count, const GLfloat *value)>															glUniform3fv;
		std::function<void(GLint location, GLsizei count, const GLfloat *value)>															glUniform4fv;
		std::function<void(GLint location, GLsizei count, const GLint *value)>																glUniform1iv;
		std::function<void(GLint location, GLsizei count, const GLint *value)>																glUniform2iv;
		std::function<void(GLint location, GLsizei count, const GLint *value)>																glUniform3iv;
		std::function<void(GLint location, GLsizei count, const GLint *value)>																glUniform4iv;
		std::function<void(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)>										glUniformMatrix2fv;
		std::function<void(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)>										glUniformMatrix3fv;
		std::function<void(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)>										glUniformMatrix4fv;
		std::function<void(GLuint program)>																									glValidateProgram;
		std::function<void(GLuint index, GLdouble x)>																						glVertexAttrib1d;
		std::function<void(GLuint index, const GLdouble *v)>																				glVertexAttrib1dv;
		std::function<void(GLuint index, GLfloat x)>																						glVertexAttrib1f;
		std::function<void(GLuint index, const GLfloat *v)>																					glVertexAttrib1fv;
		std::function<void(GLuint index, GLshort x)>																						glVertexAttrib1s;
		std::function<void(GLuint index, const GLshort *v)>																					glVertexAttrib1sv;
		std::function<void(GLuint index, GLdouble x, GLdouble y)>																			glVertexAttrib2d;
		std::function<void(GLuint index, const GLdouble *v)>																				glVertexAttrib2dv;
		std::function<void(GLuint index, GLfloat x, GLfloat y)>																				glVertexAttrib2f;
		std::function<void(GLuint index, const GLfloat *v)>																					glVertexAttrib2fv;
		std::function<void(GLuint index, GLshort x, GLshort y)>																				glVertexAttrib2s;
		std::function<void(GLuint index, const GLshort *v)>																					glVertexAttrib2sv;
		std::function<void(GLuint index, GLdouble x, GLdouble y, GLdouble z)>																glVertexAttrib3d;
		std::function<void(GLuint index, const GLdouble *v)>																				glVertexAttrib3dv;
		std::function<void(GLuint index, GLfloat x, GLfloat y, GLfloat z)>																	glVertexAttrib3f;
		std::function<void(GLuint index, const GLfloat *v)>																					glVertexAttrib3fv;
		std::function<void(GLuint index, GLshort x, GLshort y, GLshort z)>																	glVertexAttrib3s;
		std::function<void(GLuint index, const GLshort *v)>																					glVertexAttrib3sv;
		std::function<void(GLuint index, const GLbyte *v)>																					glVertexAttrib4Nbv;
		std::function<void(GLuint index, const GLint *v)>																					glVertexAttrib4Niv;
		std::function<void(GLuint index, const GLshort *v)>																					glVertexAttrib4Nsv;
		std::function<void(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w)>														glVertexAttrib4Nub;
		std::function<void(GLuint index, const GLubyte *v)>																					glVertexAttrib4Nubv;
		std::function<void(GLuint index, const GLuint *v)>																					glVertexAttrib4Nuiv;
		std::function<void(GLuint index, const GLushort *v)>																				glVertexAttrib4Nusv;
		std::function<void(GLuint index, const GLbyte *v)>																					glVertexAttrib4bv;
		std::function<void(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)>													glVertexAttrib4d;
		std::function<void(GLuint index, const GLdouble *v)>																				glVertexAttrib4dv;
		std::function<void(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)>														glVertexAttrib4f;
		std::function<void(GLuint index, const GLfloat *v)>																					glVertexAttrib4fv;
		std::function<void(GLuint index, const GLint *v)>																					glVertexAttrib4iv;
		std::function<void(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w)>														glVertexAttrib4s;
		std::function<void(GLuint index, const GLshort *v)>																					glVertexAttrib4sv;
		std::function<void(GLuint index, const GLubyte *v)>																					glVertexAttrib4ubv;
		std::function<void(GLuint index, const GLuint *v)>																					glVertexAttrib4uiv;
		std::function<void(GLuint index, const GLushort *v)>																				glVertexAttrib4usv;
		std::function<void(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer)>				glVertexAttribPointer;

		//2.1 extensions
		std::function<void(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)>		glUniformMatrix2x3fv;
		std::function<void(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)>		glUniformMatrix3x2fv;
		std::function<void(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)>		glUniformMatrix2x4fv;
		std::function<void(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)>		glUniformMatrix4x2fv;
		std::function<void(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)>		glUniformMatrix3x4fv;
		std::function<void(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)>		glUniformMatrix4x3fv;

		//3.0 extensions
		std::function<void(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a)>																				glColorMaski;
		std::function<void(GLenum target, GLuint index, GLboolean *data)>																									glGetBooleani_v;
		std::function<void(GLenum target, GLuint index, GLint *data)>																										glGetIntegeri_v;
		std::function<void(GLenum target, GLuint index)>																													glEnablei;
		std::function<void(GLenum target, GLuint index)>																													glDisablei;
		std::function<GLboolean(GLenum target, GLuint index)>																												glIsEnabledi;
		std::function<void(GLenum primitiveMode)>																															glBeginTransformFeedback;
		std::function<void(void)>																																			glEndTransformFeedback;
		std::function<void(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)>																	glBindBufferRange;
		std::function<void(GLenum target, GLuint index, GLuint buffer)>																										glBindBufferBase;
		std::function<void(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode)>																	glTransformFeedbackVaryings;
		std::function<void(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name)>										glGetTransformFeedbackVarying;
		std::function<void(GLenum target, GLenum clamp)>																													glClampColor;
		std::function<void(GLuint id, GLenum mode)>																															glBeginConditionalRender;
		std::function<void(void)>																																			glEndConditionalRender;
		std::function<void(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer)>																		glVertexAttribIPointer;
		std::function<void(GLuint index, GLenum pname, GLint *params)>																										glGetVertexAttribIiv;
		std::function<void(GLuint index, GLenum pname, GLuint *params)>																										glGetVertexAttribIuiv;
		std::function<void(GLuint index, GLint x)>																															glVertexAttribI1i;
		std::function<void(GLuint index, GLint x, GLint y)>																													glVertexAttribI2i;
		std::function<void(GLuint index, GLint x, GLint y, GLint z)>																										glVertexAttribI3i;
		std::function<void(GLuint index, GLint x, GLint y, GLint z, GLint w)>																								glVertexAttribI4i;
		std::function<void(GLuint index, GLuint x)>																															glVertexAttribI1ui;
		std::function<void(GLuint index, GLuint x, GLuint y)>																												glVertexAttribI2ui;
		std::function<void(GLuint index, GLuint x, GLuint y, GLuint z)>																										glVertexAttribI3ui;
		std::function<void(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w)>																							glVertexAttribI4ui;
		std::function<void(GLuint index, const GLint *v)>																													glVertexAttribI1iv;
		std::function<void(GLuint index, const GLint *v)>																													glVertexAttribI2iv;
		std::function<void(GLuint index, const GLint *v)>																													glVertexAttribI3iv;
		std::function<void(GLuint index, const GLint *v)>																													glVertexAttribI4iv;
		std::function<void(GLuint index, const GLuint *v)>																													glVertexAttribI1uiv;
		std::function<void(GLuint index, const GLuint *v)>																													glVertexAttribI2uiv;
		std::function<void(GLuint index, const GLuint *v)>																													glVertexAttribI3uiv;
		std::function<void(GLuint index, const GLuint *v)>																													glVertexAttribI4uiv;
		std::function<void(GLuint index, const GLbyte *v)>																													glVertexAttribI4bv;
		std::function<void(GLuint index, const GLshort *v)>																													glVertexAttribI4sv;
		std::function<void(GLuint index, const GLubyte *v)>																													glVertexAttribI4ubv;
		std::function<void(GLuint index, const GLushort *v)>																												glVertexAttribI4usv;
		std::function<void(GLuint program, GLint location, GLuint *params)>																									glGetUniformuiv;
		std::function<void(GLuint program, GLuint color, const GLchar *name)>																								glBindFragDataLocation;
		std::function<GLint(GLuint program, const GLchar *name)>																											glGetFragDataLocation;
		std::function<void(GLint location, GLuint v0)>																														glUniform1ui;
		std::function<void(GLint location, GLuint v0, GLuint v1)>																											glUniform2ui;
		std::function<void(GLint location, GLuint v0, GLuint v1, GLuint v2)>																								glUniform3ui;
		std::function<void(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)>																						glUniform4ui;
		std::function<void(GLint location, GLsizei count, const GLuint *value)>																								glUniform1uiv;
		std::function<void(GLint location, GLsizei count, const GLuint *value)>																								glUniform2uiv;
		std::function<void(GLint location, GLsizei count, const GLuint *value)>																								glUniform3uiv;
		std::function<void(GLint location, GLsizei count, const GLuint *value)>																								glUniform4uiv;
		std::function<void(GLenum target, GLenum pname, const GLint *params)>																								glTexParameterIiv;
		std::function<void(GLenum target, GLenum pname, const GLuint *params)>																								glTexParameterIuiv;
		std::function<void(GLenum target, GLenum pname, GLint *params)>																										glGetTexParameterIiv;
		std::function<void(GLenum target, GLenum pname, GLuint *params)>																									glGetTexParameterIuiv;
		std::function<void(GLenum buffer, GLint drawbuffer, const GLint *value)>																							glClearBufferiv;
		std::function<void(GLenum buffer, GLint drawbuffer, const GLuint *value)>																							glClearBufferuiv;
		std::function<void(GLenum buffer, GLint drawbuffer, const GLfloat *value)>																							glClearBufferfv;
		std::function<void(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil)>																					glClearBufferfi;
		std::function<const GLubyte*(GLenum name, GLuint index)>																											glGetStringi;
		std::function<GLboolean(GLuint renderbuffer)>																														glIsRenderbuffer;
		std::function<void(GLenum target, GLuint renderbuffer)>																												glBindRenderbuffer;
		std::function<void(GLsizei n, const GLuint *renderbuffers)>																											glDeleteRenderbuffers;
		std::function<void(GLsizei n, GLuint *renderbuffers)>																												glGenRenderbuffers;
		std::function<void(GLenum target, GLenum internalformat, GLsizei width, GLsizei height)>																			glRenderbufferStorage;
		std::function<void(GLenum target, GLenum pname, GLint *params)>																										glGetRenderbufferParameteriv;
		std::function<GLboolean(GLuint framebuffer)>																														glIsFramebuffer;
		std::function<void(GLenum target, GLuint framebuffer)>																												glBindFramebuffer;
		std::function<void(GLsizei n, const GLuint *framebuffers)>																											glDeleteFramebuffers;
		std::function<void(GLsizei n, GLuint *framebuffers)>																												glGenFramebuffers;
		std::function<GLenum(GLenum target)>																																glCheckFrameBufferStatus;
		std::function<void(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)>																glFramebufferTexture1D;
		std::function<void(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)>																glFramebufferTexture2D;
		std::function<void(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset)>													glFramebufferTexture3D;
		std::function<void(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)>																glFramebufferRenderbuffer;
		std::function<void(GLenum target, GLenum attachment, GLenum pname, GLint *params)>																					glGetFramebufferAttachmentParameteriv;
		std::function<void(GLenum target)>																																	glGenerateMipmap;
		std::function<void(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)>			glBlitFramebuffer;
		std::function<void(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)>															glRenderbufferStorageMultisample;
		std::function<void(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)>																		glFramebufferTextureLayer;
		std::function<void*(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access)>																			glMapBufferRange;
		std::function<void(GLenum target, GLintptr offset, GLsizeiptr length)>																								glFlushMappedBufferRange;
		std::function<void(GLuint array)>																																	glBindVertexArray;
		std::function<void(GLsizei n, const GLuint *arrays)>																												glDeleteVertexArrays;
		std::function<void(GLsizei n, GLuint *arrays)>																														glGenVertexArrays;
		std::function<GLboolean(GLuint array)>																																glIsVertexArray;

		//3.1 extensions
		std::function<void(GLenum mode, GLint first, GLsizei count, GLsizei instancecount)>												glDrawArraysInstanced;
		std::function<void(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount)>						glDrawElementsInstanced;
		std::function<void(GLenum target, GLenum internalformat, GLuint buffer)>														glTexBuffer;
		std::function<void(GLuint index)>																								glPrimitiveRestartIndex;
		std::function<void(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)>			glCopyBufferSubData;
		std::function<void(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices)>				glGetUniformIndices;
		std::function<void(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params)>			glGetActiveUniformsiv;
		std::function<void(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName)>					glGetActiveUniformName;
		std::function<GLuint(GLuint program, const GLchar *uniformBlockName)>															glGetUniformBlockIndex;
		std::function<void(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params)>										glGetActiveUniformBlockiv;
		std::function<void(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName)>		glGetActiveUniformBlockName;
		std::function<void(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding)>										glUniformBlockBinding;

		//3.2 extensions
		std::function<void(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex)>																glDrawElementsBaseVertex;
		std::function<void(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex)>									glDrawRangeElementsBaseVertex;
		std::function<void(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex)>										glDrawElementsInstancedBaseVertex;
		std::function<void(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex)>						glMultiDrawElementsBaseVertex;
		std::function<void(GLenum mode)>																																glProvokingVertex;
		std::function<GLsync(GLenum condition, GLbitfield flags)>																										glFenceSync;
		std::function<GLboolean(GLsync sync)>																															glIsSync;
		std::function<void(GLsync sync)>																																glDeleteSync;
		std::function<GLenum(GLsync sync, GLbitfield flags, GLuint64 timeout)>																							glClientWaitSync;
		std::function<void(GLsync sync, GLbitfield flags, GLuint64 timeout)>																							glWaitSync;
		std::function<void(GLenum pname, GLint64 *params)>																												glGetInteger64v;
		std::function<void(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values)>																	glGetSynciv;
		std::function<void(GLenum target, GLuint index, GLint64 *data)>																									glGetInteger64i_v;
		std::function<void(GLenum target, GLenum pname, GLint64 *params)>																								glGetBufferParameteri64v;
		std::function<void(GLenum target, GLenum attachment, GLuint texture, GLint level)>																				glFramebufferTexture;
		std::function<void(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)>						glTexImage2DMultisample;
		std::function<void(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)>		glTexImage3DMultisample;
		std::function<void(GLenum pname, GLuint index, GLfloat *val)>																									glGetMultisamplefv;
		std::function<void(GLuint index, GLbitfield mask)>																												glSampleMaski;

		//3.3 extensions
		std::function<void(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name)>		glBindFragDataLocationIndexed;
		std::function<GLint(GLuint program, const GLchar *name)>										glGetFragDataIndex;
		std::function<void(GLsizei count, GLuint *samplers)>											glGenSamplers;
		std::function<void(GLsizei count, const GLuint *samplers)>										glDeleteSamplers;
		std::function<GLboolean(GLuint sampler)>														glIsSampler;
		std::function<void(GLuint unit, GLuint sampler)>												glBindSampler;
		std::function<void(GLuint sampler, GLenum pname, GLint param)>									glSamplerParameteri;
		std::function<void(GLuint sampler, GLenum pname, const GLint *param)>							glSamplerParameteriv;
		std::function<void(GLuint sampler, GLenum pname, GLfloat param)>								glSamplerParameterf;
		std::function<void(GLuint sampler, GLenum pname, const GLfloat *param)>							glSamplerParameterfv;
		std::function<void(GLuint sampler, GLenum pname, const GLint *param)>							glSamplerParameterIiv;
		std::function<void(GLuint sampler, GLenum pname, const GLuint *param)>							glSamplerParameterIuiv;
		std::function<void(GLuint sampler, GLenum pname, GLint *params)>								glGetSamplerParameteriv;
		std::function<void(GLuint sampler, GLenum pname, GLint *params)>								glGetSamplerParameterIiv;
		std::function<void(GLuint sampler, GLenum pname, GLfloat *params)>								glGetSamplerParameterfv;
		std::function<void(GLuint sampler, GLenum pname, GLuint *params)>								glGetSamplerParameterIuiv;
		std::function<void(GLuint id, GLenum target)>													glQueryCounter;
		std::function<void(GLuint id, GLenum pname, GLint64 *params)>									glGetQueryObjecti64v;
		std::function<void(GLuint id, GLenum pname, GLuint64 *params)>									glGetQueryObjectui64v;
		std::function<void(GLuint index, GLuint divisor)>												glVertexAttribDivisor;
		std::function<void(GLuint index, GLenum type, GLboolean normalized, GLuint value)>				glVertexAttribP1ui;
		std::function<void(GLuint index, GLenum type, GLboolean normalized, const GLuint *value)>		glVertexAttribP1uiv;
		std::function<void(GLuint index, GLenum type, GLboolean normalized, GLuint value)>				glVertexAttribP2ui;
		std::function<void(GLuint index, GLenum type, GLboolean normalized, const GLuint *value)>		glVertexAttribP2uiv;
		std::function<void(GLuint index, GLenum type, GLboolean normalized, GLuint value)>				glVertexAttribP3ui;
		std::function<void(GLuint index, GLenum type, GLboolean normalized, const GLuint *value)>		glVertexAttribP3uiv;
		std::function<void(GLuint index, GLenum type, GLboolean normalized, GLuint value)>				glVertexAttribP4ui;
		std::function<void(GLuint index, GLenum type, GLboolean normalized, const GLuint *value)>		glVertexAttribP4uiv;
		std::function<void(GLenum type, GLuint value)>													glVertexP2ui;
		std::function<void(GLenum type, const GLuint *value)>											glVertexP2uiv;
		std::function<void(GLenum type, GLuint value)>													glVertexP3ui;
		std::function<void(GLenum type, const GLuint *value)>											glVertexP3uiv;
		std::function<void(GLenum type, GLuint value)>													glVertexP4ui;
		std::function<void(GLenum type, const GLuint *value)>											glVertexP4uiv;
		std::function<void(GLenum type, GLuint coords)>													glTexCoordP1ui;
		std::function<void(GLenum type, const GLuint *coords)>											glTexCoordP1uiv;
		std::function<void(GLenum type, GLuint coords)>													glTexCoordP2ui;
		std::function<void(GLenum type, const GLuint *coords)>											glTexCoordP2uiv;
		std::function<void(GLenum type, GLuint coords)>													glTexCoordP3ui;
		std::function<void(GLenum type, const GLuint *coords)>											glTexCoordP3uiv;
		std::function<void(GLenum type, GLuint coords)>													glTexCoordP4ui;
		std::function<void(GLenum type, const GLuint *coords)>											glTexCoordP4uiv;
		std::function<void(GLenum texture, GLenum type, GLuint coords)>									glMultiTexCoordP1ui;
		std::function<void(GLenum texture, GLenum type, const GLuint *coords)>							glMultiTexCoordP1uiv;
		std::function<void(GLenum texture, GLenum type, GLuint coords)>									glMultiTexCoordP2ui;
		std::function<void(GLenum texture, GLenum type, const GLuint *coords)>							glMultiTexCoordP2uiv;
		std::function<void(GLenum texture, GLenum type, GLuint coords)>									glMultiTexCoordP3ui;
		std::function<void(GLenum texture, GLenum type, const GLuint *coords)>							glMultiTexCoordP3uiv;
		std::function<void(GLenum texture, GLenum type, GLuint coords)>									glMultiTexCoordP4ui;
		std::function<void(GLenum texture, GLenum type, const GLuint *coords)>							glMultiTexCoordP4uiv;
		std::function<void(GLenum type, GLuint coords)>													glNormalP3ui;
		std::function<void(GLenum type, const GLuint *coords)>											glNormalP3uiv;
		std::function<void(GLenum type, GLuint color)>													glColorP3ui;
		std::function<void(GLenum type, const GLuint *color)>											glColorP3uiv;
		std::function<void(GLenum type, GLuint color)>													glColorP4ui;
		std::function<void(GLenum type, const GLuint *color)>											glColorP4uiv;
		std::function<void(GLenum type, GLuint color)>													glSecondaryColorP3ui;
		std::function<void(GLenum type, const GLuint *color)>											glSecondaryColorP3uiv;

		//4.0 extensions
		std::function<void(GLfloat value)>																							glMinSampleShading;
		std::function<void(GLuint buf, GLenum mode)>																				glBlendEquationi;
		std::function<void(GLuint buf, GLenum modeRGB, GLenum modeAlpha)>															glBlendEquationSeparatei;
		std::function<void(GLuint buf, GLenum src, GLenum dst)>																		glBlendFunci;
		std::function<void(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)>								glBlendFuncSeparatei;
		std::function<void(GLenum mode, const void *indirect)>																		glDrawArraysIndirect;
		std::function<void(GLenum mode, GLenum type, const void *indirect)>															glDrawElementsIndirect;
		std::function<void(GLint location, GLdouble x)>																				glUniform1d;
		std::function<void(GLint location, GLdouble x, GLdouble y)>																	glUniform2d;
		std::function<void(GLint location, GLdouble x, GLdouble y, GLdouble z)>														glUniform3d;
		std::function<void(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w)>											glUniform4d;
		std::function<void(GLint location, GLsizei count, const GLdouble *value)>													glUniform1dv;
		std::function<void(GLint location, GLsizei count, const GLdouble *value)>													glUniform2dv;
		std::function<void(GLint location, GLsizei count, const GLdouble *value)>													glUniform3dv;
		std::function<void(GLint location, GLsizei count, const GLdouble *value)>													glUniform4dv;
		std::function<void(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)>								glUniformMatrix2dv;
		std::function<void(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)>								glUniformMatrix3dv;
		std::function<void(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)>								glUniformMatrix4dv;
		std::function<void(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)>								glUniformMatrix2x3dv;
		std::function<void(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)>								glUniformMatrix2x4dv;
		std::function<void(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)>								glUniformMatrix3x2dv;
		std::function<void(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)>								glUniformMatrix3x4dv;
		std::function<void(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)>								glUniformMatrix4x2dv;
		std::function<void(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)>								glUniformMatrix4x3dv;
		std::function<void(GLuint program, GLint location, GLdouble *params)>														glGetUniformdv;
		std::function<GLint(GLuint program, GLenum shadertype, const GLchar *name)>													glGetSubroutineUniformLocation;
		std::function<GLuint(GLuint program, GLenum shadertype, const GLchar *name)>												glGetSubroutineIndex;
		std::function<void(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values)>							glGetActiveSubroutineUniformiv;
		std::function<void(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name)>		glGetActiveSubroutineUniformName;
		std::function<void(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name)>		glGetActiveSubroutineName;
		std::function<void(GLenum shadertype, GLsizei count, const GLuint *indices)>												glUniformSubroutinesuiv;
		std::function<void(GLenum shadertype, GLint location, GLuint *params)>														glGetUniformSubroutineuiv;
		std::function<void(GLuint program, GLenum shadertype, GLenum pname, GLint *values)>											glGetProgramStageiv;
		std::function<void(GLenum pname, GLint value)>																				glPatchParameteri;
		std::function<void(GLenum pname, const GLfloat *values)>																	glPatchParameterfv;
		std::function<void(GLenum target, GLuint id)>																				glBindTransformFeedback;
		std::function<void(GLsizei n, const GLuint *ids)>																			glDeleteTransformFeedbacks;
		std::function<void(GLsizei n, GLuint *ids)>																					glGenTransformFeedbacks;
		std::function<GLboolean(GLuint id)>																							glIsTransformFeedback;
		std::function<void(void)>																									glPauseTransformFeedback;
		std::function<void(void)>																									glResumeTransformFeedback;
		std::function<void(GLenum mode, GLuint id)>																					glDrawTransformFeedback;
		std::function<void(GLenum mode, GLuint id, GLuint stream)>																	glDrawTransformFeedbackStream;
		std::function<void(GLenum target, GLuint index, GLuint id)>																	glBeginQueryIndexed;
		std::function<void(GLenum target, GLuint index)>																			glEndQueryIndexed;
		std::function<void(GLenum target, GLuint index, GLenum pname, GLint *params)>												glGetQueryIndexediv;

		//4.1 extensions
		std::function<void(void)>																								glReleaseShaderCompiler;
		std::function<void(GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length)>		glShaderBinary;
		std::function<void(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision)>							glGetShaderPrecisionFormat;
		std::function<void(GLfloat n, GLfloat f)>																				glDepthRangef;
		std::function<void(GLfloat d)>																							glClearDepthf;
		std::function<void(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary)>				glGetProgramBinary;
		std::function<void(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length)>							glProgramBinary;
		std::function<void(GLuint program, GLenum pname, GLint value)>															glProgramParameteri;
		std::function<void(GLuint pipeline, GLbitfield stages, GLuint program)>													glUseProgramStages;
		std::function<void(GLuint pipeline, GLuint program)>																	glActiveShaderProgram;
		std::function<GLuint(GLenum type, GLsizei count, const GLchar *const*strings)>											glCreateShaderProgramv;
		std::function<void(GLuint pipeline)>																					glBindProgramPipeline;
		std::function<void(GLsizei n, const GLuint *pipelines)>																	glDeleteProgramPipelines;
		std::function<void(GLsizei n, GLuint *pipelines)>																		glGenProgramPipelines;
		std::function<GLboolean(GLuint pipeline)>																				glIsProgramPipeline;
		std::function<void(GLuint pipeline, GLenum pname, GLint *params)>														glGetProgramPipelineiv;
		std::function<void(GLuint program, GLint location, GLint v0)>															glProgramUniform1i;
		std::function<void(GLuint program, GLint location, GLsizei count, const GLint *value)>									glProgramUniform1iv;
		std::function<void(GLuint program, GLint location, GLfloat v0)>															glProgramUniform1f;
		std::function<void(GLuint program, GLint location, GLsizei count, const GLfloat *value)>								glProgramUniform1fv;
		std::function<void(GLuint program, GLint location, GLdouble v0)>														glProgramUniform1d;
		std::function<void(GLuint program, GLint location, GLsizei count, const GLdouble *value)>								glProgramUniform1dv;
		std::function<void(GLuint program, GLint location, GLuint v0)>															glProgramUniform1ui;
		std::function<void(GLuint program, GLint location, GLsizei count, const GLuint *value)>									glProgramUniform1uiv;
		std::function<void(GLuint program, GLint location, GLint v0, GLint v1)>													glProgramUniform2i;
		std::function<void(GLuint program, GLint location, GLsizei count, const GLint *value)>									glProgramUniform2iv;
		std::function<void(GLuint program, GLint location, GLfloat v0, GLfloat v1)>												glProgramUniform2f;
		std::function<void(GLuint program, GLint location, GLsizei count, const GLfloat *value)>								glProgramUniform2fv;
		std::function<void(GLuint program, GLint location, GLdouble v0, GLdouble v1)>											glProgramUniform2d;
		std::function<void(GLuint program, GLint location, GLsizei count, const GLdouble *value)>								glProgramUniform2dv;
		std::function<void(GLuint program, GLint location, GLuint v0, GLuint v1)>												glProgramUniform2ui;
		std::function<void(GLuint program, GLint location, GLsizei count, const GLuint *value)>									glProgramUniform2uiv;
		std::function<void(GLuint program, GLint location, GLint v0, GLint v1, GLint v2)>										glProgramUniform3i;
		std::function<void(GLuint program, GLint location, GLsizei count, const GLint *value)>									glProgramUniform3iv;
		std::function<void(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2)>									glProgramUniform3f;
		std::function<void(GLuint program, GLint location, GLsizei count, const GLfloat *value)>								glProgramUniform3fv;
		std::function<void(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2)>								glProgramUniform3d;
		std::function<void(GLuint program, GLint location, GLsizei count, const GLdouble *value)>								glProgramUniform3dv;
		std::function<void(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2)>									glProgramUniform3ui;
		std::function<void(GLuint program, GLint location, GLsizei count, const GLuint *value)>									glProgramUniform3uiv;
		std::function<void(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3)>								glProgramUniform4i;
		std::function<void(GLuint program, GLint location, GLsizei count, const GLint *value)>									glProgramUniform4iv;
		std::function<void(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)>						glProgramUniform4f;
		std::function<void(GLuint program, GLint location, GLsizei count, const GLfloat *value)>								glProgramUniform4fv;
		std::function<void(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3)>					glProgramUniform4d;
		std::function<void(GLuint program, GLint location, GLsizei count, const GLdouble *value)>								glProgramUniform4dv;
		std::function<void(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)>							glProgramUniform4ui;
		std::function<void(GLuint program, GLint location, GLsizei count, const GLuint *value)>									glProgramUniform4uiv;
		std::function<void(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)>			glProgramUniformMatrix2fv;
		std::function<void(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)>			glProgramUniformMatrix3fv;
		std::function<void(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)>			glProgramUniformMatrix4fv;
		std::function<void(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)>			glProgramUniformMatrix2dv;
		std::function<void(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)>			glProgramUniformMatrix3dv;
		std::function<void(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)>			glProgramUniformMatrix4dv;
		std::function<void(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)>			glProgramUniformMatrix2x3fv;
		std::function<void(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)>			glProgramUniformMatrix3x2fv;
		std::function<void(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)>			glProgramUniformMatrix2x4fv;
		std::function<void(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)>			glProgramUniformMatrix4x2fv;
		std::function<void(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)>			glProgramUniformMatrix3x4fv;
		std::function<void(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)>			glProgramUniformMatrix4x3fv;
		std::function<void(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)>			glProgramUniformMatrix2x3dv;
		std::function<void(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)>			glProgramUniformMatrix3x2dv;
		std::function<void(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)>			glProgramUniformMatrix2x4dv;
		std::function<void(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)>			glProgramUniformMatrix4x2dv;
		std::function<void(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)>			glProgramUniformMatrix3x4dv;
		std::function<void(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)>			glProgramUniformMatrix4x3dv;
		std::function<void(GLuint pipeline)>																					glValidateProgramPipeline;
		std::function<void(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog)>									glGetProgramPipelineInfoLog;
		std::function<void(GLuint index, GLdouble x)>																			glVertexAttribL1d;
		std::function<void(GLuint index, GLdouble x, GLdouble y)>																glVertexAttribL2d;
		std::function<void(GLuint index, GLdouble x, GLdouble y, GLdouble z)>													glVertexAttribL3d;
		std::function<void(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)>										glVertexAttribL4d;
		std::function<void(GLuint index, const GLdouble *v)>																	glVertexAttribL1dv;
		std::function<void(GLuint index, const GLdouble *v)>																	glVertexAttribL2dv;
		std::function<void(GLuint index, const GLdouble *v)>																	glVertexAttribL3dv;
		std::function<void(GLuint index, const GLdouble *v)>																	glVertexAttribL4dv;
		std::function<void(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer)>							glVertexAttribLPointer;
		std::function<void(GLuint index, GLenum pname, GLdouble *params)>														glGetVertexAttribLdv;
		std::function<void(GLuint first, GLsizei count, const GLfloat *v)>														glViewportArrayv;
		std::function<void(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h)>											glViewportIndexedf;
		std::function<void(GLuint index, const GLfloat *v)>																		glViewportIndexedfv;
		std::function<void(GLuint first, GLsizei count, const GLint *v)>														glScissorArrayv;
		std::function<void(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height)>								glScissorIndexed;
		std::function<void(GLuint index, const GLint *v)>																		glScissorIndexedv;
		std::function<void(GLuint first, GLsizei count, const GLdouble *v)>														glDepthRangeIndexed;
		std::function<void(GLuint index, GLdouble n, GLdouble f)>																glDepthRangeArrayv;
		std::function<void(GLenum target, GLuint index, GLfloat *data)>															glGetFloati_v;
		std::function<void(GLenum target, GLuint index, GLdouble *data)>														glGetDoublei_v;

		//4.2 extensions
		std::function<void(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance)>											glDrawArraysInstancedBaseInstance;
		std::function<void(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance)>						glDrawElementsInstancedBaseInstance;
		std::function<void(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance)>		glDrawElementsInstancedBaseVertexBaseInstance;
		std::function<void(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params)>												glGetInternalformativ;
		std::function<void(GLuint program, GLuint bufferIndex, GLenum pname, GLint *params)>																glGetActiveAtomicCounterBufferiv;
		std::function<void(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format)>							glBindImageTexture;
		std::function<void(GLbitfield barriers)>																											glMemoryBarrier;
		std::function<void(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width)>															glTexStorage1D;
		std::function<void(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)>											glTexStorage2D;
		std::function<void(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)>								glTexStorage3D;
		std::function<void(GLenum mode, GLuint id, GLsizei instancecount)>																					glDrawTransformFeedbackInstanced;
		std::function<void(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount)>																	glDrawTransformFeedbackStreamInstanced;

		//4.3 extensions
		std::function<void(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data)>																																						glClearBufferData;
		std::function<void(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data)>																													glClearBufferSubData;
		std::function<void(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z)>																																											glDispatchCompute;
		std::function<void(GLintptr indirect)>																																																						glDispatchComputeIndirect;
		std::function<void(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth)>		glCopyImageSubData;
		std::function<void(GLenum target, GLenum pname, GLint param)>																																																glFramebufferParameteri;
		std::function<void(GLenum target, GLenum pname, GLint *params)>																																																glGetFramebufferParameteriv;
		std::function<void(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params)>																																					glGetInternalformati64v;
		std::function<void(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth)>																													glInvalidateTexSubImage;
		std::function<void(GLuint texture, GLint level)>																																																			glInvalidateTexImage;
		std::function<void(GLuint buffer, GLintptr offset, GLsizeiptr length)>																																														glInvalidateBufferSubData;
		std::function<void(GLuint buffer)>																																																							glInvalidateBufferData;
		std::function<void(GLenum target, GLsizei numAttachments, const GLenum *attachments)>																																										glInvalidateFramebuffer;
		std::function<void(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height)>																														glInvalidateSubFramebuffer;
		std::function<void(GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride)>																																									glMultiDrawArraysIndirect;
		std::function<void(GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride)>																																						glMultiDrawElementsIndirect;
		std::function<void(GLuint program, GLenum programInterface, GLenum pname, GLint *params)>																																									glGetProgramInterfaceiv;
		std::function<GLuint(GLuint program, GLenum programInterface, const GLchar *name)>																																											glGetProgramResourceIndex;
		std::function<void(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name)>																																	glGetProgramResourceName;
		std::function<void(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params)>																							glGetProgramResourceiv;
		std::function<GLint(GLuint program, GLenum programInterface, const GLchar *name)>																																											glGetProgramResourceLocation;
		std::function<GLint(GLuint program, GLenum programInterface, const GLchar *name)>																																											glGetProgramResourceLocationIndex;
		std::function<void(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding)>																																									glShaderStorageBlockBinding;
		std::function<void(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size)>																																					glTexBufferRange;
		std::function<void(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)>																													glTexStorage2DMultisample;
		std::function<void(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)>																									glTexStorage3DMultisample;
		std::function<void(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers)>																							glTextureView;
		std::function<void(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride)>																																									glBindVertexBuffer;
		std::function<void(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)>																																				glVertexAttribFormat;
		std::function<void(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)>																																										glVertexAttribIFormat;
		std::function<void(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)>																																										glVertexAttribLFormat;
		std::function<void(GLuint attribindex, GLuint bindingindex)>																																																glVertexAttribBinding;
		std::function<void(GLuint bindingindex, GLuint divisor)>																																																	glVertexBindingDivisor;
		std::function<void(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled)>																																		glDebugMessageControl;
		std::function<void(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf)>																																				glDebugMessageInsert;
		std::function<void(Debug_t callback, const void *userParam)>																																																glDebugMessageCallback;
		std::function<GLuint(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog)>																									glGetDebugMessageLog;
		std::function<void(GLenum source, GLuint id, GLsizei length, const GLchar *message)>																																										glPushDebugGroup;
		std::function<void(void)>																																																									glPopDebugGroup;
		std::function<void(GLenum identifier, GLuint name, GLsizei length, const GLchar *label)>																																									glObjectLabel;
		std::function<void(const void *ptr, GLsizei length, const GLchar *label)>																																													glObjectPtrLabel;
		std::function<void(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label)>																																						glGetObjectLabel;
		std::function<void(const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label)>																																										glGetObjectPtrLabel;

		//4.4 extensions																																												
		std::function<void(GLenum target, GLsizeiptr size, const void *data, GLbitfield flags)>																											glBufferStorage;
		std::function<void(GLuint texture, GLint level, GLenum format, GLenum type, const void *data)>																									glClearTexImage;
		std::function<void(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data)>		glClearTexSubImage;
		std::function<void(GLenum target, GLuint first, GLsizei count, const GLuint *buffers)>																											glBindBuffersBase;
		std::function<void(GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes)>														glBindBuffersRange;
		std::function<void(GLuint first, GLsizei count, const GLuint *textures)>																														glBindTextures;
		std::function<void(GLuint first, GLsizei count, const GLuint *samplers)>																														glBindSamplers;
		std::function<void(GLuint first, GLsizei count, const GLuint *textures)>																														glBindImageTextures;
		std::function<void(GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides)>																		glBindVertexBuffers;

#pragma endregion

		void InitializeExtentions(void)
		{
			if (glVersionMajor > 1 || (glVersionMinor >= 2 && glVersionMajor >= 1))
			{
				Load1_2Extensions();
			}

			else
			{
				//return error message
			}

			if (glVersionMajor > 1 || (glVersionMinor >= 3 && glVersionMajor >= 1))
			{
				Load1_3Extensions();
			}

			else
			{

			}

			if (glVersionMajor > 1 || (glVersionMinor >= 4 && glVersionMajor >= 1))
			{
				Load1_4Extensions();
			}

			else
			{

			}

			if (glVersionMajor > 1 || (glVersionMinor >= 5 && glVersionMajor >= 1))
			{
				Load1_5Extensions();
			}

			else
			{

			}

			if (glVersionMajor > 2 || (glVersionMinor >= 0 && glVersionMajor >= 2))
			{
				Load2_0Extensions();
			}

			else
			{

			}

			if (glVersionMajor > 2 || (glVersionMinor >= 1 && glVersionMajor >= 2))
			{
				Load2_1Extensions();
			}

			else
			{

			}

			if (glVersionMajor > 3 || (glVersionMinor >= 0 && glVersionMajor >= 3))
			{
				Load3_0Extensions();
			}

			else
			{

			}

			if (glVersionMajor > 3 || (glVersionMinor >= 1 && glVersionMajor >= 3))
			{
				Load3_1Extensions();
			}

			else
			{

			}

			if (glVersionMajor > 3 || (glVersionMinor >= 2 && glVersionMajor >= 3))
			{
				Load3_2Extensions();
			}

			else
			{

			}

			if (glVersionMajor > 3 || (glVersionMinor >= 3 && glVersionMajor >= 3))
			{
				Load3_3Extensions();
			}

			else
			{

			}

			if (glVersionMajor > 4 || (glVersionMinor >= 0 && glVersionMajor >= 4))
			{
				Load4_0Extensions();
			}

			else
			{

			}

			if (glVersionMajor > 4 || (glVersionMinor >= 1 && glVersionMajor >= 4))
			{
				Load4_1Extensions();
			}

			else
			{

			}

			if (glVersionMajor > 4 || (glVersionMinor >= 2 && glVersionMajor >= 4))
			{
				Load4_2Extensions();
			}

			else
			{

			}

			if (glVersionMajor > 4 || (glVersionMinor >= 3 && glVersionMajor >= 4))
			{
				Load4_3Extensions();
			}

			else
			{

			}

			if (glVersionMajor > 4 || (glVersionMinor >= 4 && glVersionMajor >= 4))
			{
				Load4_4Extensions();
			}

			else
			{

			}
		}

		void InitializeExtensionsSpecific(unsigned int OpenGLVersions)
		{
			if (OpenGLVersions & glVersion_t::version1_2)
			{
				if (glVersionMajor > 1 || (glVersionMinor >= 2 && glVersionMajor >= 1))
				{
					Load1_2Extensions();
				}
			}

			if (OpenGLVersions & glVersion_t::version1_3)
			{
				if (glVersionMajor > 1 || (glVersionMinor >= 3 && glVersionMajor >= 1))
				{
					Load1_3Extensions();
				}
			}

			if (OpenGLVersions & glVersion_t::version1_4)
			{
				if (glVersionMajor > 1 || (glVersionMinor >= 4 && glVersionMajor >= 1))
				{
					Load1_4Extensions();
				}
			}

			if (OpenGLVersions & glVersion_t::version1_5)
			{
				if (glVersionMajor > 1 || (glVersionMinor >= 5 && glVersionMajor >= 1))
				{
					Load1_5Extensions();
				}
			}

			if (OpenGLVersions & glVersion_t::version2_0)
			{
				if (glVersionMajor > 2 || (glVersionMinor >= 0 && glVersionMajor >= 2))
				{
					Load2_0Extensions();
				}
			}

			if (OpenGLVersions & glVersion_t::version2_1)
			{
				if (glVersionMajor > 2 || (glVersionMinor >= 1 && glVersionMajor >= 2))
				{
					Load2_1Extensions();
				}
			}

			if (OpenGLVersions & glVersion_t::version3_0)
			{
				if (glVersionMajor > 3 || (glVersionMinor >= 0 && glVersionMajor >= 3))
				{
					Load3_0Extensions();
				}
			}

			if (OpenGLVersions & glVersion_t::version3_1)
			{
				if (glVersionMajor > 3 || (glVersionMinor >= 1 && glVersionMajor >= 3))
				{
					Load3_1Extensions();
				}
			}

			if (OpenGLVersions & glVersion_t::version3_2)
			{
				if (glVersionMajor > 3 || (glVersionMinor >= 2 && glVersionMajor >= 3))
				{
					Load3_2Extensions();
				}
			}

			if (OpenGLVersions & glVersion_t::version3_3)
			{
				if (glVersionMajor > 3 || (glVersionMinor >= 3 && glVersionMajor >= 3))
				{
					Load3_3Extensions();
				}
			}

			if (OpenGLVersions & glVersion_t::version4_0)
			{
				if (glVersionMajor > 4 || (glVersionMinor >= 0 && glVersionMajor >= 4))
				{
					Load4_0Extensions();
				}
			}

			if (OpenGLVersions & glVersion_t::version4_1)
			{
				if (glVersionMajor > 4 || (glVersionMinor >= 1 && glVersionMajor >= 4))
				{
					Load4_1Extensions();
				}
			}

			if (OpenGLVersions & glVersion_t::version4_2)
			{
				if (glVersionMajor > 4 || (glVersionMinor >= 2 && glVersionMajor >= 4))
				{
					Load4_2Extensions();
				}
			}

			if (OpenGLVersions & glVersion_t::version4_3)
			{
				if (glVersionMajor > 4 || (glVersionMinor >= 3 && glVersionMajor >= 4))
				{
					Load4_3Extensions();
				}
			}

			if (OpenGLVersions & glVersion_t::version4_4)
			{
				if (glVersionMajor > 4 || (glVersionMinor >= 4 && glVersionMajor >= 4))
				{
					Load4_4Extensions();
				}
			}
		}

	private:

		void InitializeGLVersion(void)
		{
			const GLubyte* versionString = glGetString(GL_VERSION);

			glVersionMajor = versionString[0] - '0';
			glVersionMinor = versionString[2] - '0';
		}

		void* GetProcAddress(const char* procName)
		{
			printf("blarg \n");
#if defined(_WIN32) || defined(_WIN64)
			return wglGetProcAddress((LPCSTR)procName);
#elif defined(__linux__)
			return glXGetProcAddress(procName);
#endif
		}

		bool IsExtensionSupported(const char* extensionName)
		{
			GLubyte* end;//the last extension name in Extensions
			GLint	nameLength; //the string length of the extension name

			nameLength = strlen((const char*)extensionName);

			GLubyte* allExtensions = (GLubyte*)glGetString(GL_EXTENSIONS); //get all supported extensions

			if (allExtensions != NULL)
			{
				end = allExtensions + strlen((const char*)allExtensions);

				while (allExtensions < end)
				{
					GLint str = strcspn((const char*)allExtensions, " ");

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

		void Load1_2Extensions(void)
		{
			glDrawRangeElements = (DrawRangeElements_t)GetProcAddress("glDrawRangeElements");
			glTexImage3D = (TexImage3D_t)GetProcAddress("glTexImage3D");
			glTexSubImage3D = (TexSubImage3D_t)GetProcAddress("glTexSubImage3D");
			glCopyTexSubImage3D = (CopyTexSubImage3D_t)GetProcAddress("glCopyTexSubImage3D");
			return;
		}

		void Load1_3Extensions(void)
		{
			glActiveTexture = (ActiveTexture_t)GetProcAddress("glActiveTexture");
			glSampleCoverage = (SampleCoverage_t)GetProcAddress("glSampleCoverage");
			glCompressedTexImage3D = (CompressedTexImage3D_t)GetProcAddress("glCompressedTexImage3D");
			glCompressedTexImage2D = (CompressedTexImage2D_t)GetProcAddress("glCompressedTexImage2D");
			glCompressedTexImage1D = (CompressedTexImage1D_t)GetProcAddress("glCompressedTexImage1D");
			glCompressedTexSubImage3D = (CompressedTexSubImage3D_t)GetProcAddress("glCompressedTexSubImage3D");
			glCompressedTexSubImage2D = (CompressedTexSubImage2D_t)GetProcAddress("glCompressedTexSubImage2D");
			glCompressedTexSubImage1D = (CompressedTexSubImage1D_t)GetProcAddress("glCompressedTexSubImage1D");
			glGetCompressedTexImage = (GetCompressedTexImage_t)GetProcAddress("glGetCompressedTexImage");
			glClientActiveTexture = (ClientActiveTexture_t)GetProcAddress("glClientActiveTexture");
			glMultiTexCoord1d = (MultiTexCoord1d_t)GetProcAddress("glMultiTexCoord1d");
			glMultiTexCoord1dv = (MultiTexCoord1dv_t)GetProcAddress("glMultiTexCoord1dv");
			glMultiTexCoord1f = (MultiTexCoord1f_t)GetProcAddress("glMultiTexCoord1f");
			glMultiTexCoord1fv = (MultiTexCoord1fv_t)GetProcAddress("glMultiTexCoord1fv");
			glMultiTexCoord1i = (MultiTexCoord1i_t)GetProcAddress("glMultiTexCoord1i");
			glMultiTexCoord1iv = (MultiTexCoord1iv_t)GetProcAddress("glMultiTexCoord1iv");
			glMultiTexCoord1s = (MultiTexCoord1s_t)GetProcAddress("glMultiTexCoord1s");
			glMultiTexCoord1sv = (MultiTexCoord1sv_t)GetProcAddress("glMultiTexCoord1sv");
			glMultiTexCoord2d = (MultiTexCoord2d_t)GetProcAddress("glMultiTexCoord2d");
			glMultiTexCoord2dv = (MultiTexCoord2dv_t)GetProcAddress("glMultiTexCoord2dv");
			glMultiTexCoord2f = (MultiTexCoord2f_t)GetProcAddress("glMultiTexCoord2f");
			glMultiTexCoord2fv = (MultiTexCoord2fv_t)GetProcAddress("glMultiTexCoord2fv");
			glMultiTexCoord2i = (MultiTexCoord2i_t)GetProcAddress("glMultiTexCoord2i");
			glMultiTexCoord2iv = (MultiTexCoord2iv_t)GetProcAddress("glMultiTexCoord2iv");
			glMultiTexCoord2s = (MultiTexCoord2s_t)GetProcAddress("glMultiTexCoord2s");
			glMultiTexCoord2sv = (MultiTexCoord2sv_t)GetProcAddress("glMultiTexCoord2sv");
			glMultiTexCoord3d = (MultiTexCoord3d_t)GetProcAddress("glMultiTexCoord3d");
			glMultiTexCoord3dv = (MultiTexCoord3dv_t)GetProcAddress("glMultiTexCoord3dv");
			glMultiTexCoord3f = (MultiTexCoord3f_t)GetProcAddress("glMultiTexCoord3f");
			glMultiTexCoord3fv = (MultiTexCoord3fv_t)GetProcAddress("glMultiTexCoord3fv");
			glMultiTexCoord3i = (MultiTexCoord3i_t)GetProcAddress("glMultiTexCoord3i");
			glMultiTexCoord3iv = (MultiTexCoord3iv_t)GetProcAddress("glMultiTexCoord3iv");
			glMultiTexCoord3s = (MultiTexCoord3s_t)GetProcAddress("glMultiTexCoord3s");
			glMultiTexCoord3sv = (MultiTexCoord3sv_t)GetProcAddress("glMultiTexCoord3sv");
			glMultiTexCoord4d = (MultiTexCoord4d_t)GetProcAddress("glMultiTexCoord4d");
			glMultiTexCoord4dv = (MultiTexCoord4dv_t)GetProcAddress("glMultiTexCoord4dv");
			glMultiTexCoord4f = (MultiTexCoord4f_t)GetProcAddress("glMultiTexCoord4f");
			glMultiTexCoord4fv = (MultiTexCoord4fv_t)GetProcAddress("glMultiTexCoord4fv");
			glMultiTexCoord4i = (MultiTexCoord4i_t)GetProcAddress("glMultiTexCoord4i");
			glMultiTexCoord4iv = (MultiTexCoord4iv_t)GetProcAddress("glMultiTexCoord4iv");
			glMultiTexCoord4s = (MultiTexCoord4s_t)GetProcAddress("glMultiTexCoord4s");
			glMultiTexCoord4sv = (MultiTexCoord4sv_t)GetProcAddress("glMultiTexCoord4sv");
			glLoadTransposeMatrixf = (LoadTransposeMatrixf_t)GetProcAddress("glLoadTransposeMatrixf");
			glLoadTransposeMatrixd = (LoadTransposeMatrixd_t)GetProcAddress("glLoadTransposeMatrixd");
			glMultTransposeMatrixf = (MultTransposeMatrixf_t)GetProcAddress("glMultTransposeMatrixf");
			glMultTransposeMatrixd = (MultTransposeMatrixd_t)GetProcAddress("glMultTransposeMatrixd");
			return;
		}

		void Load1_4Extensions(void)
		{
			glBlendFuncSeparate = (BlendFuncSeparate_t)GetProcAddress("glBlendFuncSeparate");
			glMultiDrawArrays = (MultiDrawArrays_t)GetProcAddress("glMultiDrawArrays");
			glMultiDrawElements = (MultiDrawElements_t)GetProcAddress("glMultiDrawElements");
			glPointParameterf = (PointParameterf_t)GetProcAddress("glPointParameterf");
			glPointParameterfv = (PointParameterfv_t)GetProcAddress("glPointParameterfv");
			glPointParameteri = (PointParameteri_t)GetProcAddress("glPointParameteri");
			glPointParameteriv = (PointParameteriv_t)GetProcAddress("glPointParameteriv");
			glFogCoordf = (FogCoordf_t)GetProcAddress("glFogCoordf");
			glFogCoordfv = (FogCoordfv_t)GetProcAddress("glFogCoordfv");
			glFogCoordd = (FogCoordd_t)GetProcAddress("glFogCoordd");
			glFogCoorddv = (FogCoorddv_t)GetProcAddress("glFogCoorddv");
			glFogCoordPointer = (FogCoordPointer_t)GetProcAddress("glFogCoordPointer");
			glSecondaryColor3b = (SecondaryColor3b_t)GetProcAddress("glSecondaryColor3b");
			glSecondaryColor3bv = (SecondaryColor3bv_t)GetProcAddress("glSecondaryColor3bv");
			glSecondaryColor3d = (SecondaryColor3d_t)GetProcAddress("glSecondaryColor3d");
			glSecondaryColor3dv = (SecondaryColor3dv_t)GetProcAddress("glSecondaryColor3dv");
			glSecondaryColor3f = (SecondaryColor3f_t)GetProcAddress("glSecondaryColor3f");
			glSecondaryColor3fv = (SecondaryColor3fv_t)GetProcAddress("glSecondaryColor3fv");
			glSecondaryColor3i = (SecondaryColor3i_t)GetProcAddress("glSecondaryColor3i");
			glSecondaryColor3iv = (SecondaryColor3iv_t)GetProcAddress("glSecondaryColor3iv");
			glSecondaryColor3s = (SecondaryColor3s_t)GetProcAddress("glSecondaryColor3s");
			glSecondaryColor3sv = (SecondaryColor3sv_t)GetProcAddress("glSecondaryColor3sv");
			glSecondaryColor3ub = (SecondaryColor3ub_t)GetProcAddress("glSecondaryColor3ub");
			glSecondaryColor3ubv = (SecondaryColor3ubv_t)GetProcAddress("glSecondaryColor3ubv");
			glSecondaryColor3ui = (SecondaryColor3ui_t)GetProcAddress("glSecondaryColor3ui");
			glSecondaryColor3uiv = (SecondaryColor3uiv_t)GetProcAddress("glSecondaryColor3uiv");
			glSecondaryColor3us = (SecondaryColor3us_t)GetProcAddress("glSecondaryColor3us");
			glSecondaryColor3usv = (SecondaryColor3usv_t)GetProcAddress("glSecondaryColor3usv");
			glSecondaryColorPointer = (SecondaryColorPointer_t)GetProcAddress("glSecondaryColorPointer");
			glWindowPos2d = (WindowPos2d_t)GetProcAddress("glWindowPos2d");
			glWindowPos2dv = (WindowPos2dv_t)GetProcAddress("glWindowPos2dv");
			glWindowPos2f = (WindowPos2f_t)GetProcAddress("glWindowPos2f");
			glWindowPos2fv = (WindowPos2fv_t)GetProcAddress("glWindowPos2fv");
			glWindowPos2i = (WindowPos2i_t)GetProcAddress("glWindowPos2i");
			glWindowPos2iv = (WindowPos2iv_t)GetProcAddress("glWindowPos2iv");
			glWindowPos2s = (WindowPos2s_t)GetProcAddress("glWindowPos2s");
			glWindowPos2sv = (WindowPos2sv_t)GetProcAddress("glWindowPos2sv");
			glWindowPos3d = (WindowPos3d_t)GetProcAddress("glWindowPos3d");
			glWindowPos3dv = (WindowPos3dv_t)GetProcAddress("glWindowPos3dv");
			glWindowPos3f = (WindowPos3f_t)GetProcAddress("glWindowPos3f");
			glWindowPos3fv = (WindowPos3fv_t)GetProcAddress("glWindowPos3fv");
			glWindowPos3i = (WindowPos3i_t)GetProcAddress("glWindowPos3i");
			glWindowPos3iv = (WindowPos3iv_t)GetProcAddress("glWindowPos3iv");
			glWindowPos3s = (WindowPos3s_t)GetProcAddress("glWindowPos3s");
			glWindowPos3sv = (WindowPos3sv_t)GetProcAddress("glWindowPos3sv");
			glBlendColor = (BlendColor_t)GetProcAddress("glBlendColor");
			glBlendEquation = (BlendEquation_t)GetProcAddress("glBlendEquation");
			return;
		}

		void Load1_5Extensions(void)
		{
			glGenQueries =					(GenQueries_t)GetProcAddress("glGenQueries");
			glDeleteQueries =				(DeleteQueries_t)GetProcAddress("glDeleteQueries");
			glIsQuery =						(IsQuery_t)GetProcAddress("glIsQuery");
			glBeginQuery =					(BeginQuery_t)GetProcAddress("glBeginQuery");
			glEndQuery =					(EndQuery_t)GetProcAddress("glEndQuery");
			glGetQueryiv =					(GetQueryiv_t)GetProcAddress("glGetQueryiv");
			glGetQueryObjectiv =			(GetQueryObjectiv_t)GetProcAddress("glGetQueryObjectiv");
			glGetQueryObjectuiv =			(GetQueryObjectuiv_t)GetProcAddress("glGetQueryObjectuiv");
			glBindBuffer =					(BindBuffer_t)GetProcAddress("glBindBuffer");
			glDeleteBuffers =				(DeleteBuffers_t)GetProcAddress("glDeleteBuffers");
			glGenBuffers =					(GenBuffers_t)GetProcAddress("glGenBuffers");
			glIsBuffer =					(IsBuffer_t)GetProcAddress("glIsBuffer");
			glBufferData =					(BufferData_t)GetProcAddress("glBufferData");
			glBufferSubData =				(BufferSubData_t)GetProcAddress("glBufferSubData");
			glGetBufferSubData =			(GetBufferSubData_t)GetProcAddress("glGetBufferSubData");
			glMapBuffer =					(MapBuffer_t)GetProcAddress("glMapBuffer");
			glUnmapBuffer =					(UnmapBuffer_t)GetProcAddress("glUnmapBuffer");
			glGetBufferParameteriv =		(GetBufferParameteriv_t)GetProcAddress("glGetBufferParameteriv");
			glGetBufferPointerv =			(GetBufferPointerv_t)GetProcAddress("glGetBufferPointerv");
			return;
		}

		void Load2_0Extensions(void)
		{
			glBlendEquationSeparate = (BlendEquationSeparate_t)GetProcAddress("glBlendEquationSeparate");
			glDrawBuffers = (DrawBuffers_t)GetProcAddress("glDrawBuffers");
			glStencilOpSeparate = (StencilOpSeparate_t)GetProcAddress("glStencilOpSeparate");
			glStencilFuncSeparate = (StencilFuncSeparate_t)GetProcAddress("glStencilFuncSeparate");
			glStencilMaskSeparate = (StencilMaskSeparate_t)GetProcAddress("glStencilMaskSeparate");
			glAttachShader = (AttachShader_t)GetProcAddress("glAttachShader");
			glBindAttribLocation = (BindAttribLocation_t)GetProcAddress("glBindAttribLocation");
			glCompileShader = (CompileShader_t)GetProcAddress("glCompileShader");
			glCreateProgram = (CreateProgram_t)GetProcAddress("glCreateProgram");
			glCreateShader = (CreateShader_t)GetProcAddress("glCreateShader");
			glDeleteProgram = (DeleteProgram_t)GetProcAddress("glDeleteProgram");
			glDeleteShader = (DeleteShader_t)GetProcAddress("glDeleteShader");
			glDetachShader = (DetachShader_t)GetProcAddress("glDetachShader");
			glDisableVertexAttribArray = (DisableVertexAttribArray_t)GetProcAddress("glDisableVertexAttribArray");
			glEnableVertexAttribArray = (EnableVertexAttribArray_t)GetProcAddress("glEnableVertexAttribArray");
			glGetActiveAttrib = (GetActiveAttrib_t)GetProcAddress("glGetActiveAttrib");
			glGetActiveUniform = (GetActiveUniform_t)GetProcAddress("glGetActiveUniform");
			glGetAttachedShaders = (GetAttachedShaders_t)GetProcAddress("glGetAttachedShaders");
			glGetAttribLocation = (GetAttribLocation_t)GetProcAddress("glGetAttribLocation");
			glGetProgramiv = (GetProgramiv_t)GetProcAddress("glGetProgramiv");
			glGetProgramInfoLog = (GetProgramInfoLog_t)GetProcAddress("glGetProgramInfoLog");
			glGetShaderiv = (GetShaderiv_t)GetProcAddress("glGetShaderiv");
			glGetShaderInfoLog = (GetShaderInfoLog_t)GetProcAddress("glGetShaderInfoLog");
			glGetShaderSource = (GetShaderSource_t)GetProcAddress("glGetShaderSource");
			glGetUniformLocation = (GetUniformLocation_t)GetProcAddress("glGetUniformLocation");
			glGetUniformfv = (GetUniformfv_t)GetProcAddress("glGetUniformfv");
			glGetUniformiv = (GetUniformiv_t)GetProcAddress("glGetUniformiv");
			glGetVertexAttribdv = (GetVertexAttribdv_t)GetProcAddress("glGetVertexAttribdv");
			glGetVertexAttribfv = (GetVertexAttribfv_t)GetProcAddress("glGetVertexAttribfv");
			glGetVertexAttribiv = (GetVertexAttribiv_t)GetProcAddress("glGetVertexAttribiv");
			glGetVertexAttribPointerv = (GetVertexAttribPointerv_t)GetProcAddress("glGetVertexAttribPointerv");
			glIsProgram = (IsProgram_t)GetProcAddress("glIsProgram");
			glIsShader = (IsShader_t)GetProcAddress("glIsShader");
			glLinkProgram = (LinkProgram_t)GetProcAddress("glLinkProgram");
			glShaderSource = (ShaderSource_t)GetProcAddress("glShaderSource");
			glUseProgram = (UseProgram_t)GetProcAddress("glUseProgram");
			glUniform1f = (Uniform1f_t)GetProcAddress("glUniform1f");
			glUniform2f = (Uniform2f_t)GetProcAddress("glUniform2f");
			glUniform3f = (Uniform3f_t)GetProcAddress("glUniform3f");
			glUniform4f = (Uniform4f_t)GetProcAddress("glUniform4f");
			glUniform1i = (Uniform1i_t)GetProcAddress("glUniform1i");
			glUniform2i = (Uniform2i_t)GetProcAddress("glUniform2i");
			glUniform3i = (Uniform3i_t)GetProcAddress("glUniform3i");
			glUniform4i = (Uniform4i_t)GetProcAddress("glUniform4i");
			glUniform1fv = (Uniform1fv_t)GetProcAddress("glUniform1fv");
			glUniform2fv = (Uniform2fv_t)GetProcAddress("glUniform2fv");
			glUniform3fv = (Uniform3fv_t)GetProcAddress("glUniform3fv");
			glUniform4fv = (Uniform4fv_t)GetProcAddress("glUniform4fv");
			glUniform1iv = (Uniform1iv_t)GetProcAddress("glUniform1iv");
			glUniform2iv = (Uniform2iv_t)GetProcAddress("glUniform2iv");
			glUniform3iv = (Uniform3iv_t)GetProcAddress("glUniform3iv");
			glUniform4iv = (Uniform4iv_t)GetProcAddress("glUniform4iv");
			glUniformMatrix2fv = (UniformMatrix2fv_t)GetProcAddress("glUniformMatrix2fv");
			glUniformMatrix3fv = (UniformMatrix3fv_t)GetProcAddress("glUniformMatrix3fv");
			glUniformMatrix4fv = (UniformMatrix4fv_t)GetProcAddress("glUniformMatrix4fv");
			glValidateProgram = (ValidateProgram_t)GetProcAddress("glValidateProgram");
			glVertexAttrib1d = (VertexAttrib1d_t)GetProcAddress("glVertexAttrib1d");
			glVertexAttrib1dv = (VertexAttrib1dv_t)GetProcAddress("glVertexAttrib1dv");
			glVertexAttrib1f = (VertexAttrib1f_t)GetProcAddress("glVertexAttrib1f");
			glVertexAttrib1fv = (VertexAttrib1fv_t)GetProcAddress("glVertexAttrib1fv");
			glVertexAttrib1s = (VertexAttrib1s_t)GetProcAddress("glVertexAttrib1s");
			glVertexAttrib1sv = (VertexAttrib1sv_t)GetProcAddress("glVertexAttrib1sv");
			glVertexAttrib2d = (VertexAttrib2d_t)GetProcAddress("glVertexAttrib2d");
			glVertexAttrib2dv = (VertexAttrib2dv_t)GetProcAddress("glVertexAttrib2dv");
			glVertexAttrib2f = (VertexAttrib2f_t)GetProcAddress("glVertexAttrib2f");
			glVertexAttrib2fv = (VertexAttrib2fv_t)GetProcAddress("glVertexAttrib2fv");
			glVertexAttrib2s = (VertexAttrib2s_t)GetProcAddress("glVertexAttrib2s");
			glVertexAttrib2sv = (VertexAttrib2sv_t)GetProcAddress("glVertexAttrib2sv");
			glVertexAttrib3d = (VertexAttrib3d_t)GetProcAddress("glVertexAttrib3d");
			glVertexAttrib3dv = (VertexAttrib3dv_t)GetProcAddress("glVertexAttrib3dv");
			glVertexAttrib3f = (VertexAttrib3f_t)GetProcAddress("glVertexAttrib3f");
			glVertexAttrib3fv = (VertexAttrib3fv_t)GetProcAddress("glVertexAttrib3fv");
			glVertexAttrib3s = (VertexAttrib3s_t)GetProcAddress("glVertexAttrib3s");
			glVertexAttrib3sv = (VertexAttrib3sv_t)GetProcAddress("glVertexAttrib3sv");
			glVertexAttrib4Nbv = (VertexAttrib4Nbv_t)GetProcAddress("glVertexAttrib4Nbv");
			glVertexAttrib4Niv = (VertexAttrib4Niv_t)GetProcAddress("glVertexAttrib4Niv");
			glVertexAttrib4Nsv = (VertexAttrib4Nsv_t)GetProcAddress("glVertexAttrib4Nsv");
			glVertexAttrib4Nub = (VertexAttrib4Nub_t)GetProcAddress("glVertexAttrib4Nub");
			glVertexAttrib4Nubv = (VertexAttrib4Nubv_t)GetProcAddress("glVertexAttrib4Nubv");
			glVertexAttrib4Nuiv = (VertexAttrib4Nuiv_t)GetProcAddress("glVertexAttrib4Nuiv");
			glVertexAttrib4Nusv = (VertexAttrib4Nusv_t)GetProcAddress("glVertexAttrib4Nusv");
			glVertexAttrib4bv = (VertexAttrib4bv_t)GetProcAddress("glVertexAttrib4bv");
			glVertexAttrib4d = (VertexAttrib4d_t)GetProcAddress("glVertexAttrib4d");
			glVertexAttrib4dv = (VertexAttrib4dv_t)GetProcAddress("glVertexAttrib4dv");
			glVertexAttrib4f = (VertexAttrib4f_t)GetProcAddress("glVertexAttrib4f");
			glVertexAttrib4fv = (VertexAttrib4fv_t)GetProcAddress("glVertexAttrib4fv");
			glVertexAttrib4iv = (VertexAttrib4iv_t)GetProcAddress("glVertexAttrib4iv");
			glVertexAttrib4s = (VertexAttrib4s_t)GetProcAddress("glVertexAttrib4s");
			glVertexAttrib4sv = (VertexAttrib4sv_t)GetProcAddress("glVertexAttrib4sv");
			glVertexAttrib4ubv = (VertexAttrib4ubv_t)GetProcAddress("glVertexAttrib4ubv");
			glVertexAttrib4uiv = (VertexAttrib4uiv_t)GetProcAddress("glVertexAttrib4uiv");
			glVertexAttrib4usv = (VertexAttrib4usv_t)GetProcAddress("glVertexAttrib4usv");
			glVertexAttribPointer = (VertexAttribPointer_t)GetProcAddress("glVertexAttribPointer");
			return;
		}

		void Load2_1Extensions(void)
		{
			glUniformMatrix2x3fv = (UniformMatrix2x3fv_t)GetProcAddress("glUniformMatrix2x3fv");
			glUniformMatrix3x2fv = (UniformMatrix3x2fv_t)GetProcAddress("glUniformMatrix3x2fv");
			glUniformMatrix2x4fv = (UniformMatrix2x4fv_t)GetProcAddress("glUniformMatrix2x4fv");
			glUniformMatrix4x2fv = (UniformMatrix4x2fv_t)GetProcAddress("glUniformMatrix4x2fv");
			glUniformMatrix3x4fv = (UniformMatrix3x4fv_t)GetProcAddress("glUniformMatrix3x4fv");
			glUniformMatrix4x3fv = (UniformMatrix4x3fv_t)GetProcAddress("glUniformMatrix4x3fv");
			return;
		}

		void Load3_0Extensions(void)
		{
			glColorMaski = (ColorMaski_t)GetProcAddress("glColorMaski");
			glGetBooleani_v = (GetBooleani_v_t)GetProcAddress("glGetBooleani_v");
			glGetIntegeri_v = (GetIntegeri_v_t)GetProcAddress("glGetIntegeri_v");
			glEnablei = (Enablei_t)GetProcAddress("glEnablei");
			glDisablei = (Disablei_t)GetProcAddress("glDisablei");
			glIsEnabledi = (IsEnabledi_t)GetProcAddress("glIsEnabledi");
			glBeginTransformFeedback = (BeginTransformFeedback_t)GetProcAddress("glBeginTransformFeedback");
			glEndTransformFeedback = (EndTransformFeedback_t)GetProcAddress("glEndTransformFeedback");
			glBindBufferRange = (BindBufferRange_t)GetProcAddress("glBindBufferRange");
			glBindBufferBase = (BindBufferBase_t)GetProcAddress("glBindBufferBase");
			glTransformFeedbackVaryings = (TransformFeedbackVaryings_t)GetProcAddress("glTransformFeedbackVaryings");
			glGetTransformFeedbackVarying = (GetTransformFeedbackVarying_t)GetProcAddress("glGetTransformFeedbackVarying");
			glClampColor = (ClampColor_t)GetProcAddress("glClampColor");
			glBeginConditionalRender = (BeginConditionalRender_t)GetProcAddress("glBeginConditionalRender");
			glEndConditionalRender = (EndConditionalRender_t)GetProcAddress("glEndConditionalRender");
			glVertexAttribIPointer = (VertexAttribIPointer_t)GetProcAddress("glVertexAttribIPointer");
			glGetVertexAttribIiv = (GetVertexAttribIiv_t)GetProcAddress("glGetVertexAttribIiv");
			glGetVertexAttribIuiv = (GetVertexAttribIuiv_t)GetProcAddress("glGetVertexAttribIuiv");
			glVertexAttribI1i = (VertexAttribI1i_t)GetProcAddress("glVertexAttribI1i");
			glVertexAttribI2i = (VertexAttribI2i_t)GetProcAddress("glVertexAttribI2i");
			glVertexAttribI3i = (VertexAttribI3i_t)GetProcAddress("glVertexAttribI3i");
			glVertexAttribI4i = (VertexAttribI4i_t)GetProcAddress("glVertexAttribI4i");
			glVertexAttribI1ui = (VertexAttribI1ui_t)GetProcAddress("glVertexAttribI1ui");
			glVertexAttribI2ui = (VertexAttribI2ui_t)GetProcAddress("glVertexAttribI2ui");
			glVertexAttribI3ui = (VertexAttribI3ui_t)GetProcAddress("glVertexAttribI3ui");
			glVertexAttribI4ui = (VertexAttribI4ui_t)GetProcAddress("glVertexAttribI4ui");
			glVertexAttribI1iv = (VertexAttribI1iv_t)GetProcAddress("glVertexAttribI1iv");
			glVertexAttribI2iv = (VertexAttribI2iv_t)GetProcAddress("glVertexAttribI2iv");
			glVertexAttribI3iv = (VertexAttribI3iv_t)GetProcAddress("glVertexAttribI3iv");
			glVertexAttribI4iv = (VertexAttribI4iv_t)GetProcAddress("glVertexAttribI4iv");
			glVertexAttribI1uiv = (VertexAttribI1uiv_t)GetProcAddress("glVertexAttribI1uiv");
			glVertexAttribI2uiv = (VertexAttribI2uiv_t)GetProcAddress("glVertexAttribI2uiv");
			glVertexAttribI3uiv = (VertexAttribI3uiv_t)GetProcAddress("glVertexAttribI3uiv");
			glVertexAttribI4uiv = (VertexAttribI4uiv_t)GetProcAddress("glVertexAttribI4uiv");
			glVertexAttribI4bv = (VertexAttribI4bv_t)GetProcAddress("glVertexAttribI4bv");
			glVertexAttribI4sv = (VertexAttribI4sv_t)GetProcAddress("glVertexAttribI4sv");
			glVertexAttribI4ubv = (VertexAttribI4ubv_t)GetProcAddress("glVertexAttribI4ubv");
			glVertexAttribI4usv = (VertexAttribI4usv_t)GetProcAddress("glVertexAttribI4usv");
			glGetUniformuiv = (GetUniformuiv_t)GetProcAddress("glGetUniformuiv");
			glBindFragDataLocation = (BindFragDataLocation_t)GetProcAddress("glBindFragDataLocation");
			glGetFragDataLocation = (GetFragDataLocation_t)GetProcAddress("glGetFragDataLocation");
			glUniform1ui = (Uniform1ui_t)GetProcAddress("glUniform1ui");
			glUniform2ui = (Uniform2ui_t)GetProcAddress("glUniform2ui");
			glUniform3ui = (Uniform3ui_t)GetProcAddress("glUniform3ui");
			glUniform4ui = (Uniform4ui_t)GetProcAddress("glUniform4ui");
			glUniform1uiv = (Uniform1uiv_t)GetProcAddress("glUniform1uiv");
			glUniform2uiv = (Uniform2uiv_t)GetProcAddress("glUniform2uiv");
			glUniform3uiv = (Uniform3uiv_t)GetProcAddress("glUniform3uiv");
			glUniform4uiv = (Uniform4uiv_t)GetProcAddress("glUniform4uiv");
			glTexParameterIiv = (TexParameterIiv_t)GetProcAddress("glTexParameterIiv");
			glTexParameterIuiv = (TexParameterIuiv_t)GetProcAddress("glTexParameterIuiv");
			glGetTexParameterIiv = (GetTexParameterIiv_t)GetProcAddress("glGetTexParameterIiv");
			glGetTexParameterIuiv = (GetTexParameterIuiv_t)GetProcAddress("glGetTexParameterIuiv");
			glClearBufferiv = (ClearBufferiv_t)GetProcAddress("glClearBufferiv");
			glClearBufferuiv = (ClearBufferuiv_t)GetProcAddress("glClearBufferuiv");
			glClearBufferfv = (ClearBufferfv_t)GetProcAddress("glClearBufferfv");
			glClearBufferfi = (ClearBufferfi_t)GetProcAddress("glClearBufferfi");
			glGetStringi = (GetStringi_t)GetProcAddress("glGetStringi");
			glIsRenderbuffer = (IsRenderbuffer_t)GetProcAddress("glIsRenderbuffer");
			glBindRenderbuffer = (BindRenderbuffer_t)GetProcAddress("glBindRenderbuffer");
			glDeleteRenderbuffers = (DeleteRenderbuffers_t)GetProcAddress("glDeleteRenderbuffers");
			glGenRenderbuffers = (GenRenderbuffers_t)GetProcAddress("glGenRenderbuffers");
			glRenderbufferStorage = (RenderbufferStorage_t)GetProcAddress("glRenderbufferStorage");
			glGetRenderbufferParameteriv = (GetRenderbufferParameteriv_t)GetProcAddress("glGetRenderbufferParameteriv");
			glIsFramebuffer = (IsFramebuffer_t)GetProcAddress("glIsFramebuffer");
			glBindFramebuffer = (BindFramebuffer_t)GetProcAddress("glBindFramebuffer");
			glDeleteFramebuffers = (DeleteFramebuffers_t)GetProcAddress("glDeleteFramebuffers");
			glGenFramebuffers = (GenFramebuffers_t)GetProcAddress("glGenFramebuffers");
			glCheckFrameBufferStatus = (CheckFramebufferStatus_t)GetProcAddress("glCheckFramebufferStatus");
			glFramebufferTexture1D = (FramebufferTexture1D_t)GetProcAddress("glFramebufferTexture1D");
			glFramebufferTexture2D = (FramebufferTexture2D_t)GetProcAddress("glFramebufferTexture2D");
			glFramebufferTexture3D = (FramebufferTexture3D_t)GetProcAddress("glFramebufferTexture3D");
			glFramebufferRenderbuffer = (FramebufferRenderbuffer_t)GetProcAddress("glFramebufferRenderbuffer");
			glGetFramebufferAttachmentParameteriv = (GetFramebufferAttachmentParameteriv_t)GetProcAddress("glGetFramebufferAttachmentParameteriv");
			glGenerateMipmap = (GenerateMipmap_t)GetProcAddress("glGenerateMipmap");
			glBlitFramebuffer = (BlitFramebuffer_t)GetProcAddress("glBlitFramebuffer");
			glRenderbufferStorageMultisample = (RenderbufferStorageMultisample_t)GetProcAddress("glRenderbufferStorageMultisample");
			glFramebufferTextureLayer = (FramebufferTextureLayer_t)GetProcAddress("glFramebufferTextureLayer");
			glMapBufferRange = (MapBufferRange_t)GetProcAddress("glMapBufferRange");
			glFlushMappedBufferRange = (FlushMappedBufferRange_t)GetProcAddress("glFlushMappedBufferRange");
			glBindVertexArray = (BindVertexArray_t)GetProcAddress("glBindVertexArray");
			glDeleteVertexArrays = (DeleteVertexArrays_t)GetProcAddress("glDeleteVertexArrays");
			glGenVertexArrays = (GenVertexArrays_t)GetProcAddress("glGenVertexArrays");
			glIsVertexArray = (IsVertexArray_t)GetProcAddress("glIsVertexArray");
			return;
		}

		void Load3_1Extensions(void)
		{
			glDrawArraysInstanced = (DrawArraysInstanced_t)GetProcAddress("glDrawArraysInstanced");
			glDrawElementsInstanced = (DrawElementsInstanced_t)GetProcAddress("glDrawElementsInstanced");
			glTexBuffer = (TexBuffer_t)GetProcAddress("glTexBuffer");
			glPrimitiveRestartIndex = (PrimitiveRestartIndex_t)GetProcAddress("glPrimitiveRestartIndex");
			glCopyBufferSubData = (CopyBufferSubData_t)GetProcAddress("glCopyBufferSubData");
			glGetUniformIndices = (GetUniformIndices_t)GetProcAddress("glGetUniformIndices");
			glGetActiveUniformsiv = (GetActiveUniformsiv_t)GetProcAddress("glGetActiveUniformsiv");
			glGetActiveUniformName = (GetActiveUniformName_t)GetProcAddress("glGetActiveUniformName");
			glGetUniformBlockIndex = (GetUniformBlockIndex_t)GetProcAddress("glGetUniformBlockIndex");
			glGetActiveUniformBlockiv = (GetActiveUniformBlockiv_t)GetProcAddress("glGetActiveUniformBlockiv");
			glGetActiveUniformBlockName = (GetActiveUniformBlockName_t)GetProcAddress("glGetActiveUniformBlockName");
			glUniformBlockBinding = (UniformBlockBinding_t)GetProcAddress("glUniformBlockBinding");
			return;
		}

		void Load3_2Extensions(void)
		{
			glDrawElementsBaseVertex = (DrawElementsBaseVertex_t)GetProcAddress("glDrawElementsBaseVertex");
			glDrawRangeElementsBaseVertex = (DrawRangeElementsBaseVertex_t)GetProcAddress("glDrawRangeElementsBaseVertex");
			glDrawElementsInstancedBaseVertex = (DrawElementsInstancedBaseVertex_t)GetProcAddress("glDrawElementsInstancedBaseVertex");
			glMultiDrawElementsBaseVertex = (MultiDrawElementsBaseVertex_t)GetProcAddress("glMultiDrawElementsBaseVertex");
			glProvokingVertex = (ProvokingVertex_t)GetProcAddress("glProvokingVertex");
			glFenceSync = (FenceSync_t)GetProcAddress("glFenceSync");
			glIsSync = (IsSync_t)GetProcAddress("glIsSync");
			glDeleteSync = (DeleteSync_t)GetProcAddress("glDeleteSync");
			glClientWaitSync = (ClientWaitSync_t)GetProcAddress("glClientWaitSync");
			glWaitSync = (WaitSync_t)GetProcAddress("glWaitSync");
			glGetInteger64v = (GetInteger64v_t)GetProcAddress("glGetInteger64v");
			glGetSynciv = (GetSynciv_t)GetProcAddress("glGetSynciv");
			glGetInteger64i_v = (GetInteger64i_v_t)GetProcAddress("glGetInteger64i_v");
			glGetBufferParameteri64v = (GetBufferParameteri64v_t)GetProcAddress("glGetBufferParameteri64v");
			glFramebufferTexture = (FramebufferTexture_t)GetProcAddress("glFramebufferTexture");
			glTexImage2DMultisample = (TexImage2DMultisample_t)GetProcAddress("glTexImage2DMultisample");
			glTexImage3DMultisample = (TexImage3DMultisample_t)GetProcAddress("glTexImage3DMultisample");
			glGetMultisamplefv = (GetMultisamplefv_t)GetProcAddress("glGetMultisamplefv");
			glSampleMaski = (SampleMaski_t)GetProcAddress("glSampleMaski");
			return;
		}

		void Load3_3Extensions(void)
		{
			glBindFragDataLocationIndexed = (BindFragDataLocationBindIndexed_t)GetProcAddress("glBindFragDataLocationIndexed");
			glGetFragDataIndex = (GetFragDataIndex_t)GetProcAddress("glGetFragDataIndex");
			glGenSamplers = (GenSamplers_t)GetProcAddress("glGenSamplers");
			glDeleteSamplers = (DeleteSamplers_t)GetProcAddress("glDeleteSamplers");
			glIsSampler = (IsSampler_t)GetProcAddress("glIsSampler");
			glBindSampler = (BindSampler_t)GetProcAddress("glBindSampler");
			glSamplerParameteri = (SamplerParameteri_t)GetProcAddress("glSamplerParameteri");
			glSamplerParameteriv = (SamplerParameteriv_t)GetProcAddress("glSamplerParameteriv");
			glSamplerParameterf = (SamplerParameterf_t)GetProcAddress("glSamplerParameterf");
			glSamplerParameterfv = (SamplerParamterfv_t)GetProcAddress("glSamplerParameterfv");
			glSamplerParameterIiv = (SamplerParameterIiv_t)GetProcAddress("glSamplerParameterIiv");
			glSamplerParameterIuiv = (SamplerParameterIuiv_t)GetProcAddress("glSamplerParameterIuiv");
			glGetSamplerParameteriv = (GetSamplerParameteriv_t)GetProcAddress("glGetSamplerParameteriv");
			glGetSamplerParameterIiv = (GetSamplerParameterIiv_t)GetProcAddress("glGetSamplerParameterIiv");
			glGetSamplerParameterfv = (GetSamplerParameterfv_t)GetProcAddress("glGetSamplerParameterfv");
			glGetSamplerParameterIuiv = (GetSamplerParameterIuiv_t)GetProcAddress("glGetSamplerParameterIuiv");
			glQueryCounter = (QueryCounter_t)GetProcAddress("glQueryCounter");
			glGetQueryObjecti64v = (GetQueryObjecti64v_t)GetProcAddress("glGetQueryObjecti64v");
			glGetQueryObjectui64v = (GetQueryObjectui64v_t)GetProcAddress("glGetQueryObjectui64v");
			glVertexAttribDivisor = (VertexAttribDivisor_t)GetProcAddress("glVertexAttribDivisor");
			glVertexAttribP1ui = (VertexAttribP1ui_t)GetProcAddress("glVertexAttribP1ui");
			glVertexAttribP1uiv = (VertexAttribP1uiv_t)GetProcAddress("glVertexAttribP1uiv");
			glVertexAttribP2ui = (VertexAttribP2ui_t)GetProcAddress("glVertexAttribP2ui");
			glVertexAttribP2uiv = (VertexAttribP2uiv_t)GetProcAddress("glVertexAttribP2uiv");
			glVertexAttribP3ui = (VertexAttribP3ui_t)GetProcAddress("glVertexAttribP3ui");
			glVertexAttribP3uiv = (VertexAttribP3uiv_t)GetProcAddress("glVertexAttribP3uiv");
			glVertexAttribP4ui = (VertexAttribP4ui_t)GetProcAddress("glVertexAttribP4ui");
			glVertexAttribP4uiv = (VertexAttribP4uiv_t)GetProcAddress("glVertexAttribP4uiv");
			glVertexAttrib4uiv = (VertexAttrib4uiv_t)GetProcAddress("glVertexAttrib4uiv");
			glVertexP2ui = (VertexP2ui_t)GetProcAddress("glVertexP2ui");
			glVertexP2uiv = (VertexP2uiv_t)GetProcAddress("glVertexP2uiv");
			glVertexP3ui = (VertexP3ui_t)GetProcAddress("glVertexP3ui");
			glVertexP3uiv = (VertexP3uiv_t)GetProcAddress("glVertexP3uiv");
			glVertexP4ui = (VertexP4ui_t)GetProcAddress("glVertexP4ui");
			glVertexP4uiv = (VertexP4uiv_t)GetProcAddress("glVertexP4uiv");
			glTexCoordP1ui = (TexCoordP1ui_t)GetProcAddress("glTexCoordP1ui");
			glTexCoordP1uiv = (TexCoordP1uiv_t)GetProcAddress("glTexCoordP1uiv");
			glTexCoordP2ui = (TexCoordP2ui_t)GetProcAddress("glTexCoordP2ui");
			glTexCoordP2uiv = (TexCoordP2uiv_t)GetProcAddress("glTexCoordP2uiv");
			glTexCoordP3ui = (TexCoordP3ui_t)GetProcAddress("glTexCoordP3ui");
			glTexCoordP3uiv = (TexCoordP3uiv_t)GetProcAddress("glTexCoordP3uiv");
			glTexCoordP4ui = (TexCoordP4ui_t)GetProcAddress("glTexCoordP4ui");
			glTexCoordP4uiv = (TexCoordP4uiv_t)GetProcAddress("glTexCoordP4uiv");
			glMultiTexCoordP1ui = (MultiTexCoordP1ui_t)GetProcAddress("glMultiTexCoordP1ui");
			glMultiTexCoordP1uiv = (MultiTexCoordP1uiv_t)GetProcAddress("glMultiTexCoordP1uiv");
			glMultiTexCoordP2ui = (MultiTexCoordP2ui_t)GetProcAddress("glMultiTexCoordP2ui");
			glMultiTexCoordP2uiv = (MultiTexCoordP2uiv_t)GetProcAddress("glMultiTexCoordP2uiv");
			glMultiTexCoordP3ui = (MultiTexCoordP3ui_t)GetProcAddress("glMultiTexCoordP3ui");
			glMultiTexCoordP3uiv = (MultiTexCoordP3uiv_t)GetProcAddress("glMultiTexCoordP3uiv");
			glMultiTexCoordP4ui = (MultiTexCoordP4ui_t)GetProcAddress("glMultiTexCoordP4ui");
			glMultiTexCoordP4uiv = (MultiTexCoordP4uiv_t)GetProcAddress("glMultiTexCoordP4uiv");
			glNormalP3ui = (NormalP3ui_t)GetProcAddress("glNormalP3ui");
			glNormalP3uiv = (NormalP3uiv_t)GetProcAddress("glNormalP3uiv");
			glColorP3ui = (ColorP3ui_t)GetProcAddress("glColorP3ui");
			glColorP3uiv = (ColorP3uiv_t)GetProcAddress("glColorP3uiv");
			glColorP4ui = (ColorP4ui_t)GetProcAddress("glColorP4ui");
			glColorP4uiv = (ColorP4uiv_t)GetProcAddress("glColorP4uiv");
			glSecondaryColorP3ui = (SecondaryColorP3ui_t)GetProcAddress("glSecondaryColorP3ui");
			glSecondaryColorP3uiv = (SecondaryColorP3uiv_t)GetProcAddress("glSecondaryColorP3uiv");
			return;
		}
	
		void Load4_0Extensions(void)
		{
			glMinSampleShading = (MinSampleShading_t)GetProcAddress("glMinSampleShading");
			glBlendEquationi = (BlendEquationi_t)GetProcAddress("glBlendEquationi");
			glBlendEquationSeparatei = (BlendEquationSeparatei_t)GetProcAddress("glBlendEquationSeparatei");
			glBlendFunci = (BlendFunci_t)GetProcAddress("glBlendFunci");
			glBlendFuncSeparatei = (BlendFuncSeparatei_t)GetProcAddress("glBlendFuncSeparatei");
			glDrawArraysIndirect = (DrawArraysIndirect_t)GetProcAddress("glDrawArraysIndirect");
			glDrawElementsIndirect = (DrawElementsIndirect_t)GetProcAddress("glDrawElementsIndirect");
			glUniform1d = (Uniform1d_t)GetProcAddress("glUniform1d");
			glUniform2d = (Uniform2d_t)GetProcAddress("glUniform2d");
			glUniform3d = (Uniform3d_t)GetProcAddress("glUniform3d");
			glUniform4d = (Uniform4d_t)GetProcAddress("glUniform4d");
			glUniform1dv = (Uniform1dv_t)GetProcAddress("glUniform1dv");
			glUniform2dv = (Uniform2dv_t)GetProcAddress("glUniform2dv");
			glUniform3dv = (Uniform3dv_t)GetProcAddress("glUniform3dv");
			glUniform4dv = (Uniform4dv_t)GetProcAddress("glUniform4dv");
			glUniformMatrix2dv = (UniformMatrix2dv_t)GetProcAddress("glUniformMatrix2dv");
			glUniformMatrix3dv = (UniformMatrix3dv_t)GetProcAddress("glUniformMatrix3dv");
			glUniformMatrix4dv = (UniformMatrix4dv_t)GetProcAddress("glUniformMatrix4dv");
			glUniformMatrix2x3dv = (UniformMatrix2x3dv_t)GetProcAddress("glUniformMatrix2x3dv");
			glUniformMatrix2x4dv = (UniformMatrix2x4dv_t)GetProcAddress("glUniformMatrix2x4dv");
			glUniformMatrix3x2dv = (UniformMatrix3x2dv_t)GetProcAddress("glUniformMatrix3x2dv");
			glUniformMatrix3x4dv = (UniformMatrix3x4dv_t)GetProcAddress("glUniformMatrix3x4dv");
			glUniformMatrix4x2dv = (UniformMatrix4x2dv_t)GetProcAddress("glUniformMatrix4x2dv");
			glUniformMatrix4x3dv = (UniformMatrix4x3dv_t)GetProcAddress("glUniformMatrix4x3dv");
			glGetUniformdv = (GetUniformdv_t)GetProcAddress("glGetUniformdv");
			glGetSubroutineUniformLocation = (GetSubroutineUniformLocation_t)GetProcAddress("glGetSubroutineUniformLocation");
			glGetSubroutineIndex = (GetSubroutineIndex_t)GetProcAddress("glGetSubroutineIndex");
			glGetActiveSubroutineUniformiv = (GetActiveSubroutineUniformiv_t)GetProcAddress("glGetActiveSubroutineUniformiv");
			glGetActiveSubroutineUniformName = (GetActiveSubroutineUniformName_t)GetProcAddress("glGetActiveSubroutineUniformName");
			glGetActiveSubroutineName = (GetActiveSubroutineName_t)GetProcAddress("glGetActiveSubroutineName");
			glUniformSubroutinesuiv = (UniformSubroutinesuiv_t)GetProcAddress("glUniformSubroutinesuiv");
			glGetUniformSubroutineuiv = (GetUniformSubroutineuiv_t)GetProcAddress("glGetUniformSubroutineuiv");
			glGetProgramStageiv = (GetProgramStageiv_t)GetProcAddress("glGetProgramStageiv");
			glPatchParameteri = (PatchParameteri_t)GetProcAddress("glPatchParameteri");
			glPatchParameterfv = (PatchParameterfv_t)GetProcAddress("glPatchParameterfv");
			glBindTransformFeedback = (BindTransformFeedback_t)GetProcAddress("glBindTransformFeedback");
			glDeleteTransformFeedbacks = (DeleteTransformFeedbacks_t)GetProcAddress("glDeleteTransformFeedbacks");
			glGenTransformFeedbacks = (GenTransformFeedbacks_t)GetProcAddress("glGenTransformFeedbacks");
			glIsTransformFeedback = (IsTransformFeedback_t)GetProcAddress("glIsTransformFeedback");
			glPauseTransformFeedback = (PauseTransformFeedback_t)GetProcAddress("glPauseTransformFeedback");
			glResumeTransformFeedback = (ResumeTransportFeedback_t)GetProcAddress("glResumeTransformFeedback");
			glDrawTransformFeedback = (DrawTransformFeedback_t)GetProcAddress("glDrawTransformFeedback");
			glDrawTransformFeedbackStream = (DrawTransformFeedbackStream_t)GetProcAddress("glDrawTransformFeedbackStream");
			glBeginQueryIndexed = (BeginQueryIndexed_t)GetProcAddress("glBeginQueryIndexed");
			glEndQueryIndexed = (EndQueryIndexed_t)GetProcAddress("glEndQueryIndexed");
			glGetQueryIndexediv = (GetQueryIndexed_t)GetProcAddress("glGetQueryIndexediv");
			return;
		}

		void Load4_1Extensions(void)
		{
			glReleaseShaderCompiler = (ReleaseShaderCompiler_t)GetProcAddress("glReleaseShaderCompiler");
			glShaderBinary = (ShaderBinary_t)GetProcAddress("glShaderBinary");
			glGetShaderPrecisionFormat = (GetShaderPrecisionFormat_t)GetProcAddress("glGetShaderPrecisionFormat");
			glDepthRangef = (DepthRangef_t)GetProcAddress("glDepthRangef");
			glClearDepthf = (ClearDepthf_t)GetProcAddress("glClearDepthf");
			glGetProgramBinary = (GetProgramBinary_t)GetProcAddress("glGetProgramBinary");
			glProgramBinary = (ProgramBinary_t)GetProcAddress("glProgramBinary");
			glProgramParameteri = (ProgramParameteri_t)GetProcAddress("glProgramParameteri");
			glUseProgramStages = (UseProgramStages_t)GetProcAddress("glUseProgramStages");
			glActiveShaderProgram = (ActiveShaderProgram_t)GetProcAddress("glActiveShaderProgram");
			glCreateShaderProgramv = (CreateShaderProgramv_t)GetProcAddress("glCreateShaderProgramv");
			glBindProgramPipeline = (BindProgramPipeline_t)GetProcAddress("glBindProgramPipeline");
			glDeleteProgramPipelines = (DeleteProgramPipelines_t)GetProcAddress("glDeleteProgramPipelines");
			glGenProgramPipelines = (GenProgramPipelines_t)GetProcAddress("glGenProgramPipelines");
			glIsProgramPipeline = (IsProgramPipeline_t)GetProcAddress("glIsProgramPipeline");
			glGetProgramPipelineiv = (GetProgramPipelineiv_t)GetProcAddress("glGetProgramPipelineiv");
			glProgramUniform1i = (ProgramUniform1i_t)GetProcAddress("glProgramUniform1i");
			glProgramUniform1iv = (ProgramUniform1iv_t)GetProcAddress("glProgramUniform1iv");
			glProgramUniform1f = (ProgramUniform1f_t)GetProcAddress("glProgramUniform1f");
			glProgramUniform1fv = (ProgramUniform1fv_t)GetProcAddress("glProgramUniform1fv");
			glProgramUniform1d = (ProgramUniform1d_t)GetProcAddress("glProgramUniform1d");
			glProgramUniform1dv = (ProgramUniform1dv_t)GetProcAddress("glProgramUniform1dv");
			glProgramUniform1ui = (ProgramUniform1ui_t)GetProcAddress("glProgramUniform1ui");
			glProgramUniform1uiv = (ProgramUniform1uiv_t)GetProcAddress("glProgramUniform1uiv");
			glProgramUniform2i = (ProgramUniform2i_t)GetProcAddress("glProgramUniform2i");
			glProgramUniform2iv = (ProgramUniform2iv_t)GetProcAddress("glProgramUniform2iv");
			glProgramUniform2f = (ProgramUniform2f_t)GetProcAddress("glProgramUniform2f");
			glProgramUniform2fv = (ProgramUniform2fv_t)GetProcAddress("glProgramUniform2fv");
			glProgramUniform2d = (ProgramUniform2d_t)GetProcAddress("glProgramUniform2d");
			glProgramUniform2dv = (ProgramUniform2dv_t)GetProcAddress("glProgramUniform2dv");
			glProgramUniform2ui = (ProgramUniform2ui_t)GetProcAddress("glProgramUniform2ui");
			glProgramUniform2uiv = (ProgramUniform2uiv_t)GetProcAddress("glProgramUniform2uiv");
			glProgramUniform3i = (ProgramUniform3i_t)GetProcAddress("glProgramUniform3i");
			glProgramUniform3iv = (ProgramUniform3iv_t)GetProcAddress("glProgramUniform3iv");
			glProgramUniform3f = (ProgramUniform3f_t)GetProcAddress("glProgramUniform3f");
			glProgramUniform3fv = (ProgramUniform3fv_t)GetProcAddress("glProgramUniform3fv");
			glProgramUniform3d = (ProgramUniform3d_t)GetProcAddress("glProgramUniform3d");
			glProgramUniform3dv = (ProgramUniform3dv_t)GetProcAddress("glProgramUniform3dv");
			glProgramUniform3ui = (ProgramUniform3ui_t)GetProcAddress("glProgramUniform3ui");
			glProgramUniform3uiv = (ProgramUniform3uiv_t)GetProcAddress("glProgramUniform3uiv");
			glProgramUniform4i = (ProgramUniform4i_t)GetProcAddress("glProgramUniform4i");
			glProgramUniform4iv = (ProgramUniform4iv_t)GetProcAddress("glProgramUniform4iv");
			glProgramUniform4f = (ProgramUniform4f_t)GetProcAddress("glProgramUniform4f");
			glProgramUniform4fv = (ProgramUniform4fv_t)GetProcAddress("glProgramUniform4fv");
			glProgramUniform4d = (ProgramUniform4d_t)GetProcAddress("glProgramUniform4d");
			glProgramUniform4dv = (ProgramUniform4dv_t)GetProcAddress("glProgramUniform4dv");
			glProgramUniform4ui = (ProgramUniform4ui_t)GetProcAddress("glProgramUniform4ui");
			glProgramUniform4uiv = (ProgramUniform4uiv_t)GetProcAddress("glProgramUniform4uiv");
			glProgramUniformMatrix2fv = (ProgramUniformMatrix2fv_t)GetProcAddress("glProgramUniformMatrix2fv");
			glProgramUniformMatrix3fv = (ProgramUniformMatrix3fv_t)GetProcAddress("glProgramUniformMatrix3fv");
			glProgramUniformMatrix4fv = (ProgramUniformMatrix4fv_t)GetProcAddress("glProgramUniformMatrix4fv");
			glProgramUniformMatrix2dv = (ProgramUniformMatrix2dv_t)GetProcAddress("glProgramUniformMatrix2dv");
			glProgramUniformMatrix3dv = (ProgramUniformMatrix3dv_t)GetProcAddress("glProgramUniformMatrix3dv");
			glProgramUniformMatrix4dv = (ProgramUniformMatrix4dv_t)GetProcAddress("glProgramUniformMatrix4dv");
			glProgramUniformMatrix2x3fv = (ProgramUniformMatrix2x3fv_t)GetProcAddress("glProgramUniformMatrix2x3fv");
			glProgramUniformMatrix3x2fv = (ProgramUniformMatrix3x2fv_t)GetProcAddress("glProgramUniformMatrix3x2fv");
			glProgramUniformMatrix2x4fv = (ProgramUniformMatrix2x4fv_t)GetProcAddress("glProgramUniformMatrix2x4fv");
			glProgramUniformMatrix4x2fv = (ProgramUniformMatrix4x2fv_t)GetProcAddress("glProgramUniformMatrix4x2fv");
			glProgramUniformMatrix3x4fv = (ProgramUniformMatrix3x4fv_t)GetProcAddress("glProgramUniformMatrix3x4fv");
			glProgramUniformMatrix4x3fv = (ProgramUniformMatrix4x3fv_t)GetProcAddress("glProgramUniformMatrix4x3fv");
			glProgramUniformMatrix2x3dv = (ProgramUniformMatrix2x3dv_t)GetProcAddress("glProgramUniformMatrix2x3dv");
			glProgramUniformMatrix3x2dv = (ProgramUniformMatrix3x2dv_t)GetProcAddress("glProgramUniformMatrix3x2dv");
			glProgramUniformMatrix2x4dv = (ProgramUniformMatrix2x4dv_t)GetProcAddress("glProgramUniformMatrix2x4dv");
			glProgramUniformMatrix4x2dv = (ProgramUniformMatrix4x2dv_t)GetProcAddress("glProgramUniformMatrix4x2dv");
			glProgramUniformMatrix3x4dv = (ProgramUniformMatrix3x4dv_t)GetProcAddress("glProgramUniformMatrix3x4dv");
			glProgramUniformMatrix4x3dv = (ProgramUniformMatrix4x3dv_t)GetProcAddress("glProgramUniformMatrix4x3dv");
			glValidateProgramPipeline = (ValidateProgramPipeline_t)GetProcAddress("glValidateProgramPipeline");
			glGetProgramPipelineInfoLog = (GetProgramPipelineInfoLog_t)GetProcAddress("glGetProgramPipelineInfoLog");
			glVertexAttribL1d = (VertexAttribL1d_t)GetProcAddress("glVertexAttribL1d");
			glVertexAttribL2d = (VertexAttribL2d_t)GetProcAddress("glVertexAttribL2d");
			glVertexAttribL3d = (VertexAttribL3d_t)GetProcAddress("glVertexAttribL3d");
			glVertexAttribL4d = (VertexAttribL4d_t)GetProcAddress("glVertexAttribL4d");
			glVertexAttribL1dv = (VertexAttribL1dv_t)GetProcAddress("glVertexAttribL1dv");
			glVertexAttribL2dv = (VertexAttribL2dv_t)GetProcAddress("glVertexAttribL2dv");
			glVertexAttribL3dv = (VertexAttribL3dv_t)GetProcAddress("glVertexAttribL3dv");
			glVertexAttribL4dv = (VertexAttribL4dv_t)GetProcAddress("glVertexAttribL4dv");
			glVertexAttribLPointer = (VertexAttribLPointer_t)GetProcAddress("glVertexAttribLPointer");
			glGetVertexAttribLdv = (GetVertexAttribLdv_t)GetProcAddress("glGetVertexAttribLdv");
			glViewportArrayv = (ViewportArrayv_t)GetProcAddress("glViewportArrayv");
			glViewportIndexedf = (ViewportIndexedf_t)GetProcAddress("glViewportIndexedf");
			glViewportIndexedfv = (ViewportIndexedfv_t)GetProcAddress("glViewportIndexedfv");
			glScissorArrayv = (ScissorArrayv_t)GetProcAddress("glScissorArrayv");
			glScissorIndexed = (ScissorIndexed_t)GetProcAddress("glScissorIndexed");
			glScissorIndexedv = (ScissorIndexedv_t)GetProcAddress("glScissorIndexedv");
			glDepthRangeIndexed = (DepthRangeIndexed_t)GetProcAddress("glDepthRangeIndexed");
			glDepthRangeArrayv = (DepthRangeArrayv_t)GetProcAddress("glDepthRangeArrayv");
			glGetFloati_v = (GetFloati_v_t)GetProcAddress("glGetFloati_v");
			glGetDoublei_v = (GetDoublei_v_t)GetProcAddress("glGetDoublei_v");
			return;
		}

		void Load4_2Extensions(void)
		{
			glDrawArraysInstancedBaseInstance = (DrawArraysInstancedBaseInstance_t)GetProcAddress("glDrawArraysInstancedBaseInstance");
			glDrawElementsInstancedBaseInstance = (DrawElementsInstancedBaseInstance_t)GetProcAddress("glDrawElementsInstancedBaseInstance");
			glDrawElementsInstancedBaseVertexBaseInstance = (DrawElementsInstancedBaseVertexBaseInstance_t)GetProcAddress("glDrawElementsInstancedBaseVertexBaseInstance");
			glGetInternalformativ = (GetInternalFormativ_t)GetProcAddress("glGetInternalformativ");
			glGetActiveAtomicCounterBufferiv = (GetActiveAtomicCounterBufferiv_t)GetProcAddress("glGetActiveAtomicCounterBufferiv");
			glBindImageTexture = (BindImageTexture_t)GetProcAddress("glBindImageTexture");
			glMemoryBarrier = (MemoryBarrier_t)GetProcAddress("glMemoryBarrier");
			glTexStorage1D = (TexStorage1D_t)GetProcAddress("glTexStorage1D");
			glTexStorage2D = (TexStorage2D_t)GetProcAddress("glTexStorage2D");
			glTexStorage3D = (TexStorage3D_t)GetProcAddress("glTexStorage3D");
			glDrawTransformFeedbackInstanced = (DrawTransformFeedbackInstanced)GetProcAddress("glDrawTransformFeedbackInstanced");
			glDrawTransformFeedbackStreamInstanced = (DrawTransformFeedbackStreamInstanced)GetProcAddress("glDrawTransformFeedbackStreamInstanced");
			return;
		}

		void Load4_3Extensions(void)
		{
			glClearBufferData = (ClearBufferData_t)GetProcAddress("glClearBufferData");
			glClearBufferSubData = (ClearBufferSubData_t)GetProcAddress("glClearBufferSubData");
			glDispatchCompute = (DispatchCompute_t)GetProcAddress("glDispatchCompute");
			glDispatchComputeIndirect = (DispatchComputeIndirect_t)GetProcAddress("glDispatchComputeIndirect");
			glCopyImageSubData = (CopyImageSubData_t)GetProcAddress("glCopyImageSubData");
			glFramebufferParameteri = (FramebufferParameteri_t)GetProcAddress("glFramebufferParameteri");
			glGetFramebufferParameteriv = (GetFramebufferParameteriv_t)GetProcAddress("glGetFramebufferParameteriv");
			glGetInternalformati64v = (GetInternalFormati64v_t)GetProcAddress("glGetInternalformati64v");
			glInvalidateTexSubImage = (InvalidateTexSubImage_t)GetProcAddress("glInvalidateTexSubImage");
			glInvalidateTexImage = (InvalidateTexImage_t)GetProcAddress("glInvalidateTexImage");
			glInvalidateBufferSubData = (InvalidateBufferSubData_t)GetProcAddress("glInvalidateBufferSubData");
			glInvalidateBufferData = (InvalidateBufferData_t)GetProcAddress("glInvalidateBufferData");
			glInvalidateFramebuffer = (InvalidateFramebuffer_t)GetProcAddress("glInvalidateFramebuffer");
			glInvalidateSubFramebuffer = (InvalidateSubFramebuffer_t)GetProcAddress("glInvalidateSubFramebuffer");
			glMultiDrawArraysIndirect = (MultiDrawArraysIndirect_t)GetProcAddress("glMultiDrawArraysIndirect");
			glMultiDrawElementsIndirect = (MultiDrawElementsIndirect_t)GetProcAddress("glMultiDrawElementsIndirect");
			glGetProgramInterfaceiv = (GetProgramInterfaceiv_t)GetProcAddress("glGetProgramInterfaceiv");
			glGetProgramResourceIndex = (GetProgramResourceIndex_t)GetProcAddress("glGetProgramResourceIndex");
			glGetProgramResourceName = (GetProgramResourceName_t)GetProcAddress("glGetProgramResourceName");
			glGetProgramResourceiv = (GetProgramResourceiv_t)GetProcAddress("glGetProgramResourceiv");
			glGetProgramResourceLocation = (GetProgramResourceLocation_t)GetProcAddress("glGetProgramResourceLocation");
			glGetProgramResourceLocationIndex = (GetProgramResourceLocationIndex_t)GetProcAddress("glGetProgramResourceLocationIndex");
			glShaderStorageBlockBinding = (ShaderStorageBlockBinding_t)GetProcAddress("glShaderStorageBlockBinding");
			glTexBufferRange = (TexBufferRange_t)GetProcAddress("glTexBufferRange");
			glTexStorage2DMultisample = (TexStorage2DMultisample_t)GetProcAddress("glTexStorage2DMultisample");
			glTexStorage3DMultisample = (TexStorage3DMultisample_t)GetProcAddress("glTexStorage3DMultisample");
			glTextureView = (TextureView_t)GetProcAddress("glTextureView");
			glBindVertexBuffer = (BindVertexBuffer_t)GetProcAddress("glBindVertexBuffer");
			glVertexAttribFormat = (VertexAttribFormat_t)GetProcAddress("glVertexAttribFormat");
			glVertexAttribIFormat = (VertexAttribIFormat_t)GetProcAddress("glVertexAttribIFormat");
			glVertexAttribLFormat = (VertexAttribLFormat_t)GetProcAddress("glVertexAttribLFormat");
			glVertexAttribBinding = (VertexAttribBinding_t)GetProcAddress("glVertexAttribBinding");
			glVertexBindingDivisor = (VertexBindingDivisor_t)GetProcAddress("glVertexBindingDivisor");
			glDebugMessageControl = (DebugMessageControl_t)GetProcAddress("glDebugMessageControl");
			glDebugMessageInsert = (DebugMessageInsert_t)GetProcAddress("glDebugMessageInsert");
			glDebugMessageCallback = (DebugMessageCallback_t)GetProcAddress("glDebugMessageCallback");
			glGetDebugMessageLog = (GetDebugMessageLog_t)GetProcAddress("glGetDebugMessageLog");
			glPushDebugGroup = (PushDebugGroup_t)GetProcAddress("glPushDebugGroup");
			glPopDebugGroup = (PopDebugGroup_t)GetProcAddress("glPopDebugGroup");
			glObjectLabel = (ObjectLabel_t)GetProcAddress("glObjectLabel");
			glObjectPtrLabel = (ObjectPtrLabel_t)GetProcAddress("glObjectPtrLabel");
			glGetObjectLabel = (GetObjectLabel_t)GetProcAddress("glGetObjectLabel");
			glGetObjectPtrLabel = (GetObjectPtrLabel_t)GetProcAddress("glGetObjectPtrLabel");
			return;
		}

		void Load4_4Extensions(void)
		{
			glBufferStorage = (BufferStorage_t)GetProcAddress("glBufferStorage");
			glClearTexImage = (ClearTexImage_t)GetProcAddress("glClearTexImage");
			glClearTexSubImage = (ClearTexSubImage_t)GetProcAddress("glClearTexSubImage");
			glBindBuffersBase = (BindBuffersBase_t)GetProcAddress("glBindBuffersBase");
			glBindBuffersRange = (BindBuffersRange_t)GetProcAddress("glBindBuffersRange");
			glBindTextures = (BindTextures_t)GetProcAddress("glBindTextures");
			glBindSamplers = (BindSamplers_t)GetProcAddress("glBindSamplers");
			glBindImageTextures = (BindImageTextures_t)GetProcAddress("glBindImageTextures");
			glBindVertexBuffers = (BindVertexBuffers_t)GetProcAddress("glBindVertexBuffers");
			return;
		}
	};

}
#endif