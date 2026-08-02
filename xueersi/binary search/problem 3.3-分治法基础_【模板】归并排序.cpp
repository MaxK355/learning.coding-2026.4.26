#include <iostream>
using namespace std;
int n, k, a[5000005],b[100005];

void merge_sort(int l,int r)
{
    if(l >= r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int i = l,j = mid + 1,k = l;
    while(i <= mid && j <= r)
    {
        if(a[i] <= a[j])
        {
            b[k] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    while(i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while(j <= r)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    for(int i = l;i <= r;i++)
    {
        a[i] = b[i];
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    merge_sort(0, n - 1);
    for(int i = 0;i < n;i++)
    {
        cout << b[i] << ' ';
    }
}