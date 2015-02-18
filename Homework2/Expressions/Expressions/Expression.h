#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node		{
	Node* left;
	Node* right;
	char op;
	bool isVar;
	int value;
	~Node();
};

class Expression	{
public:
	Expression();										//done
	Expression(string str);								//done
	Expression(const Expression &other);				//done
	Expression &operator = (const Expression &other);	//done
	~Expression();										//done
	double evaluate(double x) const;					//done
	static Expression randomExpression(int height);
	string toString() const;
	void mutate();
	int getHeight() const;								//done
private:
	Node *root;
	Node* parseStatement(string str);					//done
	bool isInteger(const string & s);					//done
	int findIndexMiddleExp(string str);					//done
	char getMiddleExp(string str);						//done
	vector<string> getLeftAndRight(string str);			//done
	string stripParens(string str);						//done
	Node* copyHelper(const Node *node);					//done
	int getHeightFromNode(Node* other) const;			//done
	double evaluateFromNode(Node* node, double x) const;
};