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
Last login: Mon Sep 26 15:47:17 on ttys001
News-MacBook-Pro:~ User$ ssh mschon@loki.ist.unomaha.edu
systems administrator's mailing list: loki@pki.nebraska.edu
mschon@loki.ist.unomaha.edu's password: 
Welcome to loki (GNU/Linux 3.2.0-90-generic x86_64)


You have mail.
Last login: Mon Sep 26 15:47:44 2016 from ip68-13-19-155.om.om.cox.net
mschon@loki:~$ ls
0                        mutt
a.out                    MyLinkedList$1.class
cProgHelloWorld.c        MyLinkedList.class
CSCI1620-F15-PROG1       MyLinkedList.java
CSCI1620-F15-PROG2       MyLinkedList$LinkedListIterator.class
CSCI1620-F15-PROG3       MyLinkedList$Node.class
CSCI1620-F15-PROG4       S15
CSCI-2240-1-F16-A1       S15_1400_005
CSCI-2240-D-s16-A0       S15_1400_006
CSCI-2240-D-S16-A0       S15_1400_006_mschon
CSCI-2240-D-S16-A1       S15_1400_006_prog
CSCI-2240-D-S16-A2       S15_1400_006_prog0
CSCI-2240-D-S16-A3       S15_1400_006_prog1
CSCI-3320-DG-F16-A2      S15_1400_006_prog10
CSCI-3320-DG-F16-A3      S15_1400_006_prog11
CSCI-F15_AdventureBookk  S15_1400_006_prog12
CSCI-F15-PROG4           S15_1400_006_prog2
<ENTER>                  S15_1400_006_prog4
first.java               S15_1400_006_prog5
LinkedList.java          S15_1400_006_prog6
Mail                     S15_1400_006_prog7
mschon_first.java        S15_1400_006_prog8
mschon_Life.java         S15_1400_006_prog9
mschon_prog0.txt         S15_1400_prog11
mschon_second            S15_1400_prog13
mschon_second.class      sent
mschon_second.java       TestLinkedList.class
mschon@loki:~$ cd CSCI-2240-1-F16-A1/
mschon@loki:~/CSCI-2240-1-F16-A1$ ls
a.out  mathQuiz.c
mschon@loki:~/CSCI-2240-1-F16-A1$ vim mathQuiz.c 










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
