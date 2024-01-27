 #include<iostream>
using namespace std;

//Singly linear linked list by using generic ptogramming 

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyLL
{
    private:
        struct node<T> * first;
        int Count;

    public:
        SinglyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void Display();
        int  SumOfAllElements();  //Even sum
        void EvenDisplay(); //EvenDisplay
        int  EvenFrequency(); //Frequency
        void OddDisplay();  //OddDisplay
        int  OddSum();      //OddSum
        int  OddFrequency(); //OddFrequency
        int  EvenSum();
        int  CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T no,int ipos);
        void DeleteAtPos(int ipos);
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside constructor\n";
    first = NULL;
    Count = 0;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;

    newn = new struct node<T>;   
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)   // if(Count == 0)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    Count++;
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = first;

    newn = new struct node<T>;   
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)   // if(Count == 0)
    {
        first = newn;
    }
    else
    {
        while(temp -> next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    Count++;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct node<T> * temp = first;

    cout<<"Elements of the linked list are : \n";
    
    while(temp != NULL) // Type 1
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp ->next;
    }
    cout<<"NULL \n";
}

template <class T>
int SinglyLL<T>::SumOfAllElements()
{
    int iSum = 0;

    while(first != NULL)
    {
        iSum = iSum +(first->data);
        first = first->next;

    }
    return iSum;
}

//EvenDisplay Logic
template <class T>
void SinglyLL<T> ::EvenDisplay()

{
     struct node<T> * temp = first;
     int iEven = 0;
    cout<<"Even Elements are :"<<"\n";

    while(temp != NULL)
    {
        if((temp->data) % 2 == 0)
        {   
            cout<<temp->data<<"\t";
        
        }
        temp = temp->next;
     }
     
}

//Odd Display 
template <class T>
void SinglyLL<T> ::OddDisplay()

{
     struct node<T> * temp = first;
     int iEven = 0;
    cout<<"Odd Elements are :"<<"\n";

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
int SinglyLL<T> ::OddFrequency()

{    
     struct node<T> * temp = first;
     int iCnt = 0;
    cout<<"Frequency of Odd  are :"<<"\n";

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

//Odd elements sum 
template <class T>
int SinglyLL<T> ::OddSum()

{
     struct node<T> * temp = first;
     int OSum = 0;
    cout<<"Odd Elements are :"<<"\n";

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
int SinglyLL<T>::EvenFrequency()
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

//EvenSum
 template <class T>
 int SinglyLL<T>::EvenSum()
  { 
      
      int ESum = 0;
      cout<<"\nSum of Even Elements Are :"<<"\n";

      while(first != NULL)
      {
          if((first->data) % 2 == 0)
          {
            ESum = ESum + (first->data);
            
          }

          first = first-> next;
         
      }   
  
      return ESum;
  }



template <class T>
int SinglyLL<T>::CountNode()
{
    return Count;
}

template <class T>
void SinglyLL<T>::DeleteFirst()
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
        struct node<T> * temp = first;

        first = first->next;
        delete temp;
    }
    Count--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
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
        struct node<T> * temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    Count--;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T no,int ipos)
{
    if((ipos < 1) || (ipos > Count+1))
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
        struct node<T> * newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;

        struct node<T> * temp = first;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next = newn;

        Count++;
    }
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > Count))
    {
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

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }

        struct node<T> * targatednode = temp->next;
        temp->next = temp->next->next;
        delete targatednode;

        Count--;
    }
}


int main()
{   
     int iRet = 0;
     SinglyLL <int>iobj;
     SinglyLL <float>fobj;
     SinglyLL <double>dobj;
     SinglyLL <char>cobj;

     iobj.InsertLast(10);
     iobj.InsertLast(22);
     iobj.InsertLast(51);
     iobj.InsertLast(101);
     iobj.InsertLast(52);
     iobj.InsertLast(88);

     cout<<"Linked list of Integres :"<<"\n";
     iobj.Display();
    
   // iRet = iobj.SumOfAllElements();
    // /cout<<"Sum of All numbers :"<<iRet<<"\n";
    cout<<"\nOdd Elements in Linked list are :"<<"\n";
    iobj.OddDisplay();
    
     iRet = iobj.OddFrequency();
     cout<<"\nFrequency of odd Elements are :"<<iRet <<"\n";

    iRet = iobj.OddSum();
    cout<<"Sum of Odd elements are :"<<iRet<<"\n";

  
    cout<<"\nEven Elements in Linked list are :"<<"\n";
    iobj.EvenDisplay();
    
    
    iRet = iobj.EvenFrequency();
    cout<<"\nFrequency of Even Elements are :"<<iRet <<"\n";
    
    iRet = iobj.EvenSum();
    cout<<"Sum of Even elements are :"<<iRet<<"\n";

    
    
      
     fobj.InsertLast(11.99);
     fobj.InsertLast(21.99);
     fobj.InsertLast(51.99);
     fobj.InsertLast(101.99);

     cout<<"\nLinked list of Floats :"<<"\n";
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















