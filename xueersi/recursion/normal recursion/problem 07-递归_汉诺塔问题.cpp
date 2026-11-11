#include <iostream>
using namespace std;
int n;
char pole1,pole2,pole3;
void tower(int n,char start,char end,char help)
{
    if(n == 0)
    {
        return ;
    }
    tower(n-1,start,help,end);
    cout << n << ':' << start << "->" << end << endl;
    tower(n-1,help,end,start);
}
int main()
{
    cin >> n >> pole1 >> pole2 >> pole3;
    tower(n,pole1,pole2,pole3);
    return 0;
}