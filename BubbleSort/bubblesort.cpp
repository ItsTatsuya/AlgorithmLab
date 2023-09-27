#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n)
{
    cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]";
}

int main()
{
    int n;
    cout << "Enter the size of array:";
    cin >> n;
    int arr[n];
    cout << "\nEnter the Elements of Array:";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nArray Before Sorting:";
    printArray(arr, n);
    bubbleSort(arr, n);
    cout << "\nArray After Sorting:";
    printArray(arr, n);

    return 0;
}