#include <iostream>

using namespace std;

void print(int a[])
{
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void bubbleSort(int *a)
{
    int temp;
    int isSorted = 0;
    for (int j = 0; j < 10; j++)
    {
        cout << "working on pass :" << j + 1 << "\n";
        isSorted = 1;
        for (int i = 0; i < 9 - j; i++)
        {
            if (a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

int main()
{
    int arr[] = {10, 3, 2, 4, 7, 6, 5, 8, 9, 1};
    print(arr);
    bubbleSort(arr);
    print(arr);
    return 0;
}