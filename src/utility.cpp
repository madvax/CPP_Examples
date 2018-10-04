#include <iostream>
#include <ctime>
#include "utility.h"

using namespace std;

// Clear the terminal/console in either Linux or Windows
void   clearDisplay(){
#ifdef __unix__
      cout << "\x1B[2J\x1B[H"; // Clear the screen Linux
#elif defined(_WIN32) || defined(WIN32)
      // TODO: Fix this to not use system()
      system("cls"); // Clear the screen Windows
#endif
} /* end clearDisplay() */


// Get current date/time, format is YYYY-MM-DD HH:mm:ss
string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "Today is %Y-%m-%d\nTransaction Time %X UTC\n", &tstruct);
    return buf;
} /*  end currentDateTime() */


