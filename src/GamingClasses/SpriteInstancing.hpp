#pragma once
#include "VertexBuffer.hpp"
#include "Program.hpp"
#include "glMathTypes.hpp"

struct SpriteVertex {
	RR::vec2 begin;
	RR::vec2 end;

	RR::vec2 uv_begin;
	RR::vec2 uv_end;
};

struct SpriteVertexReal {
	RR::vec2 sprite_vec_var;
};

static SpriteVertexReal static_sprite_verticies[] = {
	{0.0, 1.0},
	{0.0, 0.0},
	{1.0, 0.0},
	{0.0, 1.0}
};


inline GLint location_begin;
inline GLint location_end;
inline GLint location_uv_begin;
inline GLint location_uv_end;

inline GLint location_sprite_vec_var;

class SpriteInstancing {
	inline static RR::VertexBuffer<SpriteVertexReal> static_buffer;
public:
	RR::VertexBuffer<SpriteVertex> instanceData;

	SpriteInstancing(RR::Program& program, GLintptr amount);
	void prepareInstancing(RR::Program& program);
	// void set(int index, SpriteVertex& vertex);
};
