var trap = function(height) {
    let left=[];
    left[0]=height[0];
    let largeSorFar=height[0];
    
    for(let i=1;i<height.length;i++){
        largeSorFar=Math.max(largeSorFar,height[i]);
        left.push(largeSorFar);
    }
    
    largeSorFar=height[height.length-1];
    let right=[];
    right[height.length-1]=height[height.length-1];

    for(let i=height.length-1;i>=0;i--){
        largeSorFar=Math.max(largeSorFar,height[i]);
        right[i]=largeSorFar;
    }
    console.log(left);
    console.log(right);
    
    let water=0;
    
    for(let i=1;i<height.length-1;i++){
        water+=Math.min(left[i],right[i])-height[i];
    }
    return water;

};