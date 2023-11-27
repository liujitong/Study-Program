class goods{
    public:
    char name[50];
    char brand[50];
    float price;
    int num;
};
struct goods_list{
    goods data;
    goods_list *next;
}*goods_head;
void insert(goods_list *head,goods_list *node){
    goods_list *p=head;
    while(p->next!=nullptr&&p->next->data.price<node->data.price){
        p=p->next;
    }
    node->next=p->next;
    p->next=node;
}