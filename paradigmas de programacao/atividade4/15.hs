mdc :: Int -> Int -> Int
mdc x y = 
    if y == 0 then
        x
    else
        mdc y (x `mod` y)

coprimes :: Int -> Int -> Bool
coprimes x y =
    if mdc x y == 1 then
        True
    else
        False

phi :: Int -> Int
phi x = length [a | a <- [1..(x-1)], coprimes a x]

main = do
    strX <- getLine
    let x = read strX :: Int
    print (phi x)
