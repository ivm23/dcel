#pragma once
#include <utility>

class Half_Edge;

class Vertex {
public:

	Vertex() :
		vertex_coordinates(),
		incident_half_edge(NULL)
	{}

	inline Half_Edge * get_incident_half_edge() const {
		return this->incident_half_edge;
	}

	inline void set_incident_half_edge(Half_Edge * edge) {
		this->incident_half_edge = edge;
	}

	inline std::pair<double, double> get_vertex_coordinates() const {
		return this->vertex_coordinates;
	}

	inline void set_vertex_coordinates(std::pair<double, double> coordinates) {
		this->vertex_coordinates = coordinates;
	}

private:
	std::pair<double, double> vertex_coordinates;
	Half_Edge * incident_half_edge;

};