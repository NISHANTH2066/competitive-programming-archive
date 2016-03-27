/*
    ID:   gsshopo1
    PROG: friday
    LANG: C++11
*/

#include <fstream>
#include <vector>

using namespace std;

enum Weekday
{
    Saturday, Sunday, Monday, Tuesday, Wednesday, Thursday, Friday
};

inline
bool is_leap(unsigned int year)
{
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

inline
unsigned int days_in_month(unsigned int month, unsigned int year)
{
    static const vector<unsigned int> days {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    return days[month - 1] + (month == 2 && is_leap(year));
}

int main()
{
    ifstream fin  {"friday.in"};
    ofstream fout {"friday.out"};

    unsigned int period;
    fin >> period;

    unsigned int day {Saturday};
    vector<unsigned int> frequencies(7);

    for (unsigned int year {1900}; year < 1900 + period; ++year)
    {
        for (unsigned int month {1}; month <= 12; ++month)
        {
            ++frequencies[day];
            day = (day + days_in_month(month, year)) % 7;
        }
    }

    for (auto i = frequencies.cbegin(); i != frequencies.cend(); ++i)
    {
        fout << *i << " \n"[i + 1 == frequencies.cend()];
    }

    return 0;
}
