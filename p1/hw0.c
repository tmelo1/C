/* Homework 0, 600.120 Spring 2015

Tony Melo
2/4/16
Email - tmelo1@jhu.edu
Blackboard ID - tmelo1
Phone Number - (201)956-2503

*/

#include <stdio.h>
#include <string.h>

#define LENGTH 16

int main(int argc, char* argv[])
{
    char course[LENGTH];
    if (argc == 1) {
      printf("Usage: hw0 XX.###.###Gg#.#\n");
      return 1;  // exit program
    }

    strncpy(course, argv[1], LENGTH);  // copy to course string
    course[LENGTH-1] = '\0';   // make sure last character is null
    printf("course string: %s\n", course);  // echo input

    // add your code here
    int division_code = 0;
    char department[4];
    char cnumber[4];
    int j = 0;
    int h = 0;
    for(int i=3; i>2 && i<6; i++)
        department[j++] = course[i];
    for(int i=7; i>6 && i<10; i++)
        cnumber[h++] = course[i];
    int course_number;
    int department_number;
    sscanf(cnumber, "%d", &course_number);
    sscanf(department, "%d", &department_number);
    int letter_grade = 0;
    int grade_sign = 0;
    int credit_left = course[12] - '0';
    int credit_right = 0;
    switch(course[0]) {
        case 'A':
	    division_code = 0;
	    break;
	case 'B':
	    division_code = 1;
	    break;
	case 'E':
	    if(course[1] == 'D') {
		division_code = 2;
		break;
	    } else {
		division_code = 3;
		break;
	    }
	case 'M':
	    division_code = 4;
	    break;
	case 'P':
	    if(course[1] == 'H') {
		division_code = 5;
		break;
	    } else {
		division_code = 6;
		break;
	    }
	case 'S':
	    division_code = 7;
	    break;
    }
    switch(course[10]) {
        case 'A':
	    letter_grade = 0;
	    break;
	case 'B':
	    letter_grade = 1;
	    break;
	case 'C':
	    letter_grade = 2;
	    break;
	case 'D':
	    letter_grade = 3;
	    break;
	case 'F':
	    letter_grade = 4;
	    break;
	case 'I':
	    letter_grade = 5;
	    break;
	case 'S':
	    letter_grade = 6;
	    break;
	case 'U':
	    letter_grade = 7;
	    break;
    }
    switch(course[11]) {
        case '+':
	    grade_sign = 0;
	    break;
	case '-':
	    grade_sign = 1;
	    break;
	case '/':
	    grade_sign = 2;
	    break;
    }
    switch(course[14]) {
	case '0':
	    credit_right = 0;
	    break;
	case '5':
	    credit_right = 1;
	    break;
    }
    printf("Division: %d \n", division_code);
    printf("Department: %d \n", department_number );
    printf("Course: %d \n", course_number);
    printf("Grade: %d %d \n", letter_grade, grade_sign);
    printf("Credits: %d %d \n", credit_left, credit_right); 
  return 0;
}

