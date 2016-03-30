#include <cmath>
#include <iostream>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

double min_projection(unsigned int type, unsigned int size)
{
    if (type == 1)
    {
        return 2 * size;
    }
    else if (type == 2)
    {
        return size;
    }
    else
    {
        return size * sqrt(3) / 2;
    }
}

double max_projection(unsigned int type, unsigned int size)
{
    if (type == 1)
    {
        return 2 * size;
    }
    else if (type == 2)
    {
        return size * sqrt(2);
    }
    else
    {
        return size;
    }
}

int main()
{
    use_io_optimizations();

    unsigned int aperture_type;
    unsigned int aperture_size;
    cin >> aperture_type >> aperture_size;

    unsigned int covers;
    cin >> covers;

    unsigned int fitting_covers {0};

    for (unsigned int i {0}; i < covers; ++i)
    {
        unsigned int cover_type;
        unsigned int cover_size;

        cin >> cover_type >> cover_size;

        if (min_projection(cover_type, cover_size) <=
            max_projection(aperture_type, aperture_size))
        {
            ++fitting_covers;
        }
    }

    cout << fitting_covers << '\n';

    return 0;
}
