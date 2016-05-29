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

    unsigned int distance;
    cin >> distance;

    cout << (distance + 4) / 5 << '\n';

    return 0;
}
