/* Name: Mariah Schon
Class: 2240-001
Program 1
Due: September 13, 2016
Honor Pledge: On my honor as a student of the University
of Nebraska at Omaha, I have neither given nor received
unauthorized help on this homework assignment.

Name: Mariah Schon
NUID: 581
Email: mschon@unomaha.edu
Partners: Tutor at CSLC

This program is a randomized quiz. The user is asked the amount of questions, along with a difficulty level which is harder as they get closer to 4. The quiz randomly generates numbers and operations, it then tells has the user answer each problem and notifies them if it was correct or incorrect. */


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int genQuestion(int);
int answerQuestion(int);
void response(int);
int operationPicker(int, int, int);

int ans;
int indicator;
int correct=0;

int main(void){
        int qNum = 0;
        int diffLevel = 0; 
        int i;
        int mainAnswer;
        
        srand(time(NULL));     
             
    /*Make sure it's within 1-20*/
        while(qNum < 1 || qNum > 20){
            printf("How many questions for this quiz? (1-20): ");      
            scanf("%d", &qNum);
        }
       
   /*Make sure it's within 1-4*/
        while(diffLevel < 1 || diffLevel > 4){ 
            printf("Select difficulty (1-4): ");
            scanf("%d", &diffLevel);
        }

    /*Function Calls for every question*/
        for (i=1; i <= qNum; i++){
            mainAnswer= genQuestion(diffLevel);
            answerQuestion(mainAnswer);
        }
        printf("Your score was %d out of %d\n", correct, qNum);

    return 1;
}

/*
Function Name: genQuestion
Parameters:     Difficulty level of questions
Return Value(s): The answer to each question
Partners: Tutor at CSLC
Description:    This function generates each question from a randomized set of numbers, then calls another function to randomize possible operators. 
*/

int genQuestion(int difficulty){

    /*Initializing function variables and setting them equal to a value that will not appear when they are handled*/
        int num1 = 0;
        int num2 = 0;
        int opPick = -1;

/*Handles case by case based on difficulty level*/
        switch (difficulty){

            case 1:
            /*Generates a random number from 1 to 10*/
                num1 = (rand()%10) + 1;
                num2 = (rand()%10) + 1;

            /*Generates a random number to base opertation off of*/
                opPick = rand()%4;

               operationPicker(num1, num2, opPick);
               break;

            case 2:
            /*Generates a random number from 1 to 50*/
               num1 = (rand()%50) + 1;
               num2 = (rand()%50) + 1;

            /*Generates a random number to base operation off of*/
               opPick = rand()%4;

               operationPicker(num1, num2, opPick);
               break;

            case 3:
            /*Generates a random number from 1 to 100*/
               num1 = (rand()%100) + 1;
               num2 = (rand()%100) + 1;

            /*Generates a random number to base operation off of*/
               opPick = rand()%4;

               operationPicker(num1, num2, opPick);
               break;

            case 4:
            /*Generates a random number from -100 to 100*/
               num1 = (rand()%200) - 100;
               num2 = (rand()%200) - 100;

            /*Generates a random number to base operation off of*/
               opPick = rand()%4;

               operationPicker(num1, num2, opPick);
               break;
        }

        return ans;
}
/*Function Name: operationPicker
Parameters: Both numbers from the problem and the random number generated in genQuestion
Return Value(s): The answer to each equation
Partners: Tutor at CSLC
Description: This function accepts a random number from 0-3, and from that number it choses whether to use addition, subtraction, mulitplication, or division between the numbers. It finds the answer to each problem.*/


int operationPicker(int n1, int n2, int pick){
            /*Print equation and finds answer*/

            /*Addition*/
                if(pick == 0){
                    printf("%d + %d\n", n1, n2);
                    ans = n1 + n2;
                }

            /*Subtraction*/
                if(pick == 1){
                    printf("%d - %d\n", n1, n2);
                    ans = n1 - n2;
                }

            /*Multiplication*/
                if(pick == 2){
                    printf("%d * %d\n", n1, n2);
                    ans = n1 * n2;
                }

            /*Division*/
                if(pick == 3){
                    printf("%d / %d\n", n1, n2);
                    ans = n1 / n2;
                }

            /*Returns the answer to use in answerQuestion()*/
                return ans;

}
/*
Function Name: answerQuestion
Parameters: The answer to each problem
Return value(s): An indicator as to whether the user was correct, or not.
Partners: Tutor at CSLC
Description: This function prompts the user to answer the question. It then takes that input and compares to the answer to see if they were right or wrong.*/


int answerQuestion(int a){
                int input;
                    /*indicator*/

            /*Prompt user to type in their answer (input)*/
                printf("Enter Answer: ");

                scanf("%d", &input);

            /*Checks to see if answer was correct, indicates whether it was (1) or not (0)*/
                if (a == input)
                    indicator = 1;
                else
                    indicator = 0;

                response(indicator);

                return indicator;
}
/*
Function Name: response
Parameters: The indicator from answerQuestion (1 or 0)
Return Value(s): None
Partners: Tutor at CSLC
Description: This function randomizes a reaction to the users answer; three options for right and three for wrong.*/
void response(int ind){
                int ran;

    /*If it was correct, say one of three responses*/

            /*Generates random number to pick which response*/
                ran = rand()%3;

            /*If it was correct*/
                if(ind == 1){
                    if(ran == 0)
                        printf("Good Job!\n");
                    if(ran == 1)
                        printf("You did it!\n");
                    if(ran == 2)
                        printf("Way to go!\n");

            /*Keeps score*/
                    correct++;
                }

            /*If it was wrong*/
                else{
                    if(ran == 0)
                        printf("Oops!\n");
                    if(ran == 1)
                        printf("Not quite!\n");
                    if(ran == 2)
                        printf("Sorry!\n");

                    printf("The correct answer was %d \n", ans);
                }
}
                          
