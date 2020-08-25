typedef struct node1{
    int val;
    int idx;
}node;

int cmp(const void *p, const void *q){
    node *l = (node *)p;
    node *r = (node *)q;
    
    return l->val - r->val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    if(NULL == nums || numsSize == 0){
        *returnSize = 0;
        return NULL;
    }
    
    int *retArr = malloc(numsSize*sizeof(int));
    *returnSize = numsSize;
    
    node arr[numsSize];
    int i;
    
    for(i=0;i<numsSize;i++){
        arr[i].val = nums[i];
        arr[i].idx = i;
     }
    
    qsort(arr, numsSize, sizeof(node), cmp);
    
    for(i=0;i<numsSize;i++){
        retArr[arr[i].idx] = i;
        if(i!=0 && arr[i-1].val == arr[i].val)
            retArr[arr[i].idx] = retArr[arr[i-1].idx];
    }
    return retArr;

}
