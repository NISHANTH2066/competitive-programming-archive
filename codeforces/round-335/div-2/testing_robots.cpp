#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned int move_x(unsigned int x, char direction, unsigned int height)
{
    if (direction == 'U')
    {
        return max(x - 1, 1u);
    }

    if (direction == 'D')
    {
        return min(x + 1, height);
    }

    return x;
}

unsigned int move_y(unsigned int y, char direction, unsigned int width)
{
    if (direction == 'L')
    {
        return max(y - 1, 1u);
    }

    if (direction == 'R')
    {
        return min(y + 1, width);
    }

    return y;
}

vector<unsigned int> tests_per_command(unsigned int current_x,
                                       unsigned int current_y,
                                       unsigned int height,
                                       unsigned int width,
                                       const string& directions)
{
    vector<unsigned int> tests(directions.size() + 1);
    tests[0] = 1;

    vector<vector<bool>> is_visited(height + 1, vector<bool>(width + 1));
    is_visited[current_x][current_y] = true;

    for (string::size_type i {0}; i < directions.size(); ++i)
    {
        current_x = move_x(current_x, directions[i], height);
        current_y = move_y(current_y, directions[i], width);

        if (!is_visited[current_x][current_y])
        {
            ++tests[i + 1];
            is_visited[current_x][current_y] = true;
        }
    }

    tests.back() += (height * width -
                     accumulate(tests.cbegin(), tests.cend(), 0u));

    return tests;
}

int main()
{
    use_io_optimizations();

    unsigned int height;
    unsigned int width;

    cin >> height >> width;

    unsigned int current_x;
    unsigned int current_y;

    cin >> current_x >> current_y;

    string directions;
    cin >> directions;

    auto tests = tests_per_command(current_x,
                                   current_y,
                                   height,
                                   width,
                                   directions);

    for (auto i = tests.cbegin(); i != tests.cend(); ++i)
    {
        cout << *i << " \n"[i + 1 == tests.cend()];
    }

    return 0;
}
