#ifndef log_H_
#define log_H_
#include <stdio.h>


int logInit();

int logPrintTime();



#ifndef  LOG_TRACE
#define LOG_TRACE printf

#define LOG_INFO(msg)  \
	do{ \
		logPrintTime();\
		LOG_TRACE msg; \
		LOG_TRACE("[%s %d] \n",__FUNCTION__,__LINE__);\
	}while(0)

#define LOG_ERROR(err_info)  \
	do{ \
		LOG_TRACE("\033[1;40;31m ");\
		logPrintTime();\
		LOG_TRACE err_info; \
		LOG_TRACE("[%s %d] \033[0m \n",__FUNCTION__,__LINE__);\
	}while(0)

#endif


#endif








