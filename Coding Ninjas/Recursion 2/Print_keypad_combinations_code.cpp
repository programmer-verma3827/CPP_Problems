/*
Print Keypad Combinations Code

Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf

*/

#include <iostream>
#include <string>
#include "solution.h"
using namespace std;

string key[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
               //0 , 1,  2  ,3    ,4    , 5   ,6    ,7     ,8    ,9  
void keypad(int num,string output)
{
        if(num==0)
        {
            cout<<output<<endl;
            return ;
        }
        string temp=key[num%10];  // taking string corresponding to last digit
        for(int i=0;i<temp.size();i++)
            keypad(num/10,temp[i]+output);    //  taking every ch of temp in output 
    }
void printKeypad(int num)
{
    string output="";
    keypad(num,output);
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
