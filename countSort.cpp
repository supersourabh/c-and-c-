#include <iostream>
#include <cstdlib>

using namespace std;

int n = 10;

void print(int a[], int size = n)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int maxEle(int a[])
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}

void countSort(int a[])
{
    int size = maxEle(a);
    int *refArr = (int *)calloc(size+1, sizeof(int));
    
    for (int i = 0; i < n; i++)
    {
        refArr[a[i]] += 1;
    }

    
    int i = 0, j = 0;
    while (i <= size)
    {
        if (refArr[i] > 0)
        {
            a[j] = i;
            refArr[i] = refArr[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int a[] = {10, 3, 2, 7, 6, 4, 5, 8, 9, 1};
    print(a);
    countSort(a);
    print(a);

    return 0;
}