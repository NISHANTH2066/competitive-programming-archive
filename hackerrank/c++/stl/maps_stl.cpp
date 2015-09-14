#include <iostream>
#include <map>
#include <string>

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

    map<string, unsigned int> marks;

    unsigned int queries;
    cin >> queries;

    for (unsigned int i {0}; i < queries; ++i)
    {
        unsigned int type;
        string student;

        cin >> type >> student;

        if (type == 1)
        {
            unsigned int mark;
            cin >> mark;

            marks[student] += mark;
        }
        else if (type == 2)
        {
            marks[student] = 0;
        }
        else
        {
            cout << marks[student] << '\n';
        }
    }

    return 0;
}
