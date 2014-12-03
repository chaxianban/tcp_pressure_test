#include "../module.h"

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include<netinet/in.h>
#include<netinet/tcp.h>
#include<arpa/inet.h>
#include <getopt.h> 

using namespace std;

static char buf[4096];
char *ptr = NULL;


int encodeRequest(char* data, int maxLen)
{
    //只做一次初始化
    {
        sprintf(buf, "%s","if=getvminfo");
        ptr = buf;
    }

    int len = strlen(ptr);
       
    if (len > maxLen) 
        return -1;
memset(data,0,maxLen);
    memcpy(data, ptr, len);

	return len;
}

int encodeRequest_1(char* data, int maxLen)
{
    {
        sprintf(buf, "%s","|192.168.1.34|");
        ptr = buf;
    }

    int len = strlen(ptr);

    if (len > maxLen)
        return -1;

memset(data,0,maxLen);
    memcpy(data, ptr, len);

        return len;
}

int decodeResponse(char* data, int len)
{
	if(strcmp(data,"ok\n")==0)
	{
		return 1;
	}
	return 0;
}

int getsocketport(int fd)
{
        struct sockaddr_in localhost;
        int lh_len = sizeof(localhost);
        getsockname(fd, (struct sockaddr *)&localhost, (socklen_t *)&lh_len);
        return ntohs(localhost.sin_port); 
}
