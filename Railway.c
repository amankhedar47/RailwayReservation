#include <stdio.h>
#include <stdbool.h>

#define MAX_SEATS 50

struct Reservation {
    int seatNumber;
    char passengerName[30];
    bool isReserved;
};

struct Reservation reservations[MAX_SEATS];

void initializeReservations() {
    for (int i = 0; i < MAX_SEATS; i++) {
        reservations[i].seatNumber = i + 1;
        reservations[i].isReserved = false;
    }
}

void displayAvailableSeats() {
    printf("Available seats:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (!reservations[i].isReserved) {
            printf("Seat %d\n", reservations[i].seatNumber);
        }
    }
}

void makeReservation() {
    int seatNumber;
    printf("Enter the seat number you want to reserve: ");
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > MAX_SEATS) {
        printf("Invalid seat number!\n");
        return;
    }

    if (reservations[seatNumber - 1].isReserved) {
        printf("Seat %d is already reserved.\n", seatNumber);
    } else {
        printf("Enter passenger name: ");
        scanf("%s", reservations[seatNumber - 1].passengerName);
        reservations[seatNumber - 1].isReserved = true;
        printf("Reservation successful for seat %d.\n", seatNumber);
    }
}

int main() {
    initializeReservations();
    int choice;

    do {
        printf("\nRailway Reservation System\n");
        printf("1. Display available seats\n");
        printf("2. Make a reservation\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAvailableSeats();
                break;
            case 2:
                makeReservation();
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
