#include <stdio.h>

int main() {
    int all_students = 0;
    int student = 0;
    int grade = 0;
    int i;

    printf("How many students: \n");
    scanf("%d", &all_students);

    int student_grades[all_students];
    for (i = 0; i <= all_students; i++) {
        student_grades[i] = -1;
    }

    do {
        printf("Enter student number (1 - %d) or 0 to stop: \n", all_students);
        scanf("%d", &student);

        if (student == 0) {
            break;
        } else if (student > all_students) {
            printf("INVALID NUMBER\n");
        } else {
            do {
                printf("Enter grade (0 - 5) for student %d or -1 to cancel: \n", student);
                scanf("%d", &grade);

                if (grade < -1 || grade > 5) {
                    printf("INVALID GRADE\n");
                } else {
                    student_grades[student] = grade;
                }
            } while (grade < -1 || grade > 5);
        }
    } while (student != 0);

        printf("\n%-10s %-10s\n", "STUDENT", "GRADE");

        for (i = 1; i <= all_students; i++) {
            if (student_grades[i] == -1) {
                printf("%-10d %-10s\n", i, "N/A");
            } else {
                printf("%-10d %-10d\n", i, student_grades[i]);
            }
        }
        return 0;
    }