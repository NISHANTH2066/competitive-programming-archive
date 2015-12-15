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

    unsigned int people;
    unsigned int dialects;

    cin >> people >> dialects;

    unsigned int intersection {people};

    for (unsigned int i {0}; i < dialects; ++i)
    {
        unsigned int speakers;
        cin >> speakers;

        if (intersection + speakers < people)
        {
            intersection = 0;
        }
        else
        {
            intersection += speakers - people;
        }
    }

    cout << intersection << '\n';

    return 0;
}
