#include <iostream>
#include "Expression.h"
using namespace std;

int main()	{

	Expression exp("((3+x)+7)");
	cout << exp.evaluate(3);
	Expression exp2 = exp;

	return 0;
}