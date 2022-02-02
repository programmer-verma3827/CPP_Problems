/*

Palindrome Pair
Send Feedback
Given 'n' number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word, which itself is a palindrome.
The function should return either true or false. You don't have to print anything.
Input Format :
The first line of the test case contains an integer value denoting 'n'.

The following contains 'n' number of words each separated by a single space.
Output Format :
The first and only line of output contains true if the conditions described in the task are met and false otherwise.
Constraints:
0 <= n <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4
abc def ghi cba
Sample Output 1 :
true
Explanation of Sample Input 1:
"abc" and "cba" forms a palindrome
Sample Input 2 :
2
abc def
Sample Output 2 :
false
Explanation of Sample Input 2:
Neither their exists a pair which forms a palindrome, nor any of the words is a palindrome in itself. Hence, the output is 'false.'

*/

#include <bits/stdc++.h>
using namespace std;

#include <string>

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word) 
    {
        
        // Base case
        
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) 
        {
            child = root->children[index];
        } 
        
        else 
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        
        return add(child, word.substr(1));
    }

    void add(string word) 
    {
        if (add(root, word)) 
        {
            this->count++;
        }
    }
    

bool searchHelper(TrieNode *root, string word)
{   
    if(word.size() == 0 && root->isTerminal == true)
    {
        return true;
    }
    
    if(word.size() == 0 && root->isTerminal == false)
    {
        return false;
    }
    
    int index = word[0] - 'a';
    if(root->children[index] != NULL)
    {
        return searchHelper(root->children[index], word.substr(1));
    }
    
    else
    {
        return false;
    }
}
    
    
bool searchNode(string word)
{
    return searchHelper(root, word);
}
    
    
bool isPalindromePair(vector<string> words)
{
    for(int i=0;i<words.size();i++)
    {
        string str = words[i];
        int k = 0;
        for(int j=0;j<str.size();j++)
        {
            add(str.substr(k, str.size()));
            add(str.substr(0, k));
            k++;
        }
    }
    
    for(int i=0;i<words.size();i++)
    {
        string str2 = words[i];
        reverse(str2.begin(), str2.end());
        if(searchNode(str2))
        {
            return true;
        }
    }
    
    return false;
}
    
};

int main() {
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}
