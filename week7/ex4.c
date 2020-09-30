#include<stdio.h>
void* myrealloc(void* ptr,int newSize){
    if(ptr==NULL) malloc(newSize);
    if (newSize==0) return NULL;
    
    void* newPtr = malloc(newSize);
    memcpy(newPtr, ptr, newSize);
    free(ptr);
    return newPtr;
}
int main(){
    void* array =malloc(3*sizeof(int));
    array=myrealloc(array,10);
    return 0;
}