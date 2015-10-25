#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool is_palindrome(unsigned int number)
{
    string digits {to_string(number)};

    for (string::size_type i {0}; i < digits.size() / 2; ++i)
    {
        if (digits[i] != digits[digits.size() - 1 - i])
        {
            return false;
        }
    }

    return true;
}

vector<unsigned int> palindrome_sums(unsigned int up_to)
{
    vector<unsigned int> sums(up_to + 1);

    for (unsigned int i {1}; i <= up_to; ++i)
    {
        sums[i] = sums[i - 1];

        if (is_palindrome(i))
        {
            sums[i] += i;
        }
    }

    return sums;
}

int main()
{
    use_io_optimizations();

    auto sums = palindrome_sums(100000);

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int left;
        unsigned int right;

        cin >> left >> right;

        cout << sums[right] - sums[left - 1] << '\n';
    }

    return 0;
}
