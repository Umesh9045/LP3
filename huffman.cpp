#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int freq;
        char data;
        Node* left;
        Node* right;
        
        Node(char p, int q) {
            freq = q;
            data = p;
            left = NULL;
            right = NULL;
        }
};

struct compareNodes {
    bool operator() (Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void generateHuffmanCode(Node *root, string code, map<char, string>& HuffmanCodes) {
    //Case 1: Termination
    if(root == NULL) {
        return;
    }
    
    //Case 2: root has character Data i.e Last Iteration in sub-iteration
    if(root->data != '\0') {
        HuffmanCodes[root->data] = code;
    }
    
    //Case 3: root has not character data, then check recusrsively in left and right side
    generateHuffmanCode(root->left, code + '0', HuffmanCodes);
    generateHuffmanCode(root->right, code + '1', HuffmanCodes);
    
}

int main() {
    //STEP 1: Map of Data and Its frequency     -|| INPUT ||-
    map <char, int> frequency;
    frequency['a'] = 5;
    frequency['b'] = 9;
    frequency['c'] = 12;
    frequency['d'] = 13;
    frequency['e'] = 16;
    frequency['f'] = 45;
    
    //STEP 2: Create priority_queue: <elementType, containerType, comparisonFunction>
    priority_queue < Node*, vector<Node*>, compareNodes> minHeap;
    
    //STEP 2.1: Create a class for creating Nodes   -|| class Node ||-
    //STEP 2.2: Create compareNodes() function      -|| struct compareNodes() ||-
    
    //STEP 3:
    for(auto i=frequency.begin(); i!=frequency.end(); i++) {
        minHeap.push(new Node(i->first, i->second));
    }
    
    //STEP 4: Build a Huffman Tree
    while(minHeap.size() > 1) {
        //Pop first TWO entries
        Node *first = minHeap.top(); 
        minHeap.pop();
        
        Node *second = minHeap.top();
        minHeap.pop();
        
        //new node which is combination of first and second
        Node *naya = new Node('\0', first->freq + second->freq);
        naya->left = first;
        naya->right = second;
        
        //Push naya node in minHeap
        minHeap.push(naya);
    }
    
    //STEP 5: Root of Huffman Tree
    Node *root = minHeap.top();
    
    //STEP 6: Generate Huffman Code
    map<char, string>HuffmanCodes;
    
    generateHuffmanCode(root, "", HuffmanCodes);
    
    //STEP 7: Print the Huffman Code
    for (auto i = HuffmanCodes.begin(); i != HuffmanCodes.end(); i++) {
        cout << i->first << " = " << i->second << endl;
    }
    
    return 0;
}