//
//  main.c
//  minecraft-bingo
//
//  Created by emma scalabrino on 11/19/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void printCard(char fillIn[], int length);

int main() {
    char typeGenerated;
    const int NUM_SPACES = 30;
    char bingoCard[NUM_SPACES];
    int layoutGenerator;
    int amountRandomGenerated;
    int spaceGenerated;
    
    srand((int)time(0));
    printf("\n\tMinecraft Random Bingo Spaces\t\n");
    printf("Traditional Bingo or Random? [ T | R ]: ");
    scanf("%c", &typeGenerated);
    typeGenerated = toupper(typeGenerated);
    
    for (int i = 0; i < NUM_SPACES; i++) {
        bingoCard[i] = ' ';
    }
    
    switch (typeGenerated) {
        case 'T':
            /*
             In traditional style bingo, there are only 15 different possibilities for layouts of
             the board. In this program, the random numbers correlated to the different layouts are
             as follows:
             
             0: diagonal from top left to bottom right
             1: diagonal from top right to bottom left
             2: L-R top row
             3: L-R 2nd row
             4: L-R middle row
             5: L-R 4th row
             6: L-R bottom row
             7: T-B left column
             8: T-B 2nd column
             9: T-B middle column
             10: T-B 4th column
             11: T-B right column
             12: 4 corners
             13: X (both diagonals)
             14: + (middle row/column)
             
             For example, if layoutGenerator is 3, the layout of the bingo board will be the top row
             of squares going left to right.
             */
            layoutGenerator = (rand() % 15);
            switch (layoutGenerator) {
                case 0:
                    bingoCard[0] = 'x';
                    bingoCard[6] = 'x';
                    bingoCard[12] = 'x';
                    bingoCard[18] = 'x';
                    bingoCard[24] = 'x';
                    break;
                case 1:
                    bingoCard[4] = 'x';
                    bingoCard[8] = 'x';
                    bingoCard[12] = 'x';
                    bingoCard[16] = 'x';
                    bingoCard[20] = 'x';
                    break;
                case 2:
                    bingoCard[0] = 'x';
                    bingoCard[1] = 'x';
                    bingoCard[2] = 'x';
                    bingoCard[3] = 'x';
                    bingoCard[4] = 'x';
                    break;
                case 3:
                    bingoCard[5] = 'x';
                    bingoCard[6] = 'x';
                    bingoCard[7] = 'x';
                    bingoCard[8] = 'x';
                    bingoCard[9] = 'x';
                    break;
                case 4:
                    bingoCard[10] = 'x';
                    bingoCard[11] = 'x';
                    bingoCard[12] = 'x';
                    bingoCard[13] = 'x';
                    bingoCard[14] = 'x';
                    break;
                case 5:
                    bingoCard[15] = 'x';
                    bingoCard[16] = 'x';
                    bingoCard[17] = 'x';
                    bingoCard[18] = 'x';
                    bingoCard[19] = 'x';
                    break;
                case 6:
                    bingoCard[20] = 'x';
                    bingoCard[21] = 'x';
                    bingoCard[22] = 'x';
                    bingoCard[23] = 'x';
                    bingoCard[24] = 'x';
                    break;
                case 7:
                    bingoCard[0] = 'x';
                    bingoCard[5] = 'x';
                    bingoCard[10] = 'x';
                    bingoCard[15] = 'x';
                    bingoCard[20] = 'x';
                    break;
                case 8:
                    bingoCard[1] = 'x';
                    bingoCard[6] = 'x';
                    bingoCard[11] = 'x';
                    bingoCard[16] = 'x';
                    bingoCard[21] = 'x';
                    break;
                case 9:
                    bingoCard[2] = 'x';
                    bingoCard[7] = 'x';
                    bingoCard[12] = 'x';
                    bingoCard[17] = 'x';
                    bingoCard[22] = 'x';
                    break;
                case 10:
                    bingoCard[3] = 'x';
                    bingoCard[8] = 'x';
                    bingoCard[13] = 'x';
                    bingoCard[18] = 'x';
                    bingoCard[23] = 'x';
                    break;
                case 11:
                    bingoCard[4] = 'x';
                    bingoCard[9] = 'x';
                    bingoCard[14] = 'x';
                    bingoCard[19] = 'x';
                    bingoCard[24] = 'x';
                    break;
                case 12:
                    bingoCard[0] = 'x';
                    bingoCard[4] = 'x';
                    bingoCard[20] = 'x';
                    bingoCard[24] = 'x';
                    break;
                case 13:
                    bingoCard[0] = 'x';
                    bingoCard[6] = 'x';
                    bingoCard[12] = 'x';
                    bingoCard[18] = 'x';
                    bingoCard[24] = 'x';
                    bingoCard[4] = 'x';
                    bingoCard[8] = 'x';

                    bingoCard[16] = 'x';
                    bingoCard[20] = 'x';
                    break;
                case 14:
                    bingoCard[10] = 'x';
                    bingoCard[11] = 'x';
                    bingoCard[12] = 'x';
                    bingoCard[13] = 'x';
                    bingoCard[14] = 'x';
                    bingoCard[2] = 'x';
                    bingoCard[7] = 'x';
                    bingoCard[17] = 'x';
                    bingoCard[22] = 'x';
                    break;
            }
            printCard(bingoCard, NUM_SPACES);
            break;
            
        case 'R':
            printf("How many spaces do you want to be generated? (1-25): ");
            scanf("%d", &amountRandomGenerated);
            if ((amountRandomGenerated < 1) || (amountRandomGenerated > 25)) {
                printf("Invalid number of spaces to be generated.\n");
            }
            else {
                for (int i = 0; i < amountRandomGenerated; i++) {
                    spaceGenerated = (rand() % 25);
                    if (bingoCard[spaceGenerated] == ' ') {
                        bingoCard[spaceGenerated] = 'x';
                    }
                    else {
                        while (bingoCard[spaceGenerated] == 'x') {
                            spaceGenerated = (rand() % 25);
                        }
                        bingoCard[spaceGenerated] = 'x';
                    }
                }
                printCard(bingoCard, NUM_SPACES);
            }
            break;
            
        default:
            printf("Invalid input\n");
            break;
    }
    
    return 0;
}

void printCard (char fillIn[], int length) {
    printf("\n");
    printf("\t---------------------\n");
    printf("\t| B | I | N | G | O |\n");
    printf("\t---------------------\n");
    printf("\t| %c | %c | %c | %c | %c |\n", fillIn[0], fillIn[1], fillIn[2], fillIn[3], fillIn[4]);
    printf("\t---------------------\n");
    printf("\t| %c | %c | %c | %c | %c |\n", fillIn[5], fillIn[6], fillIn[7], fillIn[8], fillIn[9]);
    printf("\t---------------------\n");
    printf("\t| %c | %c | %c | %c | %c |\n", fillIn[10], fillIn[11], fillIn[12], fillIn[13], fillIn[14]);
    printf("\t---------------------\n");
    printf("\t| %c | %c | %c | %c | %c |\n", fillIn[15], fillIn[16], fillIn[17], fillIn[18], fillIn[19]);
    printf("\t---------------------\n");
    printf("\t| %c | %c | %c | %c | %c |\n", fillIn[20], fillIn[21], fillIn[22], fillIn[23], fillIn[24]);
    printf("\t---------------------\n");
    printf("\n");
}
