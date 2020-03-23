#include <iostream>
#include <cstdlib>
using namespace std;
int k;
void SetArray(int* data, int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> data[i];
    }
}

void Print(int* data, int size)
{
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

void FindMax(int* data, int size)
{
    int low = 0, high = size - 1;
    int low0 = 0, high0 = size - 1;
     k = size / 2;
    bool flag = true;
    while (flag) 
    {
        int pivot = data[low];    
        while (low < high) 
        {
        
            while (low < high && data[high] >= pivot)
            {
                high--;
            }
            if (low != high)
            {
                data[low] = data[high];
            }
        
            while (low < high && data[low] <= pivot)
            {
                low++;
            }
            if (low != high)
            {
                data[high] = data[low];
            }
        }
        data[low] = pivot;
        if (low == k - 1) {
            flag = false;
        } else if (low < k - 1) {
            low0 = ++low;
            high = high0;
        }
        else {
            high0 = --high;
            low = low0;
        }
    }
}
int main()
{
    int size, *data;
    while (cin >> size && size != 0)
    {
        data = new int[size];
        SetArray(data, size);
        FindMax(data, size);
        int i;
        for (i = 0; i <k-1; i++)
            cout << data[i] << " ";
        cout << data[i] << endl;
        int j;
        for (j = k; j < size-1; j++)
            cout << data[j] << " ";
        cout << data[j] << endl;
    }
    return 0;
}