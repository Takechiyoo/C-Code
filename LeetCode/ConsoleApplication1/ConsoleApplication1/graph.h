#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cassert>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <hash_map>
#include "windows.h"
#include "time.h"

//using namespace __gnu_cxx;
using namespace std;

class Node;
class Graph;

class Edge{
public:
	int n1, n2;  //边的两端点
	Edge(int src, int dest){
		n1 = src;
		n2 = dest;
	}
	int getSrc(){
		return n1;
	}
	int getDest(){
		return n2;
	}
};

class Node{
public:
	int id;
	set <int> adjNodes;   //存储邻居节点
	//    map <int, Edge> adjEdges;  //存储邻居边


	Node(int number){
		this->id = number;
		//        this->adjNodes=new set<int>;
	}

	int getId(){
		return id;
	}

	int getDegree(){
		return adjNodes.size();
	}

	void addNeighbor(int n)   //增加邻居节点
	{
		adjNodes.insert(n);
	}

	void removeNeighbor(int n)  //删除某个邻居节点
	{
		this->adjNodes.erase(n);
	}


};



class Graph{
public:
	map<int, Node> nodes;   //int为节点号ID，Node 为节点对象
	//	vector <Node> nodeIndex;
	//	char filename;
	list <Edge> edges;  //存储所有的边对象

	Graph(){
		//		filename=f;
		//        this->nodes=new hash_map<int,Node>;
		//       this->edges=new list<Edge>;
	}

	Node getNode(int id)    //已知节点id，返回节点对象
	{
		return this->nodes.find(id)->second;  //*(this->nodes.find(id)) 或使用引用
	}
	/*
	map<int.Node> getNodes()   //返回所有节点对象
	{
	return this->nodes;
	}
	*/
	void addNode(Node n)  //添加一个节点
	{
		if (this->nodes.find(n.getId()) == this->nodes.end()) //节点n不存在时才添加
		{
			this->nodes.insert(pair<int, Node>(n.getId(), n));
		}
	}

	void addNodes(vector<Node> nodes)  //添加多个节点
	{
		for (vector<Node>::iterator it = nodes.begin(); it != nodes.end(); it++)
		{
			if (this->nodes.find(it->getId()) == this->nodes.end())
			{
				this->nodes.insert(pair<int, Node>(it->getId(), *it));
			}
		}
	}

	list <Edge> getEdges()  //返回所有边对象
	{
		return this->edges;
	}

	/*
	Edge getEdge(int n1, int n2)  //根据两端点返回一条边对象
	{
	map<int, Edge>::iterator it;
	for (it = nodeIndex[n1]->adjEdges.begin();
	it != nodeIndex[n1]->adjEdges.end();
	++it)
	{
	if (it->first == n2)
	{
	return it->second;
	}
	}
	return NULL;
	}
	*/

	Edge getEdge(int u, int v)  //根据两端点返回一条边对象
	{
		for (list <Edge>::iterator itor = this->edges.begin(); itor != this->edges.end(); itor++)
		{
			if (itor->getSrc() == u && itor->getDest() == v || itor->getSrc() == v && itor->getDest() == u)
			{
				return *itor;
			}
		}
		//        return NULL;
	}

	void addEdge(Node x, Node y)  //根据端点对象加入边对象
	{
		if (this->nodes.find(x.getId()) == this->nodes.end())
		{
			Node start = this->nodes.find(x.getId())->second;
			start.adjNodes.insert(y.getId());
		}
		else
		{
			this->nodes.insert(pair<int, Node>(x.getId(), x));
			x.adjNodes.insert(y.getId());
		}
		if (this->nodes.find(y.getId()) == this->nodes.end())
		{
			Node start = this->nodes.find(y.getId())->second;
			start.adjNodes.insert(x.getId());
		}
		else
		{
			this->nodes.insert(pair<int, Node>(y.getId(), y));
			y.adjNodes.insert(x.getId());
		}

		this->edges.insert(new Edge(x.getId(), y.getId()));
		//Edge a = new Edge(x.getId(),y.getId());
		//edges.insert(a);
	}


	int getEdgeNumber()
	{
		return this->edges.size();
	}

	void removeEdge(Edge e)
	{
		int src = e.getSrc();
		int dest = e.getDest();
		Node u = this->getNode(src);
		Node v = this->getNode(dest);
		u.adjNodes.erase(v.getId());
		v.adjNodes.erase(u.getId());
		for (list <Edge>::iterator itor = this->edges.begin(); itor != this->edges.end(); itor++)
		{
			if ((itor->getSrc() == e.getSrc() && itor->getDest() == e.getDest()) || (itor->getSrc() == e.getDest() && itor->getDest() == e.getSrc()))
			{
				itor = this->edges.erase(itor);
			}
			else
			{
				itor++;
			}
		}
	}

	/*
	bool readGraph()
	{
	int n1, n2;
	ifstream o2(filename);
	if (!o2.is_open())
	{
	cout << "error:can not open file:" << filename << endl;
	system("pause");
	exit(0);
	}

	int j = 0;
	char buf[100];
	ifstream o1(filename);

	do
	{
	o1.get(buf[j]);
	if (buf[j] == '\t')
	{
	j++;
	}
	}
	while (buf[j] != '\n');
	o1.close();
	do
	{
	if (j == 1)
	{
	o2 >> n1;
	o2 >> n2;
	}

	if (n1 > n2)
	{
	int temp = n1;
	n1 = n2;
	n2 = temp;
	}

	bool flag = 1;
	map<int, Edge*>::iterator mit;

	if (n1 < nodeIndex.size() && nodeIndex[n1] != NULL)
	{
	for (mit = nodeIndex[n1]->adjEdges.begin(); mit != nodeIndex[n1]->adjEdges.end(); ++mit)
	{
	if (mit->first == n2)
	{
	flag = 0;
	break;
	}
	}
	}

	if (flag)
	{
	Edge* s = new Edge(n1, n2);
	edgelist.push_back(s);
	nodeIndex[n1]->mapIns(n2, s);
	nodeIndex[n2]->mapIns(n1, s);
	nodeIndex[n1]->adjNodesIns(n2);
	nodeIndex[n2]->adjNodesIns(n1);
	}
	}
	while (!o2.eof());
	o2.close();
	clock_t time2 = clock();
	return 1;
	}
	*/
};

