#version 330 core

out vec4 FragColor;

uniform vec4 colour;
uniform vec2 lightPos;
uniform sampler2D ourTexture;

in DATA {
    vec4 pos;
    vec4 color;
    vec2 texCoord;
} fs_in;

void main() {
    float intensity = 1.0 / length(fs_in.pos.xy - lightPos);
    //FragColor = colour * intensity;
    //FragColor = fs_in.color * intensity;
    FragColor = texture(ourTexture, fs_in.texCoord); // * fs_in.color * intensity;
}
