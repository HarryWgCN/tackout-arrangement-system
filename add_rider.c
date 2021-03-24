#include<stdio.h>
#include"Global Variables.h"
#include"constants.h"
static int identify_area();
extern void add_rider()
//增加骑手初始化 
{
	rider_number++;
	struct rider* nowrider,*newrider;
	newrider=malloc(sizeof(struct rider));
	if(riderhead==NULL)
	{
		riderhead=newrider;
	}
	else
	{
		for(nowrider=riderhead;nowrider->next!=NULL;nowrider=nowrider->next);
		nowrider->next=newrider;
	}
	newrider->number=rider_number;
	newrider->locationx=birthx;
	newrider->locationy=birthy;
	newrider->mission=NULL;
	newrider->next=NULL;
	newrider->unfinished=0;
	newrider->formerfinished=0;
	newrider->finished=0;
	newrider->mission_number=0;
	newrider->next=NULL;
	current_add_rider++;
	newrider->formerx=birthx;
	newrider->formery=birthy;
}
