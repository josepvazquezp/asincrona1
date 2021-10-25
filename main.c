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

    Node *focusLog = messageList;

    while(focusLog != NULL)
    {
        ChatLog *focusChat = messageList->content;
        Node *focusNode = adminList;

        while(focusNode != NULL)
        {
            if(strcmp(focusChat->username, focusNode->content) == 0)
            {
                return;
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
            return;

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
        
        focusChat->message = malloc(sizeof(ChatLog));
        strcpy(focusChat->message, f);

        focusLog = focusLog->next;

    }
    
}

void display(Node *m)
{
    ChatLog *focusChat = m->content;
    int i = 0;

    //printf("%s", focusChat->message);
    
    while(focusChat->message[i] != '\0')
    {
        printf("%c", focusChat->message[i]);
        i++;
    }

    printf("\n");
}

int main()
{
    Node *m = malloc(sizeof(Node));
    Node *a = malloc(sizeof(Node));

    ChatLog *prueba = malloc(sizeof(ChatLog));

    prueba->message = "Hola mundO";
    prueba->username = "bob";

    m->content = prueba;
    m->next = NULL;

    a->content = "admin";
    a->next = NULL;

    display(m);
    SanitizeChatLog(m, a);
    display(m);

    return 0;
}