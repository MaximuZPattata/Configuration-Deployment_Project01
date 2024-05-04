//This project is created to integrate and test the functionalities of both the classes(cFactorialFinder and cReverseTheNumber)

#include<iostream>
#include<gtest/gtest.h>
#include<cReverseTheNumber.h>
#include<cFactorialFinder.h>
#include<Windows.h>

//Loading DLL Explicitly..

//Defining pointers for the class "cReverseTheNumber"
typedef cReverseTheNumber* (*ReverseNumPointerWithParam)(int randomNum);

//Creating test fixture..
struct sStaticLibDynamicLibIntegrationTestFixture : testing::Test
{

public:
	//cReverseTheNumber* reverseNumberObj;
	HMODULE hMod;

	cReverseTheNumber* reverseNumberObj;
	cFactorialFinder* factorial;

	virtual ~sStaticLibDynamicLibIntegrationTestFixture()
	{

	}

	void SetUp()
	{
		//Default factorial value is initialized
		factorial = new cFactorialFinder();
		factorial->SetFactorial(factorial->GetRandomNumber());

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
				//The output of the default factorial value is taken as input for teh ReverseTheNumber logic
				reverseNumberObj = ReverseNumber(factorial->GetFactorial());
				reverseNumberObj->SetReversedNumberString(reverseNumberObj->GetRandomNumber());
			}
		}
	}

	void SetUp(int randomNumber)
	{
		factorial = new cFactorialFinder(randomNumber);
		factorial->SetFactorial(factorial->GetRandomNumber());

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
				//The output of the initialized factorial value is taken as input for the ReverseTheNumber logic
				reverseNumberObj = ReverseNumber(factorial->GetFactorial());
				reverseNumberObj->SetReversedNumberString(reverseNumberObj->GetRandomNumber());
			}
		}
	}

	virtual void TearDown()
	{
		FreeLibrary(hMod); //Destroying the explicit load address
		delete reverseNumberObj, factorial;
	}
};

//Good Cases : 

//This test is to make sure the default number when processed through factorial logic and reverse number logic is reflected as "021" string
TEST_F(sStaticLibDynamicLibIntegrationTestFixture, CheckDefaultFactorialReversedIs021)
{
	SetUp();

	EXPECT_EQ(reverseNumberObj->GetReversedNumberString(), "021");
}

//This test is to make sure the number intialized as 11 when processed through factorial and reverse number logic is reflected as "00861993" string
TEST_F(sStaticLibDynamicLibIntegrationTestFixture, ForInitializedNumber11FactorialReversedIs00861993)
{
	SetUp(11);

	EXPECT_EQ(reverseNumberObj->GetReversedNumberString(), "00861993");
}

//This test is to make sure the number if initialized to a negative integer and processed through factorial and reverse number logic 
// will always reflect as "0" string
TEST_F(sStaticLibDynamicLibIntegrationTestFixture, NegativeIntegerInitializedShouldResultIn0)
{
	SetUp(-1);

	EXPECT_TRUE(reverseNumberObj->GetReversedNumberString() == "0");

	SetUp(-100);

	EXPECT_TRUE(reverseNumberObj->GetReversedNumberString() == "0");
}

//This test is to make sure the number if initialized to a 0 and processed through factorial and reverse number logic 
// will always reflect as "0" string
TEST_F(sStaticLibDynamicLibIntegrationTestFixture, Integer0InitializedShouldResultIn0)
{
	SetUp(0);

	EXPECT_TRUE(reverseNumberObj->GetReversedNumberString() == "0");
}

//Bad Cases :

//This test is to make sure the default number processed through factorial and reverse number logic is set to fail.
//Anything other than "021" string fails.
TEST_F(sStaticLibDynamicLibIntegrationTestFixture, ExpectDefaultFactorialReversedToFail)
{
	SetUp();

	EXPECT_FALSE(reverseNumberObj->GetReversedNumberString() == "21");

	EXPECT_FALSE(reverseNumberObj->GetReversedNumberString() == "210");

	EXPECT_FALSE(reverseNumberObj->GetReversedNumberString() == "120");

	EXPECT_FALSE(reverseNumberObj->GetReversedNumberString() == "0021");
}

//This test is to make sure the initialized number processed through factorial and reverse number logic is set to fail.
TEST_F(sStaticLibDynamicLibIntegrationTestFixture, ExpectFactorialOfInitializedNumberWhenReversedToFail)
{
	SetUp(11);

	EXPECT_FALSE(reverseNumberObj->GetReversedNumberString() == "861993");

	EXPECT_FALSE(reverseNumberObj->GetReversedNumberString() == "00861");

	EXPECT_FALSE(reverseNumberObj->GetReversedNumberString() == "00861");

	EXPECT_FALSE(reverseNumberObj->GetReversedNumberString() == "00861");
}

//This test is to make sure the number if initialized to a 0 and processed through factorial and reverse number logic 
// will always reflect as "0" string and not as "Null" or "NULL"
TEST_F(sStaticLibDynamicLibIntegrationTestFixture, ExpectToFailWhenInitializedNumberTo0AndCheckedWithNull)
{
	SetUp(0);

	EXPECT_FALSE(reverseNumberObj->GetReversedNumberString() == "Null");

	EXPECT_FALSE(reverseNumberObj->GetReversedNumberString() == "NULL");
}

int main(int argc, char** argv) {

	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();

	return 0;
}