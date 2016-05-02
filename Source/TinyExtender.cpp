#include "TinyExtender.h"

namespace TinyExtender
{
	std::error_code make_error_code(error_t errorCode)
	{
		return std::error_code(static_cast<int>(errorCode), error_category::get());
	}

	GLuint glVersionMajor = 0;
	GLuint glVersionMinor = 0;

	//OpenGL 1.2 Extensions
	void(*glDrawRangeElements) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices) = nullptr;
	void(*glTexImage3D) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels) = nullptr;
	void(*glTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) = nullptr;
	void(*glCopyTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) = nullptr;

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

	//OpenGL 1.5 Extensions
	void(*glGenQueries) (GLsizei n, GLuint *ids) = nullptr;
	void(*glDeleteQueries) (GLsizei n, const GLuint *ids) = nullptr;
	GLboolean(*glIsQuery) (GLuint id) = nullptr;
	void(*glBeginQuery) (GLenum target, GLuint id) = nullptr;
	void(*glEndQuery) (GLenum target) = nullptr;
	void(*glGetQueryiv) (GLenum target, GLenum pname, GLint *params) = nullptr;
	void(*glGetQueryObjectiv) (GLuint id, GLenum pname, GLint *params) = nullptr;
	void(*glGetQueryObjectuiv) (GLuint id, GLenum pname, GLuint *params) = nullptr;
	void(*glBindBuffer) (GLenum target, GLuint buffer) = nullptr;
	void(*glDeleteBuffers) (GLsizei n, const GLuint *buffers) = nullptr;
	void(*glGenBuffers) (GLsizei n, GLuint *buffers) = nullptr;
	GLboolean(*glIsBuffer) (GLuint buffer) = nullptr;
	void(*glBufferData) (GLenum target, GLsizeiptr size, const void *data, GLenum usage) = nullptr;
	void(*glBufferSubData) (GLenum target, GLintptr offset, GLsizeiptr size, const void *data) = nullptr;
	void(*glGetBufferSubData) (GLenum target, GLintptr offset, GLsizeiptr size, void *data) = nullptr;
	void * (*glMapBuffer) (GLenum target, GLenum access) = nullptr;
	GLboolean(*glUnmapBuffer) (GLenum target) = nullptr;
	void(*glGetBufferParameteriv) (GLenum target, GLenum pname, GLint *params) = nullptr;
	void(*glGetBufferPointerv) (GLenum target, GLenum pname, void **params) = nullptr;

	//2.0 extensions
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

	//OpenGL 2.1 Extensions
	void(*glUniformMatrix2x3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	void(*glUniformMatrix3x2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	void(*glUniformMatrix2x4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	void(*glUniformMatrix4x2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	void(*glUniformMatrix3x4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;
	void(*glUniformMatrix4x3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) = nullptr;

	//3.0 extensions
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

	//OpenGL 3.2 Extensions
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

	//OpenGL 4.3 Extensions
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

	void Load1_2Extensions()
	{
		FetchProcAddress(glDrawRangeElements, "glDrawRangeElements");
		FetchProcAddress(glTexImage3D, "glTexImage3D");
		FetchProcAddress(glTexSubImage3D, "glTexSubImage3D");
		FetchProcAddress(glCopyTexSubImage3D, "glCopyTexSubImage3D");
	}

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

	void Load2_1Extensions()
	{
		FetchProcAddress(glUniformMatrix2x3fv, "glUniformMatrix2x3fv");
		FetchProcAddress(glUniformMatrix3x2fv, "glUniformMatrix3x2fv");
		FetchProcAddress(glUniformMatrix2x4fv, "glUniformMatrix2x4fv");
		FetchProcAddress(glUniformMatrix4x2fv, "glUniformMatrix4x2fv");
		FetchProcAddress(glUniformMatrix3x4fv, "glUniformMatrix3x4fv");
		FetchProcAddress(glUniformMatrix4x3fv, "glUniformMatrix4x3fv");
	}

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

		if (glVersionMajor > 2 || (glVersionMinor >= 0 && glVersionMajor >= 2))
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

		if (glVersionMajor > 3 || (glVersionMinor >= 0 && glVersionMajor >= 3))
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

		if (glVersionMajor > 4 || (glVersionMinor >= 0 && glVersionMajor >= 4))
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
			if (glVersionMajor > 2 || (glVersionMinor >= 0 && glVersionMajor >= 2))
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
			if (glVersionMajor > 3 || (glVersionMinor >= 0 && glVersionMajor >= 3))
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
			if (glVersionMajor > 4 || (glVersionMinor >= 0 && glVersionMajor >= 4))
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


}