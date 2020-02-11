#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<int>
#define vs vector<string>
#define vvi vector<vector<int>>
#define msi map<string, int>

#define LP(i, n) for (ll i = 0; i < n; i++)
#define LP1(i, n) for (ll i = 1; i <= n; i++)
#define BLP1(i, n) for (ll i = n; i > 0; i--)
#define BLP(i, n) for (ll i = n; i >= 0; i--)

#define el '\n'
#define IOS()                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define tc() testcases()
#define pvi(A) printvector(A)
#define pvs(A) printvectorstring(A)
#define pvvi(A) printvectorvector(A)
#define pmsi(A) printmapstringint(A)

#define a1(a) cout << a << " ";
#define a2(a, b) cout << a << " " << b << " ";
#define a3(a, b, c) cout << a << " " << b << " " << c << " ";
#define a4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << " ";
#define a5(a, b, c, d, e) cout << a << " " << b << " " << c << " " << d << " " << e << " ";

#define b1(a) cout << a << "\n";
#define b2(a, b) cout << a << " " << b << "\n";
#define b3(a, b, c) cout << a << " " << b << " " << c << "\n";
#define b4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << "\n";
#define b5(a, b, c, d, e) cout << a << " " << b << " " << c << " " << d << " " << e << "\n";

#define nl cout << "\n"

const ll MAXn = 1e5 + 5, MAXlg = __lg(MAXn) + 2;
const ll MOD = 1000000007;
const ll INF = ll(1e15);

ll a[MAXn], b[MAXn], c[MAXn], d[MAXn];

ll t = 0, u = 0, v = 0, w = 0, x = 0, y = 0, z = 0;
ll sum = 0, sum1 = 0, mul = 0, subs = 0, test = 0, num = 0, num1 = 0;
//ll aa=0, bb=0, cc=0, dd=0, ee=0;
//ll count=0, ctl=0, ctrl=0, divi=0, flag=0, cal=0, must=0, test=0;
string in;
int testcases()
{
    cin >> test;
    return test;
}
void printvectorint(vector<int> A)
{
    nl;
    for (auto x : A)
    {
        a1(x);
    }
    nl;
}

void printvectorstring(vector<string> A)
{
    nl;
    for (auto x : A)
    {
        a1(x);
    }
    nl;
}

void printvectorvectorint(vector<vector<int>> A)
{
    nl;
    for (auto x : A)
    {
        for (auto y : x)
        {
            a1(y);
        }
        nl;
    }
    nl;
}

void printmapstringint(msi A)
{
    for(auto x : A)
    {
        cout << "  " << x.first
             << "  " << x.second;
    }
}

bool check(string &temp, int A)
{
    for (int i = 0; i < ((2 * A) + 1); i++)
    {
        if (i < A)
        {
            if (temp[i] != 'B')
                return false;
        }
        if (i == A)
        {
            if (temp[i] != 'H')
                return false;
        }
        if (i > A)
        {
            if (temp[i] != 'W')
                return false;
        }
    }
    return true;
}

int sl(string &temp, int pos, msi &book)
{
    char t;
    t = temp[pos - 1];
    temp[pos - 1] = temp[pos];
    temp[pos] = t;
    if (book[temp] != 1)
    {
        return pos - 1;
    }
    else
    {
        t = temp[pos - 1];
        temp[pos - 1] = temp[pos];
        temp[pos] = t;
        return -1;
    }
}

int sr(string &temp, int pos, msi &book)
{
    char t;
    t = temp[pos + 1];
    temp[pos + 1] = temp[pos];
    temp[pos] = t;
    if (book[temp] != 1)
    {
        return pos + 1;
    }
    else
    {
        t = temp[pos + 1];
        temp[pos + 1] = temp[pos];
        temp[pos] = t;
        return -1;
    }
}

int jl(string &temp, int pos, msi &book)
{
    char t;
    t = temp[pos - 2];
    temp[pos - 2] = temp[pos];
    temp[pos] = t;
    if (book[temp] != 1)
    {
        return pos - 2;
    }
    else
    {
        t = temp[pos - 2];
        temp[pos - 2] = temp[pos];
        temp[pos] = t;
        return -1;
    }
}

int jr(string &temp, int pos, msi &book)
{
    char t;
    t = temp[pos + 2];
    temp[pos + 2] = temp[pos];
    temp[pos] = t;
    if (book[temp] != 1)
    {
        return pos + 2;
    }
    else
    {
        t = temp[pos + 2];
        temp[pos + 2] = temp[pos];
        temp[pos] = t;
        return -1;
    }
}

void recurr(vs &res, vs &get, string &temp, int pos, int A, msi &book, int level)
{
    int ret;
    string main = temp;
    string mass;
    int mpos = pos;
    if(get.size() != 0 && res.size() > get.size()) return;
    if (check(temp, A) == 1)
    {
        if (res.size() < get.size() || get.size() == 0)
        {
            get = res;
        }
        /*cout<<"Yes";
        for(auto x : res){
            cout<<x<<" ";
        }
        cout<<"     ";*/
        return;
    }
    else
    {
        temp = main;
        pos = mpos;
        /*nl;
        a3("Shift right", pos, level);
        nl;
        pmsi(book);
        nl;*/
        if (pos < (2 * A))
        {
            //nl;
            //cout << " attempt on " << temp << " ";
            ret = sr(temp, pos, book);
            //cout << "Trying sr " << ret << " ";
            if (ret != -1)
            {
                pos = ret;
                res.push_back(temp);
                book[temp] = 1;
                mass = temp;
                recurr(res, get, temp, pos, A, book, level + 1);
                res.pop_back();
                temp = mass;
                book[temp] = 0;
            }
            //cout << " exiting with " << temp << " ";
        }
        temp = main;
        pos = mpos;
        /*nl;
        a3("Shift left", pos, level);
        nl;
        pmsi(book);
        nl;*/
        if (pos > 0)
        {
            //nl;
            //cout << " attempt on " << temp << " ";
            ret = sl(temp, pos, book);
            //cout << "Trying sl " << ret << " ";
            if (ret != -1)
            {
                pos = ret;
                res.push_back(temp);
                book[temp] = 1;
                mass = temp;
                recurr(res, get, temp, pos, A, book, level + 1);
                res.pop_back();
                temp = mass;
                book[temp] = 0;
            }
            //cout << " exiting with " << temp << " ";
        }

        temp = main;
        pos = mpos;
        /*nl;
        a3("jump left", pos, level);
        nl;
        pmsi(book);
        nl;*/
        if ((pos - 2 >= 0))
        {
            if ((temp[pos - 1] != temp[pos - 2]))
            {
                //nl;
                //cout << " attempt on " << temp << " ";
                ret = jl(temp, pos, book);
                //cout << "Trying jl " << ret << " ";
                if (ret != -1)
                {
                    pos = ret;
                    res.push_back(temp);
                    book[temp] = 1;
                    mass = temp;
                    recurr(res, get, temp, pos, A, book, level + 1);
                    temp = mass;
                    res.pop_back();
                    book[temp] = 0;
                }
                //cout << " exiting with " << temp << " ";
            }
        }
        temp = main;
        pos = mpos;
        //nl;
        //a3("jump right", pos, level);
        //nl;
        //pmsi(book);
        //nl;
        if ((pos + 2 <= (2 * A)))
        {
            if ((temp[pos + 1] != temp[pos + 2]))
            {
                //nl;
                //cout << " attempt on " << temp << " ";
                ret = jr(temp, pos, book);
                //cout << "Trying jr " << ret << " ";
                if (ret != -1)
                {
                    pos = ret;
                    res.push_back(temp);
                    book[temp] = 1;
                    mass = temp;
                    recurr(res, get, temp, pos, A, book, level + 1);
                    temp = mass;
                    res.pop_back();
                    book[temp] = 0;
                }
                //cout << " exiting with " << temp << " ";
            }
        }
    }
}
vector<string> solve(int A)
{
    vs get;
    vs res;
    string temp;
    map<string, int> book;
    for (int i = 0; i < ((2 * A) + 1); i++)
    {
        if (i < A)
        {
            temp.push_back('W');
        }
        if (i == A)
        {
            temp.push_back('H');
        }
        if (i > A)
        {
            temp.push_back('B');
        }
    }
    if (book[temp] != 1)
    {
        res.push_back(temp);
        book[temp] = 1;
    }
    int pos = A;
    pos = sl(temp, A, book);
    if (book[temp] != 1)
    {
        res.push_back(temp);
        book[temp] = 1;
    }
    recurr(res, get, temp, pos, A, book, 0);
    return get;
}

//WWHBB WHWBB WBWHB WBWBH WBHBW HBWBW BHWBW BBWHW BBHWW

int main()
{
    IOS();
    //t = tc();
    t = 1;
    while (t--)
    {
        pvs(solve(3));
    }

    return 0;
}