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
	Expression();										//done
	Expression(string str);						
	Expression(const Expression &other);				//done
	Node* copyHelper(const Node *node);					//done
	~Expression();										//done
	void clear(Node* node);								//done
	Expression &operator = (const Expression &other);	//done
	double evaluate(double x) const;
	static Expression randomExpression(int height);
	string toString() const;
	void mutate();
	int getHeight() const;								//done
	int getHeightFromNode(Node* other) const;			//done
private:
	Node *root;
};