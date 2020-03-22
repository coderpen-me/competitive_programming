int Solution::solve(TreeNode* A, int B) {
    vector<TreeNode *> v;
    stack<TreeNode *> s;
    //int ret = helper(A, B, v);
    TreeNode *root = A;
    int count = 0;
    //map<int, pair<int, int>> m; 
    while(root != NULL || s.empty() == false){
        //if(root != NULL) cout<<"start "<<root->val<<"   ";
        while (root !=  NULL) 
        {
            //cout<<"pushing "<<root->val<<" ";
            for(int i=0; i<v.size(); i++)
                if( abs(v[i]->val - root->val) <= B )
                    count++/*, cout<<" count incr "*/;
            v.push_back(root);
            s.push(root);
            //m[root->val].first++;
            //m[root->val].second++;
            root = root->left; 
        }
        root = s.top();
        s.pop();
        //break;
        //cout<<"popstack "<<root->val<<" ";
        root = root->right;
        if(root == NULL){
            if(s.empty() == true)
                continue;
            while(v[v.size()-1] != s.top())
                /*cout<<"removing "<<v[v.size()-1]->val<<" ", */v.pop_back();
        }
        //cout<<"Remain v ";
        /*for(auto x : v){
            cout<<x->val<<" ";
        }*/
    }
    return count;
}