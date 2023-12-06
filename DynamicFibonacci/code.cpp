#include<iostream>
using namespace std;

int fib(int n)
{
    int f[n+1];
    f[0]=0;
    f[1]=1;
    for(int i=2;i<=n;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    return f[n];
}

int main()
{
    int n;
    cout<<"Enter the number of fibonacci numbers:";
    cin>>n;
    cout<<"The Series: ";
    for(int i=0;i<n;i++)
    {
        cout<<fib(i)<<" ";
    }
    return 0;
}



