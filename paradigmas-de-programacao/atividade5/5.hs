busca :: [Int] -> Int -> Bool
busca [a] x = a == x
busca (a:b) x = 
    if a == x then
        True
    else
        busca b x 

main = print (busca [1..10] 11)
