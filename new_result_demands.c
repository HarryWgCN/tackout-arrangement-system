#include <stdio.h>
#include <stdlib.h>
#include "Global Variables.h"

extern void result_check(int *fx, int *fy, int *dx, int *dy, int *finishn, int *overn, struct rider *cur_rider, struct order *cur_order) 
{
    extern void if_nearby(int *, int *, int *, int *, struct rider *, struct order *);
    extern void finished_num(int *, struct rider *, struct order *);
    extern void overtimed_num(int *, struct rider *, struct order *);

    	//if (!(cur_rider->addo->nearonce == 1))
			if_nearby(fx, fy, dx, dy, cur_rider, cur_order);
    	//if (!(cur_rider->addo->finonce == 1))
			finished_num(finishn, cur_rider, cur_order);
    	//if (!(cur_rider->addo->overonce == 1))
			overtimed_num(overn, cur_rider, cur_order);

}
/*
进行输出中新增的三个要求的处理，即：判断是否停靠、当前完成订单号、当前超时订单号
全局变量中struct addon为此服务
*/

extern void if_nearby(int *fx, int *fy, int *dx, int *dy, struct rider *cur_rider, struct order *cur_order) 
{
    extern int arrived(int, int, int, int);

    if ((cur_order->status == 0 || cur_order->status == 4) &&arrived(cur_rider->locationx, cur_rider->locationy, cur_order->food_locationx, cur_order->food_locationy)) {
        *fx = cur_order->food_locationx;
        *fy = cur_order->food_locationy;
        //cur_rider->addo->nearonce = 1;
    } else {
        *fx = -1;
        *fy = -1;
    }
    if ((cur_order->status == 2 || cur_order->status == 5 || cur_order->status == 8) && arrived(cur_rider->locationx, cur_rider->locationy, cur_order->destinationx, cur_order->destinationy)) {
        *dx = cur_order->destinationx;
        *dy = cur_order->destinationy;
        //cur_rider->addo->nearonce = 1;
    } else {
        *dx = -1;
        *dy = -1;
    }
}
/*
判断是否停靠，其实现方法为：
如果fx、fy或dx、dy出现二者均为-1，则没有停靠；否则返回停靠的坐标
*/
extern void finished_num(int *finishn, struct rider *cur_rider, struct order *cur_order) 
{
    extern int arrived(int, int, int, int);

    if ((cur_order->status == 2 || cur_order->status == 5 || cur_order->status == 8) &&
		arrived(cur_rider->locationx, cur_rider->locationy, cur_order->destinationx, cur_order->destinationy)) {
        *finishn = cur_order->number;
        //cur_rider->addo->finishn = 1;
    } else {
        *finishn = -1;
    }
}
/*
确定当前完成订单号，实现方法同上
*/
extern void overtimed_num(int *overn, struct rider *cur_rider, struct order *cur_order) 
{
    if (time - cur_order->ordertime > 30) {
        *overn = cur_order->number;
        //cur_rider->addo->overonce = 1;
    } else {
        *overn = -1;
    }
}
/*
确定当前超时订单号，实现方法同上
*/
