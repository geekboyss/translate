#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//hello ��� world ����

typedef struct _dict
{
    char key[256];
    char content[256];
} DICT;

//��������
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
        printf("�����뵥��:");
        fgets(cmd,sizeof(cmd),stdin);//ʹ��fgets��¼��\n
        cmd[strlen(cmd)-1] = 0;//�����һ���ַ�ȥ��\n
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
    strcpy(p[0].content,"���");
    strcpy(p[1].key,"world");
    strcpy(p[1].content,"����");
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