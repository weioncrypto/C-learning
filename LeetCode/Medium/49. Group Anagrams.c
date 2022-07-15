int key_cmp(void* a, void*b){
    return *((char*)a) - *((char*)b);
}
char *** groupAnagrams(char ** strs, int strsSize , int* returnSize, int** returnColumnSizes){ 
    char** key = calloc(10000,sizeof(char*));           // sort後的矩陣
    bool* use = (bool*)malloc(sizeof(bool) * strsSize); // 已經被排序與否
    char*** ret = calloc(10000,sizeof(char**));         // 返回矩陣
    int* index = calloc(10000, sizeof(int));            // 用來記錄returnColumn
    memset(use,false,strsSize);
    int count = 0, count_num;

    // 針對字串進行按大小排序
    for(int i = 0 ; i < strsSize ; i++)
    {
        key[i] = malloc((strlen(strs[i])+ 1) * sizeof(char));
        strcpy(key[i], strs[i]);
        qsort(key[i], strlen(key[i]), sizeof(char), key_cmp);
    }
        
    // 以首位為標記向後尋找，有的話就分配記憶體並標記
    for(int i = 0 ; i < strsSize ; i++){
        count_num = 0;
        if(use[i])continue;
        ret[count] = (char**)malloc(sizeof(char*) * (count_num + 1));
        ret[count][count_num] = (char*)malloc(sizeof(char) * (strlen(strs[i]) + 1));
        strcpy(ret[count][count_num], strs[i]);
        count_num ++;

        for(int j = i + 1 ; j < strsSize ; j++)
        {
            if(use[j])continue;
            if(strcmp(key[i],key[j]) != 0)continue;

            // 符合的對象
            ret[count] = (char**)realloc(ret[count],sizeof(char*) * (count_num + 1));
            ret[count][count_num] = (char*)malloc(sizeof(char) * (strlen(strs[i]) + 1) );
            strcpy(ret[count][count_num] , strs[j]);
            use[j] = true;
            count_num++;
        }
        index[count] = count_num;
        count++;
    }
    
    *returnSize = count;
    *returnColumnSizes = calloc((*returnSize),sizeof(int));
    for (int i = 0; i < *returnSize; i++)   
		returnColumnSizes[0][i] = index[i];
    return ret;
}
