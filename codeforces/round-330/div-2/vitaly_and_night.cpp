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

    unsigned int floors;
    unsigned int flats;

    cin >> floors >> flats;

    unsigned int awake {0};

    for (unsigned int i {0}; i < floors; ++i)
    {
        for (unsigned int j {0}; j < flats; ++j)
        {
            bool is_first_lit;
            bool is_second_lit;

            cin >> is_first_lit >> is_second_lit;

            if (is_first_lit || is_second_lit)
            {
                ++awake;
            }
        }
    }

    cout << awake << '\n';

    return 0;
}
