#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    long long a;
} card[100005];

struct action{
    long long b,c;
} act[100005];


bool cmp(node x,node y)
{
    return x.a < y.a;
}

bool cmps(action x,action y)
{
    return x.c > y.c;
}


int n,m;
long long ans = 0;
int main(){
	cin >> n >>m;
	for(int i=0;i<n;i++)
	{
	    cin >> card[i].a;
	}
	
	for(int i=0;i<m;i++)
	{
	    cin >> act[i].b >> act[i].c;
	}
	
	sort(card,card+n,cmp);
	sort(act,act+m,cmps);
	
	int pos = 0;
	for(int i=0;i<m;i++)
	{
	    int cnt = 0;
	    while(pos < n && card[pos].a < act[i].c && cnt < act[i].b)
	    {
	        card[pos].a=act[i].c;
	        pos++;
	        cnt++;
	    }
	}
	
	for(int i=0;i<n;i++)
	{
	    ans += card[i].a;
	}
	cout << ans;
	return 0;
}