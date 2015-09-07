#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using Iterator      = vector<unsigned int>::iterator;
using ConstIterator = vector<unsigned int>::const_iterator;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

unsigned long long mmerge(ConstIterator left_first,
                          ConstIterator left_last,
                          ConstIterator right_first,
                          ConstIterator right_last,
                          Iterator      result)
{
    unsigned long long inversions {0};

    while (left_first != left_last && right_first != right_last)
    {
        if (*left_first < *right_first)
        {
            *result = *left_first;
            ++left_first;
        }
        else
        {
            *result = *right_first;
            ++right_first;

            inversions += left_last - left_first;
        }

        ++result;
    }

    result = copy(left_first,  left_last,  result);
    result = copy(right_first, right_last, result);

    return inversions;
}

unsigned long long inversions_count(Iterator first, Iterator last)
{
    if (first + 1 >= last)
    {
        return 0;
    }

    auto middle = first + (last - first) / 2;

    unsigned long long inversions {inversions_count(first, middle) +
                                   inversions_count(middle, last)};

    vector<unsigned int> left(first, middle);
    vector<unsigned int> right(middle, last);

    inversions += mmerge(left .begin(), left .end(),
                         right.begin(), right.end(),
                         first);

    return inversions;
}

int main()
{
    use_io_optimizations();

    unsigned int test_cases;
    cin >> test_cases;

    for (unsigned int test {0}; test < test_cases; ++test)
    {
        unsigned int length;
        cin >> length;

        vector<unsigned int> sequence(length);

        for (auto& element : sequence)
        {
            cin >> element;
        }

        cout << inversions_count(sequence.begin(), sequence.end()) << '\n';
    }

    return 0;
}
