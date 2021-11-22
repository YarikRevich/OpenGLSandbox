#include "error.hpp"

namespace OpenGL
{
    ErrorCatcher::ErrorCatcher(unsigned int program, std::string error_message, std::function<void()> error_callback) : m_Program(program), m_Error_Callback(error_callback), m_Error_Message(error_message){};

    ShaderErrorCatcher::ShaderErrorCatcher(unsigned int program, std::string error_message, std::function<void()> error_callback)
        : ErrorCatcher(program, error_message, error_callback)
    {
        this->Catch();
    };

    void ShaderErrorCatcher::Catch()
    {
        int result;
        glGetShaderiv(m_Program, GL_COMPILE_STATUS, &result);

        if (!result)
        {
            int length;
            glGetShaderiv(m_Program, GL_INFO_LOG_LENGTH, &length);
            std::cout << m_Error_Message << std::endl;

            if (length > 0)
            {
                char *message = (char *)alloca(length * sizeof(char));
                glGetShaderInfoLog(m_Program, length, &length, message);
                std::cout << message;
            }

            glDeleteShader(m_Program);
            m_Error_Callback();
            exit(1);
        }
    };
};