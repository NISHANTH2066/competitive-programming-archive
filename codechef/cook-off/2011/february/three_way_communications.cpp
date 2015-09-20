#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

inline
bool are_in_range(int delta_x, int delta_y, unsigned int range)
{
    return delta_x * delta_x + delta_y * delta_y <= range * range;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int range;
        cin >> range;

        vector<int> x(3);
        vector<int> y(3);

        for (unsigned int i {0}; i < 3; ++i)
        {
            cin >> x[i] >> y[i];
        }

        auto connected = are_in_range(x[0] - x[1], y[0] - y[1], range) +
                         are_in_range(x[0] - x[2], y[0] - y[2], range) +
                         are_in_range(x[1] - x[2], y[1] - y[2], range);

        cout << (connected >= 2 ? "yes" : "no") << '\n';
    }

    return 0;
}
