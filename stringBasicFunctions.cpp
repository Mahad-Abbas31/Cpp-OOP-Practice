#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s = "Hello World";

    cout << "Length:" << s.length() << endl;     // 11
    cout << "Size:" << s.size() << endl;       // same as length()

    cout <<  "First Letter:" << s[0] << endl;           // 'H'
    cout <<  "Second Letter:" << s.at(1) << endl;        // 'e' (safer than [])

    s.append("!!!");                // "Hello World!!!"
    s += " Welcome";                // "Hello World!!! Welcome"

    cout << s.substr(0, 5) << endl;         // "Hello" (0 starting index), (5 no. of characters)

    // ____ TypeCasting
    // int to String
    int x = 25;
    string l = to_string(x);   // "25"

    // string to int
    string i = "123";
    int y = stoi(i);   // 123
    
    // string to float
    string k = "3.14";
    float f = stof(k);

    // string to double
    double d = stod(k);

    // ____ Uppercase
    for(int i = 0; i < s.length(); i++)
        s[i] = toupper(s[i]);           // "HELLO"

    // ____ Uppercase shortcut
    for(char &c : s)
        c = toupper(c);
    
    cout << s << endl;

    for(int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i]);           // "hello"

    cout << s << endl;

    // Find a Sub-string
    cout << s.find("World");   // returns index
    
    s.erase(5, 6);   // removes from index 5 → "Hello"

    s.replace(6, 5, "C++");   // "Hello C++"

    // ___ Checks
    char c = 'A';    
    isalpha(c);   // letter
    isdigit(c);   // number
    islower(c);
    isupper(c);
}