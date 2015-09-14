#include <iostream>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void print(const string& sequence, unsigned int times)
{
    for (unsigned int i {0}; i < times; ++i)
    {
        cout << sequence << '\n';
    }
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int rows;
        unsigned int columns;

        cin >> rows >> columns;

        unsigned int row;
        unsigned int column;

        cin >> row >> column;

        string first (columns, '.');
        string second(columns, '*');

        first[column - 1] = '*';

        print(first,  row - 1);
        print(second, 1);
        print(first,  rows - row);

        cout << '\n';
    }

    return 0;
}
