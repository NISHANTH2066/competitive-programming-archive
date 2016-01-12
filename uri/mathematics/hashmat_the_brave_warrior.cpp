#include <cstdlib>
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

    for (long long first_army, second_army; cin >> first_army >> second_army; )
    {
        cout << abs(first_army - second_army) << '\n';
    }

    return 0;
}
