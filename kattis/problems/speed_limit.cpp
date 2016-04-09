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

    for (int readings; cin >> readings && readings != -1; )
    {
        unsigned int distance      {0};
        unsigned int previous_time {0};

        for (unsigned int i {0}; i < readings; ++i)
        {
            unsigned int speed;
            unsigned int current_time;

            cin >> speed >> current_time;

            distance      += (current_time - previous_time) * speed;
            previous_time  = current_time;
        }

        cout << distance << " miles\n";
    }

    return 0;
}
