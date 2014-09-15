/*
  ID: andrewy3
  PROG: namenum
  LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string convert(const string& s){
    string result = "";
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'Q' || s[i] == 'Z')
            return "1";
        if(s[i] < 'Q')
            result += ((s[i] - 'A') / 3) + '2';
        else
            result += ((s[i] - 'Q') / 3) + '7';
    }
    return result;
}
 
int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream dict ("dict.txt");
  
    string input;
    fin >> input;
  
    bool found = false;
    string buffer;
    while (dict >> buffer)
    {
        if (buffer.length() == input.length() && convert(buffer) == input)
        {
            fout << buffer << "\n";
            found = true;
        }
    }

    if(!found)
        fout << "NONE" << "\n";
}
