#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

//pthread_mutex_t lock;
int i = 10;

void *func1()
{
//	pthread_mutex_lock(&lock);
	int x=9;
	printf("\nEntering th1 PID =%ld\n",pthread_self());
	printf("\nlock tested in th1\n");
	printf("\nx is %d\n",++i);
	printf("\nending th1\n");

//	pthread_mutex_unlock(&lock);
}

void *func2()
{
//	pthread_mutex_lock(&lock);
	int y=7;
	printf("\nEntering th2 PID =%ld\n",pthread_self());
	printf("\nlock tested in th2\n");
	printf("\ny is %d\n",++i);
	printf("Ending th2");
//	pthread_mutex_unlock(&lock);
	printf("th2 ended PID =%d",pthread_self());

}	



int main()
{
//	pthread_mutex_init(&lock,NULL);
	pthread_t th1,th2;
	pthread_create(&th1,NULL,&func1,NULL);
	pthread_create(&th2,NULL,&func2,NULL);

	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
//	pthread_mutex_destroy(&lock);

	return 0;
}

