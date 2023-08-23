// DLLL
// C++
#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node * next;
    struct Node * prev;
}NODE, *PNODE;

class DoublyLL
{
    public:
        PNODE first;
        PNODE last;
        int iCount;

        DoublyLL();
        ~DoublyLL();

        void Display();
        int Count();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no, int pos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);
};

DoublyLL::DoublyLL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

DoublyLL::~DoublyLL()
{}

void DoublyLL::Display()
{
    PNODE temp = first;

    cout<<"Elements in LL are : "<<"\n";

    cout<<"NULL <=> ";
    while(temp != NULL)
    {
        cout<<" |"<<temp->data<<" | <=> ";
        temp = temp->next;
    }
    cout<<"NULL "<<"\n";
}

int DoublyLL::Count()
{
    return iCount;
}

void DoublyLL::InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }

    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    iCount++;
}

void DoublyLL::InsertLast(int no)
{
    PNODE newn = NULL;
    PNODE temp = first;

    newn = new NODE;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }

    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

void DoublyLL::InsertAtPos(int no, int pos)
{
    if((pos<1) || (pos>iCount+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }

    else if(pos == iCount+1)
    {
        InsertLast(no);
    }

    else
    {
        PNODE newn = NULL;
        PNODE temp = first;
        
        newn = new NODE;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(int iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

void DoublyLL::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }

    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }

    else
    {
        first = first->next;
        delete first->prev;
        first->prev = NULL;
    }
    iCount--;
}

void DoublyLL::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }

    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }

    else
    {
        PNODE temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

void DoublyLL::DeleteAtPos(int pos)
{
    if((pos<1) || (pos>iCount))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }

    else if(pos == iCount)
    {
        DeleteLast();
    }

    else
    {
        PNODE temp = first;

        for(int iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete(temp->next->prev);
        temp->next->prev = temp;

        iCount--;
    }
}

int main()
{
    DoublyLL obj1;
    int iRet = 0;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    obj1.Display();
    iRet = obj1.Count();
    cout<<"Nodes in LL are : "<<iRet<<"\n";

    obj1.InsertLast(101);
    obj1.InsertLast(111);

    obj1.Display();
    iRet = obj1.Count();
    cout<<"Nodes in LL are : "<<iRet<<"\n";

    obj1.InsertAtPos(75,4);

    obj1.Display();
    iRet = obj1.Count();
    cout<<"Nodes in LL are : "<<iRet<<"\n";

    obj1.DeleteAtPos(4);

    obj1.Display();
    iRet = obj1.Count();
    cout<<"Nodes in LL are : "<<iRet<<"\n";

    obj1.DeleteFirst();
    obj1.DeleteLast();

    obj1.Display();
    iRet = obj1.Count();
    cout<<"Nodes in LL are : "<<iRet<<"\n";

    return 0;
}

