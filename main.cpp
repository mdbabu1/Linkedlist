#include <iostream>

using namespace std;

struct node
{
   int num;
   node *next;
};

//prototype
bool isEmpty(node *head);
char menu();
//here head and last element need to be reference
void insertAsFirstElement(node *&head, node *&last, int num);
void insert(node *&head, node *&last, int num);
void remove(node *&head, node *&last);
void showList(node *current);

//method
bool isEmpty(node *head)
{
  if(head == NULL)
    return true;
  else
    return false;
}

char menu()
{
  char choice;
  cout<< "Menu\n";
  cout<< "1.Add an item.\n";
  cout<< "2. Remove an item.\n";
  cout<< "3. Show the lsit.\n";
  cout<< "4.Exit\n";

  cin>> choice;

  //return choice to the main function
  return choice;

}

void insertAsFirstElement(node *&head, node *&last, int num)
{
   node * temp = new node;
   temp->num = num;
   temp->next = NULL;
   head = temp;
   last = temp;
}

void insert(node *&head, node *&last, int num)
{
  if(isEmpty(head))
    insertAsFirstElement(head, last, num);
  else
  {
     node * temp = new node;
     //After creating the node, dereferencing the num that is assigned to the local num of the function
     temp->num = num;
     //always the inserted elements next set to NULL
     temp->next = NULL;

     last->next = temp;
     last = temp;
  }
}

void remove(node *&head, node *&last)
{
   if(isEmpty(head))
      cout<< "The list is aleady empty.\n";
   else if (head == last)
   {
     delete head;
     head == NULL;
     last == NULL;
   }
   else
   {
       node *temp = head;
       head = head->next;
       delete temp;
   }
}

void showList(node *current)
{
   if(isEmpty(current))
      cout << "The list is empty\n";
   else
   {
       cout << "the list contain: \n";
       while(current !=NULL)
       {
           cout << current->num <<endl;
           current = current->next;
       }
   }

}


int main()
{
    //we intialize head and last with NULL because nothing in the last
    node *head =NULL;
    node *last = NULL;
    char choice;
    int num;

    do{

      choice = menu();

      switch(choice)
      {
      case '1': cout << "Plese enter a number:";
                cin >> num;
                insert(head, last, num);
                break;

      case '2': remove(head, last);
                break;

      case '3': showList(head);
                break;

      default: cout<< "system exit\n";
      }

    }while(choice !=4);

    return 0;
}
