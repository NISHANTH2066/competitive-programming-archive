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
        unsigned int cops;
        unsigned int speed;
        unsigned int time;

        cin >> cops >> speed >> time;

        vector<bool> is_safe(101, true);

        for (unsigned int i {0}; i < cops; ++i)
        {
            unsigned int house;
            cin >> house;

            for (unsigned int j {0}; j <= min(house, speed * time); ++j)
            {
                is_safe[house - j] = false;
            }

            for (unsigned int j {1}; j <= min(100 - house, speed * time); ++j)
            {
                is_safe[house + j] = false;
            }
        }

        cout << count(is_safe.cbegin() + 1, is_safe.cend(), true) << '\n';
    }

    return 0;
}
