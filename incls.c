#include <stdio.h>

#define MAX_CUSTOMERS 100
#define MAX_BOOTHS 10

struct Booth {
    int id;
    int freeAt;
    int totalServiceTime;
    int idleTime;
};

struct Customer {
    int id;
    int arrivalTime;
    int serviceTime;
    int assignedBooth;
    int startTime;
    int finishTime;
    int waitingTime;
};

int main() {

    int totalBooths;
    int totalCustomers;

    struct Booth booths[MAX_BOOTHS];
    struct Customer customers[MAX_CUSTOMERS];

    printf("Enter number of booths: ");
    scanf("%d", &totalBooths);

    printf("Enter number of customers (minimum 20): ");
    scanf("%d", &totalCustomers);

    if (totalCustomers < 20) {
        printf("Minimum 20 customers required!\n");
        return 0;
    }

    for (int i = 0; i < totalBooths; i++) {
        booths[i].id = i + 1;
        booths[i].freeAt = 0;
        booths[i].totalServiceTime = 0;
        booths[i].idleTime = 0;
    }

    printf("\n Customer iNput \n");

    for (int i = 0; i < totalCustomers; i++) {

        customers[i].id = i + 1;

        printf("\nCustomer C%d\n", i + 1);

        printf("Arrival Time : ");
        scanf("%d", &customers[i].arrivalTime);

        printf("Service Time : ");
        scanf("%d", &customers[i].serviceTime);
    }

    int totalWaitingTime = 0;

    for (int i = 0; i < totalCustomers; i++) {
        int bestBooth = 0;

        for (int j = 1; j < totalBooths; j++) {

            if (booths[j].freeAt < booths[bestBooth].freeAt) {
                bestBooth = j;
            }
        }
        if (customers[i].arrivalTime > booths[bestBooth].freeAt) {

            booths[bestBooth].idleTime +=customers[i].arrivalTime - booths[bestBooth].freeAt;
        }

        if (customers[i].arrivalTime > booths[bestBooth].freeAt) {

            customers[i].startTime =customers[i].arrivalTime;

        } else {

            customers[i].startTime = booths[bestBooth].freeAt;
        }

        customers[i].waitingTime =customers[i].startTime -customers[i].arrivalTime;

        customers[i].finishTime =customers[i].startTime + customers[i].serviceTime;

        customers[i].assignedBooth = booths[bestBooth].id;

        booths[bestBooth].freeAt =customers[i].finishTime;

        booths[bestBooth].totalServiceTime +=customers[i].serviceTime;
        totalWaitingTime +=customers[i].waitingTime;
    }

    printf("\n\n");
    printf("| Customer | Arrival | Service | Booth | Start | Finish | Waiting |\n");
    printf("+----------+---------+---------+-------+-------+--------+---------+\n");
    for (int i = 0; i < totalCustomers; i++) {
        printf("| C%-7d | %-7d | %-7d | B%-4d | %-5d | %-6d | %-7d |\n",
               customers[i].id,
               customers[i].arrivalTime,
               customers[i].serviceTime,
               customers[i].assignedBooth,
               customers[i].startTime,
               customers[i].finishTime,
               customers[i].waitingTime);
    }
    printf("\n\n");

    printf("Booth Stat:\n");
    printf("| Booth   | Total Service Time| Idle Time  |\n");


    for (int i = 0; i < totalBooths; i++) {
        printf("| Booth %-1d | %-17d | %-10d |\n",
               booths[i].id,
               booths[i].totalServiceTime,
               booths[i].idleTime);
    }

    printf("\n");
    float averageWaitingTime =(float) totalWaitingTime / totalCustomers;
    printf("\n\n");
    printf(" OVERALL STATISTICS\n");
    printf("Average Waiting Time : %.2f\n", averageWaitingTime);

    return 0;
}
