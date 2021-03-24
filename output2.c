#include<stdio.h>
#include<stdlib.h>
#include"Global Variables.h"
#include"functions.h"
#include<windows.h>
extern void output2(struct rider *riderhead){

	struct rider *currentptr;//命令行输出 
	currentptr=riderhead;
	int count=0;//count表示结单数和罚单数 
	int totalfinished=0;//totalfinished表示总完成数 
	int totalunfinished=0; //totalunfinished表示超时单总数 
	if(money(riderhead)<0)
		exit(0); 
   	printf("时间：%d \r\n", time);
   	printf("钱：%d \r\n",money(riderhead));
   	while(currentptr!=NULL)
   	{    		
		totalfinished=totalfinished+currentptr->finished ;
		totalunfinished=totalunfinished+currentptr->unfinished;			
		currentptr=currentptr->next;
	}//计算总完成数和总超时数 
	currentptr=riderhead;
	printf("接单数：%d \r\n", order_number/2);
	printf("完成数：%d；", totalfinished);
	printf("结单：");
	count=0;
	while(currentptr!=NULL && currentptr->mission != NULL)
	{
		if(currentptr->addo->finishn!=-1)
		count+=currentptr->addo->finishn;
		currentptr=currentptr->next;
	}//计算结单数 
	if(count!=0)
	printf("%d  ", count);
	printf("：");
	printf("\r\n");
	currentptr=riderhead;
	printf("超时数：%d；", totalunfinished);	
	printf("罚单：");
	count=0;
	while(currentptr!=NULL && currentptr->mission != NULL)
	{
		if(currentptr->addo->overn!=-1)
		count+=currentptr->addo->overn;
		currentptr=currentptr->next;
	}//计算罚单数 
	if(count!=0)
		printf("%d ", count);
		printf("；");
		printf("\r\n");
	currentptr=riderhead;
	while(currentptr!=NULL && currentptr->mission != NULL)
	{
		printf("骑手%d位置：%d, %d ", currentptr->number, currentptr->locationx, currentptr->locationy);
		printf("停靠：");
		if(currentptr->addo->dx!=-1||currentptr->addo->dy!=-1) {
			if(currentptr->addo->fx!=-1||currentptr->addo->fy!=-1)
			printf("餐馆 %d %d ", currentptr->addo->fx, currentptr->addo->fy);
			printf("食客 %d %d；", currentptr->addo->dx, currentptr->addo->dy);
			
		}
		if(currentptr->addo->fx!=-1||currentptr->addo->fy!=-1)
		{
			if(currentptr->addo->dx!=-1||currentptr->addo->dy!=-1)
			printf("食客 %d %d；", currentptr->addo->dx, currentptr->addo->dy);
			printf("餐馆 %d %d ", currentptr->addo->fx, currentptr->addo->fy);
		}
		currentptr=currentptr->next;
		printf("；");	
		printf("\r\n");	
	}//循环输出骑手信息 
	//Sleep(2000);
	if(totalfinished+totalunfinished==row - 1)
	{
		//system("pause");
		//return;
		//exit(0);
	}
}
