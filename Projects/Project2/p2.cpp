#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <limits.h>
#include <string.h>


using namespace std;

int argCheck(int argc,char* argv[]);
void intSort(ifstream& file1, ifstream& file2);
void strSort(ifstream& file1, ifstream& file2);
void MergeSort(int numbers[], int i, int k);
void Merge(int numbers[], int i, int j, int k);
void MergeSortS(string numbers[], int i, int k);
void MergeS(string numbers[], int i, int j, int k);



int main(int argc, char* argv[])
{
    int check = argCheck(argc,argv);
    if(check<0){return check;}

    //SETUP FILES
    ifstream file1;
    file1.open(argv[2]);
    if(file1.fail())
    {
        cout << "File 1 does not exist" << endl;
        return -10;
    }
    ifstream file2;
    file2.open(argv[3]);
    if(file2.fail())
    {
        cout << "File 2 does not exist" << endl;
        return -5;
    }
    
    //INTS OR STRINGS
    char sOri = argv[1][0];
    bool isString = false;
    if(sOri=='s')
    {
        isString = true;
    }
    string strArr[20000];
    int intArr[20000];
    if(isString == true){
        //String input
        strSort(file1,file2);
       // cout << "Getting String input" << endl;

    } else {
        //Int input
        intSort(file1,file2);
    }

    return 0;
}

int argCheck(int argc,char* argv[]){
    if(argc!=4)
    {
        cout << "Not enough arguments! (Must have 4)" << endl;
        return -1;
    }
    //cout << argv[1][0] << endl;
    if(argv[1][0]!='i'&&argv[1][0]!='s')
    {
        cout << "Second argument must contain 's' or 'i'" << endl;
        return -2;
    }
    return 0;
}

void intSort(ifstream& file1, ifstream& file2)
{
    int ints[20000];
    int intInput1[20000];
    int intInput2[20000];

    int counter1 = 0;
    int counter2 = 0;
    int finalCounter = 0;
    while(!file1.eof())
    {
        
        int x;
        file1 >> x;
        if(!file1.good()){break;}
        intInput1[counter1] = x;
        counter1++;

    }
    while(!file2.eof())
    {
        int y;
        file2 >> y;
        if(!file2.good()){break;}
        intInput2[counter2] = y;
        counter2++;
    }
    for(int i=0;i<counter1;i++)
    {
        bool isCommon = false;
        int select = intInput1[i];
        for(int j=0;j<counter2;j++)
        {
            if(select == intInput2[j])
            {
                isCommon = true;
            }
        }
        if(isCommon)
        {
            bool isDouble = false;
            for(int i=0;i<finalCounter;i++)
            {
                if(select==ints[i])
                {
                    isDouble=true;
                }
            }
            if(!isDouble)
            {
                ints[finalCounter] = select;
                finalCounter++;
            }
        }
    }
    MergeSort(ints,0,finalCounter-1);
   // cout << endl << "SORTED" << endl;
    for(int i=0;i<finalCounter;i++){
        cout << ints[i] << endl;
    }

}

void strSort(ifstream& file1, ifstream& file2)
{
    string strings[20000];
    string strInput1[20000];
    string strInput2[20000];
    int finalCounter=0;
    int counter1=0;
    int counter2=0;
    while(!file1.eof())
    {
        
        string x;
        file1 >> x;
        if(!file1.good()){break;}
        strInput1[counter1] = x;
      //  cout << strings[counter] << endl;
        counter1++;

    }
    //cout << endl << "Next file" << endl;
    while(!file2.eof())
    {
        string y;
        file2 >> y;
        if(!file2.good()){break;}
        strInput2[counter2] = y;
       // cout << strings[counter] << endl;
        counter2++;
    }
    for(int i=0;i<counter1;i++)
    {
        bool isCommon = false;
        string select = strInput1[i];
        for(int j=0;j<counter2;j++)
        {
            if(select == strInput2[j])
            {
                isCommon = true;
            }
        }
        if(isCommon)
        {
            bool isDouble = false;
            for(int i=0;i<finalCounter;i++)
            {
                if(select==strings[i])
                {
                    isDouble=true;
                }
            }
            if(!isDouble)
            {
                strings[finalCounter] = select;
                finalCounter++;
            }
        }
    }
    /*cout << endl << "Now on to the loop" << endl << endl;
    for(int i=0;i<counter;i++){
        cout << strings[i] << endl;
    } */
    //cout << endl << "SORTING TIME" << endl << endl;
    MergeSortS(strings,0,finalCounter-1);
    for(int i=0;i<finalCounter;i++)
    {
        cout << strings[i] << endl;
    }
}

void MergeSort(int numbers[], int i, int k) {
   int j;
   
   if (i < k) {
      j = (i + k) / 2;  // Find the midpoint in the partition
      
      // Recursively sort left and right partitions
      MergeSort(numbers, i, j);
      MergeSort(numbers, j + 1, k);
      
      // Merge left and right partition in sorted order
      Merge(numbers, i, j, k);
   }
}

void Merge(int numbers[], int i, int j, int k) {
   int mergedSize;                            // Size of merged partition
   int mergePos;                              // Position to insert merged number
   int leftPos;                               // Position of elements in left partition
   int rightPos;                              // Position of elements in right partition
   int* mergedNumbers = nullptr;

   mergePos = 0;
   mergedSize = k - i + 1;
   leftPos = i;                               // Initialize left partition position
   rightPos = j + 1;                          // Initialize right partition position
   mergedNumbers = new int[mergedSize];       // Dynamically allocates temporary array
                                              // for merged numbers
   
   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= j && rightPos <= k) {
      if (numbers[leftPos] < numbers[rightPos]) {
         mergedNumbers[mergePos] = numbers[leftPos];
         ++leftPos;
      }
      else {
         mergedNumbers[mergePos] = numbers[rightPos];
         ++rightPos;
         
      }
      ++mergePos;
   }
   
   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= j) {
      mergedNumbers[mergePos] = numbers[leftPos];
      ++leftPos;
      ++mergePos;
   }
   
   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= k) {
      mergedNumbers[mergePos] = numbers[rightPos];
      ++rightPos;
      ++mergePos;
   }
   
   // Copy merge number back to numbers
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      numbers[i + mergePos] = mergedNumbers[mergePos];
   }
   delete[] mergedNumbers;
}

void MergeSortS(string numbers[], int i, int k) {
   int j;
   
   if (i < k) {
      j = (i + k) / 2;  // Find the midpoint in the partition
      
      // Recursively sort left and right partitions
      MergeSortS(numbers, i, j);
      MergeSortS(numbers, j + 1, k);
      
      // Merge left and right partition in sorted order
      MergeS(numbers, i, j, k);
   }
}

void MergeS(string numbers[], int i, int j, int k) {
   int mergedSize;                            // Size of merged partition
   int mergePos;                              // Position to insert merged number
   int leftPos;                               // Position of elements in left partition
   int rightPos;                              // Position of elements in right partition
   string* mergedNumbers = nullptr;

   mergePos = 0;
   mergedSize = k - i + 1;
   leftPos = i;                               // Initialize left partition position
   rightPos = j + 1;                          // Initialize right partition position
   mergedNumbers = new string[mergedSize];       // Dynamically allocates temporary array
                                              // for merged numbers
   
   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= j && rightPos <= k) {
      if (numbers[leftPos] < numbers[rightPos]) {
         mergedNumbers[mergePos] = numbers[leftPos];
         ++leftPos;
      }
      else {
         mergedNumbers[mergePos] = numbers[rightPos];
         ++rightPos;
         
      }
      ++mergePos;
   }
   
   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= j) {
      mergedNumbers[mergePos] = numbers[leftPos];
      ++leftPos;
      ++mergePos;
   }
   
   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= k) {
      mergedNumbers[mergePos] = numbers[rightPos];
      ++rightPos;
      ++mergePos;
   }
   
   // Copy merge number back to numbers
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      numbers[i + mergePos] = mergedNumbers[mergePos];
   }
   delete[] mergedNumbers;
}