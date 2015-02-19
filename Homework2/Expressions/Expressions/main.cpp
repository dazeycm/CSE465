#include <iostream>
#include "Expression.h"
using namespace std;

int main()	{

	Expression exp("(((x)+(4))-((3)*(7)))");
	cout << exp.toString() << endl;
	cout << exp.evaluate(3) << endl;
	exp.mutate();
	exp.mutate();
	exp.mutate();
	exp.mutate();
	cout << exp.evaluate(3) << endl;

	return 0;
}