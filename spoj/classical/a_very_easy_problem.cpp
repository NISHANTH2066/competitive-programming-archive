#include <iostream>
#include <string>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

string convert(unsigned int number)
{
    string converted;

    for (unsigned int i {31}; i-- > 0; )
    {
        if (number & (1 << i))
        {
            if (i == 0)
            {
                converted += "2(0)";
            }
            else if (i == 1)
            {
                converted += '2';
            }
            else
            {
                converted += "2(" + convert(i) + ')';
            }

            number ^= (1 << i);

            if (number > 0)
            {
                converted += '+';
            }
        }
    }

    return converted;
}

int main()
{
    use_io_optimizations();

    for (auto number : {137, 1315, 73, 136, 255, 1384, 16385})
    {
        cout << number << '=' << convert(number) << '\n';
    }

    return 0;
}
