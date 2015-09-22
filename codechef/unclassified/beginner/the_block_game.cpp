#include <iostream>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool is_palindrome(const string& sequence)
{
    for (string::size_type i {0}; i < sequence.size() / 2; ++i)
    {
        if (sequence[i] != sequence[sequence.size() - 1 - i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        string number;
        cin >> number;

        if (is_palindrome(number))
        {
            cout << "wins";
        }
        else
        {
            cout << "losses";
        }

        cout << '\n';
    }

    return 0;
}
