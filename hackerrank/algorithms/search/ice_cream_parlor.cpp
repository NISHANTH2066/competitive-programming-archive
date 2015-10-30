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
        unsigned int cash;
        unsigned int flavors;

        cin >> cash >> flavors;

        vector<unsigned int> prices(flavors);
        vector<unsigned int> indices(10001);

        for (unsigned int i {0}; i < flavors; ++i)
        {
            cin >> prices[i];
            indices[prices[i]] = i + 1;
        }

        for (unsigned int i {0}; i < flavors; ++i)
        {
            if (prices[i] <= cash)
            {
                unsigned int remaining {cash - prices[i]};

                if (indices[remaining] && i + 1 != indices[remaining])
                {
                    cout << i + 1 << ' ' << indices[remaining] << '\n';
                    break;
                }
            }
        }
    }

    return 0;
}
