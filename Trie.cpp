#include<bits/stdc++.h>
using namespace std;

/*
https://codeforces.com/contest/271/submission/74261703
https://codeforces.com/contest/665/submission/74366182
*/


struct node{
    bool mark;
    node* next[27];
    node(){
        mark = false;
        for(int i=0; i<26; i++)
            next[i] = NULL;
    }
} *root;

void update(char* str, int len){
    node* clone = root;
    for(int i=0; i<len; i++){
        int edge = str[i] - 'a';
        if(clone -> next[edge] == NULL)
           clone -> next[edge] = new node();
        clone = clone -> next[edge];
    }
    clone -> mark = true;
}

bool search(char* str, int len){
    node* clone = root;
    for(int i=0; i<len; i++){
        int edge = str[i] - 'a';
        if(clone -> next[edge] == NULL)
            return false;
        clone = clone -> next[edge];
    }
    return clone -> mark;
}

void del(node* cur){
    for(int i=0; i<26; i++){
        if(cur -> next[i])
            del(cur -> next[i]);
    }
    delete(cur);
}


int main(){

    root = new node();
    printf("Enter word number : ");
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        char str[100];
        scanf("%s", str);
        update(str, strlen(str));
    }

    printf("Enter number of query : ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        char str[100];
        scanf("%s", str);
        if(search(str, strlen(str)))
            printf("Found\n");
        else printf("Not found!\n");
    }
    del(root);

return 0;
}
