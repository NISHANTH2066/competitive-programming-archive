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
        vector<unsigned int> numbers(3);

        cin >> numbers[0]
            >> numbers[1]
            >> numbers[2];

        sort(numbers.begin(), numbers.end());

        cout << numbers[1] << '\n';
    }

    return 0;
}
