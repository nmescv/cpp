#include "gen.h"
#include "utils.h"
#include <sys/timeb.h>
#include "TCHAR.h"
#include"RandomNumbers.h"
#include"cTimer.h"
#include"printIntro.h"

long g_lTimeTick = 0;

int main(int argc, char *argv[], char *envp[]) 
{
	long LastTimeIn=0;	
	long LastTimeInMS = 0;	
	int RValue = false;
	int Counter=0;  
	int CaptureModeHex = 0;
	int NewChar=0;
	int nResult = 0;

    printf ("main - start\n");
    printIntro *intro = new printIntro();
    CTimer *_time = new CTimer();
    
#ifdef FILE_OUTPUT
	int nOpenFileToken = 0;
	char *FileNameF = "TimeSt.log";
	FILE *fi = NULL; 
 
 // open the file for input:	
 if ( (fi = fopen(FileNameF, "a+") ) != NULL)
  {
  // printf ("file %s was open succesfully\n", FileNameF);
   nOpenFileToken = 1;
  }
 else
  {
   printf ("file %s was not open\n", FileNameF);
   getchar(); // pause, xyLe...
   nOpenFileToken = 0;
  }
	  
  fprintf(fi, "Start time: %d\n", Get1msTime());
#endif// FILE_OUTPUT

if (argc >= 2)
{
  // i = atoi(argv[1]);
  if ( (strcmp(argv[1], "/?") ==0) || (strcmp(argv[1], "-?") ==0) || (strcmp(argv[1], "help") ==0) )
  {
   intro->PrintIntroduction();
   return 1;
  }
}
 
    int random_number = 0;
    CRandomNumbers *_myRND = new CRandomNumbers();
    for (int i = 0; i < 2000; i ++)
    {
        random_number = _myRND->getRandomNumber(0, 49);
        cout << i << " - Random number: " << random_number << endl;
    }
 //*************MAIN LOOP*****************//
 do 
 {
   //This is simple Windows way:
   Sleep(100);
   
   nResult = produceRND();   
   // printf ("1-Time: %ld. RND: %d\n", _time->Get1msTimeMS(), nResult);
   printf ("%d; ", nResult);
   
   //nResult = produceRND();   
   //printf ("2-Time: %ld. RND: %d\n", _time->Get1msTimeMS(), nResult);

/*
 // This is complicated one-thread way:
  if ((( Get1msTimeMS() - LastTimeInMS)>1000-1) || (LastTimeInMS > Get1msTimeMS() ))
	{	
     printf ("Time: %ld.\n",Get1msTimeMS());
     Sleep(100);
     	  
	 LastTimeInMS = Get1msTimeMS();
   }   
*/

  // control of endless loop (may be also in monitor.cpp)
	if (_kbhit())  // has anything been pressed from keyboard ?
	{       
   
	 NewChar=(unsigned char)_getch();
	 if ((NewChar & 0xff) == 24)  // CTRL-X   pressed
	 {
	  RValue = true; // END mark
	 }
	 if (NewChar == 'd')  // pressed
	 {
	   if (1 == CaptureModeHex) 
		   CaptureModeHex = 1;
		 else
 		   CaptureModeHex = 0;
	 }
	}


}while (!RValue);  

#ifdef FILE_OUTPUT
 if (1 == nOpenFileToken)
   fclose (fi);
#endif
 
printf ("Application complete.\n");
system ("PAUSE");
return 0;
}

