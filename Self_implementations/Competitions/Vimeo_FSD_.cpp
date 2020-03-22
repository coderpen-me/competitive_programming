#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long n, m, k;
		cin>>n>>m;
		long long A[n], G[n], S[m], E[m];
		map<long long, long long> track;
		vector<long long> pep;
		for(long long i = 0; i < n; i++){
			cin>>A[i];
            if(i == 0){
                G[i] = A[i];
            }
            else{
                G[i] = (A[i] + G[i-1]);
            }
		}
        /*for(long long i = 0; i < n; i++){
			cout<<G[i]<<" ";
		}
        cout<<" \n";*/
		for(long long i = 0; i < m; i++){
			long long s, e;
			cin>>s>>e;
            S[i] = s-1;
            E[i] = e-1;
            long long sum;
            if(s-1 > 0){
                sum = (G[e-1] - G[s-2]);
            }
            if(s-1 == 0){
                sum = G[e-1];
            }
			pep.push_back(sum);
            //cout<<" Pushing "<<sum<<" ";
		}
		sort(pep.begin(), pep.end(), greater<long long>());
        sort(S, S+m);
        sort(E, E+m);
		cin>>k;
		long long ret = 0;
		for(auto x : pep){
			if(!k) break;
			ret += x;
			k--;
		}
        /*for(auto x : S){
            cout<<x<<" ";
		}
        cout<<" \n";
        for(auto x : E){
            cout<<x<<" ";
		}
        cout<<" \n";*/
        long long guest = 1, maxa = 1, tt = 1;
        long long i = 1, j = 0;
        while(i < m && j < m){
            //cout<<" i is "<<i<<" j is "<<j<<" maxa is "<<maxa<<"\n\n";
            if(S[i] > E[j]){
                guest--;
                j++;
            }
            else{
                guest++;
                if(guest > maxa){
                    maxa = guest;
                    tt = S[i];
                }
                i++;
            }
            //cout<<" i changed to "<<i<<" j to "<<j<<" now maxa is "<<maxa<<" tt is "<<tt<<"\n";
        }
		cout<<ret<<"\n";
		cout<<tt+1<<"\n";
	}
	return 0;
}