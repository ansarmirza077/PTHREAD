#include<stdio.h>
#include<pthread.h>

void *even()
{


	int a;
	printf("Enter no ");
	scanf("%d",&a);
	if(a%2==0)printf("Even no");
	else printf("Odd no");
}

int main()
{
	pthread_t th_id;
	pthread_create(&th_id,NULL,&even,NULL);
	pthread_join(th_id,NULL);

}

