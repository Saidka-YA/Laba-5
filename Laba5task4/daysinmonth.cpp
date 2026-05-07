


int daysInMonth(int month)
{
    if (month == 2) return 28;
    if (month == 1 || month == 4 || month == 6 ||
        month == 8 || month == 10 || month == 12)
        return 30;
    return 31;
}