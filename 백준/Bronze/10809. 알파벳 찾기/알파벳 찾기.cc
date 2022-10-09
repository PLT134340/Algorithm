#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word;
    cin >> word;
    
    int alphabet[26];
    for(int i = 0; i < 26; i++)
        alphabet[i] = -1;
        
    for(int i = 0; i < word.length(); i++)
        if(alphabet[word.at(i) - 'a'] == -1)
            alphabet[word.at(i) - 'a'] = i;
    
    for(int i = 0; i < 26; i++)
        cout << alphabet[i] << " ";
    return 0;
}