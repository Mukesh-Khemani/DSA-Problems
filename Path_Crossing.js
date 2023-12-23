/*
INTUITION:
The problem aims to determine whether a given path, represented by a 
string of directions ('N', 'S', 'W', 'E'), results in a crossing point. 
We use a set called visited to keep track of visited coordinates, 
starting with the origin (0,0). We then iterate through the path, 
updating the current position based on the movement directions and 
checking if the new coordinates have been visited before. If a crossing 
point is encountered, we return true; otherwise, we continue updating 
the visited set and returns false at the end.
*/
var isPathCrossing = function(path) {
    let moves={
        'N':[0,1],
        'S':[0,-1],
        'W':[-1,0],
        'E':[1,0]
    };
    let visited = new Set()
    visited.add("0,0")
    let x = 0
    let y = 0

    for(let i of path){
        let curr = moves[i]
        let dx = curr[0]
        let dy = curr[1]

        x += dx
        y += dy

        let hash = `${x},${y}`;

        if(visited.has(hash)) return true
        
        visited.add(hash)
    }
    return false
};