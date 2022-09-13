#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);


int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//Create window
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGl", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	//GLAD: to retrieve locations of drivers which is OS-specific
	//basically load all OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//set viewport
	glViewport(0, 0, 800, 600);

	//Resize viewport when window got resized
	//void framebuffer_size_callback(GLFWwindow * window, int width, int height);

	//call this everytime window resize
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	

	//Render loop (keep drawing images until being called stop)
	//We want to place all the rendering commands in the render loop
	while (!glfwWindowShouldClose(window))
	{
		//Input
		processInput(window);

		//Render commands
		
		//We want to clear screen at the start of the frame
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		//glfw: swap buffer and poll IO events
		// -----------------------------------------------------------
		//check if any events are triggered
		glfwPollEvents();

		//swap color buffer used to render to and show it as output
		//front buffer contains final output, back buffer contains pixel being drawn
		//when finish rendering, swap back to front
		glfwSwapBuffers(window);

	}

	//glfw: terminate and clearing resources
	// -----------------------------------------------------------
	glfwTerminate();
	return 0;

}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}