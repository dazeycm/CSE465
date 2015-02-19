#include <iostream>
#include "Expression.h"
using namespace std;

int main()	{

	//Expression exp("((((x)-(3))+((4)^(2)))^(((7)*(x))*((x)-(3))))");
	//cout << exp.toString() << endl;
	//cout << exp.evaluate(3) << endl;
	//exp.mutate();
	//exp.mutate();
	//exp.mutate();
	//exp.mutate();
	//cout << exp.evaluate(3) << endl;
	Expression::randomExpression(3);

	//Expression exp1;
	//Expression exp2 = exp1;

	return 0;
}