#include "log.h"
#include <sys/time.h> 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static struct timeval stuUtcStartTimeVal;
static int nLogInitFlag = 0;

int logInit()
{
	int ret = -1;
	memset(&stuUtcStartTimeVal,0,sizeof(struct timeval));
	
	ret = gettimeofday(&stuUtcStartTimeVal,NULL);
	if(0 != ret)
	{
		//printf("\n tv_sec[%lu] tv_usec[%lu]\n",stuTimeVal.tv_sec , stuTimeVal.tv_usec);
		return -1;
	}
	nLogInitFlag = 1;
	return 0;
}

int logPrintTime()
{
	int ret = -1;
	int hours = 0;
	int min = 0;
	int sec = 0;
	int millisecond = 0;
	
	unsigned long u32DiffTimeMs= 0;
	struct timeval stuTimeVal;
	if(nLogInitFlag == 0)
	{
		return -1;
	}
	
	memset(&stuTimeVal,0,sizeof(struct timeval));

	ret = gettimeofday(&stuTimeVal,NULL);
	if(0 != ret)
	{
		return -1;
	}

	u32DiffTimeMs += (stuTimeVal.tv_sec - stuUtcStartTimeVal.tv_sec)*1000;

	if(stuTimeVal.tv_usec >= stuUtcStartTimeVal.tv_usec)
	{
		u32DiffTimeMs += (stuTimeVal.tv_usec - stuUtcStartTimeVal.tv_usec)/1000;

		
	}
	else
	{
		u32DiffTimeMs -= (stuUtcStartTimeVal.tv_usec - stuTimeVal.tv_usec )/1000;
	}

	hours = (u32DiffTimeMs/1000)/3600;
	min = (u32DiffTimeMs/1000/60)%60;
	sec = (u32DiffTimeMs/1000)%60;
	millisecond = u32DiffTimeMs%1000;

	printf("--%d:%d:%d.%3d--",hours,min,sec,millisecond);

	return 0;
}




