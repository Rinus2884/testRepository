/*
    STL container

    동작명세가 정해져 있는 자료구조

    stack: LIFO, Last Input First Output
    queue: FIFO, First Input First Output

*/
#include <iostream>
#include <stack>//stack container를 사용하기 위해 포함
#include <queue>//queue container를 사용하기 위해 포함
using namespace std;

int main()
{

    //stack
    stack<int> tStack;
    //stack<int>::iterator
    //<--스택은 LIFO로 동작명세가 정해져있다. 즉, 순회는 안됨
    //   그러므로, iterator는 정의되어 있지 않다.

    tStack.push(3);
    tStack.push(2);
    tStack.push(1);
    tStack.push(777);

    //스택에 원소가 하나라도 있다면
    while (!tStack.empty())
    {
        int t = tStack.top();//맨 위의 원소의 값을 얻는다.
        cout << t << endl;

        tStack.pop();
    }



    //queue
    cout << endl << endl;

    queue<int> tQueue;
    //queue<int>::iterator
    //<--큐는 FIFO로 동작명세가 정해져있다. 즉, 순회는 안됨
    //   그러므로, iterator는 정의되어 있지 않다.

    tQueue.push(3);
    tQueue.push(2);
    tQueue.push(1);
    tQueue.push(777);

    //큐에 원소가 하나라도 있다면
    while (!tQueue.empty())
    {
        int t = tQueue.front();//맨 앞의 원소의 값을 얻는다.
        cout << t << endl;

        tQueue.pop();
    }


    return 0;
}

