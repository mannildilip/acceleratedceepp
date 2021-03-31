/* Framing program: Based on Loops */

#include <iostream>
#include <string>

/* Standard library names */
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	/* Ask person's name */			
	cout << "Please enter yur first name, ";

	/* Read the name */
	string name;
	cin >> name;

	/* Build the message that we intend to write */
	const string greeting = "Hello, " + name + "!";
	
	/* No of black surrounding the grreting and both sides of greeting */
	const int pad = 1;

	/* No. of rows and columns to write */
	const int rows = pad *2 + 3;

	const string::size_type cols = greeting.size() + pad * 2 + 2;

	/* Write a blank line to seperate i/p from o/p */

	/* Write output */
	for(int r=0; r != rows; ++r)
	{
		string::size_type c = 0;
		
		while(c != cols)
		{
			if(r == pad + 1 && c == pad + 1)
			{
				cout << greeting;
				c += greeting.size();
			}
			else
			{
				if(r == 0 || r == rows - 1 || c == 0 || c == cols -1)
					cout << "*";
				else
					cout << " ";
				++c;
			}
		}	
		cout << endl;	
	} 
	
	return 0;
	
}
