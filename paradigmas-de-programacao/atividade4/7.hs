fibonacci :: Int -> Int
fibonacci 1 = 1
fibonacci 2 = 1
fibonacci n = fibonacci (n-1) + fibonacci (n-2)

main = do
    strX <- getLine
    let x = read strX :: Int
    print (fibonacci x )
