/*
Runtime: 5 ms, faster than 40.91% of C online submissions for Remove Nth Node From End of List.
Memory Usage: 5.7 MB, less than 74.21% of C online submissions for Remove Nth Node From End of List. 
*/
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* p = head;
    if(!head->next)return NULL;
    int count = 0;

    while (p != NULL)
    {
        count++;
        p = p->next;
    }

    // 移除首位元素直接回傳
    if(n == count)
        return head->next;


    p = head;
    int temp = 0;
    while (p != NULL)
    {
        if(temp == count - n - 1)
            p->next = p->next->next;
        temp++;
        p = p->next;
    }
    return head;
}



// 用兩指標同步運行，left會停在刪除元素前
/*
Runtime: 3 ms, faster than 64.79% of C online submissions for Remove Nth Node From End of List.
Memory Usage: 5.8 MB, less than 74.21% of C online submissions for Remove Nth Node From End of List.
*/
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* left = NULL, *right = head;

    while (right != NULL)
    {
        if(left != NULL) left = left->next;
        if(n-- == 0) left = head;
        right = right->next;
    }

    //left從未移動，那就是第一個元素被刪除
    if(left == NULL)return head->next;  

    // 若移動，left會剛好停在刪除元素前面
    left->next = left->next->next;
    return head;
}
