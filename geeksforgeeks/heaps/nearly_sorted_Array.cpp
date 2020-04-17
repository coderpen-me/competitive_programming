//https://practice.geeksforgeeks.org/problems/nearly-sorted-algorithm/0
#include <bits/stdc++.h>
using namespace std;

/*  Note :: Use heap to reduce time complexity to O(n long k) with O(k) aux space.
            Use Insertion sort for time complexity of O(nk).
*/
int main() {
	int t, n, k;
    cin>>t;
	while(t--){
	    cin>>n>>k;
	    int arr[n];
	    for(int i = 0; i < n; i++){
	        cin>>arr[i];
	    }
	    sort(arr, arr+n);
	    for(int i = 0; i < n; i++){
	        cout<<arr[i]<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}