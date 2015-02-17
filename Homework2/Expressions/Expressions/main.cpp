#include <iostream>
#include "Expression.h"
using namespace std;

int main()	{
	Expression exp;
	cout << exp.getHeight() << endl;
	Expression exp2(exp);
	cout << exp2.getHeight() << endl;
	
	return 0;
}