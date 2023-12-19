/*
INTUITION:
The problem aims to apply a smoothing filter to a given 2D image 
represented by a matrix. We iterate through each pixel in the image, 
calculating the average value of the pixel and its surrounding 
neighbors using a 3x3 kernel. The sum of pixel values and a count 
of valid neighbors are computed within nested loops. The pixel value 
is then updated by shifting the averaged value to the higher byte 
of the integer representation.
*/

/**
 * @param {number[][]} img
 * @return {number[][]}
 */
var imageSmoother = function(img) {
    const m=img.length;
    const n=img[0].length;
    for(let i=0;i<m;i++){
        for(let j=0;j<n;j++){
            let sum=0;
            let count=0;
            for(let x=i-1;x<=i+1;x++){
                for(let y=j-1;y<=j+1;y++){
                    if(x>=0 && x<m && y>=0 && y<n){
                        sum+=img[x][y]&255;
                        count+=1;
                    }
                }
            }
            img[i][j]|=Math.floor(sum/count)<<8;
        }
    }
    for(let i=0;i<m;i++){
        for(let j=0;j<n;j++){
            img[i][j]>>=8;
        }
    }
    return img;
};