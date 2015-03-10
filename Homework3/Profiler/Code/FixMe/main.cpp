#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*	OLD FIND
int findNum(vector<int> w, int x)	{
	if(w.at(0) == x)
		return 1;
	else
	{
		w.erase(w.begin());
		findNum(w, x);
	}
}
*/

int findNum(vector<int> w, int x)	{
	for(int i = 0; i < w.size(); i++)	{
		if(w.at(i) == x)
			return 1;
	}
}

/*	OLD SORT
vector<int> sort(vector<int> w) {
    int temp;
    bool finished = false;
    while (!finished)    {
       finished = true;
       for (int i = 0; i < w.size()-1; i++) {
          if (w[i] > w[i+1]) {
             temp = w[i];
             w[i] = w[i+1];
             w[i+1] = temp;
             finished = false;
          }
        }
     }
    return w; 
}
*/

vector<int> mysort(vector<int> w) {
    sort(w.begin(), w.end());
	return w;
}

int main()
{
	vector<int> nums;

	for (int i = 0; i <	10000; i++)	{
		nums.push_back(rand() % 100);
	}
	nums.push_back(97);

	vector<int> sortednums = mysort(nums);
	int x = findNum(sortednums, 97);
	for(int i : sortednums)
		cout << i << endl;
	cout << sortednums.size() << endl;
	cout << x << endl;
}