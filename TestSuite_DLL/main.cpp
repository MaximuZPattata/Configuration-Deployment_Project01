//This project is created to test the functionalities of the class cReverseTheNumber 


#include<iostream>
#include<gtest/gtest.h>
#include<cReverseTheNumber.h>
#include<Windows.h>

//Loading DLL Explicitly..

//Defining pointers for the class "cReverseTheNumber"
typedef cReverseTheNumber* (*ReverseNumPointer)();
typedef cReverseTheNumber* (*ReverseNumPointerWithParam)(int randomNum);

//Creating test fixture..
struct sReverseANumberTestFixture : testing::Test
{

public:
	//cReverseTheNumber* reverseNumberObj;
	HMODULE hMod;

	cReverseTheNumber* reverseNumberObj;

	virtual ~sReverseANumberTestFixture()
	{

	}

	void SetUp()
	{
		//Local address trajectory
		hMod = LoadLibrary(TEXT("..\\x64\\Debug\\ReverseTheNumber_DLL.dll"));

		if (hMod == NULL)
		{
			std::cout << "Failed to load DLL\n\n";
		}
		else
		{
			//Reading function's address through GetProcAddress()
			ReverseNumPointer ReverseNumber = (ReverseNumPointer)GetProcAddress(hMod, "ReverseGivenNumber");

			if (ReverseNumber == NULL)
			{
				std::cout << "Function load failed !\n\n";
			}
			else
			{

				reverseNumberObj = ReverseNumber();
				reverseNumberObj->SetReversedNumberString(reverseNumberObj->GetRandomNumber());
			}
		}
	}

	void SetUp(int randomNumber)
	{
		//Local address trajectory
		hMod = LoadLibrary(TEXT("..\\x64\\Debug\\ReverseTheNumber_DLL.dll"));

		if (hMod == NULL)
		{
			std::cout << "Failed to load DLL\n\n";
		}
		else
		{
			//Reading function's address through GetProcAddress()
			ReverseNumPointerWithParam ReverseNumber = (ReverseNumPointerWithParam)GetProcAddress(hMod, "ReverseGivenNumberWithParameter");

			if (ReverseNumber == NULL)
			{
				std::cout << "Function load failed !\n\n";
			}
			else
			{
				reverseNumberObj = ReverseNumber(randomNumber);
				reverseNumberObj->SetReversedNumberString(reverseNumberObj->GetRandomNumber());
			}
		}
	}

	virtual void TearDown()
	{
		FreeLibrary(hMod); //Destroying the explicit load address
		delete reverseNumberObj;
	}
};

//Good Cases : 

//This test is to make sure the default number initialized is 123
TEST_F(sReverseANumberTestFixture, CheckDefaultNumberIs123)
{
	SetUp();
	EXPECT_EQ(reverseNumberObj->GetRandomNumber(), 123);
}

//This test is to make sure the number initialized by hardcoding is reflected as 550
TEST_F(sReverseANumberTestFixture, InitializeNumberTo550)
{
	SetUp(550);
	EXPECT_EQ(reverseNumberObj->GetRandomNumber(), 550);
}

//This test is to make sure the default number when going through the reverse number logic  becomes "321" string
TEST_F(sReverseANumberTestFixture, DefaultValueReversedIs321)
{
	SetUp();
	EXPECT_EQ(reverseNumberObj->GetReversedNumberString(), "321");
}

//This test is to make sure initializing the number with a negative number should return zero
TEST_F(sReverseANumberTestFixture, InitializingWithNegativeIntegerReturnsZero)
{
	SetUp(-56);
	EXPECT_EQ(reverseNumberObj->GetRandomNumber(), 0);
}

//This test is to make sure '0' is not omitted when reversing a number like '500'
TEST_F(sReverseANumberTestFixture, NumberReversedShouldNotOmitZero)
{
	SetUp(500);
	EXPECT_EQ(reverseNumberObj->GetReversedNumberString(), "005");
}

//Bad Cases : 

//This test is to make sure the default number is set to fail. So anything other than 123 fails. 
TEST_F(sReverseANumberTestFixture, ExpectDefaultNumberToFail)
{
	SetUp();
	EXPECT_FALSE(reverseNumberObj->GetRandomNumber() == 10);
}

//This test is to make sure the initialized number is set to fail. So anything other than the initialized number fails.
TEST_F(sReverseANumberTestFixture, ExpectInitializedNumberToFail)
{
	SetUp(10);
	EXPECT_FALSE(reverseNumberObj->GetRandomNumber() == 20);
}

//This test is to make sure the default number when processed through the reverse number logic is set to fail. Anything other than "321" fails. 
TEST_F(sReverseANumberTestFixture, ExpectDefaultNumberReversedToFail)
{
	SetUp();
	EXPECT_FALSE(reverseNumberObj->GetReversedNumberString() == "130");

	EXPECT_FALSE(reverseNumberObj->GetReversedNumberString() == "0");

	EXPECT_FALSE(reverseNumberObj->GetReversedNumberString() == "NULL");

	EXPECT_FALSE(reverseNumberObj->GetReversedNumberString() == " ");

	EXPECT_FALSE(reverseNumberObj->GetReversedNumberString() == "123");
}

//This is to test if none of the zeroes are omitted when reversing a number like 1000
TEST_F(sReverseANumberTestFixture, ExpectInitializedNumberReversedToFail)
{
	SetUp(1000);
	EXPECT_FALSE(reverseNumberObj->GetReversedNumberString() == "001");

	EXPECT_FALSE(reverseNumberObj->GetReversedNumberString() == "01");

	EXPECT_FALSE(reverseNumberObj->GetReversedNumberString() == "000");

	EXPECT_FALSE(reverseNumberObj->GetReversedNumberString() == "1");

	EXPECT_FALSE(reverseNumberObj->GetReversedNumberString() != "0001");
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();

	return 0;
}