#pragma once

#include "stdio.h"

#ifdef DEBUG
#define GL(x)                                                                              \
    x;                                                                                     \
    {                                                                                      \
        int glError = glGetError();                                                        \
        if (glError != GL_NO_ERROR)                                                        \
        {                                                                                  \
            fprintf(stderr, "OpenGL Error: %d near '%s:%d'\n", glError, __FILE__, __LINE__); \
            exit(glError);                                                                 \
        }                                                                                  \
    }
#else
#define GL(x) x
#endif
