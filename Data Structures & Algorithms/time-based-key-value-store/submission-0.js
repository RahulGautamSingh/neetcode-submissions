class TimeMap {
    constructor() {
        this.keyStore = new Map();
    }

    /**
     * @param {string} key
     * @param {string} value
     * @param {number} timestamp
     * @return {void}
     */
    set(key, value, timestamp) {
        const currentValue = this.keyStore.get(key);
        if(!currentValue){
                this.keyStore.set(key, [[timestamp, value]]);
        }
        else {
            currentValue.push([timestamp, value]);
        }
    }

    /**
     * @param {string} key
     * @param {number} timestamp
     * @return {string}
     */
    get(key, timestamp) {
        const keyArr = this.keyStore.get(key);
        if(!keyArr) return "";

        let l = 0, r = keyArr.length - 1;
        let result = "";
        while(l<=r){
            let mid = l + Math.floor((r-l)/2);

            if(timestamp < keyArr[mid][0]){
                r = mid - 1;
            } else {
                            result = keyArr[mid][1]; // valid candidate, but keep looking right for a closer one

                l = mid + 1;
            } 
        }


        return result;


    }



}
