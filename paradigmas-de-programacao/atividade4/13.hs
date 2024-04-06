mdc :: Int -> Int -> Int
mdc x y = 
    if y == 0 then
        x
    else
        mdc y (x `mod` y)

mmc :: Int -> Int -> Int
mmc x y = (x*y) `div` mdc x y

readInt :: IO [Int]
readInt = fmap (map read.words) getLine

main = do
    x <- readInt
    print (mmc (x!!0) (x!!1))
