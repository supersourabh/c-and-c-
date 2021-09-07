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

void selectionSort(int *a)
{
    int min, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (i != min)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

int main()
{
    int a[] = {10, 3, 2, 4, 7, 6, 5, 8, 9, 1};
    print(a);
    selectionSort(a);
    print(a);
    return 0;
}