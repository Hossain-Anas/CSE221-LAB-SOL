#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input3.txt", "r", stdin);
        freopen("output3.txt", "w", stdout);
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


priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq;
int n;

vector<pair<int,int>> res;
int task_count = 0;



void maximum_task()
{

    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        if (task_count==0) 
        {
            res.push_back(p);
            task_count++;
        }
        
        else
        {
            int prev_start = res[task_count-1].first;
            int prev_end = res[task_count-1].second;

            if(p.first>=prev_end) 
            {
                res.push_back(p);
                task_count++;
            }
        }
        pq.pop();
    }
}


int main()
{
    init_code();
    
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        pq.push({x,y});
    }

    // while(!pq.empty())
    // {
    //     pair<int,int> p = pq.top();
    //     pq.pop();

    //     cout<<p.first<<" "<<p.second<<endl;
    // }

    maximum_task();

    cout<<res.size()<<endl;

    for(auto i: res) cout<<i.first<<" "<<i.second<<endl;



    return 0;
}