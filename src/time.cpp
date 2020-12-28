// C++ function that returns year/month/day/hour/minutes/seconds.
// Ilan Mittelman - 5/12/2020.

#include <ctime>

int get_time(const int request)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    switch (request)
    {
    case 1: // year
        return 1900 + ltm -> tm_year;

    case 2: // month
        return 1 + ltm -> tm_mon;

    case 3: // day
        return ltm -> tm_mday;

    case 4: // hour
        return 1 + ltm -> tm_hour;

    case 5: // minutes
        return 1 + ltm -> tm_min;

    case 6: // seconds
        return 1 + ltm -> tm_sec;

    default:
        return -1;
    }

    return -1;
}