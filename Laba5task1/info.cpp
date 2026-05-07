#include "sclad.h"
#include <map>
#include <utility>
#include <iostream>
#include <iomanip>

void INFO(std::map<std::string, std::pair<std::string, int>>& sclad)
{
    int totalA = 0;
    int totalB = 0;
    int totalC = 0;
    char zones[3] = {'A', 'B', 'C'};
    for (int zone = 0; zone < 3; zone++)
    {
        for (int rack = 1; rack < 18; rack++)
        {
            for (int section = 1; section < 5; section++)
            {
                for (int shelf = 1; shelf < 4; shelf++)
                {
                    std::string address = std::string(1, zones[zone]) 
                                            + std::to_string(rack) 
                                            + std::to_string(section) 
                                            + std::to_string(shelf);
                        if (zones[zone] == 'A')
                    {
                        totalA += sclad[address].second;
                    }
                    else if (zones[zone] == 'B')
                    {
                        totalB += sclad[address].second;
                    }
                    else totalC += sclad[address].second;
                }
            }
        }
    }
    int totalProduct = totalA + totalB + totalC;
    double scladPercent = (double)totalProduct / 6120 * 100;
    double percentA = (double)totalA / 2040 * 100;
    double percentB = (double)totalB / 2040 * 100;
    double percentC = (double)totalC / 2040 * 100;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Загруженность склада: " << scladPercent << '%' << std::endl;
    std::cout << "Загруженность зоны А: " << percentA << '%' << std::endl;
    std::cout << "Загруженность зоны B: " << percentB << '%' << std::endl;
    std::cout << "Загруженность зоны С: " << percentC << '%' << std::endl;
    std::cout << "Заполненные ячейки:" << std::endl;
    for (int zone = 0; zone < 3; zone++)
    {
        for (int rack = 1; rack < 18; rack++)
        {
            for (int section = 1; section < 5; section++)
            {
                for (int shelf = 1; shelf < 4; shelf++)
                {
                    std::string address = std::string(1, zones[zone]) 
                                            + std::to_string(rack) 
                                            + std::to_string(section) 
                                            + std::to_string(shelf);
                    if (sclad[address].second > 0)
                    {
                        std::cout << address << ": " << 
                        sclad[address].first << 
                        " (" << sclad[address].second << ")"
                         << std::endl;
                    }
                }
            }
        }
    }
    std::cout << "Пустые ячейки:" << std::endl;
    for (int zone = 0; zone < 3; zone++)
    {
        for (int rack = 1; rack < 18; rack++)
        {
            for (int section = 1; section < 5; section++)
            {
                for (int shelf = 1; shelf < 4; shelf++)
                {
                    std::string address = std::string(1, zones[zone]) 
                                            + std::to_string(rack) 
                                            + std::to_string(section) 
                                            + std::to_string(shelf);
                    if (sclad[address].second == 0)
                    {
                        std::cout << address << ", ";
                    }
                }
            }
        }
    }
    std::cout << std::endl;
}