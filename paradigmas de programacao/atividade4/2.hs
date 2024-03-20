absolute :: Int -> Int
absolute x = do
    if x < 0 then
        -x
    else
        x

main = do
    strX <- getLine
    let x = (read strX :: Int)
    print (absolute x)
