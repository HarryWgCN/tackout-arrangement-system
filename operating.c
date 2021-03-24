#include"egg.h"
#include"functions.h"
#include"Global variables.h"
#include"constants.h"
static void add(int egg);
static void minus(int egg);
extern void operating()
//对于鼠标操作event的各种处理 
{
	int i,check_dragging_been_made=0;
	double x,y;
	EVENT_TYPE ev;
	while((ev = WaitForEvent())!= EXIT)
	{
		//if(check_dragging_been_made==1)
		//printf("begin loop");
		switch(ev)
		{
			case KEYDOWN:
			//有按键被按下 
			{
				switch(GetStruckKey())
                {  	case VK_LBUTTON:
					x = GetMouseX();
					y = GetMouseY();
					if((x >= 600 && x <= 600+option_width) && (y >= 250-option_width && y <= 250))	
				 	{
				 		 add(0);
					}
					//1++
					
					
					if((x >= 600+option_distance && x <= 600+option_distance+option_width) && (y >= 250-option_width && y <= 250))	
				 	{
				 		add(1);
					}
					
					//2++
					
					
					if((x >= 600+option_distance*2 && x <= 600+option_distance*2+option_width) && (y >= 250-option_width && y <= 250))	
				 	{
				 		add(2);
					}

					//3++
					
					
					if((x >= 600+option_distance*3 && x <= 600+option_distance*3+option_width) && (y >= 250-option_width && y <= 250))	
				 	{
				 		add(3);
					}

					//4++
					
					
					if((x >= 600 && x <= 600+option_width) && (y >= 170-option_width && y <= 170))	
				 	{
				 		 minus(0);
					}

					//1--
					
					
					if((x >= 600+option_distance && x <= 600+option_distance+option_width) && (y >= 170-option_width && y <= 170))	
				 	{
				 		minus(1);
					}

					//2--
					
					
					if((x >= 600+option_distance*2 && x <= 600+option_distance*2+option_width) && (y >= 170-option_width && y <= 170))	
				 	{
				 		minus(2);
					}

					//3--
					
					
					if((x >= 600+option_distance*3 && x <= 600+option_distance*3+option_width) && (y >= 170-option_width && y <= 170))	
				 	{
				 		minus(3);
					}
					
					//4--	        	
					

					if((x >= 600+(7*option_distance)/2 && x <= 600+(7*option_distance)/2+option_width+10) && (y >= 210-option_width && y <= 210))	
					{
						MovePen(600+5+(7*option_distance)/2,205+option_width+10);
						DrawString("已下单");
						add_mission();
						MovePen(400+option_width/4+option_distance*2-option_distance/2,140-option_width-10);
							DrawString("已下单");
							OffsetPen(10,0);
							DrawString("单号");
							OffsetPen(10,0);
							//printf("%d",order_number);
							DrawString(transfer(order_number/2)); 
							OffsetPen(10,0);
							DrawString("餐馆");
							OffsetPen(10,0);
							DrawString(transfer(options_number[0]));
							OffsetPen(10,0);
							DrawString(transfer(options_number[1]));
							OffsetPen(10,0);
							DrawString("食客");
							OffsetPen(10,0);
							DrawString(transfer(options_number[2]));
							OffsetPen(10,0);
							DrawString(transfer(options_number[3]));
					}
					
					
					if(x>=0&&x<=egg_width&&y>=0&&y<=egg_width)
					//鼠标左键餐馆食客区域被按下 
					{
						if(check_dragging_been_made==1)
						{
							options_number[2]=((x-zero_block_x)/block_width)-1;
							options_number[3]=(17-(y-zero_block_y)/block_width);
							MovePen(zero_block_x+(options_number[2]+1)*block_width,zero_block_y+(17-options_number[3])*block_width);
							DrawBitmap("home_click.bmp");
							check_dragging_been_made=0;
							add_mission();
							MovePen(400+option_width/4+option_distance*2-option_distance/2,140-option_width-10);
							DrawString("已下单");
							OffsetPen(10,0);
							DrawString("单号");
							OffsetPen(10,0);
							//printf("%d",order_number);
							DrawString(transfer(order_number/2)); 
							OffsetPen(10,0);
							DrawString("餐馆");
							OffsetPen(10,0);
							DrawString(transfer(options_number[0]));
							OffsetPen(10,0);
							DrawString(transfer(options_number[1]));
							OffsetPen(10,0);
							DrawString("食客");
							OffsetPen(10,0);
							DrawString(transfer(options_number[2]));
							OffsetPen(10,0);
							DrawString(transfer(options_number[3]));
							break;
						}
						else
						{
							options_number[0]=((x-zero_block_x)/block_width)-1;
						options_number[1]=(17-(y-zero_block_y)/block_width);
						check_dragging_been_made=1;
						MovePen(zero_block_x+(options_number[0]+1)*block_width,zero_block_y+(17-options_number[1])*block_width);
						DrawBitmap("home_click.bmp");
						}
						
						//printf("\nkey down 11111111--------------------------\n");
						//printf("%lf\n",((x-zero_block_x)/block_width)-1);
						//printf("%lf\n",(17-(y-zero_block_y)/block_width)); 
					
					//printf("%d\n",options_number[0]);
					//printf("%d\n",options_number[1]);
					//printf("%d\n",options_number[2]);
					//printf("%d\n",options_number[3]);
					}
					break;
					//dragging
					
					default:break; 
	
				}
			}
			/*case KEYUP:
			if(GetStruckKey()==VK_LBUTTON)
			{
				x = GetMouseX();
				y = GetMouseY();
				printf("\nget mouse%lf\n",x);
				printf("get mouse%lf\n",y);
				printf("%lf\n",((x-zero_block_x)/block_width)-1);
				printf("%lf\n",(17-(y-zero_block_y)/block_width));
				if(GetStruckKey()==VK_LBUTTON&&check_dragging_been_made!=0)
				{
					check_dragging_been_made=0;
					options_number[2]=((x-zero_block_x)/block_width)-1;
					options_number[3]=(17-(y-zero_block_y)/block_width);
					printf("\n%lf%lf key up----------\n",x,y);
					printf("%d\n",options_number[0]);
					printf("%d\n",options_number[1]);
					printf("%d\n",options_number[2]);
					printf("%d\n",options_number[3]);
					add_mission();
					
				}
			}*/
		}
	}
	_endthreadex(0);
}

static void add(int egg)
//增加按钮 
{
	int number=options_number[egg];
	char* p;
	SetActiveEgg(options[egg]);
	EatEgg();
	options[egg]=LayEgg();
	if(number+1>=10&&number+1<=16)
		MovePen(595+option_distance*(egg)+(option_width*2)/5,210-option_width/4);
	else
		MovePen(600+option_distance*(egg)+(option_width*2)/5,210-option_width/4);
	if(number==16)
	{
		DrawString("0");
		options_number[egg]=0;
	}
	else
	{
		p=transfer(number+1);
		DrawString(p);
		options_number[egg]=number+1;
	}
}


static void minus(int egg)
//减少按钮 
{
	int number=options_number[egg];
	char* p;
	SetActiveEgg(options[egg]);
	EatEgg();
	options[egg]=LayEgg();
	if(number-1>=10||number-1<0)
		MovePen(595+option_distance*(egg)+(option_width*2)/5,210-option_width/4);
	else
		MovePen(600+option_distance*(egg)+(option_width*2)/5,210-option_width/4);
	if(number==0)
	{
		DrawString("16");
		options_number[egg]=16;
	}
	else
	{
		p=transfer(number-1);
		DrawString(p);
		options_number[egg]=number-1;
	}
}
