#pragma once
#include <list>
//#include <algorithm>  

#include "Face.h"
#include "Half_Edge.h"
#include "Vertex.h"
#include "Half_Edge_Iterator.h"

class Mesh {

public:
	Mesh();
	~Mesh();

	Face* first_face() { return face_list; };
	Face* next (Face* face) { return (face != NULL) ? face->global_next : NULL; };
	void advance(Face* &face) { face = (face != NULL) ? face->global_next : NULL; };

	Vertex* first_vertex() { return vertex_list; };
	Vertex* next (Vertex* vertex) { return (vertex != NULL) ? vertex->global_next : NULL; };
	void advance(Vertex* &vertex) { vertex = (vertex != NULL) ? vertex->global_next : NULL; };

	Half_Edge* first_half_edge() { return half_edge_list; };
	Half_Edge* next(Half_Edge* half_edge) { return (half_edge != NULL) ? half_edge->global_next : NULL; };
	void advance(Half_Edge* &half_edge) { half_edge = (half_edge != NULL) ? half_edge->global_next : NULL; };

	void clear();
	
	bool is_empty() const;

	void insert(Vertex * vertex);
	void insert(Face * face);
	void insert(Half_Edge * edge);

	void remove(Vertex * vertex);
	void remove(Face * face);
	void remove(Half_Edge * half_edge);

	inline unsigned int get_num_faces() const { 
		return num_faces;
	}

	inline unsigned int get_num_vertices() const { 
		return num_vertices;
	}

	inline unsigned int get_num_half_edges() const { 
		return num_half_edges;
	}


private:
	Face * face_list;
	Vertex * vertex_list;
	Half_Edge * half_edge_list;

	unsigned int num_faces;
	unsigned int num_vertices;
	unsigned int num_half_edges;
};