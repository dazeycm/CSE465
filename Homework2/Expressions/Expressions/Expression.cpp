#include "Expression.h"

Expression::Expression()	{
	root = new Node();
	root->value = 0;
}

Expression::Expression(string str)	{
	str = stripParens(str);
	root = parseStatement(str);
}

Node* Expression::parseStatement(string str)	{
	if (getMiddleExp(str) == '+' || getMiddleExp(str) == '-' || getMiddleExp(str) == '*' || getMiddleExp(str) == '^')	{
		vector<string> parts = getLeftAndRight(str);
		Node* newOpNode = new Node();
		newOpNode->op = getMiddleExp(str);
		newOpNode->isVar = false;
		newOpNode->value = NULL;
		//cout << "String: " << str << endl;
		//cout << "Middle Expression: " << getMiddleExp(str) << endl;
		//cout << "Left Part: " << stripParens(parts[0]) << endl;
		//cout << "Right Part: " << stripParens(parts[1]) << endl;
		newOpNode->left = parseStatement(stripParens(parts[0]));
		newOpNode->right = parseStatement(stripParens(parts[1]));
		cout << "Creating newOpNode" << endl;
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
		cout << "Creating newValNode" << endl;
		return newValNode;
	}
	if (getMiddleExp(str) == 'x')	{
		Node* newVarNode = new Node();
		newVarNode->op = getMiddleExp(str);
		newVarNode->isVar = true;
		newVarNode->value = 99;
		newVarNode->left = NULL;
		newVarNode->right = NULL;
		cout << "Creating newVarNode" << endl;
		return newVarNode;
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
	newnode->right = copyHelper(other->right);
	return newnode;
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

void Expression::clear(Node* node)	{
	if (node != NULL)	{
		if (node->left != NULL) clear(node->left);
		if (node->right != NULL) clear(node->right);
		if (node->right == NULL && node->left == NULL)	{
			if (node != root)	{
				delete node;
				node = nullptr;
			}
			else{
				root = NULL;
			}
		}
	}
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
