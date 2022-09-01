#include <iostream>
#include <string>      // Supports use of "string" data type
using namespace std;

int main() {
   int    userInt;
   double userDouble;
   // FIXME: Define char and string variables
   char userChar[50];
   string userStr;
   cout << "Enter integer:" << endl;
   cin  >> userInt;
   
   // FIXME (1): Finish reading other items into variables, then output the four values on a single line separated by a space
  // cout << "You entered " << userInt << endl;
  cout << "Enter double:" << endl;
  cin >> userDouble;

  cout << "Enter character:" << endl;
  cin >> userChar;

  cout << "Enter string:" << endl;
  cin >> userStr;

  cout << userInt << " " << userDouble << " " << userChar << " " << userStr << endl;
   
   // FIXME (2): Output the four values in reverse
   cout << userStr << " " << userChar << " " << userDouble << " " << userInt << endl;
   
   // FIXME (3): Cast the double to an integer, and output that integer
   int newInt = (int) userDouble;
   cout << userDouble << " cast to an integer is " << newInt << endl;
   return 0;
}