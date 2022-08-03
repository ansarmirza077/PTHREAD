#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
//#include<semaphore.h>

pthread_mutex_t mute;

void *even()
{
	pthread_mutex_lock(&mute);
	int i,n;
	printf("Enter n value");
	scanf("%d",&n);

	for(i=0;i<n;i++){
		if(i%2==0)
	{
		printf("\n%d\n",i);
	}
	else
	{	printf("\n%d\n",i);
	}


}
pthread_mutex_unlock(&mute);
}


int main()
{
	pthread_t t[2];
	pthread_mutex_init(&mute,NULL);
	//pthread_init(&t[0],NULL);
	//pthread_init(&t[1],NULL);
	pthread_create(&t[0],NULL,&even,NULL);
	pthread_create(&t[1],NULL,&even,NULL);

	pthread_join(t[0],NULL);
	pthread_join(t[1],NULL);
	pthread_mutex_destroy(&mute);

	return 0;

}
	


