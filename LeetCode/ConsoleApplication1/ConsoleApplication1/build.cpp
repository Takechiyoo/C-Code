#include "graph.h"

using namespace std;

class GraphBuilder
{
public:
	string edge_filename;
	GraphBuilder(string filename)
	{
		this->edge_filename = filename;
	}

	Graph buildGraph()
	{
		Graph g = new Graph();
		vector<Edge> edges = new vector<Edge>();
		ifstream infile(edge_filename);
		if (!infile.is_open())
		{
			cout << "error:can not open file:" << edge_filename << endl;
			system("pause");
			exit(0);
		}
		string line;
		int x, y;
		while (getline(infile, line))
		{
			stringstream record(line);
			record >> x;
			record >> y;
			Node m = new Node(x);
			Node n = new Node(y);
			Edge e = new Edge(x, y);
			g.addNode(m);
			g.addNode(n);
			g.addEdge(m, n);
		}
		infile.close();
		return g;
	}

};
