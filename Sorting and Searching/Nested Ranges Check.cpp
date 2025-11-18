#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

bool compareTimings(const std::pair<int, int> &t1, const std::pair<int, int> &t2)
{
    if (t1.first != t2.first)
    {
        return t1.first < t2.first;
    }
    return t1.second > t2.second;
}

int main()
{
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> timings(N);
    std::map<std::pair<int, int>, int> timingsIndex;
    std::vector<int> contains(N, 0), contained(N, 0);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> timings[i].first >> timings[i].second;
        timingsIndex[timings[i]] = i;
    }

    std::sort(timings.begin(), timings.end(), compareTimings);

    int maxFinish = 0;

    for (int i = 0; i < N; ++i)
    {
        if (timings[i].second <= maxFinish)
        {
            contained[timingsIndex[timings[i]]] = 1;
        }
        maxFinish = std::max(maxFinish, timings[i].second);
    }

    int minFinish = 1e9 + 5;

    for (int i = N - 1; i >= 0; --i)
    {
        if (timings[i].second >= minFinish)
        {
            contains[timingsIndex[timings[i]]] = 1;
        }
        minFinish = std::min(minFinish, timings[i].second);
    }

    for (int i = 0; i < N; ++i)
    {
        std::cout << contains[i] << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < N; ++i)
    {
        std::cout << contained[i] << " ";
    }
    std::cout << "\n";

    return 0;
}