# Variables

## Daily Notes
- `gcc -Wall filename` Turns all warnings on
- `gcc filename -o xxx` Names the executable "xxx"

## Variable Overview
- **Variable:** a named location for storing a variable
- In C, you must **declare** a variable before you can use it. The decelaration establishes the **name**, **type**, and sometimes the initial **value** as well.
    ```
    int num; 		//type name;
    int num = 5; 	//type name = value;
    ```
- Each variable contains a **name**, **type**, and **value**
- Think of a variable as a box containing data
    ```
           total
           ------
    0x4325 | 42 | (Integer)
           ------
    ```
    - Name: total
    - Type: Integer (int)
    - Value: 42
    - Location: 0x4325
- Each variable has the following attributes:
    - A **name**, which enables you to differentiate one variable from another
	- A **type**, which specifies what type of value the variable can contain
	- A **value**, which represents the current contents of the variable
- The name and type of a variable are fixed. The value changes whenever you **assign** a new value to the variable
- **Scope** Variables are only usable in the scope that they are created.

## Data Types
- C defines a set of **primitive types** to represent simple data.
    - `int` This type is used to represent integers, which are whole numbers such as *17* or *-53*.
	- `float` This type is used to represent numbers that include a decimal fraction, such as *3.14159265*.
	- `double` This type is the same as a float but with double the precision.
	- `char` This type represents a single ASCII character. ('A', '.')
- C Types can be modified using `long`, `short`, and `unsigned`
    - `long` Doubles the space available for the variable data
    - `short` Halves the space available for the variable data
    - `unsigned` Positive values only
- Many data types are represented using structures containing **primitive types**.

## Operators and Operands
- **Arithmetic expressions**
    - `+` Addition
	- `-` Subtraction
	- `*` Multiplication
	- `/` Division
	- `%` Remainder
- Operators in C usually appear between two subexpressions, which are called its **operands**. Operators that take two operands are called **binary operators**.
- The `-` operator can also appear as a **unary operator**, as in the expression `-x`, which denotes the negative of `x`.

## The Pitfalls of Integer Division
Consider the following C++ statements, which are intended to convert 100 Celsius to Fahrenheit:
    ```
	double c = 100;
	double f = 9 / 5 * c + 32;
	```
The computation consists of evaluating the following expression:
```
9 / 5 * c + 32
  1 * 100 + 32
    100   + 32
	    132
```

## Division and Type Casts
- In C, the result will be `int` if both operands are of type `int`, but will be a `double` if *either* operand is a `double`
- For example, `14 / 5` returns 2 instead of 2.8 because both operands are of type `int`, so C++ computes an integer result by throwing away the fractional part.
- If you want double division, at least one operand needs to be a `double`, as in `((double) 14) / 5` or `14 / 5.0`
The first example is called a **type cast**

## The Modulus Operator
- The only arithmetic operator that has no direct mathematical counterpart is %, which applies only to integer operands and computes the remainder of the division:
    - `14 % 5` returns `4`
	- `14 % 7` returns `0`
	- `7 % 14` returns `7`
- The result of the `%` operator make intuitive sens only if both operands are positive.

## Precedence
- If an expression contains more than one operator, C++ uses **precedence rules** to determine the order of evaluation.
    ```
      unary-     //Highest
    *   /   %
      +   -      //Lowest
    ```
    C++ evaluates any unary `-` operators first, followed by the operators `*`, `/`, and `%`, and finally the operators `+` and `-`.
- C++ evaluates expressions from left to right.
- Parentheses may be used to change the order of operations

## Assignment Statements
- You can change the value of a variable in your program by using an **assignment statement**, which has the general form:
    ```
	variable = expression;
	```
- An assignment statement computes the value of the expression and assigns the value to the variable
	`total = total + value;`
- When you assign a new value to a variable, the old value of that variable is lost

### Shorthand Assignments
- Statements such as `total = total + value;` are so common that C allows the following shorthand form: `total += value;`
- The general form of a **shorthand assignment** is
    ```
	variable op= expression;
	```
	where `op` is any of C++'s binary operators. The effect of this statement is the same as
	```
	variable = variable op expression;
	```
	For example, the following statement multiplies `salary` by 2.
	```
	salary *= 2;
	```

### Increment and Decrement Operators
- **increment operator**:
    ```
    x++;
	```
	This statement is equivalent to
	```
	x += 1;
	```
	or in an even longer form
	```
	x = x + 1;
	```
- The `--` operator (the **decrement operator**) subtracts one.

