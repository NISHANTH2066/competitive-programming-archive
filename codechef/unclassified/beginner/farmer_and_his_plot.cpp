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

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int width;
        unsigned int height;

        cin >> width >> height;

        auto gcd = __gcd(width, height);

        cout << (width / gcd) * (height / gcd) << '\n';
    }

    return 0;
}
