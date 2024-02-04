#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDDGE
        freopen("input3.txt", "r", stdin);
        freopen("output3.txt", "w", stdout);
    #endif
}


class Student
{
    public:
    int id, marks;

    Student(int id, int marks)
    {
        this->id = id;
        this->marks = marks;
    }
};


void selection_sort(vector<Student> &students, int n)
{
    int k,j;

    for(int i=0; i<n-1; i++)
    {
        k = i;
        for(j = i+1; j<n; j++)
        {
            if(students[j].marks == students[k].marks)
            {
                if (students[j].id < students[k].id)
                {
                    k = j;
                }
            }

            else if(students[j].marks > students[k].marks)
            {
                k = j;
            }
        }
        
        swap(students[i], students[k]);
    }
}


int main()
{
    init_code();

    vector<Student> students;
    vector<int> ids;
    int t;

    cin>>t;

    for(int i=0; i<t; i++)
    {
        int id;
        cin>>id;
        ids.push_back(id);
    }

    for(int i=0; i<t; i++)
    {
        int mark;
        cin>>mark;
        students.push_back(Student(ids[i], mark));
    }

    selection_sort(students, t);

    for(auto i: students)
    {
        cout<<"ID: "<<i.id<< " Mark: "<<i.marks<<endl;
    }

    return 0;
}