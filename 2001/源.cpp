#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class A
{
	int n;
public:
	static int x;
	A(int x = 0) :n(x) {}
	void  f2(int x) { n = x; }
};
int A::x = 0;

class B:private A
{
	int m;
	A a;
public:
	B(int b, int c) :A(b) { m = c; }
	void  f3(int i, int j) { f2(i); m = j; }
	//void  f3(int i, int j) { A::n=i; m = j; }
	//void  f3(int i, int j) { A.f2(i); m = j; }
	//void  f3(int i, int j) {n=i; m = j; }
};

int main() {

	float a;
	a = 1;
	float c = a * 1;
	//B b(2, 3);
	//b.f3(5, 6);
	cout << endl;
}
