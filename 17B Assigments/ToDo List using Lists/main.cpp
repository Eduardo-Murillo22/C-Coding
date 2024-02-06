#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    list<string> todoList;

    while (true) {
        cout << "To-Do List Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Remove Task" << endl;
        cout << "3. Display Tasks" << endl;
        cout << "4. Quit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter the task: ";
                string task;
                cin.ignore();
                getline(cin, task);
                todoList.push_back(task);
                cout << "Task added!" << endl;
                break;
            }

            case 2: {
                if (!todoList.empty()) {
                    cout << "Tasks:" << endl;
                    int index = 1;
                    for (const string& item : todoList) {
                        cout << index << ". " << item << endl;
                        index++;
                    }

                    cout << "Enter the task number to remove: ";
                    int taskNumber;
                    cin >> taskNumber;

                    if (taskNumber >= 1 && taskNumber <= todoList.size()) {
                        auto it = todoList.begin();
                        advance(it, taskNumber - 1);
                        todoList.erase(it);
                        cout << "Task removed!" << endl;
                    } else {
                        cout << "Invalid task number. No task removed." << endl;
                    }
                } else {
                    cout << "No tasks to remove." << endl;
                }
                break;
            }

            case 3: {
                if (!todoList.empty()) {
                    cout << "Tasks:" << endl;
                    int index = 1;
                    for (const string& item : todoList) {
                        cout << index << ". " << item << endl;
                        index++;
                    }
                } else {
                    cout << "No tasks to display." << endl;
                }
                break;
            }

            case 4:
                cout << "Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
