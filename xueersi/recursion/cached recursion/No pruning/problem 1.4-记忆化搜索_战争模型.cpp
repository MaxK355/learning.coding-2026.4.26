#include<iostream>
#include <cmath>
using namespace std;

int a, b, q, x, y;

void sim(int x,int y)
{
    while(x > 0 && y > 0)
    {
        int y_copy = y;
        int x_copy = x;
        x = x - ceil(y_copy * 1.0 / b);
        y = y - ceil(x_copy * 1.0 / a);
    }
    if(x <= 0 && y <= 0)
    {
        cout << "EVEN" << endl;
        return;
    }
    else if(x <= 0)
    {
        cout << "Y " << y << endl;
        return;
    }
    else
    {
        cout << "X " << x << endl;
    }
    return;
}

int main(){
	cin >> a >> b >> q;
	for(int i = 0;i < q;i++)
	{
	    scanf("%d %d", &x, &y);
	    sim(x,y);
	}
	return 0;
}