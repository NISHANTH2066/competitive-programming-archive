#include <iostream>
#include <vector>

using namespace std;

const vector<unsigned int> denominations {100, 50, 10, 5, 2, 1};

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
        unsigned int money;
        cin >> money;

        unsigned int notes {0};

        for (auto denomination : denominations)
        {
            notes += money / denomination;
            money %= denomination;
        }

        cout << notes << '\n';
    }

    return 0;
}
