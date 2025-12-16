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
}
