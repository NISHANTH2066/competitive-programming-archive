#include <iomanip>
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

    cout << fixed << setprecision(1);

    unsigned int friends        {0};
    unsigned int total_distance {0};

    string name;
    unsigned int distance;

    while (getline(cin, name) && cin >> distance && cin.ignore())
    {
        ++friends;
        total_distance += distance;
    }

    cout << static_cast<double>(total_distance) / friends << '\n';

    return 0;
}
