#pragma once

#include "Face.h"
#include "Half_Edge.h"
#include "Vertex.h"

class Half_Edge_Iterator {

public:
	inline Half_Edge_Iterator(const Vertex * vertex)
	{
		reset(vertex);
	}

	inline Half_Edge_Iterator(const Face * face)
	{
		reset(face);
	}

	inline void reset(const Vertex * vertex) {

		this->start_half_edge = vertex->get_incident_half_edge();
		this->next_half_edge = start_half_edge;
	}

	inline void reset(const Face * face) {
		face_iterator = true;

		this->start_half_edge = face->get_boundary();
		this->next_half_edge = start_half_edge;
	}

	inline Half_Edge * get_next() {

		if (next_half_edge) {

			if (face_iterator) {

				next_half_edge = next_half_edge->get_next();
			}
			else
			{
				next_half_edge->get_twin()->get_next();
			}
		}

		if (next_half_edge == start_half_edge) {

			next_half_edge = NULL;
		}

		return next_half_edge;
	}

private:
	Half_Edge * start_half_edge;
	Half_Edge * next_half_edge;

	bool face_iterator;
};