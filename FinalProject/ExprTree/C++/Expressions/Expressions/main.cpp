/*
* Craig Dazey
*/

#include <iostream>
#include "Expression.h"
using namespace std;

vector<int> makeBuckets(int trials, int height)	{
	vector<int> buckets(3);
	Expression exp;

	for(int i = 0; i < trials; i++)	{
		exp = Expression::randomExpression(height);
		double result = exp.evaluate(0, true);

		if(result < -25)
			buckets[0] += 1;
		else if(result > 25)
			buckets[2] += 1;
		else
			buckets[1] += 1;
	}

	return buckets;
}

int main()	{
	srand(time(0));
	
	vector<int> buckets = makeBuckets(100000, 3);

	cout << "[-INFINITY, -25): " << buckets[0] << endl;
	cout << "[-25, 25]: " << buckets[1] << endl;
	cout << "(25, INFINITY]: " << buckets[2] << endl;

	return 0;
}