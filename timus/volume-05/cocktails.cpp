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
            digits.push_back(i % 10);
        }
    }

    BigInt& operator+=(const BigInt& number)
    {
        auto max_size = max(digits.size(), number.digits.size());

        for (unsigned int i {0}, carry {0}; i < max_size || carry; ++i)
        {
            if (i >= digits.size())
            {
                digits.push_back(0);
            }

            if (i < number.digits.size())
            {
                digits[i] += number.digits[i];
            }

            digits[i] += carry;
            carry      = digits[i] / 10;
            digits[i] %= 10;
        }

        return *this;
    }

    BigInt operator+(const BigInt& number) const
    {
        auto sum = *this;
        sum += number;

        return sum;
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

    BigInt operator*(unsigned int number) const
    {
        auto product = *this;
        product *= number;

        return product;
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

    unsigned int components;
    cin >> components;

    BigInt cocktails {0};

    for (unsigned int i {2}; i <= components; ++i)
    {
        BigInt with_i_components {1};

        for (unsigned int j {0}; j < i; ++j)
        {
            with_i_components *= components - j;
        }

        cocktails += with_i_components;
    }

    cout << cocktails << '\n';

    return 0;
}
