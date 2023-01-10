#include <iostream>
#include <GLFW/glfw3.h>
#include <cassert>
#define _WIDTH_ 800
#define _HEIGHT_ 600


using namespace std;


int main() 
{
	assert(glfwInit());

	GLFWwindow* Window = glfwCreateWindow(_WIDTH_, _HEIGHT_, "Blue Marble", nullptr, nullptr);
	assert(Window);

	while (!glfwWindowShouldClose(Window))
	{
		// Processa todos os eventos na fila do GLFW
		// Eventos podem ser: teclado, mouse, gamepad
		glfwPollEvents();

		// Envia o conteúdo do gramebuffer da janela para ser desenhado na tela
		// 480.000 pixels. Cada pixel é composto por 3 bytes(480.000*3=1.440.000)
		// 1.440.000 / 1024 ~ 1.406. 14.406 / 1024 = 1,37329 MB de memória RAM
		glfwSwapBuffers(Window);

		// glfwSwapBuffers(Window) -> pega os 1.37 MB e envia para memória de vídeo
		// Back -> front(tela): swap
	}

	glfwTerminate();

	return 0;
}