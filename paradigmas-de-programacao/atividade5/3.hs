menor :: [Int] -> Int
menor [] = 0
menor [a] = a
menor (a:b) =
    if a < menor b then
        a
    else
        menor b

main = print (menor [10, 9..1])
