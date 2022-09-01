#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
class freq
{
   public:
   int ascii;
   int frequency;

   freq();
   freq(int i, int j);
};
freq::freq()
{
   this->ascii = 0;
   this->frequency = 0;

}
freq::freq(int i, int j)
{

}
struct hack{
   char data;
   unsigned encode;
   int binArr[100000];
   int binCount=0;
};
struct MinHeapNode {
 
    // One of the input characters
    char data;
 
    // Frequency of the character
    unsigned freq;
 
    // Left and right child of this node
    struct MinHeapNode *left, *right;
};

struct MinHeap {
 
    // Current size of min heap
    unsigned size;
 
    // capacity of min heap
    unsigned capacity;
 
    // Array of minheap node pointers
    struct MinHeapNode** array;
};

struct MinHeapNode* newNode(char data, unsigned freq)
{
    struct MinHeapNode* temp
        = (struct MinHeapNode*)malloc
(sizeof(struct MinHeapNode));
 
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
 
    return temp;
}
struct MinHeap* createMinHeap(unsigned capacity)
 
{
 
    struct MinHeap* minHeap
        = (struct MinHeap*)malloc(sizeof(struct MinHeap));
 
    // current size is 0
    minHeap->size = 0;
 
    minHeap->capacity = capacity;
 
    minHeap->array
        = (struct MinHeapNode**)malloc(minHeap->
capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}
void swapMinHeapNode(struct MinHeapNode** a,
                    struct MinHeapNode** b)
 
{
 
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}
void minHeapify(struct MinHeap* minHeap, int idx)
 
{
 
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
 
    if (left < minHeap->size && minHeap->array[left]->
freq < minHeap->array[smallest]->freq)
        smallest = left;
 
    if (right < minHeap->size && minHeap->array[right]->
freq < minHeap->array[smallest]->freq)
        smallest = right;
 
    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest],
                        &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}
int isSizeOne(struct MinHeap* minHeap)
{
 
    return (minHeap->size == 1);
}
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
 
{
 
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0]
        = minHeap->array[minHeap->size - 1];
 
    minHeap->size--;
    minHeapify(minHeap, 0);
 
    return temp;
}
void insertMinHeap(struct MinHeap* minHeap,
                struct MinHeapNode* minHeapNode)
 
{
 
    ++minHeap->size;
    int i = minHeap->size - 1;
 
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
 
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
 
    minHeap->array[i] = minHeapNode;
}
void buildMinHeap(struct MinHeap* minHeap)
 
{
 
    int n = minHeap->size - 1;
    int i;
 
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

void printArr(struct MinHeapNode* root, int arr[], int n,vector<hack>& hackList)
{
    int i;
    int hacker = 0;
    hack temphack;
    for (i = 0; i < n; ++i)
    {
       hacker++;
       temphack.binArr[i]++;
       temphack.binCount++;
    }
        

   
   temphack.data = root->data;
   temphack.encode = hacker;
   hackList.push_back(temphack);
}
int isLeaf(struct MinHeapNode* root)
{
 
    return !(root->left) && !(root->right);
}
struct MinHeap* createAndBuildMinHeap(vector<freq> data, int size)
 
{
 
    struct MinHeap* minHeap = createMinHeap(size);
 
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i].ascii, data[i].frequency);
 
    minHeap->size = size;
    buildMinHeap(minHeap);
 
    return minHeap;
}

struct MinHeapNode* buildHuffmanTree(vector<freq> data, int size)
 
{
    struct MinHeapNode *left, *right, *top;
 
    // Step 1: Create a min heap of capacity
    // equal to size. Initially, there are
    // modes equal to size.
    struct MinHeap* minHeap = createAndBuildMinHeap(data, size);
 
    // Iterate while size of heap doesn't become 1
    while (!isSizeOne(minHeap)) {
 
        // Step 2: Extract the two minimum
        // freq items from min heap
        left = extractMin(minHeap);
        right = extractMin(minHeap);
 
        // Step 3: Create a new internal
        // node with frequency equal to the
        // sum of the two nodes frequencies.
        // Make the two extracted node as
        // left and right children of this new node.
        // Add this node to the min heap
        // '$' is a special value for internal nodes, not used
        top = newNode('$', left->freq + right->freq);
 
        top->left = left;
        top->right = right;
 
        insertMinHeap(minHeap, top);
    }
 
    // Step 4: The remaining node is the
    // root node and the tree is complete.
    return extractMin(minHeap);
}

void printCodes(struct MinHeapNode* root, int arr[], int top, vector<hack>& hackList)
 
{
 
    // Assign 0 to left edge and recur
    if (root->left) {
 
        arr[top] = 0;
        printCodes(root->left, arr, top + 1,hackList);
    }
 
    // Assign 1 to right edge and recur
    if (root->right) {
 
        arr[top] = 1;
        printCodes(root->right, arr, top + 1,hackList);
    }
 
    // If this is a leaf node, then
    // it contains one of the input
    // characters, print the character
    // and its code from arr[]
    if (isLeaf(root)) {
        printArr(root, arr, top, hackList);
    }
}

void HuffmanCodes(vector<freq> data, int size, vector<hack>& hackList)
 
{
   
    // Construct Huffman Tree
    struct MinHeapNode* root
        = buildHuffmanTree(data, size);
 
    // Print Huffman codes using
    // the Huffman tree built above
    int arr[size*size], top = 0;
    printCodes(root, arr, top, hackList);
}


int main(int argc, char *argv[]) {
   int frequencies[128] = {0};
   int validCount = 0;
   string longOne;
   ifstream file1;
   file1.open(argv[1]);
   if(file1.fail())
   {
      cout << "File 1 does not exist" << endl;
      return -10;
   }
   string tempStr;
   while(getline(file1,tempStr,'\0'))
   {
      longOne = longOne+tempStr;
      for(int i=0;i<tempStr.size();i++)
      {
         char x = tempStr[i];
         int ascii = int(x);
         frequencies[ascii]++;
      }
   }
   
   int uniqueFrequencies[127];
   vector<freq> list;
   int min = 9999999;
  
   int counter=0;
   for(int i=0;i<127;i++)
   {
      if(frequencies[i]!=0)
      {
         freq temp;
         temp.ascii = i;
         temp.frequency = frequencies[i];
         list.push_back(temp);
         validCount++;
      }
   }
vector<freq> sortedList = list;
//cout << validCount << endl;
int ignore[validCount];
for(int i=0;i<sortedList.size();i++)
{
   for(int j=i;j<sortedList.size();j++)
   {
      if(sortedList[j].frequency>sortedList[i].frequency)
      {
         swap(sortedList[j],sortedList[i]);
      }
   }
}
vector<hack> hackList;
HuffmanCodes(sortedList,validCount,hackList);
 /*for(int i=0;i<hackList.size();i++)
 {
    cout << "Char: " << hackList[i].data << " | CODE_LEN: " << hackList[i].encode << endl;
 }*/
 cout << "Uncompressed length: " << (longOne.length()*8) << " bits" << endl;
string newOne;
for(int i=0;i<longOne.size();i++)
{
   char tmpChar = longOne[i];
   for(int k = 0;k<hackList.size();k++)
   {
      if(hackList[k].data==tmpChar)
      {
         for(int l=0;l<hackList[k].binCount;l++)
         {
            newOne+=hackList[k].binArr[l];
         }
      }
   }
}
cout << "Compressed length: " << (newOne.length()) << " bits" << endl;
   cout << "CHAR|FREQ|CODE_LEN" << endl;
   for(int i=0;i<validCount;i++)
   {
      int codeLen = 0;
      for(int k=0;k<hackList.size();k++)
      {
         if(char(list[i].ascii) == hackList[k].data)
         {
            codeLen = hackList[k].encode;
         }
      }
      cout << "\'" << char(list[i].ascii)<< "\'|" << list[i].frequency << "|" << codeLen << endl;
   }
   cout << endl;
    /*for(int i=0;i<validCount;i++)
   {
      cout << "\'" << char(sortedList[i].ascii)<< "\'|" << sortedList[i].frequency << "|" << endl;
   }*/
   return 0;
}
