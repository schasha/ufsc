max3 :: (Ord a) => a -> a -> a -> a
max3 x y z = max x (max y z)

readFloats :: IO [Float]
readFloats = fmap (map read.words) getLine

main = do
    x <- readFloats
    print (max3 (x!!0) (x!!1) (x!!2))
