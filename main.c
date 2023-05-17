#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task1.h"
#include "task2.h"

    //argv[0] - Executabil
    //argv[1] - c.in
    //argv[2] - d.in
    //argv[3] - r.out

int main (int argc, char *argv[]) {

    int *taskType = (int *)malloc(5 * sizeof(int));
    //FILE *fileTypeTask = fopen("c.txt", "r");
    //FILE *fileWrite = fopen("r.txt", "w");

    FILE *fileTypeTask = fopen(argv[1], "r");
    FILE *fileWrite = fopen(argv[3], "w");

    for (int i = 0; i < 5; i++) {
        fscanf(fileTypeTask, "%d", &taskType[i]);
    }
    int numberTeams;
    team *allTeams = NULL;

    if (taskType[0]) {
        //FILE *fileReadValues = fopen("d.txt", "r");
        FILE *fileReadValues = fopen(argv[2], "r");
        task1(fileReadValues, fileWrite, &numberTeams, &allTeams);
    }
    if (taskType[1]) {
        task2(fileWrite, &numberTeams, &allTeams);
    }
    if (taskType[2]) {
        int x = 2;
    }
    if (taskType[3]) {
        int x = 1;
    }
    if (taskType[4]) {
        int x = 0;
    }
    writeTeams(fileWrite, &allTeams);
    // Functie care goleste toate listele + inchide fisierele
    fclose(fileTypeTask);
    fclose(fileWrite);
    free(taskType);
    return 0;   
}