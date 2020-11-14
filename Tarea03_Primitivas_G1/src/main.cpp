//============================================================================
// Name        : Tarea03_Primitivas
// Professor   : Herminio Paucar
// Version     :
// Description : Utilizamos los Vertex y Fragment Shaders
//============================================================================

// Include standard headers
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

// Vertex array object (VAO)
GLuint m_VAO[3];

// Vertex buffer object (VBO)
GLuint m_VBO[3];

// color buffer object (CBO)
GLuint m_CBO[3];

// GLSL program from the shaders
GLuint programID;


GLint WindowWidth = 600;
GLint WindowHeight = 600;

//--------------------------------------------------------------------------------
void transferDataToGPUMemory(void){
    // VAO n°1
    glGenVertexArrays(1, &m_VAO[0]);
    glBindVertexArray(m_VAO[0]);
    //VBO n°2
    glGenVertexArrays(1, &m_VAO[1]);
    glBindVertexArray(m_VAO[1]);

    // Create and compile our GLSL program from the shaders
    programID = Utils::createShaderProgram("src/vertShader.glsl", "src/fragShader.glsl");
    //vertices VAO n°2
    static const GLfloat g_vertex_buffer_data_1[]={0.0f,  0.0f, 0.0f,40.0f,  0.0f, 0.0f,0.0f,  40.0f, 0.0f};
    //colores VAO n°2
    static const GLfloat g_color_buffer_data_1[]={1.0f,1.0f, 1.0f,1.0f,1.0f, 1.0f,1.0f,1.0f, 1.0f};

    static const GLfloat g_vertex_buffer_data[] = {
        -36.0f, -18.0f,  0.0f,
        -18.0f,  0.0f,  0.0f,
        -36.0f,  0.0f, 0.0f,
		-36.0f, -18.0f,  0.0f,
        -18.0f, -18.0f, 0.0f,
		-18.0f,  0.0f,  0.0f,
        -32.0f, -6.0f, 0.0f,
        -30.0f, -3.0f, 0.0f,
        -32.0f, -3.0f, 0.0f,
        -32.0f, -6.0f, 0.0f,
		-30.0f, -6.0f,  0.0f,
		-30.0f, -3.0f, 0.0f,
		-18.0f, -18.0f, 0.0f,
		 26.0f, 22.0f, 0.0f,
		-18.0f, 22.0f, 0.0f,
		-18.0f, -18.0f, 0.0f,
		 26.0f, -18.0f, 0.0f,
		 26.0f, 22.0f, 0.0f,
		-16.0f, -25.0f, 0.0f,
		-10.0f, -18.0f, 0.0f,
		-16.0f, -18.0f, 0.0f,
		-16.0f, -25.0f, 0.0f,
		-10.0f, -25.0f, 0.0f,
		-10.0f, -18.0f, 0.0f,
		-10.0f, -27.0f, 0.0f,
		  0.0f, -18.0f, 0.0f,
		-10.0f, -18.0f, 0.0f,
		-10.0f, -27.0f, 0.0f,
		  0.0f, -27.0f, 0.0f,
		  0.0f, -18.0f, 0.0f,
		  //sumarle 26 al x ya que las patas de la tortuga son las mismas
		-16.0f+26.0f, -25.0f, 0.0f,
		-10.0f+26.0f, -18.0f, 0.0f,
		-16.0f+26.0f, -18.0f, 0.0f,
		-16.0f+26.0f, -25.0f, 0.0f,
		-10.0f+26.0f, -25.0f, 0.0f,
		-10.0f+26.0f, -18.0f, 0.0f,
		-10.0f+26.0f, -27.0f, 0.0f,
		  0.0f+26.0f, -18.0f, 0.0f,
		-10.0f+26.0f, -18.0f, 0.0f,
		-10.0f+26.0f, -27.0f, 0.0f,
		  0.0f+26.0f, -27.0f, 0.0f,
		  0.0f+26.0f, -18.0f, 0.0f,
		  //la cola
		  26.0f, -18.0f, 0.0f,
		  26.0f, -11.0f, 0.0f,
		  36.0f, -18.0f, 0.0f,
		  //cuadraditos del caparazon
		  -13.0f, 13.0f, 0.0f,
		  -2.0f, 21.0f, 0.0f,
		  -13.0f, 21.0f, 0.0f,
		  -13.0f, 13.0f, 0.0f,
		  -2.0f, 13.0f, 0.0f,
		  -2.0f, 21.0f, 0.0f,
		   7.0f, 15.0f, 0.0f,
		   15.0f, 21.0f, 0.0f,
		   7.0f, 21.0f, 0.0f,
		   7.0f, 15.0f, 0.0f,
		   15.0f, 15.0f, 0.0f,
		   15.0f, 21.0f, 0.0f,
		  -17.0f, -6.0f, 0.0f,
		  -11.0f, 6.0f, 0.0f,
		  -17.0f, 6.0f, 0.0f,
		  -17.0f, -6.0f, 0.0f,
		  -11.0f, -6.0f, 0.0f,
		  -11.0f, 6.0f, 0.0f,
		  -4.0f, -2.0f, 0.0f,
		   7.0f, 8.0f, 0.0f,
		  -4.0f, 8.0f, 0.0f,
		  -4.0f, -2.0f, 0.0f,
		   7.0f, -2.0f, 0.0f,
		   7.0f, 8.0f, 0.0f,
		   13.0f, -3.0f, 0.0f,
		   25.0f, 9.0f, 0.0f,
		   13.0f, 9.0f, 0.0f,
		   13.0f, -3.0f, 0.0f,
		   25.0f, -3.0f, 0.0f,
		   25.0f, 9.0f, 0.0f,
		   -7.0f, -16.0f, 0.0f,
		   4.0f, -9.0f, 0.0f,
		   -7.0f, -9.0f, 0.0f,
		   -7.0f, -16.0f, 0.0f,
		   4.0f, -16.0f, 0.0f,
		   4.0f, -9.0f, 0.0f,
		   11.0f, -16.0f, 0.0f,
		   19.0f, -8.0f, 0.0f,
		   11.0f, -8.0f, 0.0f,
		   11.0f, -16.0f, 0.0f,
		   19.0f, -16.0f, 0.0f,
		   19.0f, -8.0f, 0.0f,
		   //boca de la tortuga
		   -36.0f, -15.5f, 0.0f,
		   -26.0f, -15.0f, 0.0f,
		   -36.0f, -15.0f, 0.0f,
		   -36.0f, -15.5f, 0.0f,
		   -26.0f, -15.5f, 0.0f,
		   -26.0f, -15.0f, 0.0f,

    };

    // One color for each vertex. They were generated randomly.
    static const GLfloat g_color_buffer_data[] = {
        86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
		0.0f,  0.0f,  0.0f,
		0.0f,  0.0f,  0.0f,
		0.0f,  0.0f,  0.0f,
		141.0f/255.0f,  169.0f/255.0f,  95.0f/255.0f,
		141.0f/255.0f,  169.0f/255.0f,  95.0f/255.0f,
		141.0f/255.0f,  169.0f/255.0f,  95.0f/255.0f,
		141.0f/255.0f,  169.0f/255.0f,  95.0f/255.0f,
		141.0f/255.0f,  169.0f/255.0f,  95.0f/255.0f,
		141.0f/255.0f,  169.0f/255.0f,  95.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,//color de la cola
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		86.0f/255.0f,  166.0f/255.0f,  72.0f/255.0f,
		65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
				65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
				65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
				65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
				65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
				65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
				65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
				65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
				65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
				65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
				65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
				65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
				65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
				65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
				65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
				65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
				65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
				65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
				65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
		65.0f/255.0f,  79.0f/255.0f,  43.0f/255.0f,
				0.0f,  0.0f,  0.0f,
		        0.0f,  0.0f,  0.0f,
		        0.0f,  0.0f,  0.0f,
				0.0f,  0.0f,  0.0f,
				0.0f,  0.0f,  0.0f,
				0.0f,  0.0f,  0.0f,
    };

    // Move vertex data to video memory; specifically to VBO called m_VBO
    glGenBuffers(1, &m_VBO[0]);//m_VBO[0]
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO[0]);//m_VBO[0]
    glBufferData(
        GL_ARRAY_BUFFER,
        sizeof(g_vertex_buffer_data),//g_vertex_buffer_data
        g_vertex_buffer_data,//g_vertex_buffer_data
        GL_STATIC_DRAW);

    // Move color data to video memory; specifically to CBO called m_CBO
    glGenBuffers(1, &m_CBO[0]);
    glBindBuffer(GL_ARRAY_BUFFER, m_CBO[0]);
    glBufferData(
        GL_ARRAY_BUFFER,
        sizeof(g_color_buffer_data),
        g_color_buffer_data,
        GL_STATIC_DRAW);
    //PARA EL VBO N°2 Y CBO N°2
    glGenBuffers(1, &m_VBO[1]);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO[1]);
        glBufferData(
            GL_ARRAY_BUFFER,
            sizeof(g_vertex_buffer_data_1),
            g_vertex_buffer_data_1,
            GL_STATIC_DRAW);
        // Move color data to video memory; specifically to CBO called m_CBO
	glGenBuffers(1, &m_CBO[1]);
	glBindBuffer(GL_ARRAY_BUFFER, m_CBO[1]);
	glBufferData(
		GL_ARRAY_BUFFER,
		sizeof(g_color_buffer_data_1),
		g_color_buffer_data_1,
		GL_STATIC_DRAW);

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
void draw(void){
	glUseProgram(programID);
	glm::mat4 mvp = glm::ortho(-40.0f, 40.0f, -40.0f, 40.0f);
	GLuint matrix = glGetUniformLocation(programID, "mvp");
	    glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);
	    glEnableVertexAttribArray(0);
	        glBindBuffer(GL_ARRAY_BUFFER, m_VBO[1]);
	        glVertexAttribPointer(
	                              0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
	                              3,                  // size
	                              GL_FLOAT,           // type
	                              GL_FALSE,           // normalized?
	                              0,                  // stride
	                              (void*)0            // array buffer offset
	                              );

	        // 2nd attribute buffer : colors
	        glEnableVertexAttribArray(1);
	        glBindBuffer(GL_ARRAY_BUFFER, m_CBO[1]);
	        glVertexAttribPointer(
	                              1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
	                              3,                                // size
	                              GL_FLOAT,                         // type
	                              GL_FALSE,                         // normalized?
	                              0,                                // stride
	                              (void*)0                          // array buffer offset
	                              );


	        //glEnable(GL_PROGRAM_POINT_SIZE);
	        //glPointSize(10);
	        // Draw the triangle !
	        glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle
	        //glDrawArrays(GL_LINES, 0, 6); // 3 indices starting at 0 -> 1 triangle
	        glDisableVertexAttribArray(0);
	        glDisableVertexAttribArray(1);

}
//-----------DIBUJO DE LA TORTUGA---------------------
void drawTortuga (void){
    // Use our shader
    glUseProgram(programID);

    // create transformations
    //glm::mat4 model = glm::mat4(1.0f);
    //glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 mvp = glm::ortho(-40.0f, 40.0f, -40.0f, 40.0f);

    // Our ModelViewProjection : multiplication of our 3 matrices
    //glm::mat4 mvp = projection * view * model;
    // Remember, matrix multiplication is the other way around

    // retrieve the matrix uniform locations
    GLuint matrix = glGetUniformLocation(programID, "mvp");
    glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO[0]);
    glVertexAttribPointer(
                          0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                          3,                  // size
                          GL_FLOAT,           // type
                          GL_FALSE,           // normalized?
                          0,                  // stride
                          (void*)0            // array buffer offset
                          );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, m_CBO[0]);
    glVertexAttribPointer(
                          1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
                          3,                                // size
                          GL_FLOAT,                         // type
                          GL_FALSE,                         // normalized?
                          0,                                // stride
                          (void*)0                          // array buffer offset
                          );


    //glEnable(GL_PROGRAM_POINT_SIZE);
    //glPointSize(10);
    // Draw the triangle !
    glDrawArrays(GL_TRIANGLES, 0, 93); // 3 indices starting at 0 -> 1 triangle
    //glDrawArrays(GL_LINES, 0, 6); // 3 indices starting at 0 -> 1 triangle

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
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
        drawTortuga();


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
        draw();


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

