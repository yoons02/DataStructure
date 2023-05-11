#define NAME_LENGTH 20//������ �̸� ���� ����
#define WORD_LENGTH 20//�˻��ϴ� �ܾ��� ���� ����
#define MAX_NUM_DOC 10//�о���̴� �ִ� ������ �� ����
#define delimiter " \"\n\t`'��?!.,:()"//������(���ڿ����� ��ū�� ������ ����)

typedef struct treeNode *treePtr;//Ʈ����带 ����Ű�� �����͸� treePtr�� ���� 
typedef struct treeNode {
	char data[WORD_LENGTH];//�ܾ�
	int  count;//�ܾ��� ���� Ƚ��
	treePtr left;
	treePtr right;//�ܾ��� �ڽ� ���
}node;//Ʈ�� ��� ����ü�� node�� ����.
treePtr hash_table[MAX_NUM_DOC][30];//�ؽ����̺��, �Է¹��� ������ ������� ũ�Ⱑ 30�� ������ �ؽ����̺��� �̿��ϴ� ���� �ȴ�.
int num_comparison = 0;//���Խ� �񱳿����� �Ͼ�� Ƚ��
int num_search = 0;//�˻��� �񱳿����� �Ͼ�� �� Ƚ��
char document_name[MAX_NUM_DOC][NAME_LENGTH];//�Է¹��� ������ �̸��� ������� �����ϴ� ���ڿ� �迭
int indexed_word = 0;//���ε� �ܾ��� ����

int transform(char *key);//folding ������� key�� �� character ���� ���� ���ڷ� ��ȯ�ϴ� �Լ�
void search_word(char *key, int d);//�ܾ �˻��ϰ�, �� �ܾ ���� ���� �̸��� �˻��ϴµ��� �Ͼ �񱳿��� Ƚ���� ����ϴ� �Լ�
void make_bst(char *key, treePtr p, treePtr temp);//�ؽ����̺� ����Ž��Ʈ���� �����ϴ� �Լ�
treePtr search_bst(char*key, treePtr p);//����Ž��Ʈ���� �˻��Ͽ� ���ϴ� ��带 ��ȯ�ϴ� �Լ�. ã�� �����Ͱ� ���ٸ� NULL�� ��ȯ.
void bulid_hash_table(char*fname, int d);//������ �����Ͽ� �ؽ����̺��� ����� �Լ�
void insert_hash_table(char*key, int d);//�ؽ� ���̺� �ڷḦ �����ϴ� �Լ�
int hash(char*key);//folding���� 30���� ���� �������� �ؽ��Լ� ������ �̿�
void print_idx_result(int i);//���� ����� ����Ʈ�Ѵ�.
void print_result(treePtr p, int i);//�˻� �� ����� ����Ʈ��.
void print_doc(char *fname, treePtr p);//�˻� ����� �ִ� ������ ��ġ�� ����Ʈ�ϴ� �Լ�