#include<stdio.h>
#include<stdlib.h>

int mutex=1,man=5,stick[5]={1,1,1,1,1},eating[5]={0,0,0,0,0};

void pick(int man);
void put(int man);

int main(){
    int n, philosopher;
    printf("1. Pick ChopStick\n2. Put ChopStick\n3. Exit");
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &n);
        if(n == 3) exit(0);

        printf("Enter philosopher number (1-5): ");
        scanf("%d", &philosopher);
        philosopher -= 1; 
        
        switch(n){
            case 1: 
                pick(philosopher);
                break;
            case 2:
                put(philosopher);
                break;
            case 3:
                exit(0);
        }
    }
    return 0;
}

void pick(int man){
    --mutex;
    if(eating[man] == 1){
        printf("Philosopher %d is already eating.\n", man + 1);
    } else if(stick[man] == 1 && stick[(man + 1) % 5] == 1){
        stick[man] = stick[(man + 1) % 5] = 0;
        eating[man] = 1;
        printf("Philosopher %d picks chopstick %d and %d\n", man + 1, man + 1, (man + 1) % 5 + 1);
        printf("Philosopher %d is eating now.\n", man + 1);
    } else{
        printf("Philosopher %d is waiting for chopsticks.\n", man + 1);
    }
    ++mutex;
}

void put(int man){
    --mutex;
    if(eating[man] == 1){
        stick[man] = stick[(man + 1) % 5] = 1;
        eating[man] = 0;
        printf("Philosopher %d has put down chopstick %d and %d\n", man + 1, man + 1, (man + 1) % 5 + 1);
    } else{
        printf("Philosopher %d is not eating.\n", man + 1);
    }
    ++mutex;
}
