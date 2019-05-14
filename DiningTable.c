#include "stdio.h"
#include "pthread.h"
#include "unistd.h"
#include "string.h"
#define SIZE 5
/*
    Operating System...
    Lab 6 (Dining Philosopher Problem)
    Muhammad Hamza
    2016-UET-NML-CS-28
*/
int Sponse[SIZE];
pthread_mutex_t lock[SIZE];
int States[SIZE];

struct Philosopher{
  int P_ID;
  int sponse[2];
};
// Initialization All Important Things...
void InitializationStepe(struct Philosopher phil[SIZE]){
    for(int i = 0; i < SIZE; i++){
        if(i==SIZE-1){
            phil[i].sponse[0]=i;
            phil[i].sponse[1]=0;
        }
        else
        {
            phil[i].sponse[0]=i;
            phil[i].sponse[1]=i+1;
        }
        phil[i].P_ID=i;
        Sponse[i]=i;
        States[i]=0;
        pthread_mutex_init(&lock[i], NULL);
    }
}

// Eating Time for Every Philosopher...
void* StartEating(void* input){
  
  struct Philosopher* philospher=(struct Philosopher *)input;
  //printf("\nPhilosopher ID:%d\n",philospher->P_ID);
  //printf("Sponse 1: %d and sponse 2: %d\n",philospher->sponse[0],philospher->sponse[1]);  
    while(1){
        States[philospher->P_ID]=0;
        sleep(2);
        States[philospher->P_ID]=1;
        sleep(2);
        pthread_mutex_lock(&lock[philospher->sponse[0]]);
        pthread_mutex_lock(&lock[philospher->sponse[1]]);
            States[philospher->P_ID]=2;
            sleep(2);
        pthread_mutex_unlock(&lock[philospher->sponse[0]]);
        pthread_mutex_unlock(&lock[philospher->sponse[1]]);    
    }
}

// Display State Function
void* Display(void* input){
    while(1){
        printf("%d\t%d\t%d\t%d\t%d\n",States[0],States[1],States[2],States[3],States[4]);    
        sleep(2);
    }
    
    
}
// Main Function...
int main(int argc, char const *argv[]) {
    struct Philosopher PHSR[SIZE];
    InitializationStepe(PHSR);
    pthread_t threadID[SIZE];
    printf("0 show Thinking Stage, 1 Show Hungry Stage and 2 Eating Stage \n\n");
    for(int i = 0; i < SIZE; i++){
        pthread_create(&threadID[i],NULL,&StartEating,(void*)&PHSR[i]);   
    }
    pthread_t threadid;
     pthread_create(&threadid,NULL,&Display,NULL);
    // Display The States...
    
    while(1){
        sleep(2);
    }
  return 0;
}