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

    unsigned int hours;
    unsigned int minutes;

    cin >> hours >> minutes;

    if (minutes < 45)
    {
        minutes += 60;

        if (hours < 1)
        {
            hours += 24;
        }

        --hours;
    }

    minutes -= 45;

    cout << hours << ' ' << minutes << '\n';

    return 0;
}
