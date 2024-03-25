#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template<typename T, typename F>
class List
{
public:
    List();
    ~List();

    void push_back(T data, F word);
    int getsize() { return size; }

    /* T& operator[](const int index);*/

private:
    template<typename T, typename F>
    class Node
    {
    public:
        Node* pNext;
        T data;
        F word;
        Node(T data = T(), F word = F(""), Node* pNext = nullptr)
        {
            this->word = word;
            this->data = data;
            this->pNext = pNext;
        }
    };
    int size;
    Node<T, F>* head;
};


template<typename T, typename F>
List<T, F>::List()
{
    size = 0;
    head = nullptr;
}


template<typename T, typename F>
List<T, F>::~List()
{

}

template<typename T, typename F>
void List<T, F>::push_back(T data, F word)
{
    if (head == nullptr)
    {
        head = new Node<T, F>(data, word);
    }
    else
    {
        Node <T, F>* current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T, F>(data, word);
    }
    size++;
}

//template<typename T, typename F>
//T& List<T,F>::operator[](const int index)
//{
//    int counter = 0;
//    Node <T,F> *current = this->head;
//
//    while (current != nullptr)
//    {
//        if (counter == index)
//        {
//            return current->data, current->word;
//        }
//        current = current->pNext;
//        counter++;
//    }
//}

int main()
{
    setlocale(LC_ALL, "ru");

    List <int, std::string> lst;
    lst.push_back(5, hi);
    lst.push_back(10, hi);
    lst.push_back(22, hi);

    /*std::string  number;
    std::cin >> number;
    if()
    for (int i=0;i<number;i++)
    {
        lst.push_back(rand() % 10);
    }*/

    for (int i = 0; i < lst.getsize(); i++)
    {
        std::cout << lst[i] << std::endl;

    }


    return 0;
}

