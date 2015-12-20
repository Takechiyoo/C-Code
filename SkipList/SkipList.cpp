#include "Node.h"
#include <random>
#include <vector>

class SkipList
{
private:
	const int MAX_LEVEL = 5;
	int level;
	mt19937 rng;
	Node* header;
	
public:
	SkipList()
	{ 
		header = new Node(0, 0, MAX_LEVEL);
		level = 0;
		rng.seed(random_device()());
	}
	int randomLevel()
	{
		//mt19937 rng;
		//rng.seed(random_device()());
		uniform_int_distribution<mt19937::result_type> distMaxLevel(1, MAX_LEVEL);
		return distMaxLevel(rng);
	}
	int searchNode(int searchKey)
	{
		// The list is empty.
		if (level == 0)
			return -1;
		//如果forward的大小为0怎么整
		Node *p = header;
		for (int i = level; i != 0; i--)
		{
			while (p->forward[i] != NULL && p->forward[i]->key < searchKey)
				p = p->forward[i];
		}
		if (p != NULL && p->key == searchKey)
			return p->value;
		else
			return -1;
	}
	bool insertNode(int searchKey, int newValue)
	{
		vector<Node *> update(MAX_LEVEL + 1, NULL);
		// The list is empty. 
		if (level == 0)
		{
			int lvl = randomLevel();
			Node *p = new Node(searchKey, newValue, lvl);
			level = lvl;
			for (int i = level; i != 0; i--)
				header->forward[i] = p;
			return true;
		}
		Node *p = header;
		int lvl;
		for (int i = level; i != 0; i--)
		{
			while (p->forward[i] != NULL && p->forward[i]->key < searchKey)
				p = p->forward[i];
			update[i] = p;
		}
		p = p->forward[1];
		/*If the key is alreay in the list, then update the value and return true; else insert a new node with the key and value*/
		if (p != NULL && p->key == searchKey)
		{
			p->value = newValue;
			return true;
		}
		else
		{
			lvl = randomLevel();
			/*If the new node's level is greated than the list's current level, then update the list's level and the corrensponding forwords*/
			if (lvl > level)
			{
				for (int i = level + 1; i != lvl + 1; i++)
					update[i] = header;
				level = lvl;
			}
			p = new Node(searchKey, newValue, lvl);
			for (int i = 1; i != lvl + 1; i++)
			{
				p->forward[i] = update[i]->forward[i];
				update[i]->forward[i] = p;
			}
			return true;
		}
		return false;
	}
	int deleteNode(int searchKey)
	{
		vector<Node *> update(MAX_LEVEL + 1, NULL);
		// If the list is empty, return false.
		if (level == 0)
			return -1;
		Node* p = header;
		/*Find the value and remember its parents*/
		for (int i = level; i != 0; i--)
		{
			while (p->forward[i] != NULL && p->forward[i]->key < searchKey)
				p = p->forward[i];
			update[i] = p;
		}
		p = p->forward[1];
		if (p != NULL && p->key == searchKey)
		{
			for (int i = 1; i != p->level + 1; i++)
			{
				//if (update[i]->forward[i] == p->forward[i])
					//break;
				update[i]->forward[i] = p->forward[i];
			}
			/*Update the level.*/
			while (level > 0 && header->forward[level] == NULL)
				level--;
			return p->value;
		}
		return -1;
	} 
	void show()
	{
		Node *p = header->forward[1];
		cout << "root" << ":" << "value" << "\t" << level << endl;
		for (int i = 1; i != level + 1; i++)
		{
			if (header->forward[i] != NULL)
				cout << "\t" << header->forward[i]->key << endl;
			else
				cout << "\t" << "NULL" << endl;
		}
		cout << "**********************" << endl;
		while (p != NULL)
		{
			cout << p->key << ":" << p->value << "\t" << p->level << endl;
			for (int i = 1; i != p->level + 1; i++)
				if (p->forward[i] != NULL)
					cout << "\t" << p->forward[i]->key << endl;
				else
					cout << "\t" << "NULL" << endl;
			cout << "***************************" << endl;
			p = p->forward[1];
		}
	}
};

int main()
{
	//mt19937 rng;
	//rng.seed(random_device()());
	//uniform_int_distribution<mt19937::result_type> distMaxLevel(1, 10);
	SkipList l;
	l.insertNode(1, 2);
	l.insertNode(2, 3);
	l.insertNode(4, 9);
	l.insertNode(3, 10);
	l.show();
	l.deleteNode(1);
	l.deleteNode(3);
	l.deleteNode(4);
	cout << l.deleteNode(2) << endl;
	l.insertNode(5, 1);
	l.insertNode(3, 1);
	l.show();
	//cout << l.searchNode(4) << endl;
	cout << "Hello world" << endl;
}