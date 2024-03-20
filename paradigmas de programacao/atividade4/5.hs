average :: (Fractional a) => a -> a -> a -> a
average x y z = (x+y+z)/3


main = do
    strX <- getLine
    strY <- getLine
    strZ <- getLine
    let x = (read strX :: Float)
    let y = (read strY :: Float)
    let z = (read strZ :: Float)
    print (average x y z)
