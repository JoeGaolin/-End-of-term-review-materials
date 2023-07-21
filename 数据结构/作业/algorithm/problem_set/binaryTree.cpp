
#include <stdio.h>
#include <stdlib.h>

//����������Ľṹ
 
typedef struct binary_tree
 
{
 
    int data;   // �ڵ㱣�������
 
    binary_tree* left; // ������ڵ�ָ��
 
    binary_tree* right; // �����ҽڵ�ָ��
 
}node;

//��ʼ��������
 
void insert(node** tree, int gain) //ָ��ָ�������ָ�룬�����ָ��tree��ָ���ֵ
 
{
 
    node* temp = NULL;
 
    if (!(*tree)) //�жϸ��ڵ��Ƿ����
 
    {
 
        temp = (node*)malloc(sizeof(node));
 
        temp->left = temp->right = NULL; //���ҽڵ��ƿ�
 
        temp->data = gain;
 
        *tree = temp;
 
        return;
 
    }
 
 
 
    if (gain < (*tree)->data) //�ж���������
 
    {
 
        insert(&(*tree)->left, gain); //�ȼ��� &((*tree)->left)������������
 
    }
 
    else if (gain > (*tree)->data) //�ж���������
 
    {
 
        insert(&(*tree)->right, gain);//�ȼ��� &((*tree)->right)������������
 
    }
 
}
//�ͷŽڵ��ڴ�
 
void deltree(node* tree)
 
{
 
    if (tree)
 
    {
 
        deltree(tree->left);//����������һֱѰ��
 
        deltree(tree->right);//����������һֱѰ��
 
        free(tree); //�Ҳ�����free������һ��
 
    }
 
}
//ǰ�����
 
void leader(node* tree)
 
{
 
    if (tree)
 
    {
 
        printf("%d\n", tree->data);
 
        leader(tree->left);
 
        leader(tree->right);
 
    }
 
}
 
//�������
 
void inorder(node* tree)
 
{
 
    if (tree) {
 
        inorder(tree->left);
 
        printf("%d\n", tree->data);
 
        inorder(tree->right);
 
    }
 
}
 
//�������
 
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
 
    //��ֵ����������������������������ʽ
 
    insert(&root, 9);
 
    insert(&root, 4);
 
    insert(&root, 15);
 
    insert(&root, 6);
 
    insert(&root, 12);
 
    insert(&root, 16);
 
    insert(&root, 2);
 
 
 
    printf("ǰ�����\n");
 
    leader(root);
 
    printf("�������\n");
 
    inorder(root);
 
    printf("�������\n");
 
    lastder(root);
 
    //�ͷŵ�������
 
    deltree(root);
 
}