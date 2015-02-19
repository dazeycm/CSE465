#include <iostream>
#include "Expression.h"
#include "vld.h"
using namespace std;

int main()	{
	srand(time(0));
	Expression exp;
	cout << "Ctor: " << exp.toString() << endl;

	Expression exp1("((((x)-(3))+((4)^(2)))^(((7)*(x))*((x)-(3))))");
	cout << "String Ctor: " <<exp1.toString() << endl;

	Expression exp2(exp1.toString());
	cout << "Copy Ctor: " << exp2.toString() << endl;

	Expression exp3 = Expression::randomExpression(2);
	Expression exp4 = Expression::randomExpression(3);
	cout << "To String & Random Expression: " << exp3.toString() << endl;
	cout << "Height of Tree: " <<exp3.getHeight() << endl;
	cout << "To String & Random Expression: " << exp4.toString() << endl;
	cout << "Height of Tree: " << exp4.getHeight() << endl;
	
	exp3 = exp2;
	cout << "Assignment operator" << exp3.toString() << endl;

	cout << "Evaluation: " << exp3.evaluate(4) << endl;
	exp3.mutate();
	cout << "Evaluation after mutation: " << exp3.evaluate(4) << endl;
	exp3.mutate();
	cout << "Evaluation after mutation: " << exp3.evaluate(4) << endl;
	exp3.mutate();
	cout << "Evaluation after mutation: " << exp3.evaluate(4) << endl;
	cout << "Evaluation with diff x value: " << exp3.evaluate(2) << endl;

	return 0;
}