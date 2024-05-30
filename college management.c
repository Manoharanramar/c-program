#include<stdio.h>
struct Student {
    int id;
    char name[50];
    // Add more number of fields as needed
};

struct Course {
    int id;
    char name[50];
    // Add more fields as needed
};
void addStudent(struct Student students[], int *studentCount, struct Student newStudent) {
    // Add new student to the array of students
}

void displayStudents(struct Student students[], int studentCount) {
    // Display details of all students
}

// Define similar functions for courses, teachers, etc.
int main() {
    struct Student students[100];
    int studentCount = 0;

    // Main menu
    int choice;
    do {
        printf("\nCollege Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Add student
                break;
            case 2:
                // Display students
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 3);

    return 0;
}
