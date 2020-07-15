#include<iostream>
#include<vector>
#include <algorithm>


using namespace std;

int main()
{

	vector<int>nums;
	int n;
	cin >> n;
	while (n--) {
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	sort(nums.begin(),nums.end());
	for (int i = 1; i <= nums.size(); i++) {
		if (nums[i-1] != i) {
			cout << i;
			break;
		}
	}
	if(nums[nums.size()-1]== nums.size()-1)cout << nums.size();

	return 0;
}