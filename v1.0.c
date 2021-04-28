#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//hello 你好 world 世界

typedef struct _dict
{
    char key[256];
    char content[256];
} DICT;

//函数定义
void dict_init(DICT **tmp);
int search_dict(char *cmd,DICT *dict,int n,char *content);

int main()
{
    DICT *dict = NULL;
    dict_init(&dict);
    char cmd[256] = "";
    char content[256] = "";
    int ret = 0;

    while (1)
    {
        printf("请输入单词:");
        fgets(cmd,sizeof(cmd),stdin);//使用fgets会录入\n
        cmd[strlen(cmd)-1] = 0;//将最后一个字符去掉\n
        ret = search_dict(cmd,dict,2,content);
        if (ret == 1)
        {
            printf("not trant\n");

        } else {
            printf("trant : %s\n",content);
        }
        
    }
    
}

void dict_init(DICT **tmp)
{
    DICT *p;

    p = malloc(sizeof(DICT)*2);
    strcpy(p[0].key,"hello");
    strcpy(p[0].content,"你好");
    strcpy(p[1].key,"world");
    strcpy(p[1].content,"世界");
    *tmp = p;
}

int search_dict(char *cmd,DICT *dict,int n,char *content)
{
    for (size_t i = 0; i < n; i++)
    {
        if (strcmp(cmd,dict[i].key)==0)
        {
            strcpy(content,dict[i].content);
            return 0;
        }
        
    }
    return 1;
    
}