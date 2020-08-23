
typedef struct node{
    char val;
    struct node *next;
}stackNode;

typedef stackNode * stack;

stackNode *createNewNode(char C){
    stackNode *newNode = malloc(sizeof(stackNode));
    newNode->val = C;
    newNode->next = NULL;
    return newNode;
}

void push(stack *S, char C){
    stackNode * newNode = createNewNode(C);
    newNode->next = *S;
    *S = newNode;
    return;
}

char pop(stack *S){
    if(NULL == *S)
        return (char)0;
    stackNode *tmp = *S;
    char retVal;
    if(NULL != tmp){
        retVal = tmp->val;
        *S = tmp->next;
        free(tmp);
    } else {
        retVal = (char)0;
    }
    return retVal;
}

char peep(stack S){
    if(S == NULL)
        return (char)0;
    else
        return S->val;
}

void printStack(stack S){
    while(S){
        printf("%c", S->val);
        S=S->next;
    }
    return;
}

char * removeDuplicates(char * str){
    if(NULL == str)
        return NULL;
    
    stack S = NULL;
    int len = 0;
    char *retStr = NULL;
    char *s = str;
    while(*s != '\0'){
        if(*s == peep(S)){
            pop(&S);
            len--;
        } else {
            push(&S, *s);
            len++;
        }
        s++;
    }
    retStr = malloc(len+1);
    int i=0;
    retStr[len] = '\0';
    while(len > 0){
        retStr[len-1] = pop(&S);
        len--;
    }
    return retStr;
}
