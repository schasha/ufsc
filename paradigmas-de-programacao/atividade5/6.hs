ocorrencias :: [Int] -> Int -> Int
ocorrencias [a] x = if a == x then 1 else 0
ocorrencias (a:b) x = 
    if a == x then
        1 + ocorrencias b x
    else
        ocorrencias b x

main = print (ocorrencias [mod x 3 | x <- [1..100]] 0)
