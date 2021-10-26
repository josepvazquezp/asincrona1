#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct chatLog
{
  char* message;
  char* username;
} ChatLog;

typedef struct node
{
  void *content;
  struct node *next;
} Node;

void SanitizeChatLog(Node *messageList, Node *adminList)
{
    int l = 0;
    int u = 0;
    int i;
    int flag = 0;

    Node *focusLog = messageList;

    while(focusLog != NULL)
    {
        l = 0;
        u = 0;

        ChatLog *focusChat = focusLog->content;
        Node *focusNode = adminList;

        while(focusNode != NULL)
        {
            if(strcmp(focusChat->username, focusNode->content) == 0)
            {
                flag = 1;
                break;
            }

            focusNode = focusNode->next;
        }

        int c = strlen(focusChat->message);

        for(i = 0 ; i < c ; i++)
        {
            if(focusChat->message[i] >= 65 && focusChat->message[i] <= 90)
                u++;
            else if(focusChat->message[i] >= 97 && focusChat->message[i] <= 122)
                l++;
        }

        if(l == u)
            flag = 1;
    
        
        if(flag == 0)
        {
            char f[100];

            for(i = 0 ; i < c ; i++)
            {
                f[i] = focusChat->message[i];
                if(l > u && focusChat->message[i] >= 65 && focusChat->message[i] <= 90)
                    f[i] += 32;
                else if(u > l && focusChat->message[i] >= 97 && focusChat->message[i] <= 122)
                    f[i] -= 32;  
            }

            f[i] = '\0';
            
            focusChat->message = malloc(sizeof(f));
            strcpy(focusChat->message, f);
        }
        else if(flag == 1)
            flag = 0;

        focusLog = focusLog->next;

    }
    
}

void display(Node *m)
{
    Node *focusLog = m;
    //int i = 0;

   
    while(focusLog != NULL)
    {
        ChatLog *focusChat = focusLog->content;
        printf("%s\n", focusChat->message);
        
        // while(focusChat->message[i] != '\0')
        // {
        //     printf("%c", focusChat->message[i]);
        //     i++;
        // }

        //printf("\n");

        focusLog = focusLog->next;

    }
}

int main()
{
    Node *m = malloc(sizeof(Node));
    Node *a = malloc(sizeof(Node));

    Node *m2 = malloc(sizeof(Node));

    ChatLog *prueba = malloc(sizeof(ChatLog));
    ChatLog *p2 = malloc(sizeof(ChatLog));

    ChatLog *p3 = malloc(sizeof(ChatLog));
    ChatLog *p4 = malloc(sizeof(ChatLog));

    Node *m3 = malloc(sizeof(Node));
    Node *m4 = malloc(sizeof(Node));

    prueba->message = "Hola mundO";
    prueba->username = "bob";

    m->content = prueba;
    m->next = m2;

    a->content = "Admin";
    a->next = NULL;

    p2->message = "ADIOS A todos";
    p2->username = "alice";

    m2->content = p2;
    m2->next = m3;

    p3->message = "HoLa";
    p3->username = "Ralph";

    m3->content = p3;
    m3->next = m4;
    
    p4->message = "ESTO es UNA PRUEBA";
    p4->username = "Admin";

    m4->content = p4;
    m4->next = NULL;

    display(m);
    SanitizeChatLog(m, a);
    display(m);

    return 0;
}