#include <iostream>
#include "Task.hpp"

int main() {
    bool running = true;

    TaskManager manager;
    manager.loadFromFile();
    while (running) {
        std::cout << "CLI ToDo App" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Reset Tasks" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        if (choice == 1){
            std::cout << std::endl;
            std::cout << "Enter task description: ";
            std::string desc;
            std::cin.ignore(); 
            std::getline(std::cin, desc);
            manager.addTask(desc);
            std::cout << std::endl;
        } else if (choice == 2){
            std::cout << std::endl;
            manager.viewTasks();
            std::cout << "Do you want to mark any task as completed? (y/n): ";
            char markChoice;
            std::cin >> markChoice;
            if (markChoice == 'y' || markChoice == 'Y') {
                std::cout << "Enter the task number to mark as completed: ";
                int taskNum;
                std::cin >> taskNum;
                manager.markTaskCompleted(taskNum - 1);
                std::cout << std::endl;
            }
        } else if (choice == 3){
            manager.resetTasks();
        } else if (choice == 4){
            manager.saveToFile();
            running = false;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
    return 0;
}