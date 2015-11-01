
class myTri{
public:
    myTri* ptrs[26];
    int val;//char
    int ct;
    myTri(){
        val = 0;
        ct = 0;
        for(int i = 0; i < 26; i++){
            ptrs[i] = NULL;
        }//end for i
    }//myTri
};


class WordDictionary {
public:
    
    myTri myroot;
    
    // Adds a word into the data structure.
    void addWord(string word) {
        if(word.length() == 0) return;
        myTri *ptr = NULL;
        ptr = &myroot;
        for(int i = 0; i < word.length(); i++){
            char tmp = word[i];
            if(ptr->ptrs[word[i] - 'a'] == NULL)
                ptr->ptrs[word[i] - 'a'] = new myTri();
            ptr = ptr->ptrs[word[i] - 'a'];
        }//end for
        (ptr->ct) ++;
    }
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    
    bool mysearch(string word, myTri* root){
        if(root == NULL) return false;
        if(word.size() == 0) return !(root->ct == 0);
        if(word[0] == '.') {
            for(int i = 0; i < 26; i++){
                if(mysearch(word.substr(1), root->ptrs[i])) return true;
            }//end for i
            return false;
        }else{
            if(root->ptrs[word[0] - 'a'] == NULL )
                return false;
            else
                return mysearch(word.substr(1),root->ptrs[word[0] - 'a']);
            
        }//end if '.' or not
       
    }
    
    bool search(string word) {
        return mysearch(word, &myroot);
    }
    
    
    WordDictionary(){
       // myroot = new myTri();
    }//constructor
    
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
