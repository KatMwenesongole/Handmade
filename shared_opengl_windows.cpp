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
    SharedGL_glCullFace		 = (PFNGLCULLFACEPROC)               windows_opengl_loadptr(lib, "glCullFace");
    SharedGL_glFrontFace		 = (PFNGLFRONTFACEPROC)              windows_opengl_loadptr(lib, "glFrontFace");
    SharedGL_glHint		 = (PFNGLHINTPROC)                   windows_opengl_loadptr(lib, "glHint");
    SharedGL_glLineWidth		 = (PFNGLLINEWIDTHPROC)              windows_opengl_loadptr(lib, "glLineWidth");
    SharedGL_glPointSize		 = (PFNGLPOINTSIZEPROC)              windows_opengl_loadptr(lib, "glPointSize");
    SharedGL_glPolygonMode		 = (PFNGLPOLYGONMODEPROC)            windows_opengl_loadptr(lib, "glPolygonMode");
    SharedGL_glScissor		 = (PFNGLSCISSORPROC)                windows_opengl_loadptr(lib, "glScissor");
    SharedGL_glTexParameterf		 = (PFNGLTEXPARAMETERFPROC)          windows_opengl_loadptr(lib, "glTexParameterf");
    SharedGL_glTexParameterfv	 = (PFNGLTEXPARAMETERFVPROC)         windows_opengl_loadptr(lib, "glTexParameterfv");
    SharedGL_glTexParameteri		 = (PFNGLTEXPARAMETERIPROC)          windows_opengl_loadptr(lib, "glTexParameteri");
    SharedGL_glTexParameteriv	 = (PFNGLTEXPARAMETERIVPROC)         windows_opengl_loadptr(lib, "glTexParameteriv");
    SharedGL_glTexImage1D		 = (PFNGLTEXIMAGE1DPROC)             windows_opengl_loadptr(lib, "glTexImage1D");
    SharedGL_glTexImage2D		 = (PFNGLTEXIMAGE2DPROC)             windows_opengl_loadptr(lib, "glTexImage2D");
    SharedGL_glDrawBuffer		 = (PFNGLDRAWBUFFERPROC)             windows_opengl_loadptr(lib, "glDrawBuffer");
    SharedGL_glClear			 = (PFNGLCLEARPROC)                  windows_opengl_loadptr(lib, "glClear");
    SharedGL_glClearColor		 = (PFNGLCLEARCOLORPROC)             windows_opengl_loadptr(lib, "glClearColor");
    SharedGL_glClearStencil		 = (PFNGLCLEARSTENCILPROC)           windows_opengl_loadptr(lib, "glClearStencil");
    SharedGL_glClearDepth		 = (PFNGLCLEARDEPTHPROC)             windows_opengl_loadptr(lib, "glClearDepth");
    SharedGL_glStencilMask		 = (PFNGLSTENCILMASKPROC)            windows_opengl_loadptr(lib, "glStencilMask");
    SharedGL_glColorMask		 = (PFNGLCOLORMASKPROC)              windows_opengl_loadptr(lib, "glColorMask");
    SharedGL_glDepthMask		 = (PFNGLDEPTHMASKPROC)              windows_opengl_loadptr(lib, "glDepthMask");
    SharedGL_glDisable		 = (PFNGLDISABLEPROC)                windows_opengl_loadptr(lib, "glDisable");
    SharedGL_glEnable		 = (PFNGLENABLEPROC)                 windows_opengl_loadptr(lib, "glEnable");
    SharedGL_glFinish		 = (PFNGLFINISHPROC)                 windows_opengl_loadptr(lib, "glFinish");
    SharedGL_glFlush			 = (PFNGLFLUSHPROC)                  windows_opengl_loadptr(lib, "glFlush");
    SharedGL_glBlendFunc		 = (PFNGLBLENDFUNCPROC)              windows_opengl_loadptr(lib, "glBlendFunc");
    SharedGL_glLogicOp		 = (PFNGLLOGICOPPROC)                windows_opengl_loadptr(lib, "glLogicOp");
    SharedGL_glStencilFunc		 = (PFNGLSTENCILFUNCPROC)            windows_opengl_loadptr(lib, "glStencilFunc");
    SharedGL_glStencilOp		 = (PFNGLSTENCILOPPROC)              windows_opengl_loadptr(lib, "glStencilOp");
    SharedGL_glDepthFunc		 = (PFNGLDEPTHFUNCPROC)              windows_opengl_loadptr(lib, "glDepthFunc");
    SharedGL_glPixelStoref		 = (PFNGLPIXELSTOREFPROC)            windows_opengl_loadptr(lib, "glPixelStoref");
    SharedGL_glPixelStorei		 = (PFNGLPIXELSTOREIPROC)            windows_opengl_loadptr(lib, "glPixelStorei");
    SharedGL_glReadBuffer		 = (PFNGLREADBUFFERPROC)             windows_opengl_loadptr(lib, "glReadBuffer");
    SharedGL_glReadPixels		 = (PFNGLREADPIXELSPROC)             windows_opengl_loadptr(lib, "glReadPixels");
    SharedGL_glGetBooleanv		 = (PFNGLGETBOOLEANVPROC)            windows_opengl_loadptr(lib, "glGetBooleanv");
    SharedGL_glGetDoublev		 = (PFNGLGETDOUBLEVPROC)             windows_opengl_loadptr(lib, "glGetDoublev");
    SharedGL_glGetError		 = (PFNGLGETERRORPROC)               windows_opengl_loadptr(lib, "glGetError");
    SharedGL_glGetFloatv		 = (PFNGLGETFLOATVPROC)              windows_opengl_loadptr(lib, "glGetFloatv");
    SharedGL_glGetIntegerv		 = (PFNGLGETINTEGERVPROC)            windows_opengl_loadptr(lib, "glGetIntegerv");
    SharedGL_glGetString		 = (PFNGLGETSTRINGPROC)              windows_opengl_loadptr(lib, "glGetString");
    SharedGL_glGetTexImage		 = (PFNGLGETTEXIMAGEPROC)            windows_opengl_loadptr(lib, "glGetTexImage");
    SharedGL_glGetTexParameterfv	 = (PFNGLGETTEXPARAMETERFVPROC)      windows_opengl_loadptr(lib, "glGetTexParameterfv");
    SharedGL_glGetTexParameteriv	 = (PFNGLGETTEXPARAMETERIVPROC)      windows_opengl_loadptr(lib, "glGetTexParameteriv");
    SharedGL_glGetTexLevelParameterfv = (PFNGLGETTEXLEVELPARAMETERFVPROC) windows_opengl_loadptr(lib, "glGetTexLevelParameterfv");
    SharedGL_glGetTexLevelParameteriv = (PFNGLGETTEXLEVELPARAMETERIVPROC) windows_opengl_loadptr(lib, "glGetTexLevelParameteriv");
    SharedGL_glIsEnabled		 = (PFNGLISENABLEDPROC)              windows_opengl_loadptr(lib, "glIsEnabled");
    SharedGL_glDepthRange		 = (PFNGLDEPTHRANGEPROC)             windows_opengl_loadptr(lib, "glDepthRange");
    SharedGL_glViewport		 = (PFNGLVIEWPORTPROC)               windows_opengl_loadptr(lib, "glViewport");

    // 1.1 
    SharedGL_glDrawArrays	    = (PFNGLDRAWARRAYSPROC)        windows_opengl_loadptr(lib, "glDrawArrays");
    SharedGL_glDrawElements	    = (PFNGLDRAWELEMENTSPROC)      windows_opengl_loadptr(lib, "glDrawElements");
    SharedGL_glPolygonOffset	    = (PFNGLPOLYGONOFFSETPROC)     windows_opengl_loadptr(lib, "glPolygonOffset");
    SharedGL_glCopyTexImage1D    = (PFNGLCOPYTEXIMAGE1DPROC)    windows_opengl_loadptr(lib, "glCopyTexImage1D");
    SharedGL_glCopyTexImage2D    = (PFNGLCOPYTEXIMAGE2DPROC)    windows_opengl_loadptr(lib, "glCopyTexImage2D");
    SharedGL_glCopyTexSubImage1D = (PFNGLCOPYTEXSUBIMAGE1DPROC) windows_opengl_loadptr(lib, "glCopyTexSubImage1D");
    SharedGL_glCopyTexSubImage2D = (PFNGLCOPYTEXSUBIMAGE2DPROC) windows_opengl_loadptr(lib, "glCopyTexSubImage2D");
    SharedGL_glTexSubImage1D	    = (PFNGLTEXSUBIMAGE1DPROC)     windows_opengl_loadptr(lib, "glTexSubImage1D");
    SharedGL_glTexSubImage2D	    = (PFNGLTEXSUBIMAGE2DPROC)     windows_opengl_loadptr(lib, "glTexSubImage2D");
    SharedGL_glBindTexture	    = (PFNGLBINDTEXTUREPROC)       windows_opengl_loadptr(lib, "glBindTexture");
    SharedGL_glDeleteTextures    = (PFNGLDELETETEXTURESPROC)    windows_opengl_loadptr(lib, "glDeleteTextures");
    SharedGL_glGenTextures	    = (PFNGLGENTEXTURESPROC)       windows_opengl_loadptr(lib, "glGenTextures");
    SharedGL_glIsTexture	    = (PFNGLISTEXTUREPROC)         windows_opengl_loadptr(lib, "glIsTexture");

    // 1.2
    SharedGL_glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC) windows_opengl_loadptr("glDrawRangeElements");
    SharedGL_glTexImage3D        = (PFNGLTEXIMAGE3DPROC)        windows_opengl_loadptr("glTexImage3D");
    SharedGL_glTexSubImage3D     = (PFNGLTEXSUBIMAGE3DPROC)     windows_opengl_loadptr("glTexSubImage3D");
    SharedGL_glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC) windows_opengl_loadptr("glCopyTexSubImage3D");

    // 1.3 
    SharedGL_glActiveTexture		  = (PFNGLACTIVETEXTUREPROC)           windows_opengl_loadptr("glActiveTexture");
    SharedGL_glSampleCoverage	  = (PFNGLSASharedGLLECOVERAGEPROC)          windows_opengl_loadptr("glSampleCoverage");
    SharedGL_glCompressedTexImage3D	  = (PFNGLCOSharedGLRESSEDTEXIMAGE3DPROC)    windows_opengl_loadptr("glCompressedTexImage3D");
    SharedGL_glCompressedTexImage2D	  = (PFNGLCOSharedGLRESSEDTEXIMAGE2DPROC)    windows_opengl_loadptr("glCompressedTexImage2D");
    SharedGL_glCompressedTexImage1D	  = (PFNGLCOSharedGLRESSEDTEXIMAGE1DPROC)    windows_opengl_loadptr("glCompressedTexImage1D");
    SharedGL_glCompressedTexSubImage3D = (PFNGLCOSharedGLRESSEDTEXSUBIMAGE3DPROC) windows_opengl_loadptr("glCompressedTexSubImage3D");
    SharedGL_glCompressedTexSubImage2D = (PFNGLCOSharedGLRESSEDTEXSUBIMAGE2DPROC) windows_opengl_loadptr("glCompressedTexSubImage2D");
    SharedGL_glCompressedTexSubImage1D = (PFNGLCOSharedGLRESSEDTEXSUBIMAGE1DPROC) windows_opengl_loadptr("glCompressedTexSubImage1D");
    SharedGL_glGetCompressedTexImage	  = (PFNGLGETCOSharedGLRESSEDTEXIMAGEPROC)   windows_opengl_loadptr("glGetCompressedTexImage");
    
    // 1.4 
    SharedGL_glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC) windows_opengl_loadptr("glBlendFuncSeparate");
    SharedGL_glMultiDrawArrays   = (PFNGLMULTIDRAWARRAYSPROC)   windows_opengl_loadptr("glMultiDrawArrays");
    SharedGL_glMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC) windows_opengl_loadptr("glMultiDrawElements");
    SharedGL_glPointParameterf   = (PFNGLPOINTPARAMETERFPROC)   windows_opengl_loadptr("glPointParameterf");
    SharedGL_glPointParameterfv  = (PFNGLPOINTPARAMETERFVPROC)  windows_opengl_loadptr("glPointParameterfv");
    SharedGL_glPointParameteri   = (PFNGLPOINTPARAMETERIPROC)   windows_opengl_loadptr("glPointParameteri");
    SharedGL_glPointParameteriv  = (PFNGLPOINTPARAMETERIVPROC)  windows_opengl_loadptr("glPointParameteriv");
    SharedGL_glBlendColor	    = (PFNGLBLENDCOLORPROC)        windows_opengl_loadptr("glBlendColor");
    SharedGL_glBlendEquation	    = (PFNGLBLENDEQUATIONPROC)     windows_opengl_loadptr("glBlendEquation");
    
    // 1.5
    SharedGL_glGenQueries	       = (PFNGLGENQUERIESPROC)           windows_opengl_loadptr("glGenQueries");
    SharedGL_glDeleteQueries	       = (PFNGLDELETEQUERIESPROC)        windows_opengl_loadptr("glDeleteQueries");
    SharedGL_glIsQuery	       = (PFNGLISQUERYPROC)              windows_opengl_loadptr("glIsQuery");
    SharedGL_glBeginQuery	       = (PFNGLBEGINQUERYPROC)           windows_opengl_loadptr("glBeginQuery");
    SharedGL_glEndQuery	       = (PFNGLENDQUERYPROC)             windows_opengl_loadptr("glEndQuery");
    SharedGL_glGetQueryiv	       = (PFNGLGETQUERYIVPROC)           windows_opengl_loadptr("glGetQueryiv");
    SharedGL_glGetQueryObjectiv     = (PFNGLGETQUERYOBJECTIVPROC)     windows_opengl_loadptr("glGetQueryObjectiv");
    SharedGL_glGetQueryObjectuiv    = (PFNGLGETQUERYOBJECTUIVPROC)    windows_opengl_loadptr("glGetQueryObjectuiv");
    SharedGL_glBindBuffer	       = (PFNGLBINDBUFFERPROC)           windows_opengl_loadptr("glBindBuffer");
    SharedGL_glDeleteBuffers	       = (PFNGLDELETEBUFFERSPROC)        windows_opengl_loadptr("glDeleteBuffers");
    SharedGL_glGenBuffers	       = (PFNGLGENBUFFERSPROC)           windows_opengl_loadptr("glGenBuffers");
    SharedGL_glIsBuffer	       = (PFNGLISBUFFERPROC)             windows_opengl_loadptr("glIsBuffer");
    SharedGL_glBufferData	       = (PFNGLBUFFERDATAPROC)           windows_opengl_loadptr("glBufferData");
    SharedGL_glBufferSubData	       = (PFNGLBUFFERSUBDATAPROC)        windows_opengl_loadptr("glBufferSubData");
    SharedGL_glGetBufferSubData     = (PFNGLGETBUFFERSUBDATAPROC)     windows_opengl_loadptr("glGetBufferSubData");
    SharedGL_glMapBuffer	       = (PFNGLMAPBUFFERPROC)            windows_opengl_loadptr("glMapBuffer");
    SharedGL_glUnmapBuffer	       = (PFNGLUNMAPBUFFERPROC)          windows_opengl_loadptr("glUnmapBuffer");
    SharedGL_glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC) windows_opengl_loadptr("glGetBufferParameteriv");
    SharedGL_glGetBufferPointerv    = (PFNGLGETBUFFERPOINTERVPROC)    windows_opengl_loadptr("glGetBufferPointerv");
}
internal void
windows_opengl_version_2()
{
    // 2.0 
    SharedGL_glBlendEquationSeparate	   = (PFNGLBLENDEQUATIONSEPARATEPROC) 	 windows_opengl_loadptr("glBlendEquationSeparate");
    SharedGL_glDrawBuffers		   = (PFNGLDRAWBUFFERSPROC)		 windows_opengl_loadptr("glDrawBuffers");
    SharedGL_glStencilOpSeparate	   = (PFNGLSTENCILOPSEPARATEPROC)	 windows_opengl_loadptr("glStencilOpSeparate");
    SharedGL_glStencilFuncSeparate	   = (PFNGLSTENCILFUNCSEPARATEPROC)	 windows_opengl_loadptr("glStencilFuncSeparate");
    SharedGL_glStencilMaskSeparate	   = (PFNGLSTENCILMASKSEPARATEPROC)	 windows_opengl_loadptr("glStencilMaskSeparate");
    SharedGL_glAttachShader		   = (PFNGLATTACHSHADERPROC)		 windows_opengl_loadptr("glAttachShader");
    SharedGL_glBindAttribLocation	   = (PFNGLBINDATTRIBLOCATIONPROC)	 windows_opengl_loadptr("glBindAttribLocation");
    SharedGL_glCompileShader		   = (PFNGLCOSharedGLILESHADERPROC)		 windows_opengl_loadptr("glCompileShader");
    SharedGL_glCreateProgram		   = (PFNGLCREATEPROGRASharedGLROC)		 windows_opengl_loadptr("glCreateProgram");
    SharedGL_glCreateShader		   = (PFNGLCREATESHADERPROC)		 windows_opengl_loadptr("glCreateShader");
    SharedGL_glDeleteProgram		   = (PFNGLDELETEPROGRASharedGLROC)		 windows_opengl_loadptr("glDeleteProgram");
    SharedGL_glDeleteShader		   = (PFNGLDELETESHADERPROC)		 windows_opengl_loadptr("glDeleteShader");
    SharedGL_glDetachShader		   = (PFNGLDETACHSHADERPROC)		 windows_opengl_loadptr("glDetachShader");
    SharedGL_glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC) windows_opengl_loadptr("glDisableVertexAttribArray");
    SharedGL_glEnableVertexAttribArray  = (PFNGLENABLEVERTEXATTRIBARRAYPROC)	 windows_opengl_loadptr("glEnableVertexAttribArray");
    SharedGL_glGetActiveAttrib	   = (PFNGLGETACTIVEATTRIBPROC)		 windows_opengl_loadptr("glGetActiveAttrib");
    SharedGL_glGetActiveUniform	   = (PFNGLGETACTIVEUNIFORSharedGLROC)	 windows_opengl_loadptr("glGetActiveUniform");
    SharedGL_glGetAttachedShaders	   = (PFNGLGETATTACHEDSHADERSPROC)	 windows_opengl_loadptr("glGetAttachedShaders");
    SharedGL_glGetAttribLocation	   = (PFNGLGETATTRIBLOCATIONPROC)	 windows_opengl_loadptr("glGetAttribLocation");
    SharedGL_glGetProgramiv		   = (PFNGLGETPROGRAMIVPROC)		 windows_opengl_loadptr("glGetProgramiv");
    SharedGL_glGetProgramInfoLog	   = (PFNGLGETPROGRAMINFOLOGPROC)	 windows_opengl_loadptr("glGetProgramInfoLog");
    SharedGL_glGetShaderiv		   = (PFNGLGETSHADERIVPROC)		 windows_opengl_loadptr("glGetShaderiv");
    SharedGL_glGetShaderInfoLog	   = (PFNGLGETSHADERINFOLOGPROC)	 windows_opengl_loadptr("glGetShaderInfoLog");
    SharedGL_glGetShaderSource	   = (PFNGLGETSHADERSOURCEPROC)		 windows_opengl_loadptr("glGetShaderSource");
    SharedGL_glGetUniformLocation	   = (PFNGLGETUNIFORMLOCATIONPROC)	 windows_opengl_loadptr("glGetUniformLocation");
    SharedGL_glGetUniformfv		   = (PFNGLGETUNIFORMFVPROC)		 windows_opengl_loadptr("glGetUniformfv");
    SharedGL_glGetUniformiv		   = (PFNGLGETUNIFORMIVPROC)		 windows_opengl_loadptr("glGetUniformiv");
    SharedGL_glGetVertexAttribdv	   = (PFNGLGETVERTEXATTRIBDVPROC)	 windows_opengl_loadptr("glGetVertexAttribdv");
    SharedGL_glGetVertexAttribfv	   = (PFNGLGETVERTEXATTRIBFVPROC)	 windows_opengl_loadptr("glGetVertexAttribfv");
    SharedGL_glGetVertexAttribiv	   = (PFNGLGETVERTEXATTRIBIVPROC)	 windows_opengl_loadptr("glGetVertexAttribiv");
    SharedGL_glGetVertexAttribPointerv  = (PFNGLGETVERTEXATTRIBPOINTERVPROC)	 windows_opengl_loadptr("glGetVertexAttribPointerv");
    SharedGL_glIsProgram		   = (PFNGLISPROGRASharedGLROC)		 windows_opengl_loadptr("glIsProgram");
    SharedGL_glIsShader		   = (PFNGLISSHADERPROC)		 windows_opengl_loadptr("glIsShader");
    SharedGL_glLinkProgram		   = (PFNGLLINKPROGRASharedGLROC)		 windows_opengl_loadptr("glLinkProgram");
    SharedGL_glShaderSource		   = (PFNGLSHADERSOURCEPROC)		 windows_opengl_loadptr("glShaderSource");
    SharedGL_glUseProgram		   = (PFNGLUSEPROGRASharedGLROC)		 windows_opengl_loadptr("glUseProgram");
    SharedGL_glUniform1f		   = (PFNGLUNIFORM1FPROC)		 windows_opengl_loadptr("glUniform1f");
    SharedGL_glUniform2f		   = (PFNGLUNIFORM2FPROC)		 windows_opengl_loadptr("glUniform2f");
    SharedGL_glUniform3f		   = (PFNGLUNIFORM3FPROC)		 windows_opengl_loadptr("glUniform3f");
    SharedGL_glUniform4f		   = (PFNGLUNIFORM4FPROC)		 windows_opengl_loadptr("glUniform4f");
    SharedGL_glUniform1i		   = (PFNGLUNIFORM1IPROC)		 windows_opengl_loadptr("glUniform1i");
    SharedGL_glUniform2i		   = (PFNGLUNIFORM2IPROC)		 windows_opengl_loadptr("glUniform2i");
    SharedGL_glUniform3i		   = (PFNGLUNIFORM3IPROC)		 windows_opengl_loadptr("glUniform3i");
    SharedGL_glUniform4i		   = (PFNGLUNIFORM4IPROC)		 windows_opengl_loadptr("glUniform4i");
    SharedGL_glUniform1fv		   = (PFNGLUNIFORM1FVPROC)		 windows_opengl_loadptr("glUniform1fv");
    SharedGL_glUniform2fv		   = (PFNGLUNIFORM2FVPROC)		 windows_opengl_loadptr("glUniform2fv");
    SharedGL_glUniform3fv		   = (PFNGLUNIFORM3FVPROC)		 windows_opengl_loadptr("glUniform3fv");
    SharedGL_glUniform4fv		   = (PFNGLUNIFORM4FVPROC)		 windows_opengl_loadptr("glUniform4fv");
    SharedGL_glUniform1iv		   = (PFNGLUNIFORM1IVPROC)		 windows_opengl_loadptr("glUniform1iv");
    SharedGL_glUniform2iv		   = (PFNGLUNIFORM2IVPROC)		 windows_opengl_loadptr("glUniform2iv");
    SharedGL_glUniform3iv		   = (PFNGLUNIFORM3IVPROC)		 windows_opengl_loadptr("glUniform3iv");
    SharedGL_glUniform4iv		   = (PFNGLUNIFORM4IVPROC)		 windows_opengl_loadptr("glUniform4iv");
    SharedGL_glUniformMatrix2fv	   = (PFNGLUNIFORMMATRIX2FVPROC)	 windows_opengl_loadptr("glUniformMatrix2fv");
    SharedGL_glUniformMatrix3fv	   = (PFNGLUNIFORMMATRIX3FVPROC)	 windows_opengl_loadptr("glUniformMatrix3fv");
    SharedGL_glUniformMatrix4fv	   = (PFNGLUNIFORMMATRIX4FVPROC)	 windows_opengl_loadptr("glUniformMatrix4fv");
    SharedGL_glValidateProgram	   = (PFNGLVALIDATEPROGRASharedGLROC)		 windows_opengl_loadptr("glValidateProgram");
    SharedGL_glVertexAttrib1d	   = (PFNGLVERTEXATTRIB1DPROC)		 windows_opengl_loadptr("glVertexAttrib1d");
    SharedGL_glVertexAttrib1dv	   = (PFNGLVERTEXATTRIB1DVPROC)		 windows_opengl_loadptr("glVertexAttrib1dv");
    SharedGL_glVertexAttrib1f	   = (PFNGLVERTEXATTRIB1FPROC)		 windows_opengl_loadptr("glVertexAttrib1f");
    SharedGL_glVertexAttrib1fv	   = (PFNGLVERTEXATTRIB1FVPROC)		 windows_opengl_loadptr("glVertexAttrib1fv");
    SharedGL_glVertexAttrib1s	   = (PFNGLVERTEXATTRIB1SPROC)		 windows_opengl_loadptr("glVertexAttrib1s");
    SharedGL_glVertexAttrib1sv	   = (PFNGLVERTEXATTRIB1SVPROC)		 windows_opengl_loadptr("glVertexAttrib1sv");
    SharedGL_glVertexAttrib2d	   = (PFNGLVERTEXATTRIB2DPROC)		 windows_opengl_loadptr("glVertexAttrib2d");
    SharedGL_glVertexAttrib2dv	   = (PFNGLVERTEXATTRIB2DVPROC)		 windows_opengl_loadptr("glVertexAttrib2dv");
    SharedGL_glVertexAttrib2f	   = (PFNGLVERTEXATTRIB2FPROC)		 windows_opengl_loadptr("glVertexAttrib2f");
    SharedGL_glVertexAttrib2fv	   = (PFNGLVERTEXATTRIB2FVPROC)		 windows_opengl_loadptr("glVertexAttrib2fv");
    SharedGL_glVertexAttrib2s	   = (PFNGLVERTEXATTRIB2SPROC)		 windows_opengl_loadptr("glVertexAttrib2s");
    SharedGL_glVertexAttrib2sv	   = (PFNGLVERTEXATTRIB2SVPROC)		 windows_opengl_loadptr("glVertexAttrib2sv");
    SharedGL_glVertexAttrib3d	   = (PFNGLVERTEXATTRIB3DPROC)		 windows_opengl_loadptr("glVertexAttrib3d");
    SharedGL_glVertexAttrib3dv	   = (PFNGLVERTEXATTRIB3DVPROC)		 windows_opengl_loadptr("glVertexAttrib3dv");
    SharedGL_glVertexAttrib3f	   = (PFNGLVERTEXATTRIB3FPROC)		 windows_opengl_loadptr("glVertexAttrib3f");
    SharedGL_glVertexAttrib3fv	   = (PFNGLVERTEXATTRIB3FVPROC)		 windows_opengl_loadptr("glVertexAttrib3fv");
    SharedGL_glVertexAttrib3s	   = (PFNGLVERTEXATTRIB3SPROC)		 windows_opengl_loadptr("glVertexAttrib3s");
    SharedGL_glVertexAttrib3sv	   = (PFNGLVERTEXATTRIB3SVPROC)		 windows_opengl_loadptr("glVertexAttrib3sv");
    SharedGL_glVertexAttrib4Nbv	   = (PFNGLVERTEXATTRIB4NBVPROC)	 windows_opengl_loadptr("glVertexAttrib4Nbv");
    SharedGL_glVertexAttrib4Niv	   = (PFNGLVERTEXATTRIB4NIVPROC)	 windows_opengl_loadptr("glVertexAttrib4Niv");
    SharedGL_glVertexAttrib4Nsv	   = (PFNGLVERTEXATTRIB4NSVPROC)	 windows_opengl_loadptr("glVertexAttrib4Nsv");
    SharedGL_glVertexAttrib4Nub	   = (PFNGLVERTEXATTRIB4NUBPROC)	 windows_opengl_loadptr("glVertexAttrib4Nub");
    SharedGL_glVertexAttrib4Nubv	   = (PFNGLVERTEXATTRIB4NUBVPROC)	 windows_opengl_loadptr("glVertexAttrib4Nubv");
    SharedGL_glVertexAttrib4Nuiv	   = (PFNGLVERTEXATTRIB4NUIVPROC)	 windows_opengl_loadptr("glVertexAttrib4Nuiv");
    SharedGL_glVertexAttrib4Nusv	   = (PFNGLVERTEXATTRIB4NUSVPROC)	 windows_opengl_loadptr("glVertexAttrib4Nusv");
    SharedGL_glVertexAttrib4bv	   = (PFNGLVERTEXATTRIB4BVPROC)		 windows_opengl_loadptr("glVertexAttrib4bv");
    SharedGL_glVertexAttrib4d	   = (PFNGLVERTEXATTRIB4DPROC)		 windows_opengl_loadptr("glVertexAttrib4d");
    SharedGL_glVertexAttrib4dv	   = (PFNGLVERTEXATTRIB4DVPROC)		 windows_opengl_loadptr("glVertexAttrib4dv");
    SharedGL_glVertexAttrib4f	   = (PFNGLVERTEXATTRIB4FPROC)		 windows_opengl_loadptr("glVertexAttrib4f");
    SharedGL_glVertexAttrib4fv	   = (PFNGLVERTEXATTRIB4FVPROC)		 windows_opengl_loadptr("glVertexAttrib4fv");
    SharedGL_glVertexAttrib4iv	   = (PFNGLVERTEXATTRIB4IVPROC)		 windows_opengl_loadptr("glVertexAttrib4iv");
    SharedGL_glVertexAttrib4s	   = (PFNGLVERTEXATTRIB4SPROC)		 windows_opengl_loadptr("glVertexAttrib4s");
    SharedGL_glVertexAttrib4sv	   = (PFNGLVERTEXATTRIB4SVPROC)		 windows_opengl_loadptr("glVertexAttrib4sv");
    SharedGL_glVertexAttrib4ubv	   = (PFNGLVERTEXATTRIB4UBVPROC)	 windows_opengl_loadptr("glVertexAttrib4ubv");
    SharedGL_glVertexAttrib4uiv	   = (PFNGLVERTEXATTRIB4UIVPROC)	 windows_opengl_loadptr("glVertexAttrib4uiv");
    SharedGL_glVertexAttrib4usv	   = (PFNGLVERTEXATTRIB4USVPROC)	 windows_opengl_loadptr("glVertexAttrib4usv");
    SharedGL_glVertexAttribPointer	   = (PFNGLVERTEXATTRIBPOINTERPROC)	 windows_opengl_loadptr("glVertexAttribPointer");
    
    // 2.1 
    SharedGL_glUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC) windows_opengl_loadptr("glUniformMatrix2x3fv");
    SharedGL_glUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC) windows_opengl_loadptr("glUniformMatrix3x2fv");
    SharedGL_glUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC) windows_opengl_loadptr("glUniformMatrix2x4fv");
    SharedGL_glUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC) windows_opengl_loadptr("glUniformMatrix4x2fv");
    SharedGL_glUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC) windows_opengl_loadptr("glUniformMatrix3x4fv");
    SharedGL_glUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC) windows_opengl_loadptr("glUniformMatrix4x3fv");   
}
internal void
windows_opengl_version_3()
{
    // 3.0 
    SharedGL_glColorMaski			      = (PFNGLCOLORMASKIPROC)				windows_opengl_loadptr("glColorMaski");
    SharedGL_glGetBooleani_v			      = (PFNGLGETBOOLEANI_VPROC)			windows_opengl_loadptr("glGetBooleani_v");
    SharedGL_glGetIntegeri_v			      = (PFNGLGETINTEGERI_VPROC)			windows_opengl_loadptr("glGetIntegeri_v");
    SharedGL_glEnablei			      = (PFNGLENABLEIPROC)				windows_opengl_loadptr("glEnablei");
    SharedGL_glDisablei			      = (PFNGLDISABLEIPROC)				windows_opengl_loadptr("glDisablei");
    SharedGL_glIsEnabledi			      = (PFNGLISENABLEDIPROC)				windows_opengl_loadptr("glIsEnabledi");
    SharedGL_glBeginTransformFeedback	      = (PFNGLBEGINTRANSFORMFEEDBACKPROC)		windows_opengl_loadptr("glBeginTransformFeedback");
    SharedGL_glEndTransformFeedback		      = (PFNGLENDTRANSFORMFEEDBACKPROC)			windows_opengl_loadptr("glEndTransformFeedback");
    SharedGL_glBindBufferRange		      = (PFNGLBINDBUFFERRANGEPROC)			windows_opengl_loadptr("glBindBufferRange");
    SharedGL_glBindBufferBase		      = (PFNGLBINDBUFFERBASEPROC)			windows_opengl_loadptr("glBindBufferBase");
    SharedGL_glTransformFeedbackVaryings	      = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC)		windows_opengl_loadptr("glTransformFeedbackVaryings");
    SharedGL_glGetTransformFeedbackVarying	      = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)		windows_opengl_loadptr("glGetTransformFeedbackVarying");
    SharedGL_glClampColor			      = (PFNGLCLASharedGLCOLORPROC)				windows_opengl_loadptr("glClampColor");
    SharedGL_glBeginConditionalRender	      = (PFNGLBEGINCONDITIONALRENDERPROC)		windows_opengl_loadptr("glBeginConditionalRender");
    SharedGL_glEndConditionalRender		      = (PFNGLENDCONDITIONALRENDERPROC)			windows_opengl_loadptr("glEndConditionalRender");
    SharedGL_glVertexAttribIPointer		      = (PFNGLVERTEXATTRIBIPOINTERPROC)			windows_opengl_loadptr("glVertexAttribIPointer");
    SharedGL_glGetVertexAttribIiv		      = (PFNGLGETVERTEXATTRIBIIVPROC)			windows_opengl_loadptr("glGetVertexAttribIiv");
    SharedGL_glGetVertexAttribIuiv		      = (PFNGLGETVERTEXATTRIBIUIVPROC)			windows_opengl_loadptr("glGetVertexAttribIuiv");
    SharedGL_glVertexAttribI1i		      = (PFNGLVERTEXATTRIBI1IPROC)			windows_opengl_loadptr("glVertexAttribI1i");
    SharedGL_glVertexAttribI2i		      = (PFNGLVERTEXATTRIBI2IPROC)			windows_opengl_loadptr("glVertexAttribI2i");
    SharedGL_glVertexAttribI3i		      = (PFNGLVERTEXATTRIBI3IPROC)			windows_opengl_loadptr("glVertexAttribI3i");
    SharedGL_glVertexAttribI4i		      = (PFNGLVERTEXATTRIBI4IPROC)			windows_opengl_loadptr("glVertexAttribI4i");
    SharedGL_glVertexAttribI1ui		      = (PFNGLVERTEXATTRIBI1UIPROC)			windows_opengl_loadptr("glVertexAttribI1ui");
    SharedGL_glVertexAttribI2ui		      = (PFNGLVERTEXATTRIBI2UIPROC)			windows_opengl_loadptr("glVertexAttribI2ui");
    SharedGL_glVertexAttribI3ui		      = (PFNGLVERTEXATTRIBI3UIPROC)			windows_opengl_loadptr("glVertexAttribI3ui");
    SharedGL_glVertexAttribI4ui		      = (PFNGLVERTEXATTRIBI4UIPROC)			windows_opengl_loadptr("glVertexAttribI4ui");
    SharedGL_glVertexAttribI1iv		      = (PFNGLVERTEXATTRIBI1IVPROC)			windows_opengl_loadptr("glVertexAttribI1iv");
    SharedGL_glVertexAttribI2iv		      = (PFNGLVERTEXATTRIBI2IVPROC)			windows_opengl_loadptr("glVertexAttribI2iv");
    SharedGL_glVertexAttribI3iv		      = (PFNGLVERTEXATTRIBI3IVPROC)			windows_opengl_loadptr("glVertexAttribI3iv");
    SharedGL_glVertexAttribI4iv		      = (PFNGLVERTEXATTRIBI4IVPROC)			windows_opengl_loadptr("glVertexAttribI4iv");
    SharedGL_glVertexAttribI1uiv		      = (PFNGLVERTEXATTRIBI1UIVPROC)			windows_opengl_loadptr("glVertexAttribI1uiv");
    SharedGL_glVertexAttribI2uiv		      = (PFNGLVERTEXATTRIBI2UIVPROC)			windows_opengl_loadptr("glVertexAttribI2uiv");
    SharedGL_glVertexAttribI3uiv		      = (PFNGLVERTEXATTRIBI3UIVPROC)			windows_opengl_loadptr("glVertexAttribI3uiv");
    SharedGL_glVertexAttribI4uiv		      = (PFNGLVERTEXATTRIBI4UIVPROC)			windows_opengl_loadptr("glVertexAttribI4uiv");
    SharedGL_glVertexAttribI4bv		      = (PFNGLVERTEXATTRIBI4BVPROC)			windows_opengl_loadptr("glVertexAttribI4bv");
    SharedGL_glVertexAttribI4sv		      = (PFNGLVERTEXATTRIBI4SVPROC)			windows_opengl_loadptr("glVertexAttribI4sv");
    SharedGL_glVertexAttribI4ubv		      = (PFNGLVERTEXATTRIBI4UBVPROC)			windows_opengl_loadptr("glVertexAttribI4ubv");
    SharedGL_glVertexAttribI4usv		      = (PFNGLVERTEXATTRIBI4USVPROC)			windows_opengl_loadptr("glVertexAttribI4usv");
    SharedGL_glGetUniformuiv			      = (PFNGLGETUNIFORMUIVPROC)			windows_opengl_loadptr("glGetUniformuiv");
    SharedGL_glBindFragDataLocation		      = (PFNGLBINDFRAGDATALOCATIONPROC)			windows_opengl_loadptr("glBindFragDataLocation");
    SharedGL_glGetFragDataLocation		      = (PFNGLGETFRAGDATALOCATIONPROC)			windows_opengl_loadptr("glGetFragDataLocation");
    SharedGL_glUniform1ui			      = (PFNGLUNIFORM1UIPROC)				windows_opengl_loadptr("glUniform1ui");
    SharedGL_glUniform2ui			      = (PFNGLUNIFORM2UIPROC)				windows_opengl_loadptr("glUniform2ui");
    SharedGL_glUniform3ui			      = (PFNGLUNIFORM3UIPROC)				windows_opengl_loadptr("glUniform3ui");
    SharedGL_glUniform4ui			      = (PFNGLUNIFORM4UIPROC)				windows_opengl_loadptr("glUniform4ui");
    SharedGL_glUniform1uiv			      = (PFNGLUNIFORM1UIVPROC)				windows_opengl_loadptr("glUniform1uiv");
    SharedGL_glUniform2uiv			      = (PFNGLUNIFORM2UIVPROC)				windows_opengl_loadptr("glUniform2uiv");
    SharedGL_glUniform3uiv			      = (PFNGLUNIFORM3UIVPROC)				windows_opengl_loadptr("glUniform3uiv");
    SharedGL_glUniform4uiv			      = (PFNGLUNIFORM4UIVPROC)				windows_opengl_loadptr("glUniform4uiv");
    SharedGL_glTexParameterIiv		      = (PFNGLTEXPARAMETERIIVPROC)			windows_opengl_loadptr("glTexParameterIiv");
    SharedGL_glTexParameterIuiv		      = (PFNGLTEXPARAMETERIUIVPROC)			windows_opengl_loadptr("glTexParameterIuiv");
    SharedGL_glGetTexParameterIiv		      = (PFNGLGETTEXPARAMETERIIVPROC)			windows_opengl_loadptr("glGetTexParameterIiv");
    SharedGL_glGetTexParameterIuiv		      = (PFNGLGETTEXPARAMETERIUIVPROC)			windows_opengl_loadptr("glGetTexParameterIuiv");
    SharedGL_glClearBufferiv			      = (PFNGLCLEARBUFFERIVPROC)			windows_opengl_loadptr("glClearBufferiv");
    SharedGL_glClearBufferuiv		      = (PFNGLCLEARBUFFERUIVPROC)			windows_opengl_loadptr("glClearBufferuiv");
    SharedGL_glClearBufferfv			      = (PFNGLCLEARBUFFERFVPROC)			windows_opengl_loadptr("glClearBufferfv");
    SharedGL_glClearBufferfi			      = (PFNGLCLEARBUFFERFIPROC)			windows_opengl_loadptr("glClearBufferfi");
    SharedGL_glGetStringi			      = (PFNGLGETSTRINGIPROC)				windows_opengl_loadptr("glGetStringi");
    SharedGL_glIsRenderbuffer		      = (PFNGLISRENDERBUFFERPROC)			windows_opengl_loadptr("glIsRenderbuffer");
    SharedGL_glBindRenderbuffer		      = (PFNGLBINDRENDERBUFFERPROC)			windows_opengl_loadptr("glBindRenderbuffer");
    SharedGL_glDeleteRenderbuffers		      = (PFNGLDELETERENDERBUFFERSPROC)			windows_opengl_loadptr("glDeleteRenderbuffers");
    SharedGL_glGenRenderbuffers		      = (PFNGLGENRENDERBUFFERSPROC)			windows_opengl_loadptr("glGenRenderbuffers");
    SharedGL_glRenderbufferStorage		      = (PFNGLRENDERBUFFERSTORAGEPROC)			windows_opengl_loadptr("glRenderbufferStorage");
    SharedGL_glGetRenderbufferParameteriv	      = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)		windows_opengl_loadptr("glGetRenderbufferParameteriv");
    SharedGL_glIsFramebuffer			      = (PFNGLISFRAMEBUFFERPROC)			windows_opengl_loadptr("glIsFramebuffer");
    SharedGL_glBindFramebuffer		      = (PFNGLBINDFRAMEBUFFERPROC)			windows_opengl_loadptr("glBindFramebuffer");
    SharedGL_glDeleteFramebuffers		      = (PFNGLDELETEFRAMEBUFFERSPROC)			windows_opengl_loadptr("glDeleteFramebuffers");
    SharedGL_glGenFramebuffers		      = (PFNGLGENFRAMEBUFFERSPROC)			windows_opengl_loadptr("glGenFramebuffers");
    SharedGL_glCheckFramebufferStatus	      = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)		windows_opengl_loadptr("glCheckFramebufferStatus");
    SharedGL_glFramebufferTexture1D		      = (PFNGLFRAMEBUFFERTEXTURE1DPROC)			windows_opengl_loadptr("glFramebufferTexture1D");
    SharedGL_glFramebufferTexture2D		      = (PFNGLFRAMEBUFFERTEXTURE2DPROC)			windows_opengl_loadptr("glFramebufferTexture2D");
    SharedGL_glFramebufferTexture3D		      = (PFNGLFRAMEBUFFERTEXTURE3DPROC)			windows_opengl_loadptr("glFramebufferTexture3D");
    SharedGL_glFramebufferRenderbuffer	      = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)		windows_opengl_loadptr("glFramebufferRenderbuffer");
    SharedGL_glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)	windows_opengl_loadptr("glGetFramebufferAttachmentParameteriv");
    SharedGL_glGenerateMipmap		      = (PFNGLGENERATEMIPMAPPROC)			windows_opengl_loadptr("glGenerateMipmap");
    SharedGL_glBlitFramebuffer		      = (PFNGLBLITFRAMEBUFFERPROC)			windows_opengl_loadptr("glBlitFramebuffer");
    SharedGL_glRenderbufferStorageMultisample      = (PFNGLRENDERBUFFERSTORAGEMULTISASharedGLLEPROC)	windows_opengl_loadptr("glRenderbufferStorageMultisample");
    SharedGL_glFramebufferTextureLayer	      = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)		windows_opengl_loadptr("glFramebufferTextureLayer");
    SharedGL_glMapBufferRange		      = (PFNGLMAPBUFFERRANGEPROC)			windows_opengl_loadptr("glMapBufferRange");
    SharedGL_glFlushMappedBufferRange	      = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)		windows_opengl_loadptr("glFlushMappedBufferRange");
    SharedGL_glBindVertexArray		      = (PFNGLBINDVERTEXARRAYPROC)			windows_opengl_loadptr("glBindVertexArray");
    SharedGL_glDeleteVertexArrays		      = (PFNGLDELETEVERTEXARRAYSPROC)			windows_opengl_loadptr("glDeleteVertexArrays");
    SharedGL_glGenVertexArrays		      = (PFNGLGENVERTEXARRAYSPROC)			windows_opengl_loadptr("glGenVertexArrays");
    SharedGL_glIsVertexArray			      = (PFNGLISVERTEXARRAYPROC)			windows_opengl_loadptr("glIsVertexArray");
    
    // 3.1 
    SharedGL_glDrawArraysInstanced	    = (PFNGLDRAWARRAYSINSTANCEDPROC)	   windows_opengl_loadptr("glDrawArraysInstanced");
    SharedGL_glDrawElementsInstanced	    = (PFNGLDRAWELEMENTSINSTANCEDPROC)	   windows_opengl_loadptr("glDrawElementsInstanced");
    SharedGL_glTexBuffer		    = (PFNGLTEXBUFFERPROC)		   windows_opengl_loadptr("glTexBuffer");
    SharedGL_glPrimitiveRestartIndex	    = (PFNGLPRIMITIVERESTARTINDEXPROC)	   windows_opengl_loadptr("glPrimitiveRestartIndex");
    SharedGL_glCopyBufferSubData	    = (PFNGLCOPYBUFFERSUBDATAPROC)	   windows_opengl_loadptr("glCopyBufferSubData");
    SharedGL_glGetUniformIndices	    = (PFNGLGETUNIFORMINDICESPROC)	   windows_opengl_loadptr("glGetUniformIndices");
    SharedGL_glGetActiveUniformsiv	    = (PFNGLGETACTIVEUNIFORMSIVPROC)	   windows_opengl_loadptr("glGetActiveUniformsiv");
    SharedGL_glGetActiveUniformName	    = (PFNGLGETACTIVEUNIFORMNAMEPROC)	   windows_opengl_loadptr("glGetActiveUniformName");
    SharedGL_glGetUniformBlockIndex	    = (PFNGLGETUNIFORMBLOCKINDEXPROC)	   windows_opengl_loadptr("glGetUniformBlockIndex");
    SharedGL_glGetActiveUniformBlockiv   = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)   windows_opengl_loadptr("glGetActiveUniformBlockiv");
    SharedGL_glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC) windows_opengl_loadptr("glGetActiveUniformBlockName");
    SharedGL_glUniformBlockBinding	    = (PFNGLUNIFORMBLOCKBINDINGPROC)	   windows_opengl_loadptr("glUniformBlockBinding");
    SharedGL_glBindBufferRange	    = (PFNGLBINDBUFFERRANGEPROC) 	   windows_opengl_loadptr("glBindBufferRange");
    SharedGL_glBindBufferBase	    = (PFNGLBINDBUFFERBASEPROC)		   windows_opengl_loadptr("glBindBufferBase");
    SharedGL_glGetIntegeri_v		    = (PFNGLGETINTEGERI_VPROC)		   windows_opengl_loadptr("glGetIntegeri_v");
    
    // 3.2 
    SharedGL_glDrawElementsBaseVertex	  = (PFNGLDRAWELEMENTSBASEVERTEXPROC)		windows_opengl_loadptr("glDrawElementsBaseVertex");
    SharedGL_glDrawRangeElementsBaseVertex	  = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)	windows_opengl_loadptr("glDrawRangeElementsBaseVertex");
    SharedGL_glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)	windows_opengl_loadptr("glDrawElementsInstancedBaseVertex");
    SharedGL_glMultiDrawElementsBaseVertex	  = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)	windows_opengl_loadptr("glMultiDrawElementsBaseVertex");
    SharedGL_glProvokingVertex		  = (PFNGLPROVOKINGVERTEXPROC)			windows_opengl_loadptr("glProvokingVertex");
    SharedGL_glFenceSync			  = (PFNGLFENCESYNCPROC)			windows_opengl_loadptr("glFenceSync");
    SharedGL_glIsSync			  = (PFNGLISSYNCPROC)				windows_opengl_loadptr("glIsSync");
    SharedGL_glDeleteSync			  = (PFNGLDELETESYNCPROC)			windows_opengl_loadptr("glDeleteSync");
    SharedGL_glClientWaitSync		  = (PFNGLCLIENTWAITSYNCPROC)			windows_opengl_loadptr("glClientWaitSync");
    SharedGL_glWaitSync			  = (PFNGLWAITSYNCPROC)				windows_opengl_loadptr("glWaitSync");
    SharedGL_glGetInteger64v			  = (PFNGLGETINTEGER64VPROC)			windows_opengl_loadptr("glGetInteger64v");
    SharedGL_glGetSynciv			  = (PFNGLGETSYNCIVPROC)			windows_opengl_loadptr("glGetSynciv");
    SharedGL_glGetInteger64i_v		  = (PFNGLGETINTEGER64I_VPROC)			windows_opengl_loadptr("glGetInteger64i_v");
    SharedGL_glGetBufferParameteri64v	  = (PFNGLGETBUFFERPARAMETERI64VPROC)		windows_opengl_loadptr("glGetBufferParameteri64v");
    SharedGL_glFramebufferTexture		  = (PFNGLFRAMEBUFFERTEXTUREPROC)		windows_opengl_loadptr("glFramebufferTexture");
    SharedGL_glTexImage2DMultisample		  = (PFNGLTEXIMAGE2DMULTISASharedGLLEPROC)		windows_opengl_loadptr("glTexImage2DMultisample");
    SharedGL_glTexImage3DMultisample		  = (PFNGLTEXIMAGE3DMULTISASharedGLLEPROC)		windows_opengl_loadptr("glTexImage3DMultisample");
    SharedGL_glGetMultisamplefv		  = (PFNGLGETMULTISASharedGLLEFVPROC)			windows_opengl_loadptr("glGetMultisamplefv");
    SharedGL_glSampleMaski			  = (PFNGLSASharedGLLEMASKIPROC)			windows_opengl_loadptr("glSampleMaski");
    
    // 3.3 
    SharedGL_glBindFragDataLocationIndexed = (PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)	windows_opengl_loadptr("glBindFragDataLocationIndexed");
    SharedGL_glGetFragDataIndex	      = (PFNGLGETFRAGDATAINDEXPROC)		windows_opengl_loadptr("glGetFragDataIndex");
    SharedGL_glGenSamplers		      = (PFNGLGENSASharedGLLERSPROC)			windows_opengl_loadptr("glGenSamplers");
    SharedGL_glDeleteSamplers	      = (PFNGLDELETESASharedGLLERSPROC)		windows_opengl_loadptr("glDeleteSamplers");
    SharedGL_glIsSampler		      = (PFNGLISSASharedGLLERPROC)			windows_opengl_loadptr("glIsSampler");
    SharedGL_glBindSampler		      = (PFNGLBINDSASharedGLLERPROC)			windows_opengl_loadptr("glBindSampler");
    SharedGL_glSamplerParameteri	      = (PFNGLSASharedGLLERPARAMETERIPROC)		windows_opengl_loadptr("glSamplerParameteri");
    SharedGL_glSamplerParameteriv	      = (PFNGLSASharedGLLERPARAMETERIVPROC)		windows_opengl_loadptr("glSamplerParameteriv");
    SharedGL_glSamplerParameterf	      = (PFNGLSASharedGLLERPARAMETERFPROC)		windows_opengl_loadptr("glSamplerParameterf");
    SharedGL_glSamplerParameterfv	      = (PFNGLSASharedGLLERPARAMETERFVPROC)		windows_opengl_loadptr("glSamplerParameterfv");
    SharedGL_glSamplerParameterIiv	      = (PFNGLSASharedGLLERPARAMETERIIVPROC)		windows_opengl_loadptr("glSamplerParameterIiv");
    SharedGL_glSamplerParameterIuiv	      = (PFNGLSASharedGLLERPARAMETERIUIVPROC)		windows_opengl_loadptr("glSamplerParameterIuiv");
    SharedGL_glGetSamplerParameteriv	      = (PFNGLGETSASharedGLLERPARAMETERIVPROC)	windows_opengl_loadptr("glGetSamplerParameteriv");
    SharedGL_glGetSamplerParameterIiv      = (PFNGLGETSASharedGLLERPARAMETERIIVPROC)	windows_opengl_loadptr("glGetSamplerParameterIiv");
    SharedGL_glGetSamplerParameterfv	      = (PFNGLGETSASharedGLLERPARAMETERFVPROC)	windows_opengl_loadptr("glGetSamplerParameterfv");
    SharedGL_glGetSamplerParameterIuiv     = (PFNGLGETSASharedGLLERPARAMETERIUIVPROC)	windows_opengl_loadptr("glGetSamplerParameterIuiv");
    SharedGL_glQueryCounter		      = (PFNGLQUERYCOUNTERPROC)			windows_opengl_loadptr("glQueryCounter");
    SharedGL_glGetQueryObjecti64v	      = (PFNGLGETQUERYOBJECTI64VPROC)		windows_opengl_loadptr("glGetQueryObjecti64v");
    SharedGL_glGetQueryObjectui64v	      = (PFNGLGETQUERYOBJECTUI64VPROC)		windows_opengl_loadptr("glGetQueryObjectui64v");
    SharedGL_glVertexAttribDivisor	      = (PFNGLVERTEXATTRIBDIVISORPROC)		windows_opengl_loadptr("glVertexAttribDivisor");
    SharedGL_glVertexAttribP1ui	      = (PFNGLVERTEXATTRIBP1UIPROC)		windows_opengl_loadptr("glVertexAttribP1ui");
    SharedGL_glVertexAttribP1uiv	      = (PFNGLVERTEXATTRIBP1UIVPROC)		windows_opengl_loadptr("glVertexAttribP1uiv");
    SharedGL_glVertexAttribP2ui	      = (PFNGLVERTEXATTRIBP2UIPROC)		windows_opengl_loadptr("glVertexAttribP2ui");
    SharedGL_glVertexAttribP2uiv	      = (PFNGLVERTEXATTRIBP2UIVPROC)		windows_opengl_loadptr("glVertexAttribP2uiv");
    SharedGL_glVertexAttribP3ui	      = (PFNGLVERTEXATTRIBP3UIPROC)		windows_opengl_loadptr("glVertexAttribP3ui");
    SharedGL_glVertexAttribP3uiv	      = (PFNGLVERTEXATTRIBP3UIVPROC)		windows_opengl_loadptr("glVertexAttribP3uiv");
    SharedGL_glVertexAttribP4ui	      = (PFNGLVERTEXATTRIBP4UIPROC)		windows_opengl_loadptr("glVertexAttribP4ui");
    SharedGL_glVertexAttribP4uiv	      = (PFNGLVERTEXATTRIBP4UIVPROC)		windows_opengl_loadptr("glVertexAttribP4uiv");
    SharedGL_glVertexP2ui		      = (PFNGLVERTEXP2UIPROC)			windows_opengl_loadptr("glVertexP2ui");
    SharedGL_glVertexP2uiv		      = (PFNGLVERTEXP2UIVPROC)			windows_opengl_loadptr("glVertexP2uiv");
    SharedGL_glVertexP3ui		      = (PFNGLVERTEXP3UIPROC)			windows_opengl_loadptr("glVertexP3ui");
    SharedGL_glVertexP3uiv		      = (PFNGLVERTEXP3UIVPROC)			windows_opengl_loadptr("glVertexP3uiv");
    SharedGL_glVertexP4ui		      = (PFNGLVERTEXP4UIPROC)			windows_opengl_loadptr("glVertexP4ui");
    SharedGL_glVertexP4uiv		      = (PFNGLVERTEXP4UIVPROC)			windows_opengl_loadptr("glVertexP4uiv");
    SharedGL_glTexCoordP1ui		      = (PFNGLTEXCOORDP1UIPROC)			windows_opengl_loadptr("glTexCoordP1ui");
    SharedGL_glTexCoordP1uiv		      = (PFNGLTEXCOORDP1UIVPROC)		windows_opengl_loadptr("glTexCoordP1uiv");
    SharedGL_glTexCoordP2ui		      = (PFNGLTEXCOORDP2UIPROC)			windows_opengl_loadptr("glTexCoordP2ui");
    SharedGL_glTexCoordP2uiv		      = (PFNGLTEXCOORDP2UIVPROC)		windows_opengl_loadptr("glTexCoordP2uiv");
    SharedGL_glTexCoordP3ui		      = (PFNGLTEXCOORDP3UIPROC)			windows_opengl_loadptr("glTexCoordP3ui");
    SharedGL_glTexCoordP3uiv		      = (PFNGLTEXCOORDP3UIVPROC)		windows_opengl_loadptr("glTexCoordP3uiv");
    SharedGL_glTexCoordP4ui		      = (PFNGLTEXCOORDP4UIPROC)			windows_opengl_loadptr("glTexCoordP4ui");
    SharedGL_glTexCoordP4uiv		      = (PFNGLTEXCOORDP4UIVPROC)		windows_opengl_loadptr("glTexCoordP4uiv");
    SharedGL_glMultiTexCoordP1ui	      = (PFNGLMULTITEXCOORDP1UIPROC)		windows_opengl_loadptr("glMultiTexCoordP1ui");
    SharedGL_glMultiTexCoordP1uiv	      = (PFNGLMULTITEXCOORDP1UIVPROC)		windows_opengl_loadptr("glMultiTexCoordP1uiv");
    SharedGL_glMultiTexCoordP2ui	      = (PFNGLMULTITEXCOORDP2UIPROC)		windows_opengl_loadptr("glMultiTexCoordP2ui");
    SharedGL_glMultiTexCoordP2uiv	      = (PFNGLMULTITEXCOORDP2UIVPROC)		windows_opengl_loadptr("glMultiTexCoordP2uiv");
    SharedGL_glMultiTexCoordP3ui	      = (PFNGLMULTITEXCOORDP3UIPROC)		windows_opengl_loadptr("glMultiTexCoordP3ui");
    SharedGL_glMultiTexCoordP3uiv	      = (PFNGLMULTITEXCOORDP3UIVPROC)		windows_opengl_loadptr("glMultiTexCoordP3uiv");
    SharedGL_glMultiTexCoordP4ui	      = (PFNGLMULTITEXCOORDP4UIPROC)		windows_opengl_loadptr("glMultiTexCoordP4ui");
    SharedGL_glMultiTexCoordP4uiv	      = (PFNGLMULTITEXCOORDP4UIVPROC)		windows_opengl_loadptr("glMultiTexCoordP4uiv");
    SharedGL_glNormalP3ui		      = (PFNGLNORMALP3UIPROC)			windows_opengl_loadptr("glNormalP3ui");
    SharedGL_glNormalP3uiv		      = (PFNGLNORMALP3UIVPROC)			windows_opengl_loadptr("glNormalP3uiv");
    SharedGL_glColorP3ui		      = (PFNGLCOLORP3UIPROC)			windows_opengl_loadptr("glColorP3ui");
    SharedGL_glColorP3uiv		      = (PFNGLCOLORP3UIVPROC)			windows_opengl_loadptr("glColorP3uiv");
    SharedGL_glColorP4ui		      = (PFNGLCOLORP4UIPROC)			windows_opengl_loadptr("glColorP4ui");
    SharedGL_glColorP4uiv		      = (PFNGLCOLORP4UIVPROC)			windows_opengl_loadptr("glColorP4uiv");
    SharedGL_glSecondaryColorP3ui	      = (PFNGLSECONDARYCOLORP3UIPROC)		windows_opengl_loadptr("glSecondaryColorP3ui");
    SharedGL_glSecondaryColorP3uiv	      = (PFNGLSECONDARYCOLORP3UIVPROC)		windows_opengl_loadptr("glSecondaryColorP3uiv");
}
internal void
windows_opengl_version_4()
{
    // 4.0 
    SharedGL_glMinSampleShading		 = (PFNGLMINSASharedGLLESHADINGPROC)		     windows_opengl_loadptr("glMinSampleShading");
    SharedGL_glBlendEquationi		 = (PFNGLBLENDEQUATIONIPROC)		     windows_opengl_loadptr("glBlendEquationi");
    SharedGL_glBlendEquationSeparatei	 = (PFNGLBLENDEQUATIONSEPARATEIPROC)	     windows_opengl_loadptr("glBlendEquationSeparatei");
    SharedGL_glBlendFunci			 = (PFNGLBLENDFUNCIPROC)		     windows_opengl_loadptr("glBlendFunci");
    SharedGL_glBlendFuncSeparatei		 = (PFNGLBLENDFUNCSEPARATEIPROC)	     windows_opengl_loadptr("glBlendFuncSeparatei");
    SharedGL_glDrawArraysIndirect		 = (PFNGLDRAWARRAYSINDIRECTPROC)	     windows_opengl_loadptr("glDrawArraysIndirect");
    SharedGL_glDrawElementsIndirect		 = (PFNGLDRAWELEMENTSINDIRECTPROC)	     windows_opengl_loadptr("glDrawElementsIndirect");
    SharedGL_glUniform1d			 = (PFNGLUNIFORM1DPROC)			     windows_opengl_loadptr("glUniform1d");
    SharedGL_glUniform2d			 = (PFNGLUNIFORM2DPROC)			     windows_opengl_loadptr("glUniform2d");
    SharedGL_glUniform3d			 = (PFNGLUNIFORM3DPROC)			     windows_opengl_loadptr("glUniform3d");
    SharedGL_glUniform4d			 = (PFNGLUNIFORM4DPROC)			     windows_opengl_loadptr("glUniform4d");
    SharedGL_glUniform1dv			 = (PFNGLUNIFORM1DVPROC)		     windows_opengl_loadptr("glUniform1dv");
    SharedGL_glUniform2dv			 = (PFNGLUNIFORM2DVPROC)		     windows_opengl_loadptr("glUniform2dv");
    SharedGL_glUniform3dv			 = (PFNGLUNIFORM3DVPROC)		     windows_opengl_loadptr("glUniform3dv");
    SharedGL_glUniform4dv			 = (PFNGLUNIFORM4DVPROC)		     windows_opengl_loadptr("glUniform4dv");
    SharedGL_glUniformMatrix2dv		 = (PFNGLUNIFORMMATRIX2DVPROC)		     windows_opengl_loadptr("glUniformMatrix2dv");
    SharedGL_glUniformMatrix3dv		 = (PFNGLUNIFORMMATRIX3DVPROC)		     windows_opengl_loadptr("glUniformMatrix3dv");
    SharedGL_glUniformMatrix4dv		 = (PFNGLUNIFORMMATRIX4DVPROC)		     windows_opengl_loadptr("glUniformMatrix4dv");
    SharedGL_glUniformMatrix2x3dv		 = (PFNGLUNIFORMMATRIX2X3DVPROC)	     windows_opengl_loadptr("glUniformMatrix2x3dv");
    SharedGL_glUniformMatrix2x4dv		 = (PFNGLUNIFORMMATRIX2X4DVPROC)	     windows_opengl_loadptr("glUniformMatrix2x4dv");
    SharedGL_glUniformMatrix3x2dv		 = (PFNGLUNIFORMMATRIX3X2DVPROC)	     windows_opengl_loadptr("glUniformMatrix3x2dv");
    SharedGL_glUniformMatrix3x4dv		 = (PFNGLUNIFORMMATRIX3X4DVPROC)	     windows_opengl_loadptr("glUniformMatrix3x4dv");
    SharedGL_glUniformMatrix4x2dv		 = (PFNGLUNIFORMMATRIX4X2DVPROC)	     windows_opengl_loadptr("glUniformMatrix4x2dv");
    SharedGL_glUniformMatrix4x3dv		 = (PFNGLUNIFORMMATRIX4X3DVPROC)	     windows_opengl_loadptr("glUniformMatrix4x3dv");
    SharedGL_glGetUniformdv			 = (PFNGLGETUNIFORMDVPROC)		     windows_opengl_loadptr("glGetUniformdv");
    SharedGL_glGetSubroutineUniformLocation	 = (PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)   windows_opengl_loadptr("glGetSubroutineUniformLocation");
    SharedGL_glGetSubroutineIndex		 = (PFNGLGETSUBROUTINEINDEXPROC)	     windows_opengl_loadptr("glGetSubroutineIndex");
    SharedGL_glGetActiveSubroutineUniformiv	 = (PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)   windows_opengl_loadptr("glGetActiveSubroutineUniformiv");
    SharedGL_glGetActiveSubroutineUniformName = (PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC) windows_opengl_loadptr("glGetActiveSubroutineUniformName");
    SharedGL_glGetActiveSubroutineName	 = (PFNGLGETACTIVESUBROUTINENAMEPROC)	     windows_opengl_loadptr("glGetActiveSubroutineName");
    SharedGL_glUniformSubroutinesuiv		 = (PFNGLUNIFORMSUBROUTINESUIVPROC)	     windows_opengl_loadptr("glUniformSubroutinesuiv");
    SharedGL_glGetUniformSubroutineuiv	 = (PFNGLGETUNIFORMSUBROUTINEUIVPROC)	     windows_opengl_loadptr("glGetUniformSubroutineuiv");
    SharedGL_glGetProgramStageiv		 = (PFNGLGETPROGRAMSTAGEIVPROC)		     windows_opengl_loadptr("glGetProgramStageiv");
    SharedGL_glPatchParameteri		 = (PFNGLPATCHPARAMETERIPROC)		     windows_opengl_loadptr("glPatchParameteri");
    SharedGL_glPatchParameterfv		 = (PFNGLPATCHPARAMETERFVPROC)		     windows_opengl_loadptr("glPatchParameterfv");
    SharedGL_glBindTransformFeedback		 = (PFNGLBINDTRANSFORMFEEDBACKPROC)	     windows_opengl_loadptr("glBindTransformFeedback");
    SharedGL_glDeleteTransformFeedbacks	 = (PFNGLDELETETRANSFORMFEEDBACKSPROC)	     windows_opengl_loadptr("glDeleteTransformFeedbacks");
    SharedGL_glGenTransformFeedbacks		 = (PFNGLGENTRANSFORMFEEDBACKSPROC)	     windows_opengl_loadptr("glGenTransformFeedbacks");
    SharedGL_glIsTransformFeedback		 = (PFNGLISTRANSFORMFEEDBACKPROC)	     windows_opengl_loadptr("glIsTransformFeedback");
    SharedGL_glPauseTransformFeedback	 = (PFNGLPAUSETRANSFORMFEEDBACKPROC)	     windows_opengl_loadptr("glPauseTransformFeedback");
    SharedGL_glResumeTransformFeedback	 = (PFNGLRESUMETRANSFORMFEEDBACKPROC)	     windows_opengl_loadptr("glResumeTransformFeedback");
    SharedGL_glDrawTransformFeedback		 = (PFNGLDRAWTRANSFORMFEEDBACKPROC)	     windows_opengl_loadptr("glDrawTransformFeedback");
    SharedGL_glDrawTransformFeedbackStream	 = (PFNGLDRAWTRANSFORMFEEDBACKSTREASharedGLROC)    windows_opengl_loadptr("glDrawTransformFeedbackStream");
    SharedGL_glBeginQueryIndexed		 = (PFNGLBEGINQUERYINDEXEDPROC)              windows_opengl_loadptr("glBeginQueryIndexed");
    SharedGL_glEndQueryIndexed		 = (PFNGLENDQUERYINDEXEDPROC)		     windows_opengl_loadptr("glEndQueryIndexed");
    SharedGL_glGetQueryIndexediv		 = (PFNGLGETQUERYINDEXEDIVPROC)		     windows_opengl_loadptr("glGetQueryIndexediv");
    
    // 4.1 
    SharedGL_glReleaseShaderCompiler	    = (PFNGLRELEASESHADERCOSharedGLILERPROC)	   windows_opengl_loadptr("glReleaseShaderCompiler");
    SharedGL_glShaderBinary		    = (PFNGLSHADERBINARYPROC)		   windows_opengl_loadptr("glShaderBinary");
    SharedGL_glGetShaderPrecisionFormat  = (PFNGLGETSHADERPRECISIONFORMATPROC)  windows_opengl_loadptr("glGetShaderPrecisionFormat");
    SharedGL_glDepthRangef		    = (PFNGLDEPTHRANGEFPROC)		   windows_opengl_loadptr("glDepthRangef");
    SharedGL_glClearDepthf		    = (PFNGLCLEARDEPTHFPROC)		   windows_opengl_loadptr("glClearDepthf");
    SharedGL_glGetProgramBinary	    = (PFNGLGETPROGRAMBINARYPROC)	   windows_opengl_loadptr("glGetProgramBinary");
    SharedGL_glProgramBinary		    = (PFNGLPROGRAMBINARYPROC)		   windows_opengl_loadptr("glProgramBinary");
    SharedGL_glProgramParameteri	    = (PFNGLPROGRASharedGLARAMETERIPROC)	   windows_opengl_loadptr("glProgramParameteri");
    SharedGL_glUseProgramStages	    = (PFNGLUSEPROGRAMSTAGESPROC)	   windows_opengl_loadptr("glUseProgramStages");
    SharedGL_glActiveShaderProgram	    = (PFNGLACTIVESHADERPROGRASharedGLROC)	   windows_opengl_loadptr("glActiveShaderProgram");
    SharedGL_glCreateShaderProgramv	    = (PFNGLCREATESHADERPROGRAMVPROC)	   windows_opengl_loadptr("glCreateShaderProgramv");
    SharedGL_glBindProgramPipeline	    = (PFNGLBINDPROGRASharedGLIPELINEPROC)	   windows_opengl_loadptr("glBindProgramPipeline");
    SharedGL_glDeleteProgramPipelines    = (PFNGLDELETEPROGRASharedGLIPELINESPROC)	   windows_opengl_loadptr("glDeleteProgramPipelines");
    SharedGL_glGenProgramPipelines	    = (PFNGLGENPROGRASharedGLIPELINESPROC)	   windows_opengl_loadptr("glGenProgramPipelines");
    SharedGL_glIsProgramPipeline	    = (PFNGLISPROGRASharedGLIPELINEPROC)	   windows_opengl_loadptr("glIsProgramPipeline");
    SharedGL_glGetProgramPipelineiv	    = (PFNGLGETPROGRASharedGLIPELINEIVPROC)	   windows_opengl_loadptr("glGetProgramPipelineiv");
    SharedGL_glProgramParameteri	    = (PFNGLPROGRASharedGLARAMETERIPROC)	   windows_opengl_loadptr("glProgramParameteri");
    SharedGL_glProgramUniform1i	    = (PFNGLPROGRAMUNIFORM1IPROC)	   windows_opengl_loadptr("glProgramUniform1i");
    SharedGL_glProgramUniform1iv	    = (PFNGLPROGRAMUNIFORM1IVPROC)	   windows_opengl_loadptr("glProgramUniform1iv");
    SharedGL_glProgramUniform1f	    = (PFNGLPROGRAMUNIFORM1FPROC)	   windows_opengl_loadptr("glProgramUniform1f");
    SharedGL_glProgramUniform1fv	    = (PFNGLPROGRAMUNIFORM1FVPROC)	   windows_opengl_loadptr("glProgramUniform1fv");
    SharedGL_glProgramUniform1d	    = (PFNGLPROGRAMUNIFORM1DPROC)	   windows_opengl_loadptr("glProgramUniform1d");
    SharedGL_glProgramUniform1dv	    = (PFNGLPROGRAMUNIFORM1DVPROC)	   windows_opengl_loadptr("glProgramUniform1dv");
    SharedGL_glProgramUniform1ui	    = (PFNGLPROGRAMUNIFORM1UIPROC)	   windows_opengl_loadptr("glProgramUniform1ui");
    SharedGL_glProgramUniform1uiv	    = (PFNGLPROGRAMUNIFORM1UIVPROC)	   windows_opengl_loadptr("glProgramUniform1uiv");
    SharedGL_glProgramUniform2i	    = (PFNGLPROGRAMUNIFORM2IPROC)	   windows_opengl_loadptr("glProgramUniform2i");
    SharedGL_glProgramUniform2iv	    = (PFNGLPROGRAMUNIFORM2IVPROC)	   windows_opengl_loadptr("glProgramUniform2iv");
    SharedGL_glProgramUniform2f	    = (PFNGLPROGRAMUNIFORM2FPROC)	   windows_opengl_loadptr("glProgramUniform2f");
    SharedGL_glProgramUniform2fv	    = (PFNGLPROGRAMUNIFORM2FVPROC)	   windows_opengl_loadptr("glProgramUniform2fv");
    SharedGL_glProgramUniform2d	    = (PFNGLPROGRAMUNIFORM2DPROC)	   windows_opengl_loadptr("glProgramUniform2d");
    SharedGL_glProgramUniform2dv	    = (PFNGLPROGRAMUNIFORM2DVPROC)	   windows_opengl_loadptr("glProgramUniform2dv");
    SharedGL_glProgramUniform2ui	    = (PFNGLPROGRAMUNIFORM2UIPROC)	   windows_opengl_loadptr("glProgramUniform2ui");
    SharedGL_glProgramUniform2uiv	    = (PFNGLPROGRAMUNIFORM2UIVPROC)	   windows_opengl_loadptr("glProgramUniform2uiv");
    SharedGL_glProgramUniform3i	    = (PFNGLPROGRAMUNIFORM3IPROC)	   windows_opengl_loadptr("glProgramUniform3i");
    SharedGL_glProgramUniform3iv	    = (PFNGLPROGRAMUNIFORM3IVPROC)	   windows_opengl_loadptr("glProgramUniform3iv");
    SharedGL_glProgramUniform3f	    = (PFNGLPROGRAMUNIFORM3FPROC)	   windows_opengl_loadptr("glProgramUniform3f");
    SharedGL_glProgramUniform3fv	    = (PFNGLPROGRAMUNIFORM3FVPROC)	   windows_opengl_loadptr("glProgramUniform3fv");
    SharedGL_glProgramUniform3d	    = (PFNGLPROGRAMUNIFORM3DPROC)	   windows_opengl_loadptr("glProgramUniform3d");
    SharedGL_glProgramUniform3dv	    = (PFNGLPROGRAMUNIFORM3DVPROC)	   windows_opengl_loadptr("glProgramUniform3dv");
    SharedGL_glProgramUniform3ui	    = (PFNGLPROGRAMUNIFORM3UIPROC)	   windows_opengl_loadptr("glProgramUniform3ui");
    SharedGL_glProgramUniform3uiv	    = (PFNGLPROGRAMUNIFORM3UIVPROC)	   windows_opengl_loadptr("glProgramUniform3uiv");
    SharedGL_glProgramUniform4i	    = (PFNGLPROGRAMUNIFORM4IPROC)	   windows_opengl_loadptr("glProgramUniform4i");
    SharedGL_glProgramUniform4iv	    = (PFNGLPROGRAMUNIFORM4IVPROC)	   windows_opengl_loadptr("glProgramUniform4iv");
    SharedGL_glProgramUniform4f	    = (PFNGLPROGRAMUNIFORM4FPROC)	   windows_opengl_loadptr("glProgramUniform4f");
    SharedGL_glProgramUniform4fv	    = (PFNGLPROGRAMUNIFORM4FVPROC)	   windows_opengl_loadptr("glProgramUniform4fv");
    SharedGL_glProgramUniform4d	    = (PFNGLPROGRAMUNIFORM4DPROC)	   windows_opengl_loadptr("glProgramUniform4d");
    SharedGL_glProgramUniform4dv	    = (PFNGLPROGRAMUNIFORM4DVPROC)	   windows_opengl_loadptr("glProgramUniform4dv");
    SharedGL_glProgramUniform4ui	    = (PFNGLPROGRAMUNIFORM4UIPROC)	   windows_opengl_loadptr("glProgramUniform4ui");
    SharedGL_glProgramUniform4uiv	    = (PFNGLPROGRAMUNIFORM4UIVPROC)	   windows_opengl_loadptr("glProgramUniform4uiv");
    SharedGL_glProgramUniformMatrix2fv   = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC)   windows_opengl_loadptr("glProgramUniformMatrix2fv");
    SharedGL_glProgramUniformMatrix3fv   = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC)   windows_opengl_loadptr("glProgramUniformMatrix3fv");
    SharedGL_glProgramUniformMatrix4fv   = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC)   windows_opengl_loadptr("glProgramUniformMatrix4fv");
    SharedGL_glProgramUniformMatrix2dv   = (PFNGLPROGRAMUNIFORMMATRIX2DVPROC)   windows_opengl_loadptr("glProgramUniformMatrix2dv");
    SharedGL_glProgramUniformMatrix3dv   = (PFNGLPROGRAMUNIFORMMATRIX3DVPROC)   windows_opengl_loadptr("glProgramUniformMatrix3dv");
    SharedGL_glProgramUniformMatrix4dv   = (PFNGLPROGRAMUNIFORMMATRIX4DVPROC)   windows_opengl_loadptr("glProgramUniformMatrix4dv");
    SharedGL_glProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC) windows_opengl_loadptr("glProgramUniformMatrix2x3fv");
    SharedGL_glProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC) windows_opengl_loadptr("glProgramUniformMatrix3x2fv");
    SharedGL_glProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC) windows_opengl_loadptr("glProgramUniformMatrix2x4fv");
    SharedGL_glProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC) windows_opengl_loadptr("glProgramUniformMatrix4x2fv");
    SharedGL_glProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC) windows_opengl_loadptr("glProgramUniformMatrix3x4fv");
    SharedGL_glProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC) windows_opengl_loadptr("glProgramUniformMatrix4x3fv");
    SharedGL_glProgramUniformMatrix2x3dv = (PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC) windows_opengl_loadptr("glProgramUniformMatrix2x3dv");
    SharedGL_glProgramUniformMatrix3x2dv = (PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC) windows_opengl_loadptr("glProgramUniformMatrix3x2dv");
    SharedGL_glProgramUniformMatrix2x4dv = (PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC) windows_opengl_loadptr("glProgramUniformMatrix2x4dv");
    SharedGL_glProgramUniformMatrix4x2dv = (PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC) windows_opengl_loadptr("glProgramUniformMatrix4x2dv");
    SharedGL_glProgramUniformMatrix3x4dv = (PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC) windows_opengl_loadptr("glProgramUniformMatrix3x4dv");
    SharedGL_glProgramUniformMatrix4x3dv = (PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC) windows_opengl_loadptr("glProgramUniformMatrix4x3dv");
    SharedGL_glValidateProgramPipeline   = (PFNGLVALIDATEPROGRASharedGLIPELINEPROC)   windows_opengl_loadptr("glValidateProgramPipeline");
    SharedGL_glGetProgramPipelineInfoLog = (PFNGLGETPROGRASharedGLIPELINEINFOLOGPROC) windows_opengl_loadptr("glGetProgramPipelineInfoLog");
    SharedGL_glVertexAttribL1d	    = (PFNGLVERTEXATTRIBL1DPROC)	   windows_opengl_loadptr("glVertexAttribL1d");
    SharedGL_glVertexAttribL2d	    = (PFNGLVERTEXATTRIBL2DPROC)	   windows_opengl_loadptr("glVertexAttribL2d");
    SharedGL_glVertexAttribL3d	    = (PFNGLVERTEXATTRIBL3DPROC)	   windows_opengl_loadptr("glVertexAttribL3d");
    SharedGL_glVertexAttribL4d	    = (PFNGLVERTEXATTRIBL4DPROC)	   windows_opengl_loadptr("glVertexAttribL4d");
    SharedGL_glVertexAttribL1dv	    = (PFNGLVERTEXATTRIBL1DVPROC)	   windows_opengl_loadptr("glVertexAttribL1dv");
    SharedGL_glVertexAttribL2dv	    = (PFNGLVERTEXATTRIBL2DVPROC)	   windows_opengl_loadptr("glVertexAttribL2dv");
    SharedGL_glVertexAttribL3dv	    = (PFNGLVERTEXATTRIBL3DVPROC)	   windows_opengl_loadptr("glVertexAttribL3dv");
    SharedGL_glVertexAttribL4dv	    = (PFNGLVERTEXATTRIBL4DVPROC)	   windows_opengl_loadptr("glVertexAttribL4dv");
    SharedGL_glVertexAttribLPointer	    = (PFNGLVERTEXATTRIBLPOINTERPROC)	   windows_opengl_loadptr("glVertexAttribLPointer");
    SharedGL_glGetVertexAttribLdv	    = (PFNGLGETVERTEXATTRIBLDVPROC)	   windows_opengl_loadptr("glGetVertexAttribLdv");
    SharedGL_glViewportArrayv	    = (PFNGLVIEWPORTARRAYVPROC)		   windows_opengl_loadptr("glViewportArrayv");
    SharedGL_glViewportIndexedf	    = (PFNGLVIEWPORTINDEXEDFPROC)	   windows_opengl_loadptr("glViewportIndexedf");
    SharedGL_glViewportIndexedfv	    = (PFNGLVIEWPORTINDEXEDFVPROC)	   windows_opengl_loadptr("glViewportIndexedfv");
    SharedGL_glScissorArrayv		    = (PFNGLSCISSORARRAYVPROC)		   windows_opengl_loadptr("glScissorArrayv");
    SharedGL_glScissorIndexed	    = (PFNGLSCISSORINDEXEDPROC)		   windows_opengl_loadptr("glScissorIndexed");
    SharedGL_glScissorIndexedv	    = (PFNGLSCISSORINDEXEDVPROC)	   windows_opengl_loadptr("glScissorIndexedv");
    SharedGL_glDepthRangeArrayv	    = (PFNGLDEPTHRANGEARRAYVPROC)	   windows_opengl_loadptr("glDepthRangeArrayv");
    SharedGL_glDepthRangeIndexed	    = (PFNGLDEPTHRANGEINDEXEDPROC)	   windows_opengl_loadptr("glDepthRangeIndexed");
    SharedGL_glGetFloati_v		    = (PFNGLGETFLOATI_VPROC)		   windows_opengl_loadptr("glGetFloati_v");
    SharedGL_glGetDoublei_v		    = (PFNGLGETDOUBLEI_VPROC)		   windows_opengl_loadptr("glGetDoublei_v");
    
    // 4.2 
    SharedGL_glDrawArraysInstancedBaseInstance	      = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)		windows_opengl_loadptr("glDrawArraysInstancedBaseInstance");
    SharedGL_glDrawElementsInstancedBaseInstance	      = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)		windows_opengl_loadptr("glDrawElementsInstancedBaseInstance");
    SharedGL_glDrawElementsInstancedBaseVertexBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)	windows_opengl_loadptr("glDrawElementsInstancedBaseVertexBaseInstance");
    SharedGL_glGetInternalformativ			      = (PFNGLGETINTERNALFORMATIVPROC)				windows_opengl_loadptr("glGetInternalformativ");
    SharedGL_glGetActiveAtomicCounterBufferiv	      = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)		windows_opengl_loadptr("glGetActiveAtomicCounterBufferiv");
    SharedGL_glBindImageTexture			      = (PFNGLBINDIMAGETEXTUREPROC)				windows_opengl_loadptr("glBindImageTexture");
    SharedGL_glMemoryBarrier				      = (PFNGLMEMORYBARRIERPROC)				windows_opengl_loadptr("glMemoryBarrier");
    SharedGL_glTexStorage1D				      = (PFNGLTEXSTORAGE1DPROC)					windows_opengl_loadptr("glTexStorage1D");
    SharedGL_glTexStorage2D				      = (PFNGLTEXSTORAGE2DPROC)					windows_opengl_loadptr("glTexStorage2D");
    SharedGL_glTexStorage3D				      = (PFNGLTEXSTORAGE3DPROC)					windows_opengl_loadptr("glTexStorage3D");
    SharedGL_glDrawTransformFeedbackInstanced	      = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)		windows_opengl_loadptr("glDrawTransformFeedbackInstanced");
    SharedGL_glDrawTransformFeedbackStreamInstanced	      = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)		windows_opengl_loadptr("glDrawTransformFeedbackStreamInstanced");
    
    // 4.3 
    SharedGL_glClearBufferData		  = (PFNGLCLEARBUFFERDATAPROC)		        windows_opengl_loadptr("glClearBufferData");
    SharedGL_glClearBufferSubData		  = (PFNGLCLEARBUFFERSUBDATAPROC)	        windows_opengl_loadptr("glClearBufferSubData");
    SharedGL_glDispatchCompute		  = (PFNGLDISPATCHCOSharedGLUTEPROC)		        windows_opengl_loadptr("glDispatchCompute");
    SharedGL_glDispatchComputeIndirect	  = (PFNGLDISPATCHCOSharedGLUTEINDIRECTPROC)	        windows_opengl_loadptr("glDispatchComputeIndirect");
    SharedGL_glCopyImageSubData		  = (PFNGLCOPYIMAGESUBDATAPROC)		        windows_opengl_loadptr("glCopyImageSubData");
    SharedGL_glFramebufferParameteri		  = (PFNGLFRAMEBUFFERPARAMETERIPROC)	        windows_opengl_loadptr("glFramebufferParameteri");
    SharedGL_glGetFramebufferParameteriv	  = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC)        windows_opengl_loadptr("glGetFramebufferParameteriv");
    SharedGL_glGetInternalformati64v		  = (PFNGLGETINTERNALFORMATI64VPROC)	        windows_opengl_loadptr("glGetInternalformati64v");
    SharedGL_glInvalidateTexSubImage		  = (PFNGLINVALIDATETEXSUBIMAGEPROC)	        windows_opengl_loadptr("glInvalidateTexSubImage");
    SharedGL_glInvalidateTexImage		  = (PFNGLINVALIDATETEXIMAGEPROC)	        windows_opengl_loadptr("glInvalidateTexImage");
    SharedGL_glInvalidateBufferSubData	  = (PFNGLINVALIDATEBUFFERSUBDATAPROC)	        windows_opengl_loadptr("glInvalidateBufferSubData");
    SharedGL_glInvalidateBufferData		  = (PFNGLINVALIDATEBUFFERDATAPROC)	        windows_opengl_loadptr("glInvalidateBufferData");
    SharedGL_glInvalidateFramebuffer		  = (PFNGLINVALIDATEFRAMEBUFFERPROC)	        windows_opengl_loadptr("glInvalidateFramebuffer");
    SharedGL_glInvalidateSubFramebuffer	  = (PFNGLINVALIDATESUBFRAMEBUFFERPROC)	        windows_opengl_loadptr("glInvalidateSubFramebuffer");
    SharedGL_glMultiDrawArraysIndirect	  = (PFNGLMULTIDRAWARRAYSINDIRECTPROC)	        windows_opengl_loadptr("glMultiDrawArraysIndirect");
    SharedGL_glMultiDrawElementsIndirect	  = (PFNGLMULTIDRAWELEMENTSINDIRECTPROC)        windows_opengl_loadptr("glMultiDrawElementsIndirect");
    SharedGL_glGetProgramInterfaceiv		  = (PFNGLGETPROGRAMINTERFACEIVPROC)	        windows_opengl_loadptr("glGetProgramInterfaceiv");
    SharedGL_glGetProgramResourceIndex	  = (PFNGLGETPROGRAMRESOURCEINDEXPROC)	        windows_opengl_loadptr("glGetProgramResourceIndex");
    SharedGL_glGetProgramResourceName	  = (PFNGLGETPROGRAMRESOURCENAMEPROC)	        windows_opengl_loadptr("glGetProgramResourceName");
    SharedGL_glGetProgramResourceiv		  = (PFNGLGETPROGRAMRESOURCEIVPROC)	        windows_opengl_loadptr("glGetProgramResourceiv");
    SharedGL_glGetProgramResourceLocation	  = (PFNGLGETPROGRAMRESOURCELOCATIONPROC)	windows_opengl_loadptr("glGetProgramResourceLocation");
    SharedGL_glGetProgramResourceLocationIndex = (PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)	windows_opengl_loadptr("glGetProgramResourceLocationIndex");
    SharedGL_glShaderStorageBlockBinding	  = (PFNGLSHADERSTORAGEBLOCKBINDINGPROC)	windows_opengl_loadptr("glShaderStorageBlockBinding");
    SharedGL_glTexBufferRange		  = (PFNGLTEXBUFFERRANGEPROC)			windows_opengl_loadptr("glTexBufferRange");
    SharedGL_glTexStorage2DMultisample	  = (PFNGLTEXSTORAGE2DMULTISASharedGLLEPROC)		windows_opengl_loadptr("glTexStorage2DMultisample");
    SharedGL_glTexStorage3DMultisample	  = (PFNGLTEXSTORAGE3DMULTISASharedGLLEPROC)		windows_opengl_loadptr("glTexStorage3DMultisample");
    SharedGL_glTextureView			  = (PFNGLTEXTUREVIEWPROC)			windows_opengl_loadptr("glTextureView");
    SharedGL_glBindVertexBuffer		  = (PFNGLBINDVERTEXBUFFERPROC)			windows_opengl_loadptr("glBindVertexBuffer");
    SharedGL_glVertexAttribFormat		  = (PFNGLVERTEXATTRIBFORMATPROC)		windows_opengl_loadptr("glVertexAttribFormat");
    SharedGL_glVertexAttribIFormat		  = (PFNGLVERTEXATTRIBIFORMATPROC)		windows_opengl_loadptr("glVertexAttribIFormat");
    SharedGL_glVertexAttribLFormat		  = (PFNGLVERTEXATTRIBLFORMATPROC)		windows_opengl_loadptr("glVertexAttribLFormat");
    SharedGL_glVertexAttribBinding		  = (PFNGLVERTEXATTRIBBINDINGPROC)		windows_opengl_loadptr("glVertexAttribBinding");
    SharedGL_glVertexBindingDivisor		  = (PFNGLVERTEXBINDINGDIVISORPROC)		windows_opengl_loadptr("glVertexBindingDivisor");
    SharedGL_glDebugMessageControl		  = (PFNGLDEBUGMESSAGECONTROLPROC)		windows_opengl_loadptr("glDebugMessageControl");
    SharedGL_glDebugMessageInsert		  = (PFNGLDEBUGMESSAGEINSERTPROC)		windows_opengl_loadptr("glDebugMessageInsert");
    SharedGL_glDebugMessageCallback		  = (PFNGLDEBUGMESSAGECALLBACKPROC)		windows_opengl_loadptr("glDebugMessageCallback");
    SharedGL_glGetDebugMessageLog		  = (PFNGLGETDEBUGMESSAGELOGPROC)		windows_opengl_loadptr("glGetDebugMessageLog");
    SharedGL_glPushDebugGroup		  = (PFNGLPUSHDEBUGGROUPPROC)			windows_opengl_loadptr("glPushDebugGroup");
    SharedGL_glPopDebugGroup			  = (PFNGLPOPDEBUGGROUPPROC)			windows_opengl_loadptr("glPopDebugGroup");
    SharedGL_glObjectLabel			  = (PFNGLOBJECTLABELPROC)			windows_opengl_loadptr("glObjectLabel");
    SharedGL_glGetObjectLabel		  = (PFNGLGETOBJECTLABELPROC)			windows_opengl_loadptr("glGetObjectLabel");
    SharedGL_glObjectPtrLabel		  = (PFNGLOBJECTPTRLABELPROC)			windows_opengl_loadptr("glObjectPtrLabel");
    SharedGL_glGetObjectPtrLabel		  = (PFNGLGETOBJECTPTRLABELPROC)		windows_opengl_loadptr("glGetObjectPtrLabel");
    SharedGL_glGetPointerv			  = (PFNGLGETPOINTERVPROC)			windows_opengl_loadptr("glGetPointerv");
    
    /* note: 4.4 */
    SharedGL_glBufferStorage	    = (PFNGLBUFFERSTORAGEPROC)	   windows_opengl_loadptr("glBufferStorage");
    SharedGL_glClearTexImage	    = (PFNGLCLEARTEXIMAGEPROC)	   windows_opengl_loadptr("glClearTexImage");
    SharedGL_glClearTexSubImage  = (PFNGLCLEARTEXSUBIMAGEPROC)  windows_opengl_loadptr("glClearTexSubImage");
    SharedGL_glBindBuffersBase   = (PFNGLBINDBUFFERSBASEPROC)   windows_opengl_loadptr("glBindBuffersBase");
    SharedGL_glBindBuffersRange  = (PFNGLBINDBUFFERSRANGEPROC)  windows_opengl_loadptr("glBindBuffersRange");
    SharedGL_glBindTextures	    = (PFNGLBINDTEXTURESPROC)	   windows_opengl_loadptr("glBindTextures");
    SharedGL_glBindSamplers	    = (PFNGLBINDSASharedGLLERSPROC)	   windows_opengl_loadptr("glBindSamplers");
    SharedGL_glBindImageTextures = (PFNGLBINDIMAGETEXTURESPROC) windows_opengl_loadptr("glBindImageTextures");
    SharedGL_glBindVertexBuffers = (PFNGLBINDVERTEXBUFFERSPROC) windows_opengl_loadptr("glBindVertexBuffers");
    
    // 4.5 
    SharedGL_glClipControl				   = (PFNGLCLIPCONTROLPROC)			         windows_opengl_loadptr("glClipControl");
    SharedGL_glCreateTransformFeedbacks		   = (PFNGLCREATETRANSFORMFEEDBACKSPROC)	         windows_opengl_loadptr("glCreateTransformFeedbacks");
    SharedGL_glTransformFeedbackBufferBase		   = (PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)	         windows_opengl_loadptr("glTransformFeedbackBufferBase");
    SharedGL_glTransformFeedbackBufferRange		   = (PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)	         windows_opengl_loadptr("glTransformFeedbackBufferRange");
    SharedGL_glGetTransformFeedbackiv		   = (PFNGLGETTRANSFORMFEEDBACKIVPROC)		         windows_opengl_loadptr("glGetTransformFeedbackiv");
    SharedGL_glGetTransformFeedbacki_v		   = (PFNGLGETTRANSFORMFEEDBACKI_VPROC)		         windows_opengl_loadptr("glGetTransformFeedbacki_v");
    SharedGL_glGetTransformFeedbacki64_v		   = (PFNGLGETTRANSFORMFEEDBACKI64_VPROC)	         windows_opengl_loadptr("glGetTransformFeedbacki64_v");
    SharedGL_glCreateBuffers				   = (PFNGLCREATEBUFFERSPROC)			         windows_opengl_loadptr("glCreateBuffers");
    SharedGL_glNamedBufferStorage			   = (PFNGLNAMEDBUFFERSTORAGEPROC)		         windows_opengl_loadptr("glNamedBufferStorage");
    SharedGL_glNamedBufferData			   = (PFNGLNAMEDBUFFERDATAPROC)			         windows_opengl_loadptr("glNamedBufferData");
    SharedGL_glNamedBufferSubData			   = (PFNGLNAMEDBUFFERSUBDATAPROC)		         windows_opengl_loadptr("glNamedBufferSubData");
    SharedGL_glCopyNamedBufferSubData		   = (PFNGLCOPYNAMEDBUFFERSUBDATAPROC)		         windows_opengl_loadptr("glCopyNamedBufferSubData");
    SharedGL_glClearNamedBufferData			   = (PFNGLCLEARNAMEDBUFFERDATAPROC)		         windows_opengl_loadptr("glClearNamedBufferData");
    SharedGL_glClearNamedBufferSubData		   = (PFNGLCLEARNAMEDBUFFERSUBDATAPROC)		         windows_opengl_loadptr("glClearNamedBufferSubData");
    SharedGL_glMapNamedBuffer			   = (PFNGLMAPNAMEDBUFFERPROC)			         windows_opengl_loadptr("glMapNamedBuffer");
    SharedGL_glMapNamedBufferRange			   = (PFNGLMAPNAMEDBUFFERRANGEPROC)		         windows_opengl_loadptr("glMapNamedBufferRange");
    SharedGL_glUnmapNamedBuffer			   = (PFNGLUNMAPNAMEDBUFFERPROC)		         windows_opengl_loadptr("glUnmapNamedBuffer");
    SharedGL_glFlushMappedNamedBufferRange		   = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)	         windows_opengl_loadptr("glFlushMappedNamedBufferRange");
    SharedGL_glGetNamedBufferParameteriv		   = (PFNGLGETNAMEDBUFFERPARAMETERIVPROC)	         windows_opengl_loadptr("glGetNamedBufferParameteriv");
    SharedGL_glGetNamedBufferParameteri64v		   = (PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)	         windows_opengl_loadptr("glGetNamedBufferParameteri64v");
    SharedGL_glGetNamedBufferPointerv		   = (PFNGLGETNAMEDBUFFERPOINTERVPROC)		         windows_opengl_loadptr("glGetNamedBufferPointerv");
    SharedGL_glGetNamedBufferSubData			   = (PFNGLGETNAMEDBUFFERSUBDATAPROC)		         windows_opengl_loadptr("glGetNamedBufferSubData");
    SharedGL_glCreateFramebuffers			   = (PFNGLCREATEFRAMEBUFFERSPROC)		         windows_opengl_loadptr("glCreateFramebuffers");
    SharedGL_glNamedFramebufferRenderbuffer		   = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)	         windows_opengl_loadptr("glNamedFramebufferRenderbuffer");
    SharedGL_glNamedFramebufferParameteri		   = (PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)	         windows_opengl_loadptr("glNamedFramebufferParameteri");
    SharedGL_glNamedFramebufferTexture		   = (PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)		         windows_opengl_loadptr("glNamedFramebufferTexture");
    SharedGL_glNamedFramebufferTextureLayer		   = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)	         windows_opengl_loadptr("glNamedFramebufferTextureLayer");
    SharedGL_glNamedFramebufferDrawBuffer		   = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)	         windows_opengl_loadptr("glNamedFramebufferDrawBuffer");
    SharedGL_glNamedFramebufferDrawBuffers		   = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)	         windows_opengl_loadptr("glNamedFramebufferDrawBuffers");
    SharedGL_glNamedFramebufferReadBuffer		   = (PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)	         windows_opengl_loadptr("glNamedFramebufferReadBuffer");
    SharedGL_glInvalidateNamedFramebufferData	   = (PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)	         windows_opengl_loadptr("glInvalidateNamedFramebufferData");
    SharedGL_glInvalidateNamedFramebufferSubData	   = (PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)        windows_opengl_loadptr("glInvalidateNamedFramebufferSubData");
    SharedGL_glClearNamedFramebufferiv		   = (PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)		         windows_opengl_loadptr("glClearNamedFramebufferiv");
    SharedGL_glClearNamedFramebufferuiv		   = (PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)	         windows_opengl_loadptr("glClearNamedFramebufferuiv");
    SharedGL_glClearNamedFramebufferfv		   = (PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)		         windows_opengl_loadptr("glClearNamedFramebufferfv");
    SharedGL_glClearNamedFramebufferfi		   = (PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)		         windows_opengl_loadptr("glClearNamedFramebufferfi");
    SharedGL_glBlitNamedFramebuffer			   = (PFNGLBLITNAMEDFRAMEBUFFERPROC)		         windows_opengl_loadptr("glBlitNamedFramebuffer");
    SharedGL_glCheckNamedFramebufferStatus		   = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)	         windows_opengl_loadptr("glCheckNamedFramebufferStatus");
    SharedGL_glGetNamedFramebufferParameteriv	   = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)	         windows_opengl_loadptr("glGetNamedFramebufferParameteriv");
    SharedGL_glGetNamedFramebufferAttachmentParameteriv = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC) windows_opengl_loadptr("glGetNamedFramebufferAttachmentParameteriv");
    SharedGL_glCreateRenderbuffers			   = (PFNGLCREATERENDERBUFFERSPROC)			 windows_opengl_loadptr("glCreateRenderbuffers");
    SharedGL_glNamedRenderbufferStorage		   = (PFNGLNAMEDRENDERBUFFERSTORAGEPROC)		 windows_opengl_loadptr("glNamedRenderbufferStorage");
    SharedGL_glNamedRenderbufferStorageMultisample	   = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISASharedGLLEPROC)	 windows_opengl_loadptr("glNamedRenderbufferStorageMultisample");
    SharedGL_glGetNamedRenderbufferParameteriv	   = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)	         windows_opengl_loadptr("glGetNamedRenderbufferParameteriv");
    SharedGL_glCreateTextures			   = (PFNGLCREATETEXTURESPROC)			         windows_opengl_loadptr("glCreateTextures");
    SharedGL_glTextureBuffer				   = (PFNGLTEXTUREBUFFERPROC)			         windows_opengl_loadptr("glTextureBuffer");
    SharedGL_glTextureBufferRange			   = (PFNGLTEXTUREBUFFERRANGEPROC)		         windows_opengl_loadptr("glTextureBufferRange");
    SharedGL_glTextureStorage1D			   = (PFNGLTEXTURESTORAGE1DPROC)		         windows_opengl_loadptr("glTextureStorage1D");
    SharedGL_glTextureStorage2D			   = (PFNGLTEXTURESTORAGE2DPROC)		         windows_opengl_loadptr("glTextureStorage2D");
    SharedGL_glTextureStorage3D			   = (PFNGLTEXTURESTORAGE3DPROC)		         windows_opengl_loadptr("glTextureStorage3D");
    SharedGL_glTextureStorage2DMultisample		   = (PFNGLTEXTURESTORAGE2DMULTISASharedGLLEPROC)	         windows_opengl_loadptr("glTextureStorage2DMultisample");
    SharedGL_glTextureStorage3DMultisample		   = (PFNGLTEXTURESTORAGE3DMULTISASharedGLLEPROC)	         windows_opengl_loadptr("glTextureStorage3DMultisample");
    SharedGL_glTextureSubImage1D			   = (PFNGLTEXTURESUBIMAGE1DPROC)		         windows_opengl_loadptr("glTextureSubImage1D");
    SharedGL_glTextureSubImage2D			   = (PFNGLTEXTURESUBIMAGE2DPROC)		         windows_opengl_loadptr("glTextureSubImage2D");
    SharedGL_glTextureSubImage3D			   = (PFNGLTEXTURESUBIMAGE3DPROC)		         windows_opengl_loadptr("glTextureSubImage3D");
    SharedGL_glCompressedTextureSubImage1D		   = (PFNGLCOSharedGLRESSEDTEXTURESUBIMAGE1DPROC)	         windows_opengl_loadptr("glCompressedTextureSubImage1D");
    SharedGL_glCompressedTextureSubImage2D		   = (PFNGLCOSharedGLRESSEDTEXTURESUBIMAGE2DPROC)	         windows_opengl_loadptr("glCompressedTextureSubImage2D");
    SharedGL_glCompressedTextureSubImage3D		   = (PFNGLCOSharedGLRESSEDTEXTURESUBIMAGE3DPROC)	         windows_opengl_loadptr("glCompressedTextureSubImage3D");
    SharedGL_glCopyTextureSubImage1D			   = (PFNGLCOPYTEXTURESUBIMAGE1DPROC)		         windows_opengl_loadptr("glCopyTextureSubImage1D");
    SharedGL_glCopyTextureSubImage2D			   = (PFNGLCOPYTEXTURESUBIMAGE2DPROC)		         windows_opengl_loadptr("glCopyTextureSubImage2D");
    SharedGL_glCopyTextureSubImage3D			   = (PFNGLCOPYTEXTURESUBIMAGE3DPROC)		         windows_opengl_loadptr("glCopyTextureSubImage3D");
    SharedGL_glTextureParameterf			   = (PFNGLTEXTUREPARAMETERFPROC)		         windows_opengl_loadptr("glTextureParameterf");
    SharedGL_glTextureParameterfv			   = (PFNGLTEXTUREPARAMETERFVPROC)		         windows_opengl_loadptr("glTextureParameterfv");
    SharedGL_glTextureParameteri			   = (PFNGLTEXTUREPARAMETERIPROC)		         windows_opengl_loadptr("glTextureParameteri");
    SharedGL_glTextureParameterIiv			   = (PFNGLTEXTUREPARAMETERIIVPROC)		         windows_opengl_loadptr("glTextureParameterIiv");
    SharedGL_glTextureParameterIuiv			   = (PFNGLTEXTUREPARAMETERIUIVPROC)		         windows_opengl_loadptr("glTextureParameterIuiv");
    SharedGL_glTextureParameteriv			   = (PFNGLTEXTUREPARAMETERIVPROC)		         windows_opengl_loadptr("glTextureParameteriv");
    SharedGL_glGenerateTextureMipmap			   = (PFNGLGENERATETEXTUREMIPMAPPROC)		         windows_opengl_loadptr("glGenerateTextureMipmap");
    SharedGL_glBindTextureUnit			   = (PFNGLBINDTEXTUREUNITPROC)			         windows_opengl_loadptr("glBindTextureUnit");
    SharedGL_glGetTextureImage			   = (PFNGLGETTEXTUREIMAGEPROC)			         windows_opengl_loadptr("glGetTextureImage");
    SharedGL_glGetCompressedTextureImage		   = (PFNGLGETCOSharedGLRESSEDTEXTUREIMAGEPROC)	         windows_opengl_loadptr("glGetCompressedTextureImage");
    SharedGL_glGetTextureLevelParameterfv		   = (PFNGLGETTEXTURELEVELPARAMETERFVPROC)	         windows_opengl_loadptr("glGetTextureLevelParameterfv");
    SharedGL_glGetTextureLevelParameteriv		   = (PFNGLGETTEXTURELEVELPARAMETERIVPROC)	         windows_opengl_loadptr("glGetTextureLevelParameteriv");
    SharedGL_glGetTextureParameterfv			   = (PFNGLGETTEXTUREPARAMETERFVPROC)		         windows_opengl_loadptr("glGetTextureParameterfv");
    SharedGL_glGetTextureParameterIiv		   = (PFNGLGETTEXTUREPARAMETERIIVPROC)		         windows_opengl_loadptr("glGetTextureParameterIiv");
    SharedGL_glGetTextureParameterIuiv		   = (PFNGLGETTEXTUREPARAMETERIUIVPROC)		         windows_opengl_loadptr("glGetTextureParameterIuiv");
    SharedGL_glGetTextureParameteriv			   = (PFNGLGETTEXTUREPARAMETERIVPROC)		         windows_opengl_loadptr("glGetTextureParameteriv");
    SharedGL_glCreateVertexArrays			   = (PFNGLCREATEVERTEXARRAYSPROC)		         windows_opengl_loadptr("glCreateVertexArrays");
    SharedGL_glDisableVertexArrayAttrib		   = (PFNGLDISABLEVERTEXARRAYATTRIBPROC)	         windows_opengl_loadptr("glDisableVertexArrayAttrib");
    SharedGL_glEnableVertexArrayAttrib		   = (PFNGLENABLEVERTEXARRAYATTRIBPROC)		         windows_opengl_loadptr("glEnableVertexArrayAttrib");
    SharedGL_glVertexArrayElementBuffer		   = (PFNGLVERTEXARRAYELEMENTBUFFERPROC)	         windows_opengl_loadptr("glVertexArrayElementBuffer");
    SharedGL_glVertexArrayVertexBuffer		   = (PFNGLVERTEXARRAYVERTEXBUFFERPROC)		         windows_opengl_loadptr("glVertexArrayVertexBuffer");
    SharedGL_glVertexArrayVertexBuffers		   = (PFNGLVERTEXARRAYVERTEXBUFFERSPROC)	         windows_opengl_loadptr("glVertexArrayVertexBuffers");
    SharedGL_glVertexArrayAttribBinding		   = (PFNGLVERTEXARRAYATTRIBBINDINGPROC)	         windows_opengl_loadptr("glVertexArrayAttribBinding");
    SharedGL_glVertexArrayAttribFormat		   = (PFNGLVERTEXARRAYATTRIBFORMATPROC)		         windows_opengl_loadptr("glVertexArrayAttribFormat");
    SharedGL_glVertexArrayAttribIFormat		   = (PFNGLVERTEXARRAYATTRIBIFORMATPROC)	         windows_opengl_loadptr("glVertexArrayAttribIFormat");
    SharedGL_glVertexArrayAttribLFormat		   = (PFNGLVERTEXARRAYATTRIBLFORMATPROC)	         windows_opengl_loadptr("glVertexArrayAttribLFormat");
    SharedGL_glVertexArrayBindingDivisor		   = (PFNGLVERTEXARRAYBINDINGDIVISORPROC)	         windows_opengl_loadptr("glVertexArrayBindingDivisor");
    SharedGL_glGetVertexArrayiv			   = (PFNGLGETVERTEXARRAYIVPROC)		         windows_opengl_loadptr("glGetVertexArrayiv");
    SharedGL_glGetVertexArrayIndexediv		   = (PFNGLGETVERTEXARRAYINDEXEDIVPROC)		         windows_opengl_loadptr("glGetVertexArrayIndexediv");
    SharedGL_glGetVertexArrayIndexed64iv		   = (PFNGLGETVERTEXARRAYINDEXED64IVPROC)	         windows_opengl_loadptr("glGetVertexArrayIndexed64iv");
    SharedGL_glCreateSamplers			   = (PFNGLCREATESASharedGLLERSPROC)			         windows_opengl_loadptr("glCreateSamplers");
    SharedGL_glCreateProgramPipelines		   = (PFNGLCREATEPROGRASharedGLIPELINESPROC)		         windows_opengl_loadptr("glCreateProgramPipelines");
    SharedGL_glCreateQueries				   = (PFNGLCREATEQUERIESPROC)			         windows_opengl_loadptr("glCreateQueries");
    SharedGL_glGetQueryBufferObjecti64v		   = (PFNGLGETQUERYBUFFEROBJECTI64VPROC)	         windows_opengl_loadptr("glGetQueryBufferObjecti64v");
    SharedGL_glGetQueryBufferObjectiv		   = (PFNGLGETQUERYBUFFEROBJECTIVPROC)		         windows_opengl_loadptr("glGetQueryBufferObjectiv");
    SharedGL_glGetQueryBufferObjectui64v		   = (PFNGLGETQUERYBUFFEROBJECTUI64VPROC)	         windows_opengl_loadptr("glGetQueryBufferObjectui64v");
    SharedGL_glGetQueryBufferObjectuiv		   = (PFNGLGETQUERYBUFFEROBJECTUIVPROC)		         windows_opengl_loadptr("glGetQueryBufferObjectuiv");
    SharedGL_glMemoryBarrierByRegion			   = (PFNGLMEMORYBARRIERBYREGIONPROC)		         windows_opengl_loadptr("glMemoryBarrierByRegion");
    SharedGL_glGetTextureSubImage			   = (PFNGLGETTEXTURESUBIMAGEPROC)		         windows_opengl_loadptr("glGetTextureSubImage");
    SharedGL_glGetCompressedTextureSubImage		   = (PFNGLGETCOSharedGLRESSEDTEXTURESUBIMAGEPROC)	         windows_opengl_loadptr("glGetCompressedTextureSubImage");
    SharedGL_glGetGraphicsResetStatus		   = (PFNGLGETGRAPHICSRESETSTATUSPROC)		         windows_opengl_loadptr("glGetGraphicsResetStatus");
    SharedGL_glGetnCompressedTexImage		   = (PFNGLGETNCOSharedGLRESSEDTEXIMAGEPROC)		         windows_opengl_loadptr("glGetnCompressedTexImage");
    SharedGL_glGetnTexImage				   = (PFNGLGETNTEXIMAGEPROC)			         windows_opengl_loadptr("glGetnTexImage");
    SharedGL_glGetnUniformdv				   = (PFNGLGETNUNIFORMDVPROC)			         windows_opengl_loadptr("glGetnUniformdv");
    SharedGL_glGetnUniformfv				   = (PFNGLGETNUNIFORMFVPROC)			         windows_opengl_loadptr("glGetnUniformfv");
    SharedGL_glGetnUniformiv				   = (PFNGLGETNUNIFORMIVPROC)			         windows_opengl_loadptr("glGetnUniformiv");
    SharedGL_glGetnUniformuiv			   = (PFNGLGETNUNIFORMUIVPROC)			         windows_opengl_loadptr("glGetnUniformuiv");
    SharedGL_glReadnPixels				   = (PFNGLREADNPIXELSPROC)			         windows_opengl_loadptr("glReadnPixels");
    SharedGL_glGetnMapdv				   = (PFNGLGETNMAPDVPROC)			         windows_opengl_loadptr("glGetnMapdv");
    SharedGL_glGetnMapfv				   = (PFNGLGETNMAPFVPROC)			         windows_opengl_loadptr("glGetnMapfv");
    SharedGL_glGetnMapiv				   = (PFNGLGETNMAPIVPROC)			         windows_opengl_loadptr("glGetnMapiv");
    SharedGL_glGetnPixelMapfv			   = (PFNGLGETNPIXELMAPFVPROC)			         windows_opengl_loadptr("glGetnPixelMapfv");
    SharedGL_glGetnPixelMapuiv			   = (PFNGLGETNPIXELMAPUIVPROC)			         windows_opengl_loadptr("glGetnPixelMapuiv");
    SharedGL_glGetnPixelMapusv			   = (PFNGLGETNPIXELMAPUSVPROC)			         windows_opengl_loadptr("glGetnPixelMapusv");
    SharedGL_glGetnPolygonStipple			   = (PFNGLGETNPOLYGONSTIPPLEPROC)		         windows_opengl_loadptr("glGetnPolygonStipple");
    SharedGL_glGetnColorTable			   = (PFNGLGETNCOLORTABLEPROC)			         windows_opengl_loadptr("glGetnColorTable");
    SharedGL_glGetnConvolutionFilter			   = (PFNGLGETNCONVOLUTIONFILTERPROC)		         windows_opengl_loadptr("glGetnConvolutionFilter");
    SharedGL_glGetnSeparableFilter			   = (PFNGLGETNSEPARABLEFILTERPROC)		         windows_opengl_loadptr("glGetnSeparableFilter");
    SharedGL_glGetnHistogram				   = (PFNGLGETNHISTOGRASharedGLROC)			         windows_opengl_loadptr("glGetnHistogram");
    SharedGL_glGetnMinmax				   = (PFNGLGETNMINMAXPROC)			         windows_opengl_loadptr("glGetnMinmax");
    SharedGL_glTextureBarrier			   = (PFNGLTEXTUREBARRIERPROC)			         windows_opengl_loadptr("glTextureBarrier");
    
    // 4.6 
    SharedGL_glSpecializeShader		     = (PFNGLSPECIALIZESHADERPROC)		 windows_opengl_loadptr("glSpecializeShader");
    SharedGL_glMultiDrawArraysIndirectCount   = (PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)   windows_opengl_loadptr("glMultiDrawArraysIndirectCount");
    SharedGL_glMultiDrawElementsIndirectCount = (PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC) windows_opengl_loadptr("glMultiDrawElementsIndirectCount");
    SharedGL_glPolygonOffsetClamp	     = (PFNGLPOLYGONOFFSETCLASharedGLPROC)	         windows_opengl_loadptr("glPolygonOffsetClamp");
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
