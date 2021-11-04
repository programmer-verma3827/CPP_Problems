/*
Reverse Word Wise

Reverse the given string word wise. That is, the last word in given string should come at 1st place, last second word at 2nd place and so on. Individual words should remain as it is.
Input format :
String in a single line
Output format :
Word wise reversed string in a single line
Constraints :
0 <= |S| <= 10^7
where |S| represents the length of string, S.
Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
Ninjas Coding to Welcome
Sample Input 2:
Always indent your code
Sample Output 2:
code your indent Always

*/

#include <iostream>
#include "solution.h"

using namespace std;
void reverseStringWordWise(char input[]) {
    
    // Write your code here
      
     int len = 0;
    int i = 0;
    while (input[i] != '\0')
    {
        len++;
        i++;
    }

    int start = 0, end = len - 1;
    while (start < end)
    {
        swap(input[start], input[end]);
        start++;
        end--;
    }
    i=0;
    while (i<len)
    {
        start = i;
        while (input[i] != ' ' && input[i] != '\0')
        {
            i++;
        }

        end = i - 1;

        while (start < end)
        {
            swap(input[start], input[end]);
            start++;
            end--;
        }
        i++;
    }
    
}

int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
