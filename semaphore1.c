#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

//sem_t S;//declaration of semaphore
int shared=1;//global var to see semaphore working

void fun1()
{
	int sp;
	//sem_wait(&S);//system call to enter c.section
	sp=shared;
	printf("\nThread1 reading %d\n",sp);
	sp++;
	printf("\nUpdating sp value in this func1 only %d\n",sp);
	sleep(1);
	shared=sp;
	printf("\nvalue of shared variable in thread1 is %d\n",shared);
	//sem_post(&S);//system call to exit semaphore
}

void fun2()
{
	int sp1;
	//sem_wait(&S);
	sp1=shared;
	printf("\nThread2 reads value %d\n",sp1);
	sp1++;
	printf("\nLocally update %d\n",sp1);
	sleep(1);
	shared=sp1;
	printf("\nvalue of th2 %d\n",sp1);
	//sem_post(&S);
}


int main()
{
	//sem_init(&S,0,1);
	pthread_t th1,th2;
	pthread_create(&th1,NULL,fun1,NULL);
	pthread_create(&th2,NULL,fun2,NULL);

	pthread_join(th1,NULL);
 	pthread_join(th2,NULL);
  	printf("Initial shared value : %d \n ",shared);

}




