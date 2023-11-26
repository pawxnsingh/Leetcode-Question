/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    let n = digits.length;
    for(let i=n-1;i>=0;i--){
        if(digits[i] < 9){
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }

    let ans = [];
    ans.push(1);
    for(let i=0;i<n;i++){
        ans.push(0);
    }
    return ans;
};