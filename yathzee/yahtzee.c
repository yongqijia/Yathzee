//
//  main.c
//  yahtzee
//
//  Created by Yongqi Jia on 12/11/19.
//  Copyright © 2019 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>




int randome()
{
    int rand_int = rand()%(6 -1 +1)+1;

    return rand_int;
}

int opeator(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

struct upper
{
    int ones;
    int twos;
    int threes;
    int fours;
    int fives;
    int sixes;
    int bonus;
};

struct lower
{
    int three_of_a_kind;
    int four_of_a_kind;
    int full_house;
    int small_straight;
    int large_straight;
    int yahtzee;
    int chance;
};

void display(struct upper us, struct lower ls){
    
    
}

int main()
{
    char *token[10];
    struct upper us;
    struct lower ls;
    int rounds = 0;
    int total = 0;
    srand(time(NULL));
    while (rounds != 13)
    {
        int i;
        int j;
        
        int dice[5];
        
        us.ones = -1;
        us.twos = -1;
        us.threes = -1;
        us.fours = -1;
        us.fives = -1;
        us.sixes = -1;
        us.bonus = 0;
        ls.three_of_a_kind = -1;
        ls.four_of_a_kind = -1;
        ls.full_house = -1;
        ls.small_straight = -1;
        ls.large_straight = -1;
        ls.yahtzee = -1;
        ls.chance = -1;
        
        printf("********** round %d start ********\n\n", rounds + 1);
        printf("Your roll: \n\n");

        for( i=0; i<=4; i++ ) {
            dice[i] = randome();
        }
        for( i=0; i<=4; i++ ){
            printf("%d ", dice[i]);
        }

        int check = 0;
        for (i = 0; i < 2; i++) {
            char input[10];
            printf("\n\nWhich dice to reroll? ");
            fgets(input, 10, stdin);
            token[0] = strtok(input, " ");
            int o = 0;
            while (token[0] != NULL) {
                int index = atoi(token[0]) - 1;
                if (index == -1) {
                    break;
                }
                check++;
                dice[index] = randome();
                o++;
                token[o] = strtok(NULL, " ");
            }
            if (check == 0) {
                break;
            }
            printf("\n");
            if (i == 0) {
                printf("Your second roll:");
            }else{
                printf("Your third roll:");
            }
            printf("\n\n");
            for(j = 0; j < 5; j++ ){
                printf("%d ", dice[j]);
            }
        }

        // let user select
        printf("\n\nPlace dice into:\n1) Upper Section\n2) Lower Section\n\nSelection? ");
        char temp1[10];
        fgets(temp1, 10, stdin);
        int selection = atoi(temp1);

        // upper section
        if(selection == 1){
            printf("\nPlace dice into:\n1) Ones\n2) Twos\n3) Threes\n4) Fours\n5) Fives\n6) Sixes\n\n");
            while (1) {
                printf("Selection? ");
                char temp2[10];
                fgets(temp2, 10, stdin);
                int choice = atoi(temp2);
                if (choice >= 1 && choice <= 6) {
                    int sum = 0;
                    for (i = 0; i < 5; i++) {
                        if (dice[i] == choice) {
                            sum += choice;
                        }
                    }
                    if(choice == 1 && us.ones == -1){
                        us.ones = sum;
                    }else if(choice == 2 && us.twos == -1){
                        printf("in2\n");
                        us.twos = sum;
                    }else if(choice == 3 && us.threes == -1){
                        us.threes = sum;
                    }else if(choice == 4 && us.fours == -1){
                        us.fours = sum;
                    }else if(choice == 5 && us.fives == -1){
                        us.fives = sum;
                    }else if(choice == 6 && us.sixes == -1){
                        us.sixes = sum;
                    }
                    
                    break;
                }else{
                    printf("Please enter correct number!\n\n");
                }
            }
            
            if(us.ones + us.twos + us.threes + us.fours + us.fives + us.sixes >= 63) {
                us.bonus = 35;
            }
        }

        // lower section
        qsort(dice, 5, sizeof(int), opeator);
        for(i = 0; i < 5; i++){
            printf("%d ", dice[i]);
        }
        if(selection == 2){
//             qsort(numRolls, MAX_DIE, sizeof(int), compare);
            printf("\nPlace dice into:\n1) Three of a Kind\n2) Four of a Kind\n3) Full House\n4) Small Straight\n5) large Straight\n6) Yahtzee\n7) Chance\n\nSelection? " );
            char temp3[10];
            fgets(temp3, 10, stdin);
            int chooooose = atoi(temp3);
            int same3 = 0;
            int same4 = 0;
            int same5 = 0;
            int full_house = 0;
            int stright = 0;
            
            if ((dice[0] == dice[1] && dice[1] == dice[2]) ||
                (dice[2] == dice[3] && dice[3] == dice[4]) ||
                (dice[1] == dice[2] && dice[2] == dice[3])) {
                same3 = 1;
            }
            if ((dice[0] == dice[1] && dice[1] == dice[2] && dice[2] == dice[3]) ||
                (dice[1] == dice[2] && dice[2] == dice[3] && dice[3] == dice[4])) {
                same4 = 1;
            }
            if (dice[0] == dice[1] && dice[1] == dice[2] && dice[2] == dice[3] && dice[3] == dice[4]) {
                same5 = 1;
            }
            if (((dice[0] == dice[1] && dice[1] == dice[2] )&& dice[3] == dice[4]) ||
                ((dice[2] == dice[3] && dice[3] == dice[4]) && dice[0] == dice[1])) {
                full_house = 1;
            }
            
            for (i = 0; i < 4; i++) {
                if(dice[i] != dice[i+1]){
                    if(dice[i] + 1 == dice[i+1]){
                        stright += 1;
                    }
                }
            }
//
//            printf("same3: %d\n", same3);
//            printf("same4: %d\n", same4);
//            printf("same5: %d\n", same5);
            
            if(chooooose == 1){
                if (same3) {
                    ls.three_of_a_kind = dice[0] + dice[1] + dice[2] + dice[3] + dice[4];
                }else{
                    ls.three_of_a_kind = 0;
                }
            }
            if(chooooose == 2){
                if (same4) {
                    ls.four_of_a_kind = dice[0] + dice[1] + dice[2] + dice[3] + dice[4];
                }else {
                    ls.four_of_a_kind = 0;
                }
            }
            if(chooooose == 4){
                if (stright == 4) {
                    ls.small_straight = 30;
                }else {
                    ls.small_straight = 0;
                }
            }
            if(chooooose == 5){
                if (stright == 5) {
                    ls.small_straight = 40;
                }else {
                    ls.small_straight = 0;
                }
            }
            if(chooooose == 3){
                if (full_house) {
                    ls.full_house = 25;
                }else {
                    ls.full_house = 0;
                }
            }
            if(chooooose == 7){
                ls.chance = dice[0] + dice[1] + dice[2] + dice[3] + dice[4];
            }
            if(chooooose == 6){
                if (same5) {
                    ls.yahtzee = 50;
                }else {
                    ls.yahtzee = 0;
                }
            }
        }

        
        if (us.ones != -1) {
            total += us.ones;
        }
        if (us.twos != -1) {
            total += us.twos;
        }
        if (us.threes != -1) {
            total += us.threes;
        }
        if (us.fours != -1) {
            total += us.fours;
        }
        if (us.fives != -1) {
            total += us.fives;
        }
        if (us.sixes != -1) {
            total += us.sixes;
        }
        if (ls.three_of_a_kind != -1) {
            total += ls.three_of_a_kind;
        }
        if (ls.four_of_a_kind != -1) {
            total += ls.four_of_a_kind;
        }
        if (ls.small_straight != -1) {
            total += ls.small_straight;
        }
        if (ls.large_straight != -1) {
            total += ls.large_straight;
        }
        if (ls.full_house != -1) {
            total += ls.full_house;
        }
        if (ls.yahtzee != -1) {
            total += ls.yahtzee;
        }
        
        total += us.bonus;

        printf("\nYour score so far is: %d\n\n", total);
        
        if (us.ones != -1) {
            printf("Ones: %d \t\t Fours: ", us.ones);
        }else{
            printf("Ones:    \t\t Fours: ");
        }
        
        if (us.fours != -1) {
            printf("%d\n",us.fours);
        }else{
            printf("\n");
        }
        
        if (us.twos != -1) {
            printf("Twos: %d \t\t Fives: ", us.twos);
        }else{
            printf("Twos:    \t\t Fives: ");
        }
        if (us.fives != -1) {
            printf("%d\n",us.fives);
        }else{
            printf("\n");
        }
        
        if (us.threes != -1) {
            printf("Three: %d \t\t Sixes: ", us.threes);
        }else{
            printf("Three:    \t\t Sixes: ");
        }
        if (us.sixes != -1) {
            printf("%d\n",us.sixes);
        }else{
            printf("\n");
        }

        printf("Upper Section Bonus: %d\n", us.bonus);

        if (ls.three_of_a_kind != -1) {
            printf("Three of a Kind: %d \t Four of a Kind: ", ls.three_of_a_kind);
        }else{
            printf("Three of a Kind:    \t Four of a Kind: ");
        }
        if (ls.four_of_a_kind != -1) {
            printf("%d\n",ls.four_of_a_kind);
        }else{
            printf("\n");
        }
        
        if (ls.small_straight != -1) {
            printf("Small Straight: %d \t Large Strait: ", ls.small_straight);
        }else{
            printf("Small Straight:    \t Large Strait: ");
        }
        if (ls.large_straight != -1) {
            printf("%d\n",ls.large_straight);
        }else{
            printf("\n");
        }
        
        if (ls.full_house != -1) {
            printf("Full House: %d \t\t Yahtzee: ", ls.full_house);
        }else{
            printf("Full House:    \t\t Yahtzee: ");
        }
        if (ls.yahtzee != -1) {
            printf("%d\n",ls.yahtzee);
        }else{
            printf("\n");
        }
        
        if (ls.chance == -1) {
            printf("Chance: \n");
        }else{
            printf("Chance: %d\n", ls.chance);
        }
        
        
        
        printf("********** round %d end **********\n\n", rounds + 1);

        rounds++;
    }
}

