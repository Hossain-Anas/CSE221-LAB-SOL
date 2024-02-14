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


int n,people;
priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq;

int task_count = 0;

void maximum_task(vector<pair<int, int>> curr_task)
{
    while (!pq.empty())
    {
        pair<int,int> p = pq.top();
        pq.pop();

        if(task_count==0)
        {
            curr_task[0] = p;
            task_count++;
        }

        else
        {
            // int prev_start = curr_task[task_count-1].first;
            // int prev_end = curr_task[task_count-1].second;

            int new_start = p.first;
            int new_end = p.second;

            int temp_idx  = -1;
            int diff = INT_MAX;

            for(int i=0; i<people; i++)
            {
                int prev_end = curr_task[i].second;
                // cout<<"prev end "<<prev_end<<endl;

                if(new_start >= prev_end)
                {   
                    int temp = abs(new_start - prev_end);

                    if( temp < diff )
                    {
                        // cout<<"diff "<<i<<" "<<temp<<endl;
                        temp_idx = i;
                        diff = temp;
                        // cout<<"temp_idx "<<i<<endl;
                    }
                }
            }

            if(temp_idx != -1)
            {
                curr_task[temp_idx] = p;
                task_count++;
            }
        }
        // for(auto i: curr_task)
        //     cout<<i.first<<" "<<i.second<<endl;
        // cout<<"\n";
        
    }
}


int main()
{
    init_code();

    cin>>n>>people;

    for(int i=0; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        pq.push({x,y});
    }

    vector<pair<int, int>> curr_task(people, make_pair(0,0));

    // while(!pq.empty())
    // {
    //     pair<int,int> p = pq.top();
    //     pq.pop();

    //     cout<<p.first<<" "<<p.second<<endl;
    // }

    maximum_task(curr_task);

    cout<<task_count;

    // for(auto i: curr_task) cout<<i<<" ";

    return 0;
}
