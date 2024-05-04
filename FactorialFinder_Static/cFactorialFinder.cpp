
#include "cFactorialFinder.h"
#include <iostream>

//Function contains the factorial logic
int cFactorialFinder::FindFactorial(int number)
{
	int fact = number;
	for (int loopIndex = number; loopIndex > 1; loopIndex--)
	{
		fact = fact * (loopIndex - 1);
	}

	return fact;
}

//Function to initialize a random number
void cFactorialFinder::InitRandomNumber(int number)
{
	mRandomNumber = number > 0 ? number : 0;
}

cFactorialFinder::cFactorialFinder()
	:mRandomNumber(0)
{
	InitRandomNumber(5);
}

cFactorialFinder::cFactorialFinder(int randomNumber)
{
	InitRandomNumber(randomNumber);
}

//Function to fetch the private member variable "mRandomNumber"
int cFactorialFinder::GetRandomNumber()
{
	return mRandomNumber;
}

//Function to fetch the private member variable "mFactorial"
int cFactorialFinder::GetFactorial()
{
	return mFactorial;
}

//Function to fetch the user input for the random number variable
int  cFactorialFinder::GetUserInput()
{
	int userInput;
	std::cout << "\n\nEnter number : ";
	std::cin >> userInput;
	std::cout << "\n\n";

	return userInput > 0 ? userInput : 0;
}

//Function to set the user input to the private member variable "mRandomNumber"
void cFactorialFinder::SetRandomNumberFromUserInput()
{
	mRandomNumber = GetUserInput();
}

//Function to set the factorial to the private member variable "mFactorial"
void cFactorialFinder::SetFactorial(int number)
{
	mFactorial = FindFactorial(number);
}