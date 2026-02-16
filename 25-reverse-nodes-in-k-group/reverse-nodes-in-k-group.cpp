/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode*temp=head;
      int cnt=0;
      //check if k node exist
      while(cnt<k){
        if(temp==NULL){
            return head;
        }
        temp=temp->next;
        cnt++;
      }
      //recursively rest of LL
     ListNode* prevNode=reverseKGroup(temp,k);
    //Reverse the curret node
    temp=head;
    cnt=0;
    while(cnt<k){
        ListNode*next=temp->next;
        temp->next=prevNode;
        prevNode=temp;
        temp=next;
        cnt++;
    }
    return prevNode;
    }
};