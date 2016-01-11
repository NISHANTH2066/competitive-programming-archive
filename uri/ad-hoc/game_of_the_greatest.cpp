#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    for (unsigned int rounds; cin >> rounds && rounds > 0; )
    {
        unsigned int first_score  {0};
        unsigned int second_score {0};

        for (unsigned int i {0}; i < rounds; ++i)
        {
            unsigned int first;
            unsigned int second;

            cin >> first >> second;

            if (first > second)
            {
                ++first_score;
            }
            else if (second > first)
            {
                ++second_score;
            }
        }

        cout << first_score << ' ' << second_score << '\n';
    }

    return 0;
}
