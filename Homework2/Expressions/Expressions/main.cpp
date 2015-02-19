#include <iostream>
#include "Expression.h"
using namespace std;

int main()	{

	Expression exp("(((3)*(4))+(7))");
	cout << exp.toString() << endl;
	cout << exp.evaluate(3) << endl;
	exp.mutate();
	exp.mutate();
	exp.mutate();
	exp.mutate();
	cout << exp.evaluate(3) << endl;

	return 0;
}