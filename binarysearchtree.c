// Including standard input/output(library) for accessing functions like printf, scanf etc.
#include <stdio.h>
// Including standard library for accessing functions for allocating dynamic memory(like malloc ,calloc etc)
#include <stdlib.h>

// declaring a structure for node
struct node
{
    int key;
    struct node *left;
    struct node *right;
};
// declaring a newnode(From step 13 to 21, we are making a node(named as newnode))
struct node *newnode(int item)
{
    // declaring a pointer temp
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    // using temp pointer to initialize the values in newnode(LEFT, KEY, RIGHT)
    temp->key = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
// inorder traversal function(having root)
void inorder(struct node *root)
{
    // checking if root is NULL(as if root does not have any value, tree cannot exist)

    // otherwise if root has some value in it, then...)
    if (root != NULL)
    {
        // inorder traversal of the tree goes like(LEFT, root(key), RIGHT)
        inorder(root->left);
        printf(" %d", root->key);
        inorder(root->right);
    }
}
// declaring a function for inserting value in the tree having node and key as its variables)
struct node *insert(struct node *node, int key)
{
    if (node == NULL)
        return newnode(key);

    // If the value (key) is smaller than the values present in the node,
    // then that value should be inserted to the left as the left child node of that node
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    /* Else if value (key) is greater than the value present in the node
     then that value (key) should be inserted to the right as the right child node of the node*/
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    return node;
}
// Given binary search tree and a key, this function searches for the key and returns the node if found.
struct node *search(struct node *root, int key)
{
    /*if root is null and value(key) is equal to the value in the root return root*/
    if (root == NULL || root->key == key)
    {
        return root;
    }
    /*if value present in the root is less than the key entered then that key(value in the child node of that root) must be on the
     right side of the root ( In Binary search tree values greater than the root comes to right side of the root ) */
    if (root->key < key)
    {
        return search(root->right, key);
    }
     /*if value present in the root is greater than the key entered then that key(value in the child node of that root) must be on the
     left side of the root ( In Binary search tree values lesser than the root comes to left side of the root ) */
    if (root->key > key)
    {
        return search(root->left, key);
    }
    // If the key is not found, return NULL
    return NULL;
}
/* Given binary search tree and a key, this function deletes the key 
and returns the new root*/
struct node *deletenode(struct node *root, int key)
{
    // base case
    if (root == NULL)
        return root;

    // Recursive calls for predecessors of the node to be deleted

    // if the value (key) entered is less than the value in the root
     //delete the left node of the root as child with lesser value lies to the left side of root
    if (key < root->key)
    {
        root->left = deletenode(root->left, key);
    }
    // if the value (key) entered is greater than the value in the root
    //delete the right node of the root as child with greater value lies to the right side of root
    else if (key > root->key)
    {
        root->right = deletenode(root->right, key);
    }
    // if the node with the key is found
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct node *temp = root->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }

        // Copy the inorder successor's data to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deletenode(root->right, temp->key);
    }

    return root;
}


/* main function to give values (during compile time) by calling inorder traversal ,insert(to insert a new node in the tree) function
 search(to search the node entered by the user) function*/
int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 20);
    insert(root, 66);
    insert(root, 30);
    insert(root, 70);
    inorder(root);
    
    // Search for a key
    
    int key = 35;
    
    /*making a search result function for adding a print function to sreach function*/
    struct node *searchResult = search(root, key);

    // Print the search result
    if (searchResult != NULL)
    {
        printf("\n%d found", key);
    }
    else
    {
        printf("\n%d not found", key);
    }
    return 0;
}
