

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAXLEN 1000

typedef struct {
    
    int weight;
    int parent, lchild, rchild; 
    char ch;
    char* encode;
    bool unused; 
} HTNode, *HuffmanTree;

typedef struct {
    
    char* code; 
    char ch;
} HCNode, *HuffmanCode;

int** CreateAlpha(char* );
void PrintFrequency(int* , int );
HuffmanTree CreateHuffmanTree(const int* , int );
int FindMinWeightIndex(HuffmanTree , int );
HuffmanCode* GetHuffmanCode(HuffmanTree , int );
void PrintHuffmanTreeTable(HuffmanTree , int );
HuffmanCode* sort(HuffmanCode* , int );
void PrintEncode(HuffmanCode* , HuffmanTree , int );


int main()
{
    char* in; 
    while (1) {
        in = (char *)calloc(MAXLEN, sizeof(char));
        scanf("%s", in);
        if ((*in) == '0' && (*(in + 1)) == '\0') break;
        int** ptr = CreateAlpha(in);
        int n = *(ptr[0]);
        int* alpha = ptr[1];
        
        
        PrintFrequency(alpha, n);
        HuffmanTree HT = CreateHuffmanTree(alpha, n);
        PrintHuffmanTreeTable(HT, n * 2 - 1);
        HuffmanCode *codes = GetHuffmanCode(HT, n);
        codes = sort(codes, n);
        PrintEncode(codes, HT, n);
        printf("%s\n", in);

        free(ptr[1]); 
        free(ptr[0]);
        free(HT); 
        free(*codes); 
    }
}

int** CreateAlpha(char* str)
{
    size_t LEN = strlen(str);
    int* alpha = (int *)calloc(26, sizeof(int)); 
    int* size = (int *)malloc(sizeof(int));
    (*size) = 0;
    for (size_t i = 0; i < LEN; i++) {
        alpha[str[i] - 97] += 1;
        if (alpha[str[i] - 97] == 1) (*size)++;
    }
    int** ptr = (int **)calloc(2, sizeof(int*));
    ptr[0] = size;
    ptr[1] = alpha;
    return ptr;
}

void PrintFrequency(int* alpha, int n)
{
    for (int i = 0; i < 26; i++) {
        if (alpha[i] > 0) {
            n--;
            printf("%c:%d%s", 97 + i, alpha[i], n == 0 ? "\n" : " ");
        }
    }
}

HuffmanTree CreateHuffmanTree(const int* dict, int n)
{
    int m = 2 * n - 1; 
    HuffmanTree HT = (HTNode *)malloc((m + 1) * sizeof(*HT)); 
    for (int i = 1; i <= m; i++) {
        
        
        
        
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
        HT[i].unused = true;
        
    }
    int HT_idx = 1;
    for (int i = 0; i < 26; i++) {
        
        if (dict[i] > 0) {
            HT[HT_idx].ch = (char)(97 + i);
            HT[HT_idx].weight = dict[i];
            HT_idx++;
        }
    }
    int s1, s2;
    for (int i = n + 1; i <= m; i++) {
        
        s1 = FindMinWeightIndex(HT, i - 1);
        s2 = FindMinWeightIndex(HT, i - 1);
        
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
    return HT;
}

int FindMinWeightIndex(HuffmanTree HT, int num)
{
    int min = INT_MAX; 
    int index = -1;
    for (int i = 1; i <= num; i++) {
        if (HT[i].unused && min > HT[i].weight) {
            min = HT[i].weight;
            index = i;
        }
    }
    HT[index].unused = false;
    return index;
}

HuffmanCode* GetHuffmanCode(HuffmanTree HT, int n)
{
    HuffmanCode* codes = (HCNode **)calloc(n + 1, sizeof(*codes)); 
    char* ch = (char *)calloc(n, sizeof(*ch)); 
    int start; 
    int cur; 
    int f; 
    for (int i = 1; i <= n; i++) {
        
        start = n - 1;
        cur = i;
        f = HT[i].parent;
        codes[i] = (HCNode *)calloc(1, sizeof(HCNode));
        (*(codes[i])).ch = HT[i].ch;
        while (f != 0) {
            --start;
            if (HT[f].lchild == cur) {
                ch[start] = '0';
            } else {
                
                ch[start] = '1';
            }
            cur = f;
            f = HT[f].parent;
        }
        (*(codes[i])).code = (char *)calloc(n - start, sizeof(char));
        HT[i].encode = (char *)calloc(n - start, sizeof(char));
        strcpy((*(codes[i])).code, &ch[start]);
        strcpy(HT[i].encode, &ch[start]);
    }
    free(ch);
    return codes;
}

void PrintHuffmanTreeTable(HuffmanTree HT, int n)
{
    for (int i = 1; i <= n; i++) {
        printf("%d %d %d %d %d\n", i, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
    }
}

HuffmanCode* sort(HuffmanCode* codes, int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if ((codes[i])->ch > (codes[j])->ch) {
                HuffmanCode temp = codes[i];
                codes[i] = codes[j];
                codes[j] = temp;
            }
        }
    }
    return codes;
}

void PrintEncode(HuffmanCode* codes, HuffmanTree HT, int n)
{
    for (int i = 1; i <= n; i++) {
        printf("%c:%s%s", (codes[i])->ch, (codes[i])->code, i == n ? "\n" : " ");
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < HT[i].weight; j++) {
            printf("%s", HT[i].encode);
        }
    }
    printf("\n");
}