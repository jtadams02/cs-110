#include <iostream>
#include <string>
using namespace std;

//Returns the number of characters in usrStr
int GetNumOfCharacters(const string usrStr) {
   int count = 0;
   int len = usrStr.length();
   /* Type your code here. */
   for(int i=0;i<len;i++)
   {
       count++;
   }
   return count;
}

/*void OutputWithoutWhitespace(string str){
    int len = str.length();
   for(int i=0;len;i++){
       if(str.substr(i) != ' ' && str.substr(i) != '\t'){
           cout << str[i];
       }
   }
}*/
int main() {

   /* Type your code here. */
   string sentence;
    cout << "Enter a sentence or phrase:" << endl;
    getline(cin,sentence);
    cout << "You entered: " << sentence << endl;
    cout << "Number of characters: " << GetNumOfCharacters(sentence) << endl;
   // OutputWithoutWhitespace(sentence);
   return 0;
}