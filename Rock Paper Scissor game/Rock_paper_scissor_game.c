#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Program to generate random no.
int random_number_generator(int n)
{
    srand(time(NULL));
    return rand() % n;
}

// program to decide awinner
int check_winner(int computers_score, int players_score)
{
    if (computers_score > players_score)
    {
        printf("CPU won the game\n");
    }
    else if (players_score == computers_score)
    {
        printf("Its a Draw\n");
    }
    else if (players_score > computers_score)
    {
        printf("You Won the game\n");
    }
}

// Program to check which is check_greater_option
int check_greater_option(char a, char b)
{
    if ((a == 'r') && (b == 's'))
    {
        return 1;
    }
    else if ((a == 's') && (b == 'r'))
    {
        return 0;
    }
    else if ((a == 'p') && (b == 'r'))
    {
        return 1;
    }
    else if ((a == 'r') && (b == 'p'))
    {
        return 0;
    }
    else if ((a == 's') && (b == 'p'))
    {
        return 1;
    }
    else if ((a == 'p') && (b == 's'))
    {
        return 0;
    }
    else if ((a = 's') && (b = 's'))
    {
        return -1;
    }
    else if ((a = 'r') && (b = 'r'))
    {
        return -1;
    }
    else if ((a = 'p') && (b = 'p'))
    {
        return -1;
    }

    // Driver Program
}
int main()
{
    int n;
    // Decelerations and Definations.
    char name[29];       // TO store the name of the player
    char players_choice; // to store players choice
    char choice[] = {'r', 'p', 's'};
    char computers_choice; // To store computers choice
    int temp;              // temperory variable;
    int computers_score = 0, players_score = 0;
    char dict[] = {'r', 'p', 's'}; // user defined local directory

    // Below program will run only once.
    printf("\nPlease enter your name :\n");
    scanf("%s", &name);
    getchar();
    printf("How many times would you like to play this game :");
    scanf("%d", &n);
    printf("\nWelcome to the game MR.%s we would be playing best out of three\n", name);

    // using loop to play the game 3 times
    for (int i = 1; i <= n; i++)
    {
        printf("Its your turn:\n");
        printf("1.Rock\n2.Paper\n3.Scissor \nplease select any one of above :");
        scanf("%d", &temp);
        getchar();
        players_choice = dict[temp - 1];
        printf("You chose %c\n\n", players_choice);

        printf("Computers Turn:\n");
        temp = random_number_generator(3) + 1;
        computers_choice = dict[temp - 1];
        printf("Computer chose %c\n", computers_choice);

        if (check_greater_option(computers_choice, players_choice) == 1)
        {
            computers_score++;
            printf("CPU won\n");
        }
        else if (check_greater_option(computers_choice, players_choice) == -1)
        {
            computers_score++;
            players_score++;
            printf("Draw \n");
        }
        else
        {
            players_score++;
            printf("You won\n");
        }
        printf("your score:%d \t Computers Score:%d\n\n", players_score, computers_score);
    }
    check_winner(computers_score, players_score);
    return 0;
}