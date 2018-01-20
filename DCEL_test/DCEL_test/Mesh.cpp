#include "Mesh.h"

Mesh::Mesh() {
}

Mesh::~Mesh() {
	this->clear();
}

void Mesh::clear() {
	Vertex * current_vertex = vertex_list;
	Vertex * temp_vertex = NULL;

	while (current_vertex) {
		temp_vertex = current_vertex->global_next;
		current_vertex->incident_half_edge = NULL;
		current_vertex->global_next = NULL;
		current_vertex->global_prev = NULL;
		delete current_vertex;
		current_vertex = temp_vertex;
	}
	vertex_list = NULL;

	Face * current_face = face_list;
	Face * temp_face = NULL;

	while (current_face) {
		temp_face = current_face->global_next;
		delete current_face;
		current_face = temp_face;
	}
	face_list = NULL;

	Half_Edge * current_half_edge = half_edge_list;
	Half_Edge * temp_half_edge = NULL;

	while (current_half_edge) {
		temp_half_edge = current_half_edge->global_next;
		delete current_half_edge;
		current_half_edge = temp_half_edge;
	}
	half_edge_list = NULL;

	this->num_faces = 0;
	this->num_vertices = 0;
	this->num_half_edges = 0;
}

bool Mesh::is_empty() const{
	return (vertex_list == NULL && face_list == NULL && half_edge_list == NULL);
}

void Mesh::insert(Vertex * vertex) {
	if (vertex) {
		if (vertex_list) {
			vertex->global_next = vertex_list;
			vertex_list->global_prev = vertex;
			vertex_list = vertex;
		}
		else
			vertex_list = vertex;

		++num_vertices;
	}
}

void Mesh::insert(Half_Edge * half_edge) {
	if (half_edge) {
		if (half_edge_list) {
			half_edge->global_next = half_edge_list;
			half_edge_list->global_prev = half_edge;
			half_edge_list = half_edge;
		}
		else
			half_edge_list = half_edge;

		++num_half_edges;
	}
}

void Mesh::insert(Face * face) {
	if (face) {
		if (face_list) {
			face->global_next = face_list;
			face_list->global_prev = face;
			face_list = face;
		}
		else
			face_list = face;

		++num_faces;
	}
}

void Mesh::remove(Vertex * vertex) {
	if (vertex) {
		if (vertex_list == vertex) {
			vertex_list = vertex_list->global_next;
			if (vertex_list)
				vertex_list->global_prev = NULL;
		}
		else {
			vertex->global_prev->global_next = vertex->global_next;
			if (vertex->global_next)
				vertex->global_next->global_prev = vertex->global_prev;
		}
		vertex->global_next = NULL;
		vertex->global_prev = NULL;
		//delete vertex;
		--num_vertices;
	}
}

void Mesh::remove(Face * face) {
	if (face) {
		if (face_list == face) {
			face_list = face_list->global_next;
			if (face_list)
				face_list->global_prev = NULL;
		}
		else {
			face->global_prev->global_next = face->global_next;
			if (face->global_next)
				face->global_next->global_prev = face->global_prev;
		}
		face->global_next = NULL;
		face->global_prev = NULL;
	//	delete face;
		--num_faces;
	}
}

void Mesh::remove(Half_Edge * half_edge) {
	if (half_edge) {
		if (half_edge_list == half_edge) {
			half_edge_list = half_edge_list->global_next;
			if (half_edge_list)
				half_edge_list->global_prev = NULL;
		}
		else {
			half_edge->global_prev->global_next = half_edge->global_next;
			if (half_edge->global_next)
				half_edge->global_next->global_prev = half_edge->global_prev;
		}
		half_edge->global_next = NULL;
		half_edge->global_prev = NULL;
		//delete half_edge;
		--num_half_edges;
	}
}