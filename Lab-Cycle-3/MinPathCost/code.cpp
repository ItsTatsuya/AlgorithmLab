#include <iostream>

using namespace std;

int minimum(int a, int b, int c)
{
   return min(min(a, b), c);
}

void minCost(int cost[100][100], int m, int n)
{
   int i, j;
   int tc[m+1][n+1];

   tc[0][0] = cost[0][0];

   for (i = 1; i <= m; i++)
       tc[i][0] = tc[i - 1][0] + cost[i][0];

   for (j = 1; j <= n; j++)
       tc[0][j] = tc[0][j - 1] + cost[0][j];

   for (i = 1; i <= m; i++)
       for (j = 1; j <= n; j++)
           tc[i][j] = minimum(tc[i - 1][j - 1], tc[i - 1][j], tc[i][j - 1]) + cost[i][j];

   cout << "The minimum cost is: " << tc[m][n] << endl;
   cout << "The path is: " << endl;
   i = m, j = n;
   while (i > 0 && j > 0)
   {
       cout << "(" << i << ", " << j << ")" << endl;
       if (tc[i - 1][j - 1] < tc[i - 1][j] && tc[i - 1][j - 1] < tc[i][j - 1])
       {
           i--;
           j--;
       }
       else if (tc[i - 1][j] < tc[i][j - 1])
           i--;
       else
           j--;
   }
}

int main()
{
   cout << "Enter the row and column size of the matrix: ";
   int crow, ccolumn;
   cin >> crow >> ccolumn;
   int cost[100][100];
   cout << "Enter the cost matrix: " << endl;
   for (int i = 0; i < crow; i++)
       for (int j = 0; j < ccolumn; j++)
            cin >> cost[i][j];

   cout << "Enter the destination row and column: ";
   int drow, dcolumn;
   cin >> drow >> dcolumn;

   minCost(cost, drow, dcolumn);
   return 0;
}
