#pragma once

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <sstream>

#include <fstream>

namespace OpenGL
{
    class Loader
    {

    public:
        std::stringstream vertexShader;
        std::stringstream fragmentShader;

        Loader(std::string src);

        std::string GetVertexShader();
        std::string GetFragmentShader();
    };
};