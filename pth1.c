
#include<stdio.h>
#include<pthread.h>

int a=0;

void *add(){

	printf("TH_ID %d\n ",a++);
}


void *add1(){
	printf("IN add1 %d\n",a++);	

}



int main(){
	pthread_t th_id;
	pthread_t thid;
	 pthread_create(&th_id,NULL,&add,NULL);
	 pthread_create(&thid,NULL,&add1,NULL);
	pthread_join(th_id,NULL);
	pthread_join(thid,NULL);

}
