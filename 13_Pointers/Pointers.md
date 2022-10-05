# Pointers

To understand pointers it is best to first review how standard variables are stored.

## Review of variable's memory

Variables store data of some specific type of a known size at a known location in memory. To visualize this:

```
name    data     location     type
var  [0|0|0|15]  0xffffcc3c  int
         ↓ 
[00000000|00000000|00000000|00001111]
     1       2         3        4      bytes  
```

The variable named `var` of type `int` is stored at memory location `0xffffcc3c`. This means our variable stores three things:
* A name
* A location
* A type
The type gives us our size. In our example we are using `int` which is a 32 bit integer. We measure size in bytes however, so we split our integer into 4 bytes for portioning of memory. The integer is represented by the contents of all 32 bits, meaning the maximum value that could be stored is `4,294,967,296`. 

This variable we assume will be on the stack created by a line such as:

```
int var=15, v2=6, v3=2;
```
When these variables come into scope they are allocated on the stack which could be viewed as:

```
data       physical location      name saved by OS
--------------------------------------------------
[ | | |15] 0xffffcc3c             //var
[ | | | 6] 0xffffcc40             //v2
[ | | | 2] 0xffffcc44             //v3
```
This shows how the memory is laid out from the perspective of the system. Now imagine instead of storing a number we instead store the address of another:
```
data        physical location      name saved by OS
--------------------------------------------------
[      15]  0xffffcc3c             //var
[ 0xffff ]  0xffffcc40             //v2
[ 0xcc3c ]               
[       2]  0xffffcc48             //v3
```
Notice that `v2` neads twice as much space to store the entire address of another variable, so there are now 8 bytes between the start of v2 and v3.
We could use the sizeof function to confirm this, for example `sizeof(var)` would return `4` and `sizeof(v2)` woudl return `8`.

## Pointers

`v2` is now what we call a pointer, this is how it is done in C:
```
int var=15;
int *v2 = &var;
```

'`int *`' tells the compiler that this is a variable that will store a memory address that in turn will store an integer.The `&` is used to get the memory address that `var` is stored at.

If we want to find out what is inside of the address our pointer is storing we use the `*` character to **dereference** the pointer. For example, to print what is stored at this address we do the following.

```
printf("%d", *v2);
```
This would print `15`, however if we wanted to print what was stored at this variable we use `%p`. For example:
```
printf("@%p: %p -> %d", &v2, v2, *v2);
```
Think of the two operators `&` and `*`  as opposites. `&` gives us a memory address from a variable regardless of what type that variable is (maybe even a pointer variable). `*` gives us the value stored at the address we provide it. The C compiler will not allow us to dereference a variable that is not a pointer.

*Note that integers are stored using twos compliment so the actual bits would be saved using a different encoding*

## Uses of Pointers

There are two major advantages pointers can provide. 
* Pass large amount of data to functions
* Manipulate variables outside of the scope they were created in

The first of these advantages is done with arrays. The syntax `int arr[]` as a parameter is really just `int *arr`, a pointer to some memory that holds an integer. We know based on the size we created the array at how many integers will be in memory after that first integer. So if we calculate that address it might look like:

`arr + 3`

If `arr` stored `0xffffcc30` then `arr+3` would be `0xffffcc3c`. This is **12** bytes away because each value of the array takes four bytes.

`arr + 3 -> 0xffffcc30 + (sizeof(arr type) * 3)`

If we dereference this memory address we would get the 4th value in the array because adding 0 would get us our first.

```
int arr[5] = {128, 64, 32, 16, 8};
int value  = *(arr + 3);            // value = 16 
```

The syntax we have been using: `arr[3]` is just a shorthand way of writing the same thing. This also explains why when we pass arrays to functions the arrays contents can be modified by the function but a regular variable can't. However a pointer to a regular variable could accomplish the same.

## Changing variables outside their original scope

A function to calculate minmmum and maximum values in an array for example wouldn't be able to return both answers. To get around this, or to pass in any variables we want to have their contents modified by a function we can pass the address of the variable instead.

```
void min_max(int arr[], int a_size, int *min, int *max);

int main () {
    int arr[5] = {128, 64, 32, 16, 8};
    int m1, m2;
    min_max(arr, 5, &m1, &m2);
    //m1 = 8
    //m2 = 128
}
```

Even though the variables `m1` and `m2` were created in main, min_max was able to modify their values by using their memory addresses. This way we can pass as many variables as we want **updated** by a function as we desire.

## Other Uses
Other uses of pointers include for other data types that contain large amounts of storage, or data structures that link together addressess in unique ways.