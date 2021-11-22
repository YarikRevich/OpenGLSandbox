#pragma once

#include <functional>
#include <iostream>
#include "glad/glad.h"
#include <stdlib.h>
#include <string>

namespace OpenGL
{
    class ErrorCatcher
    {

    public:
        ErrorCatcher(unsigned int program, std::string error_message, std::function<void()> error_callback);

    protected:
        unsigned int m_Program;
        std::function<void()> m_Error_Callback;
        std::string m_Error_Message;
    };

    class ShaderErrorCatcher : public ErrorCatcher
    {

    public:
        ShaderErrorCatcher(unsigned int program, std::string error_message, std::function<void()> error_callback);
        void Catch();
    };
};