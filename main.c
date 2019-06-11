#include <stdio.h>
#include <stdlib.h>


struct node
{
    int value;
    struct node *mom;
    struct node *right;
    struct node *left;
};

//дерево
struct tree
{
    struct node *root;
    int all;
};

// инициализация
void init(struct tree* t)
{
    t->root = NULL;
    t->all = 0;
}

// вставка в дерево
// 0 - если удачно
// 1 - если элемент уже есть
int insert(struct tree* t, int value)
{
    struct node *branch;
    branch = (struct node*)malloc(sizeof(struct node));

    branch->value = value;
    branch->right = NULL;
    branch->left = NULL;

    if (t->root == NULL)
    {
        branch->mom = NULL;
        t->root = branch;
        t->all++;
        return 0;
    }
    else
    {
        struct node *buf, *ma;
        buf = t->root;
        while(buf != NULL)
        {
            if(value > buf->value)
            {
                ma = buf;
                buf = buf->right;
            }
            else if (value < buf->value)
            {
                ma = buf;
                buf = buf->left;
            }
            else{return 1;}
        }
        branch->mom = ma;
        if (ma->value > value)
        {
            ma->left = branch;
        }
        if (ma->value < value)
        {
            ma->right = branch;
        }
        t->all++;
        return 0;
    }
}

//удалить все элементы
void clear_particle(struct node* t)
{
    if (t->left != NULL)
    {
        clear_particle(t->left);
    }
    if (t->right != NULL)
    {
        clear_particle(t->right);
    }
    free(t);
}
void clear_all(struct tree* t)
{
    clear_particle(t->root);
    t->root = NULL;
    t->all = 0;
}


//описание дерева
void pr(struct node *n)
{
    if(n->left != NULL)
    {
        pr(n->left);
    }
    if(n->right != NULL)
    {
         pr(n->right);
    }
    printf("%d ", n->value);
}
void pr_t(struct tree *t)
{
    if(t->root == NULL)
    {
        printf("-\n");
    }
    else
    {
        pr(t->root);
        printf("\n");
    }
}

//вывод листьев
void p_ends(struct node *n)
{
    if(n->left != NULL)
    {
        p_ends(n->left);
    }
    if(n->right != NULL)
    {
         p_ends(n->right);
    }
    if(n->right == NULL && n->left == NULL)
    {
        printf("%d ", n->value);
    }
}
void ends(struct tree *t)
{
    if(t->root == NULL)
    {
        printf("-\n");
    }
    else if (t->root->left == NULL && t->root->right == NULL)
    {
         printf("%d\n", t->root->value);
    }
    else
    {
        p_ends(t->root);
    }
    printf("\n");
}

//вывод количества элементов
int ell (struct tree *t)
{
    return(t->all);
}

//проверка
void check_all (struct tree *t)
{
    for(int i = 0; i < 7; i++)
    {
        insert(t, 5);
        insert(t, 7);
        insert(t, 3);
        insert(t, 4);
        insert(t, 2);
        insert(t, 6);
        insert(t, 8);
    }

    pr_t(t);
    ends(t);
    printf("%d\n", ell(t));
    clear_all(t);
    pr_t(t);

}

int main()
{
    int v;
    struct tree *t;
    t = (struct tree*) malloc(sizeof(struct tree));
    init(t);

    check_all(t);

    /*for(int i = 0; i < 7; i++)
    {
        scanf ("%d", &v);
        insert(t, v);
    }*/

    return 0;
}

