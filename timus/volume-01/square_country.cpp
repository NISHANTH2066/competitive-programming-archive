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

int main()
{
    use_io_optimizations();

    unsigned int quadrics;
    cin >> quadrics;

    vector<unsigned int> subtasks(quadrics + 1);

    for (unsigned int i {1}; i <= quadrics; ++i)
    {
        subtasks[i] = subtasks[i - 1] + 1;

        for (unsigned int j {1}; j * j <= i; ++j)
        {
            subtasks[i] = min(subtasks[i], subtasks[i - j * j] + 1);
        }
    }

    cout << subtasks[quadrics] << '\n';

    return 0;
}
