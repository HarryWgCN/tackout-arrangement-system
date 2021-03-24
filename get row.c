#include<stdio.h>
#include"Global Variables.h"
extern int get_row()
//获得订单文件的行数以便设置退出程序条件 
{
	int count=0;
	FILE *fp;
  	int fl;
  	if((fp = fopen("sales.txt", "r")) == NULL)
    	return -1;
  	while(!feof(fp))
  	{
		fl = fgetc(fp);
    	if(fl == '\n')
    	count++;
 	}
    fclose(fp);
    return count;
}

