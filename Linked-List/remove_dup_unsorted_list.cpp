#include <bits/stdc++.h>
using namespace std;

class List;
List *head = NULL;

class List{
    public:

    int data;
    List *next;

    public:
        void add_at_end(int data){

            List *newnode = new List;
            newnode->data = data;
            newnode->next = NULL;

            if(head == NULL){
                head = newnode;
            }
            else{
                List *ptr = head;
                while(ptr->next != NULL){
                    ptr = ptr->next;
                }
                ptr->next = newnode;
            }
        }

        void display(){
            List *ptr = head;

            while(ptr != NULL){
                cout<<ptr->data<<"-->";
                ptr = ptr->next;
            }
            cout<<"NULL";
        }
};

List  *rem_dup_unsorted_list(List *head){
    
    map<int,int> m;

    List *curr = head;
    m[curr->data] = 1;
    
    List *prev = curr;
    curr = curr->next;

    while(curr != NULL){
        // if that elem is already exist in map
        if(m[curr->data]){
            prev->next = curr->next;
        }
        else{
            m[curr->data] = 1;
            prev = curr;
        }

        // Both are same as (prev = curr) 
        curr = prev->next;
        // curr = curr->next;
    }

    return head;
}




int main(){
    List ob;
    ob.add_at_end(10);
    ob.add_at_end(10);
    ob.add_at_end(30);
    ob.add_at_end(10);
    ob.add_at_end(40);
    ob.add_at_end(50);
    ob.add_at_end(60);
    ob.add_at_end(40);

    ob.display();
    cout<<endl;

    rem_dup_unsorted_list(head);

    cout<<endl;
    ob.display();

    return 0;
}