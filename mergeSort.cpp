#include <iostream>

using namespace std;

int n = 10;

void print(int a[] , int size=n)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void mergeAlgo(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int ind = high - low + 1;
    int *b = new int[100];

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    //print(b , 100);
    for (int x = low; x <= high; x++)
    {
        a[x] = b[x];
    }
}

void mergeSort(int a[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    else
    {
        int mid = (high + low) / 2;
        //recursive
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        //present recursion execution
        mergeAlgo(a, low, mid, high);
    }
}

int main()
{
    int a[] = {10, 3, 2, 7, 6, 4, 5, 8, 9, 1};
    print(a);
    mergeSort(a, 0, n - 1);
    print(a);

    return 0;
}
