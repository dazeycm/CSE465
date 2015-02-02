#Question 2
###A) How many points will be deducted if your first homework assignment is submitted exactly 24 hours late?
21.6 points

###B) What date will the class’ second mid-term exam be held?
There isn't a second midterm exam

###C) Does the class have a grader? If so, what is their name and email address?
Yes, their name is Yan Yu, and their email address is yuy6@miamioh.edu

#Question 3
The Vandelay Language Company is designing a new language based on Java and their language designers have been debating whether their language should allow variable declarations to occur at arbitrary positions in the source code. If they disallow this feature, all variable declarations will need to occur at the top of the function definition. You have been hired as an expert by to write a one page (at most) report detailing the pros and cons of allowing declarations to occur at arbitrary positions. Your report should address the main evaluation criteria, and sub criteria, defined in the textbook (e.g., readability, writeabilty, reliability, cost, etc). When appropriate, you should provide statements/examples to support your claims. Finally, give a recommendation for the proposal on a scale of 1 to 10, where 1 represents definitely oppose; 5 represents a neutral; and 10 represents definitely support.

It's important when making design decisions that you take into account many factors. The first is the readability of your source code. I would make the argument that this design decision would have almost no effect on the readability of code. Where we declare the variable doesn't matter much, as the only difference between declaration and use is the addition of the type of variable. This means that no matter where the variable is declared, the name is really what matters. You could make the argument that if you didn't know the type of the variable having everything declared at the top of the function would make it easy to find. However, most of the time this won't be a problem for a competent programmer.   

In terms of writeability, I think that allowing arbitrary positions would mean an increase in writeability. To be more specific, this feature would allow code to be more expressive. In java, variables that are defined in a certain scope are only defined in that scope, and scopes inside of that scope. If all functions were defined at the top of a function, then in a sense, all variables would be global for that function.
