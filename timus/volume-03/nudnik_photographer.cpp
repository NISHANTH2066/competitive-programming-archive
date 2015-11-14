#include <iostream>
#include <vector>

using namespace std;

inline
void  use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    use_io_optimizations();

    unsigned int people;
    cin >> people;

    vector<unsigned int> photos(people + 1);

    photos[1] = 1;
    photos[2] = 1;

    for (unsigned int i {3}; i <= people; ++i)
    {
        photos[i] = photos[i - 1] + photos[i - 3] + 1;
    }

    cout << photos[people] << '\n';

    return 0;
}
