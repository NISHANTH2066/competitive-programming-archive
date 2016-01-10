#include <iostream>
#include <map>
#include <string>

using namespace std;

const map<char, unsigned int> leds {
    {'0', 6}, {'1', 2}, {'2', 5}, {'3', 5}, {'4', 4},
    {'5', 5}, {'6', 6}, {'7', 3}, {'8', 7}, {'9', 6}
};

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
        string number;
        cin >> number;

        unsigned int needed_leds {0};

        for (auto digit : number)
        {
            needed_leds += leds.at(digit);
        }

        cout << needed_leds << " leds\n";
    }

    return 0;
}
