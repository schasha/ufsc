divisible :: Int -> Int -> Bool
divisible x y = 
    if mod x y == 0 then
        True
    else
        False

readInts :: IO [Int]
readInts = fmap (map read.words) getLine

main = do
    a <- readInts
    print (divisible (a!!0) (a!!1))
