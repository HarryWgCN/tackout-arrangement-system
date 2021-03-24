#include"egg.h"
#include"constants.h"
#include"functions.h"
#include"Global Variables.h"
#include<string.h>
void exhibit_data(void)
//各种数据的展示 
{
	exhibit_egg=LayEgg();
	int totalfinished=0,totalunfinished=0;
	struct rider* nowrider;
	char number[100],*p;
	
	MovePen(exhibit,money_exhibit);
	DrawString("资金:"); 
	p=transfer(money(riderhead));
	DrawString(p);
	//printf("ziziziziziiz");
	//printf("%d",money(riderhead));
	
	
	MovePen(exhibit,get_order_number);
	DrawString("接单数:");
	p=transfer(order_number/2);
	DrawString(p);
	
	nowrider=riderhead; 
	while(nowrider!=NULL)
   	{    		
		totalfinished=totalfinished+nowrider->finished ;
		totalunfinished=totalunfinished+nowrider->unfinished;			
		nowrider=nowrider->next;
	}
	MovePen(exhibit,finished_number);
	DrawString("完成数:"); 
	p=transfer(totalfinished);
	DrawString(p);
	
	
	MovePen(exhibit,time_over_number);
	DrawString("超时数:");
	p=transfer(totalunfinished);
	DrawString(p);MovePen(exhibit,time_over_number);
	
	
	MovePen(exhibit,time_exhibit);
	DrawString("时刻:"); 
	p=transfer(time);
	DrawString(p);
}
