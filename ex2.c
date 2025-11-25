/******************
Name: Guy Kejzman
ID: kejzmag
Assignment: EX2 2026 - Control Flow and Logic
*******************/
#define _CRT_SECURE_NO_WARNINGS
#define EXIT_OPTION 6          // Menu option number for exiting the game
#define MAX_DUCKS_IN_ROW 10    // Maximum ducks printed in a single parade row
#define BINARY_BASE 2       // Base used for binary conversion
#define DECIMAL_BASE 10     // Base used for decimal conversion
#include <stdio.h>

int main()
{
    // Main menu choice variable
    int choice = 0;

    // Main loop: keep running until the user chooses the exit option
    while (choice != EXIT_OPTION) {
        // Print the main menu and read the user's choice
        printf("Welcome to our games, please choose an option:\n");
        printf("1. Ducky's Unity Game\n");
        printf("2. The Memory Game \n");
        printf("3. Professor Pat's Power Calculation\n");
        printf("4. The Duck Parade\n");
        printf("5. The Mystery of the Repeated Digits\n");
        printf("6. Good Night Ducks\n");
        scanf("%d", &choice);

        // Execute the task based on the user's choice
        switch (choice) {
        case 1: {
            // TASK 1: Ducky's Unity Game
            // Count number of 1 bits in the binary form of a positive number
            int num = 0;
            int sum = 0;

            // Get a valid positive number from the user
            printf("please enter a positive number:\n");
            scanf("%d", &num);
            while (num <= 0) {
                printf("Invalid number, please try again\n");
                scanf("%d", &num);
            }

            // Convert to binary and count ones
            while (num > 0) {
                sum += (num % BINARY_BASE);
                num /= BINARY_BASE;
            }

            // Print the number of golden corns
            printf("Ducky earns %d corns\n", sum);
            break;
        }
        case 2: {
            // TASK 2: The Memory Game
            // Remember for each duck if it said Quak or Sh... using bits in an int
            int ducks = 0;
            int duckState = 0;
            int memory = 0;   // Each bit represents if a duck said Quak (1) or not (0)
            int i;

            // Get a valid positive number of ducks
            printf("please enter the number of ducks:\n");
            scanf("%d", &ducks);
            while (ducks <= 0) {
                printf("Invalid number, please try again\n");
                scanf("%d", &ducks);
            }

            // Ask for each duck whether it said Quak (1) or Sh... (0)
            printf("you entered %d ducks\n", ducks);
            i = 1;
            while (i <= ducks) {
                printf("duck %d do QUAK? 1 for yes, 0 for no\n", i);
                scanf("%d", &duckState);

                // Validate input for each duck
                while (duckState < 0 || duckState > 1) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &duckState);
                }

                // Store the answer in the corresponding bit
                if (duckState == 1) {
                    memory = memory | (1 << (i - 1));
                }

                i = i + 1;
            }

            // Summary: print what each duck did
            i = 1;
            while (i <= ducks) {
                if (memory & (1 << (i - 1))) {
                    printf("duck number %d do Quak\n", i);
                }
                else {
                    printf("duck number %d do Sh...\n", i);
                }
                i = i + 1;
            }

            break;
        }
        case 3: {
            // TASK 3: Professor Pat's Power Calculation
            // Compute number^exponent for non-negative integers without math.h
            int number = 0;
            int exponent = 0;

            // Get a valid (non-negative) base number
            printf("please enter the number\n");
            scanf("%d", &number);
            while (number < 0) {
                printf("Invalid number, please try again\n");
                scanf("%d", &number);
            }

            // Get a valid (non-negative) exponent
            printf("please enter the exponent\n");
            scanf("%d", &exponent);
            while (exponent < 0) {
                printf("Invalid number, please try again\n");
                scanf("%d", &exponent);
            }

            // Repeated multiplication to compute power
            int base = number;
            int result = 1;
            int i = 0;
            while (i < exponent) {
                result *= base;
                i = i + 1;
            }

            // Print the power result
            printf("your power is: %d\n", result);
            break;
        }
        case 4: {
            // TASK 4: The Duck Parade
            // Print ducks in rows, up to MAX_DUCKS_IN_ROW ducks per row
            int ducks = 0;

            // Get a valid positive number of ducks
            printf("please enter number of ducks:\n");
            scanf("%d", &ducks);
            while (ducks <= 0) {
                printf("Invalid number, please try again\n");
                scanf("%d", &ducks);
            }

            // Print ducks in blocks of up to MAX_DUCKS_IN_ROW
            while (ducks > 0) {
                int ducksThisRow = 0;

                // Decide how many ducks to print in this row
                if (ducks >= MAX_DUCKS_IN_ROW) {
                    ducksThisRow = MAX_DUCKS_IN_ROW;
                }
                else {
                    ducksThisRow = ducks;
                }

                // First line of the ducks in this row
                int i = 0;
                while (i < ducksThisRow) {
                    printf("   _");
                    if (i != ducksThisRow - 1) {
                        printf("\t\t");
                    }
                    i = i + 1;
                }
                printf("\n");

                // Second line of the ducks in this row
                i = 0;
                while (i < ducksThisRow) {
                    printf(" __(o)>");
                    if (i != ducksThisRow - 1) {
                        printf("\t\t");
                    }
                    i += 1;
                }
                printf("\n");

                // Third line of the ducks in this row
                i = 0;
                while (i < ducksThisRow) {
                    printf(" \\___)");
                    if (i != ducksThisRow - 1) {
                        printf("\t\t");
                    }
                    i += 1;
                }
                printf("\n");

                // Reduce remaining ducks by one full row
                ducks -= MAX_DUCKS_IN_ROW;
            }

            break;
        }
        case 5: {
            // TASK 5: The Mystery of the Repeated Digits
            // Print digits that appear more than once in a positive number
            int num = 0;
            int temp = 0;
            int digit = 0;

            // Get a valid positive number
            printf("please enter number\n");
            scanf("%d", &num);
            while (num <= 0) {
                printf("Invalid number, please try again\n");
                scanf("%d", &num);
            }

            // Scan digits from right to left
            while (num > 0)
            {
                // temp holds the remaining digits to the left
                temp = num / DECIMAL_BASE;
                digit = num % DECIMAL_BASE;

                // Check if this digit appears again to the left
                while (temp > 0)
                {
                    if (temp % DECIMAL_BASE == digit)
                    {
                        printf("%d appears more than once!\n", digit);
                        temp = 0;   // stop checking this digit further
                    }
                    temp /= DECIMAL_BASE;
                }
                num /= DECIMAL_BASE;
            }

            break;
        }
        case 6:
            // EXIT: print goodbye message and end the program
            printf("Good night! See you at the pond tomorrow.\n");
            break;
        default:
            // Handle invalid menu options
            printf("Invalid option, please try again\n");
            break;
        }
    }
    return 0;
}
