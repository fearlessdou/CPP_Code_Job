#include<iostream>
#include<vector>
#include <algorithm>
//给你个长度为n的01串。现在想让你找出最长的01交替子串(子串可以不连续)比
//如 : 1010, 0101是01交替的串， 1101则不是。现在你可以把某一个连续的区间进行翻
//	转，即0变1, 1变0。问修改之后的最大01交替子串的长度是多少。
//链接：https://www.nowcoder.com/questionTerminal/3fbd8fe929ea4eb3a254c0ed34ac993a
//		 来源：牛客网

#include<iostream>
#include<vector>
#include <algorithm>
#include<string>

using namespace std;
int main() {
	string s;
	cin >> s;
	int max_len = 1, len = 1,temp=s[0],res=1;
	for (int i = 1; i < s.size(); i++) {
		if (s[i - 1] == s[i]) { len++; max_len = max(max_len, len); }
		//else len = 1;
		if (s[i] != temp) {
			res++; 
			temp = s[i];
		}
	}
	if (max_len == 2)res++;
	else if (max_len > 2)res += 2;
	cout << res << endl;
	return 0;
}


//11100010100101010101010
//19
