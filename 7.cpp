// SCLL
// C++
#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node * next;
}NODE, *PNODE;

class SinglyCL
{
    public:
        PNODE first;
        PNODE last;
        int iCount;

        SinglyCL();

        void Display();
        int Count();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no, int pos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);
};

SinglyCL::SinglyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

void SinglyCL::Display()
{
    PNODE temp = first;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<"\n";
}

int SinglyCL::Count()
{
    return iCount;
}

void SinglyCL::InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;
    newn->data = no;
    newn->next = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }

    else
    {
        newn->next = first;
        first = newn;
    }
    last->next = first;
    iCount++;
}

void SinglyCL::InsertLast(int no)
{
    PNODE newn = NULL;

    newn = new NODE;
    newn->data = no;
    newn->next = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }

    else
    {
        last->next = newn;
        last = last->next;
    }
    last->next = first;
    iCount++;
}

void SinglyCL::InsertAtPos(int no, int pos)
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
        PNODE temp = first;
        PNODE newn = NULL;

        newn = new NODE;
        newn->data=no;
        newn->next=NULL;

        for(int iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

void SinglyCL::DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }

    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }

    else
    {
        first = first->next;
        delete last->next;

        last->next = first;
    }
    iCount--;
}

void SinglyCL::DeleteLast()
{
    PNODE temp = first;

    if((first == NULL) && (last == NULL))
    {
        return;
    }

    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }

    else
    {
        while(temp->next != last)
        {
            temp = temp->next;
        }
        delete last;
        last = temp;
        last->next = first;
    }
    iCount--;
}

void SinglyCL::DeleteAtPos(int pos)
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
    SinglyCL obj1;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

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