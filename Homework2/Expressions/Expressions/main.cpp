#include <iostream>
#include "Expression.h"
using namespace std;

int main()	{

	Expression exp("((((x)-(3))+((4)^(2)))^(((7)*(x))*((x)-(3))))");
	Expression exp2 = exp;

	return 0;
}