
#include <iostream>
using namespace std;

int * ReorderMe(int* A, int n)
{
    int* p = new int[n]; 
    int ref = *A;
    int dn = 0;

    


    for (int i = 0 ; i < n ; i++ )
    {
        if (*(A + i) < ref)
        {
            *(p + dn) = *(A + i);
            dn++; 
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (*(A + i) == ref)
        {
            *(p + dn) = *(A + i);
            dn++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (*(A + i) > ref)
        {
            *(p + dn) = *(A + i);
            dn++;
        }
    }

    return p; 
}

int main() // Main from ChatGPT
{
    int arr[] = { 42, 36, -55, 50, 98, 67, -23, 100, 85, -75 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the original array
    cout << "Original array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call ReorderMe function
    int * p = ReorderMe(arr, n);

    // Output the reordered array
    cout << "Reordered array: ";
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;

    return 0;
    return 0;
}

