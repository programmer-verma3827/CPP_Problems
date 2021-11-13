/*
Return Keypad Code

Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
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

#include <string>
using namespace std;
string hashtable[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num==0)
    {
		output[0]="";
        return 1;
    }
    
    int smalloutputsize=keypad(num/10,output);
    int no_of_letter=hashtable[num%10].size();
    int j=0,w=1;
  		for(int i=0;i<smalloutputsize;i++)
        {	w=1;
        	while(no_of_letter!=w)
            {
                output[smalloutputsize+j]=output[i] + hashtable[num%10][w];
                j++;w++;
                
            }
			
        }
    
    	for(int i=0;i<smalloutputsize;i++)
        {
			output[i]+=hashtable[num%10][0];
        }
    return no_of_letter*smalloutputsize;
    
}


int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
