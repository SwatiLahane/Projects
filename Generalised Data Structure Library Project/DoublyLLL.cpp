
//Doubly linear linked list using generic programming 


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
class DoublyLL
{
    private:
        struct node<T> * first;
        int Count;

    public:
          DoublyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void Display();
        int  SumOfAllElements();  //Even sum
        void EvenDisplay(); //EvenDisplay
        int  EvenFrequency(); //Frequency
        int  EvenSum();   //EvenSum
        void OddDisplay(); //OddDisplay
        int  OddFrequency(); //OddFrequency
        int  OddSum();        //oDd sum
        int  CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T no,int ipos);
        void DeleteAtPos(int ipos);
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    first = NULL;
    Count = 0;
}

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
        struct node<T> *newn = NULL;
        newn = new struct node<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;  //#

        if(first == NULL) //LL is empty
        {
            first = newn;
        }

        else  //ll contain at least one node
        { 
          newn->next =first;
          first-> prev = newn;  //#
          first = newn;
        }
       Count++;
    }

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
        struct node<T> * temp = first;
        struct node<T> * newn = NULL;
        newn = new struct node<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;  //#

        if(first == NULL) //LL is empty
        {
            first = newn;
        }

        else  //ll contain at least one node
        { 
            //type 2
            while(temp -> next != NULL)
            {
                temp = temp -> next;
            } 
            temp->next = newn;
            newn->prev = temp;  //#
        }
       Count++;
}

template <class T>
void DoublyLL<T>::Display()
{    
    struct node<T> * temp = first;
     cout<<"Contents of LinkedList are : \n";
      {   
          cout<<"NULL <=>";
          while(temp != NULL )
          {
              cout<<"| "<<temp->data<<" | <=> ";
              temp = temp ->next;
          }
          cout<<"NULL\n";
      }

}

//EvenDisplay Logic
template <class T>
void DoublyLL<T> ::EvenDisplay()

{
     struct node<T> * temp = first;
     
    cout<<"Even Elements are :"<<"\n";

    while(first != NULL)
    {
        if((first->data) % 2 == 0)
        {   
            cout<<first->data<<"\t";
        
        }
        first = first->next;
     }
     
}


//Odd Display 
template <class T>
void DoublyLL<T>::OddDisplay()

{
     struct node<T> * temp = first;
     int iEven = 0;
    cout<<"\nOdd Elements are :"<<"\n";

    while(temp != NULL)
    {
        if((temp->data) % 2 != 0)
        {   
          cout<<temp->data<<"\t";
        }
        temp = temp->next;
     }
     
}
//Frequency of odd
template <class T>
int DoublyLL<T>::OddFrequency()

{    
     struct node<T> * temp = first;
     int iCnt = 0;
    cout<<"\nFrequency of Odd  are :"<<"\n";

    while(temp != NULL)
    {
        if((temp->data) % 2 != 0)
        {   
          iCnt++;
        }
        temp = temp->next;
     }
     return iCnt;
}

//EvenSum
 template <class T>
 int DoublyLL<T>::EvenSum()
  { 
       struct node<T> * temp = first;
      int ESum = 0;
      cout<<"\nSum of Even Elements Are :"<<"\n";

      while(temp != NULL)
      {
          if((temp->data) % 2 == 0)
          {
            ESum = ESum + (temp->data);
            
          }

          temp = temp-> next;
         
      }   
  
      return ESum;
  }

//Odd elements sum 
template <class T>
int DoublyLL<T> ::OddSum()

{
     struct node<T> * temp = first;
     int OSum = 0;
    cout<<"\nOdd Elements are :"<<"\n";

    while(temp != NULL)
    {
        if((temp->data) % 2 != 0)
        {   
            
             OSum = OSum + (temp->data);
        
        }
        temp = temp->next;
     }
     return OSum;
}


//Frequecny of Even Elements 
template<class T>
int DoublyLL<T>::EvenFrequency()
{   

    struct node<T> * temp = first; 
    int iCnt  = 0;
    cout<<"\nFrequency of Even Elements :"<<"\n";

     while(temp != NULL)
    {
        if((temp->data) % 2 == 0)
        {   
            iCnt++;
            //cout<<temp->data<<"\t";
        
        }
        temp = temp->next;
     }
     return iCnt;
}






template<class T>
int DoublyLL<T>::SumOfAllElements()
{
    //struct node<T> * temp = first;
    int iSum = 0;

    cout<<"Summation of Linked list are :\n";
    {
        while(first != NULL)
        { 
            iSum = iSum + (first->data);  
            first = first->next;      
        }
        return iSum;
    }
}



template <class T>
int DoublyLL<T>::CountNode()  //
{
    return Count;
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
   if(first == NULL)
      {
          return ;
      }
      else if((first)->next == NULL  && ((first)-> prev == NULL )) //single node
                                                                  //#
      {
            delete first;
            first = NULL;

      }
      else
      {
          struct node<T> * temp = first;
          first = first->next;
          delete first->prev;
          first->prev = NULL;
      }
       Count--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
     struct node<T> * temp = first;

      if(first == NULL)
      {
          return ;
      }
      //else if madhe fakt  *Head ->next == NULL lihil tari chalat
      else if(((first)->next == NULL)  && ((first)-> prev == NULL )) //single node
                                                                  //#
      {
            free(first);
            first = NULL;
      }
      else
      {
          while(temp->next->next != NULL)
          {
              temp = temp -> next;
          }
          delete temp-> next;
          temp->next =NULL;
      }
      Count--;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T no,int ipos)
{

            
      if((ipos < 1) || (ipos > Count+1))

      {
          cout<<"Invalid Position\n";
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

     struct node<T> *newn = new struct node<T>; //dynamic Memory allocation 

      newn->data = no;
      newn->next = NULL;
      newn->prev = NULL;
       
       struct node<T> * temp = first;
       int i =0;
      for(i = 1; i< ipos-1; i++)
      
      {
          temp = temp->next;
      }

      newn->next = temp -> next;
      temp->next->prev = newn;
      temp->next = newn;
      newn->prev = temp;

      Count++;

      }
}


template <class T>
void DoublyLL<T>::DeleteAtPos(int ipos)

{
    if((ipos < 1) || (ipos > (Count)))

      {
          printf("Invalid Position\n");
          return;
      }

      if(ipos == 1)
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
         
          int i = 0;

          for(i = 1; i < ipos-1 ; i++)
          {
              temp = temp->next;
          }

          temp->next =temp ->next->next;
          delete temp->next->prev;  //#
          temp->next->prev = temp; //#

          Count--;
      }
}

int main()

{
    int iRet =0;
    DoublyLL<int>iobj;
    DoublyLL<float>fobj;
    DoublyLL<double>dobj;
    DoublyLL<char>cobj;
    

    iobj.InsertLast(11);
    iobj.InsertLast(21);
    iobj.InsertLast(51);
    iobj.InsertLast(101);
    iobj.InsertLast(12);
    iobj.InsertLast(22);
    iobj.InsertLast(52);
     
     cout<<"\nLinked list of Integres :\n"<<"\n";
     iobj.Display();
      
    //iRet = iobj.SumOfAllElements();
    //cout<<"Summation of all the elements :"<<iRet<<"\n";

    iRet = iobj.EvenSum();
    cout<<"\nSum of Even Elements in Linked list are :"<<iRet<<"\n";

     iRet = iobj.EvenFrequency();
    cout<<"\nFrequency of Even Elements are :"<<iRet <<"\n";
     
    cout<<"\nOdd Elements in Linked list are :"<<"\n";
    iobj.OddDisplay(); 
    
    iRet = iobj.OddFrequency();
    cout<<"\nFrequency of odd Elements are :"<<iRet <<"\n";

    iRet = iobj.OddSum();
    cout<<"\nSum of Odd elements are :"<<iRet<<"\n";


    cout<<"\nEven Elements in Linked list are :"<<"\n";
    iobj.EvenDisplay();
    

    fobj.InsertLast(11.99);
    fobj.InsertLast(21.99);
    fobj.InsertLast(51.99);
    fobj.InsertLast(101.99);

    cout<<"\nLinkedList of Floats : "<<"\n";
    fobj.Display();

    dobj.InsertLast(11.9999);
    dobj.InsertLast(21.9999);
    dobj.InsertLast(51.9999);
    dobj.InsertLast(101.9999);

    cout<<"\nLinkedList of Doubles : "<<"\n";
    dobj.Display();

    cobj.InsertLast('A');
    cobj.InsertLast('B');
    cobj.InsertLast('C');
    cobj.InsertLast('D');

    cout<<"\nLinkedList of Characters : "<<"\n";
    cobj.Display();

    
    return 0;
}


