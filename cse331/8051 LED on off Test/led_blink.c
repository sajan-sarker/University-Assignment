#include<reg51.h>
sbit led = P2^0;
void Delay(void);
void main()
{
	led = 0;
	while(1)
	{
		led = 1;
		Delay();
		led = 0;
		Delay();
	}
}
void Delay(void)
{
	int j;
	int i;
	for(i = 0; i<10; i++)
	{
		for(j = 0; j< 10000; j++)
		{
		}
	}
}