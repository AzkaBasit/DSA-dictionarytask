#include <iostream>
#include<assert.h>
#include "Dictionary.h"
using namespace std;

template <typename A>
                            //classs definition of Node 
class ListNode
{   
  public:
    A data;
    ListNode<A> *next=NULL;
};

//PASTE YOUR LINKED LIST CODE HERE
template <typename A>

class SinglyLinkedList
{
    public:
    ListNode<Dictionary> *head = NULL;

    //function for empty list
    bool isEmpty()
    {
        return (head==NULL);
    }

    //length of list
    int length()
    {
        int len=0;
        for(ListNode<Dictionary>* loc = head; loc; loc=loc->next)
        {  len++  ;}
        return len;
    }
    
    //insertion at start
    void InsertAtStart(A val)
    {       
            ListNode<Dictionary>* nn = new ListNode<Dictionary>;
            nn->data = val;
            nn->next = head;
            head = nn;
    }
    

    void InsertAtPosition(A val, int position)
    {   
        if(position<1)
        {
            cout<<"ENTER POSITION GREATER THAN or equal to 1"<<endl;
        }
        else if(position==1)
        {
            InsertAtStart(val);
        }
        else
        {
            ListNode<Dictionary> *nn=new ListNode<Dictionary>;
            nn->data = val;
            nn->next = NULL;
            ListNode<Dictionary> *temp;
            temp=head;

            for(int i=1;i<position-1;i++) //loop till position-1
            {   
                if(temp!=NULL)
                {
                temp=temp->next;    //now temp is at pos-1
                }
            }
                if(temp!=NULL)
                {
                nn->next=temp->next;
                temp->next=nn;
                }
        }
    }

    bool Search(A val)
    {
        for(ListNode<Dictionary>*loc= head; loc; loc=loc ->next)
        {
            return ((loc->data)==val);
        }
    }

    void DEL(A val)
    {
        ListNode<Dictionary>* loc = head;
        ListNode<Dictionary>* ploc = NULL;

        while (loc!=NULL && loc->data != val)
        {
            ploc = loc;
            loc =loc->next;
        }

        if (loc!=NULL)
        {
            if (ploc!=NULL)
            {
                ploc->next = loc->next;
                delete loc;
            }

            else
            {
                head = loc->next;
                delete loc;
            }
        }
    }

    void DESTROY()
    {
        ListNode<Dictionary> *temp;
        while ((head!=NULL))
        {   
            temp=head;
            head=head->next;
            delete temp;
        } 
        head=NULL; 
    }
    
    void print_List()
    {
        ListNode<Dictionary> *temp;
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
        
    }

    //a function that prints all nodes of a sinlgy linked list in the reverse order according to the dictionary words
    void printReverse(ListNode<Dictionary> *headnode)
    {rev(headnode);}

    void rev(ListNode<Dictionary> *temp)
    {   
        if(temp!=NULL)
        {
            rev(temp->next);
            cout<<temp->data<<endl;
        }   
        
    }

// a function which reverses the order of a linked list according to the dictionary words.
ListNode<Dictionary> *reverseList(ListNode<Dictionary> *start)
{
    
        ListNode<Dictionary>* ploc = NULL;
        ListNode<Dictionary>* loc = start;

        while (loc!=NULL) 
        {
            ListNode<Dictionary>* temp;
            temp = loc->next;
            loc->next = ploc;
            ploc = loc;
            loc = temp;
        }
        start = ploc;
        return start;   
        
}
//a function that filters all those dictionary nodes from the linked list which have the inputted letter 
//in their data part and returns a new list
ListNode<Dictionary> *FilterByLetters(ListNode<Dictionary>*start , string filtering_letter)
{
    ListNode<Dictionary>*temp;
    temp=start;
    while(temp!=NULL)
    {
        if(temp->data.word.find(filtering_letter)==-1) //deletes nodes which donot have "FILTERING_LETTER"
        {
            Dictionary deletion_node = temp->data;
            temp=temp->next;
            DEL(deletion_node);
        }

        else
        {
            temp=temp->next;
        }
    }
     return start;
}

//that rearranges a linked list such that all the even length words appear at the start of the list, 
//and all the odd length words appear at the end of the list
    ListNode<Dictionary>* rearrangeByEvenOddLength(ListNode<Dictionary>* start)
    {
       
       ListNode<Dictionary> *loc=start;
       ListNode<Dictionary> *oddHead=NULL;
       ListNode<Dictionary> *oddLast=NULL;
       ListNode<Dictionary> *evenHead=NULL;
       ListNode<Dictionary> *evenLast=NULL;
       while(loc!=NULL) 
       {
        if(loc->data.word.size()%2 == 0)
        {
            if(evenHead == NULL)
            {
                evenHead = loc;
                evenLast = loc;
            }
            else
            {
                evenLast->next = loc;
                evenLast = loc;
            }
        }

        else if(loc->data.word.size()%2==1)
        {
            if(oddHead == NULL)
            {
                oddHead = loc;
                oddLast = loc;
            }
            else
            {
                oddLast->next = loc;
                oddLast = loc;
            }
        }
        loc=loc->next;
       }
       if(evenHead != NULL)
       {
        start = evenHead;
       }

       if(evenLast !=NULL)
       {
        evenLast->next = oddHead;
       }

       if(oddLast !=NULL)
       {
        oddLast->next = NULL;
       }

        return start;
    }


};