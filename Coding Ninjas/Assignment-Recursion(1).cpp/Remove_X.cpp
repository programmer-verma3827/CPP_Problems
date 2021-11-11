/*
Remove X
Send Feedback
Given a string, compute recursively a new string where all 'x' chars have been removed.
Input format :
String S
Output format :
Modified String
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string S. 
Sample Input 1 :
xaxb
Sample Output 1:
ab
Sample Input 2 :
abc
Sample Output 2:
abc
Sample Input 3 :
xx
Sample Output 3:

*/

#include <iostream>
#include "solution.h"
using namespace std;

#include <string.h>
#include <math.h>

void removeX(char input[]) {
    // Write your code here

    if(strlen(input)<1)
    {
        return;
    }
    int i=0, j=0;
    
    removeX(input+1);
    
    while(input[i]!='\0')
    {
        if(input[i]=='x'){
            i++;
        }
        else
        {
            input[j]=input[i];
                i++;
            j++;
        }
        if(input[i]=='\0')
        {
            input[j]='\0';
        }
            
            
    }

}


int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
