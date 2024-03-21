bhaskara :: (Floating a) => a -> a -> a -> [a]
bhaskara a b c = [(-b + sqrt (b*b - 4*a*c)) / (2*a), (-b - sqrt (b*b - 4*a*c)) / (2*a)]

main = do
    strX <- getLine
    strY <- getLine
    strZ <- getLine
    let x = read strX :: Float
    let y = read strY :: Float
    let z = read strZ :: Float
    print (bhaskara x y z)

