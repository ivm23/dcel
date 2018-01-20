#pragma once
#include <utility>

class Half_Edge;

class Face {
	
public:
	Face() :
		boundary(NULL)
	{}

	inline Half_Edge * get_boundary() const {
		return this->boundary;
	}

	inline void set_boundary(Half_Edge * boundary_of_face) {
		this->boundary = boundary_of_face;
	}

private:
	Half_Edge * boundary;
	
};
