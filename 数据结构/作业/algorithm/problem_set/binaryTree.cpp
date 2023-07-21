
#include <stdio.h>
#include <stdlib.h>

//定义二叉树的结构
 
typedef struct binary_tree
 
{
 
    int data;   // 节点保存的数据
 
    binary_tree* left; // 定义左节点指针
 
    binary_tree* right; // 定义右节点指针
 
}node;

//初始化二叉树
 
void insert(node** tree, int gain) //指向指针变量的指针，结果是指针tree所指向的值
 
{
 
    node* temp = NULL;
 
    if (!(*tree)) //判断根节点是否存在
 
    {
 
        temp = (node*)malloc(sizeof(node));
 
        temp->left = temp->right = NULL; //左右节点制空
 
        temp->data = gain;
 
        *tree = temp;
 
        return;
 
    }
 
 
 
    if (gain < (*tree)->data) //判断是左子树
 
    {
 
        insert(&(*tree)->left, gain); //等价于 &((*tree)->left)，创建左子树
 
    }
 
    else if (gain > (*tree)->data) //判断是右子树
 
    {
 
        insert(&(*tree)->right, gain);//等价于 &((*tree)->right)，创建右子树
 
    }
 
}
//释放节点内存
 
void deltree(node* tree)
 
{
 
    if (tree)
 
    {
 
        deltree(tree->left);//先往左子树一直寻找
 
        deltree(tree->right);//再往右子树一直寻找
 
        free(tree); //找不到了free返回上一级
 
    }
 
}
//前序遍历
 
void leader(node* tree)
 
{
 
    if (tree)
 
    {
 
        printf("%d\n", tree->data);
 
        leader(tree->left);
 
        leader(tree->right);
 
    }
 
}
 
//中序遍历
 
void inorder(node* tree)
 
{
 
    if (tree) {
 
        inorder(tree->left);
 
        printf("%d\n", tree->data);
 
        inorder(tree->right);
 
    }
 
}
 
//后序遍历
 
void lastder(node* tree)
 
 {
 
    if (tree) {
 
        lastder(tree->left);
 
        lastder(tree->right);
 
        printf("%d\n", tree->data);
 
    }
 
}
int main(void)
 
{
 
    node* root;
 
    //int i;
 
    root = NULL;
 
    //将值赋给二叉树，下面是满二叉树形式
 
    insert(&root, 9);
 
    insert(&root, 4);
 
    insert(&root, 15);
 
    insert(&root, 6);
 
    insert(&root, 12);
 
    insert(&root, 16);
 
    insert(&root, 2);
 
 
 
    printf("前序遍历\n");
 
    leader(root);
 
    printf("中序遍历\n");
 
    inorder(root);
 
    printf("后序遍历\n");
 
    lastder(root);
 
    //释放掉二叉树
 
    deltree(root);
 
}