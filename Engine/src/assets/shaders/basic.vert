#version 330 core
layout (location = 0) in vec4 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTexCoord;

uniform mat4 pr_matrix;
uniform mat4 vw_matrix = mat4(1.0);
uniform mat4 ml_matrix = mat4(1.0);

out DATA {
    vec4 pos;
    vec4 color;
    vec2 texCoord;
} vs_out;

void main() {
    gl_Position = pr_matrix * vw_matrix * ml_matrix * aPos;
    vs_out.color = aColor;
    vs_out.pos = ml_matrix * aPos;
    vs_out.texCoord = aTexCoord;
}
