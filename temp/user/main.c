#include "public.h"
#include "systick.h"
#include "printf.h"
#include "ds18b20.h"
int main()
{	
	double temp;
	printf_init();	//printf��ʼ������
	ds18b20_init();

	while(1)
	{
		temp=readtemp();
		printf("��ǰ�¶�Ϊ��%0.4lf ��C\r\n",temp);	
	}

}
