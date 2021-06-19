// lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string.h>
using namespace std;

struct Node
{
    char ch;
    Node* link_on_next;
};
class Stack {
private:
    Node* first;
    Node* current_operator;
public:
    Stack(char a){
        // выделение памяти под корень списка
        first = new Node;
        first->ch = a;
        first->link_on_next = NULL; // это последний узел списка
        current_operator = new Node;
        current_operator->ch = a;
        current_operator->link_on_next = NULL; // это последний узел списка
       
    }
   
    void push(char c) {
        Node* temp = new Node;
        temp->link_on_next = first;
        temp->ch = c;
        first = temp;
    }
    Node* pop(Node* to_del) {
        Node* temp = new Node;
        temp = first;
        while (temp->link_on_next != to_del)
        {
            temp = temp->link_on_next;
        }
        temp->link_on_next = to_del->link_on_next;
        delete to_del;
        return temp;
    }
    void rozw() {
        int num_of_operators=0;
        Node* cursor;
        cursor = new Node;
        cursor = first;
        do
        {
           
                if (cursor->ch == 'K' || cursor->ch == 'N' || cursor->ch == 'A')
                {
                    num_of_operators++;
                    cursor = cursor->link_on_next;
                }
                else{
                    //  pre_temp = temp;
                    cursor = cursor->link_on_next;
                }
            
        } while (cursor->link_on_next!=NULL);
        
        do
        {
            Node* cursor_for_last_NAK;
            cursor_for_last_NAK = new Node;
            cursor_for_last_NAK = first;
            int temp_oper = num_of_operators;

            do
            {
                if (cursor_for_last_NAK->ch == 'K'|| cursor_for_last_NAK->ch == 'N' || cursor_for_last_NAK->ch == 'A'  )
                {
                    current_operator = cursor_for_last_NAK;
                    temp_oper--;
                }
               
                cursor_for_last_NAK = cursor_for_last_NAK->link_on_next;
            } while (temp_oper>0);
           // cout << current_operator->ch;
            
            Node* cursor_first;
            cursor_first = new Node;
            Node* cursor_sec;
            cursor_sec = new Node;

            if (current_operator->ch=='A')
            {

                cursor_first = current_operator->link_on_next;
                cursor_sec = cursor_first->link_on_next;
                if (cursor_first->ch == 'f' && cursor_sec->ch == 'f')
                {
                    cursor_sec->ch = 'f';
                }
                else  if (cursor_first->ch == 't' && cursor_sec->ch == 'f')
                {
                    cursor_sec->ch = 't';
                }
                else  if (cursor_first->ch == 'f' && cursor_sec->ch == 't')
                {
                    cursor_sec->ch = 't';
                }
                else  if (cursor_first->ch == 't' && cursor_sec->ch == 't')
                {
                    cursor_sec->ch = 't';
                }
                pop(current_operator);
                pop(cursor_first);
                num_of_operators--;
            }
            else if (current_operator->ch == 'K')
            {
                cursor_first = current_operator->link_on_next;
                cursor_sec = cursor_first->link_on_next;
                if (cursor_first->ch == 'f' && cursor_sec->ch == 'f')
                {
                    cursor_sec->ch = 'f';
                }
                else  if (cursor_first->ch == 't' && cursor_sec->ch == 'f')
                {
                    cursor_sec->ch = 'f';
                }
                else  if (cursor_first->ch == 'f' && cursor_sec->ch == 't')
                {
                    cursor_sec->ch = 'f';
                }
                else  if (cursor_first->ch == 't' && cursor_sec->ch == 't')
                {
                    cursor_sec->ch = 't';
                }
                pop(current_operator);
                pop(cursor_first);
                num_of_operators--;
            }
            else if(current_operator->ch == 'N')
            {
                cursor_first = current_operator->link_on_next;
                
                if (cursor_first->ch == 'f')
                {
                    cursor_first->ch = 't';
                }
                else  if (cursor_first->ch = 't')
                {
                    cursor_first->ch = 'f';
                }
                pop(current_operator);
                
                num_of_operators--;
            }
           // this->outpr();

            

        } while (num_of_operators>0);

    }
    
    
    
    
    
    void arithmetic_operations() {
        Node* cursor_on_tf;
        cursor_on_tf = new Node;
        Node* temp;
        temp = new Node;
        cursor_on_tf = first->link_on_next;
        Node* cursor_on_NAK;
        cursor_on_NAK = new Node;
        cursor_on_NAK = current_operator;

        do
        {
            if (cursor_on_NAK->ch == 'K')
            {
                temp = cursor_on_tf->link_on_next;
                if (cursor_on_tf->ch == 'f' && temp->ch == 'f')
                {
                    temp->ch = 'f';
                }
                else  if (cursor_on_tf->ch == 't' && temp->ch == 'f')
                {
                    temp->ch = 'f';
                }
                else  if (cursor_on_tf->ch == 'f' && temp->ch == 't')
                {
                    temp->ch = 'f';
                }
                else  if (cursor_on_tf->ch == 't' && temp->ch == 't')
                {
                    temp->ch = 't';
                }
                cursor_on_NAK = cursor_on_NAK->link_on_next;
                cursor_on_tf = temp;
            }
            else if (cursor_on_NAK->ch == 'A') {
                temp = cursor_on_tf->link_on_next;
                if (cursor_on_tf->ch == 'f' && temp->ch == 'f')
                {
                    temp->ch = 'f';
                }
                else  if (cursor_on_tf->ch == 't' && temp->ch == 'f')
                {
                    temp->ch = 't';
                }
                else  if (cursor_on_tf->ch == 'f' && temp->ch == 't')
                {
                    temp->ch = 't';
                }
                else  if (cursor_on_tf->ch == 't' && temp->ch == 't')
                {
                    temp->ch = 't';
                }
                cursor_on_NAK = cursor_on_NAK->link_on_next;
                cursor_on_tf = temp;
            }
            else if (cursor_on_NAK->ch == 'N') {
                if (cursor_on_tf->ch == 't') {
                    cursor_on_tf->ch = 'f';
                }
                else
                {
                    cursor_on_tf->ch = 't';
                }
                cursor_on_NAK = cursor_on_NAK->link_on_next;
            }
            else if (cursor_on_NAK->ch == '\n' || cursor_on_NAK->ch == 'a') {
                cursor_on_NAK = cursor_on_NAK->link_on_next;
            }
        } while (cursor_on_NAK != NULL);
        first = cursor_on_tf;
    }
    //Node* push_elem(Node* lst, char a) {
    //    Node* temp, * link_on_next_temp;
    //    temp = new Node;
    //    link_on_next_temp = lst->link_on_next; // сохранение указателя на следующий узел
    //    lst->link_on_next = temp; // предыдущий узел указывает на создаваемый
    //    temp->ch = a; // сохранение поля данных добавляемого узла
    //    temp->link_on_next = link_on_next_temp; // созданный узел указывает на следующий элемент
    //    return(temp);
    //}
    //void add_to_list_NAK(char a) {
    //    Node* temp,*p;
    //    temp = new Node;
    //       p = new Node;
    //    temp = first_of_operands;
    //    p->ch = a;
    //    p->link_on_next = NULL;
    //    while (temp->link_on_next != NULL)
    //    {
    //        //cout << temp->part << endl;
    //        temp = temp->link_on_next;
    //    }
    //    temp->link_on_next = p;
    //    
    //}   
    //void add_to_list_tf(char a) {
    //    Node* temp, * p;
    //    temp = new Node;
    //    p = new Node;
    //    temp = first;
    //    p->ch = a;
    //    p->link_on_next = NULL;
    //    while (temp->link_on_next != NULL)
    //    {
    //        //cout << temp->part << endl;
    //        temp = temp->link_on_next;
    //    }
    //    temp->link_on_next = p;

    //}
 
    //void set_last() {
    //    first_of_operands = new Node;
    //    first_of_operands = first_of_tf;
    //    while (first_of_operands->link_on_next != NULL)
    //    {
    //        //cout << temp->part << endl;
    //        first_of_operands = first_of_operands->link_on_next;
    //    }
    //}
   

    //void sort() {
    //    this->set_last();
    //    first_of_tf = first_of_tf->link_on_next;
    //    Node* cursor;
    //    cursor = new Node;
    //   
    //    cursor = first_of_tf;
    //   
    //   do
    //    {
    //        if (cursor->ch == 'K' || cursor->ch == 'N' || cursor->ch == 'A')
    //        {
    //            this->push_for_tf(cursor->ch);
    //            cursor =delite_elem(cursor);
    //        }
    //        else{
    //            //  pre_temp = temp;
    //            cursor = cursor->link_on_next;
    //        }
    //    } while (cursor != NULL);
    //}
  
    void outpr() {
        first = first->link_on_next;
       cout << this->first->ch << endl;
       /* Node* temp;
        temp = new Node;
        temp = first;
        while (temp->link_on_next != NULL)
        {
            cout << temp->ch << " ";
            temp = temp->link_on_next;
        }
        cout << endl;*/
    }
  
};
int main()
{
    int num_of_it;
    cin >> num_of_it;
    getchar();
   
    for (int u = 0; u < num_of_it; u++)
    {
        Stack* stos =new Stack('a');
        char c;
       
        do
        {

            c = getchar();
            if (c == '\xff')
            {
                break;
            }
           
              stos->push(c);
            
           
          
        } while (c != '\n');
       // stos->sort();
        stos->rozw();
        stos->outpr();
        delete stos;
    }
   
}
