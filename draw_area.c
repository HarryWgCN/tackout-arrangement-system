#include "egg.h"
#include "constants.h"
#include"Global Variables.h"
extern void draw_area(void)
//绘制动画界面以及多个egg层的初始化 
{
	int i,j;
	
	EggStart(egg_length,egg_width);
	SetPen(0,5);
	//MovePen(510,510);
	//DrawBitmap("floor.bmp"); 
	for(i=0;i<=egg_width;i=i+block_width)
	{
		MovePen(0,i);
		DrawLine(egg_width,0);
	}
	for(i=0;i<=egg_width;i=i+block_width)
	{
		MovePen(i,0);
		DrawLine(0,egg_width);
	}
	for(i=0;i<=egg_width;i+=block_width*2)
	{
		for(j=0;j<=egg_width;j+=block_width*2)
		{
			MovePen(5.5+i,23+j);
			DrawBitmap("house.bmp");
		}
	}
	
	
	for(i=0;i<=3*option_distance;i+=option_distance)
	{
		MovePen(600+i,250);
		DrawLine(option_width,0);
		DrawLine(0,-option_width);
		MovePen(600+i,250);
		DrawLine(0,-option_width);
		MovePen(600+i+option_width/4,250-option_width/2);
		DrawLine(option_width/2,0);
		MovePen(600+i+option_width/2,250-option_width/4);
		DrawLine(0,-option_width/2);
	}
	for(i=0;i<=3*option_distance;i+=option_distance)
	{
		MovePen(600+i,250-option_width);
		DrawLine(option_width,0);
	}
	//+
	
	for(i=0;i<=3*option_distance;i+=option_distance)
	{
		MovePen(600+i,210);
		DrawLine(option_width,0);
		DrawLine(0,-option_width);
		MovePen(600+i,210);
		DrawLine(0,-option_width);
	}
	for(i=0;i<=3*option_distance;i+=option_distance)
	{
		MovePen(600+i,210-option_width);
		DrawLine(option_width,0);
	}
	MovePen(600+(7*option_distance)/2,210);
	DrawLine(option_width+10,0);
	DrawLine(0,-option_width);
	MovePen(600+(7*option_distance)/2,210);
	DrawLine(0,-option_width);
	MovePen(600+(7*option_distance)/2,210-option_width);
	DrawLine(option_width+10,0);
	MovePen(600+5+(7*option_distance)/2,205);
	DrawString("下单");
	//operating number block
	
	
	for(i=0;i<=3*option_distance;i+=option_distance)
	{
		MovePen(600+i,170);
		DrawLine(option_width,0);
		DrawLine(0,-option_width);
		MovePen(600+i,170);
		DrawLine(0,-option_width);
		MovePen(600+i+option_width/4,170-option_width/2);
		DrawLine(option_width/2,0);
	}
	for(i=0;i<=3*option_distance;i+=option_distance)
	{
		MovePen(600+i,170-option_width);
		DrawLine(option_width,0);
	}
	MovePen(600-option_distance/4-10,170-option_width-10);
	DrawString("店家");
	MovePen(600+option_width/4,170-option_width-10);
	DrawString("X");
	MovePen(600+option_distance+option_width/4,170-option_width-10);
	DrawString("Y");
	MovePen(600+option_width/4+option_distance*2-option_distance/2,170-option_width-10);
	DrawString("食客");
	MovePen(600+option_width/4+option_distance*2,170-option_width-10);
	DrawString("X");
	MovePen(600+option_width/4+option_distance*3,170-option_width-10);
	DrawString("Y");
	//-
	
	
		for(i=0;i<=3;i++)
	{
		options[i]=LayEgg();
	}
	for(i=0;i<=3;i++)
	{
		SetActiveEgg(options[i]);
		MovePen(600+option_distance*i+(option_width*2)/5,210-option_width/4);
		DrawString("0");
		options_number[i]=0;
	}
}
