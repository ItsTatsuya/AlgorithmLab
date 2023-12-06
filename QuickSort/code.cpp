#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

    } while (i < j);

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
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
    quickSort(arr, 0, n - 1);
    cout << "\nArray After Sorting:";
    printArray(arr, n);

    return 0;
}
