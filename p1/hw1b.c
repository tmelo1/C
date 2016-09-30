/*
Homework 1, 600.120 Spring 2015
Tony Melo
2/11/16
tmelo1@jhu.edu
tmelo1
(201)956-2503
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 2500
#define SIZE 3
void getCourseString(unsigned int courseInt, char course[]);
 
int main(int argc, const char* argv[]) {
    if(argc == 1) {
        puts("Error, please input file name.");
        return 1;
    }
    char menu_option;
    FILE* infile = fopen(argv[1], "r");
    if(infile == NULL) {
        puts("Error reading file.");
        return 2;
    }
    int numLines = 0;
    float totalQualityPoints = 0;
    float totalGPA = 0;
    float qualityPoints = 0;
    float numCredits = 0;
    char grade_spec[SIZE];
    int depNum = 0;
    float totalCredits = 0;
    unsigned int courseArray[MAX_LINES] = {0};
    for(int i = 0; i < MAX_LINES; i++) {
        fscanf(infile, "%u", &courseArray[i]);
        if(courseArray[i] != 0) {
           numLines++;
        }
    } 
    char course_string[16];
    while(menu_option != 'q' || menu_option != 'Q') {
        puts("Please enter an option from the menu below: \n");
        puts("-------------------------------------------\n");
        puts("n - display the total numer of courses available \n");
        puts("d - display all courses from a particular department\n");
        puts("l - list all courses with a particular letter grade\n");
        puts("c - list all courses with at least a specified number of credits\n");
        puts("g - compute the GPA of all the courses with letter grades\n");
        puts("q - quit the program\n");
        puts("Please enter your choice ---> \n");
        scanf(" %c", &menu_option);
        switch(menu_option) {
            case 'n': case 'N':
                printf("There are currently %d courses available.\n", numLines);
                break;
            case 'd': case 'D':
                puts("Please enter a department number between 0-999 to search for: ");
                scanf("%d", &depNum);
                puts("Courses found: ");
                for(int i = 0; i < numLines; i++) {
                    getCourseString(courseArray[i], course_string);
                    unsigned int depMask = depNum << 19;
                    if((courseArray[i] & depMask) == depMask) {
                        printf("%s",course_string);
                        puts("\n");
                    }
                }
                break; 
            case 'l': case 'L':
                puts("Please enter the letter grade to search for (please specify +,-, or / for neither): ");
                scanf("%s", grade_spec);
                puts("Courses found: "); 
                for(int i = 0; i < MAX_LINES; i++) {
                    getCourseString(courseArray[i], course_string);
                    if(courseArray[i] != 0) {
                        if(course_string[10] == grade_spec[0] && course_string[11] == grade_spec[1]) {
                            printf("%s",course_string);
                            puts("\n");
                        }
                   }
                }
                break;
            case 'c': case 'C':
                puts("Please enter the number of credits to compare to:"); 
                scanf("%f", &numCredits);
                puts("Courses found:\n ");
                for(int i = 0; i < MAX_LINES; i++) {
                    getCourseString(courseArray[i], course_string);
                    float classCredit = (course_string[12] - '0')/1.0 + ((course_string[14] - '0')/10.0);
                    if(classCredit >= numCredits) {
                        printf("%s", course_string);
                        puts("\n");
                    }
                }
                break;
            case 'g': case 'G':
                puts("Calculating GPA....\n");
                for(int i = 0; i < MAX_LINES; i++) {
                    getCourseString(courseArray[i], course_string);
                    float classCredit = (course_string[12] - '0') + ((course_string[14] - '0')/10.0);
                    if(courseArray[i] != 0) {
                    switch(course_string[10]) {
                        case 'A':
                            if(course_string[11] == '+' || course_string[12] == '/')
                                qualityPoints = 4.0;
                            else
                                qualityPoints = 3.7;
                            break;
                        case 'B':
                            if(course_string[11] == '+')
                                qualityPoints = 3.3;
                            else if(course_string[11] == '-')
                                qualityPoints = 3.0;
                            else
                                qualityPoints = 2.7;
                            break;
                        case 'C':
                            if(course_string[11] == '+')
                                qualityPoints = 2.3;
                            else if(course_string[11] == '-')
                                qualityPoints = 2.0;
                            else
                                qualityPoints = 1.7;
                            break;
                        case 'D':
                            if(course_string[11] == '+')
                                qualityPoints = 1.3;
                            else if(course_string[11] == '-')
                                qualityPoints = 1.0;
                            else
                                qualityPoints = 0.7;
                            break;
                        case 'F':
                            qualityPoints = 0.0;
                            break;
                    }
                    totalCredits += classCredit;
                    totalQualityPoints += classCredit * qualityPoints;
                    }
                }
                totalGPA = totalQualityPoints/totalCredits;
                printf("The total GPA calculated is: %.2f \n", totalGPA);
                break;
            case 'q': case 'Q':
                puts("Exiting now.");
                return 0;
        } 
    }
    fclose(infile);
    return 0;
}


void getCourseString(unsigned int courseInt, char course[]) {
    int courseNum;
    int department;
    int division;
    int leftCredit;
    int rightCredit;
    int letterGrade;
    int gradeSign;
    int tenBitMask = 1023;
    int threeBitMask = 7;
    int oneBitMask = 1;
    int twoBitMask = 3;
    division = (courseInt >> 29) & threeBitMask;
    department = (courseInt >> 19) & tenBitMask;
    courseNum = (courseInt >> 9) & tenBitMask;
    letterGrade = (courseInt >> 6) & threeBitMask;
    gradeSign = (courseInt >> 4) & twoBitMask;
    leftCredit = (courseInt >> 1) & threeBitMask;
    rightCredit = courseInt & oneBitMask;
    switch(division) {
        case 0:
            course[0] = 'A';
            course[1] = 'S';
            break;
        case 1:
            course[0] = 'B';
            course[1] = 'U';
            break;
        case 2:
            course[0] = 'E';
            course[1] = 'D';
            break;
        case 3:
            course[0] = 'E';
            course[1] = 'N';
            break;
        case 4:
            course[0] = 'M';
            course[1] = 'E';
            break;
        case 5:
            course[0] = 'P';
            course[1] = 'H';
            break;
        case 6:
            course[0] = 'P';
            course[1] = 'Y';
            break;
        case 7:
            course[0] = 'S';
            course[1] = 'A';
            break;
    }
    course[2] = '.';

    if(department >= 100) {
        course[3] = department/100 + '0';
        course[4] = (department/10)%10 + '0';
        course[5] = department%10 + '0';
    } else if(department >= 10 && department < 100) {
        course[3] = '0';
        course[4] = department/10 + '0';
        course[5] = department%10 + '0';
    } else {
        course[3] = '0';
        course[4] = '0';
        course[5] = department + '0';;
    }
    course[6] = '.';

    if(courseNum >= 100) {
        course[7] = courseNum/100 + '0';
        course[8] = (courseNum/10)%10 + '0';
        course[9] = courseNum%10 + '0';
    } else if(courseNum >= 10 && courseNum < 100) {
        course[7] = '0';
        course[8] = courseNum/10 + '0';
        course[9] = courseNum%10 + '0';
    } else {
        course[7] = '0';
        course[8] = '0';
        course[9] = courseNum + '0';
    }

    switch(letterGrade) {
       case 0:
           course[10] = 'A';
           break;
       case 1:
           course[10] = 'B';
           break;
       case 2:
           course[10] = 'C';
           break;
       case 3:
           course[10] = 'D';
           break;
       case 4:
           course[10] = 'F';
           break;
       case 5:
           course[10] = 'I';
           break;
       case 6:
           course[10] = 'S';
           break;
       case 7:
           course[10] = 'U';
           break;
    }
    switch(gradeSign) {
       case 0:
           course[11] = '+';
           break;
       case 1:
           course[11] = '-';
           break;
       case 2:
           course[11] = '/';
           break;
    }
    switch(rightCredit) {
      case 0:
           course[14] = '0';
           break;
      case 1:
           course[14] = '5';
           break;
    }
    course[12] = leftCredit + '0';
    course[13] = '.';
    course[15] = '\0';
}
