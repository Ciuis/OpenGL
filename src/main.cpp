#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <sstream>

#include "renderer.h"
#include "vertexBuffer.h"
#include "indexBuffer.h"
#include "vertexArray.h"
#include "shader.h"

int main() {

    GLFWwindow *window;

    if (!glfwInit()) {
        std::cout << "GLFW not found" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(800, 600, "OpenGL test window", NULL, NULL);

    if (!window) {
        std::cout << "Window create failed" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    GLClearError();

    glewExperimental = true;
    if (glewInit() != GLEW_OK) {
        std::cout << "GLEW initialisation error" << std::endl;
    }

    {
        float positions[] = {
                -0.5f, -0.5f, // 0
                0.5f, -0.5f,  // 1
                0.5f, 0.5f,  // 2
                -0.5f, 0.5f, // 3

        };

        unsigned int indices[] = {
                0, 1, 2,
                2, 3, 0
        };

        VertexArray va;
        /* Vertex buffer creation */
        VertexBuffer vb(positions, 4 * 2 * sizeof(float));

        VertexBufferLayout layout;
        layout.Push<float>(2);
        va.AddBuffer(vb, layout);

        /* Index buffer creation */
        IndexBuffer ib(indices, 6);

        /* Перенесено в "shader.cpp"
        ShaderProgramSource source = ParseShader(
                "../res/shaders/basic.shader"); // быть внимательней с путями, неделю искал ошибку
                */

        Shader shader("../res/shaders/basic.shader");
        shader.Bind();
        shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

        va.Unbind();
        vb.Unbind();
        ib.Unbind();
        shader.Unbind();

        float r = 0.0f;
        float increment = 0.05f;

        /* main loop */
        while (!glfwWindowShouldClose(window)) {

            /* rendering starts here */
            GLCall(glClear(GL_COLOR_BUFFER_BIT));

            GLCall(shader.Bind());
            GLCall(shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f))

            va.Bind();
            ib.Bind();

            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

            if (r > 1.0f) {
                increment = -0.05f;
            } else if (r < 0.0f) {
                increment = 0.05f;
            }

            r += increment;

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    glfwTerminate();
    return 0;
}
