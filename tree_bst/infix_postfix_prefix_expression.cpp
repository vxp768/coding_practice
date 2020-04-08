/*
    Infix:    A+B       A+(B*C)
    Prefix:   +AB       +A*BC
    Postfix:  AB+       ABC*+
Only infix notation requires the additional symbols...parantheses
The order of operations within prefix and postfix expressions is completely 
determined by the position of the operator and nothing else.
In many ways, this makes infix the least desirable notation to use.

Consider the below expression: a op1 b op2 c op3 d
If op1 = +, op2 = *, op3 = +

The compiler first scans the expression to evaluate the expression b * c, then again scan the expression to add a to it.
The result is then added to d after another scan.
The repeated scanning makes it very in-efficient. It is better to convert the expression to postfix(or prefix) form before evaluation.
*/

// INFIX to POSTFIX
https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/


// INFIX to PREFIX
The idea is to use one stack for storing operators and other to store operands. The stepwise algo is:

1. Traverse the infix expression and check if given character is an operator or an operand.
2. If it is an operand, then push it into operand stack.
3. If it is an operator, then check if priority of current operator is greater than 
   or less than or equal to the operator at top of the stack. If priority is greater, 
   then push operator into operator stack. Otherwise pop two operands from operand stack,
   pop operator from operator stack and push string operator + operand1 + operand 2 into operand stack.
   Keep popping from both stacks and pushing result into operand stack until priority
   of current operator is less than or equal to operator at top of the operator stack.
4. If current character is ‘(‘, then push it into operator stack.
5. If current character is ‘)’, then check if top of operator stack is opening bracket or not. 
   If not pop two operands from operand stack, pop operator from operator stack and 
   push string operator + operand1 + operand 2 into operand stack. Keep popping from both stacks and 
   pushing result into operand stack until top of operator stack is an opening bracket.
6. The final prefix expression is present at top of operand stack.


// Algorithm for Prefix to Infix:

1 Read the Prefix expression in reverse order (from right to left)
2 If the symbol is an operand, then push it onto the Stack
3 If the symbol is an operator, then pop two operands from the Stack
     Create a string by concatenating the two operands and the operator between them.
     string = (operand1 + operator + operand2)
     And push the resultant string back to Stack
4 Repeat the above steps until end of Prefix expression.