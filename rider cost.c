#include<stdio.h>
#include<stdlib.h>
#include"Global Variables.h"
#include"constants.h"
extern void ridernumber1(int fund, struct rider* riderhead) 
{
	struct rider* currentptr;//
	currentptr=riderhead;
	int ridernumber2=0;//ridernumber2Ϊ���㵱ǰ�������ı��� 
	if(rider_number>=max_riders)
		return ;
	if(money(riderhead)==1000&&riderhead==NULL)
	{
		add_rider();
		add_rider();
	}//�����ʼ������ 
	while(currentptr!=NULL)
	{
		ridernumber2=currentptr->number;
		currentptr=currentptr->next;
	}//���㵱ǰ������ 
	if(ridernumber2>rider_number)
	{
		rider_number=ridernumber2;
	}//���µ�ǰ������ 
	if(rider_number>=max_riders)
	{
		return ;
	} 
	if(money(riderhead)>enough)
	{
		add_rider();
	}//�������� 
}
