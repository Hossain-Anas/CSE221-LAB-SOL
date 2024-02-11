#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input4.txt", "r", stdin);
        freopen("output4.txt", "w", stdout);
    #endif
}


class cmp
{
    public:
        bool operator()(pair<int, int> a, pair<int, int> b)
        {
            if(a.second>b.second) return true;
            else return false;
        }
};


int main()
{


}