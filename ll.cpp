#include<iostream>
#include<string>

struct node
{
    int data;
    node* next;

    node(int d): data(d), next(nullptr) {};
};

struct dnode
{
    int data;
    dnode* next, *prev;
    
    dnode(int d): data(d), next(nullptr), prev(nullptr) {};
};
class ll
{
    node* head;
public:
    ll(): head(nullptr){};
    void append(int data)
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
    void replace(int pos, int data)
    {
        node* temp = head;
        int i=0;
        while(i<pos-1)
        {
            temp = temp->next;
            i++;
        }
        node* temp2 = temp->next->next;
        node* mid = new node(data);
        delete temp->next;
        temp->next = mid;
        mid->next = temp2;
    }
    void add_middle(int pos, int data)
    {
        node* temp = head;
        int i=0;
        while(i<pos-1)
        {
            temp = temp->next;
            i++;
        }
        node* new_node = new node(data);
        new_node->next = temp->next;
        temp->next = new_node;
    }
    void reverse()
    {
        node* temp = head;
        node* prev = nullptr, *next=nullptr;
        while(temp!=nullptr)
        {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        head = prev;
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

class dll
{
    dnode* head;
    dnode* tail;
public:
    dll(): head(nullptr), tail(nullptr) {};

    void append(int data) {
        dnode* newNode = new dnode(data);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void delete_end()
    {
        if(head==tail)
            delete(head);
        else
            tail = tail->prev;
            delete(tail->next);
            tail->next = nullptr;
    }
    void print()
    {
        dnode* temp = head;
        while(temp)
        {
            std::cout<<temp->data<<"->";
            temp = temp->next;
        }
        std::cout<<"\n";
    }
    void smh()
    {

    }
    void delete_mid(int pos)
    {
        dnode* temp = head;
        int i=0;
        while(i<pos-1)
        {
            temp = temp->next;
            i++;
        }
        dnode *temp2 = temp->next->next;
        temp2->prev = temp;
        delete temp->next;
        temp->next = temp2;

    }
    void add_middle(int pos, int data)
    {
        dnode* temp = head;
        int i=0;
        while(i<pos-1)
        {
            temp = temp->next;
            i++;
        }
        dnode* temp2 = temp->next;
        dnode* new_node = new dnode(data);
        new_node->next = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
        temp2->prev = new_node;
    }

    void print_reverse1()
    {
        std::cout<<"reverse\n";
        dnode* temp = tail;
        while(temp)
        {
            std::cout<<temp->data<<"<-";
            temp = temp->prev;
        }
        std::cout<<"\n";
    }

    ~dll()
    {
        while (head)
        {
            dnode* temp = head;
            std::cout<<"deleted: "<<head->data<<std::endl;
            head = head->next;
            delete temp;
        }
    }

};

class cll
{

};


int main()
{
    dll l;
    l.append(1);
    l.append(4);
    l.append(9);
    l.append(16);
    l.append(25);
    l.append(36);
    l.print();
    l.print_reverse1();
    // l.smh();
    l.add_middle(4,1000);
    l.print_reverse1();

    l.print();

    return 0;
}