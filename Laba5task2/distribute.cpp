#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool compareVisitors(const pair<string, int>& a, const pair<string, int>& b)
{
    return a.second > b.second;
}
void DISTRIBUTE(int windows, vector<pair<string, int>> visitors)
{
    sort(visitors.begin(), visitors.end(), compareVisitors);
    vector<vector<string>> distribution(windows);
    vector<int> busyTime(windows, 0);
    for (int i = 0; i < visitors.size(); i++)
    {
        int windowIndex = 0;
        int minTime = busyTime[0];
        for (int j = 1; j < windows; j++)
        {
            if (busyTime[j] < minTime)
            {
                minTime = busyTime[j];
                windowIndex = j;
            }
        }
        distribution[windowIndex].push_back(visitors[i].first);
        busyTime[windowIndex] += visitors[i].second;
    }
    for (int i = 0; i < windows; i++)
    {
        cout << "Окно " << i + 1 << " (" << busyTime[i] << " минут): ";
        for (int j = 0; j < distribution[i].size(); j++)
        {
            cout << distribution[i][j];
            if (j != distribution[i].size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "\n";
    }
}