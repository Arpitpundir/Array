/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    const strMap = new Map();
    for(const str of strs){
        const sortedString = str.split("").sort().join('');
        //console.log(sortedString)
        if(!strMap.has(sortedString)){
            strMap.set(sortedString, []);
        }
        strMap.get(sortedString).push(str);
    }

    return Array.from(strMap.values());
};