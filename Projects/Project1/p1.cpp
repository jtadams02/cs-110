#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>


#define NUM_OF_STUFF = 10;
using namespace std;

bool removeStr(string input);
int distinctWords(string input[],int i);
int findThatWordFULL(string input[],int i,string search);

int main(int argc, char* argv[]) {
    if(argc!=2){
        cout << "Must have argument" << endl;
        return -1;
    }
    ifstream myFile;
    string userF = argv[1];
    myFile.open(userF);
    if(myFile.fail())
    {
        cout << "File does not exist!" << endl;
        return -1;
    }
   // int words = 0;
    int i= 0;
   // int k=0;
    string strArr[10000];
    //char inputC;
    while(!myFile.eof())
    {
        getline(myFile,strArr[i]);
      //  cout << strArr[i] << endl;
        i++;
    }
    

//  LETS GET THIS STRING ARRAY GOING YEAHHHHHHHHHHHHHHHHHHHHH
    string finalArr[10000];
    int strCount = 0;
    bool shouldInc = false;
    for(int k=0;k<i;k++)
    {
        int length = strArr[k].length();
        for(int z=0;z<length;z++)
        {
            char inputChar = tolower(strArr[k].at(z));
            if(isblank(inputChar))
            {
                if(shouldInc)
                {
                    strCount++;
                    shouldInc = false;
                    continue;
                } else {
                    continue;
                }
            }
            if(isalpha(inputChar))
            {
                finalArr[strCount]+=inputChar;
                shouldInc = true;
                continue;
            } else {
                if(shouldInc)
                {
                    strCount++;
                    shouldInc = false;
                    continue;
                } else {
                    continue;
                }

            }
           // cout << strArr[k][z] << endl;
        }
        strCount++;
    }

    // NO SPACES BABY WOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
    int wc = 0;
    string actualArr[strCount];
    for(int h=0;h<strCount;h++)
    {
        if(!finalArr[h].empty())
        {
           //cout << finalArr[h] << endl;
            actualArr[wc] = finalArr[h]; 
            //cout << actualArr[wc] << endl;
            wc++;
        }
    }

// DISTINCT ARRAY BABY LETS GOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
    string distinctArr[wc];
    int distinctCount = 0;
    for(int first = 0; first<wc;first++)
    {
        bool isDistinct = true;
        string tempFirst = actualArr[first];
        for(int last=0;last<wc;last++)
        {
            string tempLast = distinctArr[last];
            if((tempFirst.compare(tempLast))==0)
            {
                isDistinct=false;
            }
        }
        if(isDistinct)
        {
            distinctArr[distinctCount] = tempFirst;
           // cout << distinctArr[distinctCount] << endl;
            distinctCount++;
        }
    }

    // WOOOO LETS GET SOME OUTPUT WOOOOOOOOOOOOOOOOOOOOOOOOOOOO
    cout << "The number of words found was " << wc << endl;
    cout << "The number of distinct words was " << distinctCount << "\n" << endl;
    while(true) 
    {

    cout << "Enter a word: ";
    string input;
    cin >> input;
    cout << endl;
    int inputLen = input.length();
    bool isQ = false;
    if(input.compare("STOP")==0)
    {
        return 0;
    }
    for(int u=0;u<inputLen;u++)
    {
        if(input[u]=='?')
        {
            isQ = true;
        }
    }
    int times = 0;
    if(!isQ)
    {
        times = findThatWordFULL(actualArr,wc,input);
        cout << "The word " << input << " appears " << times << " times" << endl << endl;
    } else {
        // LETS GET THEM SHIT
        bool weOutPutting = false;
        int index[inputLen];
        for(int x=0;x<inputLen;x++)
        {
            if(input[x]=='?')
            {
                index[x] = 0;
            } else {
                index[x] = 1;
            }
        }
        for(int x = 0;x<distinctCount;x++)
        {
            string tempStr = distinctArr[x];
            int lenn = tempStr.length();
            if(lenn==inputLen)
            {
                bool willOutput = true;
                for(int t=0;t<inputLen;t++)
                {
                    if(index[t]==1)
                    {
                        if(tempStr[t]!=input[t])
                        {
                            willOutput=false;
                        }
                    }                    
                }
                if(willOutput==true)
                {
                    times = findThatWordFULL(actualArr,wc,tempStr);
                    cout << "The word " << tempStr << " appears " << times << " times" << endl;
                    weOutPutting = true;
                }
            }
            
        }
        if(!weOutPutting)
        {
            cout << "The word " << input << " appears " << times << " times" << endl << endl;
        } else {
            cout << endl;
        }
    }
    }
    return 0;
}

int findThatWordFULL(string array[],int i,string input)
{
    int wordC = 0;
    for(int x = 0;x<i;x++)
    {
        string tempStr = array[x];
        if(tempStr.compare(input)==0)
        {
            wordC++;
        }
    }
    return wordC;
}
// Finds Word Count 
int distinctWords(string input[],int i)
{

    return 0;
}