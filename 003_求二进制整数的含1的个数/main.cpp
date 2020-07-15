#include<iostream>
#include<string>

using namespace std;

int get_n_1_num(int n)
{
	int count=0;
	while (n!=0)
	{
		++count;
		n = n & (n - 1);
	}
	return count;
}

int main()
{
	cout<<get_n_1_num(8);
	getchar();
	
}