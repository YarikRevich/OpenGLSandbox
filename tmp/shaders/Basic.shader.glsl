
#shader fragment
#version 410 core

in vec3 TexCoord;
        
layout(location = 0) out vec3 color;
        
// uniform BlobSettings {
//     vec4 InnerColor
//     vec4 OuterColor
//     float InnerRadius;
//     float OuterRadius;
// };

void main(){
    // float dx = TextCoord.x + 0.5;
    // float dy = TextCoord.x - 0.5;
    // float dist = sqrt(dx * dx + dy * dy)

    color = vec3(1.0, 1.0, 1.0);
    // color = mix(InnerColor, OuterColor, smoothstep(InnerRadius, OuterRadius, dist))
}

#shader vertex
#version 410 core
    
layout(location = 0) in vec4 position;
// layout(location = 1) in vec3

out vec3 TexCoord;
    
uniform mat4 RotationMatrix;

void main(){
// TexCoord = ;
   gl_Position = RotationMatrix * position;
}