#include <algorithm>
#include <iostream>
#include <numeric>
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

    unsigned int exams;
    cin >> exams;

    vector<unsigned int> marks(exams);

    for (auto& mark : marks)
    {
        cin >> mark;
    }

    if (find(marks.cbegin(), marks.cend(), 3) != marks.cend())
    {
        cout << "None\n";
    }
    else if (count(marks.cbegin(), marks.cend(), 5) == exams)
    {
        cout << "Named\n";
    }
    else if (accumulate(marks.cbegin(), marks.cend(), 0u) >= 4.5 * exams)
    {
        cout << "High\n";
    }
    else
    {
        cout << "Common\n";
    }

    return 0;
}
