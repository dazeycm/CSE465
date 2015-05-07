using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <math.h>

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
	Expression();										
	Expression(string str);
	Expression(const Expression &other);
	Expression &operator = (const Expression &other);
	~Expression();
	double evaluate(double x, bool y) const;
	static Expression randomExpression(int height);
	string toString() const;
	void mutate();
	int getHeight() const;
private:
	Node *root;
	Node* parseStatement(string str);
	int convertToInt(string str) const;
	bool isInteger(const string & s);
	int findIndexMiddleExp(string str);
	char getMiddleExp(string str);
	vector<string> getLeftAndRight(string str);
	string stripParens(string str);
	Node* copyHelper(const Node *node);
	int getHeightFromNode(Node* other) const;
	double evaluateFromNode(Node* node, double x, bool y) const;
	static Node* addRandomNode(Node* root, int count, int height);
	void changeNode(Node* node);
	int subTreeNodeCount(Node* node);
	string getStringSubTree(Node* node, string str) const;
	string nodeToString(Node* node) const;
};
