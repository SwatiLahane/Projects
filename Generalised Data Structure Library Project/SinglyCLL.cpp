
    //Singly Circular Linked List using generic programming
    

    #include<iostream>
    using namespace std;

    template<class T>
    struct node
    {
        T data;
        struct node *next;
        
        
    };

    template<class T>
    class SinglyCL
    {
        private:
            struct node<T> * first;
            struct node<T> * last;
            int Count;

        public:
            SinglyCL();
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
    SinglyCL<T>::SinglyCL()
    {
        first= NULL;
        last = NULL;
        Count = 0;
    }

    template <class T>
    void SinglyCL<T>::InsertFirst(T no)
    {
        struct node<T>  *newn = NULL;

        newn = new struct node<T>;

        newn->data = no;
        newn->next = NULL;

        if((first == NULL) && (last == NULL))  // LL is empty
        {
            first = newn;
            last = newn;       // #
            last->next = first;      // #
    
        }
        else    // LL contains atleast 1 node
        {
            newn->next = first;
            first= newn;
            last->next = first;      // #
        }
    
        Count++;
    }

    template <class T>
    void SinglyCL<T>::InsertLast(T no)
    {
    
    struct node<T> * newn = NULL;
    struct node<T> * temp = first;

        newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;

    if((first == NULL) && (last == NULL))  // LL is empty
        {
            first = newn;
            last = newn;
            last->next = first;
        }
        else    // LL contains atleast 1 node
        {
            last->next = newn;
            last = newn;
            last->next = first;
        }
        Count++;
    }

    template <class T>
    void SinglyCL<T>::Display()
    { 
        struct node<T> * temp = first;
      cout<<"Elements in Linked List are:\n";
      {
       if((first != NULL) && (last != NULL))
       {

         do
         {
            cout<<"| "<<first->data<<" | ->";
            first = first ->next;
        
         }while(first != last->next);
        
         cout<<"Address of First Node \n";
        }

       }
    }

    template<class T>
    int SinglyCL<T>::CountNode()
    {
        return Count;
    }


    template <class T>
    void SinglyCL<T>::DeleteFirst()
    {

        if((first ==NULL) && (last == NULL)) //case 1
    {
        return ;
    }
    else if(first == last)  //Case 2
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else //case 3
    {
        struct node<T> * temp = first;
        first = first->next;
        delete(last->next); 
        last->next = first;
    
    }
       Count--;
    }


    template <class T>
    void SinglyCL<T>::DeleteLast()
    {
        if((first ==NULL) && (last == NULL)) //case 1
    {
        return ;
    }
    else if(first == last)  //Case 2
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else //case 3
    {  

        struct node<T> * temp = first;

        while(temp->next != last)
        { 
            temp = temp->next;
        }
        
        delete(last); 
        last = temp;
        last->next =first;
    
    } 
       Count--;
    }

    template <class T>
    void SinglyCL<T>::InsertAtPos(T no,int ipos)
    {
        if((ipos < 1) || (ipos > (Count +1)))
        {   
            cout<<"INvalid Position";

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
            struct node<T> * temp = first;
        
            newn->data = no;
            newn->next = NULL;
            
        
            int i=0;
            for(i=1; i<ipos-1; i++)
            {
                temp=temp->next;
            }
            newn->next = temp->next;
            temp->next = newn;

            Count++;
        }


    }

    template <class T>
    void SinglyCL<T>::DeleteAtPos(int ipos)
    {

    if((ipos < 1) || (ipos > Count))

        {   
            cout<<"INvalid Position";

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
            struct node<T> * targatednode = NULL;  
            
            int i = 0;
            for(i=1; i < ipos - 1; i++)
            {
                temp = temp ->next;
            }
            
            targatednode = temp->next;
            temp->next = temp->next->next; //taragednode->next
            delete targatednode;
            
            Count--;
            
        }
    }

    int main()
    {
        SinglyCL <int>iobj;
        SinglyCL <float>fobj;
        SinglyCL <double>dobj;
        SinglyCL <char>cobj;
        
        
    
        iobj.InsertLast(11);
        iobj.InsertLast(21);
        iobj.InsertLast(51);
        iobj.InsertLast(101);

        cout<<"Linked list of Integres :"<<"\n";
        iobj.Display();


        fobj.InsertLast(11.99);
        fobj.InsertLast(21.99);
        fobj.InsertLast(51.99);
        fobj.InsertLast(101.99);

        cout<<"Linked list of floats :"<<"\n";
        fobj.Display();

        dobj.InsertLast(11.9999);
        dobj.InsertLast(21.9999);
        dobj.InsertLast(51.9999);
        dobj.InsertLast(101.9999);

        cout<<"Linked list of doubles :"<<"\n";
        dobj.Display();


        cobj.InsertLast('A');
        cobj.InsertLast('B');
        cobj.InsertLast('C');
        cobj.InsertLast('D');

        cout<<"Linked list of floats :"<<"\n";
        cobj.Display();
        return 0;
    }