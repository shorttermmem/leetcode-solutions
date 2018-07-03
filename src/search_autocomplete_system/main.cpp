// ID 462
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <iostream>
using namespace std;

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
  
        for (unsigned int i = 0; i < times.size(); ++i)
        {
            m_trie.insert(sentences[i], times[i]);
        }
    }
    
    ~AutocompleteSystem(){}
    
    list<string> input(char c) {
        
        static Trie::TrieNode *cur = m_trie.root;
        static string prefix;
        list<string> res;

        if (c == '#')
        {
            res = m_trie.search(cur, prefix);
            cur = m_trie.root;
            prefix.clear();
        }
        else
        {
            prefix.append(1, c);
            m_trie.walk(c, &cur);
        }

        return res;
    }

private:
    
#define LEXICAL_COUNT 26+1+1
   
    class Trie
    {
    public:
        Trie(){
            root = getNode();
        }
        ~Trie(){
            dfs(root);
        }
        
        struct TrieNode
        {
            vector<TrieNode*> children;
            bool isEndOfWord;
            int count;
        };
        
        struct Entry{
            int count;
            string str;
            
            Entry(int c, string& s) : count(c), str(s){};
        };
        
        struct HeapComparator{
            bool operator() (const Entry& E1, const Entry& E2) const
            {
                if (E1.count > E2.count)
                    return true;
                else if (E1.count == E2.count && E1.str > E2.str)
                    return true;

                return false;
            }
        };
        
        using Heap = priority_queue<Entry, vector<Entry>, HeapComparator>;
        
        struct TrieNode *getNode(void)
        {
            struct TrieNode *pNode =  new TrieNode;
            
            pNode->isEndOfWord = false;
            pNode->count = -1;
            pNode->children.assign(LEXICAL_COUNT, nullptr);
            
            return pNode;
        }
        
        // If not present, inserts key into trie
        // If the key is prefix of trie node, just
        // marks leaf node
        void insert(string key, int count)
        {
            struct TrieNode *cur = root;
            
            for (unsigned int i = 0; i < key.length(); ++i)
            {
                int index = getIndexByChar(key[i]);
                
                if (!cur->children.at(index))
                {
                    cur->children.at(index) = getNode();
                }
                
                cur = cur->children.at(index);
            }
            
            // mark last node as leaf
            cur->isEndOfWord = true;
            cur->count= count;
        }
        
        void walk(char c, TrieNode** cur)
        {
            int index = getIndexByChar(c);

            if (!(*cur)->children.at(index))
                *cur = nullptr;
            else
                *cur = (*cur)->children.at(index);
            return;
        }

        list<string> search(TrieNode *node, string& prefix)
        {
            Heap entries;
            list<string> res;
            
            top3(node, entries, prefix);
            
            while(!entries.empty())
            { 
                auto&& itr = entries.top();
                res.emplace_back(move(itr.str));
                entries.pop();
            }
            return res;
        }
        
        void top3(TrieNode* node, Heap& entries, string str)
        {    
            if(node == nullptr) return;
            
            if(node->isEndOfWord)
            {
                auto&& itr = entries.top();
                
                if(node->count > itr.count)
                {
                    entries.pop();
                    entries.emplace(Entry(node->count, str));
                }
            }
            
            for(int i = 0; i < LEXICAL_COUNT; ++i)
            {
                top3(
                    node->children.at(i), 
                    entries, 
                    str.append(1, getCharByIndex(i))
                );
            }
            return;
        }
        
        int getIndexByChar(char c)
        {
            if (c == ' ')
                return 0;
            else if (c == '#')
                return 1;
            else if (c >= 'a' && c <= 'z')
                return c - 'a' + 2;
            else
                return -1;
        }
        
        char getCharByIndex(int i)
        {
            if (i ==0)
                return ' ';
            else if (i == 1)
                return '#';
            else
                return 'a' + i - 2;
        }
        
        void dfs(TrieNode* node)
        {
            if (!node) return;
            
            for(int i = 0; i < LEXICAL_COUNT; ++i)
            {
                TrieNode* cur = node->children[i];
                dfs(cur);
                if(cur)
                    delete cur;
                    cur = nullptr;
            }
        }
        
        TrieNode *root;
    };
    
   Trie m_trie; 
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */

int main(){

    vector<string> sentences{"i love you","island","iroman","i love leetcode"};
    vector<int> times(5, 1);

    int arr2[10] = {1,2,3,4,5,6,7,7,8,9};


    vector<int> arr(10);

    cout << sentences[0] << '\n';

    AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);

    list<string> param_1 = obj->input('i');
    list<string> param_2 = obj->input(' ');
    list<string> param_3 = obj->input('a');

    for(auto&& p : param_1)
    {
        cout << p << endl;
    };

    return 0;
}
