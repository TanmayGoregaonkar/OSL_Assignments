/*Name : Tanmay Deepak Goregaonkar
Roll no : 33227
BAtch : L-10
Assignment No : 4b Reader Writer
*/
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>


sem_t x;

sem_t wsem;

int readCount = 0;

int num = 1;

void* Reader()
{
	while(1)
	{
   
        sem_wait(&x);
        
        readCount++;
        
        if(readCount == 1)
        {
            sem_wait(&wsem);
        }
        
        sem_post(&x);
        
        printf("Reading value of number:: %d by reader \n",num%10);
        
        sem_wait(&x);
        
        readCount--;
        
        if(readCount==0)
        {
            sem_post(&wsem);   
        }
        
        sem_post(&x);
        
        //sleep(2);
       }
}

void* writer()
{
    while(1){
        sem_wait(&wsem);
        num=num+1;
        printf("Writer is writing %d \n",num%10);
        sem_post(&wsem);
        }
    

}

int main()
{
     sem_init(&x,0,1);
     
     sem_init(&wsem,0,1);
     
   // pthread_mutex_init(&wsem,NULL);
    pthread_t read,write;
    //int a[10]={1,2,3,4,5,6,7,8,9,10};

  //for(int i=0;i<5;i++)
    //{
       pthread_create(&write,NULL,(void*)writer,NULL);
       sleep(1);
    //}
    //sleep(1);

    //for(int i=0;i<10;i++)
    //{
        pthread_create(&read,NULL,(void*)Reader,NULL);
   // }
    
   
    

     //for(int i=0;i<10;i++)
    //{
        pthread_join(read,NULL);
    //}

	//for(int i=0;i<5;i++)
    //{
       pthread_join(write,NULL);
    //}

    

    //pthread_mutex_destroy(&x);
    //pthread_mutex_destroy(&wsem);
    
    return 0;
}







