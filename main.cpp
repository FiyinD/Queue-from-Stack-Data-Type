#include <iostream>
#include <stack>


template <typename T>
class QueueClass{
private:
    std::stack<T> enqueueStack, dequeueStack;
    T frontElem;
    bool isNew;

public:
    const T queueFront() const;
    const T& queueTop() const;
    void pushElem(const T& elem);
    void popFromFront();
    bool isEmpty() const;
    int getSize() const;

    QueueClass();
};

template <typename T>
const T QueueClass<T>::queueFront() const{
    T elem;
    if(!isEmpty()){
        elem = frontElem;
    }

    return elem;
}

template <typename T>
const T& QueueClass<T>::queueTop() const{
    if(!enqueueStack.empty())
        return enqueueStack.top();
    std::cerr << "Queue is empty\n";
}

template <typename T>
void QueueClass<T>::pushElem(const T& elem){
    if(isNew)
        frontElem = elem;

    enqueueStack.push(elem);
    isNew = false;
}

template <typename T>
void QueueClass<T>::popFromFront(){
    if(!enqueueStack.empty()){
        while(!enqueueStack.empty()){
            dequeueStack.push(enqueueStack.top());
            enqueueStack.pop();
        }

        dequeueStack.pop();
        if(!dequeueStack.empty())
            frontElem = dequeueStack.top();

        while(!dequeueStack.empty()){
            enqueueStack.push(dequeueStack.top());
            dequeueStack.pop();
        }
    }
}

template <typename T>
bool QueueClass<T>::isEmpty() const{
    return (dequeueStack.size() + enqueueStack.size()) == 0;
}

template <typename T>
int QueueClass<T>::getSize() const{
    return dequeueStack.size() + enqueueStack.size();
}

template <typename T>
QueueClass<T>::QueueClass(): isNew(true) {

}

int main()
{

    QueueClass<int> myQueue;

    for(int i = 1;i < 12;i++){
        myQueue.pushElem(i);
    }

    while(!myQueue.isEmpty()){
        int frontElem = myQueue.queueFront();
        std::cout << frontElem << " ";
        myQueue.popFromFront();
    }

    std::cout << "\n";

    for(int i = 11;i < 23;i++){
        myQueue.pushElem(i);
    }

    while(!myQueue.isEmpty()){
        int frontElem = myQueue.queueFront();
        std::cout << frontElem << " ";
        myQueue.popFromFront();
    }

    std::cout << "\n";

    return 0;
}
