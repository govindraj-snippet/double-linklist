# include <iostream>
# include <vector>
using namespace std ; 

class node {
    public :
    int data ; 
    node * next ; 
    node * back ; 

    node(int data1 , node * next1 , node * back1 ){
        data = data1 ; 
        next  = next1 ; 
        back = back1 ;
    }

    node(int data1 ){
        data = data1 ; 
        next = nullptr ; 
        back = nullptr ; 

    }

};
node * arr2dll( vector <int >arr ){
    node * head  = new node(arr[0]) ;
    node * prev = head ; 
    for(int i = 1 ; i < arr.size() ; i++ ){
        node * temp = new node(arr[i] , nullptr , prev );
        prev -> next = temp ; 
        prev  = temp ; 

    }
    return head ; 



}
node * deletebeg( node * head ){
    if(head == nullptr ) return nullptr ; 
    if(head -> next == nullptr  ) return nullptr ; 
    node * temp = head ; 
    head = head -> next ; 
    head -> back = nullptr ; 
    delete temp ; 
    return head ; 
}
node * deletetail(node * head ){
    if(head == nullptr || head -> next == nullptr )return nullptr ; 

    node * temp = head ; 

    while(temp -> next -> next != nullptr ){
       temp = temp -> next ; 
       
    }
     temp -> next -> back = nullptr ; 
        temp -> next =  nullptr ; 

    delete temp -> next ;
    return head; 
}


void  printll(node * head ){
    while(head != nullptr ){
        cout << head -> data << endl ;
        head = head -> next ; 
    }
}
int getlen(node * head ){
    int cnt = 0 ; 
    while(head != nullptr ){
        cnt++ ; 
        head = head -> next ; 
    }
    return cnt ;
}

node * deletek(node * head , int k ){
    if(k == 0 )return nullptr; 

    node * knode = head ; 

    int cnt = 0 ; 
    while(knode != nullptr ){
        cnt ++ ; 
        if(cnt == k )break ; 
        knode = knode -> next ; 
    }
    node * prev = knode -> back ; 
    node * front = knode -> next ; 
    if(prev == nullptr && front == nullptr ){
        delete head ; 
        return nullptr ; 
    }
    else if (prev == nullptr ){
        node * temp = head ; 
        head = head -> next ; 
        delete temp ; 
        return head ; 
    }
    else if(front == nullptr ) {
        return deletetail(head); 
    }
    
        prev -> next = front ; 
        front-> back = prev ; 
        delete knode ; 
        return head ; 
    
    return head ; 
    
}
void deletenode(node * temp ){
    node * prev = temp -> back ; 
    node * front = temp -> next ; 

    if(front == nullptr ){
        prev -> next = nullptr ; 
        temp -> back = nullptr ; 
        delete temp ; 
        return ; 

    }
    prev -> next = front ; 
    front -> back = prev ;
    temp -> next = nullptr ; 
    temp -> back = nullptr ; 
    delete temp ; 
}

node * insertbefhead( node * head , int val ){
    node * newhead =  new node(val);
    newhead -> next = head ; 
    head -> back = newhead ; 
    return newhead ; 

    
}
node * insertafthead (node * head ,int val  ){
    node * newnode = new node (val , head ->next , head );
    head -> next -> back = newnode ; 
    head -> next = newnode ; 
    return head ; 
    

}
node*insertbeftail(node * head  , int val ){
   
    if(head -> next == nullptr ){
        return insertbefhead(head , val );
    }
    
    node * temp = head ; 
    while(temp -> next  != nullptr){
        temp = temp -> next ; 
    }
    node * prev = temp -> back ; 
    node * newnode =   new node(val , temp , prev );


    prev -> next = newnode ; 
    temp -> back = newnode ; 
    return head ; 
    
    
}
node * insertbefk(node * head , int k , int val ){
    if(k==1){
        insertbefhead(head , val );
    }
    node * temp = head ; 
    int cnt = 0 ; 
    while(temp != nullptr ){
        cnt = cnt + 1 ; 
        if(cnt == k ){
            break ; 
        }
        temp =temp -> next ; 
    
    }
    node * prev = temp -> back;
    node * newnode = new node (val , temp , prev );
    prev -> next = newnode ; 
    temp -> back = newnode ; 
    return head ; 
}
int main(){
    vector <int> arr = {1,2,3,4,5};

   node * head  = arr2dll(arr);
   node * newhead = insertbefk(head , 69 , 3  );
   printll(newhead);
   
   
   

   return 0 ; 

}