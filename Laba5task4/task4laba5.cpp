#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "schedule.h"
using namespace std;

int main()
{
    cout << "Введите количество запросов (N):\n";
    cout << ">>> ";
    int N;
    cin >> N;
    cin.ignore();
    int currentMonth = 1;
    vector<vector<string>> schedule(daysInMonth(currentMonth));
    for (int i = 0; i < N; i++)
    {
        cout << ">>> ";
        string inputFromUser;
        getline(cin, inputFromUser);
        stringstream ss(inputFromUser);
        vector<string> tokens;
        string token;
        while (ss >> token)
        {
            tokens.push_back(token);
        }
        if (tokens.empty()) continue;
        string command = tokens[0];
        if (command == "CLASS")
        {
            if (tokens.size() < 3)
            {
                cout << "Ошибка: Неверная команда\n";
                continue;
            }
            int day = stoi(tokens[1]);
            string subject = tokens[2];
            CLASS(schedule, day, subject);
        }
        else if (command == "NEXT")
        {
            NEXT(schedule, currentMonth);
        }
        else if (command == "VIEW")
        {
            if (tokens.size() < 2)
            {
                cout << "Ошибка: Неверная команда\n";
                continue;
            }
            int day = stoi(tokens[1]);
            VIEW(schedule, day);
        }
        else
        {
            cout << "Неизвестная команда\n";
        }
    }
    return 0;
}
