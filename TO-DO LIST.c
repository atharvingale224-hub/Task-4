#include <stdio.h>
#include <string.h>

#define MAX_TASKS 50
#define TASK_LEN 100

char tasks[MAX_TASKS][TASK_LEN];
int status[MAX_TASKS];
int taskCount = 0;

void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Task list is full.\n");
        return;
    }

    printf("Enter task: ");
    getchar();
    fgets(tasks[taskCount], TASK_LEN, stdin);
    tasks[taskCount][strcspn(tasks[taskCount], "\n")] = '\0';
    status[taskCount] = 0;
    taskCount++;

    printf("Task added successfully.\n");
}

void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("\n--- TO-DO LIST ---\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s [%s]\n", i + 1, tasks[i],
               status[i] ? "Completed" : "Pending");
    }
}

void markCompleted() {
    int choice;
    viewTasks();

    printf("Enter task number to mark as completed: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > taskCount) {
        printf("Invalid task number.\n");
        return;
    }

    status[choice - 1] = 1;
    printf("Task marked as completed.\n");
}

void removeTask() {
    int choice;
    viewTasks();

    printf("Enter task number to delete: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > taskCount) {
        printf("Invalid task number.\n");
        return;
    }

    for (int i = choice - 1; i < taskCount - 1; i++) {
        strcpy(tasks[i], tasks[i + 1]);
        status[i] = status[i + 1];
    }

    taskCount--;
    printf("Task deleted successfully.\n");
}

int main() {
    int option;

    do {
        printf("\n==== TO-DO LIST MANAGER ====\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Remove Task\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (option != 5);

    return 0;
}
