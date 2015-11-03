#ifndef TINYEXTENDER_H_
#define TINYEXTENDER_H_

#define GETFUNCTION(function) function

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

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif
#ifndef GLAPI
#define GLAPI extern
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

//OpenGL 2.0 Extensions
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

//OpenGL 3.0 Extensions
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

//OpenGL 3.2 Extensions
typedef struct __GLsync *GLsync;
#ifndef GLEXT_64_TYPES_DEFINED
/* This code block is duplicated in glxext.h, so must be protected */
#define GLEXT_64_TYPES_DEFINED
/* Define int32_t, int64_t, and uint64_t types for UST/MSC */
/* (as used in the GL_EXT_timer_query extension). */
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
#endif /* __arch64__ */
#endif /* __STDC__ */
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
/* Fallback if nothing above works */
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

//OpenGL 4.3 Extensions
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

class tinyExtender
{
public:
	
	tinyExtender()
	{
		glVersion_Major = 0;
		glVersion_Minor = 0;
		InitializeGLVersion();
	}
	~tinyExtender(){}

	GLvoid InitializeExtensions()
	{
		if (glVersion_Major > 1 || (glVersion_Minor >= 2 && glVersion_Major >= 1))
		{
			Load1_2Extensions();
		}

		else
		{
			PrintErrorMessage(1, 2);
			return;
		}

		if (glVersion_Major > 1 || (glVersion_Minor >= 3 && glVersion_Major >= 1))
		{
			Load1_3Extensions();
		}

		else
		{
			PrintErrorMessage(1, 3);
			return;
		}

		if (glVersion_Major > 1 || (glVersion_Minor >= 4 && glVersion_Major >= 1))
		{
			Load1_4Extensions();
		}

		else
		{
			PrintErrorMessage(1, 4);
			return;
		}

		if (glVersion_Major > 1 || (glVersion_Minor >= 5 && glVersion_Major >= 1))
		{
			Load1_5Extensions();
		}

		else
		{
			PrintErrorMessage(1, 5);
			return;
		}

		if (glVersion_Major > 2 || (glVersion_Minor >= 0 && glVersion_Major >= 2))
		{
			Load2_0Extensions();
		}

		else
		{
			PrintErrorMessage(2, 0);
			return;
		}

		if (glVersion_Major > 2 || (glVersion_Minor >= 1 && glVersion_Major >= 2))
		{
			Load2_1Extensions();
		}

		else
		{
			PrintErrorMessage(2, 1);
			return;
		}

		if (glVersion_Major > 3 || (glVersion_Minor >= 0 && glVersion_Major >= 3))
		{
			Load3_0Extensions();
		}

		else
		{
			PrintErrorMessage(3, 0);
			return;
		}

		if (glVersion_Major > 3 || (glVersion_Minor >= 1 && glVersion_Major >= 3))
		{
			Load3_1Extensions();
		}

		else
		{
			PrintErrorMessage(3, 1);
			return;
		}

		if (glVersion_Major > 3 || (glVersion_Minor >= 2 && glVersion_Major >= 3))
		{
			Load3_2Extensions();
		}

		else
		{
			PrintErrorMessage(3, 2);
			return;
		}

		if (glVersion_Major > 3 || (glVersion_Minor >= 3 && glVersion_Major >= 3))
		{
			Load3_3Extensions();
		}

		else
		{
			PrintErrorMessage(3, 3);
			return;
		}

		if (glVersion_Major > 4 || (glVersion_Minor >= 0 && glVersion_Major >= 4))
		{
			Load4_0Extensions();
		}

		else
		{
			PrintErrorMessage(4, 0);
			return;
		}

		if (glVersion_Major > 4 || (glVersion_Minor >= 1 && glVersion_Major >= 4))
		{
			Load4_1Extensions();
		}

		else
		{
			PrintErrorMessage(4, 1);
			return;
		}

		if (glVersion_Major > 4 || (glVersion_Minor >= 2 && glVersion_Major >= 4))
		{
			Load4_2Extensions();
		}

		else
		{
			PrintErrorMessage(4, 2);
			return;
		}

		if (glVersion_Major > 4 || (glVersion_Minor >= 3 && glVersion_Minor >= 4))
		{
			Load4_3Extensions();
		}

		else
		{
			PrintErrorMessage(4, 3);
		}

		if (glVersion_Major > 4 || (glVersion_Minor >= 4 && glVersion_Major >= 4))
		{
			Load4_4Extensions();
		}

		else
		{
			PrintErrorMessage(4, 4);
			return;
		}
	}

	GLvoid InitializeExtensionsSpecific(GLbitfield openGLVersions)
	{
		if (openGLVersions & GLVERSION1_2)
		{
			if (glVersion_Major > 1 || (glVersion_Minor >= 2 && glVersion_Major >= 1))
			{
				Load1_2Extensions();
			}

			PrintErrorMessage(1, 2);
		}

		if (openGLVersions & GLVERSION1_3)
		{
			if (glVersion_Major > 1 || (glVersion_Minor >= 3 && glVersion_Major >= 1))
			{
				Load1_3Extensions();
			}

			PrintErrorMessage(1, 3);
		}

		if (openGLVersions & GLVERSION1_4)
		{
			if (glVersion_Major > 1 || (glVersion_Minor >= 4 && glVersion_Major >= 1))
			{
				Load1_4Extensions();
			}

			PrintErrorMessage(1, 4);
		}

		if (openGLVersions & GLVERSION1_5)
		{
			if (glVersion_Major > 1 || (glVersion_Minor >= 5 && glVersion_Major >= 1))
			{
				Load1_5Extensions();
			}

			PrintErrorMessage(1, 5);
		}

		if (openGLVersions & GLVERSION2_0)
		{
			if (glVersion_Major > 2 || (glVersion_Minor >= 0 && glVersion_Major >= 2))
			{
				Load2_0Extensions();
			}

			PrintErrorMessage(2, 0);
		}

		if (openGLVersions & GLVERSION2_1)
		{
			if (glVersion_Major > 2 || (glVersion_Minor >= 1 && glVersion_Major >= 2))
			{
				Load2_1Extensions();
			}

			PrintErrorMessage(2, 1);
		}

		if (openGLVersions & GLVERSION3_0)
		{
			if (glVersion_Major > 3 || (glVersion_Minor >= 0 && glVersion_Major >= 3))
			{
				Load3_0Extensions();
			}

			PrintErrorMessage(3, 0);
		}

		if (openGLVersions & GLVERSION3_1)
		{
			if (glVersion_Major > 3 || (glVersion_Minor >= 1 && glVersion_Major >= 3))
			{
				Load3_1Extensions();
			}

			PrintErrorMessage(3, 1);
		}

		if (openGLVersions & GLVERSION3_2)
		{
			if (glVersion_Major > 3 || (glVersion_Minor >= 2 && glVersion_Major >= 3))
			{
				Load3_2Extensions();
			}

			PrintErrorMessage(3, 2);
		}

		if (openGLVersions & GLVERSION3_3)
		{
			if (glVersion_Major > 3 || (glVersion_Minor >= 3 && glVersion_Major >= 3))
			{
				Load3_3Extensions();
			}

			PrintErrorMessage(3, 3);
		}

		if (openGLVersions & GLVERSION4_0)
		{
			if (glVersion_Major > 4 || (glVersion_Minor >= 0 && glVersion_Major >= 4))
			{
				Load4_0Extensions();
			}

			PrintErrorMessage(4, 0);
		}

		if (openGLVersions & GLVERSION4_1)
		{
			if (glVersion_Major > 4 || (glVersion_Minor >= 1 && glVersion_Major >= 4))
			{
				Load4_1Extensions();
			}

			PrintErrorMessage(4, 1);
		}

		if (openGLVersions & GLVERSION4_2)
		{
			if (glVersion_Major > 4 || (glVersion_Minor >= 2 && glVersion_Major >= 4))
			{
				Load4_2Extensions();
			}

			PrintErrorMessage(4, 2);
		}

		if (openGLVersions & GLVERSION4_3)
		{
			if (glVersion_Major > 4 || (glVersion_Minor >= 3 && glVersion_Major >= 4))
			{
				Load4_3Extensions();
			}

			PrintErrorMessage(4, 3);
		}

		if (openGLVersions & GLVERSION4_4)
		{
			if (glVersion_Major > 4 || (glVersion_Minor >= 4 && glVersion_Major >= 4))
			{
				Load4_4Extensions();
			}

			PrintErrorMessage(4, 4);
		}
	}

	GLvoid GetOpenGLVersion(GLuint& glVersion_Major, GLuint& glVersion_Minor)
	{
		glVersion_Major = glVersion_Major;
		glVersion_Minor = glVersion_Minor;
	}
	
	GLboolean IsExtensionSupported(GLubyte* extensionName)
	{
		GLubyte* end; //the last extension name in Extensions 
		GLint nameLength; //the string length of the given extension

		nameLength = strlen((const char*)extensionName); // the length of the given extension name string 

		GLubyte* extensions = (GLubyte*)glGetString(GL_EXTENSIONS); // get all supported extensions

		//if extensions is not empty
		if (extensions)
		{
			end = extensions + strlen((const char*)extensions);

			while (extensions < end)
			{
				GLint Blarg = strcspn((const char*)extensions, " ");
				if ((nameLength == Blarg) && (strncmp((const char*)extensionName, (const char*)extensions, Blarg) == 0))
				{
					return GL_TRUE;
				}

				extensions += (Blarg + 1);
			}
			return GL_FALSE;
		}
		return GL_FALSE;
	}

	//OpenGL 1.2 Extensions
	typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSPROC_t) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
	typedef void (APIENTRYP PFNGLTEXIMAGE3DPROC_t) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
	typedef void (APIENTRYP PFNGLTEXSUBIMAGE3DPROC_t) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
	typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE3DPROC_t) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	PFNGLDRAWRANGEELEMENTSPROC_t glDrawRangeElements;
	PFNGLTEXIMAGE3DPROC_t glTexImage3D;
	PFNGLTEXSUBIMAGE3DPROC_t glTexSubImage3D;
	PFNGLCOPYTEXSUBIMAGE3DPROC_t glCopyTexSubImage3D;

	//OpenGL 1.3 Extensions
	typedef void (APIENTRYP PFNGLACTIVETEXTUREPROC_t) (GLenum texture);
	typedef void (APIENTRYP PFNGLSAMPLECOVERAGEPROC_t) (GLfloat value, GLboolean invert);
	typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DPROC_t) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
	typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DPROC_t) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
	typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DPROC_t) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
	typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC_t) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
	typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC_t) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
	typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC_t) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
	typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEPROC_t) (GLenum target, GLint level, void *img);
	typedef void (APIENTRYP PFNGLCLIENTACTIVETEXTUREPROC_t) (GLenum texture);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD1DPROC_t) (GLenum target, GLdouble s);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD1DVPROC_t) (GLenum target, const GLdouble *v);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD1FPROC_t) (GLenum target, GLfloat s);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD1FVPROC_t) (GLenum target, const GLfloat *v);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD1IPROC_t) (GLenum target, GLint s);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD1IVPROC_t) (GLenum target, const GLint *v);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD1SPROC_t) (GLenum target, GLshort s);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD1SVPROC_t) (GLenum target, const GLshort *v);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD2DPROC_t) (GLenum target, GLdouble s, GLdouble t);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD2DVPROC_t) (GLenum target, const GLdouble *v);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD2FPROC_t) (GLenum target, GLfloat s, GLfloat t);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD2FVPROC_t) (GLenum target, const GLfloat *v);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD2IPROC_t) (GLenum target, GLint s, GLint t);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD2IVPROC_t) (GLenum target, const GLint *v);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD2SPROC_t) (GLenum target, GLshort s, GLshort t);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD2SVPROC_t) (GLenum target, const GLshort *v);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD3DPROC_t) (GLenum target, GLdouble s, GLdouble t, GLdouble r);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD3DVPROC_t) (GLenum target, const GLdouble *v);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD3FPROC_t) (GLenum target, GLfloat s, GLfloat t, GLfloat r);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD3FVPROC_t) (GLenum target, const GLfloat *v);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD3IPROC_t) (GLenum target, GLint s, GLint t, GLint r);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD3IVPROC_t) (GLenum target, const GLint *v);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD3SPROC_t) (GLenum target, GLshort s, GLshort t, GLshort r);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD3SVPROC_t) (GLenum target, const GLshort *v);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD4DPROC_t) (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD4DVPROC_t) (GLenum target, const GLdouble *v);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD4FPROC_t) (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD4FVPROC_t) (GLenum target, const GLfloat *v);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD4IPROC_t) (GLenum target, GLint s, GLint t, GLint r, GLint q);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD4IVPROC_t) (GLenum target, const GLint *v);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD4SPROC_t) (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
	typedef void (APIENTRYP PFNGLMULTITEXCOORD4SVPROC_t) (GLenum target, const GLshort *v);
	typedef void (APIENTRYP PFNGLLOADTRANSPOSEMATRIXFPROC_t) (const GLfloat *m);
	typedef void (APIENTRYP PFNGLLOADTRANSPOSEMATRIXDPROC_t) (const GLdouble *m);
	typedef void (APIENTRYP PFNGLMULTTRANSPOSEMATRIXFPROC_t) (const GLfloat *m);
	typedef void (APIENTRYP PFNGLMULTTRANSPOSEMATRIXDPROC_t) (const GLdouble *m);

	PFNGLACTIVETEXTUREPROC_t glActiveTexture;
	PFNGLSAMPLECOVERAGEPROC_t glSampleCoverage;
	PFNGLCOMPRESSEDTEXIMAGE3DPROC_t glCompressedTexImage3D;
	PFNGLCOMPRESSEDTEXIMAGE2DPROC_t glCompressedTexImage2D;
	PFNGLCOMPRESSEDTEXIMAGE1DPROC_t glCompressedTexImage1D;
	PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC_t glCompressedTexSubImage3D;
	PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC_t glCompressedTexSubImage2D;
	PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC_t glCompressedTexSubImage1D;
	PFNGLGETCOMPRESSEDTEXIMAGEPROC_t glGetCompressedTexImage;
	PFNGLCLIENTACTIVETEXTUREPROC_t glClientActiveTexture;
	PFNGLMULTITEXCOORD1DPROC_t glMultiTexCoord1d;
	PFNGLMULTITEXCOORD1DVPROC_t glMultiTexCoord1dv;
	PFNGLMULTITEXCOORD1FPROC_t glMultiTexCoord1f;
	PFNGLMULTITEXCOORD1FVPROC_t glMultiTexCoord1fv;
	PFNGLMULTITEXCOORD1IPROC_t glMultiTexCoord1i;
	PFNGLMULTITEXCOORD1IVPROC_t glMultiTexCoord1iv;
	PFNGLMULTITEXCOORD1SPROC_t glMultiTexCoord1s;
	PFNGLMULTITEXCOORD1SVPROC_t glMultiTexCoord1sv;
	PFNGLMULTITEXCOORD2DPROC_t glMultiTexCoord2d;
	PFNGLMULTITEXCOORD2DVPROC_t glMultiTexCoord2dv;
	PFNGLMULTITEXCOORD2FPROC_t glMultiTexCoord2f;
	PFNGLMULTITEXCOORD2FVPROC_t glMultiTexCoord2fv;
	PFNGLMULTITEXCOORD2IPROC_t glMultiTexCoord2i;
	PFNGLMULTITEXCOORD2IVPROC_t glMultiTexCoord2iv;
	PFNGLMULTITEXCOORD2SPROC_t glMultiTexCoord2s;
	PFNGLMULTITEXCOORD2SVPROC_t glMultiTexCoord2sv;
	PFNGLMULTITEXCOORD3DPROC_t glMultiTexCoord3d;
	PFNGLMULTITEXCOORD3DVPROC_t glMultiTexCoord3dv;
	PFNGLMULTITEXCOORD3FPROC_t glMultiTexCoord3f;
	PFNGLMULTITEXCOORD3FVPROC_t glMultiTexCoord3fv;
	PFNGLMULTITEXCOORD3IPROC_t glMultiTexCoord3i;
	PFNGLMULTITEXCOORD3IVPROC_t glMultiTexCoord3iv;
	PFNGLMULTITEXCOORD3SPROC_t glMultiTexCoord3s;
	PFNGLMULTITEXCOORD3SVPROC_t glMultiTexCoord3sv;
	PFNGLMULTITEXCOORD4DPROC_t glMultiTexCoord4d;
	PFNGLMULTITEXCOORD4DVPROC_t glMultiTexCoord4dv;
	PFNGLMULTITEXCOORD4FPROC_t glMultiTexCoord4f;
	PFNGLMULTITEXCOORD4FVPROC_t glMultiTexCoord4fv;
	PFNGLMULTITEXCOORD4IPROC_t glMultiTexCoord4i;
	PFNGLMULTITEXCOORD4IVPROC_t glMultiTexCoord4iv;
	PFNGLMULTITEXCOORD4SPROC_t glMultiTexCoord4s;
	PFNGLMULTITEXCOORD4SVPROC_t glMultiTexCoord4sv;
	PFNGLLOADTRANSPOSEMATRIXFPROC_t glLoadTransposeMatrixf;
	PFNGLLOADTRANSPOSEMATRIXDPROC_t glLoadTransposeMatrixd;
	PFNGLMULTTRANSPOSEMATRIXFPROC_t glMultTransposeMatrixf;
	PFNGLMULTTRANSPOSEMATRIXDPROC_t glMultTransposeMatrixd;

	//OpenGL 1.4 Extensions
	typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEPROC_t) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
	typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSPROC_t) (GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
	typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSPROC_t) (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
	typedef void (APIENTRYP PFNGLPOINTPARAMETERFPROC_t) (GLenum pname, GLfloat param);
	typedef void (APIENTRYP PFNGLPOINTPARAMETERFVPROC_t) (GLenum pname, const GLfloat *params);
	typedef void (APIENTRYP PFNGLPOINTPARAMETERIPROC_t) (GLenum pname, GLint param);
	typedef void (APIENTRYP PFNGLPOINTPARAMETERIVPROC_t) (GLenum pname, const GLint *params);
	typedef void (APIENTRYP PFNGLFOGCOORDFPROC_t) (GLfloat coord);
	typedef void (APIENTRYP PFNGLFOGCOORDFVPROC_t) (const GLfloat *coord);
	typedef void (APIENTRYP PFNGLFOGCOORDDPROC_t) (GLdouble coord);
	typedef void (APIENTRYP PFNGLFOGCOORDDVPROC_t) (const GLdouble *coord);
	typedef void (APIENTRYP PFNGLFOGCOORDPOINTERPROC_t) (GLenum type, GLsizei stride, const void *pointer);
	typedef void (APIENTRYP PFNGLSECONDARYCOLOR3BPROC_t) (GLbyte red, GLbyte green, GLbyte blue);
	typedef void (APIENTRYP PFNGLSECONDARYCOLOR3BVPROC_t) (const GLbyte *v);
	typedef void (APIENTRYP PFNGLSECONDARYCOLOR3DPROC_t) (GLdouble red, GLdouble green, GLdouble blue);
	typedef void (APIENTRYP PFNGLSECONDARYCOLOR3DVPROC_t) (const GLdouble *v);
	typedef void (APIENTRYP PFNGLSECONDARYCOLOR3FPROC_t) (GLfloat red, GLfloat green, GLfloat blue);
	typedef void (APIENTRYP PFNGLSECONDARYCOLOR3FVPROC_t) (const GLfloat *v);
	typedef void (APIENTRYP PFNGLSECONDARYCOLOR3IPROC_t) (GLint red, GLint green, GLint blue);
	typedef void (APIENTRYP PFNGLSECONDARYCOLOR3IVPROC_t) (const GLint *v);
	typedef void (APIENTRYP PFNGLSECONDARYCOLOR3SPROC_t) (GLshort red, GLshort green, GLshort blue);
	typedef void (APIENTRYP PFNGLSECONDARYCOLOR3SVPROC_t) (const GLshort *v);
	typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UBPROC_t) (GLubyte red, GLubyte green, GLubyte blue);
	typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UBVPROC_t) (const GLubyte *v);
	typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UIPROC_t) (GLuint red, GLuint green, GLuint blue);
	typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UIVPROC_t) (const GLuint *v);
	typedef void (APIENTRYP PFNGLSECONDARYCOLOR3USPROC_t) (GLushort red, GLushort green, GLushort blue);
	typedef void (APIENTRYP PFNGLSECONDARYCOLOR3USVPROC_t) (const GLushort *v);
	typedef void (APIENTRYP PFNGLSECONDARYCOLORPOINTERPROC_t) (GLint size, GLenum type, GLsizei stride, const void *pointer);
	typedef void (APIENTRYP PFNGLWINDOWPOS2DPROC_t) (GLdouble x, GLdouble y);
	typedef void (APIENTRYP PFNGLWINDOWPOS2DVPROC_t) (const GLdouble *v);
	typedef void (APIENTRYP PFNGLWINDOWPOS2FPROC_t) (GLfloat x, GLfloat y);
	typedef void (APIENTRYP PFNGLWINDOWPOS2FVPROC_t) (const GLfloat *v);
	typedef void (APIENTRYP PFNGLWINDOWPOS2IPROC_t) (GLint x, GLint y);
	typedef void (APIENTRYP PFNGLWINDOWPOS2IVPROC_t) (const GLint *v);
	typedef void (APIENTRYP PFNGLWINDOWPOS2SPROC_t) (GLshort x, GLshort y);
	typedef void (APIENTRYP PFNGLWINDOWPOS2SVPROC_t) (const GLshort *v);
	typedef void (APIENTRYP PFNGLWINDOWPOS3DPROC_t) (GLdouble x, GLdouble y, GLdouble z);
	typedef void (APIENTRYP PFNGLWINDOWPOS3DVPROC_t) (const GLdouble *v);
	typedef void (APIENTRYP PFNGLWINDOWPOS3FPROC_t) (GLfloat x, GLfloat y, GLfloat z);
	typedef void (APIENTRYP PFNGLWINDOWPOS3FVPROC_t) (const GLfloat *v);
	typedef void (APIENTRYP PFNGLWINDOWPOS3IPROC_t) (GLint x, GLint y, GLint z);
	typedef void (APIENTRYP PFNGLWINDOWPOS3IVPROC_t) (const GLint *v);
	typedef void (APIENTRYP PFNGLWINDOWPOS3SPROC_t) (GLshort x, GLshort y, GLshort z);
	typedef void (APIENTRYP PFNGLWINDOWPOS3SVPROC_t) (const GLshort *v);
	typedef void (APIENTRYP PFNGLBLENDCOLORPROC_t) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC_t) (GLenum mode);
	PFNGLBLENDFUNCSEPARATEPROC_t glBlendFuncSeparate;
	PFNGLMULTIDRAWARRAYSPROC_t glMultiDrawArrays;
	PFNGLMULTIDRAWELEMENTSPROC_t glMultiDrawElements;
	PFNGLPOINTPARAMETERFPROC_t glPointParameterf;
	PFNGLPOINTPARAMETERFVPROC_t glPointParameterfv;
	PFNGLPOINTPARAMETERIPROC_t glPointParameteri;
	PFNGLPOINTPARAMETERIVPROC_t glPointParameteriv;
	PFNGLFOGCOORDFPROC_t glFogCoordf;
	PFNGLFOGCOORDFVPROC_t glFogCoordfv;
	PFNGLFOGCOORDDPROC_t glFogCoordd;
	PFNGLFOGCOORDDVPROC_t glFogCoorddv;
	PFNGLFOGCOORDPOINTERPROC_t glFogCoordPointer;
	PFNGLSECONDARYCOLOR3BPROC_t glSecondaryColor3b;
	PFNGLSECONDARYCOLOR3BVPROC_t glSecondaryColor3bv;
	PFNGLSECONDARYCOLOR3DPROC_t glSecondaryColor3d;
	PFNGLSECONDARYCOLOR3DVPROC_t glSecondaryColor3dv;
	PFNGLSECONDARYCOLOR3FPROC_t glSecondaryColor3f;
	PFNGLSECONDARYCOLOR3FVPROC_t glSecondaryColor3fv;
	PFNGLSECONDARYCOLOR3IPROC_t glSecondaryColor3i;
	PFNGLSECONDARYCOLOR3IVPROC_t glSecondaryColor3iv;
	PFNGLSECONDARYCOLOR3SPROC_t glSecondaryColor3s;
	PFNGLSECONDARYCOLOR3SVPROC_t glSecondaryColor3sv;
	PFNGLSECONDARYCOLOR3UBPROC_t glSecondaryColor3ub;
	PFNGLSECONDARYCOLOR3UBVPROC_t glSecondaryColor3ubv;
	PFNGLSECONDARYCOLOR3UIPROC_t glSecondaryColor3ui;
	PFNGLSECONDARYCOLOR3UIVPROC_t glSecondaryColor3uiv;
	PFNGLSECONDARYCOLOR3USPROC_t glSecondaryColor3us;
	PFNGLSECONDARYCOLOR3USVPROC_t glSecondaryColor3usv;
	PFNGLSECONDARYCOLORPOINTERPROC_t glSecondaryColorPointer;
	PFNGLWINDOWPOS2DPROC_t glWindowPos2d;
	PFNGLWINDOWPOS2DVPROC_t glWindowPos2dv;
	PFNGLWINDOWPOS2FPROC_t glWindowPos2f;
	PFNGLWINDOWPOS2FVPROC_t glWindowPos2fv;
	PFNGLWINDOWPOS2IPROC_t glWindowPos2i;
	PFNGLWINDOWPOS2IVPROC_t glWindowPos2iv;
	PFNGLWINDOWPOS2SPROC_t glWindowPos2s;
	PFNGLWINDOWPOS2SVPROC_t glWindowPos2sv;
	PFNGLWINDOWPOS3DPROC_t glWindowPos3d;
	PFNGLWINDOWPOS3DVPROC_t glWindowPos3dv;
	PFNGLWINDOWPOS3FPROC_t glWindowPos3f;
	PFNGLWINDOWPOS3FVPROC_t glWindowPos3fv;
	PFNGLWINDOWPOS3IPROC_t glWindowPos3i;
	PFNGLWINDOWPOS3IVPROC_t glWindowPos3iv;
	PFNGLWINDOWPOS3SPROC_t glWindowPos3s;
	PFNGLWINDOWPOS3SVPROC_t glWindowPos3sv;
	PFNGLBLENDCOLORPROC_t glBlendColor;
	PFNGLBLENDEQUATIONPROC_t glBlendEquation;

	//OpenGL 1.5 Extensions
	typedef void (APIENTRYP PFNGLGENQUERIESPROC_t) (GLsizei n, GLuint *ids);
	typedef void (APIENTRYP PFNGLDELETEQUERIESPROC_t) (GLsizei n, const GLuint *ids);
	typedef GLboolean(APIENTRYP PFNGLISQUERYPROC_t) (GLuint id);
	typedef void (APIENTRYP PFNGLBEGINQUERYPROC_t) (GLenum target, GLuint id);
	typedef void (APIENTRYP PFNGLENDQUERYPROC_t) (GLenum target);
	typedef void (APIENTRYP PFNGLGETQUERYIVPROC_t) (GLenum target, GLenum pname, GLint *params);
	typedef void (APIENTRYP PFNGLGETQUERYOBJECTIVPROC_t) (GLuint id, GLenum pname, GLint *params);
	typedef void (APIENTRYP PFNGLGETQUERYOBJECTUIVPROC_t) (GLuint id, GLenum pname, GLuint *params);
	typedef void (APIENTRYP PFNGLBINDBUFFERPROC_t) (GLenum target, GLuint buffer);
	typedef void (APIENTRYP PFNGLDELETEBUFFERSPROC_t) (GLsizei n, const GLuint *buffers);
	typedef void (APIENTRYP PFNGLGENBUFFERSPROC_t) (GLsizei n, GLuint *buffers);
	typedef GLboolean(APIENTRYP PFNGLISBUFFERPROC_t) (GLuint buffer);
	typedef void (APIENTRYP PFNGLBUFFERDATAPROC_t) (GLenum target, GLsizeiptr size, const void *data, GLenum usage);
	typedef void (APIENTRYP PFNGLBUFFERSUBDATAPROC_t) (GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
	typedef void (APIENTRYP PFNGLGETBUFFERSUBDATAPROC_t) (GLenum target, GLintptr offset, GLsizeiptr size, void *data);
	typedef void *(APIENTRYP PFNGLMAPBUFFERPROC_t) (GLenum target, GLenum access);
	typedef GLboolean(APIENTRYP PFNGLUNMAPBUFFERPROC_t) (GLenum target);
	typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERIVPROC_t) (GLenum target, GLenum pname, GLint *params);
	typedef void (APIENTRYP PFNGLGETBUFFERPOINTERVPROC_t) (GLenum target, GLenum pname, void **params);
	PFNGLGENQUERIESPROC_t glGenQueries;
	PFNGLDELETEQUERIESPROC_t glDeleteQueries;
	PFNGLISQUERYPROC_t glIsQuery;
	PFNGLBEGINQUERYPROC_t glBeginQuery;
	PFNGLENDQUERYPROC_t glEndQuery;
	PFNGLGETQUERYIVPROC_t glGetQueryiv;
	PFNGLGETQUERYOBJECTIVPROC_t glGetQueryObjectiv;
	PFNGLGETQUERYOBJECTUIVPROC_t glGetQueryObjectuiv;
	PFNGLBINDBUFFERPROC_t glBindBuffer;
	PFNGLDELETEBUFFERSPROC_t glDeleteBuffers;
	PFNGLGENBUFFERSPROC_t glGenBuffers;
	PFNGLISBUFFERPROC_t glIsBuffer;
	PFNGLBUFFERDATAPROC_t glBufferData;
	PFNGLBUFFERSUBDATAPROC_t glBufferSubData;
	PFNGLGETBUFFERSUBDATAPROC_t glGetBufferSubData;
	PFNGLMAPBUFFERPROC_t glMapBuffer;
	PFNGLUNMAPBUFFERPROC_t glUnmapBuffer;
	PFNGLGETBUFFERPARAMETERIVPROC_t glGetBufferParameteriv;
	PFNGLGETBUFFERPOINTERVPROC_t glGetBufferPointerv;

	//OpenGL 2.0 Extensions
	typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEPROC_t) (GLenum modeRGB, GLenum modeAlpha);
	typedef void (APIENTRYP PFNGLDRAWBUFFERSPROC_t) (GLsizei n, const GLenum *bufs);
	typedef void (APIENTRYP PFNGLSTENCILOPSEPARATEPROC_t) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
	typedef void (APIENTRYP PFNGLSTENCILFUNCSEPARATEPROC_t) (GLenum face, GLenum func, GLint ref, GLuint mask);
	typedef void (APIENTRYP PFNGLSTENCILMASKSEPARATEPROC_t) (GLenum face, GLuint mask);
	typedef void (APIENTRYP PFNGLATTACHSHADERPROC_t) (GLuint program, GLuint shader);
	typedef void (APIENTRYP PFNGLBINDATTRIBLOCATIONPROC_t) (GLuint program, GLuint index, const GLchar *name);
	typedef void (APIENTRYP PFNGLCOMPILESHADERPROC_t) (GLuint shader);
	typedef GLuint(APIENTRYP PFNGLCREATEPROGRAMPROC_t) (void);
	typedef GLuint(APIENTRYP PFNGLCREATESHADERPROC_t) (GLenum type);
	typedef void (APIENTRYP PFNGLDELETEPROGRAMPROC_t) (GLuint program);
	typedef void (APIENTRYP PFNGLDELETESHADERPROC_t) (GLuint shader);
	typedef void (APIENTRYP PFNGLDETACHSHADERPROC_t) (GLuint program, GLuint shader);
	typedef void (APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYPROC_t) (GLuint index);
	typedef void (APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC_t) (GLuint index);
	typedef void (APIENTRYP PFNGLGETACTIVEATTRIBPROC_t) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
	typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMPROC_t) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
	typedef void (APIENTRYP PFNGLGETATTACHEDSHADERSPROC_t) (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
	typedef GLint(APIENTRYP PFNGLGETATTRIBLOCATIONPROC_t) (GLuint program, const GLchar *name);
	typedef void (APIENTRYP PFNGLGETPROGRAMIVPROC_t) (GLuint program, GLenum pname, GLint *params);
	typedef void (APIENTRYP PFNGLGETPROGRAMINFOLOGPROC_t) (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
	typedef void (APIENTRYP PFNGLGETSHADERIVPROC_t) (GLuint shader, GLenum pname, GLint *params);
	typedef void (APIENTRYP PFNGLGETSHADERINFOLOGPROC_t) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
	typedef void (APIENTRYP PFNGLGETSHADERSOURCEPROC_t) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
	typedef GLint(APIENTRYP PFNGLGETUNIFORMLOCATIONPROC_t) (GLuint program, const GLchar *name);
	typedef void (APIENTRYP PFNGLGETUNIFORMFVPROC_t) (GLuint program, GLint location, GLfloat *params);
	typedef void (APIENTRYP PFNGLGETUNIFORMIVPROC_t) (GLuint program, GLint location, GLint *params);
	typedef void (APIENTRYP PFNGLGETVERTEXATTRIBDVPROC_t) (GLuint index, GLenum pname, GLdouble *params);
	typedef void (APIENTRYP PFNGLGETVERTEXATTRIBFVPROC_t) (GLuint index, GLenum pname, GLfloat *params);
	typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIVPROC_t) (GLuint index, GLenum pname, GLint *params);
	typedef void (APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVPROC_t) (GLuint index, GLenum pname, void **pointer);
	typedef GLboolean(APIENTRYP PFNGLISPROGRAMPROC_t) (GLuint program);
	typedef GLboolean(APIENTRYP PFNGLISSHADERPROC_t) (GLuint shader);
	typedef void (APIENTRYP PFNGLLINKPROGRAMPROC_t) (GLuint program);
	typedef void (APIENTRYP PFNGLSHADERSOURCEPROC_t) (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
	typedef void (APIENTRYP PFNGLUSEPROGRAMPROC_t) (GLuint program);
	typedef void (APIENTRYP PFNGLUNIFORM1FPROC_t) (GLint location, GLfloat v0);
	typedef void (APIENTRYP PFNGLUNIFORM2FPROC_t) (GLint location, GLfloat v0, GLfloat v1);
	typedef void (APIENTRYP PFNGLUNIFORM3FPROC_t) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
	typedef void (APIENTRYP PFNGLUNIFORM4FPROC_t) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
	typedef void (APIENTRYP PFNGLUNIFORM1IPROC_t) (GLint location, GLint v0);
	typedef void (APIENTRYP PFNGLUNIFORM2IPROC_t) (GLint location, GLint v0, GLint v1);
	typedef void (APIENTRYP PFNGLUNIFORM3IPROC_t) (GLint location, GLint v0, GLint v1, GLint v2);
	typedef void (APIENTRYP PFNGLUNIFORM4IPROC_t) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
	typedef void (APIENTRYP PFNGLUNIFORM1FVPROC_t) (GLint location, GLsizei count, const GLfloat *value);
	typedef void (APIENTRYP PFNGLUNIFORM2FVPROC_t) (GLint location, GLsizei count, const GLfloat *value);
	typedef void (APIENTRYP PFNGLUNIFORM3FVPROC_t) (GLint location, GLsizei count, const GLfloat *value);
	typedef void (APIENTRYP PFNGLUNIFORM4FVPROC_t) (GLint location, GLsizei count, const GLfloat *value);
	typedef void (APIENTRYP PFNGLUNIFORM1IVPROC_t) (GLint location, GLsizei count, const GLint *value);
	typedef void (APIENTRYP PFNGLUNIFORM2IVPROC_t) (GLint location, GLsizei count, const GLint *value);
	typedef void (APIENTRYP PFNGLUNIFORM3IVPROC_t) (GLint location, GLsizei count, const GLint *value);
	typedef void (APIENTRYP PFNGLUNIFORM4IVPROC_t) (GLint location, GLsizei count, const GLint *value);
	typedef void (APIENTRYP PFNGLUNIFORMMATRIX2FVPROC_t) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	typedef void (APIENTRYP PFNGLUNIFORMMATRIX3FVPROC_t) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	typedef void (APIENTRYP PFNGLUNIFORMMATRIX4FVPROC_t) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPROC_t) (GLuint program);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB1DPROC_t) (GLuint index, GLdouble x);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB1DVPROC_t) (GLuint index, const GLdouble *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB1FPROC_t) (GLuint index, GLfloat x);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB1FVPROC_t) (GLuint index, const GLfloat *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB1SPROC_t) (GLuint index, GLshort x);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB1SVPROC_t) (GLuint index, const GLshort *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB2DPROC_t) (GLuint index, GLdouble x, GLdouble y);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB2DVPROC_t) (GLuint index, const GLdouble *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB2FPROC_t) (GLuint index, GLfloat x, GLfloat y);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB2FVPROC_t) (GLuint index, const GLfloat *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB2SPROC_t) (GLuint index, GLshort x, GLshort y);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB2SVPROC_t) (GLuint index, const GLshort *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB3DPROC_t) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB3DVPROC_t) (GLuint index, const GLdouble *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB3FPROC_t) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB3FVPROC_t) (GLuint index, const GLfloat *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB3SPROC_t) (GLuint index, GLshort x, GLshort y, GLshort z);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB3SVPROC_t) (GLuint index, const GLshort *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB4NBVPROC_t) (GLuint index, const GLbyte *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB4NIVPROC_t) (GLuint index, const GLint *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB4NSVPROC_t) (GLuint index, const GLshort *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBPROC_t) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBVPROC_t) (GLuint index, const GLubyte *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUIVPROC_t) (GLuint index, const GLuint *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUSVPROC_t) (GLuint index, const GLushort *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB4BVPROC_t) (GLuint index, const GLbyte *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB4DPROC_t) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB4DVPROC_t) (GLuint index, const GLdouble *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB4FPROC_t) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB4FVPROC_t) (GLuint index, const GLfloat *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB4IVPROC_t) (GLuint index, const GLint *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB4SPROC_t) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB4SVPROC_t) (GLuint index, const GLshort *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB4UBVPROC_t) (GLuint index, const GLubyte *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB4UIVPROC_t) (GLuint index, const GLuint *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIB4USVPROC_t) (GLuint index, const GLushort *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBPOINTERPROC_t) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
	PFNGLBLENDEQUATIONSEPARATEPROC_t glBlendEquationSeparate;
	PFNGLDRAWBUFFERSPROC_t glDrawBuffers;
	PFNGLSTENCILOPSEPARATEPROC_t glStencilOpSeparate;
	PFNGLSTENCILFUNCSEPARATEPROC_t glStencilFuncSeparate;
	PFNGLSTENCILMASKSEPARATEPROC_t glStencilMaskSeparate;
	PFNGLATTACHSHADERPROC_t glAttachShader;
	PFNGLBINDATTRIBLOCATIONPROC_t glBindAttribLocation;
	PFNGLCOMPILESHADERPROC_t glCompileShader;
	PFNGLCREATEPROGRAMPROC_t glCreateProgram;
	PFNGLCREATESHADERPROC_t glCreateShader;
	PFNGLDELETEPROGRAMPROC_t glDeleteProgram;
	PFNGLDELETESHADERPROC_t glDeleteShader;
	PFNGLDETACHSHADERPROC_t glDetachShader;
	PFNGLDISABLEVERTEXATTRIBARRAYPROC_t glDisableVertexAttribArray;
	PFNGLENABLEVERTEXATTRIBARRAYPROC_t glEnableVertexAttribArray;
	PFNGLGETACTIVEATTRIBPROC_t glGetActiveAttrib;
	PFNGLGETACTIVEUNIFORMPROC_t glGetActiveUniform;
	PFNGLGETATTACHEDSHADERSPROC_t glGetAttachedShaders;
	PFNGLGETATTRIBLOCATIONPROC_t glGetAttribLocation;
	PFNGLGETPROGRAMIVPROC_t glGetProgramiv;
	PFNGLGETPROGRAMINFOLOGPROC_t glGetProgramInfoLog;
	PFNGLGETSHADERIVPROC_t glGetShaderiv;
	PFNGLGETSHADERINFOLOGPROC_t glGetShaderInfoLog;
	PFNGLGETSHADERSOURCEPROC_t glGetShaderSource;
	PFNGLGETUNIFORMLOCATIONPROC_t glGetUniformLocation;
	PFNGLGETUNIFORMFVPROC_t glGetUniformfv;
	PFNGLGETUNIFORMIVPROC_t glGetUniformiv;
	PFNGLGETVERTEXATTRIBDVPROC_t glGetVertexAttribdv;
	PFNGLGETVERTEXATTRIBFVPROC_t glGetVertexAttribfv;
	PFNGLGETVERTEXATTRIBIVPROC_t glGetVertexAttribiv;
	PFNGLGETVERTEXATTRIBPOINTERVPROC_t glGetVertexAttribPointerv;
	PFNGLISPROGRAMPROC_t glIsProgram;
	PFNGLISSHADERPROC_t glIsShader;
	PFNGLLINKPROGRAMPROC_t glLinkProgram;
	PFNGLSHADERSOURCEPROC_t glShaderSource;
	PFNGLUSEPROGRAMPROC_t glUseProgram;
	PFNGLUNIFORM1FPROC_t glUniform1f;
	PFNGLUNIFORM2FPROC_t glUniform2f;
	PFNGLUNIFORM3FPROC_t glUniform3f;
	PFNGLUNIFORM4FPROC_t glUniform4f;
	PFNGLUNIFORM1IPROC_t glUniform1i;
	PFNGLUNIFORM2IPROC_t glUniform2i;
	PFNGLUNIFORM3IPROC_t glUniform3i;
	PFNGLUNIFORM4IPROC_t glUniform4i;
	PFNGLUNIFORM1FVPROC_t glUniform1fv;
	PFNGLUNIFORM2FVPROC_t glUniform2fv;
	PFNGLUNIFORM3FVPROC_t glUniform3fv;
	PFNGLUNIFORM4FVPROC_t glUniform4fv;
	PFNGLUNIFORM1IVPROC_t glUniform1iv;
	PFNGLUNIFORM2IVPROC_t glUniform2iv;
	PFNGLUNIFORM3IVPROC_t glUniform3iv;
	PFNGLUNIFORM4IVPROC_t glUniform4iv;
	PFNGLUNIFORMMATRIX2FVPROC_t glUniformMatrix2fv;
	PFNGLUNIFORMMATRIX3FVPROC_t glUniformMatrix3fv;
	PFNGLUNIFORMMATRIX4FVPROC_t glUniformMatrix4fv;
	PFNGLVALIDATEPROGRAMPROC_t glValidateProgram;
	PFNGLVERTEXATTRIB1DPROC_t glVertexAttrib1d;
	PFNGLVERTEXATTRIB1DVPROC_t glVertexAttrib1dv;
	PFNGLVERTEXATTRIB1FPROC_t glVertexAttrib1f;
	PFNGLVERTEXATTRIB1FVPROC_t glVertexAttrib1fv;
	PFNGLVERTEXATTRIB1SPROC_t glVertexAttrib1s;
	PFNGLVERTEXATTRIB1SVPROC_t glVertexAttrib1sv;
	PFNGLVERTEXATTRIB2DPROC_t glVertexAttrib2d;
	PFNGLVERTEXATTRIB2DVPROC_t glVertexAttrib2dv;
	PFNGLVERTEXATTRIB2FPROC_t glVertexAttrib2f;
	PFNGLVERTEXATTRIB2FVPROC_t glVertexAttrib2fv;
	PFNGLVERTEXATTRIB2SPROC_t glVertexAttrib2s;
	PFNGLVERTEXATTRIB2SVPROC_t glVertexAttrib2sv;
	PFNGLVERTEXATTRIB3DPROC_t glVertexAttrib3d;
	PFNGLVERTEXATTRIB3DVPROC_t glVertexAttrib3dv;
	PFNGLVERTEXATTRIB3FPROC_t glVertexAttrib3f;
	PFNGLVERTEXATTRIB3FVPROC_t glVertexAttrib3fv;
	PFNGLVERTEXATTRIB3SPROC_t glVertexAttrib3s;
	PFNGLVERTEXATTRIB3SVPROC_t glVertexAttrib3sv;
	PFNGLVERTEXATTRIB4NBVPROC_t glVertexAttrib4Nbv;
	PFNGLVERTEXATTRIB4NIVPROC_t glVertexAttrib4Niv;
	PFNGLVERTEXATTRIB4NSVPROC_t glVertexAttrib4Nsv;
	PFNGLVERTEXATTRIB4NUBPROC_t glVertexAttrib4Nub;
	PFNGLVERTEXATTRIB4NUBVPROC_t glVertexAttrib4Nubv;
	PFNGLVERTEXATTRIB4NUIVPROC_t glVertexAttrib4Nuiv;
	PFNGLVERTEXATTRIB4NUSVPROC_t glVertexAttrib4Nusv;
	PFNGLVERTEXATTRIB4BVPROC_t glVertexAttrib4bv;
	PFNGLVERTEXATTRIB4DPROC_t glVertexAttrib4d;
	PFNGLVERTEXATTRIB4DVPROC_t glVertexAttrib4dv;
	PFNGLVERTEXATTRIB4FPROC_t glVertexAttrib4f;
	PFNGLVERTEXATTRIB4FVPROC_t glVertexAttrib4fv;
	PFNGLVERTEXATTRIB4IVPROC_t glVertexAttrib4iv;
	PFNGLVERTEXATTRIB4SPROC_t glVertexAttrib4s;
	PFNGLVERTEXATTRIB4SVPROC_t glVertexAttrib4sv;
	PFNGLVERTEXATTRIB4UBVPROC_t glVertexAttrib4ubv;
	PFNGLVERTEXATTRIB4UIVPROC_t glVertexAttrib4uiv;
	PFNGLVERTEXATTRIB4USVPROC_t glVertexAttrib4usv;
	PFNGLVERTEXATTRIBPOINTERPROC_t glVertexAttribPointer;

	//OpenGL 2.1 Extensions
	typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3FVPROC_t) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2FVPROC_t) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4FVPROC_t) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2FVPROC_t) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4FVPROC_t) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3FVPROC_t) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	PFNGLUNIFORMMATRIX2X3FVPROC_t glUniformMatrix2x3fv;
	PFNGLUNIFORMMATRIX3X2FVPROC_t glUniformMatrix3x2fv;
	PFNGLUNIFORMMATRIX2X4FVPROC_t glUniformMatrix2x4fv;
	PFNGLUNIFORMMATRIX4X2FVPROC_t glUniformMatrix4x2fv;
	PFNGLUNIFORMMATRIX3X4FVPROC_t glUniformMatrix3x4fv;
	PFNGLUNIFORMMATRIX4X3FVPROC_t glUniformMatrix4x3fv;

	//OpenGL 3.0 Extensions
	typedef void (APIENTRYP PFNGLCOLORMASKIPROC_t) (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
	typedef void (APIENTRYP PFNGLGETBOOLEANI_VPROC_t) (GLenum target, GLuint index, GLboolean *data);
	typedef void (APIENTRYP PFNGLGETINTEGERI_VPROC_t) (GLenum target, GLuint index, GLint *data);
	typedef void (APIENTRYP PFNGLENABLEIPROC_t) (GLenum target, GLuint index);
	typedef void (APIENTRYP PFNGLDISABLEIPROC_t) (GLenum target, GLuint index);
	typedef GLboolean(APIENTRYP PFNGLISENABLEDIPROC_t) (GLenum target, GLuint index);
	typedef void (APIENTRYP PFNGLBEGINTRANSFORMFEEDBACKPROC_t) (GLenum primitiveMode);
	typedef void (APIENTRYP PFNGLENDTRANSFORMFEEDBACKPROC_t) (void);
	typedef void (APIENTRYP PFNGLBINDBUFFERRANGEPROC_t) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
	typedef void (APIENTRYP PFNGLBINDBUFFERBASEPROC_t) (GLenum target, GLuint index, GLuint buffer);
	typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSPROC_t) (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
	typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGPROC_t) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
	typedef void (APIENTRYP PFNGLCLAMPCOLORPROC_t) (GLenum target, GLenum clamp);
	typedef void (APIENTRYP PFNGLBEGINCONDITIONALRENDERPROC_t) (GLuint id, GLenum mode);
	typedef void (APIENTRYP PFNGLENDCONDITIONALRENDERPROC_t) (void);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBIPOINTERPROC_t) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
	typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIIVPROC_t) (GLuint index, GLenum pname, GLint *params);
	typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIUIVPROC_t) (GLuint index, GLenum pname, GLuint *params);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IPROC_t) (GLuint index, GLint x);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IPROC_t) (GLuint index, GLint x, GLint y);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IPROC_t) (GLuint index, GLint x, GLint y, GLint z);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IPROC_t) (GLuint index, GLint x, GLint y, GLint z, GLint w);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIPROC_t) (GLuint index, GLuint x);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIPROC_t) (GLuint index, GLuint x, GLuint y);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIPROC_t) (GLuint index, GLuint x, GLuint y, GLuint z);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIPROC_t) (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IVPROC_t) (GLuint index, const GLint *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IVPROC_t) (GLuint index, const GLint *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IVPROC_t) (GLuint index, const GLint *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IVPROC_t) (GLuint index, const GLint *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIVPROC_t) (GLuint index, const GLuint *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIVPROC_t) (GLuint index, const GLuint *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIVPROC_t) (GLuint index, const GLuint *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIVPROC_t) (GLuint index, const GLuint *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBI4BVPROC_t) (GLuint index, const GLbyte *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBI4SVPROC_t) (GLuint index, const GLshort *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UBVPROC_t) (GLuint index, const GLubyte *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBI4USVPROC_t) (GLuint index, const GLushort *v);
	typedef void (APIENTRYP PFNGLGETUNIFORMUIVPROC_t) (GLuint program, GLint location, GLuint *params);
	typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONPROC_t) (GLuint program, GLuint color, const GLchar *name);
	typedef GLint(APIENTRYP PFNGLGETFRAGDATALOCATIONPROC_t) (GLuint program, const GLchar *name);
	typedef void (APIENTRYP PFNGLUNIFORM1UIPROC_t) (GLint location, GLuint v0);
	typedef void (APIENTRYP PFNGLUNIFORM2UIPROC_t) (GLint location, GLuint v0, GLuint v1);
	typedef void (APIENTRYP PFNGLUNIFORM3UIPROC_t) (GLint location, GLuint v0, GLuint v1, GLuint v2);
	typedef void (APIENTRYP PFNGLUNIFORM4UIPROC_t) (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
	typedef void (APIENTRYP PFNGLUNIFORM1UIVPROC_t) (GLint location, GLsizei count, const GLuint *value);
	typedef void (APIENTRYP PFNGLUNIFORM2UIVPROC_t) (GLint location, GLsizei count, const GLuint *value);
	typedef void (APIENTRYP PFNGLUNIFORM3UIVPROC_t) (GLint location, GLsizei count, const GLuint *value);
	typedef void (APIENTRYP PFNGLUNIFORM4UIVPROC_t) (GLint location, GLsizei count, const GLuint *value);
	typedef void (APIENTRYP PFNGLTEXPARAMETERIIVPROC_t) (GLenum target, GLenum pname, const GLint *params);
	typedef void (APIENTRYP PFNGLTEXPARAMETERIUIVPROC_t) (GLenum target, GLenum pname, const GLuint *params);
	typedef void (APIENTRYP PFNGLGETTEXPARAMETERIIVPROC_t) (GLenum target, GLenum pname, GLint *params);
	typedef void (APIENTRYP PFNGLGETTEXPARAMETERIUIVPROC_t) (GLenum target, GLenum pname, GLuint *params);
	typedef void (APIENTRYP PFNGLCLEARBUFFERIVPROC_t) (GLenum buffer, GLint drawbuffer, const GLint *value);
	typedef void (APIENTRYP PFNGLCLEARBUFFERUIVPROC_t) (GLenum buffer, GLint drawbuffer, const GLuint *value);
	typedef void (APIENTRYP PFNGLCLEARBUFFERFVPROC_t) (GLenum buffer, GLint drawbuffer, const GLfloat *value);
	typedef void (APIENTRYP PFNGLCLEARBUFFERFIPROC_t) (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
	typedef const GLubyte *(APIENTRYP PFNGLGETSTRINGIPROC_t) (GLenum name, GLuint index);
	typedef GLboolean(APIENTRYP PFNGLISRENDERBUFFERPROC_t) (GLuint renderbuffer);
	typedef void (APIENTRYP PFNGLBINDRENDERBUFFERPROC_t) (GLenum target, GLuint renderbuffer);
	typedef void (APIENTRYP PFNGLDELETERENDERBUFFERSPROC_t) (GLsizei n, const GLuint *renderbuffers);
	typedef void (APIENTRYP PFNGLGENRENDERBUFFERSPROC_t) (GLsizei n, GLuint *renderbuffers);
	typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEPROC_t) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
	typedef void (APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVPROC_t) (GLenum target, GLenum pname, GLint *params);
	typedef GLboolean(APIENTRYP PFNGLISFRAMEBUFFERPROC_t) (GLuint framebuffer);
	typedef void (APIENTRYP PFNGLBINDFRAMEBUFFERPROC_t) (GLenum target, GLuint framebuffer);
	typedef void (APIENTRYP PFNGLDELETEFRAMEBUFFERSPROC_t) (GLsizei n, const GLuint *framebuffers);
	typedef void (APIENTRYP PFNGLGENFRAMEBUFFERSPROC_t) (GLsizei n, GLuint *framebuffers);
	typedef GLenum(APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSPROC_t) (GLenum target);
	typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE1DPROC_t) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DPROC_t) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE3DPROC_t) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
	typedef void (APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFERPROC_t) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
	typedef void (APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC_t) (GLenum target, GLenum attachment, GLenum pname, GLint *params);
	typedef void (APIENTRYP PFNGLGENERATEMIPMAPPROC_t) (GLenum target);
	typedef void (APIENTRYP PFNGLBLITFRAMEBUFFERPROC_t) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
	typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC_t) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
	typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERPROC_t) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
	typedef void *(APIENTRYP PFNGLMAPBUFFERRANGEPROC_t) (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
	typedef void (APIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEPROC_t) (GLenum target, GLintptr offset, GLsizeiptr length);
	typedef void (APIENTRYP PFNGLBINDVERTEXARRAYPROC_t) (GLuint array);
	typedef void (APIENTRYP PFNGLDELETEVERTEXARRAYSPROC_t) (GLsizei n, const GLuint *arrays);
	typedef void (APIENTRYP PFNGLGENVERTEXARRAYSPROC_t) (GLsizei n, GLuint *arrays);
	typedef GLboolean(APIENTRYP PFNGLISVERTEXARRAYPROC_t) (GLuint array);
	PFNGLCOLORMASKIPROC_t glColorMaski;
	PFNGLGETBOOLEANI_VPROC_t glGetBooleani_v;
	PFNGLGETINTEGERI_VPROC_t glGetIntegeri_v;
	PFNGLENABLEIPROC_t glEnablei;
	PFNGLDISABLEIPROC_t glDisablei;
	PFNGLISENABLEDIPROC_t glIsEnabledi;
	PFNGLBEGINTRANSFORMFEEDBACKPROC_t glBeginTransformFeedback;
	PFNGLENDTRANSFORMFEEDBACKPROC_t glEndTransformFeedback;
	PFNGLBINDBUFFERRANGEPROC_t glBindBufferRange;
	PFNGLBINDBUFFERBASEPROC_t glBindBufferBase;
	PFNGLTRANSFORMFEEDBACKVARYINGSPROC_t glTransformFeedbackVaryings;
	PFNGLGETTRANSFORMFEEDBACKVARYINGPROC_t glGetTransformFeedbackVarying;
	PFNGLCLAMPCOLORPROC_t glClampColor;
	PFNGLBEGINCONDITIONALRENDERPROC_t glBeginConditionalRender;
	PFNGLENDCONDITIONALRENDERPROC_t glEndConditionalRender;
	PFNGLVERTEXATTRIBIPOINTERPROC_t glVertexAttribIPointer;
	PFNGLGETVERTEXATTRIBIIVPROC_t glGetVertexAttribIiv;
	PFNGLGETVERTEXATTRIBIUIVPROC_t glGetVertexAttribIuiv;
	PFNGLVERTEXATTRIBI1IPROC_t glVertexAttribI1i;
	PFNGLVERTEXATTRIBI2IPROC_t glVertexAttribI2i;
	PFNGLVERTEXATTRIBI3IPROC_t glVertexAttribI3i;
	PFNGLVERTEXATTRIBI4IPROC_t glVertexAttribI4i;
	PFNGLVERTEXATTRIBI1UIPROC_t glVertexAttribI1ui;
	PFNGLVERTEXATTRIBI2UIPROC_t glVertexAttribI2ui;
	PFNGLVERTEXATTRIBI3UIPROC_t glVertexAttribI3ui;
	PFNGLVERTEXATTRIBI4UIPROC_t glVertexAttribI4ui;
	PFNGLVERTEXATTRIBI1IVPROC_t glVertexAttribI1iv;
	PFNGLVERTEXATTRIBI2IVPROC_t glVertexAttribI2iv;
	PFNGLVERTEXATTRIBI3IVPROC_t glVertexAttribI3iv;
	PFNGLVERTEXATTRIBI4IVPROC_t glVertexAttribI4iv;
	PFNGLVERTEXATTRIBI1UIVPROC_t glVertexAttribI1uiv;
	PFNGLVERTEXATTRIBI2UIVPROC_t glVertexAttribI2uiv;
	PFNGLVERTEXATTRIBI3UIVPROC_t glVertexAttribI3uiv;
	PFNGLVERTEXATTRIBI4UIVPROC_t glVertexAttribI4uiv;
	PFNGLVERTEXATTRIBI4BVPROC_t glVertexAttribI4bv;
	PFNGLVERTEXATTRIBI4SVPROC_t glVertexAttribI4sv;
	PFNGLVERTEXATTRIBI4UBVPROC_t glVertexAttribI4ubv;
	PFNGLVERTEXATTRIBI4USVPROC_t glVertexAttribI4usv;
	PFNGLGETUNIFORMUIVPROC_t glGetUniformuiv;
	PFNGLBINDFRAGDATALOCATIONPROC_t glBindFragDataLocation;
	PFNGLGETFRAGDATALOCATIONPROC_t glGetFragDataLocation;
	PFNGLUNIFORM1UIPROC_t glUniform1ui;
	PFNGLUNIFORM2UIPROC_t glUniform2ui;
	PFNGLUNIFORM3UIPROC_t glUniform3ui;
	PFNGLUNIFORM4UIPROC_t glUniform4ui;
	PFNGLUNIFORM1UIVPROC_t glUniform1uiv;
	PFNGLUNIFORM2UIVPROC_t glUniform2uiv;
	PFNGLUNIFORM3UIVPROC_t glUniform3uiv;
	PFNGLUNIFORM4UIVPROC_t glUniform4uiv;
	PFNGLTEXPARAMETERIIVPROC_t glTexParameterIiv;
	PFNGLTEXPARAMETERIUIVPROC_t glTexParameterIuiv;
	PFNGLGETTEXPARAMETERIIVPROC_t glGetTexParameterIiv;
	PFNGLGETTEXPARAMETERIUIVPROC_t glGetTexParameterIuiv;
	PFNGLCLEARBUFFERIVPROC_t glClearBufferiv;
	PFNGLCLEARBUFFERUIVPROC_t glClearBufferuiv;
	PFNGLCLEARBUFFERFVPROC_t glClearBufferfv;
	PFNGLCLEARBUFFERFIPROC_t glClearBufferfi;
	PFNGLGETSTRINGIPROC_t glGetStringi;
	PFNGLISRENDERBUFFERPROC_t glIsRenderbuffer;
	PFNGLBINDRENDERBUFFERPROC_t glBindRenderbuffer;
	PFNGLDELETERENDERBUFFERSPROC_t glDeleteRenderbuffers;
	PFNGLGENRENDERBUFFERSPROC_t glGenRenderbuffers;
	PFNGLRENDERBUFFERSTORAGEPROC_t glRenderbufferStorage;
	PFNGLGETRENDERBUFFERPARAMETERIVPROC_t glGetRenderbufferParameteriv;
	PFNGLISFRAMEBUFFERPROC_t glIsFramebuffer;
	PFNGLBINDFRAMEBUFFERPROC_t glBindFramebuffer;
	PFNGLDELETEFRAMEBUFFERSPROC_t glDeleteFramebuffers;
	PFNGLGENFRAMEBUFFERSPROC_t glGenFramebuffers;
	PFNGLCHECKFRAMEBUFFERSTATUSPROC_t glCheckFramebufferStatus;
	PFNGLFRAMEBUFFERTEXTURE1DPROC_t glFramebufferTexture1D;
	PFNGLFRAMEBUFFERTEXTURE2DPROC_t glFramebufferTexture2D;
	PFNGLFRAMEBUFFERTEXTURE3DPROC_t glFramebufferTexture3D;
	PFNGLFRAMEBUFFERRENDERBUFFERPROC_t glFramebufferRenderbuffer;
	PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC_t glGetFramebufferAttachmentParameteriv;
	PFNGLGENERATEMIPMAPPROC_t glGenerateMipmap;
	PFNGLBLITFRAMEBUFFERPROC_t glBlitFramebuffer;
	PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC_t glRenderbufferStorageMultisample;
	PFNGLFRAMEBUFFERTEXTURELAYERPROC_t glFramebufferTextureLayer;
	PFNGLMAPBUFFERRANGEPROC_t glMapBufferRange;
	PFNGLFLUSHMAPPEDBUFFERRANGEPROC_t glFlushMappedBufferRange;
	PFNGLBINDVERTEXARRAYPROC_t glBindVertexArray;
	PFNGLDELETEVERTEXARRAYSPROC_t glDeleteVertexArrays;
	PFNGLGENVERTEXARRAYSPROC_t glGenVertexArrays;
	PFNGLISVERTEXARRAYPROC_t glIsVertexArray;

	//OpenGL 3.1 Extensions
	typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDPROC_t) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
	typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDPROC_t) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
	typedef void (APIENTRYP PFNGLTEXBUFFERPROC_t) (GLenum target, GLenum internalformat, GLuint buffer);
	typedef void (APIENTRYP PFNGLPRIMITIVERESTARTINDEXPROC_t) (GLuint index);
	typedef void (APIENTRYP PFNGLCOPYBUFFERSUBDATAPROC_t) (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
	typedef void (APIENTRYP PFNGLGETUNIFORMINDICESPROC_t) (GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
	typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMSIVPROC_t) (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
	typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMNAMEPROC_t) (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
	typedef GLuint(APIENTRYP PFNGLGETUNIFORMBLOCKINDEXPROC_t) (GLuint program, const GLchar *uniformBlockName);
	typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKIVPROC_t) (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
	typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC_t) (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
	typedef void (APIENTRYP PFNGLUNIFORMBLOCKBINDINGPROC_t) (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
	PFNGLDRAWARRAYSINSTANCEDPROC_t glDrawArraysInstanced;
	PFNGLDRAWELEMENTSINSTANCEDPROC_t glDrawElementsInstanced;
	PFNGLTEXBUFFERPROC_t glTexBuffer;
	PFNGLPRIMITIVERESTARTINDEXPROC_t glPrimitiveRestartIndex;
	PFNGLCOPYBUFFERSUBDATAPROC_t glCopyBufferSubData;
	PFNGLGETUNIFORMINDICESPROC_t glGetUniformIndices;
	PFNGLGETACTIVEUNIFORMSIVPROC_t glGetActiveUniformsiv;
	PFNGLGETACTIVEUNIFORMNAMEPROC_t glGetActiveUniformName;
	PFNGLGETUNIFORMBLOCKINDEXPROC_t glGetUniformBlockIndex;
	PFNGLGETACTIVEUNIFORMBLOCKIVPROC_t glGetActiveUniformBlockiv;
	PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC_t glGetActiveUniformBlockName;
	PFNGLUNIFORMBLOCKBINDINGPROC_t glUniformBlockBinding;

	//OpenGL 3.2 Extensions
	typedef void (APIENTRYP PFNGLDRAWELEMENTSBASEVERTEXPROC_t) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
	typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC_t) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
	typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC_t) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
	typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC_t) (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
	typedef void (APIENTRYP PFNGLPROVOKINGVERTEXPROC_t) (GLenum mode);
	typedef GLsync(APIENTRYP PFNGLFENCESYNCPROC_t) (GLenum condition, GLbitfield flags);
	typedef GLboolean(APIENTRYP PFNGLISSYNCPROC_t) (GLsync sync);
	typedef void (APIENTRYP PFNGLDELETESYNCPROC_t) (GLsync sync);
	typedef GLenum(APIENTRYP PFNGLCLIENTWAITSYNCPROC_t) (GLsync sync, GLbitfield flags, GLuint64 timeout);
	typedef void (APIENTRYP PFNGLWAITSYNCPROC_t) (GLsync sync, GLbitfield flags, GLuint64 timeout);
	typedef void (APIENTRYP PFNGLGETINTEGER64VPROC_t) (GLenum pname, GLint64 *params);
	typedef void (APIENTRYP PFNGLGETSYNCIVPROC_t) (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
	typedef void (APIENTRYP PFNGLGETINTEGER64I_VPROC_t) (GLenum target, GLuint index, GLint64 *data);
	typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERI64VPROC_t) (GLenum target, GLenum pname, GLint64 *params);
	typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREPROC_t) (GLenum target, GLenum attachment, GLuint texture, GLint level);
	typedef void (APIENTRYP PFNGLTEXIMAGE2DMULTISAMPLEPROC_t) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
	typedef void (APIENTRYP PFNGLTEXIMAGE3DMULTISAMPLEPROC_t) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
	typedef void (APIENTRYP PFNGLGETMULTISAMPLEFVPROC_t) (GLenum pname, GLuint index, GLfloat *val);
	typedef void (APIENTRYP PFNGLSAMPLEMASKIPROC_t) (GLuint index, GLbitfield mask);
	PFNGLDRAWELEMENTSBASEVERTEXPROC_t glDrawElementsBaseVertex;
	PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC_t glDrawRangeElementsBaseVertex;
	PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC_t glDrawElementsInstancedBaseVertex;
	PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC_t glMultiDrawElementsBaseVertex;
	PFNGLPROVOKINGVERTEXPROC_t glProvokingVertex;
	PFNGLFENCESYNCPROC_t glFenceSync;
	PFNGLISSYNCPROC_t glIsSync;
	PFNGLDELETESYNCPROC_t glDeleteSync;
	PFNGLCLIENTWAITSYNCPROC_t glClientWaitSync;
	PFNGLWAITSYNCPROC_t glWaitSync;
	PFNGLGETINTEGER64VPROC_t glGetInteger64v;
	PFNGLGETSYNCIVPROC_t glGetSynciv;
	PFNGLGETINTEGER64I_VPROC_t glGetInteger64i_v;
	PFNGLGETBUFFERPARAMETERI64VPROC_t glGetBufferParameteri64v;
	PFNGLFRAMEBUFFERTEXTUREPROC_t glFramebufferTexture;
	PFNGLTEXIMAGE2DMULTISAMPLEPROC_t glTexImage2DMultisample;
	PFNGLTEXIMAGE3DMULTISAMPLEPROC_t glTexImage3DMultisample;
	PFNGLGETMULTISAMPLEFVPROC_t glGetMultisamplefv;
	PFNGLSAMPLEMASKIPROC_t glSampleMaski;

	//OpenGL 3.3 Extensions
	typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONINDEXEDPROC_t) (GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
	typedef GLint(APIENTRYP PFNGLGETFRAGDATAINDEXPROC_t) (GLuint program, const GLchar *name);
	typedef void (APIENTRYP PFNGLGENSAMPLERSPROC_t) (GLsizei count, GLuint *samplers);
	typedef void (APIENTRYP PFNGLDELETESAMPLERSPROC_t) (GLsizei count, const GLuint *samplers);
	typedef GLboolean(APIENTRYP PFNGLISSAMPLERPROC_t) (GLuint sampler);
	typedef void (APIENTRYP PFNGLBINDSAMPLERPROC_t) (GLuint unit, GLuint sampler);
	typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIPROC_t) (GLuint sampler, GLenum pname, GLint param);
	typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIVPROC_t) (GLuint sampler, GLenum pname, const GLint *param);
	typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFPROC_t) (GLuint sampler, GLenum pname, GLfloat param);
	typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFVPROC_t) (GLuint sampler, GLenum pname, const GLfloat *param);
	typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIIVPROC_t) (GLuint sampler, GLenum pname, const GLint *param);
	typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIUIVPROC_t) (GLuint sampler, GLenum pname, const GLuint *param);
	typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIVPROC_t) (GLuint sampler, GLenum pname, GLint *params);
	typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIIVPROC_t) (GLuint sampler, GLenum pname, GLint *params);
	typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERFVPROC_t) (GLuint sampler, GLenum pname, GLfloat *params);
	typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIUIVPROC_t) (GLuint sampler, GLenum pname, GLuint *params);
	typedef void (APIENTRYP PFNGLQUERYCOUNTERPROC_t) (GLuint id, GLenum target);
	typedef void (APIENTRYP PFNGLGETQUERYOBJECTI64VPROC_t) (GLuint id, GLenum pname, GLint64 *params);
	typedef void (APIENTRYP PFNGLGETQUERYOBJECTUI64VPROC_t) (GLuint id, GLenum pname, GLuint64 *params);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBDIVISORPROC_t) (GLuint index, GLuint divisor);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIPROC_t) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIVPROC_t) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIPROC_t) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIVPROC_t) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIPROC_t) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIVPROC_t) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIPROC_t) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIVPROC_t) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
	typedef void (APIENTRYP PFNGLVERTEXP2UIPROC_t) (GLenum type, GLuint value);
	typedef void (APIENTRYP PFNGLVERTEXP2UIVPROC_t) (GLenum type, const GLuint *value);
	typedef void (APIENTRYP PFNGLVERTEXP3UIPROC_t) (GLenum type, GLuint value);
	typedef void (APIENTRYP PFNGLVERTEXP3UIVPROC_t) (GLenum type, const GLuint *value);
	typedef void (APIENTRYP PFNGLVERTEXP4UIPROC_t) (GLenum type, GLuint value);
	typedef void (APIENTRYP PFNGLVERTEXP4UIVPROC_t) (GLenum type, const GLuint *value);
	typedef void (APIENTRYP PFNGLTEXCOORDP1UIPROC_t) (GLenum type, GLuint coords);
	typedef void (APIENTRYP PFNGLTEXCOORDP1UIVPROC_t) (GLenum type, const GLuint *coords);
	typedef void (APIENTRYP PFNGLTEXCOORDP2UIPROC_t) (GLenum type, GLuint coords);
	typedef void (APIENTRYP PFNGLTEXCOORDP2UIVPROC_t) (GLenum type, const GLuint *coords);
	typedef void (APIENTRYP PFNGLTEXCOORDP3UIPROC_t) (GLenum type, GLuint coords);
	typedef void (APIENTRYP PFNGLTEXCOORDP3UIVPROC_t) (GLenum type, const GLuint *coords);
	typedef void (APIENTRYP PFNGLTEXCOORDP4UIPROC_t) (GLenum type, GLuint coords);
	typedef void (APIENTRYP PFNGLTEXCOORDP4UIVPROC_t) (GLenum type, const GLuint *coords);
	typedef void (APIENTRYP PFNGLMULTITEXCOORDP1UIPROC_t) (GLenum texture, GLenum type, GLuint coords);
	typedef void (APIENTRYP PFNGLMULTITEXCOORDP1UIVPROC_t) (GLenum texture, GLenum type, const GLuint *coords);
	typedef void (APIENTRYP PFNGLMULTITEXCOORDP2UIPROC_t) (GLenum texture, GLenum type, GLuint coords);
	typedef void (APIENTRYP PFNGLMULTITEXCOORDP2UIVPROC_t) (GLenum texture, GLenum type, const GLuint *coords);
	typedef void (APIENTRYP PFNGLMULTITEXCOORDP3UIPROC_t) (GLenum texture, GLenum type, GLuint coords);
	typedef void (APIENTRYP PFNGLMULTITEXCOORDP3UIVPROC_t) (GLenum texture, GLenum type, const GLuint *coords);
	typedef void (APIENTRYP PFNGLMULTITEXCOORDP4UIPROC_t) (GLenum texture, GLenum type, GLuint coords);
	typedef void (APIENTRYP PFNGLMULTITEXCOORDP4UIVPROC_t) (GLenum texture, GLenum type, const GLuint *coords);
	typedef void (APIENTRYP PFNGLNORMALP3UIPROC_t) (GLenum type, GLuint coords);
	typedef void (APIENTRYP PFNGLNORMALP3UIVPROC_t) (GLenum type, const GLuint *coords);
	typedef void (APIENTRYP PFNGLCOLORP3UIPROC_t) (GLenum type, GLuint color);
	typedef void (APIENTRYP PFNGLCOLORP3UIVPROC_t) (GLenum type, const GLuint *color);
	typedef void (APIENTRYP PFNGLCOLORP4UIPROC_t) (GLenum type, GLuint color);
	typedef void (APIENTRYP PFNGLCOLORP4UIVPROC_t) (GLenum type, const GLuint *color);
	typedef void (APIENTRYP PFNGLSECONDARYCOLORP3UIPROC_t) (GLenum type, GLuint color);
	typedef void (APIENTRYP PFNGLSECONDARYCOLORP3UIVPROC_t) (GLenum type, const GLuint *color);
	PFNGLBINDFRAGDATALOCATIONINDEXEDPROC_t glBindFragDataLocationIndexed;
	PFNGLGETFRAGDATAINDEXPROC_t glGetFragDataIndex;
	PFNGLGENSAMPLERSPROC_t glGenSamplers;
	PFNGLDELETESAMPLERSPROC_t glDeleteSamplers;
	PFNGLISSAMPLERPROC_t glIsSampler;
	PFNGLBINDSAMPLERPROC_t glBindSampler;
	PFNGLSAMPLERPARAMETERIPROC_t glSamplerParameteri;
	PFNGLSAMPLERPARAMETERIVPROC_t glSamplerParameteriv;
	PFNGLSAMPLERPARAMETERFPROC_t glSamplerParameterf;
	PFNGLSAMPLERPARAMETERFVPROC_t glSamplerParameterfv;
	PFNGLSAMPLERPARAMETERIIVPROC_t glSamplerParameterIiv;
	PFNGLSAMPLERPARAMETERIUIVPROC_t glSamplerParameterIuiv;
	PFNGLGETSAMPLERPARAMETERIVPROC_t glGetSamplerParameteriv;
	PFNGLGETSAMPLERPARAMETERIIVPROC_t glGetSamplerParameterIiv;
	PFNGLGETSAMPLERPARAMETERFVPROC_t glGetSamplerParameterfv;
	PFNGLGETSAMPLERPARAMETERIUIVPROC_t glGetSamplerParameterIuiv;
	PFNGLQUERYCOUNTERPROC_t glQueryCounter;
	PFNGLGETQUERYOBJECTI64VPROC_t glGetQueryObjecti64v;
	PFNGLGETQUERYOBJECTUI64VPROC_t glGetQueryObjectui64v;
	PFNGLVERTEXATTRIBDIVISORPROC_t glVertexAttribDivisor;
	PFNGLVERTEXATTRIBP1UIPROC_t glVertexAttribP1ui;
	PFNGLVERTEXATTRIBP1UIVPROC_t glVertexAttribP1uiv;
	PFNGLVERTEXATTRIBP2UIPROC_t glVertexAttribP2ui;
	PFNGLVERTEXATTRIBP2UIVPROC_t glVertexAttribP2uiv;
	PFNGLVERTEXATTRIBP3UIPROC_t glVertexAttribP3ui;
	PFNGLVERTEXATTRIBP3UIVPROC_t glVertexAttribP3uiv;
	PFNGLVERTEXATTRIBP4UIPROC_t glVertexAttribP4ui;
	PFNGLVERTEXATTRIBP4UIVPROC_t glVertexAttribP4uiv;
	PFNGLVERTEXP2UIPROC_t glVertexP2ui;
	PFNGLVERTEXP2UIVPROC_t glVertexP2uiv;
	PFNGLVERTEXP3UIPROC_t glVertexP3ui;
	PFNGLVERTEXP3UIVPROC_t glVertexP3uiv;
	PFNGLVERTEXP4UIPROC_t glVertexP4ui;
	PFNGLVERTEXP4UIVPROC_t glVertexP4uiv;
	PFNGLTEXCOORDP1UIPROC_t glTexCoordP1ui;
	PFNGLTEXCOORDP1UIVPROC_t glTexCoordP1uiv;
	PFNGLTEXCOORDP2UIPROC_t glTexCoordP2ui;
	PFNGLTEXCOORDP2UIVPROC_t glTexCoordP2uiv;
	PFNGLTEXCOORDP3UIPROC_t glTexCoordP3ui;
	PFNGLTEXCOORDP3UIVPROC_t glTexCoordP3uiv;
	PFNGLTEXCOORDP4UIPROC_t glTexCoordP4ui;
	PFNGLTEXCOORDP4UIVPROC_t glTexCoordP4uiv;
	PFNGLMULTITEXCOORDP1UIPROC_t glMultiTexCoordP1ui;
	PFNGLMULTITEXCOORDP1UIVPROC_t glMultiTexCoordP1uiv;
	PFNGLMULTITEXCOORDP2UIPROC_t glMultiTexCoordP2ui;
	PFNGLMULTITEXCOORDP2UIVPROC_t glMultiTexCoordP2uiv;
	PFNGLMULTITEXCOORDP3UIPROC_t glMultiTexCoordP3ui;
	PFNGLMULTITEXCOORDP3UIVPROC_t glMultiTexCoordP3uiv;
	PFNGLMULTITEXCOORDP4UIPROC_t glMultiTexCoordP4ui;
	PFNGLMULTITEXCOORDP4UIVPROC_t glMultiTexCoordP4uiv;
	PFNGLNORMALP3UIPROC_t glNormalP3ui;
	PFNGLNORMALP3UIVPROC_t glNormalP3uiv;
	PFNGLCOLORP3UIPROC_t glColorP3ui;
	PFNGLCOLORP3UIVPROC_t glColorP3uiv;
	PFNGLCOLORP4UIPROC_t glColorP4ui;
	PFNGLCOLORP4UIVPROC_t glColorP4uiv;
	PFNGLSECONDARYCOLORP3UIPROC_t glSecondaryColorP3ui;
	PFNGLSECONDARYCOLORP3UIVPROC_t glSecondaryColorP3uiv;

	//OpenGL 4.0 Extensions
	typedef void (APIENTRYP PFNGLMINSAMPLESHADINGPROC_t) (GLfloat value);
	typedef void (APIENTRYP PFNGLBLENDEQUATIONIPROC_t) (GLuint buf, GLenum mode);
	typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEIPROC_t) (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
	typedef void (APIENTRYP PFNGLBLENDFUNCIPROC_t) (GLuint buf, GLenum src, GLenum dst);
	typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEIPROC_t) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
	typedef void (APIENTRYP PFNGLDRAWARRAYSINDIRECTPROC_t) (GLenum mode, const void *indirect);
	typedef void (APIENTRYP PFNGLDRAWELEMENTSINDIRECTPROC_t) (GLenum mode, GLenum type, const void *indirect);
	typedef void (APIENTRYP PFNGLUNIFORM1DPROC_t) (GLint location, GLdouble x);
	typedef void (APIENTRYP PFNGLUNIFORM2DPROC_t) (GLint location, GLdouble x, GLdouble y);
	typedef void (APIENTRYP PFNGLUNIFORM3DPROC_t) (GLint location, GLdouble x, GLdouble y, GLdouble z);
	typedef void (APIENTRYP PFNGLUNIFORM4DPROC_t) (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	typedef void (APIENTRYP PFNGLUNIFORM1DVPROC_t) (GLint location, GLsizei count, const GLdouble *value);
	typedef void (APIENTRYP PFNGLUNIFORM2DVPROC_t) (GLint location, GLsizei count, const GLdouble *value);
	typedef void (APIENTRYP PFNGLUNIFORM3DVPROC_t) (GLint location, GLsizei count, const GLdouble *value);
	typedef void (APIENTRYP PFNGLUNIFORM4DVPROC_t) (GLint location, GLsizei count, const GLdouble *value);
	typedef void (APIENTRYP PFNGLUNIFORMMATRIX2DVPROC_t) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	typedef void (APIENTRYP PFNGLUNIFORMMATRIX3DVPROC_t) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	typedef void (APIENTRYP PFNGLUNIFORMMATRIX4DVPROC_t) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3DVPROC_t) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4DVPROC_t) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2DVPROC_t) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4DVPROC_t) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2DVPROC_t) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3DVPROC_t) (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	typedef void (APIENTRYP PFNGLGETUNIFORMDVPROC_t) (GLuint program, GLint location, GLdouble *params);
	typedef GLint(APIENTRYP PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC_t) (GLuint program, GLenum shadertype, const GLchar *name);
	typedef GLuint(APIENTRYP PFNGLGETSUBROUTINEINDEXPROC_t) (GLuint program, GLenum shadertype, const GLchar *name);
	typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC_t) (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
	typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC_t) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
	typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINENAMEPROC_t) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
	typedef void (APIENTRYP PFNGLUNIFORMSUBROUTINESUIVPROC_t) (GLenum shadertype, GLsizei count, const GLuint *indices);
	typedef void (APIENTRYP PFNGLGETUNIFORMSUBROUTINEUIVPROC_t) (GLenum shadertype, GLint location, GLuint *params);
	typedef void (APIENTRYP PFNGLGETPROGRAMSTAGEIVPROC_t) (GLuint program, GLenum shadertype, GLenum pname, GLint *values);
	typedef void (APIENTRYP PFNGLPATCHPARAMETERIPROC_t) (GLenum pname, GLint value);
	typedef void (APIENTRYP PFNGLPATCHPARAMETERFVPROC_t) (GLenum pname, const GLfloat *values);
	typedef void (APIENTRYP PFNGLBINDTRANSFORMFEEDBACKPROC_t) (GLenum target, GLuint id);
	typedef void (APIENTRYP PFNGLDELETETRANSFORMFEEDBACKSPROC_t) (GLsizei n, const GLuint *ids);
	typedef void (APIENTRYP PFNGLGENTRANSFORMFEEDBACKSPROC_t) (GLsizei n, GLuint *ids);
	typedef GLboolean(APIENTRYP PFNGLISTRANSFORMFEEDBACKPROC_t) (GLuint id);
	typedef void (APIENTRYP PFNGLPAUSETRANSFORMFEEDBACKPROC_t) (void);
	typedef void (APIENTRYP PFNGLRESUMETRANSFORMFEEDBACKPROC_t) (void);
	typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKPROC_t) (GLenum mode, GLuint id);
	typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC_t) (GLenum mode, GLuint id, GLuint stream);
	typedef void (APIENTRYP PFNGLBEGINQUERYINDEXEDPROC_t) (GLenum target, GLuint index, GLuint id);
	typedef void (APIENTRYP PFNGLENDQUERYINDEXEDPROC_t) (GLenum target, GLuint index);
	typedef void (APIENTRYP PFNGLGETQUERYINDEXEDIVPROC_t) (GLenum target, GLuint index, GLenum pname, GLint *params);
	PFNGLMINSAMPLESHADINGPROC_t glMinSampleShading;
	PFNGLBLENDEQUATIONIPROC_t glBlendEquationi;
	PFNGLBLENDEQUATIONSEPARATEIPROC_t glBlendEquationSeparatei;
	PFNGLBLENDFUNCIPROC_t glBlendFunci;
	PFNGLBLENDFUNCSEPARATEIPROC_t glBlendFuncSeparatei;
	PFNGLDRAWARRAYSINDIRECTPROC_t glDrawArraysIndirect;
	PFNGLDRAWELEMENTSINDIRECTPROC_t glDrawElementsIndirect;
	PFNGLUNIFORM1DPROC_t glUniform1d;
	PFNGLUNIFORM2DPROC_t glUniform2d;
	PFNGLUNIFORM3DPROC_t glUniform3d;
	PFNGLUNIFORM4DPROC_t glUniform4d;
	PFNGLUNIFORM1DVPROC_t glUniform1dv;
	PFNGLUNIFORM2DVPROC_t glUniform2dv;
	PFNGLUNIFORM3DVPROC_t glUniform3dv;
	PFNGLUNIFORM4DVPROC_t glUniform4dv;
	PFNGLUNIFORMMATRIX2DVPROC_t glUniformMatrix2dv;
	PFNGLUNIFORMMATRIX3DVPROC_t glUniformMatrix3dv;
	PFNGLUNIFORMMATRIX4DVPROC_t glUniformMatrix4dv;
	PFNGLUNIFORMMATRIX2X3DVPROC_t glUniformMatrix2x3dv;
	PFNGLUNIFORMMATRIX2X4DVPROC_t glUniformMatrix2x4dv;
	PFNGLUNIFORMMATRIX3X2DVPROC_t glUniformMatrix3x2dv;
	PFNGLUNIFORMMATRIX3X4DVPROC_t glUniformMatrix3x4dv;
	PFNGLUNIFORMMATRIX4X2DVPROC_t glUniformMatrix4x2dv;
	PFNGLUNIFORMMATRIX4X3DVPROC_t glUniformMatrix4x3dv;
	PFNGLGETUNIFORMDVPROC_t glGetUniformdv;
	PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC_t glGetSubroutineUniformLocation;
	PFNGLGETSUBROUTINEINDEXPROC_t glGetSubroutineIndex;
	PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC_t glGetActiveSubroutineUniformiv;
	PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC_t glGetActiveSubroutineUniformName;
	PFNGLGETACTIVESUBROUTINENAMEPROC_t glGetActiveSubroutineName;
	PFNGLUNIFORMSUBROUTINESUIVPROC_t glUniformSubroutinesuiv;
	PFNGLGETUNIFORMSUBROUTINEUIVPROC_t glGetUniformSubroutineuiv;
	PFNGLGETPROGRAMSTAGEIVPROC_t glGetProgramStageiv;
	PFNGLPATCHPARAMETERIPROC_t glPatchParameteri;
	PFNGLPATCHPARAMETERFVPROC_t glPatchParameterfv;
	PFNGLBINDTRANSFORMFEEDBACKPROC_t glBindTransformFeedback;
	PFNGLDELETETRANSFORMFEEDBACKSPROC_t glDeleteTransformFeedbacks;
	PFNGLGENTRANSFORMFEEDBACKSPROC_t glGenTransformFeedbacks;
	PFNGLISTRANSFORMFEEDBACKPROC_t glIsTransformFeedback;
	PFNGLPAUSETRANSFORMFEEDBACKPROC_t glPauseTransformFeedback;
	PFNGLRESUMETRANSFORMFEEDBACKPROC_t glResumeTransformFeedback;
	PFNGLDRAWTRANSFORMFEEDBACKPROC_t glDrawTransformFeedback;
	PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC_t glDrawTransformFeedbackStream;
	PFNGLBEGINQUERYINDEXEDPROC_t glBeginQueryIndexed;
	PFNGLENDQUERYINDEXEDPROC_t glEndQueryIndexed;
	PFNGLGETQUERYINDEXEDIVPROC_t glGetQueryIndexediv;

	//OpenGL 4.1 Extensions
	typedef void (APIENTRYP PFNGLRELEASESHADERCOMPILERPROC_t) (void);
	typedef void (APIENTRYP PFNGLSHADERBINARYPROC_t) (GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length);
	typedef void (APIENTRYP PFNGLGETSHADERPRECISIONFORMATPROC_t) (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
	typedef void (APIENTRYP PFNGLDEPTHRANGEFPROC_t) (GLfloat n, GLfloat f);
	typedef void (APIENTRYP PFNGLCLEARDEPTHFPROC_t) (GLfloat d);
	typedef void (APIENTRYP PFNGLGETPROGRAMBINARYPROC_t) (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
	typedef void (APIENTRYP PFNGLPROGRAMBINARYPROC_t) (GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
	typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIPROC_t) (GLuint program, GLenum pname, GLint value);
	typedef void (APIENTRYP PFNGLUSEPROGRAMSTAGESPROC_t) (GLuint pipeline, GLbitfield stages, GLuint program);
	typedef void (APIENTRYP PFNGLACTIVESHADERPROGRAMPROC_t) (GLuint pipeline, GLuint program);
	typedef GLuint (APIENTRYP PFNGLCREATESHADERPROGRAMVPROC_t) (GLenum type, GLsizei count, const GLchar *const*strings);
	typedef void (APIENTRYP PFNGLBINDPROGRAMPIPELINEPROC_t) (GLuint pipeline);
	typedef void (APIENTRYP PFNGLDELETEPROGRAMPIPELINESPROC_t) (GLsizei n, const GLuint *pipelines);
	typedef void (APIENTRYP PFNGLGENPROGRAMPIPELINESPROC_t) (GLsizei n, GLuint *pipelines);
	typedef GLboolean (APIENTRYP PFNGLISPROGRAMPIPELINEPROC_t) (GLuint pipeline);
	typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEIVPROC_t) (GLuint pipeline, GLenum pname, GLint *params);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IPROC_t) (GLuint program, GLint location, GLint v0);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IVPROC_t) (GLuint program, GLint location, GLsizei count, const GLint *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FPROC_t) (GLuint program, GLint location, GLfloat v0);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FVPROC_t) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DPROC_t) (GLuint program, GLint location, GLdouble v0);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DVPROC_t) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIPROC_t) (GLuint program, GLint location, GLuint v0);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIVPROC_t) (GLuint program, GLint location, GLsizei count, const GLuint *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IPROC_t) (GLuint program, GLint location, GLint v0, GLint v1);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IVPROC_t) (GLuint program, GLint location, GLsizei count, const GLint *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FPROC_t) (GLuint program, GLint location, GLfloat v0, GLfloat v1);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FVPROC_t) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DPROC_t) (GLuint program, GLint location, GLdouble v0, GLdouble v1);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DVPROC_t) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIPROC_t) (GLuint program, GLint location, GLuint v0, GLuint v1);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIVPROC_t) (GLuint program, GLint location, GLsizei count, const GLuint *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IPROC_t) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IVPROC_t) (GLuint program, GLint location, GLsizei count, const GLint *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FPROC_t) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FVPROC_t) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DPROC_t) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DVPROC_t) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIPROC_t) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIVPROC_t) (GLuint program, GLint location, GLsizei count, const GLuint *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IPROC_t) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IVPROC_t) (GLuint program, GLint location, GLsizei count, const GLint *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FPROC_t) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FVPROC_t) (GLuint program, GLint location, GLsizei count, const GLfloat *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DPROC_t) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DVPROC_t) (GLuint program, GLint location, GLsizei count, const GLdouble *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIPROC_t) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIVPROC_t) (GLuint program, GLint location, GLsizei count, const GLuint *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVPROC_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVPROC_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVPROC_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVPROC_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVPROC_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVPROC_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC_t) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPIPELINEPROC_t) (GLuint pipeline);
	typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEINFOLOGPROC_t) (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DPROC_t) (GLuint index, GLdouble x);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DPROC_t) (GLuint index, GLdouble x, GLdouble y);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DPROC_t) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DPROC_t) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DVPROC_t) (GLuint index, const GLdouble *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DVPROC_t) (GLuint index, const GLdouble *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DVPROC_t) (GLuint index, const GLdouble *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DVPROC_t) (GLuint index, const GLdouble *v);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBLPOINTERPROC_t) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
	typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLDVPROC_t) (GLuint index, GLenum pname, GLdouble *params);
	typedef void (APIENTRYP PFNGLVIEWPORTARRAYVPROC_t) (GLuint first, GLsizei count, const GLfloat *v);
	typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFPROC_t) (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
	typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFVPROC_t) (GLuint index, const GLfloat *v);
	typedef void (APIENTRYP PFNGLSCISSORARRAYVPROC_t) (GLuint first, GLsizei count, const GLint *v);
	typedef void (APIENTRYP PFNGLSCISSORINDEXEDPROC_t) (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
	typedef void (APIENTRYP PFNGLSCISSORINDEXEDVPROC_t) (GLuint index, const GLint *v);
	typedef void (APIENTRYP PFNGLDEPTHRANGEARRAYVPROC_t) (GLuint first, GLsizei count, const GLdouble *v);
	typedef void (APIENTRYP PFNGLDEPTHRANGEINDEXEDPROC_t) (GLuint index, GLdouble n, GLdouble f);
	typedef void (APIENTRYP PFNGLGETFLOATI_VPROC_t) (GLenum target, GLuint index, GLfloat *data);
	typedef void (APIENTRYP PFNGLGETDOUBLEI_VPROC_t) (GLenum target, GLuint index, GLdouble *data);
	PFNGLRELEASESHADERCOMPILERPROC_t glReleaseShaderCompiler;
	PFNGLSHADERBINARYPROC_t glShaderBinary;
	PFNGLGETSHADERPRECISIONFORMATPROC_t glGetShaderPrecisionFormat;
	PFNGLDEPTHRANGEFPROC_t glDepthRangef;
	PFNGLCLEARDEPTHFPROC_t glClearDepthf;
	PFNGLGETPROGRAMBINARYPROC_t glGetProgramBinary;
	PFNGLPROGRAMBINARYPROC_t glProgramBinary;
	PFNGLPROGRAMPARAMETERIPROC_t glProgramParameteri;
	PFNGLUSEPROGRAMSTAGESPROC_t glUseProgramStages;
	PFNGLACTIVESHADERPROGRAMPROC_t glActiveShaderProgram;
	PFNGLCREATESHADERPROGRAMVPROC_t glCreateShaderProgramv;
	PFNGLBINDPROGRAMPIPELINEPROC_t glBindProgramPipeline;
	PFNGLDELETEPROGRAMPIPELINESPROC_t glDeleteProgramPipelines;
	PFNGLGENPROGRAMPIPELINESPROC_t glGenProgramPipelines;
	PFNGLISPROGRAMPIPELINEPROC_t glIsProgramPipeline;
	PFNGLGETPROGRAMPIPELINEIVPROC_t glGetProgramPipelineiv;
	PFNGLPROGRAMUNIFORM1IPROC_t glProgramUniform1i;
	PFNGLPROGRAMUNIFORM1IVPROC_t glProgramUniform1iv;
	PFNGLPROGRAMUNIFORM1FPROC_t glProgramUniform1f;
	PFNGLPROGRAMUNIFORM1FVPROC_t glProgramUniform1fv;
	PFNGLPROGRAMUNIFORM1DPROC_t glProgramUniform1d;
	PFNGLPROGRAMUNIFORM1DVPROC_t glProgramUniform1dv;
	PFNGLPROGRAMUNIFORM1UIPROC_t glProgramUniform1ui;
	PFNGLPROGRAMUNIFORM1UIVPROC_t glProgramUniform1uiv;
	PFNGLPROGRAMUNIFORM2IPROC_t glProgramUniform2i;
	PFNGLPROGRAMUNIFORM2IVPROC_t glProgramUniform2iv;
	PFNGLPROGRAMUNIFORM2FPROC_t glProgramUniform2f;
	PFNGLPROGRAMUNIFORM2FVPROC_t glProgramUniform2fv;
	PFNGLPROGRAMUNIFORM2DPROC_t glProgramUniform2d;
	PFNGLPROGRAMUNIFORM2DVPROC_t glProgramUniform2dv;
	PFNGLPROGRAMUNIFORM2UIPROC_t glProgramUniform2ui;
	PFNGLPROGRAMUNIFORM2UIVPROC_t glProgramUniform2uiv;
	PFNGLPROGRAMUNIFORM3IPROC_t glProgramUniform3i;
	PFNGLPROGRAMUNIFORM3IVPROC_t glProgramUniform3iv;
	PFNGLPROGRAMUNIFORM3FPROC_t glProgramUniform3f;
	PFNGLPROGRAMUNIFORM3FVPROC_t glProgramUniform3fv;
	PFNGLPROGRAMUNIFORM3DPROC_t glProgramUniform3d;
	PFNGLPROGRAMUNIFORM3DVPROC_t glProgramUniform3dv;
	PFNGLPROGRAMUNIFORM3UIPROC_t glProgramUniform3ui;
	PFNGLPROGRAMUNIFORM3UIVPROC_t glProgramUniform3uiv;
	PFNGLPROGRAMUNIFORM4IPROC_t glProgramUniform4i;
	PFNGLPROGRAMUNIFORM4IVPROC_t glProgramUniform4iv;
	PFNGLPROGRAMUNIFORM4FPROC_t glProgramUniform4f;
	PFNGLPROGRAMUNIFORM4FVPROC_t glProgramUniform4fv;
	PFNGLPROGRAMUNIFORM4DPROC_t glProgramUniform4d;
	PFNGLPROGRAMUNIFORM4DVPROC_t glProgramUniform4dv;
	PFNGLPROGRAMUNIFORM4UIPROC_t glProgramUniform4ui;
	PFNGLPROGRAMUNIFORM4UIVPROC_t glProgramUniform4uiv;
	PFNGLPROGRAMUNIFORMMATRIX2FVPROC_t glProgramUniformMatrix2fv;
	PFNGLPROGRAMUNIFORMMATRIX3FVPROC_t glProgramUniformMatrix3fv;
	PFNGLPROGRAMUNIFORMMATRIX4FVPROC_t glProgramUniformMatrix4fv;
	PFNGLPROGRAMUNIFORMMATRIX2DVPROC_t glProgramUniformMatrix2dv;
	PFNGLPROGRAMUNIFORMMATRIX3DVPROC_t glProgramUniformMatrix3dv;
	PFNGLPROGRAMUNIFORMMATRIX4DVPROC_t glProgramUniformMatrix4dv;
	PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC_t glProgramUniformMatrix2x3fv;
	PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC_t glProgramUniformMatrix3x2fv;
	PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC_t glProgramUniformMatrix2x4fv;
	PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC_t glProgramUniformMatrix4x2fv;
	PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC_t glProgramUniformMatrix3x4fv;
	PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC_t glProgramUniformMatrix4x3fv;
	PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC_t glProgramUniformMatrix2x3dv;
	PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC_t glProgramUniformMatrix3x2dv;
	PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC_t glProgramUniformMatrix2x4dv;
	PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC_t glProgramUniformMatrix4x2dv;
	PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC_t glProgramUniformMatrix3x4dv;
	PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC_t glProgramUniformMatrix4x3dv;
	PFNGLVALIDATEPROGRAMPIPELINEPROC_t glValidateProgramPipeline;
	PFNGLGETPROGRAMPIPELINEINFOLOGPROC_t glGetProgramPipelineInfoLog;
	PFNGLVERTEXATTRIBL1DPROC_t glVertexAttribL1d;
	PFNGLVERTEXATTRIBL2DPROC_t glVertexAttribL2d;
	PFNGLVERTEXATTRIBL3DPROC_t glVertexAttribL3d;
	PFNGLVERTEXATTRIBL4DPROC_t glVertexAttribL4d;
	PFNGLVERTEXATTRIBL1DVPROC_t glVertexAttribL1dv;
	PFNGLVERTEXATTRIBL2DVPROC_t glVertexAttribL2dv;
	PFNGLVERTEXATTRIBL3DVPROC_t glVertexAttribL3dv;
	PFNGLVERTEXATTRIBL4DVPROC_t glVertexAttribL4dv;
	PFNGLVERTEXATTRIBLPOINTERPROC_t glVertexAttribLPointer;
	PFNGLGETVERTEXATTRIBLDVPROC_t glGetVertexAttribLdv;
	PFNGLVIEWPORTARRAYVPROC_t glViewportArrayv;
	PFNGLVIEWPORTINDEXEDFPROC_t glViewportIndexedf;
	PFNGLVIEWPORTINDEXEDFVPROC_t glViewportIndexedfv;
	PFNGLSCISSORARRAYVPROC_t glScissorArrayv;
	PFNGLSCISSORINDEXEDPROC_t glScissorIndexed;
	PFNGLSCISSORINDEXEDVPROC_t glScissorIndexedv;
	PFNGLDEPTHRANGEARRAYVPROC_t glDepthRangeArrayv;
	PFNGLDEPTHRANGEINDEXEDPROC_t glDepthRangeIndexed;
	PFNGLGETFLOATI_VPROC_t glGetFloati_v;
	PFNGLGETDOUBLEI_VPROC_t glGetDoublei_v;

	//OpenGL 4.2 extensions
	typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC_t) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
	typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC_t) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
	typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC_t) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
	typedef void (APIENTRYP PFNGLGETINTERNALFORMATIVPROC_t) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);
	typedef void (APIENTRYP PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC_t) (GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
	typedef void (APIENTRYP PFNGLBINDIMAGETEXTUREPROC_t) (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
	typedef void (APIENTRYP PFNGLMEMORYBARRIERPROC_t) (GLbitfield barriers);
	typedef void (APIENTRYP PFNGLTEXSTORAGE1DPROC_t) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
	typedef void (APIENTRYP PFNGLTEXSTORAGE2DPROC_t) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
	typedef void (APIENTRYP PFNGLTEXSTORAGE3DPROC_t) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
	typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC_t) (GLenum mode, GLuint id, GLsizei instancecount);
	typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC_t) (GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
	PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC_t glDrawArraysInstancedBaseInstance;
	PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC_t glDrawElementsInstancedBaseInstance;
	PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC_t glDrawElementsInstancedBaseVertexBaseInstance;
	PFNGLGETINTERNALFORMATIVPROC_t glGetInternalformativ;
	PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC_t glGetActiveAtomicCounterBufferiv;
	PFNGLBINDIMAGETEXTUREPROC_t glBindImageTexture;
	PFNGLMEMORYBARRIERPROC_t glMemoryBarrier;
	PFNGLTEXSTORAGE1DPROC_t glTexStorage1D;
	PFNGLTEXSTORAGE2DPROC_t glTexStorage2D;
	PFNGLTEXSTORAGE3DPROC_t glTexStorage3D;
	PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC_t glDrawTransformFeedbackInstanced;
	PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC_t glDrawTransformFeedbackStreamInstanced;

	//opengl 4.3 extensions
	typedef void (APIENTRYP PFNGLBUFFERSTORAGEPROC_t) (GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
	typedef void (APIENTRYP PFNGLCLEARTEXIMAGEPROC_t) (GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
	typedef void (APIENTRYP PFNGLCLEARTEXSUBIMAGEPROC_t) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
	typedef void (APIENTRYP PFNGLBINDBUFFERSBASEPROC_t) (GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
	typedef void (APIENTRYP PFNGLBINDBUFFERSRANGEPROC_t) (GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
	typedef void (APIENTRYP PFNGLBINDTEXTURESPROC_t) (GLuint first, GLsizei count, const GLuint *textures);
	typedef void (APIENTRYP PFNGLBINDSAMPLERSPROC_t) (GLuint first, GLsizei count, const GLuint *samplers);
	typedef void (APIENTRYP PFNGLBINDIMAGETEXTURESPROC_t) (GLuint first, GLsizei count, const GLuint *textures);
	typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERSPROC_t) (GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
	PFNGLBUFFERSTORAGEPROC_t glBufferStorage;
	PFNGLCLEARTEXIMAGEPROC_t glClearTexImage;
	PFNGLCLEARTEXSUBIMAGEPROC_t glClearTexSubImage;
	PFNGLBINDBUFFERSBASEPROC_t glBindBuffersBase;
	PFNGLBINDBUFFERSRANGEPROC_t glBindBuffersRange;
	PFNGLBINDTEXTURESPROC_t glBindTextures;
	PFNGLBINDSAMPLERSPROC_t glBindSamplers;
	PFNGLBINDIMAGETEXTURESPROC_t glBindImageTextures;
	PFNGLBINDVERTEXBUFFERSPROC_t glBindVertexBuffers;

	//OpenGL 4.4 Extensions
	typedef void (APIENTRY  *GLDEBUGPROC_t)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);
	typedef void (APIENTRYP PFNGLCLEARBUFFERDATAPROC_t) (GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
	typedef void (APIENTRYP PFNGLCLEARBUFFERSUBDATAPROC_t) (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
	typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEPROC_t) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
	typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEINDIRECTPROC_t) (GLintptr indirect);
	typedef void (APIENTRYP PFNGLCOPYIMAGESUBDATAPROC_t) (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
	typedef void (APIENTRYP PFNGLFRAMEBUFFERPARAMETERIPROC_t) (GLenum target, GLenum pname, GLint param);
	typedef void (APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVPROC_t) (GLenum target, GLenum pname, GLint *params);
	typedef void (APIENTRYP PFNGLGETINTERNALFORMATI64VPROC_t) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params);
	typedef void (APIENTRYP PFNGLINVALIDATETEXSUBIMAGEPROC_t) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
	typedef void (APIENTRYP PFNGLINVALIDATETEXIMAGEPROC_t) (GLuint texture, GLint level);
	typedef void (APIENTRYP PFNGLINVALIDATEBUFFERSUBDATAPROC_t) (GLuint buffer, GLintptr offset, GLsizeiptr length);
	typedef void (APIENTRYP PFNGLINVALIDATEBUFFERDATAPROC_t) (GLuint buffer);
	typedef void (APIENTRYP PFNGLINVALIDATEFRAMEBUFFERPROC_t) (GLenum target, GLsizei numAttachments, const GLenum *attachments);
	typedef void (APIENTRYP PFNGLINVALIDATESUBFRAMEBUFFERPROC_t) (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
	typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTPROC_t) (GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
	typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTPROC_t) (GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
	typedef void (APIENTRYP PFNGLGETPROGRAMINTERFACEIVPROC_t) (GLuint program, GLenum programInterface, GLenum pname, GLint *params);
	typedef GLuint(APIENTRYP PFNGLGETPROGRAMRESOURCEINDEXPROC_t) (GLuint program, GLenum programInterface, const GLchar *name);
	typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCENAMEPROC_t) (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
	typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCEIVPROC_t) (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params);
	typedef GLint(APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONPROC_t) (GLuint program, GLenum programInterface, const GLchar *name);
	typedef GLint(APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC_t) (GLuint program, GLenum programInterface, const GLchar *name);
	typedef void (APIENTRYP PFNGLSHADERSTORAGEBLOCKBINDINGPROC_t) (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
	typedef void (APIENTRYP PFNGLTEXBUFFERRANGEPROC_t) (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
	typedef void (APIENTRYP PFNGLTEXSTORAGE2DMULTISAMPLEPROC_t) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
	typedef void (APIENTRYP PFNGLTEXSTORAGE3DMULTISAMPLEPROC_t) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
	typedef void (APIENTRYP PFNGLTEXTUREVIEWPROC_t) (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
	typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERPROC_t) (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBFORMATPROC_t) (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBIFORMATPROC_t) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBLFORMATPROC_t) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
	typedef void (APIENTRYP PFNGLVERTEXATTRIBBINDINGPROC_t) (GLuint attribindex, GLuint bindingindex);
	typedef void (APIENTRYP PFNGLVERTEXBINDINGDIVISORPROC_t) (GLuint bindingindex, GLuint divisor);
	typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLPROC_t) (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
	typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTPROC_t) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
	typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKPROC_t) (GLDEBUGPROC_t callback, const void *userParam);
	typedef GLuint(APIENTRYP PFNGLGETDEBUGMESSAGELOGPROC_t) (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
	typedef void (APIENTRYP PFNGLPUSHDEBUGGROUPPROC_t) (GLenum source, GLuint id, GLsizei length, const GLchar *message);
	typedef void (APIENTRYP PFNGLPOPDEBUGGROUPPROC_t) (void);
	typedef void (APIENTRYP PFNGLOBJECTLABELPROC_t) (GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
	typedef void (APIENTRYP PFNGLGETOBJECTLABELPROC_t) (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
	typedef void (APIENTRYP PFNGLOBJECTPTRLABELPROC_t) (const void *ptr, GLsizei length, const GLchar *label);
	typedef void (APIENTRYP PFNGLGETOBJECTPTRLABELPROC_t) (const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
	PFNGLCLEARBUFFERDATAPROC_t glClearBufferData;
	PFNGLCLEARBUFFERSUBDATAPROC_t glClearBufferSubData;
	PFNGLDISPATCHCOMPUTEPROC_t glDispatchCompute;
	PFNGLDISPATCHCOMPUTEINDIRECTPROC_t glDispatchComputeIndirect;
	PFNGLCOPYIMAGESUBDATAPROC_t  glCopyImageSubData;
	PFNGLFRAMEBUFFERPARAMETERIPROC_t glFramebufferParameteri;
	PFNGLGETFRAMEBUFFERPARAMETERIVPROC_t glGetFramebufferParameteriv;
	PFNGLGETINTERNALFORMATI64VPROC_t glGetInternalformati64v;
	PFNGLINVALIDATETEXSUBIMAGEPROC_t glInvalidateTexSubImage;
	PFNGLINVALIDATETEXIMAGEPROC_t glInvalidateTexImage;
	PFNGLINVALIDATEBUFFERSUBDATAPROC_t glInvalidateBufferSubData;
	PFNGLINVALIDATEBUFFERDATAPROC_t glInvalidateBufferData;
	PFNGLINVALIDATEFRAMEBUFFERPROC_t glInvalidateFramebuffer;
	PFNGLINVALIDATESUBFRAMEBUFFERPROC_t glInvalidateSubFramebuffer;
	PFNGLMULTIDRAWARRAYSINDIRECTPROC_t glMultiDrawArraysIndirect;
	PFNGLMULTIDRAWELEMENTSINDIRECTPROC_t glMultiDrawElementsIndirect;
	PFNGLGETPROGRAMINTERFACEIVPROC_t glGetProgramInterfaceiv;
	PFNGLGETPROGRAMRESOURCEINDEXPROC_t glGetProgramResourceIndex;
	PFNGLGETPROGRAMRESOURCENAMEPROC_t glGetProgramResourceName;
	PFNGLGETPROGRAMRESOURCEIVPROC_t glGetProgramResourceiv;
	PFNGLGETPROGRAMRESOURCELOCATIONPROC_t glGetProgramResourceLocation;
	PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC_t glGetProgramResourceLocationIndex;
	PFNGLSHADERSTORAGEBLOCKBINDINGPROC_t glShaderStorageBlockBinding;
	PFNGLTEXBUFFERRANGEPROC_t glTexBufferRange;
	PFNGLTEXSTORAGE2DMULTISAMPLEPROC_t glTexStorage2DMultisample;
	PFNGLTEXSTORAGE3DMULTISAMPLEPROC_t glTexStorage3DMultisample;
	PFNGLTEXTUREVIEWPROC_t glTextureView;
	PFNGLBINDVERTEXBUFFERPROC_t glBindVertexBuffer;
	PFNGLVERTEXATTRIBFORMATPROC_t glVertexAttribFormat;
	PFNGLVERTEXATTRIBIFORMATPROC_t glVertexAttribIFormat;
	PFNGLVERTEXATTRIBLFORMATPROC_t glVertexAttribLFormat;
	PFNGLVERTEXATTRIBBINDINGPROC_t glVertexAttribBinding;
	PFNGLVERTEXBINDINGDIVISORPROC_t glVertexBindingDivisor;
	PFNGLDEBUGMESSAGECONTROLPROC_t glDebugMessageControl;
	PFNGLDEBUGMESSAGEINSERTPROC_t glDebugMessageInsert;
	PFNGLDEBUGMESSAGECALLBACKPROC_t glDebugMessageCallback;
	PFNGLGETDEBUGMESSAGELOGPROC_t glGetDebugMessageLog;
	PFNGLPUSHDEBUGGROUPPROC_t glPushDebugGroup;
	PFNGLPOPDEBUGGROUPPROC_t glPopDebugGroup;
	PFNGLOBJECTLABELPROC_t glObjectLabel;
	PFNGLGETOBJECTLABELPROC_t glGetObjectLabel;
	PFNGLOBJECTPTRLABELPROC_t glObjectPtrLabel;
	PFNGLGETOBJECTPTRLABELPROC_t glGetObjectPtrLabel;

	private:

	GLuint glVersion_Major, glVersion_Minor;

	inline GLvoid Load1_2Extensions()
	{
		glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC_t)GetProcAddress((const GLubyte*)"glDrawRangeElements");
		glTexImage3D = (PFNGLTEXIMAGE3DPROC_t)GetProcAddress((const GLubyte*)"glTexImage3D");
		glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC_t)GetProcAddress((const GLubyte*)"glTexSubImage3D");
		glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC_t)GetProcAddress((const GLubyte*)"glCopyTexSubImage3D");
	}

	inline GLvoid Load1_3Extensions()
	{
		glActiveTexture = (PFNGLACTIVETEXTUREPROC_t)GetProcAddress((const GLubyte*)"glActiveTexture");
		glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC_t)GetProcAddress((const GLubyte*)"glSampleCoverage");
		glCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC_t)GetProcAddress((const GLubyte*)"glCompressedTexImage3D");
		glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC_t)GetProcAddress((const GLubyte*)"glCompressedTexImage2D");
		glCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1DPROC_t)GetProcAddress((const GLubyte*)"glCompressedTexImage1D");
		glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC_t)GetProcAddress((const GLubyte*)"glCompressedTexSubImage3D");
		glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC_t)GetProcAddress((const GLubyte*)"glCompressedTexSubImage2D");
		glCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC_t)GetProcAddress((const GLubyte*)"glCompressedTexSubImage1D");
		
		glGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGEPROC_t)GetProcAddress((const GLubyte*)"glGetCompressedTexImage");
		glClientActiveTexture = (PFNGLCLIENTACTIVETEXTUREPROC_t)GetProcAddress((const GLubyte*)"glClientActiveTexture");
		glMultiTexCoord1d = (PFNGLMULTITEXCOORD1DPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord1d");
		glMultiTexCoord1dv = (PFNGLMULTITEXCOORD1DVPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord1dv");
		glMultiTexCoord1f = (PFNGLMULTITEXCOORD1FPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord1f");
		glMultiTexCoord1fv = (PFNGLMULTITEXCOORD1FVPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord1fv");
		glMultiTexCoord1i = (PFNGLMULTITEXCOORD1IPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord1i");
		glMultiTexCoord1iv = (PFNGLMULTITEXCOORD1IVPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord1iv");
		glMultiTexCoord1s = (PFNGLMULTITEXCOORD1SPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord1s");
		glMultiTexCoord1sv = (PFNGLMULTITEXCOORD1SVPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord1sv");
		glMultiTexCoord2d = (PFNGLMULTITEXCOORD2DPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord2d");
		glMultiTexCoord2dv = (PFNGLMULTITEXCOORD2DVPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord2dv");

		glMultiTexCoord2f = (PFNGLMULTITEXCOORD2FPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord2f");
		glMultiTexCoord2fv = (PFNGLMULTITEXCOORD2FVPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord2fv");
		glMultiTexCoord2i = (PFNGLMULTITEXCOORD2IPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord2i");
		glMultiTexCoord2iv = (PFNGLMULTITEXCOORD2IVPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord2iv");
		glMultiTexCoord2s = (PFNGLMULTITEXCOORD2SPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord2s");
		glMultiTexCoord2sv = (PFNGLMULTITEXCOORD2SVPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord2sv");
		glMultiTexCoord3d = (PFNGLMULTITEXCOORD3DPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord3d");
		glMultiTexCoord3dv = (PFNGLMULTITEXCOORD3DVPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord3dv");
		glMultiTexCoord3f = (PFNGLMULTITEXCOORD3FPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord3f");
		glMultiTexCoord3fv = (PFNGLMULTITEXCOORD3FVPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord3fv");
		glMultiTexCoord3i = (PFNGLMULTITEXCOORD3IPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord3i");
		glMultiTexCoord3iv = (PFNGLMULTITEXCOORD3IVPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord3iv");
		glMultiTexCoord3s = (PFNGLMULTITEXCOORD3SPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord3s");
		glMultiTexCoord3sv = (PFNGLMULTITEXCOORD3SVPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord3sv");
		glMultiTexCoord4d = (PFNGLMULTITEXCOORD4DPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord4d");
		glMultiTexCoord4dv = (PFNGLMULTITEXCOORD4DVPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord4dv");
		glMultiTexCoord4f = (PFNGLMULTITEXCOORD4FPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord4f");
		glMultiTexCoord4fv = (PFNGLMULTITEXCOORD4FVPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord4fv");
		glMultiTexCoord4i = (PFNGLMULTITEXCOORD4IPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord4i");
		glMultiTexCoord4iv = (PFNGLMULTITEXCOORD4IVPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord4iv");
		glMultiTexCoord4s = (PFNGLMULTITEXCOORD4SPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord4s");
		glMultiTexCoord4sv = (PFNGLMULTITEXCOORD4SVPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoord4sv");
		glLoadTransposeMatrixf = (PFNGLLOADTRANSPOSEMATRIXFPROC_t)GetProcAddress((const GLubyte*)"glLoadTransposeMatrixf");
		glLoadTransposeMatrixd = (PFNGLLOADTRANSPOSEMATRIXDPROC_t)GetProcAddress((const GLubyte*)"glLoadTransposeMatrixd");
		glMultTransposeMatrixf = (PFNGLMULTTRANSPOSEMATRIXFPROC_t)GetProcAddress((const GLubyte*)"glMultTransposeMatrixf");
		glMultTransposeMatrixd = (PFNGLMULTTRANSPOSEMATRIXDPROC_t)GetProcAddress((const GLubyte*)"glMultTransposeMatrixd");
	}

	inline GLvoid Load1_4Extensions()
	{
		glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC_t)GetProcAddress((const GLubyte*)"glBlendFuncSeparate");
		glMultiDrawArrays = (PFNGLMULTIDRAWARRAYSPROC_t)GetProcAddress((const GLubyte*)"glMultiDrawArrays");
		glMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC_t)GetProcAddress((const GLubyte*)"glMultiDrawElements");
		glPointParameterf = (PFNGLPOINTPARAMETERFPROC_t)GetProcAddress((const GLubyte*)"glPointParameterf");
		glPointParameterfv = (PFNGLPOINTPARAMETERFVPROC_t)GetProcAddress((const GLubyte*)"glPointParameterfv");
		glPointParameteri = (PFNGLPOINTPARAMETERIPROC_t)GetProcAddress((const GLubyte*)"glPointParameteri");
		glPointParameteriv = (PFNGLPOINTPARAMETERIVPROC_t)GetProcAddress((const GLubyte*)"glPointParameteriv");
		glFogCoordf = (PFNGLFOGCOORDFPROC_t)GetProcAddress((const GLubyte*)"glFogCoordf");
		glFogCoordfv = (PFNGLFOGCOORDFVPROC_t)GetProcAddress((const GLubyte*)"glFogCoordfv");
		glFogCoordd = (PFNGLFOGCOORDDPROC_t)GetProcAddress((const GLubyte*)"glFogCoordd");
		glFogCoorddv = (PFNGLFOGCOORDDVPROC_t)GetProcAddress((const GLubyte*)"glFogCoorddv");
		glFogCoordPointer = (PFNGLFOGCOORDPOINTERPROC_t)GetProcAddress((const GLubyte*)"glFogCoordPointer");
		glSecondaryColor3b = (PFNGLSECONDARYCOLOR3BPROC_t)GetProcAddress((const GLubyte*)"glSecondaryColor3b");
		glSecondaryColor3bv = (PFNGLSECONDARYCOLOR3BVPROC_t)GetProcAddress((const GLubyte*)"glSecondaryColor3bv");
		glSecondaryColor3d = (PFNGLSECONDARYCOLOR3DPROC_t)GetProcAddress((const GLubyte*)"glSecondaryColor3d");
		glSecondaryColor3dv = (PFNGLSECONDARYCOLOR3DVPROC_t)GetProcAddress((const GLubyte*)"glSecondaryColor3dv");
		glSecondaryColor3f = (PFNGLSECONDARYCOLOR3FPROC_t)GetProcAddress((const GLubyte*)"glSecondaryColor3f");
		glSecondaryColor3fv = (PFNGLSECONDARYCOLOR3FVPROC_t)GetProcAddress((const GLubyte*)"glSecondaryColor3fv");
		glSecondaryColor3i = (PFNGLSECONDARYCOLOR3IPROC_t)GetProcAddress((const GLubyte*)"glSecondaryColor3i");
		glSecondaryColor3iv = (PFNGLSECONDARYCOLOR3IVPROC_t)GetProcAddress((const GLubyte*)"glSecondaryColor3iv");
		glSecondaryColor3s = (PFNGLSECONDARYCOLOR3SPROC_t)GetProcAddress((const GLubyte*)"glSecondaryColor3s");
		glSecondaryColor3sv = (PFNGLSECONDARYCOLOR3SVPROC_t)GetProcAddress((const GLubyte*)"glSecondaryColor3sv");
		glSecondaryColor3ub = (PFNGLSECONDARYCOLOR3UBPROC_t)GetProcAddress((const GLubyte*)"glSecondaryColor3ub");
		glSecondaryColor3ubv = (PFNGLSECONDARYCOLOR3UBVPROC_t)GetProcAddress((const GLubyte*)"glSecondaryColor3ubv");
		glSecondaryColor3ui = (PFNGLSECONDARYCOLOR3UIPROC_t)GetProcAddress((const GLubyte*)"glSecondaryColor3ui");
		glSecondaryColor3uiv = (PFNGLSECONDARYCOLOR3UIVPROC_t)GetProcAddress((const GLubyte*)"glSecondaryColor3uiv");
		glSecondaryColor3us = (PFNGLSECONDARYCOLOR3USPROC_t)GetProcAddress((const GLubyte*)"glSecondaryColor3us");
		glSecondaryColor3usv = (PFNGLSECONDARYCOLOR3USVPROC_t)GetProcAddress((const GLubyte*)"glSecondaryColor3usv");
		glSecondaryColorPointer = (PFNGLSECONDARYCOLORPOINTERPROC_t)GetProcAddress((const GLubyte*)"glSecondaryColorPointer");
		glWindowPos2d = (PFNGLWINDOWPOS2DPROC_t)GetProcAddress((const GLubyte*)"glWindowPos2d");
		glWindowPos2dv = (PFNGLWINDOWPOS2DVPROC_t)GetProcAddress((const GLubyte*)"glWindowPos2dv");
		glWindowPos2f = (PFNGLWINDOWPOS2FPROC_t)GetProcAddress((const GLubyte*)"glWindowPos2f");
		glWindowPos2fv = (PFNGLWINDOWPOS2FVPROC_t)GetProcAddress((const GLubyte*)"glWindowPos2fv");
		glWindowPos2i = (PFNGLWINDOWPOS2IPROC_t)GetProcAddress((const GLubyte*)"glWindowPos2i");
		glWindowPos2iv = (PFNGLWINDOWPOS2IVPROC_t)GetProcAddress((const GLubyte*)"glWindowPos2iv");
		glWindowPos2s = (PFNGLWINDOWPOS2SPROC_t)GetProcAddress((const GLubyte*)"glWindowPos2s");
		glWindowPos2sv = (PFNGLWINDOWPOS2SVPROC_t)GetProcAddress((const GLubyte*)"glWindowPos2sv");
		glWindowPos3d = (PFNGLWINDOWPOS3DPROC_t)GetProcAddress((const GLubyte*)"glWindowPos3d");
		glWindowPos3dv = (PFNGLWINDOWPOS3DVPROC_t)GetProcAddress((const GLubyte*)"glWindowPos3dv");
		glWindowPos3f = (PFNGLWINDOWPOS3FPROC_t)GetProcAddress((const GLubyte*)"glWindowPos3f");
		glWindowPos3fv = (PFNGLWINDOWPOS3FVPROC_t)GetProcAddress((const GLubyte*)"glWindowPos3fv");
		glWindowPos3i = (PFNGLWINDOWPOS3IPROC_t)GetProcAddress((const GLubyte*)"glWindowPos3i");
		glWindowPos3iv = (PFNGLWINDOWPOS3IVPROC_t)GetProcAddress((const GLubyte*)"glWindowPos3iv");
		glWindowPos3s = (PFNGLWINDOWPOS3SPROC_t)GetProcAddress((const GLubyte*)"glWindowPos3s");
		glWindowPos3sv = (PFNGLWINDOWPOS3SVPROC_t)GetProcAddress((const GLubyte*)"glWindowPos3sv");
		glBlendColor = (PFNGLBLENDCOLORPROC_t)GetProcAddress((const GLubyte*)"glBlendColor");
		glBlendEquation = (PFNGLBLENDEQUATIONPROC_t)GetProcAddress((const GLubyte*)"glBlendEquation");
	}

	inline GLvoid Load1_5Extensions()
	{
		glGenQueries = (PFNGLGENQUERIESPROC_t)GetProcAddress((const GLubyte*)"glGenQueries");
		glDeleteQueries = (PFNGLDELETEQUERIESPROC_t)GetProcAddress((const GLubyte*)"glDeleteQueries");
		glIsQuery = (PFNGLISQUERYPROC_t)GetProcAddress((const GLubyte*)"glIsQuery");
		glBeginQuery = (PFNGLBEGINQUERYPROC_t)GetProcAddress((const GLubyte*)"glBeginQuery");
		glEndQuery = (PFNGLENDQUERYPROC_t)GetProcAddress((const GLubyte*)"glEndQuery");
		glGetQueryiv = (PFNGLGETQUERYIVPROC_t)GetProcAddress((const GLubyte*)"glGetQueryiv");
		glGetQueryObjectiv = (PFNGLGETQUERYOBJECTIVPROC_t)GetProcAddress((const GLubyte*)"glGetQueryObjectiv");
		glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC_t)GetProcAddress((const GLubyte*)"glGetQueryObjectuiv");
		glBindBuffer = (PFNGLBINDBUFFERPROC_t)GetProcAddress((const GLubyte*)"glBindBuffer");
		glDeleteBuffers = (PFNGLDELETEBUFFERSPROC_t)GetProcAddress((const GLubyte*)"glDeleteBuffers");
		glGenBuffers = (PFNGLGENBUFFERSPROC_t)GetProcAddress((const GLubyte*)"glGenBuffers");
		glIsBuffer = (PFNGLISBUFFERPROC_t)GetProcAddress((const GLubyte*)"glIsBuffer");
		glBufferData = (PFNGLBUFFERDATAPROC_t)GetProcAddress((const GLubyte*)"glBufferData");
		glBufferSubData = (PFNGLBUFFERSUBDATAPROC_t)GetProcAddress((const GLubyte*)"glBufferSubData");
		glGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC_t)GetProcAddress((const GLubyte*)"glGetBufferSubData");
		glMapBuffer = (PFNGLMAPBUFFERPROC_t)GetProcAddress((const GLubyte*)"glMapBuffer");
		glUnmapBuffer = (PFNGLUNMAPBUFFERPROC_t)GetProcAddress((const GLubyte*)"glUnmapBuffer");
		glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC_t)GetProcAddress((const GLubyte*)"glGetBufferParameteriv");
		glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC_t)GetProcAddress((const GLubyte*)"glGetBufferPointerv");
	}

	inline GLvoid Load2_0Extensions()
	{
		glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC_t)GetProcAddress((const GLubyte*)"glBlendEquationSeparate");
		glDrawBuffers = (PFNGLDRAWBUFFERSPROC_t)GetProcAddress((const GLubyte*)"glDrawBuffers");
		glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC_t)GetProcAddress((const GLubyte*)"glStencilOpSeparate");
		glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC_t)GetProcAddress((const GLubyte*)"glStencilFuncSeparate");
		glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC_t)GetProcAddress((const GLubyte*)"glStencilMaskSeparate");
		glAttachShader = (PFNGLATTACHSHADERPROC_t)GetProcAddress((const GLubyte*)"glAttachShader");
		glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC_t)GetProcAddress((const GLubyte*)"glBindAttribLocation");
		glCompileShader = (PFNGLCOMPILESHADERPROC_t)GetProcAddress((const GLubyte*)"glCompileShader");
		glCreateProgram = (PFNGLCREATEPROGRAMPROC_t)GetProcAddress((const GLubyte*)"glCreateProgram");
		glCreateShader = (PFNGLCREATESHADERPROC_t)GetProcAddress((const GLubyte*)"glCreateShader");
		glDeleteProgram = (PFNGLDELETEPROGRAMPROC_t)GetProcAddress((const GLubyte*)"glDeleteProgram");
		glDeleteShader = (PFNGLDELETESHADERPROC_t)GetProcAddress((const GLubyte*)"glDeleteShader");
		glDetachShader = (PFNGLDETACHSHADERPROC_t)GetProcAddress((const GLubyte*)"glDetachShader");
		glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC_t)GetProcAddress((const GLubyte*)"glDisableVertexAttribArray");
		glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC_t)GetProcAddress((const GLubyte*)"glEnableVertexAttribArray");
		glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC_t)GetProcAddress((const GLubyte*)"glGetActiveAttrib");
		glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC_t)GetProcAddress((const GLubyte*)"glGetActiveUniform");
		glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC_t)GetProcAddress((const GLubyte*)"glGetAttachedShaders");
		glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC_t)GetProcAddress((const GLubyte*)"glGetAttribLocation");
		glGetProgramiv = (PFNGLGETPROGRAMIVPROC_t)GetProcAddress((const GLubyte*)"glGetProgramiv");
		glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC_t)GetProcAddress((const GLubyte*)"glGetProgramInfoLog");
		glGetShaderiv = (PFNGLGETSHADERIVPROC_t)GetProcAddress((const GLubyte*)"glGetShaderiv");
		glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC_t)GetProcAddress((const GLubyte*)"glGetShaderInfoLog");
		glGetShaderSource = (PFNGLGETSHADERSOURCEPROC_t)GetProcAddress((const GLubyte*)"glGetShaderSource");
		glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC_t)GetProcAddress((const GLubyte*)"glGetUniformLocation");
		glGetUniformfv = (PFNGLGETUNIFORMFVPROC_t)GetProcAddress((const GLubyte*)"glGetUniformfv");
		glGetUniformiv = (PFNGLGETUNIFORMIVPROC_t)GetProcAddress((const GLubyte*)"glGetUniformiv");
		glGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDVPROC_t)GetProcAddress((const GLubyte*)"glGetVertexAttribdv");
		glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC_t)GetProcAddress((const GLubyte*)"glGetVertexAttribfv");
		glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC_t)GetProcAddress((const GLubyte*)"glGetVertexAttribiv");
		glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC_t)GetProcAddress((const GLubyte*)"glGetVertexAttribPointerv");
		glIsProgram = (PFNGLISPROGRAMPROC_t)GetProcAddress((const GLubyte*)"glIsProgram");
		glIsShader = (PFNGLISSHADERPROC_t)GetProcAddress((const GLubyte*)"glIsShader");
		glLinkProgram = (PFNGLLINKPROGRAMPROC_t)GetProcAddress((const GLubyte*)"glLinkProgram");
		glShaderSource = (PFNGLSHADERSOURCEPROC_t)GetProcAddress((const GLubyte*)"glShaderSource");
		glUseProgram = (PFNGLUSEPROGRAMPROC_t)GetProcAddress((const GLubyte*)"glUseProgram");
		glUniform1f = (PFNGLUNIFORM1FPROC_t)GetProcAddress((const GLubyte*)"glUniform1f");
		glUniform2f = (PFNGLUNIFORM2FPROC_t)GetProcAddress((const GLubyte*)"glUniform2f");
		glUniform3f = (PFNGLUNIFORM3FPROC_t)GetProcAddress((const GLubyte*)"glUniform3f");
		glUniform4f = (PFNGLUNIFORM4FPROC_t)GetProcAddress((const GLubyte*)"glUniform4f");
		glUniform1i = (PFNGLUNIFORM1IPROC_t)GetProcAddress((const GLubyte*)"glUniform1i");
		glUniform2i = (PFNGLUNIFORM2IPROC_t)GetProcAddress((const GLubyte*)"glUniform2i");
		glUniform3i = (PFNGLUNIFORM3IPROC_t)GetProcAddress((const GLubyte*)"glUniform3i");
		glUniform4i = (PFNGLUNIFORM4IPROC_t)GetProcAddress((const GLubyte*)"glUniform4i");
		glUniform1fv = (PFNGLUNIFORM1FVPROC_t)GetProcAddress((const GLubyte*)"glUniform1fv");
		glUniform2fv = (PFNGLUNIFORM2FVPROC_t)GetProcAddress((const GLubyte*)"glUniform2fv");
		glUniform3fv = (PFNGLUNIFORM3FVPROC_t)GetProcAddress((const GLubyte*)"glUniform3fv");
		glUniform4fv = (PFNGLUNIFORM4FVPROC_t)GetProcAddress((const GLubyte*)"glUniform4fv");
		glUniform1iv = (PFNGLUNIFORM1IVPROC_t)GetProcAddress((const GLubyte*)"glUniform1iv");
		glUniform2iv = (PFNGLUNIFORM2IVPROC_t)GetProcAddress((const GLubyte*)"glUniform2iv");
		glUniform3iv = (PFNGLUNIFORM3IVPROC_t)GetProcAddress((const GLubyte*)"glUniform3iv");
		glUniform4iv = (PFNGLUNIFORM4IVPROC_t)GetProcAddress((const GLubyte*)"glUniform4iv");
		glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC_t)GetProcAddress((const GLubyte*)"glUniformMatrix2fv");
		glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC_t)GetProcAddress((const GLubyte*)"glUniformMatrix3fv");
		glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC_t)GetProcAddress((const GLubyte*)"glUniformMatrix4fv");
		glValidateProgram = (PFNGLVALIDATEPROGRAMPROC_t)GetProcAddress((const GLubyte*)"glValidateProgram");
		glVertexAttrib1d = (PFNGLVERTEXATTRIB1DPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib1d");
		glVertexAttrib1dv = (PFNGLVERTEXATTRIB1DVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib1dv");
		glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib1f");
		glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib1fv");
		glVertexAttrib1s = (PFNGLVERTEXATTRIB1SPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib1s");
		glVertexAttrib1sv = (PFNGLVERTEXATTRIB1SVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib1sv");
		glVertexAttrib2d = (PFNGLVERTEXATTRIB2DPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib2d");
		glVertexAttrib2dv = (PFNGLVERTEXATTRIB2DVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib2dv");
		glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib2f");
		glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib2fv");
		glVertexAttrib2s = (PFNGLVERTEXATTRIB2SPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib2s");
		glVertexAttrib2sv = (PFNGLVERTEXATTRIB2SVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib2sv");
		glVertexAttrib3d = (PFNGLVERTEXATTRIB3DPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib3d");
		glVertexAttrib3dv = (PFNGLVERTEXATTRIB3DVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib3dv");
		glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib3f");
		glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib3fv");
		glVertexAttrib3s = (PFNGLVERTEXATTRIB3SPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib3s");
		glVertexAttrib3sv = (PFNGLVERTEXATTRIB3SVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib3sv");
		glVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib4Nbv");
		glVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib4Niv");
		glVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib4Nsv");
		glVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUBPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib4Nub");
		glVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib4Nubv");
		glVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib4Nuiv");
		glVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib4Nusv");
		glVertexAttrib4bv = (PFNGLVERTEXATTRIB4BVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib4bv");
		glVertexAttrib4d = (PFNGLVERTEXATTRIB4DPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib4d");
		glVertexAttrib4dv = (PFNGLVERTEXATTRIB4DVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib4dv");
		glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib4f");
		glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib4fv");
		glVertexAttrib4iv = (PFNGLVERTEXATTRIB4IVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib4iv");
		glVertexAttrib4s = (PFNGLVERTEXATTRIB4SPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib4s");
		glVertexAttrib4sv = (PFNGLVERTEXATTRIB4SVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib4sv");
		glVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib4ubv");
		glVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib4uiv");
		glVertexAttrib4usv = (PFNGLVERTEXATTRIB4USVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib4usv");
		glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribPointer");
	}

	inline GLvoid Load2_1Extensions()
	{
		glUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC_t)GetProcAddress((const GLubyte*)"glUniformMatrix2x3fv");
		glUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC_t)GetProcAddress((const GLubyte*)"glUniformMatrix3x2fv");
		glUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC_t)GetProcAddress((const GLubyte*)"glUniformMatrix2x4fv");
		glUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC_t)GetProcAddress((const GLubyte*)"glUniformMatrix4x2fv");
		glUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC_t)GetProcAddress((const GLubyte*)"glUniformMatrix3x4fv");
		glUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC_t)GetProcAddress((const GLubyte*)"glUniformMatrix4x3fv");
	}

	inline GLvoid Load3_0Extensions()
	{
		glColorMaski = (PFNGLCOLORMASKIPROC_t)GetProcAddress((const GLubyte*)"glColorMaski");
		glGetBooleani_v = (PFNGLGETBOOLEANI_VPROC_t)GetProcAddress((const GLubyte*)"glGetBooleani_v");
		glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC_t)GetProcAddress((const GLubyte*)"glGetIntegeri_v");
		glEnablei = (PFNGLENABLEIPROC_t)GetProcAddress((const GLubyte*)"glEnablei");
		glDisablei = (PFNGLDISABLEIPROC_t)GetProcAddress((const GLubyte*)"glDisablei");
		glIsEnabledi = (PFNGLISENABLEDIPROC_t)GetProcAddress((const GLubyte*)"glIsEnabledi");
		glBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC_t)GetProcAddress((const GLubyte*)"glBeginTransformFeedback");
		glEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC_t)GetProcAddress((const GLubyte*)"glEndTransformFeedback");
		glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC_t)GetProcAddress((const GLubyte*)"glBindBufferRange");
		glBindBufferBase = (PFNGLBINDBUFFERBASEPROC_t)GetProcAddress((const GLubyte*)"glBindBufferBase");
		glTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC_t)GetProcAddress((const GLubyte*)"glTransformFeedbackVaryings");
		glGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC_t)GetProcAddress((const GLubyte*)"glGetTransformFeedbackVarying");
		glClampColor = (PFNGLCLAMPCOLORPROC_t)GetProcAddress((const GLubyte*)"glClampColor");
		glBeginConditionalRender = (PFNGLBEGINCONDITIONALRENDERPROC_t)GetProcAddress((const GLubyte*)"glBeginConditionalRender");
		glEndConditionalRender = (PFNGLENDCONDITIONALRENDERPROC_t)GetProcAddress((const GLubyte*)"glEndConditionalRender");
		glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribIPointer");
		glGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC_t)GetProcAddress((const GLubyte*)"glGetVertexAttribIiv");
		glGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC_t)GetProcAddress((const GLubyte*)"glGetVertexAttribIuiv");
		glVertexAttribI1i = (PFNGLVERTEXATTRIBI1IPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribI1i");
		glVertexAttribI2i = (PFNGLVERTEXATTRIBI2IPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribI2i");
		glVertexAttribI3i = (PFNGLVERTEXATTRIBI3IPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribI3i");
		glVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribI4i");
		glVertexAttribI1ui = (PFNGLVERTEXATTRIBI1UIPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribI1ui");
		glVertexAttribI2ui = (PFNGLVERTEXATTRIBI2UIPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribI2ui");
		glVertexAttribI3ui = (PFNGLVERTEXATTRIBI3UIPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribI3ui");
		glVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribI4ui");
		glVertexAttribI1iv = (PFNGLVERTEXATTRIBI1IVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribI1iv");
		glVertexAttribI2iv = (PFNGLVERTEXATTRIBI2IVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribI2iv");
		glVertexAttribI3iv = (PFNGLVERTEXATTRIBI3IVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribI3iv");
		glVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribI4iv");
		glVertexAttribI1uiv = (PFNGLVERTEXATTRIBI1UIVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribI1uiv");
		glVertexAttribI2uiv = (PFNGLVERTEXATTRIBI2UIVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribI2uiv");
		glVertexAttribI3uiv = (PFNGLVERTEXATTRIBI3UIVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribI3uiv");
		glVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribI4uiv");
		glVertexAttribI4bv = (PFNGLVERTEXATTRIBI4BVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribI4bv");
		glVertexAttribI4sv = (PFNGLVERTEXATTRIBI4SVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribI4sv");
		glVertexAttribI4ubv = (PFNGLVERTEXATTRIBI4UBVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribI4ubv");
		glVertexAttribI4usv = (PFNGLVERTEXATTRIBI4USVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribI4usv");
		glGetUniformuiv = (PFNGLGETUNIFORMUIVPROC_t)GetProcAddress((const GLubyte*)"glGetUniformuiv");
		glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC_t)GetProcAddress((const GLubyte*)"glBindFragDataLocation");
		glGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC_t)GetProcAddress((const GLubyte*)"glGetFragDataLocation");
		glUniform1ui = (PFNGLUNIFORM1UIPROC_t)GetProcAddress((const GLubyte*)"glUniform1ui");
		glUniform2ui = (PFNGLUNIFORM2UIPROC_t)GetProcAddress((const GLubyte*)"glUniform2ui");
		glUniform3ui = (PFNGLUNIFORM3UIPROC_t)GetProcAddress((const GLubyte*)"glUniform3ui");
		glUniform4ui = (PFNGLUNIFORM4UIPROC_t)GetProcAddress((const GLubyte*)"glUniform4ui");
		glUniform1uiv = (PFNGLUNIFORM1UIVPROC_t)GetProcAddress((const GLubyte*)"glUniform1uiv");
		glUniform2uiv = (PFNGLUNIFORM2UIVPROC_t)GetProcAddress((const GLubyte*)"glUniform2uiv");
		glUniform3uiv = (PFNGLUNIFORM3UIVPROC_t)GetProcAddress((const GLubyte*)"glUniform3uiv");
		glUniform4uiv = (PFNGLUNIFORM4UIVPROC_t)GetProcAddress((const GLubyte*)"glUniform4uiv");
		glTexParameterIiv = (PFNGLTEXPARAMETERIIVPROC_t)GetProcAddress((const GLubyte*)"glTexParameterIiv");
		glTexParameterIuiv = (PFNGLTEXPARAMETERIUIVPROC_t)GetProcAddress((const GLubyte*)"glTexParameterIuiv");
		glGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIVPROC_t)GetProcAddress((const GLubyte*)"glGetTexParameterIiv");
		glGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIVPROC_t)GetProcAddress((const GLubyte*)"glGetTexParameterIuiv");
		glClearBufferiv = (PFNGLCLEARBUFFERIVPROC_t)GetProcAddress((const GLubyte*)"glClearBufferiv");
		glClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC_t)GetProcAddress((const GLubyte*)"glClearBufferuiv");
		glClearBufferfv = (PFNGLCLEARBUFFERFVPROC_t)GetProcAddress((const GLubyte*)"glClearBufferfv");
		glClearBufferfi = (PFNGLCLEARBUFFERFIPROC_t)GetProcAddress((const GLubyte*)"glClearBufferfi");
		glGetStringi = (PFNGLGETSTRINGIPROC_t)GetProcAddress((const GLubyte*)"glGetStringi");
		glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC_t)GetProcAddress((const GLubyte*)"glIsRenderbuffer");
		glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC_t)GetProcAddress((const GLubyte*)"glBindRenderbuffer");
		glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC_t)GetProcAddress((const GLubyte*)"glDeleteRenderbuffers");
		glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC_t)GetProcAddress((const GLubyte*)"glGenRenderbuffers");
		glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC_t)GetProcAddress((const GLubyte*)"glRenderbufferStorage");
		glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC_t)GetProcAddress((const GLubyte*)"glGetRenderbufferParameteriv");
		glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC_t)GetProcAddress((const GLubyte*)"glIsFramebuffer");
		glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC_t)GetProcAddress((const GLubyte*)"glBindFramebuffer");
		glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC_t)GetProcAddress((const GLubyte*)"glDeleteFramebuffers");
		glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC_t)GetProcAddress((const GLubyte*)"glGenFramebuffers");
		glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC_t)GetProcAddress((const GLubyte*)"glCheckFramebufferStatus");
		glFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1DPROC_t)GetProcAddress((const GLubyte*)"glFramebufferTexture1D");
		glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC_t)GetProcAddress((const GLubyte*)"glFramebufferTexture2D");
		glFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3DPROC_t)GetProcAddress((const GLubyte*)"glFramebufferTexture3D");
		glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC_t)GetProcAddress((const GLubyte*)"glFramebufferRenderbuffer");
		glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC_t)GetProcAddress((const GLubyte*)"glGetFramebufferAttachmentParameteriv");
		glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC_t)GetProcAddress((const GLubyte*)"glGenerateMipmap");
		glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC_t)GetProcAddress((const GLubyte*)"glBlitFramebuffer");
		glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC_t)GetProcAddress((const GLubyte*)"glRenderbufferStorageMultisample");
		glFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC_t)GetProcAddress((const GLubyte*)"glFramebufferTextureLayer");
		glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC_t)GetProcAddress((const GLubyte*)"glMapBufferRange");
		glFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC_t)GetProcAddress((const GLubyte*)"glFlushMappedBufferRange");
		glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC_t)GetProcAddress((const GLubyte*)"glBindVertexArray");
		glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC_t)GetProcAddress((const GLubyte*)"glDeleteVertexArrays");
		glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC_t)GetProcAddress((const GLubyte*)"glGenVertexArrays");
		glIsVertexArray = (PFNGLISVERTEXARRAYPROC_t)GetProcAddress((const GLubyte*)"glIsVertexArray");
	}

	inline GLvoid Load3_1Extensions()
	{
		glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC_t)GetProcAddress((const GLubyte*)"glDrawArraysInstanced");
		glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC_t)GetProcAddress((const GLubyte*)"glDrawElementsInstanced");
		glTexBuffer = (PFNGLTEXBUFFERPROC_t)GetProcAddress((const GLubyte*)"glTexBuffer");
		glPrimitiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEXPROC_t)GetProcAddress((const GLubyte*)"glPrimitiveRestartIndex");
		glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC_t)GetProcAddress((const GLubyte*)"glCopyBufferSubData");
		glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC_t)GetProcAddress((const GLubyte*)"glGetUniformIndices");
		glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC_t)GetProcAddress((const GLubyte*)"glGetActiveUniformsiv");
		glGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC_t)GetProcAddress((const GLubyte*)"glGetActiveUniformName");
		glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC_t)GetProcAddress((const GLubyte*)"glGetUniformBlockIndex");
		glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC_t)GetProcAddress((const GLubyte*)"glGetActiveUniformBlockiv");
		glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC_t)GetProcAddress((const GLubyte*)"glGetActiveUniformBlockName");
		glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC_t)GetProcAddress((const GLubyte*)"glUniformBlockBinding");
	}

	inline GLvoid Load3_2Extensions()
	{
		glDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC_t)GetProcAddress((const GLubyte*)"glDrawElementsBaseVertex");
		glDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC_t)GetProcAddress((const GLubyte*)"glDrawRangeElementsBaseVertex");
		glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC_t)GetProcAddress((const GLubyte*)"glDrawElementsInstancedBaseVertex");
		glMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC_t)GetProcAddress((const GLubyte*)"glMultiDrawElementsBaseVertex");
		glProvokingVertex = (PFNGLPROVOKINGVERTEXPROC_t)GetProcAddress((const GLubyte*)"glProvokingVertex");
		glFenceSync = (PFNGLFENCESYNCPROC_t)GetProcAddress((const GLubyte*)"glFenceSync");
		glIsSync = (PFNGLISSYNCPROC_t)GetProcAddress((const GLubyte*)"glIsSync");
		glDeleteSync = (PFNGLDELETESYNCPROC_t)GetProcAddress((const GLubyte*)"glDeleteSync");
		glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC_t)GetProcAddress((const GLubyte*)"glClientWaitSync");
		glWaitSync = (PFNGLWAITSYNCPROC_t)GetProcAddress((const GLubyte*)"glWaitSync");
		glGetInteger64v = (PFNGLGETINTEGER64VPROC_t)GetProcAddress((const GLubyte*)"glGetInteger64v");
		glGetSynciv = (PFNGLGETSYNCIVPROC_t)GetProcAddress((const GLubyte*)"glGetSynciv");
		glGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC_t)GetProcAddress((const GLubyte*)"glGetInteger64i_v");
		glGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC_t)GetProcAddress((const GLubyte*)"glGetBufferParameteri64v");
		glFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC_t)GetProcAddress((const GLubyte*)"glFramebufferTexture");
		glTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC_t)GetProcAddress((const GLubyte*)"glTexImage2DMultisample");
		glTexImage3DMultisample = (PFNGLTEXIMAGE3DMULTISAMPLEPROC_t)GetProcAddress((const GLubyte*)"glTexImage3DMultisample");
		glGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC_t)GetProcAddress((const GLubyte*)"glGetMultisamplefv");
		glSampleMaski = (PFNGLSAMPLEMASKIPROC_t)GetProcAddress((const GLubyte*)"glSampleMaski");
	}
	
	inline GLvoid Load3_3Extensions()
	{
		glBindFragDataLocationIndexed = (PFNGLBINDFRAGDATALOCATIONINDEXEDPROC_t)GetProcAddress((const GLubyte*)"glBindFragDataLocationIndexed");
		glGetFragDataIndex = (PFNGLGETFRAGDATAINDEXPROC_t)GetProcAddress((const GLubyte*)"glGetFragDataIndex");
		glGenSamplers = (PFNGLGENSAMPLERSPROC_t)GetProcAddress((const GLubyte*)"glGenSamplers");
		glDeleteSamplers = (PFNGLDELETESAMPLERSPROC_t)GetProcAddress((const GLubyte*)"glDeleteSamplers");
		glIsSampler = (PFNGLISSAMPLERPROC_t)GetProcAddress((const GLubyte*)"glIsSampler");
		glBindSampler = (PFNGLBINDSAMPLERPROC_t)GetProcAddress((const GLubyte*)"glBindSampler");
		glSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC_t)GetProcAddress((const GLubyte*)"glSamplerParameteri");
		glSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC_t)GetProcAddress((const GLubyte*)"glSamplerParameteriv");
		glSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC_t)GetProcAddress((const GLubyte*)"glSamplerParameterf");
		glSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC_t)GetProcAddress((const GLubyte*)"glSamplerParameterfv");
		glSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIVPROC_t)GetProcAddress((const GLubyte*)"glSamplerParameterIiv");
		glSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIVPROC_t)GetProcAddress((const GLubyte*)"glSamplerParameterIuiv");
		glGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC_t)GetProcAddress((const GLubyte*)"glGetSamplerParameteriv");
		glGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIVPROC_t)GetProcAddress((const GLubyte*)"glGetSamplerParameterIiv");
		glGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC_t)GetProcAddress((const GLubyte*)"glGetSamplerParameterfv");
		glGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIVPROC_t)GetProcAddress((const GLubyte*)"glGetSamplerParameterIuiv");
		glQueryCounter = (PFNGLQUERYCOUNTERPROC_t)GetProcAddress((const GLubyte*)"glQueryCounter");
		glGetQueryObjecti64v = (PFNGLGETQUERYOBJECTI64VPROC_t)GetProcAddress((const GLubyte*)"glGetQueryObjecti64v");
		glGetQueryObjectui64v = (PFNGLGETQUERYOBJECTUI64VPROC_t)GetProcAddress((const GLubyte*)"glGetQueryObjectui64v");
		glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribDivisor");
		glVertexAttribP1ui = (PFNGLVERTEXATTRIBP1UIPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribP1ui");
		glVertexAttribP1uiv = (PFNGLVERTEXATTRIBP1UIVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribP1uiv");
		glVertexAttribP2ui = (PFNGLVERTEXATTRIBP2UIPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribP2ui");
		glVertexAttribP2uiv = (PFNGLVERTEXATTRIBP2UIVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribP2uiv");
		glVertexAttribP3ui = (PFNGLVERTEXATTRIBP3UIPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribP3ui");
		glVertexAttribP3uiv = (PFNGLVERTEXATTRIBP3UIVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribP3uiv");
		glVertexAttribP4ui = (PFNGLVERTEXATTRIBP4UIPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribP4ui");
		glVertexAttribP4uiv = (PFNGLVERTEXATTRIBP4UIVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribP4uiv");
		glVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttrib4uiv");
		glVertexP2ui = (PFNGLVERTEXP2UIPROC_t)GetProcAddress((const GLubyte*)"glVertexP2ui");
		glVertexP2uiv = (PFNGLVERTEXP2UIVPROC_t)GetProcAddress((const GLubyte*)"glVertexP2uiv");
		glVertexP3ui = (PFNGLVERTEXP3UIPROC_t)GetProcAddress((const GLubyte*)"glVertexP3ui");
		glVertexP3uiv = (PFNGLVERTEXP3UIVPROC_t)GetProcAddress((const GLubyte*)"glVertexP3uiv");
		glVertexP4ui = (PFNGLVERTEXP4UIPROC_t)GetProcAddress((const GLubyte*)"glVertexP4ui");
		glVertexP4uiv = (PFNGLVERTEXP4UIVPROC_t)GetProcAddress((const GLubyte*)"glVertexP4uiv");
		glTexCoordP1ui = (PFNGLTEXCOORDP1UIPROC_t)GetProcAddress((const GLubyte*)"glTexCoordP1ui");
		glTexCoordP1uiv = (PFNGLTEXCOORDP1UIVPROC_t)GetProcAddress((const GLubyte*)"glTexCoordP1uiv");
		glTexCoordP2ui = (PFNGLTEXCOORDP2UIPROC_t)GetProcAddress((const GLubyte*)"glTexCoordP2ui");
		glTexCoordP2uiv = (PFNGLTEXCOORDP2UIVPROC_t)GetProcAddress((const GLubyte*)"glTexCoordP2uiv");
		glTexCoordP3ui = (PFNGLTEXCOORDP3UIPROC_t)GetProcAddress((const GLubyte*)"glTexCoordP3ui");
		glTexCoordP3uiv = (PFNGLTEXCOORDP3UIVPROC_t)GetProcAddress((const GLubyte*)"glTexCoordP3uiv");
		glTexCoordP4ui = (PFNGLTEXCOORDP4UIPROC_t)GetProcAddress((const GLubyte*)"glTexCoordP4ui");
		glTexCoordP4uiv = (PFNGLTEXCOORDP4UIVPROC_t)GetProcAddress((const GLubyte*)"glTexCoordP4uiv");
		glMultiTexCoordP1ui = (PFNGLMULTITEXCOORDP1UIPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoordP1ui");
		glMultiTexCoordP1uiv = (PFNGLMULTITEXCOORDP1UIVPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoordP1uiv");
		glMultiTexCoordP2ui = (PFNGLMULTITEXCOORDP2UIPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoordP2ui");
		glMultiTexCoordP2uiv = (PFNGLMULTITEXCOORDP2UIVPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoordP2uiv");
		glMultiTexCoordP3ui = (PFNGLMULTITEXCOORDP3UIPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoordP3ui");
		glMultiTexCoordP3uiv = (PFNGLMULTITEXCOORDP3UIVPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoordP3uiv");
		glMultiTexCoordP4ui = (PFNGLMULTITEXCOORDP4UIPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoordP4ui");
		glMultiTexCoordP4uiv = (PFNGLMULTITEXCOORDP4UIVPROC_t)GetProcAddress((const GLubyte*)"glMultiTexCoordP4uiv");
		glNormalP3ui = (PFNGLNORMALP3UIPROC_t)GetProcAddress((const GLubyte*)"glNormalP3ui");
		glNormalP3uiv = (PFNGLNORMALP3UIVPROC_t)GetProcAddress((const GLubyte*)"glNormalP3uiv");
		glColorP3ui = (PFNGLCOLORP3UIPROC_t)GetProcAddress((const GLubyte*)"glColorP3ui");
		glColorP3uiv = (PFNGLCOLORP3UIVPROC_t)GetProcAddress((const GLubyte*)"glColorP3uiv");
		glColorP4ui = (PFNGLCOLORP4UIPROC_t)GetProcAddress((const GLubyte*)"glColorP4ui");
		glColorP4uiv = (PFNGLCOLORP4UIVPROC_t)GetProcAddress((const GLubyte*)"glColorP4uiv");
		glSecondaryColorP3ui = (PFNGLSECONDARYCOLORP3UIPROC_t)GetProcAddress((const GLubyte*)"glSecondaryColorP3ui");
		glSecondaryColorP3uiv = (PFNGLSECONDARYCOLORP3UIVPROC_t)GetProcAddress((const GLubyte*)"glSecondaryColorP3uiv");
	}

	inline GLvoid Load4_0Extensions()
	{
		glMinSampleShading = (PFNGLMINSAMPLESHADINGPROC_t)GetProcAddress((const GLubyte*)"glMinSampleShading");
		glBlendEquationi = (PFNGLBLENDEQUATIONIPROC_t)GetProcAddress((const GLubyte*)"glBlendEquationi");
		glBlendEquationSeparatei = (PFNGLBLENDEQUATIONSEPARATEIPROC_t)GetProcAddress((const GLubyte*)"glBlendEquationSeparatei");
		glBlendFunci = (PFNGLBLENDFUNCIPROC_t)GetProcAddress((const GLubyte*)"glBlendFunci");
		glBlendFuncSeparatei = (PFNGLBLENDFUNCSEPARATEIPROC_t)GetProcAddress((const GLubyte*)"glBlendFuncSeparatei");
		glDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECTPROC_t)GetProcAddress((const GLubyte*)"glDrawArraysIndirect");
		glDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECTPROC_t)GetProcAddress((const GLubyte*)"glDrawElementsIndirect");
		glUniform1d = (PFNGLUNIFORM1DPROC_t)GetProcAddress((const GLubyte*)"glUniform1d");
		glUniform2d = (PFNGLUNIFORM2DPROC_t)GetProcAddress((const GLubyte*)"glUniform2d");
		glUniform3d = (PFNGLUNIFORM3DPROC_t)GetProcAddress((const GLubyte*)"glUniform3d");
		glUniform4d = (PFNGLUNIFORM4DPROC_t)GetProcAddress((const GLubyte*)"glUniform4d");
		glUniform1dv = (PFNGLUNIFORM1DVPROC_t)GetProcAddress((const GLubyte*)"glUniform1dv");
		glUniform2dv = (PFNGLUNIFORM2DVPROC_t)GetProcAddress((const GLubyte*)"glUniform2dv");
		glUniform3dv = (PFNGLUNIFORM3DVPROC_t)GetProcAddress((const GLubyte*)"glUniform3dv");
		glUniform4dv = (PFNGLUNIFORM4DVPROC_t)GetProcAddress((const GLubyte*)"glUniform4dv");
		glUniformMatrix2dv = (PFNGLUNIFORMMATRIX2DVPROC_t)GetProcAddress((const GLubyte*)"glUniformMatrix2dv");
		glUniformMatrix3dv = (PFNGLUNIFORMMATRIX3DVPROC_t)GetProcAddress((const GLubyte*)"glUniformMatrix3dv");
		glUniformMatrix4dv = (PFNGLUNIFORMMATRIX4DVPROC_t)GetProcAddress((const GLubyte*)"glUniformMatrix4dv");
		glUniformMatrix2x3dv = (PFNGLUNIFORMMATRIX2X3DVPROC_t)GetProcAddress((const GLubyte*)"glUniformMatrix2x3dv");
		glUniformMatrix2x4dv = (PFNGLUNIFORMMATRIX2X4DVPROC_t)GetProcAddress((const GLubyte*)"glUniformMatrix2x4dv");
		glUniformMatrix3x2dv = (PFNGLUNIFORMMATRIX3X2DVPROC_t)GetProcAddress((const GLubyte*)"glUniformMatrix3x2dv");
		glUniformMatrix3x4dv = (PFNGLUNIFORMMATRIX3X4DVPROC_t)GetProcAddress((const GLubyte*)"glUniformMatrix3x4dv");
		glUniformMatrix4x2dv = (PFNGLUNIFORMMATRIX4X2DVPROC_t)GetProcAddress((const GLubyte*)"glUniformMatrix4x2dv");
		glUniformMatrix4x3dv = (PFNGLUNIFORMMATRIX4X3DVPROC_t)GetProcAddress((const GLubyte*)"glUniformMatrix4x3dv");
		glGetUniformdv = (PFNGLGETUNIFORMDVPROC_t)GetProcAddress((const GLubyte*)"glGetUniformdv");
		glGetSubroutineUniformLocation = (PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC_t)GetProcAddress((const GLubyte*)"glGetSubroutineUniformLocation");
		glGetSubroutineIndex = (PFNGLGETSUBROUTINEINDEXPROC_t)GetProcAddress((const GLubyte*)"glGetSubroutineIndex");
		glGetActiveSubroutineUniformiv = (PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC_t)GetProcAddress((const GLubyte*)"glGetActiveSubroutineUniformiv");
		glGetActiveSubroutineUniformName = (PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC_t)GetProcAddress((const GLubyte*)"glGetActiveSubroutineUniformName");
		glGetActiveSubroutineName = (PFNGLGETACTIVESUBROUTINENAMEPROC_t)GetProcAddress((const GLubyte*)"glGetActiveSubroutineName");
		glUniformSubroutinesuiv = (PFNGLUNIFORMSUBROUTINESUIVPROC_t)GetProcAddress((const GLubyte*)"glUniformSubroutinesuiv");
		glGetUniformSubroutineuiv = (PFNGLGETUNIFORMSUBROUTINEUIVPROC_t)GetProcAddress((const GLubyte*)"glGetUniformSubroutineuiv");
		glGetProgramStageiv = (PFNGLGETPROGRAMSTAGEIVPROC_t)GetProcAddress((const GLubyte*)"glGetProgramStageiv");
		glPatchParameteri = (PFNGLPATCHPARAMETERIPROC_t)GetProcAddress((const GLubyte*)"glPatchParameteri");
		glPatchParameterfv = (PFNGLPATCHPARAMETERFVPROC_t)GetProcAddress((const GLubyte*)"glPatchParameterfv");
		glBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACKPROC_t)GetProcAddress((const GLubyte*)"glBindTransformFeedback");
		glDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKSPROC_t)GetProcAddress((const GLubyte*)"glDeleteTransformFeedbacks");
		glGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKSPROC_t)GetProcAddress((const GLubyte*)"glGenTransformFeedbacks");
		glIsTransformFeedback = (PFNGLISTRANSFORMFEEDBACKPROC_t)GetProcAddress((const GLubyte*)"glIsTransformFeedback");
		glPauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACKPROC_t)GetProcAddress((const GLubyte*)"glPauseTransformFeedback");
		glResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACKPROC_t)GetProcAddress((const GLubyte*)"glResumeTransformFeedback");
		glDrawTransformFeedback = (PFNGLDRAWTRANSFORMFEEDBACKPROC_t)GetProcAddress((const GLubyte*)"glDrawTransformFeedback");
		glDrawTransformFeedbackStream = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC_t)GetProcAddress((const GLubyte*)"glDrawTransformFeedbackStream");
		glBeginQueryIndexed = (PFNGLBEGINQUERYINDEXEDPROC_t)GetProcAddress((const GLubyte*)"glBeginQueryIndexed");
		glEndQueryIndexed = (PFNGLENDQUERYINDEXEDPROC_t)GetProcAddress((const GLubyte*)"glEndQueryIndexed");
		glGetQueryIndexediv = (PFNGLGETQUERYINDEXEDIVPROC_t)GetProcAddress((const GLubyte*)"glGetQueryIndexediv");
	}

	inline GLvoid Load4_1Extensions()
	{
		glReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILERPROC_t)GetProcAddress((const GLubyte*)"glReleaseShaderCompiler");
		glShaderBinary = (PFNGLSHADERBINARYPROC_t)GetProcAddress((const GLubyte*)"glShaderBinary");
		glGetShaderPrecisionFormat = (PFNGLGETSHADERPRECISIONFORMATPROC_t)GetProcAddress((const GLubyte*)"glGetShaderPrecisionFormat");
		glDepthRangef = (PFNGLDEPTHRANGEFPROC_t)GetProcAddress((const GLubyte*)"glDepthRangef");
		glClearDepthf = (PFNGLCLEARDEPTHFPROC_t)GetProcAddress((const GLubyte*)"glClearDepthf");
		glGetProgramBinary = (PFNGLGETPROGRAMBINARYPROC_t)GetProcAddress((const GLubyte*)"glGetProgramBinary");
		glProgramBinary = (PFNGLPROGRAMBINARYPROC_t)GetProcAddress((const GLubyte*)"glProgramBinary");
		glProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC_t)GetProcAddress((const GLubyte*)"glProgramParameteri");
		glUseProgramStages = (PFNGLUSEPROGRAMSTAGESPROC_t)GetProcAddress((const GLubyte*)"glUseProgramStages");
		glActiveShaderProgram = (PFNGLACTIVESHADERPROGRAMPROC_t)GetProcAddress((const GLubyte*)"glActiveShaderProgram");
		glCreateShaderProgramv = (PFNGLCREATESHADERPROGRAMVPROC_t)GetProcAddress((const GLubyte*)"glCreateShaderProgramv");
		glBindProgramPipeline = (PFNGLBINDPROGRAMPIPELINEPROC_t)GetProcAddress((const GLubyte*)"glBindProgramPipeline");
		glDeleteProgramPipelines = (PFNGLDELETEPROGRAMPIPELINESPROC_t)GetProcAddress((const GLubyte*)"glDeleteProgramPipelines");
		glGenProgramPipelines = (PFNGLGENPROGRAMPIPELINESPROC_t)GetProcAddress((const GLubyte*)"glGenProgramPipelines");
		glIsProgramPipeline = (PFNGLISPROGRAMPIPELINEPROC_t)GetProcAddress((const GLubyte*)"glIsProgramPipeline");
		glGetProgramPipelineiv = (PFNGLGETPROGRAMPIPELINEIVPROC_t)GetProcAddress((const GLubyte*)"glGetProgramPipelineiv");
		glProgramUniform1i = (PFNGLPROGRAMUNIFORM1IPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform1i");
		glProgramUniform1iv = (PFNGLPROGRAMUNIFORM1IVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform1iv");
		glProgramUniform1f = (PFNGLPROGRAMUNIFORM1FPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform1f");
		glProgramUniform1fv = (PFNGLPROGRAMUNIFORM1FVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform1fv");
		glProgramUniform1d = (PFNGLPROGRAMUNIFORM1DPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform1d");
		glProgramUniform1dv = (PFNGLPROGRAMUNIFORM1DVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform1dv");
		glProgramUniform1ui = (PFNGLPROGRAMUNIFORM1UIPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform1ui");
		glProgramUniform1uiv = (PFNGLPROGRAMUNIFORM1UIVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform1uiv");
		glProgramUniform2i = (PFNGLPROGRAMUNIFORM2IPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform2i");
		glProgramUniform2iv = (PFNGLPROGRAMUNIFORM2IVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform2iv");
		glProgramUniform2f = (PFNGLPROGRAMUNIFORM2FPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform2f");
		glProgramUniform2fv = (PFNGLPROGRAMUNIFORM2FVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform2fv");
		glProgramUniform2d = (PFNGLPROGRAMUNIFORM2DPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform2d");
		glProgramUniform2dv = (PFNGLPROGRAMUNIFORM2DVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform2dv");
		glProgramUniform2ui = (PFNGLPROGRAMUNIFORM2UIPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform2ui");
		glProgramUniform2uiv = (PFNGLPROGRAMUNIFORM2UIVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform2uiv");
		glProgramUniform3i = (PFNGLPROGRAMUNIFORM3IPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform3i");
		glProgramUniform3iv = (PFNGLPROGRAMUNIFORM3IVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform3iv");
		glProgramUniform3f = (PFNGLPROGRAMUNIFORM3FPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform3f");
		glProgramUniform3fv = (PFNGLPROGRAMUNIFORM3FVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform3fv");
		glProgramUniform3d = (PFNGLPROGRAMUNIFORM3DPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform3d");
		glProgramUniform3dv = (PFNGLPROGRAMUNIFORM3DVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform3dv");
		glProgramUniform3ui = (PFNGLPROGRAMUNIFORM3UIPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform3ui");
		glProgramUniform3uiv = (PFNGLPROGRAMUNIFORM3UIVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform3uiv");
		glProgramUniform4i = (PFNGLPROGRAMUNIFORM4IPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform4i");
		glProgramUniform4iv = (PFNGLPROGRAMUNIFORM4IVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform4iv");
		glProgramUniform4f = (PFNGLPROGRAMUNIFORM4FPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform4f");
		glProgramUniform4fv = (PFNGLPROGRAMUNIFORM4FVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform4fv");
		glProgramUniform4d = (PFNGLPROGRAMUNIFORM4DPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform4d");
		glProgramUniform4dv = (PFNGLPROGRAMUNIFORM4DVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform4dv");
		glProgramUniform4ui = (PFNGLPROGRAMUNIFORM4UIPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform4ui");
		glProgramUniform4uiv = (PFNGLPROGRAMUNIFORM4UIVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniform4uiv");
		glProgramUniformMatrix2fv = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniformMatrix2fv");
		glProgramUniformMatrix3fv = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniformMatrix3fv");
		glProgramUniformMatrix4fv = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniformMatrix4fv");
		glProgramUniformMatrix2dv = (PFNGLPROGRAMUNIFORMMATRIX2DVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniformMatrix2dv");
		glProgramUniformMatrix3dv = (PFNGLPROGRAMUNIFORMMATRIX3DVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniformMatrix3dv");
		glProgramUniformMatrix4dv = (PFNGLPROGRAMUNIFORMMATRIX4DVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniformMatrix4dv");
		glProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniformMatrix2x3fv");
		glProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniformMatrix3x2fv");
		glProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniformMatrix2x4fv");
		glProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniformMatrix4x2fv");
		glProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniformMatrix3x4fv");
		glProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniformMatrix4x3fv");
		glProgramUniformMatrix2x3dv = (PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniformMatrix2x3dv");
		glProgramUniformMatrix3x2dv = (PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniformMatrix3x2dv");
		glProgramUniformMatrix2x4dv = (PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniformMatrix2x4dv");
		glProgramUniformMatrix4x2dv = (PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniformMatrix4x2dv");
		glProgramUniformMatrix3x4dv = (PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniformMatrix3x4dv");
		glProgramUniformMatrix4x3dv = (PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC_t)GetProcAddress((const GLubyte*)"glProgramUniformMatrix4x3dv");
		glValidateProgramPipeline = (PFNGLVALIDATEPROGRAMPIPELINEPROC_t)GetProcAddress((const GLubyte*)"glValidateProgramPipeline");
		glGetProgramPipelineInfoLog = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC_t)GetProcAddress((const GLubyte*)"glGetProgramPipelineInfoLog");
		glVertexAttribL1d = (PFNGLVERTEXATTRIBL1DPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribL1d");
		glVertexAttribL2d = (PFNGLVERTEXATTRIBL2DPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribL2d");
		glVertexAttribL3d = (PFNGLVERTEXATTRIBL3DPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribL3d");
		glVertexAttribL4d = (PFNGLVERTEXATTRIBL4DPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribL4d");
		glVertexAttribL1dv = (PFNGLVERTEXATTRIBL1DVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribL1dv");
		glVertexAttribL2dv = (PFNGLVERTEXATTRIBL2DVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribL2dv");
		glVertexAttribL3dv = (PFNGLVERTEXATTRIBL3DVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribL3dv");
		glVertexAttribL4dv = (PFNGLVERTEXATTRIBL4DVPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribL4dv");
		glVertexAttribLPointer = (PFNGLVERTEXATTRIBLPOINTERPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribLPointer");
		glGetVertexAttribLdv = (PFNGLGETVERTEXATTRIBLDVPROC_t)GetProcAddress((const GLubyte*)"glGetVertexAttribLdv");
		glViewportArrayv = (PFNGLVIEWPORTARRAYVPROC_t)GetProcAddress((const GLubyte*)"glViewportArrayv");
		glViewportIndexedf = (PFNGLVIEWPORTINDEXEDFPROC_t)GetProcAddress((const GLubyte*)"glViewportIndexedf");
		glViewportIndexedfv = (PFNGLVIEWPORTINDEXEDFVPROC_t)GetProcAddress((const GLubyte*)"glViewportIndexedfv");
		glScissorArrayv = (PFNGLSCISSORARRAYVPROC_t)GetProcAddress((const GLubyte*)"glScissorArrayv");
		glScissorIndexed = (PFNGLSCISSORINDEXEDPROC_t)GetProcAddress((const GLubyte*)"glScissorIndexed");
		glScissorIndexedv = (PFNGLSCISSORINDEXEDVPROC_t)GetProcAddress((const GLubyte*)"glScissorIndexedv");
		glDepthRangeIndexed = (PFNGLDEPTHRANGEINDEXEDPROC_t)GetProcAddress((const GLubyte*)"glDepthRangeIndexed");
		glDepthRangeArrayv = (PFNGLDEPTHRANGEARRAYVPROC_t)GetProcAddress((const GLubyte*)"glDepthRangeArrayv");
		glGetFloati_v = (PFNGLGETFLOATI_VPROC_t)GetProcAddress((const GLubyte*)"glGetFloati_v");
		glGetDoublei_v = (PFNGLGETDOUBLEI_VPROC_t)GetProcAddress((const GLubyte*)"glGetDoublei_v");
	}

	inline GLvoid Load4_2Extensions()
	{
		glDrawArraysInstancedBaseInstance = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC_t)GetProcAddress((const GLubyte*)"glDrawArraysInstancedBaseInstance");
		glDrawElementsInstancedBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC_t)GetProcAddress((const GLubyte*)"glDrawElementsInstancedBaseInstance");
		glDrawElementsInstancedBaseVertexBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC_t)GetProcAddress((const GLubyte*)"glDrawElementsInstancedBaseVertexBaseInstance");
		glGetInternalformativ = (PFNGLGETINTERNALFORMATIVPROC_t)GetProcAddress((const GLubyte*)"glGetInternalformativ");
		glGetActiveAtomicCounterBufferiv = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC_t)GetProcAddress((const GLubyte*)"glGetActiveAtomicCounterBufferiv");
		glBindImageTexture = (PFNGLBINDIMAGETEXTUREPROC_t)GetProcAddress((const GLubyte*)"glBindImageTexture");
		glMemoryBarrier = (PFNGLMEMORYBARRIERPROC_t)GetProcAddress((const GLubyte*)"glMemoryBarrier");
		glTexStorage1D = (PFNGLTEXSTORAGE1DPROC_t)GetProcAddress((const GLubyte*)"glTexStorage1D");
		glTexStorage2D = (PFNGLTEXSTORAGE2DPROC_t)GetProcAddress((const GLubyte*)"glTexStorage2D");
		glTexStorage3D = (PFNGLTEXSTORAGE3DPROC_t)GetProcAddress((const GLubyte*)"glTexStorage3D");
		glDrawTransformFeedbackInstanced = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC_t)GetProcAddress((const GLubyte*)"glDrawTransformFeedbackInstanced");
		glDrawTransformFeedbackStreamInstanced = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC_t)GetProcAddress((const GLubyte*)"glDrawTransformFeedbackStreamInstanced");
	}

	inline GLvoid Load4_3Extensions()
	{
		glClearBufferData = (PFNGLCLEARBUFFERDATAPROC_t)GetProcAddress((const GLubyte*)"glClearBufferData");
		glClearBufferSubData = (PFNGLCLEARBUFFERSUBDATAPROC_t)GetProcAddress((const GLubyte*)"glClearBufferSubData");
		glDispatchCompute = (PFNGLDISPATCHCOMPUTEPROC_t)GetProcAddress((const GLubyte*)"glDispatchCompute");
		glDispatchComputeIndirect = (PFNGLDISPATCHCOMPUTEINDIRECTPROC_t)GetProcAddress((const GLubyte*)"glDispatchComputeIndirect");
		glCopyImageSubData = (PFNGLCOPYIMAGESUBDATAPROC_t)GetProcAddress((const GLubyte*)"glCopyImageSubData");
		glFramebufferParameteri = (PFNGLFRAMEBUFFERPARAMETERIPROC_t)GetProcAddress((const GLubyte*)"glFramebufferParameteri");
		glGetFramebufferParameteriv = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC_t)GetProcAddress((const GLubyte*)"glGetFramebufferParameteriv");
		glGetInternalformati64v = (PFNGLGETINTERNALFORMATI64VPROC_t)GetProcAddress((const GLubyte*)"glGetInternalformati64v");
		glInvalidateTexSubImage = (PFNGLINVALIDATETEXSUBIMAGEPROC_t)GetProcAddress((const GLubyte*)"glInvalidateTexSubImage");
		glInvalidateTexImage = (PFNGLINVALIDATETEXIMAGEPROC_t)GetProcAddress((const GLubyte*)"glInvalidateTexImage");
		glInvalidateBufferSubData = (PFNGLINVALIDATEBUFFERSUBDATAPROC_t)GetProcAddress((const GLubyte*)"glInvalidateBufferSubData");
		glInvalidateBufferData = (PFNGLINVALIDATEBUFFERDATAPROC_t)GetProcAddress((const GLubyte*)"glInvalidateBufferData");
		glInvalidateFramebuffer = (PFNGLINVALIDATEFRAMEBUFFERPROC_t)GetProcAddress((const GLubyte*)"glInvalidateFramebuffer");
		glInvalidateSubFramebuffer = (PFNGLINVALIDATESUBFRAMEBUFFERPROC_t)GetProcAddress((const GLubyte*)"glInvalidateSubFramebuffer");
		glMultiDrawArraysIndirect = (PFNGLMULTIDRAWARRAYSINDIRECTPROC_t)GetProcAddress((const GLubyte*)"glMultiDrawArraysIndirect");
		glMultiDrawElementsIndirect = (PFNGLMULTIDRAWELEMENTSINDIRECTPROC_t)GetProcAddress((const GLubyte*)"glMultiDrawElementsIndirect");
		glGetProgramInterfaceiv = (PFNGLGETPROGRAMINTERFACEIVPROC_t)GetProcAddress((const GLubyte*)"glGetProgramInterfaceiv");
		glGetProgramResourceIndex = (PFNGLGETPROGRAMRESOURCEINDEXPROC_t)GetProcAddress((const GLubyte*)"glGetProgramResourceIndex");
		glGetProgramResourceName = (PFNGLGETPROGRAMRESOURCENAMEPROC_t)GetProcAddress((const GLubyte*)"glGetProgramResourceName");
		glGetProgramResourceiv = (PFNGLGETPROGRAMRESOURCEIVPROC_t)GetProcAddress((const GLubyte*)"glGetProgramResourceiv");
		glGetProgramResourceLocation = (PFNGLGETPROGRAMRESOURCELOCATIONPROC_t)GetProcAddress((const GLubyte*)"glGetProgramResourceLocation");
		glGetProgramResourceLocationIndex = (PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC_t)GetProcAddress((const GLubyte*)"glGetProgramResourceLocationIndex");
		glShaderStorageBlockBinding = (PFNGLSHADERSTORAGEBLOCKBINDINGPROC_t)GetProcAddress((const GLubyte*)"glShaderStorageBlockBinding");
		glTexBufferRange = (PFNGLTEXBUFFERRANGEPROC_t)GetProcAddress((const GLubyte*)"glTexBufferRange");
		glTexStorage2DMultisample = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC_t)GetProcAddress((const GLubyte*)"glTexStorage2DMultisample");
		glTexStorage3DMultisample = (PFNGLTEXSTORAGE3DMULTISAMPLEPROC_t)GetProcAddress((const GLubyte*)"glTexStorage3DMultisample");
		glTextureView = (PFNGLTEXTUREVIEWPROC_t)GetProcAddress((const GLubyte*)"glTextureView");
		glBindVertexBuffer = (PFNGLBINDVERTEXBUFFERPROC_t)GetProcAddress((const GLubyte*)"glBindVertexBuffer");
		glVertexAttribFormat = (PFNGLVERTEXATTRIBFORMATPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribFormat");
		glVertexAttribIFormat = (PFNGLVERTEXATTRIBIFORMATPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribIFormat");
		glVertexAttribLFormat = (PFNGLVERTEXATTRIBLFORMATPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribLFormat");
		glVertexAttribBinding = (PFNGLVERTEXATTRIBBINDINGPROC_t)GetProcAddress((const GLubyte*)"glVertexAttribBinding");
		glVertexBindingDivisor = (PFNGLVERTEXBINDINGDIVISORPROC_t)GetProcAddress((const GLubyte*)"glVertexBindingDivisor");
		glDebugMessageControl = (PFNGLDEBUGMESSAGECONTROLPROC_t)GetProcAddress((const GLubyte*)"glDebugMessageControl");
		glDebugMessageInsert = (PFNGLDEBUGMESSAGEINSERTPROC_t)GetProcAddress((const GLubyte*)"glDebugMessageInsert");
		glDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC_t)GetProcAddress((const GLubyte*)"glDebugMessageCallback");
		glGetDebugMessageLog = (PFNGLGETDEBUGMESSAGELOGPROC_t)GetProcAddress((const GLubyte*)"glGetDebugMessageLog");
		glPushDebugGroup = (PFNGLPUSHDEBUGGROUPPROC_t)GetProcAddress((const GLubyte*)"glPushDebugGroup");
		glPopDebugGroup = (PFNGLPOPDEBUGGROUPPROC_t)GetProcAddress((const GLubyte*)"glPopDebugGroup");
		glObjectLabel = (PFNGLOBJECTLABELPROC_t)GetProcAddress((const GLubyte*)"glObjectLabel");
		glObjectPtrLabel = (PFNGLOBJECTPTRLABELPROC_t)GetProcAddress((const GLubyte*)"glObjectPtrLabel");
		glGetObjectLabel = (PFNGLGETOBJECTLABELPROC_t)GetProcAddress((const GLubyte*)"glGetObjectLabel");
		glGetObjectPtrLabel = (PFNGLGETOBJECTPTRLABELPROC_t)GetProcAddress((const GLubyte*)"glGetObjectPtrLabel");
	}

	inline GLvoid Load4_4Extensions()
	{
		glBufferStorage = (PFNGLBUFFERSTORAGEPROC_t)GetProcAddress((const GLubyte*)"glBufferStorage");
		glClearTexImage = (PFNGLCLEARTEXIMAGEPROC_t)GetProcAddress((const GLubyte*)"glClearTexImage");
		glClearTexSubImage = (PFNGLCLEARTEXSUBIMAGEPROC_t)GetProcAddress((const GLubyte*)"glClearTexSubImage");
		glBindBuffersBase = (PFNGLBINDBUFFERSBASEPROC_t)GetProcAddress((const GLubyte*)"glBindBuffersBase");
		glBindBuffersRange = (PFNGLBINDBUFFERSRANGEPROC_t)GetProcAddress((const GLubyte*)"glBindBuffersRange");
		glBindTextures = (PFNGLBINDTEXTURESPROC_t)GetProcAddress((const GLubyte*)"glBindTextures");
		glBindSamplers = (PFNGLBINDSAMPLERSPROC_t)GetProcAddress((const GLubyte*)"glBindSamplers");
		glBindImageTextures = (PFNGLBINDIMAGETEXTURESPROC_t)GetProcAddress((const GLubyte*)"glBindImageTextures");
		glBindVertexBuffers = (PFNGLBINDVERTEXBUFFERSPROC_t)GetProcAddress((const GLubyte*)"glBindVertexBuffers");
	}

	GLvoid InitializeGLVersion()
	{
		const GLubyte* VersionString = glGetString(GL_VERSION);

		glVersion_Major = VersionString[0] - '0';
		glVersion_Minor = VersionString[2] - '0';
	}

	GLvoid PrintErrorMessage(GLuint glVersion_Major, GLuint glVersion_Minor) const
	{
		printf("Error: OpenGL version %i.%i not supported. stopping here\n", glVersion_Major, glVersion_Minor);
	}

	void* GetProcAddress(const GLubyte* ProcName) const
	{
#if defined(_WIN32)
		return wglGetProcAddress((LPCTSTR)ProcName);
#endif

#if defined(__linux__)
		return glXGetProcAddress(ProcName);
#endif
	}
};

#endif