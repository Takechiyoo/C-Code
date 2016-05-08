#include <iostream>  
#include <vector>

using namespace std;

int a[] = { 1, 3, 5, 4, 6 };
char str[] = "abcde";

void print_subset(int n, int s)
{
	printf("{");
	for (int i = 0; i < n; ++i)
	{
		if (s&(1 << i))         // 判断s的二进制中哪些位为1，即代表取某一位  
			printf("%c ", str[i]);   //或者a[i]  
	}
	printf("}\n");
}

void subset(int n)
{
	for (int i = 0; i < (1 << n); ++i)
	{
		print_subset(n, i);
	}
}



int findMinCoins(int n)
{
	vector<int> result(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		if (i < 2)
			result[i] = result[i - 1] + 1;
		else if (i >= 2 && i < 5)
			result[i] = result[i - 1] + 1 <= result[i - 2] + 1 ? result[i - 1] + 1 : result[i - 2] + 1;
		else
		{
			int temp = result[i - 1] + 1 <= result[i - 2] + 1 ? result[i - 1] + 1 : result[i - 2] + 1;
			result[i] = temp < result[i - 5] + 1 ? temp : result[i - 5] + 1;
		}
	}
	return result[n];
}

void f(char **p)
{
	*p += 2;
}
