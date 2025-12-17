#include "SpriteInstancing.hpp"
#include "generators.h"

SpriteInstancing::SpriteInstancing(RR::Program& program, GLintptr amount) {
	SpriteVertex* temp = new SpriteVertex[amount];
	this->instanceData = RR::VertexBuffer<SpriteVertex>(temp, amount, GL_DYNAMIC_DRAW);
	this->instanceData.bind();
	delete[] temp;
	
	RR_AUTOATTRIB(SpriteVertex, begin, GL_TRUE);
	RR_AUTOATTRIB(SpriteVertex, end, GL_TRUE);
	RR_AUTOATTRIB(SpriteVertex, uv_begin, GL_TRUE);
	RR_AUTOATTRIB(SpriteVertex, uv_end, GL_TRUE);

    RR_ATTRIBDEVISOR1(begin);
    RR_ATTRIBDEVISOR1(end);
    RR_ATTRIBDEVISOR1(uv_begin);
    RR_ATTRIBDEVISOR1(uv_end);
}

void SpriteInstancing::prepareInstancing(RR::Program& program) {
	this->static_buffer = RR::VertexBuffer<SpriteVertexReal>(static_sprite_verticies, 4, GL_STATIC_DRAW);
	RR_AUTOATTRIB(SpriteVertexReal, sprite_vec_var, GL_TRUE);
}

void set(int index, SpriteVertex& vertex) {
	glBufferSubData(GL_ARRAY_BUFFER, (GLintptr)(sizeof(SpriteVertex) * index), (GLintptr)sizeof(SpriteVertex), &vertex);
}
