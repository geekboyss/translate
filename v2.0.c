#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// hello  ���
//world  ����
typedef struct _dict
{
        char *key;
        char *content;
}DICT;
void dict_init(DICT **tmp)
{
        DICT *p;
        p = malloc(sizeof(DICT) * 2);
        p[0].key = malloc(strlen("hello")+1);
        strcpy(p[0].key,"hello");
        p[0].content = malloc(strlen("���") + 1);
        strcpy(p[0].content, "���");
        p[1].key = malloc(strlen("world") + 1);
        strcpy(p[1].key, "world");
        p[1].content = malloc(strlen("����") + 1);
        strcpy(p[1].content, "����");
        *tmp = p;
}
int search_dict(char *cmd, DICT * dict, int n, char *content)
{
        for (int i = 0; i < n; i++)
        {
               if (strcmp(cmd, dict[i].key) == 0)
               {
                       strcpy(content,dict[i].content);
                       return 1;
               }
        
        }
        return 0;
}
int main()
{
        DICT *dict=NULL;
        dict_init(&dict);
        char cmd[256] = "";
        char content[256] = "";
        int ret = 0;
        while (1)
        {
               printf("�����뵥��:");
               fgets(cmd,sizeof(cmd),stdin);
               cmd[strlen(cmd) - 1] = 0;//�����һ���ֽ�ȥ��
               ret = search_dict(cmd,dict,2, content);//����
               if (ret == 0)
               {
                       printf("not trant\n");
               }
               else
               {
                       printf("����Ϊ: %s\n", content);
               }
        
        }
        system("pause");
        return 0;
}