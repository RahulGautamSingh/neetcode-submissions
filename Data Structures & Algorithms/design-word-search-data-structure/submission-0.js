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
        return this.searchWordInNode(word, this.root);
    }

    /**
     * @param {string} word
     * @return {boolean}
     */
    searchWordInNode(word, node) {
        for(const [index, ch] of word.split("").entries()){
            if(ch === '.'){
                for(const children of node.children.values()){
                let found = this.searchWordInNode(word.slice(index + 1), children);
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
}
