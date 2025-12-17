#version 150 core

in vec2 begin;
in vec2 end;

in vec2 uv_begin;
in vec2 uv_end;

in vec2 sprite_vec_var;
out vec2 texpos;

void main() {
    vec2 pos = vec2(end.x * sprite_vec_var.x, end.y * sprite_vec_var.y)
            + vec2(begin.x * 1.0 - sprite_vec_var.x, begin.y * 1.0 - sprite_vec_var.y);

    gl_Position = vec4(pos, 1.0, 1.0);
    texpos = vec2(uv_end.x * sprite_vec_var.x, uv_end.y * sprite_vec_var.y)
            + vec2(uv_begin.x * 1.0 - sprite_vec_var.x, uv_begin.y * 1.0 - sprite_vec_var.y);

}
