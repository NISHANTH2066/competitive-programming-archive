#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

const string row_delimiter {
    "+------------------------------+--------+-------------+\n"
};

const char column_delimiter {
    '|'
};

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void print_row(const string& name, const string& date, const string& score)
{
    cout << column_delimiter << setw(30) << left << name
         << column_delimiter << setw(8)  << left << date
         << column_delimiter << setw(12) << score
         << column_delimiter << '\n';
}

void read_contest_description(string& name, string& date, string& score)
{
    getline(cin, name);
    getline(cin, date);

    unsigned int problems;
    unsigned int submissions;

    cin >> problems >> submissions;
    cin.ignore();

    score = string(problems, '.') + string(13 - problems, ' ');

    for (unsigned int i {0}; i < submissions; ++i)
    {
        char problem;
        cin >> problem;
        cin.ignore();

        string verdict;
        getline(cin, verdict);

        if (verdict == "Accepted")
        {
            score[problem - 'A'] = 'o';
        }
        else if (score[problem - 'A'] != 'o')
        {
            score[problem - 'A'] = 'x';
        }
    }
}

int main()
{
    use_io_optimizations();

    unsigned int contests;
    cin >> contests;
    cin.ignore();

    cout << row_delimiter;
    print_row("Contest name", "Date", "ABCDEFGHIJKLM");
    cout << row_delimiter;

    for (unsigned int i {0}; i < contests; ++i)
    {
        string name;
        string date;
        string score;

        read_contest_description(name, date, score);
        print_row(name, date, score);
        cout << row_delimiter;
    }

    return 0;
}
