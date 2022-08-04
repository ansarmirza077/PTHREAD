#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int p;
pthread_mutex_t lock;
void *even();
void *odd();

//int n=10;

int main()
{
	//p=pthread_mutex_init(&lock,NULL);
	//int n;
	//printf("Enter n value");
	//scanf("%d",&n);

	pthread_t t1,t2;
	pthread_create(&t1,NULL,even,NULL);
	pthread_create(&t2,NULL,odd,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	//pthread_mutex_destroy(&lock);

	return 0;

}


void *even()
{
	p=pthread_mutex_lock(&lock);
	int i;
	for(i=0;i<10;i++)
	{
		if(i%2==0) 
		{printf("%d",i);
	}else p=pthread_mutex_unlock(&lock);
}
}

void *odd()
{
	p=pthread_mutex_lock(&lock);
	int i;
	for(i=0;i<10;i++)
{
	if(i%2!=0){
	printf("%d",i);
	}else p=pthread_mutex_unlock(&lock);

}
}

