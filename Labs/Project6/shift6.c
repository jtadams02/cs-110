#include <stdio.h>
#include <stdlib.h>
/*
            ORIGINAL FUNCTION
#include <stdio.h>

void shift(int *refX, int *refY, int *refZ);

int main() {
   int x, y, z;
   printf("Enter any three integers:\n");
   scanf("%d%d%d", &x, &y, &z);
   shift(&x, &y, &z);
   printf("The results after one shift: %d %d %d\n", x, y, z);
   shift(&x, &y, &z);
   printf("The results after another shift: %d %d %d\n", x, y, z);

   return 0;
}

void shift(int *refX, int *refY, int *refZ) {
   int tempx = *refX;
   int tempy = *refY;
   int tempz = *refZ;
   *refX = tempz;
   *refY = tempx;
   *refZ = tempy;
}
*/


// Fancy New Cool Function :)


int *shift(int arr[],int count, int size, int x);
void printArr(int arr[], int size);

int main(int argc, char *argv[]) 
{   
    if(argc!=2||atoi(argv[1])<2) // Makes sure input is valid
    {
        printf("Usage: './a 'number>1' '");
        return -1;
    }
    // Declaring Variables
    int inputArr[atoi(argv[1])];
    int shiftC = 1;
    int size = atoi(argv[1]);
    // Forming Array and printing for user
    printf("Enter any %d integers: \n",atoi(argv[1]));
    for(int i=0;i<atoi(argv[1]);i++)
    {
        scanf("%d",&inputArr[i]);
    }

    printf("Printing Array: \n{");
    for(int i=0;i<atoi(argv[1])-1;i++)
    {
        printf("%d, ",inputArr[i]);
    }
    // Determining number of right shifts
    printf("%d}\nEnter number of right shifts: ",inputArr[atoi(argv[1])-1]);
    scanf("%d",&shiftC);
    printf("The integers will be shifted %d times!\n",shiftC);
    // Recursive Function
    int *shifted = shift(inputArr,shiftC,size,0);
    // Print Results
    printf("The results after %d shifts:\n",shiftC);
    printArr(shifted, size);
  // free(shifted);
    return 0;
}

void printArr(int arr[],int size)
{
    printf("{");
    for(int i=0;i<size-1;i++)
    {   
        printf("%d, ",arr[i]);
    }
    printf("%d}",arr[size]);
}
int *shift(int arr[],int count, int size, int x)
{
    
    if(x>=count) // Base Case
    {
        return arr;
    } else 
    {
        // Simple shift sort ( was not simple to make :/ )
        int last = arr[size-1];
        int prev = arr[0];
        int temp = 0;
        for(int i=1;i<size;i++)
        {
            temp = arr[i];
            arr[i] = prev;
            prev = temp;
            

        }
        arr[0]=last;

    }
    // RECURSIVE CALL!
    return shift(arr,count,size,x+1);
}

/*
    Due to Mr. Gershmel's health issues we never got to cover recursion heavily in class, quizzes, or on project. 
    Recursion is one of the key concepts of computer science that I have some trouble wrapping my head around in all honesty. 
    So, I wanted to recreate one of our assignments using a recursive function to challenge myself. It probably is not any more efficient than another for loop,
    but I thought it would be a cool and unique way to do this project. 
    I had a lot of trouble wrapping my head around the recursion like I mentioned above, I restarted several times, deleted half of my code on numerous occasions, and had to
    take breaks away from my computer. However, after almost 5-6 hours I was able to produce a working program that would recursively shift an array based on an input which
    would create said array, and also shift that array as many times as a user wanted. The original assignment only had you needing to shift the number 2 times, 
    but now with how I recreated it, it will be able to shift as many times as the user wants through the shift input.
    I had planned to take create the array from a text file of numbers, so that this function may have more usability, 
    however with how complicated just the recursive and sort function was for me, I don't want to accidentally ruin it. 
    Overall, I came at this assignment in a new and different way to challenge myself and what I've learned this year, and it helps me prepare for the upcoming test as well.

*/