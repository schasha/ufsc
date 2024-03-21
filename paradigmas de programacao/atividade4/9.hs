distance3D :: (Floating a) => (a, a, a) -> (a, a, a) -> a
distance3D (x1, y1, z1) (x2, y2, z2) = sqrt ((x2-x1)**2 + (y2-y1)**2 + (z2-z1)**2)

readFloats :: IO [Float]
readFloats = fmap (map read.words) getLine

main = do
    a <- readFloats
    b <- readFloats
    print (distance3D (a!!0, a!!1, a!!2) (b!!0, b!!1, b!!2))

