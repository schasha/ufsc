exponential :: Int -> Int -> Int
exponential x y = x^y

main = do
    strX <- getLine
    strY <- getLine
    let x = (read strX :: Int)
    let y = (read strY :: Int)
    print (exponential x y)
