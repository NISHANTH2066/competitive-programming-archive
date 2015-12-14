#include <iostream>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<unsigned int> read_sequence(unsigned int length)
{
    vector<unsigned int> sequence(length);

    for (auto& element : sequence)
    {
        cin >> element;
    }

    return sequence;
}

vector<vector<unsigned int>> inverse(const vector<unsigned int>& sequence)
{
    vector<vector<unsigned int>> indices(sequence.size() + 1);

    for (vector<unsigned int>::size_type i {0}; i < sequence.size(); ++i)
    {
        indices[sequence[i]].push_back(i + 1);
    }

    return indices;
}

bool is_impossible(const vector<unsigned int>& sequence,
                   const vector<vector<unsigned int>>& indices)
{
    for (auto element : sequence)
    {
        if (indices[element].empty())
        {
            return true;
        }
    }

    return false;
}

bool is_ambiguous(const vector<unsigned int>& sequence,
                  const vector<vector<unsigned int>>& indices)
{
    for (auto element : sequence)
    {
        if (indices[element].size() > 1)
        {
            return true;
        }
    }

    return false;
}

vector<unsigned int> initial_sequence(const vector<unsigned int>& sequence,
                                      const vector<vector<unsigned int>>& indices)
{
    vector<unsigned int> initial(sequence.size());

    for (vector<unsigned int>::size_type i {0}; i < sequence.size(); ++i)
    {
        initial[i] = indices[sequence[i]].front();
    }

    return initial;
}

int main()
{
    use_io_optimizations();

    unsigned int f_length;
    unsigned int b_length;

    cin >> f_length >> b_length;

    auto sequence_f = read_sequence(f_length);
    auto sequence_b = read_sequence(b_length);
    auto indices    = inverse(sequence_f);

    if (is_impossible(sequence_b, indices))
    {
        cout << "Impossible\n";
    }
    else if (is_ambiguous(sequence_b, indices))
    {
        cout << "Ambiguity\n";
    }
    else
    {
        cout << "Possible\n";

        auto sequence_a = initial_sequence(sequence_b, indices);

        for (auto i = sequence_a.cbegin(); i != sequence_a.cend(); ++i)
        {
            cout << *i << " \n"[i + 1 == sequence_a.cend()];
        }
    }

    return 0;
}
