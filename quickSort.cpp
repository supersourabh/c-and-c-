#include <iostream>

using namespace std;

int n = 13;

void print(int a[])
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int partition(int *a, int low, int high)
{
    int pivot = a[low];
    int i = low + 1, j = high;
    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }

        while (a[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    //interchanging a->low and a->j
    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quickSort(int *a, int low, int high)
{

    if (low < high)
    {
        int partitionIndex = partition(a, low, high);
        //print(a);
        //cout<<partitionIndex<<"\n";
        quickSort(a, low, partitionIndex - 1);
        quickSort(a, partitionIndex + 1, high);
    }
}

int main()
{
    int a[] = {10, 3, 2, 4, 7, 6, 12, 4, 5, 5, 8, 9, 1};
    print(a);
    quickSort(a, 0, n);
    print(a);
    return 0;
}
