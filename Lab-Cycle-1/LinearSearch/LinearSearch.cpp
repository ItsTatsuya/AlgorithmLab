#include <iostream>
using namespace std;

int linearSearch(int n, int v, int array[]){
    for(int i = 0;i<n;i++){
        if(array[i]==v){
            return i;
        }
    }   
    return -404;
}

int main(){
    int n, v;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int array[n];
    cout<<"Enter the elements of the array: ";
    for(int i = 0;i<n;i++){
        cin>>array[i];
    }
    cout<<"\nEnter the value to be searched: ";
    cin>>v;
    cout<<linearSearch(n, v, array) << endl;
    return 0;
}