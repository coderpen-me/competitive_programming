#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        stack<int> ss;
        int ret = 0;
        ss.push(arr[0]);
        for(int i = 1; i < arr.size(); i++){
            while(!ss.empty() && ss.top() < arr[i]){
                int tmp = ss.top();
                ss.pop();
                if(ss.empty())
                    ret += tmp*arr[i];
                else
                    ret += tmp * min(ss.top(), arr[i]);
            }
            ss.push(arr[i]);
        }
        while (!ss.empty()) {
            int tmp = ss.top();
            ss.pop();
            if(!ss.empty())
                ret += tmp * ss.top();
        }
        return ret;
    }
};