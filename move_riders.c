#include"egg.h"
#include"Global variables.h"
#include"constants.h"
extern void move_riders()
//间隔时间刷新骑手的位置实现骑手的移动 
{
	struct rider* nowrider;
	int i,j,x,y;
	if(current_add_rider!=0)
	//判断是否有新的骑手加入，并有不同的衣服 
	{
		for(i=1;i<=current_add_rider;i++)
		{
			eggs[rider_number-current_add_rider+i]=LayEgg();
			MovePen(zero_block_x+(birthx+1)*block_width,zero_block_y+(17-birthy)*block_width);
			switch(rider_number-current_add_rider+i)
			{
				case 1:DrawBitmap("rider_1.bmp");break;
				case 2:DrawBitmap("rider_2.bmp");break;
				case 3:DrawBitmap("rider_3.bmp");break;
				case 4:DrawBitmap("rider_4.bmp");break;
				default:break;
			}
			
		}
		x=GetEggXPos();
		y=GetEggYPos();
	}
	//printf("3434343434343434343434\n");
	for(i=1;i<=notices;i++)
	{
		//printf("%d ",i);
		//printf("notices");
		//printf("%d\n",notices);
		SetActiveEgg(notice[i]);
		EatEgg();
	}
	notices=0;
	current_add_rider=0;
	for(i=1,nowrider=riderhead;i<=rider_number;i++,nowrider=nowrider->next)
	{
		SetActiveEgg(eggs[i]);
		OffsetEgg((nowrider->locationx-nowrider->formerx)*block_width,(nowrider->formery-nowrider->locationy)*block_width);
		nowrider->formerx=nowrider->locationx;
		nowrider->formery=nowrider->locationy;
		if(nowrider->mission!=NULL)
		if(nowrider->addo->dx!=-1||nowrider->addo->dy!=-1)
		//停靠的变化 
		{
			if(nowrider->addo->fx!=-1||nowrider->addo->fy!=-1)
			{
				notice[i]=LayEgg();
				notices++;
				DrawBitmap("reach food.bmp");
				MovePen(zero_block_x+(nowrider->addo->fx+1)*block_width,zero_block_y+(17-nowrider->addo->fy)*block_width);
				DrawBitmap("highlight_house.bmp");
			}
				notice[i]=LayEgg();
				notices++;
				MovePen(zero_block_x+(nowrider->locationx+1)*block_width,zero_block_y+(17-nowrider->locationy)*block_width); 
				if(nowrider->formerfinished!=nowrider->finished)
				DrawBitmap("reach destination.bmp");
				MovePen(zero_block_x+(nowrider->addo->dx+1)*block_width,zero_block_y+(17-nowrider->addo->dy)*block_width);
				DrawBitmap("highlight_house.bmp");
				MovePen(zero_block_x+(nowrider->addo->dx)*block_width,zero_block_y+(17-nowrider->addo->dy-1)*block_width);
				DrawString(transfer((nowrider->addo->finishn+1)/2));
		}
		if(nowrider->mission!=NULL)
		if(nowrider->addo->fx!=-1||nowrider->addo->fy!=-1)
		//停靠的变化
		{
			if(nowrider->addo->dx!=-1||nowrider->addo->dy!=-1)
			{
				{
					notice[i]=LayEgg();
					notices++;
					if(nowrider->formerfinished!=nowrider->finished) 
					DrawBitmap("reach destination.bmp");
					MovePen(zero_block_x+(nowrider->addo->dx+1)*block_width,zero_block_y+(17-nowrider->addo->dy)*block_width);
					DrawBitmap("highlight_house.bmp");
					MovePen(zero_block_x+(nowrider->addo->dx)*block_width,zero_block_y+(17-nowrider->addo->dy-1)*block_width);
					DrawString(transfer((nowrider->addo->finishn+1)/2));
					nowrider->formerfinished=nowrider->finished;
				}
			}
			notice[i]=LayEgg();
			notices++;
			MovePen(zero_block_x+(1+nowrider->locationx)*block_width,zero_block_y+(17-nowrider->locationy)*block_width); 
			DrawBitmap("reach food.bmp");
			MovePen(zero_block_x+(nowrider->addo->fx+1)*block_width,zero_block_y+(17-nowrider->addo->fy)*block_width);
			DrawBitmap("highlight_house.bmp");
		}
	}
}
