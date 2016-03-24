#include <iostream>
#include <utility>

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

    unsigned int first;
    unsigned int second;

    cin >> first >> second;

    if (first > second)
    {
        swap(first, second);
    }

    unsigned int minutes {0};

    while (first > 0 && second > 1)
    {
        ++minutes;
        ++first;
        second -= 2;

        if (first > second)
        {
            swap(first, second);
        }
    }

    cout << minutes << '\n';


    return 0;
}
