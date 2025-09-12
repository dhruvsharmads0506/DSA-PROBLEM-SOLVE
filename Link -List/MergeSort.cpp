


/* Author : Dhruv Sharma
   Date : 12-Sep-2025
   Description : For a given Singly Linked List of integers, sort the list using the 'Merge Sort' algorithm  */



/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/
// for find middle of the link-List
node* findmid(node* head) {
    node* slow = head;
    node* fast = head->next;
    while(fast!=NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;    
    }
    return slow;
}

// merge link-list
node* merge(node* left, node* right) {
    if(right == NULL) {
        return left;
    }
    if(left == NULL) {
        return right;
    }
    node* ans = new node(-1);
    node* temp = ans;
    while(left != NULL && right!=NULL) {
        if(left->data < right->data) {
            temp -> next = left;
            temp = left;
            left = left-> next;


        }
        else {
            temp -> next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left != NULL) {
           temp -> next = left;
            temp = left;
            left = left-> next;
    }
    while(right!=NULL) {
         temp -> next = right;
            temp = right;
            right = right->next;
    }
    return ans->next;
}

// mergesortfucntion
node* mergeSort(node *head) {
    if(head == NULL || head->next==NULL) {
        return head;
    }
    node* mid = findmid(head);
    node* left = head; 
    node* right = mid->next;
    mid-> next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);


    node* result = merge(left,right);
    return result;
}

