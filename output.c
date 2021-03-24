#include<stdio.h>
#include<stdlib.h>
#include"Global Variables.h"
#include"functions.h"
extern void output(struct rider *riderhead)
{
	struct rider *nowrider;//文件输出 
	nowrider=riderhead;
	int count=0;//count表示结单数和罚单数
	int totalfinished=0;//totalfinished表示总完成数 
	int totalunfinished=0; //totalunfinished表示超时单总数 
	FILE *fptr;
		 
    fptr = fopen("out.txt","ab+");
    if(money(riderhead)<0){
		fprintf(fptr, "BANKRUPT!!!!!!!!!\r\n");
		printf("BANKRUPT!!!!!!!!!\n");
		exit(0);
	}
   	fprintf(fptr, "时间：%d \r\n", time);
   	fprintf(fptr, "钱：%d \r\n",money(riderhead));
   	//printf("时间：%d\n", time);
   	//printf("资金：%d\n", fund);
   	while(nowrider!=NULL)
   	{    		
		totalfinished=totalfinished+nowrider->finished ;
		totalunfinished=totalunfinished+nowrider->unfinished;			
		nowrider=nowrider->next;
	}//计算总完成数和总超时数 
	nowrider=riderhead;
	fprintf(fptr,"接单数：%d \r\n", order_number);
	fprintf(fptr, "完成数：%d；", totalfinished);
	fprintf(fptr, "结单：");
	count=0;
	while(nowrider!=NULL && nowrider->mission != NULL)
	{
		if(nowrider->addo->finishn!=-1)
			count+=nowrider->addo->finishn;
		nowrider=nowrider->next;
	}	//计算结单数
	if(count!=0)
	fprintf(fptr, "%d  ", count);
	fprintf(fptr,"；");
	fprintf(fptr,"\r\n");
	nowrider=riderhead;
	fprintf(fptr, "超时数：%d；", totalunfinished);	
	fprintf(fptr, "罚单：");
	count=0;
	while(nowrider!=NULL && nowrider->mission != NULL)
	{
		if(nowrider->addo->overn!=-1)
			count+=nowrider->addo->overn;
		nowrider=nowrider->next;
	}//计算罚单数
	if(count!=0)
		fprintf(fptr, "%d ", count);
		fprintf(fptr,"；");
		fprintf(fptr,"\r\n");
	nowrider=riderhead;
	while(nowrider!=NULL && nowrider->mission != NULL)
	{
		fprintf(fptr, "骑手%d位置：%d，%d ", nowrider->number, nowrider->locationx, nowrider->locationy);
		fprintf(fptr, "停靠：");
		if(nowrider->addo->dx!=-1||nowrider->addo->dy!=-1) {
			if(nowrider->addo->fx!=-1||nowrider->addo->fy!=-1)
			fprintf(fptr,"餐馆 %d %d ", nowrider->addo->fx, nowrider->addo->fy);
			fprintf(fptr,"食客 %d %d；", nowrider->addo->dx, nowrider->addo->dy);
		}
		if(nowrider->addo->fx!=-1||nowrider->addo->fy!=-1)
		{
			if(nowrider->addo->dx!=-1||nowrider->addo->dy!=-1)
			fprintf(fptr,"食客 %d %d；", nowrider->addo->dx, nowrider->addo->dy);
			fprintf(fptr,"餐馆 %d %d ", nowrider->addo->fx, nowrider->addo->fy);
		}
		nowrider=nowrider->next;
		fprintf(fptr,"；");	
		fprintf(fptr,"\r\n");	
	}
	fclose(fptr);
	if(totalfinished+totalunfinished==row)
	{
		//exit(0);
	}
}
