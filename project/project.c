#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct batsman {
    char name[25];
    int ones, twos, threes, fours, sixes, balls;
    int runs;
    float strike_rate;
};

struct bowler {
    char name[25];
    int runs_given, wickets;
    float overs;
    float economy;
};

// Function declarations
void save_batsman_details(int m);
void save_bowler_details(int n);
void view_batsman_details();
void view_bowler_details();
void match_summary();
void welcome_message();

// Main function
int main() {
    int choice;

    // Set console color to white background and black text
    system("COLOR F0");

    // Show welcome message
    welcome_message();

    // Main program menu
   // Main program menu
   printf("\n\n\n\n\n\n\n\n");
do {
    printf("                                        \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("                                        \xB2                                  \xB2                                                                             ");
    printf("       \xB2        1) Add Batsman details    \xB2\n");
    printf("                                        \xB2        2) Add Bowler details     \xB2\n");
    printf("                                        \xB2        3) View Batsman details   \xB2\n");
    printf("                                        \xB2        4) View Bowler details    \xB2\n");
    printf("                                        \xB2        5) Match Summary          \xB2\n");
    printf("                                        \xB2        6) Exit                   \xB2\n");
    printf("                                        \xB2                                  \xB2\n");
    printf("                                        \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
   
    printf("Enter your choice: ");
    scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int m;
                printf("Enter the number of batsmen to add: ");
                scanf("%d", &m);
                save_batsman_details(m);
                break;
            }
            case 2: {
                int n;
                printf("Enter the number of bowlers to add: ");
                scanf("%d", &n);
                save_bowler_details(n);
                break;
            }
            case 3:
                view_batsman_details();
                break;
            case 4:
                view_bowler_details();
                break;
            case 5:
                match_summary();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}

// Welcome message function
void welcome_message() {
    // Clear any leftover input buffers
    while (getchar() != '\n');  // Clear input buffer to ensure clean input

    printf("==============================================\n");
    printf("   Welcome to the DIGITAL CRICKET SCOREBOARD SYSTEM\n");
    printf("==============================================\n");
    printf("Press ENTER to continue to the Main Menu...\n");

    getchar();  // Wait for the user to press a key
     system("cls");
}

// Save batsman details to players.txt
void save_batsman_details(int m) {
    FILE *file = fopen("players.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct batsman pl;
    for (int i = 0; i < m; i++) {
        printf("Enter name of batsman %d: ", i + 1);
        scanf("%s", pl.name);

        printf("Enter number of ones: ");
        scanf("%d", &pl.ones);

        printf("Enter number of twos: ");
        scanf("%d", &pl.twos);

        printf("Enter number of threes: ");
        scanf("%d", &pl.threes);

        printf("Enter number of fours: ");
        scanf("%d", &pl.fours);

        printf("Enter number of sixes: ");
        scanf("%d", &pl.sixes);

        printf("Enter number of balls faced: ");
        scanf("%d", &pl.balls);

        pl.runs = (1 * pl.ones) + (2 * pl.twos) + (3 * pl.threes) + (4 * pl.fours) + (6 * pl.sixes);
        if (pl.balls != 0) {
            pl.strike_rate = (pl.runs * 100.0) / pl.balls;
        } else {
            pl.strike_rate = 0;
        }

        fprintf(file, "Batsman: %s, Runs: %d, Balls: %d, Fours: %d, Sixes: %d, Strike Rate: %.2f\n", 
                pl.name, pl.runs, pl.balls, pl.fours, pl.sixes, pl.strike_rate);
    }

    fclose(file);
    printf("Batsman details saved successfully.\n");
      system("cls");
}

// Save bowler details to players.txt
void save_bowler_details(int n) {
    FILE *file = fopen("players.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct bowler pl;
    for (int i = 0; i < n; i++) {
        printf("Enter name of bowler %d: ", i + 1);
        scanf("%s", pl.name);

        printf("Enter runs given: ");
        scanf("%d", &pl.runs_given);

        printf("Enter overs bowled: ");
        scanf("%f", &pl.overs);

        printf("Enter wickets taken: ");
        scanf("%d", &pl.wickets);

        if (pl.overs != 0) {
            pl.economy = (float)pl.runs_given / pl.overs;
        } else {
            pl.economy = 0;
        }

        fprintf(file, "Bowler: %s, Runs Given: %d, Overs: %.1f, Wickets: %d, Economy: %.2f\n", 
                pl.name, pl.runs_given, pl.overs, pl.wickets, pl.economy);
    }

    fclose(file);
    printf("Bowler details saved successfully.\n");
}

// View batsman details from players.txt
void view_batsman_details() {
    FILE *file = fopen("players.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char line[256];
    printf("Batsman Details:\n");
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Batsman")) {
            printf("%s", line);
        }
    }

    fclose(file);
}

// View bowler details from players.txt
void view_bowler_details() {
    FILE *file = fopen("players.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char line[256];
    printf("Bowler Details:\n");
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Bowler")) {
            printf("%s", line);
        }
    }

    fclose(file);
}

// View match summary from players.txt
void match_summary() {
    FILE *file = fopen("players.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char line[256];
    printf("Match Summary:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}
