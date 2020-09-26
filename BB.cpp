#include<bits/stdc++.h>
using namespace std;
#define ll long long

string maza_aaya(int num, map<int, string> conversion_hash){
    if(num == 0) return "";
    int flag = floor(log10(num) + 1);
    if(flag == 3){
        return ("hundred");
    }
    if(flag == 2){
        if(num >= 10 && num <= 20){
            return conversion_hash[num];
        }
        else{
            if(conversion_hash.find(num) != conversion_hash.end()) return conversion_hash[num];
            return (conversion_hash[(num/10)*10] + conversion_hash[num%10]);
        }
    }
    if(flag == 1){
        return conversion_hash[num];
    }
    return "";
}
string array_waah(int num, map<int, string> conversion_hash) {
    string ret = "";
    int i = 0;
    if(num == 0) return "zero";
    string itm = maza_aaya(num, conversion_hash);
    ret += itm;
    if(ret[ret.size()-1] == ' ') {
        return ret.substr(0, ret.size()-1);
    }
    return ret;
}

int arrey_nhi(ll rec[], ll d, ll n){
    unordered_map<ll, ll> hash;
    ll duplicates = 0;
    for (ll i=0; i<n; i++)
        hash[rec[i]]++;
    for (ll i=0; i<n; i++){
        duplicates += hash[d - rec[i]];
        if(d - rec[i] == rec[i])
            duplicates--;
    }
    duplicates /= 2;
    return duplicates;
}

int main(){
    map<int, string> conversion_hash;

    conversion_hash[0] = "";
    conversion_hash[1] = "one ";
    conversion_hash[2] = "two ";
    conversion_hash[3] = "three ";
    conversion_hash[4] = "four ";
    conversion_hash[5] = "five ";
    conversion_hash[6] = "six ";
    conversion_hash[7] = "seven ";
    conversion_hash[8] = "eight ";
    conversion_hash[9] = "nine ";
    conversion_hash[10] = "ten ";
    conversion_hash[11] = "eleven ";
    conversion_hash[12] = "twelve ";
    conversion_hash[13] = "thirteen ";
    conversion_hash[14] = "fourteen ";
    conversion_hash[15] = "fifteen ";
    conversion_hash[16] = "sixteen ";
    conversion_hash[17] = "seventeen ";
    conversion_hash[18] = "eighteen ";
    conversion_hash[19] = "nineteen ";
    conversion_hash[20] = "twenty ";
    conversion_hash[30] = "thirty ";
    conversion_hash[40] = "forty ";
    conversion_hash[50] = "fifty ";
    conversion_hash[60] = "sixty ";
    conversion_hash[70] = "seventy ";
    conversion_hash[80] = "eighty ";
    conversion_hash[90] = "ninety ";

    ll n, d = 0;
    cin>>n;
    ll rec[n];
    for(int i = 0; i < n; i++){
        cin>>rec[i];
        string str = array_waah(rec[i], conversion_hash);
        for(char x : str){
            if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'){
                d++;
            }
        }
    }
    cout<<array_waah(arrey_nhi(rec, d, n), conversion_hash);
    return 0;
}
