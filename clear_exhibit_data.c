#include"egg.h"
#include"Global Variables.h"
extern void clear_exhibit_data(void)
//刷新展示数据的egg 
{
	SetActiveEgg(exhibit_egg);
	EatEgg();
}
