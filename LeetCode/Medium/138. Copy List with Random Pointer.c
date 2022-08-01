struct Node* copyRandomList(struct Node* head) {
    if(!head)return NULL;
	struct Node* ptr = head;

    // 先在每個節點後方新增一複製節點
    while (ptr)
    {
        struct Node* new = (struct Node*)malloc(sizeof(struct Node));
        new->random = NULL;
        new->val = ptr->val;
        new->next = ptr->next;
        ptr->next = new;
        ptr = new->next;
    }

    ptr = head;
    // 添加隨機指針
    while (ptr)
    {
        if(ptr->random)ptr->next->random = ptr->random->next;
        ptr = ptr->next->next;
    }

    ptr = head;
    struct Node* res = head->next;
    // 斷開原先節點
    while (ptr)
    {
        struct Node* tmp = ptr->next;
        ptr->next = tmp->next;
        if(tmp->next)tmp->next = tmp->next->next;
        ptr = ptr->next;
    }
    
    return res;
}
