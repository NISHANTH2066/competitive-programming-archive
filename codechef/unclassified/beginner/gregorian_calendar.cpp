#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<string> weekdays {
    "monday",
    "tuesday",
    "wednesday",
    "thursday",
    "friday",
    "saturday",
    "sunday"
};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline
unsigned int days(unsigned int year)
{
    return year + year / 4 - year / 100 + year / 400;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int year;
        cin >> year;

        cout << weekdays[(days(year - 1) - days(1899)) % 7] << '\n';
    }

    return 0;
}
