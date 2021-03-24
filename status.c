#include <stdio.h>
#include <stdlib.h>
#include "Global Variables.h"

struct next_to_go 
{
    int x;
    int y;
};

extern void order_status_judge(struct rider *current_rider, struct order *current_order, struct order *head_order) 
{ //judged by position and time
    int arrived(int, int, int, int);
    
    if (time - current_order->ordertime <= 30 && current_order->food_locationx >= 0 && current_order->food_locationy >= 0) {
        current_order->status = 0;
    }
    if (arrived(current_rider->locationx, current_rider->locationy, current_order->food_locationx, current_order->food_locationy)
        && current_order->status == 0) {
        current_order->status = 1;
        current_order->food_locationx = current_order->food_locationx * -1 - 1;
        current_order->food_locationy = current_order->food_locationy * -1 - 1;
    }
    if (arrived(current_rider->locationx, current_rider->locationy, current_order->destinationx, current_order->destinationy)
        && current_order->status == 1) {
        current_order->status = 2;
        current_rider->finished += 1;
		
		/*if (head_order->next == NULL) {
			current_rider->mission = NULL;
		} else {
        	struct order *temp_head = head_order;//order removed from queue
        	while (temp_head->next != current_order) {
            	temp_head = temp_head->next;
        	}
        	temp_head->next = current_order->next;
        	current_order = temp_head;
        }//////////////////////////////////////////////last*/
    }
    ////////////
    if (time - current_order->ordertime == 31 && current_order->status == 1) {
        current_rider->unfinished += 1;
        current_order->status = 3;
    }
    if (arrived(current_rider->locationx, current_rider->locationy, current_order->destinationx, current_order->destinationy)
        && current_order->status == 3) {
        current_order->status = 5;

        /*struct order *temp_head = head_order;//order removed from queue
        while (temp_head->next != current_order) {
            temp_head = temp_head->next;
        }
        temp_head->next = current_order->next;
        current_order = temp_head;*/
    }
    if (time - current_order->ordertime == 61 && current_order->status == 3) {
        current_order->status = 10;
    }
    /////////
    if (time - current_order->ordertime == 31 && current_order->status == 0) {
        current_rider->unfinished += 1;
        current_order->status = 4;
    }
    if (arrived(current_rider->locationx, current_rider->locationy, current_order->food_locationx, current_order->food_locationy)
        && current_order->status == 4) {
        current_order->status = 6;
    }
    if (arrived(current_rider->locationx, current_rider->locationy, current_order->destinationx, current_order->destinationy)
        && current_order->status == 6) {
        current_order->status = 8;

        /*struct order *temp_head = head_order;//order removed from queue
        while (temp_head->next != current_order) {
            temp_head = temp_head->next;
        }
        temp_head->next = current_order->next;
        current_order = temp_head;*/
    }
    if (time - current_order->ordertime == 61 && current_order->status == 6) {
        current_order->status = 7;
    }
    if (time - current_order->ordertime == 61 && current_order->status == 4) {
        current_order->status = 9;
    }
    if (current_order->status == 10 || current_order->status == 7 || current_order->status == 9) {
            printf("BANKRUPT!!!!!!!!!\n");
            exit(0);
    }
}
//current_rider：当前骑手
//current_order：当前订单
//head_order：当前骑手的订单队列头订单
/*用来判断当前骑手订单列中每一个订单的状态，具体解释如下（直接用status的值表示）：
0、4：当前订单未到达餐馆；0表示time <= 30， 4表示30 < time <= 60；
1、3、6：当前订单已经到达餐馆，但未到达食客；1表示time <= 30， 3、6表示30 < time <= 60；
2、5、8；当前订单已经到达食客；2表示time <= 30， 5、8表示30 < time <= 60；
7、10：当前订单在time <= 60内未被送达
*/
extern int arrived(int rx, int ry, int dx, int dy) 
{
    if ((rx == dx && ry == dy - 1) || (rx == dx && ry == dy + 1) || (ry == dy && rx == dx + 1) || (ry == dy && rx == dx - 1)) {
            return 1;
        } else {
            return 0;
        }
}
//rx、ry：骑手坐标
//dx、dy：目标餐馆/食客坐标
/*
用来判断骑手是否到达餐馆或食客
*/
/******LAST EDITED 2019_05_23******/
