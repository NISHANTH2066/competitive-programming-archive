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

    unsigned int first;
    unsigned int second;
    unsigned int third;

    cin >> first >> second >> third;

    cout << first + second + third << '\n';

    return 0;
}
