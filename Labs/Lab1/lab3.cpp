#include <iostream>
#include <vector>
using namespace std;

int main() {

   /* Type your code here. */
   int max;
   int list[100];
   int threshold;
   cin >> max;
   for(int i=0;i<max;i++)
   {
       cin >> list[i];
   }
   cin >> threshold;
   
   for(int i=0;i<max;i++)
   {
       if(list[i]<=threshold)
       {
           cout << list[i] << ",";
       }
   }
    cout << endl;



   return 0;
}
