/* 
 * File:   main.cpp
 * Author: Eduardo Murillo
 *
 * Created on October 23, 2023, 11:07 AM
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <list>
#include <deque>
#include <stack>
#include <set>
using namespace std;


void showdq(deque<int> g);
/*
 * 
 */
int main(int argc, char** argv) {

    int array[5] = {10,2,6,2,5};

    cout << "Original Array" << endl;
    for (int i = 0; i < 5; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    
    sort(begin(array),end(array));
    
    cout << "Sorted Array: " << endl;
    for(int i=0; i<5; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    
    reverse(begin(array), end(array));
    cout << "Sorted array after the reverse function" << endl;
    for(int i=0; i<5; i++){
        cout << array[i] << " ";
    }
    cout << endl << endl;
    
    reverse(begin(array), end(array));
    cout << "Binary Search Looking for the #10 in the array" << endl;
    if (binary_search(begin(array), end(array), 10)) {
        cout << "Element Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    cout << "Binary Search Looking for the #50 in the array" << endl;
    if (binary_search(begin(array), end(array), 50)) {
        cout << "Element Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }
    
    

    cout << "\nMaximum element of Array is: ";
    cout << *max_element(begin(array),end(array));

    cout << "\nMinimum element of Array is: ";
    cout << *min_element(begin(array), end(array));
    
    
    cout << endl << endl;
    int arr[] = {5, 10, 15, 20, 20, 23, 42, 45};
    int n = sizeof (arr) / sizeof (arr[0]);
    vector<int> vect(arr, arr + n);

    cout << "Occurrences of 20 in vector : ";


    cout << count(vect.begin(), vect.end(), 20);

    find(vect.begin(), vect.end(), 5) != vect.end() ?
            cout << "\nElement found" :
            cout << "\nElement not found";
    
    cout << endl << endl;
    cout << "Find the first and last Position of the number 20 " << endl;
    sort(vect.begin(), vect.end());

    // Returns the first occurrence of 20
    auto q = lower_bound(vect.begin(), vect.end(), 20);

    // Returns the last occurrence of 20
    auto p = upper_bound(vect.begin(), vect.end(), 20);

    cout << "The lower bound is at position: ";
    cout << q - vect.begin() << endl;

    cout << "The upper bound is at position: ";
    cout << p - vect.begin() << endl;
    
    cout << endl << endl;
    
    
    cout << "Given Vector is:\n";
    for (int i = 0; i < n; i++)
        cout << vect[i] << " ";
 
    vect.erase(find(vect.begin(),vect.end(),10));
    cout << "\nVector after erasing element #10:\n";
    for (int i = 0; i < vect.size(); i++)
        cout << vect[i] << " ";
 
    vect.erase(unique(vect.begin(), vect.end()),
               vect.end());
    cout << "\nVector after removing duplicates:\n";
    for (int i = 0; i < vect.size(); i++)
        cout << vect[i] << " ";
    cout << endl << endl;

    cout << "Given Vector is:\n";
    for (int i = 0; i < n; i++)
        cout << vect[i] << " ";

    // modifies vector to its next permutation order
    next_permutation(vect.begin(), vect.end());
    cout << "\nVector after performing next permutation:\n";
    for (int i = 0; i < n; i++)
        cout << vect[i] << " ";

    prev_permutation(vect.begin(), vect.end());
    cout << "\nVector after performing prev permutation:\n";
    for (int i = 0; i < n; i++)
        cout << vect[i] << " ";
    
    cout << endl;
    cout << "Distance between first to max element: ";
    cout << distance(vect.begin(),
            max_element(vect.begin(), vect.end()));
    
    cout << "\n-------------------------------------------------------------------" << endl;
    
    cout << "Lists" << endl;
    list<int> List{12,45,8,6};
 
    for (auto i : List) {
        cout << i << ' ';
    }
    cout << endl;
    
    cout << "Using .front: " << List.front() << endl;
    cout << "Using .back: " << List.back() << endl;
    cout << "Using .push_front(20): " << endl;
            List.push_front(20);
    for (auto i : List) {
        cout << i << ' ';
    }
    cout << endl;
    cout << "Using .push_back(10): " << endl;
    List.push_back(10);
    for (auto i : List) {
        cout << i << ' ';
    }
    cout << endl;
    
    cout << "Remove the elements added using pop_front and pop_back" << endl;
    List.pop_back();
    List.pop_front();

    for (auto i : List) {
        cout << i << ' ';
    }
    cout << endl;
    

    cout << "\n-------------------------------------------------------------------" << endl;
    
    cout << "Deque in C++ Standard Template Library" << endl;
    deque<int> gquiz;
    gquiz.push_back(10);
    gquiz.push_front(20);
    gquiz.push_back(30);
    gquiz.push_front(15);
    cout << "The deque gquiz is : ";
    showdq(gquiz);

    cout << "\ngquiz.size() : " << gquiz.size();
    cout << "\ngquiz.max_size() : " << gquiz.max_size();

    cout << "\ngquiz.at(2) : " << gquiz.at(2);
    cout << "\ngquiz.front() : " << gquiz.front();
    cout << "\ngquiz.back() : " << gquiz.back();

    cout << "\ngquiz.pop_front() : ";
    gquiz.pop_front();
    showdq(gquiz);

    cout << "\ngquiz.pop_back() : ";
    gquiz.pop_back();
    showdq(gquiz);
    
    
    

    cout << "\n-------------------------------------------------------------------" << endl;
    cout << "Queues using STL library bits/stdc++.h" << endl;
    queue<char> queue1, queue2;
    int v = 96;
    cout << "queue1 created using .push" << endl;
    for (int i = 0; i < 5; i++) {
        queue1.push(v + 1);
        v++;
    }
    cout << "queue2 created using .emplace" << endl;
    for (int i = 0; i < 4; i++) {
        queue2.emplace(v + 1);
        v++;
    }
    cout << endl;
    

    // Swap elements of queues
    queue1.swap(queue2);

    // Print the first queue
    cout << "Queue after the swap" << endl;
    cout << "queue1 = ";
    while (!queue1.empty()) {
        cout << queue1.front() << " ";
        queue1.pop();
    }

    // Print the second set
    cout << endl << "queue2 = ";
    while (!queue2.empty()) {
        cout << queue2.front() << " ";
        queue2.pop();
    }
    cout << "\n-------------------------------------------------------------------" << endl;
    cout << "Stacks using STL library Stack" << endl;
    
    stack<int> stack;
    stack.push(21);// The values pushed in the stack should be of the same data which is written during declaration of stack
    stack.push(22);
    stack.push(24);
    stack.push(25);
    int num=0;

   
    while (!stack.empty()) {
        cout << stack.top() <<" ";
        stack.pop();
    }
    
    
    
    cout << "\n-------------------------------------------------------------------" << endl;
    cout << "Sets using STL library <set>" << endl;
    std::set<char, greater<char> > a;
    a.insert('A');
    a.insert('F');
    a.insert('E');
    a.insert('S');
    for (auto& str : a) {
        std::cout << str << ' ';
    }
    std::cout << '\n';
    

    cout << "\n-------------------------------------------------------------------" << endl;
    cout << "Maps using STL library <map>" << endl;
    
    cout << "Maps let you correlate values and names in one index map['one'] = 1 p.s:values are stored in alphabetical order" << endl;

    std::map<std::string, int> map;

    // Insert some values into the map
    map["one"] = 1;
    map["two"] = 2;
    map["three"] = 3;

    // Get an iterator pointing to the first element in the map
    std::map<std::string, int>::iterator it = map.begin();
    std::cout << "Size of map: " << map.size() << std::endl;

    // Iterate through the map and print the elements
    while (it != map.end()) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
        ++it;
    }
    

    cout << "\n-------------------------------------------------------------------" << endl;
    cout << "Pair in C++ Standard Template Library" << endl;

    // defining a pair
    pair<int, char> PAIR1;

    // first part of the pair
    PAIR1.first = 100;
    // second part of the pair
    PAIR1.second = 'G';

    cout << PAIR1.first << " ";
    cout << PAIR1.second << endl;
    
    return 0;
}

void showdq(deque<int> g)
{
    deque<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}