#ifdef WINDOWS
#include <conio.h>
#else
#include "kbhit.h"
#endif

#include "Supermarket.h"
#include <iostream>
#include <pthread.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>

#define kNumberCharCodesStart 48

using namespace std;

int main()
{
    init_keyboard();
    struct timeval start, end;
    double interval = 0.0f;    
    
    srand ( time(NULL) );
    
    Supermarket dia;
    char key = 0;
    int nKey = 0;
    do{
        gettimeofday(&start, NULL);
        if (kbhit())
        {
            key = readch();
            nKey = key - kNumberCharCodesStart;
            if (nKey > -1 && nKey < 10)
                dia.ChangeCashierStatus(nKey);
        }
                        
        #ifdef WINDOWS
        std::system ( "CLS" );
        #else
        std::system ( "clear" );
        #endif
        
        dia.RunSimulation(interval);
        dia.PrintStatus();
        
        gettimeofday(&end, NULL);
        interval = (end.tv_sec  - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0f;
    }while(key != 27);
    
    close_keyboard();
    return 0;
};