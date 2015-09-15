#include <iostream>
#include <map>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    string plaintext;
    string ciphertext;

    getline(cin, plaintext);
    getline(cin, ciphertext);

    map<char, char> dictionary;

    for (string::size_type i {0}; i < ciphertext.size(); ++i)
    {
        dictionary[ciphertext[i]] = plaintext[i];
    }

    for (char symbol; cin >> symbol; )
    {
        cout << (dictionary.count(symbol) ? dictionary[symbol] : '.');
    }

    cout << '\n';

    return 0;
}
