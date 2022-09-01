#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    string s;
    string chars = "IVXLCDM"; 
    cout << "s = ";
    cin >> s;
    cout << s << endl;
    int length = s.length();
    int finalNum = 0;
    for(int i=0;i<length;i++)
    {
        if(s[i]==chars[0])
        {
            if(s[i+1]==chars[1])
            {
                //cout << "4";
                finalNum+=4;
                i++;
                continue;
            } else if(s[i+1]==chars[2])
            {
                //cout << "9";
                finalNum+=9;
                i++;
                continue;
            } else {
                //cout<<"1";
                finalNum+=1;
                continue;
            }
        } else if(s[i]==chars[1])
        {
            finalNum+=5;
            //cout << "5";
            continue;
        } else if(s[i]==chars[2])
        {
            if(s[i+1]==chars[3])
            {
                //cout<<"40";
                finalNum+=40;
                i++;
                continue;
            } else if(s[i+1]==chars[4]){
                //cout<<"90";
                finalNum+=90;
                i++;
                continue;   
            } else {
                //cout << "10";
                finalNum+=10;
                continue;
            }
        } else if(s[i]==chars[3])
        {
            finalNum+=50;
            //cout << "50";
            continue;
        } else if(s[i]==chars[4])
        {
            if(s[i+1]==chars[5])
            {
                //cout<<"400";
                finalNum+=400;
                i++;
                continue;
            } else if(s[i+1]==chars[6])
            {
                //cout << "900";
                finalNum+=900;
                i++;
                continue;
            } else {
                //cout << "100";
                finalNum+=100;
                continue;
            }
        } else if(s[i]==chars[5])
        {
           //cout << "500";
            finalNum+=500;
            continue;
       } else if(s[i]==chars[6])
       {
            //cout << "1000";
        finalNum+=1000;
        continue;
       }
    }
    cout << "\n" << s << " = " << finalNum;

}