op :: String -> Float -> Float -> Float
op "+" x y = x + y
op "-" x y = x - y
op "*" x y = x * y
op "/" x y = x / y

main = do
    strO <- getLine
    strX <- getLine
    strY <- getLine
    let x = read strX :: Float
    let y = read strY :: Float
    print (op strO x y )
