#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,count;
    cin>>n>>m;
    int big=max(n,m);
    int sm=min(n,m);
    if(big==sm)
    {
        cout<<"0\n";
    }
    else
    {
        unordered_map<int,int> m1;
        count=1;
        m1[big]=0;
        while(big!=1)
        {

            for(i=2;i<=sqrt(big);i++)
            {
                if(big%i==0)
                    break;
            }
            cout<<i<<"\n";
            if(i==((int)sqrt(big))+1)
            {
                m1[1]=count;
                break;
            }
            else
            {
                m1[big/i]=count;
                count+=1;
                big/=i;
            }
        }
        count=0;
        while(1)
        {
            if(m1.find(sm)!=m1.end())
            {
                count+=m1[sm];
                break;
            }
            else{
                for(i=2;i<=sqrt(sm);i++)
                {
                    if(sm%i==0)
                        break;
                }
                if(i==((int)(sqrt(sm)))+1)
                {
                    sm=1;
                    count+=1;
                }
                else
                {
                    count+=1;
                    sm=sm/i;
                }
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}