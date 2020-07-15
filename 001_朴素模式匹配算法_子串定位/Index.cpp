#include<iostream>
#include<string>

using namespace std;


int Index(string S ,string T, int pos)
{
	int i = pos;  //当前主串下标
	int j = 0; //子串当前下标值

	while (i < S.length() && j < T.length())
	{
		if (S[i] == T[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 1;//返回到上次匹配的下一位
			j = 0;
		}
	}

	if (j >= T.length())
		return i - T.length()+1;
	else
		return 0;

}



void test1()
{

	string S = "abcdefg334";
	string T = "defg";
	cout << S << "  " << T;
	cout <<  "  " << S[0] << S[1] << "  ";
	cout<<Index(S, T, 0);


}

int main()
{

	test1();

	getchar();
}