#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

int tavan2(int times)
{
    if (times <= 1)
    {
        return 2;
    }
    else
    {
        return 2 * tavan2(times - 1);
    }
}

int node_ver_count(int num)
{
    int tavan = 1;
    while (num / 2)
    {
        num /= 2;
        tavan++;
    }
    return tavan;
}

template <typename T>
class Node
{
private:
    T data;
    Node *Befor;
    Node *Left;
    Node *Right;

public:
    Node(T temp)
    {
        data = temp;
        Befor = nullptr;
        Left = nullptr;
        Right = nullptr;
    }
    Node(T temp, Node *befor)
    {
        data = temp;
        Befor = befor;
        Left = nullptr;
        Right = nullptr;
    }
    void set_data(T temp)
    {
        data = temp;
        return;
    }
    void set_R(Node *R)
    {
        Right = R;
        return;
    }
    void set_L(Node *L)
    {
        Left = L;
        return;
    }
    Node *RAdd()
    {
        return Right;
    }
    Node *LAdd()
    {
        return Left;
    }
};

template <typename T>
class CompleteBinaryTree
{
protected:
    Node<T> *head;
    Node<T> *it;
    int Level = 1;
    int Size = 0;

public:
    CompleteBinaryTree(T temp)
    {
        head->set_data(temp);
        Size++;
    }
    Node<T>* loc(int lvl, int ln)
    {
        it = head;
    }
    void New_Node(T temp)
    {
        Size++;
        Node<T> *newNode = new Node<T>();
        last_cell(0) = newNode;
    }
    Node<T> *last_cell(Node<T> *i, int lvl)
    {
        if (lvl == Level-1)
        {
            if(i->LAdd)
            {
                if(i->RAdd)

                return i->RAdd;
            }
        }
        if (last_cell(i->LAdd, lvl + 1))
    }
};

int main()
{
    Node<string> ali("akbar");
}