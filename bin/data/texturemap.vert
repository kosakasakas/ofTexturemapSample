#version 410

uniform mat4 modelViewProjectionMatrix;

in vec4 position;
in vec2 texcoord;

out vec2 v_uv;

void main() 
{
    gl_Position = modelViewProjectionMatrix * position;
    v_uv = texcoord;
}
