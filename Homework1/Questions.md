#Question 2
###A) *How many points will be deducted if your first homework assignment is submitted exactly 24 hours late?*
21.6 points

###B) *What date will the class’ second mid-term exam be held?*
There isn't a second midterm exam

###C) *Does the class have a grader? If so, what is their name and email address?*
Yes, their name is Yan Yu, and their email address is yuy6@miamioh.edu

#Question 3
###*The Vandelay Language Company is designing a new language based on Java and their language designers have been debating whether their language should allow variable declarations to occur at arbitrary positions in the source code. If they disallow this feature, all variable declarations will need to occur at the top of the function definition. You have been hired as an expert by to write a one page (at most) report detailing the pros and cons of allowing declarations to occur at arbitrary positions. Your report should address the main evaluation criteria, and sub criteria, defined in the textbook (e.g., readability, writeabilty, reliability, cost, etc). When appropriate, you should provide statements/examples to support your claims. Finally, give a recommendation for the proposal on a scale of 1 to 10, where 1 represents definitely oppose; 5 represents a neutral; and 10 represents definitely support.*

It's important when making design decisions that you take into account many factors. The first is the readability of your source code. I would make the argument that this design decision would have almost no effect on the readability of code. Where we declare the variable doesn't matter much, as the only difference between declaration and use is the addition of the type of variable. This means that no matter where the variable is declared, the name is really what matters. You could make the argument that if you didn't know the type of the variable having everything declared at the top of the function would make it easy to find. However, most of the time this won't be a problem for a competent programmer.

In terms of writeability, I think that allowing arbitrary positions would mean an increase in writeability. To be more specific, this feature would allow code to be more expressive. In java, variables that are defined in a certain scope are only defined in that scope, and it's children's scopes. If all functions were defined at the top of a function, then in a sense, all variables would be global for that function. The following for example is legal in java, where variables can be arbitrarily declared:
```java
public static int f(int x)  {
  for(int i = 0; i <= 5; i++) {
    int cost = 5;
  }
  int cost = 1;
}
```
If variables could not be declared arbitrarily, the ```cost``` variable could only be used once. There is the argument that this could be considered bad practice, but the feature allows the language to be more expressive, increasing the writeability of the code.

The reliability of a program depends partly on its readability and writeability. Because of this, I believe that arbitrary variable declaration improves reliability. For example, if variables had to be declared at the top of the function, if a programmer wanted a variable only in a local scope, like inside of a ```for``` loop, they would need to have a work-around such as different capitalization. The problem with these work-arounds is that they're more likely to be incorrect in some situations, and could lead to errors.

Lastly, in terms of cost, there's no real difference between the two implementations.  However, one pro for the arbitrary declaration method, although a very small pro, is that the other implementation seemingly allows variables to be declared in the initialization of ```for``` loops such as - ```for(int i = 0; i <= 5; i++)```. I believe this could be confusing and affect the cost training in this type of languages since variables should have to be declared at the top of the method. Because of the inconsistency, the arbitrary method would be better as to make training easier, take less time, and cost less. Additionally, most languages currently allow for arbitrary declaration of videos, meaning most the cost of training for these people would be drastically lower and probably even non existent as they're used to doing it.

Overall, I would rate this proposal an 8. I think that the benefits of the arbitrary method, along with the cons of the other method mean that arbitrary declaration of variables would be a great feature to add to the language that the Vandelay Language Company is developing. 
