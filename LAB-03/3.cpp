#include <bits/stdc++.h>
using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
        freopen("input3.txt", "r", stdin);
        freopen("output3.txt", "w", stdout);
    #endif
}

int inversion(vector<int> &arr, int l, int r, int mid)
{
    int inv = 0;
    int left = mid-l+1;
    int right = r-mid;

    vector<int> left_arr(left, 0);
    vector<int> right_arr(right, 0);

    for(int i=l, j = 0; i<=mid; i++, j++)
    {   
        left_arr[j] = arr[i];
    }

    for(int i = mid+1, j= 0; i<=r; i++, j++)
    {
        right_arr[j] = arr[i];
    }

    int lp = 0, rp = 0, i= l;

    while(lp<left && rp<right)
    {
        if(left_arr[lp] <= right_arr[rp])
        {
            arr[i] = left_arr[lp];
            lp++;
            i++;
        }

        else
        {
            arr[i] = right_arr[rp];
            inv += (left - lp);
            i++;
            rp++;
        }
    }

    while(lp<left)
    {
        arr[i] = left_arr[lp];
        i++;
        lp++;
    }


    while(rp<right)
    {
        arr[i] = right_arr[rp];
        rp++;
        i++;
    }

    return inv;
}



int inversion_count(vector<int> &arr, int l, int r)
{
    int inv_count = 0;

    if(l<r)
    {
        int mid = (r+l)/2;
        inv_count += inversion_count(arr, l, mid);
        inv_count += inversion_count(arr, mid+1, r);
        inv_count += inversion(arr, l, r, mid);
    }
    
    return inv_count;
}



int main()
{
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

    int res = inversion_count(arr, 0, n-1);

    cout<<res<<endl;
}