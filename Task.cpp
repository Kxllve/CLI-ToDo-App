#include "Task.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>


std::string Task::getTask() {
    return description;
}
bool Task::isCompleted() {
    return completed;
}
void Task::markCompleted() {
    completed = true;
    std::cout << "Task '" << description << "' marked as completed." << std::endl;
}
void TaskManager::addTask(std::string desc) {
    Task newTask(desc);
    tasks.push_back(newTask);
    std::cout << "Task added: " << desc << std::endl;
}
void TaskManager::viewTasks() {
    std::cout << "Tasks:" << std::endl;
    for (int i = 0; i < tasks.size(); i++){
        if (tasks[i].isCompleted() == true){
            std::cout << "[X]" << i + 1 << ". " << tasks[i].getTask() << " (Completed)" << std::endl;
        } else {
            std::cout << "[ ]" << i + 1 << ". " << tasks[i].getTask() << std::endl;
        }
    }
}
void TaskManager::markTaskCompleted(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].markCompleted();
    } else {
        std::cout << "Invalid task number." << std::endl;
    }
}
void TaskManager::resetTasks() {
    tasks.clear();
    std::cout << "All tasks have been reset." << std::endl;
}
void TaskManager::saveToFile(){
    std::ofstream outFile("Tasks.txt");
    if (outFile.is_open()){
        for (int i = 0; i < tasks.size(); i++) {
            outFile << tasks[i].getTask() << "|" << tasks[i].isCompleted() << std::endl;
        }
        outFile.close();
    }
}
void TaskManager::loadFromFile(){
    std::ifstream inFile("Tasks.txt");
    if (inFile.is_open()){
           std::string line;
           while (std::getline(inFile, line)){
            size_t pipePos = line.find("|");
            std::string desc = line.substr(0, pipePos);
            Task newTask(desc);
            if (line.substr(pipePos + 1) == "1"){
                newTask.markCompleted();
            }
            tasks.push_back(newTask);

           }
        inFile.close();
    }
}