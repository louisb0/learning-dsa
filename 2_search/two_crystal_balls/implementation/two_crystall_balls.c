#include <math.h>
#include <stdio.h>

int solve(int floors[], int num_floors) {
    int step = (int)sqrt(num_floors);
    int prev_floor = 0;

    // Find where the ball breaks
    int breaking_block = step;
    while (breaking_block < num_floors && floors[breaking_block] == 0) {
        breaking_block += step;
        prev_floor += 1;
    }

    // Linear search within the block
    for (int i = prev_floor; i < breaking_block && i < num_floors; i++) {
        if (floors[i] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    // index 9, floor 10
    int testCase1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
                       1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    // index 19, floor 20
    int testCase2[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                       0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    printf("%d\n", solve(testCase1, 30));
    printf("%d\n", solve(testCase2, 30));
}
