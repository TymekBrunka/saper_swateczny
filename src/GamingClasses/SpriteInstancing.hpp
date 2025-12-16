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

inline GLint location_begin;
inline GLint location_end;
inline GLint location_uv_begin;
inline GLint location_uv_end;

class SpriteInstancing {
public:
	RR::VertexBuffer<SpriteVertex> instanceData;

	SpriteInstancing(RR::Program& program, GLintptr amount);
	// void set(int index, SpriteVertex& vertex);
};
