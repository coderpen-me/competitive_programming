void inorder(Node* root)
{
  if(root == NULL) return;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

void inorder(Node* root)
{
  stack<Node*> s;
  while(root != NULL || !s.empty()){
      while(root != NULL){
          s.push(root);
          root = root->left;
      }
      Node* tmp = s.top();
      s.pop();
      root = tmp->right;
      cout<<tmp->data<<" ";
  }
}