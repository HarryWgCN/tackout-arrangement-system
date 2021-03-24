#include<stdio.h>
#include"Global Variables.h"
#include"constants.h"
static int judge_whether_dangerous(int);
static int rider_situation(struct rider* r);
static int weight(struct rider* rider,struct order* noworder);
static struct rider* distribute_to(struct order* noworder);
extern void order_by_area(struct order* noworder)
//文件输入的订单分配 
{
	struct rider* rider;
	struct order* now_mission;
	rider=distribute_to(noworder);
	rider->mission_number++;
 	if(rider->mission==NULL)
	{
		rider->mission=noworder;
	}
	else
	{
		for(now_mission=rider->mission;;now_mission=now_mission->next)
		{
			if(now_mission->next==NULL)
			{
				now_mission->next=noworder;
				break;
			}
		}
	}
	order_number++;
}


static struct rider* distribute_to(struct order* noworder)
//决定此订单分配给哪位骑手 
{
	struct rider *target,*examine;
	target=riderhead;
	for(examine=riderhead->next;examine!=NULL;examine=examine->next)
	{
		if(weight(examine,noworder)<weight(target,noworder))
		{
			target=examine;
		}
	}
	return target;
}


static int weight(struct rider* rider,struct order* noworder)
//根据多种不同数据给予骑手一个可供比较的对于接单的合适性 
{
	int weight=0,count;
	struct order* examine;
	int min,centralx=0,centraly=0;
	rider->mission_number=0;
	for(examine=rider->mission;examine!=NULL;examine=examine->next)
	{
		if(examine->status==2||examine->status==5||examine->status==8);
		else
			rider->mission_number++;
		
	}
	weight+=rider->mission_number*mission_weight;
	weight+=abs(noworder->food_locationx-noworder->destinationx)*distance_weight;
	weight+=abs(noworder->food_locationy-noworder->destinationy)*distance_weight;
	if(rider->mission!=NULL)
	{
		min=abs(rider->mission->destinationx-noworder->food_locationx);
		min+=abs(rider->mission->destinationy-noworder->food_locationy);
		for(examine=rider->mission;examine!=NULL;examine=examine->next)
		{
			if(abs(examine->destinationx-noworder->food_locationx)+abs(examine->destinationy-noworder->food_locationy)<min)
			min=abs(examine->destinationx-noworder->food_locationx)+abs(examine->destinationy-noworder->food_locationy);
		}
		weight+=min*former_mission_convinience;
	}
	else
	{
		weight+=abs(rider->locationx-noworder->food_locationx);
		weight+=abs(rider->locationy-noworder->food_locationy);
	}
	if(rider->mission!=NULL)
	{
		for(examine=rider->mission,count=0;examine!=NULL;examine=examine->next,count++)
		{
			centralx+=abs(examine->destinationx+examine->food_locationx)/2;
			centraly+=abs(examine->destinationy+examine->food_locationy)/2;
		}
		centralx=centralx/count;
		centraly=centraly/count;
		for(examine=rider->mission,count=0;examine!=NULL;examine=examine->next,count++)
		{
			weight+=abs(centralx-abs(examine->destinationx+examine->food_locationx)/2)*discrete_degree;
			weight+=abs(centraly-abs(examine->destinationy+examine->food_locationy)/2)*discrete_degree;	
		}
	}
	/*if(judge_whether_dangerous(rider_situation(rider))>=100)
		weight+=1000;
	else
		weight-=1;
	if(rider->mission!=NULL)
	{
		for(examine=rider->mission,count=0;examine!=NULL;examine=examine->next,count++)
		{
			weight+=(time-examine->ordertime);
		}
	}*/
	return weight;
}


int rider_situation(struct rider* r)
//判断骑手此时的情况处境 
{
	struct order* mission;
	int count;
	for(mission=r->mission,count=0;mission!=NULL;mission=mission->next)
	{
		count++;
	}
	if(count>=4)
		return 1;
	for(mission=r->mission,count=0;mission!=NULL;mission=mission->next)
	{
		count+=abs(r->locationx-mission->food_locationx);
		count+=abs(r->locationy-mission->food_locationy);
		count+=abs(r->locationx-mission->destinationx);
		count+=abs(r->locationy-mission->destinationy);
	}
}

static int judge_whether_dangerous(int component)
{
	if(component>100)
		return 1;
	else
		return 0;
}
