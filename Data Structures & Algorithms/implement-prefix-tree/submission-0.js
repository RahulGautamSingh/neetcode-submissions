class PrefixTreeNode {
    children = new Map(); // <string, PrefixTreeNode>
    isEnd = false;
}
class PrefixTree {
    constructor() {
        this.root = new PrefixTreeNode();
    }

    /**
     * @param {string} word
     * @return {void}
     */
    insert(word) {
        let node = this.root;
        for(const ch of word){
            if(!node.children.get(ch)) node.children.set(ch, new PrefixTreeNode());
            node = node.children.get(ch);
        }

        node.isEnd = true;
    }

    /**
     * @param {string} word
     * @return {boolean}
     */
    search(word) {
        let node = this.root;
        for(const ch of word){
            let next = node.children.get(ch);
            if(!next) return false;
            node = next;
        }

        return node.isEnd;
    }

    /**
     * @param {string} prefix
     * @return {boolean}
     */
    startsWith(prefix) {
       let node = this.root;
        for(const ch of prefix){
            let next = node.children.get(ch);
            if(!next) return false;
            node = next;
        } 

        return true;
    }
}
