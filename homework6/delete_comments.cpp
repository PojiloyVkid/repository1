#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

using namespace std;

const string signal1 = "//";
const string signal2 = "/*";
const string signal3 = "*/"; 

bool find_signal1(const string& s)
{
    return s.find(signal1) != -1;
}

string without_signal1(string& s)
{
    reverse(s.begin(), s.end());
    size_t i = s.size() - s.find(signal1) - 2;
    reverse(s.begin(), s.end());
    return s.substr(0, i);
}

bool find_signal2(const string& s)
{
    return s.find(signal2) != -1;
}

bool find_signal3(const string& s)
{
    return s.find(signal3) != -1;
}

string wrong_signal(string& s)
{
    while (find_signal2(s) and find_signal3(s)) {
        s = s.substr(0, s.find(signal2)) +
            s.substr(s.find(signal3) + 2, s.size());
    }
    return s;
}

int main()
{
    ifstream input("comments.txt");
    ofstream output("without_comments.txt");
    string text;
    string s;
    
    if (input.is_open() and output.is_open())
    {
        cout << "InputError" << endl;
        return -1;
    }

    bool flag = false;
    
    while (!input.eof()) 
    {
        getline(input, s);
        if (find_signal1(s))
        {
            s = without_signal1(s);
            if (find_signal2(s) and find_signal3(s)) {
                s = wrong_signal(s);
                output << s << endl;
                continue;
            }
            output << s << endl;
            continue;
        }
        else if (find_signal2(s) and find_signal3(s)) 
        {
            output << wrong_signal(s) << endl;
        }
        else if (find_signal2(s) or find_signal3(s)) 
        {
            if (find_signal2(s)) {
                flag = true;
                output << s.substr(0, s.find(signal2)) << endl;
            }
            else 
            {
                flag = false;
                output << s.substr(s.find(signal3) + 2, s.size()) << endl;
            }
        }
        else if (!flag) 
        {
            output << s;
        }
    }
    input.close();
    output.close();
    return 0;
}
