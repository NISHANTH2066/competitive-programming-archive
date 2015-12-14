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

class TestingRobots
{
public:

    void read_input()
    {
        cin >> height    >> width
            >> initial_x >> initial_y
            >> directions;

        tests.resize(directions.size() + 1);
    }

    void solve()
    {
        unsigned int current_x {initial_x};
        unsigned int current_y {initial_y};

        tests[0] = 1;

        vector<vector<bool>> is_visited(height + 1, vector<bool>(width + 1));
        is_visited[current_x][current_y] = true;

        for (string::size_type i {0}; i < directions.size(); ++i)
        {
            move(current_x, current_y, directions[i]);

            if (!is_visited[current_x][current_y])
            {
                ++tests[i + 1];
                is_visited[current_x][current_y] = true;
            }
        }

        tests.back() += (width * height -
                         accumulate(tests.cbegin(), tests.cend(), 0u));
    }

    void write_output()
    {
        for (auto i = tests.cbegin(); i != tests.cend(); ++i)
        {
            cout << *i << " \n"[i + 1 == tests.cend()];
        }
    }

private:

    unsigned int width;
    unsigned int height;

    unsigned int initial_x;
    unsigned int initial_y;

    string directions;

    vector<unsigned int> tests;

    void move(unsigned int& x, unsigned int& y, char direction)
    {
        if (direction == 'U')
        {
            x = max(x - 1, 1u);
        }
        else if (direction == 'D')
        {
            x = min(x + 1, height);
        }
        else if (direction == 'L')
        {
            y = max(y - 1, 1u);
        }
        else if (direction == 'R')
        {
            y = min(y + 1, width);
        }
    }
};

int main()
{
    use_io_optimizations();

    TestingRobots instance;

    instance.read_input();
    instance.solve();
    instance.write_output();

    return 0;
}
