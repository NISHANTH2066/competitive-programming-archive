#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void read_files(unsigned int count, vector<bool>& flags)
{
    for (unsigned int i {0}; i < count; ++i)
    {
        unsigned int file;
        cin >> file;

        flags[file] = true;
    }
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int total;
        unsigned int ignored;
        unsigned int tracked;

        cin >> total >> ignored >> tracked;

        vector<bool> is_ignored(101);
        read_files(ignored, is_ignored);

        vector<bool> is_tracked(101);
        read_files(tracked, is_tracked);

        unsigned int ignored_and_tracked {0};

        for (unsigned int i {1}; i <= 100; ++i)
        {
            if (is_ignored[i] && is_tracked[i])
            {
                ++ignored_and_tracked;
            }
        }

        cout << ignored_and_tracked                             << ' '
             << total - ignored - tracked + ignored_and_tracked << '\n';
    }

    return 0;
}
