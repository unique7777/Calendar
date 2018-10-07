#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i,m,n,totoldays=0,year,month;    //m是循环变量，i是布尔类型，n是天数
	int empty,day[32]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
	printf("\t\t\t*********************************\n\t\t\t*\t\t\t\t*\n\t\t\t*\t\t\t\t*\n\t\t\t$        自制精美万年历\t\t$\n\t\t\t*\t\t\t\t*\n\t\t\t*\t\t\t\t*\n\t\t\t*********************************\n\n");//万年历界面
	printf("\t\t\t请输入年份：");
	scanf("%d",&year);
	if(year<1900)
	{
		printf("输入年份不能小于1900年，请重新输入\n"),
		exit(1);
	}
	printf("\t\t\t请输入月份：");
	scanf("%d",&month);
	if(boolen(year))
		printf("\t\t\t%d年是闰年,%d年%d月有%d天\n",year,year,month,Day(year,month));
	else
		printf("\t\t\t%d年是非闰年，%d年%d月有%d天\n",year,year,month,Day(year,month));
	printf("\n");
	printf("\t星期日\t星期一\t星期二\t星期三\t星期四\t星期五\t星期六\n");
	for(m=1900;m<year;m++)
	{	
		i=boolen(m);
		if(i)
			totoldays+=366;
		else totoldays+=365;
	}//将1900到上一年的整年天数相加
	for(n=1;n<month;n++)
	{
		totoldays+=Day(year,n);
	}//将当前要查询的前几个月的天数加上去
	empty=1+totoldays%7;
	if(empty==7)
		empty=0;
	for(m=0;m<empty;m++)
	{
		printf("\t");
	}
	for(m=0;m<Day(year,month);m++)
	{
		if((m+empty)%7==0)
			printf("\n");
		printf("\t  %d",day[m]);
	}
	printf("\n");
}

int boolen(int y)//判断当前年份是否为闰年
{
	if((y%400==0)||((y%4==0)&&(y%100!=0)))
		return 1;
	else return 0;
}

int Day(int year,int month)//计算天数函数
{
	int i,days;
	i=boolen(year);
	switch(month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		days=31; break;
	case 2:
		if(i) days=29;
	  	else days=28;
		break;
	default:
		days=30;break;
	}
	return days;
}	
