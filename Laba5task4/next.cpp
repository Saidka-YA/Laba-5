#include <iostream>
#include <vector>
#include <string>
#include "schedule.h"
using namespace std;

void NEXT(vector<vector<string>>& schedule, int& currentMonth)
{
    int oldDays = schedule.size();
    currentMonth++;
    if (currentMonth > 12)
        currentMonth = 1;
    int newDays = daysInMonth(currentMonth);
    if (newDays < oldDays)
    {
        for (int i = newDays; i < oldDays; i++)
        {
            for (int j = 0; j < schedule[i].size(); j++)
            {
                schedule[newDays - 1].push_back(schedule[i][j]);
            }
        }
    }
    schedule.resize(newDays);
    cout << "Переход на следующий месяц\n";
}