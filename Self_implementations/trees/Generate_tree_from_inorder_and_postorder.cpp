/* C++ program to construct tree using inorder and 
postorder traversals */
#include <bits/stdc++.h> 

using namespace std; 

/* A binary tree node has data, pointer to left 
child and a pointer to right child */
struct Node { 
	int data; 
	Node *left, *right; 
}; 

// Utility function to create a new node 
Node* newNode(int data); 

/* Helper function that allocates a new node */
Node* newNode(int data) 
{ 
	Node* node = (Node*)malloc(sizeof(Node)); 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 

/* This funtcion is here just to test */
void preOrder(Node* node) 
{ 
	if (node == NULL) 
		return; 
	printf("%d ", node->data); 
	preOrder(node->left); 
	preOrder(node->right); 
} 

int search(int A[], int l, int r, int data){
    int i;
    for(i = l; i <= r; i++){
        if(A[i] == data) break;
    }
    return i;
}
Node* make(int A[], int B[], int l, int r, int *ptr){
    //cout<<*ptr<<" ";
    if(l > r) return NULL;
    Node *node = newNode(B[(*ptr)--]);
    if(l == r){
        return node;
    }
    int ind = search(A, l, r, node->data);
    node->right = make(A, B, ind+1, r, ptr);
    node->left = make(A, B, l, ind-1, ptr);
    return node;
}
// Driver code 
int main() 
{ 
	int in[] = { 2, 1, 3 }; 
	int post[] = { 2, 3, 1 }; 
	int n = sizeof(in) / sizeof(in[0]); 
    int s = n-1;
	Node* root = make(in, post, 0, n-1, &s); 

	cout << "Preorder of the constructed tree : \n"; 
	preOrder(root); 

	return 0; 
} 
