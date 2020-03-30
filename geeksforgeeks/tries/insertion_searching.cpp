#include <bits/stdc++.h>
using namespace std;

struct trieNode{
    struct trieNode *ch[26];
    bool isEnd;
};

struct trieNode* create(){
    struct trieNode *pNode = new trieNode;
    pNode->isEnd = false;
    for(int i = 0; i < 26; i++){
        pNode->ch[i] = NULL;
    }
    return pNode;
}

void insert(struct trieNode* root, string key){
    struct trieNode *cNode = root;
    for(int i = 0; i < key.length(); i++){
        int ind = key[i] - 'a';
        if(!cNode->ch[ind]){
            cNode->ch[ind] = create();
        }
        cNode = cNode->ch[ind];
    }
    cNode->isEnd = true;
}

int search(struct trieNode* root, string key){
    struct trieNode *cNode = root;
    for(int i = 0; i < key.length(); i++){
        int ind = key[i] - 'a';
        if(!cNode->ch[ind]){
            return 0;
        }
        cNode = cNode->ch[ind];
    }
    return (cNode != NULL && cNode->isEnd);
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int len;
	    cin>>len;
	    cin.ignore();
	    string str, word;
	    getline(cin, str);
	    stringstream X(str);
	    struct trieNode *root = create();
	    while(getline(X, word, ' ')){
	        //cout<<"inserting "<<word<<"  ";
	        insert(root, word);
	    }
	    cin>>str;
	    cout<<search(root, str)<<endl;
	}
	
	
	return 0;
}