/*
Print all Codes - String

Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. Just print them in different lines.
Input format :
A numeric string S
Output Format :
All possible codes in different lines
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw

*/

#include <iostream>
#include "solution.h"
using namespace std;

void printCodes(string input, string output)
{
    if(input.size()==0)
    {
        cout<<output<<endl;
        return;
    }
    
    int first = input[0]-'0';
    char firstchar = 'a' + first - 1;
    
    printCodes(input.substr(1), output+firstchar);
    // printCodes(input.substr(2), output);

    
    
   int second = first*10+(input[1]-'0');
    
    if(10<=second && second<=26)
    {
        char secondChar = 'a' + second-1;
        printCodes(input.substr(2), output+secondChar);
    }
    
}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    
    string output = "";
    
    printCodes(input, output);
}

int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
