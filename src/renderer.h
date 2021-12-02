#pragma once

#include <GL/glew.h>
#include "vertexArray.h"
#include "indexBuffer.h"
#include "shader.h"
#include "debug.h"

class Renderer {
public:
    void Clear() const;
    void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};