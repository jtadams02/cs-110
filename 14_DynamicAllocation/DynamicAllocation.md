# Dynamic Allocation

* `malloc()` and `calloc` Allocates space on the heap instead of the stack
*  `free` De-allocates space on the heap

## Memory Leaks

Imagine we allocate data on the heap in a loop, we could allocate an undefined amount of space on the heap.
In order for the rest of the computer to have memory it can use, the program must also free that memory.
If we allocate memory that we do not free, we call that a memory leak.

To avoid memory leaks, all calls to `malloc` and `calloc` should be matched with an equivalent call to `free`

```
int *my_int = (int*) malloc(4);
// do stuff with my_int
free(my_int);
```

## Malloc

`malloc` is short for memory allocation. Its signature is:

`void* malloc(size_t size)`

* `void*` as the return type denotes that a memory address of unknown type will be returned.
* `size_t` is a numeric type to used for memory space
* `size` is the number of bytes to allocate
* **Note:** You must cast the returned value to the proper type
* **Note:** Malloc does not initialize the memory

### Usage

* Single Data
    * `double* my_double = (double*) malloc(sizeof(double));`
    * Note that we use `sizeof` to ensure we calculate the correct value regardless of differences in compilers
* Arrays
    * `int* my_array = (int*) malloc(sizeof(int) * array_size);`
    * Multiplying the size of the array by the size of a single element gives us the size of the entire array
 
      return 0;
}

## Calloc

Works like `malloc` while initializing all values to 0.

### Usage

`int* my_array = (int*) calloc(array_size, sizeof(int));`

* The size of an individual element and the number of elements are separated into separate arguments
* **Note: Still needs to be matched with a call to `free()`**