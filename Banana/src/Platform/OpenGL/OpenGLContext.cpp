#include "bnpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace Banana {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		BN_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		BN_CORE_ASSERT(status, "Failed to initialize Glad!");

		BN_CORE_INFO("OpenGL Info:");
		BN_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		BN_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		BN_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}