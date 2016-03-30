#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Score
{
    string name;
    double time;
    double finish;
};

struct ByFinish
{
    bool operator()(const Score& left, const Score& right) const
    {
        return left.finish < right.finish;
    }
};

vector<Score> read_scores()
{
    unsigned int biathletes;
    cin >> biathletes;

    vector<Score> scores(biathletes);

    for (unsigned int i {0}; i < biathletes; ++i)
    {
        string name;
        unsigned int minutes;
        char delimiter;
        double seconds;

        cin >> name >> minutes >> delimiter >> seconds;

        scores[i].name   = name;
        scores[i].time   = minutes * 60 + seconds;
        scores[i].finish = scores[i].time + i * 30;
    }

    return scores;
}

vector<string> find_leaders(const vector<Score>& scores)
{
    vector<string> leaders;
    double best_time {100 * 60};

    for (const auto& score : scores)
    {
        if (score.time < best_time)
        {
            leaders.push_back(score.name);
            best_time = score.time;
        }
    }

    return leaders;
}

int main()
{
    use_io_optimizations();

    auto scores = read_scores();
    sort(scores.begin(), scores.end(), ByFinish());

    auto leaders = find_leaders(scores);
    sort(leaders.begin(), leaders.end());

    cout << leaders.size() << '\n';

    for (const auto& leader : leaders)
    {
        cout << leader << '\n';
    }

    return 0;
}
