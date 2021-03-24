#include<stdio.h>
#include<stdlib.h>
#include"Global Variables.h"
#include"functions.h"
extern int money(struct rider *riderhead)
{
	struct rider* currentptr = riderhead;
	int Fund=1000;
	while(currentptr!=NULL)
	{
		Fund=Fund+currentptr->finished*10;
		Fund=Fund-currentptr->unfinished*50;
		currentptr=currentptr->next;
	}//计算当前资金数 
	Fund=Fund-rider_number*300;
	return Fund;
}
