#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class BigInt
{
public:

    BigInt(unsigned int number)
    {
        if (number == 0)
        {
            digits.push_back(0);
        }

        for (unsigned int i {number}; i > 0; i /= 10)
        {
            digits.push_back(number % 10);
        }
    }

    BigInt& operator*=(unsigned int number)
    {
        for (unsigned int i {0}, carry {0}; i < digits.size() || carry; ++i)
        {
            if (i >= digits.size())
            {
                digits.push_back(0);
            }

            digits[i]  = digits[i] * number + carry;
            carry      = digits[i] / 10;
            digits[i] %= 10;
        }

        return *this;
    }

    friend
    ostream& operator<<(ostream&, const BigInt&);

private:

    vector<unsigned int> digits;
};

ostream& operator<<(ostream& out, const BigInt& number)
{
    for (auto i = number.digits.crbegin(); i != number.digits.crend(); ++i)
    {
        out << *i;
    }

    return out;
}

int main()
{
    use_io_optimizations();

    unsigned int heads;
    cin >> heads;

    BigInt max_iq {1};

    if (heads % 3 == 1)
    {
        max_iq *= min(heads, 4u);
        heads  -= min(heads, 4u);
    }
    else if (heads % 3 == 2)
    {
        max_iq *= min(heads, 2u);
        heads  -= min(heads, 2u);
    }

    for (unsigned int i {0}; i < heads; i += 3)
    {
        max_iq *= 3;
    }

    cout << max_iq << '\n';

    return 0;
}
