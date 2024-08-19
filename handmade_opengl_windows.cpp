// 1.0 - 1.1 ONLY!
internal void*
windows_opengl_loadptr(HMODULE lib, const s8* function_name)
{
    void* result = 0;
    result = (void*)GetProcAddress(lib, function_name);
    if(!result)
    {
	OutputDebugStringA("couldn't load OpenGL funtion, 'GetProcAddress' failed!\n");
    }
    return(result);
}
// 1.2 - 4.6 ONLY! 
internal void*
windows_opengl_loadptr(s8* function_name)
{
    void* result = 0;
    result = (void*)wglGetProcAddress(function_name);
    if(!result)
    {
	OutputDebugStringA("couldn't load OpenGL funtion, 'wglGetProcAddress' failed!\n");
    }
    return(result);
}

internal void
windows_opengl_version_1(HMODULE lib)
{
    // 1.0 
    HH_GL_glCullFace		 = (PFNGLCULLFACEPROC)               windows_opengl_loadptr(lib, "glCullFace");
    HH_GL_glFrontFace		 = (PFNGLFRONTFACEPROC)              windows_opengl_loadptr(lib, "glFrontFace");
    HH_GL_glHint		 = (PFNGLHINTPROC)                   windows_opengl_loadptr(lib, "glHint");
    HH_GL_glLineWidth		 = (PFNGLLINEWIDTHPROC)              windows_opengl_loadptr(lib, "glLineWidth");
    HH_GL_glPointSize		 = (PFNGLPOINTSIZEPROC)              windows_opengl_loadptr(lib, "glPointSize");
    HH_GL_glPolygonMode		 = (PFNGLPOLYGONMODEPROC)            windows_opengl_loadptr(lib, "glPolygonMode");
    HH_GL_glScissor		 = (PFNGLSCISSORPROC)                windows_opengl_loadptr(lib, "glScissor");
    HH_GL_glTexParameterf		 = (PFNGLTEXPARAMETERFPROC)          windows_opengl_loadptr(lib, "glTexParameterf");
    HH_GL_glTexParameterfv	 = (PFNGLTEXPARAMETERFVPROC)         windows_opengl_loadptr(lib, "glTexParameterfv");
    HH_GL_glTexParameteri		 = (PFNGLTEXPARAMETERIPROC)          windows_opengl_loadptr(lib, "glTexParameteri");
    HH_GL_glTexParameteriv	 = (PFNGLTEXPARAMETERIVPROC)         windows_opengl_loadptr(lib, "glTexParameteriv");
    HH_GL_glTexImage1D		 = (PFNGLTEXIMAGE1DPROC)             windows_opengl_loadptr(lib, "glTexImage1D");
    HH_GL_glTexImage2D		 = (PFNGLTEXIMAGE2DPROC)             windows_opengl_loadptr(lib, "glTexImage2D");
    HH_GL_glDrawBuffer		 = (PFNGLDRAWBUFFERPROC)             windows_opengl_loadptr(lib, "glDrawBuffer");
    HH_GL_glClear			 = (PFNGLCLEARPROC)                  windows_opengl_loadptr(lib, "glClear");
    HH_GL_glClearColor		 = (PFNGLCLEARCOLORPROC)             windows_opengl_loadptr(lib, "glClearColor");
    HH_GL_glClearStencil		 = (PFNGLCLEARSTENCILPROC)           windows_opengl_loadptr(lib, "glClearStencil");
    HH_GL_glClearDepth		 = (PFNGLCLEARDEPTHPROC)             windows_opengl_loadptr(lib, "glClearDepth");
    HH_GL_glStencilMask		 = (PFNGLSTENCILMASKPROC)            windows_opengl_loadptr(lib, "glStencilMask");
    HH_GL_glColorMask		 = (PFNGLCOLORMASKPROC)              windows_opengl_loadptr(lib, "glColorMask");
    HH_GL_glDepthMask		 = (PFNGLDEPTHMASKPROC)              windows_opengl_loadptr(lib, "glDepthMask");
    HH_GL_glDisable		 = (PFNGLDISABLEPROC)                windows_opengl_loadptr(lib, "glDisable");
    HH_GL_glEnable		 = (PFNGLENABLEPROC)                 windows_opengl_loadptr(lib, "glEnable");
    HH_GL_glFinish		 = (PFNGLFINISHPROC)                 windows_opengl_loadptr(lib, "glFinish");
    HH_GL_glFlush			 = (PFNGLFLUSHPROC)                  windows_opengl_loadptr(lib, "glFlush");
    HH_GL_glBlendFunc		 = (PFNGLBLENDFUNCPROC)              windows_opengl_loadptr(lib, "glBlendFunc");
    HH_GL_glLogicOp		 = (PFNGLLOGICOPPROC)                windows_opengl_loadptr(lib, "glLogicOp");
    HH_GL_glStencilFunc		 = (PFNGLSTENCILFUNCPROC)            windows_opengl_loadptr(lib, "glStencilFunc");
    HH_GL_glStencilOp		 = (PFNGLSTENCILOPPROC)              windows_opengl_loadptr(lib, "glStencilOp");
    HH_GL_glDepthFunc		 = (PFNGLDEPTHFUNCPROC)              windows_opengl_loadptr(lib, "glDepthFunc");
    HH_GL_glPixelStoref		 = (PFNGLPIXELSTOREFPROC)            windows_opengl_loadptr(lib, "glPixelStoref");
    HH_GL_glPixelStorei		 = (PFNGLPIXELSTOREIPROC)            windows_opengl_loadptr(lib, "glPixelStorei");
    HH_GL_glReadBuffer		 = (PFNGLREADBUFFERPROC)             windows_opengl_loadptr(lib, "glReadBuffer");
    HH_GL_glReadPixels		 = (PFNGLREADPIXELSPROC)             windows_opengl_loadptr(lib, "glReadPixels");
    HH_GL_glGetBooleanv		 = (PFNGLGETBOOLEANVPROC)            windows_opengl_loadptr(lib, "glGetBooleanv");
    HH_GL_glGetDoublev		 = (PFNGLGETDOUBLEVPROC)             windows_opengl_loadptr(lib, "glGetDoublev");
    HH_GL_glGetError		 = (PFNGLGETERRORPROC)               windows_opengl_loadptr(lib, "glGetError");
    HH_GL_glGetFloatv		 = (PFNGLGETFLOATVPROC)              windows_opengl_loadptr(lib, "glGetFloatv");
    HH_GL_glGetIntegerv		 = (PFNGLGETINTEGERVPROC)            windows_opengl_loadptr(lib, "glGetIntegerv");
    HH_GL_glGetString		 = (PFNGLGETSTRINGPROC)              windows_opengl_loadptr(lib, "glGetString");
    HH_GL_glGetTexImage		 = (PFNGLGETTEXIMAGEPROC)            windows_opengl_loadptr(lib, "glGetTexImage");
    HH_GL_glGetTexParameterfv	 = (PFNGLGETTEXPARAMETERFVPROC)      windows_opengl_loadptr(lib, "glGetTexParameterfv");
    HH_GL_glGetTexParameteriv	 = (PFNGLGETTEXPARAMETERIVPROC)      windows_opengl_loadptr(lib, "glGetTexParameteriv");
    HH_GL_glGetTexLevelParameterfv = (PFNGLGETTEXLEVELPARAMETERFVPROC) windows_opengl_loadptr(lib, "glGetTexLevelParameterfv");
    HH_GL_glGetTexLevelParameteriv = (PFNGLGETTEXLEVELPARAMETERIVPROC) windows_opengl_loadptr(lib, "glGetTexLevelParameteriv");
    HH_GL_glIsEnabled		 = (PFNGLISENABLEDPROC)              windows_opengl_loadptr(lib, "glIsEnabled");
    HH_GL_glDepthRange		 = (PFNGLDEPTHRANGEPROC)             windows_opengl_loadptr(lib, "glDepthRange");
    HH_GL_glViewport		 = (PFNGLVIEWPORTPROC)               windows_opengl_loadptr(lib, "glViewport");

    // 1.1 
    HH_GL_glDrawArrays	    = (PFNGLDRAWARRAYSPROC)        windows_opengl_loadptr(lib, "glDrawArrays");
    HH_GL_glDrawElements	    = (PFNGLDRAWELEMENTSPROC)      windows_opengl_loadptr(lib, "glDrawElements");
    HH_GL_glPolygonOffset	    = (PFNGLPOLYGONOFFSETPROC)     windows_opengl_loadptr(lib, "glPolygonOffset");
    HH_GL_glCopyTexImage1D    = (PFNGLCOPYTEXIMAGE1DPROC)    windows_opengl_loadptr(lib, "glCopyTexImage1D");
    HH_GL_glCopyTexImage2D    = (PFNGLCOPYTEXIMAGE2DPROC)    windows_opengl_loadptr(lib, "glCopyTexImage2D");
    HH_GL_glCopyTexSubImage1D = (PFNGLCOPYTEXSUBIMAGE1DPROC) windows_opengl_loadptr(lib, "glCopyTexSubImage1D");
    HH_GL_glCopyTexSubImage2D = (PFNGLCOPYTEXSUBIMAGE2DPROC) windows_opengl_loadptr(lib, "glCopyTexSubImage2D");
    HH_GL_glTexSubImage1D	    = (PFNGLTEXSUBIMAGE1DPROC)     windows_opengl_loadptr(lib, "glTexSubImage1D");
    HH_GL_glTexSubImage2D	    = (PFNGLTEXSUBIMAGE2DPROC)     windows_opengl_loadptr(lib, "glTexSubImage2D");
    HH_GL_glBindTexture	    = (PFNGLBINDTEXTUREPROC)       windows_opengl_loadptr(lib, "glBindTexture");
    HH_GL_glDeleteTextures    = (PFNGLDELETETEXTURESPROC)    windows_opengl_loadptr(lib, "glDeleteTextures");
    HH_GL_glGenTextures	    = (PFNGLGENTEXTURESPROC)       windows_opengl_loadptr(lib, "glGenTextures");
    HH_GL_glIsTexture	    = (PFNGLISTEXTUREPROC)         windows_opengl_loadptr(lib, "glIsTexture");

    // 1.2
    HH_GL_glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC) windows_opengl_loadptr("glDrawRangeElements");
    HH_GL_glTexImage3D        = (PFNGLTEXIMAGE3DPROC)        windows_opengl_loadptr("glTexImage3D");
    HH_GL_glTexSubImage3D     = (PFNGLTEXSUBIMAGE3DPROC)     windows_opengl_loadptr("glTexSubImage3D");
    HH_GL_glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC) windows_opengl_loadptr("glCopyTexSubImage3D");

    // 1.3 
    HH_GL_glActiveTexture		  = (PFNGLACTIVETEXTUREPROC)           windows_opengl_loadptr("glActiveTexture");
    HH_GL_glSampleCoverage	  = (PFNGLSAHH_GLLECOVERAGEPROC)          windows_opengl_loadptr("glSampleCoverage");
    HH_GL_glCompressedTexImage3D	  = (PFNGLCOHH_GLRESSEDTEXIMAGE3DPROC)    windows_opengl_loadptr("glCompressedTexImage3D");
    HH_GL_glCompressedTexImage2D	  = (PFNGLCOHH_GLRESSEDTEXIMAGE2DPROC)    windows_opengl_loadptr("glCompressedTexImage2D");
    HH_GL_glCompressedTexImage1D	  = (PFNGLCOHH_GLRESSEDTEXIMAGE1DPROC)    windows_opengl_loadptr("glCompressedTexImage1D");
    HH_GL_glCompressedTexSubImage3D = (PFNGLCOHH_GLRESSEDTEXSUBIMAGE3DPROC) windows_opengl_loadptr("glCompressedTexSubImage3D");
    HH_GL_glCompressedTexSubImage2D = (PFNGLCOHH_GLRESSEDTEXSUBIMAGE2DPROC) windows_opengl_loadptr("glCompressedTexSubImage2D");
    HH_GL_glCompressedTexSubImage1D = (PFNGLCOHH_GLRESSEDTEXSUBIMAGE1DPROC) windows_opengl_loadptr("glCompressedTexSubImage1D");
    HH_GL_glGetCompressedTexImage	  = (PFNGLGETCOHH_GLRESSEDTEXIMAGEPROC)   windows_opengl_loadptr("glGetCompressedTexImage");
    
    // 1.4 
    HH_GL_glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC) windows_opengl_loadptr("glBlendFuncSeparate");
    HH_GL_glMultiDrawArrays   = (PFNGLMULTIDRAWARRAYSPROC)   windows_opengl_loadptr("glMultiDrawArrays");
    HH_GL_glMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC) windows_opengl_loadptr("glMultiDrawElements");
    HH_GL_glPointParameterf   = (PFNGLPOINTPARAMETERFPROC)   windows_opengl_loadptr("glPointParameterf");
    HH_GL_glPointParameterfv  = (PFNGLPOINTPARAMETERFVPROC)  windows_opengl_loadptr("glPointParameterfv");
    HH_GL_glPointParameteri   = (PFNGLPOINTPARAMETERIPROC)   windows_opengl_loadptr("glPointParameteri");
    HH_GL_glPointParameteriv  = (PFNGLPOINTPARAMETERIVPROC)  windows_opengl_loadptr("glPointParameteriv");
    HH_GL_glBlendColor	    = (PFNGLBLENDCOLORPROC)        windows_opengl_loadptr("glBlendColor");
    HH_GL_glBlendEquation	    = (PFNGLBLENDEQUATIONPROC)     windows_opengl_loadptr("glBlendEquation");
    
    // 1.5
    HH_GL_glGenQueries	       = (PFNGLGENQUERIESPROC)           windows_opengl_loadptr("glGenQueries");
    HH_GL_glDeleteQueries	       = (PFNGLDELETEQUERIESPROC)        windows_opengl_loadptr("glDeleteQueries");
    HH_GL_glIsQuery	       = (PFNGLISQUERYPROC)              windows_opengl_loadptr("glIsQuery");
    HH_GL_glBeginQuery	       = (PFNGLBEGINQUERYPROC)           windows_opengl_loadptr("glBeginQuery");
    HH_GL_glEndQuery	       = (PFNGLENDQUERYPROC)             windows_opengl_loadptr("glEndQuery");
    HH_GL_glGetQueryiv	       = (PFNGLGETQUERYIVPROC)           windows_opengl_loadptr("glGetQueryiv");
    HH_GL_glGetQueryObjectiv     = (PFNGLGETQUERYOBJECTIVPROC)     windows_opengl_loadptr("glGetQueryObjectiv");
    HH_GL_glGetQueryObjectuiv    = (PFNGLGETQUERYOBJECTUIVPROC)    windows_opengl_loadptr("glGetQueryObjectuiv");
    HH_GL_glBindBuffer	       = (PFNGLBINDBUFFERPROC)           windows_opengl_loadptr("glBindBuffer");
    HH_GL_glDeleteBuffers	       = (PFNGLDELETEBUFFERSPROC)        windows_opengl_loadptr("glDeleteBuffers");
    HH_GL_glGenBuffers	       = (PFNGLGENBUFFERSPROC)           windows_opengl_loadptr("glGenBuffers");
    HH_GL_glIsBuffer	       = (PFNGLISBUFFERPROC)             windows_opengl_loadptr("glIsBuffer");
    HH_GL_glBufferData	       = (PFNGLBUFFERDATAPROC)           windows_opengl_loadptr("glBufferData");
    HH_GL_glBufferSubData	       = (PFNGLBUFFERSUBDATAPROC)        windows_opengl_loadptr("glBufferSubData");
    HH_GL_glGetBufferSubData     = (PFNGLGETBUFFERSUBDATAPROC)     windows_opengl_loadptr("glGetBufferSubData");
    HH_GL_glMapBuffer	       = (PFNGLMAPBUFFERPROC)            windows_opengl_loadptr("glMapBuffer");
    HH_GL_glUnmapBuffer	       = (PFNGLUNMAPBUFFERPROC)          windows_opengl_loadptr("glUnmapBuffer");
    HH_GL_glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC) windows_opengl_loadptr("glGetBufferParameteriv");
    HH_GL_glGetBufferPointerv    = (PFNGLGETBUFFERPOINTERVPROC)    windows_opengl_loadptr("glGetBufferPointerv");
}
internal void
windows_opengl_version_2()
{
    // 2.0 
    HH_GL_glBlendEquationSeparate	   = (PFNGLBLENDEQUATIONSEPARATEPROC) 	 windows_opengl_loadptr("glBlendEquationSeparate");
    HH_GL_glDrawBuffers		   = (PFNGLDRAWBUFFERSPROC)		 windows_opengl_loadptr("glDrawBuffers");
    HH_GL_glStencilOpSeparate	   = (PFNGLSTENCILOPSEPARATEPROC)	 windows_opengl_loadptr("glStencilOpSeparate");
    HH_GL_glStencilFuncSeparate	   = (PFNGLSTENCILFUNCSEPARATEPROC)	 windows_opengl_loadptr("glStencilFuncSeparate");
    HH_GL_glStencilMaskSeparate	   = (PFNGLSTENCILMASKSEPARATEPROC)	 windows_opengl_loadptr("glStencilMaskSeparate");
    HH_GL_glAttachShader		   = (PFNGLATTACHSHADERPROC)		 windows_opengl_loadptr("glAttachShader");
    HH_GL_glBindAttribLocation	   = (PFNGLBINDATTRIBLOCATIONPROC)	 windows_opengl_loadptr("glBindAttribLocation");
    HH_GL_glCompileShader		   = (PFNGLCOHH_GLILESHADERPROC)		 windows_opengl_loadptr("glCompileShader");
    HH_GL_glCreateProgram		   = (PFNGLCREATEPROGRAHH_GLROC)		 windows_opengl_loadptr("glCreateProgram");
    HH_GL_glCreateShader		   = (PFNGLCREATESHADERPROC)		 windows_opengl_loadptr("glCreateShader");
    HH_GL_glDeleteProgram		   = (PFNGLDELETEPROGRAHH_GLROC)		 windows_opengl_loadptr("glDeleteProgram");
    HH_GL_glDeleteShader		   = (PFNGLDELETESHADERPROC)		 windows_opengl_loadptr("glDeleteShader");
    HH_GL_glDetachShader		   = (PFNGLDETACHSHADERPROC)		 windows_opengl_loadptr("glDetachShader");
    HH_GL_glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC) windows_opengl_loadptr("glDisableVertexAttribArray");
    HH_GL_glEnableVertexAttribArray  = (PFNGLENABLEVERTEXATTRIBARRAYPROC)	 windows_opengl_loadptr("glEnableVertexAttribArray");
    HH_GL_glGetActiveAttrib	   = (PFNGLGETACTIVEATTRIBPROC)		 windows_opengl_loadptr("glGetActiveAttrib");
    HH_GL_glGetActiveUniform	   = (PFNGLGETACTIVEUNIFORHH_GLROC)	 windows_opengl_loadptr("glGetActiveUniform");
    HH_GL_glGetAttachedShaders	   = (PFNGLGETATTACHEDSHADERSPROC)	 windows_opengl_loadptr("glGetAttachedShaders");
    HH_GL_glGetAttribLocation	   = (PFNGLGETATTRIBLOCATIONPROC)	 windows_opengl_loadptr("glGetAttribLocation");
    HH_GL_glGetProgramiv		   = (PFNGLGETPROGRAMIVPROC)		 windows_opengl_loadptr("glGetProgramiv");
    HH_GL_glGetProgramInfoLog	   = (PFNGLGETPROGRAMINFOLOGPROC)	 windows_opengl_loadptr("glGetProgramInfoLog");
    HH_GL_glGetShaderiv		   = (PFNGLGETSHADERIVPROC)		 windows_opengl_loadptr("glGetShaderiv");
    HH_GL_glGetShaderInfoLog	   = (PFNGLGETSHADERINFOLOGPROC)	 windows_opengl_loadptr("glGetShaderInfoLog");
    HH_GL_glGetShaderSource	   = (PFNGLGETSHADERSOURCEPROC)		 windows_opengl_loadptr("glGetShaderSource");
    HH_GL_glGetUniformLocation	   = (PFNGLGETUNIFORMLOCATIONPROC)	 windows_opengl_loadptr("glGetUniformLocation");
    HH_GL_glGetUniformfv		   = (PFNGLGETUNIFORMFVPROC)		 windows_opengl_loadptr("glGetUniformfv");
    HH_GL_glGetUniformiv		   = (PFNGLGETUNIFORMIVPROC)		 windows_opengl_loadptr("glGetUniformiv");
    HH_GL_glGetVertexAttribdv	   = (PFNGLGETVERTEXATTRIBDVPROC)	 windows_opengl_loadptr("glGetVertexAttribdv");
    HH_GL_glGetVertexAttribfv	   = (PFNGLGETVERTEXATTRIBFVPROC)	 windows_opengl_loadptr("glGetVertexAttribfv");
    HH_GL_glGetVertexAttribiv	   = (PFNGLGETVERTEXATTRIBIVPROC)	 windows_opengl_loadptr("glGetVertexAttribiv");
    HH_GL_glGetVertexAttribPointerv  = (PFNGLGETVERTEXATTRIBPOINTERVPROC)	 windows_opengl_loadptr("glGetVertexAttribPointerv");
    HH_GL_glIsProgram		   = (PFNGLISPROGRAHH_GLROC)		 windows_opengl_loadptr("glIsProgram");
    HH_GL_glIsShader		   = (PFNGLISSHADERPROC)		 windows_opengl_loadptr("glIsShader");
    HH_GL_glLinkProgram		   = (PFNGLLINKPROGRAHH_GLROC)		 windows_opengl_loadptr("glLinkProgram");
    HH_GL_glShaderSource		   = (PFNGLSHADERSOURCEPROC)		 windows_opengl_loadptr("glShaderSource");
    HH_GL_glUseProgram		   = (PFNGLUSEPROGRAHH_GLROC)		 windows_opengl_loadptr("glUseProgram");
    HH_GL_glUniform1f		   = (PFNGLUNIFORM1FPROC)		 windows_opengl_loadptr("glUniform1f");
    HH_GL_glUniform2f		   = (PFNGLUNIFORM2FPROC)		 windows_opengl_loadptr("glUniform2f");
    HH_GL_glUniform3f		   = (PFNGLUNIFORM3FPROC)		 windows_opengl_loadptr("glUniform3f");
    HH_GL_glUniform4f		   = (PFNGLUNIFORM4FPROC)		 windows_opengl_loadptr("glUniform4f");
    HH_GL_glUniform1i		   = (PFNGLUNIFORM1IPROC)		 windows_opengl_loadptr("glUniform1i");
    HH_GL_glUniform2i		   = (PFNGLUNIFORM2IPROC)		 windows_opengl_loadptr("glUniform2i");
    HH_GL_glUniform3i		   = (PFNGLUNIFORM3IPROC)		 windows_opengl_loadptr("glUniform3i");
    HH_GL_glUniform4i		   = (PFNGLUNIFORM4IPROC)		 windows_opengl_loadptr("glUniform4i");
    HH_GL_glUniform1fv		   = (PFNGLUNIFORM1FVPROC)		 windows_opengl_loadptr("glUniform1fv");
    HH_GL_glUniform2fv		   = (PFNGLUNIFORM2FVPROC)		 windows_opengl_loadptr("glUniform2fv");
    HH_GL_glUniform3fv		   = (PFNGLUNIFORM3FVPROC)		 windows_opengl_loadptr("glUniform3fv");
    HH_GL_glUniform4fv		   = (PFNGLUNIFORM4FVPROC)		 windows_opengl_loadptr("glUniform4fv");
    HH_GL_glUniform1iv		   = (PFNGLUNIFORM1IVPROC)		 windows_opengl_loadptr("glUniform1iv");
    HH_GL_glUniform2iv		   = (PFNGLUNIFORM2IVPROC)		 windows_opengl_loadptr("glUniform2iv");
    HH_GL_glUniform3iv		   = (PFNGLUNIFORM3IVPROC)		 windows_opengl_loadptr("glUniform3iv");
    HH_GL_glUniform4iv		   = (PFNGLUNIFORM4IVPROC)		 windows_opengl_loadptr("glUniform4iv");
    HH_GL_glUniformMatrix2fv	   = (PFNGLUNIFORMMATRIX2FVPROC)	 windows_opengl_loadptr("glUniformMatrix2fv");
    HH_GL_glUniformMatrix3fv	   = (PFNGLUNIFORMMATRIX3FVPROC)	 windows_opengl_loadptr("glUniformMatrix3fv");
    HH_GL_glUniformMatrix4fv	   = (PFNGLUNIFORMMATRIX4FVPROC)	 windows_opengl_loadptr("glUniformMatrix4fv");
    HH_GL_glValidateProgram	   = (PFNGLVALIDATEPROGRAHH_GLROC)		 windows_opengl_loadptr("glValidateProgram");
    HH_GL_glVertexAttrib1d	   = (PFNGLVERTEXATTRIB1DPROC)		 windows_opengl_loadptr("glVertexAttrib1d");
    HH_GL_glVertexAttrib1dv	   = (PFNGLVERTEXATTRIB1DVPROC)		 windows_opengl_loadptr("glVertexAttrib1dv");
    HH_GL_glVertexAttrib1f	   = (PFNGLVERTEXATTRIB1FPROC)		 windows_opengl_loadptr("glVertexAttrib1f");
    HH_GL_glVertexAttrib1fv	   = (PFNGLVERTEXATTRIB1FVPROC)		 windows_opengl_loadptr("glVertexAttrib1fv");
    HH_GL_glVertexAttrib1s	   = (PFNGLVERTEXATTRIB1SPROC)		 windows_opengl_loadptr("glVertexAttrib1s");
    HH_GL_glVertexAttrib1sv	   = (PFNGLVERTEXATTRIB1SVPROC)		 windows_opengl_loadptr("glVertexAttrib1sv");
    HH_GL_glVertexAttrib2d	   = (PFNGLVERTEXATTRIB2DPROC)		 windows_opengl_loadptr("glVertexAttrib2d");
    HH_GL_glVertexAttrib2dv	   = (PFNGLVERTEXATTRIB2DVPROC)		 windows_opengl_loadptr("glVertexAttrib2dv");
    HH_GL_glVertexAttrib2f	   = (PFNGLVERTEXATTRIB2FPROC)		 windows_opengl_loadptr("glVertexAttrib2f");
    HH_GL_glVertexAttrib2fv	   = (PFNGLVERTEXATTRIB2FVPROC)		 windows_opengl_loadptr("glVertexAttrib2fv");
    HH_GL_glVertexAttrib2s	   = (PFNGLVERTEXATTRIB2SPROC)		 windows_opengl_loadptr("glVertexAttrib2s");
    HH_GL_glVertexAttrib2sv	   = (PFNGLVERTEXATTRIB2SVPROC)		 windows_opengl_loadptr("glVertexAttrib2sv");
    HH_GL_glVertexAttrib3d	   = (PFNGLVERTEXATTRIB3DPROC)		 windows_opengl_loadptr("glVertexAttrib3d");
    HH_GL_glVertexAttrib3dv	   = (PFNGLVERTEXATTRIB3DVPROC)		 windows_opengl_loadptr("glVertexAttrib3dv");
    HH_GL_glVertexAttrib3f	   = (PFNGLVERTEXATTRIB3FPROC)		 windows_opengl_loadptr("glVertexAttrib3f");
    HH_GL_glVertexAttrib3fv	   = (PFNGLVERTEXATTRIB3FVPROC)		 windows_opengl_loadptr("glVertexAttrib3fv");
    HH_GL_glVertexAttrib3s	   = (PFNGLVERTEXATTRIB3SPROC)		 windows_opengl_loadptr("glVertexAttrib3s");
    HH_GL_glVertexAttrib3sv	   = (PFNGLVERTEXATTRIB3SVPROC)		 windows_opengl_loadptr("glVertexAttrib3sv");
    HH_GL_glVertexAttrib4Nbv	   = (PFNGLVERTEXATTRIB4NBVPROC)	 windows_opengl_loadptr("glVertexAttrib4Nbv");
    HH_GL_glVertexAttrib4Niv	   = (PFNGLVERTEXATTRIB4NIVPROC)	 windows_opengl_loadptr("glVertexAttrib4Niv");
    HH_GL_glVertexAttrib4Nsv	   = (PFNGLVERTEXATTRIB4NSVPROC)	 windows_opengl_loadptr("glVertexAttrib4Nsv");
    HH_GL_glVertexAttrib4Nub	   = (PFNGLVERTEXATTRIB4NUBPROC)	 windows_opengl_loadptr("glVertexAttrib4Nub");
    HH_GL_glVertexAttrib4Nubv	   = (PFNGLVERTEXATTRIB4NUBVPROC)	 windows_opengl_loadptr("glVertexAttrib4Nubv");
    HH_GL_glVertexAttrib4Nuiv	   = (PFNGLVERTEXATTRIB4NUIVPROC)	 windows_opengl_loadptr("glVertexAttrib4Nuiv");
    HH_GL_glVertexAttrib4Nusv	   = (PFNGLVERTEXATTRIB4NUSVPROC)	 windows_opengl_loadptr("glVertexAttrib4Nusv");
    HH_GL_glVertexAttrib4bv	   = (PFNGLVERTEXATTRIB4BVPROC)		 windows_opengl_loadptr("glVertexAttrib4bv");
    HH_GL_glVertexAttrib4d	   = (PFNGLVERTEXATTRIB4DPROC)		 windows_opengl_loadptr("glVertexAttrib4d");
    HH_GL_glVertexAttrib4dv	   = (PFNGLVERTEXATTRIB4DVPROC)		 windows_opengl_loadptr("glVertexAttrib4dv");
    HH_GL_glVertexAttrib4f	   = (PFNGLVERTEXATTRIB4FPROC)		 windows_opengl_loadptr("glVertexAttrib4f");
    HH_GL_glVertexAttrib4fv	   = (PFNGLVERTEXATTRIB4FVPROC)		 windows_opengl_loadptr("glVertexAttrib4fv");
    HH_GL_glVertexAttrib4iv	   = (PFNGLVERTEXATTRIB4IVPROC)		 windows_opengl_loadptr("glVertexAttrib4iv");
    HH_GL_glVertexAttrib4s	   = (PFNGLVERTEXATTRIB4SPROC)		 windows_opengl_loadptr("glVertexAttrib4s");
    HH_GL_glVertexAttrib4sv	   = (PFNGLVERTEXATTRIB4SVPROC)		 windows_opengl_loadptr("glVertexAttrib4sv");
    HH_GL_glVertexAttrib4ubv	   = (PFNGLVERTEXATTRIB4UBVPROC)	 windows_opengl_loadptr("glVertexAttrib4ubv");
    HH_GL_glVertexAttrib4uiv	   = (PFNGLVERTEXATTRIB4UIVPROC)	 windows_opengl_loadptr("glVertexAttrib4uiv");
    HH_GL_glVertexAttrib4usv	   = (PFNGLVERTEXATTRIB4USVPROC)	 windows_opengl_loadptr("glVertexAttrib4usv");
    HH_GL_glVertexAttribPointer	   = (PFNGLVERTEXATTRIBPOINTERPROC)	 windows_opengl_loadptr("glVertexAttribPointer");
    
    // 2.1 
    HH_GL_glUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC) windows_opengl_loadptr("glUniformMatrix2x3fv");
    HH_GL_glUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC) windows_opengl_loadptr("glUniformMatrix3x2fv");
    HH_GL_glUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC) windows_opengl_loadptr("glUniformMatrix2x4fv");
    HH_GL_glUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC) windows_opengl_loadptr("glUniformMatrix4x2fv");
    HH_GL_glUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC) windows_opengl_loadptr("glUniformMatrix3x4fv");
    HH_GL_glUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC) windows_opengl_loadptr("glUniformMatrix4x3fv");   
}
internal void
windows_opengl_version_3()
{
    // 3.0 
    HH_GL_glColorMaski			      = (PFNGLCOLORMASKIPROC)				windows_opengl_loadptr("glColorMaski");
    HH_GL_glGetBooleani_v			      = (PFNGLGETBOOLEANI_VPROC)			windows_opengl_loadptr("glGetBooleani_v");
    HH_GL_glGetIntegeri_v			      = (PFNGLGETINTEGERI_VPROC)			windows_opengl_loadptr("glGetIntegeri_v");
    HH_GL_glEnablei			      = (PFNGLENABLEIPROC)				windows_opengl_loadptr("glEnablei");
    HH_GL_glDisablei			      = (PFNGLDISABLEIPROC)				windows_opengl_loadptr("glDisablei");
    HH_GL_glIsEnabledi			      = (PFNGLISENABLEDIPROC)				windows_opengl_loadptr("glIsEnabledi");
    HH_GL_glBeginTransformFeedback	      = (PFNGLBEGINTRANSFORMFEEDBACKPROC)		windows_opengl_loadptr("glBeginTransformFeedback");
    HH_GL_glEndTransformFeedback		      = (PFNGLENDTRANSFORMFEEDBACKPROC)			windows_opengl_loadptr("glEndTransformFeedback");
    HH_GL_glBindBufferRange		      = (PFNGLBINDBUFFERRANGEPROC)			windows_opengl_loadptr("glBindBufferRange");
    HH_GL_glBindBufferBase		      = (PFNGLBINDBUFFERBASEPROC)			windows_opengl_loadptr("glBindBufferBase");
    HH_GL_glTransformFeedbackVaryings	      = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC)		windows_opengl_loadptr("glTransformFeedbackVaryings");
    HH_GL_glGetTransformFeedbackVarying	      = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)		windows_opengl_loadptr("glGetTransformFeedbackVarying");
    HH_GL_glClampColor			      = (PFNGLCLAHH_GLCOLORPROC)				windows_opengl_loadptr("glClampColor");
    HH_GL_glBeginConditionalRender	      = (PFNGLBEGINCONDITIONALRENDERPROC)		windows_opengl_loadptr("glBeginConditionalRender");
    HH_GL_glEndConditionalRender		      = (PFNGLENDCONDITIONALRENDERPROC)			windows_opengl_loadptr("glEndConditionalRender");
    HH_GL_glVertexAttribIPointer		      = (PFNGLVERTEXATTRIBIPOINTERPROC)			windows_opengl_loadptr("glVertexAttribIPointer");
    HH_GL_glGetVertexAttribIiv		      = (PFNGLGETVERTEXATTRIBIIVPROC)			windows_opengl_loadptr("glGetVertexAttribIiv");
    HH_GL_glGetVertexAttribIuiv		      = (PFNGLGETVERTEXATTRIBIUIVPROC)			windows_opengl_loadptr("glGetVertexAttribIuiv");
    HH_GL_glVertexAttribI1i		      = (PFNGLVERTEXATTRIBI1IPROC)			windows_opengl_loadptr("glVertexAttribI1i");
    HH_GL_glVertexAttribI2i		      = (PFNGLVERTEXATTRIBI2IPROC)			windows_opengl_loadptr("glVertexAttribI2i");
    HH_GL_glVertexAttribI3i		      = (PFNGLVERTEXATTRIBI3IPROC)			windows_opengl_loadptr("glVertexAttribI3i");
    HH_GL_glVertexAttribI4i		      = (PFNGLVERTEXATTRIBI4IPROC)			windows_opengl_loadptr("glVertexAttribI4i");
    HH_GL_glVertexAttribI1ui		      = (PFNGLVERTEXATTRIBI1UIPROC)			windows_opengl_loadptr("glVertexAttribI1ui");
    HH_GL_glVertexAttribI2ui		      = (PFNGLVERTEXATTRIBI2UIPROC)			windows_opengl_loadptr("glVertexAttribI2ui");
    HH_GL_glVertexAttribI3ui		      = (PFNGLVERTEXATTRIBI3UIPROC)			windows_opengl_loadptr("glVertexAttribI3ui");
    HH_GL_glVertexAttribI4ui		      = (PFNGLVERTEXATTRIBI4UIPROC)			windows_opengl_loadptr("glVertexAttribI4ui");
    HH_GL_glVertexAttribI1iv		      = (PFNGLVERTEXATTRIBI1IVPROC)			windows_opengl_loadptr("glVertexAttribI1iv");
    HH_GL_glVertexAttribI2iv		      = (PFNGLVERTEXATTRIBI2IVPROC)			windows_opengl_loadptr("glVertexAttribI2iv");
    HH_GL_glVertexAttribI3iv		      = (PFNGLVERTEXATTRIBI3IVPROC)			windows_opengl_loadptr("glVertexAttribI3iv");
    HH_GL_glVertexAttribI4iv		      = (PFNGLVERTEXATTRIBI4IVPROC)			windows_opengl_loadptr("glVertexAttribI4iv");
    HH_GL_glVertexAttribI1uiv		      = (PFNGLVERTEXATTRIBI1UIVPROC)			windows_opengl_loadptr("glVertexAttribI1uiv");
    HH_GL_glVertexAttribI2uiv		      = (PFNGLVERTEXATTRIBI2UIVPROC)			windows_opengl_loadptr("glVertexAttribI2uiv");
    HH_GL_glVertexAttribI3uiv		      = (PFNGLVERTEXATTRIBI3UIVPROC)			windows_opengl_loadptr("glVertexAttribI3uiv");
    HH_GL_glVertexAttribI4uiv		      = (PFNGLVERTEXATTRIBI4UIVPROC)			windows_opengl_loadptr("glVertexAttribI4uiv");
    HH_GL_glVertexAttribI4bv		      = (PFNGLVERTEXATTRIBI4BVPROC)			windows_opengl_loadptr("glVertexAttribI4bv");
    HH_GL_glVertexAttribI4sv		      = (PFNGLVERTEXATTRIBI4SVPROC)			windows_opengl_loadptr("glVertexAttribI4sv");
    HH_GL_glVertexAttribI4ubv		      = (PFNGLVERTEXATTRIBI4UBVPROC)			windows_opengl_loadptr("glVertexAttribI4ubv");
    HH_GL_glVertexAttribI4usv		      = (PFNGLVERTEXATTRIBI4USVPROC)			windows_opengl_loadptr("glVertexAttribI4usv");
    HH_GL_glGetUniformuiv			      = (PFNGLGETUNIFORMUIVPROC)			windows_opengl_loadptr("glGetUniformuiv");
    HH_GL_glBindFragDataLocation		      = (PFNGLBINDFRAGDATALOCATIONPROC)			windows_opengl_loadptr("glBindFragDataLocation");
    HH_GL_glGetFragDataLocation		      = (PFNGLGETFRAGDATALOCATIONPROC)			windows_opengl_loadptr("glGetFragDataLocation");
    HH_GL_glUniform1ui			      = (PFNGLUNIFORM1UIPROC)				windows_opengl_loadptr("glUniform1ui");
    HH_GL_glUniform2ui			      = (PFNGLUNIFORM2UIPROC)				windows_opengl_loadptr("glUniform2ui");
    HH_GL_glUniform3ui			      = (PFNGLUNIFORM3UIPROC)				windows_opengl_loadptr("glUniform3ui");
    HH_GL_glUniform4ui			      = (PFNGLUNIFORM4UIPROC)				windows_opengl_loadptr("glUniform4ui");
    HH_GL_glUniform1uiv			      = (PFNGLUNIFORM1UIVPROC)				windows_opengl_loadptr("glUniform1uiv");
    HH_GL_glUniform2uiv			      = (PFNGLUNIFORM2UIVPROC)				windows_opengl_loadptr("glUniform2uiv");
    HH_GL_glUniform3uiv			      = (PFNGLUNIFORM3UIVPROC)				windows_opengl_loadptr("glUniform3uiv");
    HH_GL_glUniform4uiv			      = (PFNGLUNIFORM4UIVPROC)				windows_opengl_loadptr("glUniform4uiv");
    HH_GL_glTexParameterIiv		      = (PFNGLTEXPARAMETERIIVPROC)			windows_opengl_loadptr("glTexParameterIiv");
    HH_GL_glTexParameterIuiv		      = (PFNGLTEXPARAMETERIUIVPROC)			windows_opengl_loadptr("glTexParameterIuiv");
    HH_GL_glGetTexParameterIiv		      = (PFNGLGETTEXPARAMETERIIVPROC)			windows_opengl_loadptr("glGetTexParameterIiv");
    HH_GL_glGetTexParameterIuiv		      = (PFNGLGETTEXPARAMETERIUIVPROC)			windows_opengl_loadptr("glGetTexParameterIuiv");
    HH_GL_glClearBufferiv			      = (PFNGLCLEARBUFFERIVPROC)			windows_opengl_loadptr("glClearBufferiv");
    HH_GL_glClearBufferuiv		      = (PFNGLCLEARBUFFERUIVPROC)			windows_opengl_loadptr("glClearBufferuiv");
    HH_GL_glClearBufferfv			      = (PFNGLCLEARBUFFERFVPROC)			windows_opengl_loadptr("glClearBufferfv");
    HH_GL_glClearBufferfi			      = (PFNGLCLEARBUFFERFIPROC)			windows_opengl_loadptr("glClearBufferfi");
    HH_GL_glGetStringi			      = (PFNGLGETSTRINGIPROC)				windows_opengl_loadptr("glGetStringi");
    HH_GL_glIsRenderbuffer		      = (PFNGLISRENDERBUFFERPROC)			windows_opengl_loadptr("glIsRenderbuffer");
    HH_GL_glBindRenderbuffer		      = (PFNGLBINDRENDERBUFFERPROC)			windows_opengl_loadptr("glBindRenderbuffer");
    HH_GL_glDeleteRenderbuffers		      = (PFNGLDELETERENDERBUFFERSPROC)			windows_opengl_loadptr("glDeleteRenderbuffers");
    HH_GL_glGenRenderbuffers		      = (PFNGLGENRENDERBUFFERSPROC)			windows_opengl_loadptr("glGenRenderbuffers");
    HH_GL_glRenderbufferStorage		      = (PFNGLRENDERBUFFERSTORAGEPROC)			windows_opengl_loadptr("glRenderbufferStorage");
    HH_GL_glGetRenderbufferParameteriv	      = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)		windows_opengl_loadptr("glGetRenderbufferParameteriv");
    HH_GL_glIsFramebuffer			      = (PFNGLISFRAMEBUFFERPROC)			windows_opengl_loadptr("glIsFramebuffer");
    HH_GL_glBindFramebuffer		      = (PFNGLBINDFRAMEBUFFERPROC)			windows_opengl_loadptr("glBindFramebuffer");
    HH_GL_glDeleteFramebuffers		      = (PFNGLDELETEFRAMEBUFFERSPROC)			windows_opengl_loadptr("glDeleteFramebuffers");
    HH_GL_glGenFramebuffers		      = (PFNGLGENFRAMEBUFFERSPROC)			windows_opengl_loadptr("glGenFramebuffers");
    HH_GL_glCheckFramebufferStatus	      = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)		windows_opengl_loadptr("glCheckFramebufferStatus");
    HH_GL_glFramebufferTexture1D		      = (PFNGLFRAMEBUFFERTEXTURE1DPROC)			windows_opengl_loadptr("glFramebufferTexture1D");
    HH_GL_glFramebufferTexture2D		      = (PFNGLFRAMEBUFFERTEXTURE2DPROC)			windows_opengl_loadptr("glFramebufferTexture2D");
    HH_GL_glFramebufferTexture3D		      = (PFNGLFRAMEBUFFERTEXTURE3DPROC)			windows_opengl_loadptr("glFramebufferTexture3D");
    HH_GL_glFramebufferRenderbuffer	      = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)		windows_opengl_loadptr("glFramebufferRenderbuffer");
    HH_GL_glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)	windows_opengl_loadptr("glGetFramebufferAttachmentParameteriv");
    HH_GL_glGenerateMipmap		      = (PFNGLGENERATEMIPMAPPROC)			windows_opengl_loadptr("glGenerateMipmap");
    HH_GL_glBlitFramebuffer		      = (PFNGLBLITFRAMEBUFFERPROC)			windows_opengl_loadptr("glBlitFramebuffer");
    HH_GL_glRenderbufferStorageMultisample      = (PFNGLRENDERBUFFERSTORAGEMULTISAHH_GLLEPROC)	windows_opengl_loadptr("glRenderbufferStorageMultisample");
    HH_GL_glFramebufferTextureLayer	      = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)		windows_opengl_loadptr("glFramebufferTextureLayer");
    HH_GL_glMapBufferRange		      = (PFNGLMAPBUFFERRANGEPROC)			windows_opengl_loadptr("glMapBufferRange");
    HH_GL_glFlushMappedBufferRange	      = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)		windows_opengl_loadptr("glFlushMappedBufferRange");
    HH_GL_glBindVertexArray		      = (PFNGLBINDVERTEXARRAYPROC)			windows_opengl_loadptr("glBindVertexArray");
    HH_GL_glDeleteVertexArrays		      = (PFNGLDELETEVERTEXARRAYSPROC)			windows_opengl_loadptr("glDeleteVertexArrays");
    HH_GL_glGenVertexArrays		      = (PFNGLGENVERTEXARRAYSPROC)			windows_opengl_loadptr("glGenVertexArrays");
    HH_GL_glIsVertexArray			      = (PFNGLISVERTEXARRAYPROC)			windows_opengl_loadptr("glIsVertexArray");
    
    // 3.1 
    HH_GL_glDrawArraysInstanced	    = (PFNGLDRAWARRAYSINSTANCEDPROC)	   windows_opengl_loadptr("glDrawArraysInstanced");
    HH_GL_glDrawElementsInstanced	    = (PFNGLDRAWELEMENTSINSTANCEDPROC)	   windows_opengl_loadptr("glDrawElementsInstanced");
    HH_GL_glTexBuffer		    = (PFNGLTEXBUFFERPROC)		   windows_opengl_loadptr("glTexBuffer");
    HH_GL_glPrimitiveRestartIndex	    = (PFNGLPRIMITIVERESTARTINDEXPROC)	   windows_opengl_loadptr("glPrimitiveRestartIndex");
    HH_GL_glCopyBufferSubData	    = (PFNGLCOPYBUFFERSUBDATAPROC)	   windows_opengl_loadptr("glCopyBufferSubData");
    HH_GL_glGetUniformIndices	    = (PFNGLGETUNIFORMINDICESPROC)	   windows_opengl_loadptr("glGetUniformIndices");
    HH_GL_glGetActiveUniformsiv	    = (PFNGLGETACTIVEUNIFORMSIVPROC)	   windows_opengl_loadptr("glGetActiveUniformsiv");
    HH_GL_glGetActiveUniformName	    = (PFNGLGETACTIVEUNIFORMNAMEPROC)	   windows_opengl_loadptr("glGetActiveUniformName");
    HH_GL_glGetUniformBlockIndex	    = (PFNGLGETUNIFORMBLOCKINDEXPROC)	   windows_opengl_loadptr("glGetUniformBlockIndex");
    HH_GL_glGetActiveUniformBlockiv   = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)   windows_opengl_loadptr("glGetActiveUniformBlockiv");
    HH_GL_glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC) windows_opengl_loadptr("glGetActiveUniformBlockName");
    HH_GL_glUniformBlockBinding	    = (PFNGLUNIFORMBLOCKBINDINGPROC)	   windows_opengl_loadptr("glUniformBlockBinding");
    HH_GL_glBindBufferRange	    = (PFNGLBINDBUFFERRANGEPROC) 	   windows_opengl_loadptr("glBindBufferRange");
    HH_GL_glBindBufferBase	    = (PFNGLBINDBUFFERBASEPROC)		   windows_opengl_loadptr("glBindBufferBase");
    HH_GL_glGetIntegeri_v		    = (PFNGLGETINTEGERI_VPROC)		   windows_opengl_loadptr("glGetIntegeri_v");
    
    // 3.2 
    HH_GL_glDrawElementsBaseVertex	  = (PFNGLDRAWELEMENTSBASEVERTEXPROC)		windows_opengl_loadptr("glDrawElementsBaseVertex");
    HH_GL_glDrawRangeElementsBaseVertex	  = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)	windows_opengl_loadptr("glDrawRangeElementsBaseVertex");
    HH_GL_glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)	windows_opengl_loadptr("glDrawElementsInstancedBaseVertex");
    HH_GL_glMultiDrawElementsBaseVertex	  = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)	windows_opengl_loadptr("glMultiDrawElementsBaseVertex");
    HH_GL_glProvokingVertex		  = (PFNGLPROVOKINGVERTEXPROC)			windows_opengl_loadptr("glProvokingVertex");
    HH_GL_glFenceSync			  = (PFNGLFENCESYNCPROC)			windows_opengl_loadptr("glFenceSync");
    HH_GL_glIsSync			  = (PFNGLISSYNCPROC)				windows_opengl_loadptr("glIsSync");
    HH_GL_glDeleteSync			  = (PFNGLDELETESYNCPROC)			windows_opengl_loadptr("glDeleteSync");
    HH_GL_glClientWaitSync		  = (PFNGLCLIENTWAITSYNCPROC)			windows_opengl_loadptr("glClientWaitSync");
    HH_GL_glWaitSync			  = (PFNGLWAITSYNCPROC)				windows_opengl_loadptr("glWaitSync");
    HH_GL_glGetInteger64v			  = (PFNGLGETINTEGER64VPROC)			windows_opengl_loadptr("glGetInteger64v");
    HH_GL_glGetSynciv			  = (PFNGLGETSYNCIVPROC)			windows_opengl_loadptr("glGetSynciv");
    HH_GL_glGetInteger64i_v		  = (PFNGLGETINTEGER64I_VPROC)			windows_opengl_loadptr("glGetInteger64i_v");
    HH_GL_glGetBufferParameteri64v	  = (PFNGLGETBUFFERPARAMETERI64VPROC)		windows_opengl_loadptr("glGetBufferParameteri64v");
    HH_GL_glFramebufferTexture		  = (PFNGLFRAMEBUFFERTEXTUREPROC)		windows_opengl_loadptr("glFramebufferTexture");
    HH_GL_glTexImage2DMultisample		  = (PFNGLTEXIMAGE2DMULTISAHH_GLLEPROC)		windows_opengl_loadptr("glTexImage2DMultisample");
    HH_GL_glTexImage3DMultisample		  = (PFNGLTEXIMAGE3DMULTISAHH_GLLEPROC)		windows_opengl_loadptr("glTexImage3DMultisample");
    HH_GL_glGetMultisamplefv		  = (PFNGLGETMULTISAHH_GLLEFVPROC)			windows_opengl_loadptr("glGetMultisamplefv");
    HH_GL_glSampleMaski			  = (PFNGLSAHH_GLLEMASKIPROC)			windows_opengl_loadptr("glSampleMaski");
    
    // 3.3 
    HH_GL_glBindFragDataLocationIndexed = (PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)	windows_opengl_loadptr("glBindFragDataLocationIndexed");
    HH_GL_glGetFragDataIndex	      = (PFNGLGETFRAGDATAINDEXPROC)		windows_opengl_loadptr("glGetFragDataIndex");
    HH_GL_glGenSamplers		      = (PFNGLGENSAHH_GLLERSPROC)			windows_opengl_loadptr("glGenSamplers");
    HH_GL_glDeleteSamplers	      = (PFNGLDELETESAHH_GLLERSPROC)		windows_opengl_loadptr("glDeleteSamplers");
    HH_GL_glIsSampler		      = (PFNGLISSAHH_GLLERPROC)			windows_opengl_loadptr("glIsSampler");
    HH_GL_glBindSampler		      = (PFNGLBINDSAHH_GLLERPROC)			windows_opengl_loadptr("glBindSampler");
    HH_GL_glSamplerParameteri	      = (PFNGLSAHH_GLLERPARAMETERIPROC)		windows_opengl_loadptr("glSamplerParameteri");
    HH_GL_glSamplerParameteriv	      = (PFNGLSAHH_GLLERPARAMETERIVPROC)		windows_opengl_loadptr("glSamplerParameteriv");
    HH_GL_glSamplerParameterf	      = (PFNGLSAHH_GLLERPARAMETERFPROC)		windows_opengl_loadptr("glSamplerParameterf");
    HH_GL_glSamplerParameterfv	      = (PFNGLSAHH_GLLERPARAMETERFVPROC)		windows_opengl_loadptr("glSamplerParameterfv");
    HH_GL_glSamplerParameterIiv	      = (PFNGLSAHH_GLLERPARAMETERIIVPROC)		windows_opengl_loadptr("glSamplerParameterIiv");
    HH_GL_glSamplerParameterIuiv	      = (PFNGLSAHH_GLLERPARAMETERIUIVPROC)		windows_opengl_loadptr("glSamplerParameterIuiv");
    HH_GL_glGetSamplerParameteriv	      = (PFNGLGETSAHH_GLLERPARAMETERIVPROC)	windows_opengl_loadptr("glGetSamplerParameteriv");
    HH_GL_glGetSamplerParameterIiv      = (PFNGLGETSAHH_GLLERPARAMETERIIVPROC)	windows_opengl_loadptr("glGetSamplerParameterIiv");
    HH_GL_glGetSamplerParameterfv	      = (PFNGLGETSAHH_GLLERPARAMETERFVPROC)	windows_opengl_loadptr("glGetSamplerParameterfv");
    HH_GL_glGetSamplerParameterIuiv     = (PFNGLGETSAHH_GLLERPARAMETERIUIVPROC)	windows_opengl_loadptr("glGetSamplerParameterIuiv");
    HH_GL_glQueryCounter		      = (PFNGLQUERYCOUNTERPROC)			windows_opengl_loadptr("glQueryCounter");
    HH_GL_glGetQueryObjecti64v	      = (PFNGLGETQUERYOBJECTI64VPROC)		windows_opengl_loadptr("glGetQueryObjecti64v");
    HH_GL_glGetQueryObjectui64v	      = (PFNGLGETQUERYOBJECTUI64VPROC)		windows_opengl_loadptr("glGetQueryObjectui64v");
    HH_GL_glVertexAttribDivisor	      = (PFNGLVERTEXATTRIBDIVISORPROC)		windows_opengl_loadptr("glVertexAttribDivisor");
    HH_GL_glVertexAttribP1ui	      = (PFNGLVERTEXATTRIBP1UIPROC)		windows_opengl_loadptr("glVertexAttribP1ui");
    HH_GL_glVertexAttribP1uiv	      = (PFNGLVERTEXATTRIBP1UIVPROC)		windows_opengl_loadptr("glVertexAttribP1uiv");
    HH_GL_glVertexAttribP2ui	      = (PFNGLVERTEXATTRIBP2UIPROC)		windows_opengl_loadptr("glVertexAttribP2ui");
    HH_GL_glVertexAttribP2uiv	      = (PFNGLVERTEXATTRIBP2UIVPROC)		windows_opengl_loadptr("glVertexAttribP2uiv");
    HH_GL_glVertexAttribP3ui	      = (PFNGLVERTEXATTRIBP3UIPROC)		windows_opengl_loadptr("glVertexAttribP3ui");
    HH_GL_glVertexAttribP3uiv	      = (PFNGLVERTEXATTRIBP3UIVPROC)		windows_opengl_loadptr("glVertexAttribP3uiv");
    HH_GL_glVertexAttribP4ui	      = (PFNGLVERTEXATTRIBP4UIPROC)		windows_opengl_loadptr("glVertexAttribP4ui");
    HH_GL_glVertexAttribP4uiv	      = (PFNGLVERTEXATTRIBP4UIVPROC)		windows_opengl_loadptr("glVertexAttribP4uiv");
    HH_GL_glVertexP2ui		      = (PFNGLVERTEXP2UIPROC)			windows_opengl_loadptr("glVertexP2ui");
    HH_GL_glVertexP2uiv		      = (PFNGLVERTEXP2UIVPROC)			windows_opengl_loadptr("glVertexP2uiv");
    HH_GL_glVertexP3ui		      = (PFNGLVERTEXP3UIPROC)			windows_opengl_loadptr("glVertexP3ui");
    HH_GL_glVertexP3uiv		      = (PFNGLVERTEXP3UIVPROC)			windows_opengl_loadptr("glVertexP3uiv");
    HH_GL_glVertexP4ui		      = (PFNGLVERTEXP4UIPROC)			windows_opengl_loadptr("glVertexP4ui");
    HH_GL_glVertexP4uiv		      = (PFNGLVERTEXP4UIVPROC)			windows_opengl_loadptr("glVertexP4uiv");
    HH_GL_glTexCoordP1ui		      = (PFNGLTEXCOORDP1UIPROC)			windows_opengl_loadptr("glTexCoordP1ui");
    HH_GL_glTexCoordP1uiv		      = (PFNGLTEXCOORDP1UIVPROC)		windows_opengl_loadptr("glTexCoordP1uiv");
    HH_GL_glTexCoordP2ui		      = (PFNGLTEXCOORDP2UIPROC)			windows_opengl_loadptr("glTexCoordP2ui");
    HH_GL_glTexCoordP2uiv		      = (PFNGLTEXCOORDP2UIVPROC)		windows_opengl_loadptr("glTexCoordP2uiv");
    HH_GL_glTexCoordP3ui		      = (PFNGLTEXCOORDP3UIPROC)			windows_opengl_loadptr("glTexCoordP3ui");
    HH_GL_glTexCoordP3uiv		      = (PFNGLTEXCOORDP3UIVPROC)		windows_opengl_loadptr("glTexCoordP3uiv");
    HH_GL_glTexCoordP4ui		      = (PFNGLTEXCOORDP4UIPROC)			windows_opengl_loadptr("glTexCoordP4ui");
    HH_GL_glTexCoordP4uiv		      = (PFNGLTEXCOORDP4UIVPROC)		windows_opengl_loadptr("glTexCoordP4uiv");
    HH_GL_glMultiTexCoordP1ui	      = (PFNGLMULTITEXCOORDP1UIPROC)		windows_opengl_loadptr("glMultiTexCoordP1ui");
    HH_GL_glMultiTexCoordP1uiv	      = (PFNGLMULTITEXCOORDP1UIVPROC)		windows_opengl_loadptr("glMultiTexCoordP1uiv");
    HH_GL_glMultiTexCoordP2ui	      = (PFNGLMULTITEXCOORDP2UIPROC)		windows_opengl_loadptr("glMultiTexCoordP2ui");
    HH_GL_glMultiTexCoordP2uiv	      = (PFNGLMULTITEXCOORDP2UIVPROC)		windows_opengl_loadptr("glMultiTexCoordP2uiv");
    HH_GL_glMultiTexCoordP3ui	      = (PFNGLMULTITEXCOORDP3UIPROC)		windows_opengl_loadptr("glMultiTexCoordP3ui");
    HH_GL_glMultiTexCoordP3uiv	      = (PFNGLMULTITEXCOORDP3UIVPROC)		windows_opengl_loadptr("glMultiTexCoordP3uiv");
    HH_GL_glMultiTexCoordP4ui	      = (PFNGLMULTITEXCOORDP4UIPROC)		windows_opengl_loadptr("glMultiTexCoordP4ui");
    HH_GL_glMultiTexCoordP4uiv	      = (PFNGLMULTITEXCOORDP4UIVPROC)		windows_opengl_loadptr("glMultiTexCoordP4uiv");
    HH_GL_glNormalP3ui		      = (PFNGLNORMALP3UIPROC)			windows_opengl_loadptr("glNormalP3ui");
    HH_GL_glNormalP3uiv		      = (PFNGLNORMALP3UIVPROC)			windows_opengl_loadptr("glNormalP3uiv");
    HH_GL_glColorP3ui		      = (PFNGLCOLORP3UIPROC)			windows_opengl_loadptr("glColorP3ui");
    HH_GL_glColorP3uiv		      = (PFNGLCOLORP3UIVPROC)			windows_opengl_loadptr("glColorP3uiv");
    HH_GL_glColorP4ui		      = (PFNGLCOLORP4UIPROC)			windows_opengl_loadptr("glColorP4ui");
    HH_GL_glColorP4uiv		      = (PFNGLCOLORP4UIVPROC)			windows_opengl_loadptr("glColorP4uiv");
    HH_GL_glSecondaryColorP3ui	      = (PFNGLSECONDARYCOLORP3UIPROC)		windows_opengl_loadptr("glSecondaryColorP3ui");
    HH_GL_glSecondaryColorP3uiv	      = (PFNGLSECONDARYCOLORP3UIVPROC)		windows_opengl_loadptr("glSecondaryColorP3uiv");
}
internal void
windows_opengl_version_4()
{
    // 4.0 
    HH_GL_glMinSampleShading		 = (PFNGLMINSAHH_GLLESHADINGPROC)		     windows_opengl_loadptr("glMinSampleShading");
    HH_GL_glBlendEquationi		 = (PFNGLBLENDEQUATIONIPROC)		     windows_opengl_loadptr("glBlendEquationi");
    HH_GL_glBlendEquationSeparatei	 = (PFNGLBLENDEQUATIONSEPARATEIPROC)	     windows_opengl_loadptr("glBlendEquationSeparatei");
    HH_GL_glBlendFunci			 = (PFNGLBLENDFUNCIPROC)		     windows_opengl_loadptr("glBlendFunci");
    HH_GL_glBlendFuncSeparatei		 = (PFNGLBLENDFUNCSEPARATEIPROC)	     windows_opengl_loadptr("glBlendFuncSeparatei");
    HH_GL_glDrawArraysIndirect		 = (PFNGLDRAWARRAYSINDIRECTPROC)	     windows_opengl_loadptr("glDrawArraysIndirect");
    HH_GL_glDrawElementsIndirect		 = (PFNGLDRAWELEMENTSINDIRECTPROC)	     windows_opengl_loadptr("glDrawElementsIndirect");
    HH_GL_glUniform1d			 = (PFNGLUNIFORM1DPROC)			     windows_opengl_loadptr("glUniform1d");
    HH_GL_glUniform2d			 = (PFNGLUNIFORM2DPROC)			     windows_opengl_loadptr("glUniform2d");
    HH_GL_glUniform3d			 = (PFNGLUNIFORM3DPROC)			     windows_opengl_loadptr("glUniform3d");
    HH_GL_glUniform4d			 = (PFNGLUNIFORM4DPROC)			     windows_opengl_loadptr("glUniform4d");
    HH_GL_glUniform1dv			 = (PFNGLUNIFORM1DVPROC)		     windows_opengl_loadptr("glUniform1dv");
    HH_GL_glUniform2dv			 = (PFNGLUNIFORM2DVPROC)		     windows_opengl_loadptr("glUniform2dv");
    HH_GL_glUniform3dv			 = (PFNGLUNIFORM3DVPROC)		     windows_opengl_loadptr("glUniform3dv");
    HH_GL_glUniform4dv			 = (PFNGLUNIFORM4DVPROC)		     windows_opengl_loadptr("glUniform4dv");
    HH_GL_glUniformMatrix2dv		 = (PFNGLUNIFORMMATRIX2DVPROC)		     windows_opengl_loadptr("glUniformMatrix2dv");
    HH_GL_glUniformMatrix3dv		 = (PFNGLUNIFORMMATRIX3DVPROC)		     windows_opengl_loadptr("glUniformMatrix3dv");
    HH_GL_glUniformMatrix4dv		 = (PFNGLUNIFORMMATRIX4DVPROC)		     windows_opengl_loadptr("glUniformMatrix4dv");
    HH_GL_glUniformMatrix2x3dv		 = (PFNGLUNIFORMMATRIX2X3DVPROC)	     windows_opengl_loadptr("glUniformMatrix2x3dv");
    HH_GL_glUniformMatrix2x4dv		 = (PFNGLUNIFORMMATRIX2X4DVPROC)	     windows_opengl_loadptr("glUniformMatrix2x4dv");
    HH_GL_glUniformMatrix3x2dv		 = (PFNGLUNIFORMMATRIX3X2DVPROC)	     windows_opengl_loadptr("glUniformMatrix3x2dv");
    HH_GL_glUniformMatrix3x4dv		 = (PFNGLUNIFORMMATRIX3X4DVPROC)	     windows_opengl_loadptr("glUniformMatrix3x4dv");
    HH_GL_glUniformMatrix4x2dv		 = (PFNGLUNIFORMMATRIX4X2DVPROC)	     windows_opengl_loadptr("glUniformMatrix4x2dv");
    HH_GL_glUniformMatrix4x3dv		 = (PFNGLUNIFORMMATRIX4X3DVPROC)	     windows_opengl_loadptr("glUniformMatrix4x3dv");
    HH_GL_glGetUniformdv			 = (PFNGLGETUNIFORMDVPROC)		     windows_opengl_loadptr("glGetUniformdv");
    HH_GL_glGetSubroutineUniformLocation	 = (PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)   windows_opengl_loadptr("glGetSubroutineUniformLocation");
    HH_GL_glGetSubroutineIndex		 = (PFNGLGETSUBROUTINEINDEXPROC)	     windows_opengl_loadptr("glGetSubroutineIndex");
    HH_GL_glGetActiveSubroutineUniformiv	 = (PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)   windows_opengl_loadptr("glGetActiveSubroutineUniformiv");
    HH_GL_glGetActiveSubroutineUniformName = (PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC) windows_opengl_loadptr("glGetActiveSubroutineUniformName");
    HH_GL_glGetActiveSubroutineName	 = (PFNGLGETACTIVESUBROUTINENAMEPROC)	     windows_opengl_loadptr("glGetActiveSubroutineName");
    HH_GL_glUniformSubroutinesuiv		 = (PFNGLUNIFORMSUBROUTINESUIVPROC)	     windows_opengl_loadptr("glUniformSubroutinesuiv");
    HH_GL_glGetUniformSubroutineuiv	 = (PFNGLGETUNIFORMSUBROUTINEUIVPROC)	     windows_opengl_loadptr("glGetUniformSubroutineuiv");
    HH_GL_glGetProgramStageiv		 = (PFNGLGETPROGRAMSTAGEIVPROC)		     windows_opengl_loadptr("glGetProgramStageiv");
    HH_GL_glPatchParameteri		 = (PFNGLPATCHPARAMETERIPROC)		     windows_opengl_loadptr("glPatchParameteri");
    HH_GL_glPatchParameterfv		 = (PFNGLPATCHPARAMETERFVPROC)		     windows_opengl_loadptr("glPatchParameterfv");
    HH_GL_glBindTransformFeedback		 = (PFNGLBINDTRANSFORMFEEDBACKPROC)	     windows_opengl_loadptr("glBindTransformFeedback");
    HH_GL_glDeleteTransformFeedbacks	 = (PFNGLDELETETRANSFORMFEEDBACKSPROC)	     windows_opengl_loadptr("glDeleteTransformFeedbacks");
    HH_GL_glGenTransformFeedbacks		 = (PFNGLGENTRANSFORMFEEDBACKSPROC)	     windows_opengl_loadptr("glGenTransformFeedbacks");
    HH_GL_glIsTransformFeedback		 = (PFNGLISTRANSFORMFEEDBACKPROC)	     windows_opengl_loadptr("glIsTransformFeedback");
    HH_GL_glPauseTransformFeedback	 = (PFNGLPAUSETRANSFORMFEEDBACKPROC)	     windows_opengl_loadptr("glPauseTransformFeedback");
    HH_GL_glResumeTransformFeedback	 = (PFNGLRESUMETRANSFORMFEEDBACKPROC)	     windows_opengl_loadptr("glResumeTransformFeedback");
    HH_GL_glDrawTransformFeedback		 = (PFNGLDRAWTRANSFORMFEEDBACKPROC)	     windows_opengl_loadptr("glDrawTransformFeedback");
    HH_GL_glDrawTransformFeedbackStream	 = (PFNGLDRAWTRANSFORMFEEDBACKSTREAHH_GLROC)    windows_opengl_loadptr("glDrawTransformFeedbackStream");
    HH_GL_glBeginQueryIndexed		 = (PFNGLBEGINQUERYINDEXEDPROC)              windows_opengl_loadptr("glBeginQueryIndexed");
    HH_GL_glEndQueryIndexed		 = (PFNGLENDQUERYINDEXEDPROC)		     windows_opengl_loadptr("glEndQueryIndexed");
    HH_GL_glGetQueryIndexediv		 = (PFNGLGETQUERYINDEXEDIVPROC)		     windows_opengl_loadptr("glGetQueryIndexediv");
    
    // 4.1 
    HH_GL_glReleaseShaderCompiler	    = (PFNGLRELEASESHADERCOHH_GLILERPROC)	   windows_opengl_loadptr("glReleaseShaderCompiler");
    HH_GL_glShaderBinary		    = (PFNGLSHADERBINARYPROC)		   windows_opengl_loadptr("glShaderBinary");
    HH_GL_glGetShaderPrecisionFormat  = (PFNGLGETSHADERPRECISIONFORMATPROC)  windows_opengl_loadptr("glGetShaderPrecisionFormat");
    HH_GL_glDepthRangef		    = (PFNGLDEPTHRANGEFPROC)		   windows_opengl_loadptr("glDepthRangef");
    HH_GL_glClearDepthf		    = (PFNGLCLEARDEPTHFPROC)		   windows_opengl_loadptr("glClearDepthf");
    HH_GL_glGetProgramBinary	    = (PFNGLGETPROGRAMBINARYPROC)	   windows_opengl_loadptr("glGetProgramBinary");
    HH_GL_glProgramBinary		    = (PFNGLPROGRAMBINARYPROC)		   windows_opengl_loadptr("glProgramBinary");
    HH_GL_glProgramParameteri	    = (PFNGLPROGRAHH_GLARAMETERIPROC)	   windows_opengl_loadptr("glProgramParameteri");
    HH_GL_glUseProgramStages	    = (PFNGLUSEPROGRAMSTAGESPROC)	   windows_opengl_loadptr("glUseProgramStages");
    HH_GL_glActiveShaderProgram	    = (PFNGLACTIVESHADERPROGRAHH_GLROC)	   windows_opengl_loadptr("glActiveShaderProgram");
    HH_GL_glCreateShaderProgramv	    = (PFNGLCREATESHADERPROGRAMVPROC)	   windows_opengl_loadptr("glCreateShaderProgramv");
    HH_GL_glBindProgramPipeline	    = (PFNGLBINDPROGRAHH_GLIPELINEPROC)	   windows_opengl_loadptr("glBindProgramPipeline");
    HH_GL_glDeleteProgramPipelines    = (PFNGLDELETEPROGRAHH_GLIPELINESPROC)	   windows_opengl_loadptr("glDeleteProgramPipelines");
    HH_GL_glGenProgramPipelines	    = (PFNGLGENPROGRAHH_GLIPELINESPROC)	   windows_opengl_loadptr("glGenProgramPipelines");
    HH_GL_glIsProgramPipeline	    = (PFNGLISPROGRAHH_GLIPELINEPROC)	   windows_opengl_loadptr("glIsProgramPipeline");
    HH_GL_glGetProgramPipelineiv	    = (PFNGLGETPROGRAHH_GLIPELINEIVPROC)	   windows_opengl_loadptr("glGetProgramPipelineiv");
    HH_GL_glProgramParameteri	    = (PFNGLPROGRAHH_GLARAMETERIPROC)	   windows_opengl_loadptr("glProgramParameteri");
    HH_GL_glProgramUniform1i	    = (PFNGLPROGRAMUNIFORM1IPROC)	   windows_opengl_loadptr("glProgramUniform1i");
    HH_GL_glProgramUniform1iv	    = (PFNGLPROGRAMUNIFORM1IVPROC)	   windows_opengl_loadptr("glProgramUniform1iv");
    HH_GL_glProgramUniform1f	    = (PFNGLPROGRAMUNIFORM1FPROC)	   windows_opengl_loadptr("glProgramUniform1f");
    HH_GL_glProgramUniform1fv	    = (PFNGLPROGRAMUNIFORM1FVPROC)	   windows_opengl_loadptr("glProgramUniform1fv");
    HH_GL_glProgramUniform1d	    = (PFNGLPROGRAMUNIFORM1DPROC)	   windows_opengl_loadptr("glProgramUniform1d");
    HH_GL_glProgramUniform1dv	    = (PFNGLPROGRAMUNIFORM1DVPROC)	   windows_opengl_loadptr("glProgramUniform1dv");
    HH_GL_glProgramUniform1ui	    = (PFNGLPROGRAMUNIFORM1UIPROC)	   windows_opengl_loadptr("glProgramUniform1ui");
    HH_GL_glProgramUniform1uiv	    = (PFNGLPROGRAMUNIFORM1UIVPROC)	   windows_opengl_loadptr("glProgramUniform1uiv");
    HH_GL_glProgramUniform2i	    = (PFNGLPROGRAMUNIFORM2IPROC)	   windows_opengl_loadptr("glProgramUniform2i");
    HH_GL_glProgramUniform2iv	    = (PFNGLPROGRAMUNIFORM2IVPROC)	   windows_opengl_loadptr("glProgramUniform2iv");
    HH_GL_glProgramUniform2f	    = (PFNGLPROGRAMUNIFORM2FPROC)	   windows_opengl_loadptr("glProgramUniform2f");
    HH_GL_glProgramUniform2fv	    = (PFNGLPROGRAMUNIFORM2FVPROC)	   windows_opengl_loadptr("glProgramUniform2fv");
    HH_GL_glProgramUniform2d	    = (PFNGLPROGRAMUNIFORM2DPROC)	   windows_opengl_loadptr("glProgramUniform2d");
    HH_GL_glProgramUniform2dv	    = (PFNGLPROGRAMUNIFORM2DVPROC)	   windows_opengl_loadptr("glProgramUniform2dv");
    HH_GL_glProgramUniform2ui	    = (PFNGLPROGRAMUNIFORM2UIPROC)	   windows_opengl_loadptr("glProgramUniform2ui");
    HH_GL_glProgramUniform2uiv	    = (PFNGLPROGRAMUNIFORM2UIVPROC)	   windows_opengl_loadptr("glProgramUniform2uiv");
    HH_GL_glProgramUniform3i	    = (PFNGLPROGRAMUNIFORM3IPROC)	   windows_opengl_loadptr("glProgramUniform3i");
    HH_GL_glProgramUniform3iv	    = (PFNGLPROGRAMUNIFORM3IVPROC)	   windows_opengl_loadptr("glProgramUniform3iv");
    HH_GL_glProgramUniform3f	    = (PFNGLPROGRAMUNIFORM3FPROC)	   windows_opengl_loadptr("glProgramUniform3f");
    HH_GL_glProgramUniform3fv	    = (PFNGLPROGRAMUNIFORM3FVPROC)	   windows_opengl_loadptr("glProgramUniform3fv");
    HH_GL_glProgramUniform3d	    = (PFNGLPROGRAMUNIFORM3DPROC)	   windows_opengl_loadptr("glProgramUniform3d");
    HH_GL_glProgramUniform3dv	    = (PFNGLPROGRAMUNIFORM3DVPROC)	   windows_opengl_loadptr("glProgramUniform3dv");
    HH_GL_glProgramUniform3ui	    = (PFNGLPROGRAMUNIFORM3UIPROC)	   windows_opengl_loadptr("glProgramUniform3ui");
    HH_GL_glProgramUniform3uiv	    = (PFNGLPROGRAMUNIFORM3UIVPROC)	   windows_opengl_loadptr("glProgramUniform3uiv");
    HH_GL_glProgramUniform4i	    = (PFNGLPROGRAMUNIFORM4IPROC)	   windows_opengl_loadptr("glProgramUniform4i");
    HH_GL_glProgramUniform4iv	    = (PFNGLPROGRAMUNIFORM4IVPROC)	   windows_opengl_loadptr("glProgramUniform4iv");
    HH_GL_glProgramUniform4f	    = (PFNGLPROGRAMUNIFORM4FPROC)	   windows_opengl_loadptr("glProgramUniform4f");
    HH_GL_glProgramUniform4fv	    = (PFNGLPROGRAMUNIFORM4FVPROC)	   windows_opengl_loadptr("glProgramUniform4fv");
    HH_GL_glProgramUniform4d	    = (PFNGLPROGRAMUNIFORM4DPROC)	   windows_opengl_loadptr("glProgramUniform4d");
    HH_GL_glProgramUniform4dv	    = (PFNGLPROGRAMUNIFORM4DVPROC)	   windows_opengl_loadptr("glProgramUniform4dv");
    HH_GL_glProgramUniform4ui	    = (PFNGLPROGRAMUNIFORM4UIPROC)	   windows_opengl_loadptr("glProgramUniform4ui");
    HH_GL_glProgramUniform4uiv	    = (PFNGLPROGRAMUNIFORM4UIVPROC)	   windows_opengl_loadptr("glProgramUniform4uiv");
    HH_GL_glProgramUniformMatrix2fv   = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC)   windows_opengl_loadptr("glProgramUniformMatrix2fv");
    HH_GL_glProgramUniformMatrix3fv   = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC)   windows_opengl_loadptr("glProgramUniformMatrix3fv");
    HH_GL_glProgramUniformMatrix4fv   = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC)   windows_opengl_loadptr("glProgramUniformMatrix4fv");
    HH_GL_glProgramUniformMatrix2dv   = (PFNGLPROGRAMUNIFORMMATRIX2DVPROC)   windows_opengl_loadptr("glProgramUniformMatrix2dv");
    HH_GL_glProgramUniformMatrix3dv   = (PFNGLPROGRAMUNIFORMMATRIX3DVPROC)   windows_opengl_loadptr("glProgramUniformMatrix3dv");
    HH_GL_glProgramUniformMatrix4dv   = (PFNGLPROGRAMUNIFORMMATRIX4DVPROC)   windows_opengl_loadptr("glProgramUniformMatrix4dv");
    HH_GL_glProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC) windows_opengl_loadptr("glProgramUniformMatrix2x3fv");
    HH_GL_glProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC) windows_opengl_loadptr("glProgramUniformMatrix3x2fv");
    HH_GL_glProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC) windows_opengl_loadptr("glProgramUniformMatrix2x4fv");
    HH_GL_glProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC) windows_opengl_loadptr("glProgramUniformMatrix4x2fv");
    HH_GL_glProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC) windows_opengl_loadptr("glProgramUniformMatrix3x4fv");
    HH_GL_glProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC) windows_opengl_loadptr("glProgramUniformMatrix4x3fv");
    HH_GL_glProgramUniformMatrix2x3dv = (PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC) windows_opengl_loadptr("glProgramUniformMatrix2x3dv");
    HH_GL_glProgramUniformMatrix3x2dv = (PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC) windows_opengl_loadptr("glProgramUniformMatrix3x2dv");
    HH_GL_glProgramUniformMatrix2x4dv = (PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC) windows_opengl_loadptr("glProgramUniformMatrix2x4dv");
    HH_GL_glProgramUniformMatrix4x2dv = (PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC) windows_opengl_loadptr("glProgramUniformMatrix4x2dv");
    HH_GL_glProgramUniformMatrix3x4dv = (PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC) windows_opengl_loadptr("glProgramUniformMatrix3x4dv");
    HH_GL_glProgramUniformMatrix4x3dv = (PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC) windows_opengl_loadptr("glProgramUniformMatrix4x3dv");
    HH_GL_glValidateProgramPipeline   = (PFNGLVALIDATEPROGRAHH_GLIPELINEPROC)   windows_opengl_loadptr("glValidateProgramPipeline");
    HH_GL_glGetProgramPipelineInfoLog = (PFNGLGETPROGRAHH_GLIPELINEINFOLOGPROC) windows_opengl_loadptr("glGetProgramPipelineInfoLog");
    HH_GL_glVertexAttribL1d	    = (PFNGLVERTEXATTRIBL1DPROC)	   windows_opengl_loadptr("glVertexAttribL1d");
    HH_GL_glVertexAttribL2d	    = (PFNGLVERTEXATTRIBL2DPROC)	   windows_opengl_loadptr("glVertexAttribL2d");
    HH_GL_glVertexAttribL3d	    = (PFNGLVERTEXATTRIBL3DPROC)	   windows_opengl_loadptr("glVertexAttribL3d");
    HH_GL_glVertexAttribL4d	    = (PFNGLVERTEXATTRIBL4DPROC)	   windows_opengl_loadptr("glVertexAttribL4d");
    HH_GL_glVertexAttribL1dv	    = (PFNGLVERTEXATTRIBL1DVPROC)	   windows_opengl_loadptr("glVertexAttribL1dv");
    HH_GL_glVertexAttribL2dv	    = (PFNGLVERTEXATTRIBL2DVPROC)	   windows_opengl_loadptr("glVertexAttribL2dv");
    HH_GL_glVertexAttribL3dv	    = (PFNGLVERTEXATTRIBL3DVPROC)	   windows_opengl_loadptr("glVertexAttribL3dv");
    HH_GL_glVertexAttribL4dv	    = (PFNGLVERTEXATTRIBL4DVPROC)	   windows_opengl_loadptr("glVertexAttribL4dv");
    HH_GL_glVertexAttribLPointer	    = (PFNGLVERTEXATTRIBLPOINTERPROC)	   windows_opengl_loadptr("glVertexAttribLPointer");
    HH_GL_glGetVertexAttribLdv	    = (PFNGLGETVERTEXATTRIBLDVPROC)	   windows_opengl_loadptr("glGetVertexAttribLdv");
    HH_GL_glViewportArrayv	    = (PFNGLVIEWPORTARRAYVPROC)		   windows_opengl_loadptr("glViewportArrayv");
    HH_GL_glViewportIndexedf	    = (PFNGLVIEWPORTINDEXEDFPROC)	   windows_opengl_loadptr("glViewportIndexedf");
    HH_GL_glViewportIndexedfv	    = (PFNGLVIEWPORTINDEXEDFVPROC)	   windows_opengl_loadptr("glViewportIndexedfv");
    HH_GL_glScissorArrayv		    = (PFNGLSCISSORARRAYVPROC)		   windows_opengl_loadptr("glScissorArrayv");
    HH_GL_glScissorIndexed	    = (PFNGLSCISSORINDEXEDPROC)		   windows_opengl_loadptr("glScissorIndexed");
    HH_GL_glScissorIndexedv	    = (PFNGLSCISSORINDEXEDVPROC)	   windows_opengl_loadptr("glScissorIndexedv");
    HH_GL_glDepthRangeArrayv	    = (PFNGLDEPTHRANGEARRAYVPROC)	   windows_opengl_loadptr("glDepthRangeArrayv");
    HH_GL_glDepthRangeIndexed	    = (PFNGLDEPTHRANGEINDEXEDPROC)	   windows_opengl_loadptr("glDepthRangeIndexed");
    HH_GL_glGetFloati_v		    = (PFNGLGETFLOATI_VPROC)		   windows_opengl_loadptr("glGetFloati_v");
    HH_GL_glGetDoublei_v		    = (PFNGLGETDOUBLEI_VPROC)		   windows_opengl_loadptr("glGetDoublei_v");
    
    // 4.2 
    HH_GL_glDrawArraysInstancedBaseInstance	      = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)		windows_opengl_loadptr("glDrawArraysInstancedBaseInstance");
    HH_GL_glDrawElementsInstancedBaseInstance	      = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)		windows_opengl_loadptr("glDrawElementsInstancedBaseInstance");
    HH_GL_glDrawElementsInstancedBaseVertexBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)	windows_opengl_loadptr("glDrawElementsInstancedBaseVertexBaseInstance");
    HH_GL_glGetInternalformativ			      = (PFNGLGETINTERNALFORMATIVPROC)				windows_opengl_loadptr("glGetInternalformativ");
    HH_GL_glGetActiveAtomicCounterBufferiv	      = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)		windows_opengl_loadptr("glGetActiveAtomicCounterBufferiv");
    HH_GL_glBindImageTexture			      = (PFNGLBINDIMAGETEXTUREPROC)				windows_opengl_loadptr("glBindImageTexture");
    HH_GL_glMemoryBarrier				      = (PFNGLMEMORYBARRIERPROC)				windows_opengl_loadptr("glMemoryBarrier");
    HH_GL_glTexStorage1D				      = (PFNGLTEXSTORAGE1DPROC)					windows_opengl_loadptr("glTexStorage1D");
    HH_GL_glTexStorage2D				      = (PFNGLTEXSTORAGE2DPROC)					windows_opengl_loadptr("glTexStorage2D");
    HH_GL_glTexStorage3D				      = (PFNGLTEXSTORAGE3DPROC)					windows_opengl_loadptr("glTexStorage3D");
    HH_GL_glDrawTransformFeedbackInstanced	      = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)		windows_opengl_loadptr("glDrawTransformFeedbackInstanced");
    HH_GL_glDrawTransformFeedbackStreamInstanced	      = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)		windows_opengl_loadptr("glDrawTransformFeedbackStreamInstanced");
    
    // 4.3 
    HH_GL_glClearBufferData		  = (PFNGLCLEARBUFFERDATAPROC)		        windows_opengl_loadptr("glClearBufferData");
    HH_GL_glClearBufferSubData		  = (PFNGLCLEARBUFFERSUBDATAPROC)	        windows_opengl_loadptr("glClearBufferSubData");
    HH_GL_glDispatchCompute		  = (PFNGLDISPATCHCOHH_GLUTEPROC)		        windows_opengl_loadptr("glDispatchCompute");
    HH_GL_glDispatchComputeIndirect	  = (PFNGLDISPATCHCOHH_GLUTEINDIRECTPROC)	        windows_opengl_loadptr("glDispatchComputeIndirect");
    HH_GL_glCopyImageSubData		  = (PFNGLCOPYIMAGESUBDATAPROC)		        windows_opengl_loadptr("glCopyImageSubData");
    HH_GL_glFramebufferParameteri		  = (PFNGLFRAMEBUFFERPARAMETERIPROC)	        windows_opengl_loadptr("glFramebufferParameteri");
    HH_GL_glGetFramebufferParameteriv	  = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC)        windows_opengl_loadptr("glGetFramebufferParameteriv");
    HH_GL_glGetInternalformati64v		  = (PFNGLGETINTERNALFORMATI64VPROC)	        windows_opengl_loadptr("glGetInternalformati64v");
    HH_GL_glInvalidateTexSubImage		  = (PFNGLINVALIDATETEXSUBIMAGEPROC)	        windows_opengl_loadptr("glInvalidateTexSubImage");
    HH_GL_glInvalidateTexImage		  = (PFNGLINVALIDATETEXIMAGEPROC)	        windows_opengl_loadptr("glInvalidateTexImage");
    HH_GL_glInvalidateBufferSubData	  = (PFNGLINVALIDATEBUFFERSUBDATAPROC)	        windows_opengl_loadptr("glInvalidateBufferSubData");
    HH_GL_glInvalidateBufferData		  = (PFNGLINVALIDATEBUFFERDATAPROC)	        windows_opengl_loadptr("glInvalidateBufferData");
    HH_GL_glInvalidateFramebuffer		  = (PFNGLINVALIDATEFRAMEBUFFERPROC)	        windows_opengl_loadptr("glInvalidateFramebuffer");
    HH_GL_glInvalidateSubFramebuffer	  = (PFNGLINVALIDATESUBFRAMEBUFFERPROC)	        windows_opengl_loadptr("glInvalidateSubFramebuffer");
    HH_GL_glMultiDrawArraysIndirect	  = (PFNGLMULTIDRAWARRAYSINDIRECTPROC)	        windows_opengl_loadptr("glMultiDrawArraysIndirect");
    HH_GL_glMultiDrawElementsIndirect	  = (PFNGLMULTIDRAWELEMENTSINDIRECTPROC)        windows_opengl_loadptr("glMultiDrawElementsIndirect");
    HH_GL_glGetProgramInterfaceiv		  = (PFNGLGETPROGRAMINTERFACEIVPROC)	        windows_opengl_loadptr("glGetProgramInterfaceiv");
    HH_GL_glGetProgramResourceIndex	  = (PFNGLGETPROGRAMRESOURCEINDEXPROC)	        windows_opengl_loadptr("glGetProgramResourceIndex");
    HH_GL_glGetProgramResourceName	  = (PFNGLGETPROGRAMRESOURCENAMEPROC)	        windows_opengl_loadptr("glGetProgramResourceName");
    HH_GL_glGetProgramResourceiv		  = (PFNGLGETPROGRAMRESOURCEIVPROC)	        windows_opengl_loadptr("glGetProgramResourceiv");
    HH_GL_glGetProgramResourceLocation	  = (PFNGLGETPROGRAMRESOURCELOCATIONPROC)	windows_opengl_loadptr("glGetProgramResourceLocation");
    HH_GL_glGetProgramResourceLocationIndex = (PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)	windows_opengl_loadptr("glGetProgramResourceLocationIndex");
    HH_GL_glShaderStorageBlockBinding	  = (PFNGLSHADERSTORAGEBLOCKBINDINGPROC)	windows_opengl_loadptr("glShaderStorageBlockBinding");
    HH_GL_glTexBufferRange		  = (PFNGLTEXBUFFERRANGEPROC)			windows_opengl_loadptr("glTexBufferRange");
    HH_GL_glTexStorage2DMultisample	  = (PFNGLTEXSTORAGE2DMULTISAHH_GLLEPROC)		windows_opengl_loadptr("glTexStorage2DMultisample");
    HH_GL_glTexStorage3DMultisample	  = (PFNGLTEXSTORAGE3DMULTISAHH_GLLEPROC)		windows_opengl_loadptr("glTexStorage3DMultisample");
    HH_GL_glTextureView			  = (PFNGLTEXTUREVIEWPROC)			windows_opengl_loadptr("glTextureView");
    HH_GL_glBindVertexBuffer		  = (PFNGLBINDVERTEXBUFFERPROC)			windows_opengl_loadptr("glBindVertexBuffer");
    HH_GL_glVertexAttribFormat		  = (PFNGLVERTEXATTRIBFORMATPROC)		windows_opengl_loadptr("glVertexAttribFormat");
    HH_GL_glVertexAttribIFormat		  = (PFNGLVERTEXATTRIBIFORMATPROC)		windows_opengl_loadptr("glVertexAttribIFormat");
    HH_GL_glVertexAttribLFormat		  = (PFNGLVERTEXATTRIBLFORMATPROC)		windows_opengl_loadptr("glVertexAttribLFormat");
    HH_GL_glVertexAttribBinding		  = (PFNGLVERTEXATTRIBBINDINGPROC)		windows_opengl_loadptr("glVertexAttribBinding");
    HH_GL_glVertexBindingDivisor		  = (PFNGLVERTEXBINDINGDIVISORPROC)		windows_opengl_loadptr("glVertexBindingDivisor");
    HH_GL_glDebugMessageControl		  = (PFNGLDEBUGMESSAGECONTROLPROC)		windows_opengl_loadptr("glDebugMessageControl");
    HH_GL_glDebugMessageInsert		  = (PFNGLDEBUGMESSAGEINSERTPROC)		windows_opengl_loadptr("glDebugMessageInsert");
    HH_GL_glDebugMessageCallback		  = (PFNGLDEBUGMESSAGECALLBACKPROC)		windows_opengl_loadptr("glDebugMessageCallback");
    HH_GL_glGetDebugMessageLog		  = (PFNGLGETDEBUGMESSAGELOGPROC)		windows_opengl_loadptr("glGetDebugMessageLog");
    HH_GL_glPushDebugGroup		  = (PFNGLPUSHDEBUGGROUPPROC)			windows_opengl_loadptr("glPushDebugGroup");
    HH_GL_glPopDebugGroup			  = (PFNGLPOPDEBUGGROUPPROC)			windows_opengl_loadptr("glPopDebugGroup");
    HH_GL_glObjectLabel			  = (PFNGLOBJECTLABELPROC)			windows_opengl_loadptr("glObjectLabel");
    HH_GL_glGetObjectLabel		  = (PFNGLGETOBJECTLABELPROC)			windows_opengl_loadptr("glGetObjectLabel");
    HH_GL_glObjectPtrLabel		  = (PFNGLOBJECTPTRLABELPROC)			windows_opengl_loadptr("glObjectPtrLabel");
    HH_GL_glGetObjectPtrLabel		  = (PFNGLGETOBJECTPTRLABELPROC)		windows_opengl_loadptr("glGetObjectPtrLabel");
    HH_GL_glGetPointerv			  = (PFNGLGETPOINTERVPROC)			windows_opengl_loadptr("glGetPointerv");
    
    /* note: 4.4 */
    HH_GL_glBufferStorage	    = (PFNGLBUFFERSTORAGEPROC)	   windows_opengl_loadptr("glBufferStorage");
    HH_GL_glClearTexImage	    = (PFNGLCLEARTEXIMAGEPROC)	   windows_opengl_loadptr("glClearTexImage");
    HH_GL_glClearTexSubImage  = (PFNGLCLEARTEXSUBIMAGEPROC)  windows_opengl_loadptr("glClearTexSubImage");
    HH_GL_glBindBuffersBase   = (PFNGLBINDBUFFERSBASEPROC)   windows_opengl_loadptr("glBindBuffersBase");
    HH_GL_glBindBuffersRange  = (PFNGLBINDBUFFERSRANGEPROC)  windows_opengl_loadptr("glBindBuffersRange");
    HH_GL_glBindTextures	    = (PFNGLBINDTEXTURESPROC)	   windows_opengl_loadptr("glBindTextures");
    HH_GL_glBindSamplers	    = (PFNGLBINDSAHH_GLLERSPROC)	   windows_opengl_loadptr("glBindSamplers");
    HH_GL_glBindImageTextures = (PFNGLBINDIMAGETEXTURESPROC) windows_opengl_loadptr("glBindImageTextures");
    HH_GL_glBindVertexBuffers = (PFNGLBINDVERTEXBUFFERSPROC) windows_opengl_loadptr("glBindVertexBuffers");
    
    // 4.5 
    HH_GL_glClipControl				   = (PFNGLCLIPCONTROLPROC)			         windows_opengl_loadptr("glClipControl");
    HH_GL_glCreateTransformFeedbacks		   = (PFNGLCREATETRANSFORMFEEDBACKSPROC)	         windows_opengl_loadptr("glCreateTransformFeedbacks");
    HH_GL_glTransformFeedbackBufferBase		   = (PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)	         windows_opengl_loadptr("glTransformFeedbackBufferBase");
    HH_GL_glTransformFeedbackBufferRange		   = (PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)	         windows_opengl_loadptr("glTransformFeedbackBufferRange");
    HH_GL_glGetTransformFeedbackiv		   = (PFNGLGETTRANSFORMFEEDBACKIVPROC)		         windows_opengl_loadptr("glGetTransformFeedbackiv");
    HH_GL_glGetTransformFeedbacki_v		   = (PFNGLGETTRANSFORMFEEDBACKI_VPROC)		         windows_opengl_loadptr("glGetTransformFeedbacki_v");
    HH_GL_glGetTransformFeedbacki64_v		   = (PFNGLGETTRANSFORMFEEDBACKI64_VPROC)	         windows_opengl_loadptr("glGetTransformFeedbacki64_v");
    HH_GL_glCreateBuffers				   = (PFNGLCREATEBUFFERSPROC)			         windows_opengl_loadptr("glCreateBuffers");
    HH_GL_glNamedBufferStorage			   = (PFNGLNAMEDBUFFERSTORAGEPROC)		         windows_opengl_loadptr("glNamedBufferStorage");
    HH_GL_glNamedBufferData			   = (PFNGLNAMEDBUFFERDATAPROC)			         windows_opengl_loadptr("glNamedBufferData");
    HH_GL_glNamedBufferSubData			   = (PFNGLNAMEDBUFFERSUBDATAPROC)		         windows_opengl_loadptr("glNamedBufferSubData");
    HH_GL_glCopyNamedBufferSubData		   = (PFNGLCOPYNAMEDBUFFERSUBDATAPROC)		         windows_opengl_loadptr("glCopyNamedBufferSubData");
    HH_GL_glClearNamedBufferData			   = (PFNGLCLEARNAMEDBUFFERDATAPROC)		         windows_opengl_loadptr("glClearNamedBufferData");
    HH_GL_glClearNamedBufferSubData		   = (PFNGLCLEARNAMEDBUFFERSUBDATAPROC)		         windows_opengl_loadptr("glClearNamedBufferSubData");
    HH_GL_glMapNamedBuffer			   = (PFNGLMAPNAMEDBUFFERPROC)			         windows_opengl_loadptr("glMapNamedBuffer");
    HH_GL_glMapNamedBufferRange			   = (PFNGLMAPNAMEDBUFFERRANGEPROC)		         windows_opengl_loadptr("glMapNamedBufferRange");
    HH_GL_glUnmapNamedBuffer			   = (PFNGLUNMAPNAMEDBUFFERPROC)		         windows_opengl_loadptr("glUnmapNamedBuffer");
    HH_GL_glFlushMappedNamedBufferRange		   = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)	         windows_opengl_loadptr("glFlushMappedNamedBufferRange");
    HH_GL_glGetNamedBufferParameteriv		   = (PFNGLGETNAMEDBUFFERPARAMETERIVPROC)	         windows_opengl_loadptr("glGetNamedBufferParameteriv");
    HH_GL_glGetNamedBufferParameteri64v		   = (PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)	         windows_opengl_loadptr("glGetNamedBufferParameteri64v");
    HH_GL_glGetNamedBufferPointerv		   = (PFNGLGETNAMEDBUFFERPOINTERVPROC)		         windows_opengl_loadptr("glGetNamedBufferPointerv");
    HH_GL_glGetNamedBufferSubData			   = (PFNGLGETNAMEDBUFFERSUBDATAPROC)		         windows_opengl_loadptr("glGetNamedBufferSubData");
    HH_GL_glCreateFramebuffers			   = (PFNGLCREATEFRAMEBUFFERSPROC)		         windows_opengl_loadptr("glCreateFramebuffers");
    HH_GL_glNamedFramebufferRenderbuffer		   = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)	         windows_opengl_loadptr("glNamedFramebufferRenderbuffer");
    HH_GL_glNamedFramebufferParameteri		   = (PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)	         windows_opengl_loadptr("glNamedFramebufferParameteri");
    HH_GL_glNamedFramebufferTexture		   = (PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)		         windows_opengl_loadptr("glNamedFramebufferTexture");
    HH_GL_glNamedFramebufferTextureLayer		   = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)	         windows_opengl_loadptr("glNamedFramebufferTextureLayer");
    HH_GL_glNamedFramebufferDrawBuffer		   = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)	         windows_opengl_loadptr("glNamedFramebufferDrawBuffer");
    HH_GL_glNamedFramebufferDrawBuffers		   = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)	         windows_opengl_loadptr("glNamedFramebufferDrawBuffers");
    HH_GL_glNamedFramebufferReadBuffer		   = (PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)	         windows_opengl_loadptr("glNamedFramebufferReadBuffer");
    HH_GL_glInvalidateNamedFramebufferData	   = (PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)	         windows_opengl_loadptr("glInvalidateNamedFramebufferData");
    HH_GL_glInvalidateNamedFramebufferSubData	   = (PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)        windows_opengl_loadptr("glInvalidateNamedFramebufferSubData");
    HH_GL_glClearNamedFramebufferiv		   = (PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)		         windows_opengl_loadptr("glClearNamedFramebufferiv");
    HH_GL_glClearNamedFramebufferuiv		   = (PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)	         windows_opengl_loadptr("glClearNamedFramebufferuiv");
    HH_GL_glClearNamedFramebufferfv		   = (PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)		         windows_opengl_loadptr("glClearNamedFramebufferfv");
    HH_GL_glClearNamedFramebufferfi		   = (PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)		         windows_opengl_loadptr("glClearNamedFramebufferfi");
    HH_GL_glBlitNamedFramebuffer			   = (PFNGLBLITNAMEDFRAMEBUFFERPROC)		         windows_opengl_loadptr("glBlitNamedFramebuffer");
    HH_GL_glCheckNamedFramebufferStatus		   = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)	         windows_opengl_loadptr("glCheckNamedFramebufferStatus");
    HH_GL_glGetNamedFramebufferParameteriv	   = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)	         windows_opengl_loadptr("glGetNamedFramebufferParameteriv");
    HH_GL_glGetNamedFramebufferAttachmentParameteriv = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC) windows_opengl_loadptr("glGetNamedFramebufferAttachmentParameteriv");
    HH_GL_glCreateRenderbuffers			   = (PFNGLCREATERENDERBUFFERSPROC)			 windows_opengl_loadptr("glCreateRenderbuffers");
    HH_GL_glNamedRenderbufferStorage		   = (PFNGLNAMEDRENDERBUFFERSTORAGEPROC)		 windows_opengl_loadptr("glNamedRenderbufferStorage");
    HH_GL_glNamedRenderbufferStorageMultisample	   = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAHH_GLLEPROC)	 windows_opengl_loadptr("glNamedRenderbufferStorageMultisample");
    HH_GL_glGetNamedRenderbufferParameteriv	   = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)	         windows_opengl_loadptr("glGetNamedRenderbufferParameteriv");
    HH_GL_glCreateTextures			   = (PFNGLCREATETEXTURESPROC)			         windows_opengl_loadptr("glCreateTextures");
    HH_GL_glTextureBuffer				   = (PFNGLTEXTUREBUFFERPROC)			         windows_opengl_loadptr("glTextureBuffer");
    HH_GL_glTextureBufferRange			   = (PFNGLTEXTUREBUFFERRANGEPROC)		         windows_opengl_loadptr("glTextureBufferRange");
    HH_GL_glTextureStorage1D			   = (PFNGLTEXTURESTORAGE1DPROC)		         windows_opengl_loadptr("glTextureStorage1D");
    HH_GL_glTextureStorage2D			   = (PFNGLTEXTURESTORAGE2DPROC)		         windows_opengl_loadptr("glTextureStorage2D");
    HH_GL_glTextureStorage3D			   = (PFNGLTEXTURESTORAGE3DPROC)		         windows_opengl_loadptr("glTextureStorage3D");
    HH_GL_glTextureStorage2DMultisample		   = (PFNGLTEXTURESTORAGE2DMULTISAHH_GLLEPROC)	         windows_opengl_loadptr("glTextureStorage2DMultisample");
    HH_GL_glTextureStorage3DMultisample		   = (PFNGLTEXTURESTORAGE3DMULTISAHH_GLLEPROC)	         windows_opengl_loadptr("glTextureStorage3DMultisample");
    HH_GL_glTextureSubImage1D			   = (PFNGLTEXTURESUBIMAGE1DPROC)		         windows_opengl_loadptr("glTextureSubImage1D");
    HH_GL_glTextureSubImage2D			   = (PFNGLTEXTURESUBIMAGE2DPROC)		         windows_opengl_loadptr("glTextureSubImage2D");
    HH_GL_glTextureSubImage3D			   = (PFNGLTEXTURESUBIMAGE3DPROC)		         windows_opengl_loadptr("glTextureSubImage3D");
    HH_GL_glCompressedTextureSubImage1D		   = (PFNGLCOHH_GLRESSEDTEXTURESUBIMAGE1DPROC)	         windows_opengl_loadptr("glCompressedTextureSubImage1D");
    HH_GL_glCompressedTextureSubImage2D		   = (PFNGLCOHH_GLRESSEDTEXTURESUBIMAGE2DPROC)	         windows_opengl_loadptr("glCompressedTextureSubImage2D");
    HH_GL_glCompressedTextureSubImage3D		   = (PFNGLCOHH_GLRESSEDTEXTURESUBIMAGE3DPROC)	         windows_opengl_loadptr("glCompressedTextureSubImage3D");
    HH_GL_glCopyTextureSubImage1D			   = (PFNGLCOPYTEXTURESUBIMAGE1DPROC)		         windows_opengl_loadptr("glCopyTextureSubImage1D");
    HH_GL_glCopyTextureSubImage2D			   = (PFNGLCOPYTEXTURESUBIMAGE2DPROC)		         windows_opengl_loadptr("glCopyTextureSubImage2D");
    HH_GL_glCopyTextureSubImage3D			   = (PFNGLCOPYTEXTURESUBIMAGE3DPROC)		         windows_opengl_loadptr("glCopyTextureSubImage3D");
    HH_GL_glTextureParameterf			   = (PFNGLTEXTUREPARAMETERFPROC)		         windows_opengl_loadptr("glTextureParameterf");
    HH_GL_glTextureParameterfv			   = (PFNGLTEXTUREPARAMETERFVPROC)		         windows_opengl_loadptr("glTextureParameterfv");
    HH_GL_glTextureParameteri			   = (PFNGLTEXTUREPARAMETERIPROC)		         windows_opengl_loadptr("glTextureParameteri");
    HH_GL_glTextureParameterIiv			   = (PFNGLTEXTUREPARAMETERIIVPROC)		         windows_opengl_loadptr("glTextureParameterIiv");
    HH_GL_glTextureParameterIuiv			   = (PFNGLTEXTUREPARAMETERIUIVPROC)		         windows_opengl_loadptr("glTextureParameterIuiv");
    HH_GL_glTextureParameteriv			   = (PFNGLTEXTUREPARAMETERIVPROC)		         windows_opengl_loadptr("glTextureParameteriv");
    HH_GL_glGenerateTextureMipmap			   = (PFNGLGENERATETEXTUREMIPMAPPROC)		         windows_opengl_loadptr("glGenerateTextureMipmap");
    HH_GL_glBindTextureUnit			   = (PFNGLBINDTEXTUREUNITPROC)			         windows_opengl_loadptr("glBindTextureUnit");
    HH_GL_glGetTextureImage			   = (PFNGLGETTEXTUREIMAGEPROC)			         windows_opengl_loadptr("glGetTextureImage");
    HH_GL_glGetCompressedTextureImage		   = (PFNGLGETCOHH_GLRESSEDTEXTUREIMAGEPROC)	         windows_opengl_loadptr("glGetCompressedTextureImage");
    HH_GL_glGetTextureLevelParameterfv		   = (PFNGLGETTEXTURELEVELPARAMETERFVPROC)	         windows_opengl_loadptr("glGetTextureLevelParameterfv");
    HH_GL_glGetTextureLevelParameteriv		   = (PFNGLGETTEXTURELEVELPARAMETERIVPROC)	         windows_opengl_loadptr("glGetTextureLevelParameteriv");
    HH_GL_glGetTextureParameterfv			   = (PFNGLGETTEXTUREPARAMETERFVPROC)		         windows_opengl_loadptr("glGetTextureParameterfv");
    HH_GL_glGetTextureParameterIiv		   = (PFNGLGETTEXTUREPARAMETERIIVPROC)		         windows_opengl_loadptr("glGetTextureParameterIiv");
    HH_GL_glGetTextureParameterIuiv		   = (PFNGLGETTEXTUREPARAMETERIUIVPROC)		         windows_opengl_loadptr("glGetTextureParameterIuiv");
    HH_GL_glGetTextureParameteriv			   = (PFNGLGETTEXTUREPARAMETERIVPROC)		         windows_opengl_loadptr("glGetTextureParameteriv");
    HH_GL_glCreateVertexArrays			   = (PFNGLCREATEVERTEXARRAYSPROC)		         windows_opengl_loadptr("glCreateVertexArrays");
    HH_GL_glDisableVertexArrayAttrib		   = (PFNGLDISABLEVERTEXARRAYATTRIBPROC)	         windows_opengl_loadptr("glDisableVertexArrayAttrib");
    HH_GL_glEnableVertexArrayAttrib		   = (PFNGLENABLEVERTEXARRAYATTRIBPROC)		         windows_opengl_loadptr("glEnableVertexArrayAttrib");
    HH_GL_glVertexArrayElementBuffer		   = (PFNGLVERTEXARRAYELEMENTBUFFERPROC)	         windows_opengl_loadptr("glVertexArrayElementBuffer");
    HH_GL_glVertexArrayVertexBuffer		   = (PFNGLVERTEXARRAYVERTEXBUFFERPROC)		         windows_opengl_loadptr("glVertexArrayVertexBuffer");
    HH_GL_glVertexArrayVertexBuffers		   = (PFNGLVERTEXARRAYVERTEXBUFFERSPROC)	         windows_opengl_loadptr("glVertexArrayVertexBuffers");
    HH_GL_glVertexArrayAttribBinding		   = (PFNGLVERTEXARRAYATTRIBBINDINGPROC)	         windows_opengl_loadptr("glVertexArrayAttribBinding");
    HH_GL_glVertexArrayAttribFormat		   = (PFNGLVERTEXARRAYATTRIBFORMATPROC)		         windows_opengl_loadptr("glVertexArrayAttribFormat");
    HH_GL_glVertexArrayAttribIFormat		   = (PFNGLVERTEXARRAYATTRIBIFORMATPROC)	         windows_opengl_loadptr("glVertexArrayAttribIFormat");
    HH_GL_glVertexArrayAttribLFormat		   = (PFNGLVERTEXARRAYATTRIBLFORMATPROC)	         windows_opengl_loadptr("glVertexArrayAttribLFormat");
    HH_GL_glVertexArrayBindingDivisor		   = (PFNGLVERTEXARRAYBINDINGDIVISORPROC)	         windows_opengl_loadptr("glVertexArrayBindingDivisor");
    HH_GL_glGetVertexArrayiv			   = (PFNGLGETVERTEXARRAYIVPROC)		         windows_opengl_loadptr("glGetVertexArrayiv");
    HH_GL_glGetVertexArrayIndexediv		   = (PFNGLGETVERTEXARRAYINDEXEDIVPROC)		         windows_opengl_loadptr("glGetVertexArrayIndexediv");
    HH_GL_glGetVertexArrayIndexed64iv		   = (PFNGLGETVERTEXARRAYINDEXED64IVPROC)	         windows_opengl_loadptr("glGetVertexArrayIndexed64iv");
    HH_GL_glCreateSamplers			   = (PFNGLCREATESAHH_GLLERSPROC)			         windows_opengl_loadptr("glCreateSamplers");
    HH_GL_glCreateProgramPipelines		   = (PFNGLCREATEPROGRAHH_GLIPELINESPROC)		         windows_opengl_loadptr("glCreateProgramPipelines");
    HH_GL_glCreateQueries				   = (PFNGLCREATEQUERIESPROC)			         windows_opengl_loadptr("glCreateQueries");
    HH_GL_glGetQueryBufferObjecti64v		   = (PFNGLGETQUERYBUFFEROBJECTI64VPROC)	         windows_opengl_loadptr("glGetQueryBufferObjecti64v");
    HH_GL_glGetQueryBufferObjectiv		   = (PFNGLGETQUERYBUFFEROBJECTIVPROC)		         windows_opengl_loadptr("glGetQueryBufferObjectiv");
    HH_GL_glGetQueryBufferObjectui64v		   = (PFNGLGETQUERYBUFFEROBJECTUI64VPROC)	         windows_opengl_loadptr("glGetQueryBufferObjectui64v");
    HH_GL_glGetQueryBufferObjectuiv		   = (PFNGLGETQUERYBUFFEROBJECTUIVPROC)		         windows_opengl_loadptr("glGetQueryBufferObjectuiv");
    HH_GL_glMemoryBarrierByRegion			   = (PFNGLMEMORYBARRIERBYREGIONPROC)		         windows_opengl_loadptr("glMemoryBarrierByRegion");
    HH_GL_glGetTextureSubImage			   = (PFNGLGETTEXTURESUBIMAGEPROC)		         windows_opengl_loadptr("glGetTextureSubImage");
    HH_GL_glGetCompressedTextureSubImage		   = (PFNGLGETCOHH_GLRESSEDTEXTURESUBIMAGEPROC)	         windows_opengl_loadptr("glGetCompressedTextureSubImage");
    HH_GL_glGetGraphicsResetStatus		   = (PFNGLGETGRAPHICSRESETSTATUSPROC)		         windows_opengl_loadptr("glGetGraphicsResetStatus");
    HH_GL_glGetnCompressedTexImage		   = (PFNGLGETNCOHH_GLRESSEDTEXIMAGEPROC)		         windows_opengl_loadptr("glGetnCompressedTexImage");
    HH_GL_glGetnTexImage				   = (PFNGLGETNTEXIMAGEPROC)			         windows_opengl_loadptr("glGetnTexImage");
    HH_GL_glGetnUniformdv				   = (PFNGLGETNUNIFORMDVPROC)			         windows_opengl_loadptr("glGetnUniformdv");
    HH_GL_glGetnUniformfv				   = (PFNGLGETNUNIFORMFVPROC)			         windows_opengl_loadptr("glGetnUniformfv");
    HH_GL_glGetnUniformiv				   = (PFNGLGETNUNIFORMIVPROC)			         windows_opengl_loadptr("glGetnUniformiv");
    HH_GL_glGetnUniformuiv			   = (PFNGLGETNUNIFORMUIVPROC)			         windows_opengl_loadptr("glGetnUniformuiv");
    HH_GL_glReadnPixels				   = (PFNGLREADNPIXELSPROC)			         windows_opengl_loadptr("glReadnPixels");
    HH_GL_glGetnMapdv				   = (PFNGLGETNMAPDVPROC)			         windows_opengl_loadptr("glGetnMapdv");
    HH_GL_glGetnMapfv				   = (PFNGLGETNMAPFVPROC)			         windows_opengl_loadptr("glGetnMapfv");
    HH_GL_glGetnMapiv				   = (PFNGLGETNMAPIVPROC)			         windows_opengl_loadptr("glGetnMapiv");
    HH_GL_glGetnPixelMapfv			   = (PFNGLGETNPIXELMAPFVPROC)			         windows_opengl_loadptr("glGetnPixelMapfv");
    HH_GL_glGetnPixelMapuiv			   = (PFNGLGETNPIXELMAPUIVPROC)			         windows_opengl_loadptr("glGetnPixelMapuiv");
    HH_GL_glGetnPixelMapusv			   = (PFNGLGETNPIXELMAPUSVPROC)			         windows_opengl_loadptr("glGetnPixelMapusv");
    HH_GL_glGetnPolygonStipple			   = (PFNGLGETNPOLYGONSTIPPLEPROC)		         windows_opengl_loadptr("glGetnPolygonStipple");
    HH_GL_glGetnColorTable			   = (PFNGLGETNCOLORTABLEPROC)			         windows_opengl_loadptr("glGetnColorTable");
    HH_GL_glGetnConvolutionFilter			   = (PFNGLGETNCONVOLUTIONFILTERPROC)		         windows_opengl_loadptr("glGetnConvolutionFilter");
    HH_GL_glGetnSeparableFilter			   = (PFNGLGETNSEPARABLEFILTERPROC)		         windows_opengl_loadptr("glGetnSeparableFilter");
    HH_GL_glGetnHistogram				   = (PFNGLGETNHISTOGRAHH_GLROC)			         windows_opengl_loadptr("glGetnHistogram");
    HH_GL_glGetnMinmax				   = (PFNGLGETNMINMAXPROC)			         windows_opengl_loadptr("glGetnMinmax");
    HH_GL_glTextureBarrier			   = (PFNGLTEXTUREBARRIERPROC)			         windows_opengl_loadptr("glTextureBarrier");
    
    // 4.6 
    HH_GL_glSpecializeShader		     = (PFNGLSPECIALIZESHADERPROC)		 windows_opengl_loadptr("glSpecializeShader");
    HH_GL_glMultiDrawArraysIndirectCount   = (PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)   windows_opengl_loadptr("glMultiDrawArraysIndirectCount");
    HH_GL_glMultiDrawElementsIndirectCount = (PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC) windows_opengl_loadptr("glMultiDrawElementsIndirectCount");
    HH_GL_glPolygonOffsetClamp	     = (PFNGLPOLYGONOFFSETCLAHH_GLPROC)	         windows_opengl_loadptr("glPolygonOffsetClamp");
}

internal b32
windows_opengl_initialise(HDC dc)
{
    b32 result = true;

    PIXELFORMATDESCRIPTOR pixel_format = {};
    pixel_format.nSize      = sizeof(PIXELFORMATDESCRIPTOR);
    pixel_format.nVersion   = 1;
    pixel_format.dwFlags    = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pixel_format.cColorBits = 32;
    pixel_format.cRedBits   = 8;
    pixel_format.cGreenBits = 8;
    pixel_format.cBlueBits  = 8;
    pixel_format.cAlphaBits = 8;

    s32 format_index = ChoosePixelFormat(dc, &pixel_format);
    if(format_index)
    {
	if(!DescribePixelFormat(dc, format_index, sizeof(PIXELFORMATDESCRIPTOR), &pixel_format))
	{
	    OutputDebugStringA("'DescribePixelFormat' failed!\n");
	    result = false;
	}
    }
    else
    {
	OutputDebugStringA("'ChoosePixelFormat' failed!\n");
	result = false;
    }
    
    if(SetPixelFormat(dc, format_index, &pixel_format))
    {
	HGLRC rendering_context = wglCreateContext(dc); //important: we need to do stuff so we can be more specific about the context we're creating
	if(rendering_context)
	{
	    if(!wglMakeCurrent(dc, rendering_context))
	    {
		OutputDebugStringA("'wglMakeCurrent' failed!\n");
		result = false;
	    }
	}
	else
	{
	    OutputDebugStringA("'wglCreateContext' failed!\n");
	    result = false;
	}
    }
    else
    {
	OutputDebugStringA("'SetPixelFormat' failed!\n");
	result = false;
    }

    HMODULE library = LoadLibraryA("opengl32.dll");
    if(library)
    {	
	windows_opengl_version_1(library); 
	windows_opengl_version_2();        
	windows_opengl_version_3();        
	windows_opengl_version_4();        
    }
    else
    {
	OutputDebugStringA("'LoadLibraryA' failed!\n");
	result = false;
    }
    
    return(result);
}

internal void
windows_opengl_updateviewport(s32 width, s32 height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}
