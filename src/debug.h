#include <cassert>

#ifdef NDEBUG
#define assert(x) if (!(x)) __debugbreak();
#endif

#define GLCall(x) GLClearError();\
    x;\
    assert(GLLogCall(#x, __FILE__, __LINE__))


void GLClearError();

bool GLLogCall(const char* function, const char* file, int line);