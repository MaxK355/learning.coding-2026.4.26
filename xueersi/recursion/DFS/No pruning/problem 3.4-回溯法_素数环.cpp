#include <iostream>
using namespace std;
int n;
int a[20],used[20];
bool isPrime(int x)
{
    if(x==2||x==3||x==5||x==7||x==11||x==13||x==17||x==19||x==23||x==29||x==31)
    {
        return true;
    }
    return false;
}
void DFS(int step){
    if(step > n)
    {
        if(isPrime(a[1] + a[n]))
        {
            for(int i = 1;i <= n;i++)
            {
                cout << a[i] << ' ';
            }
            cout << endl;
        }
        return;
    }
    for(int i=2;i<=n;i++)
    {
        if(!used[i])
        {   
            if(isPrime(i+a[step-1]))
            {
                a[step]=i;
                used[i]=true;
                DFS(step+1);
                used[i]=false;
            }
        }
    }
}
int main()
{
    cin>>n;
    used[1]= true;
    a[1] = 1;
    DFS(2);
    return 0;
}