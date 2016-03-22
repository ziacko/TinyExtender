#ifndef TINYEXTENDER_H_
#define TINYEXTENDER_H_

#define GLVERSION1_2 1L << 1
#define GLVERSION1_3 1L << 2
#define GLVERSION1_4 1L << 3
#define GLVERSION1_5 1L << 4
#define GLVERSION2_0 1L << 5
#define GLVERSION2_1 1L << 6
#define GLVERSION3_0 1L << 7
#define GLVERSION3_1 1L << 8
#define GLVERSION3_2 1L << 9
#define GLVERSION3_3 1L << 10
#define GLVERSION4_0 1L << 11
#define GLVERSION4_1 1L << 12
#define GLVERSION4_2 1L << 13
#define GLVERSION4_3 1L << 14
#define GLVERSION4_4 1L << 15

#if defined(_WIN32)
#include <Windows.h>
#include <gl/GL.h>

//this automatically loads the OpenGL library if you are using Visual studio 
#pragma comment (lib, "opengl32.lib")
#endif

#if defined(__linux__)
#include <GL/glx.h>
#endif

#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <functional>

/*

/*
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
typedef void (*PFNGLDRAWARRAYSINSTANCEDPROC) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
typedef void (*PFNGLDRAWELEMENTSINSTANCEDPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
typedef void (*PFNGLTEXBUFFERPROC) (GLenum target, GLenum internalformat, GLuint buffer);
typedef void (*PFNGLPRIMITIVERESTARTINDEXPROC) (GLuint index);
typedef void (*PFNGLCOPYBUFFERSUBDATAPROC) (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (*PFNGLGETUNIFORMINDICESPROC) (GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
typedef void (*PFNGLGETACTIVEUNIFORMSIVPROC) (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
typedef void (*PFNGLGETACTIVEUNIFORMNAMEPROC) (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
typedef GLuint(*PFNGLGETUNIFORMBLOCKINDEXPROC) (GLuint program, const GLchar *uniformBlockName);
typedef void (*PFNGLGETACTIVEUNIFORMBLOCKIVPROC) (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
typedef void (*PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC) (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
typedef void (*PFNGLUNIFORMBLOCKBINDINGPROC) (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
extern PFNGLDRAWARRAYSINSTANCEDPROC __teDrawArraysInstanced;
extern PFNGLDRAWELEMENTSINSTANCEDPROC __teDrawElementsInstanced;
extern PFNGLTEXBUFFERPROC __teTexBuffer;
extern PFNGLPRIMITIVERESTARTINDEXPROC __tePrimitiveRestartIndex;
extern PFNGLCOPYBUFFERSUBDATAPROC __teCopyBufferSubdata;
extern PFNGLGETUNIFORMINDICESPROC __teGetUniformIndices;
extern PFNGLGETACTIVEUNIFORMSIVPROC __teGetActiveUniformsiv;
extern PFNGLGETACTIVEUNIFORMNAMEPROC __teGetActiveUniformName;
extern PFNGLGETUNIFORMBLOCKINDEXPROC __teGetUniformBlockIndex;
extern PFNGLGETACTIVEUNIFORMBLOCKIVPROC __teGetActiveUniformBlockiv;
extern PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC __teGetActiveUniformBlockName;
extern PFNGLUNIFORMBLOCKBINDINGPROC __teUniformBlockBinding;
#define glDrawArraysInstanced GETFUNCTION(__teDrawArraysInstanced)
#define glDrawElementsInstanced GETFUNCTION(__teDrawElementsInstanced)
#define glTexBuffer GETFUNCTION(__teTexBuffer)
#define glPrimitiveRestartIndex GETFUNCTION(__tePrimitiveRestartIndex)
#define glCopyBufferSubData GETFUNCTION(__teCopyBufferSubdata)
#define glGetUniformIndices GETFUNCTION(__teGetUniformIndices)
#define glGetActiveUniformsiv GETFUNCTION(__teGetActiveUniformsiv)
#define glGetActiveUniformName GETFUNCTION(__teGetActiveUniformName)
#define glGetUniformBlockIndex GETFUNCTION(__teGetUniformBlockIndex)
#define glGetActiveUniformBlockiv GETFUNCTION(__teGetActiveUniformBlockiv)
#define glGetActiveUniformBlockName GETFUNCTION(__teGetActiveUniformBlockName)
#define glUniformBlockBinding GETFUNCTION(__teUniformBlockBinding)

//OpenGL 3.2 Extensions
typedef struct __GLsync* GLsync;
#ifndef GLEXT_64_TYPES_DEFINED
/ * This code block is duplicated in glxext.h, so must be protected * /
#define GLEXT_64_TYPES_DEFINED
/ * Define int32_t, int64_t, and uint64_t types for UST/MSC * /
/ * (as used in the GL_EXT_timer_query extension). * /
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <inttypes.h>
#elif defined(__sun__) || defined(__digital__)
#include <inttypes.h>
#if defined(__STDC__)
#if defined(__arch64__) || defined(_LP64)
typedef long int int64_t;
typedef unsigned long int uint64_t;
#else
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#endif / * __arch64__ * /
#endif / * __STDC__ * /
#elif defined( __VMS ) || defined(__sgi)
#include <inttypes.h>
#elif defined(__SCO__) || defined(__USLC__)
#include <stdint.h>
#elif defined(__UNIXOS2__) || defined(__SOL64__)
typedef long int int32_t;
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#elif defined(_WIN32) && defined(__GNUC__)
#include <stdint.h>
#elif defined(_WIN32)
typedef __int32 int32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
/ * Fallback if nothing above works * /
#include <inttypes.h>
#endif
#endif
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
typedef void (*PFNGLDRAWELEMENTSBASEVERTEXPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
typedef void (*PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
typedef void (*PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
typedef void (*PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC) (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
typedef void (*PFNGLPROVOKINGVERTEXPROC) (GLenum mode);
typedef GLsync(*PFNGLFENCESYNCPROC) (GLenum condition, GLbitfield flags);
typedef GLboolean(*PFNGLISSYNCPROC) (GLsync sync);
typedef void (*PFNGLDELETESYNCPROC) (GLsync sync);
typedef GLenum(*PFNGLCLIENTWAITSYNCPROC) (GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (*PFNGLWAITSYNCPROC) (GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (*PFNGLGETINTEGER64VPROC) (GLenum pname, GLint64 *params);
typedef void (*PFNGLGETSYNCIVPROC) (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
typedef void (*PFNGLGETINTEGER64I_VPROC) (GLenum target, GLuint index, GLint64 *data);
typedef void (*PFNGLGETBUFFERPARAMETERI64VPROC) (GLenum target, GLenum pname, GLint64 *params);
typedef void (*PFNGLFRAMEBUFFERTEXTUREPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level);
typedef void (*PFNGLTEXIMAGE2DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (*PFNGLTEXIMAGE3DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (*PFNGLGETMULTISAMPLEFVPROC) (GLenum pname, GLuint index, GLfloat *val);
typedef void (*PFNGLSAMPLEMASKIPROC) (GLuint index, GLbitfield mask);
extern PFNGLDRAWELEMENTSBASEVERTEXPROC __teDrawElementsBaseVertex;
extern PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC __teDrawRangeElementsBaseVertex;
extern PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC __teDrawElementsInstancedBaseVertex;
extern PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC __teMultiDrawElementsBaseVertex;
extern PFNGLPROVOKINGVERTEXPROC __teProvokingVertex;
extern PFNGLFENCESYNCPROC __teFenceSync;
extern PFNGLISSYNCPROC __teIsSync;
extern PFNGLDELETESYNCPROC __teDeleteSync;
extern PFNGLCLIENTWAITSYNCPROC __teClientWaitSync;
extern PFNGLWAITSYNCPROC __teWaitSync;
extern PFNGLGETINTEGER64VPROC __teGetInteger64v;
extern PFNGLGETSYNCIVPROC __teGetSynciv;
extern PFNGLGETINTEGER64I_VPROC __teGetInteger64i_v;
extern PFNGLGETBUFFERPARAMETERI64VPROC __teGetBufferParameteri64v;
extern PFNGLFRAMEBUFFERTEXTUREPROC __teFramebufferTexture;
extern PFNGLTEXIMAGE2DMULTISAMPLEPROC __teTexImage2DMultisample;
extern PFNGLTEXIMAGE3DMULTISAMPLEPROC __teTexImage3DMultisample;
extern PFNGLGETMULTISAMPLEFVPROC __teGetMultisamplefv;
extern PFNGLSAMPLEMASKIPROC __teSampleMaski;
#define glDrawElementsBaseVertex GETFUNCTION(__teDrawElementsBaseVertex)
#define glDrawRangeElementsBaseVertex GETFUNCTION(__teDrawRangeElementsBaseVertex)
#define glDrawElementsInstancedBaseVertex GETFUNCTION(__teDrawElementsInstancedBaseVertex)
#define glMultiDrawElementsBaseVertex GETFUNCTION(__teMultiDrawElementsBaseVertex)
#define glProvokingVertex GETFUNCTION(__teProvokingVertex)
#define glFenceSync GETFUNCTION(__teFenceSync)
#define glIsSync GETFUNCTION(__teIsSync)
#define glDeleteSync GETFUNCTION(__teDeleteSync)
#define glClientWaitSync GETFUNCTION(__teClientWaitSync)
#define glWaitSync GETFUNCTION(__teWaitSync)
#define glGetInteger64v GETFUNCTION(__teGetInteger64v)
#define glGetSynciv GETFUNCTION(__teGetSynciv)
#define glGetInteger64i_v GETFUNCTION(__teGetInteger64i_v)
#define glGetBufferParameteri64v GETFUNCTION(__teGetBufferParameteri64v)
#define glFramebufferTexture GETFUNCTION(__teFramebufferTexture)
#define glTexImage2DMultisample GETFUNCTION(__teTexImage2DMultisample)
#define glTexImage3DMultisample GETFUNCTION(__teTexImage3DMultisample)
#define glGetMultisamplefv GETFUNCTION(__teGetMultisamplefv)
#define glSampleMaski GETFUNCTION(__teSampleMaski)

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
typedef void (*PFNGLBINDFRAGDATALOCATIONINDEXEDPROC) (GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
typedef GLint(*PFNGLGETFRAGDATAINDEXPROC) (GLuint program, const GLchar *name);
typedef void (*PFNGLGENSAMPLERSPROC) (GLsizei count, GLuint *samplers);
typedef void (*PFNGLDELETESAMPLERSPROC) (GLsizei count, const GLuint *samplers);
typedef GLboolean(*PFNGLISSAMPLERPROC) (GLuint sampler);
typedef void (*PFNGLBINDSAMPLERPROC) (GLuint unit, GLuint sampler);
typedef void (*PFNGLSAMPLERPARAMETERIPROC) (GLuint sampler, GLenum pname, GLint param);
typedef void (*PFNGLSAMPLERPARAMETERIVPROC) (GLuint sampler, GLenum pname, const GLint *param);
typedef void (*PFNGLSAMPLERPARAMETERFPROC) (GLuint sampler, GLenum pname, GLfloat param);
typedef void (*PFNGLSAMPLERPARAMETERFVPROC) (GLuint sampler, GLenum pname, const GLfloat *param);
typedef void (*PFNGLSAMPLERPARAMETERIIVPROC) (GLuint sampler, GLenum pname, const GLint *param);
typedef void (*PFNGLSAMPLERPARAMETERIUIVPROC) (GLuint sampler, GLenum pname, const GLuint *param);
typedef void (*PFNGLGETSAMPLERPARAMETERIVPROC) (GLuint sampler, GLenum pname, GLint *params);
typedef void (*PFNGLGETSAMPLERPARAMETERIIVPROC) (GLuint sampler, GLenum pname, GLint *params);
typedef void (*PFNGLGETSAMPLERPARAMETERFVPROC) (GLuint sampler, GLenum pname, GLfloat *params);
typedef void (*PFNGLGETSAMPLERPARAMETERIUIVPROC) (GLuint sampler, GLenum pname, GLuint *params);
typedef void (*PFNGLQUERYCOUNTERPROC) (GLuint id, GLenum target);
typedef void (*PFNGLGETQUERYOBJECTI64VPROC) (GLuint id, GLenum pname, GLint64 *params);
typedef void (*PFNGLGETQUERYOBJECTUI64VPROC) (GLuint id, GLenum pname, GLuint64 *params);
typedef void (*PFNGLVERTEXATTRIBDIVISORPROC) (GLuint index, GLuint divisor);
typedef void (*PFNGLVERTEXATTRIBP1UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (*PFNGLVERTEXATTRIBP1UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (*PFNGLVERTEXATTRIBP2UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (*PFNGLVERTEXATTRIBP2UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (*PFNGLVERTEXATTRIBP3UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (*PFNGLVERTEXATTRIBP3UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (*PFNGLVERTEXATTRIBP4UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (*PFNGLVERTEXATTRIBP4UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (*PFNGLVERTEXP2UIPROC) (GLenum type, GLuint value);
typedef void (*PFNGLVERTEXP2UIVPROC) (GLenum type, const GLuint *value);
typedef void (*PFNGLVERTEXP3UIPROC) (GLenum type, GLuint value);
typedef void (*PFNGLVERTEXP3UIVPROC) (GLenum type, const GLuint *value);
typedef void (*PFNGLVERTEXP4UIPROC) (GLenum type, GLuint value);
typedef void (*PFNGLVERTEXP4UIVPROC) (GLenum type, const GLuint *value);
typedef void (*PFNGLTEXCOORDP1UIPROC) (GLenum type, GLuint coords);
typedef void (*PFNGLTEXCOORDP1UIVPROC) (GLenum type, const GLuint *coords);
typedef void (*PFNGLTEXCOORDP2UIPROC) (GLenum type, GLuint coords);
typedef void (*PFNGLTEXCOORDP2UIVPROC) (GLenum type, const GLuint *coords);
typedef void (*PFNGLTEXCOORDP3UIPROC) (GLenum type, GLuint coords);
typedef void (*PFNGLTEXCOORDP3UIVPROC) (GLenum type, const GLuint *coords);
typedef void (*PFNGLTEXCOORDP4UIPROC) (GLenum type, GLuint coords);
typedef void (*PFNGLTEXCOORDP4UIVPROC) (GLenum type, const GLuint *coords);
typedef void (*PFNGLMULTITEXCOORDP1UIPROC) (GLenum texture, GLenum type, GLuint coords);
typedef void (*PFNGLMULTITEXCOORDP1UIVPROC) (GLenum texture, GLenum type, const GLuint *coords);
typedef void (*PFNGLMULTITEXCOORDP2UIPROC) (GLenum texture, GLenum type, GLuint coords);
typedef void (*PFNGLMULTITEXCOORDP2UIVPROC) (GLenum texture, GLenum type, const GLuint *coords);
typedef void (*PFNGLMULTITEXCOORDP3UIPROC) (GLenum texture, GLenum type, GLuint coords);
typedef void (*PFNGLMULTITEXCOORDP3UIVPROC) (GLenum texture, GLenum type, const GLuint *coords);
typedef void (*PFNGLMULTITEXCOORDP4UIPROC) (GLenum texture, GLenum type, GLuint coords);
typedef void (*PFNGLMULTITEXCOORDP4UIVPROC) (GLenum texture, GLenum type, const GLuint *coords);
typedef void (*PFNGLNORMALP3UIPROC) (GLenum type, GLuint coords);
typedef void (*PFNGLNORMALP3UIVPROC) (GLenum type, const GLuint *coords);
typedef void (*PFNGLCOLORP3UIPROC) (GLenum type, GLuint color);
typedef void (*PFNGLCOLORP3UIVPROC) (GLenum type, const GLuint *color);
typedef void (*PFNGLCOLORP4UIPROC) (GLenum type, GLuint color);
typedef void (*PFNGLCOLORP4UIVPROC) (GLenum type, const GLuint *color);
typedef void (*PFNGLSECONDARYCOLORP3UIPROC) (GLenum type, GLuint color);
typedef void (*PFNGLSECONDARYCOLORP3UIVPROC) (GLenum type, const GLuint *color);
extern PFNGLBINDFRAGDATALOCATIONINDEXEDPROC __teBindFragDataLocationIndexed;
extern PFNGLGETFRAGDATAINDEXPROC __teGetFragDataIndex;
extern PFNGLGENSAMPLERSPROC __teGenSamplers;
extern PFNGLDELETESAMPLERSPROC __teDeleteSamplers;
extern PFNGLISSAMPLERPROC __teIsSampler;
extern PFNGLBINDSAMPLERPROC __teBindSampler;
extern PFNGLSAMPLERPARAMETERIPROC __teSamplerParameteri;
extern PFNGLSAMPLERPARAMETERIVPROC __teSamplerParameteriv;
extern PFNGLSAMPLERPARAMETERFPROC __teSamplerParameterf;
extern PFNGLSAMPLERPARAMETERFVPROC __teSamplerParameterfv;
extern PFNGLSAMPLERPARAMETERIIVPROC __teSamplerParameterIiv;
extern PFNGLSAMPLERPARAMETERIUIVPROC __teSamplerParameterIuiv;
extern PFNGLGETSAMPLERPARAMETERIVPROC __teGetSamplerParameteriv;
extern PFNGLGETSAMPLERPARAMETERIIVPROC __teGetSamplerParameterIiv;
extern PFNGLGETSAMPLERPARAMETERFVPROC __teGetSamplerParameterfv;
extern PFNGLGETSAMPLERPARAMETERIUIVPROC __teGetSamplerParameterIuiv;
extern PFNGLQUERYCOUNTERPROC __teQueryCounter;
extern PFNGLGETQUERYOBJECTI64VPROC __teGetQueryObjecti64v;
extern PFNGLGETQUERYOBJECTUI64VPROC __teGetQueryObjectui64v;
extern PFNGLVERTEXATTRIBDIVISORPROC __teVertexAttribDivisor;
extern PFNGLVERTEXATTRIBP1UIPROC __teVertexAttribP1ui;
extern PFNGLVERTEXATTRIBP1UIVPROC __teVertexAttribP1uiv;
extern PFNGLVERTEXATTRIBP2UIPROC __teVertexAttribP2ui;
extern PFNGLVERTEXATTRIBP2UIVPROC __teVertexAttribP2uiv;
extern PFNGLVERTEXATTRIBP3UIPROC __teVertexAttribP3ui;
extern PFNGLVERTEXATTRIBP3UIVPROC __teVertexAttribP3uiv;
extern PFNGLVERTEXATTRIBP4UIPROC __teVertexAttribP4ui;
extern PFNGLVERTEXATTRIBP4UIVPROC __teVertexAttribP4uiv;
extern PFNGLVERTEXP2UIPROC __teVertexP2ui;
extern PFNGLVERTEXP2UIVPROC __teVertexP2uiv;
extern PFNGLVERTEXP3UIPROC __teVertexP3ui;
extern PFNGLVERTEXP3UIVPROC __teVertexP3uiv;
extern PFNGLVERTEXP4UIPROC __teVertexP4ui;
extern PFNGLVERTEXP4UIVPROC __teVertexP4uiv;
extern PFNGLTEXCOORDP1UIPROC __teTexCoordP1ui;
extern PFNGLTEXCOORDP1UIVPROC __teTexCoordP1uiv;
extern PFNGLTEXCOORDP2UIPROC __teTexCoordP2ui;
extern PFNGLTEXCOORDP2UIVPROC __teTexCoordP2uiv;
extern PFNGLTEXCOORDP3UIPROC __teTexCoordP3ui;
extern PFNGLTEXCOORDP3UIVPROC __teTexCoordP3uiv;
extern PFNGLTEXCOORDP4UIPROC __teTexCoordP4ui;
extern PFNGLTEXCOORDP4UIVPROC __teTexCoordP4uiv;
extern PFNGLMULTITEXCOORDP1UIPROC __teMultiTexCoordP1ui;
extern PFNGLMULTITEXCOORDP1UIVPROC __teMultiTexCoordP1uiv;
extern PFNGLMULTITEXCOORDP2UIPROC __teMultiTexCoordP2ui;
extern PFNGLMULTITEXCOORDP2UIVPROC __teMultiTexCoordP2uiv;
extern PFNGLMULTITEXCOORDP3UIPROC __teMultiTexCoordP3ui;
extern PFNGLMULTITEXCOORDP3UIVPROC __teMultiTexCoordP3uiv;
extern PFNGLMULTITEXCOORDP4UIPROC __teMultiTexCoordP4ui;
extern PFNGLMULTITEXCOORDP4UIVPROC __teMultiTexCoordP4uiv;
extern PFNGLNORMALP3UIPROC __teNormalP3ui;
extern PFNGLNORMALP3UIVPROC __teNormalP3uiv;
extern PFNGLCOLORP3UIPROC __teColorP3ui;
extern PFNGLCOLORP3UIVPROC __teColorP3uiv;
extern PFNGLCOLORP4UIPROC __teColorP4ui;
extern PFNGLCOLORP4UIVPROC __teColorP4uiv;
extern PFNGLSECONDARYCOLORP3UIPROC __teSecondaryColorP3ui;
extern PFNGLSECONDARYCOLORP3UIVPROC __teSecondaryColorP3uiv;
#define glBindFragDataLocationIndexed GETFUNCTION(__teBindFragDataLocationIndexed)
#define glGetFragDataIndex GETFUNCTION(__teGetFragDataIndex)
#define glGenSamplers GETFUNCTION(__teGenSamplers)
#define glDeleteSamplers GETFUNCTION(__teDeleteSamplers)
#define glIsSampler GETFUNCTION(__teIsShader)
#define glBindSampler GETFUNCTION(__teBindSampler)
#define glSamplerParameteri GETFUNCTION(__teSamplerParameteri)
#define glSamplerParameteriv GETFUNCTION(__teSamplerParameteriv)
#define glSamplerParameterf GETFUNCTION(__teSamplerParameterf)
#define glSamplerParameterfv GETFUNCTION(__teSamplerParameterfv)
#define glSamplerParameterIiv GETFUNCTION(__teSamplerParameterIiv)
#define glSamplerParameterIuiv GETFUNCTION(__teSamplerParameterIuiv)
#define glGetSamplerParameteriv GETFUNCTION(__teGetSamplerParameteriv)
#define glGetSamplerParameterIiv GETFUNCTION(__teGetSamplerParameterIiv)
#define glGetSamplerParameterfv GETFUNCTION(__teGetSamplerParameterfv)
#define glGetSamplerParameterIuiv GETFUNCTION(__teGetSamplerParameterIuiv)
#define glQueryCounter GETFUNCTION(__teQueryCounter)
#define glGetQueryObjecti64v GETFUNCTION(__teGetQueryObjecti64v)
#define glGetQueryObjectui64v GETFUNCTION(__teGetQueryObjectui64v)
#define glVertexAttribDivisor GETFUNCTION(__teVertexAttribDivisor)
#define glVertexAttribP1ui GETFUNCTION(__teVertexAttribP1ui)
#define glVertexAttribP1uiv GETFUNCTION(__teVertexAttribP1uiv)
#define glVertexAttribP2ui GETFUNCTION(__teVertexAttribP2ui)
#define glVertexAttribP2uiv GETFUNCTION(__teVertexAttribP2uiv)
#define glVertexAttribP3ui GETFUNCTION(__teVertexAttribP3ui)
#define glVertexAttribP3uiv GETFUNCTION(__teVertexAttribP3uiv)
#define glVertexAttribP4ui GETFUNCTION(__teVertexAttribP4ui)
#define glVertexAttribP4uiv GETFUNCTION(__teVertexAttribP4uiv)
#define glVertexP2ui GETFUNCTION(__teVertexP2ui)
#define glVertexP2uiv GETFUNCTION(__teVertexP2uiv)
#define glVertexP3ui GETFUNCTION(__teVertexP3ui)
#define glVertexP3uiv GETFUNCTION(__teVertexP3uiv)
#define glVertexP4ui GETFUNCTION(__teVertexP4ui)
#define glVertexP4uiv GETFUNCTION(__teVertexP4uiv)
#define glTexCoordP1ui GETFUNCTION(__teTexCoordP1ui)
#define glTexCoordP1uiv GETFUNCTION(__teTexCoordP1uiv)
#define glTexCoordP2ui GETFUNCTION(__teTexCoordP2ui)
#define glTexCoordP2uiv GETFUNCTION(__teTexCoordP2uiv)
#define glTexCoordP3ui GETFUNCTION(__teTexCoordP3ui)
#define glTexCoordP3uiv GETFUNCTION(__teTexCoordP3uiv)
#define glTexCoordP4ui GETFUNCTION(__teTexCoordP4ui)
#define glTexCoordP4uiv GETFUNCTION(__teTexCoordP4uiv)
#define glMultiTexCoordP1ui GETFUNCTION(__teMultiTexCoordP1ui)
#define glMultiTexCoordP1uiv GETFUNCTION(__teMultiTexCoordP1uiv)
#define glMultiTexCoordP2ui GETFUNCTION(__teMultiTexCoordP2ui)
#define glMultiTexCoordP2uiv GETFUNCTION(__teMultiTexCoordP2uiv)
#define glMultiTexCoordP3ui GETFUNCTION(__teMultiTexCoordP3ui)
#define glMultiTexCoordP3uiv GETFUNCTION(__teMultiTexCoordP3uiv)
#define glMultiTexCoordP4ui GETFUNCTION(__teMultiTexCoordP4ui)
#define glMultiTexCoordP4uiv GETFUNCTION(__teMultiTexCoordP4uiv)
#define glNormalP3ui GETFUNCTION(__teNormalP3ui)
#define glNormalP3uiv GETFUNCTION(__teNormalP3uiv)
#define glColorP3ui GETFUNCTION(__teColorP3ui)
#define glColorP3uiv GETFUNCTION(__teColorP3uiv)
#define glColorP4ui GETFUNCTION(__teColorP4ui)
#define glColorP4uiv GETFUNCTION(__teColorP4uiv)
#define glSecondaryColorP3ui GETFUNCTION(__teSecondaryColorP3ui)
#define glSecondaryColorP3uiv GETFUNCTION(__teSecondaryColorP3uiv)

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
typedef void (*PFNGLMINSAMPLESHADINGPROC) (GLfloat value);
typedef void (*PFNGLBLENDEQUATIONIPROC) (GLuint buf, GLenum mode);
typedef void (*PFNGLBLENDEQUATIONSEPARATEIPROC) (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void (*PFNGLBLENDFUNCIPROC) (GLuint buf, GLenum src, GLenum dst);
typedef void (*PFNGLBLENDFUNCSEPARATEIPROC) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
typedef void (*PFNGLDRAWARRAYSINDIRECTPROC) (GLenum mode, const void *indirect);
typedef void (*PFNGLDRAWELEMENTSINDIRECTPROC) (GLenum mode, GLenum type, const void *indirect);
typedef void (*PFNGLUNIFORM1DPROC) (GLint location, GLdouble x);
typedef void (*PFNGLUNIFORM2DPROC) (GLint location, GLdouble x, GLdouble y);
typedef void (*PFNGLUNIFORM3DPROC) (GLint location, GLdouble x, GLdouble y, GLdouble z);
typedef void (*PFNGLUNIFORM4DPROC) (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (*PFNGLUNIFORM1DVPROC) (GLint location, GLsizei count, const GLdouble *value);
typedef void (*PFNGLUNIFORM2DVPROC) (GLint location, GLsizei count, const GLdouble *value);
typedef void (*PFNGLUNIFORM3DVPROC) (GLint location, GLsizei count, const GLdouble *value);
typedef void (*PFNGLUNIFORM4DVPROC) (GLint location, GLsizei count, const GLdouble *value);
typedef void (*PFNGLUNIFORMMATRIX2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (*PFNGLUNIFORMMATRIX3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (*PFNGLUNIFORMMATRIX4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (*PFNGLUNIFORMMATRIX2X3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (*PFNGLUNIFORMMATRIX2X4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (*PFNGLUNIFORMMATRIX3X2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (*PFNGLUNIFORMMATRIX3X4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (*PFNGLUNIFORMMATRIX4X2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (*PFNGLUNIFORMMATRIX4X3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (*PFNGLGETUNIFORMDVPROC) (GLuint program, GLint location, GLdouble *params);
typedef GLint(*PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC) (GLuint program, GLenum shadertype, const GLchar *name);
typedef GLuint(*PFNGLGETSUBROUTINEINDEXPROC) (GLuint program, GLenum shadertype, const GLchar *name);
typedef void (*PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC) (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
typedef void (*PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
typedef void (*PFNGLGETACTIVESUBROUTINENAMEPROC) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
typedef void (*PFNGLUNIFORMSUBROUTINESUIVPROC) (GLenum shadertype, GLsizei count, const GLuint *indices);
typedef void (*PFNGLGETUNIFORMSUBROUTINEUIVPROC) (GLenum shadertype, GLint location, GLuint *params);
typedef void (*PFNGLGETPROGRAMSTAGEIVPROC) (GLuint program, GLenum shadertype, GLenum pname, GLint *values);
typedef void (*PFNGLPATCHPARAMETERIPROC) (GLenum pname, GLint value);
typedef void (*PFNGLPATCHPARAMETERFVPROC) (GLenum pname, const GLfloat *values);
typedef void (*PFNGLBINDTRANSFORMFEEDBACKPROC) (GLenum target, GLuint id);
typedef void (*PFNGLDELETETRANSFORMFEEDBACKSPROC) (GLsizei n, const GLuint *ids);
typedef void (*PFNGLGENTRANSFORMFEEDBACKSPROC) (GLsizei n, GLuint *ids);
typedef GLboolean(*PFNGLISTRANSFORMFEEDBACKPROC) (GLuint id);
typedef void (*PFNGLPAUSETRANSFORMFEEDBACKPROC) (void);
typedef void (*PFNGLRESUMETRANSFORMFEEDBACKPROC) (void);
typedef void (*PFNGLDRAWTRANSFORMFEEDBACKPROC) (GLenum mode, GLuint id);
typedef void (*PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC) (GLenum mode, GLuint id, GLuint stream);
typedef void (*PFNGLBEGINQUERYINDEXEDPROC) (GLenum target, GLuint index, GLuint id);
typedef void (*PFNGLENDQUERYINDEXEDPROC) (GLenum target, GLuint index);
typedef void (*PFNGLGETQUERYINDEXEDIVPROC) (GLenum target, GLuint index, GLenum pname, GLint *params);
extern PFNGLMINSAMPLESHADINGPROC __teMinSampleShading;
extern PFNGLBLENDEQUATIONIPROC __teBlendEquationi;
extern PFNGLBLENDEQUATIONSEPARATEIPROC __teBlendEquationSeparatei;
extern PFNGLBLENDFUNCIPROC __teBlendFunci;
extern PFNGLBLENDFUNCSEPARATEIPROC __teBlendFuncSeparatei;
extern PFNGLDRAWARRAYSINDIRECTPROC __teDrawArraysIndirect;
extern PFNGLDRAWELEMENTSINDIRECTPROC __teDrawElementsIndirect;
extern PFNGLUNIFORM1DPROC __teUniform1d;
extern PFNGLUNIFORM2DPROC __teUniform2d;
extern PFNGLUNIFORM3DPROC __teUniform3d;
extern PFNGLUNIFORM4DPROC __teUniform4d;
extern PFNGLUNIFORM1DVPROC __teUniform1dv;
extern PFNGLUNIFORM2DVPROC __teUniform2dv;
extern PFNGLUNIFORM3DVPROC __teUniform3dv;
extern PFNGLUNIFORM4DVPROC __teUniform4dv;
extern PFNGLUNIFORMMATRIX2DVPROC __teUniformMatrix2dv;
extern PFNGLUNIFORMMATRIX3DVPROC __teUniformMatrix3dv;
extern PFNGLUNIFORMMATRIX4DVPROC __teUniformMatrix4dv;
extern PFNGLUNIFORMMATRIX2X3DVPROC __teUniformMatrix2x3dv;
extern PFNGLUNIFORMMATRIX2X4DVPROC __teUniformMatrix2x4dv;
extern PFNGLUNIFORMMATRIX3X2DVPROC __teUniformMatrix3x2dv;
extern PFNGLUNIFORMMATRIX3X4DVPROC __teUniformMatrix3x4dv;
extern PFNGLUNIFORMMATRIX4X2DVPROC __teUniformMatrix4x2dv;
extern PFNGLUNIFORMMATRIX4X3DVPROC __teUniformMatrix4x3dv;
extern PFNGLGETUNIFORMDVPROC __teGetUniformdv;
extern PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC __teGetSubroutineUniformLocation;
extern PFNGLGETSUBROUTINEINDEXPROC __teGetSubroutineIndex;
extern PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC __teGetActiveSubroutineUniformiv;
extern PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC __teGetActiveSubroutineUniformName;
extern PFNGLGETACTIVESUBROUTINENAMEPROC __teGetActiveSubroutineName;
extern PFNGLUNIFORMSUBROUTINESUIVPROC __teUniformSubroutinesuiv;
extern PFNGLGETUNIFORMSUBROUTINEUIVPROC __teGetUniformSubroutineuiv;
extern PFNGLGETPROGRAMSTAGEIVPROC __teGetProgramStageiv;
extern PFNGLPATCHPARAMETERIPROC __tePatchParameteri;
extern PFNGLPATCHPARAMETERFVPROC __tePatchParameterfv;
extern PFNGLBINDTRANSFORMFEEDBACKPROC __teBindTransformFeedback;
extern PFNGLDELETETRANSFORMFEEDBACKSPROC __teDeleteTransformFeedbacks;
extern PFNGLGENTRANSFORMFEEDBACKSPROC __teGenTransformFeedbacks;
extern PFNGLISTRANSFORMFEEDBACKPROC __teIsTransformFeedback;
extern PFNGLPAUSETRANSFORMFEEDBACKPROC __tePauseTransformFeedback;
extern PFNGLRESUMETRANSFORMFEEDBACKPROC __teResumeTransformFeedback;
extern PFNGLDRAWTRANSFORMFEEDBACKPROC __teDrawTransformFeedback;
extern PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC __teDrawTransformFeedbackStream;
extern PFNGLBEGINQUERYINDEXEDPROC __teBeginQueryIndexed;
extern PFNGLENDQUERYINDEXEDPROC __teEndQueryIndexed;
extern PFNGLGETQUERYINDEXEDIVPROC __teGetQueryIndexediv;
#define glMinSampleShading GETFUNCTION(__teMinSampleShading)
#define glBlendEquationi GETFUNCTION(__teBlendEquationi)
#define glBlendEquationSeparatei GETFUNCTION(__teBlendEquationSeparatei)
#define glBlendFunci GETFUNCTION(__teBlendFunci)
#define glBlendFuncSeparatei GETFUNCTION(__teBlendFuncSeparatei)
#define glDrawArraysIndirect GETFUNCTION(__teDrawArraysIndirect)
#define glDrawElementsIndirect GETFUNCTION(__teDrawElementsIndirect)
#define glUniform1d GETFUNCTION(__teUniform1d)
#define glUniform2d GETFUNCTION(__teUniform2d)
#define glUniform3d GETFUNCTION(__teUniform3d)
#define glUniform4d GETFUNCTION(__teUniform4d)
#define glUniform1dv GETFUNCTION(__teUniform1dv)
#define glUniform2dv GETFUNCTION(__teUniform2dv)
#define glUniform3dv GETFUNCTION(__teUniform3dv)
#define glUniform4dv GETFUNCTION(__teUniform4dv)
#define glUniformMatrix2dv GETFUNCTION(__teUniformMatrix2dv)
#define glUniformMatrix3dv GETFUNCTION(__teUniformMatrix3dv)
#define glUniformMatrix4dv GETFUNCTION(__teUniformMatrix4dv)
#define glUniformMatrix2x3dv GETFUNCTION(__teUniformMatrix2x3dv)
#define glUniformMatrix2x4dv GETFUNCTION(__teUniformMatrix2x4dv)
#define glUniformMatrix3x2dv GETFUNCTION(__teUniformMatrix3x2dv)
#define glUniformMatrix3x4dv GETFUNCTION(__teUniformMatrix3x4dv)
#define glUniformMatrix4x2dv GETFUNCTION(__teUniformMatrix4x2dv)
#define glUniformMatrix4x3dv GETFUNCTION(__teUniformMatrix4x3dv)
#define glGetUniformdv GETFUNCTION(__teGetUniformdv)
#define glGetSubroutineUniformLocation GETFUNCTION(__teGetSubroutineUniformLocation)
#define glGetSubroutineIndex GETFUNCTION(__teGetSubroutineIndex)
#define glGetActiveSubroutineUniformiv GETFUNCTION(__teGetActiveSubroutineUniformiv)
#define glGetActiveSubroutineUniformName GETFUNCTION(__teGetActiveSubroutineUniformName)
#define glGetActiveSubroutineName GETFUNCTION(__teGetActiveSubroutineName)
#define glUniformSubroutinesuiv GETFUNCTION(__teUniformSubroutinesuiv)
#define glGetUniformSubroutineuiv GETFUNCTION(__teGetUniformSubroutineuiv)
#define glGetProgramStageiv GETFUNCTION(__teGetProgramStageiv)
#define glPatchParameteri GETFUNCTION(__tePatchParameteri)
#define glPatchParameterfv GETFUNCTION(__tePatchParameterfv)
#define glBindTransformFeedback GETFUNCTION(__teBindTransformFeedback)
#define glDeleteTransformFeedbacks GETFUNCTION(__teDeleteTransformFeedbacks)
#define glGenTransformFeedbacks GETFUNCTION(__teGenTransformFeedbacks)
#define glIsTransformFeedback GETFUNCTION(__teIsTransformFeedback)
#define glPauseTransformFeedback GETFUNCTION(__tePauseTransformFeedback)
#define glResumeTransformFeedback GETFUNCTION(__teResumeTransformFeedback)
#define glDrawTransformFeedback GETFUNCTION(__teDrawTransformFeedback)
#define glDrawTransformFeedbackStream GETFUNCTION(__teDrawTransformFeedbackStream)
#define glBeginQueryIndexed GETFUNCTION(__teBeginQueryIndexed)
#define glEndQueryIndexed GETFUNCTION(__teEndQueryIndexed)
#define glGetQueryIndexediv GETFUNCTION(__teGetQueryIndexediv)

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
typedef void (*PFNGLRELEASESHADERCOMPILERPROC) (void);
typedef void (*PFNGLSHADERBINARYPROC) (GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length);
typedef void (*PFNGLGETSHADERPRECISIONFORMATPROC) (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
typedef void (*PFNGLDEPTHRANGEFPROC) (GLfloat n, GLfloat f);
typedef void (*PFNGLCLEARDEPTHFPROC) (GLfloat d);
typedef void (*PFNGLGETPROGRAMBINARYPROC) (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
typedef void (*PFNGLPROGRAMBINARYPROC) (GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
typedef void (*PFNGLPROGRAMPARAMETERIPROC) (GLuint program, GLenum pname, GLint value);
typedef void (*PFNGLUSEPROGRAMSTAGESPROC) (GLuint pipeline, GLbitfield stages, GLuint program);
typedef void (*PFNGLACTIVESHADERPROGRAMPROC) (GLuint pipeline, GLuint program);
typedef GLuint(*PFNGLCREATESHADERPROGRAMVPROC) (GLenum type, GLsizei count, const GLchar *const*strings);
typedef void (*PFNGLBINDPROGRAMPIPELINEPROC) (GLuint pipeline);
typedef void (*PFNGLDELETEPROGRAMPIPELINESPROC) (GLsizei n, const GLuint *pipelines);
typedef void (*PFNGLGENPROGRAMPIPELINESPROC) (GLsizei n, GLuint *pipelines);
typedef GLboolean(*PFNGLISPROGRAMPIPELINEPROC) (GLuint pipeline);
typedef void (*PFNGLGETPROGRAMPIPELINEIVPROC) (GLuint pipeline, GLenum pname, GLint *params);
typedef void (*PFNGLPROGRAMUNIFORM1IPROC) (GLuint program, GLint location, GLint v0);
typedef void (*PFNGLPROGRAMUNIFORM1IVPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (*PFNGLPROGRAMUNIFORM1FPROC) (GLuint program, GLint location, GLfloat v0);
typedef void (*PFNGLPROGRAMUNIFORM1FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (*PFNGLPROGRAMUNIFORM1DPROC) (GLuint program, GLint location, GLdouble v0);
typedef void (*PFNGLPROGRAMUNIFORM1DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (*PFNGLPROGRAMUNIFORM1UIPROC) (GLuint program, GLint location, GLuint v0);
typedef void (*PFNGLPROGRAMUNIFORM1UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (*PFNGLPROGRAMUNIFORM2IPROC) (GLuint program, GLint location, GLint v0, GLint v1);
typedef void (*PFNGLPROGRAMUNIFORM2IVPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (*PFNGLPROGRAMUNIFORM2FPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1);
typedef void (*PFNGLPROGRAMUNIFORM2FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (*PFNGLPROGRAMUNIFORM2DPROC) (GLuint program, GLint location, GLdouble v0, GLdouble v1);
typedef void (*PFNGLPROGRAMUNIFORM2DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (*PFNGLPROGRAMUNIFORM2UIPROC) (GLuint program, GLint location, GLuint v0, GLuint v1);
typedef void (*PFNGLPROGRAMUNIFORM2UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (*PFNGLPROGRAMUNIFORM3IPROC) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
typedef void (*PFNGLPROGRAMUNIFORM3IVPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (*PFNGLPROGRAMUNIFORM3FPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (*PFNGLPROGRAMUNIFORM3FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (*PFNGLPROGRAMUNIFORM3DPROC) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
typedef void (*PFNGLPROGRAMUNIFORM3DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (*PFNGLPROGRAMUNIFORM3UIPROC) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (*PFNGLPROGRAMUNIFORM3UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (*PFNGLPROGRAMUNIFORM4IPROC) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (*PFNGLPROGRAMUNIFORM4IVPROC) (GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (*PFNGLPROGRAMUNIFORM4FPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (*PFNGLPROGRAMUNIFORM4FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (*PFNGLPROGRAMUNIFORM4DPROC) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
typedef void (*PFNGLPROGRAMUNIFORM4DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (*PFNGLPROGRAMUNIFORM4UIPROC) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (*PFNGLPROGRAMUNIFORM4UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (*PFNGLPROGRAMUNIFORMMATRIX2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*PFNGLPROGRAMUNIFORMMATRIX3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*PFNGLPROGRAMUNIFORMMATRIX4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*PFNGLPROGRAMUNIFORMMATRIX2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (*PFNGLPROGRAMUNIFORMMATRIX3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (*PFNGLPROGRAMUNIFORMMATRIX4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (*PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (*PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (*PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (*PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (*PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (*PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (*PFNGLVALIDATEPROGRAMPIPELINEPROC) (GLuint pipeline);
typedef void (*PFNGLGETPROGRAMPIPELINEINFOLOGPROC) (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (*PFNGLVERTEXATTRIBL1DPROC) (GLuint index, GLdouble x);
typedef void (*PFNGLVERTEXATTRIBL2DPROC) (GLuint index, GLdouble x, GLdouble y);
typedef void (*PFNGLVERTEXATTRIBL3DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (*PFNGLVERTEXATTRIBL4DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (*PFNGLVERTEXATTRIBL1DVPROC) (GLuint index, const GLdouble *v);
typedef void (*PFNGLVERTEXATTRIBL2DVPROC) (GLuint index, const GLdouble *v);
typedef void (*PFNGLVERTEXATTRIBL3DVPROC) (GLuint index, const GLdouble *v);
typedef void (*PFNGLVERTEXATTRIBL4DVPROC) (GLuint index, const GLdouble *v);
typedef void (*PFNGLVERTEXATTRIBLPOINTERPROC) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (*PFNGLGETVERTEXATTRIBLDVPROC) (GLuint index, GLenum pname, GLdouble *params);
typedef void (*PFNGLVIEWPORTARRAYVPROC) (GLuint first, GLsizei count, const GLfloat *v);
typedef void (*PFNGLVIEWPORTINDEXEDFPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
typedef void (*PFNGLVIEWPORTINDEXEDFVPROC) (GLuint index, const GLfloat *v);
typedef void (*PFNGLSCISSORARRAYVPROC) (GLuint first, GLsizei count, const GLint *v);
typedef void (*PFNGLSCISSORINDEXEDPROC) (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
typedef void (*PFNGLSCISSORINDEXEDVPROC) (GLuint index, const GLint *v);
typedef void (*PFNGLDEPTHRANGEARRAYVPROC) (GLuint first, GLsizei count, const GLdouble *v);
typedef void (*PFNGLDEPTHRANGEINDEXEDPROC) (GLuint index, GLdouble n, GLdouble f);
typedef void (*PFNGLGETFLOATI_VPROC) (GLenum target, GLuint index, GLfloat *data);
typedef void (*PFNGLGETDOUBLEI_VPROC) (GLenum target, GLuint index, GLdouble *data);
extern PFNGLRELEASESHADERCOMPILERPROC __teReleaseShaderCompiler;
extern PFNGLSHADERBINARYPROC __teShaderBinary;
extern PFNGLGETSHADERPRECISIONFORMATPROC __teGetShaderPrecisionFormat;
extern PFNGLDEPTHRANGEFPROC __teDepthRangef;
extern PFNGLCLEARDEPTHFPROC __teClearDepthf;
extern PFNGLGETPROGRAMBINARYPROC __teGetProgramBinary;
extern PFNGLPROGRAMBINARYPROC __teProgramBinary;
extern PFNGLPROGRAMPARAMETERIPROC __teProgramParameteri;
extern PFNGLUSEPROGRAMSTAGESPROC __teUseProgramStages;
extern PFNGLACTIVESHADERPROGRAMPROC __teActiveShaderProgram;
extern PFNGLCREATESHADERPROGRAMVPROC __teCreateShaderProgramv;
extern PFNGLBINDPROGRAMPIPELINEPROC __teBindProgramPipeline;
extern PFNGLDELETEPROGRAMPIPELINESPROC __teDeleteProgramPipelines;
extern PFNGLGENPROGRAMPIPELINESPROC __teGenProgramPipelines;
extern PFNGLISPROGRAMPIPELINEPROC __teIsProgramPipeline;
extern PFNGLGETPROGRAMPIPELINEIVPROC __teGetProgramPipelineiv;
extern PFNGLPROGRAMUNIFORM1IPROC __teProgramUniform1i;
extern PFNGLPROGRAMUNIFORM1IVPROC __teProgramUniform1iv;
extern PFNGLPROGRAMUNIFORM1FPROC __teProgramUniform1f;
extern PFNGLPROGRAMUNIFORM1FVPROC __teProgramUniform1fv;
extern PFNGLPROGRAMUNIFORM1DPROC __teProgramUniform1d;
extern PFNGLPROGRAMUNIFORM1DVPROC __teProgramUniform1dv;
extern PFNGLPROGRAMUNIFORM1UIPROC __teProgramUniform1ui;
extern PFNGLPROGRAMUNIFORM1UIVPROC __teProgramUniform1uiv;
extern PFNGLPROGRAMUNIFORM2IPROC __teProgramUniform2i;
extern PFNGLPROGRAMUNIFORM2IVPROC __teProgramUniform2iv;
extern PFNGLPROGRAMUNIFORM2FPROC __teProgramUniform2f;
extern PFNGLPROGRAMUNIFORM2FVPROC __teProgramUniform2fv;
extern PFNGLPROGRAMUNIFORM2DPROC __teProgramUniform2d;
extern PFNGLPROGRAMUNIFORM2DVPROC __teProgramUniform2dv;
extern PFNGLPROGRAMUNIFORM2UIPROC __teProgramUniform2ui;
extern PFNGLPROGRAMUNIFORM2UIVPROC __teProgramUniform2uiv;
extern PFNGLPROGRAMUNIFORM3IPROC __teProgramUniform3i;
extern PFNGLPROGRAMUNIFORM3IVPROC __teProgramUniform3iv;
extern PFNGLPROGRAMUNIFORM3FPROC __teProgramUniform3f;
extern PFNGLPROGRAMUNIFORM3FVPROC __teProgramUniform3fv;
extern PFNGLPROGRAMUNIFORM3DPROC __teProgramUniform3d;
extern PFNGLPROGRAMUNIFORM3DVPROC __teProgramUniform3dv;
extern PFNGLPROGRAMUNIFORM3UIPROC __teProgramUniform3ui;
extern PFNGLPROGRAMUNIFORM3UIVPROC __teProgramUniform3uiv;
extern PFNGLPROGRAMUNIFORM4IPROC __teProgramUniform4i;
extern PFNGLPROGRAMUNIFORM4IVPROC __teProgramUniform4iv;
extern PFNGLPROGRAMUNIFORM4FPROC __teProgramUniform4f;
extern PFNGLPROGRAMUNIFORM4FVPROC __teProgramUniform4fv;
extern PFNGLPROGRAMUNIFORM4DPROC __teProgramUniform4d;
extern PFNGLPROGRAMUNIFORM4DVPROC __teProgramUniform4dv;
extern PFNGLPROGRAMUNIFORM4UIPROC __teProgramUniform4ui;
extern PFNGLPROGRAMUNIFORM4UIVPROC __teProgramUniform4uiv;
extern PFNGLPROGRAMUNIFORMMATRIX2FVPROC __teProgramUniformMatrix2fv;
extern PFNGLPROGRAMUNIFORMMATRIX3FVPROC __teProgramUniformMatrix3fv;
extern PFNGLPROGRAMUNIFORMMATRIX4FVPROC __teProgramUniformMatrix4fv;
extern PFNGLPROGRAMUNIFORMMATRIX2DVPROC __teProgramUniformMatrix2dv;
extern PFNGLPROGRAMUNIFORMMATRIX3DVPROC __teProgramUniformMatrix3dv;
extern PFNGLPROGRAMUNIFORMMATRIX4DVPROC __teProgramUniformMatrix4dv;
extern PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC __teProgramUniformMatrix2x3fv;
extern PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC __teProgramUniformMatrix3x2fv;
extern PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC __teProgramUniformMatrix2x4fv;
extern PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC __teProgramUniformMatrix4x2fv;
extern PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC __teProgramUniformMatrix3x4fv;
extern PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC __teProgramUniformMatrix4x3fv;
extern PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC __teProgramUniformMatrix2x3dv;
extern PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC __teProgramUniformMatrix3x2dv;
extern PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC __teProgramUniformMatrix2x4dv;
extern PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC __teProgramUniformMatrix4x2dv;
extern PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC __teProgramUniformMatrix3x4dv;
extern PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC __teProgramUniformMatrix4x3dv;
extern PFNGLVALIDATEPROGRAMPIPELINEPROC __teValidateProgramPipeline;
extern PFNGLGETPROGRAMPIPELINEINFOLOGPROC __teGetProgramPipelineInfoLog;
extern PFNGLVERTEXATTRIBL1DPROC __teVertexAttribL1d;
extern PFNGLVERTEXATTRIBL2DPROC __teVertexAttribL2d;
extern PFNGLVERTEXATTRIBL3DPROC __teVertexAttribL3d;
extern PFNGLVERTEXATTRIBL4DPROC __teVertexAttribL4d;
extern PFNGLVERTEXATTRIBL1DVPROC __teVertexAttribL1dv;
extern PFNGLVERTEXATTRIBL2DVPROC __teVertexAttribL2dv;
extern PFNGLVERTEXATTRIBL3DVPROC __teVertexAttribL3dv;
extern PFNGLVERTEXATTRIBL4DVPROC __teVertexAttribL4dv;
extern PFNGLVERTEXATTRIBLPOINTERPROC __teVertexAttribLPointer;
extern PFNGLGETVERTEXATTRIBLDVPROC __teGetVertexAttribLdv;
extern PFNGLVIEWPORTARRAYVPROC __teViewportArrayv;
extern PFNGLVIEWPORTINDEXEDFPROC __teViewportIndexedf;
extern PFNGLVIEWPORTINDEXEDFVPROC __teViewportIndexedfv;
extern PFNGLVIEWPORTARRAYVPROC __teViewportArrayv;
extern PFNGLSCISSORARRAYVPROC __teScissorArrayv;
extern PFNGLSCISSORINDEXEDPROC __teScissorIndexed;
extern PFNGLSCISSORINDEXEDVPROC __teScissorIndexedv;
extern PFNGLDEPTHRANGEARRAYVPROC __teDepthRangeArrayv;
extern PFNGLDEPTHRANGEINDEXEDPROC __teDepthRangeIndexed;
extern PFNGLGETFLOATI_VPROC __teGetFloati_v;
extern PFNGLGETDOUBLEI_VPROC __teGetDoublei_v;
#define glReleaseShaderCompiler GETFUNCTION(__teReleaseShaderCompiler)
#define glShaderBinary GETFUNCTION(__teShaderBinary)
#define glGetShaderPrecisionFormat GETFUNCTION(__teGetShaderPrecisionFormat)
#define glDepthRangef GETFUNCTION(__teDepthRangef)
#define glClearDepthf GETFUNCTION(__teClearDepthf)
#define glGetProgramBinary GETFUNCTION(__teGetProgramBinary)
#define glProgramBinary GETFUNCTION(__teProgramBinary)
#define glProgramParameteri GETFUNCTION(__teProgramParameteri)
#define glUseProgramStages GETFUNCTION(__teUseProgramStages)
#define glActiveShaderProgram GETFUNCTION(__teActiveShaderProgram)
#define glCreateShaderProgramv GETFUNCTION(__teCreateShaderProgramv)
#define glBindProgramPipeline GETFUNCTION(__teBindProgramPipeline)
#define glDeleteProgramPipelines GETFUNCTION(__teDeleteProgramPipelines)
#define glGenProgramPipelines GETFUNCTION(__teGenProgramPipelines)
#define glIsProgramPipeline GETFUNCTION(__teIsProgramPipeline)
#define glGetProgramPipelineiv GETFUNCTION(__teGetProgramPipelineiv)
#define glProgramUniform1i GETFUNCTION(__teProgramUniform1i)
#define glProgramUniform1iv GETFUNCTION(__teProgramUniform1iv)
#define glProgramUniform1f GETFUNCTION(__teProgramUniform1f)
#define glProgramUniform1fv GETFUNCTION(__teProgramUniform1fv)
#define glProgramUniform1d GETFUNCTION(__teProgramUniform1d)
#define glProgramUniform1dv GETFUNCTION(__teProgramUniform1dv)
#define glProgramUniform1ui GETFUNCTION(__teProgramUniform1ui)
#define glProgramUniform1uiv GETFUNCTION(__teProgramUniform1uiv)
#define glProgramUniform2i GETFUNCTION(__teProgramUniform2i)
#define glProgramUniform2iv GETFUNCTION(__teProgramUniform2iv)
#define glProgramUniform2f GETFUNCTION(__teProgramUniform2f)
#define glProgramUniform2fv GETFUNCTION(__teProgramUniform2fv)
#define glProgramUniform2d GETFUNCTION(__teProgramUniform2d)
#define glProgramUniform2dv GETFUNCTION(__teProgramUniform2dv)
#define glProgramUniform2ui GETFUNCTION(__teProgramUniform2ui)
#define glProgramUniform2uiv GETFUNCTION(__teProgramUniform2uiv)
#define glProgramUniform3i GETFUNCTION(__teProgramUniform3i)
#define glProgramUniform3iv GETFUNCTION(__teProgramUniform3iv)
#define glProgramUniform3f GETFUNCTION(__teProgramUniform3f)
#define glProgramUniform3fv GETFUNCTION(__teProgramUniform3fv)
#define glProgramUniform3d GETFUNCTION(__teProgramUniform3d)
#define glProgramUniform3dv GETFUNCTION(__teProgramUniform3dv)
#define glProgramUniform3ui GETFUNCTION(__teProgramUniform3ui)
#define glProgramUniform3uiv GETFUNCTION(__teProgramUniform3uiv)
#define glProgramUniform4i GETFUNCTION(__teProgramUniform4i)
#define glProgramUniform4iv GETFUNCTION(__teProgramUniform4iv)
#define glProgramUniform4f GETFUNCTION(__teProgramUniform4f)
#define glProgramUniform4fv GETFUNCTION(__teProgramUniform4fv)
#define glProgramUniform4d GETFUNCTION(__teProgramUniform4d)
#define glProgramUniform4dv GETFUNCTION(__teProgramUniform4dv)
#define glProgramUniform4ui GETFUNCTION(__teProgramUniform4ui)
#define glProgramUniform4uiv GETFUNCTION(__teProgramUniform4uiv)
#define glProgramUniformMatrix2fv GETFUNCTION(__teProgramUniformMatrix2fv)
#define glProgramUniformMatrix3fv GETFUNCTION(__teProgramUniformMatrix2fv)
#define glProgramUniformMatrix4fv GETFUNCTION(__teProgramUniformMatrix2fv)
#define glProgramUniformMatrix2dv GETFUNCTION(__teProgramUniformMatrix2dv)
#define glProgramUniformMatrix3dv GETFUNCTION(__teProgramUniformMatrix3dv)
#define glProgramUniformMatrix4dv GETFUNCTION(__teProgramUniformMatrix4dv)
#define glProgramUniformMatrix2x3fv GETFUNCTION(__teProgramUniformMatrix2x3fv)
#define glProgramUniformMatrix3x2fv GETFUNCTION(__teProgramUniformMatrix3x2fv)
#define glProgramUniformMatrix2x4fv GETFUNCTION(__teProgramUniformMatrix2x4fv)
#define glProgramUniformMatrix4x2fv GETFUNCTION(__teProgramUniformMatrix4x2fv)
#define glProgramUniformMatrix3x4fv GETFUNCTION(__teProgramUniformMatrix3x4fv)
#define glProgramUniformMatrix4x3fv GETFUNCTION(__teProgramUniformMatrix4x3fv)
#define glProgramUniformMatrix2x3dv GETFUNCTION(__teProgramUniformMatrix2x3dv)
#define glProgramUniformMatrix3x2dv GETFUNCTION(__teProgramUniformMatrix3x2dv)
#define glProgramUniformMatrix2x4dv GETFUNCTION(__teProgramUniformMatrix2x4dv)
#define glProgramUniformMatrix4x2dv GETFUNCTION(__teProgramUniformMatrix4x2dv)
#define glProgramUniformMatrix3x4dv GETFUNCTION(__teProgramUniformMatrix3x2dv)
#define glProgramUniformMatrix4x3dv GETFUNCTION(__teProgramUniformMatrix4x3dv)
#define glValidateProgramPipeline GETFUNCTION(__teValidateProgramPipeline)
#define glGetProgramPipelineInfoLog GETFUNCTION(__teGetProgramPipelineInfoLog)
#define glVertexAttribL1d GETFUNCTION(__teVertexAttribL1d)
#define glVertexAttribL2d GETFUNCTION(__teVertexAttribL2d)
#define glVertexAttribL3d GETFUNCTION(__teVertexAttribL3d)
#define glVertexAttribL4d GETFUNCTION(__teVertexAttribL4d)
#define glVertexAttribL1dv GETFUNCTION(__teVertexAttribL1dv)
#define glVertexAttribL2dv GETFUNCTION(__teVertexAttribL2dv)
#define glVertexAttribL3dv GETFUNCTION(__teVertexAttribL3dv)
#define glVertexAttribL4dv GETFUNCTION(__teVertexAttribL4dv)
#define glVertexAttribLPointer GETFUNCTION(__teVertexAttribLPointer)
#define glGetVertexAttribLdv GETFUNCTION(__teGetVertexAttribLdv)
#define glViewportarrayv GETFUNCTION(__teViewportArrayv)
#define glViewportIndexedf GETFUNCTION(__teViewportIndexedf)
#define glViewportIndexedfv GETFUNCTION(__teViewportIndexedfv)
#define glScissorArrayv GETFUNCTION(__teScissorArrayv)
#define glScissorIndexed GETFUNCTION(__teScissorIndexed)
#define glScissorIndexedv GETFUNCTION(__teScissorIndexedv)
#define glDepthRangeIndexed GETFUNCTION(__teDepthRangeIndexed)
#define glDepthRangeArrayv GETFUNCTION(__teDepthRangeArrayv)
#define glGetFloati_v GETFUNCTION(__teGetFloati_v)
#define glGetDoublei_v GETFUNCTION(__teGetDoublei_v)

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
typedef void (*PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
typedef void (*PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
typedef void (*PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
typedef void (*PFNGLGETINTERNALFORMATIVPROC) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);
typedef void (*PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC) (GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
typedef void (*PFNGLBINDIMAGETEXTUREPROC) (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
typedef void (*PFNGLMEMORYBARRIERPROC) (GLbitfield barriers);
typedef void (*PFNGLTEXSTORAGE1DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (*PFNGLTEXSTORAGE2DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (*PFNGLTEXSTORAGE3DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (*PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC) (GLenum mode, GLuint id, GLsizei instancecount);
typedef void (*PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC) (GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
extern PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC __teDrawArraysInstancedBaseInstance;
extern PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC __teDrawElementsInstancedBaseInstance;
extern PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC __teDrawElementsInstancedBaseVertexBaseInstance;
extern PFNGLGETINTERNALFORMATIVPROC __teGetInternalformativ;
extern PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC __teGetActiveAtomicCounterBufferiv;
extern PFNGLBINDIMAGETEXTUREPROC __teBindImageTexture;
extern PFNGLMEMORYBARRIERPROC __teMemoryBarrier;
extern PFNGLTEXSTORAGE1DPROC __teTexStorage1D;
extern PFNGLTEXSTORAGE2DPROC __teTexStorage2D;
extern PFNGLTEXSTORAGE3DPROC __teTexStorage3D;
extern PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC __teDrawTransformFeedbackInstanced;
extern PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC __teDrawTransformFeedbackStreamInstanced;
#define glDrawArraysInstancedBaseInstance GETFUNCTION(__teDrawArraysInstancedBaseInstance)
#define glDrawElementsInstancedBaseInstance GETFUNCTION(__teDrawElementsInstancedBaseInstance)
#define glDrawElementsInstancedBaseVertexBaseInstance GETFUNCTION(__teDrawElementsInstancedBaseVertexBaseInstance)
#define glGetInternalformativ GETFUNCTION(__teGetInternalformativ)
#define glGetActiveAtomicCounterBufferiv GETFUNCTION(__teGetActiveAtomicCounterBufferiv)
#define glBindImageTexture GETFUNCTION(__teBindImageTexture)
#define glMemoryBarrier GETFUNCTION(__teMemoryBarrier)
#define glTexStorage1D GETFUNCTION(__teTexStorage1D)
#define glTexStorage2D GETFUNCTION(__teTexStorage2D)
#define glTexStorage3D GETFUNCTION(__teTexStorage3D)
#define glDrawTransformFeedbackInstanced GETFUNCTION(__teDrawTransformFeedbackInstanced)
#define glDrawTransformFeedbackStreamInstanced GETFUNCTION(__teDrawTransformFeedbackStreamInstanced)

//OpenGL 4.3 Extensions
typedef void (APIENTRY  *GLDEBUGPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);
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
typedef void (*PFNGLCLEARBUFFERDATAPROC) (GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
typedef void (*PFNGLCLEARBUFFERSUBDATAPROC) (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
typedef void (*PFNGLDISPATCHCOMPUTEPROC) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
typedef void (*PFNGLDISPATCHCOMPUTEINDIRECTPROC) (GLintptr indirect);
typedef void (*PFNGLCOPYIMAGESUBDATAPROC) (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
typedef void (*PFNGLFRAMEBUFFERPARAMETERIPROC) (GLenum target, GLenum pname, GLint param);
typedef void (*PFNGLGETFRAMEBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (*PFNGLGETINTERNALFORMATI64VPROC) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params);
typedef void (*PFNGLINVALIDATETEXSUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
typedef void (*PFNGLINVALIDATETEXIMAGEPROC) (GLuint texture, GLint level);
typedef void (*PFNGLINVALIDATEBUFFERSUBDATAPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (*PFNGLINVALIDATEBUFFERDATAPROC) (GLuint buffer);
typedef void (*PFNGLINVALIDATEFRAMEBUFFERPROC) (GLenum target, GLsizei numAttachments, const GLenum *attachments);
typedef void (*PFNGLINVALIDATESUBFRAMEBUFFERPROC) (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (*PFNGLMULTIDRAWARRAYSINDIRECTPROC) (GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
typedef void (*PFNGLMULTIDRAWELEMENTSINDIRECTPROC) (GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
typedef void (*PFNGLGETPROGRAMINTERFACEIVPROC) (GLuint program, GLenum programInterface, GLenum pname, GLint *params);
typedef GLuint(*PFNGLGETPROGRAMRESOURCEINDEXPROC) (GLuint program, GLenum programInterface, const GLchar *name);
typedef void (*PFNGLGETPROGRAMRESOURCENAMEPROC) (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
typedef void (*PFNGLGETPROGRAMRESOURCEIVPROC) (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params);
typedef GLint(*PFNGLGETPROGRAMRESOURCELOCATIONPROC) (GLuint program, GLenum programInterface, const GLchar *name);
typedef GLint(*PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC) (GLuint program, GLenum programInterface, const GLchar *name);
typedef void (*PFNGLSHADERSTORAGEBLOCKBINDINGPROC) (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
typedef void (*PFNGLTEXBUFFERRANGEPROC) (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (*PFNGLTEXSTORAGE2DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (*PFNGLTEXSTORAGE3DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (*PFNGLTEXTUREVIEWPROC) (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
typedef void (*PFNGLBINDVERTEXBUFFERPROC) (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (*PFNGLVERTEXATTRIBFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (*PFNGLVERTEXATTRIBIFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (*PFNGLVERTEXATTRIBLFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (*PFNGLVERTEXATTRIBBINDINGPROC) (GLuint attribindex, GLuint bindingindex);
typedef void (*PFNGLVERTEXBINDINGDIVISORPROC) (GLuint bindingindex, GLuint divisor);
typedef void (*PFNGLDEBUGMESSAGECONTROLPROC) (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
typedef void (*PFNGLDEBUGMESSAGEINSERTPROC) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
typedef void (*PFNGLDEBUGMESSAGECALLBACKPROC) (GLDEBUGPROC callback, const void *userParam);
typedef GLuint(*PFNGLGETDEBUGMESSAGELOGPROC) (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
typedef void (*PFNGLPUSHDEBUGGROUPPROC) (GLenum source, GLuint id, GLsizei length, const GLchar *message);
typedef void (*PFNGLPOPDEBUGGROUPPROC) (void);
typedef void (*PFNGLOBJECTLABELPROC) (GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
typedef void (*PFNGLGETOBJECTLABELPROC) (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
typedef void (*PFNGLOBJECTPTRLABELPROC) (const void *ptr, GLsizei length, const GLchar *label);
typedef void (*PFNGLGETOBJECTPTRLABELPROC) (const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
extern PFNGLCLEARBUFFERDATAPROC __teClearBufferData;
extern PFNGLCLEARBUFFERSUBDATAPROC __teClearBufferSubData;
extern PFNGLDISPATCHCOMPUTEPROC __teDispatchCompute;
extern PFNGLDISPATCHCOMPUTEINDIRECTPROC __teDispatchComputeIndirect;
extern PFNGLCOPYIMAGESUBDATAPROC  __teCopyImageSubData;
extern PFNGLFRAMEBUFFERPARAMETERIPROC __teFramebufferParameteri;
extern PFNGLGETFRAMEBUFFERPARAMETERIVPROC __teGetFramebufferParameteriv;
extern PFNGLGETINTERNALFORMATI64VPROC __teGetInternalformati64v;
extern PFNGLINVALIDATETEXSUBIMAGEPROC __teInvalidateTexSubImage;
extern PFNGLINVALIDATETEXIMAGEPROC __teInvalidateTexImage;
extern PFNGLINVALIDATEBUFFERSUBDATAPROC __teInvalidateBufferSubData;
extern PFNGLINVALIDATEBUFFERDATAPROC __teInvalidateBufferData;
extern PFNGLINVALIDATEFRAMEBUFFERPROC __teInvalidateFramebuffer;
extern PFNGLINVALIDATESUBFRAMEBUFFERPROC __teInvalidateSubFramebuffer;
extern PFNGLMULTIDRAWARRAYSINDIRECTPROC __teMultiDrawArraysIndirect;
extern PFNGLMULTIDRAWELEMENTSINDIRECTPROC __teMultiDrawElementsIndirect;
extern PFNGLGETPROGRAMINTERFACEIVPROC __teGetProgramInterfaceiv;
extern PFNGLGETPROGRAMRESOURCEINDEXPROC __teGetProgramResourceIndex;
extern PFNGLGETPROGRAMRESOURCENAMEPROC __teGetProgramResourceName;
extern PFNGLGETPROGRAMRESOURCEIVPROC __teGetProgramResourceiv;
extern PFNGLGETPROGRAMRESOURCELOCATIONPROC __teGetProgramResourceLocation;
extern PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC __teGetProgramResourceLocationIndex;
extern PFNGLSHADERSTORAGEBLOCKBINDINGPROC __teShaderStorageBlockBinding;
extern PFNGLTEXBUFFERRANGEPROC __teTexBufferRange;
extern PFNGLTEXSTORAGE2DMULTISAMPLEPROC __teTexStorage2DMultisample;
extern PFNGLTEXSTORAGE3DMULTISAMPLEPROC __teTexStorage3DMultisample;
extern PFNGLTEXTUREVIEWPROC __teTextureView;
extern PFNGLBINDVERTEXBUFFERPROC __teBindVertexBuffer;
extern PFNGLVERTEXATTRIBFORMATPROC __teVertexAttribFormat;
extern PFNGLVERTEXATTRIBIFORMATPROC __teVertexAttribIFormat;
extern PFNGLVERTEXATTRIBLFORMATPROC __teVertexAttribLFormat;
extern PFNGLVERTEXATTRIBBINDINGPROC __teVertexAttribBinding;
extern PFNGLVERTEXBINDINGDIVISORPROC __teVertexBindingDivisor;
extern PFNGLDEBUGMESSAGECONTROLPROC __teDebugMessageControl;
extern PFNGLDEBUGMESSAGEINSERTPROC __teDebugMessageInsert;
extern PFNGLDEBUGMESSAGECALLBACKPROC __teDebugMessageCallback;
extern PFNGLGETDEBUGMESSAGELOGPROC __teGetDebugMessageLog;
extern PFNGLPUSHDEBUGGROUPPROC __tePushDebugGroup;
extern PFNGLPOPDEBUGGROUPPROC __tePopDebugGroup;
extern PFNGLOBJECTLABELPROC __teObjectLabel;
extern PFNGLGETOBJECTLABELPROC __teGetObjectLabel;
extern PFNGLOBJECTPTRLABELPROC __teObjectPtrLabel;
extern PFNGLGETOBJECTPTRLABELPROC __teGetObjectPtrLabel;
#define glClearBufferData GETFUNCTION(__teClearBufferData)
#define glClearBufferSubData GETFUNCTION(__teClearBufferSubData)
#define glDispatchCompute GETFUNCTION(__teDispatchCompute)
#define glDispatchComputeIndirect GETFUNCTION(__teDispatchComputeIndirect)
#define glCopyImageSubData GETFUNCTION(__teCopyImageSubData)
#define glFramebufferParameteri GETFUNCTION(__teFramebufferParameteri)
#define glGetFramebufferParameteriv GETFUNCTION(__teGetFramebufferParameteriv)
#define glGetInternalformati64v GETFUNCTION(__teGetInternalformati64v)
#define glInvalidateTexSubImage GETFUNCTION(__teInvalidateTexSubImage)
#define glInvalidateTexImage GETFUNCTION(__teInvalidateTexImage)
#define glInvalidateBufferSubData GETFUNCTION(__teInvalidateBufferSubData)
#define glInvalidateBufferData GETFUNCTION(__teInvalidateBufferData)
#define glInvalidateFramebuffer GETFUNCTION(__teInvalidateFramebuffer)
#define glInvalidateSubFramebuffer GETFUNCTION(__teInvalidateSubFramebuffer)
#define glMultiDrawArraysIndirect GETFUNCTION(__teMultiDrawArraysIndirect)
#define glMultiDrawElementsIndirect GETFUNCTION(__teMultiDrawElementsIndirect)
#define glGetProgramInterfaceiv GETFUNCTION(__teGetProgramInterfaceiv)
#define glGetProgramResourceIndex GETFUNCTION(__teGetProgramResourceIndex)
#define glGetProgramResourceName GETFUNCTION(__teGetProgramResourceName)
#define glGetProgramResourceiv GETFUNCTION(__teGetProgramResourceiv)
#define glGetProgramResourceLocation GETFUNCTION(__teGetProgramResourceLocation)
#define glGetProgramResourceLocationIndex GETFUNCTION(__teGetProgramResourceLocationIndex)
#define glShaderStorageBlockBinding GETFUNCTION(__teShaderStorageBlockBinding)
#define glTexBufferRange GETFUNCTION(__teTexBufferRange)
#define glTexStorage2DMultisample GETFUNCTION(__teTexStorage2DMultisample)
#define glTexStorage3DMultisample GETFUNCTION(__teTexStorage3DMultisample)
#define glTextureView GETFUNCTION(__teTextureView)
#define glBindVertexBuffer GETFUNCTION(__teBindVertexBuffer)
#define glVertexAttribFormat GETFUNCTION(__teVertexAttribFormat)
#define glVertexAttribIFormat GETFUNCTION(__teVertexAttribIFormat)
#define glVertexAttribLFormat GETFUNCTION(__teVertexAttribLFormat)
#define glVertexAttribBinding GETFUNCTION(__teVertexAttribBinding)
#define glVertexBindingDivisor GETFUNCTION(__teVertexBindingDivisor)
#define glDebugMessageControl GETFUNCTION(__teDebugMessageControl)
#define glDebugMessageInsert GETFUNCTION(__teDebugMessageInsert)
#define glDebugMessageCallback GETFUNCTION(__teDebugMessageCallback)
#define glGetDebugMessageLog GETFUNCTION(__teGetDebugMessageLog)
#define glPushDebugGroup GETFUNCTION(__tePushDebugGroup)
#define glPopDebugGroup GETFUNCTION(__tePopDebugGroup)
#define glObjectLabel GETFUNCTION(__teObjectLabel)
#define glGetObjectLabel GETFUNCTION(__teGetObjectLabel)
#define glObjectPtrLabel GETFUNCTION(__teObjectPtrLabel)
#define glGetObjectPtrLabel GETFUNCTION(__teGetObjectPtrLabel)

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
typedef void (*PFNGLBUFFERSTORAGEPROC) (GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
typedef void (*PFNGLCLEARTEXIMAGEPROC) (GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
typedef void (*PFNGLCLEARTEXSUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
typedef void (*PFNGLBINDBUFFERSBASEPROC) (GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
typedef void (*PFNGLBINDBUFFERSRANGEPROC) (GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
typedef void (*PFNGLBINDTEXTURESPROC) (GLuint first, GLsizei count, const GLuint *textures);
typedef void (*PFNGLBINDSAMPLERSPROC) (GLuint first, GLsizei count, const GLuint *samplers);
typedef void (*PFNGLBINDIMAGETEXTURESPROC) (GLuint first, GLsizei count, const GLuint *textures);
typedef void (*PFNGLBINDVERTEXBUFFERSPROC) (GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
extern PFNGLBUFFERSTORAGEPROC __teBufferStorage;
extern PFNGLCLEARTEXIMAGEPROC __teClearTexImage;
extern PFNGLCLEARTEXSUBIMAGEPROC __teClearTexSubImage;
extern PFNGLBINDBUFFERSBASEPROC __teBindBuffersBase;
extern PFNGLBINDBUFFERSRANGEPROC __teBindBuffersRange;
extern PFNGLBINDTEXTURESPROC __teBindTextures;
extern PFNGLBINDSAMPLERSPROC __teBindSamplers;
extern PFNGLBINDIMAGETEXTURESPROC __teBindImageTextures;
extern PFNGLBINDVERTEXBUFFERSPROC __teBindVertexBuffers;
#define glBufferStorage GETFUNCTION(__teBufferStorage)
#define glClearTexImage GETFUNCTION(__teClearTexImage)
#define glClearTexSubImage GETFUNCTION(__teClearTexSubImage)
#define glBindBuffersBase GETFUNCTION(__teBindBuffersBase)
#define glBindBuffersRange GETFUNCTION(__teBindBuffersRange)
#define glBindTextures GETFUNCTION(__teBindTextures)
#define glBindSamplers GETFUNCTION(__teBindSamplers)
#define glBindImageTextures GETFUNCTION(__teBindImageTextures)
#define glBindVertexBuffers GETFUNCTION(__teBindVertexBuffers)*/

namespace TinyExtender
{
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
typedef void (*DrawRangeElements) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
typedef void (*TexImage3D) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (*TexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (*CopyTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);

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
typedef void (*ActiveTexture) (GLenum texture);
typedef void (*SampleCoverage) (GLfloat value, GLboolean invert);
typedef void (*CompressedTexImage3D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
typedef void (*CompressedTexImage2D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
typedef void (*CompressedTexImage1D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
typedef void (*CompressedTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
typedef void (*CompressedTexSubImage2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
typedef void (*CompressedTexSubImage1D) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
typedef void (*GetCompressedTexImage) (GLenum target, GLint level, void *img);
typedef void (*ClientActiveTexture) (GLenum texture);
typedef void (*MultiTexCoord1d) (GLenum target, GLdouble s);
typedef void (*MultiTexCoord1dv) (GLenum target, const GLdouble *v);
typedef void (*MultiTexCoord1f) (GLenum target, GLfloat s);
typedef void (*MultiTexCoord1fv) (GLenum target, const GLfloat *v);
typedef void (*MultiTexCoord1i) (GLenum target, GLint s);
typedef void (*MultiTexCoord1iv) (GLenum target, const GLint *v);
typedef void (*MultiTexCoord1s) (GLenum target, GLshort s);
typedef void (*MultiTexCoord1sv) (GLenum target, const GLshort *v);
typedef void (*MultiTexCoord2d) (GLenum target, GLdouble s, GLdouble t);
typedef void (*MultiTexCoord2dv) (GLenum target, const GLdouble *v);
typedef void (*MultiTexCoord2f) (GLenum target, GLfloat s, GLfloat t);
typedef void (*MultiTexCoord2fv) (GLenum target, const GLfloat *v);
typedef void (*MultiTexCoord2i) (GLenum target, GLint s, GLint t);
typedef void (*MultiTexCoord2iv) (GLenum target, const GLint *v);
typedef void (*MultiTexCoord2s) (GLenum target, GLshort s, GLshort t);
typedef void (*MultiTexCoord2sv) (GLenum target, const GLshort *v);
typedef void (*MultiTexCoord3d) (GLenum target, GLdouble s, GLdouble t, GLdouble r);
typedef void (*MultiTexCoord3dv) (GLenum target, const GLdouble *v);
typedef void (*MultiTexCoord3f) (GLenum target, GLfloat s, GLfloat t, GLfloat r);
typedef void (*MultiTexCoord3fv) (GLenum target, const GLfloat *v);
typedef void (*MultiTexCoord3i) (GLenum target, GLint s, GLint t, GLint r);
typedef void (*MultiTexCoord3iv) (GLenum target, const GLint *v);
typedef void (*MultiTexCoord3s) (GLenum target, GLshort s, GLshort t, GLshort r);
typedef void (*MultiTexCoord3sv) (GLenum target, const GLshort *v);
typedef void (*MultiTexCoord4d) (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void (*MultiTexCoord4dv) (GLenum target, const GLdouble *v);
typedef void (*MultiTexCoord4f) (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void (*MultiTexCoord4fv) (GLenum target, const GLfloat *v);
typedef void (*MultiTexCoord4i) (GLenum target, GLint s, GLint t, GLint r, GLint q);
typedef void (*MultiTexCoord4iv) (GLenum target, const GLint *v);
typedef void (*MultiTexCoord4s) (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
typedef void (*MultiTexCoord4sv) (GLenum target, const GLshort *v);
typedef void (*LoadTransposeMatrixf) (const GLfloat *m);
typedef void (*LoadTransposeMatrixd) (const GLdouble *m);
typedef void (*MultTransposeMatrixf) (const GLfloat *m);
typedef void (*MultTransposeMatrixd) (const GLdouble *m);

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
typedef void (*BlendFuncSeparate) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
typedef void (*MultiDrawArrays) (GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
typedef void (*MultiDrawElements) (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
typedef void (*PointParameterf) (GLenum pname, GLfloat param);
typedef void (*PointParameterfv) (GLenum pname, const GLfloat *params);
typedef void (*PointParameteri) (GLenum pname, GLint param);
typedef void (*PointParameteriv) (GLenum pname, const GLint *params);
typedef void (*FogCoordf) (GLfloat coord);
typedef void (*FogCoordfv) (const GLfloat *coord);
typedef void (*FogCoordd) (GLdouble coord);
typedef void (*FogCoorddv) (const GLdouble *coord);
typedef void (*FogCoordPointer) (GLenum type, GLsizei stride, const void *pointer);
typedef void (*SecondaryColor3b) (GLbyte red, GLbyte green, GLbyte blue);
typedef void (*SecondaryColor3bv) (const GLbyte *v);
typedef void (*SecondaryColor3d) (GLdouble red, GLdouble green, GLdouble blue);
typedef void (*SecondaryColor3dv) (const GLdouble *v);
typedef void (*SecondaryColor3f) (GLfloat red, GLfloat green, GLfloat blue);
typedef void (*SecondaryColor3fv) (const GLfloat *v);
typedef void (*SecondaryColor3i) (GLint red, GLint green, GLint blue);
typedef void (*SecondaryColor3iv) (const GLint *v);
typedef void (*SecondaryColor3s) (GLshort red, GLshort green, GLshort blue);
typedef void (*SecondaryColor3sv) (const GLshort *v);
typedef void (*SecondaryColor3ub) (GLubyte red, GLubyte green, GLubyte blue);
typedef void (*SecondaryColor3ubv) (const GLubyte *v);
typedef void (*SecondaryColor3ui) (GLuint red, GLuint green, GLuint blue);
typedef void (*SecondaryColor3uiv) (const GLuint *v);
typedef void (*SecondaryColor3us) (GLushort red, GLushort green, GLushort blue);
typedef void (*SecondaryColor3usv) (const GLushort *v);
typedef void (*SecondaryColorPointer) (GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (*WindowPos2d) (GLdouble x, GLdouble y);
typedef void (*WindowPos2dv) (const GLdouble *v);
typedef void (*WindowPos2f) (GLfloat x, GLfloat y);
typedef void (*WindowPos2fv) (const GLfloat *v);
typedef void (*WindowPos2i) (GLint x, GLint y);
typedef void (*WindowPos2iv) (const GLint *v);
typedef void (*WindowPos2s) (GLshort x, GLshort y);
typedef void (*WindowPos2sv) (const GLshort *v);
typedef void (*WindowPos3d) (GLdouble x, GLdouble y, GLdouble z);
typedef void (*WindowPos3dv) (const GLdouble *v);
typedef void (*WindowPos3f) (GLfloat x, GLfloat y, GLfloat z);
typedef void (*WindowPos3fv) (const GLfloat *v);
typedef void (*WindowPos3i) (GLint x, GLint y, GLint z);
typedef void (*WindowPos3iv) (const GLint *v);
typedef void (*WindowPos3s) (GLshort x, GLshort y, GLshort z);
typedef void (*WindowPos3sv) (const GLshort *v);
typedef void (*BlendColor) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (*BlendEquation) (GLenum mode);

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
typedef void (*GenQueries) (GLsizei n, GLuint *ids);
typedef void (*DeleteQueries) (GLsizei n, const GLuint *ids);
typedef GLboolean(*IsQuery) (GLuint id);
typedef void (*BeginQuery) (GLenum target, GLuint id);
typedef void (*EndQuery) (GLenum target);
typedef void (*GetQueryiv) (GLenum target, GLenum pname, GLint *params);
typedef void (*GetQueryObjectiv) (GLuint id, GLenum pname, GLint *params);
typedef void (*GetQueryObjectuiv) (GLuint id, GLenum pname, GLuint *params);
typedef void (*BindBuffer) (GLenum target, GLuint buffer);
typedef void (*DeleteBuffers) (GLsizei n, const GLuint *buffers);
typedef void (*GenBuffers) (GLsizei n, GLuint *buffers);
typedef GLboolean(*IsBuffer) (GLuint buffer);
typedef void (*BufferData) (GLenum target, GLsizeiptr size, const void *data, GLenum usage);
typedef void (*BufferSubData) (GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
typedef void (*GetBufferSubData) (GLenum target, GLintptr offset, GLsizeiptr size, void *data);
typedef void* (*MapBuffer) (GLenum target, GLenum access);
typedef GLboolean(*UnmapBuffer) (GLenum target);
typedef void (*GetBufferParameteriv) (GLenum target, GLenum pname, GLint *params);
typedef void (*GetBufferPointerv) (GLenum target, GLenum pname, void **params);

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
typedef void (*BlendEquationSeparate) (GLenum modeRGB, GLenum modeAlpha);
typedef void (*DrawBuffers) (GLsizei n, const GLenum *bufs);
typedef void (*StencilOpSeparate) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
typedef void (*StencilFuncSeparate) (GLenum face, GLenum func, GLint ref, GLuint mask);
typedef void (*StencilMaskSeparate) (GLenum face, GLuint mask);
typedef void (*AttachShader) (GLuint program, GLuint shader);
typedef void (*BindAttribLocation) (GLuint program, GLuint index, const GLchar *name);
typedef void (*CompileShader) (GLuint shader);
typedef GLuint(*CreateProgram) (void);
typedef GLuint(*CreateShader) (GLenum type);
typedef void (*DeleteProgram) (GLuint program);
typedef void (*DeleteShader) (GLuint shader);
typedef void (*DetachShader) (GLuint program, GLuint shader);
typedef void (*DisableVertexAttribArray) (GLuint index);
typedef void (*EnableVertexAttribArray) (GLuint index);
typedef void (*GetActiveAttrib) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (*GetActiveUniform) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (*GetAttachedShaders) (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
typedef GLint(*GetAttribLocation) (GLuint program, const GLchar *name);
typedef void (*GetProgramiv) (GLuint program, GLenum pname, GLint *params);
typedef void (*GetProgramInfoLog) (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (*GetShaderiv) (GLuint shader, GLenum pname, GLint *params);
typedef void (*GetShaderInfoLog) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (*GetShaderSource) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
typedef GLint(*GetUniformLocation) (GLuint program, const GLchar *name);
typedef void (*GetUniformfv) (GLuint program, GLint location, GLfloat *params);
typedef void (*GetUniformiv) (GLuint program, GLint location, GLint *params);
typedef void (*GetVertexAttribdv) (GLuint index, GLenum pname, GLdouble *params);
typedef void (*GetVertexAttribfv) (GLuint index, GLenum pname, GLfloat *params);
typedef void (*GetVertexAttribiv) (GLuint index, GLenum pname, GLint *params);
typedef void (*GetVertexAttribPointerv) (GLuint index, GLenum pname, void **pointer);
typedef GLboolean(*IsProgram) (GLuint program);
typedef GLboolean(*IsShader) (GLuint shader);
typedef void (*LinkProgram) (GLuint program);
typedef void (*ShaderSource) (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
typedef void (*UseProgram) (GLuint program);
typedef void (*Uniform1f) (GLint location, GLfloat v0);
typedef void (*Uniform2f) (GLint location, GLfloat v0, GLfloat v1);
typedef void (*Uniform3f) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (*Uniform4f) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (*Uniform1i) (GLint location, GLint v0);
typedef void (*Uniform2i) (GLint location, GLint v0, GLint v1);
typedef void (*Uniform3i) (GLint location, GLint v0, GLint v1, GLint v2);
typedef void (*Uniform4i) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (*Uniform1fv) (GLint location, GLsizei count, const GLfloat *value);
typedef void (*Uniform2fv) (GLint location, GLsizei count, const GLfloat *value);
typedef void (*Uniform3fv) (GLint location, GLsizei count, const GLfloat *value);
typedef void (*Uniform4fv) (GLint location, GLsizei count, const GLfloat *value);
typedef void (*Uniform1iv) (GLint location, GLsizei count, const GLint *value);
typedef void (*Uniform2iv) (GLint location, GLsizei count, const GLint *value);
typedef void (*Uniform3iv) (GLint location, GLsizei count, const GLint *value);
typedef void (*Uniform4iv) (GLint location, GLsizei count, const GLint *value);
typedef void (*UniformMatrix2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*UniformMatrix3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*UniformMatrix4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*ValidateProgram) (GLuint program);
typedef void (*VertexAttrib1d) (GLuint index, GLdouble x);
typedef void (*VertexAttrib1dv) (GLuint index, const GLdouble *v);
typedef void (*VertexAttrib1f) (GLuint index, GLfloat x);
typedef void (*VertexAttrib1fv) (GLuint index, const GLfloat *v);
typedef void (*VertexAttrib1s) (GLuint index, GLshort x);
typedef void (*VertexAttrib1sv) (GLuint index, const GLshort *v);
typedef void (*VertexAttrib2d) (GLuint index, GLdouble x, GLdouble y);
typedef void (*VertexAttrib2dv) (GLuint index, const GLdouble *v);
typedef void (*VertexAttrib2f) (GLuint index, GLfloat x, GLfloat y);
typedef void (*VertexAttrib2fv) (GLuint index, const GLfloat *v);
typedef void (*VertexAttrib2s) (GLuint index, GLshort x, GLshort y);
typedef void (*VertexAttrib2sv) (GLuint index, const GLshort *v);
typedef void (*VertexAttrib3d) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (*VertexAttrib3dv) (GLuint index, const GLdouble *v);
typedef void (*VertexAttrib3f) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (*VertexAttrib3fv) (GLuint index, const GLfloat *v);
typedef void (*VertexAttrib3s) (GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (*VertexAttrib3sv) (GLuint index, const GLshort *v);
typedef void (*VertexAttrib4Nbv) (GLuint index, const GLbyte *v);
typedef void (*VertexAttrib4Niv) (GLuint index, const GLint *v);
typedef void (*VertexAttrib4Nsv) (GLuint index, const GLshort *v);
typedef void (*VertexAttrib4Nub) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (*VertexAttrib4Nubv) (GLuint index, const GLubyte *v);
typedef void (*VertexAttrib4Nuiv) (GLuint index, const GLuint *v);
typedef void (*VertexAttrib4Nusv) (GLuint index, const GLushort *v);
typedef void (*VertexAttrib4bv) (GLuint index, const GLbyte *v);
typedef void (*VertexAttrib4d) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (*VertexAttrib4dv) (GLuint index, const GLdouble *v);
typedef void (*VertexAttrib4f) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (*VertexAttrib4fv) (GLuint index, const GLfloat *v);
typedef void (*VertexAttrib4iv) (GLuint index, const GLint *v);
typedef void (*VertexAttrib4s) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (*VertexAttrib4sv) (GLuint index, const GLshort *v);
typedef void (*VertexAttrib4ubv) (GLuint index, const GLubyte *v);
typedef void (*VertexAttrib4uiv) (GLuint index, const GLuint *v);
typedef void (*VertexAttrib4usv) (GLuint index, const GLushort *v);
typedef void (*VertexAttribPointer) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);

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
typedef void (*UniformMatrix2x3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*UniformMatrix3x2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*UniformMatrix2x4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*UniformMatrix4x2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*UniformMatrix3x4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*UniformMatrix4x3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);

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
typedef void(*ColorMaski) (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
typedef void(*GetBooleani_v) (GLenum target, GLuint index, GLboolean *data);
typedef void(*GetIntegeri_v) (GLenum target, GLuint index, GLint *data);
typedef void(*Enablei) (GLenum target, GLuint index);
typedef void(*Disablei) (GLenum target, GLuint index);
typedef GLboolean(*IsEnabledi) (GLenum target, GLuint index);
typedef void(*BeginTransformFeedback) (GLenum primitiveMode);
typedef void(*EndTransformFeedback) (void);
typedef void(*BindBufferRange) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void(*BindBufferBase) (GLenum target, GLuint index, GLuint buffer);
typedef void(*TransformFeedbackVaryings) (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
typedef void(*GetTransformFeedbackVarying) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
typedef void(*ClampColor) (GLenum target, GLenum clamp);
typedef void(*BeginConditionalRender) (GLuint id, GLenum mode);
typedef void(*EndConditionalRender) (void);
typedef void(*VertexAttribIPointer) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void(*GetVertexAttribIiv) (GLuint index, GLenum pname, GLint *params);
typedef void(*GetVertexAttribIuiv) (GLuint index, GLenum pname, GLuint *params);
typedef void(*VertexAttribI1i) (GLuint index, GLint x);
typedef void(*VertexAttribI2i) (GLuint index, GLint x, GLint y);
typedef void(*VertexAttribI3i) (GLuint index, GLint x, GLint y, GLint z);
typedef void(*VertexAttribI4i) (GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void(*VertexAttribI1ui) (GLuint index, GLuint x);
typedef void(*VertexAttribI2ui) (GLuint index, GLuint x, GLuint y);
typedef void(*VertexAttribI3ui) (GLuint index, GLuint x, GLuint y, GLuint z);
typedef void(*VertexAttribI4ui) (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void(*VertexAttribI1iv) (GLuint index, const GLint *v);
typedef void(*VertexAttribI2iv) (GLuint index, const GLint *v);
typedef void(*VertexAttribI3iv) (GLuint index, const GLint *v);
typedef void(*VertexAttribI4iv) (GLuint index, const GLint *v);
typedef void(*VertexAttribI1uiv) (GLuint index, const GLuint *v);
typedef void(*VertexAttribI2uiv) (GLuint index, const GLuint *v);
typedef void(*VertexAttribI3uiv) (GLuint index, const GLuint *v);
typedef void(*VertexAttribI4uiv) (GLuint index, const GLuint *v);
typedef void(*VertexAttribI4bv) (GLuint index, const GLbyte *v);
typedef void(*VertexAttribI4sv) (GLuint index, const GLshort *v);
typedef void(*VertexAttribI4ubv) (GLuint index, const GLubyte *v);
typedef void(*VertexAttribI4usv) (GLuint index, const GLushort *v);
typedef void(*GetUniformuiv) (GLuint program, GLint location, GLuint *params);
typedef void(*BindFragDataLocation) (GLuint program, GLuint color, const GLchar *name);
typedef GLint(*GetFragDataLocation) (GLuint program, const GLchar *name);
typedef void(*Uniform1ui) (GLint location, GLuint v0);
typedef void(*Uniform2ui) (GLint location, GLuint v0, GLuint v1);
typedef void(*Uniform3ui) (GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void(*Uniform4ui) (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void(*Uniform1uiv) (GLint location, GLsizei count, const GLuint *value);
typedef void(*Uniform2uiv) (GLint location, GLsizei count, const GLuint *value);
typedef void(*Uniform3uiv) (GLint location, GLsizei count, const GLuint *value);
typedef void(*Uniform4uiv) (GLint location, GLsizei count, const GLuint *value);
typedef void(*TexParameterIiv) (GLenum target, GLenum pname, const GLint *params);
typedef void(*TexParameterIuiv) (GLenum target, GLenum pname, const GLuint *params);
typedef void(*GetTexParameterIiv) (GLenum target, GLenum pname, GLint *params);
typedef void(*GetTexParameterIuiv) (GLenum target, GLenum pname, GLuint *params);
typedef void(*ClearBufferiv) (GLenum buffer, GLint drawbuffer, const GLint *value);
typedef void(*ClearBufferuiv) (GLenum buffer, GLint drawbuffer, const GLuint *value);
typedef void(*ClearBufferfv) (GLenum buffer, GLint drawbuffer, const GLfloat *value);
typedef void(*ClearBufferfi) (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef const GLubyte *(*GetStringi) (GLenum name, GLuint index);
typedef GLboolean(*IsRenderbuffer) (GLuint renderbuffer);
typedef void(*BindRenderbuffer) (GLenum target, GLuint renderbuffer);
typedef void(*DeleteRenderbuffers) (GLsizei n, const GLuint *renderbuffers);
typedef void(*GenRenderbuffers) (GLsizei n, GLuint *renderbuffers);
typedef void(*RenderbufferStorage) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
typedef void(*GetRenderbufferParameteriv) (GLenum target, GLenum pname, GLint *params);
typedef GLboolean(*IsFramebuffer) (GLuint framebuffer);
typedef void(*BindFramebuffer) (GLenum target, GLuint framebuffer);
typedef void(*DeleteFramebuffers) (GLsizei n, const GLuint *framebuffers);
typedef void(*GenFramebuffers) (GLsizei n, GLuint *framebuffers);
typedef GLenum(*CheckFramebufferStatus) (GLenum target);
typedef void(*FramebufferTexture1D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void(*FramebufferTexture2D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void(*FramebufferTexture3D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef void(*FramebufferRenderbuffer) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void(*GetFramebufferAttachmentParameteriv) (GLenum target, GLenum attachment, GLenum pname, GLint *params);
typedef void(*GenerateMipmap) (GLenum target);
typedef void(*BlitFramebuffer) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef void(*RenderbufferStorageMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void(*FramebufferTextureLayer) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void *(*MapBufferRange) (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef void(*FlushMappedBufferRange) (GLenum target, GLintptr offset, GLsizeiptr length);
typedef void(*BindVertexArray) (GLuint array);
typedef void(*DeleteVertexArrays) (GLsizei n, const GLuint *arrays);
typedef void(*GenVertexArrays) (GLsizei n, GLuint *arrays);
typedef GLboolean(*IsVertexArray) (GLuint array);

	class extensionManager
	{
	public:

		GLuint glVersionMajor;
		GLuint glVersionMinor;

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

#pragma endregion

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

		GLvoid InitializeExtentions()
		{
			InitializeGLVersion();

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
		}

	private:

		GLvoid InitializeGLVersion()
		{
			const GLubyte* versionString = glGetString(GL_VERSION);

			glVersionMajor = versionString[0] - '0';
			glVersionMinor = versionString[2] - '0';
		}

		void* GetProcAddress(const char* procName)
		{
#if defined(_WIN32) || defined(_WIN64)
			return wglGetProcAddress((LPCSTR)procName);
#elif defined(__linux__)
			return glXGetProcAddress((procName);
#endif
		}

		bool IsExtensionSupported(GLubyte* extensionName)
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

		GLvoid Load1_2Extensions()
		{
			glDrawRangeElements = (DrawRangeElements)GetProcAddress("glDrawRangeElements");
			glTexImage3D = (TexImage3D)GetProcAddress("glTexImage3D");
			glTexSubImage3D = (TexSubImage3D)GetProcAddress("glTexSubImage3D");
			glCopyTexSubImage3D = (CopyTexSubImage3D)GetProcAddress("glCopyTexSubImgage");
		}

		GLvoid Load1_3Extensions()
		{
			glActiveTexture = (ActiveTexture)GetProcAddress("glActiveTexture");
			glSampleCoverage = (SampleCoverage)GetProcAddress("glSampleCoverage");
			glCompressedTexImage3D = (CompressedTexImage3D)GetProcAddress("glCompressedTexImage3D");
			glCompressedTexImage2D = (CompressedTexImage2D)GetProcAddress("glCompressedTexImage2D");
			glCompressedTexImage1D = (CompressedTexImage1D)GetProcAddress("glCompressedTexImage1D");
			glCompressedTexSubImage3D = (CompressedTexSubImage3D)GetProcAddress("glCompressedTexSubImage3D");
			glCompressedTexSubImage2D = (CompressedTexSubImage2D)GetProcAddress("glCompressedTexSubImage2D");
			glCompressedTexSubImage1D = (CompressedTexSubImage1D)GetProcAddress("glCompressedTexSubImage1D");
			glGetCompressedTexImage = (GetCompressedTexImage)GetProcAddress("glGetCompressedTexImage");
			glClientActiveTexture = (ClientActiveTexture)GetProcAddress("glClientActiveTexture");
			glMultiTexCoord1d = (MultiTexCoord1d)GetProcAddress("glMultiTexCoord1d");
			glMultiTexCoord1dv = (MultiTexCoord1dv)GetProcAddress("glMultiTexCoord1dv");
			glMultiTexCoord1f = (MultiTexCoord1f)GetProcAddress("glMultiTexCoord1f");
			glMultiTexCoord1fv = (MultiTexCoord1fv)GetProcAddress("glMultiTexCoord1fv");
			glMultiTexCoord1i = (MultiTexCoord1i)GetProcAddress("glMultiTexCoord1i");
			glMultiTexCoord1iv = (MultiTexCoord1iv)GetProcAddress("glMultiTexCoord1iv");
			glMultiTexCoord1s = (MultiTexCoord1s)GetProcAddress("glMultiTexCoord1s");
			glMultiTexCoord1sv = (MultiTexCoord1sv)GetProcAddress("glMultiTexCoord1sv");
			glMultiTexCoord2d = (MultiTexCoord2d)GetProcAddress("glMultiTexCoord2d");
			glMultiTexCoord2dv = (MultiTexCoord2dv)GetProcAddress("glMultiTexCoord2dv");
			glMultiTexCoord2f = (MultiTexCoord2f)GetProcAddress("glMultiTexCoord2f");
			glMultiTexCoord2fv = (MultiTexCoord2fv)GetProcAddress("glMultiTexCoord2fv");
			glMultiTexCoord2i = (MultiTexCoord2i)GetProcAddress("glMultiTexCoord2i");
			glMultiTexCoord2iv = (MultiTexCoord2iv)GetProcAddress("glMultiTexCoord2iv");
			glMultiTexCoord2s = (MultiTexCoord2s)GetProcAddress("glMultiTexCoord2s");
			glMultiTexCoord2sv = (MultiTexCoord2sv)GetProcAddress("glMultiTexCoord2sv");
			glMultiTexCoord3d = (MultiTexCoord3d)GetProcAddress("glMultiTexCoord3d");
			glMultiTexCoord3dv = (MultiTexCoord3dv)GetProcAddress("glMultiTexCoord3dv");
			glMultiTexCoord3f = (MultiTexCoord3f)GetProcAddress("glMultiTexCoord3f");
			glMultiTexCoord3fv = (MultiTexCoord3fv)GetProcAddress("glMultiTexCoord3fv");
			glMultiTexCoord3i = (MultiTexCoord3i)GetProcAddress("glMultiTexCoord3i");
			glMultiTexCoord3iv = (MultiTexCoord3iv)GetProcAddress("glMultiTexCoord3iv");
			glMultiTexCoord3s = (MultiTexCoord3s)GetProcAddress("glMultiTexCoord3s");
			glMultiTexCoord3sv = (MultiTexCoord3sv)GetProcAddress("glMultiTexCoord3sv");
			glMultiTexCoord4d = (MultiTexCoord4d)GetProcAddress("glMultiTexCoord4d");
			glMultiTexCoord4dv = (MultiTexCoord4dv)GetProcAddress("glMultiTexCoord4dv");
			glMultiTexCoord4f = (MultiTexCoord4f)GetProcAddress("glMultiTexCoord4f");
			glMultiTexCoord4fv = (MultiTexCoord4fv)GetProcAddress("glMultiTexCoord4fv");
			glMultiTexCoord4i = (MultiTexCoord4i)GetProcAddress("glMultiTexCoord4i");
			glMultiTexCoord4iv = (MultiTexCoord4iv)GetProcAddress("glMultiTexCoord4iv");
			glMultiTexCoord4s = (MultiTexCoord4s)GetProcAddress("glMultiTexCoord4s");
			glMultiTexCoord4sv = (MultiTexCoord4sv)GetProcAddress("glMultiTexCoord4sv");
			glLoadTransposeMatrixf = (LoadTransposeMatrixf)GetProcAddress("glLoadTransposeMatrixf");
			glLoadTransposeMatrixd = (LoadTransposeMatrixd)GetProcAddress("glLoadTransposeMatrixd");
			glMultTransposeMatrixf = (MultTransposeMatrixf)GetProcAddress("glMultTransposeMatrixf");
			glMultTransposeMatrixd = (MultTransposeMatrixd)GetProcAddress("glMultTransposeMatrixd");
		}

		GLvoid Load1_4Extensions()
		{
			glBlendFuncSeparate = (BlendFuncSeparate)GetProcAddress("glBlendFuncSeparate");
			glMultiDrawArrays = (MultiDrawArrays)GetProcAddress("glMultiDrawArrays");
			glMultiDrawElements = (MultiDrawElements)GetProcAddress("glMultiDrawElements");
			glPointParameterf = (PointParameterf)GetProcAddress("glPointParameterf");
			glPointParameterfv = (PointParameterfv)GetProcAddress("glPointParameterfv");
			glPointParameteri = (PointParameteri)GetProcAddress("glPointParameteri");
			glPointParameteriv = (PointParameteriv)GetProcAddress("glPointParameteriv");
			glFogCoordf = (FogCoordf)GetProcAddress("glFogCoordf");
			glFogCoordfv = (FogCoordfv)GetProcAddress("glFogCoordfv");
			glFogCoordd = (FogCoordd)GetProcAddress("glFogCoordd");
			glFogCoorddv = (FogCoorddv)GetProcAddress("glFogCoorddv");
			glFogCoordPointer = (FogCoordPointer)GetProcAddress("glFogCoordPointer");
			glSecondaryColor3b = (SecondaryColor3b)GetProcAddress("glSecondaryColor3b");
			glSecondaryColor3bv = (SecondaryColor3bv)GetProcAddress("glSecondaryColor3bv");
			glSecondaryColor3d = (SecondaryColor3d)GetProcAddress("glSecondaryColor3d");
			glSecondaryColor3dv = (SecondaryColor3dv)GetProcAddress("glSecondaryColor3dv");
			glSecondaryColor3f = (SecondaryColor3f)GetProcAddress("glSecondaryColor3f");
			glSecondaryColor3fv = (SecondaryColor3fv)GetProcAddress("glSecondaryColor3fv");
			glSecondaryColor3i = (SecondaryColor3i)GetProcAddress("glSecondaryColor3i");
			glSecondaryColor3iv = (SecondaryColor3iv)GetProcAddress("glSecondaryColor3iv");
			glSecondaryColor3s = (SecondaryColor3s)GetProcAddress("glSecondaryColor3s");
			glSecondaryColor3sv = (SecondaryColor3sv)GetProcAddress("glSecondaryColor3sv");
			glSecondaryColor3ub = (SecondaryColor3ub)GetProcAddress("glSecondaryColor3ub");
			glSecondaryColor3ubv = (SecondaryColor3ubv)GetProcAddress("glSecondaryColor3ubv");
			glSecondaryColor3ui = (SecondaryColor3ui)GetProcAddress("glSecondaryColor3ui");
			glSecondaryColor3uiv = (SecondaryColor3uiv)GetProcAddress("glSecondaryColor3uiv");
			glSecondaryColor3us = (SecondaryColor3us)GetProcAddress("glSecondaryColor3us");
			glSecondaryColor3usv = (SecondaryColor3usv)GetProcAddress("glSecondaryColor3usv");
			glSecondaryColorPointer = (SecondaryColorPointer)GetProcAddress("glSecondaryColorPointer");
			glWindowPos2d = (WindowPos2d)GetProcAddress("glWindowPos2d");
			glWindowPos2dv = (WindowPos2dv)GetProcAddress("glWindowPos2dv");
			glWindowPos2f = (WindowPos2f)GetProcAddress("glWindowPos2f");
			glWindowPos2fv = (WindowPos2fv)GetProcAddress("glWindowPos2fv");
			glWindowPos2i = (WindowPos2i)GetProcAddress("glWindowPos2i");
			glWindowPos2iv = (WindowPos2iv)GetProcAddress("glWindowPos2iv");
			glWindowPos2s = (WindowPos2s)GetProcAddress("glWindowPos2s");
			glWindowPos2sv = (WindowPos2sv)GetProcAddress("glWindowPos2sv");
			glWindowPos3d = (WindowPos3d)GetProcAddress("glWindowPos3d");
			glWindowPos3dv = (WindowPos3dv)GetProcAddress("glWindowPos3dv");
			glWindowPos3f = (WindowPos3f)GetProcAddress("glWindowPos3f");
			glWindowPos3fv = (WindowPos3fv)GetProcAddress("glWindowPos3fv");
			glWindowPos3i = (WindowPos3i)GetProcAddress("glWindowPos3i");
			glWindowPos3iv = (WindowPos3iv)GetProcAddress("glWindowPos3iv");
			glWindowPos3s = (WindowPos3s)GetProcAddress("glWindowPos3s");
			glWindowPos3sv = (WindowPos3sv)GetProcAddress("glWindowPos3sv");
			glBlendColor = (BlendColor)GetProcAddress("glBlendColor");
			glBlendEquation = (BlendEquation)GetProcAddress("glBlendEquation");
		}

		GLvoid Load1_5Extensions()
		{
			glGenQueries =					(GenQueries)GetProcAddress("glGenQueries");
			glDeleteQueries =				(DeleteQueries)GetProcAddress("glDeleteQueries");
			glIsQuery =						(IsQuery)GetProcAddress("glIsQuery");
			glBeginQuery =					(BeginQuery)GetProcAddress("glBeginQuery");
			glEndQuery =					(EndQuery)GetProcAddress("glEndQuery");
			glGetQueryiv =					(GetQueryiv)GetProcAddress("glGetQueryiv");
			glGetQueryObjectiv =			(GetQueryObjectiv)GetProcAddress("glGetQueryObjectiv");
			glGetQueryObjectuiv =			(GetQueryObjectuiv)GetProcAddress("glGetQueryObjectuiv");
			glBindBuffer =					(BindBuffer)GetProcAddress("glBindBuffer");
			glDeleteBuffers =				(DeleteBuffers)GetProcAddress("glDeleteBuffers");
			glGenBuffers =					(GenBuffers)GetProcAddress("glGenBuffers");
			glIsBuffer =					(IsBuffer)GetProcAddress("glIsBuffer");
			glBufferData =					(BufferData)GetProcAddress("glBufferData");
			glBufferSubData =				(BufferSubData)GetProcAddress("glBufferSubData");
			glGetBufferSubData =			(GetBufferSubData)GetProcAddress("glGetBufferSubData");
			glMapBuffer =					(MapBuffer)GetProcAddress("glMapBuffer");
			glUnmapBuffer =					(UnmapBuffer)GetProcAddress("glUnmapBuffer");
			glGetBufferParameteriv =		(GetBufferParameteriv)GetProcAddress("glGetBufferParameteriv");
			glGetBufferPointerv =			(GetBufferPointerv)GetProcAddress("glGetBufferPointerv");
		}

		GLvoid Load2_0Extensions()
		{
			glBlendEquationSeparate = (BlendEquationSeparate)GetProcAddress("glBlendEquationSeparate");
			glDrawBuffers = (DrawBuffers)GetProcAddress("glDrawBuffers");
			glStencilOpSeparate = (StencilOpSeparate)GetProcAddress("glStencilOpSeparate");
			glStencilFuncSeparate = (StencilFuncSeparate)GetProcAddress("glStencilFuncSeparate");
			glStencilMaskSeparate = (StencilMaskSeparate)GetProcAddress("glStencilMaskSeparate");
			glAttachShader = (AttachShader)GetProcAddress("glAttachShader");
			glBindAttribLocation = (BindAttribLocation)GetProcAddress("glBindAttribLocation");
			glCompileShader = (CompileShader)GetProcAddress("glCompileShader");
			glCreateProgram = (CreateProgram)GetProcAddress("glCreateProgram");
			glCreateShader = (CreateShader)GetProcAddress("glCreateShader");
			glDeleteProgram = (DeleteProgram)GetProcAddress("glDeleteProgram");
			glDeleteShader = (DeleteShader)GetProcAddress("glDeleteShader");
			glDetachShader = (DetachShader)GetProcAddress("glDetachShader");
			glDisableVertexAttribArray = (DisableVertexAttribArray)GetProcAddress("glDisableVertexAttribArray");
			glEnableVertexAttribArray = (EnableVertexAttribArray)GetProcAddress("glEnableVertexAttribArray");
			glGetActiveAttrib = (GetActiveAttrib)GetProcAddress("glGetActiveAttrib");
			glGetActiveUniform = (GetActiveUniform)GetProcAddress("glGetActiveUniform");
			glGetAttachedShaders = (GetAttachedShaders)GetProcAddress("glGetAttachedShaders");
			glGetAttribLocation = (GetAttribLocation)GetProcAddress("glGetAttribLocation");
			glGetProgramiv = (GetProgramiv)GetProcAddress("glGetProgramiv");
			glGetProgramInfoLog = (GetProgramInfoLog)GetProcAddress("glGetProgramInfoLog");
			glGetShaderiv = (GetShaderiv)GetProcAddress("glGetShaderiv");
			glGetShaderInfoLog = (GetShaderInfoLog)GetProcAddress("glGetShaderInfoLog");
			glGetShaderSource = (GetShaderSource)GetProcAddress("glGetShaderSource");
			glGetUniformLocation = (GetUniformLocation)GetProcAddress("glGetUniformLocation");
			glGetUniformfv = (GetUniformfv)GetProcAddress("glGetUniformfv");
			glGetUniformiv = (GetUniformiv)GetProcAddress("glGetUniformiv");
			glGetVertexAttribdv = (GetVertexAttribdv)GetProcAddress("glGetVertexAttribdv");
			glGetVertexAttribfv = (GetVertexAttribfv)GetProcAddress("glGetVertexAttribfv");
			glGetVertexAttribiv = (GetVertexAttribiv)GetProcAddress("glGetVertexAttribiv");
			glGetVertexAttribPointerv = (GetVertexAttribPointerv)GetProcAddress("glGetVertexAttribPointerv");
			glIsProgram = (IsProgram)GetProcAddress("glIsProgram");
			glIsShader = (IsShader)GetProcAddress("glIsShader");
			glLinkProgram = (LinkProgram)GetProcAddress("glLinkProgram");
			glShaderSource = (ShaderSource)GetProcAddress("glShaderSource");
			glUseProgram = (UseProgram)GetProcAddress("glUseProgram");
			glUniform1f = (Uniform1f)GetProcAddress("glUniform1f");
			glUniform2f = (Uniform2f)GetProcAddress("glUniform2f");
			glUniform3f = (Uniform3f)GetProcAddress("glUniform3f");
			glUniform4f = (Uniform4f)GetProcAddress("glUniform4f");
			glUniform1i = (Uniform1i)GetProcAddress("glUniform1i");
			glUniform2i = (Uniform2i)GetProcAddress("glUniform2i");
			glUniform3i = (Uniform3i)GetProcAddress("glUniform3i");
			glUniform4i = (Uniform4i)GetProcAddress("glUniform4i");
			glUniform1fv = (Uniform1fv)GetProcAddress("glUniform1fv");
			glUniform2fv = (Uniform2fv)GetProcAddress("glUniform2fv");
			glUniform3fv = (Uniform3fv)GetProcAddress("glUniform3fv");
			glUniform4fv = (Uniform4fv)GetProcAddress("glUniform4fv");
			glUniform1iv = (Uniform1iv)GetProcAddress("glUniform1iv");
			glUniform2iv = (Uniform2iv)GetProcAddress("glUniform2iv");
			glUniform3iv = (Uniform3iv)GetProcAddress("glUniform3iv");
			glUniform4iv = (Uniform4iv)GetProcAddress("glUniform4iv");
			glUniformMatrix2fv = (UniformMatrix2fv)GetProcAddress("glUniformMatrix2fv");
			glUniformMatrix3fv = (UniformMatrix3fv)GetProcAddress("glUniformMatrix3fv");
			glUniformMatrix4fv = (UniformMatrix4fv)GetProcAddress("glUniformMatrix4fv");
			glValidateProgram = (ValidateProgram)GetProcAddress("glValidateProgram");
			glVertexAttrib1d = (VertexAttrib1d)GetProcAddress("glVertexAttrib1d");
			glVertexAttrib1dv = (VertexAttrib1dv)GetProcAddress("glVertexAttrib1dv");
			glVertexAttrib1f = (VertexAttrib1f)GetProcAddress("glVertexAttrib1f");
			glVertexAttrib1fv = (VertexAttrib1fv)GetProcAddress("glVertexAttrib1fv");
			glVertexAttrib1s = (VertexAttrib1s)GetProcAddress("glVertexAttrib1s");
			glVertexAttrib1sv = (VertexAttrib1sv)GetProcAddress("glVertexAttrib1sv");
			glVertexAttrib2d = (VertexAttrib2d)GetProcAddress("glVertexAttrib2d");
			glVertexAttrib2dv = (VertexAttrib2dv)GetProcAddress("glVertexAttrib2dv");
			glVertexAttrib2f = (VertexAttrib2f)GetProcAddress("glVertexAttrib2f");
			glVertexAttrib2fv = (VertexAttrib2fv)GetProcAddress("glVertexAttrib2fv");
			glVertexAttrib2s = (VertexAttrib2s)GetProcAddress("glVertexAttrib2s");
			glVertexAttrib2sv = (VertexAttrib2sv)GetProcAddress("glVertexAttrib2sv");
			glVertexAttrib3d = (VertexAttrib3d)GetProcAddress("glVertexAttrib3d");
			glVertexAttrib3dv = (VertexAttrib3dv)GetProcAddress("glVertexAttrib3dv");
			glVertexAttrib3f = (VertexAttrib3f)GetProcAddress("glVertexAttrib3f");
			glVertexAttrib3fv = (VertexAttrib3fv)GetProcAddress("glVertexAttrib3fv");
			glVertexAttrib3s = (VertexAttrib3s)GetProcAddress("glVertexAttrib3s");
			glVertexAttrib3sv = (VertexAttrib3sv)GetProcAddress("glVertexAttrib3sv");
			glVertexAttrib4Nbv = (VertexAttrib4Nbv)GetProcAddress("glVertexAttrib4Nbv");
			glVertexAttrib4Niv = (VertexAttrib4Niv)GetProcAddress("glVertexAttrib4Niv");
			glVertexAttrib4Nsv = (VertexAttrib4Nsv)GetProcAddress("glVertexAttrib4Nsv");
			glVertexAttrib4Nub = (VertexAttrib4Nub)GetProcAddress("glVertexAttrib4Nub");
			glVertexAttrib4Nubv = (VertexAttrib4Nubv)GetProcAddress("glVertexAttrib4Nubv");
			glVertexAttrib4Nuiv = (VertexAttrib4Nuiv)GetProcAddress("glVertexAttrib4Nuiv");
			glVertexAttrib4Nusv = (VertexAttrib4Nusv)GetProcAddress("glVertexAttrib4Nusv");
			glVertexAttrib4bv = (VertexAttrib4bv)GetProcAddress("glVertexAttrib4bv");
			glVertexAttrib4d = (VertexAttrib4d)GetProcAddress("glVertexAttrib4d");
			glVertexAttrib4dv = (VertexAttrib4dv)GetProcAddress("glVertexAttrib4dv");
			glVertexAttrib4f = (VertexAttrib4f)GetProcAddress("glVertexAttrib4f");
			glVertexAttrib4fv = (VertexAttrib4fv)GetProcAddress("glVertexAttrib4fv");
			glVertexAttrib4iv = (VertexAttrib4iv)GetProcAddress("glVertexAttrib4iv");
			glVertexAttrib4s = (VertexAttrib4s)GetProcAddress("glVertexAttrib4s");
			glVertexAttrib4sv = (VertexAttrib4sv)GetProcAddress("glVertexAttrib4sv");
			glVertexAttrib4ubv = (VertexAttrib4ubv)GetProcAddress("glVertexAttrib4ubv");
			glVertexAttrib4uiv = (VertexAttrib4uiv)GetProcAddress("glVertexAttrib4uiv");
			glVertexAttrib4usv = (VertexAttrib4usv)GetProcAddress("glVertexAttrib4usv");
			glVertexAttribPointer = (VertexAttribPointer)GetProcAddress("glVertexAttribPointer");
		}

		GLvoid Load2_1Extensions()
		{
			glUniformMatrix2x3fv = (UniformMatrix2x3fv)GetProcAddress("glUniformMatrix2x3fv");
			glUniformMatrix3x2fv = (UniformMatrix3x2fv)GetProcAddress("glUniformMatrix3x2fv");
			glUniformMatrix2x4fv = (UniformMatrix2x4fv)GetProcAddress("glUniformMatrix2x4fv");
			glUniformMatrix4x2fv = (UniformMatrix4x2fv)GetProcAddress("glUniformMatrix4x2fv");
			glUniformMatrix3x4fv = (UniformMatrix3x4fv)GetProcAddress("glUniformMatrix3x4fv");
			glUniformMatrix4x3fv = (UniformMatrix4x3fv)GetProcAddress("glUniformMatrix4x3fv");
		}

		void Load3_0Extensions()
		{
			glColorMaski = (ColorMaski)GetProcAddress("glColorMaski");
			glGetBooleani_v = (GetBooleani_v)GetProcAddress("glGetBooleani_v");
			glGetIntegeri_v = (GetIntegeri_v)GetProcAddress("glGetIntegeri_v");
			glEnablei = (Enablei)GetProcAddress("glEnablei");
			glDisablei = (Disablei)GetProcAddress("glDisablei");
			glIsEnabledi = (IsEnabledi)GetProcAddress("glIsEnabledi");
			glBeginTransformFeedback = (BeginTransformFeedback)GetProcAddress("glBeginTransformFeedback");
			glEndTransformFeedback = (EndTransformFeedback)GetProcAddress("glEndTransformFeedback");
			glBindBufferRange = (BindBufferRange)GetProcAddress("glBindBufferRange");
			glBindBufferBase = (BindBufferBase)GetProcAddress("glBindBufferBase");
			glTransformFeedbackVaryings = (TransformFeedbackVaryings)GetProcAddress("glTransformFeedbackVaryings");
			glGetTransformFeedbackVarying = (GetTransformFeedbackVarying)GetProcAddress("glGetTransformFeedbackVarying");
			glClampColor = (ClampColor)GetProcAddress("glClampColor");
			glBeginConditionalRender = (BeginConditionalRender)GetProcAddress("glBeginConditionalRender");
			glEndConditionalRender = (EndConditionalRender)GetProcAddress("glEndConditionalRender");
			glVertexAttribIPointer = (VertexAttribIPointer)GetProcAddress("glVertexAttribIPointer");
			glGetVertexAttribIiv = (GetVertexAttribIiv)GetProcAddress("glGetVertexAttribIiv");
			glGetVertexAttribIuiv = (GetVertexAttribIuiv)GetProcAddress("glGetVertexAttribIuiv");
			glVertexAttribI1i = (VertexAttribI1i)GetProcAddress("glVertexAttribI1i");
			glVertexAttribI2i = (VertexAttribI2i)GetProcAddress("glVertexAttribI2i");
			glVertexAttribI3i = (VertexAttribI3i)GetProcAddress("glVertexAttribI3i");
			glVertexAttribI4i = (VertexAttribI4i)GetProcAddress("glVertexAttribI4i");
			glVertexAttribI1ui = (VertexAttribI1ui)GetProcAddress("glVertexAttribI1ui");
			glVertexAttribI2ui = (VertexAttribI2ui)GetProcAddress("glVertexAttribI2ui");
			glVertexAttribI3ui = (VertexAttribI3ui)GetProcAddress("glVertexAttribI3ui");
			glVertexAttribI4ui = (VertexAttribI4ui)GetProcAddress("glVertexAttribI4ui");
			glVertexAttribI1iv = (VertexAttribI1iv)GetProcAddress("glVertexAttribI1iv");
			glVertexAttribI2iv = (VertexAttribI2iv)GetProcAddress("glVertexAttribI2iv");
			glVertexAttribI3iv = (VertexAttribI3iv)GetProcAddress("glVertexAttribI3iv");
			glVertexAttribI4iv = (VertexAttribI4iv)GetProcAddress("glVertexAttribI4iv");
			glVertexAttribI1uiv = (VertexAttribI1uiv)GetProcAddress("glVertexAttribI1uiv");
			glVertexAttribI2uiv = (VertexAttribI2uiv)GetProcAddress("glVertexAttribI2uiv");
			glVertexAttribI3uiv = (VertexAttribI3uiv)GetProcAddress("glVertexAttribI3uiv");
			glVertexAttribI4uiv = (VertexAttribI4uiv)GetProcAddress("glVertexAttribI4uiv");
			glVertexAttribI4bv = (VertexAttribI4bv)GetProcAddress("glVertexAttribI4bv");
			glVertexAttribI4sv = (VertexAttribI4sv)GetProcAddress("glVertexAttribI4sv");
			glVertexAttribI4ubv = (VertexAttribI4ubv)GetProcAddress("glVertexAttribI4ubv");
			glVertexAttribI4usv = (VertexAttribI4usv)GetProcAddress("glVertexAttribI4usv");
			glGetUniformuiv = (GetUniformuiv)GetProcAddress("glGetUniformuiv");
			glBindFragDataLocation = (BindFragDataLocation)GetProcAddress("glBindFragDataLocation");
			glGetFragDataLocation = (GetFragDataLocation)GetProcAddress("glGetFragDataLocation");
			glUniform1ui = (Uniform1ui)GetProcAddress("glUniform1ui");
			glUniform2ui = (Uniform2ui)GetProcAddress("glUniform2ui");
			glUniform3ui = (Uniform3ui)GetProcAddress("glUniform3ui");
			glUniform4ui = (Uniform4ui)GetProcAddress("glUniform4ui");
			glUniform1uiv = (Uniform1uiv)GetProcAddress("glUniform1uiv");
			glUniform2uiv = (Uniform2uiv)GetProcAddress("glUniform2uiv");
			glUniform3uiv = (Uniform3uiv)GetProcAddress("glUniform3uiv");
			glUniform4uiv = (Uniform4uiv)GetProcAddress("glUniform4uiv");
			glTexParameterIiv = (TexParameterIiv)GetProcAddress("glTexParameterIiv");
			glTexParameterIuiv = (TexParameterIuiv)GetProcAddress("glTexParameterIuiv");
			glGetTexParameterIiv = (GetTexParameterIiv)GetProcAddress("glGetTexParameterIiv");
			glGetTexParameterIuiv = (GetTexParameterIuiv)GetProcAddress("glGetTexParameterIuiv");
			glClearBufferiv = (ClearBufferiv)GetProcAddress("glClearBufferiv");
			glClearBufferuiv = (ClearBufferuiv)GetProcAddress("glClearBufferuiv");
			glClearBufferfv = (ClearBufferfv)GetProcAddress("glClearBufferfv");
			glClearBufferfi = (ClearBufferfi)GetProcAddress("glClearBufferfi");
			glGetStringi = (GetStringi)GetProcAddress("glGetStringi");
			glIsRenderbuffer = (IsRenderbuffer)GetProcAddress("glIsRenderbuffer");
			glBindRenderbuffer = (BindRenderbuffer)GetProcAddress("glBindRenderbuffer");
			glDeleteRenderbuffers = (DeleteRenderbuffers)GetProcAddress("glDeleteRenderbuffers");
			glGenRenderbuffers = (GenRenderbuffers)GetProcAddress("glGenRenderbuffers");
			glRenderbufferStorage = (RenderbufferStorage)GetProcAddress("glRenderbufferStorage");
			glGetRenderbufferParameteriv = (GetRenderbufferParameteriv)GetProcAddress("glGetRenderbufferParameteriv");
			glIsFramebuffer = (IsFramebuffer)GetProcAddress("glIsFramebuffer");
			glBindFramebuffer = (BindFramebuffer)GetProcAddress("glBindFramebuffer");
			glDeleteFramebuffers = (DeleteFramebuffers)GetProcAddress("glDeleteFramebuffers");
			glGenFramebuffers = (GenFramebuffers)GetProcAddress("glGenFramebuffers");
			glCheckFrameBufferStatus = (CheckFramebufferStatus)GetProcAddress("glCheckFramebufferStatus");
			glFramebufferTexture1D = (FramebufferTexture1D)GetProcAddress("glFramebufferTexture1D");
			glFramebufferTexture2D = (FramebufferTexture2D)GetProcAddress("glFramebufferTexture2D");
			glFramebufferTexture3D = (FramebufferTexture3D)GetProcAddress("glFramebufferTexture3D");
			glFramebufferRenderbuffer = (FramebufferRenderbuffer)GetProcAddress("glFramebufferRenderbuffer");
			glGetFramebufferAttachmentParameteriv = (GetFramebufferAttachmentParameteriv)GetProcAddress("glGetFramebufferAttachmentParameteriv");
			glGenerateMipmap = (GenerateMipmap)GetProcAddress("glGenerateMipmap");
			glBlitFramebuffer = (BlitFramebuffer)GetProcAddress("glBlitFramebuffer");
			glRenderbufferStorageMultisample = (RenderbufferStorageMultisample)GetProcAddress("glRenderbufferStorageMultisample");
			glFramebufferTextureLayer = (FramebufferTextureLayer)GetProcAddress("glFramebufferTextureLayer");
			glMapBufferRange = (MapBufferRange)GetProcAddress("glMapBufferRange");
			glFlushMappedBufferRange = (FlushMappedBufferRange)GetProcAddress("glFlushMappedBufferRange");
			glBindVertexArray = (BindVertexArray)GetProcAddress("glBindVertexArray");
			glDeleteVertexArrays = (DeleteVertexArrays)GetProcAddress("glDeleteVertexArrays");
			glGenVertexArrays = (GenVertexArrays)GetProcAddress("glGenVertexArrays");
			glIsVertexArray = (IsVertexArray)GetProcAddress("glIsVertexArray");
		}

		/*
		static inline GLvoid Load2_0Extensions()
		{
			
		}

		static inline GLvoid Load2_1Extensions()
		{

		}

		static inline GLvoid Load3_0Extensions()
		{
			glColorMaski = (PFNGLCOLORMASKIPROC)GetProcAddress(("glColorMaski");
			glGetBooleani_v = (PFNGLGETBOOLEANI_VPROC)GetProcAddress(("glGetBooleani_v");
			glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC)GetProcAddress(("glGetIntegeri_v");
			glEnablei = (PFNGLENABLEIPROC)GetProcAddress(("glEnablei");
			glDisablei = (PFNGLDISABLEIPROC)GetProcAddress(("glDisablei");
			glIsEnabledi = (PFNGLISENABLEDIPROC)GetProcAddress(("glIsEnabledi");
			glBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC)GetProcAddress(("glBeginTransformFeedback");
			glEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC)GetProcAddress(("glEndTransformFeedback");
			glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)GetProcAddress(("glBindBufferRange");
			glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)GetProcAddress(("glBindBufferBase");
			glTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC)GetProcAddress(("glTransformFeedbackVaryings");
			glGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)GetProcAddress(("glGetTransformFeedbackVarying");
			glClampColor = (PFNGLCLAMPCOLORPROC)GetProcAddress(("glClampColor");
			glBeginConditionalRender = (PFNGLBEGINCONDITIONALRENDERPROC)GetProcAddress(("glBeginConditionalRender");
			glEndConditionalRender = (PFNGLENDCONDITIONALRENDERPROC)GetProcAddress(("glEndConditionalRender");
			glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC)GetProcAddress(("glVertexAttribIPointer");
			glGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC)GetProcAddress(("glGetVertexAttribIiv");
			glGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC)GetProcAddress(("glGetVertexAttribIuiv");
			glVertexAttribI1i = (PFNGLVERTEXATTRIBI1IPROC)GetProcAddress(("glVertexAttribI1i");
			glVertexAttribI2i = (PFNGLVERTEXATTRIBI2IPROC)GetProcAddress(("glVertexAttribI2i");
			glVertexAttribI3i = (PFNGLVERTEXATTRIBI3IPROC)GetProcAddress(("glVertexAttribI3i");
			glVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC)GetProcAddress(("glVertexAttribI4i");
			glVertexAttribI1ui = (PFNGLVERTEXATTRIBI1UIPROC)GetProcAddress(("glVertexAttribI1ui");
			glVertexAttribI2ui = (PFNGLVERTEXATTRIBI2UIPROC)GetProcAddress(("glVertexAttribI2ui");
			glVertexAttribI3ui = (PFNGLVERTEXATTRIBI3UIPROC)GetProcAddress(("glVertexAttribI3ui");
			glVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC)GetProcAddress(("glVertexAttribI4ui");
			glVertexAttribI1iv = (PFNGLVERTEXATTRIBI1IVPROC)GetProcAddress(("glVertexAttribI1iv");
			glVertexAttribI2iv = (PFNGLVERTEXATTRIBI2IVPROC)GetProcAddress(("glVertexAttribI2iv");
			glVertexAttribI3iv = (PFNGLVERTEXATTRIBI3IVPROC)GetProcAddress(("glVertexAttribI3iv");
			glVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC)GetProcAddress(("glVertexAttribI4iv");
			glVertexAttribI1uiv = (PFNGLVERTEXATTRIBI1UIVPROC)GetProcAddress(("glVertexAttribI1uiv");
			glVertexAttribI2uiv = (PFNGLVERTEXATTRIBI2UIVPROC)GetProcAddress(("glVertexAttribI2uiv");
			glVertexAttribI3uiv = (PFNGLVERTEXATTRIBI3UIVPROC)GetProcAddress(("glVertexAttribI3uiv");
			glVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC)GetProcAddress(("glVertexAttribI4uiv");
			glVertexAttribI4bv = (PFNGLVERTEXATTRIBI4BVPROC)GetProcAddress(("glVertexAttribI4bv");
			glVertexAttribI4sv = (PFNGLVERTEXATTRIBI4SVPROC)GetProcAddress(("glVertexAttribI4sv");
			glVertexAttribI4ubv = (PFNGLVERTEXATTRIBI4UBVPROC)GetProcAddress(("glVertexAttribI4ubv");
			glVertexAttribI4usv = (PFNGLVERTEXATTRIBI4USVPROC)GetProcAddress(("glVertexAttribI4usv");
			glGetUniformuiv = (PFNGLGETUNIFORMUIVPROC)GetProcAddress(("glGetUniformuiv");
			glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC)GetProcAddress(("glBindFragDataLocation");
			glGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC)GetProcAddress(("glGetFragDataLocation");
			glUniform1ui = (PFNGLUNIFORM1UIPROC)GetProcAddress(("glUniform1ui");
			glUniform2ui = (PFNGLUNIFORM2UIPROC)GetProcAddress(("glUniform2ui");
			glUniform3ui = (PFNGLUNIFORM3UIPROC)GetProcAddress(("glUniform3ui");
			glUniform4ui = (PFNGLUNIFORM4UIPROC)GetProcAddress(("glUniform4ui");
			glUniform1uiv = (PFNGLUNIFORM1UIVPROC)GetProcAddress(("glUniform1uiv");
			glUniform2uiv = (PFNGLUNIFORM2UIVPROC)GetProcAddress(("glUniform2uiv");
			glUniform3uiv = (PFNGLUNIFORM3UIVPROC)GetProcAddress(("glUniform3uiv");
			glUniform4uiv = (PFNGLUNIFORM4UIVPROC)GetProcAddress(("glUniform4uiv");
			glTexParameterIiv = (PFNGLTEXPARAMETERIIVPROC)GetProcAddress(("glTexParameterIiv");
			glTexParameterIuiv = (PFNGLTEXPARAMETERIUIVPROC)GetProcAddress(("glTexParameterIuiv");
			glGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIVPROC)GetProcAddress(("glGetTexParameterIiv");
			glGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIVPROC)GetProcAddress(("glGetTexParameterIuiv");
			glClearBufferiv = (PFNGLCLEARBUFFERIVPROC)GetProcAddress(("glClearBufferiv");
			glClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC)GetProcAddress(("glClearBufferuiv");
			glClearBufferfv = (PFNGLCLEARBUFFERFVPROC)GetProcAddress(("glClearBufferfv");
			glClearBufferfi = (PFNGLCLEARBUFFERFIPROC)GetProcAddress(("glClearBufferfi");
			glGetStringi = (PFNGLGETSTRINGIPROC)GetProcAddress(("glGetStringi");
			glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC)GetProcAddress(("glIsRenderbuffer");
			glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)GetProcAddress(("glBindRenderbuffer");
			glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)GetProcAddress(("glDeleteRenderbuffers");
			glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)GetProcAddress(("glGenRenderbuffers");
			glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)GetProcAddress(("glRenderbufferStorage");
			glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)GetProcAddress(("glGetRenderbufferParameteriv");
			glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC)GetProcAddress(("glIsFramebuffer");
			glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)GetProcAddress(("glBindFramebuffer");
			glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)GetProcAddress(("glDeleteFramebuffers");
			glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)GetProcAddress(("glGenFramebuffers");
			glCheckFrameBufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)GetProcAddress(("glCheckFramebufferStatus");
			glFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1DPROC)GetProcAddress(("glFramebufferTexture1D");
			glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)GetProcAddress(("glFramebufferTexture2D");
			glFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3DPROC)GetProcAddress(("glFramebufferTexture3D");
			glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)GetProcAddress(("glFramebufferRenderbuffer");
			glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)GetProcAddress(("glGetFramebufferAttachmentParameteriv");
			glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)GetProcAddress(("glGenerateMipmap");
			glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)GetProcAddress(("glBlitFramebuffer");
			glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)GetProcAddress(("glRenderbufferStorageMultisample");
			glFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)GetProcAddress(("glFramebufferTextureLayer");
			glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC)GetProcAddress(("glMapBufferRange");
			glFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)GetProcAddress(("glFlushMappedBufferRange");
			glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)GetProcAddress(("glBindVertexArray");
			glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)GetProcAddress(("glDeleteVertexArrays");
			glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)GetProcAddress(("glGenVertexArrays");
			glIsVertexArray = (PFNGLISVERTEXARRAYPROC)GetProcAddress(("glIsVertexArray");
		}

		static inline GLvoid Load3_1Extensions()
		{
			glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)GetProcAddress(("glDrawArraysInstanced");
			glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC)GetProcAddress(("glDrawElementsInstanced");
			glTexBuffer = (PFNGLTEXBUFFERPROC)GetProcAddress(("glTexBuffer");
			glPrimitiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEXPROC)GetProcAddress(("glPrimitiveRestartIndex");
			glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC)GetProcAddress(("glCopyBufferSubData");
			glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC)GetProcAddress(("glGetUniformIndices");
			glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)GetProcAddress(("glGetActiveUniformsiv");
			glGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC)GetProcAddress(("glGetActiveUniformName");
			glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)GetProcAddress(("glGetUniformBlockIndex");
			glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)GetProcAddress(("glGetActiveUniformBlockiv");
			glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)GetProcAddress(("glGetActiveUniformBlockName");
			glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC)GetProcAddress(("glUniformBlockBinding");
		}

		static inline GLvoid Load3_2Extensions()
		{
			glDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC)GetProcAddress(("glDrawElementsBaseVertex");
			glDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)GetProcAddress(("glDrawRangeElementsBaseVertex");
			glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)GetProcAddress(("glDrawElementsInstancedBaseVertex");
			glMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)GetProcAddress(("glMultiDrawElementsBaseVertex");
			glProvokingVertex = (PFNGLPROVOKINGVERTEXPROC)GetProcAddress(("glProvokingVertex");
			glFenceSync = (PFNGLFENCESYNCPROC)GetProcAddress(("glFenceSync");
			glIsSync = (PFNGLISSYNCPROC)GetProcAddress(("glIsSync");
			glDeleteSync = (PFNGLDELETESYNCPROC)GetProcAddress(("glDeleteSync");
			glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC)GetProcAddress(("glClientWaitSync");
			glWaitSync = (PFNGLWAITSYNCPROC)GetProcAddress(("glWaitSync");
			glGetInteger64v = (PFNGLGETINTEGER64VPROC)GetProcAddress(("glGetInteger64v");
			glGetSynciv = (PFNGLGETSYNCIVPROC)GetProcAddress(("glGetSynciv");
			glGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC)GetProcAddress(("glGetInteger64i_v");
			glGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC)GetProcAddress(("glGetBufferParameteri64v");
			glFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC)GetProcAddress(("glFramebufferTexture");
			glTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC)GetProcAddress(("glTexImage2DMultisample");
			glTexImage3DMultisample = (PFNGLTEXIMAGE3DMULTISAMPLEPROC)GetProcAddress(("glTexImage3DMultisample");
			glGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC)GetProcAddress(("glGetMultisamplefv");
			glSampleMaski = (PFNGLSAMPLEMASKIPROC)GetProcAddress(("glSampleMaski");
		}

		static inline GLvoid Load3_3Extensions()
		{
			glBindFragDataLocationIndexed = (PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)GetProcAddress(("glBindFragDataLocationIndexed");
			glGetFragDataIndex = (PFNGLGETFRAGDATAINDEXPROC)GetProcAddress(("glGetFragDataIndex");
			glGenSamplers = (PFNGLGENSAMPLERSPROC)GetProcAddress(("glGenSamplers");
			glDeleteSamplers = (PFNGLDELETESAMPLERSPROC)GetProcAddress(("glDeleteSamplers");
			glIsSampler = (PFNGLISSAMPLERPROC)GetProcAddress(("glIsSampler");
			glBindSampler = (PFNGLBINDSAMPLERPROC)GetProcAddress(("glBindSampler");
			glSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC)GetProcAddress(("glSamplerParameteri");
			glSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC)GetProcAddress(("glSamplerParameteriv");
			glSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC)GetProcAddress(("glSamplerParameterf");
			glSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC)GetProcAddress(("glSamplerParameterfv");
			glSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIVPROC)GetProcAddress(("glSamplerParameterIiv");
			glSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIVPROC)GetProcAddress(("glSamplerParameterIuiv");
			glGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC)GetProcAddress(("glGetSamplerParameteriv");
			glGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIVPROC)GetProcAddress(("glGetSamplerParameterIiv");
			glGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC)GetProcAddress(("glGetSamplerParameterfv");
			glGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIVPROC)GetProcAddress(("glGetSamplerParameterIuiv");
			glQueryCounter = (PFNGLQUERYCOUNTERPROC)GetProcAddress(("glQueryCounter");
			glGetQueryObjecti64v = (PFNGLGETQUERYOBJECTI64VPROC)GetProcAddress(("glGetQueryObjecti64v");
			glGetQueryObjectui64v = (PFNGLGETQUERYOBJECTUI64VPROC)GetProcAddress(("glGetQueryObjectui64v");
			glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC)GetProcAddress(("glVertexAttribDivisor");
			glVertexAttribP1ui = (PFNGLVERTEXATTRIBP1UIPROC)GetProcAddress(("glVertexAttribP1ui");
			glVertexAttribP1uiv = (PFNGLVERTEXATTRIBP1UIVPROC)GetProcAddress(("glVertexAttribP1uiv");
			glVertexAttribP2ui = (PFNGLVERTEXATTRIBP2UIPROC)GetProcAddress(("glVertexAttribP2ui");
			glVertexAttribP2uiv = (PFNGLVERTEXATTRIBP2UIVPROC)GetProcAddress(("glVertexAttribP2uiv");
			glVertexAttribP3ui = (PFNGLVERTEXATTRIBP3UIPROC)GetProcAddress(("glVertexAttribP3ui");
			glVertexAttribP3uiv = (PFNGLVERTEXATTRIBP3UIVPROC)GetProcAddress(("glVertexAttribP3uiv");
			glVertexAttribP4ui = (PFNGLVERTEXATTRIBP4UIPROC)GetProcAddress(("glVertexAttribP4ui");
			glVertexAttribP4uiv = (PFNGLVERTEXATTRIBP4UIVPROC)GetProcAddress(("glVertexAttribP4uiv");
			glVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC)GetProcAddress(("glVertexAttrib4uiv");
			glVertexP2ui = (PFNGLVERTEXP2UIPROC)GetProcAddress(("glVertexP2ui");
			glVertexP2uiv = (PFNGLVERTEXP2UIVPROC)GetProcAddress(("glVertexP2uiv");
			glVertexP3ui = (PFNGLVERTEXP3UIPROC)GetProcAddress(("glVertexP3ui");
			glVertexP3uiv = (PFNGLVERTEXP3UIVPROC)GetProcAddress(("glVertexP3uiv");
			glVertexP4ui = (PFNGLVERTEXP4UIPROC)GetProcAddress(("glVertexP4ui");
			glVertexP4uiv = (PFNGLVERTEXP4UIVPROC)GetProcAddress(("glVertexP4uiv");
			glTexCoordP1ui = (PFNGLTEXCOORDP1UIPROC)GetProcAddress(("glTexCoordP1ui");
			glTexCoordP1uiv = (PFNGLTEXCOORDP1UIVPROC)GetProcAddress(("glTexCoordP1uiv");
			glTexCoordP2ui = (PFNGLTEXCOORDP2UIPROC)GetProcAddress(("glTexCoordP2ui");
			glTexCoordP2uiv = (PFNGLTEXCOORDP2UIVPROC)GetProcAddress(("glTexCoordP2uiv");
			glTexCoordP3ui = (PFNGLTEXCOORDP3UIPROC)GetProcAddress(("glTexCoordP3ui");
			glTexCoordP3uiv = (PFNGLTEXCOORDP3UIVPROC)GetProcAddress(("glTexCoordP3uiv");
			glTexCoordP4ui = (PFNGLTEXCOORDP4UIPROC)GetProcAddress(("glTexCoordP4ui");
			glTexCoordP4uiv = (PFNGLTEXCOORDP4UIVPROC)GetProcAddress(("glTexCoordP4uiv");
			glMultiTexCoordP1ui = (PFNGLMULTITEXCOORDP1UIPROC)GetProcAddress(("glMultiTexCoordP1ui");
			glMultiTexCoordP1uiv = (PFNGLMULTITEXCOORDP1UIVPROC)GetProcAddress(("glMultiTexCoordP1uiv");
			glMultiTexCoordP2ui = (PFNGLMULTITEXCOORDP2UIPROC)GetProcAddress(("glMultiTexCoordP2ui");
			glMultiTexCoordP2uiv = (PFNGLMULTITEXCOORDP2UIVPROC)GetProcAddress(("glMultiTexCoordP2uiv");
			glMultiTexCoordP3ui = (PFNGLMULTITEXCOORDP3UIPROC)GetProcAddress(("glMultiTexCoordP3ui");
			glMultiTexCoordP3uiv = (PFNGLMULTITEXCOORDP3UIVPROC)GetProcAddress(("glMultiTexCoordP3uiv");
			glMultiTexCoordP4ui = (PFNGLMULTITEXCOORDP4UIPROC)GetProcAddress(("glMultiTexCoordP4ui");
			glMultiTexCoordP4uiv = (PFNGLMULTITEXCOORDP4UIVPROC)GetProcAddress(("glMultiTexCoordP4uiv");
			glNormalP3ui = (PFNGLNORMALP3UIPROC)GetProcAddress(("glNormalP3ui");
			glNormalP3uiv = (PFNGLNORMALP3UIVPROC)GetProcAddress(("glNormalP3uiv");
			glColorP3ui = (PFNGLCOLORP3UIPROC)GetProcAddress(("glColorP3ui");
			glColorP3uiv = (PFNGLCOLORP3UIVPROC)GetProcAddress(("glColorP3uiv");
			glColorP4ui = (PFNGLCOLORP4UIPROC)GetProcAddress(("glColorP4ui");
			glColorP4uiv = (PFNGLCOLORP4UIVPROC)GetProcAddress(("glColorP4uiv");
			glSecondaryColorP3ui = (PFNGLSECONDARYCOLORP3UIPROC)GetProcAddress(("glSecondaryColorP3ui");
			glSecondaryColorP3uiv = (PFNGLSECONDARYCOLORP3UIVPROC)GetProcAddress(("glSecondaryColorP3uiv");
		}

		static inline GLvoid Load4_0Extensions()
		{
			glMinSampleShading = (PFNGLMINSAMPLESHADINGPROC)GetProcAddress(("glMinSampleShading");
			glBlendEquationi = (PFNGLBLENDEQUATIONIPROC)GetProcAddress(("glBlendEquationi");
			glBlendEquationSeparatei = (PFNGLBLENDEQUATIONSEPARATEIPROC)GetProcAddress(("glBlendEquationSeparatei");
			glBlendFunci = (PFNGLBLENDFUNCIPROC)GetProcAddress(("glBlendFunci");
			glBlendFuncSeparatei = (PFNGLBLENDFUNCSEPARATEIPROC)GetProcAddress(("glBlendFuncSeparatei");
			glDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECTPROC)GetProcAddress(("glDrawArraysIndirect");
			glDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECTPROC)GetProcAddress(("glDrawElementsIndirect");
			glUniform1d = (PFNGLUNIFORM1DPROC)GetProcAddress(("glUniform1d");
			glUniform2d = (PFNGLUNIFORM2DPROC)GetProcAddress(("glUniform2d");
			glUniform3d = (PFNGLUNIFORM3DPROC)GetProcAddress(("glUniform3d");
			glUniform4d = (PFNGLUNIFORM4DPROC)GetProcAddress(("glUniform4d");
			glUniform1dv = (PFNGLUNIFORM1DVPROC)GetProcAddress(("glUniform1dv");
			glUniform2dv = (PFNGLUNIFORM2DVPROC)GetProcAddress(("glUniform2dv");
			glUniform3dv = (PFNGLUNIFORM3DVPROC)GetProcAddress(("glUniform3dv");
			glUniform4dv = (PFNGLUNIFORM4DVPROC)GetProcAddress(("glUniform4dv");
			glUniformMatrix2dv = (PFNGLUNIFORMMATRIX2DVPROC)GetProcAddress(("glUniformMatrix2dv");
			glUniformMatrix3dv = (PFNGLUNIFORMMATRIX3DVPROC)GetProcAddress(("glUniformMatrix3dv");
			glUniformMatrix4dv = (PFNGLUNIFORMMATRIX4DVPROC)GetProcAddress(("glUniformMatrix4dv");
			glUniformMatrix2x3dv = (PFNGLUNIFORMMATRIX2X3DVPROC)GetProcAddress(("glUniformMatrix2x3dv");
			glUniformMatrix2x4dv = (PFNGLUNIFORMMATRIX2X4DVPROC)GetProcAddress(("glUniformMatrix2x4dv");
			glUniformMatrix3x2dv = (PFNGLUNIFORMMATRIX3X2DVPROC)GetProcAddress(("glUniformMatrix3x2dv");
			glUniformMatrix3x4dv = (PFNGLUNIFORMMATRIX3X4DVPROC)GetProcAddress(("glUniformMatrix3x4dv");
			glUniformMatrix4x2dv = (PFNGLUNIFORMMATRIX4X2DVPROC)GetProcAddress(("glUniformMatrix4x2dv");
			glUniformMatrix4x3dv = (PFNGLUNIFORMMATRIX4X3DVPROC)GetProcAddress(("glUniformMatrix4x3dv");
			glGetUniformdv = (PFNGLGETUNIFORMDVPROC)GetProcAddress(("glGetUniformdv");
			glGetSubroutineUniformLocation = (PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)GetProcAddress(("glGetSubroutineUniformLocation");
			glGetSubroutineIndex = (PFNGLGETSUBROUTINEINDEXPROC)GetProcAddress(("glGetSubroutineIndex");
			glGetActiveSubroutineUniformiv = (PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)GetProcAddress(("glGetActiveSubroutineUniformiv");
			glGetActiveSubroutineUniformName = (PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)GetProcAddress(("glGetActiveSubroutineUniformName");
			glGetActiveSubroutineName = (PFNGLGETACTIVESUBROUTINENAMEPROC)GetProcAddress(("glGetActiveSubroutineName");
			glUniformSubroutinesuiv = (PFNGLUNIFORMSUBROUTINESUIVPROC)GetProcAddress(("glUniformSubroutinesuiv");
			glGetUniformSubroutineuiv = (PFNGLGETUNIFORMSUBROUTINEUIVPROC)GetProcAddress(("glGetUniformSubroutineuiv");
			glGetProgramStageiv = (PFNGLGETPROGRAMSTAGEIVPROC)GetProcAddress(("glGetProgramStageiv");
			glPatchParameteri = (PFNGLPATCHPARAMETERIPROC)GetProcAddress(("glPatchParameteri");
			glPatchParameterfv = (PFNGLPATCHPARAMETERFVPROC)GetProcAddress(("glPatchParameterfv");
			glBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACKPROC)GetProcAddress(("glBindTransformFeedback");
			glDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKSPROC)GetProcAddress(("glDeleteTransformFeedbacks");
			glGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKSPROC)GetProcAddress(("glGenTransformFeedbacks");
			glIsTransformFeedback = (PFNGLISTRANSFORMFEEDBACKPROC)GetProcAddress(("glIsTransformFeedback");
			glPauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACKPROC)GetProcAddress(("glPauseTransformFeedback");
			glResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACKPROC)GetProcAddress(("glResumeTransformFeedback");
			glDrawTransformFeedback = (PFNGLDRAWTRANSFORMFEEDBACKPROC)GetProcAddress(("glDrawTransformFeedback");
			glDrawTransformFeedbackStream = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)GetProcAddress(("glDrawTransformFeedbackStream");
			glBeginQueryIndexed = (PFNGLBEGINQUERYINDEXEDPROC)GetProcAddress(("glBeginQueryIndexed");
			glEndQueryIndexed = (PFNGLENDQUERYINDEXEDPROC)GetProcAddress(("glEndQueryIndexed");
			glGetQueryIndexediv = (PFNGLGETQUERYINDEXEDIVPROC)GetProcAddress(("glGetQueryIndexediv");
		}

		static inline GLvoid Load4_1Extensions()
		{
			glReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILERPROC)GetProcAddress(("glReleaseShaderCompiler");
			glShaderBinary = (PFNGLSHADERBINARYPROC)GetProcAddress(("glShaderBinary");
			glGetShaderPrecisionFormat = (PFNGLGETSHADERPRECISIONFORMATPROC)GetProcAddress(("glGetShaderPrecisionFormat");
			glDepthRangef = (PFNGLDEPTHRANGEFPROC)GetProcAddress(("glDepthRangef");
			glClearDepthf = (PFNGLCLEARDEPTHFPROC)GetProcAddress(("glClearDepthf");
			glGetProgramBinary = (PFNGLGETPROGRAMBINARYPROC)GetProcAddress(("glGetProgramBinary");
			glProgramBinary = (PFNGLPROGRAMBINARYPROC)GetProcAddress(("glProgramBinary");
			glProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC)GetProcAddress(("glProgramParameteri");
			glUseProgramStages = (PFNGLUSEPROGRAMSTAGESPROC)GetProcAddress(("glUseProgramStages");
			glActiveShaderProgram = (PFNGLACTIVESHADERPROGRAMPROC)GetProcAddress(("glActiveShaderProgram");
			glCreateShaderProgramv = (PFNGLCREATESHADERPROGRAMVPROC)GetProcAddress(("glCreateShaderProgramv");
			glBindProgramPipeline = (PFNGLBINDPROGRAMPIPELINEPROC)GetProcAddress(("glBindProgramPipeline");
			glDeleteProgramPipelines = (PFNGLDELETEPROGRAMPIPELINESPROC)GetProcAddress(("glDeleteProgramPipelines");
			glGenProgramPipelines = (PFNGLGENPROGRAMPIPELINESPROC)GetProcAddress(("glGenProgramPipelines");
			glIsProgramPipeline = (PFNGLISPROGRAMPIPELINEPROC)GetProcAddress(("glIsProgramPipeline");
			glGetProgramPipelineiv = (PFNGLGETPROGRAMPIPELINEIVPROC)GetProcAddress(("glGetProgramPipelineiv");
			glProgramUniform1i = (PFNGLPROGRAMUNIFORM1IPROC)GetProcAddress(("glProgramUniform1i");
			glProgramUniform1iv = (PFNGLPROGRAMUNIFORM1IVPROC)GetProcAddress(("glProgramUniform1iv");
			glProgramUniform1f = (PFNGLPROGRAMUNIFORM1FPROC)GetProcAddress(("glProgramUniform1f");
			glProgramUniform1fv = (PFNGLPROGRAMUNIFORM1FVPROC)GetProcAddress(("glProgramUniform1fv");
			glProgramUniform1d = (PFNGLPROGRAMUNIFORM1DPROC)GetProcAddress(("glProgramUniform1d");
			glProgramUniform1dv = (PFNGLPROGRAMUNIFORM1DVPROC)GetProcAddress(("glProgramUniform1dv");
			glProgramUniform1ui = (PFNGLPROGRAMUNIFORM1UIPROC)GetProcAddress(("glProgramUniform1ui");
			glProgramUniform1uiv = (PFNGLPROGRAMUNIFORM1UIVPROC)GetProcAddress(("glProgramUniform1uiv");
			glProgramUniform2i = (PFNGLPROGRAMUNIFORM2IPROC)GetProcAddress(("glProgramUniform2i");
			glProgramUniform2iv = (PFNGLPROGRAMUNIFORM2IVPROC)GetProcAddress(("glProgramUniform2iv");
			glProgramUniform2f = (PFNGLPROGRAMUNIFORM2FPROC)GetProcAddress(("glProgramUniform2f");
			glProgramUniform2fv = (PFNGLPROGRAMUNIFORM2FVPROC)GetProcAddress(("glProgramUniform2fv");
			glProgramUniform2d = (PFNGLPROGRAMUNIFORM2DPROC)GetProcAddress(("glProgramUniform2d");
			glProgramUniform2dv = (PFNGLPROGRAMUNIFORM2DVPROC)GetProcAddress(("glProgramUniform2dv");
			glProgramUniform2ui = (PFNGLPROGRAMUNIFORM2UIPROC)GetProcAddress(("glProgramUniform2ui");
			glProgramUniform2uiv = (PFNGLPROGRAMUNIFORM2UIVPROC)GetProcAddress(("glProgramUniform2uiv");
			glProgramUniform3i = (PFNGLPROGRAMUNIFORM3IPROC)GetProcAddress(("glProgramUniform3i");
			glProgramUniform3iv = (PFNGLPROGRAMUNIFORM3IVPROC)GetProcAddress(("glProgramUniform3iv");
			glProgramUniform3f = (PFNGLPROGRAMUNIFORM3FPROC)GetProcAddress(("glProgramUniform3f");
			glProgramUniform3fv = (PFNGLPROGRAMUNIFORM3FVPROC)GetProcAddress(("glProgramUniform3fv");
			glProgramUniform3d = (PFNGLPROGRAMUNIFORM3DPROC)GetProcAddress(("glProgramUniform3d");
			glProgramUniform3dv = (PFNGLPROGRAMUNIFORM3DVPROC)GetProcAddress(("glProgramUniform3dv");
			glProgramUniform3ui = (PFNGLPROGRAMUNIFORM3UIPROC)GetProcAddress(("glProgramUniform3ui");
			glProgramUniform3uiv = (PFNGLPROGRAMUNIFORM3UIVPROC)GetProcAddress(("glProgramUniform3uiv");
			glProgramUniform4i = (PFNGLPROGRAMUNIFORM4IPROC)GetProcAddress(("glProgramUniform4i");
			glProgramUniform4iv = (PFNGLPROGRAMUNIFORM4IVPROC)GetProcAddress(("glProgramUniform4iv");
			glProgramUniform4f = (PFNGLPROGRAMUNIFORM4FPROC)GetProcAddress(("glProgramUniform4f");
			glProgramUniform4fv = (PFNGLPROGRAMUNIFORM4FVPROC)GetProcAddress(("glProgramUniform4fv");
			glProgramUniform4d = (PFNGLPROGRAMUNIFORM4DPROC)GetProcAddress(("glProgramUniform4d");
			glProgramUniform4dv = (PFNGLPROGRAMUNIFORM4DVPROC)GetProcAddress(("glProgramUniform4dv");
			glProgramUniform4ui = (PFNGLPROGRAMUNIFORM4UIPROC)GetProcAddress(("glProgramUniform4ui");
			glProgramUniform4uiv = (PFNGLPROGRAMUNIFORM4UIVPROC)GetProcAddress(("glProgramUniform4uiv");
			glProgramUniformMatrix2fv = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC)GetProcAddress(("glProgramUniformMatrix2fv");
			glProgramUniformMatrix3fv = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC)GetProcAddress(("glProgramUniformMatrix3fv");
			glProgramUniformMatrix4fv = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC)GetProcAddress(("glProgramUniformMatrix4fv");
			glProgramUniformMatrix2dv = (PFNGLPROGRAMUNIFORMMATRIX2DVPROC)GetProcAddress(("glProgramUniformMatrix2dv");
			glProgramUniformMatrix3dv = (PFNGLPROGRAMUNIFORMMATRIX3DVPROC)GetProcAddress(("glProgramUniformMatrix3dv");
			glProgramUniformMatrix4dv = (PFNGLPROGRAMUNIFORMMATRIX4DVPROC)GetProcAddress(("glProgramUniformMatrix4dv");
			glProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)GetProcAddress(("glProgramUniformMatrix2x3fv");
			glProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)GetProcAddress(("glProgramUniformMatrix3x2fv");
			glProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)GetProcAddress(("glProgramUniformMatrix2x4fv");
			glProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)GetProcAddress(("glProgramUniformMatrix4x2fv");
			glProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)GetProcAddress(("glProgramUniformMatrix3x4fv");
			glProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)GetProcAddress(("glProgramUniformMatrix4x3fv");
			glProgramUniformMatrix2x3dv = (PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)GetProcAddress(("glProgramUniformMatrix2x3dv");
			glProgramUniformMatrix3x2dv = (PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)GetProcAddress(("glProgramUniformMatrix3x2dv");
			glProgramUniformMatrix2x4dv = (PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)GetProcAddress(("glProgramUniformMatrix2x4dv");
			glProgramUniformMatrix4x2dv = (PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)GetProcAddress(("glProgramUniformMatrix4x2dv");
			glProgramUniformMatrix3x4dv = (PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)GetProcAddress(("glProgramUniformMatrix3x4dv");
			glProgramUniformMatrix4x3dv = (PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)GetProcAddress(("glProgramUniformMatrix4x3dv");
			glValidateProgramPipeline = (PFNGLVALIDATEPROGRAMPIPELINEPROC)GetProcAddress(("glValidateProgramPipeline");
			glGetProgramPipelineInfoLog = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC)GetProcAddress(("glGetProgramPipelineInfoLog");
			glVertexAttribL1d = (PFNGLVERTEXATTRIBL1DPROC)GetProcAddress(("glVertexAttribL1d");
			glVertexAttribL2d = (PFNGLVERTEXATTRIBL2DPROC)GetProcAddress(("glVertexAttribL2d");
			glVertexAttribL3d = (PFNGLVERTEXATTRIBL3DPROC)GetProcAddress(("glVertexAttribL3d");
			glVertexAttribL4d = (PFNGLVERTEXATTRIBL4DPROC)GetProcAddress(("glVertexAttribL4d");
			glVertexAttribL1dv = (PFNGLVERTEXATTRIBL1DVPROC)GetProcAddress(("glVertexAttribL1dv");
			glVertexAttribL2dv = (PFNGLVERTEXATTRIBL2DVPROC)GetProcAddress(("glVertexAttribL2dv");
			glVertexAttribL3dv = (PFNGLVERTEXATTRIBL3DVPROC)GetProcAddress(("glVertexAttribL3dv");
			glVertexAttribL4dv = (PFNGLVERTEXATTRIBL4DVPROC)GetProcAddress(("glVertexAttribL4dv");
			glVertexAttribLPointer = (PFNGLVERTEXATTRIBLPOINTERPROC)GetProcAddress(("glVertexAttribLPointer");
			glGetVertexAttribLdv = (PFNGLGETVERTEXATTRIBLDVPROC)GetProcAddress(("glGetVertexAttribLdv");
			glViewportarrayv = (PFNGLVIEWPORTARRAYVPROC)GetProcAddress(("glViewportArrayv");
			glViewportIndexedf = (PFNGLVIEWPORTINDEXEDFPROC)GetProcAddress(("glViewportIndexedf");
			glViewportIndexedfv = (PFNGLVIEWPORTINDEXEDFVPROC)GetProcAddress(("glViewportIndexedfv");
			glScissorArrayv = (PFNGLSCISSORARRAYVPROC)GetProcAddress(("glScissorArrayv");
			glScissorIndexed = (PFNGLSCISSORINDEXEDPROC)GetProcAddress(("glScissorIndexed");
			glScissorIndexedv = (PFNGLSCISSORINDEXEDVPROC)GetProcAddress(("glScissorIndexedv");
			glDepthRangeIndexed = (PFNGLDEPTHRANGEINDEXEDPROC)GetProcAddress(("glDepthRangeIndexed");
			glDepthRangeArrayv = (PFNGLDEPTHRANGEARRAYVPROC)GetProcAddress(("glDepthRangeArrayv");
			glGetFloati_v = (PFNGLGETFLOATI_VPROC)GetProcAddress(("glGetFloati_v");
			glGetDoublei_v = (PFNGLGETDOUBLEI_VPROC)GetProcAddress(("glGetDoublei_v");
		}

		static inline GLvoid Load4_2Extensions()
		{
			glDrawArraysInstancedBaseInstance = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)GetProcAddress(("glDrawArraysInstancedBaseInstance");
			glDrawElementsInstancedBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)GetProcAddress(("glDrawElementsInstancedBaseInstance");
			glDrawElementsInstancedBaseVertexBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)GetProcAddress(("glDrawElementsInstancedBaseVertexBaseInstance");
			glGetInternalformativ = (PFNGLGETINTERNALFORMATIVPROC)GetProcAddress(("glGetInternalformativ");
			glGetActiveAtomicCounterBufferiv = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)GetProcAddress(("glGetActiveAtomicCounterBufferiv");
			glBindImageTexture = (PFNGLBINDIMAGETEXTUREPROC)GetProcAddress(("glBindImageTexture");
			glMemoryBarrier = (PFNGLMEMORYBARRIERPROC)GetProcAddress(("glMemoryBarrier");
			glTexStorage1D = (PFNGLTEXSTORAGE1DPROC)GetProcAddress(("glTexStorage1D");
			glTexStorage2D = (PFNGLTEXSTORAGE2DPROC)GetProcAddress(("glTexStorage2D");
			glTexStorage3D = (PFNGLTEXSTORAGE3DPROC)GetProcAddress(("glTexStorage3D");
			glDrawTransformFeedbackInstanced = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)GetProcAddress(("glDrawTransformFeedbackInstanced");
			glDrawTransformFeedbackStreamInstanced = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)GetProcAddress(("glDrawTransformFeedbackStreamInstanced");
		}

		static inline GLvoid Load4_3Extensions()
		{
			glClearBufferData = (PFNGLCLEARBUFFERDATAPROC)GetProcAddress(("glClearBufferData");
			glClearBufferSubData = (PFNGLCLEARBUFFERSUBDATAPROC)GetProcAddress(("glClearBufferSubData");
			glDispatchCompute = (PFNGLDISPATCHCOMPUTEPROC)GetProcAddress(("glDispatchCompute");
			glDispatchComputeIndirect = (PFNGLDISPATCHCOMPUTEINDIRECTPROC)GetProcAddress(("glDispatchComputeIndirect");
			glCopyImageSubData = (PFNGLCOPYIMAGESUBDATAPROC)GetProcAddress(("glCopyImageSubData");
			glFramebufferParameteri = (PFNGLFRAMEBUFFERPARAMETERIPROC)GetProcAddress(("glFramebufferParameteri");
			glGetFramebufferParameteriv = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC)GetProcAddress(("glGetFramebufferParameteriv");
			glGetInternalformati64v = (PFNGLGETINTERNALFORMATI64VPROC)GetProcAddress(("glGetInternalformati64v");
			glInvalidateTexSubImage = (PFNGLINVALIDATETEXSUBIMAGEPROC)GetProcAddress(("glInvalidateTexSubImage");
			glInvalidateTexImage = (PFNGLINVALIDATETEXIMAGEPROC)GetProcAddress(("glInvalidateTexImage");
			glInvalidateBufferSubData = (PFNGLINVALIDATEBUFFERSUBDATAPROC)GetProcAddress(("glInvalidateBufferSubData");
			glInvalidateBufferData = (PFNGLINVALIDATEBUFFERDATAPROC)GetProcAddress(("glInvalidateBufferData");
			glInvalidateFramebuffer = (PFNGLINVALIDATEFRAMEBUFFERPROC)GetProcAddress(("glInvalidateFramebuffer");
			glInvalidateSubFramebuffer = (PFNGLINVALIDATESUBFRAMEBUFFERPROC)GetProcAddress(("glInvalidateSubFramebuffer");
			glMultiDrawArraysIndirect = (PFNGLMULTIDRAWARRAYSINDIRECTPROC)GetProcAddress(("glMultiDrawArraysIndirect");
			glMultiDrawElementsIndirect = (PFNGLMULTIDRAWELEMENTSINDIRECTPROC)GetProcAddress(("glMultiDrawElementsIndirect");
			glGetProgramInterfaceiv = (PFNGLGETPROGRAMINTERFACEIVPROC)GetProcAddress(("glGetProgramInterfaceiv");
			glGetProgramResourceIndex = (PFNGLGETPROGRAMRESOURCEINDEXPROC)GetProcAddress(("glGetProgramResourceIndex");
			glGetProgramResourceName = (PFNGLGETPROGRAMRESOURCENAMEPROC)GetProcAddress(("glGetProgramResourceName");
			glGetProgramResourceiv = (PFNGLGETPROGRAMRESOURCEIVPROC)GetProcAddress(("glGetProgramResourceiv");
			glGetProgramResourceLocation = (PFNGLGETPROGRAMRESOURCELOCATIONPROC)GetProcAddress(("glGetProgramResourceLocation");
			glGetProgramResourceLocationIndex = (PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)GetProcAddress(("glGetProgramResourceLocationIndex");
			glShaderStorageBlockBinding = (PFNGLSHADERSTORAGEBLOCKBINDINGPROC)GetProcAddress(("glShaderStorageBlockBinding");
			glTexBufferRange = (PFNGLTEXBUFFERRANGEPROC)GetProcAddress(("glTexBufferRange");
			glTexStorage2DMultisample = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC)GetProcAddress(("glTexStorage2DMultisample");
			glTexStorage3DMultisample = (PFNGLTEXSTORAGE3DMULTISAMPLEPROC)GetProcAddress(("glTexStorage3DMultisample");
			glTextureView = (PFNGLTEXTUREVIEWPROC)GetProcAddress(("glTextureView");
			glBindVertexBuffer = (PFNGLBINDVERTEXBUFFERPROC)GetProcAddress(("glBindVertexBuffer");
			glVertexAttribFormat = (PFNGLVERTEXATTRIBFORMATPROC)GetProcAddress(("glVertexAttribFormat");
			glVertexAttribIFormat = (PFNGLVERTEXATTRIBIFORMATPROC)GetProcAddress(("glVertexAttribIFormat");
			glVertexAttribLFormat = (PFNGLVERTEXATTRIBLFORMATPROC)GetProcAddress(("glVertexAttribLFormat");
			glVertexAttribBinding = (PFNGLVERTEXATTRIBBINDINGPROC)GetProcAddress(("glVertexAttribBinding");
			glVertexBindingDivisor = (PFNGLVERTEXBINDINGDIVISORPROC)GetProcAddress(("glVertexBindingDivisor");
			glDebugMessageControl = (PFNGLDEBUGMESSAGECONTROLPROC)GetProcAddress(("glDebugMessageControl");
			glDebugMessageInsert = (PFNGLDEBUGMESSAGEINSERTPROC)GetProcAddress(("glDebugMessageInsert");
			glDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC)GetProcAddress(("glDebugMessageCallback");
			glGetDebugMessageLog = (PFNGLGETDEBUGMESSAGELOGPROC)GetProcAddress(("glGetDebugMessageLog");
			glPushDebugGroup = (PFNGLPUSHDEBUGGROUPPROC)GetProcAddress(("glPushDebugGroup");
			glPopDebugGroup = (PFNGLPOPDEBUGGROUPPROC)GetProcAddress(("glPopDebugGroup");
			glObjectLabel = (PFNGLOBJECTLABELPROC)GetProcAddress(("glObjectLabel");
			glObjectPtrLabel = (PFNGLOBJECTPTRLABELPROC)GetProcAddress(("glObjectPtrLabel");
			glGetObjectLabel = (PFNGLGETOBJECTLABELPROC)GetProcAddress(("glGetObjectLabel");
			glGetObjectPtrLabel = (PFNGLGETOBJECTPTRLABELPROC)GetProcAddress(("glGetObjectPtrLabel");
		}

		static inline GLvoid Load4_4Extensions()
		{
			glBufferStorage = (PFNGLBUFFERSTORAGEPROC)GetProcAddress(("glBufferStorage");
			glClearTexImage = (PFNGLCLEARTEXIMAGEPROC)GetProcAddress(("glClearTexImage");
			glClearTexSubImage = (PFNGLCLEARTEXSUBIMAGEPROC)GetProcAddress(("glClearTexSubImage");
			glBindBuffersBase = (PFNGLBINDBUFFERSBASEPROC)GetProcAddress(("glBindBuffersBase");
			glBindBuffersRange = (PFNGLBINDBUFFERSRANGEPROC)GetProcAddress(("glBindBuffersRange");
			glBindTextures = (PFNGLBINDTEXTURESPROC)GetProcAddress(("glBindTextures");
			glBindSamplers = (PFNGLBINDSAMPLERSPROC)GetProcAddress(("glBindSamplers");
			glBindImageTextures = (PFNGLBINDIMAGETEXTURESPROC)GetProcAddress(("glBindImageTextures");
			glBindVertexBuffers = (PFNGLBINDVERTEXBUFFERSPROC)GetProcAddress(("glBindVertexBuffers");
		}*/

	};

}

/*
class TinyExtender
{
public:
	
	TinyExtender(){}
	~TinyExtender(){}

	static GLvoid InitializeExtensions()
	{
		TinyExtender::InitializeGLVersion();
		GLuint Version_Major, Version_Minor;
		Version_Major = TinyExtender::GLVersion_Major;
		Version_Minor = TinyExtender::GLVersion_Minor;

		//this was a bad idea...
		//(Version_Major >= 1 && Version_Minor >= 2) ? Load1_2Extensions() : TinyExtender::PrintErrorMessage(Version_Major, Version_Minor);

		if (Version_Major > 1 || (Version_Minor >= 2 && Version_Major >= 1))
		{
			//Load1_2Extensions();
		}

		else
		{
			TinyExtender::PrintErrorMessage(1, 2);
			return;
		}

		if (Version_Major > 1 || (Version_Minor >= 3 && Version_Major >= 1))
		{
			//Load1_3Extensions();
		}

		else
		{
			TinyExtender::PrintErrorMessage(1, 3);
			return;
		}

		if (Version_Major > 1 || (Version_Minor >= 4 && Version_Major >= 1))
		{
			Load1_4Extensions();
		}

		else
		{
			TinyExtender::PrintErrorMessage(1, 4);
			return;
		}

		if (Version_Major > 1 || (Version_Minor >= 5 && Version_Major >= 1))
		{
			Load1_5Extensions();
		}

		else
		{
			TinyExtender::PrintErrorMessage(1, 5);
			return;
		}

		if (Version_Major > 2 || (Version_Minor >= 0 && Version_Major >= 2))
		{
			Load2_0Extensions();
		}

		else
		{
			TinyExtender::PrintErrorMessage(2, 0);
			return;
		}

		if (Version_Major > 2 || (Version_Minor >= 1 && Version_Major >= 2))
		{
			Load2_1Extensions();
		}

		else
		{
			TinyExtender::PrintErrorMessage(2, 1);
			return;
		}

		if (Version_Major > 3 || (Version_Minor >= 0 && Version_Major >= 3))
		{
			Load3_0Extensions();
		}

		else
		{
			TinyExtender::PrintErrorMessage(3, 0);
			return;
		}

		if (Version_Major > 3 || (Version_Minor >= 1 && Version_Major >= 3))
		{
			Load3_1Extensions();
		}

		else
		{
			TinyExtender::PrintErrorMessage(3, 1);
			return;
		}

		if (Version_Major > 3 || (Version_Minor >= 2 && Version_Major >= 3))
		{
			Load3_2Extensions();
		}

		else
		{
			TinyExtender::PrintErrorMessage(3, 2);
			return;
		}

		if (Version_Major > 3 || (Version_Minor >= 3 && Version_Major >= 3))
		{
			Load3_3Extensions();
		}

		else
		{
			TinyExtender::PrintErrorMessage(3, 3);
			return;
		}

		if (Version_Major > 4 || (Version_Minor >= 0 && Version_Major >= 4))
		{
			Load4_0Extensions();
		}

		else
		{
			TinyExtender::PrintErrorMessage(4, 0);
			return;
		}

		if (Version_Major > 4 || (Version_Minor >= 1 && Version_Major >= 4))
		{
			Load4_1Extensions();
		}

		else
		{
			TinyExtender::PrintErrorMessage(4, 1);
			return;
		}

		if (Version_Major > 4 || (Version_Minor >= 2 && Version_Major >= 4))
		{
			Load4_2Extensions();
		}

		else
		{
			TinyExtender::PrintErrorMessage(4, 2);
			return;
		}

		if (Version_Major > 4 || (Version_Minor >= 3 && Version_Minor >= 4))
		{
			Load4_3Extensions();
		}

		else
		{
			TinyExtender::PrintErrorMessage(4, 3);
		}

		if (Version_Major > 4 || (Version_Minor >= 4 && Version_Major >= 4))
		{
			Load4_4Extensions();
		}

		else
		{
			TinyExtender::PrintErrorMessage(4, 4);
			return;
		}
	}

	static GLvoid InitializeExtensionsSpecific(GLbitfield OpenGLVersions)
	{
		TinyExtender::InitializeGLVersion();
		GLuint Version_Major = TinyExtender::GLVersion_Major;
		GLuint Version_Minor = TinyExtender::GLVersion_Minor;

		if (OpenGLVersions & GLVERSION1_2)
		{
			if (Version_Major > 1 || (Version_Minor >= 2 && Version_Major >= 1))
			{
				//TinyExtender::Load1_2Extensions();
			}

			TinyExtender::PrintErrorMessage(1, 2);
		}

		if (OpenGLVersions & GLVERSION1_3)
		{
			if (Version_Major > 1 || (Version_Minor >= 3 && Version_Major >= 1))
			{
				//TinyExtender::Load1_3Extensions();
			}

			TinyExtender::PrintErrorMessage(1, 3);
		}

		if (OpenGLVersions & GLVERSION1_4)
		{
			if (Version_Major > 1 || (Version_Minor >= 4 && Version_Major >= 1))
			{
				//TinyExtender::Load1_4Extensions();
			}

			TinyExtender::PrintErrorMessage(1, 4);
		}

		if (OpenGLVersions & GLVERSION1_5)
		{
			if (Version_Major > 1 || (Version_Minor >= 5 && Version_Major >= 1))
			{
				TinyExtender::Load1_5Extensions();
			}

			TinyExtender::PrintErrorMessage(1, 5);
		}

		if (OpenGLVersions & GLVERSION2_0)
		{
			if (Version_Major > 2 || (Version_Minor >= 0 && Version_Major >= 2))
			{
				TinyExtender::Load2_0Extensions();
			}

			TinyExtender::PrintErrorMessage(2, 0);
		}

		if (OpenGLVersions & GLVERSION2_1)
		{
			if (Version_Major > 2 || (Version_Minor >= 1 && Version_Major >= 2))
			{
				TinyExtender::Load2_1Extensions();
			}

			TinyExtender::PrintErrorMessage(2, 1);
		}

		if (OpenGLVersions & GLVERSION3_0)
		{
			if (Version_Major > 3 || (Version_Minor >= 0 && Version_Major >= 3))
			{
				TinyExtender::Load3_0Extensions();
			}

			TinyExtender::PrintErrorMessage(3, 0);
		}

		if (OpenGLVersions & GLVERSION3_1)
		{
			if (Version_Major > 3 || (Version_Minor >= 1 && Version_Major >= 3))
			{
				TinyExtender::Load3_1Extensions();
			}

			TinyExtender::PrintErrorMessage(3, 1);
		}

		if (OpenGLVersions & GLVERSION3_2)
		{
			if (Version_Major > 3 || (Version_Minor >= 2 && Version_Major >= 3))
			{
				TinyExtender::Load3_2Extensions();
			}

			TinyExtender::PrintErrorMessage(3, 2);
		}

		if (OpenGLVersions & GLVERSION3_3)
		{
			if (Version_Major > 3 || (Version_Minor >= 3 && Version_Major >= 3))
			{
				TinyExtender::Load3_3Extensions();
			}

			TinyExtender::PrintErrorMessage(3, 3);
		}

		if (OpenGLVersions & GLVERSION4_0)
		{
			if (Version_Major > 4 || (Version_Minor >= 0 && Version_Major >= 4))
			{
				TinyExtender::Load4_0Extensions();
			}

			TinyExtender::PrintErrorMessage(4, 0);
		}

		if (OpenGLVersions & GLVERSION4_1)
		{
			if (Version_Major > 4 || (Version_Minor >= 1 && Version_Major >= 4))
			{
				TinyExtender::Load4_1Extensions();
			}

			TinyExtender::PrintErrorMessage(4, 1);
		}

		if (OpenGLVersions & GLVERSION4_2)
		{
			if (Version_Major > 4 || (Version_Minor >= 2 && Version_Major >= 4))
			{
				TinyExtender::Load4_2Extensions();
			}

			TinyExtender::PrintErrorMessage(4, 2);
		}

		if (OpenGLVersions & GLVERSION4_3)
		{
			if (Version_Major > 4 || (Version_Minor >= 3 && Version_Major >= 4))
			{
				TinyExtender::Load4_3Extensions();
			}

			TinyExtender::PrintErrorMessage(4, 3);
		}

		if (OpenGLVersions & GLVERSION4_4)
		{
			if (Version_Major > 4 || (Version_Minor >= 4 && Version_Major >= 4))
			{
				TinyExtender::Load4_4Extensions();
			}

			TinyExtender::PrintErrorMessage(4, 4);
		}
	}

	static GLvoid GetOpenGLVersion(GLuint& Version_Major, GLuint& Version_Minor)
	{
		Version_Major = TinyExtender::GLVersion_Major;
		Version_Minor = TinyExtender::GLVersion_Minor;
	}
	
	static GLboolean IsExtensionSupported(GLubyte* ExtensionName)
	{
		GLubyte* End; //the last extension name in Extensions 
		GLint NameLength; //the string length of the given extension

		NameLength = strlen((const char*)ExtensionName); // the length of the given extension name string 

		GLubyte* Extensions = (GLubyte*)glGetString(GL_EXTENSIONS); // get all supported extensions

		//if extensions is not empty
		if (Extensions)
		{
			End = Extensions + strlen((const char*)Extensions);

			while (Extensions < End)
			{
				GLint Blarg = strcspn((const char*)Extensions, " ");
				if ((NameLength == Blarg) && (strncmp((const char*)ExtensionName, (const char*)Extensions, Blarg) == 0))
				{
					return GL_TRUE;
				}

				Extensions += (Blarg + 1);
			}
			return GL_FALSE;
		}
		return GL_FALSE;
	}

private:
	static GLuint GLVersion_Major, GLVersion_Minor;

	static inline GLvoid Load3_0Extensions()
	{
		glColorMaski = (PFNGLCOLORMASKIPROC)GetProcAddress(("glColorMaski");
		glGetBooleani_v = (PFNGLGETBOOLEANI_VPROC)GetProcAddress(("glGetBooleani_v");
		glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC)GetProcAddress(("glGetIntegeri_v");
		glEnablei = (PFNGLENABLEIPROC)GetProcAddress(("glEnablei");
		glDisablei = (PFNGLDISABLEIPROC)GetProcAddress(("glDisablei");
		glIsEnabledi = (PFNGLISENABLEDIPROC)GetProcAddress(("glIsEnabledi");
		glBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC)GetProcAddress(("glBeginTransformFeedback");
		glEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC)GetProcAddress(("glEndTransformFeedback");
		glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)GetProcAddress(("glBindBufferRange");
		glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)GetProcAddress(("glBindBufferBase");
		glTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC)GetProcAddress(("glTransformFeedbackVaryings");
		glGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)GetProcAddress(("glGetTransformFeedbackVarying");
		glClampColor = (PFNGLCLAMPCOLORPROC)GetProcAddress(("glClampColor");
		glBeginConditionalRender = (PFNGLBEGINCONDITIONALRENDERPROC)GetProcAddress(("glBeginConditionalRender");
		glEndConditionalRender = (PFNGLENDCONDITIONALRENDERPROC)GetProcAddress(("glEndConditionalRender");
		glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC)GetProcAddress(("glVertexAttribIPointer");
		glGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC)GetProcAddress(("glGetVertexAttribIiv");
		glGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC)GetProcAddress(("glGetVertexAttribIuiv");
		glVertexAttribI1i = (PFNGLVERTEXATTRIBI1IPROC)GetProcAddress(("glVertexAttribI1i");
		glVertexAttribI2i = (PFNGLVERTEXATTRIBI2IPROC)GetProcAddress(("glVertexAttribI2i");
		glVertexAttribI3i = (PFNGLVERTEXATTRIBI3IPROC)GetProcAddress(("glVertexAttribI3i");
		glVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC)GetProcAddress(("glVertexAttribI4i");
		glVertexAttribI1ui = (PFNGLVERTEXATTRIBI1UIPROC)GetProcAddress(("glVertexAttribI1ui");
		glVertexAttribI2ui = (PFNGLVERTEXATTRIBI2UIPROC)GetProcAddress(("glVertexAttribI2ui");
		glVertexAttribI3ui = (PFNGLVERTEXATTRIBI3UIPROC)GetProcAddress(("glVertexAttribI3ui");
		glVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC)GetProcAddress(("glVertexAttribI4ui");
		glVertexAttribI1iv = (PFNGLVERTEXATTRIBI1IVPROC)GetProcAddress(("glVertexAttribI1iv");
		glVertexAttribI2iv = (PFNGLVERTEXATTRIBI2IVPROC)GetProcAddress(("glVertexAttribI2iv");
		glVertexAttribI3iv = (PFNGLVERTEXATTRIBI3IVPROC)GetProcAddress(("glVertexAttribI3iv");
		glVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC)GetProcAddress(("glVertexAttribI4iv");
		glVertexAttribI1uiv = (PFNGLVERTEXATTRIBI1UIVPROC)GetProcAddress(("glVertexAttribI1uiv");
		glVertexAttribI2uiv = (PFNGLVERTEXATTRIBI2UIVPROC)GetProcAddress(("glVertexAttribI2uiv");
		glVertexAttribI3uiv = (PFNGLVERTEXATTRIBI3UIVPROC)GetProcAddress(("glVertexAttribI3uiv");
		glVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC)GetProcAddress(("glVertexAttribI4uiv");
		glVertexAttribI4bv = (PFNGLVERTEXATTRIBI4BVPROC)GetProcAddress(("glVertexAttribI4bv");
		glVertexAttribI4sv = (PFNGLVERTEXATTRIBI4SVPROC)GetProcAddress(("glVertexAttribI4sv");
		glVertexAttribI4ubv = (PFNGLVERTEXATTRIBI4UBVPROC)GetProcAddress(("glVertexAttribI4ubv");
		glVertexAttribI4usv = (PFNGLVERTEXATTRIBI4USVPROC)GetProcAddress(("glVertexAttribI4usv");
		glGetUniformuiv = (PFNGLGETUNIFORMUIVPROC)GetProcAddress(("glGetUniformuiv");
		glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC)GetProcAddress(("glBindFragDataLocation");
		glGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC)GetProcAddress(("glGetFragDataLocation");
		glUniform1ui = (PFNGLUNIFORM1UIPROC)GetProcAddress(("glUniform1ui");
		glUniform2ui = (PFNGLUNIFORM2UIPROC)GetProcAddress(("glUniform2ui");
		glUniform3ui = (PFNGLUNIFORM3UIPROC)GetProcAddress(("glUniform3ui");
		glUniform4ui = (PFNGLUNIFORM4UIPROC)GetProcAddress(("glUniform4ui");
		glUniform1uiv = (PFNGLUNIFORM1UIVPROC)GetProcAddress(("glUniform1uiv");
		glUniform2uiv = (PFNGLUNIFORM2UIVPROC)GetProcAddress(("glUniform2uiv");
		glUniform3uiv = (PFNGLUNIFORM3UIVPROC)GetProcAddress(("glUniform3uiv");
		glUniform4uiv = (PFNGLUNIFORM4UIVPROC)GetProcAddress(("glUniform4uiv");
		glTexParameterIiv = (PFNGLTEXPARAMETERIIVPROC)GetProcAddress(("glTexParameterIiv");
		glTexParameterIuiv = (PFNGLTEXPARAMETERIUIVPROC)GetProcAddress(("glTexParameterIuiv");
		glGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIVPROC)GetProcAddress(("glGetTexParameterIiv");
		glGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIVPROC)GetProcAddress(("glGetTexParameterIuiv");
		glClearBufferiv = (PFNGLCLEARBUFFERIVPROC)GetProcAddress(("glClearBufferiv");
		glClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC)GetProcAddress(("glClearBufferuiv");
		glClearBufferfv = (PFNGLCLEARBUFFERFVPROC)GetProcAddress(("glClearBufferfv");
		glClearBufferfi = (PFNGLCLEARBUFFERFIPROC)GetProcAddress(("glClearBufferfi");
		glGetStringi = (PFNGLGETSTRINGIPROC)GetProcAddress(("glGetStringi");
		glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC)GetProcAddress(("glIsRenderbuffer");
		glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)GetProcAddress(("glBindRenderbuffer");
		glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)GetProcAddress(("glDeleteRenderbuffers");
		glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)GetProcAddress(("glGenRenderbuffers");
		glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)GetProcAddress(("glRenderbufferStorage");
		glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)GetProcAddress(("glGetRenderbufferParameteriv");
		glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC)GetProcAddress(("glIsFramebuffer");
		glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)GetProcAddress(("glBindFramebuffer");
		glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)GetProcAddress(("glDeleteFramebuffers");
		glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)GetProcAddress(("glGenFramebuffers");
		glCheckFrameBufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)GetProcAddress(("glCheckFramebufferStatus");
		glFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1DPROC)GetProcAddress(("glFramebufferTexture1D");
		glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)GetProcAddress(("glFramebufferTexture2D");
		glFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3DPROC)GetProcAddress(("glFramebufferTexture3D");
		glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)GetProcAddress(("glFramebufferRenderbuffer");
		glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)GetProcAddress(("glGetFramebufferAttachmentParameteriv");
		glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)GetProcAddress(("glGenerateMipmap");
		glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)GetProcAddress(("glBlitFramebuffer");
		glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)GetProcAddress(("glRenderbufferStorageMultisample");
		glFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)GetProcAddress(("glFramebufferTextureLayer");
		glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC)GetProcAddress(("glMapBufferRange");
		glFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)GetProcAddress(("glFlushMappedBufferRange");
		glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)GetProcAddress(("glBindVertexArray");
		glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)GetProcAddress(("glDeleteVertexArrays");
		glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)GetProcAddress(("glGenVertexArrays");
		glIsVertexArray = (PFNGLISVERTEXARRAYPROC)GetProcAddress(("glIsVertexArray");
	}

	static inline GLvoid Load3_1Extensions()
	{
		glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)GetProcAddress(("glDrawArraysInstanced");
		glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC)GetProcAddress(("glDrawElementsInstanced");
		glTexBuffer = (PFNGLTEXBUFFERPROC)GetProcAddress(("glTexBuffer");
		glPrimitiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEXPROC)GetProcAddress(("glPrimitiveRestartIndex");
		glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC)GetProcAddress(("glCopyBufferSubData");
		glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC)GetProcAddress(("glGetUniformIndices");
		glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)GetProcAddress(("glGetActiveUniformsiv");
		glGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC)GetProcAddress(("glGetActiveUniformName");
		glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)GetProcAddress(("glGetUniformBlockIndex");
		glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)GetProcAddress(("glGetActiveUniformBlockiv");
		glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)GetProcAddress(("glGetActiveUniformBlockName");
		glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC)GetProcAddress(("glUniformBlockBinding");
	}

	static inline GLvoid Load3_2Extensions()
	{
		glDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC)GetProcAddress(("glDrawElementsBaseVertex");
		glDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)GetProcAddress(("glDrawRangeElementsBaseVertex");
		glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)GetProcAddress(("glDrawElementsInstancedBaseVertex");
		glMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)GetProcAddress(("glMultiDrawElementsBaseVertex");
		glProvokingVertex = (PFNGLPROVOKINGVERTEXPROC)GetProcAddress(("glProvokingVertex");
		glFenceSync = (PFNGLFENCESYNCPROC)GetProcAddress(("glFenceSync");
		glIsSync = (PFNGLISSYNCPROC)GetProcAddress(("glIsSync");
		glDeleteSync = (PFNGLDELETESYNCPROC)GetProcAddress(("glDeleteSync");
		glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC)GetProcAddress(("glClientWaitSync");
		glWaitSync = (PFNGLWAITSYNCPROC)GetProcAddress(("glWaitSync");
		glGetInteger64v = (PFNGLGETINTEGER64VPROC)GetProcAddress(("glGetInteger64v");
		glGetSynciv = (PFNGLGETSYNCIVPROC)GetProcAddress(("glGetSynciv");
		glGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC)GetProcAddress(("glGetInteger64i_v");
		glGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC)GetProcAddress(("glGetBufferParameteri64v");
		glFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC)GetProcAddress(("glFramebufferTexture");
		glTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC)GetProcAddress(("glTexImage2DMultisample");
		glTexImage3DMultisample = (PFNGLTEXIMAGE3DMULTISAMPLEPROC)GetProcAddress(("glTexImage3DMultisample");
		glGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC)GetProcAddress(("glGetMultisamplefv");
		glSampleMaski = (PFNGLSAMPLEMASKIPROC)GetProcAddress(("glSampleMaski");
	}

	static inline GLvoid Load3_3Extensions()
	{
		glBindFragDataLocationIndexed = (PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)GetProcAddress(("glBindFragDataLocationIndexed");
		glGetFragDataIndex = (PFNGLGETFRAGDATAINDEXPROC)GetProcAddress(("glGetFragDataIndex");
		glGenSamplers = (PFNGLGENSAMPLERSPROC)GetProcAddress(("glGenSamplers");
		glDeleteSamplers = (PFNGLDELETESAMPLERSPROC)GetProcAddress(("glDeleteSamplers");
		glIsSampler = (PFNGLISSAMPLERPROC)GetProcAddress(("glIsSampler");
		glBindSampler = (PFNGLBINDSAMPLERPROC)GetProcAddress(("glBindSampler");
		glSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC)GetProcAddress(("glSamplerParameteri");
		glSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC)GetProcAddress(("glSamplerParameteriv");
		glSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC)GetProcAddress(("glSamplerParameterf");
		glSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC)GetProcAddress(("glSamplerParameterfv");
		glSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIVPROC)GetProcAddress(("glSamplerParameterIiv");
		glSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIVPROC)GetProcAddress(("glSamplerParameterIuiv");
		glGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC)GetProcAddress(("glGetSamplerParameteriv");
		glGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIVPROC)GetProcAddress(("glGetSamplerParameterIiv");
		glGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC)GetProcAddress(("glGetSamplerParameterfv");
		glGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIVPROC)GetProcAddress(("glGetSamplerParameterIuiv");
		glQueryCounter = (PFNGLQUERYCOUNTERPROC)GetProcAddress(("glQueryCounter");
		glGetQueryObjecti64v = (PFNGLGETQUERYOBJECTI64VPROC)GetProcAddress(("glGetQueryObjecti64v");
		glGetQueryObjectui64v = (PFNGLGETQUERYOBJECTUI64VPROC)GetProcAddress(("glGetQueryObjectui64v");
		glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC)GetProcAddress(("glVertexAttribDivisor");
		glVertexAttribP1ui = (PFNGLVERTEXATTRIBP1UIPROC)GetProcAddress(("glVertexAttribP1ui");
		glVertexAttribP1uiv = (PFNGLVERTEXATTRIBP1UIVPROC)GetProcAddress(("glVertexAttribP1uiv");
		glVertexAttribP2ui = (PFNGLVERTEXATTRIBP2UIPROC)GetProcAddress(("glVertexAttribP2ui");
		glVertexAttribP2uiv = (PFNGLVERTEXATTRIBP2UIVPROC)GetProcAddress(("glVertexAttribP2uiv");
		glVertexAttribP3ui = (PFNGLVERTEXATTRIBP3UIPROC)GetProcAddress(("glVertexAttribP3ui");
		glVertexAttribP3uiv = (PFNGLVERTEXATTRIBP3UIVPROC)GetProcAddress(("glVertexAttribP3uiv");
		glVertexAttribP4ui = (PFNGLVERTEXATTRIBP4UIPROC)GetProcAddress(("glVertexAttribP4ui");
		glVertexAttribP4uiv = (PFNGLVERTEXATTRIBP4UIVPROC)GetProcAddress(("glVertexAttribP4uiv");
		glVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC)GetProcAddress(("glVertexAttrib4uiv");
		glVertexP2ui = (PFNGLVERTEXP2UIPROC)GetProcAddress(("glVertexP2ui");
		glVertexP2uiv = (PFNGLVERTEXP2UIVPROC)GetProcAddress(("glVertexP2uiv");
		glVertexP3ui = (PFNGLVERTEXP3UIPROC)GetProcAddress(("glVertexP3ui");
		glVertexP3uiv = (PFNGLVERTEXP3UIVPROC)GetProcAddress(("glVertexP3uiv");
		glVertexP4ui = (PFNGLVERTEXP4UIPROC)GetProcAddress(("glVertexP4ui");
		glVertexP4uiv = (PFNGLVERTEXP4UIVPROC)GetProcAddress(("glVertexP4uiv");
		glTexCoordP1ui = (PFNGLTEXCOORDP1UIPROC)GetProcAddress(("glTexCoordP1ui");
		glTexCoordP1uiv = (PFNGLTEXCOORDP1UIVPROC)GetProcAddress(("glTexCoordP1uiv");
		glTexCoordP2ui = (PFNGLTEXCOORDP2UIPROC)GetProcAddress(("glTexCoordP2ui");
		glTexCoordP2uiv = (PFNGLTEXCOORDP2UIVPROC)GetProcAddress(("glTexCoordP2uiv");
		glTexCoordP3ui = (PFNGLTEXCOORDP3UIPROC)GetProcAddress(("glTexCoordP3ui");
		glTexCoordP3uiv = (PFNGLTEXCOORDP3UIVPROC)GetProcAddress(("glTexCoordP3uiv");
		glTexCoordP4ui = (PFNGLTEXCOORDP4UIPROC)GetProcAddress(("glTexCoordP4ui");
		glTexCoordP4uiv = (PFNGLTEXCOORDP4UIVPROC)GetProcAddress(("glTexCoordP4uiv");
		glMultiTexCoordP1ui = (PFNGLMULTITEXCOORDP1UIPROC)GetProcAddress(("glMultiTexCoordP1ui");
		glMultiTexCoordP1uiv = (PFNGLMULTITEXCOORDP1UIVPROC)GetProcAddress(("glMultiTexCoordP1uiv");
		glMultiTexCoordP2ui = (PFNGLMULTITEXCOORDP2UIPROC)GetProcAddress(("glMultiTexCoordP2ui");
		glMultiTexCoordP2uiv = (PFNGLMULTITEXCOORDP2UIVPROC)GetProcAddress(("glMultiTexCoordP2uiv");
		glMultiTexCoordP3ui = (PFNGLMULTITEXCOORDP3UIPROC)GetProcAddress(("glMultiTexCoordP3ui");
		glMultiTexCoordP3uiv = (PFNGLMULTITEXCOORDP3UIVPROC)GetProcAddress(("glMultiTexCoordP3uiv");
		glMultiTexCoordP4ui = (PFNGLMULTITEXCOORDP4UIPROC)GetProcAddress(("glMultiTexCoordP4ui");
		glMultiTexCoordP4uiv = (PFNGLMULTITEXCOORDP4UIVPROC)GetProcAddress(("glMultiTexCoordP4uiv");
		glNormalP3ui = (PFNGLNORMALP3UIPROC)GetProcAddress(("glNormalP3ui");
		glNormalP3uiv = (PFNGLNORMALP3UIVPROC)GetProcAddress(("glNormalP3uiv");
		glColorP3ui = (PFNGLCOLORP3UIPROC)GetProcAddress(("glColorP3ui");
		glColorP3uiv = (PFNGLCOLORP3UIVPROC)GetProcAddress(("glColorP3uiv");
		glColorP4ui = (PFNGLCOLORP4UIPROC)GetProcAddress(("glColorP4ui");
		glColorP4uiv = (PFNGLCOLORP4UIVPROC)GetProcAddress(("glColorP4uiv");
		glSecondaryColorP3ui = (PFNGLSECONDARYCOLORP3UIPROC)GetProcAddress(("glSecondaryColorP3ui");
		glSecondaryColorP3uiv = (PFNGLSECONDARYCOLORP3UIVPROC)GetProcAddress(("glSecondaryColorP3uiv");
	}

	static inline GLvoid Load4_0Extensions()
	{
		glMinSampleShading = (PFNGLMINSAMPLESHADINGPROC)GetProcAddress(("glMinSampleShading");
		glBlendEquationi = (PFNGLBLENDEQUATIONIPROC)GetProcAddress(("glBlendEquationi");
		glBlendEquationSeparatei = (PFNGLBLENDEQUATIONSEPARATEIPROC)GetProcAddress(("glBlendEquationSeparatei");
		glBlendFunci = (PFNGLBLENDFUNCIPROC)GetProcAddress(("glBlendFunci");
		glBlendFuncSeparatei = (PFNGLBLENDFUNCSEPARATEIPROC)GetProcAddress(("glBlendFuncSeparatei");
		glDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECTPROC)GetProcAddress(("glDrawArraysIndirect");
		glDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECTPROC)GetProcAddress(("glDrawElementsIndirect");
		glUniform1d = (PFNGLUNIFORM1DPROC)GetProcAddress(("glUniform1d");
		glUniform2d = (PFNGLUNIFORM2DPROC)GetProcAddress(("glUniform2d");
		glUniform3d = (PFNGLUNIFORM3DPROC)GetProcAddress(("glUniform3d");
		glUniform4d = (PFNGLUNIFORM4DPROC)GetProcAddress(("glUniform4d");
		glUniform1dv = (PFNGLUNIFORM1DVPROC)GetProcAddress(("glUniform1dv");
		glUniform2dv = (PFNGLUNIFORM2DVPROC)GetProcAddress(("glUniform2dv");
		glUniform3dv = (PFNGLUNIFORM3DVPROC)GetProcAddress(("glUniform3dv");
		glUniform4dv = (PFNGLUNIFORM4DVPROC)GetProcAddress(("glUniform4dv");
		glUniformMatrix2dv = (PFNGLUNIFORMMATRIX2DVPROC)GetProcAddress(("glUniformMatrix2dv");
		glUniformMatrix3dv = (PFNGLUNIFORMMATRIX3DVPROC)GetProcAddress(("glUniformMatrix3dv");
		glUniformMatrix4dv = (PFNGLUNIFORMMATRIX4DVPROC)GetProcAddress(("glUniformMatrix4dv");
		glUniformMatrix2x3dv = (PFNGLUNIFORMMATRIX2X3DVPROC)GetProcAddress(("glUniformMatrix2x3dv");
		glUniformMatrix2x4dv = (PFNGLUNIFORMMATRIX2X4DVPROC)GetProcAddress(("glUniformMatrix2x4dv");
		glUniformMatrix3x2dv = (PFNGLUNIFORMMATRIX3X2DVPROC)GetProcAddress(("glUniformMatrix3x2dv");
		glUniformMatrix3x4dv = (PFNGLUNIFORMMATRIX3X4DVPROC)GetProcAddress(("glUniformMatrix3x4dv");
		glUniformMatrix4x2dv = (PFNGLUNIFORMMATRIX4X2DVPROC)GetProcAddress(("glUniformMatrix4x2dv");
		glUniformMatrix4x3dv = (PFNGLUNIFORMMATRIX4X3DVPROC)GetProcAddress(("glUniformMatrix4x3dv");
		glGetUniformdv = (PFNGLGETUNIFORMDVPROC)GetProcAddress(("glGetUniformdv");
		glGetSubroutineUniformLocation = (PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)GetProcAddress(("glGetSubroutineUniformLocation");
		glGetSubroutineIndex = (PFNGLGETSUBROUTINEINDEXPROC)GetProcAddress(("glGetSubroutineIndex");
		glGetActiveSubroutineUniformiv = (PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)GetProcAddress(("glGetActiveSubroutineUniformiv");
		glGetActiveSubroutineUniformName = (PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)GetProcAddress(("glGetActiveSubroutineUniformName");
		glGetActiveSubroutineName = (PFNGLGETACTIVESUBROUTINENAMEPROC)GetProcAddress(("glGetActiveSubroutineName");
		glUniformSubroutinesuiv = (PFNGLUNIFORMSUBROUTINESUIVPROC)GetProcAddress(("glUniformSubroutinesuiv");
		glGetUniformSubroutineuiv = (PFNGLGETUNIFORMSUBROUTINEUIVPROC)GetProcAddress(("glGetUniformSubroutineuiv");
		glGetProgramStageiv = (PFNGLGETPROGRAMSTAGEIVPROC)GetProcAddress(("glGetProgramStageiv");
		glPatchParameteri = (PFNGLPATCHPARAMETERIPROC)GetProcAddress(("glPatchParameteri");
		glPatchParameterfv = (PFNGLPATCHPARAMETERFVPROC)GetProcAddress(("glPatchParameterfv");
		glBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACKPROC)GetProcAddress(("glBindTransformFeedback");
		glDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKSPROC)GetProcAddress(("glDeleteTransformFeedbacks");
		glGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKSPROC)GetProcAddress(("glGenTransformFeedbacks");
		glIsTransformFeedback = (PFNGLISTRANSFORMFEEDBACKPROC)GetProcAddress(("glIsTransformFeedback");
		glPauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACKPROC)GetProcAddress(("glPauseTransformFeedback");
		glResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACKPROC)GetProcAddress(("glResumeTransformFeedback");
		glDrawTransformFeedback = (PFNGLDRAWTRANSFORMFEEDBACKPROC)GetProcAddress(("glDrawTransformFeedback");
		glDrawTransformFeedbackStream = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)GetProcAddress(("glDrawTransformFeedbackStream");
		glBeginQueryIndexed = (PFNGLBEGINQUERYINDEXEDPROC)GetProcAddress(("glBeginQueryIndexed");
		glEndQueryIndexed = (PFNGLENDQUERYINDEXEDPROC)GetProcAddress(("glEndQueryIndexed");
		glGetQueryIndexediv = (PFNGLGETQUERYINDEXEDIVPROC)GetProcAddress(("glGetQueryIndexediv");
	}

	static inline GLvoid Load4_1Extensions()
	{
		glReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILERPROC)GetProcAddress(("glReleaseShaderCompiler");
		glShaderBinary = (PFNGLSHADERBINARYPROC)GetProcAddress(("glShaderBinary");
		glGetShaderPrecisionFormat = (PFNGLGETSHADERPRECISIONFORMATPROC)GetProcAddress(("glGetShaderPrecisionFormat");
		glDepthRangef = (PFNGLDEPTHRANGEFPROC)GetProcAddress(("glDepthRangef");
		glClearDepthf = (PFNGLCLEARDEPTHFPROC)GetProcAddress(("glClearDepthf");
		glGetProgramBinary = (PFNGLGETPROGRAMBINARYPROC)GetProcAddress(("glGetProgramBinary");
		glProgramBinary = (PFNGLPROGRAMBINARYPROC)GetProcAddress(("glProgramBinary");
		glProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC)GetProcAddress(("glProgramParameteri");
		glUseProgramStages = (PFNGLUSEPROGRAMSTAGESPROC)GetProcAddress(("glUseProgramStages");
		glActiveShaderProgram = (PFNGLACTIVESHADERPROGRAMPROC)GetProcAddress(("glActiveShaderProgram");
		glCreateShaderProgramv = (PFNGLCREATESHADERPROGRAMVPROC)GetProcAddress(("glCreateShaderProgramv");
		glBindProgramPipeline = (PFNGLBINDPROGRAMPIPELINEPROC)GetProcAddress(("glBindProgramPipeline");
		glDeleteProgramPipelines = (PFNGLDELETEPROGRAMPIPELINESPROC)GetProcAddress(("glDeleteProgramPipelines");
		glGenProgramPipelines = (PFNGLGENPROGRAMPIPELINESPROC)GetProcAddress(("glGenProgramPipelines");
		glIsProgramPipeline = (PFNGLISPROGRAMPIPELINEPROC)GetProcAddress(("glIsProgramPipeline");
		glGetProgramPipelineiv = (PFNGLGETPROGRAMPIPELINEIVPROC)GetProcAddress(("glGetProgramPipelineiv");
		glProgramUniform1i = (PFNGLPROGRAMUNIFORM1IPROC)GetProcAddress(("glProgramUniform1i");
		glProgramUniform1iv = (PFNGLPROGRAMUNIFORM1IVPROC)GetProcAddress(("glProgramUniform1iv");
		glProgramUniform1f = (PFNGLPROGRAMUNIFORM1FPROC)GetProcAddress(("glProgramUniform1f");
		glProgramUniform1fv = (PFNGLPROGRAMUNIFORM1FVPROC)GetProcAddress(("glProgramUniform1fv");
		glProgramUniform1d = (PFNGLPROGRAMUNIFORM1DPROC)GetProcAddress(("glProgramUniform1d");
		glProgramUniform1dv = (PFNGLPROGRAMUNIFORM1DVPROC)GetProcAddress(("glProgramUniform1dv");
		glProgramUniform1ui = (PFNGLPROGRAMUNIFORM1UIPROC)GetProcAddress(("glProgramUniform1ui");
		glProgramUniform1uiv = (PFNGLPROGRAMUNIFORM1UIVPROC)GetProcAddress(("glProgramUniform1uiv");
		glProgramUniform2i = (PFNGLPROGRAMUNIFORM2IPROC)GetProcAddress(("glProgramUniform2i");
		glProgramUniform2iv = (PFNGLPROGRAMUNIFORM2IVPROC)GetProcAddress(("glProgramUniform2iv");
		glProgramUniform2f = (PFNGLPROGRAMUNIFORM2FPROC)GetProcAddress(("glProgramUniform2f");
		glProgramUniform2fv = (PFNGLPROGRAMUNIFORM2FVPROC)GetProcAddress(("glProgramUniform2fv");
		glProgramUniform2d = (PFNGLPROGRAMUNIFORM2DPROC)GetProcAddress(("glProgramUniform2d");
		glProgramUniform2dv = (PFNGLPROGRAMUNIFORM2DVPROC)GetProcAddress(("glProgramUniform2dv");
		glProgramUniform2ui = (PFNGLPROGRAMUNIFORM2UIPROC)GetProcAddress(("glProgramUniform2ui");
		glProgramUniform2uiv = (PFNGLPROGRAMUNIFORM2UIVPROC)GetProcAddress(("glProgramUniform2uiv");
		glProgramUniform3i = (PFNGLPROGRAMUNIFORM3IPROC)GetProcAddress(("glProgramUniform3i");
		glProgramUniform3iv = (PFNGLPROGRAMUNIFORM3IVPROC)GetProcAddress(("glProgramUniform3iv");
		glProgramUniform3f = (PFNGLPROGRAMUNIFORM3FPROC)GetProcAddress(("glProgramUniform3f");
		glProgramUniform3fv = (PFNGLPROGRAMUNIFORM3FVPROC)GetProcAddress(("glProgramUniform3fv");
		glProgramUniform3d = (PFNGLPROGRAMUNIFORM3DPROC)GetProcAddress(("glProgramUniform3d");
		glProgramUniform3dv = (PFNGLPROGRAMUNIFORM3DVPROC)GetProcAddress(("glProgramUniform3dv");
		glProgramUniform3ui = (PFNGLPROGRAMUNIFORM3UIPROC)GetProcAddress(("glProgramUniform3ui");
		glProgramUniform3uiv = (PFNGLPROGRAMUNIFORM3UIVPROC)GetProcAddress(("glProgramUniform3uiv");
		glProgramUniform4i = (PFNGLPROGRAMUNIFORM4IPROC)GetProcAddress(("glProgramUniform4i");
		glProgramUniform4iv = (PFNGLPROGRAMUNIFORM4IVPROC)GetProcAddress(("glProgramUniform4iv");
		glProgramUniform4f = (PFNGLPROGRAMUNIFORM4FPROC)GetProcAddress(("glProgramUniform4f");
		glProgramUniform4fv = (PFNGLPROGRAMUNIFORM4FVPROC)GetProcAddress(("glProgramUniform4fv");
		glProgramUniform4d = (PFNGLPROGRAMUNIFORM4DPROC)GetProcAddress(("glProgramUniform4d");
		glProgramUniform4dv = (PFNGLPROGRAMUNIFORM4DVPROC)GetProcAddress(("glProgramUniform4dv");
		glProgramUniform4ui = (PFNGLPROGRAMUNIFORM4UIPROC)GetProcAddress(("glProgramUniform4ui");
		glProgramUniform4uiv = (PFNGLPROGRAMUNIFORM4UIVPROC)GetProcAddress(("glProgramUniform4uiv");
		glProgramUniformMatrix2fv = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC)GetProcAddress(("glProgramUniformMatrix2fv");
		glProgramUniformMatrix3fv = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC)GetProcAddress(("glProgramUniformMatrix3fv");
		glProgramUniformMatrix4fv = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC)GetProcAddress(("glProgramUniformMatrix4fv");
		glProgramUniformMatrix2dv = (PFNGLPROGRAMUNIFORMMATRIX2DVPROC)GetProcAddress(("glProgramUniformMatrix2dv");
		glProgramUniformMatrix3dv = (PFNGLPROGRAMUNIFORMMATRIX3DVPROC)GetProcAddress(("glProgramUniformMatrix3dv");
		glProgramUniformMatrix4dv = (PFNGLPROGRAMUNIFORMMATRIX4DVPROC)GetProcAddress(("glProgramUniformMatrix4dv");
		glProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)GetProcAddress(("glProgramUniformMatrix2x3fv");
		glProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)GetProcAddress(("glProgramUniformMatrix3x2fv");
		glProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)GetProcAddress(("glProgramUniformMatrix2x4fv");
		glProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)GetProcAddress(("glProgramUniformMatrix4x2fv");
		glProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)GetProcAddress(("glProgramUniformMatrix3x4fv");
		glProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)GetProcAddress(("glProgramUniformMatrix4x3fv");
		glProgramUniformMatrix2x3dv = (PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)GetProcAddress(("glProgramUniformMatrix2x3dv");
		glProgramUniformMatrix3x2dv = (PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)GetProcAddress(("glProgramUniformMatrix3x2dv");
		glProgramUniformMatrix2x4dv = (PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)GetProcAddress(("glProgramUniformMatrix2x4dv");
		glProgramUniformMatrix4x2dv = (PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)GetProcAddress(("glProgramUniformMatrix4x2dv");
		glProgramUniformMatrix3x4dv = (PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)GetProcAddress(("glProgramUniformMatrix3x4dv");
		glProgramUniformMatrix4x3dv = (PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)GetProcAddress(("glProgramUniformMatrix4x3dv");
		glValidateProgramPipeline = (PFNGLVALIDATEPROGRAMPIPELINEPROC)GetProcAddress(("glValidateProgramPipeline");
		glGetProgramPipelineInfoLog = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC)GetProcAddress(("glGetProgramPipelineInfoLog");
		glVertexAttribL1d = (PFNGLVERTEXATTRIBL1DPROC)GetProcAddress(("glVertexAttribL1d");
		glVertexAttribL2d = (PFNGLVERTEXATTRIBL2DPROC)GetProcAddress(("glVertexAttribL2d");
		glVertexAttribL3d = (PFNGLVERTEXATTRIBL3DPROC)GetProcAddress(("glVertexAttribL3d");
		glVertexAttribL4d = (PFNGLVERTEXATTRIBL4DPROC)GetProcAddress(("glVertexAttribL4d");
		glVertexAttribL1dv = (PFNGLVERTEXATTRIBL1DVPROC)GetProcAddress(("glVertexAttribL1dv");
		glVertexAttribL2dv = (PFNGLVERTEXATTRIBL2DVPROC)GetProcAddress(("glVertexAttribL2dv");
		glVertexAttribL3dv = (PFNGLVERTEXATTRIBL3DVPROC)GetProcAddress(("glVertexAttribL3dv");
		glVertexAttribL4dv = (PFNGLVERTEXATTRIBL4DVPROC)GetProcAddress(("glVertexAttribL4dv");
		glVertexAttribLPointer = (PFNGLVERTEXATTRIBLPOINTERPROC)GetProcAddress(("glVertexAttribLPointer");
		glGetVertexAttribLdv = (PFNGLGETVERTEXATTRIBLDVPROC)GetProcAddress(("glGetVertexAttribLdv");
		glViewportarrayv = (PFNGLVIEWPORTARRAYVPROC)GetProcAddress(("glViewportArrayv");
		glViewportIndexedf = (PFNGLVIEWPORTINDEXEDFPROC)GetProcAddress(("glViewportIndexedf");
		glViewportIndexedfv = (PFNGLVIEWPORTINDEXEDFVPROC)GetProcAddress(("glViewportIndexedfv");
		glScissorArrayv = (PFNGLSCISSORARRAYVPROC)GetProcAddress(("glScissorArrayv");
		glScissorIndexed = (PFNGLSCISSORINDEXEDPROC)GetProcAddress(("glScissorIndexed");
		glScissorIndexedv = (PFNGLSCISSORINDEXEDVPROC)GetProcAddress(("glScissorIndexedv");
		glDepthRangeIndexed = (PFNGLDEPTHRANGEINDEXEDPROC)GetProcAddress(("glDepthRangeIndexed");
		glDepthRangeArrayv = (PFNGLDEPTHRANGEARRAYVPROC)GetProcAddress(("glDepthRangeArrayv");
		glGetFloati_v = (PFNGLGETFLOATI_VPROC)GetProcAddress(("glGetFloati_v");
		glGetDoublei_v = (PFNGLGETDOUBLEI_VPROC)GetProcAddress(("glGetDoublei_v");
	}

	static inline GLvoid Load4_2Extensions()
	{
		glDrawArraysInstancedBaseInstance = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)GetProcAddress(("glDrawArraysInstancedBaseInstance");
		glDrawElementsInstancedBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)GetProcAddress(("glDrawElementsInstancedBaseInstance");
		glDrawElementsInstancedBaseVertexBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)GetProcAddress(("glDrawElementsInstancedBaseVertexBaseInstance");
		glGetInternalformativ = (PFNGLGETINTERNALFORMATIVPROC)GetProcAddress(("glGetInternalformativ");
		glGetActiveAtomicCounterBufferiv = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)GetProcAddress(("glGetActiveAtomicCounterBufferiv");
		glBindImageTexture = (PFNGLBINDIMAGETEXTUREPROC)GetProcAddress(("glBindImageTexture");
		glMemoryBarrier = (PFNGLMEMORYBARRIERPROC)GetProcAddress(("glMemoryBarrier");
		glTexStorage1D = (PFNGLTEXSTORAGE1DPROC)GetProcAddress(("glTexStorage1D");
		glTexStorage2D = (PFNGLTEXSTORAGE2DPROC)GetProcAddress(("glTexStorage2D");
		glTexStorage3D = (PFNGLTEXSTORAGE3DPROC)GetProcAddress(("glTexStorage3D");
		glDrawTransformFeedbackInstanced = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)GetProcAddress(("glDrawTransformFeedbackInstanced");
		glDrawTransformFeedbackStreamInstanced = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)GetProcAddress(("glDrawTransformFeedbackStreamInstanced");
	}

	static inline GLvoid Load4_3Extensions()
	{
		glClearBufferData = (PFNGLCLEARBUFFERDATAPROC)GetProcAddress(("glClearBufferData");
		glClearBufferSubData = (PFNGLCLEARBUFFERSUBDATAPROC)GetProcAddress(("glClearBufferSubData");
		glDispatchCompute = (PFNGLDISPATCHCOMPUTEPROC)GetProcAddress(("glDispatchCompute");
		glDispatchComputeIndirect = (PFNGLDISPATCHCOMPUTEINDIRECTPROC)GetProcAddress(("glDispatchComputeIndirect");
		glCopyImageSubData = (PFNGLCOPYIMAGESUBDATAPROC)GetProcAddress(("glCopyImageSubData");
		glFramebufferParameteri = (PFNGLFRAMEBUFFERPARAMETERIPROC)GetProcAddress(("glFramebufferParameteri");
		glGetFramebufferParameteriv = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC)GetProcAddress(("glGetFramebufferParameteriv");
		glGetInternalformati64v = (PFNGLGETINTERNALFORMATI64VPROC)GetProcAddress(("glGetInternalformati64v");
		glInvalidateTexSubImage = (PFNGLINVALIDATETEXSUBIMAGEPROC)GetProcAddress(("glInvalidateTexSubImage");
		glInvalidateTexImage = (PFNGLINVALIDATETEXIMAGEPROC)GetProcAddress(("glInvalidateTexImage");
		glInvalidateBufferSubData = (PFNGLINVALIDATEBUFFERSUBDATAPROC)GetProcAddress(("glInvalidateBufferSubData");
		glInvalidateBufferData = (PFNGLINVALIDATEBUFFERDATAPROC)GetProcAddress(("glInvalidateBufferData");
		glInvalidateFramebuffer = (PFNGLINVALIDATEFRAMEBUFFERPROC)GetProcAddress(("glInvalidateFramebuffer");
		glInvalidateSubFramebuffer = (PFNGLINVALIDATESUBFRAMEBUFFERPROC)GetProcAddress(("glInvalidateSubFramebuffer");
		glMultiDrawArraysIndirect = (PFNGLMULTIDRAWARRAYSINDIRECTPROC)GetProcAddress(("glMultiDrawArraysIndirect");
		glMultiDrawElementsIndirect = (PFNGLMULTIDRAWELEMENTSINDIRECTPROC)GetProcAddress(("glMultiDrawElementsIndirect");
		glGetProgramInterfaceiv = (PFNGLGETPROGRAMINTERFACEIVPROC)GetProcAddress(("glGetProgramInterfaceiv");
		glGetProgramResourceIndex = (PFNGLGETPROGRAMRESOURCEINDEXPROC)GetProcAddress(("glGetProgramResourceIndex");
		glGetProgramResourceName = (PFNGLGETPROGRAMRESOURCENAMEPROC)GetProcAddress(("glGetProgramResourceName");
		glGetProgramResourceiv = (PFNGLGETPROGRAMRESOURCEIVPROC)GetProcAddress(("glGetProgramResourceiv");
		glGetProgramResourceLocation = (PFNGLGETPROGRAMRESOURCELOCATIONPROC)GetProcAddress(("glGetProgramResourceLocation");
		glGetProgramResourceLocationIndex = (PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)GetProcAddress(("glGetProgramResourceLocationIndex");
		glShaderStorageBlockBinding = (PFNGLSHADERSTORAGEBLOCKBINDINGPROC)GetProcAddress(("glShaderStorageBlockBinding");
		glTexBufferRange = (PFNGLTEXBUFFERRANGEPROC)GetProcAddress(("glTexBufferRange");
		glTexStorage2DMultisample = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC)GetProcAddress(("glTexStorage2DMultisample");
		glTexStorage3DMultisample = (PFNGLTEXSTORAGE3DMULTISAMPLEPROC)GetProcAddress(("glTexStorage3DMultisample");
		glTextureView = (PFNGLTEXTUREVIEWPROC)GetProcAddress(("glTextureView");
		glBindVertexBuffer = (PFNGLBINDVERTEXBUFFERPROC)GetProcAddress(("glBindVertexBuffer");
		glVertexAttribFormat = (PFNGLVERTEXATTRIBFORMATPROC)GetProcAddress(("glVertexAttribFormat");
		glVertexAttribIFormat = (PFNGLVERTEXATTRIBIFORMATPROC)GetProcAddress(("glVertexAttribIFormat");
		glVertexAttribLFormat = (PFNGLVERTEXATTRIBLFORMATPROC)GetProcAddress(("glVertexAttribLFormat");
		glVertexAttribBinding = (PFNGLVERTEXATTRIBBINDINGPROC)GetProcAddress(("glVertexAttribBinding");
		glVertexBindingDivisor = (PFNGLVERTEXBINDINGDIVISORPROC)GetProcAddress(("glVertexBindingDivisor");
		glDebugMessageControl = (PFNGLDEBUGMESSAGECONTROLPROC)GetProcAddress(("glDebugMessageControl");
		glDebugMessageInsert = (PFNGLDEBUGMESSAGEINSERTPROC)GetProcAddress(("glDebugMessageInsert");
		glDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC)GetProcAddress(("glDebugMessageCallback");
		glGetDebugMessageLog = (PFNGLGETDEBUGMESSAGELOGPROC)GetProcAddress(("glGetDebugMessageLog");
		glPushDebugGroup = (PFNGLPUSHDEBUGGROUPPROC)GetProcAddress(("glPushDebugGroup");
		glPopDebugGroup = (PFNGLPOPDEBUGGROUPPROC)GetProcAddress(("glPopDebugGroup");
		glObjectLabel = (PFNGLOBJECTLABELPROC)GetProcAddress(("glObjectLabel");
		glObjectPtrLabel = (PFNGLOBJECTPTRLABELPROC)GetProcAddress(("glObjectPtrLabel");
		glGetObjectLabel = (PFNGLGETOBJECTLABELPROC)GetProcAddress(("glGetObjectLabel");
		glGetObjectPtrLabel = (PFNGLGETOBJECTPTRLABELPROC)GetProcAddress(("glGetObjectPtrLabel");
	}

	static inline GLvoid Load4_4Extensions()
	{
		glBufferStorage = (PFNGLBUFFERSTORAGEPROC)GetProcAddress(("glBufferStorage");
		glClearTexImage = (PFNGLCLEARTEXIMAGEPROC)GetProcAddress(("glClearTexImage");
		glClearTexSubImage = (PFNGLCLEARTEXSUBIMAGEPROC)GetProcAddress(("glClearTexSubImage");
		glBindBuffersBase = (PFNGLBINDBUFFERSBASEPROC)GetProcAddress(("glBindBuffersBase");
		glBindBuffersRange = (PFNGLBINDBUFFERSRANGEPROC)GetProcAddress(("glBindBuffersRange");
		glBindTextures = (PFNGLBINDTEXTURESPROC)GetProcAddress(("glBindTextures");
		glBindSamplers = (PFNGLBINDSAMPLERSPROC)GetProcAddress(("glBindSamplers");
		glBindImageTextures = (PFNGLBINDIMAGETEXTURESPROC)GetProcAddress(("glBindImageTextures");
		glBindVertexBuffers = (PFNGLBINDVERTEXBUFFERSPROC)GetProcAddress(("glBindVertexBuffers");
	}

	static GLvoid InitializeGLVersion()
	{
		const GLubyte* VersionString = glGetString(GL_VERSION);

		TinyExtender::GLVersion_Major = VersionString[0] - '0';
		TinyExtender::GLVersion_Minor = VersionString[2] - '0';
	}

	static GLvoid PrintErrorMessage(GLuint Version_Major, GLuint Version_Minor)
	{
		printf("Error: OpenGL version %i.%i not supported. stopping here\n", Version_Major, Version_Minor);
	}

	static void* GetProcAddress(const GLubyte* ProcName)
	{
#if defined(_WIN32)
		return wglGetProcAddress((LPCTSTR)ProcName);
#endif

#if defined(__linux__)
		return glXGetProcAddress(ProcName);
#endif
	}
};*/

#endif