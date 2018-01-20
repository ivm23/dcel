#pragma once
#include <utility>

class Half_Edge;

class Face {
	
public:
	Face() :
		boundary(NULL),
		global_next(NULL),
		global_prev(NULL)
	{}
	~Face() {};

	inline Half_Edge * get_boundary() const {
		return this->boundary;
	}

	inline void set_boundary(Half_Edge * boundary_of_face) {
		this->boundary = boundary_of_face;
	}

	friend class Mesh;

private:
	Half_Edge * boundary;

protected:
	Face * global_next;
	Face * global_prev;	
};
