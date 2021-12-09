/*

Code : Balanced Parenthesis
Send Feedback
For a given a string expression containing only round brackets or parentheses, check if they are balanced or not. Brackets are said to be balanced if the bracket which opens last, closes first.
Example:
Expression: (()())
Since all the opening brackets have their corresponding closing brackets, we say it is balanced and hence the output will be, 'true'.
You need to return a boolean value indicating whether the expression is balanced or not.
Note:
The input expression will not contain spaces in between.
Input Format:
The first and the only line of input contains a string expression without any spaces in between.
 Output Format:
The only line of output prints 'true' or 'false'.
Note:
You don't have to print anything explicitly. It has been taken care of. Just implement the function. 
Constraints:
1 <= N <= 10^7
 Where N is the length of the expression.

Time Limit: 1sec
Sample Input 1 :
(()()())
Sample Output 1 :
true
Sample Input 2 :
()()(()
Sample Output 2 :
false
Explanation to Sample Input 2:
The initial two pairs of brackets are balanced. But when you see, the opening bracket at the fourth index doesn't have its corresponding closing bracket which makes it imbalanced and in turn, making the whole expression imbalanced. Hence the output prints 'false'.

*/



#include <iostream>
#include <string>
using namespace std;

#include<stack>
bool isBalanced(string input)
{
	// Write your code here
    
    stack<char> s;
    for(int i=0;input[i]!='\0';i++)
    {
        if(input[i]=='(' ||input[i]=='{' ||input[i]=='[' )
        {
            s.push(input[i]);
        }
        
        else if(input[i]==')' ||input[i]=='}' ||input[i]==']' ) {
            if(s.empty())
            {
                return false;
            }
            
            if(input[i]==')')
            {
                if(s.top()=='(')
                {
                    s.pop();
                } 
                
                continue;
 
            }
            
            else if(input[i]=='}')
            {
                if(s.top()=='{')
                {
                    s.pop();
                }  continue;
     
            }
            else if(input[i]==']')
            {
                if(s.top()=='[')
                {
                    s.pop();
                }   
                continue;
            }
            
            else
            {
                return false;
            }
        }
    }
    if(s.empty())
    {
        return true;
    }
    return false;

}

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}
