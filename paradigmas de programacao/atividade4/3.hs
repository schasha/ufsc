triangleArea :: Float -> Float -> Float
triangleArea x y = x*y/2

main = do
    strX <- getLine
    strY <- getLine
    let x = (read strX :: Float)
    let y = (read strY :: Float)
    print (triangleArea x y)
