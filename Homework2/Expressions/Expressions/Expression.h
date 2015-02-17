#include <iostream>
#include <string>
using namespace std;

struct Node		{
	Node* left;
	Node* right;
	char op;
	bool isVar;
	int value;
};

class Expression	{
public:
	Expression();				// expression equal to the number 0
	Expression(string str);			// create expression from parenthesized expr
	Expression(const Expression &other);// copy ctor
	~Expression();				// destructor
	void clear(Node* node);
	Expression &operator = (const Expression &other);// assignment operator
	double evaluate(double x) const;
	static Expression randomExpression(int height);
	string toString() const;
	void mutate();
	int getHeight() const;
	int getHeightFromNode(Node* node) const;
private:
	Node *root;
};