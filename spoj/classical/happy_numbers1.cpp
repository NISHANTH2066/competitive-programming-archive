#include <iostream>
#include <set>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int sum_of_squared_digits(unsigned  int number)
{
    unsigned int sum {0};

    for (unsigned int i {number}; i > 0; i /= 10)
    {
        unsigned int digit {i % 10};
        sum += digit * digit;
    }

    return sum;
}

int main()
{
    use_io_optimizations();

    unsigned int number;
    cin >> number;

    set<unsigned int> seen;

    while (number != 1 && !seen.count(number))
    {
        seen.insert(number);
        number = sum_of_squared_digits(number);
    }

    if (number == 1)
    {
        cout << seen.size() << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }

    return 0;
}
