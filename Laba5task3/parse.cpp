#include <string>
#include "aviation.h"
using namespace std;

Type parseCommand(const string& command)
{
    if (command == "CREATE_PLANE") return Type::CREATE_PLANE;
    if (command == "PLANES_FOR_TOWN") return Type::PLANES_FOR_TOWN;
    if (command == "TOWNS_FOR_PLANE") return Type::TOWNS_FOR_PLANE;
    if (command == "PLANES") return Type::PLANES;
    return Type::UNKNOWN;
}