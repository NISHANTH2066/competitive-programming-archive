#include <algorithm>
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

    unsigned int basic_flat;
    unsigned int basic_rate;

    unsigned int combined_flat;
    unsigned int combined_limit;
    unsigned int combined_rate;

    unsigned int unlimited_flat;

    unsigned int phone_calls;

    cin >> basic_flat
        >> basic_rate
        >> combined_flat
        >> combined_limit
        >> combined_rate
        >> unlimited_flat
        >> phone_calls;

    unsigned int time {0};

    for (unsigned int i {0}; i < phone_calls; ++i)
    {
        char delimiter;

        unsigned int minutes;
        unsigned int seconds;

        cin >> minutes >> delimiter >> seconds;

        if (minutes > 0 || seconds > 6)
        {
            time += minutes + (seconds > 0);
        }
    }

    auto overtime = max(combined_limit, time) - combined_limit;

    cout << "Basic:     " << basic_flat + time * basic_rate           << '\n'
         << "Combined:  " << combined_flat + overtime * combined_rate << '\n'
         << "Unlimited: " << unlimited_flat                           << '\n';

    return 0;
}
