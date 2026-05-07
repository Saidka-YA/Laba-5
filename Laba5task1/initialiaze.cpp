#include "sclad.h"
#include <map>
#include <string>
#include <utility>

using namespace std;

void initialiazeSclad(map<string, pair<string, int>>& sclad)
{
    char zones[3] = {'A', 'B', 'C'};
    
    for (int zone = 0; zone < 3; zone++)
    {
        for (int rack = 1; rack < 18; rack++)
        {
            for (int section = 1; section < 5; section++)
            {
                for (int shelf = 1; shelf < 4; shelf++)
                {
                    std::string address = string(1, zones[zone]) 
                                            + to_string(rack) 
                                            + to_string(section) 
                                            + to_string(shelf);
                    
                    sclad[address] = {"", 0};
                }
            }
        }
    }
}