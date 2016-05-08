#include <iostream>
#include <stack>

using namespace std;

/*
class Queue {
private:
stack<int> data;
stack<int> transfer;
public:
//transfer function
void transferData(stack<int>& s1, stack<int>& s2)
{
while (!s1.empty())
{
s2.push(s1.top());
s1.pop();
}
}

// Push element x to the back of queue.
void push(int x) {
data.push(x);
}

// Removes the element from in front of queue.
void pop(void) {
transferData(data, transfer);
transfer.pop();
transferData(transfer, data);
}

// Get the front element.
int peek(void) {
int result;
transferData(data, transfer);
result = transfer.top();
transferData(transfer, data);
return result;
}

// Return whether the queue is empty.
bool empty(void) {
return data.empty();
}
};
*/

class Queue {
private:
	stack<int> data;
	stack<int> transfer;
public:
	//transfer function
	void transferData(stack<int>& s1, stack<int>& s2)
	{
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}

	// Push element x to the back of queue.
	void push(int x) {
		transferData(transfer, data);
		data.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		transferData(data, transfer);
		transfer.pop();
	}

	// Get the front element.
	int peek(void) {
		transferData(data, transfer);
		return transfer.top();
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return data.empty() && transfer.empty();
	}
};
