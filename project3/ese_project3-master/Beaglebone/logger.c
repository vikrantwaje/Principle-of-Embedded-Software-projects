







/*---------------------------------------------------------------------------------------------------------------------------------*/
/*
 /*-----------------------------------------------------------------------------------------------------------------------------------*/
 /* 0.Documentation section
  -----------------------------------------------------------------------------------------------------------------------------------

  @file-logging.c

 @brief:This file includes various logging functions

 @author: Vikrant Waje and Kiran Hegde

 @date:28 November 2017


 */
/*--------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<time.h>
#include<stdint.h>

time_t t;
clock_t start,end;


/*---------------------------------------------------------------------------------------------------------------------------------*/
/*
@brief: Logs when logger buffer gets initialised
Displays a log message on putty when logger buffer gets initialised
@param: None
@param: None
@return: None
/*---------------------------------------------------------------------------------------------------------------------------------*/
void LOGGERINITIALISED(){
printf("1    ");
printf("   LOGGERINITIALISED    ");
printf("  %s\n\r",ctime(&t));
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
/*
@brief: Logs when GPIO gets initialised
Displays a log message on putty when GPIO gets initialised
@param: None
@param: None
@return: None
/*---------------------------------------------------------------------------------------------------------------------------------*/
void GPIOINITIALISED(){
printf("2    ");
printf("   GPIOINITIALISED    ");
printf("  %s\n\r",ctime(&t));
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
/*
@brief: Logs when System gets initialised
Displays a log message on putty when System gets initialised
@param: None
@param: None
@return: None
/*---------------------------------------------------------------------------------------------------------------------------------*/
void SYSTEMINITIALISED(){
printf("3    ");
printf("   SYSTEMINITIALISED    ");
printf("  %s\n\r",ctime(&t));
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
/*
@brief: Logs when profiling starts
Displays a log message on putty when profiling starts
@param: None
@param: None
@return: None
/*---------------------------------------------------------------------------------------------------------------------------------*/
void PROFILINGSTARTED(){
printf("4");
printf("   PROFILING STARTED	");
printf("  %s",ctime(&t));
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
/*
@brief: Logs when system gets error
Displays a log message on putty when system gets error
@param: None
@param: None
@return: None
/*---------------------------------------------------------------------------------------------------------------------------------*/
void ERROR(){
printf("5");
printf("   ERROR       ");
printf("  %s",ctime(&t));
}



/*---------------------------------------------------------------------------------------------------------------------------------*/
/*
@brief: Logs when profiling gets completed
Displays a log message on putty when profiling gets completed
@param: None
@param: None
@return: None
/*---------------------------------------------------------------------------------------------------------------------------------*/
void PROFILINGCOMPLETED(){
printf("6");
printf("   PROFILINGCOMPLETED        ");
printf("  %s",ctime(&t));
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
/*
@brief: Logs when profiling result is calculated
Displays a log message on putty when profiling result gets calculated
@param: None
@param: None
@return: None
/*---------------------------------------------------------------------------------------------------------------------------------*/
void PROFILINGRESULT(){
printf("7");
printf("   PROFILINGRESULT        ");
printf("  %s",ctime(&t));
printf("  %f",((double)end-start)/CLOCKS_PER_SEC);
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
/*
@brief: Logs when system halts
Displays a log message on putty when system halts
@param: None
@param: None
@return: None
/*---------------------------------------------------------------------------------------------------------------------------------*/
void SYSTEM_HALTED(){
printf("8");
printf("   SYSTEMHALTED        ");
printf("  %s",ctime(&t));

}
/*---------------------------------------------------------------------------------------------------------------------------------*/
/*
@brief: Logs when data analysis is started
Displays a log message on putty when data analysis starts
@param: None
@param: None
@return: None
/*---------------------------------------------------------------------------------------------------------------------------------*/
void DATAANALYSISSTARTED(){
printf("9");
printf("   DATAANLYSISSTARTED        ");
printf("  %s",ctime(&t));

}
/*---------------------------------------------------------------------------------------------------------------------------------*/
/*
@brief: Logs when alphabetic count is computed
Displays a log message on putty when alphabetic count is computed
@param: None
@param: None
@return: None
/*---------------------------------------------------------------------------------------------------------------------------------*/
void ALPHACOUNT(){
	uint8_t alphacount;
	printf("10");
	printf("   ALPHACOUNT        ");
	printf("%d",alphacount);
	printf("  %s",ctime(&t));

}
/*---------------------------------------------------------------------------------------------------------------------------------*/
/*
@brief: Logs when numeric count is computed
Displays a log message on putty when numeric count is calculated
@param: None
@param: None
@return: None
/*---------------------------------------------------------------------------------------------------------------------------------*/
void NUMERICCOUNT(){
  uint8_t numericcount;
  printf("11");
  printf("   NUMERICCOUNT        ");
  printf("%d",numericcount);
  printf("  %s",ctime(&t));

}
/*---------------------------------------------------------------------------------------------------------------------------------*/
/*
@brief: Logs when punctuation count is computed
Displays a log message on putty when punctuation count is computed
@param: None
@param: None
@return: None
/*---------------------------------------------------------------------------------------------------------------------------------*/
void PUNCTUATIONCOUNT(){
  uint8_t punctuationcount;
  printf("12");
  printf("   PUNCTUATIONCOUNT       ");
  printf("%d",punctuationcount);
  printf("  %s",ctime(&t));

}
/*---------------------------------------------------------------------------------------------------------------------------------*/
/*
@brief: Logs when data analysis gets completed
Displays a log message on putty when data analysis gets completed
@param: None
@param: None
@return: None
/*---------------------------------------------------------------------------------------------------------------------------------*/
void DATAANALYSISCOMPLETED(){
  uint8_t punctuationcount;
    printf("13");
    printf("   DATAANLYSISCOMPLETED       ");
    printf("  %s",ctime(&t));



}
void main(){
    printf("LOG_ID   Payload                   RTC\n\r");
    time(&t);
LOGGERINITIALISED();
int o=0;
start=clock();
for(o=0;o<20000;o++);
end=clock();
}
