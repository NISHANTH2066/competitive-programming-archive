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

    unsigned int distance;
    unsigned int segment;
    unsigned int time;

    cin >> distance >> segment >> time;

    cout << distance / segment * time                 << ' '
         << (distance + segment - 1) / segment * time << '\n';

    return 0;
}
