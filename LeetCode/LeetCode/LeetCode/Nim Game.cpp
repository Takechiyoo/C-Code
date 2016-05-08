#include<iostream>

using namespace std;

/**
 * You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. 
 * The one who removes the last stone will be the winner. You will take the first turn to remove the stones.
 *
 * Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.
 *For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.
 *
 * ���������ټ������ӾͿ��Է��ֵ��Է�����ʯͷ֮�������ʣ4�����ұ������ɣ������Ҿͻ�Ӯ��
 * ���ԣ���� n - 4 ����true����ô n �ͷ���true�����õݹ������ķ������ᳬʱҲ������򵥵İ취�� ��ʵ�ϣ�ͨ�������ӿ��Է��ֵ�һ��������ľ���n=4��Ҳ����˵ֻҪ��4�ı�������ô���䡣
 *
*/
class Solution {
public:

	bool canWinNim(int n) {
		if (n % 4 == 0)
			return false;
		else
			return true;
	}
	/*
	bool canWinNim(int n) {
		if (n == 1 || n == 2 || n == 3)
			return true;
		if (n == 4)
			return false;
		return canWinNim(n - 4);
	}
	*/
};
