#include <iostream>
using namespace std;
int n, k, a[5000005];

void quick_sort(int l,int r)
{
    if(l >= r)
    {
        return;
    }
    int mid = l + r >> 1;
    swap(a[mid], a[l]);
    int i = l + 1,j = r;
    while(i <= j)
    {
        while(i <= j && a[i] < a[l])
        {
            i++;
        }
        while(i <= j && a[j] > a[l])
        {
            j--;
        }
        if(i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    swap(a[j],a[l]);
    if(j == k)
    {
        return;
    }
    else if(j > k)
    {
        quick_sort(l,j - 1);
    }
    else
    {
        quick_sort(i, r);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    quick_sort(0, n - 1);
    cout << a[k];
}