#include <iostream>
using namespace std;

void Reorder(int* A, int *& p, int n , int x) // why & ? --> To control what Arr2 is pointing to , If you don't use & ?? --> int * p = Arr2 like you make p is pointing to a garbage array of memory
{                                             // Notice : You must make delare int * Arr2 not Arr2[N] 
     p = new int[n];
    int ref = x;
    int dn = 0;

    for (int i = 0; i < n; i++)
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
   // delete[]p;// --> I remember to deallocate but dude !!!!! , It will delete the heap memory you are pointing by pointer p (You will use it in Main) ;D

}

int main() // Main from ChatGPT
{
    const int N = 12;  // Define the size of the array
    int Arr1[N], *Arr2; // Two arrays: one for input, one for reordered values
    int reorderValue;

    // Read reorder value (X)
    cout << "Enter reorder value: ";
    cin >> reorderValue;

    // Read N integer numbers from the user and store them in Arr1
    cout << "Enter " << N << " integers: ";
    for (int i = 0; i < N; i++)
    {
        cin >> Arr1[i];
    }

    // Print Arr1 before reorder
    cout << "Array before reorder:" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << Arr1[i] << " ";
    }
    cout << endl;

    // Call Reorder function
    Reorder(Arr1, Arr2, N, reorderValue);

    // Print reorder value and arrays Arr1 and Arr2
    cout << "Reorder Value: " << reorderValue << endl;

    // Print Arr1 after reorder (should remain unchanged)
    cout << "Arr1: ";
    for (int i = 0; i < N; i++)
    {
        cout << Arr1[i] << " ";
    }
    cout << endl;

    // Print Arr2 after reorder
    cout << "Arr2: ";
    for (int i = 0; i < N; i++)
    {
        cout << Arr2[i] << " ";
    }
    cout << endl;


    return 0;
}

