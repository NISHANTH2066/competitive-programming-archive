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

    unsigned int max_palindrome {0};

    for (unsigned int i {100}; i <= 999; ++i)
    {
        for (unsigned int j {100}; j <= 999; ++j)
        {
            if (is_palindrome(to_string(i * j)))
            {
                max_palindrome = max(max_palindrome, i * j);
            }
        }
    }

    cout << max_palindrome << '\n';

    return 0;
}
