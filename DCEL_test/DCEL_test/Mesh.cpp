#include "Mesh.h"

Mesh::Mesh() {
}

Mesh::~Mesh() {
	this->clear();
}

void Mesh::clear() {
	this->face_list.clear();
	this->vertex_list.clear();
	this->half_edge_list.clear();
}

bool Mesh::is_empty() const{
	return (vertex_list.empty() && face_list.empty() && half_edge_list.empty());
}

void Mesh::insert(Vertex * vertex) {
	if (vertex) {
		vertex_list.push_back(vertex);
	}
}

void Mesh::insert(Half_Edge * half_edge) {
	if (half_edge) {
		half_edge_list.push_back(half_edge);
	}
}

void Mesh::insert(Face * face) {
	if (face) {
		face_list.push_back(face);
	}
}

void Mesh::remove(Vertex * vertex) {
	if (vertex) {
		std::list<Vertex*>::iterator it = std::find(vertex_list.begin(), vertex_list.end(), vertex);
		vertex_list.erase(it);
	}
}

void Mesh::remove(Face * face) {
	if (face) {
		std::list<Face*>::iterator it = std::find(face_list.begin(), face_list.end(), face);
		face_list.erase(it);
	}
}

void Mesh::remove(Half_Edge * half_edge) {
	if (half_edge) {
		std::list<Half_Edge*>::iterator it = std::find(half_edge_list.begin(), half_edge_list.end(), half_edge);
		half_edge_list.erase(it);
	}
}