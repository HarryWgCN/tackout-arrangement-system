#include"Global Variables.h"
#include"functions.h"
extern void add_mission(void)
//鼠标下单部分的订单初始化 
{
	struct order* addorder;
	order_number++;
	addorder=malloc(sizeof(struct order));
	addorder->number=order_number;
	addorder->ordertime=time;
	addorder->next=NULL;
	addorder->food_locationx=options_number[0];
	addorder->food_locationy=options_number[1];
	addorder->destinationx=options_number[2];
	addorder->destinationy=options_number[3];
	order_by_area(addorder);
	//printf("\n successfully-------------\n");
}
