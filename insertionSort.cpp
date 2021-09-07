#include <iostream>

using namespace std;
int n = 10;

void print(int a[])
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void insertionSort(int *a)
{
    int key, j;
    //loop for passes
    for (int i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        //loop for swaps
        while (j >= 0 && a[j] > key) //" <  " for decending order
        {
            a[j + 1] = a[j];
            j--;
        }
        
        a[j + 1] = key;
    }
}

int main()
{
    int a[] = {10, 3, 2, 4, 7, 6, 5, 8, 9, 1};
    print(a);
    insertionSort(a);
    print(a);
    return 0;
}