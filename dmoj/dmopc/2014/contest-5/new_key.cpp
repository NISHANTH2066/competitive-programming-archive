#include <iostream>
#include <map>

using namespace std;

const map<char, char> decrypted {
    {'0', '9'}, {'1', 'A'}, {'2', 'B'}, {'3', 'C'}, {'4', 'D'},
    {'5', 'E'}, {'6', 'F'}, {'7', 'G'}, {'8', 'H'}, {'9', 'I'},
    {'A', 'J'}, {'B', 'K'}, {'C', 'L'}, {'D', 'M'}, {'E', 'N'},
    {'F', 'O'}, {'G', 'P'}, {'H', 'Q'}, {'I', 'R'}, {'J', 'S'},
    {'K', 'T'}, {'L', 'U'}, {'M', 'V'}, {'N', 'W'}, {'O', 'X'},
    {'P', 'Y'},
};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    string message;
    cin >> message;

    for (auto symbol : message)
    {
        cout << decrypted.at(symbol);
    }

    cout << '\n';

    return 0;
}
