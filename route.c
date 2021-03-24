#include <stdio.h>
#include <stdlib.h>
#include "Global Variables.h"

#define WARN_TIME 20

struct next_to_go 
{
    int x;
    int y;
};

extern void where_to_go(struct rider *current_rider, struct order *orderhead, struct next_to_go *one_togo) 
{//core part of the route management//queue set by priority of :location->time//result in the (re)build of the queue of next_to_go
    extern int jugde_is(struct rider*, struct order *, struct order *);

    if (orderhead == NULL) {//no order for the rider yet
        one_togo->x = current_rider->locationx;
        one_togo->y = current_rider->locationy;
    } else if (orderhead->next == NULL) {//only one order for the rider for now
        if(orderhead->status == 0 || orderhead->status == 4) {
            one_togo->x = orderhead->food_locationx;
            one_togo->y = orderhead->food_locationy;
        } else if (orderhead->status == 1 || orderhead->status == 3 || orderhead->status == 6) {
            one_togo->x = orderhead->destinationx;
            one_togo->y = orderhead->destinationy;
        } else if (orderhead->status == 2 || orderhead->status == 5 || orderhead->status == 8) {
        	one_togo->x = orderhead->destinationx;
            one_togo->y = orderhead->destinationy;
		}
    } else {//more than one order(attached to the end of an former single order), need a loop here
        struct order *best_order = orderhead;
        struct order *current_order = orderhead->next;

        while (current_order != NULL) {
            if (jugde_is(current_rider, best_order, current_order) == 0) {
                //
            } else if (jugde_is(current_rider, best_order, current_order) == 1) {
                best_order = current_order;
            } else {
                //
            }
            if (best_order->status == 1 || best_order->status == 3 || best_order->status == 6) {
                    one_togo->x = best_order->destinationx;
                    one_togo->y = best_order->destinationy;
                } else if (best_order->status == 0 || best_order->status == 4){//add something
                    one_togo->x = best_order->food_locationx;
                    one_togo->y = best_order->food_locationy;
                } else if (best_order->status == 2 || best_order->status == 5 || best_order->status == 8) {
                    one_togo->x = best_order->destinationx;
                    one_togo->y = best_order->destinationy;
                }

            current_order = current_order->next;
        }
    }
}
//current_rider����ǰ����
//orderhead����ǰ���ֶ�������ͷ����
//one_togo��������һ����Ŀ���
/*
������һ���������ص����Ŷ���
��������������ǰ������һ������һ��ʱ�䵥λ����Ŀ������
*/
extern int jugde_is(struct rider *current_rider, struct order *order_past, struct order *order_now) 
{//1 for now can replace past
    extern int distan(int, int, struct rider *);
	if (order_past->status == 2 || order_past->status == 5 || order_past->status == 8) {
		return 1;
	}
    if (time - order_past->ordertime <= 30 && time - order_now->ordertime <= 30) {
        if (order_past->status == 0 && order_now->status == 0) {
            if (time - order_past->ordertime <= WARN_TIME) {
                return 0;
            } else if (time - order_now->ordertime <= WARN_TIME){
                return 1;
            } else if (distan(order_past->food_locationx, order_past->food_locationy, current_rider) >= distan(order_now->food_locationx, order_now->food_locationy, current_rider)) {
                return 1;
            } else {//add something
                return 0;
            }
        } else if (order_past->status == 0 && order_now->status == 1) {
            if (time - order_past->ordertime <= WARN_TIME) {
                return 0;
            } else if (time - order_now->ordertime <= WARN_TIME){
                return 1;
            } else if (distan(order_past->food_locationx, order_past->food_locationy, current_rider) >= distan(order_now->destinationx, order_now->destinationy, current_rider)) {
                return 1;
            } else {//add something
                return 0;
            }
        } else if (order_past->status == 1 && order_now->status == 0) {
            if (time - order_past->ordertime <= WARN_TIME) {
                return 0;
            } else if (time - order_now->ordertime <= WARN_TIME){
                return 1;
            } else if (distan(order_past->destinationx, order_past->destinationx, current_rider) >= distan(order_now->food_locationx, order_now->food_locationy, current_rider)) {
                return 1;
            } else {//add something
                return 0;
            }
        } else if (order_past->status == 1 && order_now->status == 1) {
            if (time - order_past->ordertime <= WARN_TIME) {
                return 0;
            } else if (time - order_now->ordertime <= WARN_TIME){
                return 1;
            } else if (distan(order_past->destinationx, order_past->destinationy, current_rider) >= distan(order_now->destinationx, order_now->destinationy, current_rider)) {
                return 1;
            } else {//add something
                return 0;
            }
        } else {
            return -1;
        }
    } else if (time - order_past->ordertime <= 60 && time - order_past->ordertime > 30 && time - order_now->ordertime <= 30) {
        if (order_past->status == 0 && order_now->status == 3) {
            if (time - order_past->ordertime <= WARN_TIME) {
                return 0;
            } else if (time - order_now->ordertime <= WARN_TIME){
                return 1;
            } else if (distan(order_past->food_locationx, order_past->food_locationy, current_rider) >= distan(order_now->destinationx, order_now->destinationy, current_rider)) {
                return 1;
            } else {//add something
                return 0;
            }
        } else if (order_past->status == 1 && order_now->status == 3) {
            if (time - order_past->ordertime <= WARN_TIME) {
                return 0;
            } else if (time - order_now->ordertime <= WARN_TIME){
                return 1;
            } else if (distan(order_past->destinationx, order_past->destinationy, current_rider) >= distan(order_now->destinationx, order_now->destinationy, current_rider)) {
                return 1;
            } else {//add something
                return 0;
            }
        } else if (order_past->status == 0 && order_now->status == 4) {
            if (time - order_past->ordertime <= WARN_TIME) {
                return 0;
            } else if (time - order_now->ordertime <= WARN_TIME){
                return 1;
            } else if (distan(order_past->food_locationx, order_past->food_locationy, current_rider) >= distan(order_now->food_locationx, order_now->food_locationx, current_rider)) {
                return 1;
            } else {//add something
                return 0;
            }
        } else if (order_past->status == 1 && order_now->status == 4) {
            if (time - order_past->ordertime <= WARN_TIME) {
                return 0;
            } else if (time - order_now->ordertime <= WARN_TIME){
                return 1;
            } else if (distan(order_past->destinationx, order_past->destinationy, current_rider) >= distan(order_now->food_locationx, order_now->food_locationx, current_rider)) {
                return 1;
            } else {//add something
                return 0;
            }
        } else if (order_past->status == 0 && order_now->status == 6) {
            if (time - order_past->ordertime <= WARN_TIME) {
                return 0;
            } else if (time - order_now->ordertime <= WARN_TIME){
                return 1;
            } else if (distan(order_past->food_locationx, order_past->food_locationy, current_rider) >= distan(order_now->food_locationx, order_now->food_locationx, current_rider)) {
                return 1;
            } else {//add something
                return 0;
            }
        } else if (order_past->status == 1 && order_now->status == 6) {
            if (time - order_past->ordertime <= WARN_TIME) {
                return 0;
            } else if (time - order_now->ordertime <= WARN_TIME){
                return 1;
            } else if (distan(order_past->destinationx, order_past->destinationy, current_rider) >= distan(order_now->destinationx, order_now->destinationy, current_rider)) {
                return 1;
            } else {//add something
                return 0;
            }
        } else {
            return -1;
        }
    } else if (time - order_now->ordertime <= 60 && time - order_now->ordertime > 30 && time - order_past->ordertime <= 30) {
        if (order_now->status == 0 && order_past->status == 3) {
            if (time - order_now->ordertime <= WARN_TIME) {
                return 0;
            } else if (time - order_past->ordertime <= WARN_TIME){
                return 1;
            } else if (distan(order_now->food_locationx, order_now->food_locationy, current_rider) >= distan(order_past->destinationx, order_past->destinationy, current_rider)) {
                return 1;
            } else {//add something
                return 0;
            }
        } else if (order_now->status == 1 && order_past->status == 3) {
            if (time - order_now->ordertime <= WARN_TIME) {
                return 0;
            } else if (time - order_past->ordertime <= WARN_TIME){
                return 1;
            } else if (distan(order_now->destinationx, order_now->destinationy, current_rider) >= distan(order_past->destinationx, order_past->destinationy, current_rider)) {
                return 1;
            } else {//add something
                return 0;
            }
        } else if (order_now->status == 0 && order_past->status == 4) {
            if (time - order_now->ordertime <= WARN_TIME) {
                return 0;
            } else if (time - order_past->ordertime <= WARN_TIME){
                return 1;
            } else if (distan(order_now->food_locationx, order_now->food_locationy, current_rider) >= distan(order_past->food_locationx, order_past->food_locationx, current_rider)) {
                return 1;
            } else {//add something
                return 0;
            }
        } else if (order_now->status == 1 && order_past->status == 4) {
            if (time - order_now->ordertime <= WARN_TIME) {
                return 0;
            } else if (time - order_past->ordertime <= WARN_TIME){
                return 1;
            } else if (distan(order_now->destinationx, order_now->destinationy, current_rider) >= distan(order_past->food_locationx, order_past->food_locationx, current_rider)) {
                return 1;
            } else {//add something
                return 0;
            }
        } else if (order_now->status == 0 && order_past->status == 6) {
            if (time - order_now->ordertime <= WARN_TIME) {
                return 0;
            } else if (time - order_past->ordertime <= WARN_TIME){
                return 1;
            } else if (distan(order_now->food_locationx, order_now->food_locationy, current_rider) >= distan(order_past->food_locationx, order_past->food_locationx, current_rider)) {
                return 1;
            } else {//add something
                return 0;
            }
        } else if (order_now->status == 1 && order_past->status == 6) {
            if (time - order_now->ordertime <= WARN_TIME) {
                return 0;
            } else if (time - order_past->ordertime <= WARN_TIME){
                return 1;
            } else if (distan(order_now->destinationx, order_now->destinationy, current_rider) >= distan(order_past->destinationx, order_past->destinationy, current_rider)) {
                return 1;
            } else {//add something
                return 0;
            }
        } else {
            return -1;
        }
    } else if (time - order_past->ordertime <= 60 && time - order_past->ordertime > 30 && time - order_now->ordertime <= 60 && time - order_now->ordertime > 30) {
        if (order_past->status == 3 && order_now->status == 4) {
            if (time - order_past->ordertime <= WARN_TIME) {
                return 0;
            } else if (time - order_now->ordertime <= WARN_TIME){
                return 1;
            } else if (distan(order_past->destinationx, order_past->destinationy, current_rider) >= distan(order_now->destinationx, order_now->destinationy, current_rider)) {
                return 1;
            } else {//add something
                return 0;
            }
        } else if (order_past->status == 3 && order_now->status == 6) {
            if (time - order_past->ordertime <= WARN_TIME) {
                return 0;
            } else if (time - order_now->ordertime <= WARN_TIME){
                return 1;
            } else if (distan(order_past->destinationx, order_past->destinationy, current_rider) >= distan(order_now->destinationx, order_now->destinationy, current_rider)) {
                return 1;
            } else {//add something
                return 0;
            }
        } else if (order_past->status == 4 && order_now->status == 3) {
            if (time - order_past->ordertime <= WARN_TIME) {
                return 0;
            } else if (time - order_now->ordertime <= WARN_TIME){
                return 1;
            } else if (distan(order_past->food_locationx, order_past->food_locationy, current_rider) >= distan(order_now->destinationx, order_now->destinationy, current_rider)) {
                return 1;
            } else {//add something
                return 0;
            }
        } else if (order_past->status == 4 && order_now->status == 6) {
            if (time - order_past->ordertime <= WARN_TIME) {
                return 0;
            } else if (time - order_now->ordertime <= WARN_TIME){
                return 1;
            } else if (distan(order_past->food_locationx, order_past->food_locationy, current_rider) >= distan(order_now->destinationx, order_now->destinationy, current_rider)) {
                return 1;
            } else {//add something
                return 0;
            }
        } else if (order_past->status == 6 && order_now->status == 3) {
            if (time - order_past->ordertime <= WARN_TIME) {
                return 0;
            } else if (time - order_now->ordertime <= WARN_TIME){
                return 1;
            } else if (distan(order_past->destinationx, order_past->destinationy, current_rider) >= distan(order_now->destinationx, order_now->destinationy, current_rider)) {
                return 1;
            } else {//add something
                return 0;
            }
        } else if (order_past->status == 6 && order_now->status == 4) {
            if (time - order_past->ordertime <= WARN_TIME) {
                return 0;
            } else if (time - order_now->ordertime <= WARN_TIME){
                return 1;
            } else if (distan(order_past->destinationx, order_past->destinationx, current_rider) >= distan(order_now->food_locationx, order_now->food_locationy, current_rider)) {
                return 1;
            } else {//add something
                return 0;
            }
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}
//order_past���Ƚ��еĵ�ǰ������ǰһ������
//order_now���Ƚ��еĵ�ǰ����
//current_rider����ǰ����
/*
����һ������������
�����Ե�ǰ���ֵĶ�����������Ƚϣ���ѡ��������Ϊ��Ŀ��
�ж������е�ǰλ�á�����״̬��������������ǰʱ�������
*/
extern int distan(int x, int y, struct rider *rid) 
{
    int disx, disy;

    disx = x - rid->locationx;
    disy = y - rid->locationy;
    if (disx < 0) {
        disx = -disx;
    }
    if (disy < 0) {
        disy = -disy;
    }

    return disx + disy;
}
//x��y����ǰ������
//rid����ǰ����
/*
�������������֮��ľ���
*/
/******LAST EDITED 2019_05_23******/
