#include <iostream>
#include <memory>
#include <ostream>
#include <stdexcept>
#include <string>
#include "stack.hpp"
#include "stackItem.hpp"

using namespace std;

int main(void){

    unique_ptr<Stack<string>> stack = make_unique<Stack<string>>();
    StackItem<string> * item = nullptr;

    unique_ptr<Stack<int>> stack2 = make_unique<Stack<int>>();
    StackItem<int> * item2 = nullptr;

    try {

        stack2->push(new StackItem<int>(4));
        stack2->push(new StackItem<int>(43));

        stack->push(new StackItem<string>("hitallo"));
        stack->push(new StackItem<string>("azevedo"));

        item = stack->pop();
        cout << item->getValue() << endl;

        item2 = stack2->pop();
        cout << item2->getValue() << endl;

        item = stack->pop();
        cout << item->getValue() << endl;

        item2 = stack2->pop();
        cout << item2->getValue() << endl;


    } catch (invalid_argument& ex){
        cout << "erro: " << ex.what() << endl;
    } catch (underflow_error& e){
        cout << "erro: " << e.what() << endl;
    }

    return (0);
}
