#include<iostream>
#include<vector>
#include <algorithm>
#include <string>

using namespace std;

bool palindrome(const std::string& s, int i, int j)
{
	for (; i < j && s[i] == s[j]; ++i, --j);
	return i >= j;
}

bool validPalindrome(string s) {
	int i = 0, j = s.size() - 1;
	for (; i < j && s[i] == s[j]; ++i, --j);
	return palindrome(s, i, j - 1) || palindrome(s, i + 1, j);
}

int main() {
	string s;
	getline(cin, s);
	int len = s.size();
	string s2 = s + s;
	bool flag=false;
	for (int i = 0; i < len; i++) {
		string res = s2.substr(i, len);
		if (validPalindrome(res)) {
			flag = 1;
			break;
		}
	}
	if(flag)cout << "Yes"; 
	else cout << "No";
	return 0;
}