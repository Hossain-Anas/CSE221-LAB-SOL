#include <bits/stdc++.h>
using namespace std;



void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
}


void merge(vector<int> &arr, int l, int mid, int r)
{
    int left_size = mid-l + 1;
    int right_size = r - mid;

    vector<int> left(left_size);
    vector<int> right(right_size);

    for(int i=l, j=0; i<=mid; i++, j++)
    {
        left[j] = arr[i];
    }

    for(int i=mid+1, j=0; i<=r; i++, j++)
    {
        right[j] = arr[i];
    }

    int lp=0,rp = 0;
    int i=l;

    while(lp<left_size && rp<right_size)
    {
        if(left[lp]>right[rp])
        {
            arr[i] = right[rp];
            rp++;
        }

        else
        {
            arr[i] = left[lp];
            lp++;
        }

        i++;
    }

    while(lp<left_size )
    {
        arr[i] = left[lp];
        lp++;
        i++;
    }

    while(rp<right_size)
    {
        arr[i] = right[rp];
        rp++;
        i++;
    }
}


void mergesort(vector<int> &arr, int l, int r)
{
    if (l==r) return;

    int mid = (l+r)/2;
    mergesort(arr, l, mid);
    mergesort(arr, mid+1, r);
    merge(arr, l, mid, r);
}



int main()
{
    // clock_t start = clock();

    init_code();
    int n;
    cin>>n;

    vector<int> arr;

    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }

    // sort(arr.begin(), arr.end());

    mergesort(arr, 0, n-1);

    for(auto i: arr) cout<<i<<" ";

    cout<<endl;


    // clock_t end = clock();
    // double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    // cout << "Execution Time: " << elapsed_time << " seconds" << endl;

    return 0;
}