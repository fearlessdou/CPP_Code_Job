#include<iostream>

using namespace std;

class Solution {
public:
	char firstUniqChar(string s) {
		if (s.empty())return ' ';
		int voc[26] = { 0 };
		for (int i = 0; i < s.size(); i++) {
			voc[int(s[i] - 'a')]++;
		}
		for (int i = 0; i < 26; i++) {
			if (voc[i] == 1)return 'a' + i;
		}
		return ' ';
	}
};


int main() 
{

	Solution solution;
	string s="leetcode";
	char a;
	a= solution.firstUniqChar(s);
	return 0;
}