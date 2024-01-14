/**
 * INTUITIPN:
 * The problem aims to determine whether two strings, word1 and word2, are close. Two strings are considered 
 * close if they have the same set of characters and the frequency of each character is the same. We achieve 
 * this by maintaining frequency arrays for each string, counting the occurrences of each character. We then 
 * check if the set of characters is the same for both strings and returns false if any character is present 
 * in one string but not the other. After confirming the same set of characters, we sort the frequency arrays 
 * and checks if the sorted arrays are equal, ensuring that the frequencies of characters match.
 */

/**
 * @param {string} word1
 * @param {string} word2
 * @return {boolean}
 */
var closeStrings = function(word1, word2) {
    let freq1 = new Array(26).fill(0)
    let freq2 = new Array(26).fill(0)
    for(let c of word1) freq1[c.charCodeAt(0) - 'a'.charCodeAt(0)]++
    for(let c of word2) freq2[c.charCodeAt(0) - 'a'.charCodeAt(0)]++
    for(let i = 0; i < 26; i++) if((freq1[i] === 0 && freq2[i] !== 0) || (freq1[i] !== 0 && freq2[i] === 0)) return false
    freq1.sort((a , b)=> a - b)
    freq2.sort((a , b)=> a - b)
    for(let i = 0; i < 26; i++) if(freq1[i] !== freq2[i]) return false
    return true
    
};