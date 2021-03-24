/********START WITH THE END OF AN DISTRIBUTION*********/
/********LATEST EDITED 2019_05_23********/
#include <stdio.h>
#include <stdlib.h>
#include "Global Variables.h"


struct next_to_go 
{
    int x;
    int y;
};

extern void where_to_go(struct rider *, struct order *, struct next_to_go *);
extern void road_move(struct rider *, struct next_to_go *);
extern void order_status_judge(struct rider *, struct order *, struct order *);
extern void result_check(int *, int *, int *, int *, int *, int *, struct rider *, struct order *);

extern void route_move_status(void) 
{
    struct rider *current_riderhead = riderhead;

    while (current_riderhead != NULL) 
	{
        struct order *current_orderhead = current_riderhead->mission; //orderhead for the current rider
        struct next_to_go *next_to_go_head = malloc(sizeof(struct next_to_go));
            
        while (current_orderhead != NULL) 
		{
            order_status_judge(current_riderhead, current_orderhead, current_riderhead->mission);
            
            current_orderhead = current_orderhead->next;
        }
        current_orderhead = current_riderhead->mission;

        where_to_go(current_riderhead, current_orderhead, next_to_go_head);
        road_move(current_riderhead, next_to_go_head);
        
        while (current_orderhead != NULL) 
		{
            current_riderhead->addo = malloc(sizeof(struct addon));
            result_check(&current_riderhead->addo->fx, &current_riderhead->addo->fy, &current_riderhead->addo->dx, &current_riderhead->addo->dy,
                         &current_riderhead->addo->finishn, &current_riderhead->addo->overn, current_riderhead, current_orderhead);
            //free(current_riderhead->addo);
            if (current_riderhead->addo->fx != -1 || current_riderhead->addo->fy != -1 ||
				current_riderhead->addo->dx != -1 || current_riderhead->addo->dy != -1) 
				{
					break;
				}
            current_orderhead = current_orderhead->next;
        }
        current_orderhead = current_riderhead->mission;
        
        free(next_to_go_head);

        current_riderhead = current_riderhead->next;
    }
}
/*
�滮·�ߡ��ƶ����֡������Զ���״̬�����غ���
���ܣ�
-�����ɵ�������ֶ��У�������ƺõ��㷨�滮����·��
-��ʱ��Ϊ���ڶ����ֶ����е����ֽ����ƶ���
-�������֡�ʳ�͡��͹ݵ�״̬
-������Խ�
*/
