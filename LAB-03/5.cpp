#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input5.txt", "r", stdin);
        freopen("output5.txt", "w", stdout);
    #endif
}

int partition(vector<int> &arr, int l, int r)
{
    int pivot = arr[r];
    int i = l-1;

    for(int j = l; j<=r-1; j++)
    {
        if(arr[j] <= pivot)
        {   i++;
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[r], arr[i]);
    return i;
}



void quick_sort(vector<int> &arr, int l, int r)
{
    if(l<r)
    {
        int pivot = partition(arr, l, r);
        quick_sort(arr, l, pivot-1);
        quick_sort(arr, pivot+1, r);
    }

}


int main()
{
    init_code();
    int n;
    cin>>n;

    vector<int> arr;

    for(int i = 0; i<n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }

    quick_sort(arr, 0, n-1);

    for(int i: arr) cout<<i<<" ";
}