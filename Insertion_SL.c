#include <stdio.h> // Include standard input-output library
#include <stdlib.h> // Include standard library for memory allocation

int count = 0; // Initialize count of nodes to zero

struct node { // Define structure for a node in linked list
  int data; // Data stored in the node
  struct node *next; // Pointer to the next node
};

struct node *create_node(int data) { // Create a new node with given data
  struct node *nn = (struct node *)malloc(sizeof(struct node)); // Allocate memory for the new node
  nn->data = data; // Set data for the new node
  nn->next = NULL; // Initialize next pointer to NULL
  return nn; // Return pointer to the new node
}

void append(struct node **headAddress, int data) { // Append a node to end of linked list
    struct node *nn = create_node(data); // Create a new node with given data
    if (*headAddress == NULL) // If list is empty
        *headAddress = nn; // Set head to point to new node
    else { // If list is not empty
        struct node *temp = *headAddress; // Temporary pointer to traverse list
        while (temp->next != NULL) // Traverse to end of list
            temp = temp->next;
        temp->next = nn; // Append new node to end of list
    }
}

void display(struct node *head) { // Display elements of linked list
    struct node *temp = head; // Temporary pointer to traverse list
    while (temp != NULL) { // Loop until end of list
        printf("%d ", temp->data); // Print data of current node
        temp = temp->next; // Move to next node
    }
    printf("\n"); // Print newline after displaying all elements
}

void Insert_End(struct node **head, int data) { // Insert node at end of linked list
  struct node *temp = *head; // Temporary pointer to traverse list
  struct node *nn = create_node(data); // Create a new node with given data
  if (*head == NULL) // If list is empty
    *head = nn; // Set head to point to new node
  while (temp->next != NULL) // Traverse to end of list
    temp = temp->next;
  temp->next = nn; // Append new node to end of list
}

void Insert_Beg(struct node **head, int data) { // Insert node at beginning of linked list
  struct node *nn = create_node(data); // Create a new node with given data
  if (*head == NULL) // If list is empty
    *head = nn; // Set head to point to new node
  else { // If list is not empty
    nn->next = *head; // Make new node point to current head
    *head = nn; // Update head to point to new node
  }
}

void Insert_pos(struct node **head, int data, int pos) { // Insert node at specified position in linked list
  struct node *nn = create_node(data); // Create a new node with given data
  if (pos > count) // If position is invalid
    printf("The position is invalid"); // Print error message
  else { // If position is valid
    struct node *temp = *head; // Temporary pointer to traverse list
    for (int i = 0; i < pos-1; i++) // Traverse to node before specified position
      temp = temp->next;
    nn->next = temp->next; // Update next pointer of new node
    temp->next = nn; // Insert new node at specified position
  }
}

int main() { // Main function
  int a = 0, data = 0, pos; // Variables for user input
  struct node *head = NULL; // Initialize head pointer to NULL
  printf("Enter number of nodes to be created :"); // Prompt user for number of nodes
  scanf("%d",&count); // Read number of nodes from user
  for(int i=0;i<count;i++) // Loop to input data for each node and append to linked list
    {
      int data; // Variable to store data for each node
      printf("Enter the element :"); // Prompt user for data for current node
      scanf("%d",&data); // Read data for current node
      append(&head,data); // Append node with entered data to linked list
    }
  
  while (a != 4) { // Loop to prompt user for data to insert into linked list
    printf("Enter the data for SLL :"); // Prompt user for data
    scanf("%d", &data); // Read data to be inserted
    printf("Where to insert ?:\n1) Beginning\n2) Position\n3) End\n\n"); // Prompt user to choose insertion location
    scanf("%d", &a); // Read choice from user
    switch (a) // Switch based on user choice
      {
        case 1: // If choice is 1 (insert at beginning)
          {
            Insert_Beg(&head,data); // Insert data at beginning of linked list
            display(head); // Display updated linked list
            break; // Exit switch statement
          }
        case 2: // If choice is 2 (insert at specified position)
          {
            printf("Enter the position to insert :"); // Prompt user for position
            scanf("%d",&pos); // Read position from user
            Insert_pos(&head,data,pos); // Insert data at specified position
            display(head); // Display updated linked list
            break; // Exit switch statement
          }
        case 3: // If choice is 3 (insert at end)
          {
            Insert_End(&head,data); // Insert data at end of linked list
            display(head); // Display updated linked list
            break; // Exit switch statement
          }
        default: // If choice is not 1, 2, or 3
          {
            printf(" Wrong case value \n"); // Print error message
            break; // Exit switch statement
          }
      }
  }
}

