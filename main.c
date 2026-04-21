/*
Name: MATOVU ABDRHAMAN
Registration Number: 25/U/BIE/01392/PE
*/

#include <stdio.h>

int main(void) {
    /* Declare variables here */
int score;

int unit[16] = {4,3,3,3,3,3,3,2,4,3,3,3,3,3,3,2};
float gradePoint[] = {5,4,3,2,0};

    float semester1Total = 0, semester2Total = 0;
    int semester1Units = 0, semester2Units = 0;
    char* courseCode[] = {
        "TEMB 1101","TEMB 1102","TEMB 1103","TEMB 1104",
        "TEMB 1105","TEMB 1106","TEMB 1107","TEMB 1108",
        "TEMB 1201","TEMB 1202","TEMB 1203","TEMB 1204",
        "TEMB 1205","TEMB 1206","TEMB 1207","TEMB 1208"
    };


    /* Read 16 scores */
    for(int i = 0; i < 16; i++){
        printf("Enter score for %s: ", courseCode[i]);
        scanf("%d", &score);

        if (score < 0 || score > 100){
            printf("Invalid score, try again\n");
            i--;
            continue;
        }

        char grade;
        float point = getPoint(score, &grade);
        float weighted = point * unit[i];

        if (i < 8){
            semester1Total += weighted;
            semester1Units += unit[i];
        } else {
            semester2Total += weighted;
            semester2Units += unit[i];
        }

        printf("%s \t Score: %d \t Grade: %c \t GP: %.1f \t Unit: %d \t Weighted: %.1f\n",
               courseCode[i], score, grade, point, unit[i], weighted);
    

    /* Validate input */
 if (score < 0 || score > 100){
            printf("Invalid score, try again\n");
            i--;
            continue;
        }

    /* Determine grades and grade points */
float getPoint(int score, char *grade){
    if (score >= 80){
        *grade = 'A';
        return 5;
    }
    else if (score >= 70){
        *grade = 'B';
        return 4;
    }
    else if (score >= 60){
        *grade = 'C';
        return 3;
    }
    else if (score >= 50){
        *grade = 'D';
        return 2;
    }
    else{
        *grade = 'F';
        return 0;
    }
}

    /* Compute Semester I GPA */
 float semester1Gpa = semester1Total / semester1Units;
    /* Compute Semester II GPA */
float semester2Gpa = semester2Total / semester2Units;
    /* Compute CGPA */
 float cgpa = (semester1Total + semester2Total) /
                 (semester1Units + semester2Units);
    /* Determine classification */

    /* Display full academic report */
 printf("\nSemester 1 GPA: %.2f\n", semester1Gpa);
    printf("Semester 2 GPA: %.2f\n", semester2Gpa);
    printf("CGPA: %.2f\n", cgpa);

    printf("Classification: ");
    classification(cgpa);

    return 0;
}
}
