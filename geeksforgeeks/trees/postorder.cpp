void postOrder(Node* root)
{
  if(!root) return;
  stack<Node*> s1, s2;
  s1.push(root);
  while(!s1.empty()){
      Node* tmp = s1.top();
      s1.pop();
      s2.push(tmp);
      if(tmp->left) s1.push(tmp->left);
      if(tmp->right) s1.push(tmp->right);
  }
  while(!s2.empty()){
      cout<<s2.top()->data<<" ";
      s2.pop();
  }
}