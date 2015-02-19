#include <iostream>
#include "Expression.h"
using namespace std;

int main()	{

	Expression exp("((3+1)^x)");
	cout << exp.evaluate(3);
	exp.mutate();
	cout << exp.evaluate(3);

	return 0;
}