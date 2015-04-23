## Problem Set:

### 2a.
    <class_definition> ::= [public] [(abstract|final)] <name> [extends <name>] [implements <id>{, <id>}}]
    <id> ::= [A-Za-z0-9_]+

### 6a.
    <assign> -> <id> = <expr>
                  A  = <expr>
                  A  = <id> * <expr>
                  A  = A * <expr>
                  A  = A * (<expr>)
                  A  = A * (<id> + <expr>)
                  A  = A * (B + <expr>)
                  A  = A * (B + (<expr>))
                  A  = A * (B + (<id> * <expr))
                  A  = A * (B + (C * <expr>))
                  A  = A * (B + (C * <id>))
                  A  = A * (B + (C * A))

![ParseTree6a](parseTree.jpg)

### 7c-d.

c. ![ParseTree7c](paseTree2.jpg)

d. A = B * (C * (A + B))


### 11c-d.
C - NO
D - YES
