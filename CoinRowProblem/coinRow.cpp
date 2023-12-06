#include <iostream>
using namespace std;

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

void coinRow(int coin[], int n)
{
    int table[n + 1];
    table[0] = 0;
    table[1] = coin[0];
    for (int i = 2; i <= n; i++)
    {
        table[i] = max(coin[i-1] + table[i - 2], table[i - 1]);
    }
    cout << "Maximum value is: " << table[n] << endl;
    cout << "Coins selected are: ";
    int i = n;
    while (i >= 1)
    {
        if (table[i] == table[i - 1])
        {
            i--;
        }
        else
        {
            cout << coin[i - 1] << " ";
            i -= 2;
        }
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of coins: ";
    cin >> n;
    int coin[n];
    cout << "Enter the value of coins: ";
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
    coinRow(coin, n);
    return 0;
}