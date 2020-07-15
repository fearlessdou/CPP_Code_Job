//#include <iostream>
//#include<vector>
//using namespace std;
//void swap(int& a,int&b)
//{
//    int tmp=a;
//    a=b;
//    b=tmp;
//}
//void sort(int*sort_data,int start,int end)
//{
//    if (start>=end) return;
//    int A=sort_data[start];//选择初始位置作为基数
// 
//    int i=start+1;//哨兵i，从第二个位置开始，从左向右
//    int j=end;//哨兵j，从最后一个位置，从右向左
//    while(i<j)
//    {
//        while(A<sort_data[j]&&i<j)//哨兵j，从最后一个位置，从右向左
//            j--;
//        while(A>sort_data[i]&&i<j)//哨兵i，从第二个位置开始，从左向右
//            i++;
//        swap(sort_data[i],sort_data[j]);
//    }
//    if (sort_data[start]>sort_data[i])
//        swap(sort_data[start],sort_data[i]);
// 
// 
//    sort(sort_data,start,i-1);
//    sort(sort_data,i+1,end);
// 
//}
//
//
////大化数据结构方式
//int partition(int*sort_data, int low, int high)
//{
//	int pivotkey = *(sort_data + low);
//
//	while (low < high)
//	{
//		while (low < high&& *(sort_data + high) >= pivotkey)
//			--high;
//		swap(*(sort_data + low), *(sort_data + high));
//		while (low < high&& *(sort_data + low) <= pivotkey)
//			++low;
//		swap(*(sort_data + low), *(sort_data + high));
//	}
//	return low;
//}
//void QSort(int*sort_data, int low, int high)
//{
//
//	int pivot;
//	if (low < high)
//	{
//		pivot = partition(sort_data,low,high);
//
//		QSort(sort_data, low, pivot-1);
//		QSort(sort_data, pivot+1,high);
//
//	}
//}
//
//int main() {
// 
//	//int data[14] = { 3,5,1,6,7,8,4,9,2,10,10,8,11,13 };
//	int data[18] = { 3,5,1,6,7,8,4,9,2,10,10,8,11,13,3,5,8,9 };
//	QSort(data,0,17);
//    for(int i=0;i<18;i++)
//    {
//        std::cout<<data[i]<<std::endl;
//    }
//    return 0;
//}
//


#include<iostream>

using namespace std;

void swap(int(&L)[100], int low, int high)
{
	int temp = L[low];
	L[low] = L[high];
	L[high] = temp;

}

int partition(int(&L)[100], int low, int high)
{
	int pivotkey = L[low];

	while (high > low)
	{
		while (low<high && L[high]>=pivotkey)
			--high;
		swap(L, low, high);
		while (low<high && L[low]<=pivotkey)
			++low;
		swap(L, low, high);

	}
	return low;

}

void qsort(int(&L)[100], int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = partition(L, low, high);

		qsort(L, low, pivot - 1);
		qsort(L, pivot + 1, high);
	}


}

int main()
{
	int L[100] = { 5,6,8,99,33,66,88,54,7 ,546,364,354,643,6643,6,43};
	for (int i = 0; i < 15; i++)
		cout << L[i] << ' ';
	cout << endl;

	qsort(L, 0, 14);

	for (int i = 0; i < 15; i++)
		cout << L[i] << ' ';
	cout << endl;

}


