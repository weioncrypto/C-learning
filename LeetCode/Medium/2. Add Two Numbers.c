/*
Runtime: 15 ms, faster than 81.59% of C online submissions for Add Two Numbers.
Memory Usage: 8 MB, less than 6.71% of C online submissions for Add Two Numbers.
*/
#define MAX(a, b) ((a) > (b) ? (a) : (b))
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int ret[102] = {0};
    int count = 0, max = 0;
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* result = temp;
    while (l1 || l2)
    {
        if(l1){
            ret[count] += l1->val;
            l1 = l1->next;
        }

        if(l2){
            ret[count] += l2->val;
            l2 = l2->next;
        }
        
        // 在此處理
        if(ret[count] >= 10){
            ret[count] -= 10;
            ret[count+1]+= 1;
        }

        temp->next = (struct ListNode*)malloc(sizeof(struct ListNode)); //理論最後一位值
        temp->val = ret[count];
        if(l1 || l2)temp = temp->next;
        count++;
        max++;
    }

    if(ret[max] == 1){
        temp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp = temp->next;
        temp->val = 1;
        temp->next = NULL;
    }else{
        temp->next = NULL;
    }
    
    return result;
}
