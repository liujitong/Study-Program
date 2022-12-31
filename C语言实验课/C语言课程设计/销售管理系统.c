#include <stdio.h>
#include <stdlib.h>
#define SALESMEN_COUNT 4 // 一共4个售货员
#define PRODUCT_COUNT 5  // 一共5个产品

struct Product
{
  int id;
  int total_sales;
} Product[PRODUCT_COUNT];
struct salesmen
{
  int id;
  int total_sales;
} salesmen[SALESMEN_COUNT];

void Screen_Print() // 欢迎页界面
{
  printf("****************************\n********销售管理系统********\n********按任意键继续********\n****************************\n");
  system("Pause"); // 要展示菜单，让她暂停再继续执行
}
void Input(int sales[SALESMEN_COUNT][PRODUCT_COUNT]) // 输入界面
{
  system("cls");
  printf("输入0退出\n");
  while (1) // 设置一个死循环
  {
    // 读取一张便条
    int salesmen, product, amount;
    printf("请输入销售员编号：");
    scanf("%d", &salesmen);
    if (salesmen == 0)
    {
      break;
    }
    if (salesmen < 1 || salesmen > SALESMEN_COUNT)
    {
      printf("销售员编号无效，请重新输入\n");
      continue;
    }
    printf("请输入产品编号：");
    scanf("%d", &product);
    if (product == 0)
    {
      break;
    }
    if (product < 1 || product > PRODUCT_COUNT)
    {
      printf("产品编号无效，请重新输入\n");
      continue;
    }
    printf("请输入销售额：");
    scanf("%d", &amount);
    // 将对应的销售额加到对应的销售员和产品的销售额数组中
    sales[salesmen - 1][product - 1] += amount;
  }
}

void Total(int sales[SALESMEN_COUNT][PRODUCT_COUNT]) // 计算总销售额
{
  //计算每个销售员的总销售额
  for (int i = 0; i < SALESMEN_COUNT; i++)
  {
    for (int j = 0; j < PRODUCT_COUNT; j++)
    {
      salesmen[i].id = i + 1;
      salesmen[i].total_sales += sales[i][j];
    }
  }
  //计算产品的总销售额
  for (int i = 0; i < PRODUCT_COUNT; i++)
  {
    for (int j = 0; j < SALESMEN_COUNT; j++)
    {
      Product[i].id = i + 1;
      Product[i].total_sales += sales[j][i];
    }
  }
}
void Sort()//排序 
{
  // 销售员排序
  for (int i = 0; i < SALESMEN_COUNT - 1; i++)
  {
    for (int j = 0; j < SALESMEN_COUNT - 1 - i; j++)
    {
      if (salesmen[j].total_sales < salesmen[j + 1].total_sales)
      {
        struct salesmen temp;
        temp = salesmen[j];
        salesmen[j] = salesmen[j + 1];
        salesmen[j + 1] = temp;
      }
    }
  }
  //产品排序
  for (int i = 0; i < PRODUCT_COUNT - 1; i++)
  {
    for (int j = 0; j < PRODUCT_COUNT - 1 - i; j++)
    {
      if (Product[j].total_sales < Product[j + 1].total_sales)
      {
        struct Product temp;
        temp = Product[j];
        Product[j] = Product[j + 1];
        Product[j + 1] = temp;
      }
    }
  }
}
void Output(int sales[SALESMEN_COUNT][PRODUCT_COUNT]) // 输出界面
{
  int n;//记录用户输入数
  // 显示选择页面
  while(1)
  {
  system("cls");
  printf("输出页面\n");
  printf("1.输出销售员排行榜\n2.输出产品排行榜\n3.输出销售报表\n4.退出\n");
  printf("请选择：");
  scanf("%d",&n);
  if(n==1)
  {
  //销售员排行榜
  system("cls");
  printf("销售员排行榜\n");
  printf("\n");
  for (int i = 0; i < SALESMEN_COUNT; i++)
  {
    printf("销售排行第%d名的是:\n", i + 1);
    printf("编号：%d\n", salesmen[i].id);
    printf("总计销售额：%d\n", salesmen[i].total_sales);
    printf("\n");
  }
  system("Pause");
  }
  else if(n==2)
  {
  // 产品排行榜
  system("cls");
  printf("产品排行榜\n");
  for (int i = 0; i < PRODUCT_COUNT; i++)
  {
    printf("销售排行第%d名的是:\n编号:%d\n销售额:%d\n", i + 1, Product[i].id, Product[i].total_sales);
    printf("\n");
  }
  system("Pause");
  }
  else if(n==3)
  {
  system("cls");
  // 销售报表
  printf("     销售报表    \n");
  printf("|销售员代号|1    |2    |3    |4    |5    |总和 |\n");
  for (int i = 0; i < SALESMEN_COUNT; i++)
  {
    printf("|%d         |", i + 1);
    for (int j = 0; j < PRODUCT_COUNT; j++)
    {
      printf("%-5d|", sales[i][j]);
    }
    printf("%-5d|", salesmen[i].total_sales);
    printf("\n");
  }
  printf("|总计      |");
  for (int i = 0; i < PRODUCT_COUNT; i++)
  {
    printf("%-5d|", Product[i].total_sales);
  }
  printf("%-5d|", salesmen[0].total_sales + salesmen[1].total_sales + salesmen[2].total_sales + salesmen[3].total_sales);
  printf("\n");
  save(sales);
  printf("已保存至baobiao.md\n");
  system("Pause");
  }
  else if(n==4) break;
  else continue;
  }
}
void save(int sales[SALESMEN_COUNT][PRODUCT_COUNT])
{
  FILE *fp;
  if ((fp = fopen("baobiao.md", "wb")) == NULL)
  {
    printf("不能打开文件！\n");
    return -1;
  }
  fprintf(fp, "# 销售报表\n");
  fprintf(fp, "\n");
  fprintf(fp, "|销售员代号|1    |2    |3    |4    |5    |总和 |\n");
  fprintf(fp, "|-|-|-|-|-|-|-|\n");
  for (int i = 0; i < SALESMEN_COUNT; i++)
  {
    fprintf(fp, "|%d         |", i + 1);
    for (int j = 0; j < PRODUCT_COUNT; j++)
    {
      fprintf(fp, "%-5d|", sales[i][j]);
    }
    fprintf(fp, "%-5d|", salesmen[i].total_sales);
    fprintf(fp, "\n");
  }
  fprintf(fp, "|总计      |");
  for (int i = 0; i < PRODUCT_COUNT; i++)
  {
    fprintf(fp, "%-5d|", Product[i].total_sales);
  }
  fprintf(fp, "%-5d|", salesmen[0].total_sales + salesmen[1].total_sales + salesmen[2].total_sales + salesmen[3].total_sales);
  fprintf(fp, "\n");
}

int main()
{
  Screen_Print();
  int sales[SALESMEN_COUNT][PRODUCT_COUNT] = {0};
  while (1)//设置一个死循环，这个界面只有在用户输入3的时候才会跳出循环
  {
    system("cls");
    printf("1. 输入\n");
    printf("2. 统计\n");
    printf("3. 退出\n");
    printf("请选择要执行的操作：");
    int choice;
    scanf("%d", &choice);

    if (choice == 1)
    {
      Input(sales);
    }
    else if (choice == 2)
    {
    // 计算总销售额
    Total(sales);
    // 排序
    Sort();
    // 输出开始
    Output(sales);
    }
    else if (choice == 3)
    {
      break;
    }
  }
  return 0;
}