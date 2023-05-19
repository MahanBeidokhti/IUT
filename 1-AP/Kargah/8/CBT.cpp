#include <iostream>
#include <typeinfo>
#include <list>

using namespace std;

class node
{
public:
    int data;
    node *Right, *Left;

    node(int Data)
    {
        data = Data;
        Left = nullptr;
        Right = nullptr;
    }
};

class Tree
{
public:
    node *root;

    Tree()
    {
        root = nullptr;
    }

    void insert(int data)
    {

        if (!root)
        {
            root = new node(data);
            return;
        }

        list<node *> queue;

        queue.push_back(root);

        while (!queue.empty())
        {
            queue.erase(queue.begin());
            node *current = queue.front();
            if (!current->Left)
            {
                current->Left = new node(data);
                return;
            }
            if (!current->Right)
            {
                current->Right = new node(data);
                return;
            }
            queue.push_back(current->Left);
            queue.push_back(current->Right);
        }
    }

    void remove(int data)
    {
        if (!root)
        {
            throw "root is not valid!";
        }

        if (root->data == data)
        {
            root = nullptr;
            return;
        }

        list<node *> queue;
        queue.push_back(root);

        node *temp = nullptr;
        node *end = nullptr;

        while (!queue.empty())
        {
            node *This = queue.front();
            queue.erase(queue.begin());

            if (This->Left)
            {
                queue.push_back(This->Left);
                if (This->Left->data == data)
                {
                    temp = This->Left;
                    end = This;
                }
            }

            if (This->Right)
            {
                queue.push_back(This->Right);
                if (This->Right->data == data)
                {
                    temp = This->Right;
                    end = This;
                }
            }
        }

        if (!temp)
        {
            return;
        }

        temp->data = end->data;
        if (end->Left == temp)
        {
            delete end->Left;
            end->Left = nullptr;
        }
        else
        {
            delete end->Right;
            end->Right = nullptr;
        }
    }

    void pre(node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        cout << root->data << endl;
        pre(root->Left);
        pre(root->Right);
    }
    void pos(node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        pos(root->Left);
        pos(root->Right);
        cout << root->data << endl;
    }
    void in(node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        in(root->Left);
        cout << root->data << endl;
        in(root->Right);
    }
};

int main()
{
}