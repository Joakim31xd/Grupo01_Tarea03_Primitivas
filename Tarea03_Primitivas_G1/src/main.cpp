//============================================================================
// Name        : Tarea03_Primitivas
// Professor   : Herminio Paucar
// Version     :
// Description : Utilizamos los Vertex y Fragment Shaders
//============================================================================

// Include standard headers
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

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
GLuint m_VAO[3];

// Vertex buffer object (VBO)
GLuint m_VBO[3];

// color buffer object (CBO)
GLuint m_CBO[3];

GLuint m_EBO[3];
// GLSL program from the shaders
GLuint programID;




GLint WindowWidth = 600;
GLint WindowHeight = 600;

//--------------------------------------------------------------------------------
void transferDataToGPUMemory(void){
    // VAO n°1
    glGenVertexArrays(1, &m_VAO[0]);
    glBindVertexArray(m_VAO[0]);
   /* //VBO n°2
    glGenVertexArrays(1, &m_VAO[1]);
    glBindVertexArray(m_VAO[1]);*/

    // Create and compile our GLSL program from the shaders
    programID = Utils::createShaderProgram("src/vertShader.glsl", "src/fragShader.glsl");
    /*
    //vertices VAO n°2
    static const GLfloat g_vertex_buffer_data_1[]={0.0f,  0.0f, 0.0f,40.0f,  0.0f, 0.0f,0.0f,  40.0f, 0.0f};
    //colores VAO n°2
    static const GLfloat g_color_buffer_data_1[]={1.0f,1.0f, 1.0f,1.0f,1.0f, 1.0f,1.0f,1.0f, 1.0f};*/

    glGenBuffers(1, &m_VBO[0]);
    GLfloat* m_Vertices = new GLfloat[315]{
        -36.0f,  0.0f,  86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		-18.0f,  0.0f,  86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		-18.0f, -18.0f, 86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		-36.0f, -18.0f, 86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		-32.0f, -3.0f, 0.0f, 0.0f,  0.0f,
		-30.0f, -3.0f, 0.0f, 0.0f,  0.0f,
		-30.0f, -6.0f,  0.0f, 0.0f,  0.0f,
		-32.0f, -6.0f, 0.0f, 0.0f,  0.0f,
		-18.0f, 22.0f, 141.0f/255.0f,  169.0f/255.0f,  95.0f/255.0f,
		26.0f, 22.0f, 141.0f/255.0f,  169.0f/255.0f,  95.0f/255.0f,
		26.0f, -18.0f, 141.0f/255.0f,  169.0f/255.0f,  95.0f/255.0f,
		 -18.0f, -18.0f, 141.0f/255.0f,  169.0f/255.0f,  95.0f/255.0f,
		 -16.0f, -18.0f, 86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,//
		-10.0f, -18.0f, 86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		-10.0f, -25.0f, 86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		-16.0f, -25.0f,86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		-10.0f, -18.0f,86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		0.0f, -18.0f,86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		0.0f, -27.0f,86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		-10.0f, -27.0f, 86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		10.0f, -18.0f, 86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		16.0f, -18.0f,86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		16.0f, -25.0f,86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		10.0f, -25.0f,86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		16.0f, -18.0f,86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		26.0f, -18.0f,86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		26.0f, -27.0f,86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		16.0f, -27.0f,86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		-13.0f, 21.0f,65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		 -2.0f, 21.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		 -2.0f, 13.0f,65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
	     -13.0f, 13.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
	 	   7.0f, 21.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		   15.0f, 21.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		   15.0f, 15.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		   7.0f, 15.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		  -17.0f, 6.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		  -11.0f, 6.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		  -11.0f, -6.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		  -17.0f, -6.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		  -4.0f, 8.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		  7.0f, 8.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		  7.0f, -2.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		  -4.0f, -2.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		   13.0f, 9.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		   25.0f, 9.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		   25.0f, -3.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		   13.0f, -3.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		   -7.0f, -9.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		   4.0f, -9.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		   4.0f, -16.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		   -7.0f, -16.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		   11.0f, -8.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		   19.0f, -8.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		   19.0f, -16.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		   11.0f, -16.0f, 65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		   -36.0f, -15.0f, 0.0f, 0.0f,  0.0f,
		   -26.0f, -15.0f, 0.0f, 0.0f,  0.0f,
		   -26.0f, -15.5f, 0.0f, 0.0f,  0.0f,
		   -36.0f, -15.5f, 0.0f, 0.0f,  0.0f,
		   26.0f, -18.0f,86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		   26.0f, -11.0f,86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
	       36.0f, -18.0f,86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f
    };

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO[0]);
    	// Reserva memoria na GPU para um TARGET receber dados
    	// Copia esses dados pra essa área de memoria
    	glBufferData(
    			GL_ARRAY_BUFFER,	// TARGET associado ao nosso buffer
				315 * sizeof(GLfloat),	// tamanho do buffer
    			m_Vertices,			// Dados a serem copiados pra GPU
    			GL_STATIC_DRAW);		// Política de acesso aos dados, para otimização

        glGenBuffers(1, &m_EBO[0]);
        GLuint elements[] = {//2 triangulos por cada cuadrado
			2, 3, 0,0, 1, 2,
			6,7,4,4,5,6,
			10,11,8,8,9,10,
			14,15,12,12,13,14,
			18,19,16,16,17,18,
			22,23,20,20,21,22,
			26,27,24,24,25,26,
			30,31,28,28,29,30,
			34,35,32,32,33,34,
			38,39,36,36,37,38,
			42,43,40,40,41,42,
			46,47,44,44,45,46,
			50,51,48,48,49,50,
			54,55,52,52,53,54,
			58,59,56,56,57,58,
			60,61,62//triangulito
        };
    	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO[0]);
    	glBufferData(
    			GL_ELEMENT_ARRAY_BUFFER,
    			sizeof(elements),
    			elements,
    			GL_STATIC_DRAW);

    	// Specify the layout of the vertex data
		GLint posAttrib = glGetAttribLocation(programID, "vertexPosition");
		glEnableVertexAttribArray(posAttrib);
		glVertexAttribPointer(
				posAttrib,
				2,
				GL_FLOAT,
				GL_FALSE,
				5 * sizeof(GLfloat),
				0);

		GLint colAttrib = glGetAttribLocation(programID, "vertexColor");
		glEnableVertexAttribArray(colAttrib);
		glVertexAttribPointer(
				colAttrib,
				3,
				GL_FLOAT,
				GL_FALSE,
				5 * sizeof(GLfloat),
				(void*) (2 * sizeof(GLfloat)));
}


//--------------------------------------------------------------------------------

void cleanupDataFromGPU(){
    glDeleteBuffers(1, &m_VBO[0]);
    glDeleteBuffers(1, &m_CBO[0]);
    glDeleteVertexArrays(1, &m_VAO[0]);

    glDeleteBuffers(1, &m_VBO[1]);
    glDeleteBuffers(1, &m_CBO[1]);
    glDeleteVertexArrays(1, &m_VAO[1]);

    glDeleteProgram(programID);
}

//--------------------------------------------------------------------------------

void draw(void){
	glUseProgram(programID);
	glm::mat4 mvp = glm::ortho(-40.0f, 40.0f, -40.0f, 40.0f);
	GLuint matrix = glGetUniformLocation(programID, "mvp");
	glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);
	glDrawElements(GL_TRIANGLES, 100, GL_UNSIGNED_INT, 0);
}
//--------------------------------------------------------------------------------



int main( void )
{
    // Initialise GLFW
    glfwInit();

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window
    window = glfwCreateWindow( 600, 600, "Tarea 03: Primitivas", NULL, NULL);

    // Create window context
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    glewInit();

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    // transfer my data (vertices, colors, and shaders) to GPU side
    transferDataToGPUMemory();

    GLuint FramebufferName = 0;
    glGenFramebuffers(1, &FramebufferName);
    //glBindFramebuffer(GL_FRAMEBUFFER, FramebufferName);

    // render scene for each frame
    do{
        // White background
        glClearColor(0.1f, 0.0f, 0.1f, 0.0f);

        // Clear the screen
        glClear( GL_COLOR_BUFFER_BIT );


        /*
         * ESTE ES EL III Cuadrante, aquí va la Figura A:
         *
         * */
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glViewport(0, 0, WindowWidth*0.5, WindowHeight*0.5);
        draw();


        /*
         *
         * ESTE ES EL IV Cuadrante, aquí va la Figura B:
         *
         * */
        //right bottom
        glViewport(WindowWidth*0.5, 0, WindowWidth*0.5, WindowHeight*0.5);
        //draw();

        /*
         *
         * ESTE ES EL II Cuadrante, aquí va la figura del ratón
         *
         * */
        //left top
        glViewport(0, WindowHeight*0.5, WindowWidth*0.5, WindowHeight*0.5);
        //draw();


        /*
         *
         *
         * ESTE ES EL I Cuadrante, aquí va la figura de la carita feliz :)
         *
         * */
        //right top
        glViewport(WindowWidth*0.5, WindowHeight*0.5, WindowWidth*0.5, WindowHeight*0.5);
        //draw();

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

