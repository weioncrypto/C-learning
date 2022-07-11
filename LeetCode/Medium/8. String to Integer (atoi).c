// Might not be a good problem, so many boundary conditions are unknown.

int myAtoi(char * s){
    int left = 0;
    long long temp = 0;   //累積的值
    long long ret[200] = {0};
    int count = 0;

    int num[200] = {0};
    int sign = 0;

    int flag = 0,flag_dot = 0;
    for(int i = 0; i < strlen(s) ; i++){
        char c = s[i];
        if(c == ' ')continue;

        if(c == '.')flag_dot = 1;

        // 是個數字
        if((int)c >= 48 && (int)c <= 57 && flag_dot == 0){
            temp = temp*10 + (int)c - 48;
            flag = 1;
            if(left == 0)num[sign++] = 1;
        }else if(flag == 1 && flag_dot == 0){
            ret[count++] = temp;
            printf("%d %d\n",count,temp);
            temp = 0;
            flag = 0;
        }

        if(flag == 1 && i == strlen(s) - 1)ret[count++] = temp;

        if(c == '-'){
            if (!isdigit(s[i+1]))
                return 0;
            num[sign] = -1;
            sign++;
            flag_dot = 0;
        }else if(c == '+'){
            if (!isdigit(s[i+1]))
                return 0;
            num[sign] = 1;
            sign++;
            flag_dot = 0;
        }

        left = 1;
    }

    for(int i=0;i<10;i++)printf("%4d ",ret[i]);
    printf("\n");
    for(int i=0;i<10;i++)printf("%4d ",num[i]);
    printf("\n");

    long long sum = 0;
    for(int i = 0 ; i < count ; i++){
        if(num[i] == 0)return 0;

        if( ret[i] * num[i] > INT32_MAX){
            sum += INT32_MAX;
        }else if(ret[i] * num[i] < INT32_MIN){
            sum += INT32_MIN;
        }else{
            sum += ret[i] * num[i];
        }
    }

    if(sum > INT32_MAX || sum < INT32_MIN)return 0;
    return sum;
}
