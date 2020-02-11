// C++ Program for Lowest Common Ancestor in a Binary Tree
// A O(n) solution to find LCA of two given values n1 and n2
#include <bits/stdc++.h>

using namespace std;

// A Binary Tree node
struct Node
{
    int key;
    struct Node *left, *right;
};

// Utility function creates a new binary tree node with given key
Node *newNode(int k)
{
    Node *temp = new Node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}

// Finds the path from root node to given node of the tree, Stores the
// path in a vector path[], returns true if path exists otherwise false
bool findPath(Node *root, vector<int> &path, int k)
{
    /*
    // base case 
    if (root == NULL) return false; 

    // Store this node in path vector. The node will be removed if 
    // not in path from root to k 
    path.push_back(root->key); 

    // See if the k is same as root's key 
    if (root->key == k) 
    return true; 

    // Check if k is found in left or right sub-tree 
    if ( (root->left && findPath(root->left, path, k)) || 
    (root->right && findPath(root->right, path, k)) ) 
    return true; 

    // If not present in subtree rooted with root, remove root from 
    // path[] and return false 
    path.pop_back(); 
    return false; 
    */
    if (root == NULL)
        return false;
    path.push_back(root->key);
    if (root->key == k)
        return true;
    if ((root->left && findPath(root->left, path, k)) ||
        (root->right && findPath(root->right, path, k)))
        return true;
    path.pop_back();
    return false;
}

// Returns LCA if node n1, n2 are present in the given binary tree,
// otherwise return -1
int findLCA(Node *root, int n1, int n2)
{
    /*// to store paths to n1 and n2 from the root 
	vector<int> path1, path2; 

	// Find paths from root to n1 and root to n1. If either n1 or n2 
	// is not present, return -1 
	if ( !findPath(root, path1, n1) || !findPath(root, path2, n2)) 
		return -1; 

	// Compare the paths to get the first different value
	int i; 
	for (i = 0; i < path1.size() && i < path2.size() ; i++) 
		if (path1[i] != path2[i]) 
			break; 
	return path1[i-1]; */
    vector<int> v1, v2;
    if (!findPath(root, v1, n1) || !findPath(root, v2, n2))
    {
        return -1;
    }
    int i;
    for (int i = 0; i < v1.size() && i < v2.size(); i++)
    {
        if (v1[i] != v2[i])
        {
            break;
        }
    }
    return v1[i - 1];
}

// Driver program to test above functions
int main()
{
    // Let us create the Binary Tree shown in above diagram.
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
    cout << "nLCA(4, 6) = " << findLCA(root, 4, 6);
    cout << "nLCA(3, 4) = " << findLCA(root, 3, 4);
    cout << "nLCA(2, 4) = " << findLCA(root, 2, 4);
    return 0;
}
