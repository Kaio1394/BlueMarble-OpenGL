#define GLM_SWIZZLE

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

using namespace std;

void Construtors()
{
	glm::vec2 P0{10.0f, 10.0f};
	glm::vec3 P1{10.0f, 0.0f, 0.0f};
	glm::vec4 P2{10.0f, 0.0f, 0.0f, 0.0f};
	glm::vec4 P3 = P2 * 10.0f;

	// Vetor de inteiros
	glm::ivec2 Point3{ 1, 2 };

	// Passando valores apra um vetor a aprtir de outro vetor
	// Necessita usar o #define GLM_SWIZZLE
	glm::vec3 P = P1.rgb;

	cout << to_string(Point3) << endl;
	cout << "Tamanho do vetor: " << P0.length() << endl;

	// Normalizar um vetor
	glm::vec4 Norm = glm::normalize(P2);
	cout << to_string(P3) << endl;

	// Produto escalar
	float a = glm::dot(P, P1);
	cout << to_string(a) << endl;

	// Produto vetorial
	glm::vec3 b = { 1, 2, 0};
	glm::vec3 c = { 3, 4, 0};
	cout << to_string(b) << endl;
	cout << to_string(c) << endl;
	cout << to_string(glm::cross(b, c)) << endl;

	// Distancia
	float dist = glm::distance(b, c);
	cout << "Distancia: " << dist << endl;

	// Refração
	cout << to_string(glm::refract(P2, Norm, 1.0f)) << endl;

	// Reflexão
	cout << to_string(glm::reflect(P2, Norm)) << endl;

}


int main()
{

	Construtors();
	return 0;
}