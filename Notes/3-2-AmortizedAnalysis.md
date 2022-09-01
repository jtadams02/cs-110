# Amortized Analysis and Dynamic Arrays

- Cost per-operation over a sequence of operations
    1. Can take the total work for N operations and divide by N, i.e. average cost per operation
    2. Different than average case
        - We don't average over the possible inputs
        - Still consider worst case input
- Σ^logN^~i=0~ N/2^i^
- So the total work = 2N

# Binary Counter Banker's Method

- Different Idea - Assume the computer runs on tokens
    1. Give each operation 2 tokens. Pay for the conversion of the 0 into a 1 with a token and store the remaining token there
    2. All the other costs are turning 1's into 0's. Pay for those with the token stored there. 
- Basically ensures that every time you only pay 2 tokens (2 Operations) per call. Every value has an additonal token which it uses to flip again. 
 
# **Dynamic Arrays**

- Suppose we want to implement arrays without a fixed size limit
    1. insert operation adds a new element to the end of the array
    2. Why, when, and how much
        - When do we 're-size' the array?
            - When its Full
        - How much space do we add?
            - **DOUBLE**
        - Why?
    3. Cost: N=2^k^
        - Sum = 




