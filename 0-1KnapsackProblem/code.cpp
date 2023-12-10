#include <iostream>
using namespace std;

void knapsack(int wt[], int val[], int n, int W) //with items taken shown
{
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= W; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= W; j++)
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
    cout << "Maximum Value: " << dp[n][W] << endl;
    int i = n, j = W;
    cout << "Items Taken: ";
    while (i > 0 && j > 0)
    {
        if (dp[i][j] == dp[i - 1][j])
            i--;
        else
        {
            cout << wt[i - 1] << " ";
            j -= wt[i - 1];
            i--;
        }
    }
    cout << endl;
          
}

int main()
{
    int wt[] = {5, 4, 6, 3};
    int val[] = {10, 40,30,50};
    int W = 10;
    int n = sizeof(wt) / sizeof(wt[0]);
    knapsack(wt, val, n, W);
    return 0;
}