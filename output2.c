#include<stdio.h>
#include<stdlib.h>
#include"Global Variables.h"
#include"functions.h"
#include<windows.h>
extern void output2(struct rider *riderhead){

	struct rider *currentptr;//��������� 
	currentptr=riderhead;
	int count=0;//count��ʾ�ᵥ���ͷ����� 
	int totalfinished=0;//totalfinished��ʾ������� 
	int totalunfinished=0; //totalunfinished��ʾ��ʱ������ 
	if(money(riderhead)<0)
		exit(0); 
   	printf("ʱ�䣺%d \r\n", time);
   	printf("Ǯ��%d \r\n",money(riderhead));
   	while(currentptr!=NULL)
   	{    		
		totalfinished=totalfinished+currentptr->finished ;
		totalunfinished=totalunfinished+currentptr->unfinished;			
		currentptr=currentptr->next;
	}//��������������ܳ�ʱ�� 
	currentptr=riderhead;
	printf("�ӵ�����%d \r\n", order_number/2);
	printf("�������%d��", totalfinished);
	printf("�ᵥ��");
	count=0;
	while(currentptr!=NULL && currentptr->mission != NULL)
	{
		if(currentptr->addo->finishn!=-1)
		count+=currentptr->addo->finishn;
		currentptr=currentptr->next;
	}//����ᵥ�� 
	if(count!=0)
	printf("%d  ", count);
	printf("��");
	printf("\r\n");
	currentptr=riderhead;
	printf("��ʱ����%d��", totalunfinished);	
	printf("������");
	count=0;
	while(currentptr!=NULL && currentptr->mission != NULL)
	{
		if(currentptr->addo->overn!=-1)
		count+=currentptr->addo->overn;
		currentptr=currentptr->next;
	}//���㷣���� 
	if(count!=0)
		printf("%d ", count);
		printf("��");
		printf("\r\n");
	currentptr=riderhead;
	while(currentptr!=NULL && currentptr->mission != NULL)
	{
		printf("����%dλ�ã�%d, %d ", currentptr->number, currentptr->locationx, currentptr->locationy);
		printf("ͣ����");
		if(currentptr->addo->dx!=-1||currentptr->addo->dy!=-1) {
			if(currentptr->addo->fx!=-1||currentptr->addo->fy!=-1)
			printf("�͹� %d %d ", currentptr->addo->fx, currentptr->addo->fy);
			printf("ʳ�� %d %d��", currentptr->addo->dx, currentptr->addo->dy);
			
		}
		if(currentptr->addo->fx!=-1||currentptr->addo->fy!=-1)
		{
			if(currentptr->addo->dx!=-1||currentptr->addo->dy!=-1)
			printf("ʳ�� %d %d��", currentptr->addo->dx, currentptr->addo->dy);
			printf("�͹� %d %d ", currentptr->addo->fx, currentptr->addo->fy);
		}
		currentptr=currentptr->next;
		printf("��");	
		printf("\r\n");	
	}//ѭ�����������Ϣ 
	//Sleep(2000);
	if(totalfinished+totalunfinished==row - 1)
	{
		//system("pause");
		//return;
		//exit(0);
	}
}
