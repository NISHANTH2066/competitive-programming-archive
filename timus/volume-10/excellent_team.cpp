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

    unsigned int pirates;
    cin >> pirates;

    unsigned int max_position    {1};
    unsigned int max_comparisons {0};

    unsigned int current_position    {1};
    unsigned int current_comparisons {0};

    unsigned int current_disadvantages;
    cin >> current_disadvantages;

    for (unsigned int i {2}; i <= pirates; ++i)
    {
        unsigned int disadvantages;
        cin >> disadvantages;

        ++current_comparisons;

        if (current_comparisons > max_comparisons)
        {
            max_position    = current_position;
            max_comparisons = current_comparisons;
        }

        if (disadvantages < current_disadvantages)
        {
            current_position      = i;
            current_comparisons   = 1;
            current_disadvantages = disadvantages;
        }
    }

    cout << max_position << '\n';

    return 0;
}
