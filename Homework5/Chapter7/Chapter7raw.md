## Problem Set
### 9.
a.) (((a*b)<sup>1</sup>-1)<sup>2</sup>>>+c)<sup>3</sup>  

b.) (((a*(b-1)<sup>1</sup>)<sup>2</sup>/c)<sup>3</sup>mod d)<sup>4</sup>  

Assuming this is like regular math where you do the stuff in parentheses first. <br>
c.) (((a-b)<sup>1</sup>/c)<sup>2</sup>&(((d*e)<sup>3</sup>/a)<sup>4</sup>-3)<sup>5</sup>)<sup>6</sup>

d.)
((-a)<sup>1</sup>or ((c=d)<sup>2</sup>and e)<sup>3</sup>)<sup>4</sup>

e.) (((a>b)<sup>1</sup> xor c)<sup>3</sup> or (d<=17)<sup>2</sup>)<sup>4</sup>

f.) (-(a+b)<sup>1</sup>)<sup>2</sup>


### 18.
I would argue that an optimizing compiler should not be able to change the order of expressions in a boolean expression. This is because in C and C++ there is something called short circuiting which means if the first part of an && equals to false or the first part of || equals True then the second half of the expression is never evaluated. With this in mind, a programmer could put something in the second half which could crash the program if it's evaluated even though it should have stopped after the first half.  
