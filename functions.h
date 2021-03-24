#include<stdio.h>
#include<stdlib.h>
extern void input();
extern int get_row();
extern int money(struct rider *riderhead);
extern void ridernumber1(int fund, struct rider* riderhead);
extern void order_by_area(struct order* noworder);
extern void add_rider();
extern void output(struct rider *riderhead);
/*¶©µ¥·ÖÅäÄ£¿é*/
extern void road_move(struct rider *current_rider, struct next_to_go *current_desti);
extern int rid(int rx, int ry);//meaning on GoodNote
extern int rel(int rx, int ry, int dx, int dy);//x move
extern void where_to_go(struct rider *current_rider, struct order *orderhead, struct next_to_go *one_togo);//core part of the route management//queue set by priority of :location->time//result in the (re)build of the queue of next_to_go
extern int jugde_is(struct rider *current_rider, struct order *order_past, struct order *order_now);//1 for now can replace past
extern int distan(int x, int y, struct rider *rid);
extern void route_move_status(void);
extern void order_status_judge(struct rider *current_rider, struct order *current_order, struct order *head_order); //judged by position and time
extern int arrived(int rx, int ry, int dx, int dy);

extern void result_check(int *fx, int *fy, int *dx, int *dy, int *finishn, int *overn, struct rider *cur_rider, struct order *cur_order);
extern void if_nearby(int *, int *, int *, int *, struct rider *, struct order *);
extern void finished_num(int *, struct rider *, struct order *);
extern void overtimed_num(int *, struct rider *, struct order *);

extern void operating();
extern void move_riders();
extern void draw_area();
extern void exhibit_data();
char* transfer(int num);
int getDigit(long long n);
extern void clear_exhibit_data(void);
extern void add_mission(void);
