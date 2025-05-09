#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int>& q) {
    if (q.empty()) return;
    int x = q.front();
    q.pop();
    reverseQueue(q);
    q.push(x);
}

void printQueue(queue<int> q) {
    cout << "[ ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "]\n";
}

bool isPalindromeQueue(queue<int> q) {
    queue<int> rev = q;
    reverseQueue(rev);
    while (!q.empty()) {
        if (q.front() != rev.front())
            return false;
        q.pop();
        rev.pop();
    }
    return true;
}

bool isPalindromeStack(queue<int> q) {
    stack<int> s;
    queue<int> copy = q;
    while (!copy.empty()) {
        s.push(copy.front());
        copy.pop();
    }
    while (!q.empty()) {
        if (q.front() != s.top())
            return false;
        q.pop();
        s.pop();
    }
    return true;
}

int main() {
    queue<int> q1;
    for (int x : {1, 2, 3, 4, 5})
        q1.push(x);

    cout << "Original queue: ";
    printQueue(q1);

    reverseQueue(q1);
    cout << "Reversed queue: ";
    printQueue(q1);

    cout << "\n";

    queue<int> q2;
    for (int x : {1, 2, 3, 2, 1})
        q2.push(x);
    cout << "Queue ";
    printQueue(q2);
    cout << "isPalindromeQueue? "
         << (isPalindromeQueue(q2) ? "YES\n" : "NO\n");

    queue<int> q3;
    for (int x : {1, 2, 3, 4, 5})
        q3.push(x);
    cout << "Queue ";
    printQueue(q3);
    cout << "isPalindromeQueue? "
         << (isPalindromeQueue(q3) ? "YES\n" : "NO\n");

    cout << "\n";

    queue<int> q4;
    for (int x : {7, 8, 8, 7})
        q4.push(x);
    cout << "Queue ";
    printQueue(q4);
    cout << "isPalindromeStack? "
         << (isPalindromeStack(q4) ? "YES\n" : "NO\n");

    return 0;
}
