#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
char* transfer(int num)
//屏幕上打印数字需要字符格式，此函数将十进制整数转换成为字符格式 
{
	char* str;
	int len;
	str=(char*)malloc(sizeof(char)*(getDigit(num)+1));
	str[0]='0';
	char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i,j,k;
	if(num==0)
	{
		str[0]='0';
		str[1]='\0';
		return str;
	}
	len=getDigit(num);
	for(i=0;i<len;i++)
	{
		str[i]=index[(num/(int)pow(10,len-i-1))];
		num=num%(int)pow(10,len-i-1);
	}
	
	str[i]='\0';
	k=0;
	return str;
}


