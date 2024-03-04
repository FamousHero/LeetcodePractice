function mergeAlternately(word1: string, word2: string): string {
    let minLength: number = word1.length < word2.length? word1.length: word2.length;
    let mergeWord: string = "";
    for(let i: number = 0; i < minLength; ++i)
        {
            mergeWord += word1.charAt(i) + word2.charAt(i);
        }
    if(minLength === word1.length)
        mergeWord += word2.slice(minLength);
    else
        mergeWord += word1.slice(minLength);
    return mergeWord;
};