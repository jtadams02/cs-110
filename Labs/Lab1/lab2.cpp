#include <iostream>
#include <string>

using namespace std;

int main()
{
    string fullname;
    getline(cin, fullname);
    
    string parts[3] = {"","",""};
      
    int p = 0;  
    int i = 0;
    while (p!=string::npos)  
    {  
        p = fullname.find (" ");
        parts[i] = fullname.substr(0, p);
        fullname = fullname.substr(p+1);
        i++;
    }  
    if(parts[2] == "") 
    {
        cout << parts[1] << ", " << parts[0].substr(0,1) << "." << endl;
    } else
    {
        cout << parts[2] << ", " << parts[0].substr(0,1) << "." << parts[1].substr(0,1) << "." << endl;
    }
    return 0;
}