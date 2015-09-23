#include <iostream>
#include <string>

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
        string sequence;
        cin >> sequence;

        unsigned int balance     {0};
        unsigned int max_balance {0};

        for (auto symbol : sequence)
        {
            if (symbol == '(')
            {
                ++balance;
            }
            else
            {
                --balance;
            }

            max_balance = max(max_balance, balance);
        }

        cout << string(max_balance, '(') << string(max_balance, ')') << '\n';
    }

    return 0;
}
