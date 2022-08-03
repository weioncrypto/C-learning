/*
Runtime: 14 ms, faster than 48.85% of C online submissions for Find First and Last Position of Element in Sorted Array.
Memory Usage: 7.7 MB, less than 11.17% of C online submissions for Find First and Last Position of Element in Sorted Array.
*/
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void binarySearch(int* nums, int left, int right, int target,bool* find, int* val) {
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) {
            *val = mid;
            *find = true;
            break;
        }

        if(nums[mid] > target) {
            right = mid - 1;
        }

        if(nums[mid] < target) {
            left = mid + 1;
        }
    }
}

void binarySearch_left(int* nums, int left, int right, int target,bool find, int* val) {
    find = false;

    int mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if(nums[mid] == target) {
            *val = mid;
            find = true;
            break;
        }

        if(nums[mid] > target) {
            right = mid - 1;
        }

        if(nums[mid] < target) {
            left = mid + 1;
        }
    }
    if(find == false)return;
    binarySearch_left(nums, left, mid - 1, target, find, val);
}

void binarySearch_right(int* nums, int left, int right, int target,bool find, int* val) {
    find = false;

    int mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if(nums[mid] == target) {
            *val = mid;
            find = true;
            break;
        }

        if(nums[mid] > target) {
            right = mid - 1;
        }

        if(nums[mid] < target) {
            left = mid + 1;
        }
    }
    if(find == false)return;
    binarySearch_right(nums, mid + 1, right, target, find, val);
}

int threeMAX(int a, int b, int c) {
    if(b == INT32_MIN && c == INT32_MIN)
        return a;

    if(b == INT32_MIN)
        return MAX(a,c);

    if(c == INT32_MIN) 
        return MAX(a,b);

    return MAX(a,MAX(b,c));
}

int threeMIN(int a, int b, int c) {
    if(b == INT32_MIN && c == INT32_MIN)
        return a;

    if(b == INT32_MIN)
        return MIN(a,c);
    
    if(c == INT32_MIN)
        return MIN(a,b);
    
    return MIN(a,MIN(b,c));
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int left = 0, right = numsSize - 1, mid;
    int* ret = (int*)malloc(sizeof(int) * 2);
    ret[0] = ret[1] = -1;
    *returnSize = 2;

    if(numsSize == 0)
        return ret;

    int tmp;
    bool find = false;

    binarySearch(nums, 0, numsSize - 1, target, &find, &tmp);

    if(!find)
        return ret;

    int first = INT32_MIN, second = INT32_MIN;

    binarySearch_left(nums, 0, tmp - 1, target, false, &first);
    binarySearch_right(nums, tmp + 1, numsSize - 1, target, false, &second);
    
    ret[0] = threeMIN(tmp,first,second);
    ret[1] = threeMAX(tmp,first,second);
    
    return ret;
}
