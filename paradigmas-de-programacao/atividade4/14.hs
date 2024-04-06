mdc :: Int -> Int -> Int
mdc x y = 
    if y == 0 then
        x
    else
        mdc y (x `mod` y)

coprimos :: Int -> Int -> Bool
coprimos x y =
    if mdc x y == 1 then
        True
    else
        False

readInt :: IO [Int]
readInt = fmap (map read.words) getLine

main = do
    x <- readInt
    print (coprimos (x!!0) (x!!1))
