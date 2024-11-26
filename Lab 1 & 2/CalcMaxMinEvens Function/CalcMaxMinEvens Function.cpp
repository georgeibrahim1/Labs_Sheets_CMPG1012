// I will make some edits to this Exercise 
// I will not use Arrays , I will make a while loop to recieve nums from user
// The loop will stop when the user adds odd number 
// I assume the even nums are positive in the test code phase

#include <iostream>
using namespace std;

void CalcMaxMinEvens ()
{
    int current, previous = -1, largest = -1 , Smallest = -1;
    while (cin >> current && (current % 2 == 0))
    {
        if (largest == -1 && Smallest == -1) // To initialize 
        {
            largest = current; 
            Smallest = current;
        }
        
        
        if (current > largest)
        {
           largest = current; 
        }

        if (current < Smallest)
        {
            Smallest = current; 
        }
        
    }
    cout << "Largest : " << largest << endl ; 
    cout << "Smallest : " << Smalllest << endl;
}

int main()
{


    return 0;
}



