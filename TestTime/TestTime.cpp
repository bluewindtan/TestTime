// TestTime.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <time.h>
#include <stdlib.h>

void PrintTime(__time64_t time64)
{
	struct tm newtime;
	char buff[80];

	printf("time = %lld\n", time64);

	_localtime64_s(&newtime, &time64);
	asctime_s( buff, sizeof(buff), &newtime );
	printf( "===== Local time is %s\n", buff );

	_gmtime64_s(&newtime, &time64);
	asctime_s( buff, sizeof(buff), &newtime );
	printf( "===== Coordinated universal time is %s\n", buff );

}

int _tmain(int argc, _TCHAR* argv[])
{
	__time64_t nowTime;
	_time64( &nowTime );
	PrintTime(nowTime);

	nowTime = 0;
	PrintTime(nowTime);

	system("pause");
	return 0;
}

