/*   Expression tree form postfix expression */

Node* BuildExprTree(vector<char> postfix_expr, int size) {
    stach<char> S;
    Node *node;
    for(int i=0; i<postfix_expr.size(); i++){
        if (postfix_expr[i] is operand) {
            node = new Node;
            node->data = postfix_expr[i];
            node->left = NULL; node->right = NULL:
            S.push(node);
        } else {   //operator
            Node *op1 = S.top(); S.pop();
            Node *op2 = S.top(); S.pop();
            Node *tmp = new Node;
            tmp->data = postfix_expr[i];
            tmp->left = op1; tmp->right = op2;
            S.push(tmp);
        }
        
    }
}