#include <iostream>

using namespace std;

class node{
  public:
    int num;
    node* next;
    node(node *address, int number);
    node(node *address);
    node();
};

node::node(node *address, int number){
  next = address;
  num = number;
}

node::node(node *address){
  next = address;
}

node::node(){
  next = NULL;
}

void sort(node *start){  //alternative sorting algorithm (not required for assignment)

  node* separator = start;
  node* check = NULL;
  node* scanner = NULL;
  int hold, change;
  while((*separator).next!=NULL){

    check = (*separator).next;
    scanner = start;

    if((*check).num < (*separator).num){
      while((*check).num>(*scanner).num){ //find where node belongs
        scanner = (*scanner).next;
      }

        hold = (*scanner).num;
        (*scanner).num = (*check).num;
      while(scanner != check){
        change = hold;
        hold = (*(*scanner).next).num;
        (*(*scanner).next).num = change;
        scanner = (*scanner).next;
      }

    }
    separator = (*separator).next;
  }
}

void refSort(node *head){ //primary sorting algorithm as required by question
  node* scanBack = NULL;  //scanner to scan through sorted section
  node* separator = (*head).next; //separates sorted from non sorted section
  node* check = NULL; //holds one node ahead of separator
  node* hold = NULL;

  while((*separator).next != NULL){
    check = (*separator).next;
    scanBack = head;        //resets scanner to start of sorted section
    if((*check).num < (*separator).num){  //checks if next node needs to be sorted

      while((*check).num > (*(*scanBack).next).num){ // Loop uses scanback to find where new node should fit
        scanBack = (*scanBack).next;
      }

      hold = (*scanBack).next;          //adjusting the links of the list
      (*scanBack).next = check;
      (*separator).next = (*check).next;
      (*check).next = hold;

    }
    separator = check;      //shifts separator one forward (and therefore check as well)
  }
}


int main(){
  node *address = NULL;
  int num, content;

  do{
    cout<<"Please input the count of the numbers:"<<endl;
    cin>>num;
  }while(num<=0);

  cout<<"Please input the content of the numbers:"<<endl;

  for(int i = 0; i<num; i++){
    cin>>content;
    address = new node(address, content); // starts from last node and uses constructor
  }                                       //  to pass address of previously added node to new node

  node head(address);

  refSort(&head);

  cout<<"The list in ascending order is: "<<endl;

  address = head.next;          //sets address to first node
  while(address != NULL){       //prints
    cout<<(*address).num<<" ";
    address = (*address).next;
  }

  return 0;
}
