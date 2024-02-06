#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    vector<int> numbers;

    while (true) {
        cout << "Vector Algorithms Menu:" << endl;
        cout << "1. Add Number" << endl;
        cout << "2. Find Maximum" << endl;
        cout << "3. Find Minimum" << endl;
        cout << "4. Calculate Sum" << endl;
        cout << "5. Calculate Average" << endl;
        cout << "6. Quit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter a number: ";
                int number;
                cin >> number;
                numbers.push_back(number);
                cout << "Number added!" << endl;
                break;
            }

            case 2: {
                if (!numbers.empty()) {
                    int maxNum = *max_element(numbers.begin(), numbers.end());
                    cout << "Maximum number: " << maxNum << endl;
                } else {
                    cout << "Vector is empty." << endl;
                }
                break;
            }

            case 3: {
                if (!numbers.empty()) {
                    int minNum = *min_element(numbers.begin(), numbers.end());
                    cout << "Minimum number: " << minNum << endl;
                } else {
                    cout << "Vector is empty." << endl;
                }
                break;
            }

            case 4: {
                if (!numbers.empty()) {
                    int sum = accumulate(numbers.begin(), numbers.end(), 0);
                    cout << "Sum of numbers: " << sum << endl;
                } else {
                    cout << "Vector is empty." << endl;
                }
                break;
            }

            case 5: {
                if (!numbers.empty()) {
                    double average = static_cast<double>(accumulate(numbers.begin(), numbers.end(), 0)) / numbers.size();
                    cout << "Average of numbers: " << average << endl;
                } else {
                    cout << "Vector is empty." << endl;
                }
                break;
            }

            case 6:
                cout << "Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
