#version 430 core

in vec2 texpos;
out vec4 frag_color;

uniform sampler2D sprite;

void main() {
    frag_color = texture(sprite, texpos);
}
