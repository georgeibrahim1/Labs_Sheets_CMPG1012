
#include <iostream>
using namespace std;

bool Reverse (int * A , int n )
{
    bool isSymmetric = true; 
    for (int i = 0; i < (n / 2); i++)
    {
        if (*(A + i) != *(A + n -1 - i)) // If not Symmetric
        {
            isSymmetric = false; 
        }
    }
    if (!isSymmetric)
    {
        for (int i = 0; i < (n / 2); i++)
        {
            int temp = *(A + i);
            *(A + i) = *(A + n - 1 - i);
            *(A + n - 1 - i) = temp; 

        }
    }
    return isSymmetric; 
}

int main() // Main from ChatGPT
{
    int N;

    // Ask user for the size of the array
    cout << "Enter the size of the array: ";
    cin >> N;

    int* arr = new int[N];

    // Read N integers from the user
    cout << "Enter " << N << " integers: ";
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    // Call the Reverse function and check if the array is symmetric
    bool symmetric = Reverse(arr, N);

    // Print whether the array is symmetric
    if (symmetric)
    {
        cout << "Array is symmetric" << endl;
    }
    else
    {
        cout << "Array is NOT symmetric" << endl;
    }

    // Print the array after reverse
    cout << "Array after reverse:" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


