#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// set actual window size and allow user resizing
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}
int main() {
	glfwInit();
	// specifies desired OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// We want a context that *only* supports new core functionality
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// size of window, window title, fullscreen (see difference),
	// final option allows sharing of textures between gl contexts
	GLFWwindow* window = glfwCreateWindow(
		800,
		600,
		"OpenGL",
		nullptr,
		nullptr
	);
	// GLFWwindow* windowF = glfwCreateWindow(
	// 	800,
	// 	600,
	// 	"OpenGL",
	// 	glfwGetPrimaryMonitor(),
	// 	nullptr
	// );

	// creates context from given window
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// GLAD manages function pointers for OpenGL so initalize
	// before calling any OpenGL function
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// glfw uses a closed event loop so you only have to handle events when you want
	// makes this example really simple:

	while(!glfwWindowShouldClose(window)) {
		// swaps between front and back buffers
		glfwSwapBuffers(window);
		// retrieve window events
		glfwPollEvents();
		// if fullscreen you should also add a keybind to close the window
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);
	}
	glfwTerminate();
	return 0;
}
