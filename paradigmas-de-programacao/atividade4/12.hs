mdc :: Int -> Int -> Int
mdc x y =
    if y == 0 then
        x
    else
        mdc y (mod x y)

mdc3 :: Int -> Int -> Int -> Int
mdc3 x y z = mdc x (mdc y z)

readInt :: IO [Int]
readInt = fmap (map read.words) getLine

main = do
    x <- readInt
    print (mdc3 (x!!0) (x!!1) (x!!2))
