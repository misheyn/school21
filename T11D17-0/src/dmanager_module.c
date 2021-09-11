// Copyright 2021 gsherley
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID 100000

void initialize_doors(struct door* doors);
void output(struct door* doors);
void sort_doors(struct door* doors);
void closing_doors(struct door* doors);

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    sort_doors(doors);
    closing_doors(doors);
    output(doors);
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));
    int seed = rand() % MAX_ID;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % MAX_ID;
        doors[i].status = rand() % 2;
    }
}

void output(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        printf("%d, %d\n", doors[i].id, doors[i].status);
    }
}

void sort_doors(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT - 1; i++) {
        for (int j = 0; j < DOORS_COUNT - i - 1; j++) {
            if (doors[j].id > doors[j + 1].id) {
                        int tmp = doors[j].id;
                        doors[j].id = doors[j + 1].id;
                        doors[j + 1].id = tmp;
            }
        }
    }
}

void closing_doors(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        if (doors[i].status == 1) doors[i].status = 0;
    }
}
