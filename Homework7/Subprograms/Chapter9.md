## Problem Set

### 1.
I think there are both positive and negative aspects to operator overloading. On one side, it's much easier to say ```factor1 + factor2``` than ```factor1.add(factor2)```. This helps from a write-ability standpoint. However, I think it seriously harms how understandable the code is. This is because a lot is left ambiguous. It's not immediately known if the operator is overloaded in the correct way, and there is really no context, so what is actually happening can be disguised.  

### 15.
1. Pass-by-name adds significant complexity that lowers the readability and write-ability.  
2. Pass-by-name parameters are overly complex to implement and inefficient. 
