// Name:					Scott Corbett
// College ID:				0561772
// Telephone:				848-391-6953
// Email:					secorbett13@gmail.com
// College and Semester:	TESC, July 2014
// Course Code:				COS-213-GS007
// Course Name:				C++ Programming
//
// Assignment 4A
//	Determine whether the following statements are
//	true or false. If an answer is true, explain why and, where
//	appropriate, provide an example. If the answer is false, please
//	explain why.

#include <iostream>

// 1.  Constructors can have names different from their classes.
//		False. Constructors must have the same name as the class. 

// 2.  Destructors must have the same name astheir class, preceded by a tilde (~).
//		True. Destructors and constructors have the same name as their class. The ~
//		symbol is the complement operator which is why it makes sense to decorate
//		a destructor with as it "complements" the constructor. Below is an example.

class Question2Class
{
public:
	Question2Class();
	~Question2Class();
};

// 3.  Destructors have default arguments.
//		False. Destructors do not take any arguments.

// 4.  A destructor must be declared for each class.
//		False. If the class definition does not include a desctructor, a default constructor
//		is created for the class by the compiler.

// 5.  If a program uses the delete operator, a destructor is not needed.
//		False (sort of). The delete operator deallocates dynamically allocated memory when called.
//		Any class that includes dynamically allocated memory should definitely include a desctructor, so
//		it is good coding to include a desctructor for those classes.

// 6.  Explicit constructors need to be included in every class.
//		False. The compiler will create a default constructor for a class if no explicit definition
//		has been added in the code.

// 7.  Destructors are declared with a return type.
//		False. Like constructors, destructors do not have return types. Upon examination, it makes no
//		sense for a desctructor to return anything as the class instance is gone after the desctructor
//		exits.

// 8.  Destructors are called each time an object goes out of existence.
//		True. Desctructors are called for a class when it passes out of scope. However, calling the
//		desctructor does not release the object's memory.

// 9.  A class can have more than one constructor function.
//		True. A class can have any number of constructors. These constructors can take different arguments
//		Below is an example.
class Question9
{
public:
	Question9();
	Question9(int);
	Question9(int, double);
	Question9(int, double, bool);
private:
	int fieldOne;
	double fieldTwo;
	bool fieldThree;
};

// 10. A class can have several default constructor functions.
//		False. Classes can only have one default constructor. This constructor needs to have no arguments
//		or have defaults for all of the arguments.

// 11. Default constructors can have no parameters or all parameters must have
//	   default values.
//		True. Default constructors must have no parameters or all parameters have a default value so that
//		they can be called without arguments. The constructors might look like:
class Question11A
{
public:
	Question11A();
};

class Question11B
{
public:
	Question11B(int argOne = 1, double argTwo = 1.234);
};

// 12. Constructors need to be declared for each class.
//		False. The compiler will create a default constructor if no constructor is defined for the class.

// 13. Constructors are declared with return types.
//		False. Constructors do not have return types. Essentially, the class instance returned is the return
//		type for the constructor.

// 14. Constructors are automatically called when objects are created.
//		True. Depending upon the arguments provided to a constructor, the specific definition will be called.
//		For example, the first constructor below will be called when there are no arguments provided and the
//		second when a single argument is provided.
class Question14
{
public:
	Question14()
	{
		std::cout << "Calling default constructor";
	}

	Question14(int firstArg)
	{
		std::cout << "Called constructor with one arguent: " << firstArg;
	}
};

// 15. A class can have many destructor functions.
//		False. At most a class can only have one desctructor. This is inherent in the requirement
//		that destructors have no return type and no parameters.

// Program execution method
int main()
{
	return 0;
}
