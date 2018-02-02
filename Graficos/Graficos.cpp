// Graficos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"

#include <iostream>
using namespace std;

GLfloat red, green, blue;
GLfloat angulo = 0.0f;

void actualizar()
{
	//Aqui esta bien para actualizar los valores
	//De la version del programa!
	if (angulo < 360)
	{
		angulo += 0.01;
	}
	else
	{
		angulo = 0.0;
	}
	
	/*red += 0.01;
	green += 0.02;
	blue += 0.03;

	if (red > 1) red = 0;
	if (green > 1) green = 0;
	if (blue > 1) blue = 0;*/

}

void dibujar()
{
	//triangulo1
	glPushMatrix();
	glTranslatef(0.0f, 0.2f, 0.0f);
	//glRotatef(angulo, 0.0f, 0.0f, 0.0f);//Afecta eje x
	glRotatef(angulo, 0.0f, 1.0f, 0.0f); //Aefecta eje y
	//glRotatef(angulo, 1.0f, 1.0f, 1.0f); //Aefcta eje z
	glScalef(0.2f, 0.2f, 0.2f);
	glBegin(GL_TRIANGLES); //Inicia la rutina con un modo de dibujo

	

	glColor3f(1.0f, 0.8f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);

	glColor3f(1.0f, 0.8f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glEnd(); // Finaliza la rutina
	glPopMatrix();

	//Triangulo2
	glPushMatrix();
	glTranslatef(-0.2f, 0.0f, 0.0f);
	//glRotatef(angulo, 1.0f, 0.0f, 0.0f);//Afecta eje x
	glRotatef(angulo, 0.0f, 1.0f, 0.0f); //Aefcta eje y
	//glRotatef(angulo, 0.0f, 0.0f, 1.0f); //Aefcta eje z
	glScalef(0.2f, 0.2f, 0.2f);
	glBegin(GL_TRIANGLES); //Inicia la rutina con un modo de dibujo



	glColor3f(1.0f, 0.8f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);

	glColor3f(1.0f, 0.8f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glEnd(); // Finaliza la rutina
	glPopMatrix();

	//triangulo3
	glPushMatrix();
	glTranslatef(0.2f, 0.0f, 0.0f);
	//glRotatef(angulo, 1.0f, 0.0f, 0.0f);//Afecta eje x
	glRotatef(angulo, 0.0f, 1.0f, 0.0f); //Afecta eje y
	//glRotatef(angulo, 0.0f, 0.0f, 1.0f); //Aefcta eje z
	glScalef(0.2f, 0.2f, 0.2f);
	glBegin(GL_TRIANGLES); //Inicia la rutina con un modo de dibujo



	glColor3f(1.0f, 0.8f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);

	glColor3f(1.0f, 0.8f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glEnd(); // Finaliza la rutina
	glPopMatrix();

}

int main()
{
	//Declaración de Ventana
	GLFWwindow *window;
	
	//Propiedades de la ventana
	GLfloat ancho = 1024;
	GLfloat alto = 768;

	//Inicialización de GLFW
	if (!glfwInit())
	{
		//Si no se inicia bien termina la ejecución
		exit(EXIT_FAILURE);
	}

	//Inicialización de la ventana
	window = glfwCreateWindow(ancho, alto, "Gráficos", NULL, NULL);

	//Verificación de creación de ventana
	if (!window)
	{
		//Cerrar todos los procesos de GLFW
		glfwTerminate();
		//Termina ejecución
		exit(EXIT_FAILURE);
	}


	//Establecer "windows" como contexto
	glfwMakeContextCurrent(window);

	//Se trae las funciones de OpenGL Moderno
	glewExperimental = true;

	//Inicializar GLEW
	GLenum glewError = glewInit();

	//Verificar si GLEW se inicializo bien
	if (glewError != GLEW_OK)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	const GLubyte *version = glGetString(GL_VERSION);
	cout << "Version de OpenGL:" << version << endl;

	red = green = blue = 0.0f;
	//Ciclo de Dibujo
	while (!glfwWindowShouldClose(window))
	{
		//Establecer el area de render (viewport)
		glViewport(0, 0, ancho, alto);
		//Establecer el color con el que se limpia
		glClearColor(red, green, blue, 1);

		

		
		//Limpiar pantalla
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de Dibujo
		actualizar();
		dibujar();

		//Intercambio de Buffers
		glfwSwapBuffers(window);
		//Buscar nueva señal de entrada
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
    return 0;
}

