#include <cstdlib>
#include <string>
#include <string.h>
#include <queue>
#include <map>
#include <fstream>

using namespace std;

#define MAX_SIZE 270
#define WRITE_BUFF_SIZE 10
#define PSEUDO_EOF 256

struct Huffman_node
{
    int id; // 使用int类型，因为要插入值为256的pseudo-EOF
    unsigned int freq;
    string code;
    Huffman_node  *left, 
                  *right,
                  *parent; 
};

typedef Huffman_node* Node_ptr;

class Huffman
{
private:
    Node_ptr node_array[MAX_SIZE]; // 叶子节点数组
    Node_ptr root;  // 根节点
    int size;  // 叶子节点数
    fstream in_file, out_file; // 输入、输出文件流
    map<int, string> table;  // 字符->huffman编码映射表

    class Compare
    {
        public:
            bool operator()(const Node_ptr& c1, const Node_ptr& c2) const
            {
                return (*c1).freq > (*c2).freq;
            }
    };

    // 用于比较优先队列中元素间的顺序
    priority_queue< Node_ptr, vector<Node_ptr>, Compare > pq;

    // 根据输入文件构造包含字符及其频率的数组
    void create_node_array();

    // 根据构造好的Huffman树建立Huffman映射表
    void create_map_table(const Node_ptr node, bool left);

    // 构造优先队列
    void create_pq();

    // 构造Huffman树
    void create_huffman_tree();

    // 计算Huffman编码
    void calculate_huffman_codes();

    // 开始压缩过程
    void do_compress();

    // 从huffman编码文件中重建huffman树
    void rebuid_huffman_tree();

    // 根据重建好的huffman树解码文件
    void decode_huffman();

public:
    // 根据输入和输出流初始化对象
    Huffman(string in_file_name, string out_file_name);

    // 析构函数
    ~Huffman();

    // 压缩文件
    void compress();

    // 解压文件
    void decompress();
};


void Huffman::create_node_array()
{
    int i, count;
    int freq[MAX_SIZE] = {0}; // 频数统计数组
    char in_char;

    // 依次读入字符，统计数据
    while( !in_file.eof() )
    {
        in_file.get(in_char);
        // 消除最后一行的影响
        if( in_file.eof() )
            break;
        // char是有符号的，数组下标是unsigned 所以要换成unsigned char
        freq[(unsigned char)in_char]++; 
    }

    count = 0;
    for(i = 0; i < MAX_SIZE; ++i)
    {
        if(freq[i] <= 0)
            continue;
        Node_ptr node = new Huffman_node();
        node->id = i;
        node->freq = freq[i];
        node->code = "";
        node->left = NULL;
        node->right = NULL;
        node->parent = NULL;

        node_array[count++] = node;
    }
    // 插入频率为1的pseudo-EOF
    Node_ptr node = new Huffman_node();
    node->id = PSEUDO_EOF;
    node->freq = 1;
    node->code = "";
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    node_array[count++] = node;

    size = count;
}

void Huffman::create_map_table(const Node_ptr node, bool left)
{
    if(left)
        node->code = node->parent->code + "0";
    else
        node->code = node->parent->code + "1";

    // 如果是叶子节点，则是一个“有效”节点，加入编码表
    if(node->left == NULL && node->right == NULL)
        table[node->id] = node->code;
    else
    {
        if(node->left != NULL)
            create_map_table(node->left, true);
        if(node->right != NULL)
            create_map_table(node->right, false);
    }
}

void Huffman::create_pq()
{
    int i;

    create_node_array();

    for(i = 0; i < size; ++i)
        pq.push(node_array[i]);
}

void Huffman::create_huffman_tree()
{
    root = NULL;

    while( !pq.empty() ) { 
        // 使用优先队列存储文本数据中出现的文本内容和频率，根据频率使用优先队列排序建立哈夫曼树  
        Node_ptr first = pq.top();
        pq.pop();
        if( pq.empty() )
        {
            //建立完毕，结束
            root = first;
            break;
        }
        Node_ptr second = pq.top();
        // 寻找第一个和第二个节点
        pq.pop();
        Node_ptr new_node = new Huffman_node();
        new_node->freq = first->freq + second->freq;

        if(first->freq <= second->freq)
        {
            // 根据频率大小决定建树顺序
            new_node->left = first;
            new_node->right = second;
        }
        else
        {
            new_node->left = second;
            new_node->right = first;
        }
        first->parent = new_node;
        second->parent = new_node;

        pq.push(new_node);
    }
}

void Huffman::calculate_huffman_codes()
{
    if(root == NULL)
    {
        printf("Build the huffman tree failed or no characters are counted\n");
        exit(1);
    }

    if(root->left != NULL)
        create_map_table(root->left, true);
    if(root->right != NULL)
        create_map_table(root->right, false);
}

void Huffman::do_compress()
{
    int length, i, j, byte_count;
    char in_char;
    unsigned char out_c, tmp_c;
    string code, out_string;
    map<int, string>::iterator table_it;

    // 按节点数(包括pseudo-EOF) + 哈夫曼树 + 哈夫曼编码来写入文件

    // 第1行写入节点数（int）
    out_file << size << endl;

    // 第2~(size+1)行写入huffman树，即每行写入字符+huffman编码，如"43 00100"
    for(table_it = table.begin(); table_it != table.end(); ++table_it)
    {
        out_file << table_it->first<< " "<< table_it->second<<endl;
    }

    // 第size+2行写入huffman编码
    in_file.clear();
    in_file.seekg(ios::beg);
    code.clear();
    while( !in_file.eof() )
    {
        in_file.get(in_char);
        // 消除最后一行回车的影响
        if( in_file.eof() )
            break;
        // 找到每一个字符所对应的huffman编码
        table_it = table.find((unsigned char)in_char);
        if(table_it != table.end() )
            code += table_it->second;
        else
        {
            printf("Can't find the huffman code of character %X\n", in_char);
            exit(1);
        }
        // 当总编码的长度大于预设的WRITE_BUFF_SIZE时再写入文件
        length = code.length();
        if(length > WRITE_BUFF_SIZE)
        {
            out_string.clear();
            //将huffman的01编码以二进制流写入到输出文件
            for(i = 0; i + 7 < length; i += 8)
            {
                // 每八位01转化成一个unsigned char输出
                // 不使用char，如果使用char，在移位操作的时候符号位会影响结果
                // 另外char和unsigned char相互转化二进制位并不变
                out_c = 0;
                for(j = 0; j < 8; j++)
                {
                    if('0' == code[i+j])
                        tmp_c = 0;
                    else
                        tmp_c = 1;
                    out_c += tmp_c<<(7-j);
                }
                out_string += out_c;
            }
            out_file << out_string;
            code = code.substr(i, length-i);
        }
    }

    // 已读完所有文件，先插入pseudo-EOF
    table_it = table.find(PSEUDO_EOF);
    if(table_it != table.end() )
        code += table_it->second;
    else
    {
        printf("Can't find the huffman code of pseudo-EOF\n");
        exit(1);
    }
    // 再处理尾部剩余的huffman编码
    length = code.length();
    out_c = 0;
    for(i = 0; i < length; i++)
    {
        if('0' == code[i])
            tmp_c = 0;
        else
            tmp_c = 1;
        out_c += tmp_c<<(7-(i%8));
        if(0 == (i+1) % 8 || i == length - 1)
        {
            // 每8位写入一次文件
            out_file<<out_c;
            out_c = 0;
        }
    }
}

void Huffman::rebuid_huffman_tree()
{
    int i, j, id, length;
    string code;
    Node_ptr node, tmp, new_node;

    root = new Huffman_node();
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL; //解码的时候parent没什么用了，可以不用赋值，但为了安全，还是赋值为空

    in_file >> size;
    if(size > MAX_SIZE)
    {
        printf("The number of nodes is not valid, maybe the compressed file has been broken.\n");
        exit(1);
    }

    for(i = 0; i < size; ++i)
    {
        in_file >> id;
        in_file >> code;

        length = code.length();
        node = root;
        for(j = 0; j < length; ++j)
        {
            if('0' == code[j])
                tmp = node->left;
            else if('1' == code[j])
                tmp = node->right;
            else
            {
                printf("Decode error, huffman code is not made up with 0 or 1\n");
                exit(1);
            }

            // 如果到了空，则新建一个节点
            if(tmp == NULL)
            {
                new_node = new Huffman_node();
                new_node->left = NULL;
                new_node->right = NULL;
                new_node->parent = node;

                // 如果是最后一个0或1,说明到了叶子节点，给叶子节点赋相关的值
                if(j == length-1)
                {
                    new_node->id = id;
                    new_node->code = code;
                }

                if('0' == code[j])
                    node->left = new_node;
                else
                    node->right = new_node;

                tmp = new_node;
            }
            // 如果不为空，且到了该huffman编码的最后一位，这里却已经存在了一个节点，就说明
            // 原来的huffmaninman是有问题的
            else if(j == length -1)
            {
                printf("Huffman code is not valid, maybe the compressed file has been broken.\n");
                exit(1);
            }
            // 如果不为空，但该节点却已经是叶子节点，说明寻路到了其他字符的编码处，huffman编码也不对
            else if(tmp->left == NULL && tmp->right == NULL)
            {
                printf("Huffman code is not valid, maybe the compressed file has been broken.\n");
                exit(1);
            }
            node = tmp;
        }

    }
}

void Huffman::decode_huffman()
{
    bool pseudo_eof;
    int i, id;
    char in_char;
    string out_string;
    unsigned char u_char, flag;
    Node_ptr node;

    out_string.clear();
    node = root;
    pseudo_eof = false;
    in_file.get(in_char);// 跳过最后一个回车
    while(!in_file.eof() )
    {
        in_file.get(in_char);
        u_char = (unsigned char)in_char;
        flag = 0x80;
        for(i = 0; i < 8; ++i)
        {

            if(u_char & flag)
                node = node->right;
            else
                node = node->left;

            if(node->left == NULL && node->right == NULL)
            {
                id = node->id;
                if(id == PSEUDO_EOF)
                {
                    pseudo_eof = true;
                    break;
                }
                else
                {
                    // int to char是安全的，高位会被截断
                    out_string += (char)node->id;
                    node = root;
                }
            }
            flag = flag >> 1;
        }
        if(pseudo_eof)
            break;


        if(WRITE_BUFF_SIZE < out_string.length())
        {
            out_file << out_string;
            out_string.clear();
        }
    }

    if(!out_string.empty() )
        out_file << out_string;
}

Huffman::Huffman(string in_file_name, string out_file_name)
{
    in_file.open(in_file_name.c_str(), ios::in);
    if(!in_file)
    {
        printf("Open file error, path is: %s\n", in_file_name.c_str());
        exit(1);
    }

    out_file.open(out_file_name.c_str(), ios::out);
    if(!out_file)
    {
        printf("Open file error, path is: %s\n", out_file_name.c_str());
        exit(1);
    }
}

Huffman::~Huffman()
{
    in_file.close();
    out_file.close();
}

void Huffman::compress()
{
    create_pq();
    create_huffman_tree();
    calculate_huffman_codes();
    do_compress();
}

void Huffman::decompress()
{
    rebuid_huffman_tree();
    decode_huffman();
}
