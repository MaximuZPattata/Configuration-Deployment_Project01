#pragma once

#define DLLExport _declspec ( dllexport )

#include<string>

//Creating Interface for the class cReverseTheNumber
extern "C" __declspec (dllexport) class IReverseTheNumber
{
public:

    virtual ~IReverseTheNumber() {};

    virtual int GetRandomNumber() = 0;
    virtual std::string GetReversedNumberString() = 0;
    virtual void SetReversedNumberString(int randomNumber) = 0;
};

//The class is created to reverse any given integer and return it as a string
extern "C" __declspec (dllexport) class cReverseTheNumber : public IReverseTheNumber
{
private:

    int mRandomNumber;
    std::string mReversedNumberString;

    //Method to reverse any given integer
    std::string ReverseNumber(int randomNumber);

    //Method to initialize a random number by hardcoding 
    void InitRandomNumber(int randomNumber);

public:

    //Constructors
    cReverseTheNumber();
    cReverseTheNumber(int randomNumber);

    virtual ~cReverseTheNumber() {};

    //GetterFunctions
    virtual int GetRandomNumber();
    virtual std::string GetReversedNumberString();

    //SetterFunction
    virtual void SetReversedNumberString(int randomNumber);
};

extern "C" _declspec (dllexport) IReverseTheNumber * ReverseGivenNumber();
extern "C" _declspec (dllexport) IReverseTheNumber * ReverseGivenNumberWithParameter(int number);
