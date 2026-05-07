#include <iostream>
#include <sstream>
#include <vector>
#include "sclad.h"
using namespace std;

int main()
{
    map<string, pair<string, int>> sclad;
    initialiazeSclad(sclad);
    cout << "Введите команду в формате: <команда> <наименование товара> <количество> <адрес ячейки\n";
    cout << "Доступные команды: ADD, REMOVE, INFO, EXIT\n";
    while(true)
    {
        cout << ">>> ";
        string inputFromUser;
        getline(cin, inputFromUser);
        stringstream ss(inputFromUser);
        vector<string> tokens;
        string command, nameOfProduct, address;
        int quantityProduct = 0;
        string token;
        while (ss >> token)
        {
            tokens.push_back(token);
        }
        if (tokens.empty()) continue;
        command = tokens[0];
        if (command == "EXIT") break;
        if (command == "ADD" || command == "REMOVE")
        {
            if (tokens.size() < 4)
            {
                cout << "Ошибка: неверный ввод команды!";
                continue;
            }
            address = tokens.back();
            quantityProduct = stoi(tokens[tokens.size() - 2]);
            for (size_t i = 1; i <= tokens.size() - 3; i++)
            {
                nameOfProduct += tokens[i];
                if (i != tokens.size() - 3) nameOfProduct += " ";
            }
        }
        if (command == "ADD") 
        {
            ADD(sclad, nameOfProduct, quantityProduct, address);
        }
        else if (command == "REMOVE")
        {
            REMOVE(sclad, nameOfProduct, quantityProduct, address);
        }
        else if (command == "INFO")
        {
            INFO(sclad);
        }
    }
    return 0;
}