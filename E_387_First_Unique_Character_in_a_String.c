

int firstUniqChar(char * s){
    if(NULL == s)
        return -1;
    
    int alpha[26] = {0};
    
    char *str = s;
    
    while(*str != '\0'){
        alpha[*str-'a']++;
        str++;
    }
    str = s;
    while(*str != '\0'){
        if(alpha[*str-'a'] == 1)
            return str-s;
        str++;
    }
    return -1;

}
