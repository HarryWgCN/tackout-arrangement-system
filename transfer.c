#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
char* transfer(int num)
//��Ļ�ϴ�ӡ������Ҫ�ַ���ʽ���˺�����ʮ��������ת����Ϊ�ַ���ʽ 
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


