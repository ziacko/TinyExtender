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
	extern void(*glDrawRangeElements) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
	extern void(*glTexImage3D) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
	extern void(*glTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
	extern void(*glCopyTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	enum openGL1_2
	{
		gl_unsigned_byte_3_3_2 =				0x8032,
		gl_unsigned_short_4_4_4_4 =				0x8033,
		gl_unsigned_short_5_5_5_1 =				0x8034,
		gl_unsigned_int_8_8_8_8 =				0x8035,
		gl_unsigned_int_10_10_10_2 =			0x8036,
		gl_texture_binding_3d =					0x806a,
		gl_pack_skip_images =					0x806b,
		gl_pack_image_height =					0x806c,
		gl_unpack_skip_images =					0x806d,
		gl_unpack_image_height =				0x806e,
		gl_texture_3d =							0x806f,
		gl_proxy_texture_3d =					0x8070,
		gl_texture_depth =						0x8071,
		gl_texture_wrap_r =						0x8072,
		gl_max_3d_texture_size =				0x8073,
		gl_unsigned_byte_2_3_3_rev =			0x8362,
		gl_unsigned_short_5_6_5 =				0x8363,
		gl_unsigned_short_5_6_5_rev =			0x8364,
		gl_unsigned_short_4_4_4_4_rev =			0x8365,
		gl_unsigned_short_1_5_5_5_rev =			0x8366,
		gl_unsigned_int_8_8_8_8_rev =			0x8367,
		gl_unsigned_int_2_10_10_10_rev =		0x8368,
		gl_bgr =								0x80e0,
		gl_bgra =								0x80e1,
		gl_max_elements_vertices =				0x80e8,
		gl_max_elements_indices =				0x80e9,
		gl_clamp_to_edge =						0x812f,
		gl_texture_min_lod =					0x813a,
		gl_texture_max_lod =					0x813b,
		gl_texture_base_level =					0x813c,
		gl_texture_max_level =					0x813d,
		gl_smooth_point_size_range =			0x0b12,
		gl_smooth_point_size_granularity =		0x0b13,
		gl_smooth_line_width_range =			0x0b22,
		gl_smooth_line_width_granularity =		0x0b23,
		gl_aliased_line_width_range =			0x846e,
		gl_rescale_normal =						0x803a,
		gl_light_model_color_control =			0x81f8,
		gl_single_color =						0x81f9,
		gl_separate_specular_color =			0x81fa,
		gl_aliased_point_size_range =			0x846d
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
		gl_texture0 =								0x84c0,
		gl_texture1 =								0x84c1,
		gl_texture2 =								0x84c2,
		gl_texture3 =								0x84c3,
		gl_texture4 =								0x84c4,
		gl_texture5 =								0x84c5,
		gl_texture6 =								0x84c6,
		gl_texture7 =								0x84c7,
		gl_texture8 =								0x84c8,
		gl_texture9 =								0x84c9,
		gl_texture10 =								0x84ca,
		gl_texture11 =								0x84cb,
		gl_texture12 =								0x84cc,
		gl_texture13 =								0x84cd,
		gl_texture14 =								0x84ce,
		gl_texture15 =								0x84cf,
		gl_texture16 =								0x84d0,
		gl_texture17 =								0x84d1,
		gl_texture18 =								0x84d2,
		gl_texture19 =								0x84d3,
		gl_texture20 =								0x84d4,
		gl_texture21 =								0x84d5,
		gl_texture22 =								0x84d6,
		gl_texture23 =								0x84d7,
		gl_texture24 =								0x84d8,
		gl_texture25 =								0x84d9,
		gl_texture26 =								0x84da,
		gl_texture27 =								0x84db,
		gl_texture28 =								0x84dc,
		gl_texture29 =								0x84dd,
		gl_texture30 =								0x84de,
		gl_texture31 =								0x84df,
		gl_active_texture =							0x84e0,
		gl_multisample =							0x809d,
		gl_sample_alpha_to_coverage =				0x809e,
		gl_sample_alpha_to_one =					0x809f,
		gl_sample_coverage =						0x80a0,
		gl_sample_buffers =							0x80a8,
		gl_samples =								0x80a9,
		gl_sample_coverage_value =					0x80aa,
		gl_sample_coverage_invert =					0x80ab,
		gl_texture_cube_map =						0x8513,
		gl_texture_binding_cube_map =				0x8514,
		gl_texture_cube_map_positive_x =			0x8515,
		gl_texture_cube_map_negative_x =			0x8516,
		gl_texture_cube_map_positive_y =			0x8517,
		gl_texture_cube_map_negative_y =			0x8518,
		gl_texture_cube_map_positive_z =			0x8519,
		gl_texture_cube_map_negative_z =			0x851a,
		gl_proxy_texture_cube_map =					0x851b,
		gl_max_cube_map_texture_size =				0x851c,
		gl_compressed_rgb =							0x84ed,
		gl_compressed_rgba =						0x84ee,
		gl_texture_compression_hint =				0x84ef,
		gl_texture_compressed_image_size =			0x86a0,
		gl_texture_compressed =						0x86a1,
		gl_num_compressed_texture_formats =			0x86a2,
		gl_compressed_texture_formats =				0x86a3,
		gl_clamp_to_border =						0x812d,
		gl_client_active_texture =					0x84e1,
		gl_max_texture_units =						0x84e2,
		gl_transpose_modelview_matrix =				0x84e3,
		gl_transpose_projection_matrix =			0x84e4,
		gl_transpose_texture_matrix =				0x84e5,
		gl_transpose_color_matrix =					0x84e6,
		gl_multisample_bit =						0x20000000,
		gl_normal_map =								0x8511,
		gl_reflection_map =							0x8512,
		gl_compressed_alpha =						0x84e9,
		gl_compressed_luminance =					0x84ea,
		gl_compressed_luminance_alpha =				0x84eb,
		gl_compressed_intensity =					0x84ec,
		gl_combine =								0x8570,
		gl_combine_rgb =							0x8571,
		gl_combine_alpha =							0x8572,
		gl_source0_rgb =							0x8580,
		gl_source1_rgb =							0x8581,
		gl_source2_rgb =							0x8582,
		gl_source0_alpha =							0x8588,
		gl_source1_alpha =							0x8589,
		gl_source2_alpha =							0x858a,
		gl_operand0_rgb =							0x8590,
		gl_operand1_rgb =							0x8591,
		gl_operand2_rgb =							0x8592,
		gl_operand0_alpha =							0x8598,
		gl_operand1_alpha =							0x8599,
		gl_operand2_alpha =							0x859a,
		gl_rgb_scale =								0x8573,
		gl_add_signed =								0x8574,
		gl_interpolate =							0x8575,
		gl_subtract =								0x84e7,
		gl_constant =								0x8576,
		gl_primary_color =							0x8577,
		gl_previous =								0x8578,
		gl_dot3_rgb =								0x86ae,
		gl_dot3_rgba =								0x86af,
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
		gl_blend_dst_rgb =						0x80c8,
		gl_blend_src_rgb =						0x80c9,
		gl_blend_dst_alpha =					0x80ca,
		gl_blend_src_alpha =					0x80cb,
		gl_point_fade_threshold_size =			0x8128,
		gl_depth_component16 =					0x81a5,
		gl_depth_component24 =					0x81a6,
		gl_depth_component32 =					0x81a7,
		gl_mirrored_repeat =					0x8370,
		gl_max_texture_lod_bias =				0x84fd,
		gl_texture_lod_bias =					0x8501,
		gl_incr_wrap =							0x8507,
		gl_decr_wrap =							0x8508,
		gl_texture_depth_size =					0x884a,
		gl_texture_compare_mode =				0x884c,
		gl_texture_compare_func =				0x884d,
		gl_point_size_min =						0x8126,
		gl_point_size_max =						0x8127,
		gl_point_distance_attenuation =			0x8129,
		gl_generate_mipmap =					0x8191,
		gl_generate_mipmap_hint =				0x8192,
		gl_fog_coordinate_source =				0x8450,
		gl_fog_coordinate =						0x8451,
		gl_fragment_depth =						0x8452,
		gl_current_fog_coordinate =				0x8453,
		gl_fog_coordinate_array_type =			0x8454,
		gl_fog_coordinate_array_stride =		0x8455,
		gl_fog_coordinate_array_pointer =		0x8456,
		gl_fog_coordinate_array =				0x8457,
		gl_color_sum =							0x8458,
		gl_current_secondary_color =			0x8459,
		gl_secondary_color_array_size =			0x845a,
		gl_secondary_color_array_type =			0x845b,
		gl_secondary_color_array_stride =		0x845c,
		gl_secondary_color_array_pointer =		0x845d,
		gl_secondary_color_array =				0x845e,
		gl_texture_filter_control =				0x8500,
		gl_depth_texture_mode =					0x884b,
		gl_compare_r_to_texture =				0x884e,
		gl_func_add =							0x8006,
		gl_func_subtract =						0x800a,
		gl_func_reverse_subtract =				0x800b,
		gl_min =								0x8007,
		gl_max =								0x8008,
		gl_constant_color =						0x8001,
		gl_one_minus_constant_color =			0x8002,
		gl_constant_alpha =						0x8003,
		gl_one_minus_constant_alpha =			0x8004
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
		gl_buffer_size =								0x8764,
		gl_buffer_usage =								0x8765,
		gl_query_counter_bits =							0x8864,
		gl_current_query =								0x8865,
		gl_query_result =								0x8866,
		gl_query_result_available =						0x8867,
		gl_array_buffer =								0x8892,
		gl_element_array_buffer =						0x8893,
		gl_array_buffer_binding =						0x8894,
		gl_element_array_buffer_binding =				0x8895,
		gl_vertex_attrib_array_buffer_binding =			0x889f,
		gl_read_only =									0x88b8,
		gl_write_only =									0x88b9,
		gl_read_write =									0x88ba,
		gl_buffer_access =								0x88bb,
		gl_buffer_mapped =								0x88bc,
		gl_buffer_map_pointer =							0x88bd,
		gl_stream_draw =								0x88e0,
		gl_stream_read =								0x88e1,
		gl_stream_copy =								0x88e2,
		gl_static_draw =								0x88e4,
		gl_static_read =								0x88e5,
		gl_static_copy =								0x88e6,
		gl_dynamic_draw =								0x88e8,
		gl_dynamic_read =								0x88e9,
		gl_dynamic_copy =								0x88ea,
		gl_samples_passed =								0x8914,
		gl_src1_alpha =									0x8589,
		gl_vertex_array_buffer_binding =				0x8896,
		gl_normal_array_buffer_binding =				0x8897,
		gl_color_array_buffer_binding =					0x8898,
		gl_index_array_buffer_binding =					0x8899,
		gl_texture_coord_array_buffer_binding =			0x889a,
		gl_edge_flag_array_buffer_binding =				0x889b,
		gl_secondary_color_array_buffer_binding =		0x889c,
		gl_fog_coordinate_array_buffer_binding =		0x889d,
		gl_weight_array_buffer_binding =				0x889e,
		gl_fog_coord_src =								0x8450,
		gl_fog_coord =									0x8451,
		gl_current_fog_coord =							0x8453,
		gl_fog_coord_array_type =						0x8454,
		gl_fog_coord_array_stride =						0x8455,
		gl_fog_coord_array_pointer =					0x8456,
		gl_fog_coord_array =							0x8457,
		gl_fog_coord_array_buffer_binding =				0x889d,
		gl_src0_rgb =									0x8580,
		gl_src1_rgb =									0x8581,
		gl_src2_rgb =									0x8582,
		gl_src0_alpha =									0x8588,
		gl_src2_alpha =									0x858a,
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
		blend_equation_rgb =						0x8009,
		gl_vertex_attrib_array_enabled =			0x8622,
		gl_vertex_attrib_array_size =				0x8623,
		gl_vertex_attrib_array_stride =				0x8624,
		gl_vertex_attrib_array_type =				0x8625,
		gl_current_vertex_attrib =					0x8626,
		gl_vertex_program_point_size =				0x8642,
		gl_vertex_attrib_array_pointer =			0x8645,
		gl_stencil_back_func =						0x8800,
		gl_stencil_back_fail =						0x8801,
		gl_stencil_back_pass_depth_fail =			0x8802,
		gl_stencil_back_pass_depth_pass =			0x8803,
		gl_max_draw_buffers =						0x8824,
		gl_draw_buffer0 =							0x8825,
		gl_draw_buffer1 =							0x8826,
		gl_draw_buffer2 =							0x8827,
		gl_draw_buffer3 =							0x8828,
		gl_draw_buffer4 =							0x8829,
		gl_draw_buffer5 =							0x882a,
		gl_draw_buffer6 =							0x882b,
		gl_draw_buffer7 =							0x882c,
		gl_draw_buffer8 =							0x882d,
		gl_draw_buffer9 =							0x882e,
		gl_draw_buffer10 =							0x882f,
		gl_draw_buffer11 =							0x8830,
		gl_draw_buffer12 =							0x8831,
		gl_draw_buffer13 =							0x8832,
		gl_draw_buffer14 =							0x8833,
		gl_draw_buffer15 =							0x8834,
		gl_blend_equation_alpha =					0x883d,
		gl_max_vertex_attribs =						0x8869,
		gl_vertex_attrib_array_normalized =			0x886a,
		gl_max_texture_image_units =				0x8872,
		gl_fragment_shader =						0x8b30,
		gl_vertex_shader =							0x8b31,
		gl_max_fragment_uniform_components =		0x8b49,
		gl_max_vertex_uniform_components =			0x8b4a,
		gl_max_varying_floats =						0x8b4b,
		gl_max_vertex_texture_image_units =			0x8b4c,
		gl_max_combined_texture_image_units =		0x8b4d,
		gl_shader_type =							0x8b4f,
		gl_float_vec2 =								0x8b50,
		gl_float_vec3 =								0x8b51,
		gl_float_vec4 =								0x8b52,
		gl_int_vec2 =								0x8b53,
		gl_int_vec3 =								0x8b54,
		gl_int_vec4 =								0x8b55,
		gl_bool =									0x8b56,
		gl_bool_vec2 =								0x8b57,
		gl_bool_vec3 =								0x8b58,
		gl_bool_vec4 =								0x8b59,
		gl_float_mat2 =								0x8b5a,
		gl_float_mat3 =								0x8b5b,
		gl_float_mat4 =								0x8b5c,
		gl_sampler_1d =								0x8b5d,
		gl_sampler_2d =								0x8b5e,
		gl_sampler_3d =								0x8b5f,
		gl_sampler_cube =							0x8b60,
		gl_sampler_1d_shadow =						0x8b61,
		gl_sampler_2d_shadow =						0x8b62,
		gl_delete_status =							0x8b80,
		gl_compile_status =							0x8b81,
		gl_link_status =							0x8b82,
		gl_validate_status =						0x8b83,
		gl_info_log_length =						0x8b84,
		gl_attached_shaders =						0x8b85,
		gl_active_uniforms =						0x8b86,
		gl_active_uniform_max_length =				0x8b87,
		gl_shader_source_length =					0x8b88,
		gl_active_attributes =						0x8b89,
		gl_active_attribute_max_length =			0x8b8a,
		gl_fragment_shader_derivative_hint =		0x8b8b,
		gl_shading_language_version =				0x8b8c,
		gl_current_program =						0x8b8d,
		gl_point_sprite_coord_origin =				0x8ca0,
		gl_lower_left =								0x8ca1,
		gl_upper_left =								0x8ca2,
		gl_stencil_back_ref =						0x8ca3,
		gl_stencil_back_value_mask =				0x8ca4,
		gl_stencil_back_writemask =					0x8ca5,
		gl_vertex_program_two_side =				0x8643,
		gl_point_sprite =							0x8861,
		gl_coord_replace =							0x8862,
		gl_max_texture_coords =						0x8871
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
		gl_pixel_pack_buffer =					0x88eb,
		gl_pixel_unpack_buffer =				0x88ec,
		gl_pixel_pack_buffer_binding =			0x88ed,
		gl_pixel_unpack_buffer_binding =		0x88ef,
		gl_float_mat2x3 =						0x8b65,
		gl_float_mat2x4 =						0x8b66,
		gl_float_mat3x2 =						0x8b67,
		gl_float_mat3x4 =						0x8b68,
		gl_float_mat4x2 =						0x8b69,
		gl_float_mat4x3 =						0x8b6a,
		gl_srgb =								0x8c40,
		gl_srgb8 =								0x8c41,
		gl_srgb_alpha =							0x8c42,
		gl_srgb8_alpha8 =						0x8c43,
		gl_compressed_srgb =					0x8c48,
		gl_compressed_srgb_alpha =				0x8c49,
		gl_current_raster_secondary_color =		0x845f,
		gl_sluminance_alpha =					0x8c44,
		gl_sluminance8_alpha8 =					0x8c45,
		gl_sluminance =							0x8c46,
		gl_sluminance8 =						0x8c47,
		gl_compressed_sluminance =				0x8c4a,
		gl_compressed_sluminance_alpha =		0x8c4b,
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
		gl_compare_ref_to_texture =								0x884e,
		gl_clip_distance0 =										0x3000,
		gl_clip_distance1 =										0x3001,
		gl_clip_distance2 =										0x3002,
		gl_clip_distance3 =										0x3003,
		gl_clip_distance4 =										0x3004,
		gl_clip_distance5 =										0x3005,
		gl_clip_distance6 =										0x3006,
		gl_clip_distance7 =										0x3007,
		gl_max_clip_distances =									0x0d32,
		gl_major_version =										0x821b,
		gl_minor_version =										0x821c,
		gl_num_extensions =										0x821d,
		gl_context_flags =										0x821e,
		gl_compressed_red =										0x8225,
		gl_compressed_rg =										0x8226,
		gl_context_flag_forward_compatible_bit =				0x00000001,
		gl_rgba32f =											0x8814,
		gl_rgb32f =												0x8815,
		gl_rgba16f =											0x881a,
		gl_rgb16f =												0x881b,
		gl_vertex_attrib_array_integer =						0x88fd,
		gl_max_array_texture_layers =							0x88ff,
		gl_min_program_texel_offset =							0x8904,
		gl_max_program_texel_offset =							0x8905,
		gl_clamp_read_color =									0x891c,
		gl_fixed_only =											0x891d,
		gl_max_varying_components =								0x8b4b,
		gl_texture_1d_array =									0x8c18,
		gl_proxy_texture_1d_array =								0x8c19,
		gl_texture_2d_array =									0x8c1a,
		gl_proxy_texture_2d_array =								0x8c1b,
		gl_texture_binding_1d_array =							0x8c1c,
		gl_texture_binding_2d_array =							0x8c1d,
		gl_r11f_g11f_b10f =										0x8c3a,
		gl_unsigned_int_10f_11f_11f_rev =						0x8c3b,
		gl_rgb9_e5 =											0x8c3d,
		gl_unsigned_int_5_9_9_9_rev =							0x8c3e,
		gl_texture_shared_size =								0x8c3f,
		gl_transform_feedback_varying_max_length =				0x8c76,
		gl_transform_feedback_buffer_mode =						0x8c7f,
		gl_max_transform_feedback_separate_components =			0x8c80,
		gl_transform_feedback_varyings =						0x8c83,
		gl_transform_feedback_buffer_start =					0x8c84,
		gl_transform_feedback_buffer_size =						0x8c85,
		gl_primitives_generated =								0x8c87,
		gl_transform_feedback_primitives_written =				0x8c88,
		gl_rasterizer_discard =									0x8c89,
		gl_max_transform_feedback_interleaved_components =		0x8c8a,
		gl_max_transform_feedback_separate_attribs =			0x8c8b,
		gl_interleaved_attribs =								0x8c8c,
		gl_separate_attribs =									0x8c8d,
		gl_transform_feedback_buffer =							0x8c8e,
		gl_transform_feedback_buffer_binding =					0x8c8f,
		gl_rgba32ui =											0x8d70,
		gl_rgb32ui =											0x8d71,
		gl_rgba16ui =											0x8d76,
		gl_rgb16ui =											0x8d77,
		gl_rgba8ui =											0x8d7c,
		gl_rgb8ui =												0x8d7d,
		gl_rgba32i =											0x8d82,
		gl_rgb32i =												0x8d83,
		gl_rgba16i =											0x8d88,
		gl_rgb16i =												0x8d89,
		gl_rgba8i =												0x8d8e,
		gl_rgb8i =												0x8d8f,
		gl_red_integer =										0x8d94,
		gl_green_integer =										0x8d95,
		gl_blue_integer =										0x8d96,
		gl_rgb_integer =										0x8d98,
		gl_rgba_integer =										0x8d99,
		gl_bgr_integer =										0x8d9a,
		gl_bgra_integer =										0x8d9b,
		gl_sampler_1d_array =									0x8dc0,
		gl_sampler_2d_array =									0x8dc1,
		gl_sampler_1d_array_shadow =							0x8dc3,
		gl_sampler_2d_array_shadow =							0x8dc4,
		gl_sampler_cube_shadow =								0x8dc5,
		gl_unsigned_int_vec2 =									0x8dc6,
		gl_unsigned_int_vec3 =									0x8dc7,
		gl_unsigned_int_vec4 =									0x8dc8,
		gl_int_sampler_1d =										0x8dc9,
		gl_int_sampler_2d =										0x8dca,
		gl_int_sampler_3d =										0x8dcb,
		gl_int_sampler_cube =									0x8dcc,
		gl_int_sampler_1d_array =								0x8dce,
		gl_int_sampler_2d_array =								0x8dcf,
		gl_unsigned_int_sampler_1d =							0x8dd1,
		gl_unsigned_int_sampler_2d =							0x8dd2,
		gl_unsigned_int_sampler_3d =							0x8dd3,
		gl_unsigned_int_sampler_cube =							0x8dd4,
		gl_unsigned_int_sampler_1d_array =						0x8dd6,
		gl_unsigned_int_sampler_2d_array =						0x8dd7,
		gl_query_wait =											0x8e13,
		gl_query_no_wait =										0x8e14,
		gl_query_by_region_wait =								0x8e15,
		gl_query_by_region_no_wait =							0x8e16,
		gl_buffer_access_flags =								0x911f,
		gl_buffer_map_length =									0x9120,
		gl_buffer_map_offset =									0x9121,
		gl_depth_component32f =									0x8cac,
		gl_depth32f_stencil8 =									0x8cad,
		gl_float_32_unsigned_int_24_8_rev =						0x8dad,
		gl_invalid_framebuffer_operation =						0x0506,
		gl_framebuffer_attachment_color_encoding =				0x8210,
		gl_framebuffer_attachment_component_type =				0x8211,
		gl_framebuffer_attachment_red_size =					0x8212,
		gl_framebuffer_attachment_green_size =					0x8213,
		gl_framebuffer_attachment_blue_size =					0x8214,
		gl_framebuffer_attachment_alpha_size =					0x8215,
		gl_framebuffer_attachment_depth_size =					0x8216,
		gl_framebuffer_attachment_stencil_size =				0x8217,
		gl_framebuffer_default =								0x8218,
		gl_framebuffer_undefined =								0x8219,
		gl_depth_stencil_attachment =							0x821a,
		gl_max_renderbuffer_size =								0x84e8,
		gl_depth_stencil =										0x84f9,
		gl_unsigned_int_24_8 =									0x84fa,
		gl_depth24_stencil8 =									0x88f0,
		gl_texture_stencil_size =								0x88f1,
		gl_texture_red_type =									0x8c10,
		gl_texture_green_type =									0x8c11,
		gl_texture_blue_type =									0x8c12,
		gl_texture_alpha_type =									0x8c13,
		gl_texture_depth_type =									0x8c16,
		gl_unsigned_normalized =								0x8c17,
		gl_framebuffer_binding =								0x8ca6,
		gl_draw_framebuffer_binding =							0x8ca6,
		gl_renderbuffer_binding =								0x8ca7,
		gl_read_framebuffer =									0x8ca8,
		gl_draw_framebuffer =									0x8ca9,
		gl_read_framebuffer_binding =							0x8caa,
		gl_renderbuffer_samples =								0x8cab,
		gl_framebuffer_attachment_object_type =					0x8cd0,
		gl_framebuffer_attachment_object_name =					0x8cd1,
		gl_framebuffer_attachment_texture_level =				0x8cd2,
		gl_framebuffer_attachment_texture_cube_map_face =		0x8cd3,
		gl_framebuffer_attachment_texture_layer =				0x8cd4,
		gl_framebuffer_complete =								0x8cd5,
		gl_framebuffer_incomplete_attachment =					0x8cd6,
		gl_framebuffer_incomplete_missing_attachment =			0x8cd7,
		gl_framebuffer_incomplete_draw_buffer =					0x8cdb,
		gl_framebuffer_incomplete_read_buffer =					0x8cdc,
		gl_framebuffer_unsupported =							0x8cdd,
		gl_max_color_attachments =								0x8cdf,
		gl_color_attachment0 =									0x8ce0,
		gl_color_attachment1 =									0x8ce1,
		gl_color_attachment2 =									0x8ce2,
		gl_color_attachment3 =									0x8ce3,
		gl_color_attachment4 =									0x8ce4,
		gl_color_attachment5 =									0x8ce5,
		gl_color_attachment6 =									0x8ce6,
		gl_color_attachment7 =									0x8ce7,
		gl_color_attachment8 =									0x8ce8,
		gl_color_attachment9 =									0x8ce9,
		gl_color_attachment10 =									0x8cea,
		gl_color_attachment11 =									0x8ceb,
		gl_color_attachment12 =									0x8cec,
		gl_color_attachment13 =									0x8ced,
		gl_color_attachment14 =									0x8cee,
		gl_color_attachment15 =									0x8cef,
		gl_depth_attachment =									0x8d00,
		gl_stencil_attachment =									0x8d20,
		gl_framebuffer =										0x8d40,
		gl_renderbuffer =										0x8d41,
		gl_renderbuffer_width =									0x8d42,
		gl_renderbuffer_height =								0x8d43,
		gl_renderbuffer_internal_format =						0x8d44,
		gl_stencil_index1 =										0x8d46,
		gl_stencil_index4 =										0x8d47,
		gl_stencil_index8 =										0x8d48,
		gl_stencil_index16 =									0x8d49,
		gl_renderbuffer_red_size =								0x8d50,
		gl_renderbuffer_green_size =							0x8d51,
		gl_renderbuffer_blue_size =								0x8d52,
		gl_renderbuffer_alpha_size =							0x8d53,
		gl_renderbuffer_depth_size =							0x8d54,
		gl_renderbuffer_stencil_size =							0x8d55,
		gl_framebuffer_incomplete_multisample =					0x8d56,
		gl_max_samples =										0x8d57,
		gl_index =												0x8222,
		gl_texture_luminance_type =								0x8c14,
		gl_texture_intensity_type =								0x8c15,
		gl_framebuffer_srgb =									0x8db9,
		gl_half_float =											0x140b,
		gl_map_read_bit =										0x0001,
		gl_map_write_bit =										0x0002,
		gl_map_invalidate_range_bit =							0x0004,
		gl_map_invalidate_buffer_bit =							0x0008,
		gl_map_flush_explicit_bit =								0x0010,
		gl_map_unsynchronized_bit =								0x0020,
		gl_compressed_red_rgtc1 =								0x8dbb,
		gl_compressed_signed_red_rgtc1 =						0x8dbc,
		gl_compressed_rg_rgtc2 =								0x8dbd,
		gl_compressed_signed_rg_rgtc2 =							0x8dbe,
		gl_rg =													0x8227,
		gl_rg_integer =											0x8228,
		gl_r8 =													0x8229,
		gl_r16 =												0x822a,
		gl_rg8 =												0x822b,
		gl_rg16 =												0x822c,
		gl_r16f =												0x822d,
		gl_r32f =												0x822e,
		gl_rg16f =												0x822f,
		gl_rg32f =												0x8230,
		gl_r8i =												0x8231,
		gl_r8ui =												0x8232,
		gl_r16i =												0x8233,
		gl_r16ui =												0x8234,
		gl_r32i =												0x8235,
		gl_r32ui =												0x8236,
		gl_rg8i =												0x8237,
		gl_rg8ui =												0x8238,
		gl_rg16i =												0x8239,
		gl_rg16ui =												0x823a,
		gl_rg32i =												0x823b,
		gl_rg32ui =												0x823c,
		gl_vertex_array_binding =								0x85b5,
		gl_clamp_vertex_color =									0x891a,
		gl_clamp_fragment_color =								0x891b,
		gl_alpha_integer =										0x8d97,
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
		gl_sampler_2d_rect =									0x8b63,
		gl_sampler_2d_rect_shadow =								0x8b64,
		gl_sampler_buffer =										0x8dc2,
		gl_int_sampler_2d_rect =								0x8dcd,
		gl_int_sampler_buffer =									0x8dd0,
		gl_unsigned_int_sampler_2d_rect =						0x8dd5,
		gl_unsigned_int_sampler_buffer =						0x8dd8,
		gl_texture_buffer =										0x8c2a,
		gl_max_texture_buffer_size =							0x8c2b,
		gl_texture_binding_buffer =								0x8c2c,
		gl_texture_buffer_data_store_binding =					0x8c2d,
		gl_texture_rectangle =									0x84f5,
		gl_texture_binding_rectangle =							0x84f6,
		gl_proxy_texture_rectangle =							0x84f7,
		gl_max_rectangle_texture_size =							0x84f8,
		gl_r8_snorm =											0x8f94,
		gl_rg8_snorm =											0x8f95,
		gl_rgb8_snorm =											0x8f96,
		gl_rgba8_snorm =										0x8f97,
		gl_r16_snorm =											0x8f98,
		gl_rg16_snorm =											0x8f99,
		gl_rgb16_snorm =										0x8f9a,
		gl_rgba16_snorm =										0x8f9b,
		gl_signed_normalized =									0x8f9c,
		gl_primitive_restart =									0x8f9d,
		gl_primitive_restart_index =							0x8f9e,
		gl_copy_read_buffer =									0x8f36,
		gl_copy_write_buffer =									0x8f37,
		gl_uniform_buffer =										0x8a11,
		gl_uniform_buffer_binding =								0x8a28,
		gl_uniform_buffer_start =								0x8a29,
		gl_uniform_buffer_size =								0x8a2a,
		gl_max_vertex_uniform_blocks =							0x8a2b,
		gl_max_fragment_uniform_blocks =						0x8a2d,
		gl_max_combined_uniform_blocks =						0x8a2e,
		gl_max_uniform_buffer_bindings =						0x8a2f,
		gl_max_uniform_block_size =								0x8a30,
		gl_max_combined_vertex_uniform_components =				0x8a31,
		gl_max_combined_fragment_uniform_components =			0x8a33,
		gl_uniform_buffer_offset_alignment =					0x8a34,
		gl_active_uniform_block_max_name_length =				0x8a35,
		gl_active_uniform_blocks =								0x8a36,
		gl_uniform_type =										0x8a37,
		gl_uniform_size =										0x8a38,
		gl_uniform_name_length =								0x8a39,
		gl_uniform_block_index =								0x8a3a,
		gl_uniform_offset =										0x8a3b,
		gl_uniform_array_stride =								0x8a3c,
		gl_uniform_matrix_stride =								0x8a3d,
		gl_uniform_is_row_major =								0x8a3e,
		gl_uniform_block_binding =								0x8a3f,
		gl_uniform_block_data_size =							0x8a40,
		gl_uniform_block_name_length =							0x8a41,
		gl_uniform_block_active_uniforms =						0x8a42,
		gl_uniform_block_active_uniform_indices =				0x8a43,
		gl_uniform_block_referenced_by_vertex_shader =			0x8a44,
		gl_uniform_block_referenced_by_fragment_shader =		0x8a46,
		gl_invalid_index =										0xffffffffu
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
		gl_context_core_profile_bit =						0x00000001,
		gl_context_compatibility_profile_bit =				0x00000002,
		gl_lines_adjacency =								0x000a,
		gl_line_strip_adjacency =							0x000b,
		gl_triangles_adjacency =							0x000c,
		gl_triangle_strip_adjacency =						0x000d,
		gl_program_point_size =								0x8642,
		gl_max_geometry_texture_image_units =				0x8c29,
		gl_framebuffer_attachment_layered =					0x8da7,
		gl_framebuffer_incomplete_layer_targets =			0x8da8,
		gl_geometry_shader =								0x8dd9,
		gl_geometry_vertices_out =							0x8916,
		gl_geometry_input_type =							0x8917,
		gl_geometry_output_type =							0x8918,
		gl_max_geometry_uniform_components =				0x8ddf,
		gl_max_geometry_output_vertices =					0x8de0,
		gl_max_geometry_total_output_components =			0x8de1,
		gl_max_vertex_output_components =					0x9122,
		gl_max_geometry_input_components =					0x9123,
		gl_max_geometry_output_components =					0x9124,
		gl_max_fragment_input_components =					0x9125,
		gl_context_profile_mask =							0x9126,
		gl_depth_clamp =									0x864f,
		gl_quads_follow_provoking_vertex_convention =		0x8e4c,
		gl_first_vertex_convention =						0x8e4d,
		gl_last_vertex_convention =							0x8e4e,
		gl_provoking_vertex =								0x8e4f,
		gl_texture_cube_map_seamless =						0x884f,
		gl_max_server_wait_timeout =						0x9111,
		gl_object_type =									0x9112,
		gl_sync_condition =									0x9113,
		gl_sync_status =									0x9114,
		gl_sync_flags =										0x9115,
		gl_sync_fence =										0x9116,
		gl_sync_gpu_commands_complete =						0x9117,
		gl_unsignaled =										0x9118,
		gl_signaled =										0x9119,
		gl_already_signaled =								0x911a,
		gl_timeout_expired =								0x911b,
		gl_condition_satisfied =							0x911c,
		gl_wait_failed =									0x911d,
		gl_timeout_ignored =								0xffffffffffffffffull,
		gl_sync_flush_commands_bit =						0x00000001,
		gl_sample_position =								0x8e50,
		gl_sample_mask =									0x8e51,
		gl_sample_mask_value =								0x8e52,
		gl_max_sample_mask_words =							0x8e59,
		gl_texture_2d_multisample =							0x9100,
		gl_proxy_texture_2d_multisample =					0x9101,
		gl_texture_2d_multisample_array =					0x9102,
		gl_proxy_texture_2d_multisample_array =				0x9103,
		gl_texture_binding_2d_multisample =					0x9104,
		gl_texture_binding_2d_multisample_array =			0x9105,
		gl_texture_samples =								0x9106,
		gl_texture_fixed_sample_locations =					0x9107,
		gl_sampler_2d_multisample =							0x9108,
		gl_int_sampler_2d_multisample =						0x9109,
		gl_unsigned_int_sampler_2d_multisample =			0x910a,
		gl_sampler_2d_multisample_array =					0x910b,
		gl_int_sampler_2d_multisample_array =				0x910c,
		gl_unsigned_int_sampler_2d_multisample_array =		0x910d,
		gl_max_color_texture_samples =						0x910e,
		gl_max_depth_texture_samples =						0x910f,
		gl_max_integer_samples =							0x9110,
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
		gl_vertex_attrib_array_divisor =		0x88fe,
		gl_src1_color =							0x88f9,
		gl_one_minus_src1_color =				0x88fa,
		gl_one_minus_src1_alpha =				0x88fb,
		gl_max_dual_source_draw_buffers =		0x88fc,
		gl_any_samples_passed =					0x8c2f,
		gl_sampler_binding =					0x8919,
		gl_rgb10_a2ui =							0x906f,
		gl_texture_swizzle_r =					0x8e42,
		gl_texture_swizzle_g =					0x8e43,
		gl_texture_swizzle_b =					0x8e44,
		gl_texture_swizzle_a =					0x8e45,
		gl_texture_swizzle_rgba =				0x8e46,
		gl_time_elapsed =						0x88bf,
		gl_timestamp =							0x8e28,
		gl_int_2_10_10_10_rev =					0x8d9f,
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
		gl_sample_shading =												0x8c36,
		gl_min_sample_shading_value =									0x8c37,
		gl_min_program_texture_gather_offset =							0x8e5e,
		gl_max_program_texture_gather_offset =							0x8e5f,
		gl_texture_cube_map_array =										0x9009,
		gl_texture_binding_cube_map_array =								0x900a,
		gl_proxy_texture_cube_map_array =								0x900b,
		gl_sampler_cube_map_array =										0x900c,
		gl_sampler_cube_map_array_shadow =								0x900d,
		gl_int_sampler_cube_map_array =									0x900e,
		gl_unsigned_int_sampler_cube_map_array =						0x900f,
		gl_draw_indirect_buffer =										0x8f3f,
		gl_draw_indirect_buffer_binding =								0x8f43,
		gl_geometry_shader_invocations =								0x887f,
		gl_max_geometry_shader_invocations =							0x8e5a,
		gl_min_fragment_interpolation_offset =							0x8e5b,
		gl_max_fragment_interpolation_offset =							0x8e5c,
		gl_fragment_interpolation_offset_bits =							0x8e5d,
		gl_max_vertex_streams =											0x8e71,
		gl_double_vec2 =												0x8ffc,
		gl_double_vec3 =												0x8ffd,
		gl_double_vec4 =												0x8ffe,
		gl_double_mat2 =												0x8f46,
		gl_double_mat3 =												0x8f47,
		gl_double_mat4 =												0x8f48,
		gl_double_mat2x3 =												0x8f49,
		gl_double_mat2x4 =												0x8f4a,
		gl_double_mat3x2 =												0x8f4b,
		gl_double_mat3x4 =												0x8f4c,
		gl_double_mat4x2 =												0x8f4d,
		gl_double_mat4x3 =												0x8f4e,
		gl_active_subroutines =											0x8de5,
		gl_active_subroutine_uniforms =									0x8de6,
		gl_active_subroutine_uniform_locations =						0x8e47,
		gl_active_subroutine_max_length =								0x8e48,
		gl_active_subroutine_uniform_max_length =						0x8e49,
		gl_max_subroutines =											0x8de7,
		gl_max_subroutine_uniform_locations =							0x8de8,
		gl_num_compatible_subroutines =									0x8e4a,
		gl_compatible_subroutines =										0x8e4b,
		gl_patches =													0x000e,
		gl_patch_vertices =												0x8e72,
		gl_patch_default_inner_level =									0x8e73,
		gl_patch_default_outer_level =									0x8e74,
		gl_tess_control_output_vertices =								0x8e75,
		gl_tess_gen_mode =												0x8e76,
		gl_tess_gen_spacing =											0x8e77,
		gl_tess_gen_vertex_order =										0x8e78,
		gl_tess_gen_point_mode =										0x8e79,
		gl_isolines =													0x8e7a,
		gl_fractional_odd =												0x8e7b,
		gl_fractional_even =											0x8e7c,
		gl_max_patch_vertices =											0x8e7d,
		gl_max_tess_gen_level =											0x8e7e,
		gl_max_tess_control_uniform_components =						0x8e7f,
		gl_max_tess_evaluation_uniform_components =						0x8e80,
		gl_max_tess_control_texture_image_units =						0x8e81,
		gl_max_tess_evaluation_texture_image_units =					0x8e82,
		gl_max_tess_control_output_components =							0x8e83,
		gl_max_tess_patch_components =									0x8e84,
		gl_max_tess_control_total_output_components =					0x8e85,
		gl_max_tess_evaluation_output_components =						0x8e86,
		gl_max_tess_control_uniform_blocks =							0x8e89,
		gl_max_tess_evaluation_uniform_blocks =							0x8e8a,
		gl_max_tess_control_input_components =							0x886c,
		gl_max_tess_evaluation_input_components =						0x886d,
		gl_max_combined_tess_control_uniform_components =				0x8e1e,
		gl_max_combined_tess_evaluation_uniform_components =			0x8e1f,
		gl_uniform_block_referenced_by_tess_control_shader =			0x84f0,
		gl_uniform_block_referenced_by_tess_evaluation_shader =			0x84f1,
		gl_tess_evaluation_shader =										0x8e87,
		gl_tess_control_shader =										0x8e88,
		gl_transform_feedback =											0x8e22,
		gl_transform_feedback_buffer_paused =							0x8e23,
		gl_transform_feedback_buffer_active =							0x8e24,
		gl_transform_feedback_binding =									0x8e25,
		gl_max_transform_feedback_buffers =								0x8e70,
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
		gl_fixed =									0x140c,
		gl_implementation_color_read_type =			0x8b9a,
		gl_implementation_color_read_format =		0x8b9b,
		gl_low_float =								0x8df0,
		gl_medium_float =							0x8df1,
		gl_high_float =								0x8df2,
		gl_low_int =								0x8df3,
		gl_medium_int =								0x8df4,
		gl_high_int =								0x8df5,
		gl_shader_compiler =						0x8dfa,
		gl_shader_binary_formats =					0x8df8,
		gl_num_shader_binary_formats =				0x8df9,
		gl_max_vertex_uniform_vectors =				0x8dfb,
		gl_max_varying_vectors =					0x8dfc,
		gl_max_fragment_uniform_vectors =			0x8dfd,
		gl_rgb565 =									0x8d62,
		gl_program_binary_retrievable_hint =		0x8257,
		gl_program_binary_length =					0x8741,
		gl_num_program_binary_formats =				0x87fe,
		gl_program_binary_formats =					0x87ff,
		gl_vertex_shader_bit =						0x00000001,
		gl_fragment_shader_bit =					0x00000002,
		gl_geometry_shader_bit =					0x00000004,
		gl_tess_control_shader_bit =				0x00000008,
		gl_tess_evaluation_shader_bit =				0x00000010,
		gl_all_shader_bits =						0xffffffff,
		gl_program_separable =						0x8258,
		gl_active_program =							0x8259,
		gl_program_pipeline_binding =				0x825a,
		gl_max_viewports =							0x825b,
		gl_viewport_subpixel_bits =					0x825c,
		gl_viewport_bounds_range =					0x825d,
		gl_layer_provoking_vertex =					0x825e,
		gl_viewport_index_provoking_vertex =		0x825f,
		gl_undefined_vertex =						0x8260
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
		gl_unpack_compressed_block_width =										0x9127,
		gl_unpack_compressed_block_height =										0x9128,
		gl_unpack_compressed_block_depth =										0x9129,
		gl_unpack_compressed_block_size =										0x912a,
		gl_pack_compressed_block_width =										0x912b,
		gl_pack_compressed_block_height =										0x912c,
		gl_pack_compressed_block_depth =										0x912d,
		gl_pack_compressed_block_size =											0x912e,
		gl_num_sample_counts =													0x9380,
		gl_min_map_buffer_alignment =											0x90bc,
		gl_atomic_counter_buffer =												0x92c0,
		gl_atomic_counter_buffer_binding =										0x92c1,
		gl_atomic_counter_buffer_start =										0x92c2,
		gl_atomic_counter_buffer_size =											0x92c3,
		gl_atomic_counter_buffer_data_size =									0x92c4,
		gl_atomic_counter_buffer_active_atomic_counters =						0x92c5,
		gl_atomic_counter_buffer_active_atomic_counter_indices =				0x92c6,
		gl_atomic_counter_buffer_referenced_by_vertex_shader =					0x92c7,
		gl_atomic_counter_buffer_referenced_by_tess_control_shader =			0x92c8,
		gl_atomic_counter_buffer_referenced_by_tess_evaluation_shader =			0x92c9,
		gl_atomic_counter_buffer_referenced_by_geometry_shader =				0x92ca,
		gl_atomic_counter_buffer_referenced_by_fragment_shader =				0x92cb,
		gl_max_vertex_atomic_counter_buffers =									0x92cc,
		gl_max_tess_control_atomic_counter_buffers =							0x92cd,
		gl_max_tess_evaluation_atomic_counter_buffers =							0x92ce,
		gl_max_geometry_atomic_counter_buffers =								0x92cf,
		gl_max_fragment_atomic_counter_buffers =								0x92d0,
		gl_max_combined_atomic_counter_buffers =								0x92d1,
		gl_max_vertex_atomic_counters =											0x92d2,
		gl_max_tess_control_atomic_counters =									0x92d3,
		gl_max_tess_evaluation_atomic_counters =								0x92d4,
		gl_max_geometry_atomic_counters =										0x92d5,
		gl_max_fragment_atomic_counters =										0x92d6,
		gl_max_combined_atomic_counters =										0x92d7,
		gl_max_atomic_counter_buffer_size =										0x92d8,
		gl_max_atomic_counter_buffer_bindings =									0x92dc,
		gl_active_atomic_counter_buffers =										0x92d9,
		gl_uniform_atomic_counter_buffer_index =								0x92da,
		gl_unsigned_int_atomic_counter =										0x92db,
		gl_vertex_attrib_array_barrier_bit =									0x00000001,
		gl_element_array_barrier_bit =											0x00000002,
		gl_uniform_barrier_bit =												0x00000004,
		gl_texture_fetch_barrier_bit =											0x00000008,
		gl_shader_image_access_barrier_bit =									0x00000020,
		gl_command_barrier_bit =												0x00000040,
		gl_pixel_buffer_barrier_bit =											0x00000080,
		gl_texture_update_barrier_bit =											0x00000100,
		gl_buffer_update_barrier_bit =											0x00000200,
		gl_framebuffer_barrier_bit =											0x00000400,
		gl_transform_feedback_barrier_bit =										0x00000800,
		gl_atomic_counter_barrier_bit =											0x00001000,
		gl_all_barrier_bits =													0xffffffff,
		gl_max_image_units =													0x8f38,
		gl_max_combined_image_units_and_fragment_outputs =						0x8f39,
		gl_image_binding_name =													0x8f3a,
		gl_image_binding_level =												0x8f3b,
		gl_image_binding_layered =												0x8f3c,
		gl_image_binding_layer =												0x8f3d,
		gl_image_binding_access =												0x8f3e,
		gl_image_1d =															0x904c,
		gl_image_2d =															0x904d,
		gl_image_3d =															0x904e,
		gl_image_2d_rect =														0x904f,
		gl_image_cube =															0x9050,
		gl_image_buffer =														0x9051,
		gl_image_1d_array =														0x9052,
		gl_image_2d_array =														0x9053,
		gl_image_cube_map_array =												0x9054,
		gl_image_2d_multisample =												0x9055,
		gl_image_2d_multisample_array =											0x9056,
		gl_int_image_1d =														0x9057,
		gl_int_image_2d =														0x9058,
		gl_int_image_3d =														0x9059,
		gl_int_image_2d_rect =													0x905a,
		gl_int_image_cube =														0x905b,
		gl_int_image_buffer =													0x905c,
		gl_int_image_1d_array =													0x905d,
		gl_int_image_2d_array =													0x905e,
		gl_int_image_cube_map_array =											0x905f,
		gl_int_image_2d_multisample =											0x9060,
		gl_int_image_2d_multisample_array =										0x9061,
		gl_unsigned_int_image_1d =												0x9062,
		gl_unsigned_int_image_2d =												0x9063,
		gl_unsigned_int_image_3d =												0x9064,
		gl_unsigned_int_image_2d_rect =											0x9065,
		gl_unsigned_int_image_cube =											0x9066,
		gl_unsigned_int_image_buffer =											0x9067,
		gl_unsigned_int_image_1d_array =										0x9068,
		gl_unsigned_int_image_2d_array =										0x9069,
		gl_unsigned_int_image_cube_map_array =									0x906a,
		gl_unsigned_int_image_2d_multisample =									0x906b,
		gl_unsigned_int_image_2d_multisample_array =							0x906c,
		gl_max_image_samples =													0x906d,
		gl_image_binding_format =												0x906e,
		gl_image_format_compatibility_type =									0x90c7,
		gl_image_format_compatibility_by_size =									0x90c8,
		gl_image_format_compatibility_by_class =								0x90c9,
		gl_max_vertex_image_uniforms =											0x90ca,
		gl_max_tess_control_image_uniforms =									0x90cb,
		gl_max_tess_evaluation_image_uniforms =									0x90cc,
		gl_max_geometry_image_uniforms =										0x90cd,
		gl_max_fragment_image_uniforms =										0x90ce,
		gl_max_combined_image_uniforms =										0x90cf,
		gl_texture_immutable_format =											0x912f,
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
		gl_num_shading_language_versions =								0x82e9,
		gl_vertex_attrib_array_long =									0x874e,
		gl_compressed_rgb8_etc2 =										0x9274,
		gl_compressed_srgb8_etc2 =										0x9275,
		gl_compressed_rgb8_punchthrough_alpha1_etc2 =					0x9276,
		gl_compressed_srgb8_punchthrough_alpha1_etc2 =					0x9277,
		gl_compressed_rgba8_etc2_eac =									0x9278,
		gl_compressed_srgb8_alpha8_etc2_eac =							0x9279,
		gl_compressed_r11_eac =											0x9270,
		gl_compressed_signed_r11_eac =									0x9271,
		gl_compressed_rg11_eac =										0x9272,
		gl_compressed_signed_rg11_eac =									0x9273,
		gl_primitive_restart_fixed_index =								0x8d69,
		gl_any_samples_passed_conservative =							0x8d6a,
		gl_max_element_index =											0x8d6b,
		gl_compute_shader =												0x91b9,
		gl_max_compute_uniform_blocks =									0x91bb,
		gl_max_compute_texture_image_units =							0x91bc,
		gl_max_compute_image_uniforms =									0x91bd,
		gl_max_compute_shared_memory_size =								0x8262,
		gl_max_compute_uniform_components =								0x8263,
		gl_max_compute_atomic_counter_buffers =							0x8264,
		gl_max_compute_atomic_counters =								0x8265,
		gl_max_combined_compute_uniform_components =					0x8266,
		gl_max_compute_work_group_invocations =							0x90eb,
		gl_max_compute_work_group_count =								0x91be,
		gl_max_compute_work_group_size =								0x91bf,
		gl_compute_work_group_size =									0x8267,
		gl_uniform_block_referenced_by_compute_shader =					0x90ec,
		gl_atomic_counter_buffer_referenced_by_compute_shader =			0x90ed,
		gl_dispatch_indirect_buffer =									0x90ee,
		gl_dispatch_indirect_buffer_binding =							0x90ef,
		gl_debug_output_synchronous =									0x8242,
		gl_debug_next_logged_message_length =							0x8243,
		gl_debug_callback_function =									0x8244,
		gl_debug_callback_user_param =									0x8245,
		gl_debug_source_api =											0x8246,
		gl_debug_source_window_system =									0x8247,
		gl_debug_source_shader_compiler =								0x8248,
		gl_debug_source_third_party =									0x8249,
		gl_debug_source_application =									0x824a,
		gl_debug_source_other =											0x824b,
		gl_debug_type_error =											0x824c,
		gl_debug_type_deprecated_behavior =								0x824d,
		gl_debug_type_undefined_behavior =								0x824e,
		gl_debug_type_portability =										0x824f,
		gl_debug_type_performance =										0x8250,
		gl_debug_type_other =											0x8251,
		gl_max_debug_message_length =									0x9143,
		gl_max_debug_logged_messages =									0x9144,
		gl_debug_logged_messages =										0x9145,
		gl_debug_severity_high =										0x9146,
		gl_debug_severity_medium =										0x9147,
		gl_debug_severity_low =											0x9148,
		gl_debug_type_marker =											0x8268,
		gl_debug_type_push_group =										0x8269,
		gl_debug_type_pop_group =										0x826a,
		gl_debug_severity_notification =								0x826b,
		gl_max_debug_group_stack_depth =								0x826c,
		gl_debug_group_stack_depth =									0x826d,
		gl_buffer =														0x82e0,
		gl_shader =														0x82e1,
		gl_program =													0x82e2,
		gl_query =														0x82e3,
		gl_program_pipeline =											0x82e4,
		gl_sampler =													0x82e6,
		gl_max_label_length =											0x82e8,
		gl_debug_output =												0x92e0,
		gl_context_flag_debug_bit =										0x00000002,
		gl_max_uniform_locations =										0x826e,
		gl_framebuffer_default_width =									0x9310,
		gl_framebuffer_default_height =									0x9311,
		gl_framebuffer_default_layers =									0x9312,
		gl_framebuffer_default_samples =								0x9313,
		gl_framebuffer_default_fixed_sample_locations =					0x9314,
		gl_max_framebuffer_width =										0x9315,
		gl_max_framebuffer_height =										0x9316,
		gl_max_framebuffer_layers =										0x9317,
		gl_max_framebuffer_samples =									0x9318,
		gl_internalformat_supported =									0x826f,
		gl_internalformat_preferred =									0x8270,
		gl_internalformat_red_size =									0x8271,
		gl_internalformat_green_size =									0x8272,
		gl_internalformat_blue_size =									0x8273,
		gl_internalformat_alpha_size =									0x8274,
		gl_internalformat_depth_size =									0x8275,
		gl_internalformat_stencil_size =								0x8276,
		gl_internalformat_shared_size =									0x8277,
		gl_internalformat_red_type =									0x8278,
		gl_internalformat_green_type =									0x8279,
		gl_internalformat_blue_type =									0x827a,
		gl_internalformat_alpha_type =									0x827b,
		gl_internalformat_depth_type =									0x827c,
		gl_internalformat_stencil_type =								0x827d,
		gl_max_width =													0x827e,
		gl_max_height =													0x827f,
		gl_max_depth =													0x8280,
		gl_max_layers =													0x8281,
		gl_max_combined_dimensions =									0x8282,
		gl_color_components =											0x8283,
		gl_depth_components =											0x8284,
		gl_stencil_components =											0x8285,
		gl_color_renderable =											0x8286,
		gl_depth_renderable =											0x8287,
		gl_stencil_renderable =											0x8288,
		gl_framebuffer_renderable =										0x8289,
		gl_framebuffer_renderable_layered =								0x828a,
		gl_framebuffer_blend =											0x828b,
		gl_read_pixels =												0x828c,
		gl_read_pixels_format =											0x828d,
		gl_read_pixels_type =											0x828e,
		gl_texture_image_format =										0x828f,
		gl_texture_image_type =											0x8290,
		gl_get_texture_image_format =									0x8291,
		gl_get_texture_image_type =										0x8292,
		gl_mipmap =														0x8293,
		gl_manual_generate_mipmap =										0x8294,
		gl_auto_generate_mipmap =										0x8295,
		gl_color_encoding =												0x8296,
		gl_srgb_read =													0x8297,
		gl_srgb_write =													0x8298,
		gl_filter =														0x829a,
		gl_vertex_texture =												0x829b,
		gl_tess_control_texture =										0x829c,
		gl_tess_evaluation_texture =									0x829d,
		gl_geometry_texture =											0x829e,
		gl_fragment_texture =											0x829f,
		gl_compute_texture =											0x82a0,
		gl_texture_shadow =												0x82a1,
		gl_texture_gather =												0x82a2,
		gl_texture_gather_shadow =										0x82a3,
		gl_shader_image_load =											0x82a4,
		gl_shader_image_store =											0x82a5,
		gl_shader_image_atomic =										0x82a6,
		gl_image_texel_size =											0x82a7,
		gl_image_compatibility_class =									0x82a8,
		gl_image_pixel_format =											0x82a9,
		gl_image_pixel_type =											0x82aa,
		gl_simultaneous_texture_and_depth_test =						0x82ac,
		gl_simultaneous_texture_and_stencil_test =						0x82ad,
		gl_simultaneous_texture_and_depth_write =						0x82ae,
		gl_simultaneous_texture_and_stencil_write =						0x82af,
		gl_texture_compressed_block_width =								0x82b1,
		gl_texture_compressed_block_height =							0x82b2,
		gl_texture_compressed_block_size =								0x82b3,
		gl_clear_buffer =												0x82b4,
		gl_texture_view =												0x82b5,
		gl_view_compatibility_class =									0x82b6,
		gl_full_support =												0x82b7,
		gl_caveat_support =												0x82b8,
		gl_image_class_4_x_32 =											0x82b9,
		gl_image_class_2_x_32 =											0x82ba,
		gl_image_class_1_x_32 =											0x82bb,
		gl_image_class_4_x_16 =											0x82bc,
		gl_image_class_2_x_16 =											0x82bd,
		gl_image_class_1_x_16 =											0x82be,
		gl_image_class_4_x_8 =											0x82bf,
		gl_image_class_2_x_8 =											0x82c0,
		gl_image_class_1_x_8 =											0x82c1,
		gl_image_class_11_11_10 =										0x82c2,
		gl_image_class_10_10_10_2 =										0x82c3,
		gl_view_class_128_bits =										0x82c4,
		gl_view_class_96_bits =											0x82c5,
		gl_view_class_64_bits =											0x82c6,
		gl_view_class_48_bits =											0x82c7,
		gl_view_class_32_bits =											0x82c8,
		gl_view_class_24_bits =											0x82c9,
		gl_view_class_16_bits =											0x82ca,
		gl_view_class_8_bits =											0x82cb,
		gl_view_class_s3tc_dxt1_rgb =									0x82cc,
		gl_view_class_s3tc_dxt1_rgba =									0x82cd,
		gl_view_class_s3tc_dxt3_rgba =									0x82ce,
		gl_view_class_s3tc_dxt5_rgba =									0x82cf,
		gl_view_class_rgtc1_red =										0x82d0,
		gl_view_class_rgtc2_rg =										0x82d1,
		gl_view_class_bptc_unorm =										0x82d2,
		gl_view_class_bptc_float =										0x82d3,
		gl_uniform =													0x92e1,
		gl_uniform_block =												0x92e2,
		gl_program_input =												0x92e3,
		gl_program_output =												0x92e4,
		gl_buffer_variable =											0x92e5,
		gl_shader_storage_block =										0x92e6,
		gl_vertex_subroutine =											0x92e8,
		gl_tess_control_subroutine =									0x92e9,
		gl_tess_evaluation_subroutine =									0x92ea,
		gl_geometry_subroutine =										0x92eb,
		gl_fragment_subroutine =										0x92ec,
		gl_compute_subroutine =											0x92ed,
		gl_vertex_subroutine_uniform =									0x92ee,
		gl_tess_control_subroutine_uniform =							0x92ef,
		gl_tess_evaluation_subroutine_uniform =							0x92f0,
		gl_geometry_subroutine_uniform =								0x92f1,
		gl_fragment_subroutine_uniform =								0x92f2,
		gl_compute_subroutine_uniform =									0x92f3,
		gl_transform_feedback_varying =									0x92f4,
		gl_active_resources =											0x92f5,
		gl_max_name_length =											0x92f6,
		gl_max_num_active_variables =									0x92f7,
		gl_max_num_compatible_subroutines =								0x92f8,
		gl_name_length =												0x92f9,
		gl_type =														0x92fa,
		gl_array_size =													0x92fb,
		gl_offset =														0x92fc,
		gl_block_index =												0x92fd,
		gl_array_stride =												0x92fe,
		gl_matrix_stride =												0x92ff,
		gl_is_row_major =												0x9300,
		gl_atomic_counter_buffer_index =								0x9301,
		gl_buffer_binding =												0x9302,
		gl_buffer_data_size =											0x9303,
		gl_num_active_variables =										0x9304,
		gl_active_variables =											0x9305,
		gl_referenced_by_vertex_shader =								0x9306,
		gl_referenced_by_tess_control_shader =							0x9307,
		gl_referenced_by_tess_evaluation_shader =						0x9308,
		gl_referenced_by_geometry_shader =								0x9309,
		gl_referenced_by_fragment_shader =								0x930a,
		gl_referenced_by_compute_shader =								0x930b,
		gl_top_level_array_size =										0x930c,
		gl_top_level_array_stride =										0x930d,
		gl_location =													0x930e,
		gl_location_index =												0x930f,
		gl_is_per_patch =												0x92e7,
		gl_shader_storage_buffer =										0x90d2,
		gl_shader_storage_buffer_binding =								0x90d3,
		gl_shader_storage_buffer_start =								0x90d4,
		gl_shader_storage_buffer_size =									0x90d5,
		gl_max_vertex_shader_storage_blocks =							0x90d6,
		gl_max_geometry_shader_storage_blocks =							0x90d7,
		gl_max_tess_control_shader_storage_blocks =						0x90d8,
		gl_max_tess_evaluation_shader_storage_blocks =					0x90d9,
		gl_max_fragment_shader_storage_blocks =							0x90da,
		gl_max_compute_shader_storage_blocks =							0x90db,
		gl_max_combined_shader_storage_blocks =							0x90dc,
		gl_max_shader_storage_buffer_bindings =							0x90dd,
		gl_max_shader_storage_block_size =								0x90de,
		gl_shader_storage_buffer_offset_alignment =						0x90df,
		gl_shader_storage_barrier_bit =									0x00002000,
		gl_max_combined_shader_output_resources =						0x8f39,
		gl_depth_stencil_texture_mode =									0x90ea,
		gl_texture_buffer_offset =										0x919d,
		gl_texture_buffer_size =										0x919e,
		gl_texture_buffer_offset_alignment =							0x919f,
		gl_texture_view_min_level =										0x82db,
		gl_texture_view_num_levels =									0x82dc,
		gl_texture_view_min_layer =										0x82dd,
		gl_texture_view_num_layers =									0x82de,
		gl_texture_immutable_levels =									0x82df,
		gl_vertex_attrib_binding =										0x82d4,
		gl_vertex_attrib_relative_offset =								0x82d5,
		gl_vertex_binding_divisor =										0x82d6,
		gl_vertex_binding_offset =										0x82d7,
		gl_vertex_binding_stride =										0x82d8,
		gl_max_vertex_attrib_relative_offset =							0x82d9,
		gl_max_vertex_attrib_bindings =									0x82da,
		gl_display_list =												0x82e7,
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
		gl_max_vertex_attrib_stride =						0x82e5,
		gl_primitive_restart_for_patches_supported =		0x8221,
		gl_texture_buffer_binding =							0x8c2a,
		gl_map_persistent_bit =								0x0040,
		gl_map_coherent_bit =								0x0080,
		gl_dynamic_storage_bit =							0x0100,
		gl_client_storage_bit =								0x0200,
		gl_client_mapped_buffer_barrier_bit = 				0x00004000,
		gl_buffer_immutable_storage =						0x821f,
		gl_buffer_storage_flags =							0x8220,
		gl_clear_texture =									0x9365,
		gl_location_component =								0x934a,
		gl_transform_feedback_buffer_index =				0x934b,
		gl_transform_feedback_buffer_stride =				0x934c,
		gl_query_buffer =									0x9192,
		gl_query_buffer_barrier_bit =						0x00008000,
		gl_query_buffer_binding =							0x9193,
		gl_query_result_no_wait =							0x9194,
		gl_mirror_clamp_to_edge =							0x8743
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
	std::error_code InitializeGLVersion();

	/**< load OpenGL 1.2 extensions */
	void Load1_2Extensions();
	/**< load OpenGL 1.3 extensions */
	void Load1_3Extensions();
	/**< load OpenGL 1.4 extensions */
	void Load1_4Extensions();
	/**< load OpenGL 1.5 extensions */
	void Load1_5Extensions();
	/**< load OpenGL 2.0 extensions */
	void Load2_0Extensions();
	/**< load OpenGL 2.1 extensions */
	void Load2_1Extensions();
	/**< load OpenGL 3.0 extensions */
	void Load3_0Extensions();
	/**< load OpenGL 3.1 extensions */
	void Load3_1Extensions();
	/**< load OpenGL 3.2 extensions */
	void Load3_2Extensions();
	/**< load OpenGL 3.3 extensions */
	void Load3_3Extensions();
	/**< load OpenGL 4.0 extensions */
	void Load4_0Extensions();
	/**< load OpenGL 4.1 extensions */
	void Load4_1Extensions();
	/**< load OpenGL 4.2 extensions */
	void Load4_2Extensions();
	/**< load OpenGL 4.3 extensions */
	void Load4_3Extensions();
	/**< load OpenGL 4.4 extensions */
	void Load4_4Extensions();

	/**< load all applicable OpenGL extensions */
	std::error_code InitializeExtentions();

	/**< load specific OpenGL extensions via OpenGL versions */
	std::error_code InitializeExtensionsSpecific(unsigned int OpenGLVersions);

	/**< whether an extension is supported */
	bool IsExtensionSupported(const char* extensionName);

}
#endif
