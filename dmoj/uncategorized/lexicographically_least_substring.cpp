#include <algorithm>
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

    string sequence;
    unsigned int length;

    cin >> sequence >> length;

    string smallest {sequence.substr(0, length)};

    for (unsigned int i {1}; i < sequence.size() - length; ++i)
    {
        smallest = min(smallest, sequence.substr(i, length));
    }

    cout << smallest << '\n';

    return 0;
}
