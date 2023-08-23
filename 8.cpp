// DCLL
// C++
#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node * next;
    struct Node * prev;
}NODE, *PNODE;

class DoublyCL
{
    public:
        PNODE first;
        PNODE last;
        int iCount;

        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

DoublyCL::DoublyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

void DoublyCL::Display()
{
    cout<<"Elements of Doubly Circular LinkedList are : "<<"\n";

    PNODE temp = first;

    cout<<"<=> ";
    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout<<"| "<<temp->data<<" |"<<" <=>";
        temp = temp->next;
    }
    cout<<"\n";
}

int DoublyCL::Count()
{
    return iCount;
}

void DoublyCL::InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }

    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    last->next = first;
    first->prev = last;
    iCount++;
}

void DoublyCL::InsertLast(int no)
{
    PNODE newn = NULL;

    newn = new NODE;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }

    else
    {
        last->next = newn;
        newn->prev = last;
        last = last->next;
    }
    last->next = first;
    first->prev = last;
    iCount++;
}

void DoublyCL::InsertAtPos(int no, int iPos)
{
    if((iPos <1) || (iPos>iCount+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }

    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }

    else
    {
        PNODE temp = first;
        PNODE newn = NULL;

        newn = new NODE;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        int iCnt = 0;

        for(iCnt = 1; iCnt < iPos-1; iCnt++)
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

void DoublyCL::DeleteFirst()
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
        first->prev = last;
    }
    iCount--;
}

void DoublyCL::DeleteLast()
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
        last = last->prev;
        delete last->next;

        last->next = first;
        first->prev = last;
    }
    iCount--;
}

void DoublyCL::DeleteAtPos(int iPos)
{
    if((iPos <1) || (iPos>iCount))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }

    else if(iPos == iCount)
    {
        DeleteLast();
    }

    else
    {
        PNODE temp = first;

        int iCnt = 0;

        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete (temp->next->prev);
        temp->next->prev = temp;

        iCount--;
    }
}

int main()
{
    DoublyCL obj1;
    int iRet = 0;

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