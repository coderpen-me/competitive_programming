#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void preorder(Node* root)
{
  if(!root) return;
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}

void preorder(Node* root)
{
  if(!root) return;
  stack<Node*> s;
  s.push(root);
  while(!s.empty()){
      Node* tmp = s.top();
      cout<<tmp->data<<" ";
      s.pop();
      if(tmp->right) s.push(tmp->right);
      if(tmp->left) s.push(tmp->left);
  }
}