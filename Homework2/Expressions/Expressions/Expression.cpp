#include "Expression.h"

Expression::Expression()	{
	root = new Node();
	root->op = '+';
	root->left = new Node();
	root->right = new Node();
	root->left->isVar = true;
	root->right->isVar = true;
	root->left->value = 0;
	root->right->value = 0;
}

Expression::Expression(string str)	{
	str = stripParens(str);
	cout << str << std::endl;

	std::vector<std::string> parts = getLeftAndRight(str);

	cout << findIndexMiddleExp(str) << endl;
	cout << getMiddleExp(str) << endl;
	cout << parts.at(0) << endl;
	cout << parts.at(1) << endl;

	//root = parseStatement(str);
}

Node* Expression::parseStatement(string str)	{
	return NULL;
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
				return i+1;
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
	str.erase(0, 1);  // trim right
	str.erase(str.length() - 1);  // trim left
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
	return getHeightFromNode(root);
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
