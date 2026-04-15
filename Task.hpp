#ifndef TASK_HPP
#define TASK_HPP
#include <string>
#include <iostream>
#include <vector>

class Task {
    private:
        std::string description;
        bool completed;


    public:
        Task(std::string desc){
            description = desc;
            completed = false;
        }
        void markCompleted();
        std::string getTask();
        bool isCompleted();
};

class TaskManager{
    private:
        std::vector <Task> tasks;
    public:
        void addTask(std::string desc);
        void viewTasks();
        void markTaskCompleted(int index);
        void resetTasks();
        void saveToFile();
        void loadFromFile();

};
#endif // TASK_HPP
