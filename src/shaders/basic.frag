#version 330 core

out vec4 FragColor;

uniform vec4 colour;
uniform vec2 lightPos;

in DATA {
    vec4 pos;
    vec4 color;
} fs_in;

void main() {
    float intensity = 1.0 / length(fs_in.pos.xy - lightPos);
    //FragColor = colour * intensity;
    FragColor = fs_in.color * intensity;
}
