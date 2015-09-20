#include <algorithm>
#include <iostream>
#include <vector>

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
        unsigned int ingredients;
        cin >> ingredients;

        vector<unsigned int> quantities(ingredients);

        for (auto& quantity : quantities)
        {
            cin >> quantity;
        }

        unsigned int gcd {0};

        for (auto quantity : quantities)
        {
            gcd = __gcd(gcd, quantity);
        }

        for (auto i = quantities.cbegin(); i != quantities.cend(); ++i)
        {
            cout << *i / gcd << " \n"[i + 1 == quantities.cend()];
        }
    }

    return 0;
}
