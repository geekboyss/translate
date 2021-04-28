#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILENAME "./dict.txt"

typedef struct _dict
{
    char *key;
    char *content;
} DICT;

FILE *open_file();//���ļ�
int get_file_line();//��ȡ�ļ�����
void dict_init(DICT **tmp,int n);//��ʼ���ṹ��
void fiter_buf(char *buf);//ȥ����Ч�ַ�
int search_dict(char *cmd,DICT * dict,int n,char *content);

int main()
{
    DICT *dict = NULL;
    int n = 0;
    n = get_file_line();
    printf("n = %d\n",n);
    dict_init(&dict,n);
    char cmd[256] = "";
    char content[256] = "";
    int ret = 0;

    while (1)
    {
        printf("�����뵥��:");
        fgets(cmd,sizeof(cmd),stdin);
        cmd[strlen(cmd)-1] = 0;//��\nȥ��
        ret = search_dict(cmd,dict,n,content);//����
        if (ret == 0)
        {
            printf("not trant\n");
        } else
        {
            printf("����Ϊ:%s\n",content);
        }
        
    }
    return 0;
    
}

FILE *open_file()
{
    FILE *fp = fopen(FILENAME,"r");
    if (!fp)
    {
        perror("");
        return NULL;
    }
    return fp;
    
}
int get_file_line()
{
    int i = 0;
    char buf[256] = "";
    char *q = NULL;

    FILE *fp = open_file();
    while (1)
    {
        q = fgets(buf,sizeof(buf),fp);//��ȡһ�е���
        if (q == NULL)
            break;
        q = fgets(buf,sizeof(buf),fp);//��ȡһ�з���
        if (q == NULL)
            break;
        i++;//������Ϊһ���ṹ��
    }
    fclose(fp);
    return i;
}
void dict_init(DICT **tmp,int n)
{
    DICT *p;
    p = malloc(sizeof(DICT)*n);
    char *q = NULL;//�����ж��Ƿ�����������ѭ��
    char buf[256] = "";
    int i = 0;
    FILE *fp = open_file();

    while (1)
    {
        q = fgets(buf,sizeof(buf),fp);
        if (q == NULL)
            break;
        fiter_buf(buf);//ȥ�����ʺ������Ч�ַ�
        p[i].key = malloc(strlen(buf)+1);
        strcpy(p[i].key,buf+1);//��#��������ݿ���

        q = fgets(buf,sizeof(buf),fp);//��ȡ��Ӧ�ķ���
        if (q == NULL)
            break;
        p[i].content = malloc(sizeof(buf)+1);
        strcpy(p[i].content,buf+6);
        i++;
        
    }
    fclose(fp);
    *tmp = p;
}
void fiter_buf(char *buf)
{
    int n = strlen(buf) - 1;
    while (buf[n] == ' ' || buf[n] == '\n' || buf[n] == '\r' || buf[n] == '\t')
    {
        n--;
    }
    buf[n + 1] = 0;
}
int search_dict(char *cmd,DICT *dict,int n,char *content)
{
    for (size_t i = 0; i < n; i++)
    {
        if (strcmp(cmd,dict[i].key) == 0)
        {
            strcpy(content,dict[i].content);
            return 1;
        }
        
    }
    return 0;
    
}
