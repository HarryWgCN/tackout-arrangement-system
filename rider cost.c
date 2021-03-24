#include<stdio.h>
#include<stdlib.h>
#include"Global Variables.h"
#include"constants.h"
extern void ridernumber1(int fund, struct rider* riderhead) 
{
	struct rider* currentptr;//
	currentptr=riderhead;
	int ridernumber2=0;//ridernumber2为计算当前骑手数的变量 
	if(rider_number>=max_riders)
		return ;
	if(money(riderhead)==1000&&riderhead==NULL)
	{
		add_rider();
		add_rider();
	}//购买初始骑手数 
	while(currentptr!=NULL)
	{
		ridernumber2=currentptr->number;
		currentptr=currentptr->next;
	}//计算当前骑手数 
	if(ridernumber2>rider_number)
	{
		rider_number=ridernumber2;
	}//更新当前骑手数 
	if(rider_number>=max_riders)
	{
		return ;
	} 
	if(money(riderhead)>enough)
	{
		add_rider();
	}//购买骑手 
}
