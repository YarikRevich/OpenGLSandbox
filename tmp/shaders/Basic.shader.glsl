
#shader fragment
#version 410 core

in vec4 TexCoord;
        
out vec4 color;
        
layout (std140) uniform BlobSettings {
    vec4 InnerColor;
    vec4 OuterColor;
    float InnerRadius;
    float OuterRadius;
};

void main(){
    float dx = TexCoord.x;
    float dy = TexCoord.y;
    float dist = sqrt(dx * dx + dy * dy);

    color = vec4(mix(InnerColor, OuterColor, smoothstep(InnerRadius, OuterRadius, dist)));
}

#shader vertex
#version 410 core
    
layout(location = 0) in vec4 VertexPosition;
layout(location = 1) in vec4 VertexTexCoord;

out vec4 TexCoord;
    
uniform mat4 RotationMatrix;

void main(){
    TexCoord = VertexTexCoord;
    gl_Position = RotationMatrix * VertexPosition;
}