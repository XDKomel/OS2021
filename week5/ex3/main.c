#include <pthread.h>
#include <stdio.h>

void line() {
    printf("\n");
}

int consumerIsSleeping = 1;
int producerIsSleeping = 0;
int globalVariable = 0;
int numberOfCycles = 0;

void* produce(void* args) {
    while (1) {
        if (!producerIsSleeping) {
            if (globalVariable < 1000) {
                globalVariable++;
            } else {
                producerIsSleeping = 1;
                printf("produced number %d", globalVariable);
                line();
                consumerIsSleeping = 0;
            }
        } else if (numberOfCycles > 10) {
            break;
        }
    }
    return NULL;
}

void* consume(void* args) {
    while (1) {
        if (!consumerIsSleeping) {
            if (globalVariable > 100) {
                globalVariable--;
            } else {
                consumerIsSleeping = 1;
                printf("consumed number %d", globalVariable);
                line();
                producerIsSleeping = 0;
                numberOfCycles++;
            }
        } else if (numberOfCycles > 10) {
            break;
        }
    }
    return NULL;
}


int main() {

    pthread_t consumer;
    pthread_t producer;

    pthread_create(&producer, NULL, produce, NULL);
    pthread_create(&consumer, NULL, consume, NULL);

    pthread_join(consumer, NULL);
    pthread_join(producer, NULL);

    return 0;
}
