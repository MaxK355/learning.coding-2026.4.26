#include<iostream>
using namespace std;

int n, sum, moves, card_piles[105];

int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> card_piles[i];
        sum += card_piles[i];
    }
    sum /= n; //sum -> average
    for(int i = 1;i <= n - 1;i++)
    {
        if(card_piles[i] != sum)
        {
            card_piles[i + 1] += card_piles[i] - sum;
            moves++;
        }
    }
    cout << moves;
    return 0;
}