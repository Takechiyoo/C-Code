#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
	int key;
	int value;
	int level;
	vector<Node *> forward;
	Node(int key, int value, int level)
	{
		this->key = key;
		this->value = value;
		this->level = level;
		for (int i = 0; i != level + 1; i++)
			this->forward.push_back(NULL);
	}
};