#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode
{
    string data;                
    unsigned freq;             
    MinHeapNode *left, *right; 
 
    MinHeapNode(string data, unsigned freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare
{
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};
 
void printCodes(struct MinHeapNode* root, string str)
{
    if (!root)
        return;
 
    if (root->data != "$") //  Not Internal Node
        cout << root->data << ": " << str << "\n";
 
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}
 
 int maxDepth(struct MinHeapNode* node) 
{
   if (!node) 
       return 0;
   else
   {
       int lDepth = maxDepth(node->left);
       int rDepth = maxDepth(node->right);
 
     if (lDepth > rDepth) 
           return(lDepth+1);
       else return(rDepth+1);
   }
} 
int minDepth(struct MinHeapNode* root)
{
    if (!root)
        return 0;

    if (!root->left && !root->right)
       return 1;
 
    if (!root->left)
       return minDepth(root->right) + 1;

    if (!root->right)
       return minDepth(root->left) + 1;
 
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}

void HuffmanCodes(string data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;
 

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));
 

    while (minHeap.size() != 1)
    {
        
        left = minHeap.top();
        minHeap.pop();
 
        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode("$", left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

  	printCodes(minHeap.top(), "");
    cout << "Max Length of Codeword = " << maxDepth(minHeap.top()) - 1 << endl;
    cout << "Min Length of Codeword = " << minDepth(minHeap.top()) - 1 << endl;
}
 


int main()
{
	// Read the file	
	FILE *fp = freopen("huffman.txt","r",stdin);
     int symbols = 0;
     scanf("%d", &symbols);
     string arr[symbols];
     int freq[symbols];
     int weight;
     for(int i = 0;i < symbols;i++){
        scanf("%d", &weight);
        arr[i] = "node"+ to_string(i);
        freq[i] = weight;
	}
     
    HuffmanCodes(arr, freq, symbols);

 	
    return 0;
}
