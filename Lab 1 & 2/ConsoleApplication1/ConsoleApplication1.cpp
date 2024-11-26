#include <iostream>
using namespace std;

bool Isgrowing (int &largest)
{
	int current, previous = 0 ;
	bool growing = 1 ;
	while ( growing && cin >> current && current > 0 )
	{
		if (current < previous)
		{
			growing = 0;
		}
		else
		{
			largest = current;
			previous = current;
		}

	}
	return growing; 
}

int main()
{
	int x = 0 ; 
	bool Growing = Isgrowing(x); 

	if (Growing)
		cout << "Input values are in growing order" << endl;
	else
		cout << "Input values are NOT in growing order" << endl;

	cout << "Largest value entered is: " << x ;  


	return 0; 
}