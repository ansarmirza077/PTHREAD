#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int n=1,count=0;

void *fun1()
{
	while(n<=10)
	{
		if(n%2==0)
		{
			printf("%d",n);
			n++;
			count++;
			sleep(1);
		}
		else
			sleep(1);
	}
}

void *fun2()
{
	while(n<=10)
	{
		if(n%2!=0)
		{
			printf("%d",n);
			n++;
			count++;
			sleep(1);
		}
		else
			(sleep(1));
	}
}

int main()
{
	pthread_t t1,t2;
	pthread_create(&t1,NULL,fun1,NULL);
	pthread_create(&t2,NULL,fun2,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

}

