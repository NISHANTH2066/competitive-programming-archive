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

    unsigned int divisible_by_3  {(3  + 999) * 333 / 2};
    unsigned int divisible_by_5  {(5  + 995) * 199 / 2};
    unsigned int divisible_by_15 {(15 + 990) * 66  / 2};

    cout << divisible_by_3 + divisible_by_5 - divisible_by_15 << '\n';

    return 0;
}
