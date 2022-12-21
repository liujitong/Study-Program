#include<stdio.h>
#include<string.h>
#include <stdlib.h>   
#include <time.h>  
#include <math.h>
#include <malloc.h>
#define MAX 300
#define LEN sizeof(struct slink)
void sub(int a[MAX], int b[MAX], int c[MAX]);

struct slink
{
	int  bignum[MAX];
	/*bignum[98]������������ţ�1����0��bignum[MAX-1]�����ʵ�ʳ���*/
	struct slink *next;
};

/*/--------------------------------------�Լ������Ĵ��������-------------------------------------*/

void  print(int a[MAX])
{
	int i;
	for (i = 0; i < a[MAX-1]; i++)
		printf("%d", a[a[MAX-1] - i - 1]);//��a[MAX-1]λ��ʼ���
	printf("\n\n");
	return;
}


int  cmp(int a1[MAX], int a2[MAX])//�Ƚ�������С
{
	int l1, l2;
	int i;
	l1 = a1[MAX-1];
	l2 = a2[MAX-1];
	if (l1 > l2)
		return 1;
	if (l1 < l2)
		return -1;
	for (i = (l1 - 1); i >= 0; i--)
	{
		if (a1[i] > a2[i])
			return 1;
		if (a1[i] < a2[i])
			return -1;
	}
	return 0;
}

void mov(int a[MAX], int *b)//��ֵa��b
{
	int j;
	for (j = 0; j < MAX; j++)
		b[j] = a[j];

	return;
}


void mul(int a1[MAX], int a2[MAX], int *c)//c=a1*a2
{
	int i, j;
	int y;
	int x;
	int z;
	int w;
	int l1, l2;
	l1 = a1[MAX - 1];
	l2 = a2[MAX - 1];
	if (a1[MAX - 2] == '-'&& a2[MAX - 2] == '-')
		c[MAX - 2] = 0;
	else if (a1[MAX - 2] == '-')
		c[MAX - 2] = '-';
	else if (a2[MAX - 2] == '-')
		c[MAX - 2] = '-';
	for (i = 0; i < l1; i++)
	{
		for (j = 0; j < l2; j++)
		{
			x = a1[i] * a2[j];
			y = x / 10;
			z = x % 10;
			w = i + j;
			c[w] = c[w] + z;
			c[w + 1] = c[w + 1] + y + c[w] / 10;
			c[w] = c[w] % 10;
		}
	}
	w = l1 + l2;
	if (c[w - 1] == 0)w = w - 1;
	c[MAX - 1] = w;
	return;
}

void add(int a1[MAX], int a2[MAX], int *c)//c=a1+a2
{
	int i, l1, l2;
	int len, temp[MAX];
	int k = 0;
	l1 = a1[MAX - 1];
	l2 = a2[MAX - 1];
	if ((a1[MAX - 2] == '-') && (a2[MAX - 2] == '-'))
	{
		c[MAX - 2] = '-';
	}
	else if (a1[MAX - 2] == '-')
	{
		mov(a1, temp);
		temp[MAX - 2] = 0;
		sub(a2, temp, c);
		return;
	}
	else if (a2[MAX - 2] == '-')
	{
		mov(a2, temp);
		temp[98] = 0;
		sub(a1, temp, c);
		return;
	}

	if (l1 < l2)len = l1;
	else len = l2;
	for (i = 0; i < len; i++)
	{
		c[i] = (a1[i] + a2[i] + k) % 10;
		k = (a1[i] + a2[i] + k) / 10;
	}
	if (l1 > len)
	{
		for (i = len; i < l1; i++)
		{
			c[i] = (a1[i] + k) % 10;
			k = (a1[i] + k) / 10;
		}
		if (k != 0)
		{
			c[l1] = k;
			len = l1 + 1;
		}
		else len = l1;
	}
	else
	{
		for (i = len; i < l2; i++)
		{
			c[i] = (a2[i] + k) % 10;
			k = (a2[i] + k) / 10;
		}
		if (k != 0)
		{
			c[l2] = k;
			len = l2 + 1;
		}
		else len = l2;
	}
	c[MAX-1] = len;
	return;
}


void sub(int a1[MAX], int a2[MAX], int *c)//c=a1-a2
{
	int i, l1, l2;
	int len, t1[MAX], t2[MAX];
	int k = 0;
	l1 = a1[MAX - 1];
	l2 = a2[MAX - 1];
	if ((a1[MAX - 2] == '-') && (a2[MAX - 2] == '-'))
	{
		mov(a1, t1);
		mov(a2, t2);
		t1[MAX - 2] = 0;
		t2[MAX - 2] = 0;
		sub(t2, t1, c);
		return;
	}
	else if (a2[MAX - 2] == '-')
	{
		mov(a2, t2);
		t2[MAX - 2] = 0;
		add(a1, t2, c);
		return;
	}
	else if (a1[MAX - 2] == '-')
	{
		mov(a2, t2);
		t2[MAX - 2] = '-';
		add(a1, t2, c);
		return;
	}

	if (cmp(a1, a2) == 1)
	{

		len = l2;
		for (i = 0; i < len; i++)
		{
			if ((a1[i] - k - a2[i]) < 0)
			{
				c[i] = (a1[i] - a2[i] - k + 10) % 10;
				k = 1;
			}
			else
			{
				c[i] = (a1[i] - a2[i] - k) % 10;
				k = 0;
			}
		}


		for (i = len; i < l1; i++)
		{
			if ((a1[i] - k) < 0)
			{
				c[i] = (a1[i] - k + 10) % 10;
				k = 1;
			}
			else
			{
				c[i] = (a1[i] - k) % 10;
				k = 0;
			}
		}
		if (c[l1 - 1] == 0)/*ʹ������C�е�ǰ������0�ַ�����ʾ�ˣ���1000-20=0980--->��ʾΪ980��*/
		{
			len = l1 - 1;
			i = 2;
			while (c[l1 - i] == 0)/*111456-111450=00006������0������6��*/
			{
				len = l1 - i;
				i++;
			}

		}

		else
		{
			len = l1;
		}
	}
	else
		if (cmp(a1, a2) == (-1))
		{
			c[MAX - 2] = '-';
			len = l1;
			for (i = 0; i < len; i++)
			{
				if ((a2[i] - k - a1[i]) < 0)
				{
					c[i] = (a2[i] - a1[i] - k + 10) % 10;
					k = 1;
				}
				else
				{
					c[i] = (a2[i] - a1[i] - k) % 10;
					k = 0;
				}
			}
			for (i = len; i < l2; i++)
			{
				if ((a2[i] - k) < 0)
				{
					c[i] = (a2[i] - k + 10) % 10;
					k = 1;
				}
				else
				{
					c[i] = (a2[i] - k) % 10;
					k = 0;
				}
			}
			if (c[l2 - 1] == 0)
			{
				len = l2 - 1;
				i = 2;
				while (c[l1 - i] == 0)
				{
					len = l1 - i;
					i++;
				}

			}
			else len = l2;
		}
		else if (cmp(a1, a2) == 0)
		{
			len = 1;
			c[len - 1] = 0;
		}
	c[MAX - 1] = len;
	return;
}

void  mod(int a[MAX], int b[MAX], int  *c)/*/c=a mod b//ע�⣺������֪���˴�A��C�����鶼�ı��ˡ�*/
{
	int d[MAX];
	mov(a, d);
	while (cmp(d, b) != (-1))/*/c=a-b-b-b-b-b.......until(c<b)*/
	{
		sub(d, b, c);
		mov(c, d);/*/c���Ƹ�a*/
	}
	return;
}


void  divt(int t[MAX], int b[MAX], int  *c, int *w)/*//���̷�//�����Ժ�w=a mod b, C=a/b;*/
{
	int a1, b1, i, j, m;/*w������ʱ��������*/
	int d[MAX], e[MAX], f[MAX], g[MAX], a[MAX];

	mov(t, a);
	for (i = 0; i < MAX; i++)
		e[i] = 0;
	for (i = 0; i < MAX; i++)
		d[i] = 0;
	for (i = 0; i < MAX; i++) g[i] = 0;
	a1 = a[MAX - 1];
	b1 = b[MAX - 1];
	if (cmp(a, b) == (-1))
	{
		c[0] = 0;
		c[MAX - 1] = 1;
		mov(t, w);
		return;
	}
	else if (cmp(a, b) == 0)
	{
		c[0] = 1;
		c[MAX - 1] = 1;
		w[0] = 0;
		w[MAX - 1] = 1;
		return;
	}
	m = (a1 - b1);
	for (i = m; i >= 0; i--)/*341245/3=341245-300000*1--->41245-30000*1--->11245-3000*3--->2245-300*7--->145-30*4=25--->25-3*8=1*/
	{
		for (j = 0; j < MAX; j++)
			d[j] = 0;
		d[i] = 1;
		d[MAX - 1] = i + 1;
		mov(b, g);
		mul(g, d, e);


		while (cmp(a, e) != (-1))
		{
			c[i]++;
			sub(a, e, f);
			mov(f, a);/*f���Ƹ�g*/
		}

		for (j = i; j < MAX; j++)/*��λ����*/
			e[j] = 0;

	}
	mov(a, w);
	if (c[m] == 0) c[MAX - 1] = m;
	else c[MAX - 1] = m + 1;

	return;
}

void mulmod(int a[MAX], int b[MAX], int n[MAX], int *m)/*��� �� m=a*b mod n;*/
{
	int c[MAX], d[MAX];
	int i;
	for (i = 0; i < MAX; i++)
		d[i] = c[i] = 0;
	mul(a, b, c);
	divt(c, n, d, m);
	for (i = 0; i < m[MAX - 1]; i++)
		printf("%d", m[m[MAX - 1] - i - 1]);
	printf("\nm  length is :  %d \n", m[MAX - 1]);
}

/*���������ص�������Ҫ���ֽ�� m=a^p  mod n�ĺ������⡣*/

void expmod(int a[MAX], int p[MAX], int n[MAX], int *m)
{
	int t[MAX], l[MAX], temp[MAX]; /*/t����2��l����1��*/
	int w[MAX], s[MAX], c[MAX], b[MAX], i;
	for (i = 0; i < MAX - 1; i++)
		b[i] = l[i] = t[i] = w[i] = 0;
	t[0] = 2; t[MAX - 1] = 1;
	l[0] = 1; l[MAX - 1] = 1;
	mov(l, temp);
	mov(a, m);
	mov(p, b);

	while (cmp(b, l) != 0)
	{
		for (i = 0; i < MAX; i++)
			w[i] = c[i] = 0;

		divt(b, t, w, c);/*// c=p mod 2  w= p /2*/

		mov(w, b);/*//p=p/2*/

		if (cmp(c, l) == 0) /*/����c==1*/
		{
			for (i = 0; i < MAX; i++)
				w[i] = 0;

			mul(temp, m, w);

			mov(w, temp);

			for (i = 0; i < MAX; i++)
				w[i] = c[i] = 0;

			divt(temp, n, w, c);/* /cΪ��c=temp % n��wΪ��w=temp/n */

			mov(c, temp);
		}

		for (i = 0; i < MAX; i++)
			s[i] = 0;

		mul(m, m, s);//s=a*a

		for (i = 0; i < MAX; i++)
			c[i] = 0;

		divt(s, n, w, c);/*/w=s/n;c=s mod n*/

		mov(c, m);

	}

	for (i = 0; i < MAX; i++)
		s[i] = 0;

	mul(m, temp, s);

	for (i = 0; i < MAX; i++)
		c[i] = 0;

	divt(s, n, w, c);

	mov(c, m);/*����s��m*/

	m[MAX - 2] = a[MAX - 2];/*Ϊ����ĺ�����ʾ��Ҫ���õ�99λ��Ϊ���*/

	return;
	/*/k=temp*k%n;*/

}


int is_prime_san(int p[MAX])//p�Ƿ�Ϊ����
{

	int i, a[MAX], t[MAX], s[MAX], o[MAX];
	for (i = 0; i < MAX; i++)
		s[i] = o[i] = a[i] = t[i] = 0;
	t[0] = 1;
	t[MAX - 1] = 1;
	a[0] = 2;// { 2,3,5,7 }
	a[MAX - 1] = 1;

	sub(p, t, s);

	expmod(a, s, p, o);
	if (cmp(o, t) != 0)
	{
		return 0;
	}

	a[0] = 3;
	for (i = 0; i < MAX; i++)  o[i] = 0;

	expmod(a, s, p, o);
	if (cmp(o, t) != 0)
	{
		return 0;
	}

	a[0] = 5;
	for (i = 0; i < MAX; i++)  o[i] = 0;

	expmod(a, s, p, o);
	if (cmp(o, t) != 0)
	{
		return 0;
	}

	a[0] = 7;
	for (i = 0; i < MAX; i++)  o[i] = 0;

	expmod(a, s, p, o);

	if (cmp(o, t) != 0)
	{
		return 0;
	}

	return 1;
}


int coprime(int e[MAX], int s[MAX]) //����������֮���Ƿ���
{
	int a[MAX], b[MAX], c[MAX], d[MAX], o[MAX], l[MAX];
	int i;
	for (i = 0; i < MAX; i++)
		l[i] = o[i] = c[i] = d[i] = 0;
	o[0] = 0; o[MAX - 1] = 1;
	l[0] = 1; l[MAX - 1] = 1;
	mov(e, b);
	mov(s, a);
	do
	{
		if (cmp(b, l) == 0)
		{
			return 1;
		}
		for (i = 0; i < MAX; i++)
			c[i] = 0;
		divt(a, b, d, c);
		mov(b, a);/*b--->a*/
		mov(c, b);/*c--->b*/

	} while (cmp(c, o) != 0);
	/*	printf("Ihey are  not coprime!\n");*/
	return 0;
}


void prime_random(int *p, int *q)//���������p,q
{
	int i, k;
	time_t t;
	p[0] = 1;
	q[0] = 3;

	p[MAX - 1] = 100;
	q[MAX - 1] = 100;

	do
	{
		t = time(NULL);
		srand((unsigned long)t);
		for (i = 1; i < p[MAX - 1] - 1; i++)
		{
			k = rand() % 10;
			p[i] = k;
		}
		k = rand() % 10;
		while (k == 0)
		{
			k = rand() % 10;
		}
		p[p[MAX - 1] - 1] = k;

	} while ((is_prime_san(p)) != 1);
	printf("���� p Ϊ  : ");
	for (i = 0; i < p[MAX - 1]; i++)
	{
		printf("%d", p[p[MAX - 1] - i - 1]);
	}
	printf("\n");
	do
	{
		t = time(NULL);
		srand((unsigned long)t);
		for (i = 1; i < q[MAX - 1]; i++)
		{
			k = rand() % 10;
			q[i] = k;
		}

	} while ((is_prime_san(q)) != 1);
	printf("���� q Ϊ : ");
	for (i = 0; i < q[MAX - 1]; i++)
	{
		printf("%d", q[q[MAX - 1] - i - 1]);
	}
	printf("\n");
	return;
}

void erand(int e[MAX], int m[MAX])//�������һ����(p-1)*(q-1)���ص� e 
{
	int i, k;
	time_t t;
	e[MAX - 1] = 90;
	printf("�������һ����(p-1)*(q-1)���ص�˽Կ e :");
	do
	{
		t = time(NULL);
		srand((unsigned long)t);
		for (i = 0; i < e[MAX - 1] - 1; i++)
		{
			k = rand() % 10;
			e[i] = k;
		}
		while ((k = rand() % 10) == 0)
			k = rand() % 10;
		e[e[MAX - 1] - 1] = k;
	} while (coprime(e, m) != 1);
	for (i = 0; i < e[MAX - 1]; i++)
	{
		printf("%d", e[e[MAX - 1] - i - 1]);
	}
	printf("\n");
	return;
}

void rsad(int e[MAX], int g[MAX], int *d)
{
	int   r[MAX], n1[MAX], n2[MAX], k[MAX], w[MAX];
	int     i, t[MAX], b1[MAX], b2[MAX], temp[MAX];
	mov(g, n1);
	mov(e, n2);
	for (i = 0; i < MAX; i++)
		k[i] = w[i] = r[i] = temp[i] = b1[i] = b2[i] = t[i] = 0;
	b1[MAX - 1] = 0; b1[0] = 0;/*/b1=0;*/
	b2[MAX - 1] = 1; b2[0] = 1;/*/b2=1;*/
	while (1)
	{

		for (i = 0; i < MAX; i++)
			k[i] = w[i] = 0;
		divt(n1, n2, k, w);/*/k=n1/n2;*/
		for (i = 0; i < MAX; i++)
			temp[i] = 0;
		mul(k, n2, temp);/*/temp=k*n2;*/
		for (i = 0; i < MAX; i++)
			r[i] = 0;
		sub(n1, temp, r);

		if ((r[MAX - 1] == 1) && (r[0] == 0))/*/r=0*/
		{
			break;
		}
		else
		{
			mov(n2, n1);/*/n1=n2;*/
			mov(r, n2);/*/n2=r;*/
			mov(b2, t);/*/t=b2;*/
			for (i = 0; i < MAX; i++)
				temp[i] = 0;
			mul(k, b2, temp);/*/b2=b1-k*b2;*/
			for (i = 0; i < MAX; i++)
				b2[i] = 0;
			sub(b1, temp, b2);
			mov(t, b1);
		}
	}

	for (i = 0; i < MAX; i++)
		t[i] = 0;
	add(b2, g, t);
	for (i = 0; i < MAX; i++)
		temp[i] = d[i] = 0;
	divt(t, g, temp, d);
	printf("�����ϵ�(p-1)*(q-1)�� e ����ó��Ĺ�Կ d : ");
	for (i = 0; i < d[MAX - 1]; i++)
		printf("%d", d[d[MAX - 1] - i - 1]);
	printf("\n");
}


void savepkey(int e[MAX], int n[MAX])//������Կ
{
	FILE *fp;
	int  i;
	char  savefile[25], ch;
	printf("����������Կ(e,n)����ŵ��ļ�·��Ϊ: ");
	scanf("%s", savefile);
	printf("\n");
	fp = fopen(savefile, "w");
	for (i = 0; i < e[MAX - 1]; i++)
	{
		ch = e[e[MAX - 1] - i - 1] + 48;
		fputc(ch, fp);
	}
	ch = ' ';
	fputc(ch, fp);
	for (i = 0; i < n[MAX - 1]; i++)
	{
		ch = n[n[MAX - 1] - i - 1] + 48;
		fputc(ch, fp);
	}
	fclose(fp);
	printf("\n����(e,n)�������!\n");
}

void  tencrypto(int e[MAX], int n[MAX])/*//������Ҫ���ļ����м���*/
{
	FILE *fp;
	int i, k, count, temp, c;
	char filename[25], ch, encryfile[25];
	struct slink  *p, *p1, *p2;
	struct slink  *h;
	h = p = p1 = p2 = (struct slink *)malloc(LEN);
	h = NULL;
	printf("\n������Ҫ���ܵ��ļ�·�� : ");
	scanf("%s", filename);
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("Cannot open file !\n");
		exit(0);
	}
	printf("\n�ļ���ԭ�����ݣ�\n");
	count = 0;
	while ((ch = fgetc(fp)) != EOF)
	{
		putchar(ch);
		c = ch;
		k = 0;
		if (c < 0)
		{
			c = abs(c);/*/�Ѹ���ȡ��������һ�����*/
			p1->bignum[MAX - 2] = '0';
		}
		else
		{
			p1->bignum[MAX - 2] = '1';
		}

		while (c / 10 != 0)
		{
			temp = c % 10;
			c = c / 10;
			p1->bignum[k] = temp;
			k++;
		}
		p1->bignum[k] = c;
		p1->bignum[MAX - 1] = k + 1;
		count = count + 1;
		if (count == 1)
			h = p1;
		else p2->next = p1;
		p2 = p1;
		p1 = (struct slink *)malloc(LEN);
	}
	p2->next = NULL;
	printf("\n");
	fclose(fp);

	printf("���ܺ��ļ��ı���·�� : \n");
	scanf("%s",encryfile);
	fp=fopen(encryfile,"w");
	//fp = fopen(filename, "w");
	p = p1 = (struct slink *)malloc(LEN);
	p = h;
	printf("\n���ܺ��ļ������γ����ģ�\n");
	if (h != NULL)
		do
		{
			expmod(p->bignum, e, n, p1->bignum);
			ch = p1->bignum[MAX - 2];
			printf("%c", ch);
			fputc(ch, fp);
			if ((p1->bignum[MAX - 1] / 10) == 0)/*/�ж�p1->bignum[MAX-1]���Ƿ����ʮ��*/
			{
				ch = 0 + 48;
				printf("%c", ch);
				fputc(ch, fp);
				ch = p1->bignum[MAX - 1] + 48;
				printf("%c", ch);
				fputc(ch, fp);
			}
			else
			{
				ch = p1->bignum[MAX - 1] / 10 + 48;
				printf("%c", ch);
				fputc(ch, fp);
				ch = p1->bignum[MAX - 1] % 10 + 48;
				printf("%c", ch);
				fputc(ch, fp);
			}

			for (i = 0; i < p1->bignum[MAX - 1]; i++)
			{
				printf("%d", p1->bignum[i]);
				ch = p1->bignum[i] + 48;
				fputc(ch, fp);
			}
			p = p->next;
			p1 = (struct slink *)malloc(LEN);
		} while (p != NULL);
		printf("\n\n");
		fclose(fp);
		return;
}

void  tdecrypto(int d[MAX], int n[MAX])
{

	FILE *fp;
	struct slink *h, *p1, *p2;
	char ch, encryfile[25], decryfile[25];
	int i, j, k, c, count, temp;
	printf("\n������ܹ����ļ�·�� : ");
	scanf("%s", encryfile);
	if ((fp = fopen(encryfile, "r")) == NULL)
	{
		printf("���ļ�������!\n");
		exit(0);
	}
	printf("\n�ļ����������ݣ�\n");
	i = 0;
	j = 3;
	count = 0;
	h = p1 = p2 = (struct slink *)malloc(LEN);

	while ((ch = fgetc(fp)) != EOF)
	{
		putchar(ch);
		c = ch;
		if (j == 3)
		{
			p1->bignum[MAX - 2] = c;
			j--;
		}
		else if (j == 2)
		{
			temp = c - 48;
			j--;
		}
		else if (j == 1)
		{
			p1->bignum[MAX - 1] = temp * 10 + c - 48;
			j--;
		}
		else if (j == 0)
		{
			p1->bignum[i] = c - 48;
			i++;
			if (i == p1->bignum[MAX - 1])
			{
				i = 0;
				j = 3;
				count++;
				if (count == 1)
					h = p1;
				else p2->next = p1;
				p2 = p1;
				p1 = (struct slink *)malloc(LEN);
			}
		}
	}
	p2->next = NULL;
	printf("\n");
	fclose(fp);

	printf("���ܺ�������ļ�����·�� : \n");
	scanf("%s",decryfile);
	fp=fopen(decryfile,"w");
	//fp = fopen(encryfile, "w");
	printf("\n�������ĺ��ļ��е�����:\n");
	p2 = (struct slink *)malloc(LEN);
	p1 = h;
	k = 0;
	if (h != NULL)/*/tempΪ�ݴ�ASIIC���intֵ*/
		do
		{
			for (i = 0; i < MAX; i++)
				p2->bignum[i] = 0;
			expmod(p1->bignum, d, n, p2->bignum);
			temp = p2->bignum[0] + p2->bignum[1] * 10 + p2->bignum[2] * 100;
			if ((p2->bignum[MAX - 2]) == '0')
			{
				temp = 0 - temp;
			}/*/ת��Ϊ��ȷ��ASIIC�룬��-78-96�γɺ���	*/
			ch = temp;/*  str[k]--->ch */
			printf("%c", ch);/*  str[k]--->ch */
			fputc(ch, fp);/*/д���ļ�str[k]--->ch*/
			k++;
			p1 = p1->next;
			p2 = (struct slink *)malloc(LEN);
		} while (p1 != NULL);
		printf("\n\n");
		fclose(fp);
		return;

}

int main()
{
	int  i;
	char  c;
	int  p[MAX], q[MAX], n[MAX], d[MAX], e[MAX], m[MAX], p1[MAX], q1[MAX];
	struct slink *head, *h1, *h2;
	for (i = 0; i < MAX; i++)
		m[i] = p[i] = q[i] = n[i] = d[i] = e[i] = 0;/*/�򵥳�ʼ��һ��*/
    
    for (i = 0; i < MAX; i++)
        m[i] = p[i] = q[i] = n[i] = d[i] = e[i] = 0;
    printf("�����Կ�Բ������£�\n");
    prime_random(p, q);/*/�����������������*/
    mul(p, q, n);
    printf("�� p��q �ó� n :");
    print(n);
    mov(p, p1);
    p1[0]--;
    mov(q, q1);
    q1[0]--;      /*/q-1;*/
    mul(p1, q1, m);//m=(p-1)*(q-1)
    printf("�� (p-1)(q-1) �ó� m :");
    print(m);
    erand(e, m);
    rsad(e, m, d);
	printf("��Կ�Բ�����ɣ����ڿ���ֱ�ӽ��мӽ����ļ�!\n");

	tencrypto(e, n);
	printf("\n�����ļ��������!\n");
			
    tdecrypto(d, n);
    printf("\n�����ļ��������!\n");
    
    return 0;
}
