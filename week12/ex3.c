#include <linux/input.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
    char* dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    int fd = open(dev, O_RDONLY);
    FILE *f = fopen("ex3.txt", "w+");
    if (fd < 0) {
        perror("error");
        return 1;
    }
    struct input_event evt;
    // Remove Enter while starting the program
    read(fd, &evt, sizeof(struct input_event));
    read(fd, &evt, sizeof(struct input_event));

    printf("Press Q to exit!\n");
    
    int cap = 0;
    int pe = 0;
    int hw = 0;
    
    printf("List of available shortcuts:\nP + E -> I passed the exam!\nC + A + P -> Get some cappuccino!\nH + W -> You have some homework to do!\n");
    
    while(1) {
        read(fd, &evt, sizeof(struct input_event));
        if(evt.type != 4 && evt.code != EV_SYN) {
	    if (evt.value == 0)
	    	continue;
            if (evt.code == 46) {
                cap = 1;
                pe = 0;
                hw = 0;
            } else if (evt.code == 30 && cap == 1) {
            	cap = 2;
            	pe = 0;
            	hw = 0;
            } else if (evt.code == 25) {
            	if (cap == 2) {
            		printf("Get some cappuccino!\n");
            	} 
    		pe = 1;
    		hw = 0;
    		cap = 0;
            } else if (evt.code == 18 && pe == 1) {
            	printf("I passed the exam!\n");
            	pe = 0;
            	hw = 0;
            	cap = 0;
            } else if (evt.code == 35) {
            	hw = 1;
            	pe = 0;
            	cap = 0;
            } else if (evt.code == 17 && hw == 1) {
            	printf("You have some homework to do!\n");
            	pe = 0;
            	hw = 0;
            	cap = 0;
            } else if (evt.code == 16) {
                return 0;
            } else {
            	pe = 0;
            	hw = 0;
            	cap = 0;
            }
            
        }
    }
    return 0;
}
