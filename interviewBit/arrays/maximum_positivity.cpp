#define ll long long
vector<int> Solution::solve(vector<int> &A) {
    ll s = 0, e = 0, ptr1 = 0, ptr2 = 0;
    A.push_back(-1);
    for(int i = 0; i < A.size(); i++){
        while(A[i] >= 0) i++;
        if(ptr2 - ptr1 < i - s){
            ptr2 = i;
            ptr1 = s;
        }
        s = i+1;
    }
    vector<int> ret;
    for(int i = ptr1; i < ptr2; i++){
        ret.push_back(A[i]);
    }
    return ret;
}