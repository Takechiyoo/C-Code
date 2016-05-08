#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class rule
{
public:
	string key;
	string ip;
	string mask;
	//rule(string keyword, string address) : key(keyword), ip(address), mask(NULL){}
	rule(string keyword, string address, string maskCode) : key(keyword), ip(address), mask(maskCode){}
};

string Binarycout(int n)
{
	string bitString = "";

	for (int i = 7; i >= 0; i--)
	{
		stringstream ss;
		ss << (((n >> i) & 1));
		bitString += string(ss.str());
	}
	return bitString;
}

void processAddress(string s, rule *&r)
{
	int keyIndex = s.find(' ');
	string key = s.substr(0, keyIndex);
	int maskIndex = s.find('/');
	string mask;
	string ip;
	if (maskIndex != -1)
	{
		mask = s.substr(maskIndex + 1, s.size());
		ip = s.substr(keyIndex + 1, maskIndex);
		r = new rule(key, ip, mask);
	}
	else
	{
		ip = s.substr(keyIndex + 1, s.size());
		r = new rule(key, ip, "");
	}
	
}

string bitOfString(string s)
{
	int first = s.find(".");
	int second = s.find(".", first + 1);
	int third = s.find(".", second + 1);
	string result = "";
	int f = atoi(s.substr(0, first).c_str());
	int ss = atoi(s.substr(first + 1, second).c_str());
	int t = atoi(s.substr(second + 1, s.size()).c_str());
	result += Binarycout(f);
	result += Binarycout(ss);
	result += Binarycout(t);
	return result;
}

bool isMatch(rule*& r, rule*& p)
{
	if (r->ip == p->ip) return true;
	if (r->mask != "")
	{
		int mask = atoi(r->mask.c_str());
		string bitOfR = bitOfString(r->ip);
		string bitOfP = bitOfString(p->ip);
		for (int i = 0; i < mask; i++)
		{
			if (bitOfP[i] != bitOfR[i])
				return false;
		}
		return true;
	}
	return false;
}

void isValidIP(string ip, vector<rule *> &rules)
{
	rule *p = NULL;
	processAddress(ip, p);
	for (int i = 0; i < rules.size(); i++)
	{
		if (isMatch(rules[i], p))
		{
			if (rules[i]->key == "allow")
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	cout << "YES" << endl;
}



int main()
{	
	cout << "git" << endl;
	int n, m;
	cin >> n >> m;
	string temp;
	getline(cin, temp);
	vector<rule *> rules;
	while (n)
	{
		n--;
		string ip;
		getline(cin, ip);
		rule *r = NULL;
		processAddress(ip, r);
		rules.push_back(r);
	}
	while (m)
	{
		m--;
		string ip;
		getline(cin, ip);
		isValidIP(ip, rules);
	}
	return 0;
}