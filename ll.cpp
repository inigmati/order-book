#include<iostream>
#include<string>

struct node
{
    int data;
    node* next;

    node(int d): data(d), next(nullptr) {};
};

class ll
{
    node* head;
public:
    ll(): head(nullptr){};
    void insert(int data)
    {
        node* new_node = new node(data);
        if(!head)
        {
            head = new_node;
        }
        else
        {
            node* temp = head;
            while(temp->next)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
    void print()
    {
        node* temp = head;
        while(temp)
        {
            std::cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        std::cout<<"\n";
    }
    void delete_last()
    {
        node* temp = head;
        while(temp->next->next)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    void delete_middle(int k)
    {
        node* temp = head;
        int i= 0;
        while(i<k-1)
        {
            temp = temp->next;
            i++;
        }

        node* temp2 = temp->next->next;
        delete temp->next;
        temp->next = temp2;
    }
    ~ll()
    {
        while (head)
        {
            node* temp = head;
            std::cout<<"deleted: "<<head->data<<std::endl;
            head = head->next;
            delete temp;
        }
    }
};


int main()
{
    ll l;
    l.insert(1);
    l.insert(4);
    l.insert(9);
    l.insert(16);
    l.insert(25);
    l.insert(36);
    l.insert(49);
    l.print();
    l.delete_middle(3);
    l.print();
    l.delete_middle(3);
    l.print();
    std::cout<<"Hello CPP:\n";

    return 0;
}