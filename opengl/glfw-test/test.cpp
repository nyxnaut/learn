#include <GLFW/glfw3.h>
#include <thread>

int main() {
	glfwInit();

	//specifies we want at least OpenGL 3.2
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	// We want a context that *only* supports new core functionality
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// size of window, window title, fullscreen (see difference),
	// final option allows sharing of textures between gl contexts
	GLFWwindow* window1 = glfwCreateWindow(
		800,
		600,
		"OpenGL",
		nullptr,
		nullptr
	);
	GLFWwindow* window = glfwCreateWindow(
		800,
		600,
		"OpenGL",
		glfwGetPrimaryMonitor(),
		nullptr
	);
	
	// creates context from given window
	glfwMakeContextCurrent(window);

	//glfw uses a closed event loop so you only have to handle events when you want
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
}
