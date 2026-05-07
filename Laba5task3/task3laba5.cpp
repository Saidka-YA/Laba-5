#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include "aviation.h"
using namespace std;

int main()
{
    map<string, vector<string> > planes;
    map<string, vector<string> > towns;

    while (true)
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

        Type type = parseCommand(tokens[0]);

        if (type == Type::CREATE_PLANE)
        {
            CREATE_PLANE(planes, towns, tokens);
        }
        else if (type == Type::PLANES_FOR_TOWN)
        {
            if (tokens.size() < 2)
            {
                cout << "Ошибка: Неверная команда\n";
                continue;
            }
            PLANES_FOR_TOWN(towns, tokens[1]);
        }
        else if (type == Type::TOWNS_FOR_PLANE)
        {
            if (tokens.size() < 2)
            {
                cout << "Ошибка: Неверная команда\n";
                continue;
            }
            TOWNS_FOR_PLANE(planes, towns, tokens[1]);
        }
        else if (type == Type::PLANES)
        {
            PLANES(planes);
        }
        else
        {
            cout << "Неизвестная команда\n";
        }
    }
    return 0;
}
