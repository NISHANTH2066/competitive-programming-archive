#include <iostream>
#include <map>

using namespace std;

const map<char, map<char, char>> rotations {
    {'N', {{'E', 'O'}, {'D', 'L'}}},
    {'L', {{'E', 'N'}, {'D', 'S'}}},
    {'S', {{'E', 'L'}, {'D', 'O'}}},
    {'O', {{'E', 'S'}, {'D', 'N'}}}
};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    for (unsigned int commands; cin >> commands && commands > 0; )
    {
        char direction {'N'};

        for (unsigned int i {0}; i < commands; ++i)
        {
            char command;
            cin >> command;

            direction = rotations.at(direction).at(command);
        }

        cout << direction << '\n';
    }

    return 0;
}
