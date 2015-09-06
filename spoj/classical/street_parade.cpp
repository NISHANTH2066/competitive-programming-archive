#include <iostream>
#include <stack>
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

    for (unsigned int count; cin >> count && count != 0; )
    {
        vector<unsigned int> cars(count);

        for (auto& car : cars)
        {
            cin >> car;
        }

        unsigned int next {1};
        stack<unsigned int> branch;

        for (auto car : cars)
        {
            branch.push(car);

            while (!branch.empty() && branch.top() == next)
            {
                branch.pop();
                ++next;
            }
        }

        cout << (branch.empty() ? "yes" : "no") << '\n';
    }

    return 0;
}
