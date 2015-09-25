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

    int key;
    cin >> key;

    unsigned int elements;
    cin >> elements;

    for (unsigned int i {0}; i < elements; ++i)
    {
        int element;
        cin >> element;

        if (element == key)
        {
            cout << i << '\n';
        }
    }

    return 0;
}
