#include<stdio.h>
#include"Global Variables.h"
extern int get_row()
//��ö����ļ��������Ա������˳��������� 
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

