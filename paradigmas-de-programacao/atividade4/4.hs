xor :: Bool -> Bool -> Bool
xor x y = do
    if (x && not y) then
        True
    else if (not x && y) then
        True
    else
        False

main = do
    strX <- getLine
    strY <- getLine
    let x = (read strX :: Bool)
    let y = (read strY :: Bool)
    print (xor x y)
