#include <bits/stdc++.h>
using namespace std;
#define ll long long

int maxChunksToSorted(vector<int> arr) {
    vector<int> brr(arr);
    sort(brr.begin(), brr.end());
    long long sum1 = 0, sum2 = 0, ret = 0;
    for(int i = 0; i < arr.size(); i++){
        sum1 += arr[i];
        sum2 += brr[i];
        if(sum1 == sum2) ret++;
    }
    return ret;
}

int main() {
	ll t;
	cin>>t;
	while(t--){
	    ll n;
	    vector<int> arr;
	    cin>>n;
	    while(n--){
	        ll c;
	        cin>>c;
	        arr.push_back(c);
	    }
	    cout<<maxChunksToSorted(arr)<<"\n";
	}
	return 0;
}