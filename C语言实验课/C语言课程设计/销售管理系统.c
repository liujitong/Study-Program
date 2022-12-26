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

void Screen_Print() // 程序初始化界面
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
    printf("请输入产品编号：");
    scanf("%d", &product);
    if (product == 0)
    {
      break;
    }
    printf("请输入销售额：");
    scanf("%d", &amount);
    // 将对应的销售额加到对应的销售员和产品的销售额数组中
    sales[salesmen - 1][product - 1] += amount;
  }
}
void Total_salemen(int sales[SALESMEN_COUNT][PRODUCT_COUNT]) // 计算每个销售员的总销售额
{
  for (int i = 0; i < SALESMEN_COUNT; i++)
  {
    for (int j = 0; j < PRODUCT_COUNT; j++)
    {
      salesmen[i].id = i + 1;
      salesmen[i].total_sales += sales[i][j];
    }
  }
}
void Total_Product(int sales[SALESMEN_COUNT][PRODUCT_COUNT]) // 计算每个产品的总销售额
{

  for (int i = 0; i < PRODUCT_COUNT; i++)
  {
    for (int j = 0; j < SALESMEN_COUNT; j++)
    {
      Product[i].id = i + 1;
      Product[i].total_sales += sales[j][i];
    }
  }
}
void Sort_sales() // 销售员排序
{
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
}
void Sort_product() // 产品排序
{
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
  // 统计及排名
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
  printf("*******************************\n请按任意键输出产品排行榜\n");
  system("Pause");
  system("cls");
  // 产品排行榜
  printf("产品排行榜\n");
  for (int i = 0; i < PRODUCT_COUNT; i++)
  {
    printf("销售排行第%d名的是:\n编号:%d\n销售额:%d\n", i + 1, Product[i].id, Product[i].total_sales);
    printf("\n");
  }
  printf("*******************************\n请按任意键输出报表\n");
  system("Pause");
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
  printf("已保存至baobiao.md");
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
  Input(sales);
  /// 计算每个销售员的总销售额
  Total_salemen(sales);
  // 计算每个产品的总销售额
  Total_Product(sales);
  // 对销售额排序
  Sort_sales();
  // 对产品进行排序
  Sort_product();
  // 输出开始
  Output(sales);
}