# Arrays in C

Arrays are a collection of identical elements
*We have used them for strings many times already!*

Memory is allocated for an array by allocating however much memory is needed for an array from the correct location. By default, arrays are allocated on the stack like any other variable. However they are very commonly allocated from the heap using malloc.
amogus

## Array Memory Layout

Arrays are stored with elements directly following one another with no extra padding. To visualize this lets refresh how variables are stored and take a look at an integer array.

Bits are the smallest unit of measurement and represent whether an electrical signal is present or not. If charge is being stored in memory we represent that as a `1` and if there is no charge we represent that as a `0`. We make up all data in the computer by grouping data together and processing it in different ways. 
```
|0|1|0|1|1|0|0|0|0|1|0|0|0|0|0|1|0|0|0|0|1|1|1|0 ....
```

Bytes (8 bits) are the smallest grouping of data we interact with from software. So we split our memory into chunks of 8.
```
     0xC4                 0xC5               0xC6
 0|1|0|1|1|0|0|0    0|1|0|0|0|0|0|1    0|0|0|0|1|1|1|0  .... // Raw data
[0,1,2,3,4,5,6,7]  [0,1,2,3,4,5,6,7]  [0,1,2,3,4,5,6,7]      // Byte offset indices
     [byte]             [byte]             [byte]
       88                 65                 14              // Decimal value
```
Size in computer science almost always refers to bytes, NOT bits. Modern computers have RAM sizes of around 8-16 GB. That is about 16 billion individual bytes.

Integers in C require 4 bytes. 
```
      0xC4              0xC5             0xC6            0xC7               // Address
 0|1|0|1|1|0|0|0  0|1|0|0|0|0|0|1  0|0|0|0|1|1|1|0  0|1|0|0|0|0|0|1 ....
 [      0      ]  [      1      ]  [      2      ]  [      3      ]         // Offset from start of integer to each byte
 [                           integer                              ]         
                            1480658497                                      // Integer value

```
Computers today are mostly 32 or 64 bit, which means memory addresses have to be less than n^32 or n^64 respectively. Our integer will take 4 bytes.

An array of 2 integers
      0xC4              0xC5             0xC6            0xC7               // Address
 0|1|0|1|1|0|0|0  0|1|0|0|0|0|0|1  0|0|0|0|1|1|1|0  0|1|0|0|0|0|0|1 ....
 [      0      ]  [      1      ]  [      2      ]  [      3      ]         // Offset from start of integer to each byte
 [                               0                                ] [ 1 ]   // Offset from start of array to integer
 [                           Array of two integers                      ]   // Integer value

## Allocating space for an array

We have two locations we can allocate space for an array (or any data), and each require slightly different code. 

### Stack 

When we declare an array the value stored in the variable is the memory address of the very start of the array. Memory address types look like regular types followed by a `*`. For example, an array of integers would have type `int *` because it the memory address for where the first integer of the array is stored. 

*To allocated on the stack you must know at compile time the size of the array*

```
int my_array[10];               // Declare array with no initialization. Allocates the next 40 bytes (4 bytes per integer) of the stack to this array but leaves its values untouched
int my_array[3] = {10, 20, 30}; // Declare and initialize the array on the stack. Puts the values 10, 20 and 30 onto the stack
int my_array[5] = {0};          // Allocates the next 5 integers from the stack to this array and initializes all elements to 0 
```

The first and most common option is the stack. The stack is a growable area of the memory that our program is using. It is called the stack because of how it is grown and used. Think of a stack of plates. Whenever you add a plate to the stack it grows by some amount, and that same plate will be the first removed. This ordering is known as last in first out, or LIFO.
```
[ data 1 ]   
------------
[ data 1 ] [ data 2 ]               // Add 2 to the stack
------------
[ data 1 ] [ data 2 ] [ data 3 ]    // Add 3 to the stack
------------
[ data 1 ] [ data 2 ]               // Pop the top of the stack (3)
```

All of this is managed by the compiler and operating system for you. You simply declare the name of each chunk of data (this is a variable). When we allocate an array, N data chunks are added to the stack and we can access their memory from the address stored in our array variable.

### Heap

If the size of your array is not known at compile time then you will need to allocate on the heap instead. Think of the heap as a large area of memory that we can interact with a bit more freely, with the risks that carries. Future lectures will cover heap allocation.

## Accessing an Array

When using arrays we typically want to treat the array as a list of values that we can look at individually or in order *(Don't use the word list to describe an array as that refers to a different data type)*. To be able to access each element of the array using only the memory address that the entire array starts with we have the following two approaches.

### Using the memory address

```
*(my_array + offset); 
```
This is the direct approach. We add the offset to the arrays start location to get the location of the element we want. For the first element of the array for example we would give it no offset. Once we have the memory address of the element we want we need to *dereference* the address using the `*` symbol. This symbol opens up a memory address and gives us the value inside. Because the type of the array is known, offset will add values multiplied by the size of an indiviudal element (4 bytes for an integer).

Here is an example:
```
int my_ints[4] = {2, 4, 8, 16}; // Array with numbers inside
int first = *(my_ints + 0);     // Access the element offset by 0 elements in the array (2)
int last  = *(my_ints + 3);     // The last element is 3 offsets away from the start. 
```
*Note that if we go 4 offsets away we are at the end of the array and starting to read unknown memory*

### Using the `[]` notation

```
my_array[offset];
```

The direct approach is hard to read and a very common occurance so we syntactic sugar that allows square brackets to be converted to the first form. This makes it very easy to access arrays.

Here is an example:
```
int my_ints[4] = {2, 4, 8, 16}; // Array with numbers inside
int first = my_ints[0];         // Access the element offset by 0 elements in the array (2)
int last  = my_ints[3];         // The last element is 3 offsets away from the start. 
```
*Note that because we use offsets the first element is at index **0** and not index 1. Additionally the length of any array will be 1 more than the maximum index*

## Using Arrays

We can make arrays from any data type:
* `int` - 4 bytes per element
* `char` - 1 byte per element
* `float` - 4 bytes per element
* `double` - 8 bytes per element
* User definied types using `typedef`
    * Covered in the `structs` section of the course
* Pointers
    * Store arrays of pointers for manipulation
    * Store arrays of other arrays
        * 2D, 3D ... n Dimensional arrays

## Practice Problems
* Read in 5 numbers to an array and find the mean, variance and std dev
* Without using the `[]`, complete the previous problem