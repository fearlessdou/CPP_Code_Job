
#include<vector>
#include<iostream>


using namespace std;

vector<vector<int>> cov2(vector<vector<int>>input_X,
	vector<vector<int>>core)
{
	vector<vector<int>>feature_map;
	if (input_X.empty() || core.empty())return feature_map;

	int len_row = input_X.size() - core.size() + 1;
	int len_col = input_X[0].size() - core[0].size() + 1;

	int core_row = core.size();
	int core_col = core[0].size();

	int sum;
	for (int i = 0; i < len_row; i++)
	{
		vector<int>feature_map_cow;
		for (int j = 0; j < len_col; j++)
		{

			sum = 0;
			for (int m = 0; m < core_row; m++)
			{
				for (int n = 0; n < core_col; n++)
				{
					sum += core[m][n] * input_X[i + m][j + n];
				}
			}
			feature_map_cow.push_back(sum);
		}
		feature_map.push_back(feature_map_cow);
	}
	return feature_map;
}
vector<vector<int>> pad(vector<vector<int>>input_X, int core_size)
{
	if (input_X.empty())return input_X;
	//右补充数
	int pad_size=core_size-1;
	int left = pad_size / 2;
	int right = pad_size - left;
	int up =   pad_size / 2;
	int down = pad_size - up;

	for (int i = 0; i < input_X.size(); i++) {
		input_X[i].insert(input_X[i].begin(), left, 0);
		input_X[i].insert(input_X[i].end(), right, 0);
	}
	vector<int>pad_x((input_X.size()+ core_size-1));
	input_X.insert(input_X.begin(), up, pad_x);
	input_X.insert(input_X.end(), down, pad_x);
	
	return input_X;
}

void print_vector_2D(vector<vector<int>>vector) {
	if (vector.empty())return;
	int len_row = vector.size();
	int len_col = vector[0].size();
	for (int i = 0; i < len_row; i++)
	{
		for (int j = 0; j < len_col; j++)
		{
			cout << vector[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	vector<vector<int>>input_X = {
	{0,1,0,5,7,0},
	{0,1,0,5,7,0},
	{0,1,0,5,7,0},
	{0,1,0,5,7,0},
	{0,1,0,5,7,0}};
	//{1,2,3,4,5},
	//{6,7,8,9,0},
	//{0,9,8,7,6},
	//{3,4,5,6,7},
	//{2,9,3,8,5} };
	vector<vector<int>>core = {
	{0,1,0},
	{0,1,0},
	{0,1,0}};
	//{1,2,3,1},
	//{1,2,3,1},
	//{6,7,8,2},
	//{2,9,3,1} };
	vector<vector<int>>feature_map;
	cout << "打印二维图与卷积核" << endl;
	print_vector_2D(input_X);
	print_vector_2D(core);
	cout << "打印pading后的图" << endl;
	vector<vector<int>>pad_input_X = pad(input_X, core.size());
	print_vector_2D(pad_input_X);

	cout << "卷积后的特征图" << endl;

	feature_map = cov2(input_X, core);
	print_vector_2D(feature_map);

	feature_map = cov2(pad_input_X, core);
	print_vector_2D(feature_map);

	return 0;

}

