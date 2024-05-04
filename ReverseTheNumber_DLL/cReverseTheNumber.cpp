
#include "cReverseTheNumber.h"
#include <iostream>
#include<Windows.h>

//Function contains the logic to reverse a number
std::string cReverseTheNumber::ReverseNumber(int number)
{
	int remainder;
	std::string reverseString;
	if (number != 0)
	{
		while (number != 0) {
			remainder = number % 10;
			reverseString.append(std::to_string(remainder));
			number /= 10;
		}
	}
	else
	{
		reverseString = "0";
	}

	return reverseString;
}

//Function to initialize a random number
void cReverseTheNumber::InitRandomNumber(int number)
{
	mRandomNumber = number > 0 ? number : 0;
}

cReverseTheNumber::cReverseTheNumber()
	:mRandomNumber(0)
{
	InitRandomNumber(123);
}

cReverseTheNumber::cReverseTheNumber(int randomNumber)
{
	InitRandomNumber(randomNumber);
}

//Function to fetch the private member variable "mRandomNumber"
int cReverseTheNumber::GetRandomNumber()
{
	return mRandomNumber;
}

//Function to fetch the private member variable "mReversedNumberString"
std::string cReverseTheNumber::GetReversedNumberString()
{
	return mReversedNumberString;
}

//Function to set the factorial value to the private member variable "mFactorial"
void cReverseTheNumber::SetReversedNumberString(int number)
{
	mReversedNumberString = ReverseNumber(number);
}

//Function to set the instance of the class "cReverseTheNumber" through the interface
IReverseTheNumber* ReverseGivenNumber()
{
	return new cReverseTheNumber();
}

//Function to set the instance of the class "cReverseTheNumber" through the interface
IReverseTheNumber* ReverseGivenNumberWithParameter(int number)
{
	return new cReverseTheNumber(number);
}