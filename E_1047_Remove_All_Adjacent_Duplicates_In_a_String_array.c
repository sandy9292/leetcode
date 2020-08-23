
char * removeDuplicates(char * str){
    if(NULL == str)
        return NULL;

	int size = strlen(str);
	if(size == 1)
		return str;
	int idx = 0;
	char *stack= malloc((size+1)*(sizeof(char)));

	while(*str != '\0'){
        if(idx>0){
            if(stack[idx-1] == *str){
                idx--;
            } else {
                stack[idx++] = *str;
            }
        } else {
            stack[idx++] = *str;
        }
		str++;
	}
   	stack[idx] = '\0';
	return stack;
}
