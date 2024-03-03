#include <iostream>
#include <vector>

using namespace std;

struct Task {
    string title;
    string description;
    bool is_completed{};
};

Task create_task(string &title, string &description) {
    Task task;
    task.title = title;
    task.description = description;
    task.is_completed = false;
    return task;
}

void end_task(vector<Task> &tasks, int task_index) {
    if (task_index >= 0 && tasks.size() > task_index) {
        cout << "SUCCESSFULLY: You have ended the task by index: " << task_index << endl;
        tasks[task_index].is_completed = true;
    } else {
        cout << "ERROR: You have entered an invalid index!" << endl;
    }
}

void delete_task(vector<Task> &tasks, int task_index) {
    if (task_index >= 0 && tasks.size() > task_index) {
        cout << "SUCCESSFULLY: You have deleted the task by index: " << task_index << endl;
        tasks.erase(tasks.begin() + task_index);
    } else {
        cout << "ERROR: You have entered an invalid index!" << endl;
    }
}

void display_info_about_tasks(vector<Task> tasks) {
    cout << "====================================" << endl;
    if (tasks.empty()) {
        cout << "ERROR: tasks list is empty!" << endl;
        return;
    }
    for (int i = 0; i < tasks.size(); i++) {
        cout << "***************************************" << endl;
        cout << "TASK BY INDEX: " << i << endl;
        cout << "TITLE: " << tasks[i].title << endl;
        cout << "DESCRIPTION: " << tasks[i].description << endl;
        cout << "IS_COMPLETED: " << tasks[i].is_completed << endl;
        cout << "***************************************" << endl;
    }
    cout << "====================================" << endl;
}

int main() {
    vector<Task> tasks;

    while (true) {
        cout << "====================================" << endl;
        cout << "Welcome to Task Manager application!" << endl;
        cout << "1. Create a task - enter 1 " << endl;
        cout << "2. Delete a task - enter 2 " << endl;
        cout << "3. View tasks - enter 3 " << endl;
        cout << "4. End a task - enter 4 " << endl;
        cout << "5. Exit - enter 5" << endl;
        cout << "====================================" << endl;

        int operation;

        cin >> operation;

        cin.ignore();

        if (operation == 1) {
            string title;

            cout << "Okay, you wanna to create a task. Enter a title!" << endl;

            getline(cin, title);

            cout << "Okay. The title is: " << title << endl;

            string description;

            cout << "Enter a description!" << endl;

            getline(cin, description);

            cout << "Okay. The description is: " << description << endl;

            Task task = create_task(title, description);
            tasks.push_back(task);
            cout << "Task is successfully created!" << endl;
        }

        if (operation == 2) {
            int task_index;

            cout << "Please, enter a task index for deleting!" << endl;

            cin >> task_index;

            delete_task(tasks, task_index);
        }

        if (operation == 3) {
            display_info_about_tasks(tasks);
        }

        if (operation == 4) {
            int task_index;

            cout << "Please, enter a task index for ending!" << endl;

            cin >> task_index;

            end_task(tasks, task_index);
        }

        if (operation == 5) {
            cout << "Okay. Thank you for using and trusting our application! Bye!" << endl;
            return 0;
        }

        if (operation != 1 && operation != 2 && operation != 3 &&
            operation != 4 && operation != 5) {
            throw runtime_error("You have entered an invalid operation! Program has finished its executing!");
        }
    }

}
