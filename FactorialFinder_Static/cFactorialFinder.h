#pragma once

//This class is created to find the factorial for any given integer
class cFactorialFinder
{
private:
	int mRandomNumber;
	int mFactorial;

	//Method to find the factorial of a number
	int FindFactorial(int number);

	//Method to initialize a random number by hardcoding 
	void InitRandomNumber(int number);

public:
	//Constructors
	cFactorialFinder();
	cFactorialFinder(int randomNumber);

	//GetterFunctions
	int GetRandomNumber();
	int GetUserInput();
	int GetFactorial();

	//SetterFunctions
	void SetRandomNumberFromUserInput();
	void SetFactorial(int number);
};

