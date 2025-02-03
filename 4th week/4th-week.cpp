#include <stdio.h>

#define MAX_TRAINS 3  // Define a constant for the maximum number of trains

// Function to view available trains
void viewTrains(int train_no[], char destinations[][20], int seats[], int prices[]) {
    printf("\nAvailable Trains:\n");
    for (int i = 0; i < MAX_TRAINS; i++) {
        printf("Train No: %d, Destination: %s, Available Seats: %d, Price: %d RWF\n",
               train_no[i], destinations[i], seats[i], prices[i]);
    }
}

// Function to search trains by destination
void searchTrains(int train_no[], char destinations[][20], int seats[], int prices[]) {
    char destination[20];
    int found = 0;

    printf("\nEnter destination: ");
    scanf("%s", destination);

    printf("\nSearch results:\n");
    for (int i = 0; i < MAX_TRAINS; i++) {
        int j = 0, match = 1;
        while (destination[j] != '\0' && destinations[i][j] != '\0') {
            if (destination[j] != destinations[i][j]) {
                match = 0;
                break;
            }
            j++;
        }
        if (match && destination[j] == '\0' && destinations[i][j] == '\0') {
            printf("Train No: %d, Destination: %s, Available Seats: %d, Price: %d RWF\n",
                   train_no[i], destinations[i], seats[i], prices[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No trains found for destination: %s\n", destination);
    }
}

// Function to book tickets
void bookTicket(int train_no[], char destinations[][20], int seats[]) {
    int t_no, seat_count, found = 0;

    printf("\nEnter train number: ");
    scanf("%d", &t_no);

    for (int i = 0; i < MAX_TRAINS; i++) {
        if (train_no[i] == t_no) {
            found = 1;
            printf("Enter number of seats: ");
            scanf("%d", &seat_count);

            if (seat_count > 0 && seat_count <= seats[i]) {
                seats[i] -= seat_count;
                printf("%d tickets booked successfully for Train No: %d.\n", seat_count, t_no);
                printf("Remaining Seats: %d\n", seats[i]);
            } else {
                printf("Invalid seat count or not enough seats available!\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Train number not found!\n");
    }
}

// Function to cancel tickets
void cancelTicket(int train_no[], char destinations[][20], int seats[]) {
    int t_no, seat_count, found = 0;

    printf("\nEnter train number: ");
    scanf("%d", &t_no);

    for (int i = 0; i < MAX_TRAINS; i++) {
        if (train_no[i] == t_no) {
            found = 1;
            printf("Enter number of seats to cancel: ");
            scanf("%d", &seat_count);

            if (seat_count > 0) {
                seats[i] += seat_count;
                printf("%d tickets canceled successfully for Train No: %d.\n", seat_count, t_no);
                printf("Remaining Seats: %d\n", seats[i]);
            } else {
                printf("Invalid seat count!\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Train number not found!\n");
    }
}

int main() {
    int train_no[MAX_TRAINS] = {101, 102, 103};
    char destinations[MAX_TRAINS][20] = {"Kigali", "Musanze", "Rubavu"};
    int seats[MAX_TRAINS] = {30, 25, 15};
    int prices[MAX_TRAINS] = {5000, 4500, 3500};

    int choice;
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. View available trains\n");
        printf("2. Book a ticket\n");
        printf("3. Cancel a ticket\n");
        printf("4. Search by destination\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            viewTrains(train_no, destinations, seats, prices);
        } else if (choice == 2) {
            bookTicket(train_no, destinations, seats);
        } else if (choice == 3) {
            cancelTicket(train_no, destinations, seats);
        } else if (choice == 4) {
            searchTrains(train_no, destinations, seats, prices);
        } else if (choice == 5) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
