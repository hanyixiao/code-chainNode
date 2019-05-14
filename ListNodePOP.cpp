/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        ListNode *temp=head;
        int count=0;
        if(temp!=NULL) 
        {
            temp=temp->next;
            count++;
        }
        ListNode *temp1=head;
        for(int i=count;i>1;i--)
        {
            ListNode *temp2=head;
            for(int j=0;j<i-1;j++)
            {
                temp2=temp2->next;
                if(temp1->val>temp2->val) 
                {
                    int num=temp1->val;
                    temp1->val=temp2->val;
                    temp2->val=num;
                }
            }
            temp1=temp1->next;
        }
        return head;
    }
};
