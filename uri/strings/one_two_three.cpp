#include <iostream>

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

    unsigned int words;
    cin >> words;

    for (unsigned int i {0}; i < words; ++i)
    {
        string word;
        cin >> word;

        if (word.length() == 5)
        {
            cout << 3 << '\n';
        }
        else if (word[0] == 't' && word[1] == 'w' ||
                 word[0] == 't' && word[2] == 'o' ||
                 word[1] == 'w' && word[2] == 'o')
        {
            cout << 2 << '\n';
        }
        else
        {
            cout << 1 << '\n';
        }
    }

    return 0;
}
