#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> nums;

	for (int i = 0; i < 50000; i++)	{
		nums.push_back(i);
	}

	for (int i = 0; i < nums.size(); i++)	{
		cout << nums.at(i) << endl;
	}
}