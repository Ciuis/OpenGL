#include <iostream>
#include "renderer.h"

/* убираем все ранее найденные ошибки */
void GLClearError() {
    while (glGetError() != GL_NO_ERROR);
}

/* вывод текста ошибки */
bool GLLogCall(const char* function, const char* file, int line) {
    while (GLenum error = glGetError()) {
        std::cout << "[OpenGL Error] (" << error << ") at function: "
        << function << " at line: " << line << std::endl;
        return false;
    }

    return true;
}