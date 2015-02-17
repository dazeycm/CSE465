#include "Expression.h"
#define null 0

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

void Expression::clear(Node* node)	{
	if (node)	{
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
	if (node->left != null)
		heightLeft = getHeightFromNode(node->left);
	if (node->right != null)
		heightRight = getHeightFromNode(node->right);
	if (heightLeft > heightRight){
		return heightLeft + 1;
	}
	else{
		return heightRight + 1;
	}
}
