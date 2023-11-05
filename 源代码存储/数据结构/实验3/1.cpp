    #include<stdio.h>
    #include<stdlib.h>
    #include<malloc.h>
    #include<iostream>
    #define MAX 20
    typedef struct BTNode{       /*节点结构声明*/
        char data ;               /*节点数据*/
        struct BTNode *lchild;
        struct BTNode *rchild ;  /*指针*/
    }*BiTree;
    //ABC##DE#G##F###
    void createBiTree(BiTree *t){ /* 先序遍历创建二叉树*/
        char s;
        BiTree q;
        printf("\nplease input data:(exit for #)");
        s=getchar();
        if(s=='#'){*t=NULL; return;}
        q=(BiTree)malloc(sizeof(struct BTNode));
        if(q==NULL){printf("Memory alloc failure!"); return;}
        q->data=s;
        *t=q;
        createBiTree(&q->lchild); /*递归建立左子树*/
        createBiTree(&q->rchild); /*递归建立右子树*/
    }

    void PreOrder(BiTree p){  /* 先序遍历二叉树*/
        if ( p!= NULL ) {
            printf("%c", p->data);
            PreOrder( p->lchild ) ;
            PreOrder( p->rchild) ;
        }
    }
    void InOrder(BiTree p){  /* 中序遍历二叉树*/
        if( p!= NULL ) {
        InOrder( p->lchild ) ;
        printf("%c", p->data);
        InOrder( p->rchild) ;
        }
    }
    void PostOrder(BiTree p){  /* 后序遍历二叉树*/
    if ( p!= NULL ) {
            PostOrder( p->lchild ) ;
            PostOrder( p->rchild) ;
            printf("%c", p->data);
        }
    }

    void Preorder_n(BiTree p){ /*先序遍历的非递归算法*/
        BiTree stack[MAX],q;
        int top=0,i;
        for(i=0;i<MAX;i++) stack[i]=NULL;/*初始化栈*/
        q=p;
        while(q!=NULL){
            printf("%c",q->data);
            if(q->rchild!=NULL) stack[top++]=q->rchild;
            if(q->lchild!=NULL) q=q->lchild;
            else
                if(top>0) q=stack[--top];
                else q=NULL;
        }
    }
    void Inorder_n(BiTree p)
    {
        BiTree stack[MAX],q;
        int top=0,i;
        for(i=0;i<MAX;i++) stack[i]=NULL;/*初始化栈*/
        q=p;
        while(q!=NULL){
            char x=q->data;
            if(q->rchild!=NULL) stack[top++]=q->rchild;
            
            if(q->lchild!=NULL) q=q->lchild;
            else
                if(top>0) q=stack[--top];
                else q=NULL;
    }
    }
    void Postorder_n(BiTree p)
    {
        BiTree stack[MAX],q;
        int top=0,i;
        for(i=0;i<MAX;i++) stack[i]=NULL;/*初始化栈*/
        q=p;
        while(q!=NULL){
            char x=q->data;
            if(q->rchild!=NULL) stack[top++]=q->rchild;
            if(q->lchild!=NULL) q=q->lchild;
            else
                if(top>0) q=stack[--top];
                else q=NULL;
            printf("%c",x);
    }
    }

    void release(BiTree t){ /*释放二叉树空间*/
        if(t!=NULL){
            release(t->lchild);
            release(t->rchild);
            free(t);
        }
    }
    //计算节点个数算法
    int amount_TreeNode(BiTree t)
    {
        if(t==NULL) return 0;
        else return amount_TreeNode(t->lchild)+amount_TreeNode(t->rchild)+1;//左子树+右子树+1；
    }

    int leaf_Node(BiTree t)
    {
        if(t==NULL) return 0;
        else if(t->lchild==NULL&&t->rchild==NULL)
        {
            return 1;
        }
        else return leaf_Node(t->lchild)+leaf_Node(t->rchild);

    }
    int main(){
        BiTree t=NULL;
        createBiTree(&t);
        printf("\n\nPreOrder the tree is:");
        PreOrder(t);
        printf("\n\nInOrder the tree is:");
        InOrder(t);
        printf("\n\nPostOrder the tree is:");
        PostOrder(t);
        printf("\n\n先序遍历序列（非递归）:");
        Preorder_n(t);
        printf("\n\n中序遍历序列（非递归）:");
        Inorder_n(t);
        printf("\n\n后序遍历序列（非递归）:");
        Postorder_n(t);
        printf("\n");
        std::cout<<"节点个数"<<amount_TreeNode(t)<<std::endl;
        std::cout<<"叶子节点个数"<<leaf_Node(t)<<std::endl;
        release(t);
        return 0;
    }
