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

    for (unsigned int games; cin >> games && games > 0; )
    {
        unsigned int wins_mary {0};
        unsigned int wins_john {0};

        for (unsigned int i {0}; i < games; ++i)
        {
            bool joh_won;
            cin >> joh_won;

            if (joh_won)
            {
                ++wins_john;
            }
            else
            {
                ++wins_mary;
            }
        }

        cout << "Mary won " << wins_mary << " times and "
             << "John won " << wins_john << " times\n";
    }

    return 0;
}
