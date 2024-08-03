#version 330 core

out vec4 FragColor;

uniform vec4 colour;
uniform vec2 lightPos;

in vec4 pos;

void main() {
    float intensity = 1.0 / length(pos.xy - lightPos);
    FragColor = colour * intensity;
}
