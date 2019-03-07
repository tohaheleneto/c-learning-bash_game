#include <termios.h>

static struct termios old,sec;

void initTermios(int echo) 
{
    tcgetattr(0, &old); /* grab old terminal i/o settings */
    sec = old; /* make new settings same as old settings */
    sec.c_lflag &= ~ICANON; /* disable buffered i/o */
    sec.c_lflag &= ~ECHO; /* set no echo mode */
    tcsetattr(0, TCSANOW, &sec); /* use these new terminal i/o settings now */
}

void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}