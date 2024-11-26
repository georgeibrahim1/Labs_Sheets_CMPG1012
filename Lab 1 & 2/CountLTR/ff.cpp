
#include <iostream>
using namespace std; 

int CountLTR(char LTR)
{
    int n , c = 0;
    char a;
    cin >> n; 
    for (int i = 0; i < n; i++)
    {
        cin >> a ;
        if (int(a) == int(LTR) || int(a) == int(LTR) - 32)
           c++;
    }
    return c; 
}

int main()
{
    char what; 
    cin >> what; 
    int u = CountLTR(what);
    cout << u; 

    return 0; 
}




