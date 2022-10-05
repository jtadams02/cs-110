# Conditionals

## Branches/Selections - Making a Decision
- A few options for if statements
```
if (expression) statement
```
```
if (expression) 
    statement1
else
    statement2
```
```
if (expression) {
    statement1
    ...more statements...
}
```
```
if (expression) {
    statement1
    ...more statements...
} else {
    statement2
    ...more statements...
}
```
```
if (expression) {
    statement_list
} else if (expression) {
    statement_list
} ...more else if...
else {
    statement_list
}
```

## Relational Operators
- `==` Returns true if the two values are equal
    - `5 == 5`  true    (1)
    - `3 == 7`  false   (0)
- `!=` Returns true if the two values are NOT equal
    - `3 != 9`  true    (1)
    - `4 != 4`  false   (0)
- `<`
- `<=`
- `>`
- `>=`

### Examples
```
score >= 60
b * b - 4 * a * c < 0
b * b != 4 * a * c
```

## Logical Operators

### Examples
```
0 <= score && score <= 100
score < 0 || score > 100
!(0 <= score && score <= 100)
```

## Operator Precedence
```
Arithmetic      //Highest
Relational
Logical         //Lowest
```

## Using Just an Arithmetic Expression
- The expression for a conditional can be a purely arithmetic expression
    ```
    if (num%2){} //if num is odd
    ```

## Flowchart
Sequence
```
    ↓
----------
| stmt 1 |
----------
    ↓
----------
| stmt 2 |
----------
    ↓
   ...
    ↓
----------
| stmt n |
----------
    ↓
```

Selection
- if with else
    ```
        ↓
    ----------
    |  expr  | --False--
    ----------         |
        ↓ True         ↓
    ----------     ----------
    | stmt 1 |     | stmt 2 |
    ----------     ----------
        |              |
        |<--------------
        ↓
    ```
- if without else
    ```
        ↓
    ----------
    |  expr  | --False--
    ----------         |
        ↓ True         |
    ----------         |
    | stmt 1 |         |
    ----------         |
        |              |
        |<--------------
        ↓
    ```

## Practice Problems
- Read a numeric score and print “pass” only
- Read a numeric score and print “pass” or “fail”
- Reads a numeric score and prints its letter grade, A, B, C, D or F
- Read a number and prints “odd” or “even”
- Read two integers and print the largest
- Read three integers and print the smallest
- Reads three integers and prints the range
- Read three integers and print a how many of them are the same (print “all three match” or “two match” or “no matches”)
- Reads three numbers and prints “ascending” if they are in strictly ascending order and “descending” if they are in strictly descending order and “no order” otherwise
