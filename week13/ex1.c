#include <stdio.h>

#define true 1
#define false 0

#define input_filename "input.txt" // name of the input file
#define processes_number 5 // amount of processes
#define resources_number 3 // amount of resource types

struct Process {
    int id;
    int is_done;
    int current_allocation[resources_number];
    int requested_allocation[resources_number];
};

int existing_resources[resources_number];
int available_resources[resources_number];
struct Process process[processes_number];

void scan_file(char *filename) {
    FILE *input;
    input = fopen(filename, "r");

    if(input == NULL) {
        printf("Could not open file!\n");
        return;
    }

    for(int j = 0; j < resources_number; j++) {
        fscanf(input, "%d", &existing_resources[j]);
    }

    for(int j = 0; j < resources_number; j++) {
        fscanf(input, "%d", &available_resources[j]);
    }

    for(int j = 0; j < processes_number; j++) {
        process[j].id = j;
        process[j].is_done = false;
    }

    for(int id = 0; id < processes_number; id++) {
        for(int j = 0; j < resources_number; j++)
            fscanf(input, "%d", &process[id].current_allocation[j]);

    }

    for(int id = 0; id < processes_number; id++) {
        for(int j = 0; j < resources_number; j++)
            fscanf(input, "%d", &process[id].requested_allocation[j]);

    }
}

void release_resources(int process_id) {
    for(int j = 0; j < resources_number; j++) {
        available_resources[j] =
                available_resources[j] + process[process_id].current_allocation[j];
        process[process_id].current_allocation[j] = 0;
        process[process_id].requested_allocation[j] = 0;
        process[process_id].is_done = true;
    }
}

int find_candidate() {
    for(int id = 0; id < processes_number; id++) {
        if(process[id].is_done == true)
            continue;
        for(int j = 0; j < resources_number; j++) {
            if(process[id].requested_allocation[j] > available_resources[j])
                break;
            if(j + 1 == resources_number)
                return id;
        }
    }
    return -1;
}

void print_state(int verdict) {
    if(verdict == true) {
        printf("\n############ RESULT ###########\n");
    } else {
        printf("\n###############################\n");
    }
    printf("Available: (");
    for(int j = 0; j < resources_number; j++) {
        printf("%d", available_resources[j]);
        if(j + 1 == resources_number) {
            printf(")\n");
        } else {
            printf(", ");
        }
    }
    int counter = 0;
    for(int id = 0; id < processes_number; id++) {
        printf("Process %d ", process[id].id);
        if(verdict == true) {
            if(process[id].is_done == false) {
                printf("is deadlocked!\n");
                counter++;
            } else {
                printf("is is_done!\n");
            }
        } else {
            if(process[id].is_done == false) {
                printf("is not finished yet. Requires (");
                for(int j = 0; j < resources_number; j++) {
                    printf("%d", process[id].requested_allocation[j]);
                    if(j + 1 == resources_number) {
                        printf(").\n");
                    } else {
                        printf(", ");
                    }
                }
            } else {
                printf("is done.\n");
            }
        }
    }
    if(verdict) {
        if(counter != 0) {
            printf("Number of processes that are deadlocked: %d!\n", counter);
        } else {
            printf("No deadlocks detected!\n");
        }
    }
}

int main() {
    scan_file(input_filename);

    printf("Exists: (");
    for(int j = 0; j < resources_number; j++) {
        printf("%d", existing_resources[j]);
        if(j + 1 == resources_number) {
            printf(")\n");
        } else {
            printf(", ");
        }
    }

    int candidate;
    while(true) {
        print_state(false);
        candidate = find_candidate();
        if(candidate == -1)
            break;
        release_resources(candidate);
    }

    print_state(true);

    return 0;
}