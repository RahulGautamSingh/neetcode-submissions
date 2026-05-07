class Solution {
    /**
     * @param {string} s
     * @param {string} t
     * @return {boolean}
     */
    isAnagram(s, t) {
        // I will create an array of length 26 a-z 0-25
        // count++ from array 1 and count-- from array 2
        // if all counts 0 at last anagram else not

        const count = new Array(26).fill(0);
        const capS = s.toUpperCase();
        const capT = t.toUpperCase();

        for(const c of capS.split("")){
           const index = c.charCodeAt(0) - 65;
           count[index] = count[index] + 1;
        }

        for(const c of capT.split("")){
           const index = c.charCodeAt(0) - 65;
           count[index] = count[index] - 1;
        }

        for(const val of count){
            if(val !== 0){
                return false;
            }
        }

        return true;
    }
}
