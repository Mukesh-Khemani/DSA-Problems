#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We use array data structure because of its simple implementation and manipulation.

ALGORITHM:
-> For 'addWord' function, insert the 'word' into the vector.
-> For 'search' function: 
1) We iterate through each string of the vector whose size is equal to the size 
of the word.
2) Then we check if each character of the the string 'word' is equal to each character of 
the ith string of the vector and if unequal, the jth indexed element of 'word' is '.' or not.
3) If we find a match, we return true. Else, return false
*/
class WordDictionary {
public:
    vector<string> v;

    // Constructor call
    WordDictionary() {

    }
    
    void addWord(string word) {
        v.push_back(word);
    }
    
    bool search(string word) {
        int n=word.size();
        for(int i=0; i<v.size(); i++){
            if(n==v[i].length()){
                int j=0;
                while(j<word.size()){
                    if(v[i][j]!=word[j] && word[j]!='.'){
                        break;
                    }
                    j++;
                }
                if(j==word.size()) return true;
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}