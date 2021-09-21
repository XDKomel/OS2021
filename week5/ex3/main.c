#include <pthread.h>
#include <stdio.h>

int consumerIsSleeping = 0;
int producerIsSleeping = 0;
int buffer = 0;
const int criticalBufferValue = 1000;

void* produce(void* args) {
    while (1) {
        if (producerIsSleeping) {
            printf("I am a producer and I am sleeping\n");
            continue;
        }
        if (buffer < criticalBufferValue)
            printf("producer takes %d", buffer);
        if (buffer > 0) {
            consumerIsSleeping = 0;
            buffer++;
        } else {
            producerIsSleeping = 1;
        }
    }
    return NULL;
}

void* consume(void* args) {
    while (1) {
        if (consumerIsSleeping) {
            printf("I am a consumer and I am sleeping\n");
            continue;
        }
        if (buffer < criticalBufferValue)
            printf("consumer takes %d", buffer);
        if (buffer > 0) {
            producerIsSleeping = 0;
            buffer--;
        } else {
            consumerIsSleeping = 1;
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
