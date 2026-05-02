/*
 * Day 99: Car Fleet Calculation
 * Calculate number of car fleets reaching destination
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    double time;
} Car;

int compare(const void* a, const void* b) {
    Car* c1 = (Car*)a;
    Car* c2 = (Car*)b;
    return c2->position - c1->position;
}

int carFleet(int target, int position[], int speed[], int n) {
    Car cars[100];
    
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }
    
    qsort(cars, n, sizeof(Car), compare);
    
    int fleets = 0;
    double maxTime = 0;
    
    for (int i = 0; i < n; i++) {
        if (cars[i].time > maxTime) {
            fleets++;
            maxTime = cars[i].time;
        }
    }
    
    return fleets;
}

int main() {
    printf("=== Day 99: Car Fleet ===\n\n");
    
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int n = 5;
    
    printf("Target: %d\n", target);
    printf("Positions: ");
    for (int i = 0; i < n; i++) printf("%d ", position[i]);
    printf("\nSpeeds: ");
    for (int i = 0; i < n; i++) printf("%d ", speed[i]);
    printf("\n");
    
    printf("\nNumber of car fleets: %d\n", carFleet(target, position, speed, n));
    
    printf("\n=== Program Completed Successfully ===\n");
    return 0;
}
