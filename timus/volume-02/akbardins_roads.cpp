#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Point
{
    int x;
    int y;
    int id;
};

bool operator<(const Point& left, const Point& right)
{
    return left.x < right.x;
}

int main()
{
    use_io_optimizations();

    unsigned int towns;
    cin >> towns;

    vector<Point> positions(towns);

    for (unsigned int i {0}; i < towns; ++i)
    {
        cin >> positions[i].x >> positions[i].y;
        positions[i].id = i + 1;
    }

    sort(positions.begin(), positions.end());

    for (unsigned int i {0}; i < towns - 1; i += 2)
    {
        cout << positions[i].id << ' ' << positions[i + 1].id << '\n';
    }

    return 0;
}
