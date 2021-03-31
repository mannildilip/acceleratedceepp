#include <iostream>
#include <string>
/*
Problem is to print following 
after name as input
****************
*              *
* Hello, name! *
*              *
****************
*/
int main()

{
	std::cout << "Please enter your name: ";

	std::string name;
	std::cin >> name;
	
	/* Building the message that is intended to write */

	const std::string greeting = "Hello," + name + "!";

	/* Building second and forth line */
	const std::string spaces(greeting.size(), ' ');
	const std::string second = "* " + spaces + " *";

	/*Build the first and fifth lines */
	const std::string first(second.size(), '*');

	/* Print the frame */
	std::cout << std::endl;
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cout << "* " << greeting << " *" << std::endl;
	std::cout << second << std::endl;
	std::cout << first << std::endl;

	/* check */
	//std::string hello = "hello";
	//std::string message = hello + "world" + "!";
	//std::cout << message << std::endl;

	std::string exclam = "!";
//	std::string message = "hello," + "world" + exclam;
	std::string message = "hello," + exclam;
	std::cout << message << std::endl;
	
	
	return 0;	
}


