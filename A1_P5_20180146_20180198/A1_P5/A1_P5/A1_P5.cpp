
#include <iostream>
#include <set>
#include <string>
using namespace std;

void filter(string s)
{
    static set<string>words;
    int size = words.size();
    words.insert(s);
    if (words.size() > size)
    {
        cout << s << endl;
    }
}

void RecPermute(string soFar, string rest)

{
    
    if (rest == "") // No more characters 
        filter(soFar);// Print the word 
    else // Still more chars 
    // For each remaining char 

        for (int i = 0; i < rest.length(); i++) {

            string next = soFar + rest[i]; // Glue next char 

            string remaining = rest.substr(0, i) + rest.substr(i + 1);
            RecPermute(next, remaining);
        }

}


void ListPermutations(string word)
{
    RecPermute("", word);
}


int main()
{
    ListPermutations("Makka");
    return 0;
}
