/*
Runtime: 0 ms, faster than 100.00% of C online submissions for Letter Combinations of a Phone Number.
Memory Usage: 6.3 MB, less than 16.92% of C online submissions for Letter Combinations of a Phone Number.
*/
char ** letterCombinations(char * digits, int* returnSize){
    int n = strlen(digits);
    char **ret = (char**)malloc(sizeof(char*));
    if(n == 0){
        *returnSize = 0;
        return ret;
    }

    char temp[8][5] = {{'a','b','c','\0'},{'d','e','f','\0'},{'g','h','i','\0'},
                       {'j','k','l','\0'},{'m','n','o','\0'},{'p','q','r','s','\0'},
                       {'t','u','v','\0'},{'w','x','y','z','\0'}};

    int count = 0;                   
    if(n == 1){
        for(int i=0;temp[(int)digits[0] - 50][i]!='\0';i++){
            ret = (char**)realloc(ret,sizeof(char*)*(count+1));
            ret[count] = (char*)malloc(sizeof(char)*2);
            ret[count][0] = temp[(int)digits[0] - 50][count];
            ret[count][1] = '\0';
            //printf("%c ",temp[(int)digits[0] - 50][count]);
            count++;
        }
    }else if(n == 2){
        for(int i=0;temp[(int)digits[0] - 50][i]!='\0';i++){
            for(int j=0;temp[(int)digits[1] - 50][j]!='\0';j++){
                ret = (char**)realloc(ret,sizeof(char*)*(count+1));
                //printf("%c %c\n",temp[(int)digits[0] - 50][i],temp[(int)digits[1] - 50][j]);
                ret[count] = (char*)malloc(sizeof(char)*3);
                ret[count][0] = temp[(int)digits[0] - 50][i];
                ret[count][1] = temp[(int)digits[1] - 50][j];
                ret[count][2] = '\0';
                count++;
            }
        }
    }else if(n == 3){
        for(int i=0;temp[(int)digits[0] - 50][i]!='\0';i++){
            for(int j=0;temp[(int)digits[1] - 50][j]!='\0';j++){
                for(int k=0;temp[(int)digits[2] - 50][k]!='\0';k++){
                    ret = (char**)realloc(ret,sizeof(char*)*(count+1));
                    //printf("%c %c %c\n",temp[(int)digits[0] - 50][i],temp[(int)digits[1] - 50][j],temp[(int)digits[2] - 50][k]);
                    ret[count] = (char*)malloc(sizeof(char)*4);
                    ret[count][0] = temp[(int)digits[0] - 50][i];
                    ret[count][1] = temp[(int)digits[1] - 50][j];
                    ret[count][2] = temp[(int)digits[2] - 50][k];
                    ret[count][3] = '\0';
                    count++;
                }
            }
        }
    }else{
        for(int i=0;temp[(int)digits[0] - 50][i]!='\0';i++){
            for(int j=0;temp[(int)digits[1] - 50][j]!='\0';j++){
                for(int k=0;temp[(int)digits[2] - 50][k]!='\0';k++){
                    for(int l=0;temp[(int)digits[3] - 50][l]!='\0';l++){
                        ret = (char**)realloc(ret,sizeof(char*)*(count+1));
                        //printf("%c %c %c %c\n",temp[(int)digits[0] - 50][i],temp[(int)digits[1] - 50][j],temp[(int)digits[2] - 50][k],temp[(int)digits[3] - 50][l]);
                        ret[count] = (char*)malloc(sizeof(char)*5);
                        ret[count][0] = temp[(int)digits[0] - 50][i];
                        ret[count][1] = temp[(int)digits[1] - 50][j];
                        ret[count][2] = temp[(int)digits[2] - 50][k];
                        ret[count][3] = temp[(int)digits[3] - 50][l];
                        ret[count][4] = '\0';
                        count++;
                    }
                }
            }
        }
    }
    //printf("%c ",temp[(int)digits[0] - 50][count]);
    *returnSize = count;
    return ret;
}
