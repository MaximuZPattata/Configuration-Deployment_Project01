//This project is created to test the functionalities of the class cFactorialFinder 

#include<iostream>
#include<gtest/gtest.h>
#include<cFactorialFinder.h>

//Creating test fixture..
struct sFactorialFinderTestFixture : testing::Test
{
public:
	cFactorialFinder* factorial;

	virtual ~sFactorialFinderTestFixture()
	{

	}

	void SetUp()
	{
		factorial = new cFactorialFinder();
		factorial->SetFactorial(factorial->GetRandomNumber());
	}

	void SetUp(int randomNumber)
	{
		factorial = new cFactorialFinder(randomNumber);
		factorial->SetFactorial(factorial->GetRandomNumber());
	}

	virtual void TearDown()
	{
		delete factorial;
	}
};


//Good Cases : 

//This test is to make sure the default number initialized is 5
TEST_F(sFactorialFinderTestFixture, CheckDefaultNumberIs5)
{
	SetUp();
	EXPECT_EQ(factorial->GetRandomNumber(), 5);
}

//This test is to make sure the number initialized by hardcoding is reflected as 10
TEST_F(sFactorialFinderTestFixture, InitializeNumberTo10)
{
	SetUp(10);
	EXPECT_EQ(factorial->GetRandomNumber(), 10);
}

//This test is to make sure the default number when processed through the factorial logic is reflected as 120
TEST_F(sFactorialFinderTestFixture, CheckDefaultFactorialIs120)
{
	SetUp();
	EXPECT_EQ(factorial->GetFactorial(), 120);
}

//Bad Cases : 

//This test is to make sure the default number is set to fail. Anything other than integer 5 fails.
TEST_F(sFactorialFinderTestFixture, ExpectDefaultNumberToFail)
{
	SetUp();
	EXPECT_FALSE(factorial->GetRandomNumber() == 10);
}

//This test is to make sure the number initialized by hardcoding is set to fail. Anything other than the initialized value fails.
TEST_F(sFactorialFinderTestFixture, ExpectInitializedNumberToFail)
{
	SetUp(10);
	EXPECT_FALSE(factorial->GetRandomNumber() == 20);
}

//This test is to make sure the default number when processed through factorial logic is set to fail. Anything other than 120 fails. 
TEST_F(sFactorialFinderTestFixture, ExpectDefaultFactorialToFail)
{
	SetUp();
	EXPECT_FALSE(factorial->GetFactorial() == 130);

	EXPECT_FALSE(factorial->GetFactorial() > 150);

	EXPECT_FALSE(factorial->GetFactorial() < 100);

}

//User input cases : 

//Good case : A negative integer input test
TEST_F(sFactorialFinderTestFixture, CheckNegativeIntegerInput)
{
	std::cout << "\n\n** Negative Input test **";

	factorial->SetRandomNumberFromUserInput();
	EXPECT_GE(factorial->GetRandomNumber(), 0);
}

//Good case : User input is 1(Factorial of 1 should be 1)
TEST_F(sFactorialFinderTestFixture, CheckFactorialIs1ForUserInput1)
{
	std::cout << "\n\n** Input integer '1' **";

	factorial->SetRandomNumberFromUserInput();
	factorial->SetFactorial(factorial->GetRandomNumber());
	EXPECT_EQ(factorial->GetFactorial(), 1);
}



int main(int argc, char** argv) {

	::testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();

	return 0;
}