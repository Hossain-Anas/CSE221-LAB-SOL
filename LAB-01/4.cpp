#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDDGE
        freopen("input4.txt", "r", stdin);
        freopen("output4.txt", "w", stdout);
    #endif
}

class Train
{
    public:
        string name;
        double time;
        int order;
        string output_time;
        string destination;
    
    Train(string name, double time, int order, string destination, string output_time)
    {
        this->name = name;
        this->order = order;
        this->time = time;
        this->destination = destination;
        this->output_time = output_time;
    }
};


void bubble_sort(vector<Train> &trains, int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            string name1 = trains[j+1].name;
            string name2 = trains[j].name;
            int res = name1.compare(name2);

            if(res == 0 && trains[j].time < trains[j+1].time)
            {
                swap(trains[j], trains[j+1]);
            }

            else if(res<0)
            {
                swap(trains[j], trains[j+1]);
            }
        }
    }
}


int main()
{
    init_code();

    int t;
    cin>>t;
    cin.ignore();

    vector<Train> trains;

    for (int i = 0; i < t; i++)
    {
        string line;
        getline(cin, line);
        
        stringstream ss(line);
        string trash;

        string name;
        int order = i;

        double temp_hour, temp_min;
        char colon;
        string destination;

        ss>>name;

        while(ss>>trash && trash!="for");

        ss>>destination>>trash;

        string time_string;

        ss>>time_string;

        stringstream ss2(time_string);

        ss2>>temp_hour>>colon>>temp_min;

        double time = temp_hour + (temp_min/60.0);

        trains.push_back(Train(name, time, order, destination, time_string));

    }

    bubble_sort(trains, t);

    for(auto i: trains)
    {
        cout<<i.name<<" will departure for "<<i.destination<<" at "<<i.output_time<<endl;
    }
    

    return 0;
}