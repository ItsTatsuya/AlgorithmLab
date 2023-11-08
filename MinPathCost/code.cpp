/*code for minimum path cost in a matrix*/

#include <iostream>
using namespace std;

int min(int a, int b, int c)
{
    if(a<b)
    {
        if(a<c)
            return a;
        else
            return c;
    }
    else
    {
        if(b<c)
            return b;
        else
            return c;
    }
}

int main()
{
    int m,n;
    cout<<"Enter the number of rows and columns: ";
    cin>>m>>n;
    int a[m][n];
    cout<<"Enter the elements of the matrix:\n";
    for(int i=0;i<m;i++){
        cout<<"Enter row "<<i+1<<":";
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
    int b[m][n];
    b[0][0]=a[0][0];
    for(int i=1;i<m;i++)
        b[i][0]=b[i-1][0]+a[i][0];
    for(int j=1;j<n;j++)
        b[0][j]=b[0][j-1]+a[0][j];
    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
            b[i][j]=min(b[i-1][j],b[i][j-1],b[i-1][j-1])+a[i][j];
    cout<<"The minimum cost is: "<<b[m-1][n-1]<<endl;
    return 0;
}