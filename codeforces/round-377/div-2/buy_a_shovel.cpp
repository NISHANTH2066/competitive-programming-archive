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

    unsigned int price;
    unsigned int denomination;

    cin >> price >> denomination;

    unsigned int shovels {1};

    while (shovels * price % 10 != 0 &&
           shovels * price % 10 != denomination)
    {
            ++shovels;
    }

    cout << shovels << '\n';

    return 0;
}
