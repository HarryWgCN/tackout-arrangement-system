int getDigit(int n)
//获得一个十进制整数的位数 
{
int i=1;
int m=0;
while(i<=n)
	{
	i=i*10;
	m++;
	}
return m;
}
