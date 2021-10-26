/*Question 1: Merging Node of a Linked List
You’re given the pointer to the head nodes of two linked lists that merge together at some node. Find the node at which this merger happens. The two head nodes will be different and neither will be NULL.

For example, both lists below merge at point x.

[List #1] a--->b--->c
                     \
                      x--->y--->z--->NULL
                     /
[List #2]      p--->q
 
You have to complete the int FindMergeNode(Node* headA, Node* headB) method which takes two arguments - the heads of the linked lists.

Consider Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }

Find the node at which both lists merge and return the data of that node. 
*/

int FindMergeNode(Node* headA, Node* headB){
	

	for (int i =0; headA->next != headB->next || (headA->NULL || headB->NULL); i++){
	
	headA = headA->next;
	headB = headB->next;
	
	}
 	
	if (headA->NULL || headB->NULL){
	
	return -1;
	}
	
	return headA.data; // maybe that's wrong but I think that another way to answer this part is returning "i" 'cause "i" is the point when both list merge 

}


// this funnction calculate the lengh of the Liked List

int tamList(Node* head){
int tam=0;
for (int i =0; head->next != NULL; i++){
tam++;
head = head->next;
}
return tam;
}

