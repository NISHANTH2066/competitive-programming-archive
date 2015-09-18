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

    unsigned int size;
    unsigned int number;

    cin >> size >> number;

    unsigned int occurrences {0};

    for (unsigned int i {1}; i <= size; ++i)
    {
        if (number % i == 0 && number / i <= size)
        {
            ++occurrences;
        }
    }

    cout << occurrences << '\n';

    return 0;
}
