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

    ChatLog *focusChat = messageList->content;
    Node *focusNode = adminList;

    for(i = 0 ; i < strlen(focusChat->message) ; i++)
    {
        if(focusChat->message[i] >= 65 && focusChat->message[i] <= 90)
            u++;
        else if(focusChat->message[i] >= 97 && focusChat->message[i] <= 122)
            l++;
    }

    while(focusNode->next != NULL)
    {
        if(focusChat->username == adminList->content || l == u)
        {
            return;
        }

        focusNode = focusNode->next;
    }

    if(l > u)
    {
        for(i = 0 ; i < strlen(focusChat->message) ; i++)
        {
            if(focusChat->message[i] >= 65 && focusChat->message[i] <= 90)
                focusChat->message[i] += 32;
        }
    }
    else if(u > l)
    {
        for(i = 0 ; i < strlen(focusChat->message) ; i++)
        {
            if(focusChat->message[i] >= 97 && focusChat->message[i] <= 122)
                focusChat->message[i] -= 32;
        }
    }
}

int main()
{
    char l = 'A';

    char *s = "puto";

    printf("%c", l + 32);
    printf("%d", strlen(s));
    return 0;
}