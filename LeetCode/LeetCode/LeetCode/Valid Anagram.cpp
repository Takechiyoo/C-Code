#include <iostream>
#include <hash_map>

using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size())
			return false;

		hash_map<char, int> s_map;
		hash_map<char, int> t_map;
		for (int i = 0; i < s.size(); i++)
		{
			if (s_map.find(s[i]) == s_map.end())
				s_map[s[i]] = 1;
			else
				s_map[s[i]] = s_map[s[i]] + 1;
			if (t_map.find(t[i]) == t_map.end())
				t_map[t[i]] = 1;
			else
				t_map[t[i]] = t_map[t[i]] + 1;

		}
		return s_map == t_map;
	}
};

/*
if(s.length() != t.length())
return false;

int count[26] = {0};

for(int i=0;i<s.length();i++)
{
count[s[i]-'a']++;
count[t[i]-'a']--;
}

for(int i=0;i<26;i++)
if(count[i] != 0)
return false;

return true;
*/