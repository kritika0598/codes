 
#include <bits/stdc++.h> 

using namespace std;
typedef long long int lli;
const int ALPHABET_SIZE = 10; 
  
// trie node 
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
  
    // isEndOfWord is true if the node represents 
    // end of a word 
    bool isEndOfWord; 
}; 
  
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
  
    pNode->isEndOfWord = false; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
} 
   
bool insert(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (lli i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - '0'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
        if(pCrawl->isEndOfWord==true)
            return false;
    } 
  
    // mark last node as leaf 
    pCrawl->isEndOfWord = true;
    return true; 
} 
  
// Driver 
int main() 
{ 
    lli T;
    cin>>T;
    while(T--)
    {
        lli N;
        cin>>N;
        string keys[N];
        for(lli i=0;i<N;i++)
        {
            cin>>keys[i];
        }
        
        sort(keys,keys+N);

        struct TrieNode *root = getNode(); 
  
    // Construct trie
        bool f=true; 
        for (lli i = 0; i < N; i++) 
        {
            if(!insert(root, keys[i]))
            {
                cout<<"NO"<<endl;
                f=false;
                break;
            }
        }
        if(f)
            cout<<"YES"<<endl;     
    }
    return 0;
     
} 
