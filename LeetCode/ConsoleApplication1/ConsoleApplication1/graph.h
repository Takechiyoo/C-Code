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
	int n1, n2;  //�ߵ����˵�
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
	set <int> adjNodes;   //�洢�ھӽڵ�
	//    map <int, Edge> adjEdges;  //�洢�ھӱ�


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

	void addNeighbor(int n)   //�����ھӽڵ�
	{
		adjNodes.insert(n);
	}

	void removeNeighbor(int n)  //ɾ��ĳ���ھӽڵ�
	{
		this->adjNodes.erase(n);
	}


};



class Graph{
public:
	map<int, Node> nodes;   //intΪ�ڵ��ID��Node Ϊ�ڵ����
	//	vector <Node> nodeIndex;
	//	char filename;
	list <Edge> edges;  //�洢���еı߶���

	Graph(){
		//		filename=f;
		//        this->nodes=new hash_map<int,Node>;
		//       this->edges=new list<Edge>;
	}

	Node getNode(int id)    //��֪�ڵ�id�����ؽڵ����
	{
		return this->nodes.find(id)->second;  //*(this->nodes.find(id)) ��ʹ������
	}
	/*
	map<int.Node> getNodes()   //�������нڵ����
	{
	return this->nodes;
	}
	*/
	void addNode(Node n)  //���һ���ڵ�
	{
		if (this->nodes.find(n.getId()) == this->nodes.end()) //�ڵ�n������ʱ�����
		{
			this->nodes.insert(pair<int, Node>(n.getId(), n));
		}
	}

	void addNodes(vector<Node> nodes)  //��Ӷ���ڵ�
	{
		for (vector<Node>::iterator it = nodes.begin(); it != nodes.end(); it++)
		{
			if (this->nodes.find(it->getId()) == this->nodes.end())
			{
				this->nodes.insert(pair<int, Node>(it->getId(), *it));
			}
		}
	}

	list <Edge> getEdges()  //�������б߶���
	{
		return this->edges;
	}

	/*
	Edge getEdge(int n1, int n2)  //�������˵㷵��һ���߶���
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

	Edge getEdge(int u, int v)  //�������˵㷵��һ���߶���
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

	void addEdge(Node x, Node y)  //���ݶ˵�������߶���
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

