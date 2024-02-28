#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input6.txt", "r", stdin);
        freopen("output6.txt", "w", stdout);
    #endif
}


int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low-1;

    for(int j=low; j<=high-1; j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[i], arr[high]);

    return i;
}



int KthSmallest(vector<int> &arr, int l, int r, int k)
{
    if(l<=r)
    {
        int pivot = partition(arr, l, r);

        if(pivot < k)
        {
            return KthSmallest(arr, pivot+1, r, k);
        }

        else if(pivot > k)
        {
            return KthSmallest(arr, l, pivot-1, k);
        }

        else if(pivot == k)
        {
            return pivot;
        }
    }

    return -1;
}



int main()
{
    init_code();

    int n; cin>>n;
    vector<int> arr;

    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }

    int queries;
    cin>>queries;

    for(int i=0; i<queries; i++)
    {
        int k;
        cin>>k;

        int res = KthSmallest(arr, 0, n-1, k-1);

        if(res!=-1) cout<<arr[res]<<endl;

        else cout<<"ERROR"<<endl;
    }
    
    return 0;
}