#include<stdio.h>
#include<stdlib.h>
#include"egg.h"
struct order
{
	int number;
	int ordertime;
	int food_locationx;
	int food_locationy;
	int destinationx;
	int destinationy;
	int status;//used in path.c, etc.
	struct order *next;
};
struct rider
{
	int number;
	int formerx;
	int formery;
	int locationx;
	int locationy;
	int formerfinished;
	int finished;
	int unfinished;
	int area;
	int mission_number;
	struct rider *next;
	struct order *mission;
	struct addon *addo;//defination below here
};
struct addon 
{
	int fx;//food location x
	int fy;//food location x
	int dx;//customer location x
	int dy;//customer location x
	int finishn;//order finished total
	int overn;//order not finished total
	//int nearonce;
	//int finonce;
	//int overonce;
};
/*struct next_to_go {
    int x;
    int y;
};*/
struct rider* riderhead;
struct order* orderhead;
int time;
int rider_number;
int order_number;
int current_add_rider; 
int row;
HEGG eggs[10];
HEGG notice[1000];
HEGG exhibit_egg;
HEGG options[4];
int options_number[4]; 
int end; 
int notices;
