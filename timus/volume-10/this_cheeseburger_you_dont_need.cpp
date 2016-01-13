#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void read_word(string& object, string& subject, string& verb)
{
    char bracket;
    cin >> bracket;

    if (bracket == '{')
    {
        getline(cin, object, '}');
    }
    else if (bracket == '(')
    {
        getline(cin, subject, ')');
    }
    else if (bracket == '[')
    {
        getline(cin, verb, ']');
    }
}

string sentence()
{
    string object;
    string subject;
    string verb;

    read_word(object, subject, verb);
    read_word(object, subject, verb);
    read_word(object, subject, verb);

    return object + ' '  + subject + ' ' + verb;
}

string conjunction()
{
    if (cin.peek() != ',')
    {
        return "";
    }

    cin.ignore();
    cin.ignore();

    if (!isalpha(cin.peek()))
    {
        return ", ";
    }

    string word;
    cin >> word;

    return ", " + word + ' ';
}

int main()
{
    use_io_optimizations();

    auto first  = sentence();
    auto link   = conjunction();
    auto second = sentence();

    transform(first.begin(),  first.end(),  first.begin(),  ::tolower);
    transform(link.begin(),   link.end(),   link.begin(),   ::tolower);
    transform(second.begin(), second.end(), second.begin(), ::tolower);

    first.front() = toupper(first.front());

    cout << first + link + second << '\n';

    return 0;
}
