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

	void clear();
	
	bool is_empty() const;

	void insert(Vertex * vertex);
	void insert(Face * face);
	void insert(Half_Edge * edge);

	void remove(Vertex * vertex);
	void remove(Face * face);
	void remove(Half_Edge * half_edge);

	inline std::list<Vertex*> get_vertex_list() {
		return vertex_list;
	}

	inline std::list<Face*> get_face_list() {
		return face_list;
	}

	inline std::list<Half_Edge*> get_half_edge_list() {
		return half_edge_list;
	}

	inline unsigned int get_num_faces() const { 
		return face_list.size();
	}

	inline unsigned int get_num_vertices() const { 
		return vertex_list.size();
	}

	inline unsigned int get_num_half_edges() const { 
		return half_edge_list.size();
	}


private:
	std::list<Face *> face_list;
	std::list<Vertex *> vertex_list;
	std::list<Half_Edge *> half_edge_list;

	//unsigned int num_faces;
	//unsigned int num_vertices;
	//unsigned int num_half_edges;
};