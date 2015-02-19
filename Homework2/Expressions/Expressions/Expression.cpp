#include "Expression.h"

Expression::Expression()	{
	root = new Node();
	root->value = 0;
	root->left = NULL;
	root->right = NULL;
}

Expression::Expression(string str)	{
	str = stripParens(str);
	root = parseStatement(str);
}

Expression::Expression(const Expression &other)	{
	root = copyHelper(other.root);
}

Expression &Expression::operator = (const Expression &other)	{
	if (this != &other)	{
		delete root;
		root = copyHelper(other.root);
	}
	return *this;
}

Expression::~Expression()	{
	delete root;
}

Node::~Node()	{
	delete left;
	delete right;
	left = nullptr;
	right = nullptr;
}

double Expression::evaluate(double x) const	{
	return evaluateFromNode(root, x);
}

Expression Expression::randomExpression(int height)	{
	srand(time(NULL));
	Expression exp;
	exp.root = new Node();
	exp.root->isVar = false;
	exp.root->value = NULL;
	int chance = rand() % 4;
	switch (chance)	{
		case 0:
			exp.root->op = '+';
		case 1:
			exp.root->op = '-';
		case 2:
			exp.root->op = '*';
		case 3:
			exp.root->op = '^';
	}

	Node* node = exp.root;
	int count = 0;
	while (true)	{
		node->left = addRandomNode(node);
		node->right = addRandomNode(node);
	}

	exp.root->op = '+';
	exp.root->isVar = NULL;
	exp.root->value = NULL;
	exp.root->left = NULL;
	exp.root->right = NULL;
	return exp;
}

string Expression::toString() const	{
	string ret = "";
	string str = getStringSubTree(root, ret);
	return str;
}

void Expression::mutate()	{
	Node* node = root;
	srand(time(NULL));

	while (true)	{
		int nodeCount = subTreeNodeCount(node);
		int val = rand() % nodeCount;
		if (val == 0)	{
			changeNode(node);
			break;
		}
		else if (val <= subTreeNodeCount(node->left)){
			node = node->left;
		}
		else{
			node = node->right;
		}
	}
}

int Expression::getHeight() const	{
	return getHeightFromNode(root) - 1;	//don't include the root node
}

//============================HELPER FUNCTIONS============================

Node* Expression::parseStatement(string str)	{
	if (getMiddleExp(str) == '+' || getMiddleExp(str) == '-' || getMiddleExp(str) == '*' || getMiddleExp(str) == '^')	{
		vector<string> parts = getLeftAndRight(str);
		Node* newOpNode = new Node();
		newOpNode->op = getMiddleExp(str);
		newOpNode->isVar = false;
		newOpNode->value = NULL;
		newOpNode->left = parseStatement(stripParens(parts[0]));
		newOpNode->right = parseStatement(stripParens(parts[1]));
		return newOpNode;
	}
	if (isdigit(getMiddleExp(str)))	{
		Node* newValNode = new Node();
		newValNode->op = NULL;
		newValNode->isVar = false;
		char c = getMiddleExp(str);
		newValNode->value = c - '0';
		newValNode->left = NULL;
		newValNode->right = NULL;
		return newValNode;
	}
	if (getMiddleExp(str) == 'x')	{
		Node* newVarNode = new Node();
		newVarNode->op = NULL;
		newVarNode->isVar = true;
		newVarNode->value = NULL;
		newVarNode->left = NULL;
		newVarNode->right = NULL;
		return newVarNode;
	}
}

int Expression::convertToInt(string str) const	{
	std::istringstream converter(str);
	int ret;
	converter >> ret;
	return ret;
}

bool Expression::isInteger(const string & s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
		return false;
	char* p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}

int Expression::findIndexMiddleExp(string str)	{
	int left = 0;
	int right = 0;

	if (str.find('(') == -1)	{
		return str.size() / 2;
	}

	for (int i = 0; i < str.size(); i++)	{
		if (str[i] == '(')	{
			left += 1;
		}
		if (str[i] == ')')	{
			right += 1;
		}
		if (left == right)	{
			if (i != str.size() - 1)	{
				return i + 1;
			}
			else	{
				return i / 2;
			}
		}
	}
}

char Expression::getMiddleExp(string str)	{
	int i = findIndexMiddleExp(str);
	return str[i];
}

vector<string> Expression::getLeftAndRight(string str)	{
	std::vector<std::string> parts;
	parts.push_back(str.substr(0, findIndexMiddleExp(str)));
	parts.push_back(str.substr(findIndexMiddleExp(str) + 1, string::npos));
	return parts;
}

string Expression::stripParens(string str)	{
	if (str.find('(') != -1)	{
		str = str.substr(1, str.length() - 2);
		return str;
	}
	return str;
}

Node* Expression::copyHelper(const Node *other)	{
	if (other == NULL)	{
		return NULL;
	}
	
	Node *newnode = new Node();
	newnode->op = other->op;
	newnode->isVar = other->isVar;
	newnode->value = other->value;
	newnode->left = copyHelper(other->left);
	newnode->right = copyHelper(other->right);
	return newnode;
}

int Expression::getHeightFromNode(Node* node)	const{
	int heightLeft = 0;
	int heightRight = 0;
	if (node->left != NULL)
		heightLeft = getHeightFromNode(node->left);
	if (node->right != NULL)
		heightRight = getHeightFromNode(node->right);
	if (heightLeft > heightRight){
		return heightLeft + 1;
	}
	else{
		return heightRight + 1;
	}
}

double Expression::evaluateFromNode(Node* node, double x) const	{
	if (node->left != NULL && node->right != NULL)	{
		double leftVal = evaluateFromNode(node->left, x);
		double rightVal = evaluateFromNode(node->right, x);
		char op = node->op;
		switch (op)	{
		case '+':
			return leftVal + rightVal;
			break;
		case '-':
			return leftVal - rightVal;
			break;
		case '*':
			return leftVal * rightVal;
			break;
		case '^':
			return pow(leftVal, rightVal);
			break;
		}
		double val = leftVal + rightVal;
		return val;
	}
	else{
		if (node->isVar)
			return x;
		else
			return node->value;
	}
}

Node* Expression::addRandomNode(Node* node){
	if (node->op == NULL)	{
		return NULL;
	}
}

void Expression::changeNode(Node* node)	{
	srand(time(NULL));
	if (node->isVar != NULL)	{
		node->isVar = false;
		node->value = rand() % 10;
	}
	else if (node->op != NULL){
		int chance = rand() % 4;
		switch (chance)	{
		case 0:
			node->op = '+';
		case 1:
			node->op = '-';
		case 2:
			node->op = '*';
		case 3:
			node->op = '^';
		}
	}
	else{
		int chance = rand() % 10;
		node->value = chance;
	}
}

int Expression::subTreeNodeCount(Node* node)	{
	if (node == NULL)	{
		return 0;
	}
	else {
		return 1 + subTreeNodeCount(node->left) + subTreeNodeCount(node->right);
	}
}

string Expression::getStringSubTree(Node* node, string str)	const{
		if (node->op == NULL)	{
			return nodeToString(node);
		}
		else {
			string temp = "";
			temp += "(";
			temp += getStringSubTree(node->left, str);
			temp += node->op;
			temp += getStringSubTree(node->right, str);
			temp += ")";
			return temp;
		}
}

string Expression::nodeToString(Node* node)	const{
	string str = "";
	if (node->value != NULL)	{
		str += "(";
		char c = node->value + '0';
		str += c;
		str += ")";
	}
	else if (node->isVar){
		str += "(";
		str += "x";
		str += ")";
	}

	return str;
}


