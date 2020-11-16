//============================================================================
// Name        : Tarea03_Primitivas Grupo 01
// Professor   : Herminio Paucar
// Alumnos     : Néstor Sánchez, Juan Diego Córdova, Rosinaldo Rivera
// Description : Utilizamos los Vertex y Fragment Shaders
//============================================================================

// Include standard headers

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifndef MPI
#define M_PI 3.14159265358979323846
#endif

// Include GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include "Utils.h"

// GLM header file
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

GLFWwindow* window;

using namespace glm;
using namespace std;

// Vertex array object (VAO)
GLuint m_VAO[4];

// Vertex buffer object (VBO)
GLuint *m_VBO;

// color buffer object (CBO)
GLuint *m_CBO;

// GLSL program from the shaders
GLuint programID;

GLuint VAO_Puntero=0;
GLuint VBO_Puntero=0;
GLuint CBO_Puntero=0;

GLint numeroVertices;

GLint WindowWidth = 600;
GLint WindowHeight = 600;
//---------------------------------------------------------------------------------------------------
void GenerarCirculo(GLfloat Radio, GLfloat x, GLfloat y, GLfloat z,GLfloat R, GLfloat G , GLfloat B){

		GLfloat radius = Radio;
		GLint numeroLados = 100;
		numeroVertices = numeroLados+2;
		GLfloat twicePi = 2.0f * M_PI;

		GLfloat verticesX[numeroVertices];
		GLfloat verticesY[numeroVertices];
		GLfloat verticesZ[numeroVertices];

		verticesX[0] = x;
		verticesY[0] = y;
		verticesZ[0] = z;
		for (int i = 0; i < numeroVertices; i++) {
			verticesX[i] = x + (radius * cos(i * twicePi / numeroLados));
			verticesY[i] = y + (radius * sin(i * twicePi / numeroLados));
			verticesZ[i] = z;
		}
		GLint dimVertices = (numeroVertices) * 3;
		GLfloat m_Vertices[dimVertices];
		GLfloat m_Colores[dimVertices];


		for (int i = 0; i < numeroVertices; i++) {
			m_Vertices[i * 3] = verticesX[i];
			m_Vertices[i * 3 + 1] = verticesY[i];
			m_Vertices[i * 3 + 2] = verticesZ[i];
			m_Colores[i * 3] = R;
			m_Colores[i * 3 + 1] = G;
			m_Colores[i * 3 + 2] = B;
		}

		glBindBuffer(GL_ARRAY_BUFFER, m_VBO[VBO_Puntero]);
		glBufferData(
		    GL_ARRAY_BUFFER,
		    sizeof(m_Vertices),
			m_Vertices,
		    GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, m_CBO[CBO_Puntero]);
			glBufferData(
			GL_ARRAY_BUFFER,
			sizeof(m_Colores),
			m_Colores,
			GL_STATIC_DRAW);

}

void GenerarSemiCirculo(GLfloat Radio, GLfloat x, GLfloat y, GLfloat z,GLuint A,GLfloat R, GLfloat G , GLfloat B){

		GLfloat radius = Radio;
		GLint numeroLados = 100;
		numeroVertices = numeroLados/2;
		GLfloat twicePi = 2.0f * M_PI;
		GLfloat verticesX[numeroVertices];
		GLfloat verticesY[numeroVertices];
		GLfloat verticesZ[numeroVertices];

		verticesX[0] = (radius * cos(A * twicePi / 360));
		verticesY[0] = (radius * sin(A * twicePi/ 360));
		verticesZ[0] = z;
		int aux=numeroLados*A/360;

		for (int i=aux-1; i <aux+numeroVertices; i++) {
			verticesX[i-(aux)] = x + (radius * cos(i * twicePi / numeroLados));
			verticesY[i-(aux)] = y + (radius * sin(i * twicePi / numeroLados));
			verticesZ[i-(aux)] = z;
		}

		GLint dimVertices = ((numeroVertices)) * 3;
		GLfloat m_Vertices[dimVertices];
		GLfloat m_Colores[dimVertices];

		for (int i = 0; i < numeroVertices; i++) {
			m_Vertices[i * 3] = verticesX[i];
			m_Vertices[i * 3 + 1] = verticesY[i];
			m_Vertices[i * 3 + 2] = verticesZ[i];
			m_Colores[i * 3] = R;
			m_Colores[i * 3 + 1] = G;
			m_Colores[i * 3 + 2] = B;
		}

		glBindBuffer(GL_ARRAY_BUFFER, m_VBO[VBO_Puntero]);
		glBufferData(
		    GL_ARRAY_BUFFER,
		    sizeof(m_Vertices),
			m_Vertices,
		    GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, m_CBO[CBO_Puntero]);
			glBufferData(
			GL_ARRAY_BUFFER,
			sizeof(m_Colores),
			m_Colores,
			GL_STATIC_DRAW);
}

//--------------------------------------------------------------------------------
void GenerarRectangulo(GLfloat Altura, GLfloat Base, GLfloat x, GLfloat y, GLfloat z,GLfloat R, GLfloat G , GLfloat B){
	GLfloat m_Vertices[18]={
		x, y, z,
		x, y+Altura, z,
		x+Base, y, z,
		x+Base, y, z,
		x+Base, y+Altura, z,
		x, y+Altura, z,
	};
	numeroVertices=6;
	GLfloat m_Colores[18]={
		R,G,B,
		R,G,B,
		R,G,B,
		R,G,B,
		R,G,B,
		R,G,B,
	};

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO[VBO_Puntero]);
	glBufferData(
		GL_ARRAY_BUFFER,
		sizeof(m_Vertices),
		m_Vertices,
		GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, m_CBO[CBO_Puntero]);
	glBufferData(
		GL_ARRAY_BUFFER,
		sizeof(m_Colores),
		m_Colores,
		GL_STATIC_DRAW);
}

//--------------------------------------------------------------------------------
void GenerarTriangulo(GLfloat Altura, GLfloat Base, GLfloat x, GLfloat y, GLfloat z,GLfloat R, GLfloat G , GLfloat B){
	GLfloat m_Vertices[9]={
		x, y, z,
		x, y+Altura, z,
		x+Base, y, z,
	};
	numeroVertices=3;
	GLfloat m_Colores[9]={
		R,G,B,
		R,G,B,
		R,G,B,
	};

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO[VBO_Puntero]);
	glBufferData(
		GL_ARRAY_BUFFER,
		sizeof(m_Vertices),
		m_Vertices,
		GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, m_CBO[CBO_Puntero]);
	glBufferData(
		GL_ARRAY_BUFFER,
		sizeof(m_Colores),
		m_Colores,
		GL_STATIC_DRAW);

}

//--------------------------------------------------------------------------------
void draw (int Mode_Type){
    // Use our shader
    glUseProgram(programID);

    glm::mat4 mvp = glm::ortho(-40.0f, 40.0f, -40.0f, 40.0f);

    // retrieve the matrix uniform locations
    GLuint matrix = glGetUniformLocation(programID, "mvp");
    glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO[VBO_Puntero]);
    glVertexAttribPointer(
                          0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                          3,                  // size
                          GL_FLOAT,           // type
                          GL_FALSE,           // normalized?
                          0,                  // stride
                          (void*)0            // array buffer offset
                          );

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, m_CBO[CBO_Puntero]);
    glVertexAttribPointer(
                          1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
                          3,                                // size
                          GL_FLOAT,                         // type
                          GL_FALSE,                         // normalized?
                          0,                                // stride
                          (void*)0                          // array buffer offset
                          );
    GLenum mode[7] = {GL_POINTS, GL_LINES, GL_LINE_STRIP, GL_LINE_LOOP,GL_TRIANGLES, GL_TRIANGLE_FAN, GL_TRIANGLE_STRIP };
    glDrawArrays(mode[Mode_Type], 0, numeroVertices);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}
void ReiniciarPuntero(){
	VBO_Puntero=0;
	CBO_Puntero=0;
}
void SumarPosicionPuntero(){
	VBO_Puntero++;
	CBO_Puntero++;
}

//--------------------------------------------------------------------------------
void DibujoICuadrante(){
	m_VBO= new GLuint[6];
	m_CBO= new GLuint[6];
	glBindVertexArray(m_VAO[0]);
	glGenBuffers(6, m_VBO);
	glGenBuffers(6, m_CBO);
	GenerarCirculo(20.0, 0.0f,0.0f,0.0f,255.0f/255.0f,229.0f/255.0f,37.0f/255.0f);
	draw(5);
	GenerarCirculo(20.0, 0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
	draw(3);
	SumarPosicionPuntero();
	GenerarCirculo(3.0, 5.0f,5.0f,0.0f,1.0f,1.0f,1.0f);
	draw(5);
	GenerarCirculo(3.0, 5.0f,5.0f,0.0f,0.0f,0.0f,0.0f);
	draw(3);
	SumarPosicionPuntero();
	GenerarCirculo(3.0, -5.0f,5.0f,0.0f,1.0f,1.0f,1.0f);
	draw(5);
	GenerarCirculo(3.0, -5.0f,5.0f,0.0f,0.0f,0.0f,0.0f);
	draw(3);
	SumarPosicionPuntero();
	GenerarCirculo(1.5, 5.0f,5.0f,0.0f,0.0f,0.0f,0.0f);
	draw(5);
	SumarPosicionPuntero();
	GenerarCirculo(1.5, -5.0f,5.0f,0.0f,0.0f,0.0f,0.0f);
	draw(5);
	SumarPosicionPuntero();
	GenerarSemiCirculo(10.0, 0.0f,-2.0f,0.0f,180,0.0f,0.0f,0.0f);
	draw(2);
	ReiniciarPuntero();
}
//--------------------------------------------------------------------------------
void DibujoIICuadrante(){
	m_VBO= new GLuint[10];
	m_CBO= new GLuint[10];
	glBindVertexArray(m_VAO[1]);
	glGenBuffers(10, m_VBO);
	glGenBuffers(10, m_CBO);

	GenerarCirculo(11.02, -12.11f,18.98f,0.0f,0.66f,0.66f,0.66f);
	draw(5);
	GenerarCirculo(11.02, -12.11f,18.98f,0.0f,0.0f,0.0f,0.0f);
	draw(3);
	SumarPosicionPuntero();
	GenerarCirculo(3.85, -22.41,29.57f,0.0f,0.66f,0.66f,0.66f);
	draw(5);
	GenerarCirculo(3.85, -22.41,29.57f,0.0f,0.0f,0.0f,0.0f);
	draw(3);
	SumarPosicionPuntero();
	GenerarCirculo(3.85, -1.61f,29.23f,0.0f,0.66f,0.66f,0.66f);
	draw(5);
	GenerarCirculo(3.85,-1.61f,29.23f,0.0f,0.0f,0.0f,0.0f);
	draw(3);
	SumarPosicionPuntero();
	GenerarSemiCirculo(14.0f, 2.14f,-21.42f,0.0f,215.0f ,0.0f,0.0f,0.0f);
	draw(2);
	SumarPosicionPuntero();
	GenerarCirculo(18.39, -11.61f,-10.47f,0.0f,0.66f,0.66f,0.66f);
	draw(5);
	GenerarCirculo(18.39, -11.61f,-10.47f,0.0f,0.0f,0.0f,0.0f);
	draw(3);
	SumarPosicionPuntero();
	GenerarCirculo(3.0, -17.0f, 22.0f,0.0f,1.0f,1.0f,1.0f);
	draw(5);
	GenerarCirculo(3.0, -17.0f, 22.0f,0.0f,0.0f,0.0f,0.0f);
	draw(3);
	SumarPosicionPuntero();
	GenerarCirculo(1.5, -17.0f, 22.0f,0.0f,0.0f,0.0f,0.0f);
	draw(5);
	SumarPosicionPuntero();
	GenerarCirculo(3.0, -8.0f, 22.0f,0.0f,1.0f,1.0f,1.0f);
	draw(5);
	GenerarCirculo(3.0, -8.0f, 22.0f,0.0f,0.0f,0.0f,0.0f);
	draw(3);
	SumarPosicionPuntero();
	GenerarCirculo(1.5, -8.0f, 22.0f,0.0f,0.0f,0.0f,0.0f);
	draw(5);
	SumarPosicionPuntero();
	GenerarSemiCirculo(3.00f, -12.71f, 16.54f,0.0f,215.0f, 1.0f,1.0f,1.0f);
	draw(5);


	ReiniciarPuntero();
}
//--------------------------------------------------------------------------------
void DibujoIIICuadrante(){
	m_VBO= new GLuint[16];
	m_CBO= new GLuint[16];
	glBindVertexArray(m_VAO[2]);
	glGenBuffers(16, m_VBO);
	glGenBuffers(16, m_CBO);
	GenerarRectangulo(18.0f,18.0f,-36.0f,-18.0f, 0.0f, 86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f);
	draw(4);
	SumarPosicionPuntero();
	GenerarRectangulo(3.0f,2.0f,-32.0f, -6.0f, 0.0f, 0.0f,  0.0f,0.0f);
	draw(4);
	SumarPosicionPuntero();
	GenerarRectangulo(40.0f,44.0f,-18.0f, -18.0f, 0.0f, 141.0f/255.0f,  169.0f/255.0f,  95.0f/255.0f);
	draw(4);
	SumarPosicionPuntero();
	GenerarRectangulo(7.0f,6.0f,-16.0f, -25.0f, 0.0f, 67.0f/255.0f,  130.0f/255.0f,  65.0f/255.0f);
	draw(4);
	SumarPosicionPuntero();
	GenerarRectangulo(9.0f, 10.0f, -10.0f, -27.0f, 0.0f, 86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f);
	draw(4);
	SumarPosicionPuntero();
	GenerarRectangulo(7.0f,6.0f, 10.0f, -25.0f, 0.0f, 67.0f/255.0f,  130.0f/255.0f,  65.0f/255.0f);
	draw(4);
	SumarPosicionPuntero();
	GenerarRectangulo(9.0f, 10.0f, 16.0f, -27.0f, 0.0f, 86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f);
	draw(4);
	SumarPosicionPuntero();
	GenerarRectangulo(8.0f, 11.0f, -13.0f, 13.0f, 0.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f);
	draw(4);
	SumarPosicionPuntero();
	GenerarRectangulo(6.0f, 8.0f, 7.0f, 15.0f, 0.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f);
	draw(4);
	SumarPosicionPuntero();
	GenerarRectangulo(12.0f, 8.0f, -17.0f, -6.0f, 0.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f);
	draw(4);
	SumarPosicionPuntero();
	GenerarRectangulo(10.0f, 11.0f, -4.0f, -2.0f, 0.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f);
	draw(4);
	SumarPosicionPuntero();
	GenerarRectangulo(12.0f, 12.0f, 13.0f, -3.0f, 0.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f);
	draw(4);
	SumarPosicionPuntero();
	GenerarRectangulo(7.0f, 11.0f, -7.0f, -16.0f, 0.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f);
	draw(4);
	SumarPosicionPuntero();
	GenerarRectangulo(8.0f, 8.0f, 11.0f, -16.0f, 0.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f);
	draw(4);
	SumarPosicionPuntero();
	GenerarRectangulo(0.5f, 10.f, -36.0f, -15.5f, 0.0f, 0.0f, 0.0f,  0.0f);
	draw(4);
	SumarPosicionPuntero();
	GenerarTriangulo(7.0f, 10.0f, 26.0f, -18.0f, 0.0f, 86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f);
	draw(4);
	ReiniciarPuntero();
}
//--------------------------------------------------------------------------------
void DibujoIVCuadrante(){
	//carrito
	m_VBO= new GLuint[9];
	m_CBO= new GLuint[9];
	glBindVertexArray(m_VAO[3]);
	glGenBuffers(9, m_VBO);
	glGenBuffers(9, m_CBO);

	//parte superior carro
	GenerarRectangulo(20.0,30.0, 0.0f,10.0f,0.0f,0.0f,0.0f,1.0f); //genera la parte superior de color rojo
	draw(4);

	//cuerpo carro
	GenerarRectangulo(30.0,60.0, -30.0f,-20.0f,0.0f,0.0f,0.0f,1.0f); //generar cuerpo carro rojo
	draw(4);
	SumarPosicionPuntero();

	//adorno delantero
	GenerarRectangulo(2.0, 6.0, -30.0f,10.0f,0.0f,1.0f,0.0f,0.0f); //generar adorno rojo
	draw(4);
	SumarPosicionPuntero();

	//adorno superior
	GenerarRectangulo(2.0,30.0, 0.0f,30.0f,0.0f,1.0f,0.0f,0.0f); //generar adorno superior rojo
	draw(4);
	SumarPosicionPuntero();

	//ventana carro
	GenerarRectangulo(12.0,14.0, 8.0f,14.0f,0.0f,1.0f,1.0f,1.0f); //generar ventana blanca
	draw(4);
	SumarPosicionPuntero();

	//llanta delantera
	GenerarCirculo(10.0, -20.0f,-30.0f,0.0f,0.0f,0.0f,0.0f); //genera llanta delantera color negro
	draw(5);
	SumarPosicionPuntero();

	//llanta trasera
	GenerarCirculo(10.0, 20.0f,-30.0f,0.0f,0.0f,0.0f,0.0f); //genera llanta trasera color negro
	draw(5);
	SumarPosicionPuntero();

	//tubo escape
	GenerarRectangulo(4.0,6.0, 30.0f,-20.0f,0.0f,0.68f,0.68f,0.68f); //generar T.escape plomo
	draw(4);
	SumarPosicionPuntero();

	//manija
	GenerarRectangulo(1.5,6.0, 0.0f,0.0f,0.0f,0.0f,0.0f,0.0f); //generar manija negra
	draw(4);
	SumarPosicionPuntero();
	ReiniciarPuntero();
}

//--------------------------------------------------------------------------------
void transferDataToGPUMemory(int i){
	programID = Utils::createShaderProgram("src/vertShader.glsl", "src/fragShader.glsl");
	glGenVertexArrays(4, m_VAO);
	switch(i){
		case 1:
			DibujoICuadrante();
			break;
		case 2:
			DibujoIICuadrante();
			break;
		case 3:
			DibujoIIICuadrante();
			break;
		case 4:
			DibujoIVCuadrante();
			break;
	}
}

//--------------------------------------------------------------------------------

void cleanupDataFromGPU(){
	glDeleteBuffers(1, m_VBO);
	glDeleteBuffers(1, m_CBO);
	glDeleteVertexArrays(1, m_VAO);
	glDeleteProgram(programID);
}

//--------------------------------------------------------------------------------
int main( void )
{
    // Inicializar GLFW
    glfwInit();

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Abrir una ventana
    window = glfwCreateWindow( 600, 600, "Tarea 03: Primitivas", NULL, NULL);

    // Crear un contexto de Windows
    glfwMakeContextCurrent(window);

    // Inicializar GLEW
    glewExperimental = true; // Needed for core profile
    glewInit();

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    GLuint FramebufferName = 0;
    glGenFramebuffers(1, &FramebufferName);
    //glBindFramebuffer(GL_FRAMEBUFFER, FramebufferName);

    // render scene for each frame
    do{
        // White background
        glClearColor(253.0f/255.0f, 255.0f/255.0f, 137.0f/255.0f, 0.46f);

        // Clear the screen
        glClear( GL_COLOR_BUFFER_BIT );
        glBindFramebuffer(GL_FRAMEBUFFER, 0);

        // ESTE ES EL III Cuadrante, aquí va la Figura A:
        glViewport(0, 0, WindowWidth*0.5, WindowHeight*0.5);
        transferDataToGPUMemory(3);

        //ESTE ES EL IV Cuadrante, aquí va la Figura B:
        glViewport(WindowWidth*0.5, 0, WindowWidth*0.5, WindowHeight*0.5);
        transferDataToGPUMemory(4);

        //ESTE ES EL II Cuadrante, aquí va la figura del ratón
        glViewport(0, WindowHeight*0.5, WindowWidth*0.5, WindowHeight*0.5);
        transferDataToGPUMemory(2);

        //ESTE ES EL I Cuadrante, aquí va la figura de la carita feliz :)
        glViewport(WindowWidth*0.5, WindowHeight*0.5, WindowWidth*0.5, WindowHeight*0.5);
        transferDataToGPUMemory(1);

        // Swap buffers
        glfwSwapBuffers(window);
        // looking for events
        glfwPollEvents();

    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
          glfwWindowShouldClose(window) == 0 );

    // delete framebuffer
    glDeleteFramebuffers(1, &FramebufferName);

    // Cleanup VAO, VBOs, and shaders from GPU
    cleanupDataFromGPU();

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}

