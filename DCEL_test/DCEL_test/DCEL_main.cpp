#include "Mesh.h"
#include <iostream>

using namespace std;
int main() {
	Vertex v1, v2;
	Half_Edge e1, e2;
	Face f1, f2;

	Mesh myMesh;
	myMesh.insert(&v1);
	myMesh.insert(&v2);
	myMesh.insert(&e1);
	myMesh.insert(&e2);
	myMesh.insert(&f1);
	myMesh.insert(&f2);

	v1.set_vertex_coordinates(pair<double, double>(1, 2));
	v2.set_vertex_coordinates(pair<double, double>(2, 5));

	e1.set_origin(&v1);
	e2.set_origin(&v2);

	e1.set_twin(&e2);
	e2.set_twin(&e1);

	f1.set_boundary(&e1);
	f2.set_boundary(&e1);

	e1.set_face(&f1);
	e2.set_face(&f2);

	cout << myMesh.get_num_faces() << ' ' << myMesh.get_num_half_edges() << ' ' << myMesh.get_num_vertices() << endl;
	list<Vertex*> temp_vertex_list = myMesh.get_vertex_list();
	for (auto v = temp_vertex_list.begin(); v != temp_vertex_list.end(); ++v) {
		cout << (*v)->get_vertex_coordinates().first << ' ' << (*v)->get_vertex_coordinates().second << endl;
		(*v)->set_vertex_coordinates(pair<double, double>(1, 1));
		cout << (*v)->get_vertex_coordinates().first << ' ' << (*v)->get_vertex_coordinates().second << endl << endl;
	}
	temp_vertex_list = myMesh.get_vertex_list();
	for (auto v = temp_vertex_list.begin(); v != temp_vertex_list.end(); ++v) {
		cout << (*v)->get_vertex_coordinates().first << ' ' << (*v)->get_vertex_coordinates().second << endl;
	}

	auto v = temp_vertex_list.begin();
	myMesh.remove(*v);
	temp_vertex_list = myMesh.get_vertex_list();

	cout << "After delete!\n";
	for (auto v = temp_vertex_list.begin(); v != temp_vertex_list.end(); ++v) {
		cout << (*v)->get_vertex_coordinates().first << ' ' << (*v)->get_vertex_coordinates().second << endl;
	}



	system("Pause");
	return 0;
}