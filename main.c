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

    while(focusNode->next != NULL)
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

    for(i = 0 ; i < c ; i++)
    {
        if(l > u && focusChat->message[i] >= 65 && focusChat->message[i] <= 90)
            focusChat->message[i] += 32;
        else if(u > l && focusChat->message[i] >= 97 && focusChat->message[i] <= 122)
            focusChat->message[i] -= 32;
    }

}

int main()
{
    char *s = "hola mundo";

    return 0;
}