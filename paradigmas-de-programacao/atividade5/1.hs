soma :: [Int] -> Int
soma [] = 0
soma (a:b) = a + soma b

main = print (soma [1..10])
