#include <bits/stdc++.h>

using namespace std;

int main(){
long long n,m,size1;

cin>>n>>m;
cin>>size1;
double arr[size1];
for (long long i = 0; i < size1; i++)
    cin>>arr[i];
if (m<n){
    long long temp=m;
    m=n;
    n=temp;
}
long long s1=m-n;
long long s2=0;

long long e1=m-1;
long long e2=m-1;

double movingAvg_n = 0.0;
double movingAvg_m = 0.0;

long long i = 0;
while (i < n){
        movingAvg_n += arr[m - i - 1];
        i+=1;
}
i = 0;
while (i < m) {
        movingAvg_m += arr[i];
        i+=1;
}
//print (movingAvg_n/n, moving_avg_m/m)

long long ctr = 0;

double previous_n = movingAvg_n;
double previous_m = movingAvg_m;

for (i=m;i<size1;i++){
    if( ((movingAvg_n/(double)n) - (movingAvg_m/(double)m)) != 0){
        previous_n = movingAvg_n ;
        previous_m = movingAvg_m ;

    }

    movingAvg_n -= arr[s1];
    s1 += 1;
    e1 += 1;
    movingAvg_n += arr[e1];

    movingAvg_m -= arr[s2];
    s2 += 1;
    e2 += 1;
    movingAvg_m += arr[e2];

    if(((previous_n/(double)n) - (previous_m/(double)m) < 0) && ((movingAvg_n/(double)n) - (movingAvg_m/(double)m) > 0)){
        ctr += 1;
    }
    if(((previous_n/(double)n) - (previous_m/(double)m) > 0) && ((movingAvg_n/(double)n) - (movingAvg_m/(double)m) < 0)){
        ctr += 1;
        }
} 
 cout<<ctr;
 
  
  return 0;
}