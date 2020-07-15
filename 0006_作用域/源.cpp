#include<iostream>

//using namespace std;
int count = 3;
int main(void)
{
	int i, sum, count = 2;
	for (i = 0, sum = 0; i < count; i += 2, count++)
	{
		static int count = 4;
		count++;
		if (i % 2 == 0)
		{
			extern int count;
			count++;
			sum += count;
		}
		sum += count;
	}
	std::cout << count << '  ' << sum << std::endl;
	return 0;
}
