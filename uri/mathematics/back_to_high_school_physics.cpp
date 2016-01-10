#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    for (int velocity, time; cin >> velocity >> time; )
    {
        cout << 2 * time * velocity << '\n';
    }

    return 0;
}
