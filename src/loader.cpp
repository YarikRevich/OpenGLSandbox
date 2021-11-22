#include "loader.hpp"

namespace OpenGL
{
    Loader::Loader(std::string src)
    {
        std::ifstream stream(src);
        std::string line;

        enum class Type
        {
            None = -1,
            Vertex = 0,
            Fragment = 1
        };

        Type type = Type::None;
        while (std::getline(stream, line))
        {
            // std::cout << line;
            if (line.find("#shader") != std::string::npos)
            {
                if (line.find("vertex") != std::string::npos)
                {
                    type = Type::Vertex;
                    continue;
                }
                else if (line.find("fragment") != std::string::npos)
                {
                    type = Type::Fragment;
                    continue;
                };
            }

            if (type == Type::Fragment)
            {
                this->fragmentShader << line << "\n";
            }
            else if (type == Type::Vertex)
            {
                this->vertexShader << line << "\n";
            }
        };

        stream.close();
    };

    std::string Loader::GetVertexShader()
    {
        return vertexShader.str();
    }

    std::string Loader::GetFragmentShader()
    {
        return fragmentShader.str();
    }
};