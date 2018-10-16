#include <iostream>
#include <stack>


template <typename T>
class QueueClass{
private:
    std::stack<T> enqueueStack, dequeueStack;   //two stacks used to implement the queue
    T frontElem;                                //item in front of the queue

public:
    const T queueFront() const;                 //returns the item in front of the queue
    const T queueTop() const;                   //returns the top of the queue
    void pushElem(const T& elem);               //adds an item to the queue
    void popFromFront();                        //removes the front item from the front of the queue
    bool isEmpty() const;                       //checks if the queue is empty
    int getSize() const;                        //returns the size of the queue... i.e the number of items in the queue

    QueueClass();                               //constructor
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
const T QueueClass<T>::queueTop() const{
    if(!enqueueStack.empty())
        return enqueueStack.top();
    std::cerr << "Queue is empty\n";
}

template <typename T>
void QueueClass<T>::pushElem(const T& elem){
    if(isEmpty)
        frontElem = elem;

    enqueueStack.push(elem);
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
QueueClass<T>::QueueClass() {

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
