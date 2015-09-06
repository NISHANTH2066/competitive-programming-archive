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

    for (int girls, boys; cin >> girls >> boys && (girls >= 0 || boys >= 0); )
    {
        cout << (girls + boys) / (min(girls, boys) + 1) << '\n';
    }

    return 0;
}
