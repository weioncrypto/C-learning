// Solution 1
struct ListNode* reverseList(struct ListNode* head){
    if(!head)return head;
    int count = 0;
    int arr[5000];
    while (head != NULL)
    {
        arr[count++] = head->val;
        head = head->next;
    }

    struct ListNode* p = (struct Listnode*)malloc(sizeof(struct ListNode));

    struct ListNode* ret = p;

    count--;

    while(count >= 0){
        p->val = arr[count];
        if(count!=0){
            p->next = (struct Listnode*)malloc(sizeof(struct ListNode));
            p = p->next;
        }

        count--;
    }
    p->next = NULL;
    
    
    return ret;
}

// Solution 2
struct ListNode* reverseList(struct ListNode* head){
    if(!head)return NULL;
    struct ListNode *previous = NULL;
    struct ListNode *current = head;
    struct ListNode* next = head->next;

    while (next != NULL)
    {
        // 當前節點指向上一節點
        current->next = previous;
        // 前一節點設為當前
        previous = current;
        // 當前設為下一個
        current = next;
        
        next = current->next;
    }
    // 最後補上最後一個漏掉的當前節點
    current->next = previous;
    return current;
}
