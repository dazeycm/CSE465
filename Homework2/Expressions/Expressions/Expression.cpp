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
