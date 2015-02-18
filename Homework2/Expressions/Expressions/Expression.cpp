#include "Expression.h"

Expression::Expression()	{
	root = new Node();
	root->value = 0;
}

Expression::Expression(string str)	{
	str = stripParens(str);
	cout << str << std::endl;

	std::vector<std::string> parts = getLeftAndRight(str);

	cout << findIndexMiddleExp(str) << endl;
	cout << getMiddleExp(str) << endl;
	cout << parts.at(0) << endl;
	cout << parts.at(1) << endl;

	root = parseStatement(str);
}

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
		newValNode->isVar = NULL;
		char c = getMiddleExp(str);
		newValNode->value = c - '0';
		newValNode->left = NULL;
		newValNode->right = NULL;
		return newValNode;
	}
	
}

bool Expression::isInteger(const string & s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

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

Expression::Expression(const Expression &other)	{
	//clear(root);
	root = copyHelper(other.root);
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
	newnode->left = copyHelper(other->right);
	return newnode;
}

void Expression::clear(Node* node)	{
	if (node != NULL)	{
		if (node->left) clear(node->left);
		if (node->right) clear(node->right);
		delete node;
	}
}

Expression &Expression::operator = (const Expression &other)	{
	if (this != &other)	{
		clear(root);
		root = copyHelper(other.root);
	}
	return *this;
}

Expression::~Expression()	{
	clear(root);
}

int Expression::getHeight() const	{
	return getHeightFromNode(root) - 1;	//don't include the root node
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
