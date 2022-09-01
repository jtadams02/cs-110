#include <iostream>
#include <string>

using namespace std;

int main(){

    string str = "BIGEXAMPLE";
    int len = str.length();
    for(int i=0;i<len-1;i++)
    {
        char selected = str[i];
        char tempSelect = str[i];
        int selection = i;
        for(int k=i+1;k<len;k++)
        {
            char temp = str[k];
            if(temp < tempSelect)
            {
                tempSelect = temp;
                selection = k;
            }
        }
        str[i] = tempSelect;
        str[selection] = selected;
        cout << str << endl;

    }



    return 0;
}