#include <iostream>
#include "Expression.h"
using namespace std;

int main()	{
	srand(time(0));
	//Expression exp("((((x)-(3))+((4)^(2)))^(((7)*(x))*((x)-(3))))");

	//cout << exp.toString() << endl;
	//cout << exp.toString() << endl;
	
	Expression exp1 = Expression::randomExpression(2);
	cout << exp1.toString() << endl;

	return 0;
}