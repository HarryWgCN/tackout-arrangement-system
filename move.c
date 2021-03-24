#include <stdio.h>
#include <stdlib.h>
#include "Global Variables.h"

struct next_to_go {
    int x;
    int y;
};

extern void road_move(struct rider *current_rider, struct next_to_go *current_desti) 
{
    int rid(int, int);//rider relative position
    int rel(int, int, int, int);//relative position

    int rid_res = rid(current_rider->locationx, current_rider->locationy);
    int rel_res = rel(current_rider->locationx, current_rider->locationy, current_desti->x, current_desti->y);

    if (rid_res == 1) 
	{
        switch(rel_res) {
            case 1: {
                current_rider->locationx += 1;
                current_rider->locationy += 1;
                break;
            } 
            case 2: {
                current_rider->locationx += 2;
                break;
            }
            case 4: {
                current_rider->locationx += 2;
                break;
            }
            case 5: {
                current_rider->locationx += 1;
                current_rider->locationy -= 1;
                break;
            }
            case 8: {
                if (current_rider->locationx == 0) {
                    current_rider->locationx += 1;
                    current_rider->locationy += 1;
                    break;
                } else {
                    current_rider->locationx -= 1;
                    current_rider->locationy += 1;
                    break;
                }
            }
            case 9: {
                if (current_rider->locationx == 0) {
                    current_rider->locationx += 1;
                    current_rider->locationy -= 1;
                    break;
                } else {
                    current_rider->locationx -= 1;
                    current_rider->locationy -= 1;
                    break;
                }
            }
            case 12: {
                current_rider->locationx -= 1;
                current_rider->locationy += 1;
                break;
            } 
            case 13: {
                current_rider->locationx -= 2;
                break;
            }
            case 15: {
                current_rider->locationx -= 2;
                break;
            }
            case 16: {
                current_rider->locationx -= 1;
                current_rider->locationy -= 1;
                break;
            }
        }
    } else if (rid_res == 2){
        switch(rel_res) {
            case 1: {
                current_rider->locationx += 1;
                current_rider->locationy += 1;
                break;
            } 
            case 3: {
                if (current_rider->locationy == 0) {
                    current_rider->locationx += 1;
                    current_rider->locationy += 1;
                } else {
                    current_rider->locationx += 1;
                    current_rider->locationy -= 1;
                }
                break;
            }
            case 5: {
                current_rider->locationx += 1;
                current_rider->locationy -= 1;
                break;
            }
            case 6: {
                current_rider->locationy += 2;
                break;
            }
            case 7: {
                current_rider->locationy -= 2;
                break;
            }
            case 10: {
                current_rider->locationy += 2;
                break;
            }
            case 11: {
                current_rider->locationy -= 2;
                break;
            }
            case 12: {
                current_rider->locationx -= 1;
                current_rider->locationy += 1;
                break;
            } 
            case 14: {
                if (current_rider->locationy == 0) {//connect with choice of route
                    current_rider->locationx -= 1;
                    current_rider->locationy += 1;
                    break;
                } else {
                    current_rider->locationx -= 1;
                    current_rider->locationy -= 1;
                    break;
                }
            }
            case 16: {
                current_rider->locationx -= 1;
                current_rider->locationy -= 1;
                break;
            }
        }
    }
}
//current_rider：当前骑手
//current_desti：当前骑手目标点
/*
执行骑手的移动
根据骑手相对位置及绝对位置有不同的移动路线，其中二者决定最短路线
*/
extern int rid(int rx, int ry) 
{//meaning on GoodNote
    if (rx % 2 == 0 && ry % 2 == 1) {
        return 1;
    } else if (rx % 2 == 1 && ry % 2 == 0) {
        return 2;
    } else {
        return 0;
    }
}
//rx、ry：骑手位置
/*
确定骑手相对其附近餐馆/食客的位置，其返回值的意义：
1：骑手在上/下侧
2：骑手在左/右侧
*/
extern int rel(int rx, int ry, int dx, int dy) 
{//x move
    if (rx < dx - 1) {
        if (ry < dy - 1) {
            return 1;
        } else if (ry == dy - 1) {
            return 2;
        } else if (ry == dy) {
            return 3;
        } else if (ry == dy + 1) {
            return 4;
        } else if (ry > dy + 1) {
            return 5;
        } else {
            return 0;
        }
    } else if (rx == dx - 1) {
        if (ry < dy - 1) {
            return 6;
        } else if (ry > dy + 1) {
            return 7;
        } else {
            return 0;
        }
    } else if (rx == dx){
        if (ry < dy - 1) {
            return 8;
        } else if (ry > dy + 1) {
            return 9;
        } else {
            return 0;
        }
    } else if (rx == dx + 1){
        if (ry < dy - 1) {
            return 10;
        } else if (ry > dy + 1) {
            return 11;
        } else {
            return 0;
        }
    } else if (rx > dx + 1) {
        if (ry < dy - 1) {
            return 12;
        } else if (ry == dy - 1) {
            return 13;
        } else if (ry == dy) {
            return 14;
        } else if (ry == dy + 1) {
            return 15;
        } else if (ry > dy + 1) {
            return 16;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}
//rx、ry：骑手位置
//dx、dy：目标点位置
/*
确定骑手相对其目标点的位置，其返回值的意义见“函数说明文档附件1”：
*/
/******LAST EDITED 2019_05_21******/
