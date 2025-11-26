#include <iostream>
#include <queue>
using namespace std;

queue<int> unionQueues(queue<int> q1, queue<int> q2) {
    queue<int> result;
    while (!q1.empty()) {
        result.push(q1.front());
        q1.pop();
    }
    while (!q2.empty()) {
        result.push(q2.front());
        q2.pop();
    }
    return result;
}
