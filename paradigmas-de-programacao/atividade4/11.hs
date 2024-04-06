mdc :: Int -> Int -> Int
mdc x y = 
    if y == 0 then
        x
    else
        mdc y (x `mod` y)

main = do
    strX <- getLine
    strY <- getLine
    let x = read strX
    let y = read strY
    print (mdc x y)
