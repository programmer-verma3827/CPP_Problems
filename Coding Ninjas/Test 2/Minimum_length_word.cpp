/*
Minimum Length Word

Given a string S (that can contain multiple words), you need to find the word which has minimum length.
Note : If multiple words are of same length, then answer will be first minimum length word in the string.
Words are seperated by single space only.
Input Format :
String S
Output Format :
Minimum length word
Constraints :
1 <= Length of String S <= 10^5
Sample Input 1 :
this is test string
Sample Output 1 :
is
Sample Input 2 :
abc de ghihjk a uvw h j
Sample Output 2 :
a

*/

#include<iostream>
#include "solution.h"
using namespace std;

#include <limits.h>
#include <string.h>

void minLengthWord(char input[], char output[]){
		
	// Write your code here	
    
      int n=strlen(input);
    int mini=INT_MAX;
    int start=-1;
    int cnt=0;
    for(int i=0;i<=n;i++){
        if(input[i]!=' ' && i!=n){
            cnt++;
        }
         else if(cnt<mini||(i==n &&cnt<mini)){
            mini=cnt;
            start=i-mini;
            cnt=0;
        }
        else{
            cnt=0;
        }
     }
    for(int i=0;i<mini;i++){
         output[i]=input[i+start];
    }

}


int main(){
  char ch[10000], output[10000];
  cin.getline(ch, 10000);
  minLengthWord(ch, output);
  cout << output << endl;
}
