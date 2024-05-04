Project_1 - Configuration And Deployment
by Max Sherwin(Student id : 1128059)

- Two classes are created : 
1. To find the Factorial of a number - "cFactorialFinder" - Static Library class
2. To find the reverse of any number and return a string value - "cReverseTheNumber" - Dynamic Library class

- Test Suite projects are created for each library with good cases and bad cases, also involving the use of test fixtures.

- An integration test suite project is created where the output of the factorial function is taken as the input for the reverse a number function. The output of the integration will result in a reversed number string.


- Also the DLL is loaded explicitly (i.e. No "dll_name.lib" file is used, instead LoadLibrary() and GetProcAddress() is used to fecth the dll methods)