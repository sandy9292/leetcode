char * removeDuplicates(char * S){
    int cur = 0;
    int next = 1;
    int size = strlen(S);
    int finalSize = size;

    
    if(NULL == S || strlen(S) == 1){
        return S;
    }
    
    while(next < size){
        if(S[cur] == S[next]){
            S[next] = '0';
            finalSize--;
            next++;
            S[cur] = '0';
            finalSize--;
            if(cur>0){
                while(cur>0 && S[cur] == '0')
                    cur--;   
            }else{
                cur=next;
                next++;
            }
        } else {
            cur = next;
            next++;
        }
    }
    char *retStr = malloc((finalSize+1)*sizeof(char));
    int j=0;
    for(int i=0;i<size;i++){
        if(S[i] != '0'){
            retStr[j] = S[i];
            j++;
        }
    }
    retStr[j] = '\0';
    return retStr;
}
