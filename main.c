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

    ChatLog *focusChat = messageList->content;
    Node *focusNode = adminList;

    for(int i = 0 ; i < len(focusChat->message) ; i++)
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
            return 0;
        }

        focusNode = focusNode->next;
    }
}

int main()
{
    char l = 'A';

    printf("%c", l + 32);
    return 0;
}