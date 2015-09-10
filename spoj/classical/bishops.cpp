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

class BigInt
{
public:
    BigInt() = default;

    BigInt(unsigned int number)
    {
        for (unsigned int i {number}; i > 0; i /= 10)
        {
            digits.push_back(i % 10);
        }
    }

    BigInt operator+(const BigInt& other) const
    {
        BigInt sum {*this};
        unsigned int length {max(sum.size(), other.size())};

        for (unsigned int i {0}, carry {0}; i < length || carry; ++i)
        {
            if (i == sum.size())
            {
                sum.digits.push_back(0);
            }

            sum.digits[i] += carry;

            if (i < other.size())
            {
                sum.digits[i] += other.digits[i];
            }

            carry = (sum.digits[i] >= 10);

            if (carry)
            {
                sum.digits[i] -= 10;
            }
        }

        return sum;
    }

    BigInt operator-(const BigInt& other) const
    {
        BigInt difference {*this};

        for (unsigned int i {0}, carry {0}; i < other.size() || carry; ++i)
        {
            difference.digits[i] -= carry;

            if (i < other.size())
            {
                difference.digits[i] -= other.digits[i];
            }

            carry = (difference.digits[i] < 0);

            if (carry)
            {
                difference.digits[i] += 10;
            }
        }

        difference.trim();

        return difference;
    }

    bool operator==(unsigned int number) const
    {
        return *this == BigInt{number};
    }

    bool operator==(const BigInt& other) const
    {
        return digits == other.digits;
    }

    unsigned int size() const
    {
        return digits.size();
    }

    friend
    istream& operator>>(istream&, BigInt&);

    friend
    ostream& operator<<(ostream&, const BigInt&);

private:
    vector<int> digits;

    void trim()
    {
        while (!digits.empty() && digits.back() == 0)
        {
            digits.pop_back();
        }
    }
};

istream& operator>>(istream& in, BigInt& number)
{
    string sequence;
    in >> sequence;

    number.digits.clear();

    for (auto i = sequence.crbegin(); i != sequence.crend(); ++i)
    {
        number.digits.push_back(*i - '0');
    }

    return in;
}

ostream& operator<<(ostream& out, const BigInt& number)
{
    if (number.size() == 0)
    {
        out << 0;
    }

    for (auto i = number.digits.crbegin(); i != number.digits.crend(); ++i)
    {
        out << *i;
    }

    return out;
}

int main()
{
    use_io_optimizations();

    for (BigInt size; cin >> size; )
    {
        cout << (size == 1 ? 1 : size + size - BigInt{2}) << '\n';
    }

    return 0;
}
