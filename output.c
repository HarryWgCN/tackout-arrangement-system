#include<stdio.h>
#include<stdlib.h>
#include"Global Variables.h"
#include"functions.h"
extern void output(struct rider *riderhead)
{
	struct rider *nowrider;//�ļ���� 
	nowrider=riderhead;
	int count=0;//count��ʾ�ᵥ���ͷ�����
	int totalfinished=0;//totalfinished��ʾ������� 
	int totalunfinished=0; //totalunfinished��ʾ��ʱ������ 
	FILE *fptr;
		 
    fptr = fopen("out.txt","ab+");
    if(money(riderhead)<0){
		fprintf(fptr, "BANKRUPT!!!!!!!!!\r\n");
		printf("BANKRUPT!!!!!!!!!\n");
		exit(0);
	}
   	fprintf(fptr, "ʱ�䣺%d \r\n", time);
   	fprintf(fptr, "Ǯ��%d \r\n",money(riderhead));
   	//printf("ʱ�䣺%d\n", time);
   	//printf("�ʽ�%d\n", fund);
   	while(nowrider!=NULL)
   	{    		
		totalfinished=totalfinished+nowrider->finished ;
		totalunfinished=totalunfinished+nowrider->unfinished;			
		nowrider=nowrider->next;
	}//��������������ܳ�ʱ�� 
	nowrider=riderhead;
	fprintf(fptr,"�ӵ�����%d \r\n", order_number);
	fprintf(fptr, "�������%d��", totalfinished);
	fprintf(fptr, "�ᵥ��");
	count=0;
	while(nowrider!=NULL && nowrider->mission != NULL)
	{
		if(nowrider->addo->finishn!=-1)
			count+=nowrider->addo->finishn;
		nowrider=nowrider->next;
	}	//����ᵥ��
	if(count!=0)
	fprintf(fptr, "%d  ", count);
	fprintf(fptr,"��");
	fprintf(fptr,"\r\n");
	nowrider=riderhead;
	fprintf(fptr, "��ʱ����%d��", totalunfinished);	
	fprintf(fptr, "������");
	count=0;
	while(nowrider!=NULL && nowrider->mission != NULL)
	{
		if(nowrider->addo->overn!=-1)
			count+=nowrider->addo->overn;
		nowrider=nowrider->next;
	}//���㷣����
	if(count!=0)
		fprintf(fptr, "%d ", count);
		fprintf(fptr,"��");
		fprintf(fptr,"\r\n");
	nowrider=riderhead;
	while(nowrider!=NULL && nowrider->mission != NULL)
	{
		fprintf(fptr, "����%dλ�ã�%d��%d ", nowrider->number, nowrider->locationx, nowrider->locationy);
		fprintf(fptr, "ͣ����");
		if(nowrider->addo->dx!=-1||nowrider->addo->dy!=-1) {
			if(nowrider->addo->fx!=-1||nowrider->addo->fy!=-1)
			fprintf(fptr,"�͹� %d %d ", nowrider->addo->fx, nowrider->addo->fy);
			fprintf(fptr,"ʳ�� %d %d��", nowrider->addo->dx, nowrider->addo->dy);
		}
		if(nowrider->addo->fx!=-1||nowrider->addo->fy!=-1)
		{
			if(nowrider->addo->dx!=-1||nowrider->addo->dy!=-1)
			fprintf(fptr,"ʳ�� %d %d��", nowrider->addo->dx, nowrider->addo->dy);
			fprintf(fptr,"�͹� %d %d ", nowrider->addo->fx, nowrider->addo->fy);
		}
		nowrider=nowrider->next;
		fprintf(fptr,"��");	
		fprintf(fptr,"\r\n");	
	}
	fclose(fptr);
	if(totalfinished+totalunfinished==row)
	{
		//exit(0);
	}
}
