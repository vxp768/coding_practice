/*
 * Expression tree evaluation and construction
 */
 
 //Postfix to expression tree
 
 // Returns root of constructed tree for given 
// postfix expression 
et* constructTree(char postfix[]) 
{ 
    stack<et *> st; 
    et *t; 
  
    // Traverse through every character of 
    // input expression 
    for (int i=0; i<strlen(postfix); i++) 
    { 
        // If operand, simply push into stack 
        if (!isOperator(postfix[i])) 
        { 
            t = newNode(postfix[i]); 
            st.push(t); 
        } 
        else // operator 
        { 
            t = newNode(postfix[i]); 
  
            // Pop two top nodes 
            t->right = st.top(); 
            st.pop();      
            t->left = st.top(); 
            st.pop(); 
  
            // Add this subexpression to stack 
            st.push(t); 
        } 
    } 
    //  only element will be root of expression tree 
    t = st.top(); 
    st.pop(); 
    return t; 
}

// EVALUATE expression tree
// This function receives a node of the syntax tree  
// and recursively evaluates it  
int eval(node* root)  
{  
    // empty tree  
    if (!root)  
        return 0;  
  
    // leaf node i.e, an integer  
    if (!root->left && !root->right)  
        return toInt(root->info);  
  
    // Evaluate left subtree  
    int l_val = eval(root->left);  
  
    // Evaluate right subtree  
    int r_val = eval(root->right);  
  
    // Check which operator to apply  
    if (root->info=="+")  
        return l_val+r_val;  
  
    if (root->info=="-")  
        return l_val-r_val;  
  
    if (root->info=="*")  
        return l_val*r_val;  
  
    return l_val/r_val;  
}
int toInt(string s)  
{  
    int num = 0;  
        
      // Check if the integral value is  
      // negative or not 
      // If it is not negative, generate the number  
      // normally 
      if(s[0]!='-') 
        for (int i=0; i<s.length(); i++)  
            num = num*10 + (int(s[i])-48);  
    // If it is negative, calculate the +ve number 
    // first ignoring the sign and invert the  
    // sign at the end 
      else
        for (int i=1; i<s.length(); i++)  
        { 
            num = num*10 + (int(s[i])-48);  
            num = num*-1; 
        } 
      
    return num;  
}