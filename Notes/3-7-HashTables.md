# Hash Tables
 
- ADT-Abstract Data Type
    1. Linked Lists (inefficient)
        - Insert in O(n)
        - Find in O(n)
        - Remove in O(n)
    2. Hash Tables
    3. Search Trees

## Hash Tables

- Hash tables are based on arrays
    - An array maps an index to a location
    - This index is an integer in a bounded range
- A hash table uses a hash function to map a key to a location
    - This key can be an unbounded integer, or even a non-integer type such as a string or float
    - The same hash function must be used during all operations (insert, find, remove)
    - {keys} -> {locations}

- Hash Function Examples
    1. If keys are unbounded integers 
        ` int H(int key) {return key % N;} `
         - Where N = size of the hash table (often a prime #)
    2. If keys are strings 
        ` int H(string key) { `
            `int sum = 0;`
            `for(int j=0;j<key.length; j++) `
                `sum = (C*sum+int(key[j]))%N;`
            `}`

# Hash Functions

    1. Ideally compute index = H(key) and then access the location or slot in the hash table array: Table[index]
    2. Collisions can occur
        - When hashing is the same as another value
        - Two ways to deal with it
            1. Closed Adressing: multiple values per index
                - Seperate Chaining
            2. Open Adressing: one value per index
                - Linear probing
                - Quadratic probing
                - Double hashing

### Seperate Chaining
- Suppose:
    1. n keys
    2. N slots
    3. H(key) = key % N
- Time per operation (insert, find, remove)
    1. Worst-case: O(n)
        - Insert is O(1)
    2. Average-case:
        - O(n/N)
        - Which is O(1) if n <= cN

## Open Addressing
- No seperate chains
- All keys will be stored in different indexes 
- One key per slot
### Linear Probing
- Analysis
    1. Time per operation
        - Worst case: O(n)
        - Average Case: O(1) if n<= N/2
        - Best Case: O(1)
        - Same for quadratic and double hashing
- Disadvantages
    1. Clustering
        - 


           
