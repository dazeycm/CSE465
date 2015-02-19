# Overview - Craig Dazey
Everything in my project *should* work. 

I'm pretty sure I learned more in this assignment than I did in 274. 

## ```Expression()```
Does as it's supposed to. Creates the expression ```(0)```.

## ```Expression(string str)```
Does as it's supposed to. Creates a binary tree using ```str```.

## ```Expression(const Expression &other)```
Works. Deep copes binary tree from ```other```.

## ```~Expression()```
Works. Destructor is called on every node in binary tree.

## ```Expression &operator = (const Expression &other)```
Assignment operator works as it's supposed to.

## ```double evaluate(double x) const```
Correctly evaluates the value of tree given value for variable x.

## ```static Expression randomExpression(int height)```
Creates a balanced random tree. The instructions said to make a "full expression tree" so I took that as meaning balanced. 

## ```string toString() const```
Successfully converts tree to string form. It can be used in the constructor of another expression.

## ```void mutate()```
Randomly mutates a given node in the tree. However, the chance is not evenly distributed for each node.

## ```int getHeight() const```
Does as it's supposed to. Returns the height of the tree. 


