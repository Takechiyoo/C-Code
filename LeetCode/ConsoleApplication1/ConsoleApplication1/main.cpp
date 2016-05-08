#include "graph.h"
#include "build.cpp"

using namespace std;

float compute_coefficient(Node n);
void judge_edge_deletion(Edge e, Graph g);

int main(){
	ofstream outfile;
	outfile.open("output_karate.txt");
	clock_t begin = clock();
	GraphBuilder gb = new GraphBuilder("data/karate");
	Graph g = gb.buildGraph();
	cout << g->edges.size() << endl;

	clock_t begin1 = clock();
	cout << "build end" << endl;
	clock_t endofread = clock();

	list<Edge>::iterator it;
	for (it = g->edges.begin(); it != g->edges.end(); it++)
	{
		judge_edge_deletion(*it, g);
	}

	cout << "end computing" << endl;
	cout << g->edges.size() << endl;


	for (it = g->edges.begin(); it != g->edges.end(); it++)
	{
		cout << "(" << *it->getSrc() << "," << *it->getDest() << ")" << endl;
		cout << num++ << endl;
	}
	outfile.close();

	clock_t end = clock();

	return 0;
}

float compute_coefficient(Node n, Graph g)  // 计算节点的局部聚类系数
{
	int degree_of_Node = n->getDegree(); //the degree of node n
	int num_of_edges = 0; //the number of edges among node n's neighbors
	float coefficient;
	int temp1;
	int temp2;
	for (set<int>::iterator = n->adjNodes.begin(); index1 != n->adjNodes.end(); index1++){
		temp1 = *index1;
		for (set<int>::iterator index2 = n->adjNodes.begin(); index2 != n->adjNodes.end(); index2++){
			temp2 = *index2;
			if (temp1<temp2){
				//Node tmpnode2=new Node(temp2);
				set<int>::iterator exist = g->getNode(temp2).adjNodes.find(temp1);
				if (exist != g->getNode(temp2).adjNodes.end()){
					num_of_edges++;
				}
			}
		}
	}
	coefficient = num_of_edges / ((degree_of_Node*(degree_of_Node - 1)) + 1);
	return coefficient;
}


void judge_edge_deletion(Edge e, Graph g){  //对每条边进行判断，看是否应该删除
	int src = e->getSrc();
	int dest = e->getDest();
	float sum1_coeff;
	float sum2_coeff;
	Node node1 = g->nodes.getNode(src);
	Node node2 = g->nodes.getNode(dest);

	sum1_coeff = compute_coefficient(node1, g) + compute_coefficient(node2, g);
	node1->adjNodes.erase(node1->adjNodes.find(dest)); // 暂时不从g中删除边，此时相当于虚拟删除。
	node2->adjNodes.erase(node2->adjNodes.find(src));
	sum2_coeff = compute_coefficient(node1) + compute_coefficient(node2);


	if (sum1_coeff>sum2_coeff){
		node1->adjNodes.insert(dest);
		node2->adjNodes.insert(dest);
	}
	else{
		g->removeEdge(e);
	}
}
