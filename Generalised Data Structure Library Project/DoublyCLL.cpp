
// Doubly Circular linked List  using generic programming

#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template <class T>
class DoublyCL
{
    private:
        struct node<T> * first;
        struct node<T> * last;
        int Count;

    public:
        DoublyCL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T no,int ipos);
        void DeleteAtPos(int ipos);
};

template <class T>
DoublyCL<T>::DoublyCL()
{
    first = NULL;
    last = NULL;
    Count = 0;
}

template <class T>
void DoublyCL<T>::InsertFirst(T no)
{   
    struct node<T> *newn = NULL;
    
    newn = new struct node<T>;

    newn->data =no;
    newn->next = NULL;
    newn->prev = NULL;
   
   if((first == NULL) && (last == NULL)) //ll empty
   {
       first = newn;
       last = newn;

   } 
   else 
   {
        newn ->next= first;
        first->prev =newn;
        first = newn;
        
   }

    last->next = first;
    first->prev = last;
    Count++;

}

template <class T>
void DoublyCL<T>::InsertLast(T no)
{
   struct node<T> *newn =NULL;

   newn = new struct node<T>;
   
   newn->data = no;
   newn->next = NULL;
   newn->prev = NULL;
  
  if(first == NULL && last == NULL)
  {
      first =newn;
      last =newn;
  }

  else
  {
      newn->prev = last;
      last->next = newn;   
      last = newn;
     
  }

  last->next = first;
  first->prev =last;
  Count++;
}

template <class T>
void DoublyCL<T>::Display()
{
    struct node<T> * temp = first;
  if(first != NULL && last != NULL)
    {      
        cout<<" <=>";
        do
        {
            cout<<"| "<<first->data<<" | <=>";
            first = first->next;
        }while(first != last->next);
        cout<<"\n";
     }

}

template <class T>
int DoublyCL<T>::CountNode()
{
    return Count;
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if((first == NULL) && (last == NULL))    // LL is empty
    {
        return;
    }
    else if(first == last)   // LL contains single node
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else    // LL contains more than one node
    {

        first = first->next;
        delete last->next;    // free((*Head)->prev);
        first->prev = last;
        last->next = first;
    }
    Count--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    { 
       delete first;
       first=NULL;
       last = NULL;
    }
    else
    {
       struct node<T> * temp = first;
       while(temp->next != last)
       {
           temp = temp->next;
       }
       
       delete last;
       last = temp;
       temp->next = first;

       Count--;

    }

}

template <class T>
void DoublyCL<T>::InsertAtPos(T no,int ipos)
{
    if((ipos < 1) || (ipos > (Count+1))) //Filter
    {
        return;
    }
    if(ipos == 1)
    {
      InsertFirst(no);
    }
    else if(ipos == Count+1)
    {
        InsertLast(no);
    }
    
    else
    {    
         
         
         struct node<T> *newn = NULL;
         newn = new struct node<T>;
         
         newn->data =no;
         newn->next = NULL;
         newn->prev = NULL;

         struct node<T> * temp = first;
         int i = 0;
       for(i=1; i < ipos-1; i++)
       {
           temp = temp->next;
       }
       newn->next = temp->next;
       temp->next->prev=newn;
       temp->next=newn;
       newn->prev=temp;
       
       
       Count++;
    }

   
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int ipos)

{
   if((ipos < 1) || (ipos > Count))
    {
        return ;
    }
    if(ipos ==1)
    {
        DeleteFirst();
    }
    else if(ipos == Count)
    {
        DeleteLast();
    }
    else
    {  
        
         struct node<T> * temp = first;
        struct node<T> * targatednode = NULL;
        int i=0;
        for(i=1; i<ipos-1; i++)
        {
            temp=temp->next;
        }
        targatednode = temp->next;
        temp->next = temp->next->next;
        delete targatednode;
        Count--;
    }

 }

int main()
{
  
     DoublyCL<int>iobj;
     DoublyCL<float>fobj;
     DoublyCL<double>dobj;
      DoublyCL<char>cobj;
    //int iRet =0;


   iobj.InsertLast(11);
   iobj.InsertLast(21);
   iobj.InsertLast(51);
   iobj.InsertLast(101);

     cout<<"Linked list of Integer :"<<"\n";
     iobj.Display();


    fobj.InsertLast(11.99);
     fobj.InsertLast(21.99);
     fobj.InsertLast(51.99);
     fobj.InsertLast(101.99);

     cout<<"Linked list of Floats :"<<"\n";
     fobj.Display();


     dobj.InsertLast(11.9999);
     dobj.InsertLast(21.9999);
     dobj.InsertLast(51.9999);
     dobj.InsertLast(101.9999);

     cout<<"Linked list of Doubles :"<<"\n";
     dobj.Display();


     cobj.InsertLast('A');
     cobj.InsertLast('B');
     cobj.InsertLast('C');
     cobj.InsertLast('D');

     cout<<"Linked list of Character :"<<"\n";
     cobj.Display();
  
    return 0;
}