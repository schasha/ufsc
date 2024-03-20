isTriangle :: Int -> Int -> Int -> Bool
isTriangle x y z
    | maxSize == z = (x + y > z)
    | maxSize == x = (y + z > x)
    | maxSize == y = (z + x > y)
    where maxSize = max x (max y z)
    
main = do
    strX <- getLine
    strY <- getLine
    strZ <- getLine
    let x = (read strX :: Int)
    let y = (read strY :: Int)
    let z = (read strZ :: Int)
    print (isTriangle x y z)
