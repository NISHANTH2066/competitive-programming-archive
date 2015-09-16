#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

template <typename T>
T sum(T upper_limit)
{
    return upper_limit * (upper_limit + 1) / 2;
}

template <typename T>
T sum_of_squares(T upper_limit)
{
    return upper_limit * (upper_limit + 1) * (2 * upper_limit + 1) / 6;
}

int main()
{
    use_io_optimizations();

    cout << sum(100) * sum(100) - sum_of_squares(100) << '\n';

    return 0;
}
