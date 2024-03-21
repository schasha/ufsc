isPrime :: Int -> Bool
isPrime n = 
    if a == 1 then
        True
    else
        False
    where a = length [x | x <- [1..floor (sqrt (fromIntegral n))], mod n x == 0]

main = do
    strX <- getLine
    let x = read strX :: Int
    print (isPrime x)
