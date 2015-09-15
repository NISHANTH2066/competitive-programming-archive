#include <algorithm>
#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

template <typename T>
T lcm(T left, T right)
{
    return left * right / __gcd(left, right);
}

int main()
{
    use_io_optimizations();

    unsigned long long multiple {1};

    for (unsigned long long i {2}; i <= 20; ++i)
    {
        multiple = lcm(multiple, i);
    }

    cout << multiple << '\n';

    return 0;
}
