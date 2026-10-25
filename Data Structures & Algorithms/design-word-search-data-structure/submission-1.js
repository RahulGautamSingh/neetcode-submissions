class WordDictionaryNode {
    children = new Map(); // <string, WordDictionaryNode>
    isEnd = false;
}

class WordDictionary {
    constructor() {
        this.root = new WordDictionaryNode();
    }

    /**
     * @param {string} word
     * @return {void}
     */
    addWord(word) {
        let node = this.root;
        for(const ch of word){
            if(!node.children.get(ch)) node.children.set(ch, new WordDictionaryNode());
            node = node.children.get(ch);
        }

        node.isEnd = true;
    }

    /**
     * @param {string} word
     * @return {boolean}
     */
    search(word) {
        function searchWordInNode(index, node) {
            for(; index < word.length; index++){
                let ch = word[index];
                if(ch === '.'){
                    for(const child of node.children.values()){
                    let found = searchWordInNode(index + 1, child);
                    if(found) return true;
                    }

                    return false;
                }
                else {
                let next = node.children.get(ch);
                if(!next) return false;
                node = next;
                }
            }

            return node.isEnd;
        }
        
        return searchWordInNode(0, this.root);
    }
}
