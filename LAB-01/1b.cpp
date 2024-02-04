#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDDGE
        freopen("input1b.txt", "r", stdin);
        freopen("output1b.txt", "w", stdout);
    #endif
}

void calculate(double x, double y, char op)
{   
    double res;

    if(op=='+') res = x+y;
    else if(op=='-') res = x-y;
    else if(op=='*') res = x*y;
    else if(op=='/') res = x/y;

    cout<<"The result of "<<x<<" "<<op<<" "<<y<<" is "<<res<<endl; 
}

int main()
{
    init_code();
    int t;
    cin>>t;

    string cmd;
    double x,y;
    char op;

    while(t--)
    {
        cin>>cmd>>x>>op>>y;
        calculate(x,y,op);
    }
    
}