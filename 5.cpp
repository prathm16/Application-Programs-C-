// SLLL
// C++
#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node * next;
}NODE, *PNODE;

class SinglyLL
{
    public:
        PNODE First;
        int iCount;

        SinglyLL();
        ~SinglyLL();

        void Display();
        int Count();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no, int pos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);
};

SinglyLL::SinglyLL()
{
    First = NULL;
    iCount = 0;
}

SinglyLL::~SinglyLL()
{}

void SinglyLL::Display()
{
    PNODE temp = First;

    cout<<"Elements of LL are : "<<"\n";

    while(temp != NULL)
    {
        cout<<" |"<<temp->data<<" | -> ";
        temp= temp->next;
    }
    cout<<" NULL"<<"\n";
}

int SinglyLL::Count()
{
    return iCount;
}

void SinglyLL::InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;
    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }

    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

void SinglyLL::InsertLast(int no)
{
    PNODE newn = NULL;

    newn = new NODE;
    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }

    else
    {
        PNODE temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

void SinglyLL::InsertAtPos(int no, int pos)
{
    if((pos<1) || (pos > iCount+1))
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
        PNODE temp = First;
        PNODE newn = NULL;

        newn = new NODE;
        newn->data = no;
        newn->next = NULL;

        for(int iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

void SinglyLL::DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }

    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }

    else
    {
        PNODE temp = First;

        First = First->next;
        delete temp;
    }
    iCount--;
}

void SinglyLL::DeleteLast()
{
    if(First == NULL)
    {
        return;
    }

    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }

    else
    {
        PNODE temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

void SinglyLL::DeleteAtPos(int pos)
{
    if((pos<1) || (pos > iCount))
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
        PNODE temp = First;
        PNODE tempX = NULL;

        for(int iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        tempX = temp->next;
        temp->next = temp->next->next;
        delete tempX;

        iCount--;
    }
}

int main()
{
    int iRet = 0;
    SinglyLL obj1;

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