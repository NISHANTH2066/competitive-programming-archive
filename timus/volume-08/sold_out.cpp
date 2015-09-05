#include <algorithm>
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

    unsigned int seats;
    unsigned int vasya;

    cin >> seats >> vasya;

    cout << max({vasya - 1, seats - vasya, 2u}) - 2 << '\n';

    return 0;
}
