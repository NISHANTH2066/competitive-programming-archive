#include <iostream>
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

    unsigned int length;
    cin >> length;

    string cipher;
    cin >> cipher;

    unsigned int lines;
    cin >> lines;
    cin.ignore();

    for (unsigned int i {0}; i < lines; ++i)
    {
        string line;
        getline(cin, line);

        for (auto symbol : line)
        {
            auto position = cipher.find(symbol);

            if (position == string::npos)
            {
                cout << symbol;
            }
            else
            {
                cout << cipher[(position + 1) % length];
            }
        }

        cout << '\n';
    }

    return 0;
}
