#include <cassert>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <array>

#include <glm/glm.hpp>

#define _WIDTH_ 800
#define _HEIGHT_ 600

using namespace std;
using namespace glm;

int main() 
{
	/*std::string teste = (true == 1) ? "Verdadeiro" : "Falso";
	std::cout << teste << std::endl;*/

	assert(glfwInit() == GLFW_TRUE);

	GLFWwindow* Window = glfwCreateWindow(_WIDTH_, _HEIGHT_, "Blue Marble", nullptr, nullptr);
	assert(Window);

	// Ativa o contexto na janela window
	glfwMakeContextCurrent(Window);

	// Inicializando a lib glew
	assert(glewInit() == GLEW_OK);

	// Dados da palca de vídeo
	cout << "OpenGL vendor: " << glGetString(GL_VENDOR) << endl;
	cout << "OpenGL renderer: " << glGetString(GL_RENDERER) << endl;
	cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;

	//Definir um triângulo em coordenadas normalizadas
	array<vec3, 3> Triangle = {
		vec3{-1.0f, -1.0f, 0.0f},
		vec3{1.0f, -1.0f, 0.0f},
		vec3{0.0f, 1.0f, 0.0f}
	};

	// Copiar o triângulo para a GPU
	GLuint VertixBuffer;

	// Pedir para gerar o openGL gerar o identificado para o VertixBuffer
	glGenBuffers(1, &VertixBuffer);

	// Ativar o VertixBuffer como sendo o buffer para onde vamos copiar os dados do triângulo
	glBindBuffer(GL_ARRAY_BUFFER, VertixBuffer);

	// Copiar os dados para a memória de vídeo
	glBufferData(GL_ARRAY_BUFFER, sizeof(Triangle), Triangle.data(), GL_STATIC_DRAW);


	// Cor de fundo
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

	while (!glfwWindowShouldClose(Window))
	{
		// Limpa o framebuffer. 
		//GL_COLOR_BUFFER_BIT -> preenche a cor que foi configurada
		glClear(GL_COLOR_BUFFER_BIT);

		glEnableVertexAttribArray(0);

		// Diz ao openGL que o VertixBuffer vai ser o buffer ativo no momento
		glBindBuffer(GL_ARRAY_BUFFER, VertixBuffer);

		// Informa ao openGL onde, dentro do VertexBuffer, os vértices estão
		// No caso do array Triangles é contido em memória, logo basta dizer quantos vértices vamos
		// usar para desenhar o triângulo
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

		// Desenhar o triângulo
		glDrawArrays(GL_TRIANGLES, 0, 3);

		// Reverter o estado 
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDisableVertexAttribArray(0);

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

	// Desalocar o VertixBuffer
	glDeleteBuffers(1, &VertixBuffer);

	glfwTerminate();

	return 0;
}