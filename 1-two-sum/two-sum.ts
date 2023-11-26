function twoSum(nums: number[], target: number): number[] {
    const ans = [];
    for(let i=0;i<nums.length-1;i++){
        for(let j=i+1;j<nums.length;j++){
            if(nums[i] + nums[j] === target){
                ans.push(i);
                ans.push(j);
            }
        }
    }
    return ans;
};